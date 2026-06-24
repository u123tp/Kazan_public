
user/_mkdir:     file format elf64-littleriscv


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
    fprintf(2, "Usage: mkdir files...\n");
    exit(1);
  }

  for(i = 1; i < argc; i++){
    if(mkdir(argv[i]) < 0){
  38:	0004b503          	ld	a0,0(s1)
  3c:	54c000ef          	jal	588 <mkdir>
  40:	02054a63          	bltz	a0,74 <main+0x74>
  for(i = 1; i < argc; i++){
  44:	00848493          	addi	s1,s1,8
  48:	ff2498e3          	bne	s1,s2,38 <main+0x38>
      fprintf(2, "mkdir: %s failed to create\n", argv[i]);
      break;
    }
  }

  exit(0);
  4c:	00000513          	li	a0,0
  50:	49c000ef          	jal	4ec <exit>
  54:	00913423          	sd	s1,8(sp)
  58:	01213023          	sd	s2,0(sp)
    fprintf(2, "Usage: mkdir files...\n");
  5c:	00001597          	auipc	a1,0x1
  60:	de458593          	addi	a1,a1,-540 # e40 <malloc+0x170>
  64:	00200513          	li	a0,2
  68:	319000ef          	jal	b80 <fprintf>
    exit(1);
  6c:	00100513          	li	a0,1
  70:	47c000ef          	jal	4ec <exit>
      fprintf(2, "mkdir: %s failed to create\n", argv[i]);
  74:	0004b603          	ld	a2,0(s1)
  78:	00001597          	auipc	a1,0x1
  7c:	de058593          	addi	a1,a1,-544 # e58 <malloc+0x188>
  80:	00200513          	li	a0,2
  84:	2fd000ef          	jal	b80 <fprintf>
      break;
  88:	fc5ff06f          	j	4c <main+0x4c>

000000000000008c <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
  8c:	ff010113          	addi	sp,sp,-16
  90:	00113423          	sd	ra,8(sp)
  94:	00813023          	sd	s0,0(sp)
  98:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
  9c:	f65ff0ef          	jal	0 <main>
  exit(r);
  a0:	44c000ef          	jal	4ec <exit>

00000000000000a4 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
  a4:	ff010113          	addi	sp,sp,-16
  a8:	00113423          	sd	ra,8(sp)
  ac:	00813023          	sd	s0,0(sp)
  b0:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
  b4:	00050793          	mv	a5,a0
  b8:	00158593          	addi	a1,a1,1
  bc:	00178793          	addi	a5,a5,1
  c0:	fff5c703          	lbu	a4,-1(a1)
  c4:	fee78fa3          	sb	a4,-1(a5)
  c8:	fe0718e3          	bnez	a4,b8 <strcpy+0x14>
    ;
  return os;
}
  cc:	00813083          	ld	ra,8(sp)
  d0:	00013403          	ld	s0,0(sp)
  d4:	01010113          	addi	sp,sp,16
  d8:	00008067          	ret

00000000000000dc <strcmp>:

int
strcmp(const char *p, const char *q)
{
  dc:	ff010113          	addi	sp,sp,-16
  e0:	00113423          	sd	ra,8(sp)
  e4:	00813023          	sd	s0,0(sp)
  e8:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
  ec:	00054783          	lbu	a5,0(a0)
  f0:	00078e63          	beqz	a5,10c <strcmp+0x30>
  f4:	0005c703          	lbu	a4,0(a1)
  f8:	00f71a63          	bne	a4,a5,10c <strcmp+0x30>
    p++, q++;
  fc:	00150513          	addi	a0,a0,1
 100:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 104:	00054783          	lbu	a5,0(a0)
 108:	fe0796e3          	bnez	a5,f4 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 10c:	0005c503          	lbu	a0,0(a1)
}
 110:	40a7853b          	subw	a0,a5,a0
 114:	00813083          	ld	ra,8(sp)
 118:	00013403          	ld	s0,0(sp)
 11c:	01010113          	addi	sp,sp,16
 120:	00008067          	ret

0000000000000124 <strlen>:

uint
strlen(const char *s)
{
 124:	ff010113          	addi	sp,sp,-16
 128:	00113423          	sd	ra,8(sp)
 12c:	00813023          	sd	s0,0(sp)
 130:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 134:	00054783          	lbu	a5,0(a0)
 138:	02078663          	beqz	a5,164 <strlen+0x40>
 13c:	00150793          	addi	a5,a0,1
 140:	00078693          	mv	a3,a5
 144:	00178793          	addi	a5,a5,1
 148:	fff7c703          	lbu	a4,-1(a5)
 14c:	fe071ae3          	bnez	a4,140 <strlen+0x1c>
 150:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 154:	00813083          	ld	ra,8(sp)
 158:	00013403          	ld	s0,0(sp)
 15c:	01010113          	addi	sp,sp,16
 160:	00008067          	ret
  for(n = 0; s[n]; n++)
 164:	00000513          	li	a0,0
 168:	fedff06f          	j	154 <strlen+0x30>

000000000000016c <memset>:

void*
memset(void *dst, int c, uint n)
{
 16c:	ff010113          	addi	sp,sp,-16
 170:	00113423          	sd	ra,8(sp)
 174:	00813023          	sd	s0,0(sp)
 178:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 17c:	02060063          	beqz	a2,19c <memset+0x30>
 180:	00050793          	mv	a5,a0
 184:	02061613          	slli	a2,a2,0x20
 188:	02065613          	srli	a2,a2,0x20
 18c:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 190:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 194:	00178793          	addi	a5,a5,1
 198:	fee79ce3          	bne	a5,a4,190 <memset+0x24>
  }
  return dst;
}
 19c:	00813083          	ld	ra,8(sp)
 1a0:	00013403          	ld	s0,0(sp)
 1a4:	01010113          	addi	sp,sp,16
 1a8:	00008067          	ret

00000000000001ac <strchr>:

char*
strchr(const char *s, char c)
{
 1ac:	ff010113          	addi	sp,sp,-16
 1b0:	00113423          	sd	ra,8(sp)
 1b4:	00813023          	sd	s0,0(sp)
 1b8:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 1bc:	00054783          	lbu	a5,0(a0)
 1c0:	02078463          	beqz	a5,1e8 <strchr+0x3c>
    if(*s == c)
 1c4:	00f58a63          	beq	a1,a5,1d8 <strchr+0x2c>
  for(; *s; s++)
 1c8:	00150513          	addi	a0,a0,1
 1cc:	00054783          	lbu	a5,0(a0)
 1d0:	fe079ae3          	bnez	a5,1c4 <strchr+0x18>
      return (char*)s;
  return 0;
 1d4:	00000513          	li	a0,0
}
 1d8:	00813083          	ld	ra,8(sp)
 1dc:	00013403          	ld	s0,0(sp)
 1e0:	01010113          	addi	sp,sp,16
 1e4:	00008067          	ret
  return 0;
 1e8:	00000513          	li	a0,0
 1ec:	fedff06f          	j	1d8 <strchr+0x2c>

00000000000001f0 <gets>:

char*
gets(char *buf, int max)
{
 1f0:	fa010113          	addi	sp,sp,-96
 1f4:	04113c23          	sd	ra,88(sp)
 1f8:	04813823          	sd	s0,80(sp)
 1fc:	04913423          	sd	s1,72(sp)
 200:	05213023          	sd	s2,64(sp)
 204:	03313c23          	sd	s3,56(sp)
 208:	03413823          	sd	s4,48(sp)
 20c:	03513423          	sd	s5,40(sp)
 210:	03613023          	sd	s6,32(sp)
 214:	01713c23          	sd	s7,24(sp)
 218:	01813823          	sd	s8,16(sp)
 21c:	06010413          	addi	s0,sp,96
 220:	00050b93          	mv	s7,a0
 224:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 228:	00050913          	mv	s2,a0
 22c:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 230:	faf40b13          	addi	s6,s0,-81
 234:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 238:	00048c13          	mv	s8,s1
 23c:	0014899b          	addiw	s3,s1,1
 240:	00098493          	mv	s1,s3
 244:	0349dc63          	bge	s3,s4,27c <gets+0x8c>
    cc = read(0, &c, 1);
 248:	000a8613          	mv	a2,s5
 24c:	000b0593          	mv	a1,s6
 250:	00000513          	li	a0,0
 254:	2bc000ef          	jal	510 <read>
    if(cc < 1)
 258:	02a05263          	blez	a0,27c <gets+0x8c>
      break;
    buf[i++] = c;
 25c:	faf44783          	lbu	a5,-81(s0)
 260:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 264:	00190913          	addi	s2,s2,1
 268:	ff678713          	addi	a4,a5,-10
 26c:	00070663          	beqz	a4,278 <gets+0x88>
 270:	ff378793          	addi	a5,a5,-13
 274:	fc0792e3          	bnez	a5,238 <gets+0x48>
    buf[i++] = c;
 278:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 27c:	018b8c33          	add	s8,s7,s8
 280:	000c0023          	sb	zero,0(s8)
  return buf;
}
 284:	000b8513          	mv	a0,s7
 288:	05813083          	ld	ra,88(sp)
 28c:	05013403          	ld	s0,80(sp)
 290:	04813483          	ld	s1,72(sp)
 294:	04013903          	ld	s2,64(sp)
 298:	03813983          	ld	s3,56(sp)
 29c:	03013a03          	ld	s4,48(sp)
 2a0:	02813a83          	ld	s5,40(sp)
 2a4:	02013b03          	ld	s6,32(sp)
 2a8:	01813b83          	ld	s7,24(sp)
 2ac:	01013c03          	ld	s8,16(sp)
 2b0:	06010113          	addi	sp,sp,96
 2b4:	00008067          	ret

00000000000002b8 <stat>:

int
stat(const char *n, struct stat *st)
{
 2b8:	fe010113          	addi	sp,sp,-32
 2bc:	00113c23          	sd	ra,24(sp)
 2c0:	00813823          	sd	s0,16(sp)
 2c4:	01213023          	sd	s2,0(sp)
 2c8:	02010413          	addi	s0,sp,32
 2cc:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 2d0:	00000593          	li	a1,0
 2d4:	278000ef          	jal	54c <open>
  if(fd < 0)
 2d8:	02054e63          	bltz	a0,314 <stat+0x5c>
 2dc:	00913423          	sd	s1,8(sp)
 2e0:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 2e4:	00090593          	mv	a1,s2
 2e8:	288000ef          	jal	570 <fstat>
 2ec:	00050913          	mv	s2,a0
  close(fd);
 2f0:	00048513          	mv	a0,s1
 2f4:	234000ef          	jal	528 <close>
  return r;
 2f8:	00813483          	ld	s1,8(sp)
}
 2fc:	00090513          	mv	a0,s2
 300:	01813083          	ld	ra,24(sp)
 304:	01013403          	ld	s0,16(sp)
 308:	00013903          	ld	s2,0(sp)
 30c:	02010113          	addi	sp,sp,32
 310:	00008067          	ret
    return -1;
 314:	fff00793          	li	a5,-1
 318:	00078913          	mv	s2,a5
 31c:	fe1ff06f          	j	2fc <stat+0x44>

0000000000000320 <atoi>:

int
atoi(const char *s)
{
 320:	ff010113          	addi	sp,sp,-16
 324:	00113423          	sd	ra,8(sp)
 328:	00813023          	sd	s0,0(sp)
 32c:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 330:	00054683          	lbu	a3,0(a0)
 334:	fd06879b          	addiw	a5,a3,-48
 338:	0ff7f793          	zext.b	a5,a5
 33c:	00900613          	li	a2,9
 340:	04f66263          	bltu	a2,a5,384 <atoi+0x64>
 344:	00050713          	mv	a4,a0
  n = 0;
 348:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 34c:	00170713          	addi	a4,a4,1
 350:	0025179b          	slliw	a5,a0,0x2
 354:	00a787bb          	addw	a5,a5,a0
 358:	0017979b          	slliw	a5,a5,0x1
 35c:	00d787bb          	addw	a5,a5,a3
 360:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 364:	00074683          	lbu	a3,0(a4)
 368:	fd06879b          	addiw	a5,a3,-48
 36c:	0ff7f793          	zext.b	a5,a5
 370:	fcf67ee3          	bgeu	a2,a5,34c <atoi+0x2c>
  return n;
}
 374:	00813083          	ld	ra,8(sp)
 378:	00013403          	ld	s0,0(sp)
 37c:	01010113          	addi	sp,sp,16
 380:	00008067          	ret
  n = 0;
 384:	00000513          	li	a0,0
 388:	fedff06f          	j	374 <atoi+0x54>

000000000000038c <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 38c:	ff010113          	addi	sp,sp,-16
 390:	00113423          	sd	ra,8(sp)
 394:	00813023          	sd	s0,0(sp)
 398:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 39c:	02b57e63          	bgeu	a0,a1,3d8 <memmove+0x4c>
    while(n-- > 0)
 3a0:	02c05463          	blez	a2,3c8 <memmove+0x3c>
 3a4:	02061613          	slli	a2,a2,0x20
 3a8:	02065613          	srli	a2,a2,0x20
 3ac:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 3b0:	00050713          	mv	a4,a0
      *dst++ = *src++;
 3b4:	00158593          	addi	a1,a1,1
 3b8:	00170713          	addi	a4,a4,1
 3bc:	fff5c683          	lbu	a3,-1(a1)
 3c0:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 3c4:	fee798e3          	bne	a5,a4,3b4 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 3c8:	00813083          	ld	ra,8(sp)
 3cc:	00013403          	ld	s0,0(sp)
 3d0:	01010113          	addi	sp,sp,16
 3d4:	00008067          	ret
    while(n-- > 0)
 3d8:	fec058e3          	blez	a2,3c8 <memmove+0x3c>
    dst += n;
 3dc:	00c50733          	add	a4,a0,a2
    src += n;
 3e0:	00c585b3          	add	a1,a1,a2
 3e4:	fff6079b          	addiw	a5,a2,-1
 3e8:	02079793          	slli	a5,a5,0x20
 3ec:	0207d793          	srli	a5,a5,0x20
 3f0:	fff7c793          	not	a5,a5
 3f4:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 3f8:	fff58593          	addi	a1,a1,-1
 3fc:	fff70713          	addi	a4,a4,-1
 400:	0005c683          	lbu	a3,0(a1)
 404:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 408:	fef718e3          	bne	a4,a5,3f8 <memmove+0x6c>
 40c:	fbdff06f          	j	3c8 <memmove+0x3c>

0000000000000410 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 410:	ff010113          	addi	sp,sp,-16
 414:	00113423          	sd	ra,8(sp)
 418:	00813023          	sd	s0,0(sp)
 41c:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 420:	04060263          	beqz	a2,464 <memcmp+0x54>
 424:	02061613          	slli	a2,a2,0x20
 428:	02065613          	srli	a2,a2,0x20
 42c:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 430:	00054783          	lbu	a5,0(a0)
 434:	0005c703          	lbu	a4,0(a1)
 438:	00e79c63          	bne	a5,a4,450 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 43c:	00150513          	addi	a0,a0,1
    p2++;
 440:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 444:	fed516e3          	bne	a0,a3,430 <memcmp+0x20>
  }
  return 0;
 448:	00000513          	li	a0,0
 44c:	0080006f          	j	454 <memcmp+0x44>
      return *p1 - *p2;
 450:	40e7853b          	subw	a0,a5,a4
}
 454:	00813083          	ld	ra,8(sp)
 458:	00013403          	ld	s0,0(sp)
 45c:	01010113          	addi	sp,sp,16
 460:	00008067          	ret
  return 0;
 464:	00000513          	li	a0,0
 468:	fedff06f          	j	454 <memcmp+0x44>

000000000000046c <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 46c:	ff010113          	addi	sp,sp,-16
 470:	00113423          	sd	ra,8(sp)
 474:	00813023          	sd	s0,0(sp)
 478:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 47c:	f11ff0ef          	jal	38c <memmove>
}
 480:	00813083          	ld	ra,8(sp)
 484:	00013403          	ld	s0,0(sp)
 488:	01010113          	addi	sp,sp,16
 48c:	00008067          	ret

0000000000000490 <sbrk>:

char *
sbrk(int n) {
 490:	ff010113          	addi	sp,sp,-16
 494:	00113423          	sd	ra,8(sp)
 498:	00813023          	sd	s0,0(sp)
 49c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 4a0:	00100593          	li	a1,1
 4a4:	114000ef          	jal	5b8 <sys_sbrk>
}
 4a8:	00813083          	ld	ra,8(sp)
 4ac:	00013403          	ld	s0,0(sp)
 4b0:	01010113          	addi	sp,sp,16
 4b4:	00008067          	ret

00000000000004b8 <sbrklazy>:

char *
sbrklazy(int n) {
 4b8:	ff010113          	addi	sp,sp,-16
 4bc:	00113423          	sd	ra,8(sp)
 4c0:	00813023          	sd	s0,0(sp)
 4c4:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 4c8:	00200593          	li	a1,2
 4cc:	0ec000ef          	jal	5b8 <sys_sbrk>
}
 4d0:	00813083          	ld	ra,8(sp)
 4d4:	00013403          	ld	s0,0(sp)
 4d8:	01010113          	addi	sp,sp,16
 4dc:	00008067          	ret

00000000000004e0 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 4e0:	00100893          	li	a7,1
 ecall
 4e4:	00000073          	ecall
 ret
 4e8:	00008067          	ret

00000000000004ec <exit>:
.global exit
exit:
 li a7, SYS_exit
 4ec:	00200893          	li	a7,2
 ecall
 4f0:	00000073          	ecall
 ret
 4f4:	00008067          	ret

00000000000004f8 <wait>:
.global wait
wait:
 li a7, SYS_wait
 4f8:	00300893          	li	a7,3
 ecall
 4fc:	00000073          	ecall
 ret
 500:	00008067          	ret

0000000000000504 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 504:	00400893          	li	a7,4
 ecall
 508:	00000073          	ecall
 ret
 50c:	00008067          	ret

0000000000000510 <read>:
.global read
read:
 li a7, SYS_read
 510:	00500893          	li	a7,5
 ecall
 514:	00000073          	ecall
 ret
 518:	00008067          	ret

000000000000051c <write>:
.global write
write:
 li a7, SYS_write
 51c:	01000893          	li	a7,16
 ecall
 520:	00000073          	ecall
 ret
 524:	00008067          	ret

0000000000000528 <close>:
.global close
close:
 li a7, SYS_close
 528:	01500893          	li	a7,21
 ecall
 52c:	00000073          	ecall
 ret
 530:	00008067          	ret

0000000000000534 <kill>:
.global kill
kill:
 li a7, SYS_kill
 534:	00600893          	li	a7,6
 ecall
 538:	00000073          	ecall
 ret
 53c:	00008067          	ret

0000000000000540 <exec>:
.global exec
exec:
 li a7, SYS_exec
 540:	00700893          	li	a7,7
 ecall
 544:	00000073          	ecall
 ret
 548:	00008067          	ret

000000000000054c <open>:
.global open
open:
 li a7, SYS_open
 54c:	00f00893          	li	a7,15
 ecall
 550:	00000073          	ecall
 ret
 554:	00008067          	ret

0000000000000558 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 558:	01100893          	li	a7,17
 ecall
 55c:	00000073          	ecall
 ret
 560:	00008067          	ret

0000000000000564 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 564:	01200893          	li	a7,18
 ecall
 568:	00000073          	ecall
 ret
 56c:	00008067          	ret

0000000000000570 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 570:	00800893          	li	a7,8
 ecall
 574:	00000073          	ecall
 ret
 578:	00008067          	ret

000000000000057c <link>:
.global link
link:
 li a7, SYS_link
 57c:	01300893          	li	a7,19
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 588:	01400893          	li	a7,20
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 594:	00900893          	li	a7,9
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <dup>:
.global dup
dup:
 li a7, SYS_dup
 5a0:	00a00893          	li	a7,10
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 5ac:	00b00893          	li	a7,11
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 5b8:	00c00893          	li	a7,12
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <pause>:
.global pause
pause:
 li a7, SYS_pause
 5c4:	00d00893          	li	a7,13
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 5d0:	00e00893          	li	a7,14
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 5dc:	00001617          	auipc	a2,0x1
 5e0:	a3462603          	lw	a2,-1484(a2) # 1010 <putc_n>
 5e4:	00c04463          	bgtz	a2,5ec <putc_flush+0x10>
 5e8:	00008067          	ret
{
 5ec:	ff010113          	addi	sp,sp,-16
 5f0:	00113423          	sd	ra,8(sp)
 5f4:	00813023          	sd	s0,0(sp)
 5f8:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 5fc:	00001597          	auipc	a1,0x1
 600:	a2458593          	addi	a1,a1,-1500 # 1020 <putc_buf>
 604:	00001517          	auipc	a0,0x1
 608:	9fc52503          	lw	a0,-1540(a0) # 1000 <putc_fd>
 60c:	f11ff0ef          	jal	51c <write>
    putc_n = 0;
 610:	00001797          	auipc	a5,0x1
 614:	a007a023          	sw	zero,-1536(a5) # 1010 <putc_n>
  }
}
 618:	00813083          	ld	ra,8(sp)
 61c:	00013403          	ld	s0,0(sp)
 620:	01010113          	addi	sp,sp,16
 624:	00008067          	ret

0000000000000628 <putc>:

static void
putc(int fd, char c)
{
 628:	fe010113          	addi	sp,sp,-32
 62c:	00113c23          	sd	ra,24(sp)
 630:	00813823          	sd	s0,16(sp)
 634:	00913423          	sd	s1,8(sp)
 638:	02010413          	addi	s0,sp,32
 63c:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 640:	00001797          	auipc	a5,0x1
 644:	9c07a783          	lw	a5,-1600(a5) # 1000 <putc_fd>
 648:	04a79663          	bne	a5,a0,694 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 64c:	00001717          	auipc	a4,0x1
 650:	9c470713          	addi	a4,a4,-1596 # 1010 <putc_n>
 654:	00072683          	lw	a3,0(a4)
 658:	0016879b          	addiw	a5,a3,1
 65c:	00f72023          	sw	a5,0(a4)
 660:	00001717          	auipc	a4,0x1
 664:	9c070713          	addi	a4,a4,-1600 # 1020 <putc_buf>
 668:	00d70733          	add	a4,a4,a3
 66c:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 670:	ff648493          	addi	s1,s1,-10
 674:	02048e63          	beqz	s1,6b0 <putc+0x88>
 678:	f8078793          	addi	a5,a5,-128
 67c:	02078a63          	beqz	a5,6b0 <putc+0x88>
    putc_flush();
}
 680:	01813083          	ld	ra,24(sp)
 684:	01013403          	ld	s0,16(sp)
 688:	00813483          	ld	s1,8(sp)
 68c:	02010113          	addi	sp,sp,32
 690:	00008067          	ret
 694:	01213023          	sd	s2,0(sp)
 698:	00050913          	mv	s2,a0
    putc_flush();
 69c:	f41ff0ef          	jal	5dc <putc_flush>
    putc_fd = fd;
 6a0:	00001797          	auipc	a5,0x1
 6a4:	9727a023          	sw	s2,-1696(a5) # 1000 <putc_fd>
 6a8:	00013903          	ld	s2,0(sp)
 6ac:	fa1ff06f          	j	64c <putc+0x24>
    putc_flush();
 6b0:	f2dff0ef          	jal	5dc <putc_flush>
}
 6b4:	fcdff06f          	j	680 <putc+0x58>

00000000000006b8 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 6b8:	fb010113          	addi	sp,sp,-80
 6bc:	04113423          	sd	ra,72(sp)
 6c0:	04813023          	sd	s0,64(sp)
 6c4:	03213823          	sd	s2,48(sp)
 6c8:	03313423          	sd	s3,40(sp)
 6cc:	05010413          	addi	s0,sp,80
 6d0:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 6d4:	0a068e63          	beqz	a3,790 <printint+0xd8>
 6d8:	0a05dc63          	bgez	a1,790 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 6dc:	40b005b3          	neg	a1,a1
    neg = 1;
 6e0:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 6e4:	fb840993          	addi	s3,s0,-72
  neg = 0;
 6e8:	00098693          	mv	a3,s3
  i = 0;
 6ec:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 6f0:	00000817          	auipc	a6,0x0
 6f4:	79080813          	addi	a6,a6,1936 # e80 <digits>
 6f8:	00070893          	mv	a7,a4
 6fc:	0017051b          	addiw	a0,a4,1
 700:	00050713          	mv	a4,a0
 704:	02c5f7b3          	remu	a5,a1,a2
 708:	00f807b3          	add	a5,a6,a5
 70c:	0007c783          	lbu	a5,0(a5)
 710:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 714:	00058793          	mv	a5,a1
 718:	02c5d5b3          	divu	a1,a1,a2
 71c:	00168693          	addi	a3,a3,1
 720:	fcc7fce3          	bgeu	a5,a2,6f8 <printint+0x40>
  if (neg)
 724:	00030c63          	beqz	t1,73c <printint+0x84>
    buf[i++] = '-';
 728:	fd050793          	addi	a5,a0,-48
 72c:	00878533          	add	a0,a5,s0
 730:	02d00793          	li	a5,45
 734:	fef50423          	sb	a5,-24(a0)
 738:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 73c:	02e05e63          	blez	a4,778 <printint+0xc0>
 740:	02913c23          	sd	s1,56(sp)
 744:	fff7071b          	addiw	a4,a4,-1
 748:	00e984b3          	add	s1,s3,a4
 74c:	fff98993          	addi	s3,s3,-1
 750:	00e989b3          	add	s3,s3,a4
 754:	02071713          	slli	a4,a4,0x20
 758:	02075713          	srli	a4,a4,0x20
 75c:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 760:	0004c583          	lbu	a1,0(s1)
 764:	00090513          	mv	a0,s2
 768:	ec1ff0ef          	jal	628 <putc>
  while (--i >= 0)
 76c:	fff48493          	addi	s1,s1,-1
 770:	ff3498e3          	bne	s1,s3,760 <printint+0xa8>
 774:	03813483          	ld	s1,56(sp)
}
 778:	04813083          	ld	ra,72(sp)
 77c:	04013403          	ld	s0,64(sp)
 780:	03013903          	ld	s2,48(sp)
 784:	02813983          	ld	s3,40(sp)
 788:	05010113          	addi	sp,sp,80
 78c:	00008067          	ret
  neg = 0;
 790:	00000313          	li	t1,0
 794:	f51ff06f          	j	6e4 <printint+0x2c>

0000000000000798 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 798:	fa010113          	addi	sp,sp,-96
 79c:	04113c23          	sd	ra,88(sp)
 7a0:	04813823          	sd	s0,80(sp)
 7a4:	04913423          	sd	s1,72(sp)
 7a8:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 7ac:	0005c483          	lbu	s1,0(a1)
 7b0:	32048263          	beqz	s1,ad4 <vprintf+0x33c>
 7b4:	05213023          	sd	s2,64(sp)
 7b8:	03313c23          	sd	s3,56(sp)
 7bc:	03413823          	sd	s4,48(sp)
 7c0:	03513423          	sd	s5,40(sp)
 7c4:	03613023          	sd	s6,32(sp)
 7c8:	01713c23          	sd	s7,24(sp)
 7cc:	01813823          	sd	s8,16(sp)
 7d0:	00050b13          	mv	s6,a0
 7d4:	00058a13          	mv	s4,a1
 7d8:	00060b93          	mv	s7,a2
  state = 0;
 7dc:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 7e0:	00000913          	li	s2,0
 7e4:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 7e8:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 7ec:	06400c13          	li	s8,100
 7f0:	0300006f          	j	820 <vprintf+0x88>
        putc(fd, c0);
 7f4:	00048593          	mv	a1,s1
 7f8:	000b0513          	mv	a0,s6
 7fc:	e2dff0ef          	jal	628 <putc>
 800:	0080006f          	j	808 <vprintf+0x70>
    else if (state == '%')
 804:	03598863          	beq	s3,s5,834 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 808:	0019079b          	addiw	a5,s2,1
 80c:	00078913          	mv	s2,a5
 810:	00078713          	mv	a4,a5
 814:	00fa07b3          	add	a5,s4,a5
 818:	0007c483          	lbu	s1,0(a5)
 81c:	28048e63          	beqz	s1,ab8 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 820:	0004879b          	sext.w	a5,s1
    if (state == 0)
 824:	fe0990e3          	bnez	s3,804 <vprintf+0x6c>
      if (c0 == '%')
 828:	fd5796e3          	bne	a5,s5,7f4 <vprintf+0x5c>
        state = '%';
 82c:	00078993          	mv	s3,a5
 830:	fd9ff06f          	j	808 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 834:	00ea06b3          	add	a3,s4,a4
 838:	0016c603          	lbu	a2,1(a3)
      if (c1)
 83c:	2a060663          	beqz	a2,ae8 <vprintf+0x350>
      if (c0 == 'd')
 840:	05878063          	beq	a5,s8,880 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 844:	f9478693          	addi	a3,a5,-108
 848:	0016b693          	seqz	a3,a3
 84c:	f9c60593          	addi	a1,a2,-100
 850:	04059a63          	bnez	a1,8a4 <vprintf+0x10c>
 854:	04068863          	beqz	a3,8a4 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 858:	008b8493          	addi	s1,s7,8
 85c:	00100693          	li	a3,1
 860:	00a00613          	li	a2,10
 864:	000bb583          	ld	a1,0(s7)
 868:	000b0513          	mv	a0,s6
 86c:	e4dff0ef          	jal	6b8 <printint>
        i += 1;
 870:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 874:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 878:	00000993          	li	s3,0
 87c:	f8dff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 880:	008b8493          	addi	s1,s7,8
 884:	00100693          	li	a3,1
 888:	00a00613          	li	a2,10
 88c:	000ba583          	lw	a1,0(s7)
 890:	000b0513          	mv	a0,s6
 894:	e25ff0ef          	jal	6b8 <printint>
 898:	00048b93          	mv	s7,s1
      state = 0;
 89c:	00000993          	li	s3,0
 8a0:	f69ff06f          	j	808 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 8a4:	00ea0733          	add	a4,s4,a4
 8a8:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 8ac:	f9460713          	addi	a4,a2,-108
 8b0:	00173713          	seqz	a4,a4
 8b4:	00e6f733          	and	a4,a3,a4
 8b8:	f9c58513          	addi	a0,a1,-100
 8bc:	24051263          	bnez	a0,b00 <vprintf+0x368>
 8c0:	24070063          	beqz	a4,b00 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 8c4:	008b8493          	addi	s1,s7,8
 8c8:	00100693          	li	a3,1
 8cc:	00a00613          	li	a2,10
 8d0:	000bb583          	ld	a1,0(s7)
 8d4:	000b0513          	mv	a0,s6
 8d8:	de1ff0ef          	jal	6b8 <printint>
        i += 2;
 8dc:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 8e0:	00048b93          	mv	s7,s1
      state = 0;
 8e4:	00000993          	li	s3,0
        i += 2;
 8e8:	f21ff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 8ec:	008b8493          	addi	s1,s7,8
 8f0:	00000693          	li	a3,0
 8f4:	00a00613          	li	a2,10
 8f8:	000be583          	lwu	a1,0(s7)
 8fc:	000b0513          	mv	a0,s6
 900:	db9ff0ef          	jal	6b8 <printint>
 904:	00048b93          	mv	s7,s1
      state = 0;
 908:	00000993          	li	s3,0
 90c:	efdff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 910:	008b8493          	addi	s1,s7,8
 914:	00000693          	li	a3,0
 918:	00a00613          	li	a2,10
 91c:	000bb583          	ld	a1,0(s7)
 920:	000b0513          	mv	a0,s6
 924:	d95ff0ef          	jal	6b8 <printint>
        i += 1;
 928:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 92c:	00048b93          	mv	s7,s1
      state = 0;
 930:	00000993          	li	s3,0
 934:	ed5ff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 938:	008b8493          	addi	s1,s7,8
 93c:	00000693          	li	a3,0
 940:	00a00613          	li	a2,10
 944:	000bb583          	ld	a1,0(s7)
 948:	000b0513          	mv	a0,s6
 94c:	d6dff0ef          	jal	6b8 <printint>
        i += 2;
 950:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 954:	00048b93          	mv	s7,s1
      state = 0;
 958:	00000993          	li	s3,0
        i += 2;
 95c:	eadff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 960:	008b8493          	addi	s1,s7,8
 964:	00000693          	li	a3,0
 968:	01000613          	li	a2,16
 96c:	000be583          	lwu	a1,0(s7)
 970:	000b0513          	mv	a0,s6
 974:	d45ff0ef          	jal	6b8 <printint>
 978:	00048b93          	mv	s7,s1
      state = 0;
 97c:	00000993          	li	s3,0
 980:	e89ff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 984:	008b8493          	addi	s1,s7,8
 988:	00000693          	li	a3,0
 98c:	01000613          	li	a2,16
 990:	000bb583          	ld	a1,0(s7)
 994:	000b0513          	mv	a0,s6
 998:	d21ff0ef          	jal	6b8 <printint>
        i += 1;
 99c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 9a0:	00048b93          	mv	s7,s1
      state = 0;
 9a4:	00000993          	li	s3,0
 9a8:	e61ff06f          	j	808 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 9ac:	008b8493          	addi	s1,s7,8
 9b0:	00000693          	li	a3,0
 9b4:	01000613          	li	a2,16
 9b8:	000bb583          	ld	a1,0(s7)
 9bc:	000b0513          	mv	a0,s6
 9c0:	cf9ff0ef          	jal	6b8 <printint>
        i += 2;
 9c4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 9c8:	00048b93          	mv	s7,s1
      state = 0;
 9cc:	00000993          	li	s3,0
        i += 2;
 9d0:	e39ff06f          	j	808 <vprintf+0x70>
 9d4:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 9d8:	008b8793          	addi	a5,s7,8
 9dc:	00078c93          	mv	s9,a5
 9e0:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 9e4:	03000593          	li	a1,48
 9e8:	000b0513          	mv	a0,s6
 9ec:	c3dff0ef          	jal	628 <putc>
  putc(fd, 'x');
 9f0:	07800593          	li	a1,120
 9f4:	000b0513          	mv	a0,s6
 9f8:	c31ff0ef          	jal	628 <putc>
 9fc:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 a00:	00000b97          	auipc	s7,0x0
 a04:	480b8b93          	addi	s7,s7,1152 # e80 <digits>
 a08:	03c9d793          	srli	a5,s3,0x3c
 a0c:	00fb87b3          	add	a5,s7,a5
 a10:	0007c583          	lbu	a1,0(a5)
 a14:	000b0513          	mv	a0,s6
 a18:	c11ff0ef          	jal	628 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 a1c:	00499993          	slli	s3,s3,0x4
 a20:	fff4849b          	addiw	s1,s1,-1
 a24:	fe0492e3          	bnez	s1,a08 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 a28:	000c8b93          	mv	s7,s9
      state = 0;
 a2c:	00000993          	li	s3,0
 a30:	00813c83          	ld	s9,8(sp)
 a34:	dd5ff06f          	j	808 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 a38:	008b8493          	addi	s1,s7,8
 a3c:	000bc583          	lbu	a1,0(s7)
 a40:	000b0513          	mv	a0,s6
 a44:	be5ff0ef          	jal	628 <putc>
 a48:	00048b93          	mv	s7,s1
      state = 0;
 a4c:	00000993          	li	s3,0
 a50:	db9ff06f          	j	808 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 a54:	008b8993          	addi	s3,s7,8
 a58:	000bb483          	ld	s1,0(s7)
 a5c:	02048663          	beqz	s1,a88 <vprintf+0x2f0>
        for (; *s; s++)
 a60:	0004c583          	lbu	a1,0(s1)
 a64:	04058463          	beqz	a1,aac <vprintf+0x314>
          putc(fd, *s);
 a68:	000b0513          	mv	a0,s6
 a6c:	bbdff0ef          	jal	628 <putc>
        for (; *s; s++)
 a70:	00148493          	addi	s1,s1,1
 a74:	0004c583          	lbu	a1,0(s1)
 a78:	fe0598e3          	bnez	a1,a68 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 a7c:	00098b93          	mv	s7,s3
      state = 0;
 a80:	00000993          	li	s3,0
 a84:	d85ff06f          	j	808 <vprintf+0x70>
          s = "(null)";
 a88:	00000497          	auipc	s1,0x0
 a8c:	3f048493          	addi	s1,s1,1008 # e78 <malloc+0x1a8>
        for (; *s; s++)
 a90:	02800593          	li	a1,40
 a94:	fd5ff06f          	j	a68 <vprintf+0x2d0>
        putc(fd, '%');
 a98:	00078593          	mv	a1,a5
 a9c:	000b0513          	mv	a0,s6
 aa0:	b89ff0ef          	jal	628 <putc>
      state = 0;
 aa4:	00000993          	li	s3,0
 aa8:	d61ff06f          	j	808 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 aac:	00098b93          	mv	s7,s3
      state = 0;
 ab0:	00000993          	li	s3,0
 ab4:	d55ff06f          	j	808 <vprintf+0x70>
 ab8:	04013903          	ld	s2,64(sp)
 abc:	03813983          	ld	s3,56(sp)
 ac0:	03013a03          	ld	s4,48(sp)
 ac4:	02813a83          	ld	s5,40(sp)
 ac8:	02013b03          	ld	s6,32(sp)
 acc:	01813b83          	ld	s7,24(sp)
 ad0:	01013c03          	ld	s8,16(sp)
    }
  }
}
 ad4:	05813083          	ld	ra,88(sp)
 ad8:	05013403          	ld	s0,80(sp)
 adc:	04813483          	ld	s1,72(sp)
 ae0:	06010113          	addi	sp,sp,96
 ae4:	00008067          	ret
      if (c0 == 'd')
 ae8:	06400713          	li	a4,100
 aec:	d8e78ae3          	beq	a5,a4,880 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 af0:	f9478693          	addi	a3,a5,-108
 af4:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 af8:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 afc:	00000713          	li	a4,0
      else if (c0 == 'u')
 b00:	07500513          	li	a0,117
 b04:	dea784e3          	beq	a5,a0,8ec <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 b08:	f8b60513          	addi	a0,a2,-117
 b0c:	00051463          	bnez	a0,b14 <vprintf+0x37c>
 b10:	e00690e3          	bnez	a3,910 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 b14:	f8b58513          	addi	a0,a1,-117
 b18:	00051463          	bnez	a0,b20 <vprintf+0x388>
 b1c:	e0071ee3          	bnez	a4,938 <vprintf+0x1a0>
      else if (c0 == 'x')
 b20:	07800513          	li	a0,120
 b24:	e2a78ee3          	beq	a5,a0,960 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 b28:	f8860613          	addi	a2,a2,-120
 b2c:	00061463          	bnez	a2,b34 <vprintf+0x39c>
 b30:	e4069ae3          	bnez	a3,984 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 b34:	f8858593          	addi	a1,a1,-120
 b38:	00059463          	bnez	a1,b40 <vprintf+0x3a8>
 b3c:	e60718e3          	bnez	a4,9ac <vprintf+0x214>
      else if (c0 == 'p')
 b40:	07000713          	li	a4,112
 b44:	e8e788e3          	beq	a5,a4,9d4 <vprintf+0x23c>
      else if (c0 == 'c')
 b48:	06300713          	li	a4,99
 b4c:	eee786e3          	beq	a5,a4,a38 <vprintf+0x2a0>
      else if (c0 == 's')
 b50:	07300713          	li	a4,115
 b54:	f0e780e3          	beq	a5,a4,a54 <vprintf+0x2bc>
      else if (c0 == '%')
 b58:	02500713          	li	a4,37
 b5c:	f2e78ee3          	beq	a5,a4,a98 <vprintf+0x300>
        putc(fd, '%');
 b60:	02500593          	li	a1,37
 b64:	000b0513          	mv	a0,s6
 b68:	ac1ff0ef          	jal	628 <putc>
        putc(fd, c0);
 b6c:	00048593          	mv	a1,s1
 b70:	000b0513          	mv	a0,s6
 b74:	ab5ff0ef          	jal	628 <putc>
      state = 0;
 b78:	00000993          	li	s3,0
 b7c:	c8dff06f          	j	808 <vprintf+0x70>

0000000000000b80 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 b80:	fb010113          	addi	sp,sp,-80
 b84:	00113c23          	sd	ra,24(sp)
 b88:	00813823          	sd	s0,16(sp)
 b8c:	02010413          	addi	s0,sp,32
 b90:	00c43023          	sd	a2,0(s0)
 b94:	00d43423          	sd	a3,8(s0)
 b98:	00e43823          	sd	a4,16(s0)
 b9c:	00f43c23          	sd	a5,24(s0)
 ba0:	03043023          	sd	a6,32(s0)
 ba4:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 ba8:	00040613          	mv	a2,s0
 bac:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 bb0:	be9ff0ef          	jal	798 <vprintf>
}
 bb4:	01813083          	ld	ra,24(sp)
 bb8:	01013403          	ld	s0,16(sp)
 bbc:	05010113          	addi	sp,sp,80
 bc0:	00008067          	ret

0000000000000bc4 <printf>:

void printf(const char *fmt, ...)
{
 bc4:	fa010113          	addi	sp,sp,-96
 bc8:	00113c23          	sd	ra,24(sp)
 bcc:	00813823          	sd	s0,16(sp)
 bd0:	02010413          	addi	s0,sp,32
 bd4:	00b43423          	sd	a1,8(s0)
 bd8:	00c43823          	sd	a2,16(s0)
 bdc:	00d43c23          	sd	a3,24(s0)
 be0:	02e43023          	sd	a4,32(s0)
 be4:	02f43423          	sd	a5,40(s0)
 be8:	03043823          	sd	a6,48(s0)
 bec:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 bf0:	00840613          	addi	a2,s0,8
 bf4:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 bf8:	00050593          	mv	a1,a0
 bfc:	00100513          	li	a0,1
 c00:	b99ff0ef          	jal	798 <vprintf>
  putc_flush();
 c04:	9d9ff0ef          	jal	5dc <putc_flush>
}
 c08:	01813083          	ld	ra,24(sp)
 c0c:	01013403          	ld	s0,16(sp)
 c10:	06010113          	addi	sp,sp,96
 c14:	00008067          	ret

0000000000000c18 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 c18:	ff010113          	addi	sp,sp,-16
 c1c:	00113423          	sd	ra,8(sp)
 c20:	00813023          	sd	s0,0(sp)
 c24:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 c28:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c2c:	00000797          	auipc	a5,0x0
 c30:	3ec7b783          	ld	a5,1004(a5) # 1018 <freep>
 c34:	0140006f          	j	c48 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c38:	0007b703          	ld	a4,0(a5)
 c3c:	00e7e463          	bltu	a5,a4,c44 <free+0x2c>
 c40:	00e6ec63          	bltu	a3,a4,c58 <free+0x40>
{
 c44:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 c48:	fed7f8e3          	bgeu	a5,a3,c38 <free+0x20>
 c4c:	0007b703          	ld	a4,0(a5)
 c50:	00e6e463          	bltu	a3,a4,c58 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 c54:	fee7e8e3          	bltu	a5,a4,c44 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 c58:	ff852583          	lw	a1,-8(a0)
 c5c:	0007b603          	ld	a2,0(a5)
 c60:	02059813          	slli	a6,a1,0x20
 c64:	01c85713          	srli	a4,a6,0x1c
 c68:	00e68733          	add	a4,a3,a4
 c6c:	02e60c63          	beq	a2,a4,ca4 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 c70:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 c74:	0087a603          	lw	a2,8(a5)
 c78:	02061593          	slli	a1,a2,0x20
 c7c:	01c5d713          	srli	a4,a1,0x1c
 c80:	00e78733          	add	a4,a5,a4
 c84:	02e68c63          	beq	a3,a4,cbc <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 c88:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 c8c:	00000717          	auipc	a4,0x0
 c90:	38f73623          	sd	a5,908(a4) # 1018 <freep>
}
 c94:	00813083          	ld	ra,8(sp)
 c98:	00013403          	ld	s0,0(sp)
 c9c:	01010113          	addi	sp,sp,16
 ca0:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 ca4:	00862703          	lw	a4,8(a2)
 ca8:	00b7073b          	addw	a4,a4,a1
 cac:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 cb0:	0007b703          	ld	a4,0(a5)
 cb4:	00073603          	ld	a2,0(a4)
 cb8:	fb9ff06f          	j	c70 <free+0x58>
    p->s.size += bp->s.size;
 cbc:	ff852703          	lw	a4,-8(a0)
 cc0:	00c7073b          	addw	a4,a4,a2
 cc4:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 cc8:	ff053683          	ld	a3,-16(a0)
 ccc:	fbdff06f          	j	c88 <free+0x70>

0000000000000cd0 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 cd0:	fc010113          	addi	sp,sp,-64
 cd4:	02113c23          	sd	ra,56(sp)
 cd8:	02813823          	sd	s0,48(sp)
 cdc:	03213023          	sd	s2,32(sp)
 ce0:	01313c23          	sd	s3,24(sp)
 ce4:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 ce8:	02051993          	slli	s3,a0,0x20
 cec:	0209d993          	srli	s3,s3,0x20
 cf0:	00f98993          	addi	s3,s3,15
 cf4:	0049d993          	srli	s3,s3,0x4
 cf8:	0019899b          	addiw	s3,s3,1
 cfc:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 d00:	00000517          	auipc	a0,0x0
 d04:	31853503          	ld	a0,792(a0) # 1018 <freep>
 d08:	04050463          	beqz	a0,d50 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d0c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 d10:	0087a703          	lw	a4,8(a5)
 d14:	0d377a63          	bgeu	a4,s3,de8 <malloc+0x118>
 d18:	02913423          	sd	s1,40(sp)
 d1c:	01413823          	sd	s4,16(sp)
 d20:	01513423          	sd	s5,8(sp)
 d24:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 d28:	00098a13          	mv	s4,s3
 d2c:	00001737          	lui	a4,0x1
 d30:	00e9f463          	bgeu	s3,a4,d38 <malloc+0x68>
 d34:	00001a37          	lui	s4,0x1
 d38:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 d3c:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 d40:	00000497          	auipc	s1,0x0
 d44:	2d848493          	addi	s1,s1,728 # 1018 <freep>
  if(p == SBRK_ERROR)
 d48:	fff00a93          	li	s5,-1
 d4c:	05c0006f          	j	da8 <malloc+0xd8>
 d50:	02913423          	sd	s1,40(sp)
 d54:	01413823          	sd	s4,16(sp)
 d58:	01513423          	sd	s5,8(sp)
 d5c:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 d60:	00000797          	auipc	a5,0x0
 d64:	34078793          	addi	a5,a5,832 # 10a0 <base>
 d68:	00000717          	auipc	a4,0x0
 d6c:	2af73823          	sd	a5,688(a4) # 1018 <freep>
 d70:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 d74:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 d78:	fb1ff06f          	j	d28 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 d7c:	0007b703          	ld	a4,0(a5)
 d80:	00e53023          	sd	a4,0(a0)
 d84:	0800006f          	j	e04 <malloc+0x134>
  hp->s.size = nu;
 d88:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 d8c:	01050513          	addi	a0,a0,16
 d90:	e89ff0ef          	jal	c18 <free>
  return freep;
 d94:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 d98:	08050863          	beqz	a0,e28 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 d9c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 da0:	0087a703          	lw	a4,8(a5)
 da4:	03277a63          	bgeu	a4,s2,dd8 <malloc+0x108>
    if(p == freep)
 da8:	0004b703          	ld	a4,0(s1)
 dac:	00078513          	mv	a0,a5
 db0:	fef716e3          	bne	a4,a5,d9c <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 db4:	000a0513          	mv	a0,s4
 db8:	ed8ff0ef          	jal	490 <sbrk>
  if(p == SBRK_ERROR)
 dbc:	fd5516e3          	bne	a0,s5,d88 <malloc+0xb8>
        return 0;
 dc0:	00000513          	li	a0,0
 dc4:	02813483          	ld	s1,40(sp)
 dc8:	01013a03          	ld	s4,16(sp)
 dcc:	00813a83          	ld	s5,8(sp)
 dd0:	00013b03          	ld	s6,0(sp)
 dd4:	03c0006f          	j	e10 <malloc+0x140>
 dd8:	02813483          	ld	s1,40(sp)
 ddc:	01013a03          	ld	s4,16(sp)
 de0:	00813a83          	ld	s5,8(sp)
 de4:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 de8:	f8e90ae3          	beq	s2,a4,d7c <malloc+0xac>
        p->s.size -= nunits;
 dec:	4137073b          	subw	a4,a4,s3
 df0:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 df4:	02071693          	slli	a3,a4,0x20
 df8:	01c6d713          	srli	a4,a3,0x1c
 dfc:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 e00:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 e04:	00000717          	auipc	a4,0x0
 e08:	20a73a23          	sd	a0,532(a4) # 1018 <freep>
      return (void*)(p + 1);
 e0c:	01078513          	addi	a0,a5,16
  }
}
 e10:	03813083          	ld	ra,56(sp)
 e14:	03013403          	ld	s0,48(sp)
 e18:	02013903          	ld	s2,32(sp)
 e1c:	01813983          	ld	s3,24(sp)
 e20:	04010113          	addi	sp,sp,64
 e24:	00008067          	ret
 e28:	02813483          	ld	s1,40(sp)
 e2c:	01013a03          	ld	s4,16(sp)
 e30:	00813a83          	ld	s5,8(sp)
 e34:	00013b03          	ld	s6,0(sp)
 e38:	fd9ff06f          	j	e10 <malloc+0x140>
