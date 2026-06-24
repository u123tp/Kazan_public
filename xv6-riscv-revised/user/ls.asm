
user/_ls:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <fmtname>:
#include "kernel/fs.h"
#include "kernel/fcntl.h"

char*
fmtname(char *path)
{
       0:	fe010113          	addi	sp,sp,-32
       4:	00113c23          	sd	ra,24(sp)
       8:	00813823          	sd	s0,16(sp)
       c:	00913423          	sd	s1,8(sp)
      10:	02010413          	addi	s0,sp,32
      14:	00050493          	mv	s1,a0
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
      18:	37c000ef          	jal	394 <strlen>
      1c:	02051793          	slli	a5,a0,0x20
      20:	0207d793          	srli	a5,a5,0x20
      24:	00f487b3          	add	a5,s1,a5
      28:	02f00693          	li	a3,47
      2c:	0097ea63          	bltu	a5,s1,40 <fmtname+0x40>
      30:	0007c703          	lbu	a4,0(a5)
      34:	00d70663          	beq	a4,a3,40 <fmtname+0x40>
      38:	fff78793          	addi	a5,a5,-1
      3c:	fe97fae3          	bgeu	a5,s1,30 <fmtname+0x30>
    ;
  p++;
      40:	00178493          	addi	s1,a5,1

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
      44:	00048513          	mv	a0,s1
      48:	34c000ef          	jal	394 <strlen>
      4c:	00d00793          	li	a5,13
      50:	00a7fe63          	bgeu	a5,a0,6c <fmtname+0x6c>
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  buf[sizeof(buf)-1] = '\0';
  return buf;
}
      54:	00048513          	mv	a0,s1
      58:	01813083          	ld	ra,24(sp)
      5c:	01013403          	ld	s0,16(sp)
      60:	00813483          	ld	s1,8(sp)
      64:	02010113          	addi	sp,sp,32
      68:	00008067          	ret
      6c:	01213023          	sd	s2,0(sp)
  memmove(buf, p, strlen(p));
      70:	00048513          	mv	a0,s1
      74:	320000ef          	jal	394 <strlen>
      78:	00050613          	mv	a2,a0
      7c:	00048593          	mv	a1,s1
      80:	00002517          	auipc	a0,0x2
      84:	fa050513          	addi	a0,a0,-96 # 2020 <buf.0>
      88:	574000ef          	jal	5fc <memmove>
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
      8c:	00048513          	mv	a0,s1
      90:	304000ef          	jal	394 <strlen>
      94:	00050913          	mv	s2,a0
      98:	00048513          	mv	a0,s1
      9c:	2f8000ef          	jal	394 <strlen>
      a0:	02091793          	slli	a5,s2,0x20
      a4:	0207d793          	srli	a5,a5,0x20
      a8:	00e00613          	li	a2,14
      ac:	40a6063b          	subw	a2,a2,a0
      b0:	02000593          	li	a1,32
      b4:	00002717          	auipc	a4,0x2
      b8:	f6c70713          	addi	a4,a4,-148 # 2020 <buf.0>
      bc:	00070493          	mv	s1,a4
      c0:	00f70533          	add	a0,a4,a5
      c4:	318000ef          	jal	3dc <memset>
  buf[sizeof(buf)-1] = '\0';
      c8:	00048723          	sb	zero,14(s1)
  return buf;
      cc:	00013903          	ld	s2,0(sp)
      d0:	f85ff06f          	j	54 <fmtname+0x54>

00000000000000d4 <ls>:

void
ls(char *path)
{
      d4:	da010113          	addi	sp,sp,-608
      d8:	24113c23          	sd	ra,600(sp)
      dc:	24813823          	sd	s0,592(sp)
      e0:	25213023          	sd	s2,576(sp)
      e4:	26010413          	addi	s0,sp,608
      e8:	00050913          	mv	s2,a0
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(path, O_RDONLY)) < 0){
      ec:	00000593          	li	a1,0
      f0:	6cc000ef          	jal	7bc <open>
      f4:	06054c63          	bltz	a0,16c <ls+0x98>
      f8:	24913423          	sd	s1,584(sp)
      fc:	00050493          	mv	s1,a0
    fprintf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
     100:	da840593          	addi	a1,s0,-600
     104:	6dc000ef          	jal	7e0 <fstat>
     108:	06054e63          	bltz	a0,184 <ls+0xb0>
    fprintf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type){
     10c:	db041783          	lh	a5,-592(s0)
     110:	00100713          	li	a4,1
     114:	08e78a63          	beq	a5,a4,1a8 <ls+0xd4>
     118:	ffe7879b          	addiw	a5,a5,-2
     11c:	03079793          	slli	a5,a5,0x30
     120:	0307d793          	srli	a5,a5,0x30
     124:	02f76463          	bltu	a4,a5,14c <ls+0x78>
  case T_DEVICE:
  case T_FILE:
    printf("%s %d %d %d\n", fmtname(path), st.type, st.ino, (int) st.size);
     128:	00090513          	mv	a0,s2
     12c:	ed5ff0ef          	jal	0 <fmtname>
     130:	00050593          	mv	a1,a0
     134:	db842703          	lw	a4,-584(s0)
     138:	dac42683          	lw	a3,-596(s0)
     13c:	db041603          	lh	a2,-592(s0)
     140:	00001517          	auipc	a0,0x1
     144:	fa050513          	addi	a0,a0,-96 # 10e0 <malloc+0x1a0>
     148:	4ed000ef          	jal	e34 <printf>
      }
      printf("%s %d %d %d\n", fmtname(buf), st.type, st.ino, (int) st.size);
    }
    break;
  }
  close(fd);
     14c:	00048513          	mv	a0,s1
     150:	648000ef          	jal	798 <close>
     154:	24813483          	ld	s1,584(sp)
}
     158:	25813083          	ld	ra,600(sp)
     15c:	25013403          	ld	s0,592(sp)
     160:	24013903          	ld	s2,576(sp)
     164:	26010113          	addi	sp,sp,608
     168:	00008067          	ret
    fprintf(2, "ls: cannot open %s\n", path);
     16c:	00090613          	mv	a2,s2
     170:	00001597          	auipc	a1,0x1
     174:	f4058593          	addi	a1,a1,-192 # 10b0 <malloc+0x170>
     178:	00200513          	li	a0,2
     17c:	475000ef          	jal	df0 <fprintf>
    return;
     180:	fd9ff06f          	j	158 <ls+0x84>
    fprintf(2, "ls: cannot stat %s\n", path);
     184:	00090613          	mv	a2,s2
     188:	00001597          	auipc	a1,0x1
     18c:	f4058593          	addi	a1,a1,-192 # 10c8 <malloc+0x188>
     190:	00200513          	li	a0,2
     194:	45d000ef          	jal	df0 <fprintf>
    close(fd);
     198:	00048513          	mv	a0,s1
     19c:	5fc000ef          	jal	798 <close>
    return;
     1a0:	24813483          	ld	s1,584(sp)
     1a4:	fb5ff06f          	j	158 <ls+0x84>
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
     1a8:	00090513          	mv	a0,s2
     1ac:	1e8000ef          	jal	394 <strlen>
     1b0:	0105051b          	addiw	a0,a0,16
     1b4:	20000793          	li	a5,512
     1b8:	00a7fa63          	bgeu	a5,a0,1cc <ls+0xf8>
      printf("ls: path too long\n");
     1bc:	00001517          	auipc	a0,0x1
     1c0:	f3450513          	addi	a0,a0,-204 # 10f0 <malloc+0x1b0>
     1c4:	471000ef          	jal	e34 <printf>
      break;
     1c8:	f85ff06f          	j	14c <ls+0x78>
     1cc:	23313c23          	sd	s3,568(sp)
    strcpy(buf, path);
     1d0:	00090593          	mv	a1,s2
     1d4:	dd040513          	addi	a0,s0,-560
     1d8:	13c000ef          	jal	314 <strcpy>
    p = buf+strlen(buf);
     1dc:	dd040513          	addi	a0,s0,-560
     1e0:	1b4000ef          	jal	394 <strlen>
     1e4:	02051513          	slli	a0,a0,0x20
     1e8:	02055513          	srli	a0,a0,0x20
     1ec:	dd040793          	addi	a5,s0,-560
     1f0:	00a787b3          	add	a5,a5,a0
     1f4:	00078913          	mv	s2,a5
    *p++ = '/';
     1f8:	00178793          	addi	a5,a5,1
     1fc:	00078993          	mv	s3,a5
     200:	02f00793          	li	a5,47
     204:	00f90023          	sb	a5,0(s2)
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
     208:	0140006f          	j	21c <ls+0x148>
        printf("ls: cannot stat %s\n", buf);
     20c:	dd040593          	addi	a1,s0,-560
     210:	00001517          	auipc	a0,0x1
     214:	eb850513          	addi	a0,a0,-328 # 10c8 <malloc+0x188>
     218:	41d000ef          	jal	e34 <printf>
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
     21c:	01000613          	li	a2,16
     220:	dc040593          	addi	a1,s0,-576
     224:	00048513          	mv	a0,s1
     228:	558000ef          	jal	780 <read>
     22c:	01000793          	li	a5,16
     230:	04f51c63          	bne	a0,a5,288 <ls+0x1b4>
      if(de.inum == 0)
     234:	dc045783          	lhu	a5,-576(s0)
     238:	fe0782e3          	beqz	a5,21c <ls+0x148>
      memmove(p, de.name, DIRSIZ);
     23c:	00e00613          	li	a2,14
     240:	dc240593          	addi	a1,s0,-574
     244:	00098513          	mv	a0,s3
     248:	3b4000ef          	jal	5fc <memmove>
      p[DIRSIZ] = 0;
     24c:	000907a3          	sb	zero,15(s2)
      if(stat(buf, &st) < 0){
     250:	da840593          	addi	a1,s0,-600
     254:	dd040513          	addi	a0,s0,-560
     258:	2d0000ef          	jal	528 <stat>
     25c:	fa0548e3          	bltz	a0,20c <ls+0x138>
      printf("%s %d %d %d\n", fmtname(buf), st.type, st.ino, (int) st.size);
     260:	dd040513          	addi	a0,s0,-560
     264:	d9dff0ef          	jal	0 <fmtname>
     268:	00050593          	mv	a1,a0
     26c:	db842703          	lw	a4,-584(s0)
     270:	dac42683          	lw	a3,-596(s0)
     274:	db041603          	lh	a2,-592(s0)
     278:	00001517          	auipc	a0,0x1
     27c:	e6850513          	addi	a0,a0,-408 # 10e0 <malloc+0x1a0>
     280:	3b5000ef          	jal	e34 <printf>
     284:	f99ff06f          	j	21c <ls+0x148>
     288:	23813983          	ld	s3,568(sp)
     28c:	ec1ff06f          	j	14c <ls+0x78>

0000000000000290 <main>:

int
main(int argc, char *argv[])
{
     290:	fe010113          	addi	sp,sp,-32
     294:	00113c23          	sd	ra,24(sp)
     298:	00813823          	sd	s0,16(sp)
     29c:	02010413          	addi	s0,sp,32
  int i;

  if(argc < 2){
     2a0:	00100793          	li	a5,1
     2a4:	02a7de63          	bge	a5,a0,2e0 <main+0x50>
     2a8:	00913423          	sd	s1,8(sp)
     2ac:	01213023          	sd	s2,0(sp)
     2b0:	00858493          	addi	s1,a1,8
     2b4:	ffe5091b          	addiw	s2,a0,-2
     2b8:	02091793          	slli	a5,s2,0x20
     2bc:	01d7d913          	srli	s2,a5,0x1d
     2c0:	01058593          	addi	a1,a1,16
     2c4:	00b90933          	add	s2,s2,a1
    ls(".");
    exit(0);
  }
  for(i=1; i<argc; i++)
    ls(argv[i]);
     2c8:	0004b503          	ld	a0,0(s1)
     2cc:	e09ff0ef          	jal	d4 <ls>
  for(i=1; i<argc; i++)
     2d0:	00848493          	addi	s1,s1,8
     2d4:	ff249ae3          	bne	s1,s2,2c8 <main+0x38>
  exit(0);
     2d8:	00000513          	li	a0,0
     2dc:	480000ef          	jal	75c <exit>
     2e0:	00913423          	sd	s1,8(sp)
     2e4:	01213023          	sd	s2,0(sp)
    ls(".");
     2e8:	00001517          	auipc	a0,0x1
     2ec:	e2050513          	addi	a0,a0,-480 # 1108 <malloc+0x1c8>
     2f0:	de5ff0ef          	jal	d4 <ls>
    exit(0);
     2f4:	00000513          	li	a0,0
     2f8:	464000ef          	jal	75c <exit>

00000000000002fc <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
     2fc:	ff010113          	addi	sp,sp,-16
     300:	00113423          	sd	ra,8(sp)
     304:	00813023          	sd	s0,0(sp)
     308:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
     30c:	f85ff0ef          	jal	290 <main>
  exit(r);
     310:	44c000ef          	jal	75c <exit>

0000000000000314 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
     314:	ff010113          	addi	sp,sp,-16
     318:	00113423          	sd	ra,8(sp)
     31c:	00813023          	sd	s0,0(sp)
     320:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
     324:	00050793          	mv	a5,a0
     328:	00158593          	addi	a1,a1,1
     32c:	00178793          	addi	a5,a5,1
     330:	fff5c703          	lbu	a4,-1(a1)
     334:	fee78fa3          	sb	a4,-1(a5)
     338:	fe0718e3          	bnez	a4,328 <strcpy+0x14>
    ;
  return os;
}
     33c:	00813083          	ld	ra,8(sp)
     340:	00013403          	ld	s0,0(sp)
     344:	01010113          	addi	sp,sp,16
     348:	00008067          	ret

000000000000034c <strcmp>:

int
strcmp(const char *p, const char *q)
{
     34c:	ff010113          	addi	sp,sp,-16
     350:	00113423          	sd	ra,8(sp)
     354:	00813023          	sd	s0,0(sp)
     358:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
     35c:	00054783          	lbu	a5,0(a0)
     360:	00078e63          	beqz	a5,37c <strcmp+0x30>
     364:	0005c703          	lbu	a4,0(a1)
     368:	00f71a63          	bne	a4,a5,37c <strcmp+0x30>
    p++, q++;
     36c:	00150513          	addi	a0,a0,1
     370:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
     374:	00054783          	lbu	a5,0(a0)
     378:	fe0796e3          	bnez	a5,364 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
     37c:	0005c503          	lbu	a0,0(a1)
}
     380:	40a7853b          	subw	a0,a5,a0
     384:	00813083          	ld	ra,8(sp)
     388:	00013403          	ld	s0,0(sp)
     38c:	01010113          	addi	sp,sp,16
     390:	00008067          	ret

0000000000000394 <strlen>:

uint
strlen(const char *s)
{
     394:	ff010113          	addi	sp,sp,-16
     398:	00113423          	sd	ra,8(sp)
     39c:	00813023          	sd	s0,0(sp)
     3a0:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
     3a4:	00054783          	lbu	a5,0(a0)
     3a8:	02078663          	beqz	a5,3d4 <strlen+0x40>
     3ac:	00150793          	addi	a5,a0,1
     3b0:	00078693          	mv	a3,a5
     3b4:	00178793          	addi	a5,a5,1
     3b8:	fff7c703          	lbu	a4,-1(a5)
     3bc:	fe071ae3          	bnez	a4,3b0 <strlen+0x1c>
     3c0:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
     3c4:	00813083          	ld	ra,8(sp)
     3c8:	00013403          	ld	s0,0(sp)
     3cc:	01010113          	addi	sp,sp,16
     3d0:	00008067          	ret
  for(n = 0; s[n]; n++)
     3d4:	00000513          	li	a0,0
     3d8:	fedff06f          	j	3c4 <strlen+0x30>

00000000000003dc <memset>:

void*
memset(void *dst, int c, uint n)
{
     3dc:	ff010113          	addi	sp,sp,-16
     3e0:	00113423          	sd	ra,8(sp)
     3e4:	00813023          	sd	s0,0(sp)
     3e8:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
     3ec:	02060063          	beqz	a2,40c <memset+0x30>
     3f0:	00050793          	mv	a5,a0
     3f4:	02061613          	slli	a2,a2,0x20
     3f8:	02065613          	srli	a2,a2,0x20
     3fc:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
     400:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
     404:	00178793          	addi	a5,a5,1
     408:	fee79ce3          	bne	a5,a4,400 <memset+0x24>
  }
  return dst;
}
     40c:	00813083          	ld	ra,8(sp)
     410:	00013403          	ld	s0,0(sp)
     414:	01010113          	addi	sp,sp,16
     418:	00008067          	ret

000000000000041c <strchr>:

char*
strchr(const char *s, char c)
{
     41c:	ff010113          	addi	sp,sp,-16
     420:	00113423          	sd	ra,8(sp)
     424:	00813023          	sd	s0,0(sp)
     428:	01010413          	addi	s0,sp,16
  for(; *s; s++)
     42c:	00054783          	lbu	a5,0(a0)
     430:	02078463          	beqz	a5,458 <strchr+0x3c>
    if(*s == c)
     434:	00f58a63          	beq	a1,a5,448 <strchr+0x2c>
  for(; *s; s++)
     438:	00150513          	addi	a0,a0,1
     43c:	00054783          	lbu	a5,0(a0)
     440:	fe079ae3          	bnez	a5,434 <strchr+0x18>
      return (char*)s;
  return 0;
     444:	00000513          	li	a0,0
}
     448:	00813083          	ld	ra,8(sp)
     44c:	00013403          	ld	s0,0(sp)
     450:	01010113          	addi	sp,sp,16
     454:	00008067          	ret
  return 0;
     458:	00000513          	li	a0,0
     45c:	fedff06f          	j	448 <strchr+0x2c>

0000000000000460 <gets>:

char*
gets(char *buf, int max)
{
     460:	fa010113          	addi	sp,sp,-96
     464:	04113c23          	sd	ra,88(sp)
     468:	04813823          	sd	s0,80(sp)
     46c:	04913423          	sd	s1,72(sp)
     470:	05213023          	sd	s2,64(sp)
     474:	03313c23          	sd	s3,56(sp)
     478:	03413823          	sd	s4,48(sp)
     47c:	03513423          	sd	s5,40(sp)
     480:	03613023          	sd	s6,32(sp)
     484:	01713c23          	sd	s7,24(sp)
     488:	01813823          	sd	s8,16(sp)
     48c:	06010413          	addi	s0,sp,96
     490:	00050b93          	mv	s7,a0
     494:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
     498:	00050913          	mv	s2,a0
     49c:	00000493          	li	s1,0
    cc = read(0, &c, 1);
     4a0:	faf40b13          	addi	s6,s0,-81
     4a4:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
     4a8:	00048c13          	mv	s8,s1
     4ac:	0014899b          	addiw	s3,s1,1
     4b0:	00098493          	mv	s1,s3
     4b4:	0349dc63          	bge	s3,s4,4ec <gets+0x8c>
    cc = read(0, &c, 1);
     4b8:	000a8613          	mv	a2,s5
     4bc:	000b0593          	mv	a1,s6
     4c0:	00000513          	li	a0,0
     4c4:	2bc000ef          	jal	780 <read>
    if(cc < 1)
     4c8:	02a05263          	blez	a0,4ec <gets+0x8c>
      break;
    buf[i++] = c;
     4cc:	faf44783          	lbu	a5,-81(s0)
     4d0:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
     4d4:	00190913          	addi	s2,s2,1
     4d8:	ff678713          	addi	a4,a5,-10
     4dc:	00070663          	beqz	a4,4e8 <gets+0x88>
     4e0:	ff378793          	addi	a5,a5,-13
     4e4:	fc0792e3          	bnez	a5,4a8 <gets+0x48>
    buf[i++] = c;
     4e8:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
     4ec:	018b8c33          	add	s8,s7,s8
     4f0:	000c0023          	sb	zero,0(s8)
  return buf;
}
     4f4:	000b8513          	mv	a0,s7
     4f8:	05813083          	ld	ra,88(sp)
     4fc:	05013403          	ld	s0,80(sp)
     500:	04813483          	ld	s1,72(sp)
     504:	04013903          	ld	s2,64(sp)
     508:	03813983          	ld	s3,56(sp)
     50c:	03013a03          	ld	s4,48(sp)
     510:	02813a83          	ld	s5,40(sp)
     514:	02013b03          	ld	s6,32(sp)
     518:	01813b83          	ld	s7,24(sp)
     51c:	01013c03          	ld	s8,16(sp)
     520:	06010113          	addi	sp,sp,96
     524:	00008067          	ret

0000000000000528 <stat>:

int
stat(const char *n, struct stat *st)
{
     528:	fe010113          	addi	sp,sp,-32
     52c:	00113c23          	sd	ra,24(sp)
     530:	00813823          	sd	s0,16(sp)
     534:	01213023          	sd	s2,0(sp)
     538:	02010413          	addi	s0,sp,32
     53c:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
     540:	00000593          	li	a1,0
     544:	278000ef          	jal	7bc <open>
  if(fd < 0)
     548:	02054e63          	bltz	a0,584 <stat+0x5c>
     54c:	00913423          	sd	s1,8(sp)
     550:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
     554:	00090593          	mv	a1,s2
     558:	288000ef          	jal	7e0 <fstat>
     55c:	00050913          	mv	s2,a0
  close(fd);
     560:	00048513          	mv	a0,s1
     564:	234000ef          	jal	798 <close>
  return r;
     568:	00813483          	ld	s1,8(sp)
}
     56c:	00090513          	mv	a0,s2
     570:	01813083          	ld	ra,24(sp)
     574:	01013403          	ld	s0,16(sp)
     578:	00013903          	ld	s2,0(sp)
     57c:	02010113          	addi	sp,sp,32
     580:	00008067          	ret
    return -1;
     584:	fff00793          	li	a5,-1
     588:	00078913          	mv	s2,a5
     58c:	fe1ff06f          	j	56c <stat+0x44>

0000000000000590 <atoi>:

int
atoi(const char *s)
{
     590:	ff010113          	addi	sp,sp,-16
     594:	00113423          	sd	ra,8(sp)
     598:	00813023          	sd	s0,0(sp)
     59c:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
     5a0:	00054683          	lbu	a3,0(a0)
     5a4:	fd06879b          	addiw	a5,a3,-48
     5a8:	0ff7f793          	zext.b	a5,a5
     5ac:	00900613          	li	a2,9
     5b0:	04f66263          	bltu	a2,a5,5f4 <atoi+0x64>
     5b4:	00050713          	mv	a4,a0
  n = 0;
     5b8:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
     5bc:	00170713          	addi	a4,a4,1
     5c0:	0025179b          	slliw	a5,a0,0x2
     5c4:	00a787bb          	addw	a5,a5,a0
     5c8:	0017979b          	slliw	a5,a5,0x1
     5cc:	00d787bb          	addw	a5,a5,a3
     5d0:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
     5d4:	00074683          	lbu	a3,0(a4)
     5d8:	fd06879b          	addiw	a5,a3,-48
     5dc:	0ff7f793          	zext.b	a5,a5
     5e0:	fcf67ee3          	bgeu	a2,a5,5bc <atoi+0x2c>
  return n;
}
     5e4:	00813083          	ld	ra,8(sp)
     5e8:	00013403          	ld	s0,0(sp)
     5ec:	01010113          	addi	sp,sp,16
     5f0:	00008067          	ret
  n = 0;
     5f4:	00000513          	li	a0,0
     5f8:	fedff06f          	j	5e4 <atoi+0x54>

00000000000005fc <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
     5fc:	ff010113          	addi	sp,sp,-16
     600:	00113423          	sd	ra,8(sp)
     604:	00813023          	sd	s0,0(sp)
     608:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
     60c:	02b57e63          	bgeu	a0,a1,648 <memmove+0x4c>
    while(n-- > 0)
     610:	02c05463          	blez	a2,638 <memmove+0x3c>
     614:	02061613          	slli	a2,a2,0x20
     618:	02065613          	srli	a2,a2,0x20
     61c:	00c507b3          	add	a5,a0,a2
  dst = vdst;
     620:	00050713          	mv	a4,a0
      *dst++ = *src++;
     624:	00158593          	addi	a1,a1,1
     628:	00170713          	addi	a4,a4,1
     62c:	fff5c683          	lbu	a3,-1(a1)
     630:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
     634:	fee798e3          	bne	a5,a4,624 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
     638:	00813083          	ld	ra,8(sp)
     63c:	00013403          	ld	s0,0(sp)
     640:	01010113          	addi	sp,sp,16
     644:	00008067          	ret
    while(n-- > 0)
     648:	fec058e3          	blez	a2,638 <memmove+0x3c>
    dst += n;
     64c:	00c50733          	add	a4,a0,a2
    src += n;
     650:	00c585b3          	add	a1,a1,a2
     654:	fff6079b          	addiw	a5,a2,-1
     658:	02079793          	slli	a5,a5,0x20
     65c:	0207d793          	srli	a5,a5,0x20
     660:	fff7c793          	not	a5,a5
     664:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
     668:	fff58593          	addi	a1,a1,-1
     66c:	fff70713          	addi	a4,a4,-1
     670:	0005c683          	lbu	a3,0(a1)
     674:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
     678:	fef718e3          	bne	a4,a5,668 <memmove+0x6c>
     67c:	fbdff06f          	j	638 <memmove+0x3c>

0000000000000680 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
     680:	ff010113          	addi	sp,sp,-16
     684:	00113423          	sd	ra,8(sp)
     688:	00813023          	sd	s0,0(sp)
     68c:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
     690:	04060263          	beqz	a2,6d4 <memcmp+0x54>
     694:	02061613          	slli	a2,a2,0x20
     698:	02065613          	srli	a2,a2,0x20
     69c:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
     6a0:	00054783          	lbu	a5,0(a0)
     6a4:	0005c703          	lbu	a4,0(a1)
     6a8:	00e79c63          	bne	a5,a4,6c0 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
     6ac:	00150513          	addi	a0,a0,1
    p2++;
     6b0:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
     6b4:	fed516e3          	bne	a0,a3,6a0 <memcmp+0x20>
  }
  return 0;
     6b8:	00000513          	li	a0,0
     6bc:	0080006f          	j	6c4 <memcmp+0x44>
      return *p1 - *p2;
     6c0:	40e7853b          	subw	a0,a5,a4
}
     6c4:	00813083          	ld	ra,8(sp)
     6c8:	00013403          	ld	s0,0(sp)
     6cc:	01010113          	addi	sp,sp,16
     6d0:	00008067          	ret
  return 0;
     6d4:	00000513          	li	a0,0
     6d8:	fedff06f          	j	6c4 <memcmp+0x44>

00000000000006dc <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
     6dc:	ff010113          	addi	sp,sp,-16
     6e0:	00113423          	sd	ra,8(sp)
     6e4:	00813023          	sd	s0,0(sp)
     6e8:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
     6ec:	f11ff0ef          	jal	5fc <memmove>
}
     6f0:	00813083          	ld	ra,8(sp)
     6f4:	00013403          	ld	s0,0(sp)
     6f8:	01010113          	addi	sp,sp,16
     6fc:	00008067          	ret

0000000000000700 <sbrk>:

char *
sbrk(int n) {
     700:	ff010113          	addi	sp,sp,-16
     704:	00113423          	sd	ra,8(sp)
     708:	00813023          	sd	s0,0(sp)
     70c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
     710:	00100593          	li	a1,1
     714:	114000ef          	jal	828 <sys_sbrk>
}
     718:	00813083          	ld	ra,8(sp)
     71c:	00013403          	ld	s0,0(sp)
     720:	01010113          	addi	sp,sp,16
     724:	00008067          	ret

0000000000000728 <sbrklazy>:

char *
sbrklazy(int n) {
     728:	ff010113          	addi	sp,sp,-16
     72c:	00113423          	sd	ra,8(sp)
     730:	00813023          	sd	s0,0(sp)
     734:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
     738:	00200593          	li	a1,2
     73c:	0ec000ef          	jal	828 <sys_sbrk>
}
     740:	00813083          	ld	ra,8(sp)
     744:	00013403          	ld	s0,0(sp)
     748:	01010113          	addi	sp,sp,16
     74c:	00008067          	ret

0000000000000750 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
     750:	00100893          	li	a7,1
 ecall
     754:	00000073          	ecall
 ret
     758:	00008067          	ret

000000000000075c <exit>:
.global exit
exit:
 li a7, SYS_exit
     75c:	00200893          	li	a7,2
 ecall
     760:	00000073          	ecall
 ret
     764:	00008067          	ret

0000000000000768 <wait>:
.global wait
wait:
 li a7, SYS_wait
     768:	00300893          	li	a7,3
 ecall
     76c:	00000073          	ecall
 ret
     770:	00008067          	ret

0000000000000774 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
     774:	00400893          	li	a7,4
 ecall
     778:	00000073          	ecall
 ret
     77c:	00008067          	ret

0000000000000780 <read>:
.global read
read:
 li a7, SYS_read
     780:	00500893          	li	a7,5
 ecall
     784:	00000073          	ecall
 ret
     788:	00008067          	ret

000000000000078c <write>:
.global write
write:
 li a7, SYS_write
     78c:	01000893          	li	a7,16
 ecall
     790:	00000073          	ecall
 ret
     794:	00008067          	ret

0000000000000798 <close>:
.global close
close:
 li a7, SYS_close
     798:	01500893          	li	a7,21
 ecall
     79c:	00000073          	ecall
 ret
     7a0:	00008067          	ret

00000000000007a4 <kill>:
.global kill
kill:
 li a7, SYS_kill
     7a4:	00600893          	li	a7,6
 ecall
     7a8:	00000073          	ecall
 ret
     7ac:	00008067          	ret

00000000000007b0 <exec>:
.global exec
exec:
 li a7, SYS_exec
     7b0:	00700893          	li	a7,7
 ecall
     7b4:	00000073          	ecall
 ret
     7b8:	00008067          	ret

00000000000007bc <open>:
.global open
open:
 li a7, SYS_open
     7bc:	00f00893          	li	a7,15
 ecall
     7c0:	00000073          	ecall
 ret
     7c4:	00008067          	ret

00000000000007c8 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
     7c8:	01100893          	li	a7,17
 ecall
     7cc:	00000073          	ecall
 ret
     7d0:	00008067          	ret

00000000000007d4 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
     7d4:	01200893          	li	a7,18
 ecall
     7d8:	00000073          	ecall
 ret
     7dc:	00008067          	ret

00000000000007e0 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
     7e0:	00800893          	li	a7,8
 ecall
     7e4:	00000073          	ecall
 ret
     7e8:	00008067          	ret

00000000000007ec <link>:
.global link
link:
 li a7, SYS_link
     7ec:	01300893          	li	a7,19
 ecall
     7f0:	00000073          	ecall
 ret
     7f4:	00008067          	ret

00000000000007f8 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
     7f8:	01400893          	li	a7,20
 ecall
     7fc:	00000073          	ecall
 ret
     800:	00008067          	ret

0000000000000804 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
     804:	00900893          	li	a7,9
 ecall
     808:	00000073          	ecall
 ret
     80c:	00008067          	ret

0000000000000810 <dup>:
.global dup
dup:
 li a7, SYS_dup
     810:	00a00893          	li	a7,10
 ecall
     814:	00000073          	ecall
 ret
     818:	00008067          	ret

000000000000081c <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
     81c:	00b00893          	li	a7,11
 ecall
     820:	00000073          	ecall
 ret
     824:	00008067          	ret

0000000000000828 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
     828:	00c00893          	li	a7,12
 ecall
     82c:	00000073          	ecall
 ret
     830:	00008067          	ret

0000000000000834 <pause>:
.global pause
pause:
 li a7, SYS_pause
     834:	00d00893          	li	a7,13
 ecall
     838:	00000073          	ecall
 ret
     83c:	00008067          	ret

0000000000000840 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
     840:	00e00893          	li	a7,14
 ecall
     844:	00000073          	ecall
 ret
     848:	00008067          	ret

000000000000084c <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
     84c:	00001617          	auipc	a2,0x1
     850:	7c462603          	lw	a2,1988(a2) # 2010 <putc_n>
     854:	00c04463          	bgtz	a2,85c <putc_flush+0x10>
     858:	00008067          	ret
{
     85c:	ff010113          	addi	sp,sp,-16
     860:	00113423          	sd	ra,8(sp)
     864:	00813023          	sd	s0,0(sp)
     868:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
     86c:	00001597          	auipc	a1,0x1
     870:	7c458593          	addi	a1,a1,1988 # 2030 <putc_buf>
     874:	00001517          	auipc	a0,0x1
     878:	78c52503          	lw	a0,1932(a0) # 2000 <putc_fd>
     87c:	f11ff0ef          	jal	78c <write>
    putc_n = 0;
     880:	00001797          	auipc	a5,0x1
     884:	7807a823          	sw	zero,1936(a5) # 2010 <putc_n>
  }
}
     888:	00813083          	ld	ra,8(sp)
     88c:	00013403          	ld	s0,0(sp)
     890:	01010113          	addi	sp,sp,16
     894:	00008067          	ret

0000000000000898 <putc>:

static void
putc(int fd, char c)
{
     898:	fe010113          	addi	sp,sp,-32
     89c:	00113c23          	sd	ra,24(sp)
     8a0:	00813823          	sd	s0,16(sp)
     8a4:	00913423          	sd	s1,8(sp)
     8a8:	02010413          	addi	s0,sp,32
     8ac:	00058493          	mv	s1,a1
  if (putc_fd != fd)
     8b0:	00001797          	auipc	a5,0x1
     8b4:	7507a783          	lw	a5,1872(a5) # 2000 <putc_fd>
     8b8:	04a79663          	bne	a5,a0,904 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
     8bc:	00001717          	auipc	a4,0x1
     8c0:	75470713          	addi	a4,a4,1876 # 2010 <putc_n>
     8c4:	00072683          	lw	a3,0(a4)
     8c8:	0016879b          	addiw	a5,a3,1
     8cc:	00f72023          	sw	a5,0(a4)
     8d0:	00001717          	auipc	a4,0x1
     8d4:	76070713          	addi	a4,a4,1888 # 2030 <putc_buf>
     8d8:	00d70733          	add	a4,a4,a3
     8dc:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
     8e0:	ff648493          	addi	s1,s1,-10
     8e4:	02048e63          	beqz	s1,920 <putc+0x88>
     8e8:	f8078793          	addi	a5,a5,-128
     8ec:	02078a63          	beqz	a5,920 <putc+0x88>
    putc_flush();
}
     8f0:	01813083          	ld	ra,24(sp)
     8f4:	01013403          	ld	s0,16(sp)
     8f8:	00813483          	ld	s1,8(sp)
     8fc:	02010113          	addi	sp,sp,32
     900:	00008067          	ret
     904:	01213023          	sd	s2,0(sp)
     908:	00050913          	mv	s2,a0
    putc_flush();
     90c:	f41ff0ef          	jal	84c <putc_flush>
    putc_fd = fd;
     910:	00001797          	auipc	a5,0x1
     914:	6f27a823          	sw	s2,1776(a5) # 2000 <putc_fd>
     918:	00013903          	ld	s2,0(sp)
     91c:	fa1ff06f          	j	8bc <putc+0x24>
    putc_flush();
     920:	f2dff0ef          	jal	84c <putc_flush>
}
     924:	fcdff06f          	j	8f0 <putc+0x58>

0000000000000928 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
     928:	fb010113          	addi	sp,sp,-80
     92c:	04113423          	sd	ra,72(sp)
     930:	04813023          	sd	s0,64(sp)
     934:	03213823          	sd	s2,48(sp)
     938:	03313423          	sd	s3,40(sp)
     93c:	05010413          	addi	s0,sp,80
     940:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
     944:	0a068e63          	beqz	a3,a00 <printint+0xd8>
     948:	0a05dc63          	bgez	a1,a00 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
     94c:	40b005b3          	neg	a1,a1
    neg = 1;
     950:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
     954:	fb840993          	addi	s3,s0,-72
  neg = 0;
     958:	00098693          	mv	a3,s3
  i = 0;
     95c:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
     960:	00000817          	auipc	a6,0x0
     964:	7b880813          	addi	a6,a6,1976 # 1118 <digits>
     968:	00070893          	mv	a7,a4
     96c:	0017051b          	addiw	a0,a4,1
     970:	00050713          	mv	a4,a0
     974:	02c5f7b3          	remu	a5,a1,a2
     978:	00f807b3          	add	a5,a6,a5
     97c:	0007c783          	lbu	a5,0(a5)
     980:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
     984:	00058793          	mv	a5,a1
     988:	02c5d5b3          	divu	a1,a1,a2
     98c:	00168693          	addi	a3,a3,1
     990:	fcc7fce3          	bgeu	a5,a2,968 <printint+0x40>
  if (neg)
     994:	00030c63          	beqz	t1,9ac <printint+0x84>
    buf[i++] = '-';
     998:	fd050793          	addi	a5,a0,-48
     99c:	00878533          	add	a0,a5,s0
     9a0:	02d00793          	li	a5,45
     9a4:	fef50423          	sb	a5,-24(a0)
     9a8:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
     9ac:	02e05e63          	blez	a4,9e8 <printint+0xc0>
     9b0:	02913c23          	sd	s1,56(sp)
     9b4:	fff7071b          	addiw	a4,a4,-1
     9b8:	00e984b3          	add	s1,s3,a4
     9bc:	fff98993          	addi	s3,s3,-1
     9c0:	00e989b3          	add	s3,s3,a4
     9c4:	02071713          	slli	a4,a4,0x20
     9c8:	02075713          	srli	a4,a4,0x20
     9cc:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
     9d0:	0004c583          	lbu	a1,0(s1)
     9d4:	00090513          	mv	a0,s2
     9d8:	ec1ff0ef          	jal	898 <putc>
  while (--i >= 0)
     9dc:	fff48493          	addi	s1,s1,-1
     9e0:	ff3498e3          	bne	s1,s3,9d0 <printint+0xa8>
     9e4:	03813483          	ld	s1,56(sp)
}
     9e8:	04813083          	ld	ra,72(sp)
     9ec:	04013403          	ld	s0,64(sp)
     9f0:	03013903          	ld	s2,48(sp)
     9f4:	02813983          	ld	s3,40(sp)
     9f8:	05010113          	addi	sp,sp,80
     9fc:	00008067          	ret
  neg = 0;
     a00:	00000313          	li	t1,0
     a04:	f51ff06f          	j	954 <printint+0x2c>

0000000000000a08 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
     a08:	fa010113          	addi	sp,sp,-96
     a0c:	04113c23          	sd	ra,88(sp)
     a10:	04813823          	sd	s0,80(sp)
     a14:	04913423          	sd	s1,72(sp)
     a18:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
     a1c:	0005c483          	lbu	s1,0(a1)
     a20:	32048263          	beqz	s1,d44 <vprintf+0x33c>
     a24:	05213023          	sd	s2,64(sp)
     a28:	03313c23          	sd	s3,56(sp)
     a2c:	03413823          	sd	s4,48(sp)
     a30:	03513423          	sd	s5,40(sp)
     a34:	03613023          	sd	s6,32(sp)
     a38:	01713c23          	sd	s7,24(sp)
     a3c:	01813823          	sd	s8,16(sp)
     a40:	00050b13          	mv	s6,a0
     a44:	00058a13          	mv	s4,a1
     a48:	00060b93          	mv	s7,a2
  state = 0;
     a4c:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
     a50:	00000913          	li	s2,0
     a54:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
     a58:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
     a5c:	06400c13          	li	s8,100
     a60:	0300006f          	j	a90 <vprintf+0x88>
        putc(fd, c0);
     a64:	00048593          	mv	a1,s1
     a68:	000b0513          	mv	a0,s6
     a6c:	e2dff0ef          	jal	898 <putc>
     a70:	0080006f          	j	a78 <vprintf+0x70>
    else if (state == '%')
     a74:	03598863          	beq	s3,s5,aa4 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
     a78:	0019079b          	addiw	a5,s2,1
     a7c:	00078913          	mv	s2,a5
     a80:	00078713          	mv	a4,a5
     a84:	00fa07b3          	add	a5,s4,a5
     a88:	0007c483          	lbu	s1,0(a5)
     a8c:	28048e63          	beqz	s1,d28 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
     a90:	0004879b          	sext.w	a5,s1
    if (state == 0)
     a94:	fe0990e3          	bnez	s3,a74 <vprintf+0x6c>
      if (c0 == '%')
     a98:	fd5796e3          	bne	a5,s5,a64 <vprintf+0x5c>
        state = '%';
     a9c:	00078993          	mv	s3,a5
     aa0:	fd9ff06f          	j	a78 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
     aa4:	00ea06b3          	add	a3,s4,a4
     aa8:	0016c603          	lbu	a2,1(a3)
      if (c1)
     aac:	2a060663          	beqz	a2,d58 <vprintf+0x350>
      if (c0 == 'd')
     ab0:	05878063          	beq	a5,s8,af0 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
     ab4:	f9478693          	addi	a3,a5,-108
     ab8:	0016b693          	seqz	a3,a3
     abc:	f9c60593          	addi	a1,a2,-100
     ac0:	04059a63          	bnez	a1,b14 <vprintf+0x10c>
     ac4:	04068863          	beqz	a3,b14 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
     ac8:	008b8493          	addi	s1,s7,8
     acc:	00100693          	li	a3,1
     ad0:	00a00613          	li	a2,10
     ad4:	000bb583          	ld	a1,0(s7)
     ad8:	000b0513          	mv	a0,s6
     adc:	e4dff0ef          	jal	928 <printint>
        i += 1;
     ae0:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
     ae4:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
     ae8:	00000993          	li	s3,0
     aec:	f8dff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
     af0:	008b8493          	addi	s1,s7,8
     af4:	00100693          	li	a3,1
     af8:	00a00613          	li	a2,10
     afc:	000ba583          	lw	a1,0(s7)
     b00:	000b0513          	mv	a0,s6
     b04:	e25ff0ef          	jal	928 <printint>
     b08:	00048b93          	mv	s7,s1
      state = 0;
     b0c:	00000993          	li	s3,0
     b10:	f69ff06f          	j	a78 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
     b14:	00ea0733          	add	a4,s4,a4
     b18:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
     b1c:	f9460713          	addi	a4,a2,-108
     b20:	00173713          	seqz	a4,a4
     b24:	00e6f733          	and	a4,a3,a4
     b28:	f9c58513          	addi	a0,a1,-100
     b2c:	24051263          	bnez	a0,d70 <vprintf+0x368>
     b30:	24070063          	beqz	a4,d70 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
     b34:	008b8493          	addi	s1,s7,8
     b38:	00100693          	li	a3,1
     b3c:	00a00613          	li	a2,10
     b40:	000bb583          	ld	a1,0(s7)
     b44:	000b0513          	mv	a0,s6
     b48:	de1ff0ef          	jal	928 <printint>
        i += 2;
     b4c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
     b50:	00048b93          	mv	s7,s1
      state = 0;
     b54:	00000993          	li	s3,0
        i += 2;
     b58:	f21ff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
     b5c:	008b8493          	addi	s1,s7,8
     b60:	00000693          	li	a3,0
     b64:	00a00613          	li	a2,10
     b68:	000be583          	lwu	a1,0(s7)
     b6c:	000b0513          	mv	a0,s6
     b70:	db9ff0ef          	jal	928 <printint>
     b74:	00048b93          	mv	s7,s1
      state = 0;
     b78:	00000993          	li	s3,0
     b7c:	efdff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
     b80:	008b8493          	addi	s1,s7,8
     b84:	00000693          	li	a3,0
     b88:	00a00613          	li	a2,10
     b8c:	000bb583          	ld	a1,0(s7)
     b90:	000b0513          	mv	a0,s6
     b94:	d95ff0ef          	jal	928 <printint>
        i += 1;
     b98:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
     b9c:	00048b93          	mv	s7,s1
      state = 0;
     ba0:	00000993          	li	s3,0
     ba4:	ed5ff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
     ba8:	008b8493          	addi	s1,s7,8
     bac:	00000693          	li	a3,0
     bb0:	00a00613          	li	a2,10
     bb4:	000bb583          	ld	a1,0(s7)
     bb8:	000b0513          	mv	a0,s6
     bbc:	d6dff0ef          	jal	928 <printint>
        i += 2;
     bc0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
     bc4:	00048b93          	mv	s7,s1
      state = 0;
     bc8:	00000993          	li	s3,0
        i += 2;
     bcc:	eadff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
     bd0:	008b8493          	addi	s1,s7,8
     bd4:	00000693          	li	a3,0
     bd8:	01000613          	li	a2,16
     bdc:	000be583          	lwu	a1,0(s7)
     be0:	000b0513          	mv	a0,s6
     be4:	d45ff0ef          	jal	928 <printint>
     be8:	00048b93          	mv	s7,s1
      state = 0;
     bec:	00000993          	li	s3,0
     bf0:	e89ff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
     bf4:	008b8493          	addi	s1,s7,8
     bf8:	00000693          	li	a3,0
     bfc:	01000613          	li	a2,16
     c00:	000bb583          	ld	a1,0(s7)
     c04:	000b0513          	mv	a0,s6
     c08:	d21ff0ef          	jal	928 <printint>
        i += 1;
     c0c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
     c10:	00048b93          	mv	s7,s1
      state = 0;
     c14:	00000993          	li	s3,0
     c18:	e61ff06f          	j	a78 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
     c1c:	008b8493          	addi	s1,s7,8
     c20:	00000693          	li	a3,0
     c24:	01000613          	li	a2,16
     c28:	000bb583          	ld	a1,0(s7)
     c2c:	000b0513          	mv	a0,s6
     c30:	cf9ff0ef          	jal	928 <printint>
        i += 2;
     c34:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
     c38:	00048b93          	mv	s7,s1
      state = 0;
     c3c:	00000993          	li	s3,0
        i += 2;
     c40:	e39ff06f          	j	a78 <vprintf+0x70>
     c44:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
     c48:	008b8793          	addi	a5,s7,8
     c4c:	00078c93          	mv	s9,a5
     c50:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
     c54:	03000593          	li	a1,48
     c58:	000b0513          	mv	a0,s6
     c5c:	c3dff0ef          	jal	898 <putc>
  putc(fd, 'x');
     c60:	07800593          	li	a1,120
     c64:	000b0513          	mv	a0,s6
     c68:	c31ff0ef          	jal	898 <putc>
     c6c:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
     c70:	00000b97          	auipc	s7,0x0
     c74:	4a8b8b93          	addi	s7,s7,1192 # 1118 <digits>
     c78:	03c9d793          	srli	a5,s3,0x3c
     c7c:	00fb87b3          	add	a5,s7,a5
     c80:	0007c583          	lbu	a1,0(a5)
     c84:	000b0513          	mv	a0,s6
     c88:	c11ff0ef          	jal	898 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
     c8c:	00499993          	slli	s3,s3,0x4
     c90:	fff4849b          	addiw	s1,s1,-1
     c94:	fe0492e3          	bnez	s1,c78 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
     c98:	000c8b93          	mv	s7,s9
      state = 0;
     c9c:	00000993          	li	s3,0
     ca0:	00813c83          	ld	s9,8(sp)
     ca4:	dd5ff06f          	j	a78 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
     ca8:	008b8493          	addi	s1,s7,8
     cac:	000bc583          	lbu	a1,0(s7)
     cb0:	000b0513          	mv	a0,s6
     cb4:	be5ff0ef          	jal	898 <putc>
     cb8:	00048b93          	mv	s7,s1
      state = 0;
     cbc:	00000993          	li	s3,0
     cc0:	db9ff06f          	j	a78 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
     cc4:	008b8993          	addi	s3,s7,8
     cc8:	000bb483          	ld	s1,0(s7)
     ccc:	02048663          	beqz	s1,cf8 <vprintf+0x2f0>
        for (; *s; s++)
     cd0:	0004c583          	lbu	a1,0(s1)
     cd4:	04058463          	beqz	a1,d1c <vprintf+0x314>
          putc(fd, *s);
     cd8:	000b0513          	mv	a0,s6
     cdc:	bbdff0ef          	jal	898 <putc>
        for (; *s; s++)
     ce0:	00148493          	addi	s1,s1,1
     ce4:	0004c583          	lbu	a1,0(s1)
     ce8:	fe0598e3          	bnez	a1,cd8 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
     cec:	00098b93          	mv	s7,s3
      state = 0;
     cf0:	00000993          	li	s3,0
     cf4:	d85ff06f          	j	a78 <vprintf+0x70>
          s = "(null)";
     cf8:	00000497          	auipc	s1,0x0
     cfc:	41848493          	addi	s1,s1,1048 # 1110 <malloc+0x1d0>
        for (; *s; s++)
     d00:	02800593          	li	a1,40
     d04:	fd5ff06f          	j	cd8 <vprintf+0x2d0>
        putc(fd, '%');
     d08:	00078593          	mv	a1,a5
     d0c:	000b0513          	mv	a0,s6
     d10:	b89ff0ef          	jal	898 <putc>
      state = 0;
     d14:	00000993          	li	s3,0
     d18:	d61ff06f          	j	a78 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
     d1c:	00098b93          	mv	s7,s3
      state = 0;
     d20:	00000993          	li	s3,0
     d24:	d55ff06f          	j	a78 <vprintf+0x70>
     d28:	04013903          	ld	s2,64(sp)
     d2c:	03813983          	ld	s3,56(sp)
     d30:	03013a03          	ld	s4,48(sp)
     d34:	02813a83          	ld	s5,40(sp)
     d38:	02013b03          	ld	s6,32(sp)
     d3c:	01813b83          	ld	s7,24(sp)
     d40:	01013c03          	ld	s8,16(sp)
    }
  }
}
     d44:	05813083          	ld	ra,88(sp)
     d48:	05013403          	ld	s0,80(sp)
     d4c:	04813483          	ld	s1,72(sp)
     d50:	06010113          	addi	sp,sp,96
     d54:	00008067          	ret
      if (c0 == 'd')
     d58:	06400713          	li	a4,100
     d5c:	d8e78ae3          	beq	a5,a4,af0 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
     d60:	f9478693          	addi	a3,a5,-108
     d64:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
     d68:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
     d6c:	00000713          	li	a4,0
      else if (c0 == 'u')
     d70:	07500513          	li	a0,117
     d74:	dea784e3          	beq	a5,a0,b5c <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
     d78:	f8b60513          	addi	a0,a2,-117
     d7c:	00051463          	bnez	a0,d84 <vprintf+0x37c>
     d80:	e00690e3          	bnez	a3,b80 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
     d84:	f8b58513          	addi	a0,a1,-117
     d88:	00051463          	bnez	a0,d90 <vprintf+0x388>
     d8c:	e0071ee3          	bnez	a4,ba8 <vprintf+0x1a0>
      else if (c0 == 'x')
     d90:	07800513          	li	a0,120
     d94:	e2a78ee3          	beq	a5,a0,bd0 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
     d98:	f8860613          	addi	a2,a2,-120
     d9c:	00061463          	bnez	a2,da4 <vprintf+0x39c>
     da0:	e4069ae3          	bnez	a3,bf4 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
     da4:	f8858593          	addi	a1,a1,-120
     da8:	00059463          	bnez	a1,db0 <vprintf+0x3a8>
     dac:	e60718e3          	bnez	a4,c1c <vprintf+0x214>
      else if (c0 == 'p')
     db0:	07000713          	li	a4,112
     db4:	e8e788e3          	beq	a5,a4,c44 <vprintf+0x23c>
      else if (c0 == 'c')
     db8:	06300713          	li	a4,99
     dbc:	eee786e3          	beq	a5,a4,ca8 <vprintf+0x2a0>
      else if (c0 == 's')
     dc0:	07300713          	li	a4,115
     dc4:	f0e780e3          	beq	a5,a4,cc4 <vprintf+0x2bc>
      else if (c0 == '%')
     dc8:	02500713          	li	a4,37
     dcc:	f2e78ee3          	beq	a5,a4,d08 <vprintf+0x300>
        putc(fd, '%');
     dd0:	02500593          	li	a1,37
     dd4:	000b0513          	mv	a0,s6
     dd8:	ac1ff0ef          	jal	898 <putc>
        putc(fd, c0);
     ddc:	00048593          	mv	a1,s1
     de0:	000b0513          	mv	a0,s6
     de4:	ab5ff0ef          	jal	898 <putc>
      state = 0;
     de8:	00000993          	li	s3,0
     dec:	c8dff06f          	j	a78 <vprintf+0x70>

0000000000000df0 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
     df0:	fb010113          	addi	sp,sp,-80
     df4:	00113c23          	sd	ra,24(sp)
     df8:	00813823          	sd	s0,16(sp)
     dfc:	02010413          	addi	s0,sp,32
     e00:	00c43023          	sd	a2,0(s0)
     e04:	00d43423          	sd	a3,8(s0)
     e08:	00e43823          	sd	a4,16(s0)
     e0c:	00f43c23          	sd	a5,24(s0)
     e10:	03043023          	sd	a6,32(s0)
     e14:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
     e18:	00040613          	mv	a2,s0
     e1c:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
     e20:	be9ff0ef          	jal	a08 <vprintf>
}
     e24:	01813083          	ld	ra,24(sp)
     e28:	01013403          	ld	s0,16(sp)
     e2c:	05010113          	addi	sp,sp,80
     e30:	00008067          	ret

0000000000000e34 <printf>:

void printf(const char *fmt, ...)
{
     e34:	fa010113          	addi	sp,sp,-96
     e38:	00113c23          	sd	ra,24(sp)
     e3c:	00813823          	sd	s0,16(sp)
     e40:	02010413          	addi	s0,sp,32
     e44:	00b43423          	sd	a1,8(s0)
     e48:	00c43823          	sd	a2,16(s0)
     e4c:	00d43c23          	sd	a3,24(s0)
     e50:	02e43023          	sd	a4,32(s0)
     e54:	02f43423          	sd	a5,40(s0)
     e58:	03043823          	sd	a6,48(s0)
     e5c:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
     e60:	00840613          	addi	a2,s0,8
     e64:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
     e68:	00050593          	mv	a1,a0
     e6c:	00100513          	li	a0,1
     e70:	b99ff0ef          	jal	a08 <vprintf>
  putc_flush();
     e74:	9d9ff0ef          	jal	84c <putc_flush>
}
     e78:	01813083          	ld	ra,24(sp)
     e7c:	01013403          	ld	s0,16(sp)
     e80:	06010113          	addi	sp,sp,96
     e84:	00008067          	ret

0000000000000e88 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
     e88:	ff010113          	addi	sp,sp,-16
     e8c:	00113423          	sd	ra,8(sp)
     e90:	00813023          	sd	s0,0(sp)
     e94:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
     e98:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
     e9c:	00001797          	auipc	a5,0x1
     ea0:	17c7b783          	ld	a5,380(a5) # 2018 <freep>
     ea4:	0140006f          	j	eb8 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
     ea8:	0007b703          	ld	a4,0(a5)
     eac:	00e7e463          	bltu	a5,a4,eb4 <free+0x2c>
     eb0:	00e6ec63          	bltu	a3,a4,ec8 <free+0x40>
{
     eb4:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
     eb8:	fed7f8e3          	bgeu	a5,a3,ea8 <free+0x20>
     ebc:	0007b703          	ld	a4,0(a5)
     ec0:	00e6e463          	bltu	a3,a4,ec8 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
     ec4:	fee7e8e3          	bltu	a5,a4,eb4 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
     ec8:	ff852583          	lw	a1,-8(a0)
     ecc:	0007b603          	ld	a2,0(a5)
     ed0:	02059813          	slli	a6,a1,0x20
     ed4:	01c85713          	srli	a4,a6,0x1c
     ed8:	00e68733          	add	a4,a3,a4
     edc:	02e60c63          	beq	a2,a4,f14 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
     ee0:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
     ee4:	0087a603          	lw	a2,8(a5)
     ee8:	02061593          	slli	a1,a2,0x20
     eec:	01c5d713          	srli	a4,a1,0x1c
     ef0:	00e78733          	add	a4,a5,a4
     ef4:	02e68c63          	beq	a3,a4,f2c <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
     ef8:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
     efc:	00001717          	auipc	a4,0x1
     f00:	10f73e23          	sd	a5,284(a4) # 2018 <freep>
}
     f04:	00813083          	ld	ra,8(sp)
     f08:	00013403          	ld	s0,0(sp)
     f0c:	01010113          	addi	sp,sp,16
     f10:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
     f14:	00862703          	lw	a4,8(a2)
     f18:	00b7073b          	addw	a4,a4,a1
     f1c:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
     f20:	0007b703          	ld	a4,0(a5)
     f24:	00073603          	ld	a2,0(a4)
     f28:	fb9ff06f          	j	ee0 <free+0x58>
    p->s.size += bp->s.size;
     f2c:	ff852703          	lw	a4,-8(a0)
     f30:	00c7073b          	addw	a4,a4,a2
     f34:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
     f38:	ff053683          	ld	a3,-16(a0)
     f3c:	fbdff06f          	j	ef8 <free+0x70>

0000000000000f40 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
     f40:	fc010113          	addi	sp,sp,-64
     f44:	02113c23          	sd	ra,56(sp)
     f48:	02813823          	sd	s0,48(sp)
     f4c:	03213023          	sd	s2,32(sp)
     f50:	01313c23          	sd	s3,24(sp)
     f54:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
     f58:	02051993          	slli	s3,a0,0x20
     f5c:	0209d993          	srli	s3,s3,0x20
     f60:	00f98993          	addi	s3,s3,15
     f64:	0049d993          	srli	s3,s3,0x4
     f68:	0019899b          	addiw	s3,s3,1
     f6c:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
     f70:	00001517          	auipc	a0,0x1
     f74:	0a853503          	ld	a0,168(a0) # 2018 <freep>
     f78:	04050463          	beqz	a0,fc0 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
     f7c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
     f80:	0087a703          	lw	a4,8(a5)
     f84:	0d377a63          	bgeu	a4,s3,1058 <malloc+0x118>
     f88:	02913423          	sd	s1,40(sp)
     f8c:	01413823          	sd	s4,16(sp)
     f90:	01513423          	sd	s5,8(sp)
     f94:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
     f98:	00098a13          	mv	s4,s3
     f9c:	00001737          	lui	a4,0x1
     fa0:	00e9f463          	bgeu	s3,a4,fa8 <malloc+0x68>
     fa4:	00001a37          	lui	s4,0x1
     fa8:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
     fac:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
     fb0:	00001497          	auipc	s1,0x1
     fb4:	06848493          	addi	s1,s1,104 # 2018 <freep>
  if(p == SBRK_ERROR)
     fb8:	fff00a93          	li	s5,-1
     fbc:	05c0006f          	j	1018 <malloc+0xd8>
     fc0:	02913423          	sd	s1,40(sp)
     fc4:	01413823          	sd	s4,16(sp)
     fc8:	01513423          	sd	s5,8(sp)
     fcc:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
     fd0:	00001797          	auipc	a5,0x1
     fd4:	0e078793          	addi	a5,a5,224 # 20b0 <base>
     fd8:	00001717          	auipc	a4,0x1
     fdc:	04f73023          	sd	a5,64(a4) # 2018 <freep>
     fe0:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
     fe4:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
     fe8:	fb1ff06f          	j	f98 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
     fec:	0007b703          	ld	a4,0(a5)
     ff0:	00e53023          	sd	a4,0(a0)
     ff4:	0800006f          	j	1074 <malloc+0x134>
  hp->s.size = nu;
     ff8:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
     ffc:	01050513          	addi	a0,a0,16
    1000:	e89ff0ef          	jal	e88 <free>
  return freep;
    1004:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    1008:	08050863          	beqz	a0,1098 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    100c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1010:	0087a703          	lw	a4,8(a5)
    1014:	03277a63          	bgeu	a4,s2,1048 <malloc+0x108>
    if(p == freep)
    1018:	0004b703          	ld	a4,0(s1)
    101c:	00078513          	mv	a0,a5
    1020:	fef716e3          	bne	a4,a5,100c <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    1024:	000a0513          	mv	a0,s4
    1028:	ed8ff0ef          	jal	700 <sbrk>
  if(p == SBRK_ERROR)
    102c:	fd5516e3          	bne	a0,s5,ff8 <malloc+0xb8>
        return 0;
    1030:	00000513          	li	a0,0
    1034:	02813483          	ld	s1,40(sp)
    1038:	01013a03          	ld	s4,16(sp)
    103c:	00813a83          	ld	s5,8(sp)
    1040:	00013b03          	ld	s6,0(sp)
    1044:	03c0006f          	j	1080 <malloc+0x140>
    1048:	02813483          	ld	s1,40(sp)
    104c:	01013a03          	ld	s4,16(sp)
    1050:	00813a83          	ld	s5,8(sp)
    1054:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    1058:	f8e90ae3          	beq	s2,a4,fec <malloc+0xac>
        p->s.size -= nunits;
    105c:	4137073b          	subw	a4,a4,s3
    1060:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    1064:	02071693          	slli	a3,a4,0x20
    1068:	01c6d713          	srli	a4,a3,0x1c
    106c:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    1070:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    1074:	00001717          	auipc	a4,0x1
    1078:	faa73223          	sd	a0,-92(a4) # 2018 <freep>
      return (void*)(p + 1);
    107c:	01078513          	addi	a0,a5,16
  }
}
    1080:	03813083          	ld	ra,56(sp)
    1084:	03013403          	ld	s0,48(sp)
    1088:	02013903          	ld	s2,32(sp)
    108c:	01813983          	ld	s3,24(sp)
    1090:	04010113          	addi	sp,sp,64
    1094:	00008067          	ret
    1098:	02813483          	ld	s1,40(sp)
    109c:	01013a03          	ld	s4,16(sp)
    10a0:	00813a83          	ld	s5,8(sp)
    10a4:	00013b03          	ld	s6,0(sp)
    10a8:	fd9ff06f          	j	1080 <malloc+0x140>
