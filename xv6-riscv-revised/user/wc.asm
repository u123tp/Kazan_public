
user/_wc:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <wc>:

char buf[512];

void
wc(int fd, char *name)
{
   0:	f8010113          	addi	sp,sp,-128
   4:	06113c23          	sd	ra,120(sp)
   8:	06813823          	sd	s0,112(sp)
   c:	06913423          	sd	s1,104(sp)
  10:	07213023          	sd	s2,96(sp)
  14:	05313c23          	sd	s3,88(sp)
  18:	05413823          	sd	s4,80(sp)
  1c:	05513423          	sd	s5,72(sp)
  20:	05613023          	sd	s6,64(sp)
  24:	03713c23          	sd	s7,56(sp)
  28:	03813823          	sd	s8,48(sp)
  2c:	03913423          	sd	s9,40(sp)
  30:	03a13023          	sd	s10,32(sp)
  34:	01b13c23          	sd	s11,24(sp)
  38:	08010413          	addi	s0,sp,128
  3c:	f8a43423          	sd	a0,-120(s0)
  40:	f8b43023          	sd	a1,-128(s0)
  int i, n;
  int l, w, c, inword;

  l = w = c = 0;
  inword = 0;
  44:	00000913          	li	s2,0
  l = w = c = 0;
  48:	00000c93          	li	s9,0
  4c:	00000c13          	li	s8,0
  50:	00000b93          	li	s7,0
  while((n = read(fd, buf, sizeof(buf))) > 0){
  54:	20000d93          	li	s11,512
  58:	00002d17          	auipc	s10,0x2
  5c:	fc8d0d13          	addi	s10,s10,-56 # 2020 <buf>
    for(i=0; i<n; i++){
      c++;
      if(buf[i] == '\n')
  60:	00a00a93          	li	s5,10
        l++;
      if(strchr(" \r\t\n\v", buf[i]))
  64:	00001a17          	auipc	s4,0x1
  68:	f3ca0a13          	addi	s4,s4,-196 # fa0 <malloc+0x16c>
  while((n = read(fd, buf, sizeof(buf))) > 0){
  6c:	0400006f          	j	ac <wc+0xac>
      if(strchr(" \r\t\n\v", buf[i]))
  70:	000a0513          	mv	a0,s4
  74:	29c000ef          	jal	310 <strchr>
  78:	02050063          	beqz	a0,98 <wc+0x98>
        inword = 0;
  7c:	00000913          	li	s2,0
    for(i=0; i<n; i++){
  80:	00148493          	addi	s1,s1,1
  84:	03348263          	beq	s1,s3,a8 <wc+0xa8>
      if(buf[i] == '\n')
  88:	0004c583          	lbu	a1,0(s1)
  8c:	ff5592e3          	bne	a1,s5,70 <wc+0x70>
        l++;
  90:	001b8b9b          	addiw	s7,s7,1
  94:	fddff06f          	j	70 <wc+0x70>
      else if(!inword){
  98:	fe0914e3          	bnez	s2,80 <wc+0x80>
        w++;
  9c:	001c0c1b          	addiw	s8,s8,1
        inword = 1;
  a0:	00100913          	li	s2,1
  a4:	fddff06f          	j	80 <wc+0x80>
  a8:	019b0cbb          	addw	s9,s6,s9
  while((n = read(fd, buf, sizeof(buf))) > 0){
  ac:	000d8613          	mv	a2,s11
  b0:	000d0593          	mv	a1,s10
  b4:	f8843503          	ld	a0,-120(s0)
  b8:	5bc000ef          	jal	674 <read>
  bc:	00050b13          	mv	s6,a0
  c0:	00a05a63          	blez	a0,d4 <wc+0xd4>
  c4:	00002497          	auipc	s1,0x2
  c8:	f5c48493          	addi	s1,s1,-164 # 2020 <buf>
  cc:	009b09b3          	add	s3,s6,s1
  d0:	fb9ff06f          	j	88 <wc+0x88>
      }
    }
  }
  if(n < 0){
  d4:	04054e63          	bltz	a0,130 <wc+0x130>
    printf("wc: read error\n");
    exit(1);
  }
  printf("%d %d %d %s\n", l, w, c, name);
  d8:	f8043703          	ld	a4,-128(s0)
  dc:	000c8693          	mv	a3,s9
  e0:	000c0613          	mv	a2,s8
  e4:	000b8593          	mv	a1,s7
  e8:	00001517          	auipc	a0,0x1
  ec:	ed850513          	addi	a0,a0,-296 # fc0 <malloc+0x18c>
  f0:	439000ef          	jal	d28 <printf>
}
  f4:	07813083          	ld	ra,120(sp)
  f8:	07013403          	ld	s0,112(sp)
  fc:	06813483          	ld	s1,104(sp)
 100:	06013903          	ld	s2,96(sp)
 104:	05813983          	ld	s3,88(sp)
 108:	05013a03          	ld	s4,80(sp)
 10c:	04813a83          	ld	s5,72(sp)
 110:	04013b03          	ld	s6,64(sp)
 114:	03813b83          	ld	s7,56(sp)
 118:	03013c03          	ld	s8,48(sp)
 11c:	02813c83          	ld	s9,40(sp)
 120:	02013d03          	ld	s10,32(sp)
 124:	01813d83          	ld	s11,24(sp)
 128:	08010113          	addi	sp,sp,128
 12c:	00008067          	ret
    printf("wc: read error\n");
 130:	00001517          	auipc	a0,0x1
 134:	e8050513          	addi	a0,a0,-384 # fb0 <malloc+0x17c>
 138:	3f1000ef          	jal	d28 <printf>
    exit(1);
 13c:	00100513          	li	a0,1
 140:	510000ef          	jal	650 <exit>

0000000000000144 <main>:

int
main(int argc, char *argv[])
{
 144:	fd010113          	addi	sp,sp,-48
 148:	02113423          	sd	ra,40(sp)
 14c:	02813023          	sd	s0,32(sp)
 150:	03010413          	addi	s0,sp,48
  int fd, i;

  if(argc <= 1){
 154:	00100793          	li	a5,1
 158:	04a7de63          	bge	a5,a0,1b4 <main+0x70>
 15c:	00913c23          	sd	s1,24(sp)
 160:	01213823          	sd	s2,16(sp)
 164:	01313423          	sd	s3,8(sp)
 168:	00858913          	addi	s2,a1,8
 16c:	ffe5099b          	addiw	s3,a0,-2
 170:	02099793          	slli	a5,s3,0x20
 174:	01d7d993          	srli	s3,a5,0x1d
 178:	01058593          	addi	a1,a1,16
 17c:	00b989b3          	add	s3,s3,a1
    wc(0, "");
    exit(0);
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], O_RDONLY)) < 0){
 180:	00000593          	li	a1,0
 184:	00093503          	ld	a0,0(s2)
 188:	528000ef          	jal	6b0 <open>
 18c:	00050493          	mv	s1,a0
 190:	04054463          	bltz	a0,1d8 <main+0x94>
      printf("wc: cannot open %s\n", argv[i]);
      exit(1);
    }
    wc(fd, argv[i]);
 194:	00093583          	ld	a1,0(s2)
 198:	e69ff0ef          	jal	0 <wc>
    close(fd);
 19c:	00048513          	mv	a0,s1
 1a0:	4ec000ef          	jal	68c <close>
  for(i = 1; i < argc; i++){
 1a4:	00890913          	addi	s2,s2,8
 1a8:	fd391ce3          	bne	s2,s3,180 <main+0x3c>
  }
  exit(0);
 1ac:	00000513          	li	a0,0
 1b0:	4a0000ef          	jal	650 <exit>
 1b4:	00913c23          	sd	s1,24(sp)
 1b8:	01213823          	sd	s2,16(sp)
 1bc:	01313423          	sd	s3,8(sp)
    wc(0, "");
 1c0:	00001597          	auipc	a1,0x1
 1c4:	de858593          	addi	a1,a1,-536 # fa8 <malloc+0x174>
 1c8:	00000513          	li	a0,0
 1cc:	e35ff0ef          	jal	0 <wc>
    exit(0);
 1d0:	00000513          	li	a0,0
 1d4:	47c000ef          	jal	650 <exit>
      printf("wc: cannot open %s\n", argv[i]);
 1d8:	00093583          	ld	a1,0(s2)
 1dc:	00001517          	auipc	a0,0x1
 1e0:	df450513          	addi	a0,a0,-524 # fd0 <malloc+0x19c>
 1e4:	345000ef          	jal	d28 <printf>
      exit(1);
 1e8:	00100513          	li	a0,1
 1ec:	464000ef          	jal	650 <exit>

00000000000001f0 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
 1f0:	ff010113          	addi	sp,sp,-16
 1f4:	00113423          	sd	ra,8(sp)
 1f8:	00813023          	sd	s0,0(sp)
 1fc:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
 200:	f45ff0ef          	jal	144 <main>
  exit(r);
 204:	44c000ef          	jal	650 <exit>

0000000000000208 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 208:	ff010113          	addi	sp,sp,-16
 20c:	00113423          	sd	ra,8(sp)
 210:	00813023          	sd	s0,0(sp)
 214:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 218:	00050793          	mv	a5,a0
 21c:	00158593          	addi	a1,a1,1
 220:	00178793          	addi	a5,a5,1
 224:	fff5c703          	lbu	a4,-1(a1)
 228:	fee78fa3          	sb	a4,-1(a5)
 22c:	fe0718e3          	bnez	a4,21c <strcpy+0x14>
    ;
  return os;
}
 230:	00813083          	ld	ra,8(sp)
 234:	00013403          	ld	s0,0(sp)
 238:	01010113          	addi	sp,sp,16
 23c:	00008067          	ret

0000000000000240 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 240:	ff010113          	addi	sp,sp,-16
 244:	00113423          	sd	ra,8(sp)
 248:	00813023          	sd	s0,0(sp)
 24c:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 250:	00054783          	lbu	a5,0(a0)
 254:	00078e63          	beqz	a5,270 <strcmp+0x30>
 258:	0005c703          	lbu	a4,0(a1)
 25c:	00f71a63          	bne	a4,a5,270 <strcmp+0x30>
    p++, q++;
 260:	00150513          	addi	a0,a0,1
 264:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 268:	00054783          	lbu	a5,0(a0)
 26c:	fe0796e3          	bnez	a5,258 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 270:	0005c503          	lbu	a0,0(a1)
}
 274:	40a7853b          	subw	a0,a5,a0
 278:	00813083          	ld	ra,8(sp)
 27c:	00013403          	ld	s0,0(sp)
 280:	01010113          	addi	sp,sp,16
 284:	00008067          	ret

0000000000000288 <strlen>:

uint
strlen(const char *s)
{
 288:	ff010113          	addi	sp,sp,-16
 28c:	00113423          	sd	ra,8(sp)
 290:	00813023          	sd	s0,0(sp)
 294:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 298:	00054783          	lbu	a5,0(a0)
 29c:	02078663          	beqz	a5,2c8 <strlen+0x40>
 2a0:	00150793          	addi	a5,a0,1
 2a4:	00078693          	mv	a3,a5
 2a8:	00178793          	addi	a5,a5,1
 2ac:	fff7c703          	lbu	a4,-1(a5)
 2b0:	fe071ae3          	bnez	a4,2a4 <strlen+0x1c>
 2b4:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 2b8:	00813083          	ld	ra,8(sp)
 2bc:	00013403          	ld	s0,0(sp)
 2c0:	01010113          	addi	sp,sp,16
 2c4:	00008067          	ret
  for(n = 0; s[n]; n++)
 2c8:	00000513          	li	a0,0
 2cc:	fedff06f          	j	2b8 <strlen+0x30>

00000000000002d0 <memset>:

void*
memset(void *dst, int c, uint n)
{
 2d0:	ff010113          	addi	sp,sp,-16
 2d4:	00113423          	sd	ra,8(sp)
 2d8:	00813023          	sd	s0,0(sp)
 2dc:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 2e0:	02060063          	beqz	a2,300 <memset+0x30>
 2e4:	00050793          	mv	a5,a0
 2e8:	02061613          	slli	a2,a2,0x20
 2ec:	02065613          	srli	a2,a2,0x20
 2f0:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 2f4:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 2f8:	00178793          	addi	a5,a5,1
 2fc:	fee79ce3          	bne	a5,a4,2f4 <memset+0x24>
  }
  return dst;
}
 300:	00813083          	ld	ra,8(sp)
 304:	00013403          	ld	s0,0(sp)
 308:	01010113          	addi	sp,sp,16
 30c:	00008067          	ret

0000000000000310 <strchr>:

char*
strchr(const char *s, char c)
{
 310:	ff010113          	addi	sp,sp,-16
 314:	00113423          	sd	ra,8(sp)
 318:	00813023          	sd	s0,0(sp)
 31c:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 320:	00054783          	lbu	a5,0(a0)
 324:	02078463          	beqz	a5,34c <strchr+0x3c>
    if(*s == c)
 328:	00f58a63          	beq	a1,a5,33c <strchr+0x2c>
  for(; *s; s++)
 32c:	00150513          	addi	a0,a0,1
 330:	00054783          	lbu	a5,0(a0)
 334:	fe079ae3          	bnez	a5,328 <strchr+0x18>
      return (char*)s;
  return 0;
 338:	00000513          	li	a0,0
}
 33c:	00813083          	ld	ra,8(sp)
 340:	00013403          	ld	s0,0(sp)
 344:	01010113          	addi	sp,sp,16
 348:	00008067          	ret
  return 0;
 34c:	00000513          	li	a0,0
 350:	fedff06f          	j	33c <strchr+0x2c>

0000000000000354 <gets>:

char*
gets(char *buf, int max)
{
 354:	fa010113          	addi	sp,sp,-96
 358:	04113c23          	sd	ra,88(sp)
 35c:	04813823          	sd	s0,80(sp)
 360:	04913423          	sd	s1,72(sp)
 364:	05213023          	sd	s2,64(sp)
 368:	03313c23          	sd	s3,56(sp)
 36c:	03413823          	sd	s4,48(sp)
 370:	03513423          	sd	s5,40(sp)
 374:	03613023          	sd	s6,32(sp)
 378:	01713c23          	sd	s7,24(sp)
 37c:	01813823          	sd	s8,16(sp)
 380:	06010413          	addi	s0,sp,96
 384:	00050b93          	mv	s7,a0
 388:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 38c:	00050913          	mv	s2,a0
 390:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 394:	faf40b13          	addi	s6,s0,-81
 398:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 39c:	00048c13          	mv	s8,s1
 3a0:	0014899b          	addiw	s3,s1,1
 3a4:	00098493          	mv	s1,s3
 3a8:	0349dc63          	bge	s3,s4,3e0 <gets+0x8c>
    cc = read(0, &c, 1);
 3ac:	000a8613          	mv	a2,s5
 3b0:	000b0593          	mv	a1,s6
 3b4:	00000513          	li	a0,0
 3b8:	2bc000ef          	jal	674 <read>
    if(cc < 1)
 3bc:	02a05263          	blez	a0,3e0 <gets+0x8c>
      break;
    buf[i++] = c;
 3c0:	faf44783          	lbu	a5,-81(s0)
 3c4:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 3c8:	00190913          	addi	s2,s2,1
 3cc:	ff678713          	addi	a4,a5,-10
 3d0:	00070663          	beqz	a4,3dc <gets+0x88>
 3d4:	ff378793          	addi	a5,a5,-13
 3d8:	fc0792e3          	bnez	a5,39c <gets+0x48>
    buf[i++] = c;
 3dc:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 3e0:	018b8c33          	add	s8,s7,s8
 3e4:	000c0023          	sb	zero,0(s8)
  return buf;
}
 3e8:	000b8513          	mv	a0,s7
 3ec:	05813083          	ld	ra,88(sp)
 3f0:	05013403          	ld	s0,80(sp)
 3f4:	04813483          	ld	s1,72(sp)
 3f8:	04013903          	ld	s2,64(sp)
 3fc:	03813983          	ld	s3,56(sp)
 400:	03013a03          	ld	s4,48(sp)
 404:	02813a83          	ld	s5,40(sp)
 408:	02013b03          	ld	s6,32(sp)
 40c:	01813b83          	ld	s7,24(sp)
 410:	01013c03          	ld	s8,16(sp)
 414:	06010113          	addi	sp,sp,96
 418:	00008067          	ret

000000000000041c <stat>:

int
stat(const char *n, struct stat *st)
{
 41c:	fe010113          	addi	sp,sp,-32
 420:	00113c23          	sd	ra,24(sp)
 424:	00813823          	sd	s0,16(sp)
 428:	01213023          	sd	s2,0(sp)
 42c:	02010413          	addi	s0,sp,32
 430:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 434:	00000593          	li	a1,0
 438:	278000ef          	jal	6b0 <open>
  if(fd < 0)
 43c:	02054e63          	bltz	a0,478 <stat+0x5c>
 440:	00913423          	sd	s1,8(sp)
 444:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 448:	00090593          	mv	a1,s2
 44c:	288000ef          	jal	6d4 <fstat>
 450:	00050913          	mv	s2,a0
  close(fd);
 454:	00048513          	mv	a0,s1
 458:	234000ef          	jal	68c <close>
  return r;
 45c:	00813483          	ld	s1,8(sp)
}
 460:	00090513          	mv	a0,s2
 464:	01813083          	ld	ra,24(sp)
 468:	01013403          	ld	s0,16(sp)
 46c:	00013903          	ld	s2,0(sp)
 470:	02010113          	addi	sp,sp,32
 474:	00008067          	ret
    return -1;
 478:	fff00793          	li	a5,-1
 47c:	00078913          	mv	s2,a5
 480:	fe1ff06f          	j	460 <stat+0x44>

0000000000000484 <atoi>:

int
atoi(const char *s)
{
 484:	ff010113          	addi	sp,sp,-16
 488:	00113423          	sd	ra,8(sp)
 48c:	00813023          	sd	s0,0(sp)
 490:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 494:	00054683          	lbu	a3,0(a0)
 498:	fd06879b          	addiw	a5,a3,-48
 49c:	0ff7f793          	zext.b	a5,a5
 4a0:	00900613          	li	a2,9
 4a4:	04f66263          	bltu	a2,a5,4e8 <atoi+0x64>
 4a8:	00050713          	mv	a4,a0
  n = 0;
 4ac:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 4b0:	00170713          	addi	a4,a4,1
 4b4:	0025179b          	slliw	a5,a0,0x2
 4b8:	00a787bb          	addw	a5,a5,a0
 4bc:	0017979b          	slliw	a5,a5,0x1
 4c0:	00d787bb          	addw	a5,a5,a3
 4c4:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 4c8:	00074683          	lbu	a3,0(a4)
 4cc:	fd06879b          	addiw	a5,a3,-48
 4d0:	0ff7f793          	zext.b	a5,a5
 4d4:	fcf67ee3          	bgeu	a2,a5,4b0 <atoi+0x2c>
  return n;
}
 4d8:	00813083          	ld	ra,8(sp)
 4dc:	00013403          	ld	s0,0(sp)
 4e0:	01010113          	addi	sp,sp,16
 4e4:	00008067          	ret
  n = 0;
 4e8:	00000513          	li	a0,0
 4ec:	fedff06f          	j	4d8 <atoi+0x54>

00000000000004f0 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 4f0:	ff010113          	addi	sp,sp,-16
 4f4:	00113423          	sd	ra,8(sp)
 4f8:	00813023          	sd	s0,0(sp)
 4fc:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 500:	02b57e63          	bgeu	a0,a1,53c <memmove+0x4c>
    while(n-- > 0)
 504:	02c05463          	blez	a2,52c <memmove+0x3c>
 508:	02061613          	slli	a2,a2,0x20
 50c:	02065613          	srli	a2,a2,0x20
 510:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 514:	00050713          	mv	a4,a0
      *dst++ = *src++;
 518:	00158593          	addi	a1,a1,1
 51c:	00170713          	addi	a4,a4,1
 520:	fff5c683          	lbu	a3,-1(a1)
 524:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 528:	fee798e3          	bne	a5,a4,518 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 52c:	00813083          	ld	ra,8(sp)
 530:	00013403          	ld	s0,0(sp)
 534:	01010113          	addi	sp,sp,16
 538:	00008067          	ret
    while(n-- > 0)
 53c:	fec058e3          	blez	a2,52c <memmove+0x3c>
    dst += n;
 540:	00c50733          	add	a4,a0,a2
    src += n;
 544:	00c585b3          	add	a1,a1,a2
 548:	fff6079b          	addiw	a5,a2,-1
 54c:	02079793          	slli	a5,a5,0x20
 550:	0207d793          	srli	a5,a5,0x20
 554:	fff7c793          	not	a5,a5
 558:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 55c:	fff58593          	addi	a1,a1,-1
 560:	fff70713          	addi	a4,a4,-1
 564:	0005c683          	lbu	a3,0(a1)
 568:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 56c:	fef718e3          	bne	a4,a5,55c <memmove+0x6c>
 570:	fbdff06f          	j	52c <memmove+0x3c>

0000000000000574 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 574:	ff010113          	addi	sp,sp,-16
 578:	00113423          	sd	ra,8(sp)
 57c:	00813023          	sd	s0,0(sp)
 580:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 584:	04060263          	beqz	a2,5c8 <memcmp+0x54>
 588:	02061613          	slli	a2,a2,0x20
 58c:	02065613          	srli	a2,a2,0x20
 590:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 594:	00054783          	lbu	a5,0(a0)
 598:	0005c703          	lbu	a4,0(a1)
 59c:	00e79c63          	bne	a5,a4,5b4 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 5a0:	00150513          	addi	a0,a0,1
    p2++;
 5a4:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 5a8:	fed516e3          	bne	a0,a3,594 <memcmp+0x20>
  }
  return 0;
 5ac:	00000513          	li	a0,0
 5b0:	0080006f          	j	5b8 <memcmp+0x44>
      return *p1 - *p2;
 5b4:	40e7853b          	subw	a0,a5,a4
}
 5b8:	00813083          	ld	ra,8(sp)
 5bc:	00013403          	ld	s0,0(sp)
 5c0:	01010113          	addi	sp,sp,16
 5c4:	00008067          	ret
  return 0;
 5c8:	00000513          	li	a0,0
 5cc:	fedff06f          	j	5b8 <memcmp+0x44>

00000000000005d0 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 5d0:	ff010113          	addi	sp,sp,-16
 5d4:	00113423          	sd	ra,8(sp)
 5d8:	00813023          	sd	s0,0(sp)
 5dc:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 5e0:	f11ff0ef          	jal	4f0 <memmove>
}
 5e4:	00813083          	ld	ra,8(sp)
 5e8:	00013403          	ld	s0,0(sp)
 5ec:	01010113          	addi	sp,sp,16
 5f0:	00008067          	ret

00000000000005f4 <sbrk>:

char *
sbrk(int n) {
 5f4:	ff010113          	addi	sp,sp,-16
 5f8:	00113423          	sd	ra,8(sp)
 5fc:	00813023          	sd	s0,0(sp)
 600:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 604:	00100593          	li	a1,1
 608:	114000ef          	jal	71c <sys_sbrk>
}
 60c:	00813083          	ld	ra,8(sp)
 610:	00013403          	ld	s0,0(sp)
 614:	01010113          	addi	sp,sp,16
 618:	00008067          	ret

000000000000061c <sbrklazy>:

char *
sbrklazy(int n) {
 61c:	ff010113          	addi	sp,sp,-16
 620:	00113423          	sd	ra,8(sp)
 624:	00813023          	sd	s0,0(sp)
 628:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 62c:	00200593          	li	a1,2
 630:	0ec000ef          	jal	71c <sys_sbrk>
}
 634:	00813083          	ld	ra,8(sp)
 638:	00013403          	ld	s0,0(sp)
 63c:	01010113          	addi	sp,sp,16
 640:	00008067          	ret

0000000000000644 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 644:	00100893          	li	a7,1
 ecall
 648:	00000073          	ecall
 ret
 64c:	00008067          	ret

0000000000000650 <exit>:
.global exit
exit:
 li a7, SYS_exit
 650:	00200893          	li	a7,2
 ecall
 654:	00000073          	ecall
 ret
 658:	00008067          	ret

000000000000065c <wait>:
.global wait
wait:
 li a7, SYS_wait
 65c:	00300893          	li	a7,3
 ecall
 660:	00000073          	ecall
 ret
 664:	00008067          	ret

0000000000000668 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 668:	00400893          	li	a7,4
 ecall
 66c:	00000073          	ecall
 ret
 670:	00008067          	ret

0000000000000674 <read>:
.global read
read:
 li a7, SYS_read
 674:	00500893          	li	a7,5
 ecall
 678:	00000073          	ecall
 ret
 67c:	00008067          	ret

0000000000000680 <write>:
.global write
write:
 li a7, SYS_write
 680:	01000893          	li	a7,16
 ecall
 684:	00000073          	ecall
 ret
 688:	00008067          	ret

000000000000068c <close>:
.global close
close:
 li a7, SYS_close
 68c:	01500893          	li	a7,21
 ecall
 690:	00000073          	ecall
 ret
 694:	00008067          	ret

0000000000000698 <kill>:
.global kill
kill:
 li a7, SYS_kill
 698:	00600893          	li	a7,6
 ecall
 69c:	00000073          	ecall
 ret
 6a0:	00008067          	ret

00000000000006a4 <exec>:
.global exec
exec:
 li a7, SYS_exec
 6a4:	00700893          	li	a7,7
 ecall
 6a8:	00000073          	ecall
 ret
 6ac:	00008067          	ret

00000000000006b0 <open>:
.global open
open:
 li a7, SYS_open
 6b0:	00f00893          	li	a7,15
 ecall
 6b4:	00000073          	ecall
 ret
 6b8:	00008067          	ret

00000000000006bc <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 6bc:	01100893          	li	a7,17
 ecall
 6c0:	00000073          	ecall
 ret
 6c4:	00008067          	ret

00000000000006c8 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 6c8:	01200893          	li	a7,18
 ecall
 6cc:	00000073          	ecall
 ret
 6d0:	00008067          	ret

00000000000006d4 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 6d4:	00800893          	li	a7,8
 ecall
 6d8:	00000073          	ecall
 ret
 6dc:	00008067          	ret

00000000000006e0 <link>:
.global link
link:
 li a7, SYS_link
 6e0:	01300893          	li	a7,19
 ecall
 6e4:	00000073          	ecall
 ret
 6e8:	00008067          	ret

00000000000006ec <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 6ec:	01400893          	li	a7,20
 ecall
 6f0:	00000073          	ecall
 ret
 6f4:	00008067          	ret

00000000000006f8 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 6f8:	00900893          	li	a7,9
 ecall
 6fc:	00000073          	ecall
 ret
 700:	00008067          	ret

0000000000000704 <dup>:
.global dup
dup:
 li a7, SYS_dup
 704:	00a00893          	li	a7,10
 ecall
 708:	00000073          	ecall
 ret
 70c:	00008067          	ret

0000000000000710 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 710:	00b00893          	li	a7,11
 ecall
 714:	00000073          	ecall
 ret
 718:	00008067          	ret

000000000000071c <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 71c:	00c00893          	li	a7,12
 ecall
 720:	00000073          	ecall
 ret
 724:	00008067          	ret

0000000000000728 <pause>:
.global pause
pause:
 li a7, SYS_pause
 728:	00d00893          	li	a7,13
 ecall
 72c:	00000073          	ecall
 ret
 730:	00008067          	ret

0000000000000734 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 734:	00e00893          	li	a7,14
 ecall
 738:	00000073          	ecall
 ret
 73c:	00008067          	ret

0000000000000740 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 740:	00002617          	auipc	a2,0x2
 744:	8d062603          	lw	a2,-1840(a2) # 2010 <putc_n>
 748:	00c04463          	bgtz	a2,750 <putc_flush+0x10>
 74c:	00008067          	ret
{
 750:	ff010113          	addi	sp,sp,-16
 754:	00113423          	sd	ra,8(sp)
 758:	00813023          	sd	s0,0(sp)
 75c:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 760:	00002597          	auipc	a1,0x2
 764:	ac058593          	addi	a1,a1,-1344 # 2220 <putc_buf>
 768:	00002517          	auipc	a0,0x2
 76c:	89852503          	lw	a0,-1896(a0) # 2000 <putc_fd>
 770:	f11ff0ef          	jal	680 <write>
    putc_n = 0;
 774:	00002797          	auipc	a5,0x2
 778:	8807ae23          	sw	zero,-1892(a5) # 2010 <putc_n>
  }
}
 77c:	00813083          	ld	ra,8(sp)
 780:	00013403          	ld	s0,0(sp)
 784:	01010113          	addi	sp,sp,16
 788:	00008067          	ret

000000000000078c <putc>:

static void
putc(int fd, char c)
{
 78c:	fe010113          	addi	sp,sp,-32
 790:	00113c23          	sd	ra,24(sp)
 794:	00813823          	sd	s0,16(sp)
 798:	00913423          	sd	s1,8(sp)
 79c:	02010413          	addi	s0,sp,32
 7a0:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 7a4:	00002797          	auipc	a5,0x2
 7a8:	85c7a783          	lw	a5,-1956(a5) # 2000 <putc_fd>
 7ac:	04a79663          	bne	a5,a0,7f8 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 7b0:	00002717          	auipc	a4,0x2
 7b4:	86070713          	addi	a4,a4,-1952 # 2010 <putc_n>
 7b8:	00072683          	lw	a3,0(a4)
 7bc:	0016879b          	addiw	a5,a3,1
 7c0:	00f72023          	sw	a5,0(a4)
 7c4:	00002717          	auipc	a4,0x2
 7c8:	a5c70713          	addi	a4,a4,-1444 # 2220 <putc_buf>
 7cc:	00d70733          	add	a4,a4,a3
 7d0:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 7d4:	ff648493          	addi	s1,s1,-10
 7d8:	02048e63          	beqz	s1,814 <putc+0x88>
 7dc:	f8078793          	addi	a5,a5,-128
 7e0:	02078a63          	beqz	a5,814 <putc+0x88>
    putc_flush();
}
 7e4:	01813083          	ld	ra,24(sp)
 7e8:	01013403          	ld	s0,16(sp)
 7ec:	00813483          	ld	s1,8(sp)
 7f0:	02010113          	addi	sp,sp,32
 7f4:	00008067          	ret
 7f8:	01213023          	sd	s2,0(sp)
 7fc:	00050913          	mv	s2,a0
    putc_flush();
 800:	f41ff0ef          	jal	740 <putc_flush>
    putc_fd = fd;
 804:	00001797          	auipc	a5,0x1
 808:	7f27ae23          	sw	s2,2044(a5) # 2000 <putc_fd>
 80c:	00013903          	ld	s2,0(sp)
 810:	fa1ff06f          	j	7b0 <putc+0x24>
    putc_flush();
 814:	f2dff0ef          	jal	740 <putc_flush>
}
 818:	fcdff06f          	j	7e4 <putc+0x58>

000000000000081c <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 81c:	fb010113          	addi	sp,sp,-80
 820:	04113423          	sd	ra,72(sp)
 824:	04813023          	sd	s0,64(sp)
 828:	03213823          	sd	s2,48(sp)
 82c:	03313423          	sd	s3,40(sp)
 830:	05010413          	addi	s0,sp,80
 834:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 838:	0a068e63          	beqz	a3,8f4 <printint+0xd8>
 83c:	0a05dc63          	bgez	a1,8f4 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 840:	40b005b3          	neg	a1,a1
    neg = 1;
 844:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 848:	fb840993          	addi	s3,s0,-72
  neg = 0;
 84c:	00098693          	mv	a3,s3
  i = 0;
 850:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 854:	00000817          	auipc	a6,0x0
 858:	79c80813          	addi	a6,a6,1948 # ff0 <digits>
 85c:	00070893          	mv	a7,a4
 860:	0017051b          	addiw	a0,a4,1
 864:	00050713          	mv	a4,a0
 868:	02c5f7b3          	remu	a5,a1,a2
 86c:	00f807b3          	add	a5,a6,a5
 870:	0007c783          	lbu	a5,0(a5)
 874:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 878:	00058793          	mv	a5,a1
 87c:	02c5d5b3          	divu	a1,a1,a2
 880:	00168693          	addi	a3,a3,1
 884:	fcc7fce3          	bgeu	a5,a2,85c <printint+0x40>
  if (neg)
 888:	00030c63          	beqz	t1,8a0 <printint+0x84>
    buf[i++] = '-';
 88c:	fd050793          	addi	a5,a0,-48
 890:	00878533          	add	a0,a5,s0
 894:	02d00793          	li	a5,45
 898:	fef50423          	sb	a5,-24(a0)
 89c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 8a0:	02e05e63          	blez	a4,8dc <printint+0xc0>
 8a4:	02913c23          	sd	s1,56(sp)
 8a8:	fff7071b          	addiw	a4,a4,-1
 8ac:	00e984b3          	add	s1,s3,a4
 8b0:	fff98993          	addi	s3,s3,-1
 8b4:	00e989b3          	add	s3,s3,a4
 8b8:	02071713          	slli	a4,a4,0x20
 8bc:	02075713          	srli	a4,a4,0x20
 8c0:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 8c4:	0004c583          	lbu	a1,0(s1)
 8c8:	00090513          	mv	a0,s2
 8cc:	ec1ff0ef          	jal	78c <putc>
  while (--i >= 0)
 8d0:	fff48493          	addi	s1,s1,-1
 8d4:	ff3498e3          	bne	s1,s3,8c4 <printint+0xa8>
 8d8:	03813483          	ld	s1,56(sp)
}
 8dc:	04813083          	ld	ra,72(sp)
 8e0:	04013403          	ld	s0,64(sp)
 8e4:	03013903          	ld	s2,48(sp)
 8e8:	02813983          	ld	s3,40(sp)
 8ec:	05010113          	addi	sp,sp,80
 8f0:	00008067          	ret
  neg = 0;
 8f4:	00000313          	li	t1,0
 8f8:	f51ff06f          	j	848 <printint+0x2c>

00000000000008fc <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 8fc:	fa010113          	addi	sp,sp,-96
 900:	04113c23          	sd	ra,88(sp)
 904:	04813823          	sd	s0,80(sp)
 908:	04913423          	sd	s1,72(sp)
 90c:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 910:	0005c483          	lbu	s1,0(a1)
 914:	32048263          	beqz	s1,c38 <vprintf+0x33c>
 918:	05213023          	sd	s2,64(sp)
 91c:	03313c23          	sd	s3,56(sp)
 920:	03413823          	sd	s4,48(sp)
 924:	03513423          	sd	s5,40(sp)
 928:	03613023          	sd	s6,32(sp)
 92c:	01713c23          	sd	s7,24(sp)
 930:	01813823          	sd	s8,16(sp)
 934:	00050b13          	mv	s6,a0
 938:	00058a13          	mv	s4,a1
 93c:	00060b93          	mv	s7,a2
  state = 0;
 940:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 944:	00000913          	li	s2,0
 948:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 94c:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 950:	06400c13          	li	s8,100
 954:	0300006f          	j	984 <vprintf+0x88>
        putc(fd, c0);
 958:	00048593          	mv	a1,s1
 95c:	000b0513          	mv	a0,s6
 960:	e2dff0ef          	jal	78c <putc>
 964:	0080006f          	j	96c <vprintf+0x70>
    else if (state == '%')
 968:	03598863          	beq	s3,s5,998 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 96c:	0019079b          	addiw	a5,s2,1
 970:	00078913          	mv	s2,a5
 974:	00078713          	mv	a4,a5
 978:	00fa07b3          	add	a5,s4,a5
 97c:	0007c483          	lbu	s1,0(a5)
 980:	28048e63          	beqz	s1,c1c <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 984:	0004879b          	sext.w	a5,s1
    if (state == 0)
 988:	fe0990e3          	bnez	s3,968 <vprintf+0x6c>
      if (c0 == '%')
 98c:	fd5796e3          	bne	a5,s5,958 <vprintf+0x5c>
        state = '%';
 990:	00078993          	mv	s3,a5
 994:	fd9ff06f          	j	96c <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 998:	00ea06b3          	add	a3,s4,a4
 99c:	0016c603          	lbu	a2,1(a3)
      if (c1)
 9a0:	2a060663          	beqz	a2,c4c <vprintf+0x350>
      if (c0 == 'd')
 9a4:	05878063          	beq	a5,s8,9e4 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 9a8:	f9478693          	addi	a3,a5,-108
 9ac:	0016b693          	seqz	a3,a3
 9b0:	f9c60593          	addi	a1,a2,-100
 9b4:	04059a63          	bnez	a1,a08 <vprintf+0x10c>
 9b8:	04068863          	beqz	a3,a08 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 9bc:	008b8493          	addi	s1,s7,8
 9c0:	00100693          	li	a3,1
 9c4:	00a00613          	li	a2,10
 9c8:	000bb583          	ld	a1,0(s7)
 9cc:	000b0513          	mv	a0,s6
 9d0:	e4dff0ef          	jal	81c <printint>
        i += 1;
 9d4:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 9d8:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 9dc:	00000993          	li	s3,0
 9e0:	f8dff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 9e4:	008b8493          	addi	s1,s7,8
 9e8:	00100693          	li	a3,1
 9ec:	00a00613          	li	a2,10
 9f0:	000ba583          	lw	a1,0(s7)
 9f4:	000b0513          	mv	a0,s6
 9f8:	e25ff0ef          	jal	81c <printint>
 9fc:	00048b93          	mv	s7,s1
      state = 0;
 a00:	00000993          	li	s3,0
 a04:	f69ff06f          	j	96c <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 a08:	00ea0733          	add	a4,s4,a4
 a0c:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 a10:	f9460713          	addi	a4,a2,-108
 a14:	00173713          	seqz	a4,a4
 a18:	00e6f733          	and	a4,a3,a4
 a1c:	f9c58513          	addi	a0,a1,-100
 a20:	24051263          	bnez	a0,c64 <vprintf+0x368>
 a24:	24070063          	beqz	a4,c64 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 a28:	008b8493          	addi	s1,s7,8
 a2c:	00100693          	li	a3,1
 a30:	00a00613          	li	a2,10
 a34:	000bb583          	ld	a1,0(s7)
 a38:	000b0513          	mv	a0,s6
 a3c:	de1ff0ef          	jal	81c <printint>
        i += 2;
 a40:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 a44:	00048b93          	mv	s7,s1
      state = 0;
 a48:	00000993          	li	s3,0
        i += 2;
 a4c:	f21ff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 a50:	008b8493          	addi	s1,s7,8
 a54:	00000693          	li	a3,0
 a58:	00a00613          	li	a2,10
 a5c:	000be583          	lwu	a1,0(s7)
 a60:	000b0513          	mv	a0,s6
 a64:	db9ff0ef          	jal	81c <printint>
 a68:	00048b93          	mv	s7,s1
      state = 0;
 a6c:	00000993          	li	s3,0
 a70:	efdff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 a74:	008b8493          	addi	s1,s7,8
 a78:	00000693          	li	a3,0
 a7c:	00a00613          	li	a2,10
 a80:	000bb583          	ld	a1,0(s7)
 a84:	000b0513          	mv	a0,s6
 a88:	d95ff0ef          	jal	81c <printint>
        i += 1;
 a8c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 a90:	00048b93          	mv	s7,s1
      state = 0;
 a94:	00000993          	li	s3,0
 a98:	ed5ff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 a9c:	008b8493          	addi	s1,s7,8
 aa0:	00000693          	li	a3,0
 aa4:	00a00613          	li	a2,10
 aa8:	000bb583          	ld	a1,0(s7)
 aac:	000b0513          	mv	a0,s6
 ab0:	d6dff0ef          	jal	81c <printint>
        i += 2;
 ab4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 ab8:	00048b93          	mv	s7,s1
      state = 0;
 abc:	00000993          	li	s3,0
        i += 2;
 ac0:	eadff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 ac4:	008b8493          	addi	s1,s7,8
 ac8:	00000693          	li	a3,0
 acc:	01000613          	li	a2,16
 ad0:	000be583          	lwu	a1,0(s7)
 ad4:	000b0513          	mv	a0,s6
 ad8:	d45ff0ef          	jal	81c <printint>
 adc:	00048b93          	mv	s7,s1
      state = 0;
 ae0:	00000993          	li	s3,0
 ae4:	e89ff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 ae8:	008b8493          	addi	s1,s7,8
 aec:	00000693          	li	a3,0
 af0:	01000613          	li	a2,16
 af4:	000bb583          	ld	a1,0(s7)
 af8:	000b0513          	mv	a0,s6
 afc:	d21ff0ef          	jal	81c <printint>
        i += 1;
 b00:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 b04:	00048b93          	mv	s7,s1
      state = 0;
 b08:	00000993          	li	s3,0
 b0c:	e61ff06f          	j	96c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 b10:	008b8493          	addi	s1,s7,8
 b14:	00000693          	li	a3,0
 b18:	01000613          	li	a2,16
 b1c:	000bb583          	ld	a1,0(s7)
 b20:	000b0513          	mv	a0,s6
 b24:	cf9ff0ef          	jal	81c <printint>
        i += 2;
 b28:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 b2c:	00048b93          	mv	s7,s1
      state = 0;
 b30:	00000993          	li	s3,0
        i += 2;
 b34:	e39ff06f          	j	96c <vprintf+0x70>
 b38:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 b3c:	008b8793          	addi	a5,s7,8
 b40:	00078c93          	mv	s9,a5
 b44:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 b48:	03000593          	li	a1,48
 b4c:	000b0513          	mv	a0,s6
 b50:	c3dff0ef          	jal	78c <putc>
  putc(fd, 'x');
 b54:	07800593          	li	a1,120
 b58:	000b0513          	mv	a0,s6
 b5c:	c31ff0ef          	jal	78c <putc>
 b60:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 b64:	00000b97          	auipc	s7,0x0
 b68:	48cb8b93          	addi	s7,s7,1164 # ff0 <digits>
 b6c:	03c9d793          	srli	a5,s3,0x3c
 b70:	00fb87b3          	add	a5,s7,a5
 b74:	0007c583          	lbu	a1,0(a5)
 b78:	000b0513          	mv	a0,s6
 b7c:	c11ff0ef          	jal	78c <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 b80:	00499993          	slli	s3,s3,0x4
 b84:	fff4849b          	addiw	s1,s1,-1
 b88:	fe0492e3          	bnez	s1,b6c <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 b8c:	000c8b93          	mv	s7,s9
      state = 0;
 b90:	00000993          	li	s3,0
 b94:	00813c83          	ld	s9,8(sp)
 b98:	dd5ff06f          	j	96c <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 b9c:	008b8493          	addi	s1,s7,8
 ba0:	000bc583          	lbu	a1,0(s7)
 ba4:	000b0513          	mv	a0,s6
 ba8:	be5ff0ef          	jal	78c <putc>
 bac:	00048b93          	mv	s7,s1
      state = 0;
 bb0:	00000993          	li	s3,0
 bb4:	db9ff06f          	j	96c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 bb8:	008b8993          	addi	s3,s7,8
 bbc:	000bb483          	ld	s1,0(s7)
 bc0:	02048663          	beqz	s1,bec <vprintf+0x2f0>
        for (; *s; s++)
 bc4:	0004c583          	lbu	a1,0(s1)
 bc8:	04058463          	beqz	a1,c10 <vprintf+0x314>
          putc(fd, *s);
 bcc:	000b0513          	mv	a0,s6
 bd0:	bbdff0ef          	jal	78c <putc>
        for (; *s; s++)
 bd4:	00148493          	addi	s1,s1,1
 bd8:	0004c583          	lbu	a1,0(s1)
 bdc:	fe0598e3          	bnez	a1,bcc <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 be0:	00098b93          	mv	s7,s3
      state = 0;
 be4:	00000993          	li	s3,0
 be8:	d85ff06f          	j	96c <vprintf+0x70>
          s = "(null)";
 bec:	00000497          	auipc	s1,0x0
 bf0:	3fc48493          	addi	s1,s1,1020 # fe8 <malloc+0x1b4>
        for (; *s; s++)
 bf4:	02800593          	li	a1,40
 bf8:	fd5ff06f          	j	bcc <vprintf+0x2d0>
        putc(fd, '%');
 bfc:	00078593          	mv	a1,a5
 c00:	000b0513          	mv	a0,s6
 c04:	b89ff0ef          	jal	78c <putc>
      state = 0;
 c08:	00000993          	li	s3,0
 c0c:	d61ff06f          	j	96c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 c10:	00098b93          	mv	s7,s3
      state = 0;
 c14:	00000993          	li	s3,0
 c18:	d55ff06f          	j	96c <vprintf+0x70>
 c1c:	04013903          	ld	s2,64(sp)
 c20:	03813983          	ld	s3,56(sp)
 c24:	03013a03          	ld	s4,48(sp)
 c28:	02813a83          	ld	s5,40(sp)
 c2c:	02013b03          	ld	s6,32(sp)
 c30:	01813b83          	ld	s7,24(sp)
 c34:	01013c03          	ld	s8,16(sp)
    }
  }
}
 c38:	05813083          	ld	ra,88(sp)
 c3c:	05013403          	ld	s0,80(sp)
 c40:	04813483          	ld	s1,72(sp)
 c44:	06010113          	addi	sp,sp,96
 c48:	00008067          	ret
      if (c0 == 'd')
 c4c:	06400713          	li	a4,100
 c50:	d8e78ae3          	beq	a5,a4,9e4 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 c54:	f9478693          	addi	a3,a5,-108
 c58:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 c5c:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 c60:	00000713          	li	a4,0
      else if (c0 == 'u')
 c64:	07500513          	li	a0,117
 c68:	dea784e3          	beq	a5,a0,a50 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 c6c:	f8b60513          	addi	a0,a2,-117
 c70:	00051463          	bnez	a0,c78 <vprintf+0x37c>
 c74:	e00690e3          	bnez	a3,a74 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 c78:	f8b58513          	addi	a0,a1,-117
 c7c:	00051463          	bnez	a0,c84 <vprintf+0x388>
 c80:	e0071ee3          	bnez	a4,a9c <vprintf+0x1a0>
      else if (c0 == 'x')
 c84:	07800513          	li	a0,120
 c88:	e2a78ee3          	beq	a5,a0,ac4 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 c8c:	f8860613          	addi	a2,a2,-120
 c90:	00061463          	bnez	a2,c98 <vprintf+0x39c>
 c94:	e4069ae3          	bnez	a3,ae8 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 c98:	f8858593          	addi	a1,a1,-120
 c9c:	00059463          	bnez	a1,ca4 <vprintf+0x3a8>
 ca0:	e60718e3          	bnez	a4,b10 <vprintf+0x214>
      else if (c0 == 'p')
 ca4:	07000713          	li	a4,112
 ca8:	e8e788e3          	beq	a5,a4,b38 <vprintf+0x23c>
      else if (c0 == 'c')
 cac:	06300713          	li	a4,99
 cb0:	eee786e3          	beq	a5,a4,b9c <vprintf+0x2a0>
      else if (c0 == 's')
 cb4:	07300713          	li	a4,115
 cb8:	f0e780e3          	beq	a5,a4,bb8 <vprintf+0x2bc>
      else if (c0 == '%')
 cbc:	02500713          	li	a4,37
 cc0:	f2e78ee3          	beq	a5,a4,bfc <vprintf+0x300>
        putc(fd, '%');
 cc4:	02500593          	li	a1,37
 cc8:	000b0513          	mv	a0,s6
 ccc:	ac1ff0ef          	jal	78c <putc>
        putc(fd, c0);
 cd0:	00048593          	mv	a1,s1
 cd4:	000b0513          	mv	a0,s6
 cd8:	ab5ff0ef          	jal	78c <putc>
      state = 0;
 cdc:	00000993          	li	s3,0
 ce0:	c8dff06f          	j	96c <vprintf+0x70>

0000000000000ce4 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 ce4:	fb010113          	addi	sp,sp,-80
 ce8:	00113c23          	sd	ra,24(sp)
 cec:	00813823          	sd	s0,16(sp)
 cf0:	02010413          	addi	s0,sp,32
 cf4:	00c43023          	sd	a2,0(s0)
 cf8:	00d43423          	sd	a3,8(s0)
 cfc:	00e43823          	sd	a4,16(s0)
 d00:	00f43c23          	sd	a5,24(s0)
 d04:	03043023          	sd	a6,32(s0)
 d08:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 d0c:	00040613          	mv	a2,s0
 d10:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 d14:	be9ff0ef          	jal	8fc <vprintf>
}
 d18:	01813083          	ld	ra,24(sp)
 d1c:	01013403          	ld	s0,16(sp)
 d20:	05010113          	addi	sp,sp,80
 d24:	00008067          	ret

0000000000000d28 <printf>:

void printf(const char *fmt, ...)
{
 d28:	fa010113          	addi	sp,sp,-96
 d2c:	00113c23          	sd	ra,24(sp)
 d30:	00813823          	sd	s0,16(sp)
 d34:	02010413          	addi	s0,sp,32
 d38:	00b43423          	sd	a1,8(s0)
 d3c:	00c43823          	sd	a2,16(s0)
 d40:	00d43c23          	sd	a3,24(s0)
 d44:	02e43023          	sd	a4,32(s0)
 d48:	02f43423          	sd	a5,40(s0)
 d4c:	03043823          	sd	a6,48(s0)
 d50:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 d54:	00840613          	addi	a2,s0,8
 d58:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 d5c:	00050593          	mv	a1,a0
 d60:	00100513          	li	a0,1
 d64:	b99ff0ef          	jal	8fc <vprintf>
  putc_flush();
 d68:	9d9ff0ef          	jal	740 <putc_flush>
}
 d6c:	01813083          	ld	ra,24(sp)
 d70:	01013403          	ld	s0,16(sp)
 d74:	06010113          	addi	sp,sp,96
 d78:	00008067          	ret

0000000000000d7c <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 d7c:	ff010113          	addi	sp,sp,-16
 d80:	00113423          	sd	ra,8(sp)
 d84:	00813023          	sd	s0,0(sp)
 d88:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 d8c:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 d90:	00001797          	auipc	a5,0x1
 d94:	2887b783          	ld	a5,648(a5) # 2018 <freep>
 d98:	0140006f          	j	dac <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 d9c:	0007b703          	ld	a4,0(a5)
 da0:	00e7e463          	bltu	a5,a4,da8 <free+0x2c>
 da4:	00e6ec63          	bltu	a3,a4,dbc <free+0x40>
{
 da8:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 dac:	fed7f8e3          	bgeu	a5,a3,d9c <free+0x20>
 db0:	0007b703          	ld	a4,0(a5)
 db4:	00e6e463          	bltu	a3,a4,dbc <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 db8:	fee7e8e3          	bltu	a5,a4,da8 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 dbc:	ff852583          	lw	a1,-8(a0)
 dc0:	0007b603          	ld	a2,0(a5)
 dc4:	02059813          	slli	a6,a1,0x20
 dc8:	01c85713          	srli	a4,a6,0x1c
 dcc:	00e68733          	add	a4,a3,a4
 dd0:	02e60c63          	beq	a2,a4,e08 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 dd4:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 dd8:	0087a603          	lw	a2,8(a5)
 ddc:	02061593          	slli	a1,a2,0x20
 de0:	01c5d713          	srli	a4,a1,0x1c
 de4:	00e78733          	add	a4,a5,a4
 de8:	02e68c63          	beq	a3,a4,e20 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 dec:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 df0:	00001717          	auipc	a4,0x1
 df4:	22f73423          	sd	a5,552(a4) # 2018 <freep>
}
 df8:	00813083          	ld	ra,8(sp)
 dfc:	00013403          	ld	s0,0(sp)
 e00:	01010113          	addi	sp,sp,16
 e04:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 e08:	00862703          	lw	a4,8(a2)
 e0c:	00b7073b          	addw	a4,a4,a1
 e10:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 e14:	0007b703          	ld	a4,0(a5)
 e18:	00073603          	ld	a2,0(a4)
 e1c:	fb9ff06f          	j	dd4 <free+0x58>
    p->s.size += bp->s.size;
 e20:	ff852703          	lw	a4,-8(a0)
 e24:	00c7073b          	addw	a4,a4,a2
 e28:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 e2c:	ff053683          	ld	a3,-16(a0)
 e30:	fbdff06f          	j	dec <free+0x70>

0000000000000e34 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 e34:	fc010113          	addi	sp,sp,-64
 e38:	02113c23          	sd	ra,56(sp)
 e3c:	02813823          	sd	s0,48(sp)
 e40:	03213023          	sd	s2,32(sp)
 e44:	01313c23          	sd	s3,24(sp)
 e48:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 e4c:	02051993          	slli	s3,a0,0x20
 e50:	0209d993          	srli	s3,s3,0x20
 e54:	00f98993          	addi	s3,s3,15
 e58:	0049d993          	srli	s3,s3,0x4
 e5c:	0019899b          	addiw	s3,s3,1
 e60:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 e64:	00001517          	auipc	a0,0x1
 e68:	1b453503          	ld	a0,436(a0) # 2018 <freep>
 e6c:	04050463          	beqz	a0,eb4 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 e70:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 e74:	0087a703          	lw	a4,8(a5)
 e78:	0d377a63          	bgeu	a4,s3,f4c <malloc+0x118>
 e7c:	02913423          	sd	s1,40(sp)
 e80:	01413823          	sd	s4,16(sp)
 e84:	01513423          	sd	s5,8(sp)
 e88:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 e8c:	00098a13          	mv	s4,s3
 e90:	00001737          	lui	a4,0x1
 e94:	00e9f463          	bgeu	s3,a4,e9c <malloc+0x68>
 e98:	00001a37          	lui	s4,0x1
 e9c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 ea0:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 ea4:	00001497          	auipc	s1,0x1
 ea8:	17448493          	addi	s1,s1,372 # 2018 <freep>
  if(p == SBRK_ERROR)
 eac:	fff00a93          	li	s5,-1
 eb0:	05c0006f          	j	f0c <malloc+0xd8>
 eb4:	02913423          	sd	s1,40(sp)
 eb8:	01413823          	sd	s4,16(sp)
 ebc:	01513423          	sd	s5,8(sp)
 ec0:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 ec4:	00001797          	auipc	a5,0x1
 ec8:	3dc78793          	addi	a5,a5,988 # 22a0 <base>
 ecc:	00001717          	auipc	a4,0x1
 ed0:	14f73623          	sd	a5,332(a4) # 2018 <freep>
 ed4:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 ed8:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 edc:	fb1ff06f          	j	e8c <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 ee0:	0007b703          	ld	a4,0(a5)
 ee4:	00e53023          	sd	a4,0(a0)
 ee8:	0800006f          	j	f68 <malloc+0x134>
  hp->s.size = nu;
 eec:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 ef0:	01050513          	addi	a0,a0,16
 ef4:	e89ff0ef          	jal	d7c <free>
  return freep;
 ef8:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 efc:	08050863          	beqz	a0,f8c <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 f00:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 f04:	0087a703          	lw	a4,8(a5)
 f08:	03277a63          	bgeu	a4,s2,f3c <malloc+0x108>
    if(p == freep)
 f0c:	0004b703          	ld	a4,0(s1)
 f10:	00078513          	mv	a0,a5
 f14:	fef716e3          	bne	a4,a5,f00 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 f18:	000a0513          	mv	a0,s4
 f1c:	ed8ff0ef          	jal	5f4 <sbrk>
  if(p == SBRK_ERROR)
 f20:	fd5516e3          	bne	a0,s5,eec <malloc+0xb8>
        return 0;
 f24:	00000513          	li	a0,0
 f28:	02813483          	ld	s1,40(sp)
 f2c:	01013a03          	ld	s4,16(sp)
 f30:	00813a83          	ld	s5,8(sp)
 f34:	00013b03          	ld	s6,0(sp)
 f38:	03c0006f          	j	f74 <malloc+0x140>
 f3c:	02813483          	ld	s1,40(sp)
 f40:	01013a03          	ld	s4,16(sp)
 f44:	00813a83          	ld	s5,8(sp)
 f48:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 f4c:	f8e90ae3          	beq	s2,a4,ee0 <malloc+0xac>
        p->s.size -= nunits;
 f50:	4137073b          	subw	a4,a4,s3
 f54:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 f58:	02071693          	slli	a3,a4,0x20
 f5c:	01c6d713          	srli	a4,a3,0x1c
 f60:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 f64:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 f68:	00001717          	auipc	a4,0x1
 f6c:	0aa73823          	sd	a0,176(a4) # 2018 <freep>
      return (void*)(p + 1);
 f70:	01078513          	addi	a0,a5,16
  }
}
 f74:	03813083          	ld	ra,56(sp)
 f78:	03013403          	ld	s0,48(sp)
 f7c:	02013903          	ld	s2,32(sp)
 f80:	01813983          	ld	s3,24(sp)
 f84:	04010113          	addi	sp,sp,64
 f88:	00008067          	ret
 f8c:	02813483          	ld	s1,40(sp)
 f90:	01013a03          	ld	s4,16(sp)
 f94:	00813a83          	ld	s5,8(sp)
 f98:	00013b03          	ld	s6,0(sp)
 f9c:	fd9ff06f          	j	f74 <malloc+0x140>
