
user/_zombie:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
   0:	ff010113          	addi	sp,sp,-16
   4:	00113423          	sd	ra,8(sp)
   8:	00813023          	sd	s0,0(sp)
   c:	01010413          	addi	s0,sp,16
  if(fork() > 0)
  10:	470000ef          	jal	480 <fork>
  14:	00a04663          	bgtz	a0,20 <main+0x20>
    pause(5);  // Let child exit before parent.
  exit(0);
  18:	00000513          	li	a0,0
  1c:	470000ef          	jal	48c <exit>
    pause(5);  // Let child exit before parent.
  20:	00500513          	li	a0,5
  24:	540000ef          	jal	564 <pause>
  28:	ff1ff06f          	j	18 <main+0x18>

000000000000002c <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  2c:	ff010113          	addi	sp,sp,-16
  30:	00113423          	sd	ra,8(sp)
  34:	00813023          	sd	s0,0(sp)
  38:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  3c:	fc5ff0ef          	jal	0 <main>
  exit(r);
  40:	44c000ef          	jal	48c <exit>

0000000000000044 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  44:	ff010113          	addi	sp,sp,-16
  48:	00113423          	sd	ra,8(sp)
  4c:	00813023          	sd	s0,0(sp)
  50:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  54:	00050793          	mv	a5,a0
  58:	00158593          	addi	a1,a1,1
  5c:	00178793          	addi	a5,a5,1
  60:	fff5c703          	lbu	a4,-1(a1)
  64:	fee78fa3          	sb	a4,-1(a5)
  68:	fe0718e3          	bnez	a4,58 <strcpy+0x14>
    ;
  return os;
}
  6c:	00813083          	ld	ra,8(sp)
  70:	00013403          	ld	s0,0(sp)
  74:	01010113          	addi	sp,sp,16
  78:	00008067          	ret

000000000000007c <strcmp>:

int
strcmp(const char *p, const char *q)
{
  7c:	ff010113          	addi	sp,sp,-16
  80:	00113423          	sd	ra,8(sp)
  84:	00813023          	sd	s0,0(sp)
  88:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
  8c:	00054783          	lbu	a5,0(a0)
  90:	00078e63          	beqz	a5,ac <strcmp+0x30>
  94:	0005c703          	lbu	a4,0(a1)
  98:	00f71a63          	bne	a4,a5,ac <strcmp+0x30>
    p++, q++;
  9c:	00150513          	addi	a0,a0,1
  a0:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
  a4:	00054783          	lbu	a5,0(a0)
  a8:	fe0796e3          	bnez	a5,94 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
  ac:	0005c503          	lbu	a0,0(a1)
}
  b0:	40a7853b          	subw	a0,a5,a0
  b4:	00813083          	ld	ra,8(sp)
  b8:	00013403          	ld	s0,0(sp)
  bc:	01010113          	addi	sp,sp,16
  c0:	00008067          	ret

00000000000000c4 <strlen>:

uint
strlen(const char *s)
{
  c4:	ff010113          	addi	sp,sp,-16
  c8:	00113423          	sd	ra,8(sp)
  cc:	00813023          	sd	s0,0(sp)
  d0:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
  d4:	00054783          	lbu	a5,0(a0)
  d8:	02078663          	beqz	a5,104 <strlen+0x40>
  dc:	00150793          	addi	a5,a0,1
  e0:	00078693          	mv	a3,a5
  e4:	00178793          	addi	a5,a5,1
  e8:	fff7c703          	lbu	a4,-1(a5)
  ec:	fe071ae3          	bnez	a4,e0 <strlen+0x1c>
  f0:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
  f4:	00813083          	ld	ra,8(sp)
  f8:	00013403          	ld	s0,0(sp)
  fc:	01010113          	addi	sp,sp,16
 100:	00008067          	ret
  for(n = 0; s[n]; n++)
 104:	00000513          	li	a0,0
 108:	fedff06f          	j	f4 <strlen+0x30>

000000000000010c <memset>:

void*
memset(void *dst, int c, uint n)
{
 10c:	ff010113          	addi	sp,sp,-16
 110:	00113423          	sd	ra,8(sp)
 114:	00813023          	sd	s0,0(sp)
 118:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 11c:	02060063          	beqz	a2,13c <memset+0x30>
 120:	00050793          	mv	a5,a0
 124:	02061613          	slli	a2,a2,0x20
 128:	02065613          	srli	a2,a2,0x20
 12c:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 130:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 134:	00178793          	addi	a5,a5,1
 138:	fee79ce3          	bne	a5,a4,130 <memset+0x24>
  }
  return dst;
}
 13c:	00813083          	ld	ra,8(sp)
 140:	00013403          	ld	s0,0(sp)
 144:	01010113          	addi	sp,sp,16
 148:	00008067          	ret

000000000000014c <strchr>:

char*
strchr(const char *s, char c)
{
 14c:	ff010113          	addi	sp,sp,-16
 150:	00113423          	sd	ra,8(sp)
 154:	00813023          	sd	s0,0(sp)
 158:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 15c:	00054783          	lbu	a5,0(a0)
 160:	02078463          	beqz	a5,188 <strchr+0x3c>
    if(*s == c)
 164:	00f58a63          	beq	a1,a5,178 <strchr+0x2c>
  for(; *s; s++)
 168:	00150513          	addi	a0,a0,1
 16c:	00054783          	lbu	a5,0(a0)
 170:	fe079ae3          	bnez	a5,164 <strchr+0x18>
      return (char*)s;
  return 0;
 174:	00000513          	li	a0,0
}
 178:	00813083          	ld	ra,8(sp)
 17c:	00013403          	ld	s0,0(sp)
 180:	01010113          	addi	sp,sp,16
 184:	00008067          	ret
  return 0;
 188:	00000513          	li	a0,0
 18c:	fedff06f          	j	178 <strchr+0x2c>

0000000000000190 <gets>:

char*
gets(char *buf, int max)
{
 190:	fa010113          	addi	sp,sp,-96
 194:	04113c23          	sd	ra,88(sp)
 198:	04813823          	sd	s0,80(sp)
 19c:	04913423          	sd	s1,72(sp)
 1a0:	05213023          	sd	s2,64(sp)
 1a4:	03313c23          	sd	s3,56(sp)
 1a8:	03413823          	sd	s4,48(sp)
 1ac:	03513423          	sd	s5,40(sp)
 1b0:	03613023          	sd	s6,32(sp)
 1b4:	01713c23          	sd	s7,24(sp)
 1b8:	01813823          	sd	s8,16(sp)
 1bc:	06010413          	addi	s0,sp,96
 1c0:	00050b93          	mv	s7,a0
 1c4:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 1c8:	00050913          	mv	s2,a0
 1cc:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 1d0:	faf40b13          	addi	s6,s0,-81
 1d4:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 1d8:	00048c13          	mv	s8,s1
 1dc:	0014899b          	addiw	s3,s1,1
 1e0:	00098493          	mv	s1,s3
 1e4:	0349dc63          	bge	s3,s4,21c <gets+0x8c>
    cc = read(0, &c, 1);
 1e8:	000a8613          	mv	a2,s5
 1ec:	000b0593          	mv	a1,s6
 1f0:	00000513          	li	a0,0
 1f4:	2bc000ef          	jal	4b0 <read>
    if(cc < 1)
 1f8:	02a05263          	blez	a0,21c <gets+0x8c>
      break;
    buf[i++] = c;
 1fc:	faf44783          	lbu	a5,-81(s0)
 200:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 204:	00190913          	addi	s2,s2,1
 208:	ff678713          	addi	a4,a5,-10
 20c:	00070663          	beqz	a4,218 <gets+0x88>
 210:	ff378793          	addi	a5,a5,-13
 214:	fc0792e3          	bnez	a5,1d8 <gets+0x48>
    buf[i++] = c;
 218:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 21c:	018b8c33          	add	s8,s7,s8
 220:	000c0023          	sb	zero,0(s8)
  return buf;
}
 224:	000b8513          	mv	a0,s7
 228:	05813083          	ld	ra,88(sp)
 22c:	05013403          	ld	s0,80(sp)
 230:	04813483          	ld	s1,72(sp)
 234:	04013903          	ld	s2,64(sp)
 238:	03813983          	ld	s3,56(sp)
 23c:	03013a03          	ld	s4,48(sp)
 240:	02813a83          	ld	s5,40(sp)
 244:	02013b03          	ld	s6,32(sp)
 248:	01813b83          	ld	s7,24(sp)
 24c:	01013c03          	ld	s8,16(sp)
 250:	06010113          	addi	sp,sp,96
 254:	00008067          	ret

0000000000000258 <stat>:

int
stat(const char *n, struct stat *st)
{
 258:	fe010113          	addi	sp,sp,-32
 25c:	00113c23          	sd	ra,24(sp)
 260:	00813823          	sd	s0,16(sp)
 264:	01213023          	sd	s2,0(sp)
 268:	02010413          	addi	s0,sp,32
 26c:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 270:	00000593          	li	a1,0
 274:	278000ef          	jal	4ec <open>
  if(fd < 0)
 278:	02054e63          	bltz	a0,2b4 <stat+0x5c>
 27c:	00913423          	sd	s1,8(sp)
 280:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 284:	00090593          	mv	a1,s2
 288:	288000ef          	jal	510 <fstat>
 28c:	00050913          	mv	s2,a0
  close(fd);
 290:	00048513          	mv	a0,s1
 294:	234000ef          	jal	4c8 <close>
  return r;
 298:	00813483          	ld	s1,8(sp)
}
 29c:	00090513          	mv	a0,s2
 2a0:	01813083          	ld	ra,24(sp)
 2a4:	01013403          	ld	s0,16(sp)
 2a8:	00013903          	ld	s2,0(sp)
 2ac:	02010113          	addi	sp,sp,32
 2b0:	00008067          	ret
    return -1;
 2b4:	fff00793          	li	a5,-1
 2b8:	00078913          	mv	s2,a5
 2bc:	fe1ff06f          	j	29c <stat+0x44>

00000000000002c0 <atoi>:

int
atoi(const char *s)
{
 2c0:	ff010113          	addi	sp,sp,-16
 2c4:	00113423          	sd	ra,8(sp)
 2c8:	00813023          	sd	s0,0(sp)
 2cc:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 2d0:	00054683          	lbu	a3,0(a0)
 2d4:	fd06879b          	addiw	a5,a3,-48
 2d8:	0ff7f793          	zext.b	a5,a5
 2dc:	00900613          	li	a2,9
 2e0:	04f66263          	bltu	a2,a5,324 <atoi+0x64>
 2e4:	00050713          	mv	a4,a0
  n = 0;
 2e8:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 2ec:	00170713          	addi	a4,a4,1
 2f0:	0025179b          	slliw	a5,a0,0x2
 2f4:	00a787bb          	addw	a5,a5,a0
 2f8:	0017979b          	slliw	a5,a5,0x1
 2fc:	00d787bb          	addw	a5,a5,a3
 300:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 304:	00074683          	lbu	a3,0(a4)
 308:	fd06879b          	addiw	a5,a3,-48
 30c:	0ff7f793          	zext.b	a5,a5
 310:	fcf67ee3          	bgeu	a2,a5,2ec <atoi+0x2c>
  return n;
}
 314:	00813083          	ld	ra,8(sp)
 318:	00013403          	ld	s0,0(sp)
 31c:	01010113          	addi	sp,sp,16
 320:	00008067          	ret
  n = 0;
 324:	00000513          	li	a0,0
 328:	fedff06f          	j	314 <atoi+0x54>

000000000000032c <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 32c:	ff010113          	addi	sp,sp,-16
 330:	00113423          	sd	ra,8(sp)
 334:	00813023          	sd	s0,0(sp)
 338:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 33c:	02b57e63          	bgeu	a0,a1,378 <memmove+0x4c>
    while(n-- > 0)
 340:	02c05463          	blez	a2,368 <memmove+0x3c>
 344:	02061613          	slli	a2,a2,0x20
 348:	02065613          	srli	a2,a2,0x20
 34c:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 350:	00050713          	mv	a4,a0
      *dst++ = *src++;
 354:	00158593          	addi	a1,a1,1
 358:	00170713          	addi	a4,a4,1
 35c:	fff5c683          	lbu	a3,-1(a1)
 360:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 364:	fee798e3          	bne	a5,a4,354 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 368:	00813083          	ld	ra,8(sp)
 36c:	00013403          	ld	s0,0(sp)
 370:	01010113          	addi	sp,sp,16
 374:	00008067          	ret
    while(n-- > 0)
 378:	fec058e3          	blez	a2,368 <memmove+0x3c>
    dst += n;
 37c:	00c50733          	add	a4,a0,a2
    src += n;
 380:	00c585b3          	add	a1,a1,a2
 384:	fff6079b          	addiw	a5,a2,-1
 388:	02079793          	slli	a5,a5,0x20
 38c:	0207d793          	srli	a5,a5,0x20
 390:	fff7c793          	not	a5,a5
 394:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 398:	fff58593          	addi	a1,a1,-1
 39c:	fff70713          	addi	a4,a4,-1
 3a0:	0005c683          	lbu	a3,0(a1)
 3a4:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 3a8:	fef718e3          	bne	a4,a5,398 <memmove+0x6c>
 3ac:	fbdff06f          	j	368 <memmove+0x3c>

00000000000003b0 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 3b0:	ff010113          	addi	sp,sp,-16
 3b4:	00113423          	sd	ra,8(sp)
 3b8:	00813023          	sd	s0,0(sp)
 3bc:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 3c0:	04060263          	beqz	a2,404 <memcmp+0x54>
 3c4:	02061613          	slli	a2,a2,0x20
 3c8:	02065613          	srli	a2,a2,0x20
 3cc:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 3d0:	00054783          	lbu	a5,0(a0)
 3d4:	0005c703          	lbu	a4,0(a1)
 3d8:	00e79c63          	bne	a5,a4,3f0 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 3dc:	00150513          	addi	a0,a0,1
    p2++;
 3e0:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 3e4:	fed516e3          	bne	a0,a3,3d0 <memcmp+0x20>
  }
  return 0;
 3e8:	00000513          	li	a0,0
 3ec:	0080006f          	j	3f4 <memcmp+0x44>
      return *p1 - *p2;
 3f0:	40e7853b          	subw	a0,a5,a4
}
 3f4:	00813083          	ld	ra,8(sp)
 3f8:	00013403          	ld	s0,0(sp)
 3fc:	01010113          	addi	sp,sp,16
 400:	00008067          	ret
  return 0;
 404:	00000513          	li	a0,0
 408:	fedff06f          	j	3f4 <memcmp+0x44>

000000000000040c <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 40c:	ff010113          	addi	sp,sp,-16
 410:	00113423          	sd	ra,8(sp)
 414:	00813023          	sd	s0,0(sp)
 418:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 41c:	f11ff0ef          	jal	32c <memmove>
}
 420:	00813083          	ld	ra,8(sp)
 424:	00013403          	ld	s0,0(sp)
 428:	01010113          	addi	sp,sp,16
 42c:	00008067          	ret

0000000000000430 <sbrk>:

char *
sbrk(int n) {
 430:	ff010113          	addi	sp,sp,-16
 434:	00113423          	sd	ra,8(sp)
 438:	00813023          	sd	s0,0(sp)
 43c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 440:	00100593          	li	a1,1
 444:	114000ef          	jal	558 <sys_sbrk>
}
 448:	00813083          	ld	ra,8(sp)
 44c:	00013403          	ld	s0,0(sp)
 450:	01010113          	addi	sp,sp,16
 454:	00008067          	ret

0000000000000458 <sbrklazy>:

char *
sbrklazy(int n) {
 458:	ff010113          	addi	sp,sp,-16
 45c:	00113423          	sd	ra,8(sp)
 460:	00813023          	sd	s0,0(sp)
 464:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 468:	00200593          	li	a1,2
 46c:	0ec000ef          	jal	558 <sys_sbrk>
}
 470:	00813083          	ld	ra,8(sp)
 474:	00013403          	ld	s0,0(sp)
 478:	01010113          	addi	sp,sp,16
 47c:	00008067          	ret

0000000000000480 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 480:	00100893          	li	a7,1
 ecall
 484:	00000073          	ecall
 ret
 488:	00008067          	ret

000000000000048c <exit>:
.global exit
exit:
 li a7, SYS_exit
 48c:	00200893          	li	a7,2
 ecall
 490:	00000073          	ecall
 ret
 494:	00008067          	ret

0000000000000498 <wait>:
.global wait
wait:
 li a7, SYS_wait
 498:	00300893          	li	a7,3
 ecall
 49c:	00000073          	ecall
 ret
 4a0:	00008067          	ret

00000000000004a4 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 4a4:	00400893          	li	a7,4
 ecall
 4a8:	00000073          	ecall
 ret
 4ac:	00008067          	ret

00000000000004b0 <read>:
.global read
read:
 li a7, SYS_read
 4b0:	00500893          	li	a7,5
 ecall
 4b4:	00000073          	ecall
 ret
 4b8:	00008067          	ret

00000000000004bc <write>:
.global write
write:
 li a7, SYS_write
 4bc:	01000893          	li	a7,16
 ecall
 4c0:	00000073          	ecall
 ret
 4c4:	00008067          	ret

00000000000004c8 <close>:
.global close
close:
 li a7, SYS_close
 4c8:	01500893          	li	a7,21
 ecall
 4cc:	00000073          	ecall
 ret
 4d0:	00008067          	ret

00000000000004d4 <kill>:
.global kill
kill:
 li a7, SYS_kill
 4d4:	00600893          	li	a7,6
 ecall
 4d8:	00000073          	ecall
 ret
 4dc:	00008067          	ret

00000000000004e0 <exec>:
.global exec
exec:
 li a7, SYS_exec
 4e0:	00700893          	li	a7,7
 ecall
 4e4:	00000073          	ecall
 ret
 4e8:	00008067          	ret

00000000000004ec <open>:
.global open
open:
 li a7, SYS_open
 4ec:	00f00893          	li	a7,15
 ecall
 4f0:	00000073          	ecall
 ret
 4f4:	00008067          	ret

00000000000004f8 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 4f8:	01100893          	li	a7,17
 ecall
 4fc:	00000073          	ecall
 ret
 500:	00008067          	ret

0000000000000504 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 504:	01200893          	li	a7,18
 ecall
 508:	00000073          	ecall
 ret
 50c:	00008067          	ret

0000000000000510 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 510:	00800893          	li	a7,8
 ecall
 514:	00000073          	ecall
 ret
 518:	00008067          	ret

000000000000051c <link>:
.global link
link:
 li a7, SYS_link
 51c:	01300893          	li	a7,19
 ecall
 520:	00000073          	ecall
 ret
 524:	00008067          	ret

0000000000000528 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 528:	01400893          	li	a7,20
 ecall
 52c:	00000073          	ecall
 ret
 530:	00008067          	ret

0000000000000534 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 534:	00900893          	li	a7,9
 ecall
 538:	00000073          	ecall
 ret
 53c:	00008067          	ret

0000000000000540 <dup>:
.global dup
dup:
 li a7, SYS_dup
 540:	00a00893          	li	a7,10
 ecall
 544:	00000073          	ecall
 ret
 548:	00008067          	ret

000000000000054c <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 54c:	00b00893          	li	a7,11
 ecall
 550:	00000073          	ecall
 ret
 554:	00008067          	ret

0000000000000558 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 558:	00c00893          	li	a7,12
 ecall
 55c:	00000073          	ecall
 ret
 560:	00008067          	ret

0000000000000564 <pause>:
.global pause
pause:
 li a7, SYS_pause
 564:	00d00893          	li	a7,13
 ecall
 568:	00000073          	ecall
 ret
 56c:	00008067          	ret

0000000000000570 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 570:	00e00893          	li	a7,14
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 57c:	00001617          	auipc	a2,0x1
 580:	a9462603          	lw	a2,-1388(a2) # 1010 <putc_n>
 584:	00c04463          	bgtz	a2,58c <putc_flush+0x10>
 588:	00008067          	ret
{
 58c:	ff010113          	addi	sp,sp,-16
 590:	00113423          	sd	ra,8(sp)
 594:	00813023          	sd	s0,0(sp)
 598:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 59c:	00001597          	auipc	a1,0x1
 5a0:	a8458593          	addi	a1,a1,-1404 # 1020 <putc_buf>
 5a4:	00001517          	auipc	a0,0x1
 5a8:	a5c52503          	lw	a0,-1444(a0) # 1000 <putc_fd>
 5ac:	f11ff0ef          	jal	4bc <write>
    putc_n = 0;
 5b0:	00001797          	auipc	a5,0x1
 5b4:	a607a023          	sw	zero,-1440(a5) # 1010 <putc_n>
  }
}
 5b8:	00813083          	ld	ra,8(sp)
 5bc:	00013403          	ld	s0,0(sp)
 5c0:	01010113          	addi	sp,sp,16
 5c4:	00008067          	ret

00000000000005c8 <putc>:

static void
putc(int fd, char c)
{
 5c8:	fe010113          	addi	sp,sp,-32
 5cc:	00113c23          	sd	ra,24(sp)
 5d0:	00813823          	sd	s0,16(sp)
 5d4:	00913423          	sd	s1,8(sp)
 5d8:	02010413          	addi	s0,sp,32
 5dc:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 5e0:	00001797          	auipc	a5,0x1
 5e4:	a207a783          	lw	a5,-1504(a5) # 1000 <putc_fd>
 5e8:	04a79663          	bne	a5,a0,634 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 5ec:	00001717          	auipc	a4,0x1
 5f0:	a2470713          	addi	a4,a4,-1500 # 1010 <putc_n>
 5f4:	00072683          	lw	a3,0(a4)
 5f8:	0016879b          	addiw	a5,a3,1
 5fc:	00f72023          	sw	a5,0(a4)
 600:	00001717          	auipc	a4,0x1
 604:	a2070713          	addi	a4,a4,-1504 # 1020 <putc_buf>
 608:	00d70733          	add	a4,a4,a3
 60c:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 610:	ff648493          	addi	s1,s1,-10
 614:	02048e63          	beqz	s1,650 <putc+0x88>
 618:	f8078793          	addi	a5,a5,-128
 61c:	02078a63          	beqz	a5,650 <putc+0x88>
    putc_flush();
}
 620:	01813083          	ld	ra,24(sp)
 624:	01013403          	ld	s0,16(sp)
 628:	00813483          	ld	s1,8(sp)
 62c:	02010113          	addi	sp,sp,32
 630:	00008067          	ret
 634:	01213023          	sd	s2,0(sp)
 638:	00050913          	mv	s2,a0
    putc_flush();
 63c:	f41ff0ef          	jal	57c <putc_flush>
    putc_fd = fd;
 640:	00001797          	auipc	a5,0x1
 644:	9d27a023          	sw	s2,-1600(a5) # 1000 <putc_fd>
 648:	00013903          	ld	s2,0(sp)
 64c:	fa1ff06f          	j	5ec <putc+0x24>
    putc_flush();
 650:	f2dff0ef          	jal	57c <putc_flush>
}
 654:	fcdff06f          	j	620 <putc+0x58>

0000000000000658 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 658:	fb010113          	addi	sp,sp,-80
 65c:	04113423          	sd	ra,72(sp)
 660:	04813023          	sd	s0,64(sp)
 664:	03213823          	sd	s2,48(sp)
 668:	03313423          	sd	s3,40(sp)
 66c:	05010413          	addi	s0,sp,80
 670:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 674:	0a068e63          	beqz	a3,730 <printint+0xd8>
 678:	0a05dc63          	bgez	a1,730 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 67c:	40b005b3          	neg	a1,a1
    neg = 1;
 680:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 684:	fb840993          	addi	s3,s0,-72
  neg = 0;
 688:	00098693          	mv	a3,s3
  i = 0;
 68c:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 690:	00000817          	auipc	a6,0x0
 694:	75880813          	addi	a6,a6,1880 # de8 <digits>
 698:	00070893          	mv	a7,a4
 69c:	0017051b          	addiw	a0,a4,1
 6a0:	00050713          	mv	a4,a0
 6a4:	02c5f7b3          	remu	a5,a1,a2
 6a8:	00f807b3          	add	a5,a6,a5
 6ac:	0007c783          	lbu	a5,0(a5)
 6b0:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 6b4:	00058793          	mv	a5,a1
 6b8:	02c5d5b3          	divu	a1,a1,a2
 6bc:	00168693          	addi	a3,a3,1
 6c0:	fcc7fce3          	bgeu	a5,a2,698 <printint+0x40>
  if (neg)
 6c4:	00030c63          	beqz	t1,6dc <printint+0x84>
    buf[i++] = '-';
 6c8:	fd050793          	addi	a5,a0,-48
 6cc:	00878533          	add	a0,a5,s0
 6d0:	02d00793          	li	a5,45
 6d4:	fef50423          	sb	a5,-24(a0)
 6d8:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 6dc:	02e05e63          	blez	a4,718 <printint+0xc0>
 6e0:	02913c23          	sd	s1,56(sp)
 6e4:	fff7071b          	addiw	a4,a4,-1
 6e8:	00e984b3          	add	s1,s3,a4
 6ec:	fff98993          	addi	s3,s3,-1
 6f0:	00e989b3          	add	s3,s3,a4
 6f4:	02071713          	slli	a4,a4,0x20
 6f8:	02075713          	srli	a4,a4,0x20
 6fc:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 700:	0004c583          	lbu	a1,0(s1)
 704:	00090513          	mv	a0,s2
 708:	ec1ff0ef          	jal	5c8 <putc>
  while (--i >= 0)
 70c:	fff48493          	addi	s1,s1,-1
 710:	ff3498e3          	bne	s1,s3,700 <printint+0xa8>
 714:	03813483          	ld	s1,56(sp)
}
 718:	04813083          	ld	ra,72(sp)
 71c:	04013403          	ld	s0,64(sp)
 720:	03013903          	ld	s2,48(sp)
 724:	02813983          	ld	s3,40(sp)
 728:	05010113          	addi	sp,sp,80
 72c:	00008067          	ret
  neg = 0;
 730:	00000313          	li	t1,0
 734:	f51ff06f          	j	684 <printint+0x2c>

0000000000000738 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 738:	fa010113          	addi	sp,sp,-96
 73c:	04113c23          	sd	ra,88(sp)
 740:	04813823          	sd	s0,80(sp)
 744:	04913423          	sd	s1,72(sp)
 748:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 74c:	0005c483          	lbu	s1,0(a1)
 750:	32048263          	beqz	s1,a74 <vprintf+0x33c>
 754:	05213023          	sd	s2,64(sp)
 758:	03313c23          	sd	s3,56(sp)
 75c:	03413823          	sd	s4,48(sp)
 760:	03513423          	sd	s5,40(sp)
 764:	03613023          	sd	s6,32(sp)
 768:	01713c23          	sd	s7,24(sp)
 76c:	01813823          	sd	s8,16(sp)
 770:	00050b13          	mv	s6,a0
 774:	00058a13          	mv	s4,a1
 778:	00060b93          	mv	s7,a2
  state = 0;
 77c:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 780:	00000913          	li	s2,0
 784:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 788:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 78c:	06400c13          	li	s8,100
 790:	0300006f          	j	7c0 <vprintf+0x88>
        putc(fd, c0);
 794:	00048593          	mv	a1,s1
 798:	000b0513          	mv	a0,s6
 79c:	e2dff0ef          	jal	5c8 <putc>
 7a0:	0080006f          	j	7a8 <vprintf+0x70>
    else if (state == '%')
 7a4:	03598863          	beq	s3,s5,7d4 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 7a8:	0019079b          	addiw	a5,s2,1
 7ac:	00078913          	mv	s2,a5
 7b0:	00078713          	mv	a4,a5
 7b4:	00fa07b3          	add	a5,s4,a5
 7b8:	0007c483          	lbu	s1,0(a5)
 7bc:	28048e63          	beqz	s1,a58 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 7c0:	0004879b          	sext.w	a5,s1
    if (state == 0)
 7c4:	fe0990e3          	bnez	s3,7a4 <vprintf+0x6c>
      if (c0 == '%')
 7c8:	fd5796e3          	bne	a5,s5,794 <vprintf+0x5c>
        state = '%';
 7cc:	00078993          	mv	s3,a5
 7d0:	fd9ff06f          	j	7a8 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 7d4:	00ea06b3          	add	a3,s4,a4
 7d8:	0016c603          	lbu	a2,1(a3)
      if (c1)
 7dc:	2a060663          	beqz	a2,a88 <vprintf+0x350>
      if (c0 == 'd')
 7e0:	05878063          	beq	a5,s8,820 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 7e4:	f9478693          	addi	a3,a5,-108
 7e8:	0016b693          	seqz	a3,a3
 7ec:	f9c60593          	addi	a1,a2,-100
 7f0:	04059a63          	bnez	a1,844 <vprintf+0x10c>
 7f4:	04068863          	beqz	a3,844 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 7f8:	008b8493          	addi	s1,s7,8
 7fc:	00100693          	li	a3,1
 800:	00a00613          	li	a2,10
 804:	000bb583          	ld	a1,0(s7)
 808:	000b0513          	mv	a0,s6
 80c:	e4dff0ef          	jal	658 <printint>
        i += 1;
 810:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 814:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 818:	00000993          	li	s3,0
 81c:	f8dff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 820:	008b8493          	addi	s1,s7,8
 824:	00100693          	li	a3,1
 828:	00a00613          	li	a2,10
 82c:	000ba583          	lw	a1,0(s7)
 830:	000b0513          	mv	a0,s6
 834:	e25ff0ef          	jal	658 <printint>
 838:	00048b93          	mv	s7,s1
      state = 0;
 83c:	00000993          	li	s3,0
 840:	f69ff06f          	j	7a8 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 844:	00ea0733          	add	a4,s4,a4
 848:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 84c:	f9460713          	addi	a4,a2,-108
 850:	00173713          	seqz	a4,a4
 854:	00e6f733          	and	a4,a3,a4
 858:	f9c58513          	addi	a0,a1,-100
 85c:	24051263          	bnez	a0,aa0 <vprintf+0x368>
 860:	24070063          	beqz	a4,aa0 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 864:	008b8493          	addi	s1,s7,8
 868:	00100693          	li	a3,1
 86c:	00a00613          	li	a2,10
 870:	000bb583          	ld	a1,0(s7)
 874:	000b0513          	mv	a0,s6
 878:	de1ff0ef          	jal	658 <printint>
        i += 2;
 87c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 880:	00048b93          	mv	s7,s1
      state = 0;
 884:	00000993          	li	s3,0
        i += 2;
 888:	f21ff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 88c:	008b8493          	addi	s1,s7,8
 890:	00000693          	li	a3,0
 894:	00a00613          	li	a2,10
 898:	000be583          	lwu	a1,0(s7)
 89c:	000b0513          	mv	a0,s6
 8a0:	db9ff0ef          	jal	658 <printint>
 8a4:	00048b93          	mv	s7,s1
      state = 0;
 8a8:	00000993          	li	s3,0
 8ac:	efdff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 8b0:	008b8493          	addi	s1,s7,8
 8b4:	00000693          	li	a3,0
 8b8:	00a00613          	li	a2,10
 8bc:	000bb583          	ld	a1,0(s7)
 8c0:	000b0513          	mv	a0,s6
 8c4:	d95ff0ef          	jal	658 <printint>
        i += 1;
 8c8:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 8cc:	00048b93          	mv	s7,s1
      state = 0;
 8d0:	00000993          	li	s3,0
 8d4:	ed5ff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 8d8:	008b8493          	addi	s1,s7,8
 8dc:	00000693          	li	a3,0
 8e0:	00a00613          	li	a2,10
 8e4:	000bb583          	ld	a1,0(s7)
 8e8:	000b0513          	mv	a0,s6
 8ec:	d6dff0ef          	jal	658 <printint>
        i += 2;
 8f0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 8f4:	00048b93          	mv	s7,s1
      state = 0;
 8f8:	00000993          	li	s3,0
        i += 2;
 8fc:	eadff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 900:	008b8493          	addi	s1,s7,8
 904:	00000693          	li	a3,0
 908:	01000613          	li	a2,16
 90c:	000be583          	lwu	a1,0(s7)
 910:	000b0513          	mv	a0,s6
 914:	d45ff0ef          	jal	658 <printint>
 918:	00048b93          	mv	s7,s1
      state = 0;
 91c:	00000993          	li	s3,0
 920:	e89ff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 924:	008b8493          	addi	s1,s7,8
 928:	00000693          	li	a3,0
 92c:	01000613          	li	a2,16
 930:	000bb583          	ld	a1,0(s7)
 934:	000b0513          	mv	a0,s6
 938:	d21ff0ef          	jal	658 <printint>
        i += 1;
 93c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 940:	00048b93          	mv	s7,s1
      state = 0;
 944:	00000993          	li	s3,0
 948:	e61ff06f          	j	7a8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 94c:	008b8493          	addi	s1,s7,8
 950:	00000693          	li	a3,0
 954:	01000613          	li	a2,16
 958:	000bb583          	ld	a1,0(s7)
 95c:	000b0513          	mv	a0,s6
 960:	cf9ff0ef          	jal	658 <printint>
        i += 2;
 964:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 968:	00048b93          	mv	s7,s1
      state = 0;
 96c:	00000993          	li	s3,0
        i += 2;
 970:	e39ff06f          	j	7a8 <vprintf+0x70>
 974:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 978:	008b8793          	addi	a5,s7,8
 97c:	00078c93          	mv	s9,a5
 980:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 984:	03000593          	li	a1,48
 988:	000b0513          	mv	a0,s6
 98c:	c3dff0ef          	jal	5c8 <putc>
  putc(fd, 'x');
 990:	07800593          	li	a1,120
 994:	000b0513          	mv	a0,s6
 998:	c31ff0ef          	jal	5c8 <putc>
 99c:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 9a0:	00000b97          	auipc	s7,0x0
 9a4:	448b8b93          	addi	s7,s7,1096 # de8 <digits>
 9a8:	03c9d793          	srli	a5,s3,0x3c
 9ac:	00fb87b3          	add	a5,s7,a5
 9b0:	0007c583          	lbu	a1,0(a5)
 9b4:	000b0513          	mv	a0,s6
 9b8:	c11ff0ef          	jal	5c8 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 9bc:	00499993          	slli	s3,s3,0x4
 9c0:	fff4849b          	addiw	s1,s1,-1
 9c4:	fe0492e3          	bnez	s1,9a8 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 9c8:	000c8b93          	mv	s7,s9
      state = 0;
 9cc:	00000993          	li	s3,0
 9d0:	00813c83          	ld	s9,8(sp)
 9d4:	dd5ff06f          	j	7a8 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 9d8:	008b8493          	addi	s1,s7,8
 9dc:	000bc583          	lbu	a1,0(s7)
 9e0:	000b0513          	mv	a0,s6
 9e4:	be5ff0ef          	jal	5c8 <putc>
 9e8:	00048b93          	mv	s7,s1
      state = 0;
 9ec:	00000993          	li	s3,0
 9f0:	db9ff06f          	j	7a8 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 9f4:	008b8993          	addi	s3,s7,8
 9f8:	000bb483          	ld	s1,0(s7)
 9fc:	02048663          	beqz	s1,a28 <vprintf+0x2f0>
        for (; *s; s++)
 a00:	0004c583          	lbu	a1,0(s1)
 a04:	04058463          	beqz	a1,a4c <vprintf+0x314>
          putc(fd, *s);
 a08:	000b0513          	mv	a0,s6
 a0c:	bbdff0ef          	jal	5c8 <putc>
        for (; *s; s++)
 a10:	00148493          	addi	s1,s1,1
 a14:	0004c583          	lbu	a1,0(s1)
 a18:	fe0598e3          	bnez	a1,a08 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 a1c:	00098b93          	mv	s7,s3
      state = 0;
 a20:	00000993          	li	s3,0
 a24:	d85ff06f          	j	7a8 <vprintf+0x70>
          s = "(null)";
 a28:	00000497          	auipc	s1,0x0
 a2c:	3b848493          	addi	s1,s1,952 # de0 <malloc+0x170>
        for (; *s; s++)
 a30:	02800593          	li	a1,40
 a34:	fd5ff06f          	j	a08 <vprintf+0x2d0>
        putc(fd, '%');
 a38:	00078593          	mv	a1,a5
 a3c:	000b0513          	mv	a0,s6
 a40:	b89ff0ef          	jal	5c8 <putc>
      state = 0;
 a44:	00000993          	li	s3,0
 a48:	d61ff06f          	j	7a8 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a4c:	00098b93          	mv	s7,s3
      state = 0;
 a50:	00000993          	li	s3,0
 a54:	d55ff06f          	j	7a8 <vprintf+0x70>
 a58:	04013903          	ld	s2,64(sp)
 a5c:	03813983          	ld	s3,56(sp)
 a60:	03013a03          	ld	s4,48(sp)
 a64:	02813a83          	ld	s5,40(sp)
 a68:	02013b03          	ld	s6,32(sp)
 a6c:	01813b83          	ld	s7,24(sp)
 a70:	01013c03          	ld	s8,16(sp)
    }
  }
}
 a74:	05813083          	ld	ra,88(sp)
 a78:	05013403          	ld	s0,80(sp)
 a7c:	04813483          	ld	s1,72(sp)
 a80:	06010113          	addi	sp,sp,96
 a84:	00008067          	ret
      if (c0 == 'd')
 a88:	06400713          	li	a4,100
 a8c:	d8e78ae3          	beq	a5,a4,820 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 a90:	f9478693          	addi	a3,a5,-108
 a94:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 a98:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 a9c:	00000713          	li	a4,0
      else if (c0 == 'u')
 aa0:	07500513          	li	a0,117
 aa4:	dea784e3          	beq	a5,a0,88c <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 aa8:	f8b60513          	addi	a0,a2,-117
 aac:	00051463          	bnez	a0,ab4 <vprintf+0x37c>
 ab0:	e00690e3          	bnez	a3,8b0 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 ab4:	f8b58513          	addi	a0,a1,-117
 ab8:	00051463          	bnez	a0,ac0 <vprintf+0x388>
 abc:	e0071ee3          	bnez	a4,8d8 <vprintf+0x1a0>
      else if (c0 == 'x')
 ac0:	07800513          	li	a0,120
 ac4:	e2a78ee3          	beq	a5,a0,900 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 ac8:	f8860613          	addi	a2,a2,-120
 acc:	00061463          	bnez	a2,ad4 <vprintf+0x39c>
 ad0:	e4069ae3          	bnez	a3,924 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 ad4:	f8858593          	addi	a1,a1,-120
 ad8:	00059463          	bnez	a1,ae0 <vprintf+0x3a8>
 adc:	e60718e3          	bnez	a4,94c <vprintf+0x214>
      else if (c0 == 'p')
 ae0:	07000713          	li	a4,112
 ae4:	e8e788e3          	beq	a5,a4,974 <vprintf+0x23c>
      else if (c0 == 'c')
 ae8:	06300713          	li	a4,99
 aec:	eee786e3          	beq	a5,a4,9d8 <vprintf+0x2a0>
      else if (c0 == 's')
 af0:	07300713          	li	a4,115
 af4:	f0e780e3          	beq	a5,a4,9f4 <vprintf+0x2bc>
      else if (c0 == '%')
 af8:	02500713          	li	a4,37
 afc:	f2e78ee3          	beq	a5,a4,a38 <vprintf+0x300>
        putc(fd, '%');
 b00:	02500593          	li	a1,37
 b04:	000b0513          	mv	a0,s6
 b08:	ac1ff0ef          	jal	5c8 <putc>
        putc(fd, c0);
 b0c:	00048593          	mv	a1,s1
 b10:	000b0513          	mv	a0,s6
 b14:	ab5ff0ef          	jal	5c8 <putc>
      state = 0;
 b18:	00000993          	li	s3,0
 b1c:	c8dff06f          	j	7a8 <vprintf+0x70>

0000000000000b20 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 b20:	fb010113          	addi	sp,sp,-80
 b24:	00113c23          	sd	ra,24(sp)
 b28:	00813823          	sd	s0,16(sp)
 b2c:	02010413          	addi	s0,sp,32
 b30:	00c43023          	sd	a2,0(s0)
 b34:	00d43423          	sd	a3,8(s0)
 b38:	00e43823          	sd	a4,16(s0)
 b3c:	00f43c23          	sd	a5,24(s0)
 b40:	03043023          	sd	a6,32(s0)
 b44:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 b48:	00040613          	mv	a2,s0
 b4c:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 b50:	be9ff0ef          	jal	738 <vprintf>
}
 b54:	01813083          	ld	ra,24(sp)
 b58:	01013403          	ld	s0,16(sp)
 b5c:	05010113          	addi	sp,sp,80
 b60:	00008067          	ret

0000000000000b64 <printf>:

void printf(const char *fmt, ...)
{
 b64:	fa010113          	addi	sp,sp,-96
 b68:	00113c23          	sd	ra,24(sp)
 b6c:	00813823          	sd	s0,16(sp)
 b70:	02010413          	addi	s0,sp,32
 b74:	00b43423          	sd	a1,8(s0)
 b78:	00c43823          	sd	a2,16(s0)
 b7c:	00d43c23          	sd	a3,24(s0)
 b80:	02e43023          	sd	a4,32(s0)
 b84:	02f43423          	sd	a5,40(s0)
 b88:	03043823          	sd	a6,48(s0)
 b8c:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 b90:	00840613          	addi	a2,s0,8
 b94:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 b98:	00050593          	mv	a1,a0
 b9c:	00100513          	li	a0,1
 ba0:	b99ff0ef          	jal	738 <vprintf>
  putc_flush();
 ba4:	9d9ff0ef          	jal	57c <putc_flush>
}
 ba8:	01813083          	ld	ra,24(sp)
 bac:	01013403          	ld	s0,16(sp)
 bb0:	06010113          	addi	sp,sp,96
 bb4:	00008067          	ret

0000000000000bb8 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 bb8:	ff010113          	addi	sp,sp,-16
 bbc:	00113423          	sd	ra,8(sp)
 bc0:	00813023          	sd	s0,0(sp)
 bc4:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 bc8:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 bcc:	00000797          	auipc	a5,0x0
 bd0:	44c7b783          	ld	a5,1100(a5) # 1018 <freep>
 bd4:	0140006f          	j	be8 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 bd8:	0007b703          	ld	a4,0(a5)
 bdc:	00e7e463          	bltu	a5,a4,be4 <free+0x2c>
 be0:	00e6ec63          	bltu	a3,a4,bf8 <free+0x40>
{
 be4:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 be8:	fed7f8e3          	bgeu	a5,a3,bd8 <free+0x20>
 bec:	0007b703          	ld	a4,0(a5)
 bf0:	00e6e463          	bltu	a3,a4,bf8 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 bf4:	fee7e8e3          	bltu	a5,a4,be4 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 bf8:	ff852583          	lw	a1,-8(a0)
 bfc:	0007b603          	ld	a2,0(a5)
 c00:	02059813          	slli	a6,a1,0x20
 c04:	01c85713          	srli	a4,a6,0x1c
 c08:	00e68733          	add	a4,a3,a4
 c0c:	02e60c63          	beq	a2,a4,c44 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c10:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c14:	0087a603          	lw	a2,8(a5)
 c18:	02061593          	slli	a1,a2,0x20
 c1c:	01c5d713          	srli	a4,a1,0x1c
 c20:	00e78733          	add	a4,a5,a4
 c24:	02e68c63          	beq	a3,a4,c5c <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 c28:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 c2c:	00000717          	auipc	a4,0x0
 c30:	3ef73623          	sd	a5,1004(a4) # 1018 <freep>
}
 c34:	00813083          	ld	ra,8(sp)
 c38:	00013403          	ld	s0,0(sp)
 c3c:	01010113          	addi	sp,sp,16
 c40:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 c44:	00862703          	lw	a4,8(a2)
 c48:	00b7073b          	addw	a4,a4,a1
 c4c:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 c50:	0007b703          	ld	a4,0(a5)
 c54:	00073603          	ld	a2,0(a4)
 c58:	fb9ff06f          	j	c10 <free+0x58>
    p->s.size += bp->s.size;
 c5c:	ff852703          	lw	a4,-8(a0)
 c60:	00c7073b          	addw	a4,a4,a2
 c64:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 c68:	ff053683          	ld	a3,-16(a0)
 c6c:	fbdff06f          	j	c28 <free+0x70>

0000000000000c70 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 c70:	fc010113          	addi	sp,sp,-64
 c74:	02113c23          	sd	ra,56(sp)
 c78:	02813823          	sd	s0,48(sp)
 c7c:	03213023          	sd	s2,32(sp)
 c80:	01313c23          	sd	s3,24(sp)
 c84:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 c88:	02051993          	slli	s3,a0,0x20
 c8c:	0209d993          	srli	s3,s3,0x20
 c90:	00f98993          	addi	s3,s3,15
 c94:	0049d993          	srli	s3,s3,0x4
 c98:	0019899b          	addiw	s3,s3,1
 c9c:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 ca0:	00000517          	auipc	a0,0x0
 ca4:	37853503          	ld	a0,888(a0) # 1018 <freep>
 ca8:	04050463          	beqz	a0,cf0 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 cac:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 cb0:	0087a703          	lw	a4,8(a5)
 cb4:	0d377a63          	bgeu	a4,s3,d88 <malloc+0x118>
 cb8:	02913423          	sd	s1,40(sp)
 cbc:	01413823          	sd	s4,16(sp)
 cc0:	01513423          	sd	s5,8(sp)
 cc4:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 cc8:	00098a13          	mv	s4,s3
 ccc:	00001737          	lui	a4,0x1
 cd0:	00e9f463          	bgeu	s3,a4,cd8 <malloc+0x68>
 cd4:	00001a37          	lui	s4,0x1
 cd8:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 cdc:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 ce0:	00000497          	auipc	s1,0x0
 ce4:	33848493          	addi	s1,s1,824 # 1018 <freep>
  if(p == SBRK_ERROR)
 ce8:	fff00a93          	li	s5,-1
 cec:	05c0006f          	j	d48 <malloc+0xd8>
 cf0:	02913423          	sd	s1,40(sp)
 cf4:	01413823          	sd	s4,16(sp)
 cf8:	01513423          	sd	s5,8(sp)
 cfc:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d00:	00000797          	auipc	a5,0x0
 d04:	3a078793          	addi	a5,a5,928 # 10a0 <base>
 d08:	00000717          	auipc	a4,0x0
 d0c:	30f73823          	sd	a5,784(a4) # 1018 <freep>
 d10:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d14:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d18:	fb1ff06f          	j	cc8 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 d1c:	0007b703          	ld	a4,0(a5)
 d20:	00e53023          	sd	a4,0(a0)
 d24:	0800006f          	j	da4 <malloc+0x134>
  hp->s.size = nu;
 d28:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 d2c:	01050513          	addi	a0,a0,16
 d30:	e89ff0ef          	jal	bb8 <free>
  return freep;
 d34:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 d38:	08050863          	beqz	a0,dc8 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d3c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d40:	0087a703          	lw	a4,8(a5)
 d44:	03277a63          	bgeu	a4,s2,d78 <malloc+0x108>
    if(p == freep)
 d48:	0004b703          	ld	a4,0(s1)
 d4c:	00078513          	mv	a0,a5
 d50:	fef716e3          	bne	a4,a5,d3c <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 d54:	000a0513          	mv	a0,s4
 d58:	ed8ff0ef          	jal	430 <sbrk>
  if(p == SBRK_ERROR)
 d5c:	fd5516e3          	bne	a0,s5,d28 <malloc+0xb8>
        return 0;
 d60:	00000513          	li	a0,0
 d64:	02813483          	ld	s1,40(sp)
 d68:	01013a03          	ld	s4,16(sp)
 d6c:	00813a83          	ld	s5,8(sp)
 d70:	00013b03          	ld	s6,0(sp)
 d74:	03c0006f          	j	db0 <malloc+0x140>
 d78:	02813483          	ld	s1,40(sp)
 d7c:	01013a03          	ld	s4,16(sp)
 d80:	00813a83          	ld	s5,8(sp)
 d84:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 d88:	f8e90ae3          	beq	s2,a4,d1c <malloc+0xac>
        p->s.size -= nunits;
 d8c:	4137073b          	subw	a4,a4,s3
 d90:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 d94:	02071693          	slli	a3,a4,0x20
 d98:	01c6d713          	srli	a4,a3,0x1c
 d9c:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 da0:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 da4:	00000717          	auipc	a4,0x0
 da8:	26a73a23          	sd	a0,628(a4) # 1018 <freep>
      return (void*)(p + 1);
 dac:	01078513          	addi	a0,a5,16
  }
}
 db0:	03813083          	ld	ra,56(sp)
 db4:	03013403          	ld	s0,48(sp)
 db8:	02013903          	ld	s2,32(sp)
 dbc:	01813983          	ld	s3,24(sp)
 dc0:	04010113          	addi	sp,sp,64
 dc4:	00008067          	ret
 dc8:	02813483          	ld	s1,40(sp)
 dcc:	01013a03          	ld	s4,16(sp)
 dd0:	00813a83          	ld	s5,8(sp)
 dd4:	00013b03          	ld	s6,0(sp)
 dd8:	fd9ff06f          	j	db0 <malloc+0x140>
