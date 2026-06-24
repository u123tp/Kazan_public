
user/_init:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:

char *argv[] = { "sh", 0 };

int
main(void)
{
   0:	fe010113          	addi	sp,sp,-32
   4:	00113c23          	sd	ra,24(sp)
   8:	00813823          	sd	s0,16(sp)
   c:	00913423          	sd	s1,8(sp)
  10:	01213023          	sd	s2,0(sp)
  14:	02010413          	addi	s0,sp,32
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
  18:	00200593          	li	a1,2
  1c:	00001517          	auipc	a0,0x1
  20:	e8450513          	addi	a0,a0,-380 # ea0 <malloc+0x178>
  24:	580000ef          	jal	5a4 <open>
  28:	04054c63          	bltz	a0,80 <main+0x80>
    mknod("console", CONSOLE, 0);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  2c:	00000513          	li	a0,0
  30:	5c8000ef          	jal	5f8 <dup>
  dup(0);  // stderr
  34:	00000513          	li	a0,0
  38:	5c0000ef          	jal	5f8 <dup>

  for(;;){
    printf("init: starting sh\n");
  3c:	00001917          	auipc	s2,0x1
  40:	e6c90913          	addi	s2,s2,-404 # ea8 <malloc+0x180>
  44:	00090513          	mv	a0,s2
  48:	3d5000ef          	jal	c1c <printf>
    pid = fork();
  4c:	4ec000ef          	jal	538 <fork>
  50:	00050493          	mv	s1,a0
    if(pid < 0){
  54:	04054a63          	bltz	a0,a8 <main+0xa8>
      printf("init: fork failed\n");
      exit(1);
    }
    if(pid == 0){
  58:	06050263          	beqz	a0,bc <main+0xbc>
    }

    for(;;){
      // this call to wait() returns if the shell exits,
      // or if a parentless process exits.
      wpid = wait((int *) 0);
  5c:	00000513          	li	a0,0
  60:	4f0000ef          	jal	550 <wait>
      if(wpid == pid){
  64:	fea480e3          	beq	s1,a0,44 <main+0x44>
        // the shell exited; restart it.
        break;
      } else if(wpid < 0){
  68:	fe055ae3          	bgez	a0,5c <main+0x5c>
        printf("init: wait returned an error\n");
  6c:	00001517          	auipc	a0,0x1
  70:	e8c50513          	addi	a0,a0,-372 # ef8 <malloc+0x1d0>
  74:	3a9000ef          	jal	c1c <printf>
        exit(1);
  78:	00100513          	li	a0,1
  7c:	4c8000ef          	jal	544 <exit>
    mknod("console", CONSOLE, 0);
  80:	00000613          	li	a2,0
  84:	00100593          	li	a1,1
  88:	00001517          	auipc	a0,0x1
  8c:	e1850513          	addi	a0,a0,-488 # ea0 <malloc+0x178>
  90:	520000ef          	jal	5b0 <mknod>
    open("console", O_RDWR);
  94:	00200593          	li	a1,2
  98:	00001517          	auipc	a0,0x1
  9c:	e0850513          	addi	a0,a0,-504 # ea0 <malloc+0x178>
  a0:	504000ef          	jal	5a4 <open>
  a4:	f89ff06f          	j	2c <main+0x2c>
      printf("init: fork failed\n");
  a8:	00001517          	auipc	a0,0x1
  ac:	e1850513          	addi	a0,a0,-488 # ec0 <malloc+0x198>
  b0:	36d000ef          	jal	c1c <printf>
      exit(1);
  b4:	00100513          	li	a0,1
  b8:	48c000ef          	jal	544 <exit>
      exec("sh", argv);
  bc:	00001597          	auipc	a1,0x1
  c0:	f5458593          	addi	a1,a1,-172 # 1010 <argv>
  c4:	00001517          	auipc	a0,0x1
  c8:	e1450513          	addi	a0,a0,-492 # ed8 <malloc+0x1b0>
  cc:	4cc000ef          	jal	598 <exec>
      printf("init: exec sh failed\n");
  d0:	00001517          	auipc	a0,0x1
  d4:	e1050513          	addi	a0,a0,-496 # ee0 <malloc+0x1b8>
  d8:	345000ef          	jal	c1c <printf>
      exit(1);
  dc:	00100513          	li	a0,1
  e0:	464000ef          	jal	544 <exit>

00000000000000e4 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  e4:	ff010113          	addi	sp,sp,-16
  e8:	00113423          	sd	ra,8(sp)
  ec:	00813023          	sd	s0,0(sp)
  f0:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  f4:	f0dff0ef          	jal	0 <main>
  exit(r);
  f8:	44c000ef          	jal	544 <exit>

00000000000000fc <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  fc:	ff010113          	addi	sp,sp,-16
 100:	00113423          	sd	ra,8(sp)
 104:	00813023          	sd	s0,0(sp)
 108:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 10c:	00050793          	mv	a5,a0
 110:	00158593          	addi	a1,a1,1
 114:	00178793          	addi	a5,a5,1
 118:	fff5c703          	lbu	a4,-1(a1)
 11c:	fee78fa3          	sb	a4,-1(a5)
 120:	fe0718e3          	bnez	a4,110 <strcpy+0x14>
    ;
  return os;
}
 124:	00813083          	ld	ra,8(sp)
 128:	00013403          	ld	s0,0(sp)
 12c:	01010113          	addi	sp,sp,16
 130:	00008067          	ret

0000000000000134 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 134:	ff010113          	addi	sp,sp,-16
 138:	00113423          	sd	ra,8(sp)
 13c:	00813023          	sd	s0,0(sp)
 140:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 144:	00054783          	lbu	a5,0(a0)
 148:	00078e63          	beqz	a5,164 <strcmp+0x30>
 14c:	0005c703          	lbu	a4,0(a1)
 150:	00f71a63          	bne	a4,a5,164 <strcmp+0x30>
    p++, q++;
 154:	00150513          	addi	a0,a0,1
 158:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 15c:	00054783          	lbu	a5,0(a0)
 160:	fe0796e3          	bnez	a5,14c <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 164:	0005c503          	lbu	a0,0(a1)
}
 168:	40a7853b          	subw	a0,a5,a0
 16c:	00813083          	ld	ra,8(sp)
 170:	00013403          	ld	s0,0(sp)
 174:	01010113          	addi	sp,sp,16
 178:	00008067          	ret

000000000000017c <strlen>:

uint
strlen(const char *s)
{
 17c:	ff010113          	addi	sp,sp,-16
 180:	00113423          	sd	ra,8(sp)
 184:	00813023          	sd	s0,0(sp)
 188:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 18c:	00054783          	lbu	a5,0(a0)
 190:	02078663          	beqz	a5,1bc <strlen+0x40>
 194:	00150793          	addi	a5,a0,1
 198:	00078693          	mv	a3,a5
 19c:	00178793          	addi	a5,a5,1
 1a0:	fff7c703          	lbu	a4,-1(a5)
 1a4:	fe071ae3          	bnez	a4,198 <strlen+0x1c>
 1a8:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 1ac:	00813083          	ld	ra,8(sp)
 1b0:	00013403          	ld	s0,0(sp)
 1b4:	01010113          	addi	sp,sp,16
 1b8:	00008067          	ret
  for(n = 0; s[n]; n++)
 1bc:	00000513          	li	a0,0
 1c0:	fedff06f          	j	1ac <strlen+0x30>

00000000000001c4 <memset>:

void*
memset(void *dst, int c, uint n)
{
 1c4:	ff010113          	addi	sp,sp,-16
 1c8:	00113423          	sd	ra,8(sp)
 1cc:	00813023          	sd	s0,0(sp)
 1d0:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 1d4:	02060063          	beqz	a2,1f4 <memset+0x30>
 1d8:	00050793          	mv	a5,a0
 1dc:	02061613          	slli	a2,a2,0x20
 1e0:	02065613          	srli	a2,a2,0x20
 1e4:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 1e8:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 1ec:	00178793          	addi	a5,a5,1
 1f0:	fee79ce3          	bne	a5,a4,1e8 <memset+0x24>
  }
  return dst;
}
 1f4:	00813083          	ld	ra,8(sp)
 1f8:	00013403          	ld	s0,0(sp)
 1fc:	01010113          	addi	sp,sp,16
 200:	00008067          	ret

0000000000000204 <strchr>:

char*
strchr(const char *s, char c)
{
 204:	ff010113          	addi	sp,sp,-16
 208:	00113423          	sd	ra,8(sp)
 20c:	00813023          	sd	s0,0(sp)
 210:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 214:	00054783          	lbu	a5,0(a0)
 218:	02078463          	beqz	a5,240 <strchr+0x3c>
    if(*s == c)
 21c:	00f58a63          	beq	a1,a5,230 <strchr+0x2c>
  for(; *s; s++)
 220:	00150513          	addi	a0,a0,1
 224:	00054783          	lbu	a5,0(a0)
 228:	fe079ae3          	bnez	a5,21c <strchr+0x18>
      return (char*)s;
  return 0;
 22c:	00000513          	li	a0,0
}
 230:	00813083          	ld	ra,8(sp)
 234:	00013403          	ld	s0,0(sp)
 238:	01010113          	addi	sp,sp,16
 23c:	00008067          	ret
  return 0;
 240:	00000513          	li	a0,0
 244:	fedff06f          	j	230 <strchr+0x2c>

0000000000000248 <gets>:

char*
gets(char *buf, int max)
{
 248:	fa010113          	addi	sp,sp,-96
 24c:	04113c23          	sd	ra,88(sp)
 250:	04813823          	sd	s0,80(sp)
 254:	04913423          	sd	s1,72(sp)
 258:	05213023          	sd	s2,64(sp)
 25c:	03313c23          	sd	s3,56(sp)
 260:	03413823          	sd	s4,48(sp)
 264:	03513423          	sd	s5,40(sp)
 268:	03613023          	sd	s6,32(sp)
 26c:	01713c23          	sd	s7,24(sp)
 270:	01813823          	sd	s8,16(sp)
 274:	06010413          	addi	s0,sp,96
 278:	00050b93          	mv	s7,a0
 27c:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 280:	00050913          	mv	s2,a0
 284:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 288:	faf40b13          	addi	s6,s0,-81
 28c:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 290:	00048c13          	mv	s8,s1
 294:	0014899b          	addiw	s3,s1,1
 298:	00098493          	mv	s1,s3
 29c:	0349dc63          	bge	s3,s4,2d4 <gets+0x8c>
    cc = read(0, &c, 1);
 2a0:	000a8613          	mv	a2,s5
 2a4:	000b0593          	mv	a1,s6
 2a8:	00000513          	li	a0,0
 2ac:	2bc000ef          	jal	568 <read>
    if(cc < 1)
 2b0:	02a05263          	blez	a0,2d4 <gets+0x8c>
      break;
    buf[i++] = c;
 2b4:	faf44783          	lbu	a5,-81(s0)
 2b8:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 2bc:	00190913          	addi	s2,s2,1
 2c0:	ff678713          	addi	a4,a5,-10
 2c4:	00070663          	beqz	a4,2d0 <gets+0x88>
 2c8:	ff378793          	addi	a5,a5,-13
 2cc:	fc0792e3          	bnez	a5,290 <gets+0x48>
    buf[i++] = c;
 2d0:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 2d4:	018b8c33          	add	s8,s7,s8
 2d8:	000c0023          	sb	zero,0(s8)
  return buf;
}
 2dc:	000b8513          	mv	a0,s7
 2e0:	05813083          	ld	ra,88(sp)
 2e4:	05013403          	ld	s0,80(sp)
 2e8:	04813483          	ld	s1,72(sp)
 2ec:	04013903          	ld	s2,64(sp)
 2f0:	03813983          	ld	s3,56(sp)
 2f4:	03013a03          	ld	s4,48(sp)
 2f8:	02813a83          	ld	s5,40(sp)
 2fc:	02013b03          	ld	s6,32(sp)
 300:	01813b83          	ld	s7,24(sp)
 304:	01013c03          	ld	s8,16(sp)
 308:	06010113          	addi	sp,sp,96
 30c:	00008067          	ret

0000000000000310 <stat>:

int
stat(const char *n, struct stat *st)
{
 310:	fe010113          	addi	sp,sp,-32
 314:	00113c23          	sd	ra,24(sp)
 318:	00813823          	sd	s0,16(sp)
 31c:	01213023          	sd	s2,0(sp)
 320:	02010413          	addi	s0,sp,32
 324:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 328:	00000593          	li	a1,0
 32c:	278000ef          	jal	5a4 <open>
  if(fd < 0)
 330:	02054e63          	bltz	a0,36c <stat+0x5c>
 334:	00913423          	sd	s1,8(sp)
 338:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 33c:	00090593          	mv	a1,s2
 340:	288000ef          	jal	5c8 <fstat>
 344:	00050913          	mv	s2,a0
  close(fd);
 348:	00048513          	mv	a0,s1
 34c:	234000ef          	jal	580 <close>
  return r;
 350:	00813483          	ld	s1,8(sp)
}
 354:	00090513          	mv	a0,s2
 358:	01813083          	ld	ra,24(sp)
 35c:	01013403          	ld	s0,16(sp)
 360:	00013903          	ld	s2,0(sp)
 364:	02010113          	addi	sp,sp,32
 368:	00008067          	ret
    return -1;
 36c:	fff00793          	li	a5,-1
 370:	00078913          	mv	s2,a5
 374:	fe1ff06f          	j	354 <stat+0x44>

0000000000000378 <atoi>:

int
atoi(const char *s)
{
 378:	ff010113          	addi	sp,sp,-16
 37c:	00113423          	sd	ra,8(sp)
 380:	00813023          	sd	s0,0(sp)
 384:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 388:	00054683          	lbu	a3,0(a0)
 38c:	fd06879b          	addiw	a5,a3,-48
 390:	0ff7f793          	zext.b	a5,a5
 394:	00900613          	li	a2,9
 398:	04f66263          	bltu	a2,a5,3dc <atoi+0x64>
 39c:	00050713          	mv	a4,a0
  n = 0;
 3a0:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 3a4:	00170713          	addi	a4,a4,1
 3a8:	0025179b          	slliw	a5,a0,0x2
 3ac:	00a787bb          	addw	a5,a5,a0
 3b0:	0017979b          	slliw	a5,a5,0x1
 3b4:	00d787bb          	addw	a5,a5,a3
 3b8:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 3bc:	00074683          	lbu	a3,0(a4)
 3c0:	fd06879b          	addiw	a5,a3,-48
 3c4:	0ff7f793          	zext.b	a5,a5
 3c8:	fcf67ee3          	bgeu	a2,a5,3a4 <atoi+0x2c>
  return n;
}
 3cc:	00813083          	ld	ra,8(sp)
 3d0:	00013403          	ld	s0,0(sp)
 3d4:	01010113          	addi	sp,sp,16
 3d8:	00008067          	ret
  n = 0;
 3dc:	00000513          	li	a0,0
 3e0:	fedff06f          	j	3cc <atoi+0x54>

00000000000003e4 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 3e4:	ff010113          	addi	sp,sp,-16
 3e8:	00113423          	sd	ra,8(sp)
 3ec:	00813023          	sd	s0,0(sp)
 3f0:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 3f4:	02b57e63          	bgeu	a0,a1,430 <memmove+0x4c>
    while(n-- > 0)
 3f8:	02c05463          	blez	a2,420 <memmove+0x3c>
 3fc:	02061613          	slli	a2,a2,0x20
 400:	02065613          	srli	a2,a2,0x20
 404:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 408:	00050713          	mv	a4,a0
      *dst++ = *src++;
 40c:	00158593          	addi	a1,a1,1
 410:	00170713          	addi	a4,a4,1
 414:	fff5c683          	lbu	a3,-1(a1)
 418:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 41c:	fee798e3          	bne	a5,a4,40c <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 420:	00813083          	ld	ra,8(sp)
 424:	00013403          	ld	s0,0(sp)
 428:	01010113          	addi	sp,sp,16
 42c:	00008067          	ret
    while(n-- > 0)
 430:	fec058e3          	blez	a2,420 <memmove+0x3c>
    dst += n;
 434:	00c50733          	add	a4,a0,a2
    src += n;
 438:	00c585b3          	add	a1,a1,a2
 43c:	fff6079b          	addiw	a5,a2,-1
 440:	02079793          	slli	a5,a5,0x20
 444:	0207d793          	srli	a5,a5,0x20
 448:	fff7c793          	not	a5,a5
 44c:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 450:	fff58593          	addi	a1,a1,-1
 454:	fff70713          	addi	a4,a4,-1
 458:	0005c683          	lbu	a3,0(a1)
 45c:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 460:	fef718e3          	bne	a4,a5,450 <memmove+0x6c>
 464:	fbdff06f          	j	420 <memmove+0x3c>

0000000000000468 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 468:	ff010113          	addi	sp,sp,-16
 46c:	00113423          	sd	ra,8(sp)
 470:	00813023          	sd	s0,0(sp)
 474:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 478:	04060263          	beqz	a2,4bc <memcmp+0x54>
 47c:	02061613          	slli	a2,a2,0x20
 480:	02065613          	srli	a2,a2,0x20
 484:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 488:	00054783          	lbu	a5,0(a0)
 48c:	0005c703          	lbu	a4,0(a1)
 490:	00e79c63          	bne	a5,a4,4a8 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 494:	00150513          	addi	a0,a0,1
    p2++;
 498:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 49c:	fed516e3          	bne	a0,a3,488 <memcmp+0x20>
  }
  return 0;
 4a0:	00000513          	li	a0,0
 4a4:	0080006f          	j	4ac <memcmp+0x44>
      return *p1 - *p2;
 4a8:	40e7853b          	subw	a0,a5,a4
}
 4ac:	00813083          	ld	ra,8(sp)
 4b0:	00013403          	ld	s0,0(sp)
 4b4:	01010113          	addi	sp,sp,16
 4b8:	00008067          	ret
  return 0;
 4bc:	00000513          	li	a0,0
 4c0:	fedff06f          	j	4ac <memcmp+0x44>

00000000000004c4 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 4c4:	ff010113          	addi	sp,sp,-16
 4c8:	00113423          	sd	ra,8(sp)
 4cc:	00813023          	sd	s0,0(sp)
 4d0:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 4d4:	f11ff0ef          	jal	3e4 <memmove>
}
 4d8:	00813083          	ld	ra,8(sp)
 4dc:	00013403          	ld	s0,0(sp)
 4e0:	01010113          	addi	sp,sp,16
 4e4:	00008067          	ret

00000000000004e8 <sbrk>:

char *
sbrk(int n) {
 4e8:	ff010113          	addi	sp,sp,-16
 4ec:	00113423          	sd	ra,8(sp)
 4f0:	00813023          	sd	s0,0(sp)
 4f4:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 4f8:	00100593          	li	a1,1
 4fc:	114000ef          	jal	610 <sys_sbrk>
}
 500:	00813083          	ld	ra,8(sp)
 504:	00013403          	ld	s0,0(sp)
 508:	01010113          	addi	sp,sp,16
 50c:	00008067          	ret

0000000000000510 <sbrklazy>:

char *
sbrklazy(int n) {
 510:	ff010113          	addi	sp,sp,-16
 514:	00113423          	sd	ra,8(sp)
 518:	00813023          	sd	s0,0(sp)
 51c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 520:	00200593          	li	a1,2
 524:	0ec000ef          	jal	610 <sys_sbrk>
}
 528:	00813083          	ld	ra,8(sp)
 52c:	00013403          	ld	s0,0(sp)
 530:	01010113          	addi	sp,sp,16
 534:	00008067          	ret

0000000000000538 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 538:	00100893          	li	a7,1
 ecall
 53c:	00000073          	ecall
 ret
 540:	00008067          	ret

0000000000000544 <exit>:
.global exit
exit:
 li a7, SYS_exit
 544:	00200893          	li	a7,2
 ecall
 548:	00000073          	ecall
 ret
 54c:	00008067          	ret

0000000000000550 <wait>:
.global wait
wait:
 li a7, SYS_wait
 550:	00300893          	li	a7,3
 ecall
 554:	00000073          	ecall
 ret
 558:	00008067          	ret

000000000000055c <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 55c:	00400893          	li	a7,4
 ecall
 560:	00000073          	ecall
 ret
 564:	00008067          	ret

0000000000000568 <read>:
.global read
read:
 li a7, SYS_read
 568:	00500893          	li	a7,5
 ecall
 56c:	00000073          	ecall
 ret
 570:	00008067          	ret

0000000000000574 <write>:
.global write
write:
 li a7, SYS_write
 574:	01000893          	li	a7,16
 ecall
 578:	00000073          	ecall
 ret
 57c:	00008067          	ret

0000000000000580 <close>:
.global close
close:
 li a7, SYS_close
 580:	01500893          	li	a7,21
 ecall
 584:	00000073          	ecall
 ret
 588:	00008067          	ret

000000000000058c <kill>:
.global kill
kill:
 li a7, SYS_kill
 58c:	00600893          	li	a7,6
 ecall
 590:	00000073          	ecall
 ret
 594:	00008067          	ret

0000000000000598 <exec>:
.global exec
exec:
 li a7, SYS_exec
 598:	00700893          	li	a7,7
 ecall
 59c:	00000073          	ecall
 ret
 5a0:	00008067          	ret

00000000000005a4 <open>:
.global open
open:
 li a7, SYS_open
 5a4:	00f00893          	li	a7,15
 ecall
 5a8:	00000073          	ecall
 ret
 5ac:	00008067          	ret

00000000000005b0 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 5b0:	01100893          	li	a7,17
 ecall
 5b4:	00000073          	ecall
 ret
 5b8:	00008067          	ret

00000000000005bc <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 5bc:	01200893          	li	a7,18
 ecall
 5c0:	00000073          	ecall
 ret
 5c4:	00008067          	ret

00000000000005c8 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 5c8:	00800893          	li	a7,8
 ecall
 5cc:	00000073          	ecall
 ret
 5d0:	00008067          	ret

00000000000005d4 <link>:
.global link
link:
 li a7, SYS_link
 5d4:	01300893          	li	a7,19
 ecall
 5d8:	00000073          	ecall
 ret
 5dc:	00008067          	ret

00000000000005e0 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 5e0:	01400893          	li	a7,20
 ecall
 5e4:	00000073          	ecall
 ret
 5e8:	00008067          	ret

00000000000005ec <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 5ec:	00900893          	li	a7,9
 ecall
 5f0:	00000073          	ecall
 ret
 5f4:	00008067          	ret

00000000000005f8 <dup>:
.global dup
dup:
 li a7, SYS_dup
 5f8:	00a00893          	li	a7,10
 ecall
 5fc:	00000073          	ecall
 ret
 600:	00008067          	ret

0000000000000604 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 604:	00b00893          	li	a7,11
 ecall
 608:	00000073          	ecall
 ret
 60c:	00008067          	ret

0000000000000610 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 610:	00c00893          	li	a7,12
 ecall
 614:	00000073          	ecall
 ret
 618:	00008067          	ret

000000000000061c <pause>:
.global pause
pause:
 li a7, SYS_pause
 61c:	00d00893          	li	a7,13
 ecall
 620:	00000073          	ecall
 ret
 624:	00008067          	ret

0000000000000628 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 628:	00e00893          	li	a7,14
 ecall
 62c:	00000073          	ecall
 ret
 630:	00008067          	ret

0000000000000634 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 634:	00001617          	auipc	a2,0x1
 638:	9ec62603          	lw	a2,-1556(a2) # 1020 <putc_n>
 63c:	00c04463          	bgtz	a2,644 <putc_flush+0x10>
 640:	00008067          	ret
{
 644:	ff010113          	addi	sp,sp,-16
 648:	00113423          	sd	ra,8(sp)
 64c:	00813023          	sd	s0,0(sp)
 650:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 654:	00001597          	auipc	a1,0x1
 658:	9dc58593          	addi	a1,a1,-1572 # 1030 <putc_buf>
 65c:	00001517          	auipc	a0,0x1
 660:	9a452503          	lw	a0,-1628(a0) # 1000 <putc_fd>
 664:	f11ff0ef          	jal	574 <write>
    putc_n = 0;
 668:	00001797          	auipc	a5,0x1
 66c:	9a07ac23          	sw	zero,-1608(a5) # 1020 <putc_n>
  }
}
 670:	00813083          	ld	ra,8(sp)
 674:	00013403          	ld	s0,0(sp)
 678:	01010113          	addi	sp,sp,16
 67c:	00008067          	ret

0000000000000680 <putc>:

static void
putc(int fd, char c)
{
 680:	fe010113          	addi	sp,sp,-32
 684:	00113c23          	sd	ra,24(sp)
 688:	00813823          	sd	s0,16(sp)
 68c:	00913423          	sd	s1,8(sp)
 690:	02010413          	addi	s0,sp,32
 694:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 698:	00001797          	auipc	a5,0x1
 69c:	9687a783          	lw	a5,-1688(a5) # 1000 <putc_fd>
 6a0:	04a79663          	bne	a5,a0,6ec <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 6a4:	00001717          	auipc	a4,0x1
 6a8:	97c70713          	addi	a4,a4,-1668 # 1020 <putc_n>
 6ac:	00072683          	lw	a3,0(a4)
 6b0:	0016879b          	addiw	a5,a3,1
 6b4:	00f72023          	sw	a5,0(a4)
 6b8:	00001717          	auipc	a4,0x1
 6bc:	97870713          	addi	a4,a4,-1672 # 1030 <putc_buf>
 6c0:	00d70733          	add	a4,a4,a3
 6c4:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 6c8:	ff648493          	addi	s1,s1,-10
 6cc:	02048e63          	beqz	s1,708 <putc+0x88>
 6d0:	f8078793          	addi	a5,a5,-128
 6d4:	02078a63          	beqz	a5,708 <putc+0x88>
    putc_flush();
}
 6d8:	01813083          	ld	ra,24(sp)
 6dc:	01013403          	ld	s0,16(sp)
 6e0:	00813483          	ld	s1,8(sp)
 6e4:	02010113          	addi	sp,sp,32
 6e8:	00008067          	ret
 6ec:	01213023          	sd	s2,0(sp)
 6f0:	00050913          	mv	s2,a0
    putc_flush();
 6f4:	f41ff0ef          	jal	634 <putc_flush>
    putc_fd = fd;
 6f8:	00001797          	auipc	a5,0x1
 6fc:	9127a423          	sw	s2,-1784(a5) # 1000 <putc_fd>
 700:	00013903          	ld	s2,0(sp)
 704:	fa1ff06f          	j	6a4 <putc+0x24>
    putc_flush();
 708:	f2dff0ef          	jal	634 <putc_flush>
}
 70c:	fcdff06f          	j	6d8 <putc+0x58>

0000000000000710 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 710:	fb010113          	addi	sp,sp,-80
 714:	04113423          	sd	ra,72(sp)
 718:	04813023          	sd	s0,64(sp)
 71c:	03213823          	sd	s2,48(sp)
 720:	03313423          	sd	s3,40(sp)
 724:	05010413          	addi	s0,sp,80
 728:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 72c:	0a068e63          	beqz	a3,7e8 <printint+0xd8>
 730:	0a05dc63          	bgez	a1,7e8 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 734:	40b005b3          	neg	a1,a1
    neg = 1;
 738:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 73c:	fb840993          	addi	s3,s0,-72
  neg = 0;
 740:	00098693          	mv	a3,s3
  i = 0;
 744:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 748:	00000817          	auipc	a6,0x0
 74c:	7d880813          	addi	a6,a6,2008 # f20 <digits>
 750:	00070893          	mv	a7,a4
 754:	0017051b          	addiw	a0,a4,1
 758:	00050713          	mv	a4,a0
 75c:	02c5f7b3          	remu	a5,a1,a2
 760:	00f807b3          	add	a5,a6,a5
 764:	0007c783          	lbu	a5,0(a5)
 768:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 76c:	00058793          	mv	a5,a1
 770:	02c5d5b3          	divu	a1,a1,a2
 774:	00168693          	addi	a3,a3,1
 778:	fcc7fce3          	bgeu	a5,a2,750 <printint+0x40>
  if (neg)
 77c:	00030c63          	beqz	t1,794 <printint+0x84>
    buf[i++] = '-';
 780:	fd050793          	addi	a5,a0,-48
 784:	00878533          	add	a0,a5,s0
 788:	02d00793          	li	a5,45
 78c:	fef50423          	sb	a5,-24(a0)
 790:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 794:	02e05e63          	blez	a4,7d0 <printint+0xc0>
 798:	02913c23          	sd	s1,56(sp)
 79c:	fff7071b          	addiw	a4,a4,-1
 7a0:	00e984b3          	add	s1,s3,a4
 7a4:	fff98993          	addi	s3,s3,-1
 7a8:	00e989b3          	add	s3,s3,a4
 7ac:	02071713          	slli	a4,a4,0x20
 7b0:	02075713          	srli	a4,a4,0x20
 7b4:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 7b8:	0004c583          	lbu	a1,0(s1)
 7bc:	00090513          	mv	a0,s2
 7c0:	ec1ff0ef          	jal	680 <putc>
  while (--i >= 0)
 7c4:	fff48493          	addi	s1,s1,-1
 7c8:	ff3498e3          	bne	s1,s3,7b8 <printint+0xa8>
 7cc:	03813483          	ld	s1,56(sp)
}
 7d0:	04813083          	ld	ra,72(sp)
 7d4:	04013403          	ld	s0,64(sp)
 7d8:	03013903          	ld	s2,48(sp)
 7dc:	02813983          	ld	s3,40(sp)
 7e0:	05010113          	addi	sp,sp,80
 7e4:	00008067          	ret
  neg = 0;
 7e8:	00000313          	li	t1,0
 7ec:	f51ff06f          	j	73c <printint+0x2c>

00000000000007f0 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 7f0:	fa010113          	addi	sp,sp,-96
 7f4:	04113c23          	sd	ra,88(sp)
 7f8:	04813823          	sd	s0,80(sp)
 7fc:	04913423          	sd	s1,72(sp)
 800:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 804:	0005c483          	lbu	s1,0(a1)
 808:	32048263          	beqz	s1,b2c <vprintf+0x33c>
 80c:	05213023          	sd	s2,64(sp)
 810:	03313c23          	sd	s3,56(sp)
 814:	03413823          	sd	s4,48(sp)
 818:	03513423          	sd	s5,40(sp)
 81c:	03613023          	sd	s6,32(sp)
 820:	01713c23          	sd	s7,24(sp)
 824:	01813823          	sd	s8,16(sp)
 828:	00050b13          	mv	s6,a0
 82c:	00058a13          	mv	s4,a1
 830:	00060b93          	mv	s7,a2
  state = 0;
 834:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 838:	00000913          	li	s2,0
 83c:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 840:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 844:	06400c13          	li	s8,100
 848:	0300006f          	j	878 <vprintf+0x88>
        putc(fd, c0);
 84c:	00048593          	mv	a1,s1
 850:	000b0513          	mv	a0,s6
 854:	e2dff0ef          	jal	680 <putc>
 858:	0080006f          	j	860 <vprintf+0x70>
    else if (state == '%')
 85c:	03598863          	beq	s3,s5,88c <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 860:	0019079b          	addiw	a5,s2,1
 864:	00078913          	mv	s2,a5
 868:	00078713          	mv	a4,a5
 86c:	00fa07b3          	add	a5,s4,a5
 870:	0007c483          	lbu	s1,0(a5)
 874:	28048e63          	beqz	s1,b10 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 878:	0004879b          	sext.w	a5,s1
    if (state == 0)
 87c:	fe0990e3          	bnez	s3,85c <vprintf+0x6c>
      if (c0 == '%')
 880:	fd5796e3          	bne	a5,s5,84c <vprintf+0x5c>
        state = '%';
 884:	00078993          	mv	s3,a5
 888:	fd9ff06f          	j	860 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 88c:	00ea06b3          	add	a3,s4,a4
 890:	0016c603          	lbu	a2,1(a3)
      if (c1)
 894:	2a060663          	beqz	a2,b40 <vprintf+0x350>
      if (c0 == 'd')
 898:	05878063          	beq	a5,s8,8d8 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 89c:	f9478693          	addi	a3,a5,-108
 8a0:	0016b693          	seqz	a3,a3
 8a4:	f9c60593          	addi	a1,a2,-100
 8a8:	04059a63          	bnez	a1,8fc <vprintf+0x10c>
 8ac:	04068863          	beqz	a3,8fc <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 8b0:	008b8493          	addi	s1,s7,8
 8b4:	00100693          	li	a3,1
 8b8:	00a00613          	li	a2,10
 8bc:	000bb583          	ld	a1,0(s7)
 8c0:	000b0513          	mv	a0,s6
 8c4:	e4dff0ef          	jal	710 <printint>
        i += 1;
 8c8:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 8cc:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 8d0:	00000993          	li	s3,0
 8d4:	f8dff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 8d8:	008b8493          	addi	s1,s7,8
 8dc:	00100693          	li	a3,1
 8e0:	00a00613          	li	a2,10
 8e4:	000ba583          	lw	a1,0(s7)
 8e8:	000b0513          	mv	a0,s6
 8ec:	e25ff0ef          	jal	710 <printint>
 8f0:	00048b93          	mv	s7,s1
      state = 0;
 8f4:	00000993          	li	s3,0
 8f8:	f69ff06f          	j	860 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 8fc:	00ea0733          	add	a4,s4,a4
 900:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 904:	f9460713          	addi	a4,a2,-108
 908:	00173713          	seqz	a4,a4
 90c:	00e6f733          	and	a4,a3,a4
 910:	f9c58513          	addi	a0,a1,-100
 914:	24051263          	bnez	a0,b58 <vprintf+0x368>
 918:	24070063          	beqz	a4,b58 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 91c:	008b8493          	addi	s1,s7,8
 920:	00100693          	li	a3,1
 924:	00a00613          	li	a2,10
 928:	000bb583          	ld	a1,0(s7)
 92c:	000b0513          	mv	a0,s6
 930:	de1ff0ef          	jal	710 <printint>
        i += 2;
 934:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 938:	00048b93          	mv	s7,s1
      state = 0;
 93c:	00000993          	li	s3,0
        i += 2;
 940:	f21ff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 944:	008b8493          	addi	s1,s7,8
 948:	00000693          	li	a3,0
 94c:	00a00613          	li	a2,10
 950:	000be583          	lwu	a1,0(s7)
 954:	000b0513          	mv	a0,s6
 958:	db9ff0ef          	jal	710 <printint>
 95c:	00048b93          	mv	s7,s1
      state = 0;
 960:	00000993          	li	s3,0
 964:	efdff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 968:	008b8493          	addi	s1,s7,8
 96c:	00000693          	li	a3,0
 970:	00a00613          	li	a2,10
 974:	000bb583          	ld	a1,0(s7)
 978:	000b0513          	mv	a0,s6
 97c:	d95ff0ef          	jal	710 <printint>
        i += 1;
 980:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 984:	00048b93          	mv	s7,s1
      state = 0;
 988:	00000993          	li	s3,0
 98c:	ed5ff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 990:	008b8493          	addi	s1,s7,8
 994:	00000693          	li	a3,0
 998:	00a00613          	li	a2,10
 99c:	000bb583          	ld	a1,0(s7)
 9a0:	000b0513          	mv	a0,s6
 9a4:	d6dff0ef          	jal	710 <printint>
        i += 2;
 9a8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 9ac:	00048b93          	mv	s7,s1
      state = 0;
 9b0:	00000993          	li	s3,0
        i += 2;
 9b4:	eadff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 9b8:	008b8493          	addi	s1,s7,8
 9bc:	00000693          	li	a3,0
 9c0:	01000613          	li	a2,16
 9c4:	000be583          	lwu	a1,0(s7)
 9c8:	000b0513          	mv	a0,s6
 9cc:	d45ff0ef          	jal	710 <printint>
 9d0:	00048b93          	mv	s7,s1
      state = 0;
 9d4:	00000993          	li	s3,0
 9d8:	e89ff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9dc:	008b8493          	addi	s1,s7,8
 9e0:	00000693          	li	a3,0
 9e4:	01000613          	li	a2,16
 9e8:	000bb583          	ld	a1,0(s7)
 9ec:	000b0513          	mv	a0,s6
 9f0:	d21ff0ef          	jal	710 <printint>
        i += 1;
 9f4:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 9f8:	00048b93          	mv	s7,s1
      state = 0;
 9fc:	00000993          	li	s3,0
 a00:	e61ff06f          	j	860 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a04:	008b8493          	addi	s1,s7,8
 a08:	00000693          	li	a3,0
 a0c:	01000613          	li	a2,16
 a10:	000bb583          	ld	a1,0(s7)
 a14:	000b0513          	mv	a0,s6
 a18:	cf9ff0ef          	jal	710 <printint>
        i += 2;
 a1c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 a20:	00048b93          	mv	s7,s1
      state = 0;
 a24:	00000993          	li	s3,0
        i += 2;
 a28:	e39ff06f          	j	860 <vprintf+0x70>
 a2c:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 a30:	008b8793          	addi	a5,s7,8
 a34:	00078c93          	mv	s9,a5
 a38:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 a3c:	03000593          	li	a1,48
 a40:	000b0513          	mv	a0,s6
 a44:	c3dff0ef          	jal	680 <putc>
  putc(fd, 'x');
 a48:	07800593          	li	a1,120
 a4c:	000b0513          	mv	a0,s6
 a50:	c31ff0ef          	jal	680 <putc>
 a54:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a58:	00000b97          	auipc	s7,0x0
 a5c:	4c8b8b93          	addi	s7,s7,1224 # f20 <digits>
 a60:	03c9d793          	srli	a5,s3,0x3c
 a64:	00fb87b3          	add	a5,s7,a5
 a68:	0007c583          	lbu	a1,0(a5)
 a6c:	000b0513          	mv	a0,s6
 a70:	c11ff0ef          	jal	680 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a74:	00499993          	slli	s3,s3,0x4
 a78:	fff4849b          	addiw	s1,s1,-1
 a7c:	fe0492e3          	bnez	s1,a60 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a80:	000c8b93          	mv	s7,s9
      state = 0;
 a84:	00000993          	li	s3,0
 a88:	00813c83          	ld	s9,8(sp)
 a8c:	dd5ff06f          	j	860 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a90:	008b8493          	addi	s1,s7,8
 a94:	000bc583          	lbu	a1,0(s7)
 a98:	000b0513          	mv	a0,s6
 a9c:	be5ff0ef          	jal	680 <putc>
 aa0:	00048b93          	mv	s7,s1
      state = 0;
 aa4:	00000993          	li	s3,0
 aa8:	db9ff06f          	j	860 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 aac:	008b8993          	addi	s3,s7,8
 ab0:	000bb483          	ld	s1,0(s7)
 ab4:	02048663          	beqz	s1,ae0 <vprintf+0x2f0>
        for (; *s; s++)
 ab8:	0004c583          	lbu	a1,0(s1)
 abc:	04058463          	beqz	a1,b04 <vprintf+0x314>
          putc(fd, *s);
 ac0:	000b0513          	mv	a0,s6
 ac4:	bbdff0ef          	jal	680 <putc>
        for (; *s; s++)
 ac8:	00148493          	addi	s1,s1,1
 acc:	0004c583          	lbu	a1,0(s1)
 ad0:	fe0598e3          	bnez	a1,ac0 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 ad4:	00098b93          	mv	s7,s3
      state = 0;
 ad8:	00000993          	li	s3,0
 adc:	d85ff06f          	j	860 <vprintf+0x70>
          s = "(null)";
 ae0:	00000497          	auipc	s1,0x0
 ae4:	43848493          	addi	s1,s1,1080 # f18 <malloc+0x1f0>
        for (; *s; s++)
 ae8:	02800593          	li	a1,40
 aec:	fd5ff06f          	j	ac0 <vprintf+0x2d0>
        putc(fd, '%');
 af0:	00078593          	mv	a1,a5
 af4:	000b0513          	mv	a0,s6
 af8:	b89ff0ef          	jal	680 <putc>
      state = 0;
 afc:	00000993          	li	s3,0
 b00:	d61ff06f          	j	860 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b04:	00098b93          	mv	s7,s3
      state = 0;
 b08:	00000993          	li	s3,0
 b0c:	d55ff06f          	j	860 <vprintf+0x70>
 b10:	04013903          	ld	s2,64(sp)
 b14:	03813983          	ld	s3,56(sp)
 b18:	03013a03          	ld	s4,48(sp)
 b1c:	02813a83          	ld	s5,40(sp)
 b20:	02013b03          	ld	s6,32(sp)
 b24:	01813b83          	ld	s7,24(sp)
 b28:	01013c03          	ld	s8,16(sp)
    }
  }
}
 b2c:	05813083          	ld	ra,88(sp)
 b30:	05013403          	ld	s0,80(sp)
 b34:	04813483          	ld	s1,72(sp)
 b38:	06010113          	addi	sp,sp,96
 b3c:	00008067          	ret
      if (c0 == 'd')
 b40:	06400713          	li	a4,100
 b44:	d8e78ae3          	beq	a5,a4,8d8 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 b48:	f9478693          	addi	a3,a5,-108
 b4c:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 b50:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 b54:	00000713          	li	a4,0
      else if (c0 == 'u')
 b58:	07500513          	li	a0,117
 b5c:	dea784e3          	beq	a5,a0,944 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b60:	f8b60513          	addi	a0,a2,-117
 b64:	00051463          	bnez	a0,b6c <vprintf+0x37c>
 b68:	e00690e3          	bnez	a3,968 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 b6c:	f8b58513          	addi	a0,a1,-117
 b70:	00051463          	bnez	a0,b78 <vprintf+0x388>
 b74:	e0071ee3          	bnez	a4,990 <vprintf+0x1a0>
      else if (c0 == 'x')
 b78:	07800513          	li	a0,120
 b7c:	e2a78ee3          	beq	a5,a0,9b8 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b80:	f8860613          	addi	a2,a2,-120
 b84:	00061463          	bnez	a2,b8c <vprintf+0x39c>
 b88:	e4069ae3          	bnez	a3,9dc <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b8c:	f8858593          	addi	a1,a1,-120
 b90:	00059463          	bnez	a1,b98 <vprintf+0x3a8>
 b94:	e60718e3          	bnez	a4,a04 <vprintf+0x214>
      else if (c0 == 'p')
 b98:	07000713          	li	a4,112
 b9c:	e8e788e3          	beq	a5,a4,a2c <vprintf+0x23c>
      else if (c0 == 'c')
 ba0:	06300713          	li	a4,99
 ba4:	eee786e3          	beq	a5,a4,a90 <vprintf+0x2a0>
      else if (c0 == 's')
 ba8:	07300713          	li	a4,115
 bac:	f0e780e3          	beq	a5,a4,aac <vprintf+0x2bc>
      else if (c0 == '%')
 bb0:	02500713          	li	a4,37
 bb4:	f2e78ee3          	beq	a5,a4,af0 <vprintf+0x300>
        putc(fd, '%');
 bb8:	02500593          	li	a1,37
 bbc:	000b0513          	mv	a0,s6
 bc0:	ac1ff0ef          	jal	680 <putc>
        putc(fd, c0);
 bc4:	00048593          	mv	a1,s1
 bc8:	000b0513          	mv	a0,s6
 bcc:	ab5ff0ef          	jal	680 <putc>
      state = 0;
 bd0:	00000993          	li	s3,0
 bd4:	c8dff06f          	j	860 <vprintf+0x70>

0000000000000bd8 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 bd8:	fb010113          	addi	sp,sp,-80
 bdc:	00113c23          	sd	ra,24(sp)
 be0:	00813823          	sd	s0,16(sp)
 be4:	02010413          	addi	s0,sp,32
 be8:	00c43023          	sd	a2,0(s0)
 bec:	00d43423          	sd	a3,8(s0)
 bf0:	00e43823          	sd	a4,16(s0)
 bf4:	00f43c23          	sd	a5,24(s0)
 bf8:	03043023          	sd	a6,32(s0)
 bfc:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 c00:	00040613          	mv	a2,s0
 c04:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 c08:	be9ff0ef          	jal	7f0 <vprintf>
}
 c0c:	01813083          	ld	ra,24(sp)
 c10:	01013403          	ld	s0,16(sp)
 c14:	05010113          	addi	sp,sp,80
 c18:	00008067          	ret

0000000000000c1c <printf>:

void printf(const char *fmt, ...)
{
 c1c:	fa010113          	addi	sp,sp,-96
 c20:	00113c23          	sd	ra,24(sp)
 c24:	00813823          	sd	s0,16(sp)
 c28:	02010413          	addi	s0,sp,32
 c2c:	00b43423          	sd	a1,8(s0)
 c30:	00c43823          	sd	a2,16(s0)
 c34:	00d43c23          	sd	a3,24(s0)
 c38:	02e43023          	sd	a4,32(s0)
 c3c:	02f43423          	sd	a5,40(s0)
 c40:	03043823          	sd	a6,48(s0)
 c44:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 c48:	00840613          	addi	a2,s0,8
 c4c:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 c50:	00050593          	mv	a1,a0
 c54:	00100513          	li	a0,1
 c58:	b99ff0ef          	jal	7f0 <vprintf>
  putc_flush();
 c5c:	9d9ff0ef          	jal	634 <putc_flush>
}
 c60:	01813083          	ld	ra,24(sp)
 c64:	01013403          	ld	s0,16(sp)
 c68:	06010113          	addi	sp,sp,96
 c6c:	00008067          	ret

0000000000000c70 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c70:	ff010113          	addi	sp,sp,-16
 c74:	00113423          	sd	ra,8(sp)
 c78:	00813023          	sd	s0,0(sp)
 c7c:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c80:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c84:	00000797          	auipc	a5,0x0
 c88:	3a47b783          	ld	a5,932(a5) # 1028 <freep>
 c8c:	0140006f          	j	ca0 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c90:	0007b703          	ld	a4,0(a5)
 c94:	00e7e463          	bltu	a5,a4,c9c <free+0x2c>
 c98:	00e6ec63          	bltu	a3,a4,cb0 <free+0x40>
{
 c9c:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 ca0:	fed7f8e3          	bgeu	a5,a3,c90 <free+0x20>
 ca4:	0007b703          	ld	a4,0(a5)
 ca8:	00e6e463          	bltu	a3,a4,cb0 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 cac:	fee7e8e3          	bltu	a5,a4,c9c <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 cb0:	ff852583          	lw	a1,-8(a0)
 cb4:	0007b603          	ld	a2,0(a5)
 cb8:	02059813          	slli	a6,a1,0x20
 cbc:	01c85713          	srli	a4,a6,0x1c
 cc0:	00e68733          	add	a4,a3,a4
 cc4:	02e60c63          	beq	a2,a4,cfc <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 cc8:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 ccc:	0087a603          	lw	a2,8(a5)
 cd0:	02061593          	slli	a1,a2,0x20
 cd4:	01c5d713          	srli	a4,a1,0x1c
 cd8:	00e78733          	add	a4,a5,a4
 cdc:	02e68c63          	beq	a3,a4,d14 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 ce0:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 ce4:	00000717          	auipc	a4,0x0
 ce8:	34f73223          	sd	a5,836(a4) # 1028 <freep>
}
 cec:	00813083          	ld	ra,8(sp)
 cf0:	00013403          	ld	s0,0(sp)
 cf4:	01010113          	addi	sp,sp,16
 cf8:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 cfc:	00862703          	lw	a4,8(a2)
 d00:	00b7073b          	addw	a4,a4,a1
 d04:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 d08:	0007b703          	ld	a4,0(a5)
 d0c:	00073603          	ld	a2,0(a4)
 d10:	fb9ff06f          	j	cc8 <free+0x58>
    p->s.size += bp->s.size;
 d14:	ff852703          	lw	a4,-8(a0)
 d18:	00c7073b          	addw	a4,a4,a2
 d1c:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 d20:	ff053683          	ld	a3,-16(a0)
 d24:	fbdff06f          	j	ce0 <free+0x70>

0000000000000d28 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 d28:	fc010113          	addi	sp,sp,-64
 d2c:	02113c23          	sd	ra,56(sp)
 d30:	02813823          	sd	s0,48(sp)
 d34:	03213023          	sd	s2,32(sp)
 d38:	01313c23          	sd	s3,24(sp)
 d3c:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 d40:	02051993          	slli	s3,a0,0x20
 d44:	0209d993          	srli	s3,s3,0x20
 d48:	00f98993          	addi	s3,s3,15
 d4c:	0049d993          	srli	s3,s3,0x4
 d50:	0019899b          	addiw	s3,s3,1
 d54:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d58:	00000517          	auipc	a0,0x0
 d5c:	2d053503          	ld	a0,720(a0) # 1028 <freep>
 d60:	04050463          	beqz	a0,da8 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d64:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d68:	0087a703          	lw	a4,8(a5)
 d6c:	0d377a63          	bgeu	a4,s3,e40 <malloc+0x118>
 d70:	02913423          	sd	s1,40(sp)
 d74:	01413823          	sd	s4,16(sp)
 d78:	01513423          	sd	s5,8(sp)
 d7c:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d80:	00098a13          	mv	s4,s3
 d84:	00001737          	lui	a4,0x1
 d88:	00e9f463          	bgeu	s3,a4,d90 <malloc+0x68>
 d8c:	00001a37          	lui	s4,0x1
 d90:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d94:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d98:	00000497          	auipc	s1,0x0
 d9c:	29048493          	addi	s1,s1,656 # 1028 <freep>
  if(p == SBRK_ERROR)
 da0:	fff00a93          	li	s5,-1
 da4:	05c0006f          	j	e00 <malloc+0xd8>
 da8:	02913423          	sd	s1,40(sp)
 dac:	01413823          	sd	s4,16(sp)
 db0:	01513423          	sd	s5,8(sp)
 db4:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 db8:	00000797          	auipc	a5,0x0
 dbc:	2f878793          	addi	a5,a5,760 # 10b0 <base>
 dc0:	00000717          	auipc	a4,0x0
 dc4:	26f73423          	sd	a5,616(a4) # 1028 <freep>
 dc8:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 dcc:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 dd0:	fb1ff06f          	j	d80 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 dd4:	0007b703          	ld	a4,0(a5)
 dd8:	00e53023          	sd	a4,0(a0)
 ddc:	0800006f          	j	e5c <malloc+0x134>
  hp->s.size = nu;
 de0:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 de4:	01050513          	addi	a0,a0,16
 de8:	e89ff0ef          	jal	c70 <free>
  return freep;
 dec:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 df0:	08050863          	beqz	a0,e80 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 df4:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 df8:	0087a703          	lw	a4,8(a5)
 dfc:	03277a63          	bgeu	a4,s2,e30 <malloc+0x108>
    if(p == freep)
 e00:	0004b703          	ld	a4,0(s1)
 e04:	00078513          	mv	a0,a5
 e08:	fef716e3          	bne	a4,a5,df4 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 e0c:	000a0513          	mv	a0,s4
 e10:	ed8ff0ef          	jal	4e8 <sbrk>
  if(p == SBRK_ERROR)
 e14:	fd5516e3          	bne	a0,s5,de0 <malloc+0xb8>
        return 0;
 e18:	00000513          	li	a0,0
 e1c:	02813483          	ld	s1,40(sp)
 e20:	01013a03          	ld	s4,16(sp)
 e24:	00813a83          	ld	s5,8(sp)
 e28:	00013b03          	ld	s6,0(sp)
 e2c:	03c0006f          	j	e68 <malloc+0x140>
 e30:	02813483          	ld	s1,40(sp)
 e34:	01013a03          	ld	s4,16(sp)
 e38:	00813a83          	ld	s5,8(sp)
 e3c:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 e40:	f8e90ae3          	beq	s2,a4,dd4 <malloc+0xac>
        p->s.size -= nunits;
 e44:	4137073b          	subw	a4,a4,s3
 e48:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 e4c:	02071693          	slli	a3,a4,0x20
 e50:	01c6d713          	srli	a4,a3,0x1c
 e54:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e58:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e5c:	00000717          	auipc	a4,0x0
 e60:	1ca73623          	sd	a0,460(a4) # 1028 <freep>
      return (void*)(p + 1);
 e64:	01078513          	addi	a0,a5,16
  }
}
 e68:	03813083          	ld	ra,56(sp)
 e6c:	03013403          	ld	s0,48(sp)
 e70:	02013903          	ld	s2,32(sp)
 e74:	01813983          	ld	s3,24(sp)
 e78:	04010113          	addi	sp,sp,64
 e7c:	00008067          	ret
 e80:	02813483          	ld	s1,40(sp)
 e84:	01013a03          	ld	s4,16(sp)
 e88:	00813a83          	ld	s5,8(sp)
 e8c:	00013b03          	ld	s6,0(sp)
 e90:	fd9ff06f          	j	e68 <malloc+0x140>
