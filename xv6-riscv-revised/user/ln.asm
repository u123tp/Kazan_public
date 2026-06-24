
user/_ln:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
   0:	fe010113          	addi	sp,sp,-32
   4:	00113c23          	sd	ra,24(sp)
   8:	00813823          	sd	s0,16(sp)
   c:	02010413          	addi	s0,sp,32
  if(argc != 3){
  10:	00300793          	li	a5,3
  14:	02f50063          	beq	a0,a5,34 <main+0x34>
  18:	00913423          	sd	s1,8(sp)
    fprintf(2, "Usage: ln old new\n");
  1c:	00001597          	auipc	a1,0x1
  20:	e0458593          	addi	a1,a1,-508 # e20 <malloc+0x16c>
  24:	00200513          	li	a0,2
  28:	33d000ef          	jal	b64 <fprintf>
    exit(1);
  2c:	00100513          	li	a0,1
  30:	4a0000ef          	jal	4d0 <exit>
  34:	00913423          	sd	s1,8(sp)
  38:	00058493          	mv	s1,a1
  }
  if(link(argv[1], argv[2]) < 0)
  3c:	0105b583          	ld	a1,16(a1)
  40:	0084b503          	ld	a0,8(s1)
  44:	51c000ef          	jal	560 <link>
  48:	00054663          	bltz	a0,54 <main+0x54>
    fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  exit(0);
  4c:	00000513          	li	a0,0
  50:	480000ef          	jal	4d0 <exit>
    fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  54:	0104b683          	ld	a3,16(s1)
  58:	0084b603          	ld	a2,8(s1)
  5c:	00001597          	auipc	a1,0x1
  60:	ddc58593          	addi	a1,a1,-548 # e38 <malloc+0x184>
  64:	00200513          	li	a0,2
  68:	2fd000ef          	jal	b64 <fprintf>
  6c:	fe1ff06f          	j	4c <main+0x4c>

0000000000000070 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  70:	ff010113          	addi	sp,sp,-16
  74:	00113423          	sd	ra,8(sp)
  78:	00813023          	sd	s0,0(sp)
  7c:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  80:	f81ff0ef          	jal	0 <main>
  exit(r);
  84:	44c000ef          	jal	4d0 <exit>

0000000000000088 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  88:	ff010113          	addi	sp,sp,-16
  8c:	00113423          	sd	ra,8(sp)
  90:	00813023          	sd	s0,0(sp)
  94:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  98:	00050793          	mv	a5,a0
  9c:	00158593          	addi	a1,a1,1
  a0:	00178793          	addi	a5,a5,1
  a4:	fff5c703          	lbu	a4,-1(a1)
  a8:	fee78fa3          	sb	a4,-1(a5)
  ac:	fe0718e3          	bnez	a4,9c <strcpy+0x14>
    ;
  return os;
}
  b0:	00813083          	ld	ra,8(sp)
  b4:	00013403          	ld	s0,0(sp)
  b8:	01010113          	addi	sp,sp,16
  bc:	00008067          	ret

00000000000000c0 <strcmp>:

int
strcmp(const char *p, const char *q)
{
  c0:	ff010113          	addi	sp,sp,-16
  c4:	00113423          	sd	ra,8(sp)
  c8:	00813023          	sd	s0,0(sp)
  cc:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
  d0:	00054783          	lbu	a5,0(a0)
  d4:	00078e63          	beqz	a5,f0 <strcmp+0x30>
  d8:	0005c703          	lbu	a4,0(a1)
  dc:	00f71a63          	bne	a4,a5,f0 <strcmp+0x30>
    p++, q++;
  e0:	00150513          	addi	a0,a0,1
  e4:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
  e8:	00054783          	lbu	a5,0(a0)
  ec:	fe0796e3          	bnez	a5,d8 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
  f0:	0005c503          	lbu	a0,0(a1)
}
  f4:	40a7853b          	subw	a0,a5,a0
  f8:	00813083          	ld	ra,8(sp)
  fc:	00013403          	ld	s0,0(sp)
 100:	01010113          	addi	sp,sp,16
 104:	00008067          	ret

0000000000000108 <strlen>:

uint
strlen(const char *s)
{
 108:	ff010113          	addi	sp,sp,-16
 10c:	00113423          	sd	ra,8(sp)
 110:	00813023          	sd	s0,0(sp)
 114:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 118:	00054783          	lbu	a5,0(a0)
 11c:	02078663          	beqz	a5,148 <strlen+0x40>
 120:	00150793          	addi	a5,a0,1
 124:	00078693          	mv	a3,a5
 128:	00178793          	addi	a5,a5,1
 12c:	fff7c703          	lbu	a4,-1(a5)
 130:	fe071ae3          	bnez	a4,124 <strlen+0x1c>
 134:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 138:	00813083          	ld	ra,8(sp)
 13c:	00013403          	ld	s0,0(sp)
 140:	01010113          	addi	sp,sp,16
 144:	00008067          	ret
  for(n = 0; s[n]; n++)
 148:	00000513          	li	a0,0
 14c:	fedff06f          	j	138 <strlen+0x30>

0000000000000150 <memset>:

void*
memset(void *dst, int c, uint n)
{
 150:	ff010113          	addi	sp,sp,-16
 154:	00113423          	sd	ra,8(sp)
 158:	00813023          	sd	s0,0(sp)
 15c:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 160:	02060063          	beqz	a2,180 <memset+0x30>
 164:	00050793          	mv	a5,a0
 168:	02061613          	slli	a2,a2,0x20
 16c:	02065613          	srli	a2,a2,0x20
 170:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 174:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 178:	00178793          	addi	a5,a5,1
 17c:	fee79ce3          	bne	a5,a4,174 <memset+0x24>
  }
  return dst;
}
 180:	00813083          	ld	ra,8(sp)
 184:	00013403          	ld	s0,0(sp)
 188:	01010113          	addi	sp,sp,16
 18c:	00008067          	ret

0000000000000190 <strchr>:

char*
strchr(const char *s, char c)
{
 190:	ff010113          	addi	sp,sp,-16
 194:	00113423          	sd	ra,8(sp)
 198:	00813023          	sd	s0,0(sp)
 19c:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 1a0:	00054783          	lbu	a5,0(a0)
 1a4:	02078463          	beqz	a5,1cc <strchr+0x3c>
    if(*s == c)
 1a8:	00f58a63          	beq	a1,a5,1bc <strchr+0x2c>
  for(; *s; s++)
 1ac:	00150513          	addi	a0,a0,1
 1b0:	00054783          	lbu	a5,0(a0)
 1b4:	fe079ae3          	bnez	a5,1a8 <strchr+0x18>
      return (char*)s;
  return 0;
 1b8:	00000513          	li	a0,0
}
 1bc:	00813083          	ld	ra,8(sp)
 1c0:	00013403          	ld	s0,0(sp)
 1c4:	01010113          	addi	sp,sp,16
 1c8:	00008067          	ret
  return 0;
 1cc:	00000513          	li	a0,0
 1d0:	fedff06f          	j	1bc <strchr+0x2c>

00000000000001d4 <gets>:

char*
gets(char *buf, int max)
{
 1d4:	fa010113          	addi	sp,sp,-96
 1d8:	04113c23          	sd	ra,88(sp)
 1dc:	04813823          	sd	s0,80(sp)
 1e0:	04913423          	sd	s1,72(sp)
 1e4:	05213023          	sd	s2,64(sp)
 1e8:	03313c23          	sd	s3,56(sp)
 1ec:	03413823          	sd	s4,48(sp)
 1f0:	03513423          	sd	s5,40(sp)
 1f4:	03613023          	sd	s6,32(sp)
 1f8:	01713c23          	sd	s7,24(sp)
 1fc:	01813823          	sd	s8,16(sp)
 200:	06010413          	addi	s0,sp,96
 204:	00050b93          	mv	s7,a0
 208:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 20c:	00050913          	mv	s2,a0
 210:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 214:	faf40b13          	addi	s6,s0,-81
 218:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 21c:	00048c13          	mv	s8,s1
 220:	0014899b          	addiw	s3,s1,1
 224:	00098493          	mv	s1,s3
 228:	0349dc63          	bge	s3,s4,260 <gets+0x8c>
    cc = read(0, &c, 1);
 22c:	000a8613          	mv	a2,s5
 230:	000b0593          	mv	a1,s6
 234:	00000513          	li	a0,0
 238:	2bc000ef          	jal	4f4 <read>
    if(cc < 1)
 23c:	02a05263          	blez	a0,260 <gets+0x8c>
      break;
    buf[i++] = c;
 240:	faf44783          	lbu	a5,-81(s0)
 244:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 248:	00190913          	addi	s2,s2,1
 24c:	ff678713          	addi	a4,a5,-10
 250:	00070663          	beqz	a4,25c <gets+0x88>
 254:	ff378793          	addi	a5,a5,-13
 258:	fc0792e3          	bnez	a5,21c <gets+0x48>
    buf[i++] = c;
 25c:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 260:	018b8c33          	add	s8,s7,s8
 264:	000c0023          	sb	zero,0(s8)
  return buf;
}
 268:	000b8513          	mv	a0,s7
 26c:	05813083          	ld	ra,88(sp)
 270:	05013403          	ld	s0,80(sp)
 274:	04813483          	ld	s1,72(sp)
 278:	04013903          	ld	s2,64(sp)
 27c:	03813983          	ld	s3,56(sp)
 280:	03013a03          	ld	s4,48(sp)
 284:	02813a83          	ld	s5,40(sp)
 288:	02013b03          	ld	s6,32(sp)
 28c:	01813b83          	ld	s7,24(sp)
 290:	01013c03          	ld	s8,16(sp)
 294:	06010113          	addi	sp,sp,96
 298:	00008067          	ret

000000000000029c <stat>:

int
stat(const char *n, struct stat *st)
{
 29c:	fe010113          	addi	sp,sp,-32
 2a0:	00113c23          	sd	ra,24(sp)
 2a4:	00813823          	sd	s0,16(sp)
 2a8:	01213023          	sd	s2,0(sp)
 2ac:	02010413          	addi	s0,sp,32
 2b0:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 2b4:	00000593          	li	a1,0
 2b8:	278000ef          	jal	530 <open>
  if(fd < 0)
 2bc:	02054e63          	bltz	a0,2f8 <stat+0x5c>
 2c0:	00913423          	sd	s1,8(sp)
 2c4:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 2c8:	00090593          	mv	a1,s2
 2cc:	288000ef          	jal	554 <fstat>
 2d0:	00050913          	mv	s2,a0
  close(fd);
 2d4:	00048513          	mv	a0,s1
 2d8:	234000ef          	jal	50c <close>
  return r;
 2dc:	00813483          	ld	s1,8(sp)
}
 2e0:	00090513          	mv	a0,s2
 2e4:	01813083          	ld	ra,24(sp)
 2e8:	01013403          	ld	s0,16(sp)
 2ec:	00013903          	ld	s2,0(sp)
 2f0:	02010113          	addi	sp,sp,32
 2f4:	00008067          	ret
    return -1;
 2f8:	fff00793          	li	a5,-1
 2fc:	00078913          	mv	s2,a5
 300:	fe1ff06f          	j	2e0 <stat+0x44>

0000000000000304 <atoi>:

int
atoi(const char *s)
{
 304:	ff010113          	addi	sp,sp,-16
 308:	00113423          	sd	ra,8(sp)
 30c:	00813023          	sd	s0,0(sp)
 310:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 314:	00054683          	lbu	a3,0(a0)
 318:	fd06879b          	addiw	a5,a3,-48
 31c:	0ff7f793          	zext.b	a5,a5
 320:	00900613          	li	a2,9
 324:	04f66263          	bltu	a2,a5,368 <atoi+0x64>
 328:	00050713          	mv	a4,a0
  n = 0;
 32c:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 330:	00170713          	addi	a4,a4,1
 334:	0025179b          	slliw	a5,a0,0x2
 338:	00a787bb          	addw	a5,a5,a0
 33c:	0017979b          	slliw	a5,a5,0x1
 340:	00d787bb          	addw	a5,a5,a3
 344:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 348:	00074683          	lbu	a3,0(a4)
 34c:	fd06879b          	addiw	a5,a3,-48
 350:	0ff7f793          	zext.b	a5,a5
 354:	fcf67ee3          	bgeu	a2,a5,330 <atoi+0x2c>
  return n;
}
 358:	00813083          	ld	ra,8(sp)
 35c:	00013403          	ld	s0,0(sp)
 360:	01010113          	addi	sp,sp,16
 364:	00008067          	ret
  n = 0;
 368:	00000513          	li	a0,0
 36c:	fedff06f          	j	358 <atoi+0x54>

0000000000000370 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 370:	ff010113          	addi	sp,sp,-16
 374:	00113423          	sd	ra,8(sp)
 378:	00813023          	sd	s0,0(sp)
 37c:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 380:	02b57e63          	bgeu	a0,a1,3bc <memmove+0x4c>
    while(n-- > 0)
 384:	02c05463          	blez	a2,3ac <memmove+0x3c>
 388:	02061613          	slli	a2,a2,0x20
 38c:	02065613          	srli	a2,a2,0x20
 390:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 394:	00050713          	mv	a4,a0
      *dst++ = *src++;
 398:	00158593          	addi	a1,a1,1
 39c:	00170713          	addi	a4,a4,1
 3a0:	fff5c683          	lbu	a3,-1(a1)
 3a4:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 3a8:	fee798e3          	bne	a5,a4,398 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 3ac:	00813083          	ld	ra,8(sp)
 3b0:	00013403          	ld	s0,0(sp)
 3b4:	01010113          	addi	sp,sp,16
 3b8:	00008067          	ret
    while(n-- > 0)
 3bc:	fec058e3          	blez	a2,3ac <memmove+0x3c>
    dst += n;
 3c0:	00c50733          	add	a4,a0,a2
    src += n;
 3c4:	00c585b3          	add	a1,a1,a2
 3c8:	fff6079b          	addiw	a5,a2,-1
 3cc:	02079793          	slli	a5,a5,0x20
 3d0:	0207d793          	srli	a5,a5,0x20
 3d4:	fff7c793          	not	a5,a5
 3d8:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 3dc:	fff58593          	addi	a1,a1,-1
 3e0:	fff70713          	addi	a4,a4,-1
 3e4:	0005c683          	lbu	a3,0(a1)
 3e8:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 3ec:	fef718e3          	bne	a4,a5,3dc <memmove+0x6c>
 3f0:	fbdff06f          	j	3ac <memmove+0x3c>

00000000000003f4 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 3f4:	ff010113          	addi	sp,sp,-16
 3f8:	00113423          	sd	ra,8(sp)
 3fc:	00813023          	sd	s0,0(sp)
 400:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 404:	04060263          	beqz	a2,448 <memcmp+0x54>
 408:	02061613          	slli	a2,a2,0x20
 40c:	02065613          	srli	a2,a2,0x20
 410:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 414:	00054783          	lbu	a5,0(a0)
 418:	0005c703          	lbu	a4,0(a1)
 41c:	00e79c63          	bne	a5,a4,434 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 420:	00150513          	addi	a0,a0,1
    p2++;
 424:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 428:	fed516e3          	bne	a0,a3,414 <memcmp+0x20>
  }
  return 0;
 42c:	00000513          	li	a0,0
 430:	0080006f          	j	438 <memcmp+0x44>
      return *p1 - *p2;
 434:	40e7853b          	subw	a0,a5,a4
}
 438:	00813083          	ld	ra,8(sp)
 43c:	00013403          	ld	s0,0(sp)
 440:	01010113          	addi	sp,sp,16
 444:	00008067          	ret
  return 0;
 448:	00000513          	li	a0,0
 44c:	fedff06f          	j	438 <memcmp+0x44>

0000000000000450 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 450:	ff010113          	addi	sp,sp,-16
 454:	00113423          	sd	ra,8(sp)
 458:	00813023          	sd	s0,0(sp)
 45c:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 460:	f11ff0ef          	jal	370 <memmove>
}
 464:	00813083          	ld	ra,8(sp)
 468:	00013403          	ld	s0,0(sp)
 46c:	01010113          	addi	sp,sp,16
 470:	00008067          	ret

0000000000000474 <sbrk>:

char *
sbrk(int n) {
 474:	ff010113          	addi	sp,sp,-16
 478:	00113423          	sd	ra,8(sp)
 47c:	00813023          	sd	s0,0(sp)
 480:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 484:	00100593          	li	a1,1
 488:	114000ef          	jal	59c <sys_sbrk>
}
 48c:	00813083          	ld	ra,8(sp)
 490:	00013403          	ld	s0,0(sp)
 494:	01010113          	addi	sp,sp,16
 498:	00008067          	ret

000000000000049c <sbrklazy>:

char *
sbrklazy(int n) {
 49c:	ff010113          	addi	sp,sp,-16
 4a0:	00113423          	sd	ra,8(sp)
 4a4:	00813023          	sd	s0,0(sp)
 4a8:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 4ac:	00200593          	li	a1,2
 4b0:	0ec000ef          	jal	59c <sys_sbrk>
}
 4b4:	00813083          	ld	ra,8(sp)
 4b8:	00013403          	ld	s0,0(sp)
 4bc:	01010113          	addi	sp,sp,16
 4c0:	00008067          	ret

00000000000004c4 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 4c4:	00100893          	li	a7,1
 ecall
 4c8:	00000073          	ecall
 ret
 4cc:	00008067          	ret

00000000000004d0 <exit>:
.global exit
exit:
 li a7, SYS_exit
 4d0:	00200893          	li	a7,2
 ecall
 4d4:	00000073          	ecall
 ret
 4d8:	00008067          	ret

00000000000004dc <wait>:
.global wait
wait:
 li a7, SYS_wait
 4dc:	00300893          	li	a7,3
 ecall
 4e0:	00000073          	ecall
 ret
 4e4:	00008067          	ret

00000000000004e8 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 4e8:	00400893          	li	a7,4
 ecall
 4ec:	00000073          	ecall
 ret
 4f0:	00008067          	ret

00000000000004f4 <read>:
.global read
read:
 li a7, SYS_read
 4f4:	00500893          	li	a7,5
 ecall
 4f8:	00000073          	ecall
 ret
 4fc:	00008067          	ret

0000000000000500 <write>:
.global write
write:
 li a7, SYS_write
 500:	01000893          	li	a7,16
 ecall
 504:	00000073          	ecall
 ret
 508:	00008067          	ret

000000000000050c <close>:
.global close
close:
 li a7, SYS_close
 50c:	01500893          	li	a7,21
 ecall
 510:	00000073          	ecall
 ret
 514:	00008067          	ret

0000000000000518 <kill>:
.global kill
kill:
 li a7, SYS_kill
 518:	00600893          	li	a7,6
 ecall
 51c:	00000073          	ecall
 ret
 520:	00008067          	ret

0000000000000524 <exec>:
.global exec
exec:
 li a7, SYS_exec
 524:	00700893          	li	a7,7
 ecall
 528:	00000073          	ecall
 ret
 52c:	00008067          	ret

0000000000000530 <open>:
.global open
open:
 li a7, SYS_open
 530:	00f00893          	li	a7,15
 ecall
 534:	00000073          	ecall
 ret
 538:	00008067          	ret

000000000000053c <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 53c:	01100893          	li	a7,17
 ecall
 540:	00000073          	ecall
 ret
 544:	00008067          	ret

0000000000000548 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 548:	01200893          	li	a7,18
 ecall
 54c:	00000073          	ecall
 ret
 550:	00008067          	ret

0000000000000554 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 554:	00800893          	li	a7,8
 ecall
 558:	00000073          	ecall
 ret
 55c:	00008067          	ret

0000000000000560 <link>:
.global link
link:
 li a7, SYS_link
 560:	01300893          	li	a7,19
 ecall
 564:	00000073          	ecall
 ret
 568:	00008067          	ret

000000000000056c <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 56c:	01400893          	li	a7,20
 ecall
 570:	00000073          	ecall
 ret
 574:	00008067          	ret

0000000000000578 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 578:	00900893          	li	a7,9
 ecall
 57c:	00000073          	ecall
 ret
 580:	00008067          	ret

0000000000000584 <dup>:
.global dup
dup:
 li a7, SYS_dup
 584:	00a00893          	li	a7,10
 ecall
 588:	00000073          	ecall
 ret
 58c:	00008067          	ret

0000000000000590 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 590:	00b00893          	li	a7,11
 ecall
 594:	00000073          	ecall
 ret
 598:	00008067          	ret

000000000000059c <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 59c:	00c00893          	li	a7,12
 ecall
 5a0:	00000073          	ecall
 ret
 5a4:	00008067          	ret

00000000000005a8 <pause>:
.global pause
pause:
 li a7, SYS_pause
 5a8:	00d00893          	li	a7,13
 ecall
 5ac:	00000073          	ecall
 ret
 5b0:	00008067          	ret

00000000000005b4 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 5b4:	00e00893          	li	a7,14
 ecall
 5b8:	00000073          	ecall
 ret
 5bc:	00008067          	ret

00000000000005c0 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 5c0:	00001617          	auipc	a2,0x1
 5c4:	a5062603          	lw	a2,-1456(a2) # 1010 <putc_n>
 5c8:	00c04463          	bgtz	a2,5d0 <putc_flush+0x10>
 5cc:	00008067          	ret
{
 5d0:	ff010113          	addi	sp,sp,-16
 5d4:	00113423          	sd	ra,8(sp)
 5d8:	00813023          	sd	s0,0(sp)
 5dc:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 5e0:	00001597          	auipc	a1,0x1
 5e4:	a4058593          	addi	a1,a1,-1472 # 1020 <putc_buf>
 5e8:	00001517          	auipc	a0,0x1
 5ec:	a1852503          	lw	a0,-1512(a0) # 1000 <putc_fd>
 5f0:	f11ff0ef          	jal	500 <write>
    putc_n = 0;
 5f4:	00001797          	auipc	a5,0x1
 5f8:	a007ae23          	sw	zero,-1508(a5) # 1010 <putc_n>
  }
}
 5fc:	00813083          	ld	ra,8(sp)
 600:	00013403          	ld	s0,0(sp)
 604:	01010113          	addi	sp,sp,16
 608:	00008067          	ret

000000000000060c <putc>:

static void
putc(int fd, char c)
{
 60c:	fe010113          	addi	sp,sp,-32
 610:	00113c23          	sd	ra,24(sp)
 614:	00813823          	sd	s0,16(sp)
 618:	00913423          	sd	s1,8(sp)
 61c:	02010413          	addi	s0,sp,32
 620:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 624:	00001797          	auipc	a5,0x1
 628:	9dc7a783          	lw	a5,-1572(a5) # 1000 <putc_fd>
 62c:	04a79663          	bne	a5,a0,678 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 630:	00001717          	auipc	a4,0x1
 634:	9e070713          	addi	a4,a4,-1568 # 1010 <putc_n>
 638:	00072683          	lw	a3,0(a4)
 63c:	0016879b          	addiw	a5,a3,1
 640:	00f72023          	sw	a5,0(a4)
 644:	00001717          	auipc	a4,0x1
 648:	9dc70713          	addi	a4,a4,-1572 # 1020 <putc_buf>
 64c:	00d70733          	add	a4,a4,a3
 650:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 654:	ff648493          	addi	s1,s1,-10
 658:	02048e63          	beqz	s1,694 <putc+0x88>
 65c:	f8078793          	addi	a5,a5,-128
 660:	02078a63          	beqz	a5,694 <putc+0x88>
    putc_flush();
}
 664:	01813083          	ld	ra,24(sp)
 668:	01013403          	ld	s0,16(sp)
 66c:	00813483          	ld	s1,8(sp)
 670:	02010113          	addi	sp,sp,32
 674:	00008067          	ret
 678:	01213023          	sd	s2,0(sp)
 67c:	00050913          	mv	s2,a0
    putc_flush();
 680:	f41ff0ef          	jal	5c0 <putc_flush>
    putc_fd = fd;
 684:	00001797          	auipc	a5,0x1
 688:	9727ae23          	sw	s2,-1668(a5) # 1000 <putc_fd>
 68c:	00013903          	ld	s2,0(sp)
 690:	fa1ff06f          	j	630 <putc+0x24>
    putc_flush();
 694:	f2dff0ef          	jal	5c0 <putc_flush>
}
 698:	fcdff06f          	j	664 <putc+0x58>

000000000000069c <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 69c:	fb010113          	addi	sp,sp,-80
 6a0:	04113423          	sd	ra,72(sp)
 6a4:	04813023          	sd	s0,64(sp)
 6a8:	03213823          	sd	s2,48(sp)
 6ac:	03313423          	sd	s3,40(sp)
 6b0:	05010413          	addi	s0,sp,80
 6b4:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 6b8:	0a068e63          	beqz	a3,774 <printint+0xd8>
 6bc:	0a05dc63          	bgez	a1,774 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 6c0:	40b005b3          	neg	a1,a1
    neg = 1;
 6c4:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 6c8:	fb840993          	addi	s3,s0,-72
  neg = 0;
 6cc:	00098693          	mv	a3,s3
  i = 0;
 6d0:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 6d4:	00000817          	auipc	a6,0x0
 6d8:	78480813          	addi	a6,a6,1924 # e58 <digits>
 6dc:	00070893          	mv	a7,a4
 6e0:	0017051b          	addiw	a0,a4,1
 6e4:	00050713          	mv	a4,a0
 6e8:	02c5f7b3          	remu	a5,a1,a2
 6ec:	00f807b3          	add	a5,a6,a5
 6f0:	0007c783          	lbu	a5,0(a5)
 6f4:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 6f8:	00058793          	mv	a5,a1
 6fc:	02c5d5b3          	divu	a1,a1,a2
 700:	00168693          	addi	a3,a3,1
 704:	fcc7fce3          	bgeu	a5,a2,6dc <printint+0x40>
  if (neg)
 708:	00030c63          	beqz	t1,720 <printint+0x84>
    buf[i++] = '-';
 70c:	fd050793          	addi	a5,a0,-48
 710:	00878533          	add	a0,a5,s0
 714:	02d00793          	li	a5,45
 718:	fef50423          	sb	a5,-24(a0)
 71c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 720:	02e05e63          	blez	a4,75c <printint+0xc0>
 724:	02913c23          	sd	s1,56(sp)
 728:	fff7071b          	addiw	a4,a4,-1
 72c:	00e984b3          	add	s1,s3,a4
 730:	fff98993          	addi	s3,s3,-1
 734:	00e989b3          	add	s3,s3,a4
 738:	02071713          	slli	a4,a4,0x20
 73c:	02075713          	srli	a4,a4,0x20
 740:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 744:	0004c583          	lbu	a1,0(s1)
 748:	00090513          	mv	a0,s2
 74c:	ec1ff0ef          	jal	60c <putc>
  while (--i >= 0)
 750:	fff48493          	addi	s1,s1,-1
 754:	ff3498e3          	bne	s1,s3,744 <printint+0xa8>
 758:	03813483          	ld	s1,56(sp)
}
 75c:	04813083          	ld	ra,72(sp)
 760:	04013403          	ld	s0,64(sp)
 764:	03013903          	ld	s2,48(sp)
 768:	02813983          	ld	s3,40(sp)
 76c:	05010113          	addi	sp,sp,80
 770:	00008067          	ret
  neg = 0;
 774:	00000313          	li	t1,0
 778:	f51ff06f          	j	6c8 <printint+0x2c>

000000000000077c <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 77c:	fa010113          	addi	sp,sp,-96
 780:	04113c23          	sd	ra,88(sp)
 784:	04813823          	sd	s0,80(sp)
 788:	04913423          	sd	s1,72(sp)
 78c:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 790:	0005c483          	lbu	s1,0(a1)
 794:	32048263          	beqz	s1,ab8 <vprintf+0x33c>
 798:	05213023          	sd	s2,64(sp)
 79c:	03313c23          	sd	s3,56(sp)
 7a0:	03413823          	sd	s4,48(sp)
 7a4:	03513423          	sd	s5,40(sp)
 7a8:	03613023          	sd	s6,32(sp)
 7ac:	01713c23          	sd	s7,24(sp)
 7b0:	01813823          	sd	s8,16(sp)
 7b4:	00050b13          	mv	s6,a0
 7b8:	00058a13          	mv	s4,a1
 7bc:	00060b93          	mv	s7,a2
  state = 0;
 7c0:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 7c4:	00000913          	li	s2,0
 7c8:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 7cc:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 7d0:	06400c13          	li	s8,100
 7d4:	0300006f          	j	804 <vprintf+0x88>
        putc(fd, c0);
 7d8:	00048593          	mv	a1,s1
 7dc:	000b0513          	mv	a0,s6
 7e0:	e2dff0ef          	jal	60c <putc>
 7e4:	0080006f          	j	7ec <vprintf+0x70>
    else if (state == '%')
 7e8:	03598863          	beq	s3,s5,818 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 7ec:	0019079b          	addiw	a5,s2,1
 7f0:	00078913          	mv	s2,a5
 7f4:	00078713          	mv	a4,a5
 7f8:	00fa07b3          	add	a5,s4,a5
 7fc:	0007c483          	lbu	s1,0(a5)
 800:	28048e63          	beqz	s1,a9c <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 804:	0004879b          	sext.w	a5,s1
    if (state == 0)
 808:	fe0990e3          	bnez	s3,7e8 <vprintf+0x6c>
      if (c0 == '%')
 80c:	fd5796e3          	bne	a5,s5,7d8 <vprintf+0x5c>
        state = '%';
 810:	00078993          	mv	s3,a5
 814:	fd9ff06f          	j	7ec <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 818:	00ea06b3          	add	a3,s4,a4
 81c:	0016c603          	lbu	a2,1(a3)
      if (c1)
 820:	2a060663          	beqz	a2,acc <vprintf+0x350>
      if (c0 == 'd')
 824:	05878063          	beq	a5,s8,864 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 828:	f9478693          	addi	a3,a5,-108
 82c:	0016b693          	seqz	a3,a3
 830:	f9c60593          	addi	a1,a2,-100
 834:	04059a63          	bnez	a1,888 <vprintf+0x10c>
 838:	04068863          	beqz	a3,888 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 83c:	008b8493          	addi	s1,s7,8
 840:	00100693          	li	a3,1
 844:	00a00613          	li	a2,10
 848:	000bb583          	ld	a1,0(s7)
 84c:	000b0513          	mv	a0,s6
 850:	e4dff0ef          	jal	69c <printint>
        i += 1;
 854:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 858:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 85c:	00000993          	li	s3,0
 860:	f8dff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 864:	008b8493          	addi	s1,s7,8
 868:	00100693          	li	a3,1
 86c:	00a00613          	li	a2,10
 870:	000ba583          	lw	a1,0(s7)
 874:	000b0513          	mv	a0,s6
 878:	e25ff0ef          	jal	69c <printint>
 87c:	00048b93          	mv	s7,s1
      state = 0;
 880:	00000993          	li	s3,0
 884:	f69ff06f          	j	7ec <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 888:	00ea0733          	add	a4,s4,a4
 88c:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 890:	f9460713          	addi	a4,a2,-108
 894:	00173713          	seqz	a4,a4
 898:	00e6f733          	and	a4,a3,a4
 89c:	f9c58513          	addi	a0,a1,-100
 8a0:	24051263          	bnez	a0,ae4 <vprintf+0x368>
 8a4:	24070063          	beqz	a4,ae4 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 8a8:	008b8493          	addi	s1,s7,8
 8ac:	00100693          	li	a3,1
 8b0:	00a00613          	li	a2,10
 8b4:	000bb583          	ld	a1,0(s7)
 8b8:	000b0513          	mv	a0,s6
 8bc:	de1ff0ef          	jal	69c <printint>
        i += 2;
 8c0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 8c4:	00048b93          	mv	s7,s1
      state = 0;
 8c8:	00000993          	li	s3,0
        i += 2;
 8cc:	f21ff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 8d0:	008b8493          	addi	s1,s7,8
 8d4:	00000693          	li	a3,0
 8d8:	00a00613          	li	a2,10
 8dc:	000be583          	lwu	a1,0(s7)
 8e0:	000b0513          	mv	a0,s6
 8e4:	db9ff0ef          	jal	69c <printint>
 8e8:	00048b93          	mv	s7,s1
      state = 0;
 8ec:	00000993          	li	s3,0
 8f0:	efdff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 8f4:	008b8493          	addi	s1,s7,8
 8f8:	00000693          	li	a3,0
 8fc:	00a00613          	li	a2,10
 900:	000bb583          	ld	a1,0(s7)
 904:	000b0513          	mv	a0,s6
 908:	d95ff0ef          	jal	69c <printint>
        i += 1;
 90c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 910:	00048b93          	mv	s7,s1
      state = 0;
 914:	00000993          	li	s3,0
 918:	ed5ff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 91c:	008b8493          	addi	s1,s7,8
 920:	00000693          	li	a3,0
 924:	00a00613          	li	a2,10
 928:	000bb583          	ld	a1,0(s7)
 92c:	000b0513          	mv	a0,s6
 930:	d6dff0ef          	jal	69c <printint>
        i += 2;
 934:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 938:	00048b93          	mv	s7,s1
      state = 0;
 93c:	00000993          	li	s3,0
        i += 2;
 940:	eadff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 944:	008b8493          	addi	s1,s7,8
 948:	00000693          	li	a3,0
 94c:	01000613          	li	a2,16
 950:	000be583          	lwu	a1,0(s7)
 954:	000b0513          	mv	a0,s6
 958:	d45ff0ef          	jal	69c <printint>
 95c:	00048b93          	mv	s7,s1
      state = 0;
 960:	00000993          	li	s3,0
 964:	e89ff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 968:	008b8493          	addi	s1,s7,8
 96c:	00000693          	li	a3,0
 970:	01000613          	li	a2,16
 974:	000bb583          	ld	a1,0(s7)
 978:	000b0513          	mv	a0,s6
 97c:	d21ff0ef          	jal	69c <printint>
        i += 1;
 980:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 984:	00048b93          	mv	s7,s1
      state = 0;
 988:	00000993          	li	s3,0
 98c:	e61ff06f          	j	7ec <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 990:	008b8493          	addi	s1,s7,8
 994:	00000693          	li	a3,0
 998:	01000613          	li	a2,16
 99c:	000bb583          	ld	a1,0(s7)
 9a0:	000b0513          	mv	a0,s6
 9a4:	cf9ff0ef          	jal	69c <printint>
        i += 2;
 9a8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 9ac:	00048b93          	mv	s7,s1
      state = 0;
 9b0:	00000993          	li	s3,0
        i += 2;
 9b4:	e39ff06f          	j	7ec <vprintf+0x70>
 9b8:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 9bc:	008b8793          	addi	a5,s7,8
 9c0:	00078c93          	mv	s9,a5
 9c4:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 9c8:	03000593          	li	a1,48
 9cc:	000b0513          	mv	a0,s6
 9d0:	c3dff0ef          	jal	60c <putc>
  putc(fd, 'x');
 9d4:	07800593          	li	a1,120
 9d8:	000b0513          	mv	a0,s6
 9dc:	c31ff0ef          	jal	60c <putc>
 9e0:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 9e4:	00000b97          	auipc	s7,0x0
 9e8:	474b8b93          	addi	s7,s7,1140 # e58 <digits>
 9ec:	03c9d793          	srli	a5,s3,0x3c
 9f0:	00fb87b3          	add	a5,s7,a5
 9f4:	0007c583          	lbu	a1,0(a5)
 9f8:	000b0513          	mv	a0,s6
 9fc:	c11ff0ef          	jal	60c <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a00:	00499993          	slli	s3,s3,0x4
 a04:	fff4849b          	addiw	s1,s1,-1
 a08:	fe0492e3          	bnez	s1,9ec <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a0c:	000c8b93          	mv	s7,s9
      state = 0;
 a10:	00000993          	li	s3,0
 a14:	00813c83          	ld	s9,8(sp)
 a18:	dd5ff06f          	j	7ec <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a1c:	008b8493          	addi	s1,s7,8
 a20:	000bc583          	lbu	a1,0(s7)
 a24:	000b0513          	mv	a0,s6
 a28:	be5ff0ef          	jal	60c <putc>
 a2c:	00048b93          	mv	s7,s1
      state = 0;
 a30:	00000993          	li	s3,0
 a34:	db9ff06f          	j	7ec <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a38:	008b8993          	addi	s3,s7,8
 a3c:	000bb483          	ld	s1,0(s7)
 a40:	02048663          	beqz	s1,a6c <vprintf+0x2f0>
        for (; *s; s++)
 a44:	0004c583          	lbu	a1,0(s1)
 a48:	04058463          	beqz	a1,a90 <vprintf+0x314>
          putc(fd, *s);
 a4c:	000b0513          	mv	a0,s6
 a50:	bbdff0ef          	jal	60c <putc>
        for (; *s; s++)
 a54:	00148493          	addi	s1,s1,1
 a58:	0004c583          	lbu	a1,0(s1)
 a5c:	fe0598e3          	bnez	a1,a4c <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 a60:	00098b93          	mv	s7,s3
      state = 0;
 a64:	00000993          	li	s3,0
 a68:	d85ff06f          	j	7ec <vprintf+0x70>
          s = "(null)";
 a6c:	00000497          	auipc	s1,0x0
 a70:	3e448493          	addi	s1,s1,996 # e50 <malloc+0x19c>
        for (; *s; s++)
 a74:	02800593          	li	a1,40
 a78:	fd5ff06f          	j	a4c <vprintf+0x2d0>
        putc(fd, '%');
 a7c:	00078593          	mv	a1,a5
 a80:	000b0513          	mv	a0,s6
 a84:	b89ff0ef          	jal	60c <putc>
      state = 0;
 a88:	00000993          	li	s3,0
 a8c:	d61ff06f          	j	7ec <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a90:	00098b93          	mv	s7,s3
      state = 0;
 a94:	00000993          	li	s3,0
 a98:	d55ff06f          	j	7ec <vprintf+0x70>
 a9c:	04013903          	ld	s2,64(sp)
 aa0:	03813983          	ld	s3,56(sp)
 aa4:	03013a03          	ld	s4,48(sp)
 aa8:	02813a83          	ld	s5,40(sp)
 aac:	02013b03          	ld	s6,32(sp)
 ab0:	01813b83          	ld	s7,24(sp)
 ab4:	01013c03          	ld	s8,16(sp)
    }
  }
}
 ab8:	05813083          	ld	ra,88(sp)
 abc:	05013403          	ld	s0,80(sp)
 ac0:	04813483          	ld	s1,72(sp)
 ac4:	06010113          	addi	sp,sp,96
 ac8:	00008067          	ret
      if (c0 == 'd')
 acc:	06400713          	li	a4,100
 ad0:	d8e78ae3          	beq	a5,a4,864 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 ad4:	f9478693          	addi	a3,a5,-108
 ad8:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 adc:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 ae0:	00000713          	li	a4,0
      else if (c0 == 'u')
 ae4:	07500513          	li	a0,117
 ae8:	dea784e3          	beq	a5,a0,8d0 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 aec:	f8b60513          	addi	a0,a2,-117
 af0:	00051463          	bnez	a0,af8 <vprintf+0x37c>
 af4:	e00690e3          	bnez	a3,8f4 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 af8:	f8b58513          	addi	a0,a1,-117
 afc:	00051463          	bnez	a0,b04 <vprintf+0x388>
 b00:	e0071ee3          	bnez	a4,91c <vprintf+0x1a0>
      else if (c0 == 'x')
 b04:	07800513          	li	a0,120
 b08:	e2a78ee3          	beq	a5,a0,944 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b0c:	f8860613          	addi	a2,a2,-120
 b10:	00061463          	bnez	a2,b18 <vprintf+0x39c>
 b14:	e4069ae3          	bnez	a3,968 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b18:	f8858593          	addi	a1,a1,-120
 b1c:	00059463          	bnez	a1,b24 <vprintf+0x3a8>
 b20:	e60718e3          	bnez	a4,990 <vprintf+0x214>
      else if (c0 == 'p')
 b24:	07000713          	li	a4,112
 b28:	e8e788e3          	beq	a5,a4,9b8 <vprintf+0x23c>
      else if (c0 == 'c')
 b2c:	06300713          	li	a4,99
 b30:	eee786e3          	beq	a5,a4,a1c <vprintf+0x2a0>
      else if (c0 == 's')
 b34:	07300713          	li	a4,115
 b38:	f0e780e3          	beq	a5,a4,a38 <vprintf+0x2bc>
      else if (c0 == '%')
 b3c:	02500713          	li	a4,37
 b40:	f2e78ee3          	beq	a5,a4,a7c <vprintf+0x300>
        putc(fd, '%');
 b44:	02500593          	li	a1,37
 b48:	000b0513          	mv	a0,s6
 b4c:	ac1ff0ef          	jal	60c <putc>
        putc(fd, c0);
 b50:	00048593          	mv	a1,s1
 b54:	000b0513          	mv	a0,s6
 b58:	ab5ff0ef          	jal	60c <putc>
      state = 0;
 b5c:	00000993          	li	s3,0
 b60:	c8dff06f          	j	7ec <vprintf+0x70>

0000000000000b64 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 b64:	fb010113          	addi	sp,sp,-80
 b68:	00113c23          	sd	ra,24(sp)
 b6c:	00813823          	sd	s0,16(sp)
 b70:	02010413          	addi	s0,sp,32
 b74:	00c43023          	sd	a2,0(s0)
 b78:	00d43423          	sd	a3,8(s0)
 b7c:	00e43823          	sd	a4,16(s0)
 b80:	00f43c23          	sd	a5,24(s0)
 b84:	03043023          	sd	a6,32(s0)
 b88:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 b8c:	00040613          	mv	a2,s0
 b90:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 b94:	be9ff0ef          	jal	77c <vprintf>
}
 b98:	01813083          	ld	ra,24(sp)
 b9c:	01013403          	ld	s0,16(sp)
 ba0:	05010113          	addi	sp,sp,80
 ba4:	00008067          	ret

0000000000000ba8 <printf>:

void printf(const char *fmt, ...)
{
 ba8:	fa010113          	addi	sp,sp,-96
 bac:	00113c23          	sd	ra,24(sp)
 bb0:	00813823          	sd	s0,16(sp)
 bb4:	02010413          	addi	s0,sp,32
 bb8:	00b43423          	sd	a1,8(s0)
 bbc:	00c43823          	sd	a2,16(s0)
 bc0:	00d43c23          	sd	a3,24(s0)
 bc4:	02e43023          	sd	a4,32(s0)
 bc8:	02f43423          	sd	a5,40(s0)
 bcc:	03043823          	sd	a6,48(s0)
 bd0:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 bd4:	00840613          	addi	a2,s0,8
 bd8:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 bdc:	00050593          	mv	a1,a0
 be0:	00100513          	li	a0,1
 be4:	b99ff0ef          	jal	77c <vprintf>
  putc_flush();
 be8:	9d9ff0ef          	jal	5c0 <putc_flush>
}
 bec:	01813083          	ld	ra,24(sp)
 bf0:	01013403          	ld	s0,16(sp)
 bf4:	06010113          	addi	sp,sp,96
 bf8:	00008067          	ret

0000000000000bfc <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 bfc:	ff010113          	addi	sp,sp,-16
 c00:	00113423          	sd	ra,8(sp)
 c04:	00813023          	sd	s0,0(sp)
 c08:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c0c:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c10:	00000797          	auipc	a5,0x0
 c14:	4087b783          	ld	a5,1032(a5) # 1018 <freep>
 c18:	0140006f          	j	c2c <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c1c:	0007b703          	ld	a4,0(a5)
 c20:	00e7e463          	bltu	a5,a4,c28 <free+0x2c>
 c24:	00e6ec63          	bltu	a3,a4,c3c <free+0x40>
{
 c28:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c2c:	fed7f8e3          	bgeu	a5,a3,c1c <free+0x20>
 c30:	0007b703          	ld	a4,0(a5)
 c34:	00e6e463          	bltu	a3,a4,c3c <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c38:	fee7e8e3          	bltu	a5,a4,c28 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 c3c:	ff852583          	lw	a1,-8(a0)
 c40:	0007b603          	ld	a2,0(a5)
 c44:	02059813          	slli	a6,a1,0x20
 c48:	01c85713          	srli	a4,a6,0x1c
 c4c:	00e68733          	add	a4,a3,a4
 c50:	02e60c63          	beq	a2,a4,c88 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c54:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c58:	0087a603          	lw	a2,8(a5)
 c5c:	02061593          	slli	a1,a2,0x20
 c60:	01c5d713          	srli	a4,a1,0x1c
 c64:	00e78733          	add	a4,a5,a4
 c68:	02e68c63          	beq	a3,a4,ca0 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 c6c:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 c70:	00000717          	auipc	a4,0x0
 c74:	3af73423          	sd	a5,936(a4) # 1018 <freep>
}
 c78:	00813083          	ld	ra,8(sp)
 c7c:	00013403          	ld	s0,0(sp)
 c80:	01010113          	addi	sp,sp,16
 c84:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 c88:	00862703          	lw	a4,8(a2)
 c8c:	00b7073b          	addw	a4,a4,a1
 c90:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 c94:	0007b703          	ld	a4,0(a5)
 c98:	00073603          	ld	a2,0(a4)
 c9c:	fb9ff06f          	j	c54 <free+0x58>
    p->s.size += bp->s.size;
 ca0:	ff852703          	lw	a4,-8(a0)
 ca4:	00c7073b          	addw	a4,a4,a2
 ca8:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 cac:	ff053683          	ld	a3,-16(a0)
 cb0:	fbdff06f          	j	c6c <free+0x70>

0000000000000cb4 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 cb4:	fc010113          	addi	sp,sp,-64
 cb8:	02113c23          	sd	ra,56(sp)
 cbc:	02813823          	sd	s0,48(sp)
 cc0:	03213023          	sd	s2,32(sp)
 cc4:	01313c23          	sd	s3,24(sp)
 cc8:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 ccc:	02051993          	slli	s3,a0,0x20
 cd0:	0209d993          	srli	s3,s3,0x20
 cd4:	00f98993          	addi	s3,s3,15
 cd8:	0049d993          	srli	s3,s3,0x4
 cdc:	0019899b          	addiw	s3,s3,1
 ce0:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 ce4:	00000517          	auipc	a0,0x0
 ce8:	33453503          	ld	a0,820(a0) # 1018 <freep>
 cec:	04050463          	beqz	a0,d34 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 cf0:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 cf4:	0087a703          	lw	a4,8(a5)
 cf8:	0d377a63          	bgeu	a4,s3,dcc <malloc+0x118>
 cfc:	02913423          	sd	s1,40(sp)
 d00:	01413823          	sd	s4,16(sp)
 d04:	01513423          	sd	s5,8(sp)
 d08:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d0c:	00098a13          	mv	s4,s3
 d10:	00001737          	lui	a4,0x1
 d14:	00e9f463          	bgeu	s3,a4,d1c <malloc+0x68>
 d18:	00001a37          	lui	s4,0x1
 d1c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d20:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d24:	00000497          	auipc	s1,0x0
 d28:	2f448493          	addi	s1,s1,756 # 1018 <freep>
  if(p == SBRK_ERROR)
 d2c:	fff00a93          	li	s5,-1
 d30:	05c0006f          	j	d8c <malloc+0xd8>
 d34:	02913423          	sd	s1,40(sp)
 d38:	01413823          	sd	s4,16(sp)
 d3c:	01513423          	sd	s5,8(sp)
 d40:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d44:	00000797          	auipc	a5,0x0
 d48:	35c78793          	addi	a5,a5,860 # 10a0 <base>
 d4c:	00000717          	auipc	a4,0x0
 d50:	2cf73623          	sd	a5,716(a4) # 1018 <freep>
 d54:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d58:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d5c:	fb1ff06f          	j	d0c <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 d60:	0007b703          	ld	a4,0(a5)
 d64:	00e53023          	sd	a4,0(a0)
 d68:	0800006f          	j	de8 <malloc+0x134>
  hp->s.size = nu;
 d6c:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 d70:	01050513          	addi	a0,a0,16
 d74:	e89ff0ef          	jal	bfc <free>
  return freep;
 d78:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 d7c:	08050863          	beqz	a0,e0c <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d80:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d84:	0087a703          	lw	a4,8(a5)
 d88:	03277a63          	bgeu	a4,s2,dbc <malloc+0x108>
    if(p == freep)
 d8c:	0004b703          	ld	a4,0(s1)
 d90:	00078513          	mv	a0,a5
 d94:	fef716e3          	bne	a4,a5,d80 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 d98:	000a0513          	mv	a0,s4
 d9c:	ed8ff0ef          	jal	474 <sbrk>
  if(p == SBRK_ERROR)
 da0:	fd5516e3          	bne	a0,s5,d6c <malloc+0xb8>
        return 0;
 da4:	00000513          	li	a0,0
 da8:	02813483          	ld	s1,40(sp)
 dac:	01013a03          	ld	s4,16(sp)
 db0:	00813a83          	ld	s5,8(sp)
 db4:	00013b03          	ld	s6,0(sp)
 db8:	03c0006f          	j	df4 <malloc+0x140>
 dbc:	02813483          	ld	s1,40(sp)
 dc0:	01013a03          	ld	s4,16(sp)
 dc4:	00813a83          	ld	s5,8(sp)
 dc8:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 dcc:	f8e90ae3          	beq	s2,a4,d60 <malloc+0xac>
        p->s.size -= nunits;
 dd0:	4137073b          	subw	a4,a4,s3
 dd4:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 dd8:	02071693          	slli	a3,a4,0x20
 ddc:	01c6d713          	srli	a4,a3,0x1c
 de0:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 de4:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 de8:	00000717          	auipc	a4,0x0
 dec:	22a73823          	sd	a0,560(a4) # 1018 <freep>
      return (void*)(p + 1);
 df0:	01078513          	addi	a0,a5,16
  }
}
 df4:	03813083          	ld	ra,56(sp)
 df8:	03013403          	ld	s0,48(sp)
 dfc:	02013903          	ld	s2,32(sp)
 e00:	01813983          	ld	s3,24(sp)
 e04:	04010113          	addi	sp,sp,64
 e08:	00008067          	ret
 e0c:	02813483          	ld	s1,40(sp)
 e10:	01013a03          	ld	s4,16(sp)
 e14:	00813a83          	ld	s5,8(sp)
 e18:	00013b03          	ld	s6,0(sp)
 e1c:	fd9ff06f          	j	df4 <malloc+0x140>
