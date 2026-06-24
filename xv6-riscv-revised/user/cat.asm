
user/_cat:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <cat>:

char buf[512];

void
cat(int fd)
{
   0:	fc010113          	addi	sp,sp,-64
   4:	02113c23          	sd	ra,56(sp)
   8:	02813823          	sd	s0,48(sp)
   c:	02913423          	sd	s1,40(sp)
  10:	03213023          	sd	s2,32(sp)
  14:	01313c23          	sd	s3,24(sp)
  18:	01413823          	sd	s4,16(sp)
  1c:	01513423          	sd	s5,8(sp)
  20:	04010413          	addi	s0,sp,64
  24:	00050993          	mv	s3,a0
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
  28:	20000a13          	li	s4,512
  2c:	00001917          	auipc	s2,0x1
  30:	ff490913          	addi	s2,s2,-12 # 1020 <buf>
    if (write(1, buf, n) != n) {
  34:	00100a93          	li	s5,1
  while((n = read(fd, buf, sizeof(buf))) > 0) {
  38:	000a0613          	mv	a2,s4
  3c:	00090593          	mv	a1,s2
  40:	00098513          	mv	a0,s3
  44:	5a0000ef          	jal	5e4 <read>
  48:	00050493          	mv	s1,a0
  4c:	02a05863          	blez	a0,7c <cat+0x7c>
    if (write(1, buf, n) != n) {
  50:	00048613          	mv	a2,s1
  54:	00090593          	mv	a1,s2
  58:	000a8513          	mv	a0,s5
  5c:	594000ef          	jal	5f0 <write>
  60:	fc950ce3          	beq	a0,s1,38 <cat+0x38>
      fprintf(2, "cat: write error\n");
  64:	00001597          	auipc	a1,0x1
  68:	eac58593          	addi	a1,a1,-340 # f10 <malloc+0x16c>
  6c:	00200513          	li	a0,2
  70:	3e5000ef          	jal	c54 <fprintf>
      exit(1);
  74:	00100513          	li	a0,1
  78:	548000ef          	jal	5c0 <exit>
    }
  }
  if(n < 0){
  7c:	02054463          	bltz	a0,a4 <cat+0xa4>
    fprintf(2, "cat: read error\n");
    exit(1);
  }
}
  80:	03813083          	ld	ra,56(sp)
  84:	03013403          	ld	s0,48(sp)
  88:	02813483          	ld	s1,40(sp)
  8c:	02013903          	ld	s2,32(sp)
  90:	01813983          	ld	s3,24(sp)
  94:	01013a03          	ld	s4,16(sp)
  98:	00813a83          	ld	s5,8(sp)
  9c:	04010113          	addi	sp,sp,64
  a0:	00008067          	ret
    fprintf(2, "cat: read error\n");
  a4:	00001597          	auipc	a1,0x1
  a8:	e8458593          	addi	a1,a1,-380 # f28 <malloc+0x184>
  ac:	00200513          	li	a0,2
  b0:	3a5000ef          	jal	c54 <fprintf>
    exit(1);
  b4:	00100513          	li	a0,1
  b8:	508000ef          	jal	5c0 <exit>

00000000000000bc <main>:

int
main(int argc, char *argv[])
{
  bc:	fd010113          	addi	sp,sp,-48
  c0:	02113423          	sd	ra,40(sp)
  c4:	02813023          	sd	s0,32(sp)
  c8:	03010413          	addi	s0,sp,48
  int fd, i;

  if(argc <= 1){
  cc:	00100793          	li	a5,1
  d0:	04a7dc63          	bge	a5,a0,128 <main+0x6c>
  d4:	00913c23          	sd	s1,24(sp)
  d8:	01213823          	sd	s2,16(sp)
  dc:	01313423          	sd	s3,8(sp)
  e0:	00858913          	addi	s2,a1,8
  e4:	ffe5099b          	addiw	s3,a0,-2
  e8:	02099793          	slli	a5,s3,0x20
  ec:	01d7d993          	srli	s3,a5,0x1d
  f0:	01058593          	addi	a1,a1,16
  f4:	00b989b3          	add	s3,s3,a1
    cat(0);
    exit(0);
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], O_RDONLY)) < 0){
  f8:	00000593          	li	a1,0
  fc:	00093503          	ld	a0,0(s2)
 100:	520000ef          	jal	620 <open>
 104:	00050493          	mv	s1,a0
 108:	02054e63          	bltz	a0,144 <main+0x88>
      fprintf(2, "cat: cannot open %s\n", argv[i]);
      exit(1);
    }
    cat(fd);
 10c:	ef5ff0ef          	jal	0 <cat>
    close(fd);
 110:	00048513          	mv	a0,s1
 114:	4e8000ef          	jal	5fc <close>
  for(i = 1; i < argc; i++){
 118:	00890913          	addi	s2,s2,8
 11c:	fd391ee3          	bne	s2,s3,f8 <main+0x3c>
  }
  exit(0);
 120:	00000513          	li	a0,0
 124:	49c000ef          	jal	5c0 <exit>
 128:	00913c23          	sd	s1,24(sp)
 12c:	01213823          	sd	s2,16(sp)
 130:	01313423          	sd	s3,8(sp)
    cat(0);
 134:	00000513          	li	a0,0
 138:	ec9ff0ef          	jal	0 <cat>
    exit(0);
 13c:	00000513          	li	a0,0
 140:	480000ef          	jal	5c0 <exit>
      fprintf(2, "cat: cannot open %s\n", argv[i]);
 144:	00093603          	ld	a2,0(s2)
 148:	00001597          	auipc	a1,0x1
 14c:	df858593          	addi	a1,a1,-520 # f40 <malloc+0x19c>
 150:	00200513          	li	a0,2
 154:	301000ef          	jal	c54 <fprintf>
      exit(1);
 158:	00100513          	li	a0,1
 15c:	464000ef          	jal	5c0 <exit>

0000000000000160 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
 160:	ff010113          	addi	sp,sp,-16
 164:	00113423          	sd	ra,8(sp)
 168:	00813023          	sd	s0,0(sp)
 16c:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
 170:	f4dff0ef          	jal	bc <main>
  exit(r);
 174:	44c000ef          	jal	5c0 <exit>

0000000000000178 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
 178:	ff010113          	addi	sp,sp,-16
 17c:	00113423          	sd	ra,8(sp)
 180:	00813023          	sd	s0,0(sp)
 184:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
 188:	00050793          	mv	a5,a0
 18c:	00158593          	addi	a1,a1,1
 190:	00178793          	addi	a5,a5,1
 194:	fff5c703          	lbu	a4,-1(a1)
 198:	fee78fa3          	sb	a4,-1(a5)
 19c:	fe0718e3          	bnez	a4,18c <strcpy+0x14>
    ;
  return os;
}
 1a0:	00813083          	ld	ra,8(sp)
 1a4:	00013403          	ld	s0,0(sp)
 1a8:	01010113          	addi	sp,sp,16
 1ac:	00008067          	ret

00000000000001b0 <strcmp>:

int
strcmp(const char *p, const char *q)
{
 1b0:	ff010113          	addi	sp,sp,-16
 1b4:	00113423          	sd	ra,8(sp)
 1b8:	00813023          	sd	s0,0(sp)
 1bc:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
 1c0:	00054783          	lbu	a5,0(a0)
 1c4:	00078e63          	beqz	a5,1e0 <strcmp+0x30>
 1c8:	0005c703          	lbu	a4,0(a1)
 1cc:	00f71a63          	bne	a4,a5,1e0 <strcmp+0x30>
    p++, q++;
 1d0:	00150513          	addi	a0,a0,1
 1d4:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
 1d8:	00054783          	lbu	a5,0(a0)
 1dc:	fe0796e3          	bnez	a5,1c8 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
 1e0:	0005c503          	lbu	a0,0(a1)
}
 1e4:	40a7853b          	subw	a0,a5,a0
 1e8:	00813083          	ld	ra,8(sp)
 1ec:	00013403          	ld	s0,0(sp)
 1f0:	01010113          	addi	sp,sp,16
 1f4:	00008067          	ret

00000000000001f8 <strlen>:

uint
strlen(const char *s)
{
 1f8:	ff010113          	addi	sp,sp,-16
 1fc:	00113423          	sd	ra,8(sp)
 200:	00813023          	sd	s0,0(sp)
 204:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
 208:	00054783          	lbu	a5,0(a0)
 20c:	02078663          	beqz	a5,238 <strlen+0x40>
 210:	00150793          	addi	a5,a0,1
 214:	00078693          	mv	a3,a5
 218:	00178793          	addi	a5,a5,1
 21c:	fff7c703          	lbu	a4,-1(a5)
 220:	fe071ae3          	bnez	a4,214 <strlen+0x1c>
 224:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
 228:	00813083          	ld	ra,8(sp)
 22c:	00013403          	ld	s0,0(sp)
 230:	01010113          	addi	sp,sp,16
 234:	00008067          	ret
  for(n = 0; s[n]; n++)
 238:	00000513          	li	a0,0
 23c:	fedff06f          	j	228 <strlen+0x30>

0000000000000240 <memset>:

void*
memset(void *dst, int c, uint n)
{
 240:	ff010113          	addi	sp,sp,-16
 244:	00113423          	sd	ra,8(sp)
 248:	00813023          	sd	s0,0(sp)
 24c:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
 250:	02060063          	beqz	a2,270 <memset+0x30>
 254:	00050793          	mv	a5,a0
 258:	02061613          	slli	a2,a2,0x20
 25c:	02065613          	srli	a2,a2,0x20
 260:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
 264:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
 268:	00178793          	addi	a5,a5,1
 26c:	fee79ce3          	bne	a5,a4,264 <memset+0x24>
  }
  return dst;
}
 270:	00813083          	ld	ra,8(sp)
 274:	00013403          	ld	s0,0(sp)
 278:	01010113          	addi	sp,sp,16
 27c:	00008067          	ret

0000000000000280 <strchr>:

char*
strchr(const char *s, char c)
{
 280:	ff010113          	addi	sp,sp,-16
 284:	00113423          	sd	ra,8(sp)
 288:	00813023          	sd	s0,0(sp)
 28c:	01010413          	addi	s0,sp,16
  for(; *s; s++)
 290:	00054783          	lbu	a5,0(a0)
 294:	02078463          	beqz	a5,2bc <strchr+0x3c>
    if(*s == c)
 298:	00f58a63          	beq	a1,a5,2ac <strchr+0x2c>
  for(; *s; s++)
 29c:	00150513          	addi	a0,a0,1
 2a0:	00054783          	lbu	a5,0(a0)
 2a4:	fe079ae3          	bnez	a5,298 <strchr+0x18>
      return (char*)s;
  return 0;
 2a8:	00000513          	li	a0,0
}
 2ac:	00813083          	ld	ra,8(sp)
 2b0:	00013403          	ld	s0,0(sp)
 2b4:	01010113          	addi	sp,sp,16
 2b8:	00008067          	ret
  return 0;
 2bc:	00000513          	li	a0,0
 2c0:	fedff06f          	j	2ac <strchr+0x2c>

00000000000002c4 <gets>:

char*
gets(char *buf, int max)
{
 2c4:	fa010113          	addi	sp,sp,-96
 2c8:	04113c23          	sd	ra,88(sp)
 2cc:	04813823          	sd	s0,80(sp)
 2d0:	04913423          	sd	s1,72(sp)
 2d4:	05213023          	sd	s2,64(sp)
 2d8:	03313c23          	sd	s3,56(sp)
 2dc:	03413823          	sd	s4,48(sp)
 2e0:	03513423          	sd	s5,40(sp)
 2e4:	03613023          	sd	s6,32(sp)
 2e8:	01713c23          	sd	s7,24(sp)
 2ec:	01813823          	sd	s8,16(sp)
 2f0:	06010413          	addi	s0,sp,96
 2f4:	00050b93          	mv	s7,a0
 2f8:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
 2fc:	00050913          	mv	s2,a0
 300:	00000493          	li	s1,0
    cc = read(0, &c, 1);
 304:	faf40b13          	addi	s6,s0,-81
 308:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
 30c:	00048c13          	mv	s8,s1
 310:	0014899b          	addiw	s3,s1,1
 314:	00098493          	mv	s1,s3
 318:	0349dc63          	bge	s3,s4,350 <gets+0x8c>
    cc = read(0, &c, 1);
 31c:	000a8613          	mv	a2,s5
 320:	000b0593          	mv	a1,s6
 324:	00000513          	li	a0,0
 328:	2bc000ef          	jal	5e4 <read>
    if(cc < 1)
 32c:	02a05263          	blez	a0,350 <gets+0x8c>
      break;
    buf[i++] = c;
 330:	faf44783          	lbu	a5,-81(s0)
 334:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
 338:	00190913          	addi	s2,s2,1
 33c:	ff678713          	addi	a4,a5,-10
 340:	00070663          	beqz	a4,34c <gets+0x88>
 344:	ff378793          	addi	a5,a5,-13
 348:	fc0792e3          	bnez	a5,30c <gets+0x48>
    buf[i++] = c;
 34c:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
 350:	018b8c33          	add	s8,s7,s8
 354:	000c0023          	sb	zero,0(s8)
  return buf;
}
 358:	000b8513          	mv	a0,s7
 35c:	05813083          	ld	ra,88(sp)
 360:	05013403          	ld	s0,80(sp)
 364:	04813483          	ld	s1,72(sp)
 368:	04013903          	ld	s2,64(sp)
 36c:	03813983          	ld	s3,56(sp)
 370:	03013a03          	ld	s4,48(sp)
 374:	02813a83          	ld	s5,40(sp)
 378:	02013b03          	ld	s6,32(sp)
 37c:	01813b83          	ld	s7,24(sp)
 380:	01013c03          	ld	s8,16(sp)
 384:	06010113          	addi	sp,sp,96
 388:	00008067          	ret

000000000000038c <stat>:

int
stat(const char *n, struct stat *st)
{
 38c:	fe010113          	addi	sp,sp,-32
 390:	00113c23          	sd	ra,24(sp)
 394:	00813823          	sd	s0,16(sp)
 398:	01213023          	sd	s2,0(sp)
 39c:	02010413          	addi	s0,sp,32
 3a0:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
 3a4:	00000593          	li	a1,0
 3a8:	278000ef          	jal	620 <open>
  if(fd < 0)
 3ac:	02054e63          	bltz	a0,3e8 <stat+0x5c>
 3b0:	00913423          	sd	s1,8(sp)
 3b4:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
 3b8:	00090593          	mv	a1,s2
 3bc:	288000ef          	jal	644 <fstat>
 3c0:	00050913          	mv	s2,a0
  close(fd);
 3c4:	00048513          	mv	a0,s1
 3c8:	234000ef          	jal	5fc <close>
  return r;
 3cc:	00813483          	ld	s1,8(sp)
}
 3d0:	00090513          	mv	a0,s2
 3d4:	01813083          	ld	ra,24(sp)
 3d8:	01013403          	ld	s0,16(sp)
 3dc:	00013903          	ld	s2,0(sp)
 3e0:	02010113          	addi	sp,sp,32
 3e4:	00008067          	ret
    return -1;
 3e8:	fff00793          	li	a5,-1
 3ec:	00078913          	mv	s2,a5
 3f0:	fe1ff06f          	j	3d0 <stat+0x44>

00000000000003f4 <atoi>:

int
atoi(const char *s)
{
 3f4:	ff010113          	addi	sp,sp,-16
 3f8:	00113423          	sd	ra,8(sp)
 3fc:	00813023          	sd	s0,0(sp)
 400:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
 404:	00054683          	lbu	a3,0(a0)
 408:	fd06879b          	addiw	a5,a3,-48
 40c:	0ff7f793          	zext.b	a5,a5
 410:	00900613          	li	a2,9
 414:	04f66263          	bltu	a2,a5,458 <atoi+0x64>
 418:	00050713          	mv	a4,a0
  n = 0;
 41c:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
 420:	00170713          	addi	a4,a4,1
 424:	0025179b          	slliw	a5,a0,0x2
 428:	00a787bb          	addw	a5,a5,a0
 42c:	0017979b          	slliw	a5,a5,0x1
 430:	00d787bb          	addw	a5,a5,a3
 434:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
 438:	00074683          	lbu	a3,0(a4)
 43c:	fd06879b          	addiw	a5,a3,-48
 440:	0ff7f793          	zext.b	a5,a5
 444:	fcf67ee3          	bgeu	a2,a5,420 <atoi+0x2c>
  return n;
}
 448:	00813083          	ld	ra,8(sp)
 44c:	00013403          	ld	s0,0(sp)
 450:	01010113          	addi	sp,sp,16
 454:	00008067          	ret
  n = 0;
 458:	00000513          	li	a0,0
 45c:	fedff06f          	j	448 <atoi+0x54>

0000000000000460 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
 460:	ff010113          	addi	sp,sp,-16
 464:	00113423          	sd	ra,8(sp)
 468:	00813023          	sd	s0,0(sp)
 46c:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
 470:	02b57e63          	bgeu	a0,a1,4ac <memmove+0x4c>
    while(n-- > 0)
 474:	02c05463          	blez	a2,49c <memmove+0x3c>
 478:	02061613          	slli	a2,a2,0x20
 47c:	02065613          	srli	a2,a2,0x20
 480:	00c507b3          	add	a5,a0,a2
  dst = vdst;
 484:	00050713          	mv	a4,a0
      *dst++ = *src++;
 488:	00158593          	addi	a1,a1,1
 48c:	00170713          	addi	a4,a4,1
 490:	fff5c683          	lbu	a3,-1(a1)
 494:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
 498:	fee798e3          	bne	a5,a4,488 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
 49c:	00813083          	ld	ra,8(sp)
 4a0:	00013403          	ld	s0,0(sp)
 4a4:	01010113          	addi	sp,sp,16
 4a8:	00008067          	ret
    while(n-- > 0)
 4ac:	fec058e3          	blez	a2,49c <memmove+0x3c>
    dst += n;
 4b0:	00c50733          	add	a4,a0,a2
    src += n;
 4b4:	00c585b3          	add	a1,a1,a2
 4b8:	fff6079b          	addiw	a5,a2,-1
 4bc:	02079793          	slli	a5,a5,0x20
 4c0:	0207d793          	srli	a5,a5,0x20
 4c4:	fff7c793          	not	a5,a5
 4c8:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
 4cc:	fff58593          	addi	a1,a1,-1
 4d0:	fff70713          	addi	a4,a4,-1
 4d4:	0005c683          	lbu	a3,0(a1)
 4d8:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
 4dc:	fef718e3          	bne	a4,a5,4cc <memmove+0x6c>
 4e0:	fbdff06f          	j	49c <memmove+0x3c>

00000000000004e4 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
 4e4:	ff010113          	addi	sp,sp,-16
 4e8:	00113423          	sd	ra,8(sp)
 4ec:	00813023          	sd	s0,0(sp)
 4f0:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
 4f4:	04060263          	beqz	a2,538 <memcmp+0x54>
 4f8:	02061613          	slli	a2,a2,0x20
 4fc:	02065613          	srli	a2,a2,0x20
 500:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
 504:	00054783          	lbu	a5,0(a0)
 508:	0005c703          	lbu	a4,0(a1)
 50c:	00e79c63          	bne	a5,a4,524 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
 510:	00150513          	addi	a0,a0,1
    p2++;
 514:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
 518:	fed516e3          	bne	a0,a3,504 <memcmp+0x20>
  }
  return 0;
 51c:	00000513          	li	a0,0
 520:	0080006f          	j	528 <memcmp+0x44>
      return *p1 - *p2;
 524:	40e7853b          	subw	a0,a5,a4
}
 528:	00813083          	ld	ra,8(sp)
 52c:	00013403          	ld	s0,0(sp)
 530:	01010113          	addi	sp,sp,16
 534:	00008067          	ret
  return 0;
 538:	00000513          	li	a0,0
 53c:	fedff06f          	j	528 <memcmp+0x44>

0000000000000540 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
 540:	ff010113          	addi	sp,sp,-16
 544:	00113423          	sd	ra,8(sp)
 548:	00813023          	sd	s0,0(sp)
 54c:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
 550:	f11ff0ef          	jal	460 <memmove>
}
 554:	00813083          	ld	ra,8(sp)
 558:	00013403          	ld	s0,0(sp)
 55c:	01010113          	addi	sp,sp,16
 560:	00008067          	ret

0000000000000564 <sbrk>:

char *
sbrk(int n) {
 564:	ff010113          	addi	sp,sp,-16
 568:	00113423          	sd	ra,8(sp)
 56c:	00813023          	sd	s0,0(sp)
 570:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
 574:	00100593          	li	a1,1
 578:	114000ef          	jal	68c <sys_sbrk>
}
 57c:	00813083          	ld	ra,8(sp)
 580:	00013403          	ld	s0,0(sp)
 584:	01010113          	addi	sp,sp,16
 588:	00008067          	ret

000000000000058c <sbrklazy>:

char *
sbrklazy(int n) {
 58c:	ff010113          	addi	sp,sp,-16
 590:	00113423          	sd	ra,8(sp)
 594:	00813023          	sd	s0,0(sp)
 598:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
 59c:	00200593          	li	a1,2
 5a0:	0ec000ef          	jal	68c <sys_sbrk>
}
 5a4:	00813083          	ld	ra,8(sp)
 5a8:	00013403          	ld	s0,0(sp)
 5ac:	01010113          	addi	sp,sp,16
 5b0:	00008067          	ret

00000000000005b4 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
 5b4:	00100893          	li	a7,1
 ecall
 5b8:	00000073          	ecall
 ret
 5bc:	00008067          	ret

00000000000005c0 <exit>:
.global exit
exit:
 li a7, SYS_exit
 5c0:	00200893          	li	a7,2
 ecall
 5c4:	00000073          	ecall
 ret
 5c8:	00008067          	ret

00000000000005cc <wait>:
.global wait
wait:
 li a7, SYS_wait
 5cc:	00300893          	li	a7,3
 ecall
 5d0:	00000073          	ecall
 ret
 5d4:	00008067          	ret

00000000000005d8 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
 5d8:	00400893          	li	a7,4
 ecall
 5dc:	00000073          	ecall
 ret
 5e0:	00008067          	ret

00000000000005e4 <read>:
.global read
read:
 li a7, SYS_read
 5e4:	00500893          	li	a7,5
 ecall
 5e8:	00000073          	ecall
 ret
 5ec:	00008067          	ret

00000000000005f0 <write>:
.global write
write:
 li a7, SYS_write
 5f0:	01000893          	li	a7,16
 ecall
 5f4:	00000073          	ecall
 ret
 5f8:	00008067          	ret

00000000000005fc <close>:
.global close
close:
 li a7, SYS_close
 5fc:	01500893          	li	a7,21
 ecall
 600:	00000073          	ecall
 ret
 604:	00008067          	ret

0000000000000608 <kill>:
.global kill
kill:
 li a7, SYS_kill
 608:	00600893          	li	a7,6
 ecall
 60c:	00000073          	ecall
 ret
 610:	00008067          	ret

0000000000000614 <exec>:
.global exec
exec:
 li a7, SYS_exec
 614:	00700893          	li	a7,7
 ecall
 618:	00000073          	ecall
 ret
 61c:	00008067          	ret

0000000000000620 <open>:
.global open
open:
 li a7, SYS_open
 620:	00f00893          	li	a7,15
 ecall
 624:	00000073          	ecall
 ret
 628:	00008067          	ret

000000000000062c <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
 62c:	01100893          	li	a7,17
 ecall
 630:	00000073          	ecall
 ret
 634:	00008067          	ret

0000000000000638 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
 638:	01200893          	li	a7,18
 ecall
 63c:	00000073          	ecall
 ret
 640:	00008067          	ret

0000000000000644 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
 644:	00800893          	li	a7,8
 ecall
 648:	00000073          	ecall
 ret
 64c:	00008067          	ret

0000000000000650 <link>:
.global link
link:
 li a7, SYS_link
 650:	01300893          	li	a7,19
 ecall
 654:	00000073          	ecall
 ret
 658:	00008067          	ret

000000000000065c <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
 65c:	01400893          	li	a7,20
 ecall
 660:	00000073          	ecall
 ret
 664:	00008067          	ret

0000000000000668 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
 668:	00900893          	li	a7,9
 ecall
 66c:	00000073          	ecall
 ret
 670:	00008067          	ret

0000000000000674 <dup>:
.global dup
dup:
 li a7, SYS_dup
 674:	00a00893          	li	a7,10
 ecall
 678:	00000073          	ecall
 ret
 67c:	00008067          	ret

0000000000000680 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
 680:	00b00893          	li	a7,11
 ecall
 684:	00000073          	ecall
 ret
 688:	00008067          	ret

000000000000068c <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
 68c:	00c00893          	li	a7,12
 ecall
 690:	00000073          	ecall
 ret
 694:	00008067          	ret

0000000000000698 <pause>:
.global pause
pause:
 li a7, SYS_pause
 698:	00d00893          	li	a7,13
 ecall
 69c:	00000073          	ecall
 ret
 6a0:	00008067          	ret

00000000000006a4 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
 6a4:	00e00893          	li	a7,14
 ecall
 6a8:	00000073          	ecall
 ret
 6ac:	00008067          	ret

00000000000006b0 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
 6b0:	00001617          	auipc	a2,0x1
 6b4:	96062603          	lw	a2,-1696(a2) # 1010 <putc_n>
 6b8:	00c04463          	bgtz	a2,6c0 <putc_flush+0x10>
 6bc:	00008067          	ret
{
 6c0:	ff010113          	addi	sp,sp,-16
 6c4:	00113423          	sd	ra,8(sp)
 6c8:	00813023          	sd	s0,0(sp)
 6cc:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
 6d0:	00001597          	auipc	a1,0x1
 6d4:	b5058593          	addi	a1,a1,-1200 # 1220 <putc_buf>
 6d8:	00001517          	auipc	a0,0x1
 6dc:	92852503          	lw	a0,-1752(a0) # 1000 <putc_fd>
 6e0:	f11ff0ef          	jal	5f0 <write>
    putc_n = 0;
 6e4:	00001797          	auipc	a5,0x1
 6e8:	9207a623          	sw	zero,-1748(a5) # 1010 <putc_n>
  }
}
 6ec:	00813083          	ld	ra,8(sp)
 6f0:	00013403          	ld	s0,0(sp)
 6f4:	01010113          	addi	sp,sp,16
 6f8:	00008067          	ret

00000000000006fc <putc>:

static void
putc(int fd, char c)
{
 6fc:	fe010113          	addi	sp,sp,-32
 700:	00113c23          	sd	ra,24(sp)
 704:	00813823          	sd	s0,16(sp)
 708:	00913423          	sd	s1,8(sp)
 70c:	02010413          	addi	s0,sp,32
 710:	00058493          	mv	s1,a1
  if (putc_fd != fd)
 714:	00001797          	auipc	a5,0x1
 718:	8ec7a783          	lw	a5,-1812(a5) # 1000 <putc_fd>
 71c:	04a79663          	bne	a5,a0,768 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
 720:	00001717          	auipc	a4,0x1
 724:	8f070713          	addi	a4,a4,-1808 # 1010 <putc_n>
 728:	00072683          	lw	a3,0(a4)
 72c:	0016879b          	addiw	a5,a3,1
 730:	00f72023          	sw	a5,0(a4)
 734:	00001717          	auipc	a4,0x1
 738:	aec70713          	addi	a4,a4,-1300 # 1220 <putc_buf>
 73c:	00d70733          	add	a4,a4,a3
 740:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
 744:	ff648493          	addi	s1,s1,-10
 748:	02048e63          	beqz	s1,784 <putc+0x88>
 74c:	f8078793          	addi	a5,a5,-128
 750:	02078a63          	beqz	a5,784 <putc+0x88>
    putc_flush();
}
 754:	01813083          	ld	ra,24(sp)
 758:	01013403          	ld	s0,16(sp)
 75c:	00813483          	ld	s1,8(sp)
 760:	02010113          	addi	sp,sp,32
 764:	00008067          	ret
 768:	01213023          	sd	s2,0(sp)
 76c:	00050913          	mv	s2,a0
    putc_flush();
 770:	f41ff0ef          	jal	6b0 <putc_flush>
    putc_fd = fd;
 774:	00001797          	auipc	a5,0x1
 778:	8927a623          	sw	s2,-1908(a5) # 1000 <putc_fd>
 77c:	00013903          	ld	s2,0(sp)
 780:	fa1ff06f          	j	720 <putc+0x24>
    putc_flush();
 784:	f2dff0ef          	jal	6b0 <putc_flush>
}
 788:	fcdff06f          	j	754 <putc+0x58>

000000000000078c <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
 78c:	fb010113          	addi	sp,sp,-80
 790:	04113423          	sd	ra,72(sp)
 794:	04813023          	sd	s0,64(sp)
 798:	03213823          	sd	s2,48(sp)
 79c:	03313423          	sd	s3,40(sp)
 7a0:	05010413          	addi	s0,sp,80
 7a4:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
 7a8:	0a068e63          	beqz	a3,864 <printint+0xd8>
 7ac:	0a05dc63          	bgez	a1,864 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
 7b0:	40b005b3          	neg	a1,a1
    neg = 1;
 7b4:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
 7b8:	fb840993          	addi	s3,s0,-72
  neg = 0;
 7bc:	00098693          	mv	a3,s3
  i = 0;
 7c0:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
 7c4:	00000817          	auipc	a6,0x0
 7c8:	79c80813          	addi	a6,a6,1948 # f60 <digits>
 7cc:	00070893          	mv	a7,a4
 7d0:	0017051b          	addiw	a0,a4,1
 7d4:	00050713          	mv	a4,a0
 7d8:	02c5f7b3          	remu	a5,a1,a2
 7dc:	00f807b3          	add	a5,a6,a5
 7e0:	0007c783          	lbu	a5,0(a5)
 7e4:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
 7e8:	00058793          	mv	a5,a1
 7ec:	02c5d5b3          	divu	a1,a1,a2
 7f0:	00168693          	addi	a3,a3,1
 7f4:	fcc7fce3          	bgeu	a5,a2,7cc <printint+0x40>
  if (neg)
 7f8:	00030c63          	beqz	t1,810 <printint+0x84>
    buf[i++] = '-';
 7fc:	fd050793          	addi	a5,a0,-48
 800:	00878533          	add	a0,a5,s0
 804:	02d00793          	li	a5,45
 808:	fef50423          	sb	a5,-24(a0)
 80c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
 810:	02e05e63          	blez	a4,84c <printint+0xc0>
 814:	02913c23          	sd	s1,56(sp)
 818:	fff7071b          	addiw	a4,a4,-1
 81c:	00e984b3          	add	s1,s3,a4
 820:	fff98993          	addi	s3,s3,-1
 824:	00e989b3          	add	s3,s3,a4
 828:	02071713          	slli	a4,a4,0x20
 82c:	02075713          	srli	a4,a4,0x20
 830:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 834:	0004c583          	lbu	a1,0(s1)
 838:	00090513          	mv	a0,s2
 83c:	ec1ff0ef          	jal	6fc <putc>
  while (--i >= 0)
 840:	fff48493          	addi	s1,s1,-1
 844:	ff3498e3          	bne	s1,s3,834 <printint+0xa8>
 848:	03813483          	ld	s1,56(sp)
}
 84c:	04813083          	ld	ra,72(sp)
 850:	04013403          	ld	s0,64(sp)
 854:	03013903          	ld	s2,48(sp)
 858:	02813983          	ld	s3,40(sp)
 85c:	05010113          	addi	sp,sp,80
 860:	00008067          	ret
  neg = 0;
 864:	00000313          	li	t1,0
 868:	f51ff06f          	j	7b8 <printint+0x2c>

000000000000086c <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
 86c:	fa010113          	addi	sp,sp,-96
 870:	04113c23          	sd	ra,88(sp)
 874:	04813823          	sd	s0,80(sp)
 878:	04913423          	sd	s1,72(sp)
 87c:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
 880:	0005c483          	lbu	s1,0(a1)
 884:	32048263          	beqz	s1,ba8 <vprintf+0x33c>
 888:	05213023          	sd	s2,64(sp)
 88c:	03313c23          	sd	s3,56(sp)
 890:	03413823          	sd	s4,48(sp)
 894:	03513423          	sd	s5,40(sp)
 898:	03613023          	sd	s6,32(sp)
 89c:	01713c23          	sd	s7,24(sp)
 8a0:	01813823          	sd	s8,16(sp)
 8a4:	00050b13          	mv	s6,a0
 8a8:	00058a13          	mv	s4,a1
 8ac:	00060b93          	mv	s7,a2
  state = 0;
 8b0:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
 8b4:	00000913          	li	s2,0
 8b8:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
 8bc:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
 8c0:	06400c13          	li	s8,100
 8c4:	0300006f          	j	8f4 <vprintf+0x88>
        putc(fd, c0);
 8c8:	00048593          	mv	a1,s1
 8cc:	000b0513          	mv	a0,s6
 8d0:	e2dff0ef          	jal	6fc <putc>
 8d4:	0080006f          	j	8dc <vprintf+0x70>
    else if (state == '%')
 8d8:	03598863          	beq	s3,s5,908 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
 8dc:	0019079b          	addiw	a5,s2,1
 8e0:	00078913          	mv	s2,a5
 8e4:	00078713          	mv	a4,a5
 8e8:	00fa07b3          	add	a5,s4,a5
 8ec:	0007c483          	lbu	s1,0(a5)
 8f0:	28048e63          	beqz	s1,b8c <vprintf+0x320>
    c0 = fmt[i] & 0xff;
 8f4:	0004879b          	sext.w	a5,s1
    if (state == 0)
 8f8:	fe0990e3          	bnez	s3,8d8 <vprintf+0x6c>
      if (c0 == '%')
 8fc:	fd5796e3          	bne	a5,s5,8c8 <vprintf+0x5c>
        state = '%';
 900:	00078993          	mv	s3,a5
 904:	fd9ff06f          	j	8dc <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
 908:	00ea06b3          	add	a3,s4,a4
 90c:	0016c603          	lbu	a2,1(a3)
      if (c1)
 910:	2a060663          	beqz	a2,bbc <vprintf+0x350>
      if (c0 == 'd')
 914:	05878063          	beq	a5,s8,954 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
 918:	f9478693          	addi	a3,a5,-108
 91c:	0016b693          	seqz	a3,a3
 920:	f9c60593          	addi	a1,a2,-100
 924:	04059a63          	bnez	a1,978 <vprintf+0x10c>
 928:	04068863          	beqz	a3,978 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
 92c:	008b8493          	addi	s1,s7,8
 930:	00100693          	li	a3,1
 934:	00a00613          	li	a2,10
 938:	000bb583          	ld	a1,0(s7)
 93c:	000b0513          	mv	a0,s6
 940:	e4dff0ef          	jal	78c <printint>
        i += 1;
 944:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
 948:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
 94c:	00000993          	li	s3,0
 950:	f8dff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
 954:	008b8493          	addi	s1,s7,8
 958:	00100693          	li	a3,1
 95c:	00a00613          	li	a2,10
 960:	000ba583          	lw	a1,0(s7)
 964:	000b0513          	mv	a0,s6
 968:	e25ff0ef          	jal	78c <printint>
 96c:	00048b93          	mv	s7,s1
      state = 0;
 970:	00000993          	li	s3,0
 974:	f69ff06f          	j	8dc <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
 978:	00ea0733          	add	a4,s4,a4
 97c:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 980:	f9460713          	addi	a4,a2,-108
 984:	00173713          	seqz	a4,a4
 988:	00e6f733          	and	a4,a3,a4
 98c:	f9c58513          	addi	a0,a1,-100
 990:	24051263          	bnez	a0,bd4 <vprintf+0x368>
 994:	24070063          	beqz	a4,bd4 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
 998:	008b8493          	addi	s1,s7,8
 99c:	00100693          	li	a3,1
 9a0:	00a00613          	li	a2,10
 9a4:	000bb583          	ld	a1,0(s7)
 9a8:	000b0513          	mv	a0,s6
 9ac:	de1ff0ef          	jal	78c <printint>
        i += 2;
 9b0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
 9b4:	00048b93          	mv	s7,s1
      state = 0;
 9b8:	00000993          	li	s3,0
        i += 2;
 9bc:	f21ff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
 9c0:	008b8493          	addi	s1,s7,8
 9c4:	00000693          	li	a3,0
 9c8:	00a00613          	li	a2,10
 9cc:	000be583          	lwu	a1,0(s7)
 9d0:	000b0513          	mv	a0,s6
 9d4:	db9ff0ef          	jal	78c <printint>
 9d8:	00048b93          	mv	s7,s1
      state = 0;
 9dc:	00000993          	li	s3,0
 9e0:	efdff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 9e4:	008b8493          	addi	s1,s7,8
 9e8:	00000693          	li	a3,0
 9ec:	00a00613          	li	a2,10
 9f0:	000bb583          	ld	a1,0(s7)
 9f4:	000b0513          	mv	a0,s6
 9f8:	d95ff0ef          	jal	78c <printint>
        i += 1;
 9fc:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
 a00:	00048b93          	mv	s7,s1
      state = 0;
 a04:	00000993          	li	s3,0
 a08:	ed5ff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
 a0c:	008b8493          	addi	s1,s7,8
 a10:	00000693          	li	a3,0
 a14:	00a00613          	li	a2,10
 a18:	000bb583          	ld	a1,0(s7)
 a1c:	000b0513          	mv	a0,s6
 a20:	d6dff0ef          	jal	78c <printint>
        i += 2;
 a24:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
 a28:	00048b93          	mv	s7,s1
      state = 0;
 a2c:	00000993          	li	s3,0
        i += 2;
 a30:	eadff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
 a34:	008b8493          	addi	s1,s7,8
 a38:	00000693          	li	a3,0
 a3c:	01000613          	li	a2,16
 a40:	000be583          	lwu	a1,0(s7)
 a44:	000b0513          	mv	a0,s6
 a48:	d45ff0ef          	jal	78c <printint>
 a4c:	00048b93          	mv	s7,s1
      state = 0;
 a50:	00000993          	li	s3,0
 a54:	e89ff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a58:	008b8493          	addi	s1,s7,8
 a5c:	00000693          	li	a3,0
 a60:	01000613          	li	a2,16
 a64:	000bb583          	ld	a1,0(s7)
 a68:	000b0513          	mv	a0,s6
 a6c:	d21ff0ef          	jal	78c <printint>
        i += 1;
 a70:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
 a74:	00048b93          	mv	s7,s1
      state = 0;
 a78:	00000993          	li	s3,0
 a7c:	e61ff06f          	j	8dc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
 a80:	008b8493          	addi	s1,s7,8
 a84:	00000693          	li	a3,0
 a88:	01000613          	li	a2,16
 a8c:	000bb583          	ld	a1,0(s7)
 a90:	000b0513          	mv	a0,s6
 a94:	cf9ff0ef          	jal	78c <printint>
        i += 2;
 a98:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
 a9c:	00048b93          	mv	s7,s1
      state = 0;
 aa0:	00000993          	li	s3,0
        i += 2;
 aa4:	e39ff06f          	j	8dc <vprintf+0x70>
 aa8:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
 aac:	008b8793          	addi	a5,s7,8
 ab0:	00078c93          	mv	s9,a5
 ab4:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 ab8:	03000593          	li	a1,48
 abc:	000b0513          	mv	a0,s6
 ac0:	c3dff0ef          	jal	6fc <putc>
  putc(fd, 'x');
 ac4:	07800593          	li	a1,120
 ac8:	000b0513          	mv	a0,s6
 acc:	c31ff0ef          	jal	6fc <putc>
 ad0:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 ad4:	00000b97          	auipc	s7,0x0
 ad8:	48cb8b93          	addi	s7,s7,1164 # f60 <digits>
 adc:	03c9d793          	srli	a5,s3,0x3c
 ae0:	00fb87b3          	add	a5,s7,a5
 ae4:	0007c583          	lbu	a1,0(a5)
 ae8:	000b0513          	mv	a0,s6
 aec:	c11ff0ef          	jal	6fc <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 af0:	00499993          	slli	s3,s3,0x4
 af4:	fff4849b          	addiw	s1,s1,-1
 af8:	fe0492e3          	bnez	s1,adc <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
 afc:	000c8b93          	mv	s7,s9
      state = 0;
 b00:	00000993          	li	s3,0
 b04:	00813c83          	ld	s9,8(sp)
 b08:	dd5ff06f          	j	8dc <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
 b0c:	008b8493          	addi	s1,s7,8
 b10:	000bc583          	lbu	a1,0(s7)
 b14:	000b0513          	mv	a0,s6
 b18:	be5ff0ef          	jal	6fc <putc>
 b1c:	00048b93          	mv	s7,s1
      state = 0;
 b20:	00000993          	li	s3,0
 b24:	db9ff06f          	j	8dc <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b28:	008b8993          	addi	s3,s7,8
 b2c:	000bb483          	ld	s1,0(s7)
 b30:	02048663          	beqz	s1,b5c <vprintf+0x2f0>
        for (; *s; s++)
 b34:	0004c583          	lbu	a1,0(s1)
 b38:	04058463          	beqz	a1,b80 <vprintf+0x314>
          putc(fd, *s);
 b3c:	000b0513          	mv	a0,s6
 b40:	bbdff0ef          	jal	6fc <putc>
        for (; *s; s++)
 b44:	00148493          	addi	s1,s1,1
 b48:	0004c583          	lbu	a1,0(s1)
 b4c:	fe0598e3          	bnez	a1,b3c <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
 b50:	00098b93          	mv	s7,s3
      state = 0;
 b54:	00000993          	li	s3,0
 b58:	d85ff06f          	j	8dc <vprintf+0x70>
          s = "(null)";
 b5c:	00000497          	auipc	s1,0x0
 b60:	3fc48493          	addi	s1,s1,1020 # f58 <malloc+0x1b4>
        for (; *s; s++)
 b64:	02800593          	li	a1,40
 b68:	fd5ff06f          	j	b3c <vprintf+0x2d0>
        putc(fd, '%');
 b6c:	00078593          	mv	a1,a5
 b70:	000b0513          	mv	a0,s6
 b74:	b89ff0ef          	jal	6fc <putc>
      state = 0;
 b78:	00000993          	li	s3,0
 b7c:	d61ff06f          	j	8dc <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
 b80:	00098b93          	mv	s7,s3
      state = 0;
 b84:	00000993          	li	s3,0
 b88:	d55ff06f          	j	8dc <vprintf+0x70>
 b8c:	04013903          	ld	s2,64(sp)
 b90:	03813983          	ld	s3,56(sp)
 b94:	03013a03          	ld	s4,48(sp)
 b98:	02813a83          	ld	s5,40(sp)
 b9c:	02013b03          	ld	s6,32(sp)
 ba0:	01813b83          	ld	s7,24(sp)
 ba4:	01013c03          	ld	s8,16(sp)
    }
  }
}
 ba8:	05813083          	ld	ra,88(sp)
 bac:	05013403          	ld	s0,80(sp)
 bb0:	04813483          	ld	s1,72(sp)
 bb4:	06010113          	addi	sp,sp,96
 bb8:	00008067          	ret
      if (c0 == 'd')
 bbc:	06400713          	li	a4,100
 bc0:	d8e78ae3          	beq	a5,a4,954 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
 bc4:	f9478693          	addi	a3,a5,-108
 bc8:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
 bcc:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
 bd0:	00000713          	li	a4,0
      else if (c0 == 'u')
 bd4:	07500513          	li	a0,117
 bd8:	dea784e3          	beq	a5,a0,9c0 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
 bdc:	f8b60513          	addi	a0,a2,-117
 be0:	00051463          	bnez	a0,be8 <vprintf+0x37c>
 be4:	e00690e3          	bnez	a3,9e4 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
 be8:	f8b58513          	addi	a0,a1,-117
 bec:	00051463          	bnez	a0,bf4 <vprintf+0x388>
 bf0:	e0071ee3          	bnez	a4,a0c <vprintf+0x1a0>
      else if (c0 == 'x')
 bf4:	07800513          	li	a0,120
 bf8:	e2a78ee3          	beq	a5,a0,a34 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
 bfc:	f8860613          	addi	a2,a2,-120
 c00:	00061463          	bnez	a2,c08 <vprintf+0x39c>
 c04:	e4069ae3          	bnez	a3,a58 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
 c08:	f8858593          	addi	a1,a1,-120
 c0c:	00059463          	bnez	a1,c14 <vprintf+0x3a8>
 c10:	e60718e3          	bnez	a4,a80 <vprintf+0x214>
      else if (c0 == 'p')
 c14:	07000713          	li	a4,112
 c18:	e8e788e3          	beq	a5,a4,aa8 <vprintf+0x23c>
      else if (c0 == 'c')
 c1c:	06300713          	li	a4,99
 c20:	eee786e3          	beq	a5,a4,b0c <vprintf+0x2a0>
      else if (c0 == 's')
 c24:	07300713          	li	a4,115
 c28:	f0e780e3          	beq	a5,a4,b28 <vprintf+0x2bc>
      else if (c0 == '%')
 c2c:	02500713          	li	a4,37
 c30:	f2e78ee3          	beq	a5,a4,b6c <vprintf+0x300>
        putc(fd, '%');
 c34:	02500593          	li	a1,37
 c38:	000b0513          	mv	a0,s6
 c3c:	ac1ff0ef          	jal	6fc <putc>
        putc(fd, c0);
 c40:	00048593          	mv	a1,s1
 c44:	000b0513          	mv	a0,s6
 c48:	ab5ff0ef          	jal	6fc <putc>
      state = 0;
 c4c:	00000993          	li	s3,0
 c50:	c8dff06f          	j	8dc <vprintf+0x70>

0000000000000c54 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
 c54:	fb010113          	addi	sp,sp,-80
 c58:	00113c23          	sd	ra,24(sp)
 c5c:	00813823          	sd	s0,16(sp)
 c60:	02010413          	addi	s0,sp,32
 c64:	00c43023          	sd	a2,0(s0)
 c68:	00d43423          	sd	a3,8(s0)
 c6c:	00e43823          	sd	a4,16(s0)
 c70:	00f43c23          	sd	a5,24(s0)
 c74:	03043023          	sd	a6,32(s0)
 c78:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 c7c:	00040613          	mv	a2,s0
 c80:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 c84:	be9ff0ef          	jal	86c <vprintf>
}
 c88:	01813083          	ld	ra,24(sp)
 c8c:	01013403          	ld	s0,16(sp)
 c90:	05010113          	addi	sp,sp,80
 c94:	00008067          	ret

0000000000000c98 <printf>:

void printf(const char *fmt, ...)
{
 c98:	fa010113          	addi	sp,sp,-96
 c9c:	00113c23          	sd	ra,24(sp)
 ca0:	00813823          	sd	s0,16(sp)
 ca4:	02010413          	addi	s0,sp,32
 ca8:	00b43423          	sd	a1,8(s0)
 cac:	00c43823          	sd	a2,16(s0)
 cb0:	00d43c23          	sd	a3,24(s0)
 cb4:	02e43023          	sd	a4,32(s0)
 cb8:	02f43423          	sd	a5,40(s0)
 cbc:	03043823          	sd	a6,48(s0)
 cc0:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 cc4:	00840613          	addi	a2,s0,8
 cc8:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 ccc:	00050593          	mv	a1,a0
 cd0:	00100513          	li	a0,1
 cd4:	b99ff0ef          	jal	86c <vprintf>
  putc_flush();
 cd8:	9d9ff0ef          	jal	6b0 <putc_flush>
}
 cdc:	01813083          	ld	ra,24(sp)
 ce0:	01013403          	ld	s0,16(sp)
 ce4:	06010113          	addi	sp,sp,96
 ce8:	00008067          	ret

0000000000000cec <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
 cec:	ff010113          	addi	sp,sp,-16
 cf0:	00113423          	sd	ra,8(sp)
 cf4:	00813023          	sd	s0,0(sp)
 cf8:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
 cfc:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 d00:	00000797          	auipc	a5,0x0
 d04:	3187b783          	ld	a5,792(a5) # 1018 <freep>
 d08:	0140006f          	j	d1c <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 d0c:	0007b703          	ld	a4,0(a5)
 d10:	00e7e463          	bltu	a5,a4,d18 <free+0x2c>
 d14:	00e6ec63          	bltu	a3,a4,d2c <free+0x40>
{
 d18:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
 d1c:	fed7f8e3          	bgeu	a5,a3,d0c <free+0x20>
 d20:	0007b703          	ld	a4,0(a5)
 d24:	00e6e463          	bltu	a3,a4,d2c <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
 d28:	fee7e8e3          	bltu	a5,a4,d18 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
 d2c:	ff852583          	lw	a1,-8(a0)
 d30:	0007b603          	ld	a2,0(a5)
 d34:	02059813          	slli	a6,a1,0x20
 d38:	01c85713          	srli	a4,a6,0x1c
 d3c:	00e68733          	add	a4,a3,a4
 d40:	02e60c63          	beq	a2,a4,d78 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
 d44:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
 d48:	0087a603          	lw	a2,8(a5)
 d4c:	02061593          	slli	a1,a2,0x20
 d50:	01c5d713          	srli	a4,a1,0x1c
 d54:	00e78733          	add	a4,a5,a4
 d58:	02e68c63          	beq	a3,a4,d90 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
 d5c:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
 d60:	00000717          	auipc	a4,0x0
 d64:	2af73c23          	sd	a5,696(a4) # 1018 <freep>
}
 d68:	00813083          	ld	ra,8(sp)
 d6c:	00013403          	ld	s0,0(sp)
 d70:	01010113          	addi	sp,sp,16
 d74:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
 d78:	00862703          	lw	a4,8(a2)
 d7c:	00b7073b          	addw	a4,a4,a1
 d80:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
 d84:	0007b703          	ld	a4,0(a5)
 d88:	00073603          	ld	a2,0(a4)
 d8c:	fb9ff06f          	j	d44 <free+0x58>
    p->s.size += bp->s.size;
 d90:	ff852703          	lw	a4,-8(a0)
 d94:	00c7073b          	addw	a4,a4,a2
 d98:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
 d9c:	ff053683          	ld	a3,-16(a0)
 da0:	fbdff06f          	j	d5c <free+0x70>

0000000000000da4 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
 da4:	fc010113          	addi	sp,sp,-64
 da8:	02113c23          	sd	ra,56(sp)
 dac:	02813823          	sd	s0,48(sp)
 db0:	03213023          	sd	s2,32(sp)
 db4:	01313c23          	sd	s3,24(sp)
 db8:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
 dbc:	02051993          	slli	s3,a0,0x20
 dc0:	0209d993          	srli	s3,s3,0x20
 dc4:	00f98993          	addi	s3,s3,15
 dc8:	0049d993          	srli	s3,s3,0x4
 dcc:	0019899b          	addiw	s3,s3,1
 dd0:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
 dd4:	00000517          	auipc	a0,0x0
 dd8:	24453503          	ld	a0,580(a0) # 1018 <freep>
 ddc:	04050463          	beqz	a0,e24 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 de0:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 de4:	0087a703          	lw	a4,8(a5)
 de8:	0d377a63          	bgeu	a4,s3,ebc <malloc+0x118>
 dec:	02913423          	sd	s1,40(sp)
 df0:	01413823          	sd	s4,16(sp)
 df4:	01513423          	sd	s5,8(sp)
 df8:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
 dfc:	00098a13          	mv	s4,s3
 e00:	00001737          	lui	a4,0x1
 e04:	00e9f463          	bgeu	s3,a4,e0c <malloc+0x68>
 e08:	00001a37          	lui	s4,0x1
 e0c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
 e10:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
 e14:	00000497          	auipc	s1,0x0
 e18:	20448493          	addi	s1,s1,516 # 1018 <freep>
  if(p == SBRK_ERROR)
 e1c:	fff00a93          	li	s5,-1
 e20:	05c0006f          	j	e7c <malloc+0xd8>
 e24:	02913423          	sd	s1,40(sp)
 e28:	01413823          	sd	s4,16(sp)
 e2c:	01513423          	sd	s5,8(sp)
 e30:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
 e34:	00000797          	auipc	a5,0x0
 e38:	46c78793          	addi	a5,a5,1132 # 12a0 <base>
 e3c:	00000717          	auipc	a4,0x0
 e40:	1cf73e23          	sd	a5,476(a4) # 1018 <freep>
 e44:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
 e48:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
 e4c:	fb1ff06f          	j	dfc <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
 e50:	0007b703          	ld	a4,0(a5)
 e54:	00e53023          	sd	a4,0(a0)
 e58:	0800006f          	j	ed8 <malloc+0x134>
  hp->s.size = nu;
 e5c:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
 e60:	01050513          	addi	a0,a0,16
 e64:	e89ff0ef          	jal	cec <free>
  return freep;
 e68:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
 e6c:	08050863          	beqz	a0,efc <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
 e70:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
 e74:	0087a703          	lw	a4,8(a5)
 e78:	03277a63          	bgeu	a4,s2,eac <malloc+0x108>
    if(p == freep)
 e7c:	0004b703          	ld	a4,0(s1)
 e80:	00078513          	mv	a0,a5
 e84:	fef716e3          	bne	a4,a5,e70 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
 e88:	000a0513          	mv	a0,s4
 e8c:	ed8ff0ef          	jal	564 <sbrk>
  if(p == SBRK_ERROR)
 e90:	fd5516e3          	bne	a0,s5,e5c <malloc+0xb8>
        return 0;
 e94:	00000513          	li	a0,0
 e98:	02813483          	ld	s1,40(sp)
 e9c:	01013a03          	ld	s4,16(sp)
 ea0:	00813a83          	ld	s5,8(sp)
 ea4:	00013b03          	ld	s6,0(sp)
 ea8:	03c0006f          	j	ee4 <malloc+0x140>
 eac:	02813483          	ld	s1,40(sp)
 eb0:	01013a03          	ld	s4,16(sp)
 eb4:	00813a83          	ld	s5,8(sp)
 eb8:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
 ebc:	f8e90ae3          	beq	s2,a4,e50 <malloc+0xac>
        p->s.size -= nunits;
 ec0:	4137073b          	subw	a4,a4,s3
 ec4:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
 ec8:	02071693          	slli	a3,a4,0x20
 ecc:	01c6d713          	srli	a4,a3,0x1c
 ed0:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
 ed4:	0137a423          	sw	s3,8(a5)
      freep = prevp;
 ed8:	00000717          	auipc	a4,0x0
 edc:	14a73023          	sd	a0,320(a4) # 1018 <freep>
      return (void*)(p + 1);
 ee0:	01078513          	addi	a0,a5,16
  }
}
 ee4:	03813083          	ld	ra,56(sp)
 ee8:	03013403          	ld	s0,48(sp)
 eec:	02013903          	ld	s2,32(sp)
 ef0:	01813983          	ld	s3,24(sp)
 ef4:	04010113          	addi	sp,sp,64
 ef8:	00008067          	ret
 efc:	02813483          	ld	s1,40(sp)
 f00:	01013a03          	ld	s4,16(sp)
 f04:	00813a83          	ld	s5,8(sp)
 f08:	00013b03          	ld	s6,0(sp)
 f0c:	fd9ff06f          	j	ee4 <malloc+0x140>
