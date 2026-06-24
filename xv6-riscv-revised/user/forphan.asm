
user/_forphan:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:

char buf[BUFSZ];

int
main(int argc, char **argv)
{
   0:	fc010113          	addi	sp,sp,-64
   4:	02113c23          	sd	ra,56(sp)
   8:	02813823          	sd	s0,48(sp)
   c:	02913423          	sd	s1,40(sp)
  10:	04010413          	addi	s0,sp,64
  int fd = 0;
  char *s = argv[0];
  14:	0005b483          	ld	s1,0(a1)
  struct stat st;
  char *ff = "file0";
  
  if ((fd = open(ff, O_CREATE|O_WRONLY)) < 0) {
  18:	20100593          	li	a1,513
  1c:	00001517          	auipc	a0,0x1
  20:	e8450513          	addi	a0,a0,-380 # ea0 <malloc+0x170>
  24:	588000ef          	jal	5ac <open>
  28:	04054863          	bltz	a0,78 <main+0x78>
    printf("%s: open failed\n", s);
    exit(1);
  }
  if(fstat(fd, &st) < 0){
  2c:	fc840593          	addi	a1,s0,-56
  30:	5a0000ef          	jal	5d0 <fstat>
  34:	04054e63          	bltz	a0,90 <main+0x90>
    fprintf(2, "%s: cannot stat %s\n", s, "ff");
    exit(1);
  }
  if (unlink(ff) < 0) {
  38:	00001517          	auipc	a0,0x1
  3c:	e6850513          	addi	a0,a0,-408 # ea0 <malloc+0x170>
  40:	584000ef          	jal	5c4 <unlink>
  44:	06054863          	bltz	a0,b4 <main+0xb4>
    printf("%s: unlink failed\n", s);
    exit(1);
  }
  if (open(ff, O_RDONLY) != -1) {
  48:	00000593          	li	a1,0
  4c:	00001517          	auipc	a0,0x1
  50:	e5450513          	addi	a0,a0,-428 # ea0 <malloc+0x170>
  54:	558000ef          	jal	5ac <open>
  58:	fff00793          	li	a5,-1
  5c:	06f50863          	beq	a0,a5,cc <main+0xcc>
    printf("%s: open successed\n", s);
  60:	00048593          	mv	a1,s1
  64:	00001517          	auipc	a0,0x1
  68:	e9c50513          	addi	a0,a0,-356 # f00 <malloc+0x1d0>
  6c:	3b9000ef          	jal	c24 <printf>
    exit(1);
  70:	00100513          	li	a0,1
  74:	4d8000ef          	jal	54c <exit>
    printf("%s: open failed\n", s);
  78:	00048593          	mv	a1,s1
  7c:	00001517          	auipc	a0,0x1
  80:	e3450513          	addi	a0,a0,-460 # eb0 <malloc+0x180>
  84:	3a1000ef          	jal	c24 <printf>
    exit(1);
  88:	00100513          	li	a0,1
  8c:	4c0000ef          	jal	54c <exit>
    fprintf(2, "%s: cannot stat %s\n", s, "ff");
  90:	00001697          	auipc	a3,0x1
  94:	e3868693          	addi	a3,a3,-456 # ec8 <malloc+0x198>
  98:	00048613          	mv	a2,s1
  9c:	00001597          	auipc	a1,0x1
  a0:	e3458593          	addi	a1,a1,-460 # ed0 <malloc+0x1a0>
  a4:	00200513          	li	a0,2
  a8:	339000ef          	jal	be0 <fprintf>
    exit(1);
  ac:	00100513          	li	a0,1
  b0:	49c000ef          	jal	54c <exit>
    printf("%s: unlink failed\n", s);
  b4:	00048593          	mv	a1,s1
  b8:	00001517          	auipc	a0,0x1
  bc:	e3050513          	addi	a0,a0,-464 # ee8 <malloc+0x1b8>
  c0:	365000ef          	jal	c24 <printf>
    exit(1);
  c4:	00100513          	li	a0,1
  c8:	484000ef          	jal	54c <exit>
  }
  printf("wait for kill and reclaim %d\n", st.ino);
  cc:	fcc42583          	lw	a1,-52(s0)
  d0:	00001517          	auipc	a0,0x1
  d4:	e4850513          	addi	a0,a0,-440 # f18 <malloc+0x1e8>
  d8:	34d000ef          	jal	c24 <printf>
  // sit around until killed
  for(;;) pause(1000);
  dc:	3e800493          	li	s1,1000
  e0:	00048513          	mv	a0,s1
  e4:	540000ef          	jal	624 <pause>
  e8:	ff9ff06f          	j	e0 <main+0xe0>

00000000000000ec <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  ec:	ff010113          	addi	sp,sp,-16
  f0:	00113423          	sd	ra,8(sp)
  f4:	00813023          	sd	s0,0(sp)
  f8:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  fc:	f05ff0ef          	jal	0 <main>
  exit(r);
 100:	44c000ef          	jal	54c <exit>

0000000000000104 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 104:	ff010113          	addi	sp,sp,-16
 108:	00113423          	sd	ra,8(sp)
 10c:	00813023          	sd	s0,0(sp)
 110:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 114:	00050793          	mv	a5,a0
 118:	00158593          	addi	a1,a1,1
 11c:	00178793          	addi	a5,a5,1
 120:	fff5c703          	lbu	a4,-1(a1)
 124:	fee78fa3          	sb	a4,-1(a5)
 128:	fe0718e3          	bnez	a4,118 <strcpy+0x14>
    ;
  return os;
}
 12c:	00813083          	ld	ra,8(sp)
 130:	00013403          	ld	s0,0(sp)
 134:	01010113          	addi	sp,sp,16
 138:	00008067          	ret

000000000000013c <strcmp>:

int
strcmp(const char *p, const char *q)
{
 13c:	ff010113          	addi	sp,sp,-16
 140:	00113423          	sd	ra,8(sp)
 144:	00813023          	sd	s0,0(sp)
 148:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 14c:	00054783          	lbu	a5,0(a0)
 150:	00078e63          	beqz	a5,16c <strcmp+0x30>
 154:	0005c703          	lbu	a4,0(a1)
 158:	00f71a63          	bne	a4,a5,16c <strcmp+0x30>
    p++, q++;
 15c:	00150513          	addi	a0,a0,1
 160:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 164:	00054783          	lbu	a5,0(a0)
 168:	fe0796e3          	bnez	a5,154 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 16c:	0005c503          	lbu	a0,0(a1)
}
 170:	40a7853b          	subw	a0,a5,a0
 174:	00813083          	ld	ra,8(sp)
 178:	00013403          	ld	s0,0(sp)
 17c:	01010113          	addi	sp,sp,16
 180:	00008067          	ret

0000000000000184 <strlen>:

uint
strlen(const char *s)
{
 184:	ff010113          	addi	sp,sp,-16
 188:	00113423          	sd	ra,8(sp)
 18c:	00813023          	sd	s0,0(sp)
 190:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 194:	00054783          	lbu	a5,0(a0)
 198:	02078663          	beqz	a5,1c4 <strlen+0x40>
 19c:	00150793          	addi	a5,a0,1
 1a0:	00078693          	mv	a3,a5
 1a4:	00178793          	addi	a5,a5,1
 1a8:	fff7c703          	lbu	a4,-1(a5)
 1ac:	fe071ae3          	bnez	a4,1a0 <strlen+0x1c>
 1b0:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 1b4:	00813083          	ld	ra,8(sp)
 1b8:	00013403          	ld	s0,0(sp)
 1bc:	01010113          	addi	sp,sp,16
 1c0:	00008067          	ret
  for(n = 0; s[n]; n++)
 1c4:	00000513          	li	a0,0
 1c8:	fedff06f          	j	1b4 <strlen+0x30>

00000000000001cc <memset>:

void*
memset(void *dst, int c, uint n)
{
 1cc:	ff010113          	addi	sp,sp,-16
 1d0:	00113423          	sd	ra,8(sp)
 1d4:	00813023          	sd	s0,0(sp)
 1d8:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 1dc:	02060063          	beqz	a2,1fc <memset+0x30>
 1e0:	00050793          	mv	a5,a0
 1e4:	02061613          	slli	a2,a2,0x20
 1e8:	02065613          	srli	a2,a2,0x20
 1ec:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 1f0:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 1f4:	00178793          	addi	a5,a5,1
 1f8:	fee79ce3          	bne	a5,a4,1f0 <memset+0x24>
  }
  return dst;
}
 1fc:	00813083          	ld	ra,8(sp)
 200:	00013403          	ld	s0,0(sp)
 204:	01010113          	addi	sp,sp,16
 208:	00008067          	ret

000000000000020c <strchr>:

char*
strchr(const char *s, char c)
{
 20c:	ff010113          	addi	sp,sp,-16
 210:	00113423          	sd	ra,8(sp)
 214:	00813023          	sd	s0,0(sp)
 218:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 21c:	00054783          	lbu	a5,0(a0)
 220:	02078463          	beqz	a5,248 <strchr+0x3c>
    if(*s == c)
 224:	00f58a63          	beq	a1,a5,238 <strchr+0x2c>
  for(; *s; s++)
 228:	00150513          	addi	a0,a0,1
 22c:	00054783          	lbu	a5,0(a0)
 230:	fe079ae3          	bnez	a5,224 <strchr+0x18>
      return (char*)s;
  return 0;
 234:	00000513          	li	a0,0
}
 238:	00813083          	ld	ra,8(sp)
 23c:	00013403          	ld	s0,0(sp)
 240:	01010113          	addi	sp,sp,16
 244:	00008067          	ret
  return 0;
 248:	00000513          	li	a0,0
 24c:	fedff06f          	j	238 <strchr+0x2c>

0000000000000250 <gets>:

char*
gets(char *buf, int max)
{
 250:	fa010113          	addi	sp,sp,-96
 254:	04113c23          	sd	ra,88(sp)
 258:	04813823          	sd	s0,80(sp)
 25c:	04913423          	sd	s1,72(sp)
 260:	05213023          	sd	s2,64(sp)
 264:	03313c23          	sd	s3,56(sp)
 268:	03413823          	sd	s4,48(sp)
 26c:	03513423          	sd	s5,40(sp)
 270:	03613023          	sd	s6,32(sp)
 274:	01713c23          	sd	s7,24(sp)
 278:	01813823          	sd	s8,16(sp)
 27c:	06010413          	addi	s0,sp,96
 280:	00050b93          	mv	s7,a0
 284:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 288:	00050913          	mv	s2,a0
 28c:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 290:	faf40b13          	addi	s6,s0,-81
 294:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 298:	00048c13          	mv	s8,s1
 29c:	0014899b          	addiw	s3,s1,1
 2a0:	00098493          	mv	s1,s3
 2a4:	0349dc63          	bge	s3,s4,2dc <gets+0x8c>
    cc = read(0, &c, 1);
 2a8:	000a8613          	mv	a2,s5
 2ac:	000b0593          	mv	a1,s6
 2b0:	00000513          	li	a0,0
 2b4:	2bc000ef          	jal	570 <read>
    if(cc < 1)
 2b8:	02a05263          	blez	a0,2dc <gets+0x8c>
      break;
    buf[i++] = c;
 2bc:	faf44783          	lbu	a5,-81(s0)
 2c0:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 2c4:	00190913          	addi	s2,s2,1
 2c8:	ff678713          	addi	a4,a5,-10
 2cc:	00070663          	beqz	a4,2d8 <gets+0x88>
 2d0:	ff378793          	addi	a5,a5,-13
 2d4:	fc0792e3          	bnez	a5,298 <gets+0x48>
    buf[i++] = c;
 2d8:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 2dc:	018b8c33          	add	s8,s7,s8
 2e0:	000c0023          	sb	zero,0(s8)
  return buf;
}
 2e4:	000b8513          	mv	a0,s7
 2e8:	05813083          	ld	ra,88(sp)
 2ec:	05013403          	ld	s0,80(sp)
 2f0:	04813483          	ld	s1,72(sp)
 2f4:	04013903          	ld	s2,64(sp)
 2f8:	03813983          	ld	s3,56(sp)
 2fc:	03013a03          	ld	s4,48(sp)
 300:	02813a83          	ld	s5,40(sp)
 304:	02013b03          	ld	s6,32(sp)
 308:	01813b83          	ld	s7,24(sp)
 30c:	01013c03          	ld	s8,16(sp)
 310:	06010113          	addi	sp,sp,96
 314:	00008067          	ret

0000000000000318 <stat>:

int
stat(const char *n, struct stat *st)
{
 318:	fe010113          	addi	sp,sp,-32
 31c:	00113c23          	sd	ra,24(sp)
 320:	00813823          	sd	s0,16(sp)
 324:	01213023          	sd	s2,0(sp)
 328:	02010413          	addi	s0,sp,32
 32c:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 330:	00000593          	li	a1,0
 334:	278000ef          	jal	5ac <open>
  if(fd < 0)
 338:	02054e63          	bltz	a0,374 <stat+0x5c>
 33c:	00913423          	sd	s1,8(sp)
 340:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 344:	00090593          	mv	a1,s2
 348:	288000ef          	jal	5d0 <fstat>
 34c:	00050913          	mv	s2,a0
  close(fd);
 350:	00048513          	mv	a0,s1
 354:	234000ef          	jal	588 <close>
  return r;
 358:	00813483          	ld	s1,8(sp)
}
 35c:	00090513          	mv	a0,s2
 360:	01813083          	ld	ra,24(sp)
 364:	01013403          	ld	s0,16(sp)
 368:	00013903          	ld	s2,0(sp)
 36c:	02010113          	addi	sp,sp,32
 370:	00008067          	ret
    return -1;
 374:	fff00793          	li	a5,-1
 378:	00078913          	mv	s2,a5
 37c:	fe1ff06f          	j	35c <stat+0x44>

0000000000000380 <atoi>:

int
atoi(const char *s)
{
 380:	ff010113          	addi	sp,sp,-16
 384:	00113423          	sd	ra,8(sp)
 388:	00813023          	sd	s0,0(sp)
 38c:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 390:	00054683          	lbu	a3,0(a0)
 394:	fd06879b          	addiw	a5,a3,-48
 398:	0ff7f793          	zext.b	a5,a5
 39c:	00900613          	li	a2,9
 3a0:	04f66263          	bltu	a2,a5,3e4 <atoi+0x64>
 3a4:	00050713          	mv	a4,a0
  n = 0;
 3a8:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 3ac:	00170713          	addi	a4,a4,1
 3b0:	0025179b          	slliw	a5,a0,0x2
 3b4:	00a787bb          	addw	a5,a5,a0
 3b8:	0017979b          	slliw	a5,a5,0x1
 3bc:	00d787bb          	addw	a5,a5,a3
 3c0:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 3c4:	00074683          	lbu	a3,0(a4)
 3c8:	fd06879b          	addiw	a5,a3,-48
 3cc:	0ff7f793          	zext.b	a5,a5
 3d0:	fcf67ee3          	bgeu	a2,a5,3ac <atoi+0x2c>
  return n;
}
 3d4:	00813083          	ld	ra,8(sp)
 3d8:	00013403          	ld	s0,0(sp)
 3dc:	01010113          	addi	sp,sp,16
 3e0:	00008067          	ret
  n = 0;
 3e4:	00000513          	li	a0,0
 3e8:	fedff06f          	j	3d4 <atoi+0x54>

00000000000003ec <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 3ec:	ff010113          	addi	sp,sp,-16
 3f0:	00113423          	sd	ra,8(sp)
 3f4:	00813023          	sd	s0,0(sp)
 3f8:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 3fc:	02b57e63          	bgeu	a0,a1,438 <memmove+0x4c>
    while(n-- > 0)
 400:	02c05463          	blez	a2,428 <memmove+0x3c>
 404:	02061613          	slli	a2,a2,0x20
 408:	02065613          	srli	a2,a2,0x20
 40c:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 410:	00050713          	mv	a4,a0
      *dst++ = *src++;
 414:	00158593          	addi	a1,a1,1
 418:	00170713          	addi	a4,a4,1
 41c:	fff5c683          	lbu	a3,-1(a1)
 420:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 424:	fee798e3          	bne	a5,a4,414 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 428:	00813083          	ld	ra,8(sp)
 42c:	00013403          	ld	s0,0(sp)
 430:	01010113          	addi	sp,sp,16
 434:	00008067          	ret
    while(n-- > 0)
 438:	fec058e3          	blez	a2,428 <memmove+0x3c>
    dst += n;
 43c:	00c50733          	add	a4,a0,a2
    src += n;
 440:	00c585b3          	add	a1,a1,a2
 444:	fff6079b          	addiw	a5,a2,-1
 448:	02079793          	slli	a5,a5,0x20
 44c:	0207d793          	srli	a5,a5,0x20
 450:	fff7c793          	not	a5,a5
 454:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 458:	fff58593          	addi	a1,a1,-1
 45c:	fff70713          	addi	a4,a4,-1
 460:	0005c683          	lbu	a3,0(a1)
 464:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 468:	fef718e3          	bne	a4,a5,458 <memmove+0x6c>
 46c:	fbdff06f          	j	428 <memmove+0x3c>

0000000000000470 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 470:	ff010113          	addi	sp,sp,-16
 474:	00113423          	sd	ra,8(sp)
 478:	00813023          	sd	s0,0(sp)
 47c:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 480:	04060263          	beqz	a2,4c4 <memcmp+0x54>
 484:	02061613          	slli	a2,a2,0x20
 488:	02065613          	srli	a2,a2,0x20
 48c:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 490:	00054783          	lbu	a5,0(a0)
 494:	0005c703          	lbu	a4,0(a1)
 498:	00e79c63          	bne	a5,a4,4b0 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 49c:	00150513          	addi	a0,a0,1
    p2++;
 4a0:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 4a4:	fed516e3          	bne	a0,a3,490 <memcmp+0x20>
  }
  return 0;
 4a8:	00000513          	li	a0,0
 4ac:	0080006f          	j	4b4 <memcmp+0x44>
      return *p1 - *p2;
 4b0:	40e7853b          	subw	a0,a5,a4
}
 4b4:	00813083          	ld	ra,8(sp)
 4b8:	00013403          	ld	s0,0(sp)
 4bc:	01010113          	addi	sp,sp,16
 4c0:	00008067          	ret
  return 0;
 4c4:	00000513          	li	a0,0
 4c8:	fedff06f          	j	4b4 <memcmp+0x44>

00000000000004cc <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 4cc:	ff010113          	addi	sp,sp,-16
 4d0:	00113423          	sd	ra,8(sp)
 4d4:	00813023          	sd	s0,0(sp)
 4d8:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 4dc:	f11ff0ef          	jal	3ec <memmove>
}
 4e0:	00813083          	ld	ra,8(sp)
 4e4:	00013403          	ld	s0,0(sp)
 4e8:	01010113          	addi	sp,sp,16
 4ec:	00008067          	ret

00000000000004f0 <sbrk>:

char *
sbrk(int n) {
 4f0:	ff010113          	addi	sp,sp,-16
 4f4:	00113423          	sd	ra,8(sp)
 4f8:	00813023          	sd	s0,0(sp)
 4fc:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 500:	00100593          	li	a1,1
 504:	114000ef          	jal	618 <sys_sbrk>
}
 508:	00813083          	ld	ra,8(sp)
 50c:	00013403          	ld	s0,0(sp)
 510:	01010113          	addi	sp,sp,16
 514:	00008067          	ret

0000000000000518 <sbrklazy>:

char *
sbrklazy(int n) {
 518:	ff010113          	addi	sp,sp,-16
 51c:	00113423          	sd	ra,8(sp)
 520:	00813023          	sd	s0,0(sp)
 524:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 528:	00200593          	li	a1,2
 52c:	0ec000ef          	jal	618 <sys_sbrk>
}
 530:	00813083          	ld	ra,8(sp)
 534:	00013403          	ld	s0,0(sp)
 538:	01010113          	addi	sp,sp,16
 53c:	00008067          	ret

0000000000000540 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 540:	00100893          	li	a7,1
 ecall
 544:	00000073          	ecall
 ret
 548:	00008067          	ret

000000000000054c <exit>:
.global exit
exit:
 li a7, SYS_exit
 54c:	00200893          	li	a7,2
 ecall
 550:	00000073          	ecall
 ret
 554:	00008067          	ret

0000000000000558 <wait>:
.global wait
wait:
 li a7, SYS_wait
 558:	00300893          	li	a7,3
 ecall
 55c:	00000073          	ecall
 ret
 560:	00008067          	ret

0000000000000564 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 564:	00400893          	li	a7,4
 ecall
 568:	00000073          	ecall
 ret
 56c:	00008067          	ret

0000000000000570 <read>:
.global read
read:
 li a7, SYS_read
 570:	00500893          	li	a7,5
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <write>:
.global write
write:
 li a7, SYS_write
 57c:	01000893          	li	a7,16
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <close>:
.global close
close:
 li a7, SYS_close
 588:	01500893          	li	a7,21
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <kill>:
.global kill
kill:
 li a7, SYS_kill
 594:	00600893          	li	a7,6
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <exec>:
.global exec
exec:
 li a7, SYS_exec
 5a0:	00700893          	li	a7,7
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <open>:
.global open
open:
 li a7, SYS_open
 5ac:	00f00893          	li	a7,15
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 5b8:	01100893          	li	a7,17
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 5c4:	01200893          	li	a7,18
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 5d0:	00800893          	li	a7,8
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <link>:
.global link
link:
 li a7, SYS_link
 5dc:	01300893          	li	a7,19
 ecall
 5e0:	00000073          	ecall
 ret
 5e4:	00008067          	ret

00000000000005e8 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 5e8:	01400893          	li	a7,20
 ecall
 5ec:	00000073          	ecall
 ret
 5f0:	00008067          	ret

00000000000005f4 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 5f4:	00900893          	li	a7,9
 ecall
 5f8:	00000073          	ecall
 ret
 5fc:	00008067          	ret

0000000000000600 <dup>:
.global dup
dup:
 li a7, SYS_dup
 600:	00a00893          	li	a7,10
 ecall
 604:	00000073          	ecall
 ret
 608:	00008067          	ret

000000000000060c <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 60c:	00b00893          	li	a7,11
 ecall
 610:	00000073          	ecall
 ret
 614:	00008067          	ret

0000000000000618 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 618:	00c00893          	li	a7,12
 ecall
 61c:	00000073          	ecall
 ret
 620:	00008067          	ret

0000000000000624 <pause>:
.global pause
pause:
 li a7, SYS_pause
 624:	00d00893          	li	a7,13
 ecall
 628:	00000073          	ecall
 ret
 62c:	00008067          	ret

0000000000000630 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 630:	00e00893          	li	a7,14
 ecall
 634:	00000073          	ecall
 ret
 638:	00008067          	ret

000000000000063c <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 63c:	00001617          	auipc	a2,0x1
 640:	9d462603          	lw	a2,-1580(a2) # 1010 <putc_n>
 644:	00c04463          	bgtz	a2,64c <putc_flush+0x10>
 648:	00008067          	ret
{
 64c:	ff010113          	addi	sp,sp,-16
 650:	00113423          	sd	ra,8(sp)
 654:	00813023          	sd	s0,0(sp)
 658:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 65c:	00001597          	auipc	a1,0x1
 660:	bbc58593          	addi	a1,a1,-1092 # 1218 <putc_buf>
 664:	00001517          	auipc	a0,0x1
 668:	99c52503          	lw	a0,-1636(a0) # 1000 <putc_fd>
 66c:	f11ff0ef          	jal	57c <write>
    putc_n = 0;
 670:	00001797          	auipc	a5,0x1
 674:	9a07a023          	sw	zero,-1632(a5) # 1010 <putc_n>
  }
}
 678:	00813083          	ld	ra,8(sp)
 67c:	00013403          	ld	s0,0(sp)
 680:	01010113          	addi	sp,sp,16
 684:	00008067          	ret

0000000000000688 <putc>:

static void
putc(int fd, char c)
{
 688:	fe010113          	addi	sp,sp,-32
 68c:	00113c23          	sd	ra,24(sp)
 690:	00813823          	sd	s0,16(sp)
 694:	00913423          	sd	s1,8(sp)
 698:	02010413          	addi	s0,sp,32
 69c:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 6a0:	00001797          	auipc	a5,0x1
 6a4:	9607a783          	lw	a5,-1696(a5) # 1000 <putc_fd>
 6a8:	04a79663          	bne	a5,a0,6f4 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 6ac:	00001717          	auipc	a4,0x1
 6b0:	96470713          	addi	a4,a4,-1692 # 1010 <putc_n>
 6b4:	00072683          	lw	a3,0(a4)
 6b8:	0016879b          	addiw	a5,a3,1
 6bc:	00f72023          	sw	a5,0(a4)
 6c0:	00001717          	auipc	a4,0x1
 6c4:	b5870713          	addi	a4,a4,-1192 # 1218 <putc_buf>
 6c8:	00d70733          	add	a4,a4,a3
 6cc:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 6d0:	ff648493          	addi	s1,s1,-10
 6d4:	02048e63          	beqz	s1,710 <putc+0x88>
 6d8:	f8078793          	addi	a5,a5,-128
 6dc:	02078a63          	beqz	a5,710 <putc+0x88>
    putc_flush();
}
 6e0:	01813083          	ld	ra,24(sp)
 6e4:	01013403          	ld	s0,16(sp)
 6e8:	00813483          	ld	s1,8(sp)
 6ec:	02010113          	addi	sp,sp,32
 6f0:	00008067          	ret
 6f4:	01213023          	sd	s2,0(sp)
 6f8:	00050913          	mv	s2,a0
    putc_flush();
 6fc:	f41ff0ef          	jal	63c <putc_flush>
    putc_fd = fd;
 700:	00001797          	auipc	a5,0x1
 704:	9127a023          	sw	s2,-1792(a5) # 1000 <putc_fd>
 708:	00013903          	ld	s2,0(sp)
 70c:	fa1ff06f          	j	6ac <putc+0x24>
    putc_flush();
 710:	f2dff0ef          	jal	63c <putc_flush>
}
 714:	fcdff06f          	j	6e0 <putc+0x58>

0000000000000718 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 718:	fb010113          	addi	sp,sp,-80
 71c:	04113423          	sd	ra,72(sp)
 720:	04813023          	sd	s0,64(sp)
 724:	03213823          	sd	s2,48(sp)
 728:	03313423          	sd	s3,40(sp)
 72c:	05010413          	addi	s0,sp,80
 730:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 734:	0a068e63          	beqz	a3,7f0 <printint+0xd8>
 738:	0a05dc63          	bgez	a1,7f0 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 73c:	40b005b3          	neg	a1,a1
    neg = 1;
 740:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 744:	fb840993          	addi	s3,s0,-72
  neg = 0;
 748:	00098693          	mv	a3,s3
  i = 0;
 74c:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 750:	00000817          	auipc	a6,0x0
 754:	7f080813          	addi	a6,a6,2032 # f40 <digits>
 758:	00070893          	mv	a7,a4
 75c:	0017051b          	addiw	a0,a4,1
 760:	00050713          	mv	a4,a0
 764:	02c5f7b3          	remu	a5,a1,a2
 768:	00f807b3          	add	a5,a6,a5
 76c:	0007c783          	lbu	a5,0(a5)
 770:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 774:	00058793          	mv	a5,a1
 778:	02c5d5b3          	divu	a1,a1,a2
 77c:	00168693          	addi	a3,a3,1
 780:	fcc7fce3          	bgeu	a5,a2,758 <printint+0x40>
  if (neg)
 784:	00030c63          	beqz	t1,79c <printint+0x84>
    buf[i++] = '-';
 788:	fd050793          	addi	a5,a0,-48
 78c:	00878533          	add	a0,a5,s0
 790:	02d00793          	li	a5,45
 794:	fef50423          	sb	a5,-24(a0)
 798:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 79c:	02e05e63          	blez	a4,7d8 <printint+0xc0>
 7a0:	02913c23          	sd	s1,56(sp)
 7a4:	fff7071b          	addiw	a4,a4,-1
 7a8:	00e984b3          	add	s1,s3,a4
 7ac:	fff98993          	addi	s3,s3,-1
 7b0:	00e989b3          	add	s3,s3,a4
 7b4:	02071713          	slli	a4,a4,0x20
 7b8:	02075713          	srli	a4,a4,0x20
 7bc:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 7c0:	0004c583          	lbu	a1,0(s1)
 7c4:	00090513          	mv	a0,s2
 7c8:	ec1ff0ef          	jal	688 <putc>
  while (--i >= 0)
 7cc:	fff48493          	addi	s1,s1,-1
 7d0:	ff3498e3          	bne	s1,s3,7c0 <printint+0xa8>
 7d4:	03813483          	ld	s1,56(sp)
}
 7d8:	04813083          	ld	ra,72(sp)
 7dc:	04013403          	ld	s0,64(sp)
 7e0:	03013903          	ld	s2,48(sp)
 7e4:	02813983          	ld	s3,40(sp)
 7e8:	05010113          	addi	sp,sp,80
 7ec:	00008067          	ret
  neg = 0;
 7f0:	00000313          	li	t1,0
 7f4:	f51ff06f          	j	744 <printint+0x2c>

00000000000007f8 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 7f8:	fa010113          	addi	sp,sp,-96
 7fc:	04113c23          	sd	ra,88(sp)
 800:	04813823          	sd	s0,80(sp)
 804:	04913423          	sd	s1,72(sp)
 808:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 80c:	0005c483          	lbu	s1,0(a1)
 810:	32048263          	beqz	s1,b34 <vprintf+0x33c>
 814:	05213023          	sd	s2,64(sp)
 818:	03313c23          	sd	s3,56(sp)
 81c:	03413823          	sd	s4,48(sp)
 820:	03513423          	sd	s5,40(sp)
 824:	03613023          	sd	s6,32(sp)
 828:	01713c23          	sd	s7,24(sp)
 82c:	01813823          	sd	s8,16(sp)
 830:	00050b13          	mv	s6,a0
 834:	00058a13          	mv	s4,a1
 838:	00060b93          	mv	s7,a2
  state = 0;
 83c:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 840:	00000913          	li	s2,0
 844:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 848:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 84c:	06400c13          	li	s8,100
 850:	0300006f          	j	880 <vprintf+0x88>
        putc(fd, c0);
 854:	00048593          	mv	a1,s1
 858:	000b0513          	mv	a0,s6
 85c:	e2dff0ef          	jal	688 <putc>
 860:	0080006f          	j	868 <vprintf+0x70>
    else if (state == '%')
 864:	03598863          	beq	s3,s5,894 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 868:	0019079b          	addiw	a5,s2,1
 86c:	00078913          	mv	s2,a5
 870:	00078713          	mv	a4,a5
 874:	00fa07b3          	add	a5,s4,a5
 878:	0007c483          	lbu	s1,0(a5)
 87c:	28048e63          	beqz	s1,b18 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 880:	0004879b          	sext.w	a5,s1
    if (state == 0)
 884:	fe0990e3          	bnez	s3,864 <vprintf+0x6c>
      if (c0 == '%')
 888:	fd5796e3          	bne	a5,s5,854 <vprintf+0x5c>
        state = '%';
 88c:	00078993          	mv	s3,a5
 890:	fd9ff06f          	j	868 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 894:	00ea06b3          	add	a3,s4,a4
 898:	0016c603          	lbu	a2,1(a3)
      if (c1)
 89c:	2a060663          	beqz	a2,b48 <vprintf+0x350>
      if (c0 == 'd')
 8a0:	05878063          	beq	a5,s8,8e0 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 8a4:	f9478693          	addi	a3,a5,-108
 8a8:	0016b693          	seqz	a3,a3
 8ac:	f9c60593          	addi	a1,a2,-100
 8b0:	04059a63          	bnez	a1,904 <vprintf+0x10c>
 8b4:	04068863          	beqz	a3,904 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 8b8:	008b8493          	addi	s1,s7,8
 8bc:	00100693          	li	a3,1
 8c0:	00a00613          	li	a2,10
 8c4:	000bb583          	ld	a1,0(s7)
 8c8:	000b0513          	mv	a0,s6
 8cc:	e4dff0ef          	jal	718 <printint>
        i += 1;
 8d0:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 8d4:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 8d8:	00000993          	li	s3,0
 8dc:	f8dff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 8e0:	008b8493          	addi	s1,s7,8
 8e4:	00100693          	li	a3,1
 8e8:	00a00613          	li	a2,10
 8ec:	000ba583          	lw	a1,0(s7)
 8f0:	000b0513          	mv	a0,s6
 8f4:	e25ff0ef          	jal	718 <printint>
 8f8:	00048b93          	mv	s7,s1
      state = 0;
 8fc:	00000993          	li	s3,0
 900:	f69ff06f          	j	868 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 904:	00ea0733          	add	a4,s4,a4
 908:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 90c:	f9460713          	addi	a4,a2,-108
 910:	00173713          	seqz	a4,a4
 914:	00e6f733          	and	a4,a3,a4
 918:	f9c58513          	addi	a0,a1,-100
 91c:	24051263          	bnez	a0,b60 <vprintf+0x368>
 920:	24070063          	beqz	a4,b60 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 924:	008b8493          	addi	s1,s7,8
 928:	00100693          	li	a3,1
 92c:	00a00613          	li	a2,10
 930:	000bb583          	ld	a1,0(s7)
 934:	000b0513          	mv	a0,s6
 938:	de1ff0ef          	jal	718 <printint>
        i += 2;
 93c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 940:	00048b93          	mv	s7,s1
      state = 0;
 944:	00000993          	li	s3,0
        i += 2;
 948:	f21ff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 94c:	008b8493          	addi	s1,s7,8
 950:	00000693          	li	a3,0
 954:	00a00613          	li	a2,10
 958:	000be583          	lwu	a1,0(s7)
 95c:	000b0513          	mv	a0,s6
 960:	db9ff0ef          	jal	718 <printint>
 964:	00048b93          	mv	s7,s1
      state = 0;
 968:	00000993          	li	s3,0
 96c:	efdff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 970:	008b8493          	addi	s1,s7,8
 974:	00000693          	li	a3,0
 978:	00a00613          	li	a2,10
 97c:	000bb583          	ld	a1,0(s7)
 980:	000b0513          	mv	a0,s6
 984:	d95ff0ef          	jal	718 <printint>
        i += 1;
 988:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 98c:	00048b93          	mv	s7,s1
      state = 0;
 990:	00000993          	li	s3,0
 994:	ed5ff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 998:	008b8493          	addi	s1,s7,8
 99c:	00000693          	li	a3,0
 9a0:	00a00613          	li	a2,10
 9a4:	000bb583          	ld	a1,0(s7)
 9a8:	000b0513          	mv	a0,s6
 9ac:	d6dff0ef          	jal	718 <printint>
        i += 2;
 9b0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 9b4:	00048b93          	mv	s7,s1
      state = 0;
 9b8:	00000993          	li	s3,0
        i += 2;
 9bc:	eadff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 9c0:	008b8493          	addi	s1,s7,8
 9c4:	00000693          	li	a3,0
 9c8:	01000613          	li	a2,16
 9cc:	000be583          	lwu	a1,0(s7)
 9d0:	000b0513          	mv	a0,s6
 9d4:	d45ff0ef          	jal	718 <printint>
 9d8:	00048b93          	mv	s7,s1
      state = 0;
 9dc:	00000993          	li	s3,0
 9e0:	e89ff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9e4:	008b8493          	addi	s1,s7,8
 9e8:	00000693          	li	a3,0
 9ec:	01000613          	li	a2,16
 9f0:	000bb583          	ld	a1,0(s7)
 9f4:	000b0513          	mv	a0,s6
 9f8:	d21ff0ef          	jal	718 <printint>
        i += 1;
 9fc:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 a00:	00048b93          	mv	s7,s1
      state = 0;
 a04:	00000993          	li	s3,0
 a08:	e61ff06f          	j	868 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a0c:	008b8493          	addi	s1,s7,8
 a10:	00000693          	li	a3,0
 a14:	01000613          	li	a2,16
 a18:	000bb583          	ld	a1,0(s7)
 a1c:	000b0513          	mv	a0,s6
 a20:	cf9ff0ef          	jal	718 <printint>
        i += 2;
 a24:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 a28:	00048b93          	mv	s7,s1
      state = 0;
 a2c:	00000993          	li	s3,0
        i += 2;
 a30:	e39ff06f          	j	868 <vprintf+0x70>
 a34:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 a38:	008b8793          	addi	a5,s7,8
 a3c:	00078c93          	mv	s9,a5
 a40:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 a44:	03000593          	li	a1,48
 a48:	000b0513          	mv	a0,s6
 a4c:	c3dff0ef          	jal	688 <putc>
  putc(fd, 'x');
 a50:	07800593          	li	a1,120
 a54:	000b0513          	mv	a0,s6
 a58:	c31ff0ef          	jal	688 <putc>
 a5c:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a60:	00000b97          	auipc	s7,0x0
 a64:	4e0b8b93          	addi	s7,s7,1248 # f40 <digits>
 a68:	03c9d793          	srli	a5,s3,0x3c
 a6c:	00fb87b3          	add	a5,s7,a5
 a70:	0007c583          	lbu	a1,0(a5)
 a74:	000b0513          	mv	a0,s6
 a78:	c11ff0ef          	jal	688 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a7c:	00499993          	slli	s3,s3,0x4
 a80:	fff4849b          	addiw	s1,s1,-1
 a84:	fe0492e3          	bnez	s1,a68 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a88:	000c8b93          	mv	s7,s9
      state = 0;
 a8c:	00000993          	li	s3,0
 a90:	00813c83          	ld	s9,8(sp)
 a94:	dd5ff06f          	j	868 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a98:	008b8493          	addi	s1,s7,8
 a9c:	000bc583          	lbu	a1,0(s7)
 aa0:	000b0513          	mv	a0,s6
 aa4:	be5ff0ef          	jal	688 <putc>
 aa8:	00048b93          	mv	s7,s1
      state = 0;
 aac:	00000993          	li	s3,0
 ab0:	db9ff06f          	j	868 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 ab4:	008b8993          	addi	s3,s7,8
 ab8:	000bb483          	ld	s1,0(s7)
 abc:	02048663          	beqz	s1,ae8 <vprintf+0x2f0>
        for (; *s; s++)
 ac0:	0004c583          	lbu	a1,0(s1)
 ac4:	04058463          	beqz	a1,b0c <vprintf+0x314>
          putc(fd, *s);
 ac8:	000b0513          	mv	a0,s6
 acc:	bbdff0ef          	jal	688 <putc>
        for (; *s; s++)
 ad0:	00148493          	addi	s1,s1,1
 ad4:	0004c583          	lbu	a1,0(s1)
 ad8:	fe0598e3          	bnez	a1,ac8 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 adc:	00098b93          	mv	s7,s3
      state = 0;
 ae0:	00000993          	li	s3,0
 ae4:	d85ff06f          	j	868 <vprintf+0x70>
          s = "(null)";
 ae8:	00000497          	auipc	s1,0x0
 aec:	45048493          	addi	s1,s1,1104 # f38 <malloc+0x208>
        for (; *s; s++)
 af0:	02800593          	li	a1,40
 af4:	fd5ff06f          	j	ac8 <vprintf+0x2d0>
        putc(fd, '%');
 af8:	00078593          	mv	a1,a5
 afc:	000b0513          	mv	a0,s6
 b00:	b89ff0ef          	jal	688 <putc>
      state = 0;
 b04:	00000993          	li	s3,0
 b08:	d61ff06f          	j	868 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b0c:	00098b93          	mv	s7,s3
      state = 0;
 b10:	00000993          	li	s3,0
 b14:	d55ff06f          	j	868 <vprintf+0x70>
 b18:	04013903          	ld	s2,64(sp)
 b1c:	03813983          	ld	s3,56(sp)
 b20:	03013a03          	ld	s4,48(sp)
 b24:	02813a83          	ld	s5,40(sp)
 b28:	02013b03          	ld	s6,32(sp)
 b2c:	01813b83          	ld	s7,24(sp)
 b30:	01013c03          	ld	s8,16(sp)
    }
  }
}
 b34:	05813083          	ld	ra,88(sp)
 b38:	05013403          	ld	s0,80(sp)
 b3c:	04813483          	ld	s1,72(sp)
 b40:	06010113          	addi	sp,sp,96
 b44:	00008067          	ret
      if (c0 == 'd')
 b48:	06400713          	li	a4,100
 b4c:	d8e78ae3          	beq	a5,a4,8e0 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 b50:	f9478693          	addi	a3,a5,-108
 b54:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 b58:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 b5c:	00000713          	li	a4,0
      else if (c0 == 'u')
 b60:	07500513          	li	a0,117
 b64:	dea784e3          	beq	a5,a0,94c <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b68:	f8b60513          	addi	a0,a2,-117
 b6c:	00051463          	bnez	a0,b74 <vprintf+0x37c>
 b70:	e00690e3          	bnez	a3,970 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 b74:	f8b58513          	addi	a0,a1,-117
 b78:	00051463          	bnez	a0,b80 <vprintf+0x388>
 b7c:	e0071ee3          	bnez	a4,998 <vprintf+0x1a0>
      else if (c0 == 'x')
 b80:	07800513          	li	a0,120
 b84:	e2a78ee3          	beq	a5,a0,9c0 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b88:	f8860613          	addi	a2,a2,-120
 b8c:	00061463          	bnez	a2,b94 <vprintf+0x39c>
 b90:	e4069ae3          	bnez	a3,9e4 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b94:	f8858593          	addi	a1,a1,-120
 b98:	00059463          	bnez	a1,ba0 <vprintf+0x3a8>
 b9c:	e60718e3          	bnez	a4,a0c <vprintf+0x214>
      else if (c0 == 'p')
 ba0:	07000713          	li	a4,112
 ba4:	e8e788e3          	beq	a5,a4,a34 <vprintf+0x23c>
      else if (c0 == 'c')
 ba8:	06300713          	li	a4,99
 bac:	eee786e3          	beq	a5,a4,a98 <vprintf+0x2a0>
      else if (c0 == 's')
 bb0:	07300713          	li	a4,115
 bb4:	f0e780e3          	beq	a5,a4,ab4 <vprintf+0x2bc>
      else if (c0 == '%')
 bb8:	02500713          	li	a4,37
 bbc:	f2e78ee3          	beq	a5,a4,af8 <vprintf+0x300>
        putc(fd, '%');
 bc0:	02500593          	li	a1,37
 bc4:	000b0513          	mv	a0,s6
 bc8:	ac1ff0ef          	jal	688 <putc>
        putc(fd, c0);
 bcc:	00048593          	mv	a1,s1
 bd0:	000b0513          	mv	a0,s6
 bd4:	ab5ff0ef          	jal	688 <putc>
      state = 0;
 bd8:	00000993          	li	s3,0
 bdc:	c8dff06f          	j	868 <vprintf+0x70>

0000000000000be0 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 be0:	fb010113          	addi	sp,sp,-80
 be4:	00113c23          	sd	ra,24(sp)
 be8:	00813823          	sd	s0,16(sp)
 bec:	02010413          	addi	s0,sp,32
 bf0:	00c43023          	sd	a2,0(s0)
 bf4:	00d43423          	sd	a3,8(s0)
 bf8:	00e43823          	sd	a4,16(s0)
 bfc:	00f43c23          	sd	a5,24(s0)
 c00:	03043023          	sd	a6,32(s0)
 c04:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 c08:	00040613          	mv	a2,s0
 c0c:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 c10:	be9ff0ef          	jal	7f8 <vprintf>
}
 c14:	01813083          	ld	ra,24(sp)
 c18:	01013403          	ld	s0,16(sp)
 c1c:	05010113          	addi	sp,sp,80
 c20:	00008067          	ret

0000000000000c24 <printf>:

void printf(const char *fmt, ...)
{
 c24:	fa010113          	addi	sp,sp,-96
 c28:	00113c23          	sd	ra,24(sp)
 c2c:	00813823          	sd	s0,16(sp)
 c30:	02010413          	addi	s0,sp,32
 c34:	00b43423          	sd	a1,8(s0)
 c38:	00c43823          	sd	a2,16(s0)
 c3c:	00d43c23          	sd	a3,24(s0)
 c40:	02e43023          	sd	a4,32(s0)
 c44:	02f43423          	sd	a5,40(s0)
 c48:	03043823          	sd	a6,48(s0)
 c4c:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 c50:	00840613          	addi	a2,s0,8
 c54:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 c58:	00050593          	mv	a1,a0
 c5c:	00100513          	li	a0,1
 c60:	b99ff0ef          	jal	7f8 <vprintf>
  putc_flush();
 c64:	9d9ff0ef          	jal	63c <putc_flush>
}
 c68:	01813083          	ld	ra,24(sp)
 c6c:	01013403          	ld	s0,16(sp)
 c70:	06010113          	addi	sp,sp,96
 c74:	00008067          	ret

0000000000000c78 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c78:	ff010113          	addi	sp,sp,-16
 c7c:	00113423          	sd	ra,8(sp)
 c80:	00813023          	sd	s0,0(sp)
 c84:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c88:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c8c:	00000797          	auipc	a5,0x0
 c90:	38c7b783          	ld	a5,908(a5) # 1018 <freep>
 c94:	0140006f          	j	ca8 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c98:	0007b703          	ld	a4,0(a5)
 c9c:	00e7e463          	bltu	a5,a4,ca4 <free+0x2c>
 ca0:	00e6ec63          	bltu	a3,a4,cb8 <free+0x40>
{
 ca4:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 ca8:	fed7f8e3          	bgeu	a5,a3,c98 <free+0x20>
 cac:	0007b703          	ld	a4,0(a5)
 cb0:	00e6e463          	bltu	a3,a4,cb8 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 cb4:	fee7e8e3          	bltu	a5,a4,ca4 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 cb8:	ff852583          	lw	a1,-8(a0)
 cbc:	0007b603          	ld	a2,0(a5)
 cc0:	02059813          	slli	a6,a1,0x20
 cc4:	01c85713          	srli	a4,a6,0x1c
 cc8:	00e68733          	add	a4,a3,a4
 ccc:	02e60c63          	beq	a2,a4,d04 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 cd0:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 cd4:	0087a603          	lw	a2,8(a5)
 cd8:	02061593          	slli	a1,a2,0x20
 cdc:	01c5d713          	srli	a4,a1,0x1c
 ce0:	00e78733          	add	a4,a5,a4
 ce4:	02e68c63          	beq	a3,a4,d1c <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 ce8:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 cec:	00000717          	auipc	a4,0x0
 cf0:	32f73623          	sd	a5,812(a4) # 1018 <freep>
}
 cf4:	00813083          	ld	ra,8(sp)
 cf8:	00013403          	ld	s0,0(sp)
 cfc:	01010113          	addi	sp,sp,16
 d00:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 d04:	00862703          	lw	a4,8(a2)
 d08:	00b7073b          	addw	a4,a4,a1
 d0c:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 d10:	0007b703          	ld	a4,0(a5)
 d14:	00073603          	ld	a2,0(a4)
 d18:	fb9ff06f          	j	cd0 <free+0x58>
    p->s.size += bp->s.size;
 d1c:	ff852703          	lw	a4,-8(a0)
 d20:	00c7073b          	addw	a4,a4,a2
 d24:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 d28:	ff053683          	ld	a3,-16(a0)
 d2c:	fbdff06f          	j	ce8 <free+0x70>

0000000000000d30 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 d30:	fc010113          	addi	sp,sp,-64
 d34:	02113c23          	sd	ra,56(sp)
 d38:	02813823          	sd	s0,48(sp)
 d3c:	03213023          	sd	s2,32(sp)
 d40:	01313c23          	sd	s3,24(sp)
 d44:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 d48:	02051993          	slli	s3,a0,0x20
 d4c:	0209d993          	srli	s3,s3,0x20
 d50:	00f98993          	addi	s3,s3,15
 d54:	0049d993          	srli	s3,s3,0x4
 d58:	0019899b          	addiw	s3,s3,1
 d5c:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d60:	00000517          	auipc	a0,0x0
 d64:	2b853503          	ld	a0,696(a0) # 1018 <freep>
 d68:	04050463          	beqz	a0,db0 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d6c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d70:	0087a703          	lw	a4,8(a5)
 d74:	0d377a63          	bgeu	a4,s3,e48 <malloc+0x118>
 d78:	02913423          	sd	s1,40(sp)
 d7c:	01413823          	sd	s4,16(sp)
 d80:	01513423          	sd	s5,8(sp)
 d84:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d88:	00098a13          	mv	s4,s3
 d8c:	00001737          	lui	a4,0x1
 d90:	00e9f463          	bgeu	s3,a4,d98 <malloc+0x68>
 d94:	00001a37          	lui	s4,0x1
 d98:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d9c:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 da0:	00000497          	auipc	s1,0x0
 da4:	27848493          	addi	s1,s1,632 # 1018 <freep>
  if(p == SBRK_ERROR)
 da8:	fff00a93          	li	s5,-1
 dac:	05c0006f          	j	e08 <malloc+0xd8>
 db0:	02913423          	sd	s1,40(sp)
 db4:	01413823          	sd	s4,16(sp)
 db8:	01513423          	sd	s5,8(sp)
 dbc:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 dc0:	00000797          	auipc	a5,0x0
 dc4:	4d878793          	addi	a5,a5,1240 # 1298 <base>
 dc8:	00000717          	auipc	a4,0x0
 dcc:	24f73823          	sd	a5,592(a4) # 1018 <freep>
 dd0:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 dd4:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 dd8:	fb1ff06f          	j	d88 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 ddc:	0007b703          	ld	a4,0(a5)
 de0:	00e53023          	sd	a4,0(a0)
 de4:	0800006f          	j	e64 <malloc+0x134>
  hp->s.size = nu;
 de8:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 dec:	01050513          	addi	a0,a0,16
 df0:	e89ff0ef          	jal	c78 <free>
  return freep;
 df4:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 df8:	08050863          	beqz	a0,e88 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 dfc:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 e00:	0087a703          	lw	a4,8(a5)
 e04:	03277a63          	bgeu	a4,s2,e38 <malloc+0x108>
    if(p == freep)
 e08:	0004b703          	ld	a4,0(s1)
 e0c:	00078513          	mv	a0,a5
 e10:	fef716e3          	bne	a4,a5,dfc <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 e14:	000a0513          	mv	a0,s4
 e18:	ed8ff0ef          	jal	4f0 <sbrk>
  if(p == SBRK_ERROR)
 e1c:	fd5516e3          	bne	a0,s5,de8 <malloc+0xb8>
        return 0;
 e20:	00000513          	li	a0,0
 e24:	02813483          	ld	s1,40(sp)
 e28:	01013a03          	ld	s4,16(sp)
 e2c:	00813a83          	ld	s5,8(sp)
 e30:	00013b03          	ld	s6,0(sp)
 e34:	03c0006f          	j	e70 <malloc+0x140>
 e38:	02813483          	ld	s1,40(sp)
 e3c:	01013a03          	ld	s4,16(sp)
 e40:	00813a83          	ld	s5,8(sp)
 e44:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 e48:	f8e90ae3          	beq	s2,a4,ddc <malloc+0xac>
        p->s.size -= nunits;
 e4c:	4137073b          	subw	a4,a4,s3
 e50:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 e54:	02071693          	slli	a3,a4,0x20
 e58:	01c6d713          	srli	a4,a3,0x1c
 e5c:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e60:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e64:	00000717          	auipc	a4,0x0
 e68:	1aa73a23          	sd	a0,436(a4) # 1018 <freep>
      return (void*)(p + 1);
 e6c:	01078513          	addi	a0,a5,16
  }
}
 e70:	03813083          	ld	ra,56(sp)
 e74:	03013403          	ld	s0,48(sp)
 e78:	02013903          	ld	s2,32(sp)
 e7c:	01813983          	ld	s3,24(sp)
 e80:	04010113          	addi	sp,sp,64
 e84:	00008067          	ret
 e88:	02813483          	ld	s1,40(sp)
 e8c:	01013a03          	ld	s4,16(sp)
 e90:	00813a83          	ld	s5,8(sp)
 e94:	00013b03          	ld	s6,0(sp)
 e98:	fd9ff06f          	j	e70 <malloc+0x140>
