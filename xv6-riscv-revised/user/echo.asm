
user/_echo:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
   0:	fc010113          	addi	sp,sp,-64
   4:	02113c23          	sd	ra,56(sp)
   8:	02813823          	sd	s0,48(sp)
   c:	02913423          	sd	s1,40(sp)
  10:	03213023          	sd	s2,32(sp)
  14:	01313c23          	sd	s3,24(sp)
  18:	01413823          	sd	s4,16(sp)
  1c:	01513423          	sd	s5,8(sp)
  20:	01613023          	sd	s6,0(sp)
  24:	04010413          	addi	s0,sp,64
  int i;

  for(i = 1; i < argc; i++){
  28:	00100793          	li	a5,1
  2c:	06a7de63          	bge	a5,a0,a8 <main+0xa8>
  30:	00858493          	addi	s1,a1,8
  34:	ffe5051b          	addiw	a0,a0,-2
  38:	02051793          	slli	a5,a0,0x20
  3c:	01d7d513          	srli	a0,a5,0x1d
  40:	00a48ab3          	add	s5,s1,a0
  44:	01058593          	addi	a1,a1,16
  48:	00a58a33          	add	s4,a1,a0
    write(1, argv[i], strlen(argv[i]));
  4c:	00100993          	li	s3,1
    if(i + 1 < argc){
      write(1, " ", 1);
  50:	00001b17          	auipc	s6,0x1
  54:	e10b0b13          	addi	s6,s6,-496 # e60 <malloc+0x16c>
  58:	01c0006f          	j	74 <main+0x74>
  5c:	00098613          	mv	a2,s3
  60:	000b0593          	mv	a1,s6
  64:	00098513          	mv	a0,s3
  68:	4d8000ef          	jal	540 <write>
  for(i = 1; i < argc; i++){
  6c:	00848493          	addi	s1,s1,8
  70:	03448c63          	beq	s1,s4,a8 <main+0xa8>
    write(1, argv[i], strlen(argv[i]));
  74:	0004b903          	ld	s2,0(s1)
  78:	00090513          	mv	a0,s2
  7c:	0cc000ef          	jal	148 <strlen>
  80:	00050613          	mv	a2,a0
  84:	00090593          	mv	a1,s2
  88:	00098513          	mv	a0,s3
  8c:	4b4000ef          	jal	540 <write>
    if(i + 1 < argc){
  90:	fd5496e3          	bne	s1,s5,5c <main+0x5c>
    } else {
      write(1, "\n", 1);
  94:	00100613          	li	a2,1
  98:	00001597          	auipc	a1,0x1
  9c:	dd058593          	addi	a1,a1,-560 # e68 <malloc+0x174>
  a0:	00060513          	mv	a0,a2
  a4:	49c000ef          	jal	540 <write>
    }
  }
  exit(0);
  a8:	00000513          	li	a0,0
  ac:	464000ef          	jal	510 <exit>

00000000000000b0 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  b0:	ff010113          	addi	sp,sp,-16
  b4:	00113423          	sd	ra,8(sp)
  b8:	00813023          	sd	s0,0(sp)
  bc:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  c0:	f41ff0ef          	jal	0 <main>
  exit(r);
  c4:	44c000ef          	jal	510 <exit>

00000000000000c8 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  c8:	ff010113          	addi	sp,sp,-16
  cc:	00113423          	sd	ra,8(sp)
  d0:	00813023          	sd	s0,0(sp)
  d4:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  d8:	00050793          	mv	a5,a0
  dc:	00158593          	addi	a1,a1,1
  e0:	00178793          	addi	a5,a5,1
  e4:	fff5c703          	lbu	a4,-1(a1)
  e8:	fee78fa3          	sb	a4,-1(a5)
  ec:	fe0718e3          	bnez	a4,dc <strcpy+0x14>
    ;
  return os;
}
  f0:	00813083          	ld	ra,8(sp)
  f4:	00013403          	ld	s0,0(sp)
  f8:	01010113          	addi	sp,sp,16
  fc:	00008067          	ret

0000000000000100 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 100:	ff010113          	addi	sp,sp,-16
 104:	00113423          	sd	ra,8(sp)
 108:	00813023          	sd	s0,0(sp)
 10c:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 110:	00054783          	lbu	a5,0(a0)
 114:	00078e63          	beqz	a5,130 <strcmp+0x30>
 118:	0005c703          	lbu	a4,0(a1)
 11c:	00f71a63          	bne	a4,a5,130 <strcmp+0x30>
    p++, q++;
 120:	00150513          	addi	a0,a0,1
 124:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 128:	00054783          	lbu	a5,0(a0)
 12c:	fe0796e3          	bnez	a5,118 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 130:	0005c503          	lbu	a0,0(a1)
}
 134:	40a7853b          	subw	a0,a5,a0
 138:	00813083          	ld	ra,8(sp)
 13c:	00013403          	ld	s0,0(sp)
 140:	01010113          	addi	sp,sp,16
 144:	00008067          	ret

0000000000000148 <strlen>:

uint
strlen(const char *s)
{
 148:	ff010113          	addi	sp,sp,-16
 14c:	00113423          	sd	ra,8(sp)
 150:	00813023          	sd	s0,0(sp)
 154:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 158:	00054783          	lbu	a5,0(a0)
 15c:	02078663          	beqz	a5,188 <strlen+0x40>
 160:	00150793          	addi	a5,a0,1
 164:	00078693          	mv	a3,a5
 168:	00178793          	addi	a5,a5,1
 16c:	fff7c703          	lbu	a4,-1(a5)
 170:	fe071ae3          	bnez	a4,164 <strlen+0x1c>
 174:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 178:	00813083          	ld	ra,8(sp)
 17c:	00013403          	ld	s0,0(sp)
 180:	01010113          	addi	sp,sp,16
 184:	00008067          	ret
  for(n = 0; s[n]; n++)
 188:	00000513          	li	a0,0
 18c:	fedff06f          	j	178 <strlen+0x30>

0000000000000190 <memset>:

void*
memset(void *dst, int c, uint n)
{
 190:	ff010113          	addi	sp,sp,-16
 194:	00113423          	sd	ra,8(sp)
 198:	00813023          	sd	s0,0(sp)
 19c:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 1a0:	02060063          	beqz	a2,1c0 <memset+0x30>
 1a4:	00050793          	mv	a5,a0
 1a8:	02061613          	slli	a2,a2,0x20
 1ac:	02065613          	srli	a2,a2,0x20
 1b0:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 1b4:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 1b8:	00178793          	addi	a5,a5,1
 1bc:	fee79ce3          	bne	a5,a4,1b4 <memset+0x24>
  }
  return dst;
}
 1c0:	00813083          	ld	ra,8(sp)
 1c4:	00013403          	ld	s0,0(sp)
 1c8:	01010113          	addi	sp,sp,16
 1cc:	00008067          	ret

00000000000001d0 <strchr>:

char*
strchr(const char *s, char c)
{
 1d0:	ff010113          	addi	sp,sp,-16
 1d4:	00113423          	sd	ra,8(sp)
 1d8:	00813023          	sd	s0,0(sp)
 1dc:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 1e0:	00054783          	lbu	a5,0(a0)
 1e4:	02078463          	beqz	a5,20c <strchr+0x3c>
    if(*s == c)
 1e8:	00f58a63          	beq	a1,a5,1fc <strchr+0x2c>
  for(; *s; s++)
 1ec:	00150513          	addi	a0,a0,1
 1f0:	00054783          	lbu	a5,0(a0)
 1f4:	fe079ae3          	bnez	a5,1e8 <strchr+0x18>
      return (char*)s;
  return 0;
 1f8:	00000513          	li	a0,0
}
 1fc:	00813083          	ld	ra,8(sp)
 200:	00013403          	ld	s0,0(sp)
 204:	01010113          	addi	sp,sp,16
 208:	00008067          	ret
  return 0;
 20c:	00000513          	li	a0,0
 210:	fedff06f          	j	1fc <strchr+0x2c>

0000000000000214 <gets>:

char*
gets(char *buf, int max)
{
 214:	fa010113          	addi	sp,sp,-96
 218:	04113c23          	sd	ra,88(sp)
 21c:	04813823          	sd	s0,80(sp)
 220:	04913423          	sd	s1,72(sp)
 224:	05213023          	sd	s2,64(sp)
 228:	03313c23          	sd	s3,56(sp)
 22c:	03413823          	sd	s4,48(sp)
 230:	03513423          	sd	s5,40(sp)
 234:	03613023          	sd	s6,32(sp)
 238:	01713c23          	sd	s7,24(sp)
 23c:	01813823          	sd	s8,16(sp)
 240:	06010413          	addi	s0,sp,96
 244:	00050b93          	mv	s7,a0
 248:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 24c:	00050913          	mv	s2,a0
 250:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 254:	faf40b13          	addi	s6,s0,-81
 258:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 25c:	00048c13          	mv	s8,s1
 260:	0014899b          	addiw	s3,s1,1
 264:	00098493          	mv	s1,s3
 268:	0349dc63          	bge	s3,s4,2a0 <gets+0x8c>
    cc = read(0, &c, 1);
 26c:	000a8613          	mv	a2,s5
 270:	000b0593          	mv	a1,s6
 274:	00000513          	li	a0,0
 278:	2bc000ef          	jal	534 <read>
    if(cc < 1)
 27c:	02a05263          	blez	a0,2a0 <gets+0x8c>
      break;
    buf[i++] = c;
 280:	faf44783          	lbu	a5,-81(s0)
 284:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 288:	00190913          	addi	s2,s2,1
 28c:	ff678713          	addi	a4,a5,-10
 290:	00070663          	beqz	a4,29c <gets+0x88>
 294:	ff378793          	addi	a5,a5,-13
 298:	fc0792e3          	bnez	a5,25c <gets+0x48>
    buf[i++] = c;
 29c:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 2a0:	018b8c33          	add	s8,s7,s8
 2a4:	000c0023          	sb	zero,0(s8)
  return buf;
}
 2a8:	000b8513          	mv	a0,s7
 2ac:	05813083          	ld	ra,88(sp)
 2b0:	05013403          	ld	s0,80(sp)
 2b4:	04813483          	ld	s1,72(sp)
 2b8:	04013903          	ld	s2,64(sp)
 2bc:	03813983          	ld	s3,56(sp)
 2c0:	03013a03          	ld	s4,48(sp)
 2c4:	02813a83          	ld	s5,40(sp)
 2c8:	02013b03          	ld	s6,32(sp)
 2cc:	01813b83          	ld	s7,24(sp)
 2d0:	01013c03          	ld	s8,16(sp)
 2d4:	06010113          	addi	sp,sp,96
 2d8:	00008067          	ret

00000000000002dc <stat>:

int
stat(const char *n, struct stat *st)
{
 2dc:	fe010113          	addi	sp,sp,-32
 2e0:	00113c23          	sd	ra,24(sp)
 2e4:	00813823          	sd	s0,16(sp)
 2e8:	01213023          	sd	s2,0(sp)
 2ec:	02010413          	addi	s0,sp,32
 2f0:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 2f4:	00000593          	li	a1,0
 2f8:	278000ef          	jal	570 <open>
  if(fd < 0)
 2fc:	02054e63          	bltz	a0,338 <stat+0x5c>
 300:	00913423          	sd	s1,8(sp)
 304:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 308:	00090593          	mv	a1,s2
 30c:	288000ef          	jal	594 <fstat>
 310:	00050913          	mv	s2,a0
  close(fd);
 314:	00048513          	mv	a0,s1
 318:	234000ef          	jal	54c <close>
  return r;
 31c:	00813483          	ld	s1,8(sp)
}
 320:	00090513          	mv	a0,s2
 324:	01813083          	ld	ra,24(sp)
 328:	01013403          	ld	s0,16(sp)
 32c:	00013903          	ld	s2,0(sp)
 330:	02010113          	addi	sp,sp,32
 334:	00008067          	ret
    return -1;
 338:	fff00793          	li	a5,-1
 33c:	00078913          	mv	s2,a5
 340:	fe1ff06f          	j	320 <stat+0x44>

0000000000000344 <atoi>:

int
atoi(const char *s)
{
 344:	ff010113          	addi	sp,sp,-16
 348:	00113423          	sd	ra,8(sp)
 34c:	00813023          	sd	s0,0(sp)
 350:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 354:	00054683          	lbu	a3,0(a0)
 358:	fd06879b          	addiw	a5,a3,-48
 35c:	0ff7f793          	zext.b	a5,a5
 360:	00900613          	li	a2,9
 364:	04f66263          	bltu	a2,a5,3a8 <atoi+0x64>
 368:	00050713          	mv	a4,a0
  n = 0;
 36c:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 370:	00170713          	addi	a4,a4,1
 374:	0025179b          	slliw	a5,a0,0x2
 378:	00a787bb          	addw	a5,a5,a0
 37c:	0017979b          	slliw	a5,a5,0x1
 380:	00d787bb          	addw	a5,a5,a3
 384:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 388:	00074683          	lbu	a3,0(a4)
 38c:	fd06879b          	addiw	a5,a3,-48
 390:	0ff7f793          	zext.b	a5,a5
 394:	fcf67ee3          	bgeu	a2,a5,370 <atoi+0x2c>
  return n;
}
 398:	00813083          	ld	ra,8(sp)
 39c:	00013403          	ld	s0,0(sp)
 3a0:	01010113          	addi	sp,sp,16
 3a4:	00008067          	ret
  n = 0;
 3a8:	00000513          	li	a0,0
 3ac:	fedff06f          	j	398 <atoi+0x54>

00000000000003b0 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 3b0:	ff010113          	addi	sp,sp,-16
 3b4:	00113423          	sd	ra,8(sp)
 3b8:	00813023          	sd	s0,0(sp)
 3bc:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 3c0:	02b57e63          	bgeu	a0,a1,3fc <memmove+0x4c>
    while(n-- > 0)
 3c4:	02c05463          	blez	a2,3ec <memmove+0x3c>
 3c8:	02061613          	slli	a2,a2,0x20
 3cc:	02065613          	srli	a2,a2,0x20
 3d0:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 3d4:	00050713          	mv	a4,a0
      *dst++ = *src++;
 3d8:	00158593          	addi	a1,a1,1
 3dc:	00170713          	addi	a4,a4,1
 3e0:	fff5c683          	lbu	a3,-1(a1)
 3e4:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 3e8:	fee798e3          	bne	a5,a4,3d8 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 3ec:	00813083          	ld	ra,8(sp)
 3f0:	00013403          	ld	s0,0(sp)
 3f4:	01010113          	addi	sp,sp,16
 3f8:	00008067          	ret
    while(n-- > 0)
 3fc:	fec058e3          	blez	a2,3ec <memmove+0x3c>
    dst += n;
 400:	00c50733          	add	a4,a0,a2
    src += n;
 404:	00c585b3          	add	a1,a1,a2
 408:	fff6079b          	addiw	a5,a2,-1
 40c:	02079793          	slli	a5,a5,0x20
 410:	0207d793          	srli	a5,a5,0x20
 414:	fff7c793          	not	a5,a5
 418:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 41c:	fff58593          	addi	a1,a1,-1
 420:	fff70713          	addi	a4,a4,-1
 424:	0005c683          	lbu	a3,0(a1)
 428:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 42c:	fef718e3          	bne	a4,a5,41c <memmove+0x6c>
 430:	fbdff06f          	j	3ec <memmove+0x3c>

0000000000000434 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 434:	ff010113          	addi	sp,sp,-16
 438:	00113423          	sd	ra,8(sp)
 43c:	00813023          	sd	s0,0(sp)
 440:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 444:	04060263          	beqz	a2,488 <memcmp+0x54>
 448:	02061613          	slli	a2,a2,0x20
 44c:	02065613          	srli	a2,a2,0x20
 450:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 454:	00054783          	lbu	a5,0(a0)
 458:	0005c703          	lbu	a4,0(a1)
 45c:	00e79c63          	bne	a5,a4,474 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 460:	00150513          	addi	a0,a0,1
    p2++;
 464:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 468:	fed516e3          	bne	a0,a3,454 <memcmp+0x20>
  }
  return 0;
 46c:	00000513          	li	a0,0
 470:	0080006f          	j	478 <memcmp+0x44>
      return *p1 - *p2;
 474:	40e7853b          	subw	a0,a5,a4
}
 478:	00813083          	ld	ra,8(sp)
 47c:	00013403          	ld	s0,0(sp)
 480:	01010113          	addi	sp,sp,16
 484:	00008067          	ret
  return 0;
 488:	00000513          	li	a0,0
 48c:	fedff06f          	j	478 <memcmp+0x44>

0000000000000490 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 490:	ff010113          	addi	sp,sp,-16
 494:	00113423          	sd	ra,8(sp)
 498:	00813023          	sd	s0,0(sp)
 49c:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 4a0:	f11ff0ef          	jal	3b0 <memmove>
}
 4a4:	00813083          	ld	ra,8(sp)
 4a8:	00013403          	ld	s0,0(sp)
 4ac:	01010113          	addi	sp,sp,16
 4b0:	00008067          	ret

00000000000004b4 <sbrk>:

char *
sbrk(int n) {
 4b4:	ff010113          	addi	sp,sp,-16
 4b8:	00113423          	sd	ra,8(sp)
 4bc:	00813023          	sd	s0,0(sp)
 4c0:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 4c4:	00100593          	li	a1,1
 4c8:	114000ef          	jal	5dc <sys_sbrk>
}
 4cc:	00813083          	ld	ra,8(sp)
 4d0:	00013403          	ld	s0,0(sp)
 4d4:	01010113          	addi	sp,sp,16
 4d8:	00008067          	ret

00000000000004dc <sbrklazy>:

char *
sbrklazy(int n) {
 4dc:	ff010113          	addi	sp,sp,-16
 4e0:	00113423          	sd	ra,8(sp)
 4e4:	00813023          	sd	s0,0(sp)
 4e8:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 4ec:	00200593          	li	a1,2
 4f0:	0ec000ef          	jal	5dc <sys_sbrk>
}
 4f4:	00813083          	ld	ra,8(sp)
 4f8:	00013403          	ld	s0,0(sp)
 4fc:	01010113          	addi	sp,sp,16
 500:	00008067          	ret

0000000000000504 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 504:	00100893          	li	a7,1
 ecall
 508:	00000073          	ecall
 ret
 50c:	00008067          	ret

0000000000000510 <exit>:
.global exit
exit:
 li a7, SYS_exit
 510:	00200893          	li	a7,2
 ecall
 514:	00000073          	ecall
 ret
 518:	00008067          	ret

000000000000051c <wait>:
.global wait
wait:
 li a7, SYS_wait
 51c:	00300893          	li	a7,3
 ecall
 520:	00000073          	ecall
 ret
 524:	00008067          	ret

0000000000000528 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 528:	00400893          	li	a7,4
 ecall
 52c:	00000073          	ecall
 ret
 530:	00008067          	ret

0000000000000534 <read>:
.global read
read:
 li a7, SYS_read
 534:	00500893          	li	a7,5
 ecall
 538:	00000073          	ecall
 ret
 53c:	00008067          	ret

0000000000000540 <write>:
.global write
write:
 li a7, SYS_write
 540:	01000893          	li	a7,16
 ecall
 544:	00000073          	ecall
 ret
 548:	00008067          	ret

000000000000054c <close>:
.global close
close:
 li a7, SYS_close
 54c:	01500893          	li	a7,21
 ecall
 550:	00000073          	ecall
 ret
 554:	00008067          	ret

0000000000000558 <kill>:
.global kill
kill:
 li a7, SYS_kill
 558:	00600893          	li	a7,6
 ecall
 55c:	00000073          	ecall
 ret
 560:	00008067          	ret

0000000000000564 <exec>:
.global exec
exec:
 li a7, SYS_exec
 564:	00700893          	li	a7,7
 ecall
 568:	00000073          	ecall
 ret
 56c:	00008067          	ret

0000000000000570 <open>:
.global open
open:
 li a7, SYS_open
 570:	00f00893          	li	a7,15
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 57c:	01100893          	li	a7,17
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 588:	01200893          	li	a7,18
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 594:	00800893          	li	a7,8
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <link>:
.global link
link:
 li a7, SYS_link
 5a0:	01300893          	li	a7,19
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 5ac:	01400893          	li	a7,20
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 5b8:	00900893          	li	a7,9
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <dup>:
.global dup
dup:
 li a7, SYS_dup
 5c4:	00a00893          	li	a7,10
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 5d0:	00b00893          	li	a7,11
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 5dc:	00c00893          	li	a7,12
 ecall
 5e0:	00000073          	ecall
 ret
 5e4:	00008067          	ret

00000000000005e8 <pause>:
.global pause
pause:
 li a7, SYS_pause
 5e8:	00d00893          	li	a7,13
 ecall
 5ec:	00000073          	ecall
 ret
 5f0:	00008067          	ret

00000000000005f4 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 5f4:	00e00893          	li	a7,14
 ecall
 5f8:	00000073          	ecall
 ret
 5fc:	00008067          	ret

0000000000000600 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 600:	00001617          	auipc	a2,0x1
 604:	a1062603          	lw	a2,-1520(a2) # 1010 <putc_n>
 608:	00c04463          	bgtz	a2,610 <putc_flush+0x10>
 60c:	00008067          	ret
{
 610:	ff010113          	addi	sp,sp,-16
 614:	00113423          	sd	ra,8(sp)
 618:	00813023          	sd	s0,0(sp)
 61c:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 620:	00001597          	auipc	a1,0x1
 624:	a0058593          	addi	a1,a1,-1536 # 1020 <putc_buf>
 628:	00001517          	auipc	a0,0x1
 62c:	9d852503          	lw	a0,-1576(a0) # 1000 <putc_fd>
 630:	f11ff0ef          	jal	540 <write>
    putc_n = 0;
 634:	00001797          	auipc	a5,0x1
 638:	9c07ae23          	sw	zero,-1572(a5) # 1010 <putc_n>
  }
}
 63c:	00813083          	ld	ra,8(sp)
 640:	00013403          	ld	s0,0(sp)
 644:	01010113          	addi	sp,sp,16
 648:	00008067          	ret

000000000000064c <putc>:

static void
putc(int fd, char c)
{
 64c:	fe010113          	addi	sp,sp,-32
 650:	00113c23          	sd	ra,24(sp)
 654:	00813823          	sd	s0,16(sp)
 658:	00913423          	sd	s1,8(sp)
 65c:	02010413          	addi	s0,sp,32
 660:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 664:	00001797          	auipc	a5,0x1
 668:	99c7a783          	lw	a5,-1636(a5) # 1000 <putc_fd>
 66c:	04a79663          	bne	a5,a0,6b8 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 670:	00001717          	auipc	a4,0x1
 674:	9a070713          	addi	a4,a4,-1632 # 1010 <putc_n>
 678:	00072683          	lw	a3,0(a4)
 67c:	0016879b          	addiw	a5,a3,1
 680:	00f72023          	sw	a5,0(a4)
 684:	00001717          	auipc	a4,0x1
 688:	99c70713          	addi	a4,a4,-1636 # 1020 <putc_buf>
 68c:	00d70733          	add	a4,a4,a3
 690:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 694:	ff648493          	addi	s1,s1,-10
 698:	02048e63          	beqz	s1,6d4 <putc+0x88>
 69c:	f8078793          	addi	a5,a5,-128
 6a0:	02078a63          	beqz	a5,6d4 <putc+0x88>
    putc_flush();
}
 6a4:	01813083          	ld	ra,24(sp)
 6a8:	01013403          	ld	s0,16(sp)
 6ac:	00813483          	ld	s1,8(sp)
 6b0:	02010113          	addi	sp,sp,32
 6b4:	00008067          	ret
 6b8:	01213023          	sd	s2,0(sp)
 6bc:	00050913          	mv	s2,a0
    putc_flush();
 6c0:	f41ff0ef          	jal	600 <putc_flush>
    putc_fd = fd;
 6c4:	00001797          	auipc	a5,0x1
 6c8:	9327ae23          	sw	s2,-1732(a5) # 1000 <putc_fd>
 6cc:	00013903          	ld	s2,0(sp)
 6d0:	fa1ff06f          	j	670 <putc+0x24>
    putc_flush();
 6d4:	f2dff0ef          	jal	600 <putc_flush>
}
 6d8:	fcdff06f          	j	6a4 <putc+0x58>

00000000000006dc <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 6dc:	fb010113          	addi	sp,sp,-80
 6e0:	04113423          	sd	ra,72(sp)
 6e4:	04813023          	sd	s0,64(sp)
 6e8:	03213823          	sd	s2,48(sp)
 6ec:	03313423          	sd	s3,40(sp)
 6f0:	05010413          	addi	s0,sp,80
 6f4:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 6f8:	0a068e63          	beqz	a3,7b4 <printint+0xd8>
 6fc:	0a05dc63          	bgez	a1,7b4 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 700:	40b005b3          	neg	a1,a1
    neg = 1;
 704:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 708:	fb840993          	addi	s3,s0,-72
  neg = 0;
 70c:	00098693          	mv	a3,s3
  i = 0;
 710:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 714:	00000817          	auipc	a6,0x0
 718:	76480813          	addi	a6,a6,1892 # e78 <digits>
 71c:	00070893          	mv	a7,a4
 720:	0017051b          	addiw	a0,a4,1
 724:	00050713          	mv	a4,a0
 728:	02c5f7b3          	remu	a5,a1,a2
 72c:	00f807b3          	add	a5,a6,a5
 730:	0007c783          	lbu	a5,0(a5)
 734:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 738:	00058793          	mv	a5,a1
 73c:	02c5d5b3          	divu	a1,a1,a2
 740:	00168693          	addi	a3,a3,1
 744:	fcc7fce3          	bgeu	a5,a2,71c <printint+0x40>
  if (neg)
 748:	00030c63          	beqz	t1,760 <printint+0x84>
    buf[i++] = '-';
 74c:	fd050793          	addi	a5,a0,-48
 750:	00878533          	add	a0,a5,s0
 754:	02d00793          	li	a5,45
 758:	fef50423          	sb	a5,-24(a0)
 75c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 760:	02e05e63          	blez	a4,79c <printint+0xc0>
 764:	02913c23          	sd	s1,56(sp)
 768:	fff7071b          	addiw	a4,a4,-1
 76c:	00e984b3          	add	s1,s3,a4
 770:	fff98993          	addi	s3,s3,-1
 774:	00e989b3          	add	s3,s3,a4
 778:	02071713          	slli	a4,a4,0x20
 77c:	02075713          	srli	a4,a4,0x20
 780:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 784:	0004c583          	lbu	a1,0(s1)
 788:	00090513          	mv	a0,s2
 78c:	ec1ff0ef          	jal	64c <putc>
  while (--i >= 0)
 790:	fff48493          	addi	s1,s1,-1
 794:	ff3498e3          	bne	s1,s3,784 <printint+0xa8>
 798:	03813483          	ld	s1,56(sp)
}
 79c:	04813083          	ld	ra,72(sp)
 7a0:	04013403          	ld	s0,64(sp)
 7a4:	03013903          	ld	s2,48(sp)
 7a8:	02813983          	ld	s3,40(sp)
 7ac:	05010113          	addi	sp,sp,80
 7b0:	00008067          	ret
  neg = 0;
 7b4:	00000313          	li	t1,0
 7b8:	f51ff06f          	j	708 <printint+0x2c>

00000000000007bc <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 7bc:	fa010113          	addi	sp,sp,-96
 7c0:	04113c23          	sd	ra,88(sp)
 7c4:	04813823          	sd	s0,80(sp)
 7c8:	04913423          	sd	s1,72(sp)
 7cc:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 7d0:	0005c483          	lbu	s1,0(a1)
 7d4:	32048263          	beqz	s1,af8 <vprintf+0x33c>
 7d8:	05213023          	sd	s2,64(sp)
 7dc:	03313c23          	sd	s3,56(sp)
 7e0:	03413823          	sd	s4,48(sp)
 7e4:	03513423          	sd	s5,40(sp)
 7e8:	03613023          	sd	s6,32(sp)
 7ec:	01713c23          	sd	s7,24(sp)
 7f0:	01813823          	sd	s8,16(sp)
 7f4:	00050b13          	mv	s6,a0
 7f8:	00058a13          	mv	s4,a1
 7fc:	00060b93          	mv	s7,a2
  state = 0;
 800:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 804:	00000913          	li	s2,0
 808:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 80c:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 810:	06400c13          	li	s8,100
 814:	0300006f          	j	844 <vprintf+0x88>
        putc(fd, c0);
 818:	00048593          	mv	a1,s1
 81c:	000b0513          	mv	a0,s6
 820:	e2dff0ef          	jal	64c <putc>
 824:	0080006f          	j	82c <vprintf+0x70>
    else if (state == '%')
 828:	03598863          	beq	s3,s5,858 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 82c:	0019079b          	addiw	a5,s2,1
 830:	00078913          	mv	s2,a5
 834:	00078713          	mv	a4,a5
 838:	00fa07b3          	add	a5,s4,a5
 83c:	0007c483          	lbu	s1,0(a5)
 840:	28048e63          	beqz	s1,adc <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 844:	0004879b          	sext.w	a5,s1
    if (state == 0)
 848:	fe0990e3          	bnez	s3,828 <vprintf+0x6c>
      if (c0 == '%')
 84c:	fd5796e3          	bne	a5,s5,818 <vprintf+0x5c>
        state = '%';
 850:	00078993          	mv	s3,a5
 854:	fd9ff06f          	j	82c <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 858:	00ea06b3          	add	a3,s4,a4
 85c:	0016c603          	lbu	a2,1(a3)
      if (c1)
 860:	2a060663          	beqz	a2,b0c <vprintf+0x350>
      if (c0 == 'd')
 864:	05878063          	beq	a5,s8,8a4 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 868:	f9478693          	addi	a3,a5,-108
 86c:	0016b693          	seqz	a3,a3
 870:	f9c60593          	addi	a1,a2,-100
 874:	04059a63          	bnez	a1,8c8 <vprintf+0x10c>
 878:	04068863          	beqz	a3,8c8 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 87c:	008b8493          	addi	s1,s7,8
 880:	00100693          	li	a3,1
 884:	00a00613          	li	a2,10
 888:	000bb583          	ld	a1,0(s7)
 88c:	000b0513          	mv	a0,s6
 890:	e4dff0ef          	jal	6dc <printint>
        i += 1;
 894:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 898:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 89c:	00000993          	li	s3,0
 8a0:	f8dff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 8a4:	008b8493          	addi	s1,s7,8
 8a8:	00100693          	li	a3,1
 8ac:	00a00613          	li	a2,10
 8b0:	000ba583          	lw	a1,0(s7)
 8b4:	000b0513          	mv	a0,s6
 8b8:	e25ff0ef          	jal	6dc <printint>
 8bc:	00048b93          	mv	s7,s1
      state = 0;
 8c0:	00000993          	li	s3,0
 8c4:	f69ff06f          	j	82c <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 8c8:	00ea0733          	add	a4,s4,a4
 8cc:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 8d0:	f9460713          	addi	a4,a2,-108
 8d4:	00173713          	seqz	a4,a4
 8d8:	00e6f733          	and	a4,a3,a4
 8dc:	f9c58513          	addi	a0,a1,-100
 8e0:	24051263          	bnez	a0,b24 <vprintf+0x368>
 8e4:	24070063          	beqz	a4,b24 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 8e8:	008b8493          	addi	s1,s7,8
 8ec:	00100693          	li	a3,1
 8f0:	00a00613          	li	a2,10
 8f4:	000bb583          	ld	a1,0(s7)
 8f8:	000b0513          	mv	a0,s6
 8fc:	de1ff0ef          	jal	6dc <printint>
        i += 2;
 900:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 904:	00048b93          	mv	s7,s1
      state = 0;
 908:	00000993          	li	s3,0
        i += 2;
 90c:	f21ff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 910:	008b8493          	addi	s1,s7,8
 914:	00000693          	li	a3,0
 918:	00a00613          	li	a2,10
 91c:	000be583          	lwu	a1,0(s7)
 920:	000b0513          	mv	a0,s6
 924:	db9ff0ef          	jal	6dc <printint>
 928:	00048b93          	mv	s7,s1
      state = 0;
 92c:	00000993          	li	s3,0
 930:	efdff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 934:	008b8493          	addi	s1,s7,8
 938:	00000693          	li	a3,0
 93c:	00a00613          	li	a2,10
 940:	000bb583          	ld	a1,0(s7)
 944:	000b0513          	mv	a0,s6
 948:	d95ff0ef          	jal	6dc <printint>
        i += 1;
 94c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 950:	00048b93          	mv	s7,s1
      state = 0;
 954:	00000993          	li	s3,0
 958:	ed5ff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 95c:	008b8493          	addi	s1,s7,8
 960:	00000693          	li	a3,0
 964:	00a00613          	li	a2,10
 968:	000bb583          	ld	a1,0(s7)
 96c:	000b0513          	mv	a0,s6
 970:	d6dff0ef          	jal	6dc <printint>
        i += 2;
 974:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 978:	00048b93          	mv	s7,s1
      state = 0;
 97c:	00000993          	li	s3,0
        i += 2;
 980:	eadff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 984:	008b8493          	addi	s1,s7,8
 988:	00000693          	li	a3,0
 98c:	01000613          	li	a2,16
 990:	000be583          	lwu	a1,0(s7)
 994:	000b0513          	mv	a0,s6
 998:	d45ff0ef          	jal	6dc <printint>
 99c:	00048b93          	mv	s7,s1
      state = 0;
 9a0:	00000993          	li	s3,0
 9a4:	e89ff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9a8:	008b8493          	addi	s1,s7,8
 9ac:	00000693          	li	a3,0
 9b0:	01000613          	li	a2,16
 9b4:	000bb583          	ld	a1,0(s7)
 9b8:	000b0513          	mv	a0,s6
 9bc:	d21ff0ef          	jal	6dc <printint>
        i += 1;
 9c0:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 9c4:	00048b93          	mv	s7,s1
      state = 0;
 9c8:	00000993          	li	s3,0
 9cc:	e61ff06f          	j	82c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9d0:	008b8493          	addi	s1,s7,8
 9d4:	00000693          	li	a3,0
 9d8:	01000613          	li	a2,16
 9dc:	000bb583          	ld	a1,0(s7)
 9e0:	000b0513          	mv	a0,s6
 9e4:	cf9ff0ef          	jal	6dc <printint>
        i += 2;
 9e8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 9ec:	00048b93          	mv	s7,s1
      state = 0;
 9f0:	00000993          	li	s3,0
        i += 2;
 9f4:	e39ff06f          	j	82c <vprintf+0x70>
 9f8:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 9fc:	008b8793          	addi	a5,s7,8
 a00:	00078c93          	mv	s9,a5
 a04:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 a08:	03000593          	li	a1,48
 a0c:	000b0513          	mv	a0,s6
 a10:	c3dff0ef          	jal	64c <putc>
  putc(fd, 'x');
 a14:	07800593          	li	a1,120
 a18:	000b0513          	mv	a0,s6
 a1c:	c31ff0ef          	jal	64c <putc>
 a20:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a24:	00000b97          	auipc	s7,0x0
 a28:	454b8b93          	addi	s7,s7,1108 # e78 <digits>
 a2c:	03c9d793          	srli	a5,s3,0x3c
 a30:	00fb87b3          	add	a5,s7,a5
 a34:	0007c583          	lbu	a1,0(a5)
 a38:	000b0513          	mv	a0,s6
 a3c:	c11ff0ef          	jal	64c <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a40:	00499993          	slli	s3,s3,0x4
 a44:	fff4849b          	addiw	s1,s1,-1
 a48:	fe0492e3          	bnez	s1,a2c <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a4c:	000c8b93          	mv	s7,s9
      state = 0;
 a50:	00000993          	li	s3,0
 a54:	00813c83          	ld	s9,8(sp)
 a58:	dd5ff06f          	j	82c <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a5c:	008b8493          	addi	s1,s7,8
 a60:	000bc583          	lbu	a1,0(s7)
 a64:	000b0513          	mv	a0,s6
 a68:	be5ff0ef          	jal	64c <putc>
 a6c:	00048b93          	mv	s7,s1
      state = 0;
 a70:	00000993          	li	s3,0
 a74:	db9ff06f          	j	82c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a78:	008b8993          	addi	s3,s7,8
 a7c:	000bb483          	ld	s1,0(s7)
 a80:	02048663          	beqz	s1,aac <vprintf+0x2f0>
        for (; *s; s++)
 a84:	0004c583          	lbu	a1,0(s1)
 a88:	04058463          	beqz	a1,ad0 <vprintf+0x314>
          putc(fd, *s);
 a8c:	000b0513          	mv	a0,s6
 a90:	bbdff0ef          	jal	64c <putc>
        for (; *s; s++)
 a94:	00148493          	addi	s1,s1,1
 a98:	0004c583          	lbu	a1,0(s1)
 a9c:	fe0598e3          	bnez	a1,a8c <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 aa0:	00098b93          	mv	s7,s3
      state = 0;
 aa4:	00000993          	li	s3,0
 aa8:	d85ff06f          	j	82c <vprintf+0x70>
          s = "(null)";
 aac:	00000497          	auipc	s1,0x0
 ab0:	3c448493          	addi	s1,s1,964 # e70 <malloc+0x17c>
        for (; *s; s++)
 ab4:	02800593          	li	a1,40
 ab8:	fd5ff06f          	j	a8c <vprintf+0x2d0>
        putc(fd, '%');
 abc:	00078593          	mv	a1,a5
 ac0:	000b0513          	mv	a0,s6
 ac4:	b89ff0ef          	jal	64c <putc>
      state = 0;
 ac8:	00000993          	li	s3,0
 acc:	d61ff06f          	j	82c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 ad0:	00098b93          	mv	s7,s3
      state = 0;
 ad4:	00000993          	li	s3,0
 ad8:	d55ff06f          	j	82c <vprintf+0x70>
 adc:	04013903          	ld	s2,64(sp)
 ae0:	03813983          	ld	s3,56(sp)
 ae4:	03013a03          	ld	s4,48(sp)
 ae8:	02813a83          	ld	s5,40(sp)
 aec:	02013b03          	ld	s6,32(sp)
 af0:	01813b83          	ld	s7,24(sp)
 af4:	01013c03          	ld	s8,16(sp)
    }
  }
}
 af8:	05813083          	ld	ra,88(sp)
 afc:	05013403          	ld	s0,80(sp)
 b00:	04813483          	ld	s1,72(sp)
 b04:	06010113          	addi	sp,sp,96
 b08:	00008067          	ret
      if (c0 == 'd')
 b0c:	06400713          	li	a4,100
 b10:	d8e78ae3          	beq	a5,a4,8a4 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 b14:	f9478693          	addi	a3,a5,-108
 b18:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 b1c:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 b20:	00000713          	li	a4,0
      else if (c0 == 'u')
 b24:	07500513          	li	a0,117
 b28:	dea784e3          	beq	a5,a0,910 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b2c:	f8b60513          	addi	a0,a2,-117
 b30:	00051463          	bnez	a0,b38 <vprintf+0x37c>
 b34:	e00690e3          	bnez	a3,934 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 b38:	f8b58513          	addi	a0,a1,-117
 b3c:	00051463          	bnez	a0,b44 <vprintf+0x388>
 b40:	e0071ee3          	bnez	a4,95c <vprintf+0x1a0>
      else if (c0 == 'x')
 b44:	07800513          	li	a0,120
 b48:	e2a78ee3          	beq	a5,a0,984 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b4c:	f8860613          	addi	a2,a2,-120
 b50:	00061463          	bnez	a2,b58 <vprintf+0x39c>
 b54:	e4069ae3          	bnez	a3,9a8 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b58:	f8858593          	addi	a1,a1,-120
 b5c:	00059463          	bnez	a1,b64 <vprintf+0x3a8>
 b60:	e60718e3          	bnez	a4,9d0 <vprintf+0x214>
      else if (c0 == 'p')
 b64:	07000713          	li	a4,112
 b68:	e8e788e3          	beq	a5,a4,9f8 <vprintf+0x23c>
      else if (c0 == 'c')
 b6c:	06300713          	li	a4,99
 b70:	eee786e3          	beq	a5,a4,a5c <vprintf+0x2a0>
      else if (c0 == 's')
 b74:	07300713          	li	a4,115
 b78:	f0e780e3          	beq	a5,a4,a78 <vprintf+0x2bc>
      else if (c0 == '%')
 b7c:	02500713          	li	a4,37
 b80:	f2e78ee3          	beq	a5,a4,abc <vprintf+0x300>
        putc(fd, '%');
 b84:	02500593          	li	a1,37
 b88:	000b0513          	mv	a0,s6
 b8c:	ac1ff0ef          	jal	64c <putc>
        putc(fd, c0);
 b90:	00048593          	mv	a1,s1
 b94:	000b0513          	mv	a0,s6
 b98:	ab5ff0ef          	jal	64c <putc>
      state = 0;
 b9c:	00000993          	li	s3,0
 ba0:	c8dff06f          	j	82c <vprintf+0x70>

0000000000000ba4 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 ba4:	fb010113          	addi	sp,sp,-80
 ba8:	00113c23          	sd	ra,24(sp)
 bac:	00813823          	sd	s0,16(sp)
 bb0:	02010413          	addi	s0,sp,32
 bb4:	00c43023          	sd	a2,0(s0)
 bb8:	00d43423          	sd	a3,8(s0)
 bbc:	00e43823          	sd	a4,16(s0)
 bc0:	00f43c23          	sd	a5,24(s0)
 bc4:	03043023          	sd	a6,32(s0)
 bc8:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 bcc:	00040613          	mv	a2,s0
 bd0:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 bd4:	be9ff0ef          	jal	7bc <vprintf>
}
 bd8:	01813083          	ld	ra,24(sp)
 bdc:	01013403          	ld	s0,16(sp)
 be0:	05010113          	addi	sp,sp,80
 be4:	00008067          	ret

0000000000000be8 <printf>:

void printf(const char *fmt, ...)
{
 be8:	fa010113          	addi	sp,sp,-96
 bec:	00113c23          	sd	ra,24(sp)
 bf0:	00813823          	sd	s0,16(sp)
 bf4:	02010413          	addi	s0,sp,32
 bf8:	00b43423          	sd	a1,8(s0)
 bfc:	00c43823          	sd	a2,16(s0)
 c00:	00d43c23          	sd	a3,24(s0)
 c04:	02e43023          	sd	a4,32(s0)
 c08:	02f43423          	sd	a5,40(s0)
 c0c:	03043823          	sd	a6,48(s0)
 c10:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 c14:	00840613          	addi	a2,s0,8
 c18:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 c1c:	00050593          	mv	a1,a0
 c20:	00100513          	li	a0,1
 c24:	b99ff0ef          	jal	7bc <vprintf>
  putc_flush();
 c28:	9d9ff0ef          	jal	600 <putc_flush>
}
 c2c:	01813083          	ld	ra,24(sp)
 c30:	01013403          	ld	s0,16(sp)
 c34:	06010113          	addi	sp,sp,96
 c38:	00008067          	ret

0000000000000c3c <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c3c:	ff010113          	addi	sp,sp,-16
 c40:	00113423          	sd	ra,8(sp)
 c44:	00813023          	sd	s0,0(sp)
 c48:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c4c:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c50:	00000797          	auipc	a5,0x0
 c54:	3c87b783          	ld	a5,968(a5) # 1018 <freep>
 c58:	0140006f          	j	c6c <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c5c:	0007b703          	ld	a4,0(a5)
 c60:	00e7e463          	bltu	a5,a4,c68 <free+0x2c>
 c64:	00e6ec63          	bltu	a3,a4,c7c <free+0x40>
{
 c68:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c6c:	fed7f8e3          	bgeu	a5,a3,c5c <free+0x20>
 c70:	0007b703          	ld	a4,0(a5)
 c74:	00e6e463          	bltu	a3,a4,c7c <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c78:	fee7e8e3          	bltu	a5,a4,c68 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 c7c:	ff852583          	lw	a1,-8(a0)
 c80:	0007b603          	ld	a2,0(a5)
 c84:	02059813          	slli	a6,a1,0x20
 c88:	01c85713          	srli	a4,a6,0x1c
 c8c:	00e68733          	add	a4,a3,a4
 c90:	02e60c63          	beq	a2,a4,cc8 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c94:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c98:	0087a603          	lw	a2,8(a5)
 c9c:	02061593          	slli	a1,a2,0x20
 ca0:	01c5d713          	srli	a4,a1,0x1c
 ca4:	00e78733          	add	a4,a5,a4
 ca8:	02e68c63          	beq	a3,a4,ce0 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 cac:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 cb0:	00000717          	auipc	a4,0x0
 cb4:	36f73423          	sd	a5,872(a4) # 1018 <freep>
}
 cb8:	00813083          	ld	ra,8(sp)
 cbc:	00013403          	ld	s0,0(sp)
 cc0:	01010113          	addi	sp,sp,16
 cc4:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 cc8:	00862703          	lw	a4,8(a2)
 ccc:	00b7073b          	addw	a4,a4,a1
 cd0:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 cd4:	0007b703          	ld	a4,0(a5)
 cd8:	00073603          	ld	a2,0(a4)
 cdc:	fb9ff06f          	j	c94 <free+0x58>
    p->s.size += bp->s.size;
 ce0:	ff852703          	lw	a4,-8(a0)
 ce4:	00c7073b          	addw	a4,a4,a2
 ce8:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 cec:	ff053683          	ld	a3,-16(a0)
 cf0:	fbdff06f          	j	cac <free+0x70>

0000000000000cf4 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 cf4:	fc010113          	addi	sp,sp,-64
 cf8:	02113c23          	sd	ra,56(sp)
 cfc:	02813823          	sd	s0,48(sp)
 d00:	03213023          	sd	s2,32(sp)
 d04:	01313c23          	sd	s3,24(sp)
 d08:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 d0c:	02051993          	slli	s3,a0,0x20
 d10:	0209d993          	srli	s3,s3,0x20
 d14:	00f98993          	addi	s3,s3,15
 d18:	0049d993          	srli	s3,s3,0x4
 d1c:	0019899b          	addiw	s3,s3,1
 d20:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d24:	00000517          	auipc	a0,0x0
 d28:	2f453503          	ld	a0,756(a0) # 1018 <freep>
 d2c:	04050463          	beqz	a0,d74 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d30:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d34:	0087a703          	lw	a4,8(a5)
 d38:	0d377a63          	bgeu	a4,s3,e0c <malloc+0x118>
 d3c:	02913423          	sd	s1,40(sp)
 d40:	01413823          	sd	s4,16(sp)
 d44:	01513423          	sd	s5,8(sp)
 d48:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d4c:	00098a13          	mv	s4,s3
 d50:	00001737          	lui	a4,0x1
 d54:	00e9f463          	bgeu	s3,a4,d5c <malloc+0x68>
 d58:	00001a37          	lui	s4,0x1
 d5c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d60:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d64:	00000497          	auipc	s1,0x0
 d68:	2b448493          	addi	s1,s1,692 # 1018 <freep>
  if(p == SBRK_ERROR)
 d6c:	fff00a93          	li	s5,-1
 d70:	05c0006f          	j	dcc <malloc+0xd8>
 d74:	02913423          	sd	s1,40(sp)
 d78:	01413823          	sd	s4,16(sp)
 d7c:	01513423          	sd	s5,8(sp)
 d80:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d84:	00000797          	auipc	a5,0x0
 d88:	31c78793          	addi	a5,a5,796 # 10a0 <base>
 d8c:	00000717          	auipc	a4,0x0
 d90:	28f73623          	sd	a5,652(a4) # 1018 <freep>
 d94:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d98:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d9c:	fb1ff06f          	j	d4c <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 da0:	0007b703          	ld	a4,0(a5)
 da4:	00e53023          	sd	a4,0(a0)
 da8:	0800006f          	j	e28 <malloc+0x134>
  hp->s.size = nu;
 dac:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 db0:	01050513          	addi	a0,a0,16
 db4:	e89ff0ef          	jal	c3c <free>
  return freep;
 db8:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 dbc:	08050863          	beqz	a0,e4c <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 dc0:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 dc4:	0087a703          	lw	a4,8(a5)
 dc8:	03277a63          	bgeu	a4,s2,dfc <malloc+0x108>
    if(p == freep)
 dcc:	0004b703          	ld	a4,0(s1)
 dd0:	00078513          	mv	a0,a5
 dd4:	fef716e3          	bne	a4,a5,dc0 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 dd8:	000a0513          	mv	a0,s4
 ddc:	ed8ff0ef          	jal	4b4 <sbrk>
  if(p == SBRK_ERROR)
 de0:	fd5516e3          	bne	a0,s5,dac <malloc+0xb8>
        return 0;
 de4:	00000513          	li	a0,0
 de8:	02813483          	ld	s1,40(sp)
 dec:	01013a03          	ld	s4,16(sp)
 df0:	00813a83          	ld	s5,8(sp)
 df4:	00013b03          	ld	s6,0(sp)
 df8:	03c0006f          	j	e34 <malloc+0x140>
 dfc:	02813483          	ld	s1,40(sp)
 e00:	01013a03          	ld	s4,16(sp)
 e04:	00813a83          	ld	s5,8(sp)
 e08:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 e0c:	f8e90ae3          	beq	s2,a4,da0 <malloc+0xac>
        p->s.size -= nunits;
 e10:	4137073b          	subw	a4,a4,s3
 e14:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 e18:	02071693          	slli	a3,a4,0x20
 e1c:	01c6d713          	srli	a4,a3,0x1c
 e20:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e24:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e28:	00000717          	auipc	a4,0x0
 e2c:	1ea73823          	sd	a0,496(a4) # 1018 <freep>
      return (void*)(p + 1);
 e30:	01078513          	addi	a0,a5,16
  }
}
 e34:	03813083          	ld	ra,56(sp)
 e38:	03013403          	ld	s0,48(sp)
 e3c:	02013903          	ld	s2,32(sp)
 e40:	01813983          	ld	s3,24(sp)
 e44:	04010113          	addi	sp,sp,64
 e48:	00008067          	ret
 e4c:	02813483          	ld	s1,40(sp)
 e50:	01013a03          	ld	s4,16(sp)
 e54:	00813a83          	ld	s5,8(sp)
 e58:	00013b03          	ld	s6,0(sp)
 e5c:	fd9ff06f          	j	e34 <malloc+0x140>
