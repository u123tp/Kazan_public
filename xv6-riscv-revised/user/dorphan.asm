
user/_dorphan:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:

char buf[BUFSZ];

int
main(int argc, char **argv)
{
   0:	fe010113          	addi	sp,sp,-32
   4:	00113c23          	sd	ra,24(sp)
   8:	00813823          	sd	s0,16(sp)
   c:	00913423          	sd	s1,8(sp)
  10:	02010413          	addi	s0,sp,32
  char *s = argv[0];
  14:	0005b483          	ld	s1,0(a1)

  if(mkdir("dd") != 0){
  18:	00001517          	auipc	a0,0x1
  1c:	e4850513          	addi	a0,a0,-440 # e60 <malloc+0x170>
  20:	588000ef          	jal	5a8 <mkdir>
  24:	00050e63          	beqz	a0,40 <main+0x40>
    printf("%s: mkdir dd failed\n", s);
  28:	00048593          	mv	a1,s1
  2c:	00001517          	auipc	a0,0x1
  30:	e3c50513          	addi	a0,a0,-452 # e68 <malloc+0x178>
  34:	3b1000ef          	jal	be4 <printf>
    exit(1);
  38:	00100513          	li	a0,1
  3c:	4d0000ef          	jal	50c <exit>
  }

  if(chdir("dd") != 0){
  40:	00001517          	auipc	a0,0x1
  44:	e2050513          	addi	a0,a0,-480 # e60 <malloc+0x170>
  48:	56c000ef          	jal	5b4 <chdir>
  4c:	00050e63          	beqz	a0,68 <main+0x68>
    printf("%s: chdir dd failed\n", s);
  50:	00048593          	mv	a1,s1
  54:	00001517          	auipc	a0,0x1
  58:	e2c50513          	addi	a0,a0,-468 # e80 <malloc+0x190>
  5c:	389000ef          	jal	be4 <printf>
    exit(1);
  60:	00100513          	li	a0,1
  64:	4a8000ef          	jal	50c <exit>
  }

  if (unlink("../dd") < 0) {
  68:	00001517          	auipc	a0,0x1
  6c:	e3050513          	addi	a0,a0,-464 # e98 <malloc+0x1a8>
  70:	514000ef          	jal	584 <unlink>
  74:	02054063          	bltz	a0,94 <main+0x94>
    printf("%s: unlink failed\n", s);
    exit(1);
  }
  printf("wait for kill and reclaim\n");
  78:	00001517          	auipc	a0,0x1
  7c:	e4050513          	addi	a0,a0,-448 # eb8 <malloc+0x1c8>
  80:	365000ef          	jal	be4 <printf>
  // sit around until killed
  for(;;) pause(1000);
  84:	3e800493          	li	s1,1000
  88:	00048513          	mv	a0,s1
  8c:	558000ef          	jal	5e4 <pause>
  90:	ff9ff06f          	j	88 <main+0x88>
    printf("%s: unlink failed\n", s);
  94:	00048593          	mv	a1,s1
  98:	00001517          	auipc	a0,0x1
  9c:	e0850513          	addi	a0,a0,-504 # ea0 <malloc+0x1b0>
  a0:	345000ef          	jal	be4 <printf>
    exit(1);
  a4:	00100513          	li	a0,1
  a8:	464000ef          	jal	50c <exit>

00000000000000ac <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  ac:	ff010113          	addi	sp,sp,-16
  b0:	00113423          	sd	ra,8(sp)
  b4:	00813023          	sd	s0,0(sp)
  b8:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  bc:	f45ff0ef          	jal	0 <main>
  exit(r);
  c0:	44c000ef          	jal	50c <exit>

00000000000000c4 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  c4:	ff010113          	addi	sp,sp,-16
  c8:	00113423          	sd	ra,8(sp)
  cc:	00813023          	sd	s0,0(sp)
  d0:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  d4:	00050793          	mv	a5,a0
  d8:	00158593          	addi	a1,a1,1
  dc:	00178793          	addi	a5,a5,1
  e0:	fff5c703          	lbu	a4,-1(a1)
  e4:	fee78fa3          	sb	a4,-1(a5)
  e8:	fe0718e3          	bnez	a4,d8 <strcpy+0x14>
    ;
  return os;
}
  ec:	00813083          	ld	ra,8(sp)
  f0:	00013403          	ld	s0,0(sp)
  f4:	01010113          	addi	sp,sp,16
  f8:	00008067          	ret

00000000000000fc <strcmp>:

int
strcmp(const char *p, const char *q)
{
  fc:	ff010113          	addi	sp,sp,-16
 100:	00113423          	sd	ra,8(sp)
 104:	00813023          	sd	s0,0(sp)
 108:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 10c:	00054783          	lbu	a5,0(a0)
 110:	00078e63          	beqz	a5,12c <strcmp+0x30>
 114:	0005c703          	lbu	a4,0(a1)
 118:	00f71a63          	bne	a4,a5,12c <strcmp+0x30>
    p++, q++;
 11c:	00150513          	addi	a0,a0,1
 120:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 124:	00054783          	lbu	a5,0(a0)
 128:	fe0796e3          	bnez	a5,114 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 12c:	0005c503          	lbu	a0,0(a1)
}
 130:	40a7853b          	subw	a0,a5,a0
 134:	00813083          	ld	ra,8(sp)
 138:	00013403          	ld	s0,0(sp)
 13c:	01010113          	addi	sp,sp,16
 140:	00008067          	ret

0000000000000144 <strlen>:

uint
strlen(const char *s)
{
 144:	ff010113          	addi	sp,sp,-16
 148:	00113423          	sd	ra,8(sp)
 14c:	00813023          	sd	s0,0(sp)
 150:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 154:	00054783          	lbu	a5,0(a0)
 158:	02078663          	beqz	a5,184 <strlen+0x40>
 15c:	00150793          	addi	a5,a0,1
 160:	00078693          	mv	a3,a5
 164:	00178793          	addi	a5,a5,1
 168:	fff7c703          	lbu	a4,-1(a5)
 16c:	fe071ae3          	bnez	a4,160 <strlen+0x1c>
 170:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 174:	00813083          	ld	ra,8(sp)
 178:	00013403          	ld	s0,0(sp)
 17c:	01010113          	addi	sp,sp,16
 180:	00008067          	ret
  for(n = 0; s[n]; n++)
 184:	00000513          	li	a0,0
 188:	fedff06f          	j	174 <strlen+0x30>

000000000000018c <memset>:

void*
memset(void *dst, int c, uint n)
{
 18c:	ff010113          	addi	sp,sp,-16
 190:	00113423          	sd	ra,8(sp)
 194:	00813023          	sd	s0,0(sp)
 198:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 19c:	02060063          	beqz	a2,1bc <memset+0x30>
 1a0:	00050793          	mv	a5,a0
 1a4:	02061613          	slli	a2,a2,0x20
 1a8:	02065613          	srli	a2,a2,0x20
 1ac:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 1b0:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 1b4:	00178793          	addi	a5,a5,1
 1b8:	fee79ce3          	bne	a5,a4,1b0 <memset+0x24>
  }
  return dst;
}
 1bc:	00813083          	ld	ra,8(sp)
 1c0:	00013403          	ld	s0,0(sp)
 1c4:	01010113          	addi	sp,sp,16
 1c8:	00008067          	ret

00000000000001cc <strchr>:

char*
strchr(const char *s, char c)
{
 1cc:	ff010113          	addi	sp,sp,-16
 1d0:	00113423          	sd	ra,8(sp)
 1d4:	00813023          	sd	s0,0(sp)
 1d8:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 1dc:	00054783          	lbu	a5,0(a0)
 1e0:	02078463          	beqz	a5,208 <strchr+0x3c>
    if(*s == c)
 1e4:	00f58a63          	beq	a1,a5,1f8 <strchr+0x2c>
  for(; *s; s++)
 1e8:	00150513          	addi	a0,a0,1
 1ec:	00054783          	lbu	a5,0(a0)
 1f0:	fe079ae3          	bnez	a5,1e4 <strchr+0x18>
      return (char*)s;
  return 0;
 1f4:	00000513          	li	a0,0
}
 1f8:	00813083          	ld	ra,8(sp)
 1fc:	00013403          	ld	s0,0(sp)
 200:	01010113          	addi	sp,sp,16
 204:	00008067          	ret
  return 0;
 208:	00000513          	li	a0,0
 20c:	fedff06f          	j	1f8 <strchr+0x2c>

0000000000000210 <gets>:

char*
gets(char *buf, int max)
{
 210:	fa010113          	addi	sp,sp,-96
 214:	04113c23          	sd	ra,88(sp)
 218:	04813823          	sd	s0,80(sp)
 21c:	04913423          	sd	s1,72(sp)
 220:	05213023          	sd	s2,64(sp)
 224:	03313c23          	sd	s3,56(sp)
 228:	03413823          	sd	s4,48(sp)
 22c:	03513423          	sd	s5,40(sp)
 230:	03613023          	sd	s6,32(sp)
 234:	01713c23          	sd	s7,24(sp)
 238:	01813823          	sd	s8,16(sp)
 23c:	06010413          	addi	s0,sp,96
 240:	00050b93          	mv	s7,a0
 244:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 248:	00050913          	mv	s2,a0
 24c:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 250:	faf40b13          	addi	s6,s0,-81
 254:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 258:	00048c13          	mv	s8,s1
 25c:	0014899b          	addiw	s3,s1,1
 260:	00098493          	mv	s1,s3
 264:	0349dc63          	bge	s3,s4,29c <gets+0x8c>
    cc = read(0, &c, 1);
 268:	000a8613          	mv	a2,s5
 26c:	000b0593          	mv	a1,s6
 270:	00000513          	li	a0,0
 274:	2bc000ef          	jal	530 <read>
    if(cc < 1)
 278:	02a05263          	blez	a0,29c <gets+0x8c>
      break;
    buf[i++] = c;
 27c:	faf44783          	lbu	a5,-81(s0)
 280:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 284:	00190913          	addi	s2,s2,1
 288:	ff678713          	addi	a4,a5,-10
 28c:	00070663          	beqz	a4,298 <gets+0x88>
 290:	ff378793          	addi	a5,a5,-13
 294:	fc0792e3          	bnez	a5,258 <gets+0x48>
    buf[i++] = c;
 298:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 29c:	018b8c33          	add	s8,s7,s8
 2a0:	000c0023          	sb	zero,0(s8)
  return buf;
}
 2a4:	000b8513          	mv	a0,s7
 2a8:	05813083          	ld	ra,88(sp)
 2ac:	05013403          	ld	s0,80(sp)
 2b0:	04813483          	ld	s1,72(sp)
 2b4:	04013903          	ld	s2,64(sp)
 2b8:	03813983          	ld	s3,56(sp)
 2bc:	03013a03          	ld	s4,48(sp)
 2c0:	02813a83          	ld	s5,40(sp)
 2c4:	02013b03          	ld	s6,32(sp)
 2c8:	01813b83          	ld	s7,24(sp)
 2cc:	01013c03          	ld	s8,16(sp)
 2d0:	06010113          	addi	sp,sp,96
 2d4:	00008067          	ret

00000000000002d8 <stat>:

int
stat(const char *n, struct stat *st)
{
 2d8:	fe010113          	addi	sp,sp,-32
 2dc:	00113c23          	sd	ra,24(sp)
 2e0:	00813823          	sd	s0,16(sp)
 2e4:	01213023          	sd	s2,0(sp)
 2e8:	02010413          	addi	s0,sp,32
 2ec:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 2f0:	00000593          	li	a1,0
 2f4:	278000ef          	jal	56c <open>
  if(fd < 0)
 2f8:	02054e63          	bltz	a0,334 <stat+0x5c>
 2fc:	00913423          	sd	s1,8(sp)
 300:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 304:	00090593          	mv	a1,s2
 308:	288000ef          	jal	590 <fstat>
 30c:	00050913          	mv	s2,a0
  close(fd);
 310:	00048513          	mv	a0,s1
 314:	234000ef          	jal	548 <close>
  return r;
 318:	00813483          	ld	s1,8(sp)
}
 31c:	00090513          	mv	a0,s2
 320:	01813083          	ld	ra,24(sp)
 324:	01013403          	ld	s0,16(sp)
 328:	00013903          	ld	s2,0(sp)
 32c:	02010113          	addi	sp,sp,32
 330:	00008067          	ret
    return -1;
 334:	fff00793          	li	a5,-1
 338:	00078913          	mv	s2,a5
 33c:	fe1ff06f          	j	31c <stat+0x44>

0000000000000340 <atoi>:

int
atoi(const char *s)
{
 340:	ff010113          	addi	sp,sp,-16
 344:	00113423          	sd	ra,8(sp)
 348:	00813023          	sd	s0,0(sp)
 34c:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 350:	00054683          	lbu	a3,0(a0)
 354:	fd06879b          	addiw	a5,a3,-48
 358:	0ff7f793          	zext.b	a5,a5
 35c:	00900613          	li	a2,9
 360:	04f66263          	bltu	a2,a5,3a4 <atoi+0x64>
 364:	00050713          	mv	a4,a0
  n = 0;
 368:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 36c:	00170713          	addi	a4,a4,1
 370:	0025179b          	slliw	a5,a0,0x2
 374:	00a787bb          	addw	a5,a5,a0
 378:	0017979b          	slliw	a5,a5,0x1
 37c:	00d787bb          	addw	a5,a5,a3
 380:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 384:	00074683          	lbu	a3,0(a4)
 388:	fd06879b          	addiw	a5,a3,-48
 38c:	0ff7f793          	zext.b	a5,a5
 390:	fcf67ee3          	bgeu	a2,a5,36c <atoi+0x2c>
  return n;
}
 394:	00813083          	ld	ra,8(sp)
 398:	00013403          	ld	s0,0(sp)
 39c:	01010113          	addi	sp,sp,16
 3a0:	00008067          	ret
  n = 0;
 3a4:	00000513          	li	a0,0
 3a8:	fedff06f          	j	394 <atoi+0x54>

00000000000003ac <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 3ac:	ff010113          	addi	sp,sp,-16
 3b0:	00113423          	sd	ra,8(sp)
 3b4:	00813023          	sd	s0,0(sp)
 3b8:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 3bc:	02b57e63          	bgeu	a0,a1,3f8 <memmove+0x4c>
    while(n-- > 0)
 3c0:	02c05463          	blez	a2,3e8 <memmove+0x3c>
 3c4:	02061613          	slli	a2,a2,0x20
 3c8:	02065613          	srli	a2,a2,0x20
 3cc:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 3d0:	00050713          	mv	a4,a0
      *dst++ = *src++;
 3d4:	00158593          	addi	a1,a1,1
 3d8:	00170713          	addi	a4,a4,1
 3dc:	fff5c683          	lbu	a3,-1(a1)
 3e0:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 3e4:	fee798e3          	bne	a5,a4,3d4 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 3e8:	00813083          	ld	ra,8(sp)
 3ec:	00013403          	ld	s0,0(sp)
 3f0:	01010113          	addi	sp,sp,16
 3f4:	00008067          	ret
    while(n-- > 0)
 3f8:	fec058e3          	blez	a2,3e8 <memmove+0x3c>
    dst += n;
 3fc:	00c50733          	add	a4,a0,a2
    src += n;
 400:	00c585b3          	add	a1,a1,a2
 404:	fff6079b          	addiw	a5,a2,-1
 408:	02079793          	slli	a5,a5,0x20
 40c:	0207d793          	srli	a5,a5,0x20
 410:	fff7c793          	not	a5,a5
 414:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 418:	fff58593          	addi	a1,a1,-1
 41c:	fff70713          	addi	a4,a4,-1
 420:	0005c683          	lbu	a3,0(a1)
 424:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 428:	fef718e3          	bne	a4,a5,418 <memmove+0x6c>
 42c:	fbdff06f          	j	3e8 <memmove+0x3c>

0000000000000430 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 430:	ff010113          	addi	sp,sp,-16
 434:	00113423          	sd	ra,8(sp)
 438:	00813023          	sd	s0,0(sp)
 43c:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 440:	04060263          	beqz	a2,484 <memcmp+0x54>
 444:	02061613          	slli	a2,a2,0x20
 448:	02065613          	srli	a2,a2,0x20
 44c:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 450:	00054783          	lbu	a5,0(a0)
 454:	0005c703          	lbu	a4,0(a1)
 458:	00e79c63          	bne	a5,a4,470 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 45c:	00150513          	addi	a0,a0,1
    p2++;
 460:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 464:	fed516e3          	bne	a0,a3,450 <memcmp+0x20>
  }
  return 0;
 468:	00000513          	li	a0,0
 46c:	0080006f          	j	474 <memcmp+0x44>
      return *p1 - *p2;
 470:	40e7853b          	subw	a0,a5,a4
}
 474:	00813083          	ld	ra,8(sp)
 478:	00013403          	ld	s0,0(sp)
 47c:	01010113          	addi	sp,sp,16
 480:	00008067          	ret
  return 0;
 484:	00000513          	li	a0,0
 488:	fedff06f          	j	474 <memcmp+0x44>

000000000000048c <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 48c:	ff010113          	addi	sp,sp,-16
 490:	00113423          	sd	ra,8(sp)
 494:	00813023          	sd	s0,0(sp)
 498:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 49c:	f11ff0ef          	jal	3ac <memmove>
}
 4a0:	00813083          	ld	ra,8(sp)
 4a4:	00013403          	ld	s0,0(sp)
 4a8:	01010113          	addi	sp,sp,16
 4ac:	00008067          	ret

00000000000004b0 <sbrk>:

char *
sbrk(int n) {
 4b0:	ff010113          	addi	sp,sp,-16
 4b4:	00113423          	sd	ra,8(sp)
 4b8:	00813023          	sd	s0,0(sp)
 4bc:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 4c0:	00100593          	li	a1,1
 4c4:	114000ef          	jal	5d8 <sys_sbrk>
}
 4c8:	00813083          	ld	ra,8(sp)
 4cc:	00013403          	ld	s0,0(sp)
 4d0:	01010113          	addi	sp,sp,16
 4d4:	00008067          	ret

00000000000004d8 <sbrklazy>:

char *
sbrklazy(int n) {
 4d8:	ff010113          	addi	sp,sp,-16
 4dc:	00113423          	sd	ra,8(sp)
 4e0:	00813023          	sd	s0,0(sp)
 4e4:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 4e8:	00200593          	li	a1,2
 4ec:	0ec000ef          	jal	5d8 <sys_sbrk>
}
 4f0:	00813083          	ld	ra,8(sp)
 4f4:	00013403          	ld	s0,0(sp)
 4f8:	01010113          	addi	sp,sp,16
 4fc:	00008067          	ret

0000000000000500 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 500:	00100893          	li	a7,1
 ecall
 504:	00000073          	ecall
 ret
 508:	00008067          	ret

000000000000050c <exit>:
.global exit
exit:
 li a7, SYS_exit
 50c:	00200893          	li	a7,2
 ecall
 510:	00000073          	ecall
 ret
 514:	00008067          	ret

0000000000000518 <wait>:
.global wait
wait:
 li a7, SYS_wait
 518:	00300893          	li	a7,3
 ecall
 51c:	00000073          	ecall
 ret
 520:	00008067          	ret

0000000000000524 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 524:	00400893          	li	a7,4
 ecall
 528:	00000073          	ecall
 ret
 52c:	00008067          	ret

0000000000000530 <read>:
.global read
read:
 li a7, SYS_read
 530:	00500893          	li	a7,5
 ecall
 534:	00000073          	ecall
 ret
 538:	00008067          	ret

000000000000053c <write>:
.global write
write:
 li a7, SYS_write
 53c:	01000893          	li	a7,16
 ecall
 540:	00000073          	ecall
 ret
 544:	00008067          	ret

0000000000000548 <close>:
.global close
close:
 li a7, SYS_close
 548:	01500893          	li	a7,21
 ecall
 54c:	00000073          	ecall
 ret
 550:	00008067          	ret

0000000000000554 <kill>:
.global kill
kill:
 li a7, SYS_kill
 554:	00600893          	li	a7,6
 ecall
 558:	00000073          	ecall
 ret
 55c:	00008067          	ret

0000000000000560 <exec>:
.global exec
exec:
 li a7, SYS_exec
 560:	00700893          	li	a7,7
 ecall
 564:	00000073          	ecall
 ret
 568:	00008067          	ret

000000000000056c <open>:
.global open
open:
 li a7, SYS_open
 56c:	00f00893          	li	a7,15
 ecall
 570:	00000073          	ecall
 ret
 574:	00008067          	ret

0000000000000578 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 578:	01100893          	li	a7,17
 ecall
 57c:	00000073          	ecall
 ret
 580:	00008067          	ret

0000000000000584 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 584:	01200893          	li	a7,18
 ecall
 588:	00000073          	ecall
 ret
 58c:	00008067          	ret

0000000000000590 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 590:	00800893          	li	a7,8
 ecall
 594:	00000073          	ecall
 ret
 598:	00008067          	ret

000000000000059c <link>:
.global link
link:
 li a7, SYS_link
 59c:	01300893          	li	a7,19
 ecall
 5a0:	00000073          	ecall
 ret
 5a4:	00008067          	ret

00000000000005a8 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 5a8:	01400893          	li	a7,20
 ecall
 5ac:	00000073          	ecall
 ret
 5b0:	00008067          	ret

00000000000005b4 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 5b4:	00900893          	li	a7,9
 ecall
 5b8:	00000073          	ecall
 ret
 5bc:	00008067          	ret

00000000000005c0 <dup>:
.global dup
dup:
 li a7, SYS_dup
 5c0:	00a00893          	li	a7,10
 ecall
 5c4:	00000073          	ecall
 ret
 5c8:	00008067          	ret

00000000000005cc <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 5cc:	00b00893          	li	a7,11
 ecall
 5d0:	00000073          	ecall
 ret
 5d4:	00008067          	ret

00000000000005d8 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 5d8:	00c00893          	li	a7,12
 ecall
 5dc:	00000073          	ecall
 ret
 5e0:	00008067          	ret

00000000000005e4 <pause>:
.global pause
pause:
 li a7, SYS_pause
 5e4:	00d00893          	li	a7,13
 ecall
 5e8:	00000073          	ecall
 ret
 5ec:	00008067          	ret

00000000000005f0 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 5f0:	00e00893          	li	a7,14
 ecall
 5f4:	00000073          	ecall
 ret
 5f8:	00008067          	ret

00000000000005fc <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 5fc:	00001617          	auipc	a2,0x1
 600:	a1462603          	lw	a2,-1516(a2) # 1010 <putc_n>
 604:	00c04463          	bgtz	a2,60c <putc_flush+0x10>
 608:	00008067          	ret
{
 60c:	ff010113          	addi	sp,sp,-16
 610:	00113423          	sd	ra,8(sp)
 614:	00813023          	sd	s0,0(sp)
 618:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 61c:	00001597          	auipc	a1,0x1
 620:	bfc58593          	addi	a1,a1,-1028 # 1218 <putc_buf>
 624:	00001517          	auipc	a0,0x1
 628:	9dc52503          	lw	a0,-1572(a0) # 1000 <putc_fd>
 62c:	f11ff0ef          	jal	53c <write>
    putc_n = 0;
 630:	00001797          	auipc	a5,0x1
 634:	9e07a023          	sw	zero,-1568(a5) # 1010 <putc_n>
  }
}
 638:	00813083          	ld	ra,8(sp)
 63c:	00013403          	ld	s0,0(sp)
 640:	01010113          	addi	sp,sp,16
 644:	00008067          	ret

0000000000000648 <putc>:

static void
putc(int fd, char c)
{
 648:	fe010113          	addi	sp,sp,-32
 64c:	00113c23          	sd	ra,24(sp)
 650:	00813823          	sd	s0,16(sp)
 654:	00913423          	sd	s1,8(sp)
 658:	02010413          	addi	s0,sp,32
 65c:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 660:	00001797          	auipc	a5,0x1
 664:	9a07a783          	lw	a5,-1632(a5) # 1000 <putc_fd>
 668:	04a79663          	bne	a5,a0,6b4 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 66c:	00001717          	auipc	a4,0x1
 670:	9a470713          	addi	a4,a4,-1628 # 1010 <putc_n>
 674:	00072683          	lw	a3,0(a4)
 678:	0016879b          	addiw	a5,a3,1
 67c:	00f72023          	sw	a5,0(a4)
 680:	00001717          	auipc	a4,0x1
 684:	b9870713          	addi	a4,a4,-1128 # 1218 <putc_buf>
 688:	00d70733          	add	a4,a4,a3
 68c:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 690:	ff648493          	addi	s1,s1,-10
 694:	02048e63          	beqz	s1,6d0 <putc+0x88>
 698:	f8078793          	addi	a5,a5,-128
 69c:	02078a63          	beqz	a5,6d0 <putc+0x88>
    putc_flush();
}
 6a0:	01813083          	ld	ra,24(sp)
 6a4:	01013403          	ld	s0,16(sp)
 6a8:	00813483          	ld	s1,8(sp)
 6ac:	02010113          	addi	sp,sp,32
 6b0:	00008067          	ret
 6b4:	01213023          	sd	s2,0(sp)
 6b8:	00050913          	mv	s2,a0
    putc_flush();
 6bc:	f41ff0ef          	jal	5fc <putc_flush>
    putc_fd = fd;
 6c0:	00001797          	auipc	a5,0x1
 6c4:	9527a023          	sw	s2,-1728(a5) # 1000 <putc_fd>
 6c8:	00013903          	ld	s2,0(sp)
 6cc:	fa1ff06f          	j	66c <putc+0x24>
    putc_flush();
 6d0:	f2dff0ef          	jal	5fc <putc_flush>
}
 6d4:	fcdff06f          	j	6a0 <putc+0x58>

00000000000006d8 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 6d8:	fb010113          	addi	sp,sp,-80
 6dc:	04113423          	sd	ra,72(sp)
 6e0:	04813023          	sd	s0,64(sp)
 6e4:	03213823          	sd	s2,48(sp)
 6e8:	03313423          	sd	s3,40(sp)
 6ec:	05010413          	addi	s0,sp,80
 6f0:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 6f4:	0a068e63          	beqz	a3,7b0 <printint+0xd8>
 6f8:	0a05dc63          	bgez	a1,7b0 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 6fc:	40b005b3          	neg	a1,a1
    neg = 1;
 700:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 704:	fb840993          	addi	s3,s0,-72
  neg = 0;
 708:	00098693          	mv	a3,s3
  i = 0;
 70c:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 710:	00000817          	auipc	a6,0x0
 714:	7d080813          	addi	a6,a6,2000 # ee0 <digits>
 718:	00070893          	mv	a7,a4
 71c:	0017051b          	addiw	a0,a4,1
 720:	00050713          	mv	a4,a0
 724:	02c5f7b3          	remu	a5,a1,a2
 728:	00f807b3          	add	a5,a6,a5
 72c:	0007c783          	lbu	a5,0(a5)
 730:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 734:	00058793          	mv	a5,a1
 738:	02c5d5b3          	divu	a1,a1,a2
 73c:	00168693          	addi	a3,a3,1
 740:	fcc7fce3          	bgeu	a5,a2,718 <printint+0x40>
  if (neg)
 744:	00030c63          	beqz	t1,75c <printint+0x84>
    buf[i++] = '-';
 748:	fd050793          	addi	a5,a0,-48
 74c:	00878533          	add	a0,a5,s0
 750:	02d00793          	li	a5,45
 754:	fef50423          	sb	a5,-24(a0)
 758:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 75c:	02e05e63          	blez	a4,798 <printint+0xc0>
 760:	02913c23          	sd	s1,56(sp)
 764:	fff7071b          	addiw	a4,a4,-1
 768:	00e984b3          	add	s1,s3,a4
 76c:	fff98993          	addi	s3,s3,-1
 770:	00e989b3          	add	s3,s3,a4
 774:	02071713          	slli	a4,a4,0x20
 778:	02075713          	srli	a4,a4,0x20
 77c:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 780:	0004c583          	lbu	a1,0(s1)
 784:	00090513          	mv	a0,s2
 788:	ec1ff0ef          	jal	648 <putc>
  while (--i >= 0)
 78c:	fff48493          	addi	s1,s1,-1
 790:	ff3498e3          	bne	s1,s3,780 <printint+0xa8>
 794:	03813483          	ld	s1,56(sp)
}
 798:	04813083          	ld	ra,72(sp)
 79c:	04013403          	ld	s0,64(sp)
 7a0:	03013903          	ld	s2,48(sp)
 7a4:	02813983          	ld	s3,40(sp)
 7a8:	05010113          	addi	sp,sp,80
 7ac:	00008067          	ret
  neg = 0;
 7b0:	00000313          	li	t1,0
 7b4:	f51ff06f          	j	704 <printint+0x2c>

00000000000007b8 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 7b8:	fa010113          	addi	sp,sp,-96
 7bc:	04113c23          	sd	ra,88(sp)
 7c0:	04813823          	sd	s0,80(sp)
 7c4:	04913423          	sd	s1,72(sp)
 7c8:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 7cc:	0005c483          	lbu	s1,0(a1)
 7d0:	32048263          	beqz	s1,af4 <vprintf+0x33c>
 7d4:	05213023          	sd	s2,64(sp)
 7d8:	03313c23          	sd	s3,56(sp)
 7dc:	03413823          	sd	s4,48(sp)
 7e0:	03513423          	sd	s5,40(sp)
 7e4:	03613023          	sd	s6,32(sp)
 7e8:	01713c23          	sd	s7,24(sp)
 7ec:	01813823          	sd	s8,16(sp)
 7f0:	00050b13          	mv	s6,a0
 7f4:	00058a13          	mv	s4,a1
 7f8:	00060b93          	mv	s7,a2
  state = 0;
 7fc:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 800:	00000913          	li	s2,0
 804:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 808:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 80c:	06400c13          	li	s8,100
 810:	0300006f          	j	840 <vprintf+0x88>
        putc(fd, c0);
 814:	00048593          	mv	a1,s1
 818:	000b0513          	mv	a0,s6
 81c:	e2dff0ef          	jal	648 <putc>
 820:	0080006f          	j	828 <vprintf+0x70>
    else if (state == '%')
 824:	03598863          	beq	s3,s5,854 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 828:	0019079b          	addiw	a5,s2,1
 82c:	00078913          	mv	s2,a5
 830:	00078713          	mv	a4,a5
 834:	00fa07b3          	add	a5,s4,a5
 838:	0007c483          	lbu	s1,0(a5)
 83c:	28048e63          	beqz	s1,ad8 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 840:	0004879b          	sext.w	a5,s1
    if (state == 0)
 844:	fe0990e3          	bnez	s3,824 <vprintf+0x6c>
      if (c0 == '%')
 848:	fd5796e3          	bne	a5,s5,814 <vprintf+0x5c>
        state = '%';
 84c:	00078993          	mv	s3,a5
 850:	fd9ff06f          	j	828 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 854:	00ea06b3          	add	a3,s4,a4
 858:	0016c603          	lbu	a2,1(a3)
      if (c1)
 85c:	2a060663          	beqz	a2,b08 <vprintf+0x350>
      if (c0 == 'd')
 860:	05878063          	beq	a5,s8,8a0 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 864:	f9478693          	addi	a3,a5,-108
 868:	0016b693          	seqz	a3,a3
 86c:	f9c60593          	addi	a1,a2,-100
 870:	04059a63          	bnez	a1,8c4 <vprintf+0x10c>
 874:	04068863          	beqz	a3,8c4 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 878:	008b8493          	addi	s1,s7,8
 87c:	00100693          	li	a3,1
 880:	00a00613          	li	a2,10
 884:	000bb583          	ld	a1,0(s7)
 888:	000b0513          	mv	a0,s6
 88c:	e4dff0ef          	jal	6d8 <printint>
        i += 1;
 890:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 894:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 898:	00000993          	li	s3,0
 89c:	f8dff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 8a0:	008b8493          	addi	s1,s7,8
 8a4:	00100693          	li	a3,1
 8a8:	00a00613          	li	a2,10
 8ac:	000ba583          	lw	a1,0(s7)
 8b0:	000b0513          	mv	a0,s6
 8b4:	e25ff0ef          	jal	6d8 <printint>
 8b8:	00048b93          	mv	s7,s1
      state = 0;
 8bc:	00000993          	li	s3,0
 8c0:	f69ff06f          	j	828 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 8c4:	00ea0733          	add	a4,s4,a4
 8c8:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 8cc:	f9460713          	addi	a4,a2,-108
 8d0:	00173713          	seqz	a4,a4
 8d4:	00e6f733          	and	a4,a3,a4
 8d8:	f9c58513          	addi	a0,a1,-100
 8dc:	24051263          	bnez	a0,b20 <vprintf+0x368>
 8e0:	24070063          	beqz	a4,b20 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 8e4:	008b8493          	addi	s1,s7,8
 8e8:	00100693          	li	a3,1
 8ec:	00a00613          	li	a2,10
 8f0:	000bb583          	ld	a1,0(s7)
 8f4:	000b0513          	mv	a0,s6
 8f8:	de1ff0ef          	jal	6d8 <printint>
        i += 2;
 8fc:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 900:	00048b93          	mv	s7,s1
      state = 0;
 904:	00000993          	li	s3,0
        i += 2;
 908:	f21ff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 90c:	008b8493          	addi	s1,s7,8
 910:	00000693          	li	a3,0
 914:	00a00613          	li	a2,10
 918:	000be583          	lwu	a1,0(s7)
 91c:	000b0513          	mv	a0,s6
 920:	db9ff0ef          	jal	6d8 <printint>
 924:	00048b93          	mv	s7,s1
      state = 0;
 928:	00000993          	li	s3,0
 92c:	efdff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 930:	008b8493          	addi	s1,s7,8
 934:	00000693          	li	a3,0
 938:	00a00613          	li	a2,10
 93c:	000bb583          	ld	a1,0(s7)
 940:	000b0513          	mv	a0,s6
 944:	d95ff0ef          	jal	6d8 <printint>
        i += 1;
 948:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 94c:	00048b93          	mv	s7,s1
      state = 0;
 950:	00000993          	li	s3,0
 954:	ed5ff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 958:	008b8493          	addi	s1,s7,8
 95c:	00000693          	li	a3,0
 960:	00a00613          	li	a2,10
 964:	000bb583          	ld	a1,0(s7)
 968:	000b0513          	mv	a0,s6
 96c:	d6dff0ef          	jal	6d8 <printint>
        i += 2;
 970:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 974:	00048b93          	mv	s7,s1
      state = 0;
 978:	00000993          	li	s3,0
        i += 2;
 97c:	eadff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 980:	008b8493          	addi	s1,s7,8
 984:	00000693          	li	a3,0
 988:	01000613          	li	a2,16
 98c:	000be583          	lwu	a1,0(s7)
 990:	000b0513          	mv	a0,s6
 994:	d45ff0ef          	jal	6d8 <printint>
 998:	00048b93          	mv	s7,s1
      state = 0;
 99c:	00000993          	li	s3,0
 9a0:	e89ff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9a4:	008b8493          	addi	s1,s7,8
 9a8:	00000693          	li	a3,0
 9ac:	01000613          	li	a2,16
 9b0:	000bb583          	ld	a1,0(s7)
 9b4:	000b0513          	mv	a0,s6
 9b8:	d21ff0ef          	jal	6d8 <printint>
        i += 1;
 9bc:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 9c0:	00048b93          	mv	s7,s1
      state = 0;
 9c4:	00000993          	li	s3,0
 9c8:	e61ff06f          	j	828 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9cc:	008b8493          	addi	s1,s7,8
 9d0:	00000693          	li	a3,0
 9d4:	01000613          	li	a2,16
 9d8:	000bb583          	ld	a1,0(s7)
 9dc:	000b0513          	mv	a0,s6
 9e0:	cf9ff0ef          	jal	6d8 <printint>
        i += 2;
 9e4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 9e8:	00048b93          	mv	s7,s1
      state = 0;
 9ec:	00000993          	li	s3,0
        i += 2;
 9f0:	e39ff06f          	j	828 <vprintf+0x70>
 9f4:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 9f8:	008b8793          	addi	a5,s7,8
 9fc:	00078c93          	mv	s9,a5
 a00:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 a04:	03000593          	li	a1,48
 a08:	000b0513          	mv	a0,s6
 a0c:	c3dff0ef          	jal	648 <putc>
  putc(fd, 'x');
 a10:	07800593          	li	a1,120
 a14:	000b0513          	mv	a0,s6
 a18:	c31ff0ef          	jal	648 <putc>
 a1c:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a20:	00000b97          	auipc	s7,0x0
 a24:	4c0b8b93          	addi	s7,s7,1216 # ee0 <digits>
 a28:	03c9d793          	srli	a5,s3,0x3c
 a2c:	00fb87b3          	add	a5,s7,a5
 a30:	0007c583          	lbu	a1,0(a5)
 a34:	000b0513          	mv	a0,s6
 a38:	c11ff0ef          	jal	648 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a3c:	00499993          	slli	s3,s3,0x4
 a40:	fff4849b          	addiw	s1,s1,-1
 a44:	fe0492e3          	bnez	s1,a28 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a48:	000c8b93          	mv	s7,s9
      state = 0;
 a4c:	00000993          	li	s3,0
 a50:	00813c83          	ld	s9,8(sp)
 a54:	dd5ff06f          	j	828 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a58:	008b8493          	addi	s1,s7,8
 a5c:	000bc583          	lbu	a1,0(s7)
 a60:	000b0513          	mv	a0,s6
 a64:	be5ff0ef          	jal	648 <putc>
 a68:	00048b93          	mv	s7,s1
      state = 0;
 a6c:	00000993          	li	s3,0
 a70:	db9ff06f          	j	828 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a74:	008b8993          	addi	s3,s7,8
 a78:	000bb483          	ld	s1,0(s7)
 a7c:	02048663          	beqz	s1,aa8 <vprintf+0x2f0>
        for (; *s; s++)
 a80:	0004c583          	lbu	a1,0(s1)
 a84:	04058463          	beqz	a1,acc <vprintf+0x314>
          putc(fd, *s);
 a88:	000b0513          	mv	a0,s6
 a8c:	bbdff0ef          	jal	648 <putc>
        for (; *s; s++)
 a90:	00148493          	addi	s1,s1,1
 a94:	0004c583          	lbu	a1,0(s1)
 a98:	fe0598e3          	bnez	a1,a88 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 a9c:	00098b93          	mv	s7,s3
      state = 0;
 aa0:	00000993          	li	s3,0
 aa4:	d85ff06f          	j	828 <vprintf+0x70>
          s = "(null)";
 aa8:	00000497          	auipc	s1,0x0
 aac:	43048493          	addi	s1,s1,1072 # ed8 <malloc+0x1e8>
        for (; *s; s++)
 ab0:	02800593          	li	a1,40
 ab4:	fd5ff06f          	j	a88 <vprintf+0x2d0>
        putc(fd, '%');
 ab8:	00078593          	mv	a1,a5
 abc:	000b0513          	mv	a0,s6
 ac0:	b89ff0ef          	jal	648 <putc>
      state = 0;
 ac4:	00000993          	li	s3,0
 ac8:	d61ff06f          	j	828 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 acc:	00098b93          	mv	s7,s3
      state = 0;
 ad0:	00000993          	li	s3,0
 ad4:	d55ff06f          	j	828 <vprintf+0x70>
 ad8:	04013903          	ld	s2,64(sp)
 adc:	03813983          	ld	s3,56(sp)
 ae0:	03013a03          	ld	s4,48(sp)
 ae4:	02813a83          	ld	s5,40(sp)
 ae8:	02013b03          	ld	s6,32(sp)
 aec:	01813b83          	ld	s7,24(sp)
 af0:	01013c03          	ld	s8,16(sp)
    }
  }
}
 af4:	05813083          	ld	ra,88(sp)
 af8:	05013403          	ld	s0,80(sp)
 afc:	04813483          	ld	s1,72(sp)
 b00:	06010113          	addi	sp,sp,96
 b04:	00008067          	ret
      if (c0 == 'd')
 b08:	06400713          	li	a4,100
 b0c:	d8e78ae3          	beq	a5,a4,8a0 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 b10:	f9478693          	addi	a3,a5,-108
 b14:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 b18:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 b1c:	00000713          	li	a4,0
      else if (c0 == 'u')
 b20:	07500513          	li	a0,117
 b24:	dea784e3          	beq	a5,a0,90c <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b28:	f8b60513          	addi	a0,a2,-117
 b2c:	00051463          	bnez	a0,b34 <vprintf+0x37c>
 b30:	e00690e3          	bnez	a3,930 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 b34:	f8b58513          	addi	a0,a1,-117
 b38:	00051463          	bnez	a0,b40 <vprintf+0x388>
 b3c:	e0071ee3          	bnez	a4,958 <vprintf+0x1a0>
      else if (c0 == 'x')
 b40:	07800513          	li	a0,120
 b44:	e2a78ee3          	beq	a5,a0,980 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b48:	f8860613          	addi	a2,a2,-120
 b4c:	00061463          	bnez	a2,b54 <vprintf+0x39c>
 b50:	e4069ae3          	bnez	a3,9a4 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b54:	f8858593          	addi	a1,a1,-120
 b58:	00059463          	bnez	a1,b60 <vprintf+0x3a8>
 b5c:	e60718e3          	bnez	a4,9cc <vprintf+0x214>
      else if (c0 == 'p')
 b60:	07000713          	li	a4,112
 b64:	e8e788e3          	beq	a5,a4,9f4 <vprintf+0x23c>
      else if (c0 == 'c')
 b68:	06300713          	li	a4,99
 b6c:	eee786e3          	beq	a5,a4,a58 <vprintf+0x2a0>
      else if (c0 == 's')
 b70:	07300713          	li	a4,115
 b74:	f0e780e3          	beq	a5,a4,a74 <vprintf+0x2bc>
      else if (c0 == '%')
 b78:	02500713          	li	a4,37
 b7c:	f2e78ee3          	beq	a5,a4,ab8 <vprintf+0x300>
        putc(fd, '%');
 b80:	02500593          	li	a1,37
 b84:	000b0513          	mv	a0,s6
 b88:	ac1ff0ef          	jal	648 <putc>
        putc(fd, c0);
 b8c:	00048593          	mv	a1,s1
 b90:	000b0513          	mv	a0,s6
 b94:	ab5ff0ef          	jal	648 <putc>
      state = 0;
 b98:	00000993          	li	s3,0
 b9c:	c8dff06f          	j	828 <vprintf+0x70>

0000000000000ba0 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 ba0:	fb010113          	addi	sp,sp,-80
 ba4:	00113c23          	sd	ra,24(sp)
 ba8:	00813823          	sd	s0,16(sp)
 bac:	02010413          	addi	s0,sp,32
 bb0:	00c43023          	sd	a2,0(s0)
 bb4:	00d43423          	sd	a3,8(s0)
 bb8:	00e43823          	sd	a4,16(s0)
 bbc:	00f43c23          	sd	a5,24(s0)
 bc0:	03043023          	sd	a6,32(s0)
 bc4:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 bc8:	00040613          	mv	a2,s0
 bcc:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 bd0:	be9ff0ef          	jal	7b8 <vprintf>
}
 bd4:	01813083          	ld	ra,24(sp)
 bd8:	01013403          	ld	s0,16(sp)
 bdc:	05010113          	addi	sp,sp,80
 be0:	00008067          	ret

0000000000000be4 <printf>:

void printf(const char *fmt, ...)
{
 be4:	fa010113          	addi	sp,sp,-96
 be8:	00113c23          	sd	ra,24(sp)
 bec:	00813823          	sd	s0,16(sp)
 bf0:	02010413          	addi	s0,sp,32
 bf4:	00b43423          	sd	a1,8(s0)
 bf8:	00c43823          	sd	a2,16(s0)
 bfc:	00d43c23          	sd	a3,24(s0)
 c00:	02e43023          	sd	a4,32(s0)
 c04:	02f43423          	sd	a5,40(s0)
 c08:	03043823          	sd	a6,48(s0)
 c0c:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 c10:	00840613          	addi	a2,s0,8
 c14:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 c18:	00050593          	mv	a1,a0
 c1c:	00100513          	li	a0,1
 c20:	b99ff0ef          	jal	7b8 <vprintf>
  putc_flush();
 c24:	9d9ff0ef          	jal	5fc <putc_flush>
}
 c28:	01813083          	ld	ra,24(sp)
 c2c:	01013403          	ld	s0,16(sp)
 c30:	06010113          	addi	sp,sp,96
 c34:	00008067          	ret

0000000000000c38 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c38:	ff010113          	addi	sp,sp,-16
 c3c:	00113423          	sd	ra,8(sp)
 c40:	00813023          	sd	s0,0(sp)
 c44:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c48:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c4c:	00000797          	auipc	a5,0x0
 c50:	3cc7b783          	ld	a5,972(a5) # 1018 <freep>
 c54:	0140006f          	j	c68 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c58:	0007b703          	ld	a4,0(a5)
 c5c:	00e7e463          	bltu	a5,a4,c64 <free+0x2c>
 c60:	00e6ec63          	bltu	a3,a4,c78 <free+0x40>
{
 c64:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c68:	fed7f8e3          	bgeu	a5,a3,c58 <free+0x20>
 c6c:	0007b703          	ld	a4,0(a5)
 c70:	00e6e463          	bltu	a3,a4,c78 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c74:	fee7e8e3          	bltu	a5,a4,c64 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 c78:	ff852583          	lw	a1,-8(a0)
 c7c:	0007b603          	ld	a2,0(a5)
 c80:	02059813          	slli	a6,a1,0x20
 c84:	01c85713          	srli	a4,a6,0x1c
 c88:	00e68733          	add	a4,a3,a4
 c8c:	02e60c63          	beq	a2,a4,cc4 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c90:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c94:	0087a603          	lw	a2,8(a5)
 c98:	02061593          	slli	a1,a2,0x20
 c9c:	01c5d713          	srli	a4,a1,0x1c
 ca0:	00e78733          	add	a4,a5,a4
 ca4:	02e68c63          	beq	a3,a4,cdc <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 ca8:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 cac:	00000717          	auipc	a4,0x0
 cb0:	36f73623          	sd	a5,876(a4) # 1018 <freep>
}
 cb4:	00813083          	ld	ra,8(sp)
 cb8:	00013403          	ld	s0,0(sp)
 cbc:	01010113          	addi	sp,sp,16
 cc0:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 cc4:	00862703          	lw	a4,8(a2)
 cc8:	00b7073b          	addw	a4,a4,a1
 ccc:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 cd0:	0007b703          	ld	a4,0(a5)
 cd4:	00073603          	ld	a2,0(a4)
 cd8:	fb9ff06f          	j	c90 <free+0x58>
    p->s.size += bp->s.size;
 cdc:	ff852703          	lw	a4,-8(a0)
 ce0:	00c7073b          	addw	a4,a4,a2
 ce4:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 ce8:	ff053683          	ld	a3,-16(a0)
 cec:	fbdff06f          	j	ca8 <free+0x70>

0000000000000cf0 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 cf0:	fc010113          	addi	sp,sp,-64
 cf4:	02113c23          	sd	ra,56(sp)
 cf8:	02813823          	sd	s0,48(sp)
 cfc:	03213023          	sd	s2,32(sp)
 d00:	01313c23          	sd	s3,24(sp)
 d04:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 d08:	02051993          	slli	s3,a0,0x20
 d0c:	0209d993          	srli	s3,s3,0x20
 d10:	00f98993          	addi	s3,s3,15
 d14:	0049d993          	srli	s3,s3,0x4
 d18:	0019899b          	addiw	s3,s3,1
 d1c:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d20:	00000517          	auipc	a0,0x0
 d24:	2f853503          	ld	a0,760(a0) # 1018 <freep>
 d28:	04050463          	beqz	a0,d70 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d2c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d30:	0087a703          	lw	a4,8(a5)
 d34:	0d377a63          	bgeu	a4,s3,e08 <malloc+0x118>
 d38:	02913423          	sd	s1,40(sp)
 d3c:	01413823          	sd	s4,16(sp)
 d40:	01513423          	sd	s5,8(sp)
 d44:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d48:	00098a13          	mv	s4,s3
 d4c:	00001737          	lui	a4,0x1
 d50:	00e9f463          	bgeu	s3,a4,d58 <malloc+0x68>
 d54:	00001a37          	lui	s4,0x1
 d58:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d5c:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d60:	00000497          	auipc	s1,0x0
 d64:	2b848493          	addi	s1,s1,696 # 1018 <freep>
  if(p == SBRK_ERROR)
 d68:	fff00a93          	li	s5,-1
 d6c:	05c0006f          	j	dc8 <malloc+0xd8>
 d70:	02913423          	sd	s1,40(sp)
 d74:	01413823          	sd	s4,16(sp)
 d78:	01513423          	sd	s5,8(sp)
 d7c:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d80:	00000797          	auipc	a5,0x0
 d84:	51878793          	addi	a5,a5,1304 # 1298 <base>
 d88:	00000717          	auipc	a4,0x0
 d8c:	28f73823          	sd	a5,656(a4) # 1018 <freep>
 d90:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d94:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d98:	fb1ff06f          	j	d48 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 d9c:	0007b703          	ld	a4,0(a5)
 da0:	00e53023          	sd	a4,0(a0)
 da4:	0800006f          	j	e24 <malloc+0x134>
  hp->s.size = nu;
 da8:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 dac:	01050513          	addi	a0,a0,16
 db0:	e89ff0ef          	jal	c38 <free>
  return freep;
 db4:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 db8:	08050863          	beqz	a0,e48 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 dbc:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 dc0:	0087a703          	lw	a4,8(a5)
 dc4:	03277a63          	bgeu	a4,s2,df8 <malloc+0x108>
    if(p == freep)
 dc8:	0004b703          	ld	a4,0(s1)
 dcc:	00078513          	mv	a0,a5
 dd0:	fef716e3          	bne	a4,a5,dbc <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 dd4:	000a0513          	mv	a0,s4
 dd8:	ed8ff0ef          	jal	4b0 <sbrk>
  if(p == SBRK_ERROR)
 ddc:	fd5516e3          	bne	a0,s5,da8 <malloc+0xb8>
        return 0;
 de0:	00000513          	li	a0,0
 de4:	02813483          	ld	s1,40(sp)
 de8:	01013a03          	ld	s4,16(sp)
 dec:	00813a83          	ld	s5,8(sp)
 df0:	00013b03          	ld	s6,0(sp)
 df4:	03c0006f          	j	e30 <malloc+0x140>
 df8:	02813483          	ld	s1,40(sp)
 dfc:	01013a03          	ld	s4,16(sp)
 e00:	00813a83          	ld	s5,8(sp)
 e04:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 e08:	f8e90ae3          	beq	s2,a4,d9c <malloc+0xac>
        p->s.size -= nunits;
 e0c:	4137073b          	subw	a4,a4,s3
 e10:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 e14:	02071693          	slli	a3,a4,0x20
 e18:	01c6d713          	srli	a4,a3,0x1c
 e1c:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e20:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e24:	00000717          	auipc	a4,0x0
 e28:	1ea73a23          	sd	a0,500(a4) # 1018 <freep>
      return (void*)(p + 1);
 e2c:	01078513          	addi	a0,a5,16
  }
}
 e30:	03813083          	ld	ra,56(sp)
 e34:	03013403          	ld	s0,48(sp)
 e38:	02013903          	ld	s2,32(sp)
 e3c:	01813983          	ld	s3,24(sp)
 e40:	04010113          	addi	sp,sp,64
 e44:	00008067          	ret
 e48:	02813483          	ld	s1,40(sp)
 e4c:	01013a03          	ld	s4,16(sp)
 e50:	00813a83          	ld	s5,8(sp)
 e54:	00013b03          	ld	s6,0(sp)
 e58:	fd9ff06f          	j	e30 <malloc+0x140>
