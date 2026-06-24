
user/_kill:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
   0:	fe010113          	addi	sp,sp,-32
   4:	00113c23          	sd	ra,24(sp)
   8:	00813823          	sd	s0,16(sp)
   c:	02010413          	addi	s0,sp,32
  int i;

  if(argc < 2){
  10:	00100793          	li	a5,1
  14:	04a7d063          	bge	a5,a0,54 <main+0x54>
  18:	00913423          	sd	s1,8(sp)
  1c:	01213023          	sd	s2,0(sp)
  20:	00858493          	addi	s1,a1,8
  24:	ffe5091b          	addiw	s2,a0,-2
  28:	02091793          	slli	a5,s2,0x20
  2c:	01d7d913          	srli	s2,a5,0x1d
  30:	01058593          	addi	a1,a1,16
  34:	00b90933          	add	s2,s2,a1
    fprintf(2, "usage: kill pid...\n");
    exit(1);
  }
  for(i=1; i<argc; i++)
    kill(atoi(argv[i]));
  38:	0004b503          	ld	a0,0(s1)
  3c:	2cc000ef          	jal	308 <atoi>
  40:	4dc000ef          	jal	51c <kill>
  for(i=1; i<argc; i++)
  44:	00848493          	addi	s1,s1,8
  48:	ff2498e3          	bne	s1,s2,38 <main+0x38>
  exit(0);
  4c:	00000513          	li	a0,0
  50:	484000ef          	jal	4d4 <exit>
  54:	00913423          	sd	s1,8(sp)
  58:	01213023          	sd	s2,0(sp)
    fprintf(2, "usage: kill pid...\n");
  5c:	00001597          	auipc	a1,0x1
  60:	dd458593          	addi	a1,a1,-556 # e30 <malloc+0x178>
  64:	00200513          	li	a0,2
  68:	301000ef          	jal	b68 <fprintf>
    exit(1);
  6c:	00100513          	li	a0,1
  70:	464000ef          	jal	4d4 <exit>

0000000000000074 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  74:	ff010113          	addi	sp,sp,-16
  78:	00113423          	sd	ra,8(sp)
  7c:	00813023          	sd	s0,0(sp)
  80:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  84:	f7dff0ef          	jal	0 <main>
  exit(r);
  88:	44c000ef          	jal	4d4 <exit>

000000000000008c <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  8c:	ff010113          	addi	sp,sp,-16
  90:	00113423          	sd	ra,8(sp)
  94:	00813023          	sd	s0,0(sp)
  98:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  9c:	00050793          	mv	a5,a0
  a0:	00158593          	addi	a1,a1,1
  a4:	00178793          	addi	a5,a5,1
  a8:	fff5c703          	lbu	a4,-1(a1)
  ac:	fee78fa3          	sb	a4,-1(a5)
  b0:	fe0718e3          	bnez	a4,a0 <strcpy+0x14>
    ;
  return os;
}
  b4:	00813083          	ld	ra,8(sp)
  b8:	00013403          	ld	s0,0(sp)
  bc:	01010113          	addi	sp,sp,16
  c0:	00008067          	ret

00000000000000c4 <strcmp>:

int
strcmp(const char *p, const char *q)
{
  c4:	ff010113          	addi	sp,sp,-16
  c8:	00113423          	sd	ra,8(sp)
  cc:	00813023          	sd	s0,0(sp)
  d0:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
  d4:	00054783          	lbu	a5,0(a0)
  d8:	00078e63          	beqz	a5,f4 <strcmp+0x30>
  dc:	0005c703          	lbu	a4,0(a1)
  e0:	00f71a63          	bne	a4,a5,f4 <strcmp+0x30>
    p++, q++;
  e4:	00150513          	addi	a0,a0,1
  e8:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
  ec:	00054783          	lbu	a5,0(a0)
  f0:	fe0796e3          	bnez	a5,dc <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
  f4:	0005c503          	lbu	a0,0(a1)
}
  f8:	40a7853b          	subw	a0,a5,a0
  fc:	00813083          	ld	ra,8(sp)
 100:	00013403          	ld	s0,0(sp)
 104:	01010113          	addi	sp,sp,16
 108:	00008067          	ret

000000000000010c <strlen>:

uint
strlen(const char *s)
{
 10c:	ff010113          	addi	sp,sp,-16
 110:	00113423          	sd	ra,8(sp)
 114:	00813023          	sd	s0,0(sp)
 118:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 11c:	00054783          	lbu	a5,0(a0)
 120:	02078663          	beqz	a5,14c <strlen+0x40>
 124:	00150793          	addi	a5,a0,1
 128:	00078693          	mv	a3,a5
 12c:	00178793          	addi	a5,a5,1
 130:	fff7c703          	lbu	a4,-1(a5)
 134:	fe071ae3          	bnez	a4,128 <strlen+0x1c>
 138:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 13c:	00813083          	ld	ra,8(sp)
 140:	00013403          	ld	s0,0(sp)
 144:	01010113          	addi	sp,sp,16
 148:	00008067          	ret
  for(n = 0; s[n]; n++)
 14c:	00000513          	li	a0,0
 150:	fedff06f          	j	13c <strlen+0x30>

0000000000000154 <memset>:

void*
memset(void *dst, int c, uint n)
{
 154:	ff010113          	addi	sp,sp,-16
 158:	00113423          	sd	ra,8(sp)
 15c:	00813023          	sd	s0,0(sp)
 160:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 164:	02060063          	beqz	a2,184 <memset+0x30>
 168:	00050793          	mv	a5,a0
 16c:	02061613          	slli	a2,a2,0x20
 170:	02065613          	srli	a2,a2,0x20
 174:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 178:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 17c:	00178793          	addi	a5,a5,1
 180:	fee79ce3          	bne	a5,a4,178 <memset+0x24>
  }
  return dst;
}
 184:	00813083          	ld	ra,8(sp)
 188:	00013403          	ld	s0,0(sp)
 18c:	01010113          	addi	sp,sp,16
 190:	00008067          	ret

0000000000000194 <strchr>:

char*
strchr(const char *s, char c)
{
 194:	ff010113          	addi	sp,sp,-16
 198:	00113423          	sd	ra,8(sp)
 19c:	00813023          	sd	s0,0(sp)
 1a0:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 1a4:	00054783          	lbu	a5,0(a0)
 1a8:	02078463          	beqz	a5,1d0 <strchr+0x3c>
    if(*s == c)
 1ac:	00f58a63          	beq	a1,a5,1c0 <strchr+0x2c>
  for(; *s; s++)
 1b0:	00150513          	addi	a0,a0,1
 1b4:	00054783          	lbu	a5,0(a0)
 1b8:	fe079ae3          	bnez	a5,1ac <strchr+0x18>
      return (char*)s;
  return 0;
 1bc:	00000513          	li	a0,0
}
 1c0:	00813083          	ld	ra,8(sp)
 1c4:	00013403          	ld	s0,0(sp)
 1c8:	01010113          	addi	sp,sp,16
 1cc:	00008067          	ret
  return 0;
 1d0:	00000513          	li	a0,0
 1d4:	fedff06f          	j	1c0 <strchr+0x2c>

00000000000001d8 <gets>:

char*
gets(char *buf, int max)
{
 1d8:	fa010113          	addi	sp,sp,-96
 1dc:	04113c23          	sd	ra,88(sp)
 1e0:	04813823          	sd	s0,80(sp)
 1e4:	04913423          	sd	s1,72(sp)
 1e8:	05213023          	sd	s2,64(sp)
 1ec:	03313c23          	sd	s3,56(sp)
 1f0:	03413823          	sd	s4,48(sp)
 1f4:	03513423          	sd	s5,40(sp)
 1f8:	03613023          	sd	s6,32(sp)
 1fc:	01713c23          	sd	s7,24(sp)
 200:	01813823          	sd	s8,16(sp)
 204:	06010413          	addi	s0,sp,96
 208:	00050b93          	mv	s7,a0
 20c:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 210:	00050913          	mv	s2,a0
 214:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 218:	faf40b13          	addi	s6,s0,-81
 21c:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 220:	00048c13          	mv	s8,s1
 224:	0014899b          	addiw	s3,s1,1
 228:	00098493          	mv	s1,s3
 22c:	0349dc63          	bge	s3,s4,264 <gets+0x8c>
    cc = read(0, &c, 1);
 230:	000a8613          	mv	a2,s5
 234:	000b0593          	mv	a1,s6
 238:	00000513          	li	a0,0
 23c:	2bc000ef          	jal	4f8 <read>
    if(cc < 1)
 240:	02a05263          	blez	a0,264 <gets+0x8c>
      break;
    buf[i++] = c;
 244:	faf44783          	lbu	a5,-81(s0)
 248:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 24c:	00190913          	addi	s2,s2,1
 250:	ff678713          	addi	a4,a5,-10
 254:	00070663          	beqz	a4,260 <gets+0x88>
 258:	ff378793          	addi	a5,a5,-13
 25c:	fc0792e3          	bnez	a5,220 <gets+0x48>
    buf[i++] = c;
 260:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 264:	018b8c33          	add	s8,s7,s8
 268:	000c0023          	sb	zero,0(s8)
  return buf;
}
 26c:	000b8513          	mv	a0,s7
 270:	05813083          	ld	ra,88(sp)
 274:	05013403          	ld	s0,80(sp)
 278:	04813483          	ld	s1,72(sp)
 27c:	04013903          	ld	s2,64(sp)
 280:	03813983          	ld	s3,56(sp)
 284:	03013a03          	ld	s4,48(sp)
 288:	02813a83          	ld	s5,40(sp)
 28c:	02013b03          	ld	s6,32(sp)
 290:	01813b83          	ld	s7,24(sp)
 294:	01013c03          	ld	s8,16(sp)
 298:	06010113          	addi	sp,sp,96
 29c:	00008067          	ret

00000000000002a0 <stat>:

int
stat(const char *n, struct stat *st)
{
 2a0:	fe010113          	addi	sp,sp,-32
 2a4:	00113c23          	sd	ra,24(sp)
 2a8:	00813823          	sd	s0,16(sp)
 2ac:	01213023          	sd	s2,0(sp)
 2b0:	02010413          	addi	s0,sp,32
 2b4:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 2b8:	00000593          	li	a1,0
 2bc:	278000ef          	jal	534 <open>
  if(fd < 0)
 2c0:	02054e63          	bltz	a0,2fc <stat+0x5c>
 2c4:	00913423          	sd	s1,8(sp)
 2c8:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 2cc:	00090593          	mv	a1,s2
 2d0:	288000ef          	jal	558 <fstat>
 2d4:	00050913          	mv	s2,a0
  close(fd);
 2d8:	00048513          	mv	a0,s1
 2dc:	234000ef          	jal	510 <close>
  return r;
 2e0:	00813483          	ld	s1,8(sp)
}
 2e4:	00090513          	mv	a0,s2
 2e8:	01813083          	ld	ra,24(sp)
 2ec:	01013403          	ld	s0,16(sp)
 2f0:	00013903          	ld	s2,0(sp)
 2f4:	02010113          	addi	sp,sp,32
 2f8:	00008067          	ret
    return -1;
 2fc:	fff00793          	li	a5,-1
 300:	00078913          	mv	s2,a5
 304:	fe1ff06f          	j	2e4 <stat+0x44>

0000000000000308 <atoi>:

int
atoi(const char *s)
{
 308:	ff010113          	addi	sp,sp,-16
 30c:	00113423          	sd	ra,8(sp)
 310:	00813023          	sd	s0,0(sp)
 314:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 318:	00054683          	lbu	a3,0(a0)
 31c:	fd06879b          	addiw	a5,a3,-48
 320:	0ff7f793          	zext.b	a5,a5
 324:	00900613          	li	a2,9
 328:	04f66263          	bltu	a2,a5,36c <atoi+0x64>
 32c:	00050713          	mv	a4,a0
  n = 0;
 330:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 334:	00170713          	addi	a4,a4,1
 338:	0025179b          	slliw	a5,a0,0x2
 33c:	00a787bb          	addw	a5,a5,a0
 340:	0017979b          	slliw	a5,a5,0x1
 344:	00d787bb          	addw	a5,a5,a3
 348:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 34c:	00074683          	lbu	a3,0(a4)
 350:	fd06879b          	addiw	a5,a3,-48
 354:	0ff7f793          	zext.b	a5,a5
 358:	fcf67ee3          	bgeu	a2,a5,334 <atoi+0x2c>
  return n;
}
 35c:	00813083          	ld	ra,8(sp)
 360:	00013403          	ld	s0,0(sp)
 364:	01010113          	addi	sp,sp,16
 368:	00008067          	ret
  n = 0;
 36c:	00000513          	li	a0,0
 370:	fedff06f          	j	35c <atoi+0x54>

0000000000000374 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 374:	ff010113          	addi	sp,sp,-16
 378:	00113423          	sd	ra,8(sp)
 37c:	00813023          	sd	s0,0(sp)
 380:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 384:	02b57e63          	bgeu	a0,a1,3c0 <memmove+0x4c>
    while(n-- > 0)
 388:	02c05463          	blez	a2,3b0 <memmove+0x3c>
 38c:	02061613          	slli	a2,a2,0x20
 390:	02065613          	srli	a2,a2,0x20
 394:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 398:	00050713          	mv	a4,a0
      *dst++ = *src++;
 39c:	00158593          	addi	a1,a1,1
 3a0:	00170713          	addi	a4,a4,1
 3a4:	fff5c683          	lbu	a3,-1(a1)
 3a8:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 3ac:	fee798e3          	bne	a5,a4,39c <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 3b0:	00813083          	ld	ra,8(sp)
 3b4:	00013403          	ld	s0,0(sp)
 3b8:	01010113          	addi	sp,sp,16
 3bc:	00008067          	ret
    while(n-- > 0)
 3c0:	fec058e3          	blez	a2,3b0 <memmove+0x3c>
    dst += n;
 3c4:	00c50733          	add	a4,a0,a2
    src += n;
 3c8:	00c585b3          	add	a1,a1,a2
 3cc:	fff6079b          	addiw	a5,a2,-1
 3d0:	02079793          	slli	a5,a5,0x20
 3d4:	0207d793          	srli	a5,a5,0x20
 3d8:	fff7c793          	not	a5,a5
 3dc:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 3e0:	fff58593          	addi	a1,a1,-1
 3e4:	fff70713          	addi	a4,a4,-1
 3e8:	0005c683          	lbu	a3,0(a1)
 3ec:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 3f0:	fef718e3          	bne	a4,a5,3e0 <memmove+0x6c>
 3f4:	fbdff06f          	j	3b0 <memmove+0x3c>

00000000000003f8 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 3f8:	ff010113          	addi	sp,sp,-16
 3fc:	00113423          	sd	ra,8(sp)
 400:	00813023          	sd	s0,0(sp)
 404:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 408:	04060263          	beqz	a2,44c <memcmp+0x54>
 40c:	02061613          	slli	a2,a2,0x20
 410:	02065613          	srli	a2,a2,0x20
 414:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 418:	00054783          	lbu	a5,0(a0)
 41c:	0005c703          	lbu	a4,0(a1)
 420:	00e79c63          	bne	a5,a4,438 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 424:	00150513          	addi	a0,a0,1
    p2++;
 428:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 42c:	fed516e3          	bne	a0,a3,418 <memcmp+0x20>
  }
  return 0;
 430:	00000513          	li	a0,0
 434:	0080006f          	j	43c <memcmp+0x44>
      return *p1 - *p2;
 438:	40e7853b          	subw	a0,a5,a4
}
 43c:	00813083          	ld	ra,8(sp)
 440:	00013403          	ld	s0,0(sp)
 444:	01010113          	addi	sp,sp,16
 448:	00008067          	ret
  return 0;
 44c:	00000513          	li	a0,0
 450:	fedff06f          	j	43c <memcmp+0x44>

0000000000000454 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 454:	ff010113          	addi	sp,sp,-16
 458:	00113423          	sd	ra,8(sp)
 45c:	00813023          	sd	s0,0(sp)
 460:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 464:	f11ff0ef          	jal	374 <memmove>
}
 468:	00813083          	ld	ra,8(sp)
 46c:	00013403          	ld	s0,0(sp)
 470:	01010113          	addi	sp,sp,16
 474:	00008067          	ret

0000000000000478 <sbrk>:

char *
sbrk(int n) {
 478:	ff010113          	addi	sp,sp,-16
 47c:	00113423          	sd	ra,8(sp)
 480:	00813023          	sd	s0,0(sp)
 484:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 488:	00100593          	li	a1,1
 48c:	114000ef          	jal	5a0 <sys_sbrk>
}
 490:	00813083          	ld	ra,8(sp)
 494:	00013403          	ld	s0,0(sp)
 498:	01010113          	addi	sp,sp,16
 49c:	00008067          	ret

00000000000004a0 <sbrklazy>:

char *
sbrklazy(int n) {
 4a0:	ff010113          	addi	sp,sp,-16
 4a4:	00113423          	sd	ra,8(sp)
 4a8:	00813023          	sd	s0,0(sp)
 4ac:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 4b0:	00200593          	li	a1,2
 4b4:	0ec000ef          	jal	5a0 <sys_sbrk>
}
 4b8:	00813083          	ld	ra,8(sp)
 4bc:	00013403          	ld	s0,0(sp)
 4c0:	01010113          	addi	sp,sp,16
 4c4:	00008067          	ret

00000000000004c8 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 4c8:	00100893          	li	a7,1
 ecall
 4cc:	00000073          	ecall
 ret
 4d0:	00008067          	ret

00000000000004d4 <exit>:
.global exit
exit:
 li a7, SYS_exit
 4d4:	00200893          	li	a7,2
 ecall
 4d8:	00000073          	ecall
 ret
 4dc:	00008067          	ret

00000000000004e0 <wait>:
.global wait
wait:
 li a7, SYS_wait
 4e0:	00300893          	li	a7,3
 ecall
 4e4:	00000073          	ecall
 ret
 4e8:	00008067          	ret

00000000000004ec <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 4ec:	00400893          	li	a7,4
 ecall
 4f0:	00000073          	ecall
 ret
 4f4:	00008067          	ret

00000000000004f8 <read>:
.global read
read:
 li a7, SYS_read
 4f8:	00500893          	li	a7,5
 ecall
 4fc:	00000073          	ecall
 ret
 500:	00008067          	ret

0000000000000504 <write>:
.global write
write:
 li a7, SYS_write
 504:	01000893          	li	a7,16
 ecall
 508:	00000073          	ecall
 ret
 50c:	00008067          	ret

0000000000000510 <close>:
.global close
close:
 li a7, SYS_close
 510:	01500893          	li	a7,21
 ecall
 514:	00000073          	ecall
 ret
 518:	00008067          	ret

000000000000051c <kill>:
.global kill
kill:
 li a7, SYS_kill
 51c:	00600893          	li	a7,6
 ecall
 520:	00000073          	ecall
 ret
 524:	00008067          	ret

0000000000000528 <exec>:
.global exec
exec:
 li a7, SYS_exec
 528:	00700893          	li	a7,7
 ecall
 52c:	00000073          	ecall
 ret
 530:	00008067          	ret

0000000000000534 <open>:
.global open
open:
 li a7, SYS_open
 534:	00f00893          	li	a7,15
 ecall
 538:	00000073          	ecall
 ret
 53c:	00008067          	ret

0000000000000540 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 540:	01100893          	li	a7,17
 ecall
 544:	00000073          	ecall
 ret
 548:	00008067          	ret

000000000000054c <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 54c:	01200893          	li	a7,18
 ecall
 550:	00000073          	ecall
 ret
 554:	00008067          	ret

0000000000000558 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 558:	00800893          	li	a7,8
 ecall
 55c:	00000073          	ecall
 ret
 560:	00008067          	ret

0000000000000564 <link>:
.global link
link:
 li a7, SYS_link
 564:	01300893          	li	a7,19
 ecall
 568:	00000073          	ecall
 ret
 56c:	00008067          	ret

0000000000000570 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 570:	01400893          	li	a7,20
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 57c:	00900893          	li	a7,9
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <dup>:
.global dup
dup:
 li a7, SYS_dup
 588:	00a00893          	li	a7,10
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 594:	00b00893          	li	a7,11
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 5a0:	00c00893          	li	a7,12
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <pause>:
.global pause
pause:
 li a7, SYS_pause
 5ac:	00d00893          	li	a7,13
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 5b8:	00e00893          	li	a7,14
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 5c4:	00001617          	auipc	a2,0x1
 5c8:	a4c62603          	lw	a2,-1460(a2) # 1010 <putc_n>
 5cc:	00c04463          	bgtz	a2,5d4 <putc_flush+0x10>
 5d0:	00008067          	ret
{
 5d4:	ff010113          	addi	sp,sp,-16
 5d8:	00113423          	sd	ra,8(sp)
 5dc:	00813023          	sd	s0,0(sp)
 5e0:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 5e4:	00001597          	auipc	a1,0x1
 5e8:	a3c58593          	addi	a1,a1,-1476 # 1020 <putc_buf>
 5ec:	00001517          	auipc	a0,0x1
 5f0:	a1452503          	lw	a0,-1516(a0) # 1000 <putc_fd>
 5f4:	f11ff0ef          	jal	504 <write>
    putc_n = 0;
 5f8:	00001797          	auipc	a5,0x1
 5fc:	a007ac23          	sw	zero,-1512(a5) # 1010 <putc_n>
  }
}
 600:	00813083          	ld	ra,8(sp)
 604:	00013403          	ld	s0,0(sp)
 608:	01010113          	addi	sp,sp,16
 60c:	00008067          	ret

0000000000000610 <putc>:

static void
putc(int fd, char c)
{
 610:	fe010113          	addi	sp,sp,-32
 614:	00113c23          	sd	ra,24(sp)
 618:	00813823          	sd	s0,16(sp)
 61c:	00913423          	sd	s1,8(sp)
 620:	02010413          	addi	s0,sp,32
 624:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 628:	00001797          	auipc	a5,0x1
 62c:	9d87a783          	lw	a5,-1576(a5) # 1000 <putc_fd>
 630:	04a79663          	bne	a5,a0,67c <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 634:	00001717          	auipc	a4,0x1
 638:	9dc70713          	addi	a4,a4,-1572 # 1010 <putc_n>
 63c:	00072683          	lw	a3,0(a4)
 640:	0016879b          	addiw	a5,a3,1
 644:	00f72023          	sw	a5,0(a4)
 648:	00001717          	auipc	a4,0x1
 64c:	9d870713          	addi	a4,a4,-1576 # 1020 <putc_buf>
 650:	00d70733          	add	a4,a4,a3
 654:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 658:	ff648493          	addi	s1,s1,-10
 65c:	02048e63          	beqz	s1,698 <putc+0x88>
 660:	f8078793          	addi	a5,a5,-128
 664:	02078a63          	beqz	a5,698 <putc+0x88>
    putc_flush();
}
 668:	01813083          	ld	ra,24(sp)
 66c:	01013403          	ld	s0,16(sp)
 670:	00813483          	ld	s1,8(sp)
 674:	02010113          	addi	sp,sp,32
 678:	00008067          	ret
 67c:	01213023          	sd	s2,0(sp)
 680:	00050913          	mv	s2,a0
    putc_flush();
 684:	f41ff0ef          	jal	5c4 <putc_flush>
    putc_fd = fd;
 688:	00001797          	auipc	a5,0x1
 68c:	9727ac23          	sw	s2,-1672(a5) # 1000 <putc_fd>
 690:	00013903          	ld	s2,0(sp)
 694:	fa1ff06f          	j	634 <putc+0x24>
    putc_flush();
 698:	f2dff0ef          	jal	5c4 <putc_flush>
}
 69c:	fcdff06f          	j	668 <putc+0x58>

00000000000006a0 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 6a0:	fb010113          	addi	sp,sp,-80
 6a4:	04113423          	sd	ra,72(sp)
 6a8:	04813023          	sd	s0,64(sp)
 6ac:	03213823          	sd	s2,48(sp)
 6b0:	03313423          	sd	s3,40(sp)
 6b4:	05010413          	addi	s0,sp,80
 6b8:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 6bc:	0a068e63          	beqz	a3,778 <printint+0xd8>
 6c0:	0a05dc63          	bgez	a1,778 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 6c4:	40b005b3          	neg	a1,a1
    neg = 1;
 6c8:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 6cc:	fb840993          	addi	s3,s0,-72
  neg = 0;
 6d0:	00098693          	mv	a3,s3
  i = 0;
 6d4:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 6d8:	00000817          	auipc	a6,0x0
 6dc:	77880813          	addi	a6,a6,1912 # e50 <digits>
 6e0:	00070893          	mv	a7,a4
 6e4:	0017051b          	addiw	a0,a4,1
 6e8:	00050713          	mv	a4,a0
 6ec:	02c5f7b3          	remu	a5,a1,a2
 6f0:	00f807b3          	add	a5,a6,a5
 6f4:	0007c783          	lbu	a5,0(a5)
 6f8:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 6fc:	00058793          	mv	a5,a1
 700:	02c5d5b3          	divu	a1,a1,a2
 704:	00168693          	addi	a3,a3,1
 708:	fcc7fce3          	bgeu	a5,a2,6e0 <printint+0x40>
  if (neg)
 70c:	00030c63          	beqz	t1,724 <printint+0x84>
    buf[i++] = '-';
 710:	fd050793          	addi	a5,a0,-48
 714:	00878533          	add	a0,a5,s0
 718:	02d00793          	li	a5,45
 71c:	fef50423          	sb	a5,-24(a0)
 720:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 724:	02e05e63          	blez	a4,760 <printint+0xc0>
 728:	02913c23          	sd	s1,56(sp)
 72c:	fff7071b          	addiw	a4,a4,-1
 730:	00e984b3          	add	s1,s3,a4
 734:	fff98993          	addi	s3,s3,-1
 738:	00e989b3          	add	s3,s3,a4
 73c:	02071713          	slli	a4,a4,0x20
 740:	02075713          	srli	a4,a4,0x20
 744:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 748:	0004c583          	lbu	a1,0(s1)
 74c:	00090513          	mv	a0,s2
 750:	ec1ff0ef          	jal	610 <putc>
  while (--i >= 0)
 754:	fff48493          	addi	s1,s1,-1
 758:	ff3498e3          	bne	s1,s3,748 <printint+0xa8>
 75c:	03813483          	ld	s1,56(sp)
}
 760:	04813083          	ld	ra,72(sp)
 764:	04013403          	ld	s0,64(sp)
 768:	03013903          	ld	s2,48(sp)
 76c:	02813983          	ld	s3,40(sp)
 770:	05010113          	addi	sp,sp,80
 774:	00008067          	ret
  neg = 0;
 778:	00000313          	li	t1,0
 77c:	f51ff06f          	j	6cc <printint+0x2c>

0000000000000780 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 780:	fa010113          	addi	sp,sp,-96
 784:	04113c23          	sd	ra,88(sp)
 788:	04813823          	sd	s0,80(sp)
 78c:	04913423          	sd	s1,72(sp)
 790:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 794:	0005c483          	lbu	s1,0(a1)
 798:	32048263          	beqz	s1,abc <vprintf+0x33c>
 79c:	05213023          	sd	s2,64(sp)
 7a0:	03313c23          	sd	s3,56(sp)
 7a4:	03413823          	sd	s4,48(sp)
 7a8:	03513423          	sd	s5,40(sp)
 7ac:	03613023          	sd	s6,32(sp)
 7b0:	01713c23          	sd	s7,24(sp)
 7b4:	01813823          	sd	s8,16(sp)
 7b8:	00050b13          	mv	s6,a0
 7bc:	00058a13          	mv	s4,a1
 7c0:	00060b93          	mv	s7,a2
  state = 0;
 7c4:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 7c8:	00000913          	li	s2,0
 7cc:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 7d0:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 7d4:	06400c13          	li	s8,100
 7d8:	0300006f          	j	808 <vprintf+0x88>
        putc(fd, c0);
 7dc:	00048593          	mv	a1,s1
 7e0:	000b0513          	mv	a0,s6
 7e4:	e2dff0ef          	jal	610 <putc>
 7e8:	0080006f          	j	7f0 <vprintf+0x70>
    else if (state == '%')
 7ec:	03598863          	beq	s3,s5,81c <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 7f0:	0019079b          	addiw	a5,s2,1
 7f4:	00078913          	mv	s2,a5
 7f8:	00078713          	mv	a4,a5
 7fc:	00fa07b3          	add	a5,s4,a5
 800:	0007c483          	lbu	s1,0(a5)
 804:	28048e63          	beqz	s1,aa0 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 808:	0004879b          	sext.w	a5,s1
    if (state == 0)
 80c:	fe0990e3          	bnez	s3,7ec <vprintf+0x6c>
      if (c0 == '%')
 810:	fd5796e3          	bne	a5,s5,7dc <vprintf+0x5c>
        state = '%';
 814:	00078993          	mv	s3,a5
 818:	fd9ff06f          	j	7f0 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 81c:	00ea06b3          	add	a3,s4,a4
 820:	0016c603          	lbu	a2,1(a3)
      if (c1)
 824:	2a060663          	beqz	a2,ad0 <vprintf+0x350>
      if (c0 == 'd')
 828:	05878063          	beq	a5,s8,868 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 82c:	f9478693          	addi	a3,a5,-108
 830:	0016b693          	seqz	a3,a3
 834:	f9c60593          	addi	a1,a2,-100
 838:	04059a63          	bnez	a1,88c <vprintf+0x10c>
 83c:	04068863          	beqz	a3,88c <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 840:	008b8493          	addi	s1,s7,8
 844:	00100693          	li	a3,1
 848:	00a00613          	li	a2,10
 84c:	000bb583          	ld	a1,0(s7)
 850:	000b0513          	mv	a0,s6
 854:	e4dff0ef          	jal	6a0 <printint>
        i += 1;
 858:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 85c:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 860:	00000993          	li	s3,0
 864:	f8dff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 868:	008b8493          	addi	s1,s7,8
 86c:	00100693          	li	a3,1
 870:	00a00613          	li	a2,10
 874:	000ba583          	lw	a1,0(s7)
 878:	000b0513          	mv	a0,s6
 87c:	e25ff0ef          	jal	6a0 <printint>
 880:	00048b93          	mv	s7,s1
      state = 0;
 884:	00000993          	li	s3,0
 888:	f69ff06f          	j	7f0 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 88c:	00ea0733          	add	a4,s4,a4
 890:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 894:	f9460713          	addi	a4,a2,-108
 898:	00173713          	seqz	a4,a4
 89c:	00e6f733          	and	a4,a3,a4
 8a0:	f9c58513          	addi	a0,a1,-100
 8a4:	24051263          	bnez	a0,ae8 <vprintf+0x368>
 8a8:	24070063          	beqz	a4,ae8 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 8ac:	008b8493          	addi	s1,s7,8
 8b0:	00100693          	li	a3,1
 8b4:	00a00613          	li	a2,10
 8b8:	000bb583          	ld	a1,0(s7)
 8bc:	000b0513          	mv	a0,s6
 8c0:	de1ff0ef          	jal	6a0 <printint>
        i += 2;
 8c4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 8c8:	00048b93          	mv	s7,s1
      state = 0;
 8cc:	00000993          	li	s3,0
        i += 2;
 8d0:	f21ff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 8d4:	008b8493          	addi	s1,s7,8
 8d8:	00000693          	li	a3,0
 8dc:	00a00613          	li	a2,10
 8e0:	000be583          	lwu	a1,0(s7)
 8e4:	000b0513          	mv	a0,s6
 8e8:	db9ff0ef          	jal	6a0 <printint>
 8ec:	00048b93          	mv	s7,s1
      state = 0;
 8f0:	00000993          	li	s3,0
 8f4:	efdff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 8f8:	008b8493          	addi	s1,s7,8
 8fc:	00000693          	li	a3,0
 900:	00a00613          	li	a2,10
 904:	000bb583          	ld	a1,0(s7)
 908:	000b0513          	mv	a0,s6
 90c:	d95ff0ef          	jal	6a0 <printint>
        i += 1;
 910:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 914:	00048b93          	mv	s7,s1
      state = 0;
 918:	00000993          	li	s3,0
 91c:	ed5ff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 920:	008b8493          	addi	s1,s7,8
 924:	00000693          	li	a3,0
 928:	00a00613          	li	a2,10
 92c:	000bb583          	ld	a1,0(s7)
 930:	000b0513          	mv	a0,s6
 934:	d6dff0ef          	jal	6a0 <printint>
        i += 2;
 938:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 93c:	00048b93          	mv	s7,s1
      state = 0;
 940:	00000993          	li	s3,0
        i += 2;
 944:	eadff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 948:	008b8493          	addi	s1,s7,8
 94c:	00000693          	li	a3,0
 950:	01000613          	li	a2,16
 954:	000be583          	lwu	a1,0(s7)
 958:	000b0513          	mv	a0,s6
 95c:	d45ff0ef          	jal	6a0 <printint>
 960:	00048b93          	mv	s7,s1
      state = 0;
 964:	00000993          	li	s3,0
 968:	e89ff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 96c:	008b8493          	addi	s1,s7,8
 970:	00000693          	li	a3,0
 974:	01000613          	li	a2,16
 978:	000bb583          	ld	a1,0(s7)
 97c:	000b0513          	mv	a0,s6
 980:	d21ff0ef          	jal	6a0 <printint>
        i += 1;
 984:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 988:	00048b93          	mv	s7,s1
      state = 0;
 98c:	00000993          	li	s3,0
 990:	e61ff06f          	j	7f0 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 994:	008b8493          	addi	s1,s7,8
 998:	00000693          	li	a3,0
 99c:	01000613          	li	a2,16
 9a0:	000bb583          	ld	a1,0(s7)
 9a4:	000b0513          	mv	a0,s6
 9a8:	cf9ff0ef          	jal	6a0 <printint>
        i += 2;
 9ac:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 9b0:	00048b93          	mv	s7,s1
      state = 0;
 9b4:	00000993          	li	s3,0
        i += 2;
 9b8:	e39ff06f          	j	7f0 <vprintf+0x70>
 9bc:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 9c0:	008b8793          	addi	a5,s7,8
 9c4:	00078c93          	mv	s9,a5
 9c8:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 9cc:	03000593          	li	a1,48
 9d0:	000b0513          	mv	a0,s6
 9d4:	c3dff0ef          	jal	610 <putc>
  putc(fd, 'x');
 9d8:	07800593          	li	a1,120
 9dc:	000b0513          	mv	a0,s6
 9e0:	c31ff0ef          	jal	610 <putc>
 9e4:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 9e8:	00000b97          	auipc	s7,0x0
 9ec:	468b8b93          	addi	s7,s7,1128 # e50 <digits>
 9f0:	03c9d793          	srli	a5,s3,0x3c
 9f4:	00fb87b3          	add	a5,s7,a5
 9f8:	0007c583          	lbu	a1,0(a5)
 9fc:	000b0513          	mv	a0,s6
 a00:	c11ff0ef          	jal	610 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a04:	00499993          	slli	s3,s3,0x4
 a08:	fff4849b          	addiw	s1,s1,-1
 a0c:	fe0492e3          	bnez	s1,9f0 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a10:	000c8b93          	mv	s7,s9
      state = 0;
 a14:	00000993          	li	s3,0
 a18:	00813c83          	ld	s9,8(sp)
 a1c:	dd5ff06f          	j	7f0 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a20:	008b8493          	addi	s1,s7,8
 a24:	000bc583          	lbu	a1,0(s7)
 a28:	000b0513          	mv	a0,s6
 a2c:	be5ff0ef          	jal	610 <putc>
 a30:	00048b93          	mv	s7,s1
      state = 0;
 a34:	00000993          	li	s3,0
 a38:	db9ff06f          	j	7f0 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a3c:	008b8993          	addi	s3,s7,8
 a40:	000bb483          	ld	s1,0(s7)
 a44:	02048663          	beqz	s1,a70 <vprintf+0x2f0>
        for (; *s; s++)
 a48:	0004c583          	lbu	a1,0(s1)
 a4c:	04058463          	beqz	a1,a94 <vprintf+0x314>
          putc(fd, *s);
 a50:	000b0513          	mv	a0,s6
 a54:	bbdff0ef          	jal	610 <putc>
        for (; *s; s++)
 a58:	00148493          	addi	s1,s1,1
 a5c:	0004c583          	lbu	a1,0(s1)
 a60:	fe0598e3          	bnez	a1,a50 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 a64:	00098b93          	mv	s7,s3
      state = 0;
 a68:	00000993          	li	s3,0
 a6c:	d85ff06f          	j	7f0 <vprintf+0x70>
          s = "(null)";
 a70:	00000497          	auipc	s1,0x0
 a74:	3d848493          	addi	s1,s1,984 # e48 <malloc+0x190>
        for (; *s; s++)
 a78:	02800593          	li	a1,40
 a7c:	fd5ff06f          	j	a50 <vprintf+0x2d0>
        putc(fd, '%');
 a80:	00078593          	mv	a1,a5
 a84:	000b0513          	mv	a0,s6
 a88:	b89ff0ef          	jal	610 <putc>
      state = 0;
 a8c:	00000993          	li	s3,0
 a90:	d61ff06f          	j	7f0 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a94:	00098b93          	mv	s7,s3
      state = 0;
 a98:	00000993          	li	s3,0
 a9c:	d55ff06f          	j	7f0 <vprintf+0x70>
 aa0:	04013903          	ld	s2,64(sp)
 aa4:	03813983          	ld	s3,56(sp)
 aa8:	03013a03          	ld	s4,48(sp)
 aac:	02813a83          	ld	s5,40(sp)
 ab0:	02013b03          	ld	s6,32(sp)
 ab4:	01813b83          	ld	s7,24(sp)
 ab8:	01013c03          	ld	s8,16(sp)
    }
  }
}
 abc:	05813083          	ld	ra,88(sp)
 ac0:	05013403          	ld	s0,80(sp)
 ac4:	04813483          	ld	s1,72(sp)
 ac8:	06010113          	addi	sp,sp,96
 acc:	00008067          	ret
      if (c0 == 'd')
 ad0:	06400713          	li	a4,100
 ad4:	d8e78ae3          	beq	a5,a4,868 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 ad8:	f9478693          	addi	a3,a5,-108
 adc:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 ae0:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 ae4:	00000713          	li	a4,0
      else if (c0 == 'u')
 ae8:	07500513          	li	a0,117
 aec:	dea784e3          	beq	a5,a0,8d4 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 af0:	f8b60513          	addi	a0,a2,-117
 af4:	00051463          	bnez	a0,afc <vprintf+0x37c>
 af8:	e00690e3          	bnez	a3,8f8 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 afc:	f8b58513          	addi	a0,a1,-117
 b00:	00051463          	bnez	a0,b08 <vprintf+0x388>
 b04:	e0071ee3          	bnez	a4,920 <vprintf+0x1a0>
      else if (c0 == 'x')
 b08:	07800513          	li	a0,120
 b0c:	e2a78ee3          	beq	a5,a0,948 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b10:	f8860613          	addi	a2,a2,-120
 b14:	00061463          	bnez	a2,b1c <vprintf+0x39c>
 b18:	e4069ae3          	bnez	a3,96c <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b1c:	f8858593          	addi	a1,a1,-120
 b20:	00059463          	bnez	a1,b28 <vprintf+0x3a8>
 b24:	e60718e3          	bnez	a4,994 <vprintf+0x214>
      else if (c0 == 'p')
 b28:	07000713          	li	a4,112
 b2c:	e8e788e3          	beq	a5,a4,9bc <vprintf+0x23c>
      else if (c0 == 'c')
 b30:	06300713          	li	a4,99
 b34:	eee786e3          	beq	a5,a4,a20 <vprintf+0x2a0>
      else if (c0 == 's')
 b38:	07300713          	li	a4,115
 b3c:	f0e780e3          	beq	a5,a4,a3c <vprintf+0x2bc>
      else if (c0 == '%')
 b40:	02500713          	li	a4,37
 b44:	f2e78ee3          	beq	a5,a4,a80 <vprintf+0x300>
        putc(fd, '%');
 b48:	02500593          	li	a1,37
 b4c:	000b0513          	mv	a0,s6
 b50:	ac1ff0ef          	jal	610 <putc>
        putc(fd, c0);
 b54:	00048593          	mv	a1,s1
 b58:	000b0513          	mv	a0,s6
 b5c:	ab5ff0ef          	jal	610 <putc>
      state = 0;
 b60:	00000993          	li	s3,0
 b64:	c8dff06f          	j	7f0 <vprintf+0x70>

0000000000000b68 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 b68:	fb010113          	addi	sp,sp,-80
 b6c:	00113c23          	sd	ra,24(sp)
 b70:	00813823          	sd	s0,16(sp)
 b74:	02010413          	addi	s0,sp,32
 b78:	00c43023          	sd	a2,0(s0)
 b7c:	00d43423          	sd	a3,8(s0)
 b80:	00e43823          	sd	a4,16(s0)
 b84:	00f43c23          	sd	a5,24(s0)
 b88:	03043023          	sd	a6,32(s0)
 b8c:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 b90:	00040613          	mv	a2,s0
 b94:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 b98:	be9ff0ef          	jal	780 <vprintf>
}
 b9c:	01813083          	ld	ra,24(sp)
 ba0:	01013403          	ld	s0,16(sp)
 ba4:	05010113          	addi	sp,sp,80
 ba8:	00008067          	ret

0000000000000bac <printf>:

void printf(const char *fmt, ...)
{
 bac:	fa010113          	addi	sp,sp,-96
 bb0:	00113c23          	sd	ra,24(sp)
 bb4:	00813823          	sd	s0,16(sp)
 bb8:	02010413          	addi	s0,sp,32
 bbc:	00b43423          	sd	a1,8(s0)
 bc0:	00c43823          	sd	a2,16(s0)
 bc4:	00d43c23          	sd	a3,24(s0)
 bc8:	02e43023          	sd	a4,32(s0)
 bcc:	02f43423          	sd	a5,40(s0)
 bd0:	03043823          	sd	a6,48(s0)
 bd4:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 bd8:	00840613          	addi	a2,s0,8
 bdc:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 be0:	00050593          	mv	a1,a0
 be4:	00100513          	li	a0,1
 be8:	b99ff0ef          	jal	780 <vprintf>
  putc_flush();
 bec:	9d9ff0ef          	jal	5c4 <putc_flush>
}
 bf0:	01813083          	ld	ra,24(sp)
 bf4:	01013403          	ld	s0,16(sp)
 bf8:	06010113          	addi	sp,sp,96
 bfc:	00008067          	ret

0000000000000c00 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c00:	ff010113          	addi	sp,sp,-16
 c04:	00113423          	sd	ra,8(sp)
 c08:	00813023          	sd	s0,0(sp)
 c0c:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c10:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c14:	00000797          	auipc	a5,0x0
 c18:	4047b783          	ld	a5,1028(a5) # 1018 <freep>
 c1c:	0140006f          	j	c30 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c20:	0007b703          	ld	a4,0(a5)
 c24:	00e7e463          	bltu	a5,a4,c2c <free+0x2c>
 c28:	00e6ec63          	bltu	a3,a4,c40 <free+0x40>
{
 c2c:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c30:	fed7f8e3          	bgeu	a5,a3,c20 <free+0x20>
 c34:	0007b703          	ld	a4,0(a5)
 c38:	00e6e463          	bltu	a3,a4,c40 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c3c:	fee7e8e3          	bltu	a5,a4,c2c <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 c40:	ff852583          	lw	a1,-8(a0)
 c44:	0007b603          	ld	a2,0(a5)
 c48:	02059813          	slli	a6,a1,0x20
 c4c:	01c85713          	srli	a4,a6,0x1c
 c50:	00e68733          	add	a4,a3,a4
 c54:	02e60c63          	beq	a2,a4,c8c <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c58:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c5c:	0087a603          	lw	a2,8(a5)
 c60:	02061593          	slli	a1,a2,0x20
 c64:	01c5d713          	srli	a4,a1,0x1c
 c68:	00e78733          	add	a4,a5,a4
 c6c:	02e68c63          	beq	a3,a4,ca4 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 c70:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 c74:	00000717          	auipc	a4,0x0
 c78:	3af73223          	sd	a5,932(a4) # 1018 <freep>
}
 c7c:	00813083          	ld	ra,8(sp)
 c80:	00013403          	ld	s0,0(sp)
 c84:	01010113          	addi	sp,sp,16
 c88:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 c8c:	00862703          	lw	a4,8(a2)
 c90:	00b7073b          	addw	a4,a4,a1
 c94:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 c98:	0007b703          	ld	a4,0(a5)
 c9c:	00073603          	ld	a2,0(a4)
 ca0:	fb9ff06f          	j	c58 <free+0x58>
    p->s.size += bp->s.size;
 ca4:	ff852703          	lw	a4,-8(a0)
 ca8:	00c7073b          	addw	a4,a4,a2
 cac:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 cb0:	ff053683          	ld	a3,-16(a0)
 cb4:	fbdff06f          	j	c70 <free+0x70>

0000000000000cb8 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 cb8:	fc010113          	addi	sp,sp,-64
 cbc:	02113c23          	sd	ra,56(sp)
 cc0:	02813823          	sd	s0,48(sp)
 cc4:	03213023          	sd	s2,32(sp)
 cc8:	01313c23          	sd	s3,24(sp)
 ccc:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 cd0:	02051993          	slli	s3,a0,0x20
 cd4:	0209d993          	srli	s3,s3,0x20
 cd8:	00f98993          	addi	s3,s3,15
 cdc:	0049d993          	srli	s3,s3,0x4
 ce0:	0019899b          	addiw	s3,s3,1
 ce4:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 ce8:	00000517          	auipc	a0,0x0
 cec:	33053503          	ld	a0,816(a0) # 1018 <freep>
 cf0:	04050463          	beqz	a0,d38 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 cf4:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 cf8:	0087a703          	lw	a4,8(a5)
 cfc:	0d377a63          	bgeu	a4,s3,dd0 <malloc+0x118>
 d00:	02913423          	sd	s1,40(sp)
 d04:	01413823          	sd	s4,16(sp)
 d08:	01513423          	sd	s5,8(sp)
 d0c:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d10:	00098a13          	mv	s4,s3
 d14:	00001737          	lui	a4,0x1
 d18:	00e9f463          	bgeu	s3,a4,d20 <malloc+0x68>
 d1c:	00001a37          	lui	s4,0x1
 d20:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d24:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d28:	00000497          	auipc	s1,0x0
 d2c:	2f048493          	addi	s1,s1,752 # 1018 <freep>
  if(p == SBRK_ERROR)
 d30:	fff00a93          	li	s5,-1
 d34:	05c0006f          	j	d90 <malloc+0xd8>
 d38:	02913423          	sd	s1,40(sp)
 d3c:	01413823          	sd	s4,16(sp)
 d40:	01513423          	sd	s5,8(sp)
 d44:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d48:	00000797          	auipc	a5,0x0
 d4c:	35878793          	addi	a5,a5,856 # 10a0 <base>
 d50:	00000717          	auipc	a4,0x0
 d54:	2cf73423          	sd	a5,712(a4) # 1018 <freep>
 d58:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d5c:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d60:	fb1ff06f          	j	d10 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 d64:	0007b703          	ld	a4,0(a5)
 d68:	00e53023          	sd	a4,0(a0)
 d6c:	0800006f          	j	dec <malloc+0x134>
  hp->s.size = nu;
 d70:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 d74:	01050513          	addi	a0,a0,16
 d78:	e89ff0ef          	jal	c00 <free>
  return freep;
 d7c:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 d80:	08050863          	beqz	a0,e10 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d84:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d88:	0087a703          	lw	a4,8(a5)
 d8c:	03277a63          	bgeu	a4,s2,dc0 <malloc+0x108>
    if(p == freep)
 d90:	0004b703          	ld	a4,0(s1)
 d94:	00078513          	mv	a0,a5
 d98:	fef716e3          	bne	a4,a5,d84 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 d9c:	000a0513          	mv	a0,s4
 da0:	ed8ff0ef          	jal	478 <sbrk>
  if(p == SBRK_ERROR)
 da4:	fd5516e3          	bne	a0,s5,d70 <malloc+0xb8>
        return 0;
 da8:	00000513          	li	a0,0
 dac:	02813483          	ld	s1,40(sp)
 db0:	01013a03          	ld	s4,16(sp)
 db4:	00813a83          	ld	s5,8(sp)
 db8:	00013b03          	ld	s6,0(sp)
 dbc:	03c0006f          	j	df8 <malloc+0x140>
 dc0:	02813483          	ld	s1,40(sp)
 dc4:	01013a03          	ld	s4,16(sp)
 dc8:	00813a83          	ld	s5,8(sp)
 dcc:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 dd0:	f8e90ae3          	beq	s2,a4,d64 <malloc+0xac>
        p->s.size -= nunits;
 dd4:	4137073b          	subw	a4,a4,s3
 dd8:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 ddc:	02071693          	slli	a3,a4,0x20
 de0:	01c6d713          	srli	a4,a3,0x1c
 de4:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 de8:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 dec:	00000717          	auipc	a4,0x0
 df0:	22a73623          	sd	a0,556(a4) # 1018 <freep>
      return (void*)(p + 1);
 df4:	01078513          	addi	a0,a5,16
  }
}
 df8:	03813083          	ld	ra,56(sp)
 dfc:	03013403          	ld	s0,48(sp)
 e00:	02013903          	ld	s2,32(sp)
 e04:	01813983          	ld	s3,24(sp)
 e08:	04010113          	addi	sp,sp,64
 e0c:	00008067          	ret
 e10:	02813483          	ld	s1,40(sp)
 e14:	01013a03          	ld	s4,16(sp)
 e18:	00813a83          	ld	s5,8(sp)
 e1c:	00013b03          	ld	s6,0(sp)
 e20:	fd9ff06f          	j	df8 <malloc+0x140>
