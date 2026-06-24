
user/_forktest:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <print>:

#define N  1000

void
print(const char *s)
{
   0:	fe010113          	addi	sp,sp,-32
   4:	00113c23          	sd	ra,24(sp)
   8:	00813823          	sd	s0,16(sp)
   c:	00913423          	sd	s1,8(sp)
  10:	02010413          	addi	s0,sp,32
  14:	00050493          	mv	s1,a0
  write(1, s, strlen(s));
  18:	1a8000ef          	jal	1c0 <strlen>
  1c:	00050613          	mv	a2,a0
  20:	00048593          	mv	a1,s1
  24:	00100513          	li	a0,1
  28:	590000ef          	jal	5b8 <write>
}
  2c:	01813083          	ld	ra,24(sp)
  30:	01013403          	ld	s0,16(sp)
  34:	00813483          	ld	s1,8(sp)
  38:	02010113          	addi	sp,sp,32
  3c:	00008067          	ret

0000000000000040 <forktest>:

void
forktest(void)
{
  40:	fe010113          	addi	sp,sp,-32
  44:	00113c23          	sd	ra,24(sp)
  48:	00813823          	sd	s0,16(sp)
  4c:	00913423          	sd	s1,8(sp)
  50:	01213023          	sd	s2,0(sp)
  54:	02010413          	addi	s0,sp,32
  int n, pid;

  print("fork test\n");
  58:	00000517          	auipc	a0,0x0
  5c:	62050513          	addi	a0,a0,1568 # 678 <uptime+0xc>
  60:	fa1ff0ef          	jal	0 <print>

  for(n=0; n<N; n++){
  64:	00000493          	li	s1,0
  68:	3e800913          	li	s2,1000
    pid = fork();
  6c:	510000ef          	jal	57c <fork>
    if(pid < 0)
  70:	04054863          	bltz	a0,c0 <forktest+0x80>
      break;
    if(pid == 0)
  74:	02050063          	beqz	a0,94 <forktest+0x54>
  for(n=0; n<N; n++){
  78:	0014849b          	addiw	s1,s1,1
  7c:	ff2498e3          	bne	s1,s2,6c <forktest+0x2c>
      exit(0);
  }

  if(n == N){
    print("fork claimed to work N times!\n");
  80:	00000517          	auipc	a0,0x0
  84:	64850513          	addi	a0,a0,1608 # 6c8 <uptime+0x5c>
  88:	f79ff0ef          	jal	0 <print>
    exit(1);
  8c:	00100513          	li	a0,1
  90:	4f8000ef          	jal	588 <exit>
      exit(0);
  94:	4f4000ef          	jal	588 <exit>
  }

  for(; n > 0; n--){
    if(wait(0) < 0){
      print("wait stopped early\n");
  98:	00000517          	auipc	a0,0x0
  9c:	5f050513          	addi	a0,a0,1520 # 688 <uptime+0x1c>
  a0:	f61ff0ef          	jal	0 <print>
      exit(1);
  a4:	00100513          	li	a0,1
  a8:	4e0000ef          	jal	588 <exit>
    }
  }

  if(wait(0) != -1){
    print("wait got too many\n");
  ac:	00000517          	auipc	a0,0x0
  b0:	5f450513          	addi	a0,a0,1524 # 6a0 <uptime+0x34>
  b4:	f4dff0ef          	jal	0 <print>
    exit(1);
  b8:	00100513          	li	a0,1
  bc:	4cc000ef          	jal	588 <exit>
  for(; n > 0; n--){
  c0:	00905c63          	blez	s1,d8 <forktest+0x98>
    if(wait(0) < 0){
  c4:	00000513          	li	a0,0
  c8:	4cc000ef          	jal	594 <wait>
  cc:	fc0546e3          	bltz	a0,98 <forktest+0x58>
  for(; n > 0; n--){
  d0:	fff4849b          	addiw	s1,s1,-1
  d4:	fe0498e3          	bnez	s1,c4 <forktest+0x84>
  if(wait(0) != -1){
  d8:	00000513          	li	a0,0
  dc:	4b8000ef          	jal	594 <wait>
  e0:	fff00793          	li	a5,-1
  e4:	fcf514e3          	bne	a0,a5,ac <forktest+0x6c>
  }

  print("fork test OK\n");
  e8:	00000517          	auipc	a0,0x0
  ec:	5d050513          	addi	a0,a0,1488 # 6b8 <uptime+0x4c>
  f0:	f11ff0ef          	jal	0 <print>
}
  f4:	01813083          	ld	ra,24(sp)
  f8:	01013403          	ld	s0,16(sp)
  fc:	00813483          	ld	s1,8(sp)
 100:	00013903          	ld	s2,0(sp)
 104:	02010113          	addi	sp,sp,32
 108:	00008067          	ret

000000000000010c <main>:

int
main(void)
{
 10c:	ff010113          	addi	sp,sp,-16
 110:	00113423          	sd	ra,8(sp)
 114:	00813023          	sd	s0,0(sp)
 118:	01010413          	addi	s0,sp,16
  forktest();
 11c:	f25ff0ef          	jal	40 <forktest>
  exit(0);
 120:	00000513          	li	a0,0
 124:	464000ef          	jal	588 <exit>

0000000000000128 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
 128:	ff010113          	addi	sp,sp,-16
 12c:	00113423          	sd	ra,8(sp)
 130:	00813023          	sd	s0,0(sp)
 134:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
 138:	fd5ff0ef          	jal	10c <main>
  exit(r);
 13c:	44c000ef          	jal	588 <exit>

0000000000000140 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 140:	ff010113          	addi	sp,sp,-16
 144:	00113423          	sd	ra,8(sp)
 148:	00813023          	sd	s0,0(sp)
 14c:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 150:	00050793          	mv	a5,a0
 154:	00158593          	addi	a1,a1,1
 158:	00178793          	addi	a5,a5,1
 15c:	fff5c703          	lbu	a4,-1(a1)
 160:	fee78fa3          	sb	a4,-1(a5)
 164:	fe0718e3          	bnez	a4,154 <strcpy+0x14>
    ;
  return os;
}
 168:	00813083          	ld	ra,8(sp)
 16c:	00013403          	ld	s0,0(sp)
 170:	01010113          	addi	sp,sp,16
 174:	00008067          	ret

0000000000000178 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 178:	ff010113          	addi	sp,sp,-16
 17c:	00113423          	sd	ra,8(sp)
 180:	00813023          	sd	s0,0(sp)
 184:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 188:	00054783          	lbu	a5,0(a0)
 18c:	00078e63          	beqz	a5,1a8 <strcmp+0x30>
 190:	0005c703          	lbu	a4,0(a1)
 194:	00f71a63          	bne	a4,a5,1a8 <strcmp+0x30>
    p++, q++;
 198:	00150513          	addi	a0,a0,1
 19c:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 1a0:	00054783          	lbu	a5,0(a0)
 1a4:	fe0796e3          	bnez	a5,190 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 1a8:	0005c503          	lbu	a0,0(a1)
}
 1ac:	40a7853b          	subw	a0,a5,a0
 1b0:	00813083          	ld	ra,8(sp)
 1b4:	00013403          	ld	s0,0(sp)
 1b8:	01010113          	addi	sp,sp,16
 1bc:	00008067          	ret

00000000000001c0 <strlen>:

uint
strlen(const char *s)
{
 1c0:	ff010113          	addi	sp,sp,-16
 1c4:	00113423          	sd	ra,8(sp)
 1c8:	00813023          	sd	s0,0(sp)
 1cc:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 1d0:	00054783          	lbu	a5,0(a0)
 1d4:	02078663          	beqz	a5,200 <strlen+0x40>
 1d8:	00150793          	addi	a5,a0,1
 1dc:	00078693          	mv	a3,a5
 1e0:	00178793          	addi	a5,a5,1
 1e4:	fff7c703          	lbu	a4,-1(a5)
 1e8:	fe071ae3          	bnez	a4,1dc <strlen+0x1c>
 1ec:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 1f0:	00813083          	ld	ra,8(sp)
 1f4:	00013403          	ld	s0,0(sp)
 1f8:	01010113          	addi	sp,sp,16
 1fc:	00008067          	ret
  for(n = 0; s[n]; n++)
 200:	00000513          	li	a0,0
 204:	fedff06f          	j	1f0 <strlen+0x30>

0000000000000208 <memset>:

void*
memset(void *dst, int c, uint n)
{
 208:	ff010113          	addi	sp,sp,-16
 20c:	00113423          	sd	ra,8(sp)
 210:	00813023          	sd	s0,0(sp)
 214:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 218:	02060063          	beqz	a2,238 <memset+0x30>
 21c:	00050793          	mv	a5,a0
 220:	02061613          	slli	a2,a2,0x20
 224:	02065613          	srli	a2,a2,0x20
 228:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 22c:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 230:	00178793          	addi	a5,a5,1
 234:	fee79ce3          	bne	a5,a4,22c <memset+0x24>
  }
  return dst;
}
 238:	00813083          	ld	ra,8(sp)
 23c:	00013403          	ld	s0,0(sp)
 240:	01010113          	addi	sp,sp,16
 244:	00008067          	ret

0000000000000248 <strchr>:

char*
strchr(const char *s, char c)
{
 248:	ff010113          	addi	sp,sp,-16
 24c:	00113423          	sd	ra,8(sp)
 250:	00813023          	sd	s0,0(sp)
 254:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 258:	00054783          	lbu	a5,0(a0)
 25c:	02078463          	beqz	a5,284 <strchr+0x3c>
    if(*s == c)
 260:	00f58a63          	beq	a1,a5,274 <strchr+0x2c>
  for(; *s; s++)
 264:	00150513          	addi	a0,a0,1
 268:	00054783          	lbu	a5,0(a0)
 26c:	fe079ae3          	bnez	a5,260 <strchr+0x18>
      return (char*)s;
  return 0;
 270:	00000513          	li	a0,0
}
 274:	00813083          	ld	ra,8(sp)
 278:	00013403          	ld	s0,0(sp)
 27c:	01010113          	addi	sp,sp,16
 280:	00008067          	ret
  return 0;
 284:	00000513          	li	a0,0
 288:	fedff06f          	j	274 <strchr+0x2c>

000000000000028c <gets>:

char*
gets(char *buf, int max)
{
 28c:	fa010113          	addi	sp,sp,-96
 290:	04113c23          	sd	ra,88(sp)
 294:	04813823          	sd	s0,80(sp)
 298:	04913423          	sd	s1,72(sp)
 29c:	05213023          	sd	s2,64(sp)
 2a0:	03313c23          	sd	s3,56(sp)
 2a4:	03413823          	sd	s4,48(sp)
 2a8:	03513423          	sd	s5,40(sp)
 2ac:	03613023          	sd	s6,32(sp)
 2b0:	01713c23          	sd	s7,24(sp)
 2b4:	01813823          	sd	s8,16(sp)
 2b8:	06010413          	addi	s0,sp,96
 2bc:	00050b93          	mv	s7,a0
 2c0:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 2c4:	00050913          	mv	s2,a0
 2c8:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 2cc:	faf40b13          	addi	s6,s0,-81
 2d0:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 2d4:	00048c13          	mv	s8,s1
 2d8:	0014899b          	addiw	s3,s1,1
 2dc:	00098493          	mv	s1,s3
 2e0:	0349dc63          	bge	s3,s4,318 <gets+0x8c>
    cc = read(0, &c, 1);
 2e4:	000a8613          	mv	a2,s5
 2e8:	000b0593          	mv	a1,s6
 2ec:	00000513          	li	a0,0
 2f0:	2bc000ef          	jal	5ac <read>
    if(cc < 1)
 2f4:	02a05263          	blez	a0,318 <gets+0x8c>
      break;
    buf[i++] = c;
 2f8:	faf44783          	lbu	a5,-81(s0)
 2fc:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 300:	00190913          	addi	s2,s2,1
 304:	ff678713          	addi	a4,a5,-10
 308:	00070663          	beqz	a4,314 <gets+0x88>
 30c:	ff378793          	addi	a5,a5,-13
 310:	fc0792e3          	bnez	a5,2d4 <gets+0x48>
    buf[i++] = c;
 314:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 318:	018b8c33          	add	s8,s7,s8
 31c:	000c0023          	sb	zero,0(s8)
  return buf;
}
 320:	000b8513          	mv	a0,s7
 324:	05813083          	ld	ra,88(sp)
 328:	05013403          	ld	s0,80(sp)
 32c:	04813483          	ld	s1,72(sp)
 330:	04013903          	ld	s2,64(sp)
 334:	03813983          	ld	s3,56(sp)
 338:	03013a03          	ld	s4,48(sp)
 33c:	02813a83          	ld	s5,40(sp)
 340:	02013b03          	ld	s6,32(sp)
 344:	01813b83          	ld	s7,24(sp)
 348:	01013c03          	ld	s8,16(sp)
 34c:	06010113          	addi	sp,sp,96
 350:	00008067          	ret

0000000000000354 <stat>:

int
stat(const char *n, struct stat *st)
{
 354:	fe010113          	addi	sp,sp,-32
 358:	00113c23          	sd	ra,24(sp)
 35c:	00813823          	sd	s0,16(sp)
 360:	01213023          	sd	s2,0(sp)
 364:	02010413          	addi	s0,sp,32
 368:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 36c:	00000593          	li	a1,0
 370:	278000ef          	jal	5e8 <open>
  if(fd < 0)
 374:	02054e63          	bltz	a0,3b0 <stat+0x5c>
 378:	00913423          	sd	s1,8(sp)
 37c:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 380:	00090593          	mv	a1,s2
 384:	288000ef          	jal	60c <fstat>
 388:	00050913          	mv	s2,a0
  close(fd);
 38c:	00048513          	mv	a0,s1
 390:	234000ef          	jal	5c4 <close>
  return r;
 394:	00813483          	ld	s1,8(sp)
}
 398:	00090513          	mv	a0,s2
 39c:	01813083          	ld	ra,24(sp)
 3a0:	01013403          	ld	s0,16(sp)
 3a4:	00013903          	ld	s2,0(sp)
 3a8:	02010113          	addi	sp,sp,32
 3ac:	00008067          	ret
    return -1;
 3b0:	fff00793          	li	a5,-1
 3b4:	00078913          	mv	s2,a5
 3b8:	fe1ff06f          	j	398 <stat+0x44>

00000000000003bc <atoi>:

int
atoi(const char *s)
{
 3bc:	ff010113          	addi	sp,sp,-16
 3c0:	00113423          	sd	ra,8(sp)
 3c4:	00813023          	sd	s0,0(sp)
 3c8:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 3cc:	00054683          	lbu	a3,0(a0)
 3d0:	fd06879b          	addiw	a5,a3,-48
 3d4:	0ff7f793          	zext.b	a5,a5
 3d8:	00900613          	li	a2,9
 3dc:	04f66263          	bltu	a2,a5,420 <atoi+0x64>
 3e0:	00050713          	mv	a4,a0
  n = 0;
 3e4:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 3e8:	00170713          	addi	a4,a4,1
 3ec:	0025179b          	slliw	a5,a0,0x2
 3f0:	00a787bb          	addw	a5,a5,a0
 3f4:	0017979b          	slliw	a5,a5,0x1
 3f8:	00d787bb          	addw	a5,a5,a3
 3fc:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 400:	00074683          	lbu	a3,0(a4)
 404:	fd06879b          	addiw	a5,a3,-48
 408:	0ff7f793          	zext.b	a5,a5
 40c:	fcf67ee3          	bgeu	a2,a5,3e8 <atoi+0x2c>
  return n;
}
 410:	00813083          	ld	ra,8(sp)
 414:	00013403          	ld	s0,0(sp)
 418:	01010113          	addi	sp,sp,16
 41c:	00008067          	ret
  n = 0;
 420:	00000513          	li	a0,0
 424:	fedff06f          	j	410 <atoi+0x54>

0000000000000428 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 428:	ff010113          	addi	sp,sp,-16
 42c:	00113423          	sd	ra,8(sp)
 430:	00813023          	sd	s0,0(sp)
 434:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 438:	02b57e63          	bgeu	a0,a1,474 <memmove+0x4c>
    while(n-- > 0)
 43c:	02c05463          	blez	a2,464 <memmove+0x3c>
 440:	02061613          	slli	a2,a2,0x20
 444:	02065613          	srli	a2,a2,0x20
 448:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 44c:	00050713          	mv	a4,a0
      *dst++ = *src++;
 450:	00158593          	addi	a1,a1,1
 454:	00170713          	addi	a4,a4,1
 458:	fff5c683          	lbu	a3,-1(a1)
 45c:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 460:	fee798e3          	bne	a5,a4,450 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 464:	00813083          	ld	ra,8(sp)
 468:	00013403          	ld	s0,0(sp)
 46c:	01010113          	addi	sp,sp,16
 470:	00008067          	ret
    while(n-- > 0)
 474:	fec058e3          	blez	a2,464 <memmove+0x3c>
    dst += n;
 478:	00c50733          	add	a4,a0,a2
    src += n;
 47c:	00c585b3          	add	a1,a1,a2
 480:	fff6079b          	addiw	a5,a2,-1
 484:	02079793          	slli	a5,a5,0x20
 488:	0207d793          	srli	a5,a5,0x20
 48c:	fff7c793          	not	a5,a5
 490:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 494:	fff58593          	addi	a1,a1,-1
 498:	fff70713          	addi	a4,a4,-1
 49c:	0005c683          	lbu	a3,0(a1)
 4a0:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 4a4:	fef718e3          	bne	a4,a5,494 <memmove+0x6c>
 4a8:	fbdff06f          	j	464 <memmove+0x3c>

00000000000004ac <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 4ac:	ff010113          	addi	sp,sp,-16
 4b0:	00113423          	sd	ra,8(sp)
 4b4:	00813023          	sd	s0,0(sp)
 4b8:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 4bc:	04060263          	beqz	a2,500 <memcmp+0x54>
 4c0:	02061613          	slli	a2,a2,0x20
 4c4:	02065613          	srli	a2,a2,0x20
 4c8:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 4cc:	00054783          	lbu	a5,0(a0)
 4d0:	0005c703          	lbu	a4,0(a1)
 4d4:	00e79c63          	bne	a5,a4,4ec <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 4d8:	00150513          	addi	a0,a0,1
    p2++;
 4dc:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 4e0:	fed516e3          	bne	a0,a3,4cc <memcmp+0x20>
  }
  return 0;
 4e4:	00000513          	li	a0,0
 4e8:	0080006f          	j	4f0 <memcmp+0x44>
      return *p1 - *p2;
 4ec:	40e7853b          	subw	a0,a5,a4
}
 4f0:	00813083          	ld	ra,8(sp)
 4f4:	00013403          	ld	s0,0(sp)
 4f8:	01010113          	addi	sp,sp,16
 4fc:	00008067          	ret
  return 0;
 500:	00000513          	li	a0,0
 504:	fedff06f          	j	4f0 <memcmp+0x44>

0000000000000508 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 508:	ff010113          	addi	sp,sp,-16
 50c:	00113423          	sd	ra,8(sp)
 510:	00813023          	sd	s0,0(sp)
 514:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 518:	f11ff0ef          	jal	428 <memmove>
}
 51c:	00813083          	ld	ra,8(sp)
 520:	00013403          	ld	s0,0(sp)
 524:	01010113          	addi	sp,sp,16
 528:	00008067          	ret

000000000000052c <sbrk>:

char *
sbrk(int n) {
 52c:	ff010113          	addi	sp,sp,-16
 530:	00113423          	sd	ra,8(sp)
 534:	00813023          	sd	s0,0(sp)
 538:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 53c:	00100593          	li	a1,1
 540:	114000ef          	jal	654 <sys_sbrk>
}
 544:	00813083          	ld	ra,8(sp)
 548:	00013403          	ld	s0,0(sp)
 54c:	01010113          	addi	sp,sp,16
 550:	00008067          	ret

0000000000000554 <sbrklazy>:

char *
sbrklazy(int n) {
 554:	ff010113          	addi	sp,sp,-16
 558:	00113423          	sd	ra,8(sp)
 55c:	00813023          	sd	s0,0(sp)
 560:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 564:	00200593          	li	a1,2
 568:	0ec000ef          	jal	654 <sys_sbrk>
}
 56c:	00813083          	ld	ra,8(sp)
 570:	00013403          	ld	s0,0(sp)
 574:	01010113          	addi	sp,sp,16
 578:	00008067          	ret

000000000000057c <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 57c:	00100893          	li	a7,1
 ecall
 580:	00000073          	ecall
 ret
 584:	00008067          	ret

0000000000000588 <exit>:
.global exit
exit:
 li a7, SYS_exit
 588:	00200893          	li	a7,2
 ecall
 58c:	00000073          	ecall
 ret
 590:	00008067          	ret

0000000000000594 <wait>:
.global wait
wait:
 li a7, SYS_wait
 594:	00300893          	li	a7,3
 ecall
 598:	00000073          	ecall
 ret
 59c:	00008067          	ret

00000000000005a0 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 5a0:	00400893          	li	a7,4
 ecall
 5a4:	00000073          	ecall
 ret
 5a8:	00008067          	ret

00000000000005ac <read>:
.global read
read:
 li a7, SYS_read
 5ac:	00500893          	li	a7,5
 ecall
 5b0:	00000073          	ecall
 ret
 5b4:	00008067          	ret

00000000000005b8 <write>:
.global write
write:
 li a7, SYS_write
 5b8:	01000893          	li	a7,16
 ecall
 5bc:	00000073          	ecall
 ret
 5c0:	00008067          	ret

00000000000005c4 <close>:
.global close
close:
 li a7, SYS_close
 5c4:	01500893          	li	a7,21
 ecall
 5c8:	00000073          	ecall
 ret
 5cc:	00008067          	ret

00000000000005d0 <kill>:
.global kill
kill:
 li a7, SYS_kill
 5d0:	00600893          	li	a7,6
 ecall
 5d4:	00000073          	ecall
 ret
 5d8:	00008067          	ret

00000000000005dc <exec>:
.global exec
exec:
 li a7, SYS_exec
 5dc:	00700893          	li	a7,7
 ecall
 5e0:	00000073          	ecall
 ret
 5e4:	00008067          	ret

00000000000005e8 <open>:
.global open
open:
 li a7, SYS_open
 5e8:	00f00893          	li	a7,15
 ecall
 5ec:	00000073          	ecall
 ret
 5f0:	00008067          	ret

00000000000005f4 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 5f4:	01100893          	li	a7,17
 ecall
 5f8:	00000073          	ecall
 ret
 5fc:	00008067          	ret

0000000000000600 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 600:	01200893          	li	a7,18
 ecall
 604:	00000073          	ecall
 ret
 608:	00008067          	ret

000000000000060c <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 60c:	00800893          	li	a7,8
 ecall
 610:	00000073          	ecall
 ret
 614:	00008067          	ret

0000000000000618 <link>:
.global link
link:
 li a7, SYS_link
 618:	01300893          	li	a7,19
 ecall
 61c:	00000073          	ecall
 ret
 620:	00008067          	ret

0000000000000624 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 624:	01400893          	li	a7,20
 ecall
 628:	00000073          	ecall
 ret
 62c:	00008067          	ret

0000000000000630 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 630:	00900893          	li	a7,9
 ecall
 634:	00000073          	ecall
 ret
 638:	00008067          	ret

000000000000063c <dup>:
.global dup
dup:
 li a7, SYS_dup
 63c:	00a00893          	li	a7,10
 ecall
 640:	00000073          	ecall
 ret
 644:	00008067          	ret

0000000000000648 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 648:	00b00893          	li	a7,11
 ecall
 64c:	00000073          	ecall
 ret
 650:	00008067          	ret

0000000000000654 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 654:	00c00893          	li	a7,12
 ecall
 658:	00000073          	ecall
 ret
 65c:	00008067          	ret

0000000000000660 <pause>:
.global pause
pause:
 li a7, SYS_pause
 660:	00d00893          	li	a7,13
 ecall
 664:	00000073          	ecall
 ret
 668:	00008067          	ret

000000000000066c <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 66c:	00e00893          	li	a7,14
 ecall
 670:	00000073          	ecall
 ret
 674:	00008067          	ret
