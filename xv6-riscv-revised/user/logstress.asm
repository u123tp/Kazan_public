
user/_logstress:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
main(int argc, char **argv)
{
  int fd, n;
  enum { N = 250, SZ=2000 };
  
  for (int i = 1; i < argc; i++){
   0:	00100793          	li	a5,1
   4:	14a7d663          	bge	a5,a0,150 <main+0x150>
{
   8:	fc010113          	addi	sp,sp,-64
   c:	02113c23          	sd	ra,56(sp)
  10:	02813823          	sd	s0,48(sp)
  14:	02913423          	sd	s1,40(sp)
  18:	03213023          	sd	s2,32(sp)
  1c:	01313c23          	sd	s3,24(sp)
  20:	01413823          	sd	s4,16(sp)
  24:	04010413          	addi	s0,sp,64
  28:	00050913          	mv	s2,a0
  2c:	00058a13          	mv	s4,a1
  for (int i = 1; i < argc; i++){
  30:	00078493          	mv	s1,a5
  34:	0080006f          	j	3c <main+0x3c>
  38:	00078493          	mv	s1,a5
    int pid1 = fork();
  3c:	570000ef          	jal	5ac <fork>
    if(pid1 < 0){
  40:	00054e63          	bltz	a0,5c <main+0x5c>
      printf("%s: fork failed\n", argv[0]);
      exit(1);
    }
    if(pid1 == 0) {
  44:	02050863          	beqz	a0,74 <main+0x74>
  for (int i = 1; i < argc; i++){
  48:	0014879b          	addiw	a5,s1,1
  4c:	fef916e3          	bne	s2,a5,38 <main+0x38>
      }
      exit(0);
    }
  }
  int xstatus;
  for(int i = 1; i < argc; i++){
  50:	00100913          	li	s2,1
    wait(&xstatus);
  54:	fcc40993          	addi	s3,s0,-52
  58:	0b80006f          	j	110 <main+0x110>
      printf("%s: fork failed\n", argv[0]);
  5c:	000a3583          	ld	a1,0(s4)
  60:	00001517          	auipc	a0,0x1
  64:	eb050513          	addi	a0,a0,-336 # f10 <malloc+0x174>
  68:	429000ef          	jal	c90 <printf>
      exit(1);
  6c:	00100513          	li	a0,1
  70:	548000ef          	jal	5b8 <exit>
      fd = open(argv[i], O_CREATE | O_RDWR);
  74:	00349913          	slli	s2,s1,0x3
  78:	012a0933          	add	s2,s4,s2
  7c:	20200593          	li	a1,514
  80:	00093503          	ld	a0,0(s2)
  84:	594000ef          	jal	618 <open>
  88:	00050993          	mv	s3,a0
      if(fd < 0){
  8c:	04054663          	bltz	a0,d8 <main+0xd8>
      memset(buf, '0'+i, SZ);
  90:	7d000613          	li	a2,2000
  94:	0304859b          	addiw	a1,s1,48
  98:	00001517          	auipc	a0,0x1
  9c:	f8850513          	addi	a0,a0,-120 # 1020 <buf>
  a0:	198000ef          	jal	238 <memset>
  a4:	0fa00493          	li	s1,250
        if((n = write(fd, buf, SZ)) != SZ){
  a8:	7d000913          	li	s2,2000
  ac:	00001a17          	auipc	s4,0x1
  b0:	f74a0a13          	addi	s4,s4,-140 # 1020 <buf>
  b4:	00090613          	mv	a2,s2
  b8:	000a0593          	mv	a1,s4
  bc:	00098513          	mv	a0,s3
  c0:	528000ef          	jal	5e8 <write>
  c4:	03251863          	bne	a0,s2,f4 <main+0xf4>
      for(i = 0; i < N; i++){
  c8:	fff4849b          	addiw	s1,s1,-1
  cc:	fe0494e3          	bnez	s1,b4 <main+0xb4>
      exit(0);
  d0:	00000513          	li	a0,0
  d4:	4e4000ef          	jal	5b8 <exit>
        printf("%s: create %s failed\n", argv[0], argv[i]);
  d8:	00093603          	ld	a2,0(s2)
  dc:	000a3583          	ld	a1,0(s4)
  e0:	00001517          	auipc	a0,0x1
  e4:	e4850513          	addi	a0,a0,-440 # f28 <malloc+0x18c>
  e8:	3a9000ef          	jal	c90 <printf>
        exit(1);
  ec:	00100513          	li	a0,1
  f0:	4c8000ef          	jal	5b8 <exit>
          printf("write failed %d\n", n);
  f4:	00050593          	mv	a1,a0
  f8:	00001517          	auipc	a0,0x1
  fc:	e4850513          	addi	a0,a0,-440 # f40 <malloc+0x1a4>
 100:	391000ef          	jal	c90 <printf>
          exit(1);
 104:	00100513          	li	a0,1
 108:	4b0000ef          	jal	5b8 <exit>
 10c:	00078913          	mv	s2,a5
    wait(&xstatus);
 110:	00098513          	mv	a0,s3
 114:	4b0000ef          	jal	5c4 <wait>
    if(xstatus != 0)
 118:	fcc42503          	lw	a0,-52(s0)
 11c:	02051863          	bnez	a0,14c <main+0x14c>
  for(int i = 1; i < argc; i++){
 120:	0019079b          	addiw	a5,s2,1
 124:	ff2494e3          	bne	s1,s2,10c <main+0x10c>
      exit(xstatus);
  }
  return 0;
}
 128:	00000513          	li	a0,0
 12c:	03813083          	ld	ra,56(sp)
 130:	03013403          	ld	s0,48(sp)
 134:	02813483          	ld	s1,40(sp)
 138:	02013903          	ld	s2,32(sp)
 13c:	01813983          	ld	s3,24(sp)
 140:	01013a03          	ld	s4,16(sp)
 144:	04010113          	addi	sp,sp,64
 148:	00008067          	ret
      exit(xstatus);
 14c:	46c000ef          	jal	5b8 <exit>
}
 150:	00000513          	li	a0,0
 154:	00008067          	ret

0000000000000158 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
 158:	ff010113          	addi	sp,sp,-16
 15c:	00113423          	sd	ra,8(sp)
 160:	00813023          	sd	s0,0(sp)
 164:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
 168:	e99ff0ef          	jal	0 <main>
  exit(r);
 16c:	44c000ef          	jal	5b8 <exit>

0000000000000170 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 170:	ff010113          	addi	sp,sp,-16
 174:	00113423          	sd	ra,8(sp)
 178:	00813023          	sd	s0,0(sp)
 17c:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 180:	00050793          	mv	a5,a0
 184:	00158593          	addi	a1,a1,1
 188:	00178793          	addi	a5,a5,1
 18c:	fff5c703          	lbu	a4,-1(a1)
 190:	fee78fa3          	sb	a4,-1(a5)
 194:	fe0718e3          	bnez	a4,184 <strcpy+0x14>
    ;
  return os;
}
 198:	00813083          	ld	ra,8(sp)
 19c:	00013403          	ld	s0,0(sp)
 1a0:	01010113          	addi	sp,sp,16
 1a4:	00008067          	ret

00000000000001a8 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 1a8:	ff010113          	addi	sp,sp,-16
 1ac:	00113423          	sd	ra,8(sp)
 1b0:	00813023          	sd	s0,0(sp)
 1b4:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 1b8:	00054783          	lbu	a5,0(a0)
 1bc:	00078e63          	beqz	a5,1d8 <strcmp+0x30>
 1c0:	0005c703          	lbu	a4,0(a1)
 1c4:	00f71a63          	bne	a4,a5,1d8 <strcmp+0x30>
    p++, q++;
 1c8:	00150513          	addi	a0,a0,1
 1cc:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 1d0:	00054783          	lbu	a5,0(a0)
 1d4:	fe0796e3          	bnez	a5,1c0 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 1d8:	0005c503          	lbu	a0,0(a1)
}
 1dc:	40a7853b          	subw	a0,a5,a0
 1e0:	00813083          	ld	ra,8(sp)
 1e4:	00013403          	ld	s0,0(sp)
 1e8:	01010113          	addi	sp,sp,16
 1ec:	00008067          	ret

00000000000001f0 <strlen>:

uint
strlen(const char *s)
{
 1f0:	ff010113          	addi	sp,sp,-16
 1f4:	00113423          	sd	ra,8(sp)
 1f8:	00813023          	sd	s0,0(sp)
 1fc:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 200:	00054783          	lbu	a5,0(a0)
 204:	02078663          	beqz	a5,230 <strlen+0x40>
 208:	00150793          	addi	a5,a0,1
 20c:	00078693          	mv	a3,a5
 210:	00178793          	addi	a5,a5,1
 214:	fff7c703          	lbu	a4,-1(a5)
 218:	fe071ae3          	bnez	a4,20c <strlen+0x1c>
 21c:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 220:	00813083          	ld	ra,8(sp)
 224:	00013403          	ld	s0,0(sp)
 228:	01010113          	addi	sp,sp,16
 22c:	00008067          	ret
  for(n = 0; s[n]; n++)
 230:	00000513          	li	a0,0
 234:	fedff06f          	j	220 <strlen+0x30>

0000000000000238 <memset>:

void*
memset(void *dst, int c, uint n)
{
 238:	ff010113          	addi	sp,sp,-16
 23c:	00113423          	sd	ra,8(sp)
 240:	00813023          	sd	s0,0(sp)
 244:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 248:	02060063          	beqz	a2,268 <memset+0x30>
 24c:	00050793          	mv	a5,a0
 250:	02061613          	slli	a2,a2,0x20
 254:	02065613          	srli	a2,a2,0x20
 258:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 25c:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 260:	00178793          	addi	a5,a5,1
 264:	fee79ce3          	bne	a5,a4,25c <memset+0x24>
  }
  return dst;
}
 268:	00813083          	ld	ra,8(sp)
 26c:	00013403          	ld	s0,0(sp)
 270:	01010113          	addi	sp,sp,16
 274:	00008067          	ret

0000000000000278 <strchr>:

char*
strchr(const char *s, char c)
{
 278:	ff010113          	addi	sp,sp,-16
 27c:	00113423          	sd	ra,8(sp)
 280:	00813023          	sd	s0,0(sp)
 284:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 288:	00054783          	lbu	a5,0(a0)
 28c:	02078463          	beqz	a5,2b4 <strchr+0x3c>
    if(*s == c)
 290:	00f58a63          	beq	a1,a5,2a4 <strchr+0x2c>
  for(; *s; s++)
 294:	00150513          	addi	a0,a0,1
 298:	00054783          	lbu	a5,0(a0)
 29c:	fe079ae3          	bnez	a5,290 <strchr+0x18>
      return (char*)s;
  return 0;
 2a0:	00000513          	li	a0,0
}
 2a4:	00813083          	ld	ra,8(sp)
 2a8:	00013403          	ld	s0,0(sp)
 2ac:	01010113          	addi	sp,sp,16
 2b0:	00008067          	ret
  return 0;
 2b4:	00000513          	li	a0,0
 2b8:	fedff06f          	j	2a4 <strchr+0x2c>

00000000000002bc <gets>:

char*
gets(char *buf, int max)
{
 2bc:	fa010113          	addi	sp,sp,-96
 2c0:	04113c23          	sd	ra,88(sp)
 2c4:	04813823          	sd	s0,80(sp)
 2c8:	04913423          	sd	s1,72(sp)
 2cc:	05213023          	sd	s2,64(sp)
 2d0:	03313c23          	sd	s3,56(sp)
 2d4:	03413823          	sd	s4,48(sp)
 2d8:	03513423          	sd	s5,40(sp)
 2dc:	03613023          	sd	s6,32(sp)
 2e0:	01713c23          	sd	s7,24(sp)
 2e4:	01813823          	sd	s8,16(sp)
 2e8:	06010413          	addi	s0,sp,96
 2ec:	00050b93          	mv	s7,a0
 2f0:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 2f4:	00050913          	mv	s2,a0
 2f8:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 2fc:	faf40b13          	addi	s6,s0,-81
 300:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 304:	00048c13          	mv	s8,s1
 308:	0014899b          	addiw	s3,s1,1
 30c:	00098493          	mv	s1,s3
 310:	0349dc63          	bge	s3,s4,348 <gets+0x8c>
    cc = read(0, &c, 1);
 314:	000a8613          	mv	a2,s5
 318:	000b0593          	mv	a1,s6
 31c:	00000513          	li	a0,0
 320:	2bc000ef          	jal	5dc <read>
    if(cc < 1)
 324:	02a05263          	blez	a0,348 <gets+0x8c>
      break;
    buf[i++] = c;
 328:	faf44783          	lbu	a5,-81(s0)
 32c:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 330:	00190913          	addi	s2,s2,1
 334:	ff678713          	addi	a4,a5,-10
 338:	00070663          	beqz	a4,344 <gets+0x88>
 33c:	ff378793          	addi	a5,a5,-13
 340:	fc0792e3          	bnez	a5,304 <gets+0x48>
    buf[i++] = c;
 344:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 348:	018b8c33          	add	s8,s7,s8
 34c:	000c0023          	sb	zero,0(s8)
  return buf;
}
 350:	000b8513          	mv	a0,s7
 354:	05813083          	ld	ra,88(sp)
 358:	05013403          	ld	s0,80(sp)
 35c:	04813483          	ld	s1,72(sp)
 360:	04013903          	ld	s2,64(sp)
 364:	03813983          	ld	s3,56(sp)
 368:	03013a03          	ld	s4,48(sp)
 36c:	02813a83          	ld	s5,40(sp)
 370:	02013b03          	ld	s6,32(sp)
 374:	01813b83          	ld	s7,24(sp)
 378:	01013c03          	ld	s8,16(sp)
 37c:	06010113          	addi	sp,sp,96
 380:	00008067          	ret

0000000000000384 <stat>:

int
stat(const char *n, struct stat *st)
{
 384:	fe010113          	addi	sp,sp,-32
 388:	00113c23          	sd	ra,24(sp)
 38c:	00813823          	sd	s0,16(sp)
 390:	01213023          	sd	s2,0(sp)
 394:	02010413          	addi	s0,sp,32
 398:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 39c:	00000593          	li	a1,0
 3a0:	278000ef          	jal	618 <open>
  if(fd < 0)
 3a4:	02054e63          	bltz	a0,3e0 <stat+0x5c>
 3a8:	00913423          	sd	s1,8(sp)
 3ac:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 3b0:	00090593          	mv	a1,s2
 3b4:	288000ef          	jal	63c <fstat>
 3b8:	00050913          	mv	s2,a0
  close(fd);
 3bc:	00048513          	mv	a0,s1
 3c0:	234000ef          	jal	5f4 <close>
  return r;
 3c4:	00813483          	ld	s1,8(sp)
}
 3c8:	00090513          	mv	a0,s2
 3cc:	01813083          	ld	ra,24(sp)
 3d0:	01013403          	ld	s0,16(sp)
 3d4:	00013903          	ld	s2,0(sp)
 3d8:	02010113          	addi	sp,sp,32
 3dc:	00008067          	ret
    return -1;
 3e0:	fff00793          	li	a5,-1
 3e4:	00078913          	mv	s2,a5
 3e8:	fe1ff06f          	j	3c8 <stat+0x44>

00000000000003ec <atoi>:

int
atoi(const char *s)
{
 3ec:	ff010113          	addi	sp,sp,-16
 3f0:	00113423          	sd	ra,8(sp)
 3f4:	00813023          	sd	s0,0(sp)
 3f8:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 3fc:	00054683          	lbu	a3,0(a0)
 400:	fd06879b          	addiw	a5,a3,-48
 404:	0ff7f793          	zext.b	a5,a5
 408:	00900613          	li	a2,9
 40c:	04f66263          	bltu	a2,a5,450 <atoi+0x64>
 410:	00050713          	mv	a4,a0
  n = 0;
 414:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 418:	00170713          	addi	a4,a4,1
 41c:	0025179b          	slliw	a5,a0,0x2
 420:	00a787bb          	addw	a5,a5,a0
 424:	0017979b          	slliw	a5,a5,0x1
 428:	00d787bb          	addw	a5,a5,a3
 42c:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 430:	00074683          	lbu	a3,0(a4)
 434:	fd06879b          	addiw	a5,a3,-48
 438:	0ff7f793          	zext.b	a5,a5
 43c:	fcf67ee3          	bgeu	a2,a5,418 <atoi+0x2c>
  return n;
}
 440:	00813083          	ld	ra,8(sp)
 444:	00013403          	ld	s0,0(sp)
 448:	01010113          	addi	sp,sp,16
 44c:	00008067          	ret
  n = 0;
 450:	00000513          	li	a0,0
 454:	fedff06f          	j	440 <atoi+0x54>

0000000000000458 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 458:	ff010113          	addi	sp,sp,-16
 45c:	00113423          	sd	ra,8(sp)
 460:	00813023          	sd	s0,0(sp)
 464:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 468:	02b57e63          	bgeu	a0,a1,4a4 <memmove+0x4c>
    while(n-- > 0)
 46c:	02c05463          	blez	a2,494 <memmove+0x3c>
 470:	02061613          	slli	a2,a2,0x20
 474:	02065613          	srli	a2,a2,0x20
 478:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 47c:	00050713          	mv	a4,a0
      *dst++ = *src++;
 480:	00158593          	addi	a1,a1,1
 484:	00170713          	addi	a4,a4,1
 488:	fff5c683          	lbu	a3,-1(a1)
 48c:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 490:	fee798e3          	bne	a5,a4,480 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 494:	00813083          	ld	ra,8(sp)
 498:	00013403          	ld	s0,0(sp)
 49c:	01010113          	addi	sp,sp,16
 4a0:	00008067          	ret
    while(n-- > 0)
 4a4:	fec058e3          	blez	a2,494 <memmove+0x3c>
    dst += n;
 4a8:	00c50733          	add	a4,a0,a2
    src += n;
 4ac:	00c585b3          	add	a1,a1,a2
 4b0:	fff6079b          	addiw	a5,a2,-1
 4b4:	02079793          	slli	a5,a5,0x20
 4b8:	0207d793          	srli	a5,a5,0x20
 4bc:	fff7c793          	not	a5,a5
 4c0:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 4c4:	fff58593          	addi	a1,a1,-1
 4c8:	fff70713          	addi	a4,a4,-1
 4cc:	0005c683          	lbu	a3,0(a1)
 4d0:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 4d4:	fef718e3          	bne	a4,a5,4c4 <memmove+0x6c>
 4d8:	fbdff06f          	j	494 <memmove+0x3c>

00000000000004dc <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 4dc:	ff010113          	addi	sp,sp,-16
 4e0:	00113423          	sd	ra,8(sp)
 4e4:	00813023          	sd	s0,0(sp)
 4e8:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 4ec:	04060263          	beqz	a2,530 <memcmp+0x54>
 4f0:	02061613          	slli	a2,a2,0x20
 4f4:	02065613          	srli	a2,a2,0x20
 4f8:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 4fc:	00054783          	lbu	a5,0(a0)
 500:	0005c703          	lbu	a4,0(a1)
 504:	00e79c63          	bne	a5,a4,51c <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 508:	00150513          	addi	a0,a0,1
    p2++;
 50c:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 510:	fed516e3          	bne	a0,a3,4fc <memcmp+0x20>
  }
  return 0;
 514:	00000513          	li	a0,0
 518:	0080006f          	j	520 <memcmp+0x44>
      return *p1 - *p2;
 51c:	40e7853b          	subw	a0,a5,a4
}
 520:	00813083          	ld	ra,8(sp)
 524:	00013403          	ld	s0,0(sp)
 528:	01010113          	addi	sp,sp,16
 52c:	00008067          	ret
  return 0;
 530:	00000513          	li	a0,0
 534:	fedff06f          	j	520 <memcmp+0x44>

0000000000000538 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 538:	ff010113          	addi	sp,sp,-16
 53c:	00113423          	sd	ra,8(sp)
 540:	00813023          	sd	s0,0(sp)
 544:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 548:	f11ff0ef          	jal	458 <memmove>
}
 54c:	00813083          	ld	ra,8(sp)
 550:	00013403          	ld	s0,0(sp)
 554:	01010113          	addi	sp,sp,16
 558:	00008067          	ret

000000000000055c <sbrk>:

char *
sbrk(int n) {
 55c:	ff010113          	addi	sp,sp,-16
 560:	00113423          	sd	ra,8(sp)
 564:	00813023          	sd	s0,0(sp)
 568:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 56c:	00100593          	li	a1,1
 570:	114000ef          	jal	684 <sys_sbrk>
}
 574:	00813083          	ld	ra,8(sp)
 578:	00013403          	ld	s0,0(sp)
 57c:	01010113          	addi	sp,sp,16
 580:	00008067          	ret

0000000000000584 <sbrklazy>:

char *
sbrklazy(int n) {
 584:	ff010113          	addi	sp,sp,-16
 588:	00113423          	sd	ra,8(sp)
 58c:	00813023          	sd	s0,0(sp)
 590:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 594:	00200593          	li	a1,2
 598:	0ec000ef          	jal	684 <sys_sbrk>
}
 59c:	00813083          	ld	ra,8(sp)
 5a0:	00013403          	ld	s0,0(sp)
 5a4:	01010113          	addi	sp,sp,16
 5a8:	00008067          	ret

00000000000005ac <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 5ac:	00100893          	li	a7,1
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <exit>:
.global exit
exit:
 li a7, SYS_exit
 5b8:	00200893          	li	a7,2
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <wait>:
.global wait
wait:
 li a7, SYS_wait
 5c4:	00300893          	li	a7,3
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 5d0:	00400893          	li	a7,4
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <read>:
.global read
read:
 li a7, SYS_read
 5dc:	00500893          	li	a7,5
 ecall
 5e0:	00000073          	ecall
 ret
 5e4:	00008067          	ret

00000000000005e8 <write>:
.global write
write:
 li a7, SYS_write
 5e8:	01000893          	li	a7,16
 ecall
 5ec:	00000073          	ecall
 ret
 5f0:	00008067          	ret

00000000000005f4 <close>:
.global close
close:
 li a7, SYS_close
 5f4:	01500893          	li	a7,21
 ecall
 5f8:	00000073          	ecall
 ret
 5fc:	00008067          	ret

0000000000000600 <kill>:
.global kill
kill:
 li a7, SYS_kill
 600:	00600893          	li	a7,6
 ecall
 604:	00000073          	ecall
 ret
 608:	00008067          	ret

000000000000060c <exec>:
.global exec
exec:
 li a7, SYS_exec
 60c:	00700893          	li	a7,7
 ecall
 610:	00000073          	ecall
 ret
 614:	00008067          	ret

0000000000000618 <open>:
.global open
open:
 li a7, SYS_open
 618:	00f00893          	li	a7,15
 ecall
 61c:	00000073          	ecall
 ret
 620:	00008067          	ret

0000000000000624 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 624:	01100893          	li	a7,17
 ecall
 628:	00000073          	ecall
 ret
 62c:	00008067          	ret

0000000000000630 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 630:	01200893          	li	a7,18
 ecall
 634:	00000073          	ecall
 ret
 638:	00008067          	ret

000000000000063c <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 63c:	00800893          	li	a7,8
 ecall
 640:	00000073          	ecall
 ret
 644:	00008067          	ret

0000000000000648 <link>:
.global link
link:
 li a7, SYS_link
 648:	01300893          	li	a7,19
 ecall
 64c:	00000073          	ecall
 ret
 650:	00008067          	ret

0000000000000654 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 654:	01400893          	li	a7,20
 ecall
 658:	00000073          	ecall
 ret
 65c:	00008067          	ret

0000000000000660 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 660:	00900893          	li	a7,9
 ecall
 664:	00000073          	ecall
 ret
 668:	00008067          	ret

000000000000066c <dup>:
.global dup
dup:
 li a7, SYS_dup
 66c:	00a00893          	li	a7,10
 ecall
 670:	00000073          	ecall
 ret
 674:	00008067          	ret

0000000000000678 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 678:	00b00893          	li	a7,11
 ecall
 67c:	00000073          	ecall
 ret
 680:	00008067          	ret

0000000000000684 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 684:	00c00893          	li	a7,12
 ecall
 688:	00000073          	ecall
 ret
 68c:	00008067          	ret

0000000000000690 <pause>:
.global pause
pause:
 li a7, SYS_pause
 690:	00d00893          	li	a7,13
 ecall
 694:	00000073          	ecall
 ret
 698:	00008067          	ret

000000000000069c <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 69c:	00e00893          	li	a7,14
 ecall
 6a0:	00000073          	ecall
 ret
 6a4:	00008067          	ret

00000000000006a8 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 6a8:	00001617          	auipc	a2,0x1
 6ac:	96862603          	lw	a2,-1688(a2) # 1010 <putc_n>
 6b0:	00c04463          	bgtz	a2,6b8 <putc_flush+0x10>
 6b4:	00008067          	ret
{
 6b8:	ff010113          	addi	sp,sp,-16
 6bc:	00113423          	sd	ra,8(sp)
 6c0:	00813023          	sd	s0,0(sp)
 6c4:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 6c8:	00001597          	auipc	a1,0x1
 6cc:	b5058593          	addi	a1,a1,-1200 # 1218 <putc_buf>
 6d0:	00001517          	auipc	a0,0x1
 6d4:	93052503          	lw	a0,-1744(a0) # 1000 <putc_fd>
 6d8:	f11ff0ef          	jal	5e8 <write>
    putc_n = 0;
 6dc:	00001797          	auipc	a5,0x1
 6e0:	9207aa23          	sw	zero,-1740(a5) # 1010 <putc_n>
  }
}
 6e4:	00813083          	ld	ra,8(sp)
 6e8:	00013403          	ld	s0,0(sp)
 6ec:	01010113          	addi	sp,sp,16
 6f0:	00008067          	ret

00000000000006f4 <putc>:

static void
putc(int fd, char c)
{
 6f4:	fe010113          	addi	sp,sp,-32
 6f8:	00113c23          	sd	ra,24(sp)
 6fc:	00813823          	sd	s0,16(sp)
 700:	00913423          	sd	s1,8(sp)
 704:	02010413          	addi	s0,sp,32
 708:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 70c:	00001797          	auipc	a5,0x1
 710:	8f47a783          	lw	a5,-1804(a5) # 1000 <putc_fd>
 714:	04a79663          	bne	a5,a0,760 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 718:	00001717          	auipc	a4,0x1
 71c:	8f870713          	addi	a4,a4,-1800 # 1010 <putc_n>
 720:	00072683          	lw	a3,0(a4)
 724:	0016879b          	addiw	a5,a3,1
 728:	00f72023          	sw	a5,0(a4)
 72c:	00001717          	auipc	a4,0x1
 730:	aec70713          	addi	a4,a4,-1300 # 1218 <putc_buf>
 734:	00d70733          	add	a4,a4,a3
 738:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 73c:	ff648493          	addi	s1,s1,-10
 740:	02048e63          	beqz	s1,77c <putc+0x88>
 744:	f8078793          	addi	a5,a5,-128
 748:	02078a63          	beqz	a5,77c <putc+0x88>
    putc_flush();
}
 74c:	01813083          	ld	ra,24(sp)
 750:	01013403          	ld	s0,16(sp)
 754:	00813483          	ld	s1,8(sp)
 758:	02010113          	addi	sp,sp,32
 75c:	00008067          	ret
 760:	01213023          	sd	s2,0(sp)
 764:	00050913          	mv	s2,a0
    putc_flush();
 768:	f41ff0ef          	jal	6a8 <putc_flush>
    putc_fd = fd;
 76c:	00001797          	auipc	a5,0x1
 770:	8927aa23          	sw	s2,-1900(a5) # 1000 <putc_fd>
 774:	00013903          	ld	s2,0(sp)
 778:	fa1ff06f          	j	718 <putc+0x24>
    putc_flush();
 77c:	f2dff0ef          	jal	6a8 <putc_flush>
}
 780:	fcdff06f          	j	74c <putc+0x58>

0000000000000784 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 784:	fb010113          	addi	sp,sp,-80
 788:	04113423          	sd	ra,72(sp)
 78c:	04813023          	sd	s0,64(sp)
 790:	03213823          	sd	s2,48(sp)
 794:	03313423          	sd	s3,40(sp)
 798:	05010413          	addi	s0,sp,80
 79c:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 7a0:	0a068e63          	beqz	a3,85c <printint+0xd8>
 7a4:	0a05dc63          	bgez	a1,85c <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 7a8:	40b005b3          	neg	a1,a1
    neg = 1;
 7ac:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 7b0:	fb840993          	addi	s3,s0,-72
  neg = 0;
 7b4:	00098693          	mv	a3,s3
  i = 0;
 7b8:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 7bc:	00000817          	auipc	a6,0x0
 7c0:	7a480813          	addi	a6,a6,1956 # f60 <digits>
 7c4:	00070893          	mv	a7,a4
 7c8:	0017051b          	addiw	a0,a4,1
 7cc:	00050713          	mv	a4,a0
 7d0:	02c5f7b3          	remu	a5,a1,a2
 7d4:	00f807b3          	add	a5,a6,a5
 7d8:	0007c783          	lbu	a5,0(a5)
 7dc:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 7e0:	00058793          	mv	a5,a1
 7e4:	02c5d5b3          	divu	a1,a1,a2
 7e8:	00168693          	addi	a3,a3,1
 7ec:	fcc7fce3          	bgeu	a5,a2,7c4 <printint+0x40>
  if (neg)
 7f0:	00030c63          	beqz	t1,808 <printint+0x84>
    buf[i++] = '-';
 7f4:	fd050793          	addi	a5,a0,-48
 7f8:	00878533          	add	a0,a5,s0
 7fc:	02d00793          	li	a5,45
 800:	fef50423          	sb	a5,-24(a0)
 804:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 808:	02e05e63          	blez	a4,844 <printint+0xc0>
 80c:	02913c23          	sd	s1,56(sp)
 810:	fff7071b          	addiw	a4,a4,-1
 814:	00e984b3          	add	s1,s3,a4
 818:	fff98993          	addi	s3,s3,-1
 81c:	00e989b3          	add	s3,s3,a4
 820:	02071713          	slli	a4,a4,0x20
 824:	02075713          	srli	a4,a4,0x20
 828:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 82c:	0004c583          	lbu	a1,0(s1)
 830:	00090513          	mv	a0,s2
 834:	ec1ff0ef          	jal	6f4 <putc>
  while (--i >= 0)
 838:	fff48493          	addi	s1,s1,-1
 83c:	ff3498e3          	bne	s1,s3,82c <printint+0xa8>
 840:	03813483          	ld	s1,56(sp)
}
 844:	04813083          	ld	ra,72(sp)
 848:	04013403          	ld	s0,64(sp)
 84c:	03013903          	ld	s2,48(sp)
 850:	02813983          	ld	s3,40(sp)
 854:	05010113          	addi	sp,sp,80
 858:	00008067          	ret
  neg = 0;
 85c:	00000313          	li	t1,0
 860:	f51ff06f          	j	7b0 <printint+0x2c>

0000000000000864 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 864:	fa010113          	addi	sp,sp,-96
 868:	04113c23          	sd	ra,88(sp)
 86c:	04813823          	sd	s0,80(sp)
 870:	04913423          	sd	s1,72(sp)
 874:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 878:	0005c483          	lbu	s1,0(a1)
 87c:	32048263          	beqz	s1,ba0 <vprintf+0x33c>
 880:	05213023          	sd	s2,64(sp)
 884:	03313c23          	sd	s3,56(sp)
 888:	03413823          	sd	s4,48(sp)
 88c:	03513423          	sd	s5,40(sp)
 890:	03613023          	sd	s6,32(sp)
 894:	01713c23          	sd	s7,24(sp)
 898:	01813823          	sd	s8,16(sp)
 89c:	00050b13          	mv	s6,a0
 8a0:	00058a13          	mv	s4,a1
 8a4:	00060b93          	mv	s7,a2
  state = 0;
 8a8:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 8ac:	00000913          	li	s2,0
 8b0:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 8b4:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 8b8:	06400c13          	li	s8,100
 8bc:	0300006f          	j	8ec <vprintf+0x88>
        putc(fd, c0);
 8c0:	00048593          	mv	a1,s1
 8c4:	000b0513          	mv	a0,s6
 8c8:	e2dff0ef          	jal	6f4 <putc>
 8cc:	0080006f          	j	8d4 <vprintf+0x70>
    else if (state == '%')
 8d0:	03598863          	beq	s3,s5,900 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 8d4:	0019079b          	addiw	a5,s2,1
 8d8:	00078913          	mv	s2,a5
 8dc:	00078713          	mv	a4,a5
 8e0:	00fa07b3          	add	a5,s4,a5
 8e4:	0007c483          	lbu	s1,0(a5)
 8e8:	28048e63          	beqz	s1,b84 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 8ec:	0004879b          	sext.w	a5,s1
    if (state == 0)
 8f0:	fe0990e3          	bnez	s3,8d0 <vprintf+0x6c>
      if (c0 == '%')
 8f4:	fd5796e3          	bne	a5,s5,8c0 <vprintf+0x5c>
        state = '%';
 8f8:	00078993          	mv	s3,a5
 8fc:	fd9ff06f          	j	8d4 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 900:	00ea06b3          	add	a3,s4,a4
 904:	0016c603          	lbu	a2,1(a3)
      if (c1)
 908:	2a060663          	beqz	a2,bb4 <vprintf+0x350>
      if (c0 == 'd')
 90c:	05878063          	beq	a5,s8,94c <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 910:	f9478693          	addi	a3,a5,-108
 914:	0016b693          	seqz	a3,a3
 918:	f9c60593          	addi	a1,a2,-100
 91c:	04059a63          	bnez	a1,970 <vprintf+0x10c>
 920:	04068863          	beqz	a3,970 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 924:	008b8493          	addi	s1,s7,8
 928:	00100693          	li	a3,1
 92c:	00a00613          	li	a2,10
 930:	000bb583          	ld	a1,0(s7)
 934:	000b0513          	mv	a0,s6
 938:	e4dff0ef          	jal	784 <printint>
        i += 1;
 93c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 940:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 944:	00000993          	li	s3,0
 948:	f8dff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 94c:	008b8493          	addi	s1,s7,8
 950:	00100693          	li	a3,1
 954:	00a00613          	li	a2,10
 958:	000ba583          	lw	a1,0(s7)
 95c:	000b0513          	mv	a0,s6
 960:	e25ff0ef          	jal	784 <printint>
 964:	00048b93          	mv	s7,s1
      state = 0;
 968:	00000993          	li	s3,0
 96c:	f69ff06f          	j	8d4 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 970:	00ea0733          	add	a4,s4,a4
 974:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 978:	f9460713          	addi	a4,a2,-108
 97c:	00173713          	seqz	a4,a4
 980:	00e6f733          	and	a4,a3,a4
 984:	f9c58513          	addi	a0,a1,-100
 988:	24051263          	bnez	a0,bcc <vprintf+0x368>
 98c:	24070063          	beqz	a4,bcc <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 990:	008b8493          	addi	s1,s7,8
 994:	00100693          	li	a3,1
 998:	00a00613          	li	a2,10
 99c:	000bb583          	ld	a1,0(s7)
 9a0:	000b0513          	mv	a0,s6
 9a4:	de1ff0ef          	jal	784 <printint>
        i += 2;
 9a8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 9ac:	00048b93          	mv	s7,s1
      state = 0;
 9b0:	00000993          	li	s3,0
        i += 2;
 9b4:	f21ff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 9b8:	008b8493          	addi	s1,s7,8
 9bc:	00000693          	li	a3,0
 9c0:	00a00613          	li	a2,10
 9c4:	000be583          	lwu	a1,0(s7)
 9c8:	000b0513          	mv	a0,s6
 9cc:	db9ff0ef          	jal	784 <printint>
 9d0:	00048b93          	mv	s7,s1
      state = 0;
 9d4:	00000993          	li	s3,0
 9d8:	efdff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 9dc:	008b8493          	addi	s1,s7,8
 9e0:	00000693          	li	a3,0
 9e4:	00a00613          	li	a2,10
 9e8:	000bb583          	ld	a1,0(s7)
 9ec:	000b0513          	mv	a0,s6
 9f0:	d95ff0ef          	jal	784 <printint>
        i += 1;
 9f4:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 9f8:	00048b93          	mv	s7,s1
      state = 0;
 9fc:	00000993          	li	s3,0
 a00:	ed5ff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 a04:	008b8493          	addi	s1,s7,8
 a08:	00000693          	li	a3,0
 a0c:	00a00613          	li	a2,10
 a10:	000bb583          	ld	a1,0(s7)
 a14:	000b0513          	mv	a0,s6
 a18:	d6dff0ef          	jal	784 <printint>
        i += 2;
 a1c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 a20:	00048b93          	mv	s7,s1
      state = 0;
 a24:	00000993          	li	s3,0
        i += 2;
 a28:	eadff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 a2c:	008b8493          	addi	s1,s7,8
 a30:	00000693          	li	a3,0
 a34:	01000613          	li	a2,16
 a38:	000be583          	lwu	a1,0(s7)
 a3c:	000b0513          	mv	a0,s6
 a40:	d45ff0ef          	jal	784 <printint>
 a44:	00048b93          	mv	s7,s1
      state = 0;
 a48:	00000993          	li	s3,0
 a4c:	e89ff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a50:	008b8493          	addi	s1,s7,8
 a54:	00000693          	li	a3,0
 a58:	01000613          	li	a2,16
 a5c:	000bb583          	ld	a1,0(s7)
 a60:	000b0513          	mv	a0,s6
 a64:	d21ff0ef          	jal	784 <printint>
        i += 1;
 a68:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 a6c:	00048b93          	mv	s7,s1
      state = 0;
 a70:	00000993          	li	s3,0
 a74:	e61ff06f          	j	8d4 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a78:	008b8493          	addi	s1,s7,8
 a7c:	00000693          	li	a3,0
 a80:	01000613          	li	a2,16
 a84:	000bb583          	ld	a1,0(s7)
 a88:	000b0513          	mv	a0,s6
 a8c:	cf9ff0ef          	jal	784 <printint>
        i += 2;
 a90:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 a94:	00048b93          	mv	s7,s1
      state = 0;
 a98:	00000993          	li	s3,0
        i += 2;
 a9c:	e39ff06f          	j	8d4 <vprintf+0x70>
 aa0:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 aa4:	008b8793          	addi	a5,s7,8
 aa8:	00078c93          	mv	s9,a5
 aac:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 ab0:	03000593          	li	a1,48
 ab4:	000b0513          	mv	a0,s6
 ab8:	c3dff0ef          	jal	6f4 <putc>
  putc(fd, 'x');
 abc:	07800593          	li	a1,120
 ac0:	000b0513          	mv	a0,s6
 ac4:	c31ff0ef          	jal	6f4 <putc>
 ac8:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 acc:	00000b97          	auipc	s7,0x0
 ad0:	494b8b93          	addi	s7,s7,1172 # f60 <digits>
 ad4:	03c9d793          	srli	a5,s3,0x3c
 ad8:	00fb87b3          	add	a5,s7,a5
 adc:	0007c583          	lbu	a1,0(a5)
 ae0:	000b0513          	mv	a0,s6
 ae4:	c11ff0ef          	jal	6f4 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 ae8:	00499993          	slli	s3,s3,0x4
 aec:	fff4849b          	addiw	s1,s1,-1
 af0:	fe0492e3          	bnez	s1,ad4 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 af4:	000c8b93          	mv	s7,s9
      state = 0;
 af8:	00000993          	li	s3,0
 afc:	00813c83          	ld	s9,8(sp)
 b00:	dd5ff06f          	j	8d4 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 b04:	008b8493          	addi	s1,s7,8
 b08:	000bc583          	lbu	a1,0(s7)
 b0c:	000b0513          	mv	a0,s6
 b10:	be5ff0ef          	jal	6f4 <putc>
 b14:	00048b93          	mv	s7,s1
      state = 0;
 b18:	00000993          	li	s3,0
 b1c:	db9ff06f          	j	8d4 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b20:	008b8993          	addi	s3,s7,8
 b24:	000bb483          	ld	s1,0(s7)
 b28:	02048663          	beqz	s1,b54 <vprintf+0x2f0>
        for (; *s; s++)
 b2c:	0004c583          	lbu	a1,0(s1)
 b30:	04058463          	beqz	a1,b78 <vprintf+0x314>
          putc(fd, *s);
 b34:	000b0513          	mv	a0,s6
 b38:	bbdff0ef          	jal	6f4 <putc>
        for (; *s; s++)
 b3c:	00148493          	addi	s1,s1,1
 b40:	0004c583          	lbu	a1,0(s1)
 b44:	fe0598e3          	bnez	a1,b34 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 b48:	00098b93          	mv	s7,s3
      state = 0;
 b4c:	00000993          	li	s3,0
 b50:	d85ff06f          	j	8d4 <vprintf+0x70>
          s = "(null)";
 b54:	00000497          	auipc	s1,0x0
 b58:	40448493          	addi	s1,s1,1028 # f58 <malloc+0x1bc>
        for (; *s; s++)
 b5c:	02800593          	li	a1,40
 b60:	fd5ff06f          	j	b34 <vprintf+0x2d0>
        putc(fd, '%');
 b64:	00078593          	mv	a1,a5
 b68:	000b0513          	mv	a0,s6
 b6c:	b89ff0ef          	jal	6f4 <putc>
      state = 0;
 b70:	00000993          	li	s3,0
 b74:	d61ff06f          	j	8d4 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b78:	00098b93          	mv	s7,s3
      state = 0;
 b7c:	00000993          	li	s3,0
 b80:	d55ff06f          	j	8d4 <vprintf+0x70>
 b84:	04013903          	ld	s2,64(sp)
 b88:	03813983          	ld	s3,56(sp)
 b8c:	03013a03          	ld	s4,48(sp)
 b90:	02813a83          	ld	s5,40(sp)
 b94:	02013b03          	ld	s6,32(sp)
 b98:	01813b83          	ld	s7,24(sp)
 b9c:	01013c03          	ld	s8,16(sp)
    }
  }
}
 ba0:	05813083          	ld	ra,88(sp)
 ba4:	05013403          	ld	s0,80(sp)
 ba8:	04813483          	ld	s1,72(sp)
 bac:	06010113          	addi	sp,sp,96
 bb0:	00008067          	ret
      if (c0 == 'd')
 bb4:	06400713          	li	a4,100
 bb8:	d8e78ae3          	beq	a5,a4,94c <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 bbc:	f9478693          	addi	a3,a5,-108
 bc0:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 bc4:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 bc8:	00000713          	li	a4,0
      else if (c0 == 'u')
 bcc:	07500513          	li	a0,117
 bd0:	dea784e3          	beq	a5,a0,9b8 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 bd4:	f8b60513          	addi	a0,a2,-117
 bd8:	00051463          	bnez	a0,be0 <vprintf+0x37c>
 bdc:	e00690e3          	bnez	a3,9dc <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 be0:	f8b58513          	addi	a0,a1,-117
 be4:	00051463          	bnez	a0,bec <vprintf+0x388>
 be8:	e0071ee3          	bnez	a4,a04 <vprintf+0x1a0>
      else if (c0 == 'x')
 bec:	07800513          	li	a0,120
 bf0:	e2a78ee3          	beq	a5,a0,a2c <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 bf4:	f8860613          	addi	a2,a2,-120
 bf8:	00061463          	bnez	a2,c00 <vprintf+0x39c>
 bfc:	e4069ae3          	bnez	a3,a50 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 c00:	f8858593          	addi	a1,a1,-120
 c04:	00059463          	bnez	a1,c0c <vprintf+0x3a8>
 c08:	e60718e3          	bnez	a4,a78 <vprintf+0x214>
      else if (c0 == 'p')
 c0c:	07000713          	li	a4,112
 c10:	e8e788e3          	beq	a5,a4,aa0 <vprintf+0x23c>
      else if (c0 == 'c')
 c14:	06300713          	li	a4,99
 c18:	eee786e3          	beq	a5,a4,b04 <vprintf+0x2a0>
      else if (c0 == 's')
 c1c:	07300713          	li	a4,115
 c20:	f0e780e3          	beq	a5,a4,b20 <vprintf+0x2bc>
      else if (c0 == '%')
 c24:	02500713          	li	a4,37
 c28:	f2e78ee3          	beq	a5,a4,b64 <vprintf+0x300>
        putc(fd, '%');
 c2c:	02500593          	li	a1,37
 c30:	000b0513          	mv	a0,s6
 c34:	ac1ff0ef          	jal	6f4 <putc>
        putc(fd, c0);
 c38:	00048593          	mv	a1,s1
 c3c:	000b0513          	mv	a0,s6
 c40:	ab5ff0ef          	jal	6f4 <putc>
      state = 0;
 c44:	00000993          	li	s3,0
 c48:	c8dff06f          	j	8d4 <vprintf+0x70>

0000000000000c4c <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 c4c:	fb010113          	addi	sp,sp,-80
 c50:	00113c23          	sd	ra,24(sp)
 c54:	00813823          	sd	s0,16(sp)
 c58:	02010413          	addi	s0,sp,32
 c5c:	00c43023          	sd	a2,0(s0)
 c60:	00d43423          	sd	a3,8(s0)
 c64:	00e43823          	sd	a4,16(s0)
 c68:	00f43c23          	sd	a5,24(s0)
 c6c:	03043023          	sd	a6,32(s0)
 c70:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 c74:	00040613          	mv	a2,s0
 c78:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 c7c:	be9ff0ef          	jal	864 <vprintf>
}
 c80:	01813083          	ld	ra,24(sp)
 c84:	01013403          	ld	s0,16(sp)
 c88:	05010113          	addi	sp,sp,80
 c8c:	00008067          	ret

0000000000000c90 <printf>:

void printf(const char *fmt, ...)
{
 c90:	fa010113          	addi	sp,sp,-96
 c94:	00113c23          	sd	ra,24(sp)
 c98:	00813823          	sd	s0,16(sp)
 c9c:	02010413          	addi	s0,sp,32
 ca0:	00b43423          	sd	a1,8(s0)
 ca4:	00c43823          	sd	a2,16(s0)
 ca8:	00d43c23          	sd	a3,24(s0)
 cac:	02e43023          	sd	a4,32(s0)
 cb0:	02f43423          	sd	a5,40(s0)
 cb4:	03043823          	sd	a6,48(s0)
 cb8:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 cbc:	00840613          	addi	a2,s0,8
 cc0:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 cc4:	00050593          	mv	a1,a0
 cc8:	00100513          	li	a0,1
 ccc:	b99ff0ef          	jal	864 <vprintf>
  putc_flush();
 cd0:	9d9ff0ef          	jal	6a8 <putc_flush>
}
 cd4:	01813083          	ld	ra,24(sp)
 cd8:	01013403          	ld	s0,16(sp)
 cdc:	06010113          	addi	sp,sp,96
 ce0:	00008067          	ret

0000000000000ce4 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 ce4:	ff010113          	addi	sp,sp,-16
 ce8:	00113423          	sd	ra,8(sp)
 cec:	00813023          	sd	s0,0(sp)
 cf0:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 cf4:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 cf8:	00000797          	auipc	a5,0x0
 cfc:	3207b783          	ld	a5,800(a5) # 1018 <freep>
 d00:	0140006f          	j	d14 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 d04:	0007b703          	ld	a4,0(a5)
 d08:	00e7e463          	bltu	a5,a4,d10 <free+0x2c>
 d0c:	00e6ec63          	bltu	a3,a4,d24 <free+0x40>
{
 d10:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 d14:	fed7f8e3          	bgeu	a5,a3,d04 <free+0x20>
 d18:	0007b703          	ld	a4,0(a5)
 d1c:	00e6e463          	bltu	a3,a4,d24 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 d20:	fee7e8e3          	bltu	a5,a4,d10 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 d24:	ff852583          	lw	a1,-8(a0)
 d28:	0007b603          	ld	a2,0(a5)
 d2c:	02059813          	slli	a6,a1,0x20
 d30:	01c85713          	srli	a4,a6,0x1c
 d34:	00e68733          	add	a4,a3,a4
 d38:	02e60c63          	beq	a2,a4,d70 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 d3c:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 d40:	0087a603          	lw	a2,8(a5)
 d44:	02061593          	slli	a1,a2,0x20
 d48:	01c5d713          	srli	a4,a1,0x1c
 d4c:	00e78733          	add	a4,a5,a4
 d50:	02e68c63          	beq	a3,a4,d88 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 d54:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 d58:	00000717          	auipc	a4,0x0
 d5c:	2cf73023          	sd	a5,704(a4) # 1018 <freep>
}
 d60:	00813083          	ld	ra,8(sp)
 d64:	00013403          	ld	s0,0(sp)
 d68:	01010113          	addi	sp,sp,16
 d6c:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 d70:	00862703          	lw	a4,8(a2)
 d74:	00b7073b          	addw	a4,a4,a1
 d78:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 d7c:	0007b703          	ld	a4,0(a5)
 d80:	00073603          	ld	a2,0(a4)
 d84:	fb9ff06f          	j	d3c <free+0x58>
    p->s.size += bp->s.size;
 d88:	ff852703          	lw	a4,-8(a0)
 d8c:	00c7073b          	addw	a4,a4,a2
 d90:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 d94:	ff053683          	ld	a3,-16(a0)
 d98:	fbdff06f          	j	d54 <free+0x70>

0000000000000d9c <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 d9c:	fc010113          	addi	sp,sp,-64
 da0:	02113c23          	sd	ra,56(sp)
 da4:	02813823          	sd	s0,48(sp)
 da8:	03213023          	sd	s2,32(sp)
 dac:	01313c23          	sd	s3,24(sp)
 db0:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 db4:	02051993          	slli	s3,a0,0x20
 db8:	0209d993          	srli	s3,s3,0x20
 dbc:	00f98993          	addi	s3,s3,15
 dc0:	0049d993          	srli	s3,s3,0x4
 dc4:	0019899b          	addiw	s3,s3,1
 dc8:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 dcc:	00000517          	auipc	a0,0x0
 dd0:	24c53503          	ld	a0,588(a0) # 1018 <freep>
 dd4:	04050463          	beqz	a0,e1c <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 dd8:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 ddc:	0087a703          	lw	a4,8(a5)
 de0:	0d377a63          	bgeu	a4,s3,eb4 <malloc+0x118>
 de4:	02913423          	sd	s1,40(sp)
 de8:	01413823          	sd	s4,16(sp)
 dec:	01513423          	sd	s5,8(sp)
 df0:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 df4:	00098a13          	mv	s4,s3
 df8:	00001737          	lui	a4,0x1
 dfc:	00e9f463          	bgeu	s3,a4,e04 <malloc+0x68>
 e00:	00001a37          	lui	s4,0x1
 e04:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 e08:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 e0c:	00000497          	auipc	s1,0x0
 e10:	20c48493          	addi	s1,s1,524 # 1018 <freep>
  if(p == SBRK_ERROR)
 e14:	fff00a93          	li	s5,-1
 e18:	05c0006f          	j	e74 <malloc+0xd8>
 e1c:	02913423          	sd	s1,40(sp)
 e20:	01413823          	sd	s4,16(sp)
 e24:	01513423          	sd	s5,8(sp)
 e28:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 e2c:	00000797          	auipc	a5,0x0
 e30:	46c78793          	addi	a5,a5,1132 # 1298 <base>
 e34:	00000717          	auipc	a4,0x0
 e38:	1ef73223          	sd	a5,484(a4) # 1018 <freep>
 e3c:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 e40:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 e44:	fb1ff06f          	j	df4 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 e48:	0007b703          	ld	a4,0(a5)
 e4c:	00e53023          	sd	a4,0(a0)
 e50:	0800006f          	j	ed0 <malloc+0x134>
  hp->s.size = nu;
 e54:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 e58:	01050513          	addi	a0,a0,16
 e5c:	e89ff0ef          	jal	ce4 <free>
  return freep;
 e60:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 e64:	08050863          	beqz	a0,ef4 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 e68:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 e6c:	0087a703          	lw	a4,8(a5)
 e70:	03277a63          	bgeu	a4,s2,ea4 <malloc+0x108>
    if(p == freep)
 e74:	0004b703          	ld	a4,0(s1)
 e78:	00078513          	mv	a0,a5
 e7c:	fef716e3          	bne	a4,a5,e68 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 e80:	000a0513          	mv	a0,s4
 e84:	ed8ff0ef          	jal	55c <sbrk>
  if(p == SBRK_ERROR)
 e88:	fd5516e3          	bne	a0,s5,e54 <malloc+0xb8>
        return 0;
 e8c:	00000513          	li	a0,0
 e90:	02813483          	ld	s1,40(sp)
 e94:	01013a03          	ld	s4,16(sp)
 e98:	00813a83          	ld	s5,8(sp)
 e9c:	00013b03          	ld	s6,0(sp)
 ea0:	03c0006f          	j	edc <malloc+0x140>
 ea4:	02813483          	ld	s1,40(sp)
 ea8:	01013a03          	ld	s4,16(sp)
 eac:	00813a83          	ld	s5,8(sp)
 eb0:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 eb4:	f8e90ae3          	beq	s2,a4,e48 <malloc+0xac>
        p->s.size -= nunits;
 eb8:	4137073b          	subw	a4,a4,s3
 ebc:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 ec0:	02071693          	slli	a3,a4,0x20
 ec4:	01c6d713          	srli	a4,a3,0x1c
 ec8:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 ecc:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 ed0:	00000717          	auipc	a4,0x0
 ed4:	14a73423          	sd	a0,328(a4) # 1018 <freep>
      return (void*)(p + 1);
 ed8:	01078513          	addi	a0,a5,16
  }
}
 edc:	03813083          	ld	ra,56(sp)
 ee0:	03013403          	ld	s0,48(sp)
 ee4:	02013903          	ld	s2,32(sp)
 ee8:	01813983          	ld	s3,24(sp)
 eec:	04010113          	addi	sp,sp,64
 ef0:	00008067          	ret
 ef4:	02813483          	ld	s1,40(sp)
 ef8:	01013a03          	ld	s4,16(sp)
 efc:	00813a83          	ld	s5,8(sp)
 f00:	00013b03          	ld	s6,0(sp)
 f04:	fd9ff06f          	j	edc <malloc+0x140>
