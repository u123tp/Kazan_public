
user/_stressfs:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
   0:	dc010113          	addi	sp,sp,-576
   4:	22113c23          	sd	ra,568(sp)
   8:	22813823          	sd	s0,560(sp)
   c:	22913423          	sd	s1,552(sp)
  10:	23213023          	sd	s2,544(sp)
  14:	21313c23          	sd	s3,536(sp)
  18:	21413823          	sd	s4,528(sp)
  1c:	24010413          	addi	s0,sp,576
  int fd, i;
  char path[] = "stressfs0";
  20:	00001797          	auipc	a5,0x1
  24:	ee078793          	addi	a5,a5,-288 # f00 <malloc+0x1a0>
  28:	0007b703          	ld	a4,0(a5)
  2c:	fce43023          	sd	a4,-64(s0)
  30:	0087d783          	lhu	a5,8(a5)
  34:	fcf41423          	sh	a5,-56(s0)
  char data[512];

  printf("stressfs starting\n");
  38:	00001517          	auipc	a0,0x1
  3c:	e9850513          	addi	a0,a0,-360 # ed0 <malloc+0x170>
  40:	415000ef          	jal	c54 <printf>
  memset(data, 'a', sizeof(data));
  44:	20000613          	li	a2,512
  48:	06100593          	li	a1,97
  4c:	dc040513          	addi	a0,s0,-576
  50:	1ac000ef          	jal	1fc <memset>

  for(i = 0; i < 4; i++)
  54:	00000493          	li	s1,0
  58:	00400913          	li	s2,4
    if(fork() > 0)
  5c:	514000ef          	jal	570 <fork>
  60:	00a04663          	bgtz	a0,6c <main+0x6c>
  for(i = 0; i < 4; i++)
  64:	0014849b          	addiw	s1,s1,1
  68:	ff249ae3          	bne	s1,s2,5c <main+0x5c>
      break;

  printf("write %d\n", i);
  6c:	00048593          	mv	a1,s1
  70:	00001517          	auipc	a0,0x1
  74:	e7850513          	addi	a0,a0,-392 # ee8 <malloc+0x188>
  78:	3dd000ef          	jal	c54 <printf>

  path[8] += i;
  7c:	fc844783          	lbu	a5,-56(s0)
  80:	009787bb          	addw	a5,a5,s1
  84:	fcf40423          	sb	a5,-56(s0)
  fd = open(path, O_CREATE | O_RDWR);
  88:	20200593          	li	a1,514
  8c:	fc040513          	addi	a0,s0,-64
  90:	54c000ef          	jal	5dc <open>
  94:	00050913          	mv	s2,a0
  98:	01400493          	li	s1,20
  for(i = 0; i < 20; i++)
//    printf(fd, "%d\n", i);
    write(fd, data, sizeof(data));
  9c:	dc040a13          	addi	s4,s0,-576
  a0:	20000993          	li	s3,512
  a4:	00098613          	mv	a2,s3
  a8:	000a0593          	mv	a1,s4
  ac:	00090513          	mv	a0,s2
  b0:	4fc000ef          	jal	5ac <write>
  for(i = 0; i < 20; i++)
  b4:	fff4849b          	addiw	s1,s1,-1
  b8:	fe0496e3          	bnez	s1,a4 <main+0xa4>
  close(fd);
  bc:	00090513          	mv	a0,s2
  c0:	4f8000ef          	jal	5b8 <close>

  printf("read\n");
  c4:	00001517          	auipc	a0,0x1
  c8:	e3450513          	addi	a0,a0,-460 # ef8 <malloc+0x198>
  cc:	389000ef          	jal	c54 <printf>

  fd = open(path, O_RDONLY);
  d0:	00000593          	li	a1,0
  d4:	fc040513          	addi	a0,s0,-64
  d8:	504000ef          	jal	5dc <open>
  dc:	00050913          	mv	s2,a0
  e0:	01400493          	li	s1,20
  for (i = 0; i < 20; i++)
    read(fd, data, sizeof(data));
  e4:	dc040a13          	addi	s4,s0,-576
  e8:	20000993          	li	s3,512
  ec:	00098613          	mv	a2,s3
  f0:	000a0593          	mv	a1,s4
  f4:	00090513          	mv	a0,s2
  f8:	4a8000ef          	jal	5a0 <read>
  for (i = 0; i < 20; i++)
  fc:	fff4849b          	addiw	s1,s1,-1
 100:	fe0496e3          	bnez	s1,ec <main+0xec>
  close(fd);
 104:	00090513          	mv	a0,s2
 108:	4b0000ef          	jal	5b8 <close>

  wait(0);
 10c:	00000513          	li	a0,0
 110:	478000ef          	jal	588 <wait>

  exit(0);
 114:	00000513          	li	a0,0
 118:	464000ef          	jal	57c <exit>

000000000000011c <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
 11c:	ff010113          	addi	sp,sp,-16
 120:	00113423          	sd	ra,8(sp)
 124:	00813023          	sd	s0,0(sp)
 128:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
 12c:	ed5ff0ef          	jal	0 <main>
  exit(r);
 130:	44c000ef          	jal	57c <exit>

0000000000000134 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 134:	ff010113          	addi	sp,sp,-16
 138:	00113423          	sd	ra,8(sp)
 13c:	00813023          	sd	s0,0(sp)
 140:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 144:	00050793          	mv	a5,a0
 148:	00158593          	addi	a1,a1,1
 14c:	00178793          	addi	a5,a5,1
 150:	fff5c703          	lbu	a4,-1(a1)
 154:	fee78fa3          	sb	a4,-1(a5)
 158:	fe0718e3          	bnez	a4,148 <strcpy+0x14>
    ;
  return os;
}
 15c:	00813083          	ld	ra,8(sp)
 160:	00013403          	ld	s0,0(sp)
 164:	01010113          	addi	sp,sp,16
 168:	00008067          	ret

000000000000016c <strcmp>:

int
strcmp(const char *p, const char *q)
{
 16c:	ff010113          	addi	sp,sp,-16
 170:	00113423          	sd	ra,8(sp)
 174:	00813023          	sd	s0,0(sp)
 178:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 17c:	00054783          	lbu	a5,0(a0)
 180:	00078e63          	beqz	a5,19c <strcmp+0x30>
 184:	0005c703          	lbu	a4,0(a1)
 188:	00f71a63          	bne	a4,a5,19c <strcmp+0x30>
    p++, q++;
 18c:	00150513          	addi	a0,a0,1
 190:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 194:	00054783          	lbu	a5,0(a0)
 198:	fe0796e3          	bnez	a5,184 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 19c:	0005c503          	lbu	a0,0(a1)
}
 1a0:	40a7853b          	subw	a0,a5,a0
 1a4:	00813083          	ld	ra,8(sp)
 1a8:	00013403          	ld	s0,0(sp)
 1ac:	01010113          	addi	sp,sp,16
 1b0:	00008067          	ret

00000000000001b4 <strlen>:

uint
strlen(const char *s)
{
 1b4:	ff010113          	addi	sp,sp,-16
 1b8:	00113423          	sd	ra,8(sp)
 1bc:	00813023          	sd	s0,0(sp)
 1c0:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 1c4:	00054783          	lbu	a5,0(a0)
 1c8:	02078663          	beqz	a5,1f4 <strlen+0x40>
 1cc:	00150793          	addi	a5,a0,1
 1d0:	00078693          	mv	a3,a5
 1d4:	00178793          	addi	a5,a5,1
 1d8:	fff7c703          	lbu	a4,-1(a5)
 1dc:	fe071ae3          	bnez	a4,1d0 <strlen+0x1c>
 1e0:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 1e4:	00813083          	ld	ra,8(sp)
 1e8:	00013403          	ld	s0,0(sp)
 1ec:	01010113          	addi	sp,sp,16
 1f0:	00008067          	ret
  for(n = 0; s[n]; n++)
 1f4:	00000513          	li	a0,0
 1f8:	fedff06f          	j	1e4 <strlen+0x30>

00000000000001fc <memset>:

void*
memset(void *dst, int c, uint n)
{
 1fc:	ff010113          	addi	sp,sp,-16
 200:	00113423          	sd	ra,8(sp)
 204:	00813023          	sd	s0,0(sp)
 208:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 20c:	02060063          	beqz	a2,22c <memset+0x30>
 210:	00050793          	mv	a5,a0
 214:	02061613          	slli	a2,a2,0x20
 218:	02065613          	srli	a2,a2,0x20
 21c:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 220:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 224:	00178793          	addi	a5,a5,1
 228:	fee79ce3          	bne	a5,a4,220 <memset+0x24>
  }
  return dst;
}
 22c:	00813083          	ld	ra,8(sp)
 230:	00013403          	ld	s0,0(sp)
 234:	01010113          	addi	sp,sp,16
 238:	00008067          	ret

000000000000023c <strchr>:

char*
strchr(const char *s, char c)
{
 23c:	ff010113          	addi	sp,sp,-16
 240:	00113423          	sd	ra,8(sp)
 244:	00813023          	sd	s0,0(sp)
 248:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 24c:	00054783          	lbu	a5,0(a0)
 250:	02078463          	beqz	a5,278 <strchr+0x3c>
    if(*s == c)
 254:	00f58a63          	beq	a1,a5,268 <strchr+0x2c>
  for(; *s; s++)
 258:	00150513          	addi	a0,a0,1
 25c:	00054783          	lbu	a5,0(a0)
 260:	fe079ae3          	bnez	a5,254 <strchr+0x18>
      return (char*)s;
  return 0;
 264:	00000513          	li	a0,0
}
 268:	00813083          	ld	ra,8(sp)
 26c:	00013403          	ld	s0,0(sp)
 270:	01010113          	addi	sp,sp,16
 274:	00008067          	ret
  return 0;
 278:	00000513          	li	a0,0
 27c:	fedff06f          	j	268 <strchr+0x2c>

0000000000000280 <gets>:

char*
gets(char *buf, int max)
{
 280:	fa010113          	addi	sp,sp,-96
 284:	04113c23          	sd	ra,88(sp)
 288:	04813823          	sd	s0,80(sp)
 28c:	04913423          	sd	s1,72(sp)
 290:	05213023          	sd	s2,64(sp)
 294:	03313c23          	sd	s3,56(sp)
 298:	03413823          	sd	s4,48(sp)
 29c:	03513423          	sd	s5,40(sp)
 2a0:	03613023          	sd	s6,32(sp)
 2a4:	01713c23          	sd	s7,24(sp)
 2a8:	01813823          	sd	s8,16(sp)
 2ac:	06010413          	addi	s0,sp,96
 2b0:	00050b93          	mv	s7,a0
 2b4:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 2b8:	00050913          	mv	s2,a0
 2bc:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 2c0:	faf40b13          	addi	s6,s0,-81
 2c4:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 2c8:	00048c13          	mv	s8,s1
 2cc:	0014899b          	addiw	s3,s1,1
 2d0:	00098493          	mv	s1,s3
 2d4:	0349dc63          	bge	s3,s4,30c <gets+0x8c>
    cc = read(0, &c, 1);
 2d8:	000a8613          	mv	a2,s5
 2dc:	000b0593          	mv	a1,s6
 2e0:	00000513          	li	a0,0
 2e4:	2bc000ef          	jal	5a0 <read>
    if(cc < 1)
 2e8:	02a05263          	blez	a0,30c <gets+0x8c>
      break;
    buf[i++] = c;
 2ec:	faf44783          	lbu	a5,-81(s0)
 2f0:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 2f4:	00190913          	addi	s2,s2,1
 2f8:	ff678713          	addi	a4,a5,-10
 2fc:	00070663          	beqz	a4,308 <gets+0x88>
 300:	ff378793          	addi	a5,a5,-13
 304:	fc0792e3          	bnez	a5,2c8 <gets+0x48>
    buf[i++] = c;
 308:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 30c:	018b8c33          	add	s8,s7,s8
 310:	000c0023          	sb	zero,0(s8)
  return buf;
}
 314:	000b8513          	mv	a0,s7
 318:	05813083          	ld	ra,88(sp)
 31c:	05013403          	ld	s0,80(sp)
 320:	04813483          	ld	s1,72(sp)
 324:	04013903          	ld	s2,64(sp)
 328:	03813983          	ld	s3,56(sp)
 32c:	03013a03          	ld	s4,48(sp)
 330:	02813a83          	ld	s5,40(sp)
 334:	02013b03          	ld	s6,32(sp)
 338:	01813b83          	ld	s7,24(sp)
 33c:	01013c03          	ld	s8,16(sp)
 340:	06010113          	addi	sp,sp,96
 344:	00008067          	ret

0000000000000348 <stat>:

int
stat(const char *n, struct stat *st)
{
 348:	fe010113          	addi	sp,sp,-32
 34c:	00113c23          	sd	ra,24(sp)
 350:	00813823          	sd	s0,16(sp)
 354:	01213023          	sd	s2,0(sp)
 358:	02010413          	addi	s0,sp,32
 35c:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 360:	00000593          	li	a1,0
 364:	278000ef          	jal	5dc <open>
  if(fd < 0)
 368:	02054e63          	bltz	a0,3a4 <stat+0x5c>
 36c:	00913423          	sd	s1,8(sp)
 370:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 374:	00090593          	mv	a1,s2
 378:	288000ef          	jal	600 <fstat>
 37c:	00050913          	mv	s2,a0
  close(fd);
 380:	00048513          	mv	a0,s1
 384:	234000ef          	jal	5b8 <close>
  return r;
 388:	00813483          	ld	s1,8(sp)
}
 38c:	00090513          	mv	a0,s2
 390:	01813083          	ld	ra,24(sp)
 394:	01013403          	ld	s0,16(sp)
 398:	00013903          	ld	s2,0(sp)
 39c:	02010113          	addi	sp,sp,32
 3a0:	00008067          	ret
    return -1;
 3a4:	fff00793          	li	a5,-1
 3a8:	00078913          	mv	s2,a5
 3ac:	fe1ff06f          	j	38c <stat+0x44>

00000000000003b0 <atoi>:

int
atoi(const char *s)
{
 3b0:	ff010113          	addi	sp,sp,-16
 3b4:	00113423          	sd	ra,8(sp)
 3b8:	00813023          	sd	s0,0(sp)
 3bc:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 3c0:	00054683          	lbu	a3,0(a0)
 3c4:	fd06879b          	addiw	a5,a3,-48
 3c8:	0ff7f793          	zext.b	a5,a5
 3cc:	00900613          	li	a2,9
 3d0:	04f66263          	bltu	a2,a5,414 <atoi+0x64>
 3d4:	00050713          	mv	a4,a0
  n = 0;
 3d8:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 3dc:	00170713          	addi	a4,a4,1
 3e0:	0025179b          	slliw	a5,a0,0x2
 3e4:	00a787bb          	addw	a5,a5,a0
 3e8:	0017979b          	slliw	a5,a5,0x1
 3ec:	00d787bb          	addw	a5,a5,a3
 3f0:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 3f4:	00074683          	lbu	a3,0(a4)
 3f8:	fd06879b          	addiw	a5,a3,-48
 3fc:	0ff7f793          	zext.b	a5,a5
 400:	fcf67ee3          	bgeu	a2,a5,3dc <atoi+0x2c>
  return n;
}
 404:	00813083          	ld	ra,8(sp)
 408:	00013403          	ld	s0,0(sp)
 40c:	01010113          	addi	sp,sp,16
 410:	00008067          	ret
  n = 0;
 414:	00000513          	li	a0,0
 418:	fedff06f          	j	404 <atoi+0x54>

000000000000041c <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 41c:	ff010113          	addi	sp,sp,-16
 420:	00113423          	sd	ra,8(sp)
 424:	00813023          	sd	s0,0(sp)
 428:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 42c:	02b57e63          	bgeu	a0,a1,468 <memmove+0x4c>
    while(n-- > 0)
 430:	02c05463          	blez	a2,458 <memmove+0x3c>
 434:	02061613          	slli	a2,a2,0x20
 438:	02065613          	srli	a2,a2,0x20
 43c:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 440:	00050713          	mv	a4,a0
      *dst++ = *src++;
 444:	00158593          	addi	a1,a1,1
 448:	00170713          	addi	a4,a4,1
 44c:	fff5c683          	lbu	a3,-1(a1)
 450:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 454:	fee798e3          	bne	a5,a4,444 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 458:	00813083          	ld	ra,8(sp)
 45c:	00013403          	ld	s0,0(sp)
 460:	01010113          	addi	sp,sp,16
 464:	00008067          	ret
    while(n-- > 0)
 468:	fec058e3          	blez	a2,458 <memmove+0x3c>
    dst += n;
 46c:	00c50733          	add	a4,a0,a2
    src += n;
 470:	00c585b3          	add	a1,a1,a2
 474:	fff6079b          	addiw	a5,a2,-1
 478:	02079793          	slli	a5,a5,0x20
 47c:	0207d793          	srli	a5,a5,0x20
 480:	fff7c793          	not	a5,a5
 484:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 488:	fff58593          	addi	a1,a1,-1
 48c:	fff70713          	addi	a4,a4,-1
 490:	0005c683          	lbu	a3,0(a1)
 494:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 498:	fef718e3          	bne	a4,a5,488 <memmove+0x6c>
 49c:	fbdff06f          	j	458 <memmove+0x3c>

00000000000004a0 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 4a0:	ff010113          	addi	sp,sp,-16
 4a4:	00113423          	sd	ra,8(sp)
 4a8:	00813023          	sd	s0,0(sp)
 4ac:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 4b0:	04060263          	beqz	a2,4f4 <memcmp+0x54>
 4b4:	02061613          	slli	a2,a2,0x20
 4b8:	02065613          	srli	a2,a2,0x20
 4bc:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 4c0:	00054783          	lbu	a5,0(a0)
 4c4:	0005c703          	lbu	a4,0(a1)
 4c8:	00e79c63          	bne	a5,a4,4e0 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 4cc:	00150513          	addi	a0,a0,1
    p2++;
 4d0:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 4d4:	fed516e3          	bne	a0,a3,4c0 <memcmp+0x20>
  }
  return 0;
 4d8:	00000513          	li	a0,0
 4dc:	0080006f          	j	4e4 <memcmp+0x44>
      return *p1 - *p2;
 4e0:	40e7853b          	subw	a0,a5,a4
}
 4e4:	00813083          	ld	ra,8(sp)
 4e8:	00013403          	ld	s0,0(sp)
 4ec:	01010113          	addi	sp,sp,16
 4f0:	00008067          	ret
  return 0;
 4f4:	00000513          	li	a0,0
 4f8:	fedff06f          	j	4e4 <memcmp+0x44>

00000000000004fc <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 4fc:	ff010113          	addi	sp,sp,-16
 500:	00113423          	sd	ra,8(sp)
 504:	00813023          	sd	s0,0(sp)
 508:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 50c:	f11ff0ef          	jal	41c <memmove>
}
 510:	00813083          	ld	ra,8(sp)
 514:	00013403          	ld	s0,0(sp)
 518:	01010113          	addi	sp,sp,16
 51c:	00008067          	ret

0000000000000520 <sbrk>:

char *
sbrk(int n) {
 520:	ff010113          	addi	sp,sp,-16
 524:	00113423          	sd	ra,8(sp)
 528:	00813023          	sd	s0,0(sp)
 52c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 530:	00100593          	li	a1,1
 534:	114000ef          	jal	648 <sys_sbrk>
}
 538:	00813083          	ld	ra,8(sp)
 53c:	00013403          	ld	s0,0(sp)
 540:	01010113          	addi	sp,sp,16
 544:	00008067          	ret

0000000000000548 <sbrklazy>:

char *
sbrklazy(int n) {
 548:	ff010113          	addi	sp,sp,-16
 54c:	00113423          	sd	ra,8(sp)
 550:	00813023          	sd	s0,0(sp)
 554:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 558:	00200593          	li	a1,2
 55c:	0ec000ef          	jal	648 <sys_sbrk>
}
 560:	00813083          	ld	ra,8(sp)
 564:	00013403          	ld	s0,0(sp)
 568:	01010113          	addi	sp,sp,16
 56c:	00008067          	ret

0000000000000570 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 570:	00100893          	li	a7,1
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <exit>:
.global exit
exit:
 li a7, SYS_exit
 57c:	00200893          	li	a7,2
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <wait>:
.global wait
wait:
 li a7, SYS_wait
 588:	00300893          	li	a7,3
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 594:	00400893          	li	a7,4
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <read>:
.global read
read:
 li a7, SYS_read
 5a0:	00500893          	li	a7,5
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <write>:
.global write
write:
 li a7, SYS_write
 5ac:	01000893          	li	a7,16
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <close>:
.global close
close:
 li a7, SYS_close
 5b8:	01500893          	li	a7,21
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <kill>:
.global kill
kill:
 li a7, SYS_kill
 5c4:	00600893          	li	a7,6
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <exec>:
.global exec
exec:
 li a7, SYS_exec
 5d0:	00700893          	li	a7,7
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <open>:
.global open
open:
 li a7, SYS_open
 5dc:	00f00893          	li	a7,15
 ecall
 5e0:	00000073          	ecall
 ret
 5e4:	00008067          	ret

00000000000005e8 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 5e8:	01100893          	li	a7,17
 ecall
 5ec:	00000073          	ecall
 ret
 5f0:	00008067          	ret

00000000000005f4 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 5f4:	01200893          	li	a7,18
 ecall
 5f8:	00000073          	ecall
 ret
 5fc:	00008067          	ret

0000000000000600 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 600:	00800893          	li	a7,8
 ecall
 604:	00000073          	ecall
 ret
 608:	00008067          	ret

000000000000060c <link>:
.global link
link:
 li a7, SYS_link
 60c:	01300893          	li	a7,19
 ecall
 610:	00000073          	ecall
 ret
 614:	00008067          	ret

0000000000000618 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 618:	01400893          	li	a7,20
 ecall
 61c:	00000073          	ecall
 ret
 620:	00008067          	ret

0000000000000624 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 624:	00900893          	li	a7,9
 ecall
 628:	00000073          	ecall
 ret
 62c:	00008067          	ret

0000000000000630 <dup>:
.global dup
dup:
 li a7, SYS_dup
 630:	00a00893          	li	a7,10
 ecall
 634:	00000073          	ecall
 ret
 638:	00008067          	ret

000000000000063c <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 63c:	00b00893          	li	a7,11
 ecall
 640:	00000073          	ecall
 ret
 644:	00008067          	ret

0000000000000648 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 648:	00c00893          	li	a7,12
 ecall
 64c:	00000073          	ecall
 ret
 650:	00008067          	ret

0000000000000654 <pause>:
.global pause
pause:
 li a7, SYS_pause
 654:	00d00893          	li	a7,13
 ecall
 658:	00000073          	ecall
 ret
 65c:	00008067          	ret

0000000000000660 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 660:	00e00893          	li	a7,14
 ecall
 664:	00000073          	ecall
 ret
 668:	00008067          	ret

000000000000066c <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 66c:	00001617          	auipc	a2,0x1
 670:	9a462603          	lw	a2,-1628(a2) # 1010 <putc_n>
 674:	00c04463          	bgtz	a2,67c <putc_flush+0x10>
 678:	00008067          	ret
{
 67c:	ff010113          	addi	sp,sp,-16
 680:	00113423          	sd	ra,8(sp)
 684:	00813023          	sd	s0,0(sp)
 688:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 68c:	00001597          	auipc	a1,0x1
 690:	99458593          	addi	a1,a1,-1644 # 1020 <putc_buf>
 694:	00001517          	auipc	a0,0x1
 698:	96c52503          	lw	a0,-1684(a0) # 1000 <putc_fd>
 69c:	f11ff0ef          	jal	5ac <write>
    putc_n = 0;
 6a0:	00001797          	auipc	a5,0x1
 6a4:	9607a823          	sw	zero,-1680(a5) # 1010 <putc_n>
  }
}
 6a8:	00813083          	ld	ra,8(sp)
 6ac:	00013403          	ld	s0,0(sp)
 6b0:	01010113          	addi	sp,sp,16
 6b4:	00008067          	ret

00000000000006b8 <putc>:

static void
putc(int fd, char c)
{
 6b8:	fe010113          	addi	sp,sp,-32
 6bc:	00113c23          	sd	ra,24(sp)
 6c0:	00813823          	sd	s0,16(sp)
 6c4:	00913423          	sd	s1,8(sp)
 6c8:	02010413          	addi	s0,sp,32
 6cc:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 6d0:	00001797          	auipc	a5,0x1
 6d4:	9307a783          	lw	a5,-1744(a5) # 1000 <putc_fd>
 6d8:	04a79663          	bne	a5,a0,724 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 6dc:	00001717          	auipc	a4,0x1
 6e0:	93470713          	addi	a4,a4,-1740 # 1010 <putc_n>
 6e4:	00072683          	lw	a3,0(a4)
 6e8:	0016879b          	addiw	a5,a3,1
 6ec:	00f72023          	sw	a5,0(a4)
 6f0:	00001717          	auipc	a4,0x1
 6f4:	93070713          	addi	a4,a4,-1744 # 1020 <putc_buf>
 6f8:	00d70733          	add	a4,a4,a3
 6fc:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 700:	ff648493          	addi	s1,s1,-10
 704:	02048e63          	beqz	s1,740 <putc+0x88>
 708:	f8078793          	addi	a5,a5,-128
 70c:	02078a63          	beqz	a5,740 <putc+0x88>
    putc_flush();
}
 710:	01813083          	ld	ra,24(sp)
 714:	01013403          	ld	s0,16(sp)
 718:	00813483          	ld	s1,8(sp)
 71c:	02010113          	addi	sp,sp,32
 720:	00008067          	ret
 724:	01213023          	sd	s2,0(sp)
 728:	00050913          	mv	s2,a0
    putc_flush();
 72c:	f41ff0ef          	jal	66c <putc_flush>
    putc_fd = fd;
 730:	00001797          	auipc	a5,0x1
 734:	8d27a823          	sw	s2,-1840(a5) # 1000 <putc_fd>
 738:	00013903          	ld	s2,0(sp)
 73c:	fa1ff06f          	j	6dc <putc+0x24>
    putc_flush();
 740:	f2dff0ef          	jal	66c <putc_flush>
}
 744:	fcdff06f          	j	710 <putc+0x58>

0000000000000748 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 748:	fb010113          	addi	sp,sp,-80
 74c:	04113423          	sd	ra,72(sp)
 750:	04813023          	sd	s0,64(sp)
 754:	03213823          	sd	s2,48(sp)
 758:	03313423          	sd	s3,40(sp)
 75c:	05010413          	addi	s0,sp,80
 760:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 764:	0a068e63          	beqz	a3,820 <printint+0xd8>
 768:	0a05dc63          	bgez	a1,820 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 76c:	40b005b3          	neg	a1,a1
    neg = 1;
 770:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 774:	fb840993          	addi	s3,s0,-72
  neg = 0;
 778:	00098693          	mv	a3,s3
  i = 0;
 77c:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 780:	00000817          	auipc	a6,0x0
 784:	79880813          	addi	a6,a6,1944 # f18 <digits>
 788:	00070893          	mv	a7,a4
 78c:	0017051b          	addiw	a0,a4,1
 790:	00050713          	mv	a4,a0
 794:	02c5f7b3          	remu	a5,a1,a2
 798:	00f807b3          	add	a5,a6,a5
 79c:	0007c783          	lbu	a5,0(a5)
 7a0:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 7a4:	00058793          	mv	a5,a1
 7a8:	02c5d5b3          	divu	a1,a1,a2
 7ac:	00168693          	addi	a3,a3,1
 7b0:	fcc7fce3          	bgeu	a5,a2,788 <printint+0x40>
  if (neg)
 7b4:	00030c63          	beqz	t1,7cc <printint+0x84>
    buf[i++] = '-';
 7b8:	fd050793          	addi	a5,a0,-48
 7bc:	00878533          	add	a0,a5,s0
 7c0:	02d00793          	li	a5,45
 7c4:	fef50423          	sb	a5,-24(a0)
 7c8:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 7cc:	02e05e63          	blez	a4,808 <printint+0xc0>
 7d0:	02913c23          	sd	s1,56(sp)
 7d4:	fff7071b          	addiw	a4,a4,-1
 7d8:	00e984b3          	add	s1,s3,a4
 7dc:	fff98993          	addi	s3,s3,-1
 7e0:	00e989b3          	add	s3,s3,a4
 7e4:	02071713          	slli	a4,a4,0x20
 7e8:	02075713          	srli	a4,a4,0x20
 7ec:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 7f0:	0004c583          	lbu	a1,0(s1)
 7f4:	00090513          	mv	a0,s2
 7f8:	ec1ff0ef          	jal	6b8 <putc>
  while (--i >= 0)
 7fc:	fff48493          	addi	s1,s1,-1
 800:	ff3498e3          	bne	s1,s3,7f0 <printint+0xa8>
 804:	03813483          	ld	s1,56(sp)
}
 808:	04813083          	ld	ra,72(sp)
 80c:	04013403          	ld	s0,64(sp)
 810:	03013903          	ld	s2,48(sp)
 814:	02813983          	ld	s3,40(sp)
 818:	05010113          	addi	sp,sp,80
 81c:	00008067          	ret
  neg = 0;
 820:	00000313          	li	t1,0
 824:	f51ff06f          	j	774 <printint+0x2c>

0000000000000828 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 828:	fa010113          	addi	sp,sp,-96
 82c:	04113c23          	sd	ra,88(sp)
 830:	04813823          	sd	s0,80(sp)
 834:	04913423          	sd	s1,72(sp)
 838:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 83c:	0005c483          	lbu	s1,0(a1)
 840:	32048263          	beqz	s1,b64 <vprintf+0x33c>
 844:	05213023          	sd	s2,64(sp)
 848:	03313c23          	sd	s3,56(sp)
 84c:	03413823          	sd	s4,48(sp)
 850:	03513423          	sd	s5,40(sp)
 854:	03613023          	sd	s6,32(sp)
 858:	01713c23          	sd	s7,24(sp)
 85c:	01813823          	sd	s8,16(sp)
 860:	00050b13          	mv	s6,a0
 864:	00058a13          	mv	s4,a1
 868:	00060b93          	mv	s7,a2
  state = 0;
 86c:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 870:	00000913          	li	s2,0
 874:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 878:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 87c:	06400c13          	li	s8,100
 880:	0300006f          	j	8b0 <vprintf+0x88>
        putc(fd, c0);
 884:	00048593          	mv	a1,s1
 888:	000b0513          	mv	a0,s6
 88c:	e2dff0ef          	jal	6b8 <putc>
 890:	0080006f          	j	898 <vprintf+0x70>
    else if (state == '%')
 894:	03598863          	beq	s3,s5,8c4 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 898:	0019079b          	addiw	a5,s2,1
 89c:	00078913          	mv	s2,a5
 8a0:	00078713          	mv	a4,a5
 8a4:	00fa07b3          	add	a5,s4,a5
 8a8:	0007c483          	lbu	s1,0(a5)
 8ac:	28048e63          	beqz	s1,b48 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 8b0:	0004879b          	sext.w	a5,s1
    if (state == 0)
 8b4:	fe0990e3          	bnez	s3,894 <vprintf+0x6c>
      if (c0 == '%')
 8b8:	fd5796e3          	bne	a5,s5,884 <vprintf+0x5c>
        state = '%';
 8bc:	00078993          	mv	s3,a5
 8c0:	fd9ff06f          	j	898 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 8c4:	00ea06b3          	add	a3,s4,a4
 8c8:	0016c603          	lbu	a2,1(a3)
      if (c1)
 8cc:	2a060663          	beqz	a2,b78 <vprintf+0x350>
      if (c0 == 'd')
 8d0:	05878063          	beq	a5,s8,910 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 8d4:	f9478693          	addi	a3,a5,-108
 8d8:	0016b693          	seqz	a3,a3
 8dc:	f9c60593          	addi	a1,a2,-100
 8e0:	04059a63          	bnez	a1,934 <vprintf+0x10c>
 8e4:	04068863          	beqz	a3,934 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 8e8:	008b8493          	addi	s1,s7,8
 8ec:	00100693          	li	a3,1
 8f0:	00a00613          	li	a2,10
 8f4:	000bb583          	ld	a1,0(s7)
 8f8:	000b0513          	mv	a0,s6
 8fc:	e4dff0ef          	jal	748 <printint>
        i += 1;
 900:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 904:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 908:	00000993          	li	s3,0
 90c:	f8dff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 910:	008b8493          	addi	s1,s7,8
 914:	00100693          	li	a3,1
 918:	00a00613          	li	a2,10
 91c:	000ba583          	lw	a1,0(s7)
 920:	000b0513          	mv	a0,s6
 924:	e25ff0ef          	jal	748 <printint>
 928:	00048b93          	mv	s7,s1
      state = 0;
 92c:	00000993          	li	s3,0
 930:	f69ff06f          	j	898 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 934:	00ea0733          	add	a4,s4,a4
 938:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 93c:	f9460713          	addi	a4,a2,-108
 940:	00173713          	seqz	a4,a4
 944:	00e6f733          	and	a4,a3,a4
 948:	f9c58513          	addi	a0,a1,-100
 94c:	24051263          	bnez	a0,b90 <vprintf+0x368>
 950:	24070063          	beqz	a4,b90 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 954:	008b8493          	addi	s1,s7,8
 958:	00100693          	li	a3,1
 95c:	00a00613          	li	a2,10
 960:	000bb583          	ld	a1,0(s7)
 964:	000b0513          	mv	a0,s6
 968:	de1ff0ef          	jal	748 <printint>
        i += 2;
 96c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 970:	00048b93          	mv	s7,s1
      state = 0;
 974:	00000993          	li	s3,0
        i += 2;
 978:	f21ff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 97c:	008b8493          	addi	s1,s7,8
 980:	00000693          	li	a3,0
 984:	00a00613          	li	a2,10
 988:	000be583          	lwu	a1,0(s7)
 98c:	000b0513          	mv	a0,s6
 990:	db9ff0ef          	jal	748 <printint>
 994:	00048b93          	mv	s7,s1
      state = 0;
 998:	00000993          	li	s3,0
 99c:	efdff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 9a0:	008b8493          	addi	s1,s7,8
 9a4:	00000693          	li	a3,0
 9a8:	00a00613          	li	a2,10
 9ac:	000bb583          	ld	a1,0(s7)
 9b0:	000b0513          	mv	a0,s6
 9b4:	d95ff0ef          	jal	748 <printint>
        i += 1;
 9b8:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 9bc:	00048b93          	mv	s7,s1
      state = 0;
 9c0:	00000993          	li	s3,0
 9c4:	ed5ff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 9c8:	008b8493          	addi	s1,s7,8
 9cc:	00000693          	li	a3,0
 9d0:	00a00613          	li	a2,10
 9d4:	000bb583          	ld	a1,0(s7)
 9d8:	000b0513          	mv	a0,s6
 9dc:	d6dff0ef          	jal	748 <printint>
        i += 2;
 9e0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 9e4:	00048b93          	mv	s7,s1
      state = 0;
 9e8:	00000993          	li	s3,0
        i += 2;
 9ec:	eadff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 9f0:	008b8493          	addi	s1,s7,8
 9f4:	00000693          	li	a3,0
 9f8:	01000613          	li	a2,16
 9fc:	000be583          	lwu	a1,0(s7)
 a00:	000b0513          	mv	a0,s6
 a04:	d45ff0ef          	jal	748 <printint>
 a08:	00048b93          	mv	s7,s1
      state = 0;
 a0c:	00000993          	li	s3,0
 a10:	e89ff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a14:	008b8493          	addi	s1,s7,8
 a18:	00000693          	li	a3,0
 a1c:	01000613          	li	a2,16
 a20:	000bb583          	ld	a1,0(s7)
 a24:	000b0513          	mv	a0,s6
 a28:	d21ff0ef          	jal	748 <printint>
        i += 1;
 a2c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 a30:	00048b93          	mv	s7,s1
      state = 0;
 a34:	00000993          	li	s3,0
 a38:	e61ff06f          	j	898 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a3c:	008b8493          	addi	s1,s7,8
 a40:	00000693          	li	a3,0
 a44:	01000613          	li	a2,16
 a48:	000bb583          	ld	a1,0(s7)
 a4c:	000b0513          	mv	a0,s6
 a50:	cf9ff0ef          	jal	748 <printint>
        i += 2;
 a54:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 a58:	00048b93          	mv	s7,s1
      state = 0;
 a5c:	00000993          	li	s3,0
        i += 2;
 a60:	e39ff06f          	j	898 <vprintf+0x70>
 a64:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 a68:	008b8793          	addi	a5,s7,8
 a6c:	00078c93          	mv	s9,a5
 a70:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 a74:	03000593          	li	a1,48
 a78:	000b0513          	mv	a0,s6
 a7c:	c3dff0ef          	jal	6b8 <putc>
  putc(fd, 'x');
 a80:	07800593          	li	a1,120
 a84:	000b0513          	mv	a0,s6
 a88:	c31ff0ef          	jal	6b8 <putc>
 a8c:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a90:	00000b97          	auipc	s7,0x0
 a94:	488b8b93          	addi	s7,s7,1160 # f18 <digits>
 a98:	03c9d793          	srli	a5,s3,0x3c
 a9c:	00fb87b3          	add	a5,s7,a5
 aa0:	0007c583          	lbu	a1,0(a5)
 aa4:	000b0513          	mv	a0,s6
 aa8:	c11ff0ef          	jal	6b8 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 aac:	00499993          	slli	s3,s3,0x4
 ab0:	fff4849b          	addiw	s1,s1,-1
 ab4:	fe0492e3          	bnez	s1,a98 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 ab8:	000c8b93          	mv	s7,s9
      state = 0;
 abc:	00000993          	li	s3,0
 ac0:	00813c83          	ld	s9,8(sp)
 ac4:	dd5ff06f          	j	898 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 ac8:	008b8493          	addi	s1,s7,8
 acc:	000bc583          	lbu	a1,0(s7)
 ad0:	000b0513          	mv	a0,s6
 ad4:	be5ff0ef          	jal	6b8 <putc>
 ad8:	00048b93          	mv	s7,s1
      state = 0;
 adc:	00000993          	li	s3,0
 ae0:	db9ff06f          	j	898 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 ae4:	008b8993          	addi	s3,s7,8
 ae8:	000bb483          	ld	s1,0(s7)
 aec:	02048663          	beqz	s1,b18 <vprintf+0x2f0>
        for (; *s; s++)
 af0:	0004c583          	lbu	a1,0(s1)
 af4:	04058463          	beqz	a1,b3c <vprintf+0x314>
          putc(fd, *s);
 af8:	000b0513          	mv	a0,s6
 afc:	bbdff0ef          	jal	6b8 <putc>
        for (; *s; s++)
 b00:	00148493          	addi	s1,s1,1
 b04:	0004c583          	lbu	a1,0(s1)
 b08:	fe0598e3          	bnez	a1,af8 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 b0c:	00098b93          	mv	s7,s3
      state = 0;
 b10:	00000993          	li	s3,0
 b14:	d85ff06f          	j	898 <vprintf+0x70>
          s = "(null)";
 b18:	00000497          	auipc	s1,0x0
 b1c:	3f848493          	addi	s1,s1,1016 # f10 <malloc+0x1b0>
        for (; *s; s++)
 b20:	02800593          	li	a1,40
 b24:	fd5ff06f          	j	af8 <vprintf+0x2d0>
        putc(fd, '%');
 b28:	00078593          	mv	a1,a5
 b2c:	000b0513          	mv	a0,s6
 b30:	b89ff0ef          	jal	6b8 <putc>
      state = 0;
 b34:	00000993          	li	s3,0
 b38:	d61ff06f          	j	898 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b3c:	00098b93          	mv	s7,s3
      state = 0;
 b40:	00000993          	li	s3,0
 b44:	d55ff06f          	j	898 <vprintf+0x70>
 b48:	04013903          	ld	s2,64(sp)
 b4c:	03813983          	ld	s3,56(sp)
 b50:	03013a03          	ld	s4,48(sp)
 b54:	02813a83          	ld	s5,40(sp)
 b58:	02013b03          	ld	s6,32(sp)
 b5c:	01813b83          	ld	s7,24(sp)
 b60:	01013c03          	ld	s8,16(sp)
    }
  }
}
 b64:	05813083          	ld	ra,88(sp)
 b68:	05013403          	ld	s0,80(sp)
 b6c:	04813483          	ld	s1,72(sp)
 b70:	06010113          	addi	sp,sp,96
 b74:	00008067          	ret
      if (c0 == 'd')
 b78:	06400713          	li	a4,100
 b7c:	d8e78ae3          	beq	a5,a4,910 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 b80:	f9478693          	addi	a3,a5,-108
 b84:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 b88:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 b8c:	00000713          	li	a4,0
      else if (c0 == 'u')
 b90:	07500513          	li	a0,117
 b94:	dea784e3          	beq	a5,a0,97c <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b98:	f8b60513          	addi	a0,a2,-117
 b9c:	00051463          	bnez	a0,ba4 <vprintf+0x37c>
 ba0:	e00690e3          	bnez	a3,9a0 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 ba4:	f8b58513          	addi	a0,a1,-117
 ba8:	00051463          	bnez	a0,bb0 <vprintf+0x388>
 bac:	e0071ee3          	bnez	a4,9c8 <vprintf+0x1a0>
      else if (c0 == 'x')
 bb0:	07800513          	li	a0,120
 bb4:	e2a78ee3          	beq	a5,a0,9f0 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 bb8:	f8860613          	addi	a2,a2,-120
 bbc:	00061463          	bnez	a2,bc4 <vprintf+0x39c>
 bc0:	e4069ae3          	bnez	a3,a14 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 bc4:	f8858593          	addi	a1,a1,-120
 bc8:	00059463          	bnez	a1,bd0 <vprintf+0x3a8>
 bcc:	e60718e3          	bnez	a4,a3c <vprintf+0x214>
      else if (c0 == 'p')
 bd0:	07000713          	li	a4,112
 bd4:	e8e788e3          	beq	a5,a4,a64 <vprintf+0x23c>
      else if (c0 == 'c')
 bd8:	06300713          	li	a4,99
 bdc:	eee786e3          	beq	a5,a4,ac8 <vprintf+0x2a0>
      else if (c0 == 's')
 be0:	07300713          	li	a4,115
 be4:	f0e780e3          	beq	a5,a4,ae4 <vprintf+0x2bc>
      else if (c0 == '%')
 be8:	02500713          	li	a4,37
 bec:	f2e78ee3          	beq	a5,a4,b28 <vprintf+0x300>
        putc(fd, '%');
 bf0:	02500593          	li	a1,37
 bf4:	000b0513          	mv	a0,s6
 bf8:	ac1ff0ef          	jal	6b8 <putc>
        putc(fd, c0);
 bfc:	00048593          	mv	a1,s1
 c00:	000b0513          	mv	a0,s6
 c04:	ab5ff0ef          	jal	6b8 <putc>
      state = 0;
 c08:	00000993          	li	s3,0
 c0c:	c8dff06f          	j	898 <vprintf+0x70>

0000000000000c10 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 c10:	fb010113          	addi	sp,sp,-80
 c14:	00113c23          	sd	ra,24(sp)
 c18:	00813823          	sd	s0,16(sp)
 c1c:	02010413          	addi	s0,sp,32
 c20:	00c43023          	sd	a2,0(s0)
 c24:	00d43423          	sd	a3,8(s0)
 c28:	00e43823          	sd	a4,16(s0)
 c2c:	00f43c23          	sd	a5,24(s0)
 c30:	03043023          	sd	a6,32(s0)
 c34:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 c38:	00040613          	mv	a2,s0
 c3c:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 c40:	be9ff0ef          	jal	828 <vprintf>
}
 c44:	01813083          	ld	ra,24(sp)
 c48:	01013403          	ld	s0,16(sp)
 c4c:	05010113          	addi	sp,sp,80
 c50:	00008067          	ret

0000000000000c54 <printf>:

void printf(const char *fmt, ...)
{
 c54:	fa010113          	addi	sp,sp,-96
 c58:	00113c23          	sd	ra,24(sp)
 c5c:	00813823          	sd	s0,16(sp)
 c60:	02010413          	addi	s0,sp,32
 c64:	00b43423          	sd	a1,8(s0)
 c68:	00c43823          	sd	a2,16(s0)
 c6c:	00d43c23          	sd	a3,24(s0)
 c70:	02e43023          	sd	a4,32(s0)
 c74:	02f43423          	sd	a5,40(s0)
 c78:	03043823          	sd	a6,48(s0)
 c7c:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 c80:	00840613          	addi	a2,s0,8
 c84:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 c88:	00050593          	mv	a1,a0
 c8c:	00100513          	li	a0,1
 c90:	b99ff0ef          	jal	828 <vprintf>
  putc_flush();
 c94:	9d9ff0ef          	jal	66c <putc_flush>
}
 c98:	01813083          	ld	ra,24(sp)
 c9c:	01013403          	ld	s0,16(sp)
 ca0:	06010113          	addi	sp,sp,96
 ca4:	00008067          	ret

0000000000000ca8 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 ca8:	ff010113          	addi	sp,sp,-16
 cac:	00113423          	sd	ra,8(sp)
 cb0:	00813023          	sd	s0,0(sp)
 cb4:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 cb8:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 cbc:	00000797          	auipc	a5,0x0
 cc0:	35c7b783          	ld	a5,860(a5) # 1018 <freep>
 cc4:	0140006f          	j	cd8 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 cc8:	0007b703          	ld	a4,0(a5)
 ccc:	00e7e463          	bltu	a5,a4,cd4 <free+0x2c>
 cd0:	00e6ec63          	bltu	a3,a4,ce8 <free+0x40>
{
 cd4:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 cd8:	fed7f8e3          	bgeu	a5,a3,cc8 <free+0x20>
 cdc:	0007b703          	ld	a4,0(a5)
 ce0:	00e6e463          	bltu	a3,a4,ce8 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 ce4:	fee7e8e3          	bltu	a5,a4,cd4 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 ce8:	ff852583          	lw	a1,-8(a0)
 cec:	0007b603          	ld	a2,0(a5)
 cf0:	02059813          	slli	a6,a1,0x20
 cf4:	01c85713          	srli	a4,a6,0x1c
 cf8:	00e68733          	add	a4,a3,a4
 cfc:	02e60c63          	beq	a2,a4,d34 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 d00:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 d04:	0087a603          	lw	a2,8(a5)
 d08:	02061593          	slli	a1,a2,0x20
 d0c:	01c5d713          	srli	a4,a1,0x1c
 d10:	00e78733          	add	a4,a5,a4
 d14:	02e68c63          	beq	a3,a4,d4c <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 d18:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 d1c:	00000717          	auipc	a4,0x0
 d20:	2ef73e23          	sd	a5,764(a4) # 1018 <freep>
}
 d24:	00813083          	ld	ra,8(sp)
 d28:	00013403          	ld	s0,0(sp)
 d2c:	01010113          	addi	sp,sp,16
 d30:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 d34:	00862703          	lw	a4,8(a2)
 d38:	00b7073b          	addw	a4,a4,a1
 d3c:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 d40:	0007b703          	ld	a4,0(a5)
 d44:	00073603          	ld	a2,0(a4)
 d48:	fb9ff06f          	j	d00 <free+0x58>
    p->s.size += bp->s.size;
 d4c:	ff852703          	lw	a4,-8(a0)
 d50:	00c7073b          	addw	a4,a4,a2
 d54:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 d58:	ff053683          	ld	a3,-16(a0)
 d5c:	fbdff06f          	j	d18 <free+0x70>

0000000000000d60 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 d60:	fc010113          	addi	sp,sp,-64
 d64:	02113c23          	sd	ra,56(sp)
 d68:	02813823          	sd	s0,48(sp)
 d6c:	03213023          	sd	s2,32(sp)
 d70:	01313c23          	sd	s3,24(sp)
 d74:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 d78:	02051993          	slli	s3,a0,0x20
 d7c:	0209d993          	srli	s3,s3,0x20
 d80:	00f98993          	addi	s3,s3,15
 d84:	0049d993          	srli	s3,s3,0x4
 d88:	0019899b          	addiw	s3,s3,1
 d8c:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d90:	00000517          	auipc	a0,0x0
 d94:	28853503          	ld	a0,648(a0) # 1018 <freep>
 d98:	04050463          	beqz	a0,de0 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d9c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 da0:	0087a703          	lw	a4,8(a5)
 da4:	0d377a63          	bgeu	a4,s3,e78 <malloc+0x118>
 da8:	02913423          	sd	s1,40(sp)
 dac:	01413823          	sd	s4,16(sp)
 db0:	01513423          	sd	s5,8(sp)
 db4:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 db8:	00098a13          	mv	s4,s3
 dbc:	00001737          	lui	a4,0x1
 dc0:	00e9f463          	bgeu	s3,a4,dc8 <malloc+0x68>
 dc4:	00001a37          	lui	s4,0x1
 dc8:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 dcc:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 dd0:	00000497          	auipc	s1,0x0
 dd4:	24848493          	addi	s1,s1,584 # 1018 <freep>
  if(p == SBRK_ERROR)
 dd8:	fff00a93          	li	s5,-1
 ddc:	05c0006f          	j	e38 <malloc+0xd8>
 de0:	02913423          	sd	s1,40(sp)
 de4:	01413823          	sd	s4,16(sp)
 de8:	01513423          	sd	s5,8(sp)
 dec:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 df0:	00000797          	auipc	a5,0x0
 df4:	2b078793          	addi	a5,a5,688 # 10a0 <base>
 df8:	00000717          	auipc	a4,0x0
 dfc:	22f73023          	sd	a5,544(a4) # 1018 <freep>
 e00:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 e04:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 e08:	fb1ff06f          	j	db8 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 e0c:	0007b703          	ld	a4,0(a5)
 e10:	00e53023          	sd	a4,0(a0)
 e14:	0800006f          	j	e94 <malloc+0x134>
  hp->s.size = nu;
 e18:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 e1c:	01050513          	addi	a0,a0,16
 e20:	e89ff0ef          	jal	ca8 <free>
  return freep;
 e24:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 e28:	08050863          	beqz	a0,eb8 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 e2c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 e30:	0087a703          	lw	a4,8(a5)
 e34:	03277a63          	bgeu	a4,s2,e68 <malloc+0x108>
    if(p == freep)
 e38:	0004b703          	ld	a4,0(s1)
 e3c:	00078513          	mv	a0,a5
 e40:	fef716e3          	bne	a4,a5,e2c <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 e44:	000a0513          	mv	a0,s4
 e48:	ed8ff0ef          	jal	520 <sbrk>
  if(p == SBRK_ERROR)
 e4c:	fd5516e3          	bne	a0,s5,e18 <malloc+0xb8>
        return 0;
 e50:	00000513          	li	a0,0
 e54:	02813483          	ld	s1,40(sp)
 e58:	01013a03          	ld	s4,16(sp)
 e5c:	00813a83          	ld	s5,8(sp)
 e60:	00013b03          	ld	s6,0(sp)
 e64:	03c0006f          	j	ea0 <malloc+0x140>
 e68:	02813483          	ld	s1,40(sp)
 e6c:	01013a03          	ld	s4,16(sp)
 e70:	00813a83          	ld	s5,8(sp)
 e74:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 e78:	f8e90ae3          	beq	s2,a4,e0c <malloc+0xac>
        p->s.size -= nunits;
 e7c:	4137073b          	subw	a4,a4,s3
 e80:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 e84:	02071693          	slli	a3,a4,0x20
 e88:	01c6d713          	srli	a4,a3,0x1c
 e8c:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e90:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e94:	00000717          	auipc	a4,0x0
 e98:	18a73223          	sd	a0,388(a4) # 1018 <freep>
      return (void*)(p + 1);
 e9c:	01078513          	addi	a0,a5,16
  }
}
 ea0:	03813083          	ld	ra,56(sp)
 ea4:	03013403          	ld	s0,48(sp)
 ea8:	02013903          	ld	s2,32(sp)
 eac:	01813983          	ld	s3,24(sp)
 eb0:	04010113          	addi	sp,sp,64
 eb4:	00008067          	ret
 eb8:	02813483          	ld	s1,40(sp)
 ebc:	01013a03          	ld	s4,16(sp)
 ec0:	00813a83          	ld	s5,8(sp)
 ec4:	00013b03          	ld	s6,0(sp)
 ec8:	fd9ff06f          	j	ea0 <malloc+0x140>
