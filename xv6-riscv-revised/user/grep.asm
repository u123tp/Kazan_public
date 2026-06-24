
user/_grep:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <matchstar>:
  return 0;
}

// matchstar: search for c*re at beginning of text
int matchstar(int c, char *re, char *text)
{
       0:	fd010113          	addi	sp,sp,-48
       4:	02113423          	sd	ra,40(sp)
       8:	02813023          	sd	s0,32(sp)
       c:	00913c23          	sd	s1,24(sp)
      10:	01213823          	sd	s2,16(sp)
      14:	01313423          	sd	s3,8(sp)
      18:	01413023          	sd	s4,0(sp)
      1c:	03010413          	addi	s0,sp,48
      20:	00050913          	mv	s2,a0
      24:	00058993          	mv	s3,a1
      28:	00060493          	mv	s1,a2
  do{  // a * matches zero or more instances
    if(matchhere(re, text))
      return 1;
  }while(*text!='\0' && (*text++==c || c=='.'));
      2c:	fd250a13          	addi	s4,a0,-46
      30:	001a3a13          	seqz	s4,s4
    if(matchhere(re, text))
      34:	00048593          	mv	a1,s1
      38:	00098513          	mv	a0,s3
      3c:	044000ef          	jal	80 <matchhere>
      40:	00051e63          	bnez	a0,5c <matchstar+0x5c>
  }while(*text!='\0' && (*text++==c || c=='.'));
      44:	0004c783          	lbu	a5,0(s1)
      48:	00078c63          	beqz	a5,60 <matchstar+0x60>
      4c:	00148493          	addi	s1,s1,1
      50:	ff2782e3          	beq	a5,s2,34 <matchstar+0x34>
      54:	fe0a10e3          	bnez	s4,34 <matchstar+0x34>
      58:	0080006f          	j	60 <matchstar+0x60>
      return 1;
      5c:	00100513          	li	a0,1
  return 0;
}
      60:	02813083          	ld	ra,40(sp)
      64:	02013403          	ld	s0,32(sp)
      68:	01813483          	ld	s1,24(sp)
      6c:	01013903          	ld	s2,16(sp)
      70:	00813983          	ld	s3,8(sp)
      74:	00013a03          	ld	s4,0(sp)
      78:	03010113          	addi	sp,sp,48
      7c:	00008067          	ret

0000000000000080 <matchhere>:
  if(re[0] == '\0')
      80:	00054703          	lbu	a4,0(a0)
      84:	08070463          	beqz	a4,10c <matchhere+0x8c>
{
      88:	ff010113          	addi	sp,sp,-16
      8c:	00113423          	sd	ra,8(sp)
      90:	00813023          	sd	s0,0(sp)
      94:	01010413          	addi	s0,sp,16
      98:	00050793          	mv	a5,a0
  if(re[1] == '*')
      9c:	00154683          	lbu	a3,1(a0)
      a0:	02a00613          	li	a2,42
      a4:	02c68c63          	beq	a3,a2,dc <matchhere+0x5c>
  if(re[0] == '$' && re[1] == '\0')
      a8:	00069663          	bnez	a3,b4 <matchhere+0x34>
      ac:	fdc70693          	addi	a3,a4,-36
      b0:	04068063          	beqz	a3,f0 <matchhere+0x70>
  if(*text!='\0' && (re[0]=='.' || re[0]==*text))
      b4:	0005c683          	lbu	a3,0(a1)
  return 0;
      b8:	00000513          	li	a0,0
  if(*text!='\0' && (re[0]=='.' || re[0]==*text))
      bc:	00068863          	beqz	a3,cc <matchhere+0x4c>
      c0:	02d70e63          	beq	a4,a3,fc <matchhere+0x7c>
      c4:	fd270713          	addi	a4,a4,-46
      c8:	02070a63          	beqz	a4,fc <matchhere+0x7c>
}
      cc:	00813083          	ld	ra,8(sp)
      d0:	00013403          	ld	s0,0(sp)
      d4:	01010113          	addi	sp,sp,16
      d8:	00008067          	ret
    return matchstar(re[0], re+2, text);
      dc:	00058613          	mv	a2,a1
      e0:	00250593          	addi	a1,a0,2
      e4:	00070513          	mv	a0,a4
      e8:	f19ff0ef          	jal	0 <matchstar>
      ec:	fe1ff06f          	j	cc <matchhere+0x4c>
    return *text == '\0';
      f0:	0005c503          	lbu	a0,0(a1)
      f4:	00153513          	seqz	a0,a0
      f8:	fd5ff06f          	j	cc <matchhere+0x4c>
    return matchhere(re+1, text+1);
      fc:	00158593          	addi	a1,a1,1
     100:	00178513          	addi	a0,a5,1
     104:	f7dff0ef          	jal	80 <matchhere>
     108:	fc5ff06f          	j	cc <matchhere+0x4c>
    return 1;
     10c:	00100513          	li	a0,1
}
     110:	00008067          	ret

0000000000000114 <match>:
{
     114:	fe010113          	addi	sp,sp,-32
     118:	00113c23          	sd	ra,24(sp)
     11c:	00813823          	sd	s0,16(sp)
     120:	00913423          	sd	s1,8(sp)
     124:	01213023          	sd	s2,0(sp)
     128:	02010413          	addi	s0,sp,32
     12c:	00050913          	mv	s2,a0
     130:	00058493          	mv	s1,a1
  if(re[0] == '^')
     134:	00054703          	lbu	a4,0(a0)
     138:	05e00793          	li	a5,94
     13c:	02f70263          	beq	a4,a5,160 <match+0x4c>
    if(matchhere(re, text))
     140:	00048593          	mv	a1,s1
     144:	00090513          	mv	a0,s2
     148:	f39ff0ef          	jal	80 <matchhere>
     14c:	02051063          	bnez	a0,16c <match+0x58>
  }while(*text++ != '\0');
     150:	00148493          	addi	s1,s1,1
     154:	fff4c783          	lbu	a5,-1(s1)
     158:	fe0794e3          	bnez	a5,140 <match+0x2c>
     15c:	0140006f          	j	170 <match+0x5c>
    return matchhere(re+1, text);
     160:	00150513          	addi	a0,a0,1
     164:	f1dff0ef          	jal	80 <matchhere>
     168:	0080006f          	j	170 <match+0x5c>
      return 1;
     16c:	00100513          	li	a0,1
}
     170:	01813083          	ld	ra,24(sp)
     174:	01013403          	ld	s0,16(sp)
     178:	00813483          	ld	s1,8(sp)
     17c:	00013903          	ld	s2,0(sp)
     180:	02010113          	addi	sp,sp,32
     184:	00008067          	ret

0000000000000188 <grep>:
{
     188:	fa010113          	addi	sp,sp,-96
     18c:	04113c23          	sd	ra,88(sp)
     190:	04813823          	sd	s0,80(sp)
     194:	04913423          	sd	s1,72(sp)
     198:	05213023          	sd	s2,64(sp)
     19c:	03313c23          	sd	s3,56(sp)
     1a0:	03413823          	sd	s4,48(sp)
     1a4:	03513423          	sd	s5,40(sp)
     1a8:	03613023          	sd	s6,32(sp)
     1ac:	01713c23          	sd	s7,24(sp)
     1b0:	01813823          	sd	s8,16(sp)
     1b4:	01913423          	sd	s9,8(sp)
     1b8:	01a13023          	sd	s10,0(sp)
     1bc:	06010413          	addi	s0,sp,96
     1c0:	00050a93          	mv	s5,a0
     1c4:	00058c93          	mv	s9,a1
  m = 0;
     1c8:	00000b13          	li	s6,0
  while((n = read(fd, buf+m, sizeof(buf)-m-1)) > 0){
     1cc:	3ff00d13          	li	s10,1023
     1d0:	00002b97          	auipc	s7,0x2
     1d4:	e50b8b93          	addi	s7,s7,-432 # 2020 <buf>
    while((q = strchr(p, '\n')) != 0){
     1d8:	00a00993          	li	s3,10
        write(1, p, q+1 - p);
     1dc:	00100c13          	li	s8,1
  while((n = read(fd, buf+m, sizeof(buf)-m-1)) > 0){
     1e0:	0500006f          	j	230 <grep+0xa8>
      p = q+1;
     1e4:	00148913          	addi	s2,s1,1
    while((q = strchr(p, '\n')) != 0){
     1e8:	00098593          	mv	a1,s3
     1ec:	00090513          	mv	a0,s2
     1f0:	2b4000ef          	jal	4a4 <strchr>
     1f4:	00050493          	mv	s1,a0
     1f8:	02050a63          	beqz	a0,22c <grep+0xa4>
      *q = 0;
     1fc:	00048023          	sb	zero,0(s1)
      if(match(pattern, p)){
     200:	00090593          	mv	a1,s2
     204:	000a8513          	mv	a0,s5
     208:	f0dff0ef          	jal	114 <match>
     20c:	fc050ce3          	beqz	a0,1e4 <grep+0x5c>
        *q = '\n';
     210:	01348023          	sb	s3,0(s1)
        write(1, p, q+1 - p);
     214:	00148613          	addi	a2,s1,1
     218:	4126063b          	subw	a2,a2,s2
     21c:	00090593          	mv	a1,s2
     220:	000c0513          	mv	a0,s8
     224:	5f0000ef          	jal	814 <write>
     228:	fbdff06f          	j	1e4 <grep+0x5c>
    if(m > 0){
     22c:	03604863          	bgtz	s6,25c <grep+0xd4>
  while((n = read(fd, buf+m, sizeof(buf)-m-1)) > 0){
     230:	416d063b          	subw	a2,s10,s6
     234:	016b85b3          	add	a1,s7,s6
     238:	000c8513          	mv	a0,s9
     23c:	5cc000ef          	jal	808 <read>
     240:	04a05263          	blez	a0,284 <grep+0xfc>
    m += n;
     244:	00ab0a3b          	addw	s4,s6,a0
     248:	000a0b13          	mv	s6,s4
    buf[m] = '\0';
     24c:	014b87b3          	add	a5,s7,s4
     250:	00078023          	sb	zero,0(a5)
    p = buf;
     254:	000b8913          	mv	s2,s7
    while((q = strchr(p, '\n')) != 0){
     258:	f91ff06f          	j	1e8 <grep+0x60>
      m -= p - buf;
     25c:	00002797          	auipc	a5,0x2
     260:	dc478793          	addi	a5,a5,-572 # 2020 <buf>
     264:	40f907b3          	sub	a5,s2,a5
     268:	40fa063b          	subw	a2,s4,a5
     26c:	00060b13          	mv	s6,a2
      memmove(buf, p, m);
     270:	00090593          	mv	a1,s2
     274:	00002517          	auipc	a0,0x2
     278:	dac50513          	addi	a0,a0,-596 # 2020 <buf>
     27c:	408000ef          	jal	684 <memmove>
     280:	fb1ff06f          	j	230 <grep+0xa8>
}
     284:	05813083          	ld	ra,88(sp)
     288:	05013403          	ld	s0,80(sp)
     28c:	04813483          	ld	s1,72(sp)
     290:	04013903          	ld	s2,64(sp)
     294:	03813983          	ld	s3,56(sp)
     298:	03013a03          	ld	s4,48(sp)
     29c:	02813a83          	ld	s5,40(sp)
     2a0:	02013b03          	ld	s6,32(sp)
     2a4:	01813b83          	ld	s7,24(sp)
     2a8:	01013c03          	ld	s8,16(sp)
     2ac:	00813c83          	ld	s9,8(sp)
     2b0:	00013d03          	ld	s10,0(sp)
     2b4:	06010113          	addi	sp,sp,96
     2b8:	00008067          	ret

00000000000002bc <main>:
{
     2bc:	fd010113          	addi	sp,sp,-48
     2c0:	02113423          	sd	ra,40(sp)
     2c4:	02813023          	sd	s0,32(sp)
     2c8:	00913c23          	sd	s1,24(sp)
     2cc:	01213823          	sd	s2,16(sp)
     2d0:	01313423          	sd	s3,8(sp)
     2d4:	01413023          	sd	s4,0(sp)
     2d8:	03010413          	addi	s0,sp,48
  if(argc <= 1){
     2dc:	00100793          	li	a5,1
     2e0:	06a7d063          	bge	a5,a0,340 <main+0x84>
  pattern = argv[1];
     2e4:	0085ba03          	ld	s4,8(a1)
  if(argc <= 2){
     2e8:	00200793          	li	a5,2
     2ec:	06a7d663          	bge	a5,a0,358 <main+0x9c>
     2f0:	01058913          	addi	s2,a1,16
     2f4:	ffd5099b          	addiw	s3,a0,-3
     2f8:	02099793          	slli	a5,s3,0x20
     2fc:	01d7d993          	srli	s3,a5,0x1d
     300:	01858593          	addi	a1,a1,24
     304:	00b989b3          	add	s3,s3,a1
    if((fd = open(argv[i], O_RDONLY)) < 0){
     308:	00000593          	li	a1,0
     30c:	00093503          	ld	a0,0(s2)
     310:	534000ef          	jal	844 <open>
     314:	00050493          	mv	s1,a0
     318:	04054a63          	bltz	a0,36c <main+0xb0>
    grep(pattern, fd);
     31c:	00050593          	mv	a1,a0
     320:	000a0513          	mv	a0,s4
     324:	e65ff0ef          	jal	188 <grep>
    close(fd);
     328:	00048513          	mv	a0,s1
     32c:	4f4000ef          	jal	820 <close>
  for(i = 2; i < argc; i++){
     330:	00890913          	addi	s2,s2,8
     334:	fd391ae3          	bne	s2,s3,308 <main+0x4c>
  exit(0);
     338:	00000513          	li	a0,0
     33c:	4a8000ef          	jal	7e4 <exit>
    fprintf(2, "usage: grep pattern [file ...]\n");
     340:	00001597          	auipc	a1,0x1
     344:	e0058593          	addi	a1,a1,-512 # 1140 <malloc+0x178>
     348:	00200513          	li	a0,2
     34c:	32d000ef          	jal	e78 <fprintf>
    exit(1);
     350:	00100513          	li	a0,1
     354:	490000ef          	jal	7e4 <exit>
    grep(pattern, 0);
     358:	00000593          	li	a1,0
     35c:	000a0513          	mv	a0,s4
     360:	e29ff0ef          	jal	188 <grep>
    exit(0);
     364:	00000513          	li	a0,0
     368:	47c000ef          	jal	7e4 <exit>
      printf("grep: cannot open %s\n", argv[i]);
     36c:	00093583          	ld	a1,0(s2)
     370:	00001517          	auipc	a0,0x1
     374:	df050513          	addi	a0,a0,-528 # 1160 <malloc+0x198>
     378:	345000ef          	jal	ebc <printf>
      exit(1);
     37c:	00100513          	li	a0,1
     380:	464000ef          	jal	7e4 <exit>

0000000000000384 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
     384:	ff010113          	addi	sp,sp,-16
     388:	00113423          	sd	ra,8(sp)
     38c:	00813023          	sd	s0,0(sp)
     390:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
     394:	f29ff0ef          	jal	2bc <main>
  exit(r);
     398:	44c000ef          	jal	7e4 <exit>

000000000000039c <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
     39c:	ff010113          	addi	sp,sp,-16
     3a0:	00113423          	sd	ra,8(sp)
     3a4:	00813023          	sd	s0,0(sp)
     3a8:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
     3ac:	00050793          	mv	a5,a0
     3b0:	00158593          	addi	a1,a1,1
     3b4:	00178793          	addi	a5,a5,1
     3b8:	fff5c703          	lbu	a4,-1(a1)
     3bc:	fee78fa3          	sb	a4,-1(a5)
     3c0:	fe0718e3          	bnez	a4,3b0 <strcpy+0x14>
    ;
  return os;
}
     3c4:	00813083          	ld	ra,8(sp)
     3c8:	00013403          	ld	s0,0(sp)
     3cc:	01010113          	addi	sp,sp,16
     3d0:	00008067          	ret

00000000000003d4 <strcmp>:

int
strcmp(const char *p, const char *q)
{
     3d4:	ff010113          	addi	sp,sp,-16
     3d8:	00113423          	sd	ra,8(sp)
     3dc:	00813023          	sd	s0,0(sp)
     3e0:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
     3e4:	00054783          	lbu	a5,0(a0)
     3e8:	00078e63          	beqz	a5,404 <strcmp+0x30>
     3ec:	0005c703          	lbu	a4,0(a1)
     3f0:	00f71a63          	bne	a4,a5,404 <strcmp+0x30>
    p++, q++;
     3f4:	00150513          	addi	a0,a0,1
     3f8:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
     3fc:	00054783          	lbu	a5,0(a0)
     400:	fe0796e3          	bnez	a5,3ec <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
     404:	0005c503          	lbu	a0,0(a1)
}
     408:	40a7853b          	subw	a0,a5,a0
     40c:	00813083          	ld	ra,8(sp)
     410:	00013403          	ld	s0,0(sp)
     414:	01010113          	addi	sp,sp,16
     418:	00008067          	ret

000000000000041c <strlen>:

uint
strlen(const char *s)
{
     41c:	ff010113          	addi	sp,sp,-16
     420:	00113423          	sd	ra,8(sp)
     424:	00813023          	sd	s0,0(sp)
     428:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
     42c:	00054783          	lbu	a5,0(a0)
     430:	02078663          	beqz	a5,45c <strlen+0x40>
     434:	00150793          	addi	a5,a0,1
     438:	00078693          	mv	a3,a5
     43c:	00178793          	addi	a5,a5,1
     440:	fff7c703          	lbu	a4,-1(a5)
     444:	fe071ae3          	bnez	a4,438 <strlen+0x1c>
     448:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
     44c:	00813083          	ld	ra,8(sp)
     450:	00013403          	ld	s0,0(sp)
     454:	01010113          	addi	sp,sp,16
     458:	00008067          	ret
  for(n = 0; s[n]; n++)
     45c:	00000513          	li	a0,0
     460:	fedff06f          	j	44c <strlen+0x30>

0000000000000464 <memset>:

void*
memset(void *dst, int c, uint n)
{
     464:	ff010113          	addi	sp,sp,-16
     468:	00113423          	sd	ra,8(sp)
     46c:	00813023          	sd	s0,0(sp)
     470:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
     474:	02060063          	beqz	a2,494 <memset+0x30>
     478:	00050793          	mv	a5,a0
     47c:	02061613          	slli	a2,a2,0x20
     480:	02065613          	srli	a2,a2,0x20
     484:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
     488:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
     48c:	00178793          	addi	a5,a5,1
     490:	fee79ce3          	bne	a5,a4,488 <memset+0x24>
  }
  return dst;
}
     494:	00813083          	ld	ra,8(sp)
     498:	00013403          	ld	s0,0(sp)
     49c:	01010113          	addi	sp,sp,16
     4a0:	00008067          	ret

00000000000004a4 <strchr>:

char*
strchr(const char *s, char c)
{
     4a4:	ff010113          	addi	sp,sp,-16
     4a8:	00113423          	sd	ra,8(sp)
     4ac:	00813023          	sd	s0,0(sp)
     4b0:	01010413          	addi	s0,sp,16
  for(; *s; s++)
     4b4:	00054783          	lbu	a5,0(a0)
     4b8:	02078463          	beqz	a5,4e0 <strchr+0x3c>
    if(*s == c)
     4bc:	00f58a63          	beq	a1,a5,4d0 <strchr+0x2c>
  for(; *s; s++)
     4c0:	00150513          	addi	a0,a0,1
     4c4:	00054783          	lbu	a5,0(a0)
     4c8:	fe079ae3          	bnez	a5,4bc <strchr+0x18>
      return (char*)s;
  return 0;
     4cc:	00000513          	li	a0,0
}
     4d0:	00813083          	ld	ra,8(sp)
     4d4:	00013403          	ld	s0,0(sp)
     4d8:	01010113          	addi	sp,sp,16
     4dc:	00008067          	ret
  return 0;
     4e0:	00000513          	li	a0,0
     4e4:	fedff06f          	j	4d0 <strchr+0x2c>

00000000000004e8 <gets>:

char*
gets(char *buf, int max)
{
     4e8:	fa010113          	addi	sp,sp,-96
     4ec:	04113c23          	sd	ra,88(sp)
     4f0:	04813823          	sd	s0,80(sp)
     4f4:	04913423          	sd	s1,72(sp)
     4f8:	05213023          	sd	s2,64(sp)
     4fc:	03313c23          	sd	s3,56(sp)
     500:	03413823          	sd	s4,48(sp)
     504:	03513423          	sd	s5,40(sp)
     508:	03613023          	sd	s6,32(sp)
     50c:	01713c23          	sd	s7,24(sp)
     510:	01813823          	sd	s8,16(sp)
     514:	06010413          	addi	s0,sp,96
     518:	00050b93          	mv	s7,a0
     51c:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
     520:	00050913          	mv	s2,a0
     524:	00000493          	li	s1,0
    cc = read(0, &c, 1);
     528:	faf40b13          	addi	s6,s0,-81
     52c:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
     530:	00048c13          	mv	s8,s1
     534:	0014899b          	addiw	s3,s1,1
     538:	00098493          	mv	s1,s3
     53c:	0349dc63          	bge	s3,s4,574 <gets+0x8c>
    cc = read(0, &c, 1);
     540:	000a8613          	mv	a2,s5
     544:	000b0593          	mv	a1,s6
     548:	00000513          	li	a0,0
     54c:	2bc000ef          	jal	808 <read>
    if(cc < 1)
     550:	02a05263          	blez	a0,574 <gets+0x8c>
      break;
    buf[i++] = c;
     554:	faf44783          	lbu	a5,-81(s0)
     558:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
     55c:	00190913          	addi	s2,s2,1
     560:	ff678713          	addi	a4,a5,-10
     564:	00070663          	beqz	a4,570 <gets+0x88>
     568:	ff378793          	addi	a5,a5,-13
     56c:	fc0792e3          	bnez	a5,530 <gets+0x48>
    buf[i++] = c;
     570:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
     574:	018b8c33          	add	s8,s7,s8
     578:	000c0023          	sb	zero,0(s8)
  return buf;
}
     57c:	000b8513          	mv	a0,s7
     580:	05813083          	ld	ra,88(sp)
     584:	05013403          	ld	s0,80(sp)
     588:	04813483          	ld	s1,72(sp)
     58c:	04013903          	ld	s2,64(sp)
     590:	03813983          	ld	s3,56(sp)
     594:	03013a03          	ld	s4,48(sp)
     598:	02813a83          	ld	s5,40(sp)
     59c:	02013b03          	ld	s6,32(sp)
     5a0:	01813b83          	ld	s7,24(sp)
     5a4:	01013c03          	ld	s8,16(sp)
     5a8:	06010113          	addi	sp,sp,96
     5ac:	00008067          	ret

00000000000005b0 <stat>:

int
stat(const char *n, struct stat *st)
{
     5b0:	fe010113          	addi	sp,sp,-32
     5b4:	00113c23          	sd	ra,24(sp)
     5b8:	00813823          	sd	s0,16(sp)
     5bc:	01213023          	sd	s2,0(sp)
     5c0:	02010413          	addi	s0,sp,32
     5c4:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
     5c8:	00000593          	li	a1,0
     5cc:	278000ef          	jal	844 <open>
  if(fd < 0)
     5d0:	02054e63          	bltz	a0,60c <stat+0x5c>
     5d4:	00913423          	sd	s1,8(sp)
     5d8:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
     5dc:	00090593          	mv	a1,s2
     5e0:	288000ef          	jal	868 <fstat>
     5e4:	00050913          	mv	s2,a0
  close(fd);
     5e8:	00048513          	mv	a0,s1
     5ec:	234000ef          	jal	820 <close>
  return r;
     5f0:	00813483          	ld	s1,8(sp)
}
     5f4:	00090513          	mv	a0,s2
     5f8:	01813083          	ld	ra,24(sp)
     5fc:	01013403          	ld	s0,16(sp)
     600:	00013903          	ld	s2,0(sp)
     604:	02010113          	addi	sp,sp,32
     608:	00008067          	ret
    return -1;
     60c:	fff00793          	li	a5,-1
     610:	00078913          	mv	s2,a5
     614:	fe1ff06f          	j	5f4 <stat+0x44>

0000000000000618 <atoi>:

int
atoi(const char *s)
{
     618:	ff010113          	addi	sp,sp,-16
     61c:	00113423          	sd	ra,8(sp)
     620:	00813023          	sd	s0,0(sp)
     624:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
     628:	00054683          	lbu	a3,0(a0)
     62c:	fd06879b          	addiw	a5,a3,-48
     630:	0ff7f793          	zext.b	a5,a5
     634:	00900613          	li	a2,9
     638:	04f66263          	bltu	a2,a5,67c <atoi+0x64>
     63c:	00050713          	mv	a4,a0
  n = 0;
     640:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
     644:	00170713          	addi	a4,a4,1
     648:	0025179b          	slliw	a5,a0,0x2
     64c:	00a787bb          	addw	a5,a5,a0
     650:	0017979b          	slliw	a5,a5,0x1
     654:	00d787bb          	addw	a5,a5,a3
     658:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
     65c:	00074683          	lbu	a3,0(a4)
     660:	fd06879b          	addiw	a5,a3,-48
     664:	0ff7f793          	zext.b	a5,a5
     668:	fcf67ee3          	bgeu	a2,a5,644 <atoi+0x2c>
  return n;
}
     66c:	00813083          	ld	ra,8(sp)
     670:	00013403          	ld	s0,0(sp)
     674:	01010113          	addi	sp,sp,16
     678:	00008067          	ret
  n = 0;
     67c:	00000513          	li	a0,0
     680:	fedff06f          	j	66c <atoi+0x54>

0000000000000684 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
     684:	ff010113          	addi	sp,sp,-16
     688:	00113423          	sd	ra,8(sp)
     68c:	00813023          	sd	s0,0(sp)
     690:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
     694:	02b57e63          	bgeu	a0,a1,6d0 <memmove+0x4c>
    while(n-- > 0)
     698:	02c05463          	blez	a2,6c0 <memmove+0x3c>
     69c:	02061613          	slli	a2,a2,0x20
     6a0:	02065613          	srli	a2,a2,0x20
     6a4:	00c507b3          	add	a5,a0,a2
  dst = vdst;
     6a8:	00050713          	mv	a4,a0
      *dst++ = *src++;
     6ac:	00158593          	addi	a1,a1,1
     6b0:	00170713          	addi	a4,a4,1
     6b4:	fff5c683          	lbu	a3,-1(a1)
     6b8:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
     6bc:	fee798e3          	bne	a5,a4,6ac <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
     6c0:	00813083          	ld	ra,8(sp)
     6c4:	00013403          	ld	s0,0(sp)
     6c8:	01010113          	addi	sp,sp,16
     6cc:	00008067          	ret
    while(n-- > 0)
     6d0:	fec058e3          	blez	a2,6c0 <memmove+0x3c>
    dst += n;
     6d4:	00c50733          	add	a4,a0,a2
    src += n;
     6d8:	00c585b3          	add	a1,a1,a2
     6dc:	fff6079b          	addiw	a5,a2,-1
     6e0:	02079793          	slli	a5,a5,0x20
     6e4:	0207d793          	srli	a5,a5,0x20
     6e8:	fff7c793          	not	a5,a5
     6ec:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
     6f0:	fff58593          	addi	a1,a1,-1
     6f4:	fff70713          	addi	a4,a4,-1
     6f8:	0005c683          	lbu	a3,0(a1)
     6fc:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
     700:	fef718e3          	bne	a4,a5,6f0 <memmove+0x6c>
     704:	fbdff06f          	j	6c0 <memmove+0x3c>

0000000000000708 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
     708:	ff010113          	addi	sp,sp,-16
     70c:	00113423          	sd	ra,8(sp)
     710:	00813023          	sd	s0,0(sp)
     714:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
     718:	04060263          	beqz	a2,75c <memcmp+0x54>
     71c:	02061613          	slli	a2,a2,0x20
     720:	02065613          	srli	a2,a2,0x20
     724:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
     728:	00054783          	lbu	a5,0(a0)
     72c:	0005c703          	lbu	a4,0(a1)
     730:	00e79c63          	bne	a5,a4,748 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
     734:	00150513          	addi	a0,a0,1
    p2++;
     738:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
     73c:	fed516e3          	bne	a0,a3,728 <memcmp+0x20>
  }
  return 0;
     740:	00000513          	li	a0,0
     744:	0080006f          	j	74c <memcmp+0x44>
      return *p1 - *p2;
     748:	40e7853b          	subw	a0,a5,a4
}
     74c:	00813083          	ld	ra,8(sp)
     750:	00013403          	ld	s0,0(sp)
     754:	01010113          	addi	sp,sp,16
     758:	00008067          	ret
  return 0;
     75c:	00000513          	li	a0,0
     760:	fedff06f          	j	74c <memcmp+0x44>

0000000000000764 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
     764:	ff010113          	addi	sp,sp,-16
     768:	00113423          	sd	ra,8(sp)
     76c:	00813023          	sd	s0,0(sp)
     770:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
     774:	f11ff0ef          	jal	684 <memmove>
}
     778:	00813083          	ld	ra,8(sp)
     77c:	00013403          	ld	s0,0(sp)
     780:	01010113          	addi	sp,sp,16
     784:	00008067          	ret

0000000000000788 <sbrk>:

char *
sbrk(int n) {
     788:	ff010113          	addi	sp,sp,-16
     78c:	00113423          	sd	ra,8(sp)
     790:	00813023          	sd	s0,0(sp)
     794:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
     798:	00100593          	li	a1,1
     79c:	114000ef          	jal	8b0 <sys_sbrk>
}
     7a0:	00813083          	ld	ra,8(sp)
     7a4:	00013403          	ld	s0,0(sp)
     7a8:	01010113          	addi	sp,sp,16
     7ac:	00008067          	ret

00000000000007b0 <sbrklazy>:

char *
sbrklazy(int n) {
     7b0:	ff010113          	addi	sp,sp,-16
     7b4:	00113423          	sd	ra,8(sp)
     7b8:	00813023          	sd	s0,0(sp)
     7bc:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
     7c0:	00200593          	li	a1,2
     7c4:	0ec000ef          	jal	8b0 <sys_sbrk>
}
     7c8:	00813083          	ld	ra,8(sp)
     7cc:	00013403          	ld	s0,0(sp)
     7d0:	01010113          	addi	sp,sp,16
     7d4:	00008067          	ret

00000000000007d8 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
     7d8:	00100893          	li	a7,1
 ecall
     7dc:	00000073          	ecall
 ret
     7e0:	00008067          	ret

00000000000007e4 <exit>:
.global exit
exit:
 li a7, SYS_exit
     7e4:	00200893          	li	a7,2
 ecall
     7e8:	00000073          	ecall
 ret
     7ec:	00008067          	ret

00000000000007f0 <wait>:
.global wait
wait:
 li a7, SYS_wait
     7f0:	00300893          	li	a7,3
 ecall
     7f4:	00000073          	ecall
 ret
     7f8:	00008067          	ret

00000000000007fc <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
     7fc:	00400893          	li	a7,4
 ecall
     800:	00000073          	ecall
 ret
     804:	00008067          	ret

0000000000000808 <read>:
.global read
read:
 li a7, SYS_read
     808:	00500893          	li	a7,5
 ecall
     80c:	00000073          	ecall
 ret
     810:	00008067          	ret

0000000000000814 <write>:
.global write
write:
 li a7, SYS_write
     814:	01000893          	li	a7,16
 ecall
     818:	00000073          	ecall
 ret
     81c:	00008067          	ret

0000000000000820 <close>:
.global close
close:
 li a7, SYS_close
     820:	01500893          	li	a7,21
 ecall
     824:	00000073          	ecall
 ret
     828:	00008067          	ret

000000000000082c <kill>:
.global kill
kill:
 li a7, SYS_kill
     82c:	00600893          	li	a7,6
 ecall
     830:	00000073          	ecall
 ret
     834:	00008067          	ret

0000000000000838 <exec>:
.global exec
exec:
 li a7, SYS_exec
     838:	00700893          	li	a7,7
 ecall
     83c:	00000073          	ecall
 ret
     840:	00008067          	ret

0000000000000844 <open>:
.global open
open:
 li a7, SYS_open
     844:	00f00893          	li	a7,15
 ecall
     848:	00000073          	ecall
 ret
     84c:	00008067          	ret

0000000000000850 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
     850:	01100893          	li	a7,17
 ecall
     854:	00000073          	ecall
 ret
     858:	00008067          	ret

000000000000085c <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
     85c:	01200893          	li	a7,18
 ecall
     860:	00000073          	ecall
 ret
     864:	00008067          	ret

0000000000000868 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
     868:	00800893          	li	a7,8
 ecall
     86c:	00000073          	ecall
 ret
     870:	00008067          	ret

0000000000000874 <link>:
.global link
link:
 li a7, SYS_link
     874:	01300893          	li	a7,19
 ecall
     878:	00000073          	ecall
 ret
     87c:	00008067          	ret

0000000000000880 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
     880:	01400893          	li	a7,20
 ecall
     884:	00000073          	ecall
 ret
     888:	00008067          	ret

000000000000088c <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
     88c:	00900893          	li	a7,9
 ecall
     890:	00000073          	ecall
 ret
     894:	00008067          	ret

0000000000000898 <dup>:
.global dup
dup:
 li a7, SYS_dup
     898:	00a00893          	li	a7,10
 ecall
     89c:	00000073          	ecall
 ret
     8a0:	00008067          	ret

00000000000008a4 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
     8a4:	00b00893          	li	a7,11
 ecall
     8a8:	00000073          	ecall
 ret
     8ac:	00008067          	ret

00000000000008b0 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
     8b0:	00c00893          	li	a7,12
 ecall
     8b4:	00000073          	ecall
 ret
     8b8:	00008067          	ret

00000000000008bc <pause>:
.global pause
pause:
 li a7, SYS_pause
     8bc:	00d00893          	li	a7,13
 ecall
     8c0:	00000073          	ecall
 ret
     8c4:	00008067          	ret

00000000000008c8 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
     8c8:	00e00893          	li	a7,14
 ecall
     8cc:	00000073          	ecall
 ret
     8d0:	00008067          	ret

00000000000008d4 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
     8d4:	00001617          	auipc	a2,0x1
     8d8:	73c62603          	lw	a2,1852(a2) # 2010 <putc_n>
     8dc:	00c04463          	bgtz	a2,8e4 <putc_flush+0x10>
     8e0:	00008067          	ret
{
     8e4:	ff010113          	addi	sp,sp,-16
     8e8:	00113423          	sd	ra,8(sp)
     8ec:	00813023          	sd	s0,0(sp)
     8f0:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
     8f4:	00002597          	auipc	a1,0x2
     8f8:	b2c58593          	addi	a1,a1,-1236 # 2420 <putc_buf>
     8fc:	00001517          	auipc	a0,0x1
     900:	70452503          	lw	a0,1796(a0) # 2000 <putc_fd>
     904:	f11ff0ef          	jal	814 <write>
    putc_n = 0;
     908:	00001797          	auipc	a5,0x1
     90c:	7007a423          	sw	zero,1800(a5) # 2010 <putc_n>
  }
}
     910:	00813083          	ld	ra,8(sp)
     914:	00013403          	ld	s0,0(sp)
     918:	01010113          	addi	sp,sp,16
     91c:	00008067          	ret

0000000000000920 <putc>:

static void
putc(int fd, char c)
{
     920:	fe010113          	addi	sp,sp,-32
     924:	00113c23          	sd	ra,24(sp)
     928:	00813823          	sd	s0,16(sp)
     92c:	00913423          	sd	s1,8(sp)
     930:	02010413          	addi	s0,sp,32
     934:	00058493          	mv	s1,a1
  if (putc_fd != fd)
     938:	00001797          	auipc	a5,0x1
     93c:	6c87a783          	lw	a5,1736(a5) # 2000 <putc_fd>
     940:	04a79663          	bne	a5,a0,98c <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
     944:	00001717          	auipc	a4,0x1
     948:	6cc70713          	addi	a4,a4,1740 # 2010 <putc_n>
     94c:	00072683          	lw	a3,0(a4)
     950:	0016879b          	addiw	a5,a3,1
     954:	00f72023          	sw	a5,0(a4)
     958:	00002717          	auipc	a4,0x2
     95c:	ac870713          	addi	a4,a4,-1336 # 2420 <putc_buf>
     960:	00d70733          	add	a4,a4,a3
     964:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
     968:	ff648493          	addi	s1,s1,-10
     96c:	02048e63          	beqz	s1,9a8 <putc+0x88>
     970:	f8078793          	addi	a5,a5,-128
     974:	02078a63          	beqz	a5,9a8 <putc+0x88>
    putc_flush();
}
     978:	01813083          	ld	ra,24(sp)
     97c:	01013403          	ld	s0,16(sp)
     980:	00813483          	ld	s1,8(sp)
     984:	02010113          	addi	sp,sp,32
     988:	00008067          	ret
     98c:	01213023          	sd	s2,0(sp)
     990:	00050913          	mv	s2,a0
    putc_flush();
     994:	f41ff0ef          	jal	8d4 <putc_flush>
    putc_fd = fd;
     998:	00001797          	auipc	a5,0x1
     99c:	6727a423          	sw	s2,1640(a5) # 2000 <putc_fd>
     9a0:	00013903          	ld	s2,0(sp)
     9a4:	fa1ff06f          	j	944 <putc+0x24>
    putc_flush();
     9a8:	f2dff0ef          	jal	8d4 <putc_flush>
}
     9ac:	fcdff06f          	j	978 <putc+0x58>

00000000000009b0 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
     9b0:	fb010113          	addi	sp,sp,-80
     9b4:	04113423          	sd	ra,72(sp)
     9b8:	04813023          	sd	s0,64(sp)
     9bc:	03213823          	sd	s2,48(sp)
     9c0:	03313423          	sd	s3,40(sp)
     9c4:	05010413          	addi	s0,sp,80
     9c8:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
     9cc:	0a068e63          	beqz	a3,a88 <printint+0xd8>
     9d0:	0a05dc63          	bgez	a1,a88 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
     9d4:	40b005b3          	neg	a1,a1
    neg = 1;
     9d8:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
     9dc:	fb840993          	addi	s3,s0,-72
  neg = 0;
     9e0:	00098693          	mv	a3,s3
  i = 0;
     9e4:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
     9e8:	00000817          	auipc	a6,0x0
     9ec:	79880813          	addi	a6,a6,1944 # 1180 <digits>
     9f0:	00070893          	mv	a7,a4
     9f4:	0017051b          	addiw	a0,a4,1
     9f8:	00050713          	mv	a4,a0
     9fc:	02c5f7b3          	remu	a5,a1,a2
     a00:	00f807b3          	add	a5,a6,a5
     a04:	0007c783          	lbu	a5,0(a5)
     a08:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
     a0c:	00058793          	mv	a5,a1
     a10:	02c5d5b3          	divu	a1,a1,a2
     a14:	00168693          	addi	a3,a3,1
     a18:	fcc7fce3          	bgeu	a5,a2,9f0 <printint+0x40>
  if (neg)
     a1c:	00030c63          	beqz	t1,a34 <printint+0x84>
    buf[i++] = '-';
     a20:	fd050793          	addi	a5,a0,-48
     a24:	00878533          	add	a0,a5,s0
     a28:	02d00793          	li	a5,45
     a2c:	fef50423          	sb	a5,-24(a0)
     a30:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
     a34:	02e05e63          	blez	a4,a70 <printint+0xc0>
     a38:	02913c23          	sd	s1,56(sp)
     a3c:	fff7071b          	addiw	a4,a4,-1
     a40:	00e984b3          	add	s1,s3,a4
     a44:	fff98993          	addi	s3,s3,-1
     a48:	00e989b3          	add	s3,s3,a4
     a4c:	02071713          	slli	a4,a4,0x20
     a50:	02075713          	srli	a4,a4,0x20
     a54:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
     a58:	0004c583          	lbu	a1,0(s1)
     a5c:	00090513          	mv	a0,s2
     a60:	ec1ff0ef          	jal	920 <putc>
  while (--i >= 0)
     a64:	fff48493          	addi	s1,s1,-1
     a68:	ff3498e3          	bne	s1,s3,a58 <printint+0xa8>
     a6c:	03813483          	ld	s1,56(sp)
}
     a70:	04813083          	ld	ra,72(sp)
     a74:	04013403          	ld	s0,64(sp)
     a78:	03013903          	ld	s2,48(sp)
     a7c:	02813983          	ld	s3,40(sp)
     a80:	05010113          	addi	sp,sp,80
     a84:	00008067          	ret
  neg = 0;
     a88:	00000313          	li	t1,0
     a8c:	f51ff06f          	j	9dc <printint+0x2c>

0000000000000a90 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
     a90:	fa010113          	addi	sp,sp,-96
     a94:	04113c23          	sd	ra,88(sp)
     a98:	04813823          	sd	s0,80(sp)
     a9c:	04913423          	sd	s1,72(sp)
     aa0:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
     aa4:	0005c483          	lbu	s1,0(a1)
     aa8:	32048263          	beqz	s1,dcc <vprintf+0x33c>
     aac:	05213023          	sd	s2,64(sp)
     ab0:	03313c23          	sd	s3,56(sp)
     ab4:	03413823          	sd	s4,48(sp)
     ab8:	03513423          	sd	s5,40(sp)
     abc:	03613023          	sd	s6,32(sp)
     ac0:	01713c23          	sd	s7,24(sp)
     ac4:	01813823          	sd	s8,16(sp)
     ac8:	00050b13          	mv	s6,a0
     acc:	00058a13          	mv	s4,a1
     ad0:	00060b93          	mv	s7,a2
  state = 0;
     ad4:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
     ad8:	00000913          	li	s2,0
     adc:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
     ae0:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
     ae4:	06400c13          	li	s8,100
     ae8:	0300006f          	j	b18 <vprintf+0x88>
        putc(fd, c0);
     aec:	00048593          	mv	a1,s1
     af0:	000b0513          	mv	a0,s6
     af4:	e2dff0ef          	jal	920 <putc>
     af8:	0080006f          	j	b00 <vprintf+0x70>
    else if (state == '%')
     afc:	03598863          	beq	s3,s5,b2c <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
     b00:	0019079b          	addiw	a5,s2,1
     b04:	00078913          	mv	s2,a5
     b08:	00078713          	mv	a4,a5
     b0c:	00fa07b3          	add	a5,s4,a5
     b10:	0007c483          	lbu	s1,0(a5)
     b14:	28048e63          	beqz	s1,db0 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
     b18:	0004879b          	sext.w	a5,s1
    if (state == 0)
     b1c:	fe0990e3          	bnez	s3,afc <vprintf+0x6c>
      if (c0 == '%')
     b20:	fd5796e3          	bne	a5,s5,aec <vprintf+0x5c>
        state = '%';
     b24:	00078993          	mv	s3,a5
     b28:	fd9ff06f          	j	b00 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
     b2c:	00ea06b3          	add	a3,s4,a4
     b30:	0016c603          	lbu	a2,1(a3)
      if (c1)
     b34:	2a060663          	beqz	a2,de0 <vprintf+0x350>
      if (c0 == 'd')
     b38:	05878063          	beq	a5,s8,b78 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
     b3c:	f9478693          	addi	a3,a5,-108
     b40:	0016b693          	seqz	a3,a3
     b44:	f9c60593          	addi	a1,a2,-100
     b48:	04059a63          	bnez	a1,b9c <vprintf+0x10c>
     b4c:	04068863          	beqz	a3,b9c <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
     b50:	008b8493          	addi	s1,s7,8
     b54:	00100693          	li	a3,1
     b58:	00a00613          	li	a2,10
     b5c:	000bb583          	ld	a1,0(s7)
     b60:	000b0513          	mv	a0,s6
     b64:	e4dff0ef          	jal	9b0 <printint>
        i += 1;
     b68:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
     b6c:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
     b70:	00000993          	li	s3,0
     b74:	f8dff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
     b78:	008b8493          	addi	s1,s7,8
     b7c:	00100693          	li	a3,1
     b80:	00a00613          	li	a2,10
     b84:	000ba583          	lw	a1,0(s7)
     b88:	000b0513          	mv	a0,s6
     b8c:	e25ff0ef          	jal	9b0 <printint>
     b90:	00048b93          	mv	s7,s1
      state = 0;
     b94:	00000993          	li	s3,0
     b98:	f69ff06f          	j	b00 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
     b9c:	00ea0733          	add	a4,s4,a4
     ba0:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
     ba4:	f9460713          	addi	a4,a2,-108
     ba8:	00173713          	seqz	a4,a4
     bac:	00e6f733          	and	a4,a3,a4
     bb0:	f9c58513          	addi	a0,a1,-100
     bb4:	24051263          	bnez	a0,df8 <vprintf+0x368>
     bb8:	24070063          	beqz	a4,df8 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
     bbc:	008b8493          	addi	s1,s7,8
     bc0:	00100693          	li	a3,1
     bc4:	00a00613          	li	a2,10
     bc8:	000bb583          	ld	a1,0(s7)
     bcc:	000b0513          	mv	a0,s6
     bd0:	de1ff0ef          	jal	9b0 <printint>
        i += 2;
     bd4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
     bd8:	00048b93          	mv	s7,s1
      state = 0;
     bdc:	00000993          	li	s3,0
        i += 2;
     be0:	f21ff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
     be4:	008b8493          	addi	s1,s7,8
     be8:	00000693          	li	a3,0
     bec:	00a00613          	li	a2,10
     bf0:	000be583          	lwu	a1,0(s7)
     bf4:	000b0513          	mv	a0,s6
     bf8:	db9ff0ef          	jal	9b0 <printint>
     bfc:	00048b93          	mv	s7,s1
      state = 0;
     c00:	00000993          	li	s3,0
     c04:	efdff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
     c08:	008b8493          	addi	s1,s7,8
     c0c:	00000693          	li	a3,0
     c10:	00a00613          	li	a2,10
     c14:	000bb583          	ld	a1,0(s7)
     c18:	000b0513          	mv	a0,s6
     c1c:	d95ff0ef          	jal	9b0 <printint>
        i += 1;
     c20:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
     c24:	00048b93          	mv	s7,s1
      state = 0;
     c28:	00000993          	li	s3,0
     c2c:	ed5ff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
     c30:	008b8493          	addi	s1,s7,8
     c34:	00000693          	li	a3,0
     c38:	00a00613          	li	a2,10
     c3c:	000bb583          	ld	a1,0(s7)
     c40:	000b0513          	mv	a0,s6
     c44:	d6dff0ef          	jal	9b0 <printint>
        i += 2;
     c48:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
     c4c:	00048b93          	mv	s7,s1
      state = 0;
     c50:	00000993          	li	s3,0
        i += 2;
     c54:	eadff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
     c58:	008b8493          	addi	s1,s7,8
     c5c:	00000693          	li	a3,0
     c60:	01000613          	li	a2,16
     c64:	000be583          	lwu	a1,0(s7)
     c68:	000b0513          	mv	a0,s6
     c6c:	d45ff0ef          	jal	9b0 <printint>
     c70:	00048b93          	mv	s7,s1
      state = 0;
     c74:	00000993          	li	s3,0
     c78:	e89ff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
     c7c:	008b8493          	addi	s1,s7,8
     c80:	00000693          	li	a3,0
     c84:	01000613          	li	a2,16
     c88:	000bb583          	ld	a1,0(s7)
     c8c:	000b0513          	mv	a0,s6
     c90:	d21ff0ef          	jal	9b0 <printint>
        i += 1;
     c94:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
     c98:	00048b93          	mv	s7,s1
      state = 0;
     c9c:	00000993          	li	s3,0
     ca0:	e61ff06f          	j	b00 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
     ca4:	008b8493          	addi	s1,s7,8
     ca8:	00000693          	li	a3,0
     cac:	01000613          	li	a2,16
     cb0:	000bb583          	ld	a1,0(s7)
     cb4:	000b0513          	mv	a0,s6
     cb8:	cf9ff0ef          	jal	9b0 <printint>
        i += 2;
     cbc:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
     cc0:	00048b93          	mv	s7,s1
      state = 0;
     cc4:	00000993          	li	s3,0
        i += 2;
     cc8:	e39ff06f          	j	b00 <vprintf+0x70>
     ccc:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
     cd0:	008b8793          	addi	a5,s7,8
     cd4:	00078c93          	mv	s9,a5
     cd8:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
     cdc:	03000593          	li	a1,48
     ce0:	000b0513          	mv	a0,s6
     ce4:	c3dff0ef          	jal	920 <putc>
  putc(fd, 'x');
     ce8:	07800593          	li	a1,120
     cec:	000b0513          	mv	a0,s6
     cf0:	c31ff0ef          	jal	920 <putc>
     cf4:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
     cf8:	00000b97          	auipc	s7,0x0
     cfc:	488b8b93          	addi	s7,s7,1160 # 1180 <digits>
     d00:	03c9d793          	srli	a5,s3,0x3c
     d04:	00fb87b3          	add	a5,s7,a5
     d08:	0007c583          	lbu	a1,0(a5)
     d0c:	000b0513          	mv	a0,s6
     d10:	c11ff0ef          	jal	920 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
     d14:	00499993          	slli	s3,s3,0x4
     d18:	fff4849b          	addiw	s1,s1,-1
     d1c:	fe0492e3          	bnez	s1,d00 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
     d20:	000c8b93          	mv	s7,s9
      state = 0;
     d24:	00000993          	li	s3,0
     d28:	00813c83          	ld	s9,8(sp)
     d2c:	dd5ff06f          	j	b00 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
     d30:	008b8493          	addi	s1,s7,8
     d34:	000bc583          	lbu	a1,0(s7)
     d38:	000b0513          	mv	a0,s6
     d3c:	be5ff0ef          	jal	920 <putc>
     d40:	00048b93          	mv	s7,s1
      state = 0;
     d44:	00000993          	li	s3,0
     d48:	db9ff06f          	j	b00 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
     d4c:	008b8993          	addi	s3,s7,8
     d50:	000bb483          	ld	s1,0(s7)
     d54:	02048663          	beqz	s1,d80 <vprintf+0x2f0>
        for (; *s; s++)
     d58:	0004c583          	lbu	a1,0(s1)
     d5c:	04058463          	beqz	a1,da4 <vprintf+0x314>
          putc(fd, *s);
     d60:	000b0513          	mv	a0,s6
     d64:	bbdff0ef          	jal	920 <putc>
        for (; *s; s++)
     d68:	00148493          	addi	s1,s1,1
     d6c:	0004c583          	lbu	a1,0(s1)
     d70:	fe0598e3          	bnez	a1,d60 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
     d74:	00098b93          	mv	s7,s3
      state = 0;
     d78:	00000993          	li	s3,0
     d7c:	d85ff06f          	j	b00 <vprintf+0x70>
          s = "(null)";
     d80:	00000497          	auipc	s1,0x0
     d84:	3f848493          	addi	s1,s1,1016 # 1178 <malloc+0x1b0>
        for (; *s; s++)
     d88:	02800593          	li	a1,40
     d8c:	fd5ff06f          	j	d60 <vprintf+0x2d0>
        putc(fd, '%');
     d90:	00078593          	mv	a1,a5
     d94:	000b0513          	mv	a0,s6
     d98:	b89ff0ef          	jal	920 <putc>
      state = 0;
     d9c:	00000993          	li	s3,0
     da0:	d61ff06f          	j	b00 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
     da4:	00098b93          	mv	s7,s3
      state = 0;
     da8:	00000993          	li	s3,0
     dac:	d55ff06f          	j	b00 <vprintf+0x70>
     db0:	04013903          	ld	s2,64(sp)
     db4:	03813983          	ld	s3,56(sp)
     db8:	03013a03          	ld	s4,48(sp)
     dbc:	02813a83          	ld	s5,40(sp)
     dc0:	02013b03          	ld	s6,32(sp)
     dc4:	01813b83          	ld	s7,24(sp)
     dc8:	01013c03          	ld	s8,16(sp)
    }
  }
}
     dcc:	05813083          	ld	ra,88(sp)
     dd0:	05013403          	ld	s0,80(sp)
     dd4:	04813483          	ld	s1,72(sp)
     dd8:	06010113          	addi	sp,sp,96
     ddc:	00008067          	ret
      if (c0 == 'd')
     de0:	06400713          	li	a4,100
     de4:	d8e78ae3          	beq	a5,a4,b78 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
     de8:	f9478693          	addi	a3,a5,-108
     dec:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
     df0:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
     df4:	00000713          	li	a4,0
      else if (c0 == 'u')
     df8:	07500513          	li	a0,117
     dfc:	dea784e3          	beq	a5,a0,be4 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
     e00:	f8b60513          	addi	a0,a2,-117
     e04:	00051463          	bnez	a0,e0c <vprintf+0x37c>
     e08:	e00690e3          	bnez	a3,c08 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
     e0c:	f8b58513          	addi	a0,a1,-117
     e10:	00051463          	bnez	a0,e18 <vprintf+0x388>
     e14:	e0071ee3          	bnez	a4,c30 <vprintf+0x1a0>
      else if (c0 == 'x')
     e18:	07800513          	li	a0,120
     e1c:	e2a78ee3          	beq	a5,a0,c58 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
     e20:	f8860613          	addi	a2,a2,-120
     e24:	00061463          	bnez	a2,e2c <vprintf+0x39c>
     e28:	e4069ae3          	bnez	a3,c7c <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
     e2c:	f8858593          	addi	a1,a1,-120
     e30:	00059463          	bnez	a1,e38 <vprintf+0x3a8>
     e34:	e60718e3          	bnez	a4,ca4 <vprintf+0x214>
      else if (c0 == 'p')
     e38:	07000713          	li	a4,112
     e3c:	e8e788e3          	beq	a5,a4,ccc <vprintf+0x23c>
      else if (c0 == 'c')
     e40:	06300713          	li	a4,99
     e44:	eee786e3          	beq	a5,a4,d30 <vprintf+0x2a0>
      else if (c0 == 's')
     e48:	07300713          	li	a4,115
     e4c:	f0e780e3          	beq	a5,a4,d4c <vprintf+0x2bc>
      else if (c0 == '%')
     e50:	02500713          	li	a4,37
     e54:	f2e78ee3          	beq	a5,a4,d90 <vprintf+0x300>
        putc(fd, '%');
     e58:	02500593          	li	a1,37
     e5c:	000b0513          	mv	a0,s6
     e60:	ac1ff0ef          	jal	920 <putc>
        putc(fd, c0);
     e64:	00048593          	mv	a1,s1
     e68:	000b0513          	mv	a0,s6
     e6c:	ab5ff0ef          	jal	920 <putc>
      state = 0;
     e70:	00000993          	li	s3,0
     e74:	c8dff06f          	j	b00 <vprintf+0x70>

0000000000000e78 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
     e78:	fb010113          	addi	sp,sp,-80
     e7c:	00113c23          	sd	ra,24(sp)
     e80:	00813823          	sd	s0,16(sp)
     e84:	02010413          	addi	s0,sp,32
     e88:	00c43023          	sd	a2,0(s0)
     e8c:	00d43423          	sd	a3,8(s0)
     e90:	00e43823          	sd	a4,16(s0)
     e94:	00f43c23          	sd	a5,24(s0)
     e98:	03043023          	sd	a6,32(s0)
     e9c:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
     ea0:	00040613          	mv	a2,s0
     ea4:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
     ea8:	be9ff0ef          	jal	a90 <vprintf>
}
     eac:	01813083          	ld	ra,24(sp)
     eb0:	01013403          	ld	s0,16(sp)
     eb4:	05010113          	addi	sp,sp,80
     eb8:	00008067          	ret

0000000000000ebc <printf>:

void printf(const char *fmt, ...)
{
     ebc:	fa010113          	addi	sp,sp,-96
     ec0:	00113c23          	sd	ra,24(sp)
     ec4:	00813823          	sd	s0,16(sp)
     ec8:	02010413          	addi	s0,sp,32
     ecc:	00b43423          	sd	a1,8(s0)
     ed0:	00c43823          	sd	a2,16(s0)
     ed4:	00d43c23          	sd	a3,24(s0)
     ed8:	02e43023          	sd	a4,32(s0)
     edc:	02f43423          	sd	a5,40(s0)
     ee0:	03043823          	sd	a6,48(s0)
     ee4:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
     ee8:	00840613          	addi	a2,s0,8
     eec:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
     ef0:	00050593          	mv	a1,a0
     ef4:	00100513          	li	a0,1
     ef8:	b99ff0ef          	jal	a90 <vprintf>
  putc_flush();
     efc:	9d9ff0ef          	jal	8d4 <putc_flush>
}
     f00:	01813083          	ld	ra,24(sp)
     f04:	01013403          	ld	s0,16(sp)
     f08:	06010113          	addi	sp,sp,96
     f0c:	00008067          	ret

0000000000000f10 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
     f10:	ff010113          	addi	sp,sp,-16
     f14:	00113423          	sd	ra,8(sp)
     f18:	00813023          	sd	s0,0(sp)
     f1c:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
     f20:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
     f24:	00001797          	auipc	a5,0x1
     f28:	0f47b783          	ld	a5,244(a5) # 2018 <freep>
     f2c:	0140006f          	j	f40 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
     f30:	0007b703          	ld	a4,0(a5)
     f34:	00e7e463          	bltu	a5,a4,f3c <free+0x2c>
     f38:	00e6ec63          	bltu	a3,a4,f50 <free+0x40>
{
     f3c:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
     f40:	fed7f8e3          	bgeu	a5,a3,f30 <free+0x20>
     f44:	0007b703          	ld	a4,0(a5)
     f48:	00e6e463          	bltu	a3,a4,f50 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
     f4c:	fee7e8e3          	bltu	a5,a4,f3c <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
     f50:	ff852583          	lw	a1,-8(a0)
     f54:	0007b603          	ld	a2,0(a5)
     f58:	02059813          	slli	a6,a1,0x20
     f5c:	01c85713          	srli	a4,a6,0x1c
     f60:	00e68733          	add	a4,a3,a4
     f64:	02e60c63          	beq	a2,a4,f9c <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
     f68:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
     f6c:	0087a603          	lw	a2,8(a5)
     f70:	02061593          	slli	a1,a2,0x20
     f74:	01c5d713          	srli	a4,a1,0x1c
     f78:	00e78733          	add	a4,a5,a4
     f7c:	02e68c63          	beq	a3,a4,fb4 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
     f80:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
     f84:	00001717          	auipc	a4,0x1
     f88:	08f73a23          	sd	a5,148(a4) # 2018 <freep>
}
     f8c:	00813083          	ld	ra,8(sp)
     f90:	00013403          	ld	s0,0(sp)
     f94:	01010113          	addi	sp,sp,16
     f98:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
     f9c:	00862703          	lw	a4,8(a2)
     fa0:	00b7073b          	addw	a4,a4,a1
     fa4:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
     fa8:	0007b703          	ld	a4,0(a5)
     fac:	00073603          	ld	a2,0(a4)
     fb0:	fb9ff06f          	j	f68 <free+0x58>
    p->s.size += bp->s.size;
     fb4:	ff852703          	lw	a4,-8(a0)
     fb8:	00c7073b          	addw	a4,a4,a2
     fbc:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
     fc0:	ff053683          	ld	a3,-16(a0)
     fc4:	fbdff06f          	j	f80 <free+0x70>

0000000000000fc8 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
     fc8:	fc010113          	addi	sp,sp,-64
     fcc:	02113c23          	sd	ra,56(sp)
     fd0:	02813823          	sd	s0,48(sp)
     fd4:	03213023          	sd	s2,32(sp)
     fd8:	01313c23          	sd	s3,24(sp)
     fdc:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
     fe0:	02051993          	slli	s3,a0,0x20
     fe4:	0209d993          	srli	s3,s3,0x20
     fe8:	00f98993          	addi	s3,s3,15
     fec:	0049d993          	srli	s3,s3,0x4
     ff0:	0019899b          	addiw	s3,s3,1
     ff4:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
     ff8:	00001517          	auipc	a0,0x1
     ffc:	02053503          	ld	a0,32(a0) # 2018 <freep>
    1000:	04050463          	beqz	a0,1048 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1004:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1008:	0087a703          	lw	a4,8(a5)
    100c:	0d377a63          	bgeu	a4,s3,10e0 <malloc+0x118>
    1010:	02913423          	sd	s1,40(sp)
    1014:	01413823          	sd	s4,16(sp)
    1018:	01513423          	sd	s5,8(sp)
    101c:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
    1020:	00098a13          	mv	s4,s3
    1024:	00001737          	lui	a4,0x1
    1028:	00e9f463          	bgeu	s3,a4,1030 <malloc+0x68>
    102c:	00001a37          	lui	s4,0x1
    1030:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
    1034:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    1038:	00001497          	auipc	s1,0x1
    103c:	fe048493          	addi	s1,s1,-32 # 2018 <freep>
  if(p == SBRK_ERROR)
    1040:	fff00a93          	li	s5,-1
    1044:	05c0006f          	j	10a0 <malloc+0xd8>
    1048:	02913423          	sd	s1,40(sp)
    104c:	01413823          	sd	s4,16(sp)
    1050:	01513423          	sd	s5,8(sp)
    1054:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
    1058:	00001797          	auipc	a5,0x1
    105c:	44878793          	addi	a5,a5,1096 # 24a0 <base>
    1060:	00001717          	auipc	a4,0x1
    1064:	faf73c23          	sd	a5,-72(a4) # 2018 <freep>
    1068:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
    106c:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
    1070:	fb1ff06f          	j	1020 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
    1074:	0007b703          	ld	a4,0(a5)
    1078:	00e53023          	sd	a4,0(a0)
    107c:	0800006f          	j	10fc <malloc+0x134>
  hp->s.size = nu;
    1080:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
    1084:	01050513          	addi	a0,a0,16
    1088:	e89ff0ef          	jal	f10 <free>
  return freep;
    108c:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    1090:	08050863          	beqz	a0,1120 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1094:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1098:	0087a703          	lw	a4,8(a5)
    109c:	03277a63          	bgeu	a4,s2,10d0 <malloc+0x108>
    if(p == freep)
    10a0:	0004b703          	ld	a4,0(s1)
    10a4:	00078513          	mv	a0,a5
    10a8:	fef716e3          	bne	a4,a5,1094 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    10ac:	000a0513          	mv	a0,s4
    10b0:	ed8ff0ef          	jal	788 <sbrk>
  if(p == SBRK_ERROR)
    10b4:	fd5516e3          	bne	a0,s5,1080 <malloc+0xb8>
        return 0;
    10b8:	00000513          	li	a0,0
    10bc:	02813483          	ld	s1,40(sp)
    10c0:	01013a03          	ld	s4,16(sp)
    10c4:	00813a83          	ld	s5,8(sp)
    10c8:	00013b03          	ld	s6,0(sp)
    10cc:	03c0006f          	j	1108 <malloc+0x140>
    10d0:	02813483          	ld	s1,40(sp)
    10d4:	01013a03          	ld	s4,16(sp)
    10d8:	00813a83          	ld	s5,8(sp)
    10dc:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    10e0:	f8e90ae3          	beq	s2,a4,1074 <malloc+0xac>
        p->s.size -= nunits;
    10e4:	4137073b          	subw	a4,a4,s3
    10e8:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    10ec:	02071693          	slli	a3,a4,0x20
    10f0:	01c6d713          	srli	a4,a3,0x1c
    10f4:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    10f8:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    10fc:	00001717          	auipc	a4,0x1
    1100:	f0a73e23          	sd	a0,-228(a4) # 2018 <freep>
      return (void*)(p + 1);
    1104:	01078513          	addi	a0,a5,16
  }
}
    1108:	03813083          	ld	ra,56(sp)
    110c:	03013403          	ld	s0,48(sp)
    1110:	02013903          	ld	s2,32(sp)
    1114:	01813983          	ld	s3,24(sp)
    1118:	04010113          	addi	sp,sp,64
    111c:	00008067          	ret
    1120:	02813483          	ld	s1,40(sp)
    1124:	01013a03          	ld	s4,16(sp)
    1128:	00813a83          	ld	s5,8(sp)
    112c:	00013b03          	ld	s6,0(sp)
    1130:	fd9ff06f          	j	1108 <malloc+0x140>
