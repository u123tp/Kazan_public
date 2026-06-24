
user/_usertests:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <copyinstr1>:
}

// what if you pass ridiculous string pointers to system calls?
void
copyinstr1(char *s)
{
       0:	fa010113          	addi	sp,sp,-96
       4:	04113c23          	sd	ra,88(sp)
       8:	04813823          	sd	s0,80(sp)
       c:	04913423          	sd	s1,72(sp)
      10:	05213023          	sd	s2,64(sp)
      14:	03313c23          	sd	s3,56(sp)
      18:	03413823          	sd	s4,48(sp)
      1c:	06010413          	addi	s0,sp,96
  uint64 addrs[] = { 0x80000000LL, 0x3fffffe000, 0x3ffffff000, 0x4000000000,
      20:	00009797          	auipc	a5,0x9
      24:	70078793          	addi	a5,a5,1792 # 9720 <malloc+0x26f8>
      28:	0007b583          	ld	a1,0(a5)
      2c:	0087b603          	ld	a2,8(a5)
      30:	0107b683          	ld	a3,16(a5)
      34:	0187b703          	ld	a4,24(a5)
      38:	fab43423          	sd	a1,-88(s0)
      3c:	fac43823          	sd	a2,-80(s0)
      40:	fad43c23          	sd	a3,-72(s0)
      44:	fce43023          	sd	a4,-64(s0)
      48:	0207b783          	ld	a5,32(a5)
      4c:	fcf43423          	sd	a5,-56(s0)
                     0xffffffffffffffff };

  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
      50:	fa840493          	addi	s1,s0,-88
      54:	fd040a13          	addi	s4,s0,-48
    uint64 addr = addrs[ai];

    int fd = open((char *)addr, O_CREATE|O_WRONLY);
      58:	20100993          	li	s3,513
      5c:	0004b903          	ld	s2,0(s1)
      60:	00098593          	mv	a1,s3
      64:	00090513          	mv	a0,s2
      68:	03d060ef          	jal	68a4 <open>
    if(fd >= 0){
      6c:	02055663          	bgez	a0,98 <copyinstr1+0x98>
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
      70:	00848493          	addi	s1,s1,8
      74:	ff4494e3          	bne	s1,s4,5c <copyinstr1+0x5c>
      printf("open(%p) returned %d, not -1\n", (void*)addr, fd);
      exit(1);
    }
  }
}
      78:	05813083          	ld	ra,88(sp)
      7c:	05013403          	ld	s0,80(sp)
      80:	04813483          	ld	s1,72(sp)
      84:	04013903          	ld	s2,64(sp)
      88:	03813983          	ld	s3,56(sp)
      8c:	03013a03          	ld	s4,48(sp)
      90:	06010113          	addi	sp,sp,96
      94:	00008067          	ret
      printf("open(%p) returned %d, not -1\n", (void*)addr, fd);
      98:	00050613          	mv	a2,a0
      9c:	00090593          	mv	a1,s2
      a0:	00007517          	auipc	a0,0x7
      a4:	10050513          	addi	a0,a0,256 # 71a0 <malloc+0x178>
      a8:	675060ef          	jal	6f1c <printf>
      exit(1);
      ac:	00100513          	li	a0,1
      b0:	794060ef          	jal	6844 <exit>

00000000000000b4 <bsstest>:
void
bsstest(char *s)
{
  int i;

  for(i = 0; i < sizeof(uninit); i++){
      b4:	0000b797          	auipc	a5,0xb
      b8:	4f478793          	addi	a5,a5,1268 # b5a8 <uninit>
      bc:	0000e697          	auipc	a3,0xe
      c0:	bfc68693          	addi	a3,a3,-1028 # dcb8 <buf>
    if(uninit[i] != '\0'){
      c4:	0007c703          	lbu	a4,0(a5)
      c8:	00071863          	bnez	a4,d8 <bsstest+0x24>
  for(i = 0; i < sizeof(uninit); i++){
      cc:	00178793          	addi	a5,a5,1
      d0:	fed79ae3          	bne	a5,a3,c4 <bsstest+0x10>
      d4:	00008067          	ret
{
      d8:	ff010113          	addi	sp,sp,-16
      dc:	00113423          	sd	ra,8(sp)
      e0:	00813023          	sd	s0,0(sp)
      e4:	01010413          	addi	s0,sp,16
      printf("%s: bss test failed\n", s);
      e8:	00050593          	mv	a1,a0
      ec:	00007517          	auipc	a0,0x7
      f0:	0d450513          	addi	a0,a0,212 # 71c0 <malloc+0x198>
      f4:	629060ef          	jal	6f1c <printf>
      exit(1);
      f8:	00100513          	li	a0,1
      fc:	748060ef          	jal	6844 <exit>

0000000000000100 <opentest>:
{
     100:	fe010113          	addi	sp,sp,-32
     104:	00113c23          	sd	ra,24(sp)
     108:	00813823          	sd	s0,16(sp)
     10c:	00913423          	sd	s1,8(sp)
     110:	02010413          	addi	s0,sp,32
     114:	00050493          	mv	s1,a0
  fd = open("echo", 0);
     118:	00000593          	li	a1,0
     11c:	00007517          	auipc	a0,0x7
     120:	0bc50513          	addi	a0,a0,188 # 71d8 <malloc+0x1b0>
     124:	780060ef          	jal	68a4 <open>
  if(fd < 0){
     128:	02054863          	bltz	a0,158 <opentest+0x58>
  close(fd);
     12c:	754060ef          	jal	6880 <close>
  fd = open("doesnotexist", 0);
     130:	00000593          	li	a1,0
     134:	00007517          	auipc	a0,0x7
     138:	0c450513          	addi	a0,a0,196 # 71f8 <malloc+0x1d0>
     13c:	768060ef          	jal	68a4 <open>
  if(fd >= 0){
     140:	02055863          	bgez	a0,170 <opentest+0x70>
}
     144:	01813083          	ld	ra,24(sp)
     148:	01013403          	ld	s0,16(sp)
     14c:	00813483          	ld	s1,8(sp)
     150:	02010113          	addi	sp,sp,32
     154:	00008067          	ret
    printf("%s: open echo failed!\n", s);
     158:	00048593          	mv	a1,s1
     15c:	00007517          	auipc	a0,0x7
     160:	08450513          	addi	a0,a0,132 # 71e0 <malloc+0x1b8>
     164:	5b9060ef          	jal	6f1c <printf>
    exit(1);
     168:	00100513          	li	a0,1
     16c:	6d8060ef          	jal	6844 <exit>
    printf("%s: open doesnotexist succeeded!\n", s);
     170:	00048593          	mv	a1,s1
     174:	00007517          	auipc	a0,0x7
     178:	09450513          	addi	a0,a0,148 # 7208 <malloc+0x1e0>
     17c:	5a1060ef          	jal	6f1c <printf>
    exit(1);
     180:	00100513          	li	a0,1
     184:	6c0060ef          	jal	6844 <exit>

0000000000000188 <truncate2>:
{
     188:	fd010113          	addi	sp,sp,-48
     18c:	02113423          	sd	ra,40(sp)
     190:	02813023          	sd	s0,32(sp)
     194:	00913c23          	sd	s1,24(sp)
     198:	01213823          	sd	s2,16(sp)
     19c:	01313423          	sd	s3,8(sp)
     1a0:	03010413          	addi	s0,sp,48
     1a4:	00050993          	mv	s3,a0
  unlink("truncfile");
     1a8:	00007517          	auipc	a0,0x7
     1ac:	08850513          	addi	a0,a0,136 # 7230 <malloc+0x208>
     1b0:	70c060ef          	jal	68bc <unlink>
  int fd1 = open("truncfile", O_CREATE|O_TRUNC|O_WRONLY);
     1b4:	60100593          	li	a1,1537
     1b8:	00007517          	auipc	a0,0x7
     1bc:	07850513          	addi	a0,a0,120 # 7230 <malloc+0x208>
     1c0:	6e4060ef          	jal	68a4 <open>
     1c4:	00050493          	mv	s1,a0
  write(fd1, "abcd", 4);
     1c8:	00400613          	li	a2,4
     1cc:	00007597          	auipc	a1,0x7
     1d0:	07458593          	addi	a1,a1,116 # 7240 <malloc+0x218>
     1d4:	6a0060ef          	jal	6874 <write>
  int fd2 = open("truncfile", O_TRUNC|O_WRONLY);
     1d8:	40100593          	li	a1,1025
     1dc:	00007517          	auipc	a0,0x7
     1e0:	05450513          	addi	a0,a0,84 # 7230 <malloc+0x208>
     1e4:	6c0060ef          	jal	68a4 <open>
     1e8:	00050913          	mv	s2,a0
  int n = write(fd1, "x", 1);
     1ec:	00100613          	li	a2,1
     1f0:	00007597          	auipc	a1,0x7
     1f4:	05858593          	addi	a1,a1,88 # 7248 <malloc+0x220>
     1f8:	00048513          	mv	a0,s1
     1fc:	678060ef          	jal	6874 <write>
  if(n != -1){
     200:	fff00793          	li	a5,-1
     204:	02f51e63          	bne	a0,a5,240 <truncate2+0xb8>
  unlink("truncfile");
     208:	00007517          	auipc	a0,0x7
     20c:	02850513          	addi	a0,a0,40 # 7230 <malloc+0x208>
     210:	6ac060ef          	jal	68bc <unlink>
  close(fd1);
     214:	00048513          	mv	a0,s1
     218:	668060ef          	jal	6880 <close>
  close(fd2);
     21c:	00090513          	mv	a0,s2
     220:	660060ef          	jal	6880 <close>
}
     224:	02813083          	ld	ra,40(sp)
     228:	02013403          	ld	s0,32(sp)
     22c:	01813483          	ld	s1,24(sp)
     230:	01013903          	ld	s2,16(sp)
     234:	00813983          	ld	s3,8(sp)
     238:	03010113          	addi	sp,sp,48
     23c:	00008067          	ret
    printf("%s: write returned %d, expected -1\n", s, n);
     240:	00050613          	mv	a2,a0
     244:	00098593          	mv	a1,s3
     248:	00007517          	auipc	a0,0x7
     24c:	00850513          	addi	a0,a0,8 # 7250 <malloc+0x228>
     250:	4cd060ef          	jal	6f1c <printf>
    exit(1);
     254:	00100513          	li	a0,1
     258:	5ec060ef          	jal	6844 <exit>

000000000000025c <createtest>:
{
     25c:	fc010113          	addi	sp,sp,-64
     260:	02113c23          	sd	ra,56(sp)
     264:	02813823          	sd	s0,48(sp)
     268:	02913423          	sd	s1,40(sp)
     26c:	03213023          	sd	s2,32(sp)
     270:	01313c23          	sd	s3,24(sp)
     274:	01413823          	sd	s4,16(sp)
     278:	04010413          	addi	s0,sp,64
  name[0] = 'a';
     27c:	06100793          	li	a5,97
     280:	fcf40423          	sb	a5,-56(s0)
  name[2] = '\0';
     284:	fc040523          	sb	zero,-54(s0)
     288:	03000493          	li	s1,48
    fd = open(name, O_CREATE|O_RDWR);
     28c:	fc840a13          	addi	s4,s0,-56
     290:	20200993          	li	s3,514
  for(i = 0; i < N; i++){
     294:	06400913          	li	s2,100
    name[1] = '0' + i;
     298:	fc9404a3          	sb	s1,-55(s0)
    fd = open(name, O_CREATE|O_RDWR);
     29c:	00098593          	mv	a1,s3
     2a0:	000a0513          	mv	a0,s4
     2a4:	600060ef          	jal	68a4 <open>
    close(fd);
     2a8:	5d8060ef          	jal	6880 <close>
  for(i = 0; i < N; i++){
     2ac:	0014849b          	addiw	s1,s1,1
     2b0:	0ff4f493          	zext.b	s1,s1
     2b4:	ff2492e3          	bne	s1,s2,298 <createtest+0x3c>
  name[0] = 'a';
     2b8:	06100793          	li	a5,97
     2bc:	fcf40423          	sb	a5,-56(s0)
  name[2] = '\0';
     2c0:	fc040523          	sb	zero,-54(s0)
     2c4:	03000493          	li	s1,48
    unlink(name);
     2c8:	fc840993          	addi	s3,s0,-56
  for(i = 0; i < N; i++){
     2cc:	06400913          	li	s2,100
    name[1] = '0' + i;
     2d0:	fc9404a3          	sb	s1,-55(s0)
    unlink(name);
     2d4:	00098513          	mv	a0,s3
     2d8:	5e4060ef          	jal	68bc <unlink>
  for(i = 0; i < N; i++){
     2dc:	0014849b          	addiw	s1,s1,1
     2e0:	0ff4f493          	zext.b	s1,s1
     2e4:	ff2496e3          	bne	s1,s2,2d0 <createtest+0x74>
}
     2e8:	03813083          	ld	ra,56(sp)
     2ec:	03013403          	ld	s0,48(sp)
     2f0:	02813483          	ld	s1,40(sp)
     2f4:	02013903          	ld	s2,32(sp)
     2f8:	01813983          	ld	s3,24(sp)
     2fc:	01013a03          	ld	s4,16(sp)
     300:	04010113          	addi	sp,sp,64
     304:	00008067          	ret

0000000000000308 <bigwrite>:
{
     308:	fa010113          	addi	sp,sp,-96
     30c:	04113c23          	sd	ra,88(sp)
     310:	04813823          	sd	s0,80(sp)
     314:	04913423          	sd	s1,72(sp)
     318:	05213023          	sd	s2,64(sp)
     31c:	03313c23          	sd	s3,56(sp)
     320:	03413823          	sd	s4,48(sp)
     324:	03513423          	sd	s5,40(sp)
     328:	03613023          	sd	s6,32(sp)
     32c:	01713c23          	sd	s7,24(sp)
     330:	01813823          	sd	s8,16(sp)
     334:	01913423          	sd	s9,8(sp)
     338:	06010413          	addi	s0,sp,96
     33c:	00050c93          	mv	s9,a0
  unlink("bigwrite");
     340:	00007517          	auipc	a0,0x7
     344:	f3850513          	addi	a0,a0,-200 # 7278 <malloc+0x250>
     348:	574060ef          	jal	68bc <unlink>
  for(sz = 499; sz < (MAXOPBLOCKS+2)*BSIZE; sz += 471){
     34c:	1f300493          	li	s1,499
    fd = open("bigwrite", O_CREATE | O_RDWR);
     350:	20200b93          	li	s7,514
     354:	00007a17          	auipc	s4,0x7
     358:	f24a0a13          	addi	s4,s4,-220 # 7278 <malloc+0x250>
     35c:	00200b13          	li	s6,2
      int cc = write(fd, buf, sz);
     360:	0000e997          	auipc	s3,0xe
     364:	95898993          	addi	s3,s3,-1704 # dcb8 <buf>
  for(sz = 499; sz < (MAXOPBLOCKS+2)*BSIZE; sz += 471){
     368:	00003ab7          	lui	s5,0x3
     36c:	1c9a8a93          	addi	s5,s5,457 # 31c9 <sbrkbugs+0x61>
    fd = open("bigwrite", O_CREATE | O_RDWR);
     370:	000b8593          	mv	a1,s7
     374:	000a0513          	mv	a0,s4
     378:	52c060ef          	jal	68a4 <open>
     37c:	00050913          	mv	s2,a0
    if(fd < 0){
     380:	06054863          	bltz	a0,3f0 <bigwrite+0xe8>
     384:	000b0c13          	mv	s8,s6
      int cc = write(fd, buf, sz);
     388:	00048613          	mv	a2,s1
     38c:	00098593          	mv	a1,s3
     390:	00090513          	mv	a0,s2
     394:	4e0060ef          	jal	6874 <write>
      if(cc != sz){
     398:	06951863          	bne	a0,s1,408 <bigwrite+0x100>
    for(i = 0; i < 2; i++){
     39c:	fffc0c1b          	addiw	s8,s8,-1
     3a0:	fe0c14e3          	bnez	s8,388 <bigwrite+0x80>
    close(fd);
     3a4:	00090513          	mv	a0,s2
     3a8:	4d8060ef          	jal	6880 <close>
    unlink("bigwrite");
     3ac:	000a0513          	mv	a0,s4
     3b0:	50c060ef          	jal	68bc <unlink>
  for(sz = 499; sz < (MAXOPBLOCKS+2)*BSIZE; sz += 471){
     3b4:	1d74849b          	addiw	s1,s1,471
     3b8:	fb549ce3          	bne	s1,s5,370 <bigwrite+0x68>
}
     3bc:	05813083          	ld	ra,88(sp)
     3c0:	05013403          	ld	s0,80(sp)
     3c4:	04813483          	ld	s1,72(sp)
     3c8:	04013903          	ld	s2,64(sp)
     3cc:	03813983          	ld	s3,56(sp)
     3d0:	03013a03          	ld	s4,48(sp)
     3d4:	02813a83          	ld	s5,40(sp)
     3d8:	02013b03          	ld	s6,32(sp)
     3dc:	01813b83          	ld	s7,24(sp)
     3e0:	01013c03          	ld	s8,16(sp)
     3e4:	00813c83          	ld	s9,8(sp)
     3e8:	06010113          	addi	sp,sp,96
     3ec:	00008067          	ret
      printf("%s: cannot create bigwrite\n", s);
     3f0:	000c8593          	mv	a1,s9
     3f4:	00007517          	auipc	a0,0x7
     3f8:	e9450513          	addi	a0,a0,-364 # 7288 <malloc+0x260>
     3fc:	321060ef          	jal	6f1c <printf>
      exit(1);
     400:	00100513          	li	a0,1
     404:	440060ef          	jal	6844 <exit>
        printf("%s: write(%d) ret %d\n", s, sz, cc);
     408:	00050693          	mv	a3,a0
     40c:	00048613          	mv	a2,s1
     410:	000c8593          	mv	a1,s9
     414:	00007517          	auipc	a0,0x7
     418:	e9450513          	addi	a0,a0,-364 # 72a8 <malloc+0x280>
     41c:	301060ef          	jal	6f1c <printf>
        exit(1);
     420:	00100513          	li	a0,1
     424:	420060ef          	jal	6844 <exit>

0000000000000428 <badwrite>:
// file is deleted? if the kernel has this bug, it will panic: balloc:
// out of blocks. assumed_free may need to be raised to be more than
// the number of free blocks. this test takes a long time.
void
badwrite(char *s)
{
     428:	fc010113          	addi	sp,sp,-64
     42c:	02113c23          	sd	ra,56(sp)
     430:	02813823          	sd	s0,48(sp)
     434:	02913423          	sd	s1,40(sp)
     438:	03213023          	sd	s2,32(sp)
     43c:	01313c23          	sd	s3,24(sp)
     440:	01413823          	sd	s4,16(sp)
     444:	01513423          	sd	s5,8(sp)
     448:	01613023          	sd	s6,0(sp)
     44c:	04010413          	addi	s0,sp,64
  int assumed_free = 600;
  
  unlink("junk");
     450:	00007517          	auipc	a0,0x7
     454:	e7050513          	addi	a0,a0,-400 # 72c0 <malloc+0x298>
     458:	464060ef          	jal	68bc <unlink>
     45c:	25800913          	li	s2,600
  for(int i = 0; i < assumed_free; i++){
    int fd = open("junk", O_CREATE|O_WRONLY);
     460:	20100a93          	li	s5,513
     464:	00007997          	auipc	s3,0x7
     468:	e5c98993          	addi	s3,s3,-420 # 72c0 <malloc+0x298>
    if(fd < 0){
      printf("open junk failed\n");
      exit(1);
    }
    write(fd, (char*)0xffffffffffL, 1);
     46c:	00100b13          	li	s6,1
     470:	fff00a13          	li	s4,-1
     474:	018a5a13          	srli	s4,s4,0x18
    int fd = open("junk", O_CREATE|O_WRONLY);
     478:	000a8593          	mv	a1,s5
     47c:	00098513          	mv	a0,s3
     480:	424060ef          	jal	68a4 <open>
     484:	00050493          	mv	s1,a0
    if(fd < 0){
     488:	06054663          	bltz	a0,4f4 <badwrite+0xcc>
    write(fd, (char*)0xffffffffffL, 1);
     48c:	000b0613          	mv	a2,s6
     490:	000a0593          	mv	a1,s4
     494:	3e0060ef          	jal	6874 <write>
    close(fd);
     498:	00048513          	mv	a0,s1
     49c:	3e4060ef          	jal	6880 <close>
    unlink("junk");
     4a0:	00098513          	mv	a0,s3
     4a4:	418060ef          	jal	68bc <unlink>
  for(int i = 0; i < assumed_free; i++){
     4a8:	fff9091b          	addiw	s2,s2,-1
     4ac:	fc0916e3          	bnez	s2,478 <badwrite+0x50>
  }

  int fd = open("junk", O_CREATE|O_WRONLY);
     4b0:	20100593          	li	a1,513
     4b4:	00007517          	auipc	a0,0x7
     4b8:	e0c50513          	addi	a0,a0,-500 # 72c0 <malloc+0x298>
     4bc:	3e8060ef          	jal	68a4 <open>
     4c0:	00050493          	mv	s1,a0
  if(fd < 0){
     4c4:	04054263          	bltz	a0,508 <badwrite+0xe0>
    printf("open junk failed\n");
    exit(1);
  }
  if(write(fd, "x", 1) != 1){
     4c8:	00100613          	li	a2,1
     4cc:	00007597          	auipc	a1,0x7
     4d0:	d7c58593          	addi	a1,a1,-644 # 7248 <malloc+0x220>
     4d4:	3a0060ef          	jal	6874 <write>
     4d8:	00100793          	li	a5,1
     4dc:	04f50063          	beq	a0,a5,51c <badwrite+0xf4>
    printf("write failed\n");
     4e0:	00007517          	auipc	a0,0x7
     4e4:	e0050513          	addi	a0,a0,-512 # 72e0 <malloc+0x2b8>
     4e8:	235060ef          	jal	6f1c <printf>
    exit(1);
     4ec:	00100513          	li	a0,1
     4f0:	354060ef          	jal	6844 <exit>
      printf("open junk failed\n");
     4f4:	00007517          	auipc	a0,0x7
     4f8:	dd450513          	addi	a0,a0,-556 # 72c8 <malloc+0x2a0>
     4fc:	221060ef          	jal	6f1c <printf>
      exit(1);
     500:	00100513          	li	a0,1
     504:	340060ef          	jal	6844 <exit>
    printf("open junk failed\n");
     508:	00007517          	auipc	a0,0x7
     50c:	dc050513          	addi	a0,a0,-576 # 72c8 <malloc+0x2a0>
     510:	20d060ef          	jal	6f1c <printf>
    exit(1);
     514:	00100513          	li	a0,1
     518:	32c060ef          	jal	6844 <exit>
  }
  close(fd);
     51c:	00048513          	mv	a0,s1
     520:	360060ef          	jal	6880 <close>
  unlink("junk");
     524:	00007517          	auipc	a0,0x7
     528:	d9c50513          	addi	a0,a0,-612 # 72c0 <malloc+0x298>
     52c:	390060ef          	jal	68bc <unlink>

  exit(0);
     530:	00000513          	li	a0,0
     534:	310060ef          	jal	6844 <exit>

0000000000000538 <outofinodes>:
  }
}

void
outofinodes(char *s)
{
     538:	fa010113          	addi	sp,sp,-96
     53c:	04113c23          	sd	ra,88(sp)
     540:	04813823          	sd	s0,80(sp)
     544:	04913423          	sd	s1,72(sp)
     548:	05213023          	sd	s2,64(sp)
     54c:	03313c23          	sd	s3,56(sp)
     550:	03413823          	sd	s4,48(sp)
     554:	03513423          	sd	s5,40(sp)
     558:	06010413          	addi	s0,sp,96
  int nzz = 32*32;
  for(int i = 0; i < nzz; i++){
     55c:	00000493          	li	s1,0
    char name[32];
    name[0] = 'z';
     560:	07a00993          	li	s3,122
    name[1] = 'z';
    name[2] = '0' + (i / 32);
    name[3] = '0' + (i % 32);
    name[4] = '\0';
    unlink(name);
     564:	fa040913          	addi	s2,s0,-96
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
     568:	60200a13          	li	s4,1538
  for(int i = 0; i < nzz; i++){
     56c:	40000a93          	li	s5,1024
    name[0] = 'z';
     570:	fb340023          	sb	s3,-96(s0)
    name[1] = 'z';
     574:	fb3400a3          	sb	s3,-95(s0)
    name[2] = '0' + (i / 32);
     578:	41f4d71b          	sraiw	a4,s1,0x1f
     57c:	01b7571b          	srliw	a4,a4,0x1b
     580:	009707bb          	addw	a5,a4,s1
     584:	4057d69b          	sraiw	a3,a5,0x5
     588:	0306869b          	addiw	a3,a3,48
     58c:	fad40123          	sb	a3,-94(s0)
    name[3] = '0' + (i % 32);
     590:	01f7f793          	andi	a5,a5,31
     594:	40e787bb          	subw	a5,a5,a4
     598:	0307879b          	addiw	a5,a5,48
     59c:	faf401a3          	sb	a5,-93(s0)
    name[4] = '\0';
     5a0:	fa040223          	sb	zero,-92(s0)
    unlink(name);
     5a4:	00090513          	mv	a0,s2
     5a8:	314060ef          	jal	68bc <unlink>
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
     5ac:	000a0593          	mv	a1,s4
     5b0:	00090513          	mv	a0,s2
     5b4:	2f0060ef          	jal	68a4 <open>
    if(fd < 0){
     5b8:	00054863          	bltz	a0,5c8 <outofinodes+0x90>
      // failure is eventually expected.
      break;
    }
    close(fd);
     5bc:	2c4060ef          	jal	6880 <close>
  for(int i = 0; i < nzz; i++){
     5c0:	0014849b          	addiw	s1,s1,1
     5c4:	fb5496e3          	bne	s1,s5,570 <outofinodes+0x38>
     5c8:	00000493          	li	s1,0
  }

  for(int i = 0; i < nzz; i++){
    char name[32];
    name[0] = 'z';
     5cc:	07a00913          	li	s2,122
    name[1] = 'z';
    name[2] = '0' + (i / 32);
    name[3] = '0' + (i % 32);
    name[4] = '\0';
    unlink(name);
     5d0:	fa040a13          	addi	s4,s0,-96
  for(int i = 0; i < nzz; i++){
     5d4:	40000993          	li	s3,1024
    name[0] = 'z';
     5d8:	fb240023          	sb	s2,-96(s0)
    name[1] = 'z';
     5dc:	fb2400a3          	sb	s2,-95(s0)
    name[2] = '0' + (i / 32);
     5e0:	41f4d71b          	sraiw	a4,s1,0x1f
     5e4:	01b7571b          	srliw	a4,a4,0x1b
     5e8:	009707bb          	addw	a5,a4,s1
     5ec:	4057d69b          	sraiw	a3,a5,0x5
     5f0:	0306869b          	addiw	a3,a3,48
     5f4:	fad40123          	sb	a3,-94(s0)
    name[3] = '0' + (i % 32);
     5f8:	01f7f793          	andi	a5,a5,31
     5fc:	40e787bb          	subw	a5,a5,a4
     600:	0307879b          	addiw	a5,a5,48
     604:	faf401a3          	sb	a5,-93(s0)
    name[4] = '\0';
     608:	fa040223          	sb	zero,-92(s0)
    unlink(name);
     60c:	000a0513          	mv	a0,s4
     610:	2ac060ef          	jal	68bc <unlink>
  for(int i = 0; i < nzz; i++){
     614:	0014849b          	addiw	s1,s1,1
     618:	fd3490e3          	bne	s1,s3,5d8 <outofinodes+0xa0>
  }
}
     61c:	05813083          	ld	ra,88(sp)
     620:	05013403          	ld	s0,80(sp)
     624:	04813483          	ld	s1,72(sp)
     628:	04013903          	ld	s2,64(sp)
     62c:	03813983          	ld	s3,56(sp)
     630:	03013a03          	ld	s4,48(sp)
     634:	02813a83          	ld	s5,40(sp)
     638:	06010113          	addi	sp,sp,96
     63c:	00008067          	ret

0000000000000640 <copyin>:
{
     640:	f7010113          	addi	sp,sp,-144
     644:	08113423          	sd	ra,136(sp)
     648:	08813023          	sd	s0,128(sp)
     64c:	06913c23          	sd	s1,120(sp)
     650:	07213823          	sd	s2,112(sp)
     654:	07313423          	sd	s3,104(sp)
     658:	07413023          	sd	s4,96(sp)
     65c:	05513c23          	sd	s5,88(sp)
     660:	05613823          	sd	s6,80(sp)
     664:	05713423          	sd	s7,72(sp)
     668:	05813023          	sd	s8,64(sp)
     66c:	03913c23          	sd	s9,56(sp)
     670:	09010413          	addi	s0,sp,144
  uint64 addrs[] = { 0x80000000LL, 0x3fffffe000, 0x3ffffff000, 0x4000000000,
     674:	00009797          	auipc	a5,0x9
     678:	0ac78793          	addi	a5,a5,172 # 9720 <malloc+0x26f8>
     67c:	0007b583          	ld	a1,0(a5)
     680:	0087b603          	ld	a2,8(a5)
     684:	0107b683          	ld	a3,16(a5)
     688:	0187b703          	ld	a4,24(a5)
     68c:	f6b43c23          	sd	a1,-136(s0)
     690:	f8c43023          	sd	a2,-128(s0)
     694:	f8d43423          	sd	a3,-120(s0)
     698:	f8e43823          	sd	a4,-112(s0)
     69c:	0207b783          	ld	a5,32(a5)
     6a0:	f8f43c23          	sd	a5,-104(s0)
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
     6a4:	f7840913          	addi	s2,s0,-136
     6a8:	fa040c93          	addi	s9,s0,-96
    int fd = open("copyin1", O_CREATE|O_WRONLY);
     6ac:	20100b13          	li	s6,513
     6b0:	00007a97          	auipc	s5,0x7
     6b4:	c40a8a93          	addi	s5,s5,-960 # 72f0 <malloc+0x2c8>
    int n = write(fd, (void*)addr, 8192);
     6b8:	00002a37          	lui	s4,0x2
    n = write(1, (char*)addr, 8192);
     6bc:	00100c13          	li	s8,1
    if(pipe(fds) < 0){
     6c0:	f7040b93          	addi	s7,s0,-144
    uint64 addr = addrs[ai];
     6c4:	00093983          	ld	s3,0(s2)
    int fd = open("copyin1", O_CREATE|O_WRONLY);
     6c8:	000b0593          	mv	a1,s6
     6cc:	000a8513          	mv	a0,s5
     6d0:	1d4060ef          	jal	68a4 <open>
     6d4:	00050493          	mv	s1,a0
    if(fd < 0){
     6d8:	0a054263          	bltz	a0,77c <copyin+0x13c>
    int n = write(fd, (void*)addr, 8192);
     6dc:	000a0613          	mv	a2,s4
     6e0:	00098593          	mv	a1,s3
     6e4:	190060ef          	jal	6874 <write>
    if(n >= 0){
     6e8:	0a055463          	bgez	a0,790 <copyin+0x150>
    close(fd);
     6ec:	00048513          	mv	a0,s1
     6f0:	190060ef          	jal	6880 <close>
    unlink("copyin1");
     6f4:	000a8513          	mv	a0,s5
     6f8:	1c4060ef          	jal	68bc <unlink>
    n = write(1, (char*)addr, 8192);
     6fc:	000a0613          	mv	a2,s4
     700:	00098593          	mv	a1,s3
     704:	000c0513          	mv	a0,s8
     708:	16c060ef          	jal	6874 <write>
    if(n > 0){
     70c:	0aa04063          	bgtz	a0,7ac <copyin+0x16c>
    if(pipe(fds) < 0){
     710:	000b8513          	mv	a0,s7
     714:	148060ef          	jal	685c <pipe>
     718:	0a054863          	bltz	a0,7c8 <copyin+0x188>
    n = write(fds[1], (char*)addr, 8192);
     71c:	000a0613          	mv	a2,s4
     720:	00098593          	mv	a1,s3
     724:	f7442503          	lw	a0,-140(s0)
     728:	14c060ef          	jal	6874 <write>
    if(n > 0){
     72c:	0aa04863          	bgtz	a0,7dc <copyin+0x19c>
    close(fds[0]);
     730:	f7042503          	lw	a0,-144(s0)
     734:	14c060ef          	jal	6880 <close>
    close(fds[1]);
     738:	f7442503          	lw	a0,-140(s0)
     73c:	144060ef          	jal	6880 <close>
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
     740:	00890913          	addi	s2,s2,8
     744:	f99910e3          	bne	s2,s9,6c4 <copyin+0x84>
}
     748:	08813083          	ld	ra,136(sp)
     74c:	08013403          	ld	s0,128(sp)
     750:	07813483          	ld	s1,120(sp)
     754:	07013903          	ld	s2,112(sp)
     758:	06813983          	ld	s3,104(sp)
     75c:	06013a03          	ld	s4,96(sp)
     760:	05813a83          	ld	s5,88(sp)
     764:	05013b03          	ld	s6,80(sp)
     768:	04813b83          	ld	s7,72(sp)
     76c:	04013c03          	ld	s8,64(sp)
     770:	03813c83          	ld	s9,56(sp)
     774:	09010113          	addi	sp,sp,144
     778:	00008067          	ret
      printf("open(copyin1) failed\n");
     77c:	00007517          	auipc	a0,0x7
     780:	b7c50513          	addi	a0,a0,-1156 # 72f8 <malloc+0x2d0>
     784:	798060ef          	jal	6f1c <printf>
      exit(1);
     788:	00100513          	li	a0,1
     78c:	0b8060ef          	jal	6844 <exit>
      printf("write(fd, %p, 8192) returned %d, not -1\n", (void*)addr, n);
     790:	00050613          	mv	a2,a0
     794:	00098593          	mv	a1,s3
     798:	00007517          	auipc	a0,0x7
     79c:	b7850513          	addi	a0,a0,-1160 # 7310 <malloc+0x2e8>
     7a0:	77c060ef          	jal	6f1c <printf>
      exit(1);
     7a4:	00100513          	li	a0,1
     7a8:	09c060ef          	jal	6844 <exit>
      printf("write(1, %p, 8192) returned %d, not -1 or 0\n", (void*)addr, n);
     7ac:	00050613          	mv	a2,a0
     7b0:	00098593          	mv	a1,s3
     7b4:	00007517          	auipc	a0,0x7
     7b8:	b8c50513          	addi	a0,a0,-1140 # 7340 <malloc+0x318>
     7bc:	760060ef          	jal	6f1c <printf>
      exit(1);
     7c0:	00100513          	li	a0,1
     7c4:	080060ef          	jal	6844 <exit>
      printf("pipe() failed\n");
     7c8:	00007517          	auipc	a0,0x7
     7cc:	ba850513          	addi	a0,a0,-1112 # 7370 <malloc+0x348>
     7d0:	74c060ef          	jal	6f1c <printf>
      exit(1);
     7d4:	00100513          	li	a0,1
     7d8:	06c060ef          	jal	6844 <exit>
      printf("write(pipe, %p, 8192) returned %d, not -1 or 0\n", (void*)addr, n);
     7dc:	00050613          	mv	a2,a0
     7e0:	00098593          	mv	a1,s3
     7e4:	00007517          	auipc	a0,0x7
     7e8:	b9c50513          	addi	a0,a0,-1124 # 7380 <malloc+0x358>
     7ec:	730060ef          	jal	6f1c <printf>
      exit(1);
     7f0:	00100513          	li	a0,1
     7f4:	050060ef          	jal	6844 <exit>

00000000000007f8 <copyout>:
{
     7f8:	f6010113          	addi	sp,sp,-160
     7fc:	08113c23          	sd	ra,152(sp)
     800:	08813823          	sd	s0,144(sp)
     804:	08913423          	sd	s1,136(sp)
     808:	09213023          	sd	s2,128(sp)
     80c:	07313c23          	sd	s3,120(sp)
     810:	07413823          	sd	s4,112(sp)
     814:	07513423          	sd	s5,104(sp)
     818:	07613023          	sd	s6,96(sp)
     81c:	05713c23          	sd	s7,88(sp)
     820:	05813823          	sd	s8,80(sp)
     824:	05913423          	sd	s9,72(sp)
     828:	0a010413          	addi	s0,sp,160
  uint64 addrs[] = { 0LL, 0x80000000LL, 0x3fffffe000, 0x3ffffff000, 0x4000000000,
     82c:	00009797          	auipc	a5,0x9
     830:	ef478793          	addi	a5,a5,-268 # 9720 <malloc+0x26f8>
     834:	0287b503          	ld	a0,40(a5)
     838:	0307b583          	ld	a1,48(a5)
     83c:	0387b603          	ld	a2,56(a5)
     840:	0407b683          	ld	a3,64(a5)
     844:	0487b703          	ld	a4,72(a5)
     848:	f6a43823          	sd	a0,-144(s0)
     84c:	f6b43c23          	sd	a1,-136(s0)
     850:	f8c43023          	sd	a2,-128(s0)
     854:	f8d43423          	sd	a3,-120(s0)
     858:	f8e43823          	sd	a4,-112(s0)
     85c:	0507b783          	ld	a5,80(a5)
     860:	f8f43c23          	sd	a5,-104(s0)
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
     864:	f7040913          	addi	s2,s0,-144
     868:	fa040c93          	addi	s9,s0,-96
    int fd = open("README", 0);
     86c:	00007b17          	auipc	s6,0x7
     870:	b44b0b13          	addi	s6,s6,-1212 # 73b0 <malloc+0x388>
    int n = read(fd, (void*)addr, 8192);
     874:	00002ab7          	lui	s5,0x2
    if(pipe(fds) < 0){
     878:	f6840c13          	addi	s8,s0,-152
    n = write(fds[1], "x", 1);
     87c:	00100a13          	li	s4,1
     880:	00007b97          	auipc	s7,0x7
     884:	9c8b8b93          	addi	s7,s7,-1592 # 7248 <malloc+0x220>
    uint64 addr = addrs[ai];
     888:	00093983          	ld	s3,0(s2)
    int fd = open("README", 0);
     88c:	00000593          	li	a1,0
     890:	000b0513          	mv	a0,s6
     894:	010060ef          	jal	68a4 <open>
     898:	00050493          	mv	s1,a0
    if(fd < 0){
     89c:	08054e63          	bltz	a0,938 <copyout+0x140>
    int n = read(fd, (void*)addr, 8192);
     8a0:	000a8613          	mv	a2,s5
     8a4:	00098593          	mv	a1,s3
     8a8:	7c1050ef          	jal	6868 <read>
    if(n > 0){
     8ac:	0aa04063          	bgtz	a0,94c <copyout+0x154>
    close(fd);
     8b0:	00048513          	mv	a0,s1
     8b4:	7cd050ef          	jal	6880 <close>
    if(pipe(fds) < 0){
     8b8:	000c0513          	mv	a0,s8
     8bc:	7a1050ef          	jal	685c <pipe>
     8c0:	0a054463          	bltz	a0,968 <copyout+0x170>
    n = write(fds[1], "x", 1);
     8c4:	000a0613          	mv	a2,s4
     8c8:	000b8593          	mv	a1,s7
     8cc:	f6c42503          	lw	a0,-148(s0)
     8d0:	7a5050ef          	jal	6874 <write>
    if(n != 1){
     8d4:	0b451463          	bne	a0,s4,97c <copyout+0x184>
    n = read(fds[0], (void*)addr, 8192);
     8d8:	000a8613          	mv	a2,s5
     8dc:	00098593          	mv	a1,s3
     8e0:	f6842503          	lw	a0,-152(s0)
     8e4:	785050ef          	jal	6868 <read>
    if(n > 0){
     8e8:	0aa04463          	bgtz	a0,990 <copyout+0x198>
    close(fds[0]);
     8ec:	f6842503          	lw	a0,-152(s0)
     8f0:	791050ef          	jal	6880 <close>
    close(fds[1]);
     8f4:	f6c42503          	lw	a0,-148(s0)
     8f8:	789050ef          	jal	6880 <close>
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
     8fc:	00890913          	addi	s2,s2,8
     900:	f99914e3          	bne	s2,s9,888 <copyout+0x90>
}
     904:	09813083          	ld	ra,152(sp)
     908:	09013403          	ld	s0,144(sp)
     90c:	08813483          	ld	s1,136(sp)
     910:	08013903          	ld	s2,128(sp)
     914:	07813983          	ld	s3,120(sp)
     918:	07013a03          	ld	s4,112(sp)
     91c:	06813a83          	ld	s5,104(sp)
     920:	06013b03          	ld	s6,96(sp)
     924:	05813b83          	ld	s7,88(sp)
     928:	05013c03          	ld	s8,80(sp)
     92c:	04813c83          	ld	s9,72(sp)
     930:	0a010113          	addi	sp,sp,160
     934:	00008067          	ret
      printf("open(README) failed\n");
     938:	00007517          	auipc	a0,0x7
     93c:	a8050513          	addi	a0,a0,-1408 # 73b8 <malloc+0x390>
     940:	5dc060ef          	jal	6f1c <printf>
      exit(1);
     944:	00100513          	li	a0,1
     948:	6fd050ef          	jal	6844 <exit>
      printf("read(fd, %p, 8192) returned %d, not -1 or 0\n", (void*)addr, n);
     94c:	00050613          	mv	a2,a0
     950:	00098593          	mv	a1,s3
     954:	00007517          	auipc	a0,0x7
     958:	a7c50513          	addi	a0,a0,-1412 # 73d0 <malloc+0x3a8>
     95c:	5c0060ef          	jal	6f1c <printf>
      exit(1);
     960:	00100513          	li	a0,1
     964:	6e1050ef          	jal	6844 <exit>
      printf("pipe() failed\n");
     968:	00007517          	auipc	a0,0x7
     96c:	a0850513          	addi	a0,a0,-1528 # 7370 <malloc+0x348>
     970:	5ac060ef          	jal	6f1c <printf>
      exit(1);
     974:	00100513          	li	a0,1
     978:	6cd050ef          	jal	6844 <exit>
      printf("pipe write failed\n");
     97c:	00007517          	auipc	a0,0x7
     980:	a8450513          	addi	a0,a0,-1404 # 7400 <malloc+0x3d8>
     984:	598060ef          	jal	6f1c <printf>
      exit(1);
     988:	00100513          	li	a0,1
     98c:	6b9050ef          	jal	6844 <exit>
      printf("read(pipe, %p, 8192) returned %d, not -1 or 0\n", (void*)addr, n);
     990:	00050613          	mv	a2,a0
     994:	00098593          	mv	a1,s3
     998:	00007517          	auipc	a0,0x7
     99c:	a8050513          	addi	a0,a0,-1408 # 7418 <malloc+0x3f0>
     9a0:	57c060ef          	jal	6f1c <printf>
      exit(1);
     9a4:	00100513          	li	a0,1
     9a8:	69d050ef          	jal	6844 <exit>

00000000000009ac <truncate1>:
{
     9ac:	fa010113          	addi	sp,sp,-96
     9b0:	04113c23          	sd	ra,88(sp)
     9b4:	04813823          	sd	s0,80(sp)
     9b8:	04913423          	sd	s1,72(sp)
     9bc:	05213023          	sd	s2,64(sp)
     9c0:	03313c23          	sd	s3,56(sp)
     9c4:	03413823          	sd	s4,48(sp)
     9c8:	03513423          	sd	s5,40(sp)
     9cc:	06010413          	addi	s0,sp,96
     9d0:	00050a13          	mv	s4,a0
  unlink("truncfile");
     9d4:	00007517          	auipc	a0,0x7
     9d8:	85c50513          	addi	a0,a0,-1956 # 7230 <malloc+0x208>
     9dc:	6e1050ef          	jal	68bc <unlink>
  int fd1 = open("truncfile", O_CREATE|O_WRONLY|O_TRUNC);
     9e0:	60100593          	li	a1,1537
     9e4:	00007517          	auipc	a0,0x7
     9e8:	84c50513          	addi	a0,a0,-1972 # 7230 <malloc+0x208>
     9ec:	6b9050ef          	jal	68a4 <open>
     9f0:	00050493          	mv	s1,a0
  write(fd1, "abcd", 4);
     9f4:	00400613          	li	a2,4
     9f8:	00007597          	auipc	a1,0x7
     9fc:	84858593          	addi	a1,a1,-1976 # 7240 <malloc+0x218>
     a00:	675050ef          	jal	6874 <write>
  close(fd1);
     a04:	00048513          	mv	a0,s1
     a08:	679050ef          	jal	6880 <close>
  int fd2 = open("truncfile", O_RDONLY);
     a0c:	00000593          	li	a1,0
     a10:	00007517          	auipc	a0,0x7
     a14:	82050513          	addi	a0,a0,-2016 # 7230 <malloc+0x208>
     a18:	68d050ef          	jal	68a4 <open>
     a1c:	00050493          	mv	s1,a0
  int n = read(fd2, buf, sizeof(buf));
     a20:	02000613          	li	a2,32
     a24:	fa040593          	addi	a1,s0,-96
     a28:	641050ef          	jal	6868 <read>
  if(n != 4){
     a2c:	00400793          	li	a5,4
     a30:	0ef51263          	bne	a0,a5,b14 <truncate1+0x168>
  fd1 = open("truncfile", O_WRONLY|O_TRUNC);
     a34:	40100593          	li	a1,1025
     a38:	00006517          	auipc	a0,0x6
     a3c:	7f850513          	addi	a0,a0,2040 # 7230 <malloc+0x208>
     a40:	665050ef          	jal	68a4 <open>
     a44:	00050993          	mv	s3,a0
  int fd3 = open("truncfile", O_RDONLY);
     a48:	00000593          	li	a1,0
     a4c:	00006517          	auipc	a0,0x6
     a50:	7e450513          	addi	a0,a0,2020 # 7230 <malloc+0x208>
     a54:	651050ef          	jal	68a4 <open>
     a58:	00050913          	mv	s2,a0
  n = read(fd3, buf, sizeof(buf));
     a5c:	02000613          	li	a2,32
     a60:	fa040593          	addi	a1,s0,-96
     a64:	605050ef          	jal	6868 <read>
     a68:	00050a93          	mv	s5,a0
  if(n != 0){
     a6c:	0c051263          	bnez	a0,b30 <truncate1+0x184>
  n = read(fd2, buf, sizeof(buf));
     a70:	02000613          	li	a2,32
     a74:	fa040593          	addi	a1,s0,-96
     a78:	00048513          	mv	a0,s1
     a7c:	5ed050ef          	jal	6868 <read>
     a80:	00050a93          	mv	s5,a0
  if(n != 0){
     a84:	0c051c63          	bnez	a0,b5c <truncate1+0x1b0>
  write(fd1, "abcdef", 6);
     a88:	00600613          	li	a2,6
     a8c:	00007597          	auipc	a1,0x7
     a90:	a1c58593          	addi	a1,a1,-1508 # 74a8 <malloc+0x480>
     a94:	00098513          	mv	a0,s3
     a98:	5dd050ef          	jal	6874 <write>
  n = read(fd3, buf, sizeof(buf));
     a9c:	02000613          	li	a2,32
     aa0:	fa040593          	addi	a1,s0,-96
     aa4:	00090513          	mv	a0,s2
     aa8:	5c1050ef          	jal	6868 <read>
  if(n != 6){
     aac:	00600793          	li	a5,6
     ab0:	0cf51c63          	bne	a0,a5,b88 <truncate1+0x1dc>
  n = read(fd2, buf, sizeof(buf));
     ab4:	02000613          	li	a2,32
     ab8:	fa040593          	addi	a1,s0,-96
     abc:	00048513          	mv	a0,s1
     ac0:	5a9050ef          	jal	6868 <read>
  if(n != 2){
     ac4:	00200793          	li	a5,2
     ac8:	0cf51e63          	bne	a0,a5,ba4 <truncate1+0x1f8>
  unlink("truncfile");
     acc:	00006517          	auipc	a0,0x6
     ad0:	76450513          	addi	a0,a0,1892 # 7230 <malloc+0x208>
     ad4:	5e9050ef          	jal	68bc <unlink>
  close(fd1);
     ad8:	00098513          	mv	a0,s3
     adc:	5a5050ef          	jal	6880 <close>
  close(fd2);
     ae0:	00048513          	mv	a0,s1
     ae4:	59d050ef          	jal	6880 <close>
  close(fd3);
     ae8:	00090513          	mv	a0,s2
     aec:	595050ef          	jal	6880 <close>
}
     af0:	05813083          	ld	ra,88(sp)
     af4:	05013403          	ld	s0,80(sp)
     af8:	04813483          	ld	s1,72(sp)
     afc:	04013903          	ld	s2,64(sp)
     b00:	03813983          	ld	s3,56(sp)
     b04:	03013a03          	ld	s4,48(sp)
     b08:	02813a83          	ld	s5,40(sp)
     b0c:	06010113          	addi	sp,sp,96
     b10:	00008067          	ret
    printf("%s: read %d bytes, wanted 4\n", s, n);
     b14:	00050613          	mv	a2,a0
     b18:	000a0593          	mv	a1,s4
     b1c:	00007517          	auipc	a0,0x7
     b20:	92c50513          	addi	a0,a0,-1748 # 7448 <malloc+0x420>
     b24:	3f8060ef          	jal	6f1c <printf>
    exit(1);
     b28:	00100513          	li	a0,1
     b2c:	519050ef          	jal	6844 <exit>
    printf("aaa fd3=%d\n", fd3);
     b30:	00090593          	mv	a1,s2
     b34:	00007517          	auipc	a0,0x7
     b38:	93450513          	addi	a0,a0,-1740 # 7468 <malloc+0x440>
     b3c:	3e0060ef          	jal	6f1c <printf>
    printf("%s: read %d bytes, wanted 0\n", s, n);
     b40:	000a8613          	mv	a2,s5
     b44:	000a0593          	mv	a1,s4
     b48:	00007517          	auipc	a0,0x7
     b4c:	93050513          	addi	a0,a0,-1744 # 7478 <malloc+0x450>
     b50:	3cc060ef          	jal	6f1c <printf>
    exit(1);
     b54:	00100513          	li	a0,1
     b58:	4ed050ef          	jal	6844 <exit>
    printf("bbb fd2=%d\n", fd2);
     b5c:	00048593          	mv	a1,s1
     b60:	00007517          	auipc	a0,0x7
     b64:	93850513          	addi	a0,a0,-1736 # 7498 <malloc+0x470>
     b68:	3b4060ef          	jal	6f1c <printf>
    printf("%s: read %d bytes, wanted 0\n", s, n);
     b6c:	000a8613          	mv	a2,s5
     b70:	000a0593          	mv	a1,s4
     b74:	00007517          	auipc	a0,0x7
     b78:	90450513          	addi	a0,a0,-1788 # 7478 <malloc+0x450>
     b7c:	3a0060ef          	jal	6f1c <printf>
    exit(1);
     b80:	00100513          	li	a0,1
     b84:	4c1050ef          	jal	6844 <exit>
    printf("%s: read %d bytes, wanted 6\n", s, n);
     b88:	00050613          	mv	a2,a0
     b8c:	000a0593          	mv	a1,s4
     b90:	00007517          	auipc	a0,0x7
     b94:	92050513          	addi	a0,a0,-1760 # 74b0 <malloc+0x488>
     b98:	384060ef          	jal	6f1c <printf>
    exit(1);
     b9c:	00100513          	li	a0,1
     ba0:	4a5050ef          	jal	6844 <exit>
    printf("%s: read %d bytes, wanted 2\n", s, n);
     ba4:	00050613          	mv	a2,a0
     ba8:	000a0593          	mv	a1,s4
     bac:	00007517          	auipc	a0,0x7
     bb0:	92450513          	addi	a0,a0,-1756 # 74d0 <malloc+0x4a8>
     bb4:	368060ef          	jal	6f1c <printf>
    exit(1);
     bb8:	00100513          	li	a0,1
     bbc:	489050ef          	jal	6844 <exit>

0000000000000bc0 <writetest>:
{
     bc0:	fb010113          	addi	sp,sp,-80
     bc4:	04113423          	sd	ra,72(sp)
     bc8:	04813023          	sd	s0,64(sp)
     bcc:	02913c23          	sd	s1,56(sp)
     bd0:	03213823          	sd	s2,48(sp)
     bd4:	03313423          	sd	s3,40(sp)
     bd8:	03413023          	sd	s4,32(sp)
     bdc:	01513c23          	sd	s5,24(sp)
     be0:	01613823          	sd	s6,16(sp)
     be4:	01713423          	sd	s7,8(sp)
     be8:	05010413          	addi	s0,sp,80
     bec:	00050b93          	mv	s7,a0
  fd = open("small", O_CREATE|O_RDWR);
     bf0:	20200593          	li	a1,514
     bf4:	00007517          	auipc	a0,0x7
     bf8:	8fc50513          	addi	a0,a0,-1796 # 74f0 <malloc+0x4c8>
     bfc:	4a9050ef          	jal	68a4 <open>
  if(fd < 0){
     c00:	0c054863          	bltz	a0,cd0 <writetest+0x110>
     c04:	00050993          	mv	s3,a0
     c08:	00000913          	li	s2,0
    if(write(fd, "aaaaaaaaaa", SZ) != SZ){
     c0c:	00a00493          	li	s1,10
     c10:	00007a17          	auipc	s4,0x7
     c14:	908a0a13          	addi	s4,s4,-1784 # 7518 <malloc+0x4f0>
    if(write(fd, "bbbbbbbbbb", SZ) != SZ){
     c18:	00007b17          	auipc	s6,0x7
     c1c:	938b0b13          	addi	s6,s6,-1736 # 7550 <malloc+0x528>
  for(i = 0; i < N; i++){
     c20:	06400a93          	li	s5,100
    if(write(fd, "aaaaaaaaaa", SZ) != SZ){
     c24:	00048613          	mv	a2,s1
     c28:	000a0593          	mv	a1,s4
     c2c:	00098513          	mv	a0,s3
     c30:	445050ef          	jal	6874 <write>
     c34:	0a951a63          	bne	a0,s1,ce8 <writetest+0x128>
    if(write(fd, "bbbbbbbbbb", SZ) != SZ){
     c38:	00048613          	mv	a2,s1
     c3c:	000b0593          	mv	a1,s6
     c40:	00098513          	mv	a0,s3
     c44:	431050ef          	jal	6874 <write>
     c48:	0a951e63          	bne	a0,s1,d04 <writetest+0x144>
  for(i = 0; i < N; i++){
     c4c:	0019091b          	addiw	s2,s2,1
     c50:	fd591ae3          	bne	s2,s5,c24 <writetest+0x64>
  close(fd);
     c54:	00098513          	mv	a0,s3
     c58:	429050ef          	jal	6880 <close>
  fd = open("small", O_RDONLY);
     c5c:	00000593          	li	a1,0
     c60:	00007517          	auipc	a0,0x7
     c64:	89050513          	addi	a0,a0,-1904 # 74f0 <malloc+0x4c8>
     c68:	43d050ef          	jal	68a4 <open>
     c6c:	00050493          	mv	s1,a0
  if(fd < 0){
     c70:	0a054863          	bltz	a0,d20 <writetest+0x160>
  i = read(fd, buf, N*SZ*2);
     c74:	7d000613          	li	a2,2000
     c78:	0000d597          	auipc	a1,0xd
     c7c:	04058593          	addi	a1,a1,64 # dcb8 <buf>
     c80:	3e9050ef          	jal	6868 <read>
  if(i != N*SZ*2){
     c84:	7d000793          	li	a5,2000
     c88:	0af51863          	bne	a0,a5,d38 <writetest+0x178>
  close(fd);
     c8c:	00048513          	mv	a0,s1
     c90:	3f1050ef          	jal	6880 <close>
  if(unlink("small") < 0){
     c94:	00007517          	auipc	a0,0x7
     c98:	85c50513          	addi	a0,a0,-1956 # 74f0 <malloc+0x4c8>
     c9c:	421050ef          	jal	68bc <unlink>
     ca0:	0a054863          	bltz	a0,d50 <writetest+0x190>
}
     ca4:	04813083          	ld	ra,72(sp)
     ca8:	04013403          	ld	s0,64(sp)
     cac:	03813483          	ld	s1,56(sp)
     cb0:	03013903          	ld	s2,48(sp)
     cb4:	02813983          	ld	s3,40(sp)
     cb8:	02013a03          	ld	s4,32(sp)
     cbc:	01813a83          	ld	s5,24(sp)
     cc0:	01013b03          	ld	s6,16(sp)
     cc4:	00813b83          	ld	s7,8(sp)
     cc8:	05010113          	addi	sp,sp,80
     ccc:	00008067          	ret
    printf("%s: error: creat small failed!\n", s);
     cd0:	000b8593          	mv	a1,s7
     cd4:	00007517          	auipc	a0,0x7
     cd8:	82450513          	addi	a0,a0,-2012 # 74f8 <malloc+0x4d0>
     cdc:	240060ef          	jal	6f1c <printf>
    exit(1);
     ce0:	00100513          	li	a0,1
     ce4:	361050ef          	jal	6844 <exit>
      printf("%s: error: write aa %d new file failed\n", s, i);
     ce8:	00090613          	mv	a2,s2
     cec:	000b8593          	mv	a1,s7
     cf0:	00007517          	auipc	a0,0x7
     cf4:	83850513          	addi	a0,a0,-1992 # 7528 <malloc+0x500>
     cf8:	224060ef          	jal	6f1c <printf>
      exit(1);
     cfc:	00100513          	li	a0,1
     d00:	345050ef          	jal	6844 <exit>
      printf("%s: error: write bb %d new file failed\n", s, i);
     d04:	00090613          	mv	a2,s2
     d08:	000b8593          	mv	a1,s7
     d0c:	00007517          	auipc	a0,0x7
     d10:	85450513          	addi	a0,a0,-1964 # 7560 <malloc+0x538>
     d14:	208060ef          	jal	6f1c <printf>
      exit(1);
     d18:	00100513          	li	a0,1
     d1c:	329050ef          	jal	6844 <exit>
    printf("%s: error: open small failed!\n", s);
     d20:	000b8593          	mv	a1,s7
     d24:	00007517          	auipc	a0,0x7
     d28:	86450513          	addi	a0,a0,-1948 # 7588 <malloc+0x560>
     d2c:	1f0060ef          	jal	6f1c <printf>
    exit(1);
     d30:	00100513          	li	a0,1
     d34:	311050ef          	jal	6844 <exit>
    printf("%s: read failed\n", s);
     d38:	000b8593          	mv	a1,s7
     d3c:	00007517          	auipc	a0,0x7
     d40:	86c50513          	addi	a0,a0,-1940 # 75a8 <malloc+0x580>
     d44:	1d8060ef          	jal	6f1c <printf>
    exit(1);
     d48:	00100513          	li	a0,1
     d4c:	2f9050ef          	jal	6844 <exit>
    printf("%s: unlink small failed\n", s);
     d50:	000b8593          	mv	a1,s7
     d54:	00007517          	auipc	a0,0x7
     d58:	86c50513          	addi	a0,a0,-1940 # 75c0 <malloc+0x598>
     d5c:	1c0060ef          	jal	6f1c <printf>
    exit(1);
     d60:	00100513          	li	a0,1
     d64:	2e1050ef          	jal	6844 <exit>

0000000000000d68 <writebig>:
{
     d68:	fc010113          	addi	sp,sp,-64
     d6c:	02113c23          	sd	ra,56(sp)
     d70:	02813823          	sd	s0,48(sp)
     d74:	02913423          	sd	s1,40(sp)
     d78:	03213023          	sd	s2,32(sp)
     d7c:	01313c23          	sd	s3,24(sp)
     d80:	01413823          	sd	s4,16(sp)
     d84:	01513423          	sd	s5,8(sp)
     d88:	01613023          	sd	s6,0(sp)
     d8c:	04010413          	addi	s0,sp,64
     d90:	00050b13          	mv	s6,a0
  fd = open("big", O_CREATE|O_RDWR);
     d94:	20200593          	li	a1,514
     d98:	00007517          	auipc	a0,0x7
     d9c:	84850513          	addi	a0,a0,-1976 # 75e0 <malloc+0x5b8>
     da0:	305050ef          	jal	68a4 <open>
  if(fd < 0){
     da4:	08054a63          	bltz	a0,e38 <writebig+0xd0>
     da8:	00050a13          	mv	s4,a0
     dac:	00000493          	li	s1,0
    ((int*)buf)[0] = i;
     db0:	0000d997          	auipc	s3,0xd
     db4:	f0898993          	addi	s3,s3,-248 # dcb8 <buf>
    if(write(fd, buf, BSIZE) != BSIZE){
     db8:	40000913          	li	s2,1024
  for(i = 0; i < MAXFILE; i++){
     dbc:	10c00a93          	li	s5,268
    ((int*)buf)[0] = i;
     dc0:	0099a023          	sw	s1,0(s3)
    if(write(fd, buf, BSIZE) != BSIZE){
     dc4:	00090613          	mv	a2,s2
     dc8:	00098593          	mv	a1,s3
     dcc:	000a0513          	mv	a0,s4
     dd0:	2a5050ef          	jal	6874 <write>
     dd4:	07251e63          	bne	a0,s2,e50 <writebig+0xe8>
  for(i = 0; i < MAXFILE; i++){
     dd8:	0014849b          	addiw	s1,s1,1
     ddc:	ff5492e3          	bne	s1,s5,dc0 <writebig+0x58>
  close(fd);
     de0:	000a0513          	mv	a0,s4
     de4:	29d050ef          	jal	6880 <close>
  fd = open("big", O_RDONLY);
     de8:	00000593          	li	a1,0
     dec:	00006517          	auipc	a0,0x6
     df0:	7f450513          	addi	a0,a0,2036 # 75e0 <malloc+0x5b8>
     df4:	2b1050ef          	jal	68a4 <open>
     df8:	00050a13          	mv	s4,a0
  n = 0;
     dfc:	00000493          	li	s1,0
    i = read(fd, buf, BSIZE);
     e00:	40000993          	li	s3,1024
     e04:	0000d917          	auipc	s2,0xd
     e08:	eb490913          	addi	s2,s2,-332 # dcb8 <buf>
  if(fd < 0){
     e0c:	06054063          	bltz	a0,e6c <writebig+0x104>
    i = read(fd, buf, BSIZE);
     e10:	00098613          	mv	a2,s3
     e14:	00090593          	mv	a1,s2
     e18:	000a0513          	mv	a0,s4
     e1c:	24d050ef          	jal	6868 <read>
    if(i == 0){
     e20:	06050263          	beqz	a0,e84 <writebig+0x11c>
    } else if(i != BSIZE){
     e24:	0d351263          	bne	a0,s3,ee8 <writebig+0x180>
    if(((int*)buf)[0] != n){
     e28:	00092683          	lw	a3,0(s2)
     e2c:	0c969c63          	bne	a3,s1,f04 <writebig+0x19c>
    n++;
     e30:	0014849b          	addiw	s1,s1,1
    i = read(fd, buf, BSIZE);
     e34:	fddff06f          	j	e10 <writebig+0xa8>
    printf("%s: error: creat big failed!\n", s);
     e38:	000b0593          	mv	a1,s6
     e3c:	00006517          	auipc	a0,0x6
     e40:	7ac50513          	addi	a0,a0,1964 # 75e8 <malloc+0x5c0>
     e44:	0d8060ef          	jal	6f1c <printf>
    exit(1);
     e48:	00100513          	li	a0,1
     e4c:	1f9050ef          	jal	6844 <exit>
      printf("%s: error: write big file failed i=%d\n", s, i);
     e50:	00048613          	mv	a2,s1
     e54:	000b0593          	mv	a1,s6
     e58:	00006517          	auipc	a0,0x6
     e5c:	7b050513          	addi	a0,a0,1968 # 7608 <malloc+0x5e0>
     e60:	0bc060ef          	jal	6f1c <printf>
      exit(1);
     e64:	00100513          	li	a0,1
     e68:	1dd050ef          	jal	6844 <exit>
    printf("%s: error: open big failed!\n", s);
     e6c:	000b0593          	mv	a1,s6
     e70:	00006517          	auipc	a0,0x6
     e74:	7c050513          	addi	a0,a0,1984 # 7630 <malloc+0x608>
     e78:	0a4060ef          	jal	6f1c <printf>
    exit(1);
     e7c:	00100513          	li	a0,1
     e80:	1c5050ef          	jal	6844 <exit>
      if(n != MAXFILE){
     e84:	10c00793          	li	a5,268
     e88:	04f49263          	bne	s1,a5,ecc <writebig+0x164>
  close(fd);
     e8c:	000a0513          	mv	a0,s4
     e90:	1f1050ef          	jal	6880 <close>
  if(unlink("big") < 0){
     e94:	00006517          	auipc	a0,0x6
     e98:	74c50513          	addi	a0,a0,1868 # 75e0 <malloc+0x5b8>
     e9c:	221050ef          	jal	68bc <unlink>
     ea0:	08054063          	bltz	a0,f20 <writebig+0x1b8>
}
     ea4:	03813083          	ld	ra,56(sp)
     ea8:	03013403          	ld	s0,48(sp)
     eac:	02813483          	ld	s1,40(sp)
     eb0:	02013903          	ld	s2,32(sp)
     eb4:	01813983          	ld	s3,24(sp)
     eb8:	01013a03          	ld	s4,16(sp)
     ebc:	00813a83          	ld	s5,8(sp)
     ec0:	00013b03          	ld	s6,0(sp)
     ec4:	04010113          	addi	sp,sp,64
     ec8:	00008067          	ret
        printf("%s: read only %d blocks from big", s, n);
     ecc:	00048613          	mv	a2,s1
     ed0:	000b0593          	mv	a1,s6
     ed4:	00006517          	auipc	a0,0x6
     ed8:	77c50513          	addi	a0,a0,1916 # 7650 <malloc+0x628>
     edc:	040060ef          	jal	6f1c <printf>
        exit(1);
     ee0:	00100513          	li	a0,1
     ee4:	161050ef          	jal	6844 <exit>
      printf("%s: read failed %d\n", s, i);
     ee8:	00050613          	mv	a2,a0
     eec:	000b0593          	mv	a1,s6
     ef0:	00006517          	auipc	a0,0x6
     ef4:	78850513          	addi	a0,a0,1928 # 7678 <malloc+0x650>
     ef8:	024060ef          	jal	6f1c <printf>
      exit(1);
     efc:	00100513          	li	a0,1
     f00:	145050ef          	jal	6844 <exit>
      printf("%s: read content of block %d is %d\n", s,
     f04:	00048613          	mv	a2,s1
     f08:	000b0593          	mv	a1,s6
     f0c:	00006517          	auipc	a0,0x6
     f10:	78450513          	addi	a0,a0,1924 # 7690 <malloc+0x668>
     f14:	008060ef          	jal	6f1c <printf>
      exit(1);
     f18:	00100513          	li	a0,1
     f1c:	129050ef          	jal	6844 <exit>
    printf("%s: unlink big failed\n", s);
     f20:	000b0593          	mv	a1,s6
     f24:	00006517          	auipc	a0,0x6
     f28:	79450513          	addi	a0,a0,1940 # 76b8 <malloc+0x690>
     f2c:	7f1050ef          	jal	6f1c <printf>
    exit(1);
     f30:	00100513          	li	a0,1
     f34:	111050ef          	jal	6844 <exit>

0000000000000f38 <unlinkread>:
{
     f38:	fd010113          	addi	sp,sp,-48
     f3c:	02113423          	sd	ra,40(sp)
     f40:	02813023          	sd	s0,32(sp)
     f44:	00913c23          	sd	s1,24(sp)
     f48:	01213823          	sd	s2,16(sp)
     f4c:	01313423          	sd	s3,8(sp)
     f50:	03010413          	addi	s0,sp,48
     f54:	00050993          	mv	s3,a0
  fd = open("unlinkread", O_CREATE | O_RDWR);
     f58:	20200593          	li	a1,514
     f5c:	00006517          	auipc	a0,0x6
     f60:	77450513          	addi	a0,a0,1908 # 76d0 <malloc+0x6a8>
     f64:	141050ef          	jal	68a4 <open>
  if(fd < 0){
     f68:	0e054663          	bltz	a0,1054 <unlinkread+0x11c>
     f6c:	00050493          	mv	s1,a0
  write(fd, "hello", SZ);
     f70:	00500613          	li	a2,5
     f74:	00006597          	auipc	a1,0x6
     f78:	78c58593          	addi	a1,a1,1932 # 7700 <malloc+0x6d8>
     f7c:	0f9050ef          	jal	6874 <write>
  close(fd);
     f80:	00048513          	mv	a0,s1
     f84:	0fd050ef          	jal	6880 <close>
  fd = open("unlinkread", O_RDWR);
     f88:	00200593          	li	a1,2
     f8c:	00006517          	auipc	a0,0x6
     f90:	74450513          	addi	a0,a0,1860 # 76d0 <malloc+0x6a8>
     f94:	111050ef          	jal	68a4 <open>
     f98:	00050493          	mv	s1,a0
  if(fd < 0){
     f9c:	0c054863          	bltz	a0,106c <unlinkread+0x134>
  if(unlink("unlinkread") != 0){
     fa0:	00006517          	auipc	a0,0x6
     fa4:	73050513          	addi	a0,a0,1840 # 76d0 <malloc+0x6a8>
     fa8:	115050ef          	jal	68bc <unlink>
     fac:	0c051c63          	bnez	a0,1084 <unlinkread+0x14c>
  fd1 = open("unlinkread", O_CREATE | O_RDWR);
     fb0:	20200593          	li	a1,514
     fb4:	00006517          	auipc	a0,0x6
     fb8:	71c50513          	addi	a0,a0,1820 # 76d0 <malloc+0x6a8>
     fbc:	0e9050ef          	jal	68a4 <open>
     fc0:	00050913          	mv	s2,a0
  write(fd1, "yyy", 3);
     fc4:	00300613          	li	a2,3
     fc8:	00006597          	auipc	a1,0x6
     fcc:	78058593          	addi	a1,a1,1920 # 7748 <malloc+0x720>
     fd0:	0a5050ef          	jal	6874 <write>
  close(fd1);
     fd4:	00090513          	mv	a0,s2
     fd8:	0a9050ef          	jal	6880 <close>
  if(read(fd, buf, sizeof(buf)) != SZ){
     fdc:	00003637          	lui	a2,0x3
     fe0:	0000d597          	auipc	a1,0xd
     fe4:	cd858593          	addi	a1,a1,-808 # dcb8 <buf>
     fe8:	00048513          	mv	a0,s1
     fec:	07d050ef          	jal	6868 <read>
     ff0:	00500793          	li	a5,5
     ff4:	0af51463          	bne	a0,a5,109c <unlinkread+0x164>
  if(buf[0] != 'h'){
     ff8:	0000d717          	auipc	a4,0xd
     ffc:	cc074703          	lbu	a4,-832(a4) # dcb8 <buf>
    1000:	06800793          	li	a5,104
    1004:	0af71863          	bne	a4,a5,10b4 <unlinkread+0x17c>
  if(write(fd, buf, 10) != 10){
    1008:	00a00613          	li	a2,10
    100c:	0000d597          	auipc	a1,0xd
    1010:	cac58593          	addi	a1,a1,-852 # dcb8 <buf>
    1014:	00048513          	mv	a0,s1
    1018:	05d050ef          	jal	6874 <write>
    101c:	00a00793          	li	a5,10
    1020:	0af51663          	bne	a0,a5,10cc <unlinkread+0x194>
  close(fd);
    1024:	00048513          	mv	a0,s1
    1028:	059050ef          	jal	6880 <close>
  unlink("unlinkread");
    102c:	00006517          	auipc	a0,0x6
    1030:	6a450513          	addi	a0,a0,1700 # 76d0 <malloc+0x6a8>
    1034:	089050ef          	jal	68bc <unlink>
}
    1038:	02813083          	ld	ra,40(sp)
    103c:	02013403          	ld	s0,32(sp)
    1040:	01813483          	ld	s1,24(sp)
    1044:	01013903          	ld	s2,16(sp)
    1048:	00813983          	ld	s3,8(sp)
    104c:	03010113          	addi	sp,sp,48
    1050:	00008067          	ret
    printf("%s: create unlinkread failed\n", s);
    1054:	00098593          	mv	a1,s3
    1058:	00006517          	auipc	a0,0x6
    105c:	68850513          	addi	a0,a0,1672 # 76e0 <malloc+0x6b8>
    1060:	6bd050ef          	jal	6f1c <printf>
    exit(1);
    1064:	00100513          	li	a0,1
    1068:	7dc050ef          	jal	6844 <exit>
    printf("%s: open unlinkread failed\n", s);
    106c:	00098593          	mv	a1,s3
    1070:	00006517          	auipc	a0,0x6
    1074:	69850513          	addi	a0,a0,1688 # 7708 <malloc+0x6e0>
    1078:	6a5050ef          	jal	6f1c <printf>
    exit(1);
    107c:	00100513          	li	a0,1
    1080:	7c4050ef          	jal	6844 <exit>
    printf("%s: unlink unlinkread failed\n", s);
    1084:	00098593          	mv	a1,s3
    1088:	00006517          	auipc	a0,0x6
    108c:	6a050513          	addi	a0,a0,1696 # 7728 <malloc+0x700>
    1090:	68d050ef          	jal	6f1c <printf>
    exit(1);
    1094:	00100513          	li	a0,1
    1098:	7ac050ef          	jal	6844 <exit>
    printf("%s: unlinkread read failed", s);
    109c:	00098593          	mv	a1,s3
    10a0:	00006517          	auipc	a0,0x6
    10a4:	6b050513          	addi	a0,a0,1712 # 7750 <malloc+0x728>
    10a8:	675050ef          	jal	6f1c <printf>
    exit(1);
    10ac:	00100513          	li	a0,1
    10b0:	794050ef          	jal	6844 <exit>
    printf("%s: unlinkread wrong data\n", s);
    10b4:	00098593          	mv	a1,s3
    10b8:	00006517          	auipc	a0,0x6
    10bc:	6b850513          	addi	a0,a0,1720 # 7770 <malloc+0x748>
    10c0:	65d050ef          	jal	6f1c <printf>
    exit(1);
    10c4:	00100513          	li	a0,1
    10c8:	77c050ef          	jal	6844 <exit>
    printf("%s: unlinkread write failed\n", s);
    10cc:	00098593          	mv	a1,s3
    10d0:	00006517          	auipc	a0,0x6
    10d4:	6c050513          	addi	a0,a0,1728 # 7790 <malloc+0x768>
    10d8:	645050ef          	jal	6f1c <printf>
    exit(1);
    10dc:	00100513          	li	a0,1
    10e0:	764050ef          	jal	6844 <exit>

00000000000010e4 <linktest>:
{
    10e4:	fe010113          	addi	sp,sp,-32
    10e8:	00113c23          	sd	ra,24(sp)
    10ec:	00813823          	sd	s0,16(sp)
    10f0:	00913423          	sd	s1,8(sp)
    10f4:	01213023          	sd	s2,0(sp)
    10f8:	02010413          	addi	s0,sp,32
    10fc:	00050913          	mv	s2,a0
  unlink("lf1");
    1100:	00006517          	auipc	a0,0x6
    1104:	6b050513          	addi	a0,a0,1712 # 77b0 <malloc+0x788>
    1108:	7b4050ef          	jal	68bc <unlink>
  unlink("lf2");
    110c:	00006517          	auipc	a0,0x6
    1110:	6ac50513          	addi	a0,a0,1708 # 77b8 <malloc+0x790>
    1114:	7a8050ef          	jal	68bc <unlink>
  fd = open("lf1", O_CREATE|O_RDWR);
    1118:	20200593          	li	a1,514
    111c:	00006517          	auipc	a0,0x6
    1120:	69450513          	addi	a0,a0,1684 # 77b0 <malloc+0x788>
    1124:	780050ef          	jal	68a4 <open>
  if(fd < 0){
    1128:	10054063          	bltz	a0,1228 <linktest+0x144>
    112c:	00050493          	mv	s1,a0
  if(write(fd, "hello", SZ) != SZ){
    1130:	00500613          	li	a2,5
    1134:	00006597          	auipc	a1,0x6
    1138:	5cc58593          	addi	a1,a1,1484 # 7700 <malloc+0x6d8>
    113c:	738050ef          	jal	6874 <write>
    1140:	00500793          	li	a5,5
    1144:	0ef51e63          	bne	a0,a5,1240 <linktest+0x15c>
  close(fd);
    1148:	00048513          	mv	a0,s1
    114c:	734050ef          	jal	6880 <close>
  if(link("lf1", "lf2") < 0){
    1150:	00006597          	auipc	a1,0x6
    1154:	66858593          	addi	a1,a1,1640 # 77b8 <malloc+0x790>
    1158:	00006517          	auipc	a0,0x6
    115c:	65850513          	addi	a0,a0,1624 # 77b0 <malloc+0x788>
    1160:	774050ef          	jal	68d4 <link>
    1164:	0e054a63          	bltz	a0,1258 <linktest+0x174>
  unlink("lf1");
    1168:	00006517          	auipc	a0,0x6
    116c:	64850513          	addi	a0,a0,1608 # 77b0 <malloc+0x788>
    1170:	74c050ef          	jal	68bc <unlink>
  if(open("lf1", 0) >= 0){
    1174:	00000593          	li	a1,0
    1178:	00006517          	auipc	a0,0x6
    117c:	63850513          	addi	a0,a0,1592 # 77b0 <malloc+0x788>
    1180:	724050ef          	jal	68a4 <open>
    1184:	0e055663          	bgez	a0,1270 <linktest+0x18c>
  fd = open("lf2", 0);
    1188:	00000593          	li	a1,0
    118c:	00006517          	auipc	a0,0x6
    1190:	62c50513          	addi	a0,a0,1580 # 77b8 <malloc+0x790>
    1194:	710050ef          	jal	68a4 <open>
    1198:	00050493          	mv	s1,a0
  if(fd < 0){
    119c:	0e054663          	bltz	a0,1288 <linktest+0x1a4>
  if(read(fd, buf, sizeof(buf)) != SZ){
    11a0:	00003637          	lui	a2,0x3
    11a4:	0000d597          	auipc	a1,0xd
    11a8:	b1458593          	addi	a1,a1,-1260 # dcb8 <buf>
    11ac:	6bc050ef          	jal	6868 <read>
    11b0:	00500793          	li	a5,5
    11b4:	0ef51663          	bne	a0,a5,12a0 <linktest+0x1bc>
  close(fd);
    11b8:	00048513          	mv	a0,s1
    11bc:	6c4050ef          	jal	6880 <close>
  if(link("lf2", "lf2") >= 0){
    11c0:	00006597          	auipc	a1,0x6
    11c4:	5f858593          	addi	a1,a1,1528 # 77b8 <malloc+0x790>
    11c8:	00058513          	mv	a0,a1
    11cc:	708050ef          	jal	68d4 <link>
    11d0:	0e055463          	bgez	a0,12b8 <linktest+0x1d4>
  unlink("lf2");
    11d4:	00006517          	auipc	a0,0x6
    11d8:	5e450513          	addi	a0,a0,1508 # 77b8 <malloc+0x790>
    11dc:	6e0050ef          	jal	68bc <unlink>
  if(link("lf2", "lf1") >= 0){
    11e0:	00006597          	auipc	a1,0x6
    11e4:	5d058593          	addi	a1,a1,1488 # 77b0 <malloc+0x788>
    11e8:	00006517          	auipc	a0,0x6
    11ec:	5d050513          	addi	a0,a0,1488 # 77b8 <malloc+0x790>
    11f0:	6e4050ef          	jal	68d4 <link>
    11f4:	0c055e63          	bgez	a0,12d0 <linktest+0x1ec>
  if(link(".", "lf1") >= 0){
    11f8:	00006597          	auipc	a1,0x6
    11fc:	5b858593          	addi	a1,a1,1464 # 77b0 <malloc+0x788>
    1200:	00006517          	auipc	a0,0x6
    1204:	6c050513          	addi	a0,a0,1728 # 78c0 <malloc+0x898>
    1208:	6cc050ef          	jal	68d4 <link>
    120c:	0c055e63          	bgez	a0,12e8 <linktest+0x204>
}
    1210:	01813083          	ld	ra,24(sp)
    1214:	01013403          	ld	s0,16(sp)
    1218:	00813483          	ld	s1,8(sp)
    121c:	00013903          	ld	s2,0(sp)
    1220:	02010113          	addi	sp,sp,32
    1224:	00008067          	ret
    printf("%s: create lf1 failed\n", s);
    1228:	00090593          	mv	a1,s2
    122c:	00006517          	auipc	a0,0x6
    1230:	59450513          	addi	a0,a0,1428 # 77c0 <malloc+0x798>
    1234:	4e9050ef          	jal	6f1c <printf>
    exit(1);
    1238:	00100513          	li	a0,1
    123c:	608050ef          	jal	6844 <exit>
    printf("%s: write lf1 failed\n", s);
    1240:	00090593          	mv	a1,s2
    1244:	00006517          	auipc	a0,0x6
    1248:	59450513          	addi	a0,a0,1428 # 77d8 <malloc+0x7b0>
    124c:	4d1050ef          	jal	6f1c <printf>
    exit(1);
    1250:	00100513          	li	a0,1
    1254:	5f0050ef          	jal	6844 <exit>
    printf("%s: link lf1 lf2 failed\n", s);
    1258:	00090593          	mv	a1,s2
    125c:	00006517          	auipc	a0,0x6
    1260:	59450513          	addi	a0,a0,1428 # 77f0 <malloc+0x7c8>
    1264:	4b9050ef          	jal	6f1c <printf>
    exit(1);
    1268:	00100513          	li	a0,1
    126c:	5d8050ef          	jal	6844 <exit>
    printf("%s: unlinked lf1 but it is still there!\n", s);
    1270:	00090593          	mv	a1,s2
    1274:	00006517          	auipc	a0,0x6
    1278:	59c50513          	addi	a0,a0,1436 # 7810 <malloc+0x7e8>
    127c:	4a1050ef          	jal	6f1c <printf>
    exit(1);
    1280:	00100513          	li	a0,1
    1284:	5c0050ef          	jal	6844 <exit>
    printf("%s: open lf2 failed\n", s);
    1288:	00090593          	mv	a1,s2
    128c:	00006517          	auipc	a0,0x6
    1290:	5b450513          	addi	a0,a0,1460 # 7840 <malloc+0x818>
    1294:	489050ef          	jal	6f1c <printf>
    exit(1);
    1298:	00100513          	li	a0,1
    129c:	5a8050ef          	jal	6844 <exit>
    printf("%s: read lf2 failed\n", s);
    12a0:	00090593          	mv	a1,s2
    12a4:	00006517          	auipc	a0,0x6
    12a8:	5b450513          	addi	a0,a0,1460 # 7858 <malloc+0x830>
    12ac:	471050ef          	jal	6f1c <printf>
    exit(1);
    12b0:	00100513          	li	a0,1
    12b4:	590050ef          	jal	6844 <exit>
    printf("%s: link lf2 lf2 succeeded! oops\n", s);
    12b8:	00090593          	mv	a1,s2
    12bc:	00006517          	auipc	a0,0x6
    12c0:	5b450513          	addi	a0,a0,1460 # 7870 <malloc+0x848>
    12c4:	459050ef          	jal	6f1c <printf>
    exit(1);
    12c8:	00100513          	li	a0,1
    12cc:	578050ef          	jal	6844 <exit>
    printf("%s: link non-existent succeeded! oops\n", s);
    12d0:	00090593          	mv	a1,s2
    12d4:	00006517          	auipc	a0,0x6
    12d8:	5c450513          	addi	a0,a0,1476 # 7898 <malloc+0x870>
    12dc:	441050ef          	jal	6f1c <printf>
    exit(1);
    12e0:	00100513          	li	a0,1
    12e4:	560050ef          	jal	6844 <exit>
    printf("%s: link . lf1 succeeded! oops\n", s);
    12e8:	00090593          	mv	a1,s2
    12ec:	00006517          	auipc	a0,0x6
    12f0:	5dc50513          	addi	a0,a0,1500 # 78c8 <malloc+0x8a0>
    12f4:	429050ef          	jal	6f1c <printf>
    exit(1);
    12f8:	00100513          	li	a0,1
    12fc:	548050ef          	jal	6844 <exit>

0000000000001300 <validatetest>:
{
    1300:	fc010113          	addi	sp,sp,-64
    1304:	02113c23          	sd	ra,56(sp)
    1308:	02813823          	sd	s0,48(sp)
    130c:	02913423          	sd	s1,40(sp)
    1310:	03213023          	sd	s2,32(sp)
    1314:	01313c23          	sd	s3,24(sp)
    1318:	01413823          	sd	s4,16(sp)
    131c:	01513423          	sd	s5,8(sp)
    1320:	01613023          	sd	s6,0(sp)
    1324:	04010413          	addi	s0,sp,64
    1328:	00050b13          	mv	s6,a0
  for(p = 0; p <= (uint)hi; p += PGSIZE){
    132c:	00000493          	li	s1,0
    if(link("nosuchfile", (char*)p) != -1){
    1330:	00006997          	auipc	s3,0x6
    1334:	5b898993          	addi	s3,s3,1464 # 78e8 <malloc+0x8c0>
    1338:	fff00913          	li	s2,-1
  for(p = 0; p <= (uint)hi; p += PGSIZE){
    133c:	00001ab7          	lui	s5,0x1
    1340:	00114a37          	lui	s4,0x114
    if(link("nosuchfile", (char*)p) != -1){
    1344:	00048593          	mv	a1,s1
    1348:	00098513          	mv	a0,s3
    134c:	588050ef          	jal	68d4 <link>
    1350:	03251a63          	bne	a0,s2,1384 <validatetest+0x84>
  for(p = 0; p <= (uint)hi; p += PGSIZE){
    1354:	015484b3          	add	s1,s1,s5
    1358:	ff4496e3          	bne	s1,s4,1344 <validatetest+0x44>
}
    135c:	03813083          	ld	ra,56(sp)
    1360:	03013403          	ld	s0,48(sp)
    1364:	02813483          	ld	s1,40(sp)
    1368:	02013903          	ld	s2,32(sp)
    136c:	01813983          	ld	s3,24(sp)
    1370:	01013a03          	ld	s4,16(sp)
    1374:	00813a83          	ld	s5,8(sp)
    1378:	00013b03          	ld	s6,0(sp)
    137c:	04010113          	addi	sp,sp,64
    1380:	00008067          	ret
      printf("%s: link should not succeed\n", s);
    1384:	000b0593          	mv	a1,s6
    1388:	00006517          	auipc	a0,0x6
    138c:	57050513          	addi	a0,a0,1392 # 78f8 <malloc+0x8d0>
    1390:	38d050ef          	jal	6f1c <printf>
      exit(1);
    1394:	00100513          	li	a0,1
    1398:	4ac050ef          	jal	6844 <exit>

000000000000139c <bigdir>:
{
    139c:	fa010113          	addi	sp,sp,-96
    13a0:	04113c23          	sd	ra,88(sp)
    13a4:	04813823          	sd	s0,80(sp)
    13a8:	04913423          	sd	s1,72(sp)
    13ac:	05213023          	sd	s2,64(sp)
    13b0:	03313c23          	sd	s3,56(sp)
    13b4:	03413823          	sd	s4,48(sp)
    13b8:	03513423          	sd	s5,40(sp)
    13bc:	03613023          	sd	s6,32(sp)
    13c0:	01713c23          	sd	s7,24(sp)
    13c4:	06010413          	addi	s0,sp,96
    13c8:	00050b93          	mv	s7,a0
  unlink("bd");
    13cc:	00006517          	auipc	a0,0x6
    13d0:	54c50513          	addi	a0,a0,1356 # 7918 <malloc+0x8f0>
    13d4:	4e8050ef          	jal	68bc <unlink>
  fd = open("bd", O_CREATE);
    13d8:	20000593          	li	a1,512
    13dc:	00006517          	auipc	a0,0x6
    13e0:	53c50513          	addi	a0,a0,1340 # 7918 <malloc+0x8f0>
    13e4:	4c0050ef          	jal	68a4 <open>
  if(fd < 0){
    13e8:	0e054a63          	bltz	a0,14dc <bigdir+0x140>
  close(fd);
    13ec:	494050ef          	jal	6880 <close>
  for(i = 0; i < N; i++){
    13f0:	00000913          	li	s2,0
    name[0] = 'x';
    13f4:	07800a93          	li	s5,120
    if(link("bd", name) != 0){
    13f8:	fa040a13          	addi	s4,s0,-96
    13fc:	00006997          	auipc	s3,0x6
    1400:	51c98993          	addi	s3,s3,1308 # 7918 <malloc+0x8f0>
  for(i = 0; i < N; i++){
    1404:	1f400b13          	li	s6,500
    name[0] = 'x';
    1408:	fb540023          	sb	s5,-96(s0)
    name[1] = '0' + (i / 64);
    140c:	41f9571b          	sraiw	a4,s2,0x1f
    1410:	01a7571b          	srliw	a4,a4,0x1a
    1414:	012707bb          	addw	a5,a4,s2
    1418:	4067d69b          	sraiw	a3,a5,0x6
    141c:	0306869b          	addiw	a3,a3,48
    1420:	fad400a3          	sb	a3,-95(s0)
    name[2] = '0' + (i % 64);
    1424:	03f7f793          	andi	a5,a5,63
    1428:	40e787bb          	subw	a5,a5,a4
    142c:	0307879b          	addiw	a5,a5,48
    1430:	faf40123          	sb	a5,-94(s0)
    name[3] = '\0';
    1434:	fa0401a3          	sb	zero,-93(s0)
    if(link("bd", name) != 0){
    1438:	000a0593          	mv	a1,s4
    143c:	00098513          	mv	a0,s3
    1440:	494050ef          	jal	68d4 <link>
    1444:	00050493          	mv	s1,a0
    1448:	0a051663          	bnez	a0,14f4 <bigdir+0x158>
  for(i = 0; i < N; i++){
    144c:	0019091b          	addiw	s2,s2,1
    1450:	fb691ce3          	bne	s2,s6,1408 <bigdir+0x6c>
  unlink("bd");
    1454:	00006517          	auipc	a0,0x6
    1458:	4c450513          	addi	a0,a0,1220 # 7918 <malloc+0x8f0>
    145c:	460050ef          	jal	68bc <unlink>
    name[0] = 'x';
    1460:	07800993          	li	s3,120
    if(unlink(name) != 0){
    1464:	fa040913          	addi	s2,s0,-96
  for(i = 0; i < N; i++){
    1468:	1f400a13          	li	s4,500
    name[0] = 'x';
    146c:	fb340023          	sb	s3,-96(s0)
    name[1] = '0' + (i / 64);
    1470:	41f4d71b          	sraiw	a4,s1,0x1f
    1474:	01a7571b          	srliw	a4,a4,0x1a
    1478:	009707bb          	addw	a5,a4,s1
    147c:	4067d69b          	sraiw	a3,a5,0x6
    1480:	0306869b          	addiw	a3,a3,48
    1484:	fad400a3          	sb	a3,-95(s0)
    name[2] = '0' + (i % 64);
    1488:	03f7f793          	andi	a5,a5,63
    148c:	40e787bb          	subw	a5,a5,a4
    1490:	0307879b          	addiw	a5,a5,48
    1494:	faf40123          	sb	a5,-94(s0)
    name[3] = '\0';
    1498:	fa0401a3          	sb	zero,-93(s0)
    if(unlink(name) != 0){
    149c:	00090513          	mv	a0,s2
    14a0:	41c050ef          	jal	68bc <unlink>
    14a4:	06051863          	bnez	a0,1514 <bigdir+0x178>
  for(i = 0; i < N; i++){
    14a8:	0014849b          	addiw	s1,s1,1
    14ac:	fd4490e3          	bne	s1,s4,146c <bigdir+0xd0>
}
    14b0:	05813083          	ld	ra,88(sp)
    14b4:	05013403          	ld	s0,80(sp)
    14b8:	04813483          	ld	s1,72(sp)
    14bc:	04013903          	ld	s2,64(sp)
    14c0:	03813983          	ld	s3,56(sp)
    14c4:	03013a03          	ld	s4,48(sp)
    14c8:	02813a83          	ld	s5,40(sp)
    14cc:	02013b03          	ld	s6,32(sp)
    14d0:	01813b83          	ld	s7,24(sp)
    14d4:	06010113          	addi	sp,sp,96
    14d8:	00008067          	ret
    printf("%s: bigdir create failed\n", s);
    14dc:	000b8593          	mv	a1,s7
    14e0:	00006517          	auipc	a0,0x6
    14e4:	44050513          	addi	a0,a0,1088 # 7920 <malloc+0x8f8>
    14e8:	235050ef          	jal	6f1c <printf>
    exit(1);
    14ec:	00100513          	li	a0,1
    14f0:	354050ef          	jal	6844 <exit>
      printf("%s: bigdir i=%d link(bd, %s) failed\n", s, i, name);
    14f4:	fa040693          	addi	a3,s0,-96
    14f8:	00090613          	mv	a2,s2
    14fc:	000b8593          	mv	a1,s7
    1500:	00006517          	auipc	a0,0x6
    1504:	44050513          	addi	a0,a0,1088 # 7940 <malloc+0x918>
    1508:	215050ef          	jal	6f1c <printf>
      exit(1);
    150c:	00100513          	li	a0,1
    1510:	334050ef          	jal	6844 <exit>
      printf("%s: bigdir unlink failed", s);
    1514:	000b8593          	mv	a1,s7
    1518:	00006517          	auipc	a0,0x6
    151c:	45050513          	addi	a0,a0,1104 # 7968 <malloc+0x940>
    1520:	1fd050ef          	jal	6f1c <printf>
      exit(1);
    1524:	00100513          	li	a0,1
    1528:	31c050ef          	jal	6844 <exit>

000000000000152c <pgbug>:
{
    152c:	fd010113          	addi	sp,sp,-48
    1530:	02113423          	sd	ra,40(sp)
    1534:	02813023          	sd	s0,32(sp)
    1538:	00913c23          	sd	s1,24(sp)
    153c:	03010413          	addi	s0,sp,48
  argv[0] = 0;
    1540:	fc043c23          	sd	zero,-40(s0)
  exec(big, argv);
    1544:	00009497          	auipc	s1,0x9
    1548:	abc48493          	addi	s1,s1,-1348 # a000 <big>
    154c:	fd840593          	addi	a1,s0,-40
    1550:	0004b503          	ld	a0,0(s1)
    1554:	344050ef          	jal	6898 <exec>
  pipe(big);
    1558:	0004b503          	ld	a0,0(s1)
    155c:	300050ef          	jal	685c <pipe>
  exit(0);
    1560:	00000513          	li	a0,0
    1564:	2e0050ef          	jal	6844 <exit>

0000000000001568 <badarg>:
{
    1568:	fc010113          	addi	sp,sp,-64
    156c:	02113c23          	sd	ra,56(sp)
    1570:	02813823          	sd	s0,48(sp)
    1574:	02913423          	sd	s1,40(sp)
    1578:	03213023          	sd	s2,32(sp)
    157c:	01313c23          	sd	s3,24(sp)
    1580:	01413823          	sd	s4,16(sp)
    1584:	04010413          	addi	s0,sp,64
    1588:	0000c4b7          	lui	s1,0xc
    158c:	35048493          	addi	s1,s1,848 # c350 <uninit+0xda8>
    argv[0] = (char*)0xffffffff;
    1590:	fff00913          	li	s2,-1
    1594:	02095913          	srli	s2,s2,0x20
    exec("echo", argv);
    1598:	fc040a13          	addi	s4,s0,-64
    159c:	00006997          	auipc	s3,0x6
    15a0:	c3c98993          	addi	s3,s3,-964 # 71d8 <malloc+0x1b0>
    argv[0] = (char*)0xffffffff;
    15a4:	fd243023          	sd	s2,-64(s0)
    argv[1] = 0;
    15a8:	fc043423          	sd	zero,-56(s0)
    exec("echo", argv);
    15ac:	000a0593          	mv	a1,s4
    15b0:	00098513          	mv	a0,s3
    15b4:	2e4050ef          	jal	6898 <exec>
  for(int i = 0; i < 50000; i++){
    15b8:	fff4849b          	addiw	s1,s1,-1
    15bc:	fe0494e3          	bnez	s1,15a4 <badarg+0x3c>
  exit(0);
    15c0:	00000513          	li	a0,0
    15c4:	280050ef          	jal	6844 <exit>

00000000000015c8 <copyinstr2>:
{
    15c8:	f3010113          	addi	sp,sp,-208
    15cc:	0c113423          	sd	ra,200(sp)
    15d0:	0c813023          	sd	s0,192(sp)
    15d4:	0d010413          	addi	s0,sp,208
  for(int i = 0; i < MAXPATH; i++)
    15d8:	f6840793          	addi	a5,s0,-152
    15dc:	fe840693          	addi	a3,s0,-24
    b[i] = 'x';
    15e0:	07800713          	li	a4,120
    15e4:	00e78023          	sb	a4,0(a5)
  for(int i = 0; i < MAXPATH; i++)
    15e8:	00178793          	addi	a5,a5,1
    15ec:	fed79ce3          	bne	a5,a3,15e4 <copyinstr2+0x1c>
  b[MAXPATH] = '\0';
    15f0:	fe040423          	sb	zero,-24(s0)
  int ret = unlink(b);
    15f4:	f6840513          	addi	a0,s0,-152
    15f8:	2c4050ef          	jal	68bc <unlink>
  if(ret != -1){
    15fc:	fff00793          	li	a5,-1
    1600:	0cf51e63          	bne	a0,a5,16dc <copyinstr2+0x114>
  int fd = open(b, O_CREATE | O_WRONLY);
    1604:	20100593          	li	a1,513
    1608:	f6840513          	addi	a0,s0,-152
    160c:	298050ef          	jal	68a4 <open>
  if(fd != -1){
    1610:	fff00793          	li	a5,-1
    1614:	0ef51263          	bne	a0,a5,16f8 <copyinstr2+0x130>
  ret = link(b, b);
    1618:	f6840513          	addi	a0,s0,-152
    161c:	00050593          	mv	a1,a0
    1620:	2b4050ef          	jal	68d4 <link>
  if(ret != -1){
    1624:	fff00793          	li	a5,-1
    1628:	0ef51663          	bne	a0,a5,1714 <copyinstr2+0x14c>
  char *args[] = { "xx", 0 };
    162c:	00007797          	auipc	a5,0x7
    1630:	48c78793          	addi	a5,a5,1164 # 8ab8 <malloc+0x1a90>
    1634:	f4f43c23          	sd	a5,-168(s0)
    1638:	f6043023          	sd	zero,-160(s0)
  ret = exec(b, args);
    163c:	f5840593          	addi	a1,s0,-168
    1640:	f6840513          	addi	a0,s0,-152
    1644:	254050ef          	jal	6898 <exec>
  if(ret != -1){
    1648:	fff00793          	li	a5,-1
    164c:	0ef51463          	bne	a0,a5,1734 <copyinstr2+0x16c>
  int pid = fork();
    1650:	1e8050ef          	jal	6838 <fork>
  if(pid < 0){
    1654:	0e054e63          	bltz	a0,1750 <copyinstr2+0x188>
  if(pid == 0){
    1658:	10051a63          	bnez	a0,176c <copyinstr2+0x1a4>
    165c:	00009797          	auipc	a5,0x9
    1660:	f4478793          	addi	a5,a5,-188 # a5a0 <big.0>
    1664:	0000a697          	auipc	a3,0xa
    1668:	f3c68693          	addi	a3,a3,-196 # b5a0 <big.0+0x1000>
      big[i] = 'x';
    166c:	07800713          	li	a4,120
    1670:	00e78023          	sb	a4,0(a5)
    for(int i = 0; i < PGSIZE; i++)
    1674:	00178793          	addi	a5,a5,1
    1678:	fed79ce3          	bne	a5,a3,1670 <copyinstr2+0xa8>
    big[PGSIZE] = '\0';
    167c:	0000a797          	auipc	a5,0xa
    1680:	f2078223          	sb	zero,-220(a5) # b5a0 <big.0+0x1000>
    char *args2[] = { big, big, big, 0 };
    1684:	00008797          	auipc	a5,0x8
    1688:	09c78793          	addi	a5,a5,156 # 9720 <malloc+0x26f8>
    168c:	0587b603          	ld	a2,88(a5)
    1690:	0607b683          	ld	a3,96(a5)
    1694:	0687b703          	ld	a4,104(a5)
    1698:	f2c43823          	sd	a2,-208(s0)
    169c:	f2d43c23          	sd	a3,-200(s0)
    16a0:	f4e43023          	sd	a4,-192(s0)
    16a4:	0707b783          	ld	a5,112(a5)
    16a8:	f4f43423          	sd	a5,-184(s0)
    ret = exec("echo", args2);
    16ac:	f3040593          	addi	a1,s0,-208
    16b0:	00006517          	auipc	a0,0x6
    16b4:	b2850513          	addi	a0,a0,-1240 # 71d8 <malloc+0x1b0>
    16b8:	1e0050ef          	jal	6898 <exec>
    if(ret != -1){
    16bc:	fff00793          	li	a5,-1
    16c0:	0af50263          	beq	a0,a5,1764 <copyinstr2+0x19c>
      printf("exec(echo, BIG) returned %d, not -1\n", fd);
    16c4:	00078593          	mv	a1,a5
    16c8:	00006517          	auipc	a0,0x6
    16cc:	34850513          	addi	a0,a0,840 # 7a10 <malloc+0x9e8>
    16d0:	04d050ef          	jal	6f1c <printf>
      exit(1);
    16d4:	00100513          	li	a0,1
    16d8:	16c050ef          	jal	6844 <exit>
    printf("unlink(%s) returned %d, not -1\n", b, ret);
    16dc:	00050613          	mv	a2,a0
    16e0:	f6840593          	addi	a1,s0,-152
    16e4:	00006517          	auipc	a0,0x6
    16e8:	2a450513          	addi	a0,a0,676 # 7988 <malloc+0x960>
    16ec:	031050ef          	jal	6f1c <printf>
    exit(1);
    16f0:	00100513          	li	a0,1
    16f4:	150050ef          	jal	6844 <exit>
    printf("open(%s) returned %d, not -1\n", b, fd);
    16f8:	00050613          	mv	a2,a0
    16fc:	f6840593          	addi	a1,s0,-152
    1700:	00006517          	auipc	a0,0x6
    1704:	2a850513          	addi	a0,a0,680 # 79a8 <malloc+0x980>
    1708:	015050ef          	jal	6f1c <printf>
    exit(1);
    170c:	00100513          	li	a0,1
    1710:	134050ef          	jal	6844 <exit>
    printf("link(%s, %s) returned %d, not -1\n", b, b, ret);
    1714:	f6840593          	addi	a1,s0,-152
    1718:	00050693          	mv	a3,a0
    171c:	00058613          	mv	a2,a1
    1720:	00006517          	auipc	a0,0x6
    1724:	2a850513          	addi	a0,a0,680 # 79c8 <malloc+0x9a0>
    1728:	7f4050ef          	jal	6f1c <printf>
    exit(1);
    172c:	00100513          	li	a0,1
    1730:	114050ef          	jal	6844 <exit>
    printf("exec(%s) returned %d, not -1\n", b, fd);
    1734:	00078613          	mv	a2,a5
    1738:	f6840593          	addi	a1,s0,-152
    173c:	00006517          	auipc	a0,0x6
    1740:	2b450513          	addi	a0,a0,692 # 79f0 <malloc+0x9c8>
    1744:	7d8050ef          	jal	6f1c <printf>
    exit(1);
    1748:	00100513          	li	a0,1
    174c:	0f8050ef          	jal	6844 <exit>
    printf("fork failed\n");
    1750:	00008517          	auipc	a0,0x8
    1754:	8c050513          	addi	a0,a0,-1856 # 9010 <malloc+0x1fe8>
    1758:	7c4050ef          	jal	6f1c <printf>
    exit(1);
    175c:	00100513          	li	a0,1
    1760:	0e4050ef          	jal	6844 <exit>
    exit(747); // OK
    1764:	2eb00513          	li	a0,747
    1768:	0dc050ef          	jal	6844 <exit>
  int st = 0;
    176c:	f4042a23          	sw	zero,-172(s0)
  wait(&st);
    1770:	f5440513          	addi	a0,s0,-172
    1774:	0dc050ef          	jal	6850 <wait>
  if(st != 747){
    1778:	f5442703          	lw	a4,-172(s0)
    177c:	2eb00793          	li	a5,747
    1780:	00f71a63          	bne	a4,a5,1794 <copyinstr2+0x1cc>
}
    1784:	0c813083          	ld	ra,200(sp)
    1788:	0c013403          	ld	s0,192(sp)
    178c:	0d010113          	addi	sp,sp,208
    1790:	00008067          	ret
    printf("exec(echo, BIG) succeeded, should have failed\n");
    1794:	00006517          	auipc	a0,0x6
    1798:	2a450513          	addi	a0,a0,676 # 7a38 <malloc+0xa10>
    179c:	780050ef          	jal	6f1c <printf>
    exit(1);
    17a0:	00100513          	li	a0,1
    17a4:	0a0050ef          	jal	6844 <exit>

00000000000017a8 <truncate3>:
{
    17a8:	f7010113          	addi	sp,sp,-144
    17ac:	08113423          	sd	ra,136(sp)
    17b0:	08813023          	sd	s0,128(sp)
    17b4:	03913c23          	sd	s9,56(sp)
    17b8:	09010413          	addi	s0,sp,144
    17bc:	00050c93          	mv	s9,a0
  close(open("truncfile", O_CREATE|O_TRUNC|O_WRONLY));
    17c0:	60100593          	li	a1,1537
    17c4:	00006517          	auipc	a0,0x6
    17c8:	a6c50513          	addi	a0,a0,-1428 # 7230 <malloc+0x208>
    17cc:	0d8050ef          	jal	68a4 <open>
    17d0:	0b0050ef          	jal	6880 <close>
  pid = fork();
    17d4:	064050ef          	jal	6838 <fork>
  if(pid < 0){
    17d8:	0a054663          	bltz	a0,1884 <truncate3+0xdc>
  if(pid == 0){
    17dc:	10051a63          	bnez	a0,18f0 <truncate3+0x148>
    17e0:	06913c23          	sd	s1,120(sp)
    17e4:	07213823          	sd	s2,112(sp)
    17e8:	07313423          	sd	s3,104(sp)
    17ec:	07413023          	sd	s4,96(sp)
    17f0:	05513c23          	sd	s5,88(sp)
    17f4:	05613823          	sd	s6,80(sp)
    17f8:	05713423          	sd	s7,72(sp)
    17fc:	05813023          	sd	s8,64(sp)
    1800:	06400913          	li	s2,100
      int fd = open("truncfile", O_WRONLY);
    1804:	00100a93          	li	s5,1
    1808:	00006997          	auipc	s3,0x6
    180c:	a2898993          	addi	s3,s3,-1496 # 7230 <malloc+0x208>
      int n = write(fd, "1234567890", 10);
    1810:	00a00a13          	li	s4,10
    1814:	00006b17          	auipc	s6,0x6
    1818:	284b0b13          	addi	s6,s6,644 # 7a98 <malloc+0xa70>
      read(fd, buf, sizeof(buf));
    181c:	f7840c13          	addi	s8,s0,-136
    1820:	02000b93          	li	s7,32
      int fd = open("truncfile", O_WRONLY);
    1824:	000a8593          	mv	a1,s5
    1828:	00098513          	mv	a0,s3
    182c:	078050ef          	jal	68a4 <open>
    1830:	00050493          	mv	s1,a0
      if(fd < 0){
    1834:	08054463          	bltz	a0,18bc <truncate3+0x114>
      int n = write(fd, "1234567890", 10);
    1838:	000a0613          	mv	a2,s4
    183c:	000b0593          	mv	a1,s6
    1840:	034050ef          	jal	6874 <write>
      if(n != 10){
    1844:	09451863          	bne	a0,s4,18d4 <truncate3+0x12c>
      close(fd);
    1848:	00048513          	mv	a0,s1
    184c:	034050ef          	jal	6880 <close>
      fd = open("truncfile", O_RDONLY);
    1850:	00000593          	li	a1,0
    1854:	00098513          	mv	a0,s3
    1858:	04c050ef          	jal	68a4 <open>
    185c:	00050493          	mv	s1,a0
      read(fd, buf, sizeof(buf));
    1860:	000b8613          	mv	a2,s7
    1864:	000c0593          	mv	a1,s8
    1868:	000050ef          	jal	6868 <read>
      close(fd);
    186c:	00048513          	mv	a0,s1
    1870:	010050ef          	jal	6880 <close>
    for(int i = 0; i < 100; i++){
    1874:	fff9091b          	addiw	s2,s2,-1
    1878:	fa0916e3          	bnez	s2,1824 <truncate3+0x7c>
    exit(0);
    187c:	00000513          	li	a0,0
    1880:	7c5040ef          	jal	6844 <exit>
    1884:	06913c23          	sd	s1,120(sp)
    1888:	07213823          	sd	s2,112(sp)
    188c:	07313423          	sd	s3,104(sp)
    1890:	07413023          	sd	s4,96(sp)
    1894:	05513c23          	sd	s5,88(sp)
    1898:	05613823          	sd	s6,80(sp)
    189c:	05713423          	sd	s7,72(sp)
    18a0:	05813023          	sd	s8,64(sp)
    printf("%s: fork failed\n", s);
    18a4:	000c8593          	mv	a1,s9
    18a8:	00006517          	auipc	a0,0x6
    18ac:	1c050513          	addi	a0,a0,448 # 7a68 <malloc+0xa40>
    18b0:	66c050ef          	jal	6f1c <printf>
    exit(1);
    18b4:	00100513          	li	a0,1
    18b8:	78d040ef          	jal	6844 <exit>
        printf("%s: open failed\n", s);
    18bc:	000c8593          	mv	a1,s9
    18c0:	00006517          	auipc	a0,0x6
    18c4:	1c050513          	addi	a0,a0,448 # 7a80 <malloc+0xa58>
    18c8:	654050ef          	jal	6f1c <printf>
        exit(1);
    18cc:	00100513          	li	a0,1
    18d0:	775040ef          	jal	6844 <exit>
        printf("%s: write got %d, expected 10\n", s, n);
    18d4:	00050613          	mv	a2,a0
    18d8:	000c8593          	mv	a1,s9
    18dc:	00006517          	auipc	a0,0x6
    18e0:	1cc50513          	addi	a0,a0,460 # 7aa8 <malloc+0xa80>
    18e4:	638050ef          	jal	6f1c <printf>
        exit(1);
    18e8:	00100513          	li	a0,1
    18ec:	759040ef          	jal	6844 <exit>
    18f0:	06913c23          	sd	s1,120(sp)
    18f4:	07213823          	sd	s2,112(sp)
    18f8:	07313423          	sd	s3,104(sp)
    18fc:	07413023          	sd	s4,96(sp)
    1900:	05513c23          	sd	s5,88(sp)
    1904:	05613823          	sd	s6,80(sp)
    1908:	09600913          	li	s2,150
    int fd = open("truncfile", O_CREATE|O_WRONLY|O_TRUNC);
    190c:	60100a93          	li	s5,1537
    1910:	00006a17          	auipc	s4,0x6
    1914:	920a0a13          	addi	s4,s4,-1760 # 7230 <malloc+0x208>
    int n = write(fd, "xxx", 3);
    1918:	00300993          	li	s3,3
    191c:	00006b17          	auipc	s6,0x6
    1920:	1acb0b13          	addi	s6,s6,428 # 7ac8 <malloc+0xaa0>
    int fd = open("truncfile", O_CREATE|O_WRONLY|O_TRUNC);
    1924:	000a8593          	mv	a1,s5
    1928:	000a0513          	mv	a0,s4
    192c:	779040ef          	jal	68a4 <open>
    1930:	00050493          	mv	s1,a0
    if(fd < 0){
    1934:	04054463          	bltz	a0,197c <truncate3+0x1d4>
    int n = write(fd, "xxx", 3);
    1938:	00098613          	mv	a2,s3
    193c:	000b0593          	mv	a1,s6
    1940:	735040ef          	jal	6874 <write>
    if(n != 3){
    1944:	05351c63          	bne	a0,s3,199c <truncate3+0x1f4>
    close(fd);
    1948:	00048513          	mv	a0,s1
    194c:	735040ef          	jal	6880 <close>
  for(int i = 0; i < 150; i++){
    1950:	fff9091b          	addiw	s2,s2,-1
    1954:	fc0918e3          	bnez	s2,1924 <truncate3+0x17c>
    1958:	05713423          	sd	s7,72(sp)
    195c:	05813023          	sd	s8,64(sp)
  wait(&xstatus);
    1960:	f9c40513          	addi	a0,s0,-100
    1964:	6ed040ef          	jal	6850 <wait>
  unlink("truncfile");
    1968:	00006517          	auipc	a0,0x6
    196c:	8c850513          	addi	a0,a0,-1848 # 7230 <malloc+0x208>
    1970:	74d040ef          	jal	68bc <unlink>
  exit(xstatus);
    1974:	f9c42503          	lw	a0,-100(s0)
    1978:	6cd040ef          	jal	6844 <exit>
    197c:	05713423          	sd	s7,72(sp)
    1980:	05813023          	sd	s8,64(sp)
      printf("%s: open failed\n", s);
    1984:	000c8593          	mv	a1,s9
    1988:	00006517          	auipc	a0,0x6
    198c:	0f850513          	addi	a0,a0,248 # 7a80 <malloc+0xa58>
    1990:	58c050ef          	jal	6f1c <printf>
      exit(1);
    1994:	00100513          	li	a0,1
    1998:	6ad040ef          	jal	6844 <exit>
    199c:	05713423          	sd	s7,72(sp)
    19a0:	05813023          	sd	s8,64(sp)
      printf("%s: write got %d, expected 3\n", s, n);
    19a4:	00050613          	mv	a2,a0
    19a8:	000c8593          	mv	a1,s9
    19ac:	00006517          	auipc	a0,0x6
    19b0:	12450513          	addi	a0,a0,292 # 7ad0 <malloc+0xaa8>
    19b4:	568050ef          	jal	6f1c <printf>
      exit(1);
    19b8:	00100513          	li	a0,1
    19bc:	689040ef          	jal	6844 <exit>

00000000000019c0 <exectest>:
{
    19c0:	fb010113          	addi	sp,sp,-80
    19c4:	04113423          	sd	ra,72(sp)
    19c8:	04813023          	sd	s0,64(sp)
    19cc:	03213823          	sd	s2,48(sp)
    19d0:	05010413          	addi	s0,sp,80
    19d4:	00050913          	mv	s2,a0
  char *echoargv[] = { "echo", "OK", 0 };
    19d8:	00006797          	auipc	a5,0x6
    19dc:	80078793          	addi	a5,a5,-2048 # 71d8 <malloc+0x1b0>
    19e0:	fcf43023          	sd	a5,-64(s0)
    19e4:	00006797          	auipc	a5,0x6
    19e8:	10c78793          	addi	a5,a5,268 # 7af0 <malloc+0xac8>
    19ec:	fcf43423          	sd	a5,-56(s0)
    19f0:	fc043823          	sd	zero,-48(s0)
  unlink("echo-ok");
    19f4:	00006517          	auipc	a0,0x6
    19f8:	10450513          	addi	a0,a0,260 # 7af8 <malloc+0xad0>
    19fc:	6c1040ef          	jal	68bc <unlink>
  pid = fork();
    1a00:	639040ef          	jal	6838 <fork>
  if(pid < 0) {
    1a04:	04054663          	bltz	a0,1a50 <exectest+0x90>
    1a08:	02913c23          	sd	s1,56(sp)
    1a0c:	00050493          	mv	s1,a0
  if(pid == 0) {
    1a10:	08051463          	bnez	a0,1a98 <exectest+0xd8>
    close(1);
    1a14:	00100513          	li	a0,1
    1a18:	669040ef          	jal	6880 <close>
    fd = open("echo-ok", O_CREATE|O_WRONLY);
    1a1c:	20100593          	li	a1,513
    1a20:	00006517          	auipc	a0,0x6
    1a24:	0d850513          	addi	a0,a0,216 # 7af8 <malloc+0xad0>
    1a28:	67d040ef          	jal	68a4 <open>
    if(fd < 0) {
    1a2c:	04054063          	bltz	a0,1a6c <exectest+0xac>
    if(fd != 1) {
    1a30:	00100793          	li	a5,1
    1a34:	04f50863          	beq	a0,a5,1a84 <exectest+0xc4>
      printf("%s: wrong fd\n", s);
    1a38:	00090593          	mv	a1,s2
    1a3c:	00006517          	auipc	a0,0x6
    1a40:	0dc50513          	addi	a0,a0,220 # 7b18 <malloc+0xaf0>
    1a44:	4d8050ef          	jal	6f1c <printf>
      exit(1);
    1a48:	00100513          	li	a0,1
    1a4c:	5f9040ef          	jal	6844 <exit>
    1a50:	02913c23          	sd	s1,56(sp)
     printf("%s: fork failed\n", s);
    1a54:	00090593          	mv	a1,s2
    1a58:	00006517          	auipc	a0,0x6
    1a5c:	01050513          	addi	a0,a0,16 # 7a68 <malloc+0xa40>
    1a60:	4bc050ef          	jal	6f1c <printf>
     exit(1);
    1a64:	00100513          	li	a0,1
    1a68:	5dd040ef          	jal	6844 <exit>
      printf("%s: create failed\n", s);
    1a6c:	00090593          	mv	a1,s2
    1a70:	00006517          	auipc	a0,0x6
    1a74:	09050513          	addi	a0,a0,144 # 7b00 <malloc+0xad8>
    1a78:	4a4050ef          	jal	6f1c <printf>
      exit(1);
    1a7c:	00100513          	li	a0,1
    1a80:	5c5040ef          	jal	6844 <exit>
    if(exec("echo", echoargv) < 0){
    1a84:	fc040593          	addi	a1,s0,-64
    1a88:	00005517          	auipc	a0,0x5
    1a8c:	75050513          	addi	a0,a0,1872 # 71d8 <malloc+0x1b0>
    1a90:	609040ef          	jal	6898 <exec>
    1a94:	00054e63          	bltz	a0,1ab0 <exectest+0xf0>
  if (wait(&xstatus) != pid) {
    1a98:	fdc40513          	addi	a0,s0,-36
    1a9c:	5b5040ef          	jal	6850 <wait>
    1aa0:	02951463          	bne	a0,s1,1ac8 <exectest+0x108>
  if(xstatus != 0)
    1aa4:	fdc42503          	lw	a0,-36(s0)
    1aa8:	02050a63          	beqz	a0,1adc <exectest+0x11c>
    exit(xstatus);
    1aac:	599040ef          	jal	6844 <exit>
      printf("%s: exec echo failed\n", s);
    1ab0:	00090593          	mv	a1,s2
    1ab4:	00006517          	auipc	a0,0x6
    1ab8:	07450513          	addi	a0,a0,116 # 7b28 <malloc+0xb00>
    1abc:	460050ef          	jal	6f1c <printf>
      exit(1);
    1ac0:	00100513          	li	a0,1
    1ac4:	581040ef          	jal	6844 <exit>
    printf("%s: wait failed!\n", s);
    1ac8:	00090593          	mv	a1,s2
    1acc:	00006517          	auipc	a0,0x6
    1ad0:	07450513          	addi	a0,a0,116 # 7b40 <malloc+0xb18>
    1ad4:	448050ef          	jal	6f1c <printf>
    1ad8:	fcdff06f          	j	1aa4 <exectest+0xe4>
  fd = open("echo-ok", O_RDONLY);
    1adc:	00000593          	li	a1,0
    1ae0:	00006517          	auipc	a0,0x6
    1ae4:	01850513          	addi	a0,a0,24 # 7af8 <malloc+0xad0>
    1ae8:	5bd040ef          	jal	68a4 <open>
  if(fd < 0) {
    1aec:	02054863          	bltz	a0,1b1c <exectest+0x15c>
  if (read(fd, buf, 2) != 2) {
    1af0:	00200613          	li	a2,2
    1af4:	fb840593          	addi	a1,s0,-72
    1af8:	571040ef          	jal	6868 <read>
    1afc:	00200793          	li	a5,2
    1b00:	02f50a63          	beq	a0,a5,1b34 <exectest+0x174>
    printf("%s: read failed\n", s);
    1b04:	00090593          	mv	a1,s2
    1b08:	00006517          	auipc	a0,0x6
    1b0c:	aa050513          	addi	a0,a0,-1376 # 75a8 <malloc+0x580>
    1b10:	40c050ef          	jal	6f1c <printf>
    exit(1);
    1b14:	00100513          	li	a0,1
    1b18:	52d040ef          	jal	6844 <exit>
    printf("%s: open failed\n", s);
    1b1c:	00090593          	mv	a1,s2
    1b20:	00006517          	auipc	a0,0x6
    1b24:	f6050513          	addi	a0,a0,-160 # 7a80 <malloc+0xa58>
    1b28:	3f4050ef          	jal	6f1c <printf>
    exit(1);
    1b2c:	00100513          	li	a0,1
    1b30:	515040ef          	jal	6844 <exit>
  unlink("echo-ok");
    1b34:	00006517          	auipc	a0,0x6
    1b38:	fc450513          	addi	a0,a0,-60 # 7af8 <malloc+0xad0>
    1b3c:	581040ef          	jal	68bc <unlink>
  if(buf[0] == 'O' && buf[1] == 'K')
    1b40:	fb844703          	lbu	a4,-72(s0)
    1b44:	04f00793          	li	a5,79
    1b48:	00f71863          	bne	a4,a5,1b58 <exectest+0x198>
    1b4c:	fb944703          	lbu	a4,-71(s0)
    1b50:	04b00793          	li	a5,75
    1b54:	00f70e63          	beq	a4,a5,1b70 <exectest+0x1b0>
    printf("%s: wrong output\n", s);
    1b58:	00090593          	mv	a1,s2
    1b5c:	00006517          	auipc	a0,0x6
    1b60:	ffc50513          	addi	a0,a0,-4 # 7b58 <malloc+0xb30>
    1b64:	3b8050ef          	jal	6f1c <printf>
    exit(1);
    1b68:	00100513          	li	a0,1
    1b6c:	4d9040ef          	jal	6844 <exit>
    exit(0);
    1b70:	00000513          	li	a0,0
    1b74:	4d1040ef          	jal	6844 <exit>

0000000000001b78 <pipe1>:
{
    1b78:	fa010113          	addi	sp,sp,-96
    1b7c:	04113c23          	sd	ra,88(sp)
    1b80:	04813823          	sd	s0,80(sp)
    1b84:	01813823          	sd	s8,16(sp)
    1b88:	06010413          	addi	s0,sp,96
    1b8c:	00050c13          	mv	s8,a0
  if(pipe(fds) != 0){
    1b90:	fa840513          	addi	a0,s0,-88
    1b94:	4c9040ef          	jal	685c <pipe>
    1b98:	08051a63          	bnez	a0,1c2c <pipe1+0xb4>
    1b9c:	04913423          	sd	s1,72(sp)
    1ba0:	03313c23          	sd	s3,56(sp)
    1ba4:	00050493          	mv	s1,a0
  pid = fork();
    1ba8:	491040ef          	jal	6838 <fork>
    1bac:	00050993          	mv	s3,a0
  if(pid == 0){
    1bb0:	0a050863          	beqz	a0,1c60 <pipe1+0xe8>
  } else if(pid > 0){
    1bb4:	1ca05863          	blez	a0,1d84 <pipe1+0x20c>
    1bb8:	05213023          	sd	s2,64(sp)
    1bbc:	03413823          	sd	s4,48(sp)
    close(fds[1]);
    1bc0:	fac42503          	lw	a0,-84(s0)
    1bc4:	4bd040ef          	jal	6880 <close>
    total = 0;
    1bc8:	00048993          	mv	s3,s1
    cc = 1;
    1bcc:	00100913          	li	s2,1
    while((n = read(fds[0], buf, cc)) > 0){
    1bd0:	0000ca17          	auipc	s4,0xc
    1bd4:	0e8a0a13          	addi	s4,s4,232 # dcb8 <buf>
    1bd8:	00090613          	mv	a2,s2
    1bdc:	000a0593          	mv	a1,s4
    1be0:	fa842503          	lw	a0,-88(s0)
    1be4:	485040ef          	jal	6868 <read>
    1be8:	00050593          	mv	a1,a0
    1bec:	14a05063          	blez	a0,1d2c <pipe1+0x1b4>
    1bf0:	0000c797          	auipc	a5,0xc
    1bf4:	0c878793          	addi	a5,a5,200 # dcb8 <buf>
    1bf8:	00b4863b          	addw	a2,s1,a1
        if((buf[i] & 0xff) != (seq++ & 0xff)){
    1bfc:	0007c683          	lbu	a3,0(a5)
    1c00:	0ff4f713          	zext.b	a4,s1
    1c04:	0ee69a63          	bne	a3,a4,1cf8 <pipe1+0x180>
    1c08:	0014849b          	addiw	s1,s1,1
      for(i = 0; i < n; i++){
    1c0c:	00178793          	addi	a5,a5,1
    1c10:	fec496e3          	bne	s1,a2,1bfc <pipe1+0x84>
      total += n;
    1c14:	00b989bb          	addw	s3,s3,a1
      cc = cc * 2;
    1c18:	0019191b          	slliw	s2,s2,0x1
      if(cc > sizeof(buf))
    1c1c:	000037b7          	lui	a5,0x3
    1c20:	fb27fce3          	bgeu	a5,s2,1bd8 <pipe1+0x60>
        cc = sizeof(buf);
    1c24:	00078913          	mv	s2,a5
    1c28:	fb1ff06f          	j	1bd8 <pipe1+0x60>
    1c2c:	04913423          	sd	s1,72(sp)
    1c30:	05213023          	sd	s2,64(sp)
    1c34:	03313c23          	sd	s3,56(sp)
    1c38:	03413823          	sd	s4,48(sp)
    1c3c:	03513423          	sd	s5,40(sp)
    1c40:	03613023          	sd	s6,32(sp)
    1c44:	01713c23          	sd	s7,24(sp)
    printf("%s: pipe() failed\n", s);
    1c48:	000c0593          	mv	a1,s8
    1c4c:	00006517          	auipc	a0,0x6
    1c50:	f2450513          	addi	a0,a0,-220 # 7b70 <malloc+0xb48>
    1c54:	2c8050ef          	jal	6f1c <printf>
    exit(1);
    1c58:	00100513          	li	a0,1
    1c5c:	3e9040ef          	jal	6844 <exit>
    1c60:	05213023          	sd	s2,64(sp)
    1c64:	03413823          	sd	s4,48(sp)
    1c68:	03513423          	sd	s5,40(sp)
    1c6c:	03613023          	sd	s6,32(sp)
    1c70:	01713c23          	sd	s7,24(sp)
    close(fds[0]);
    1c74:	fa842503          	lw	a0,-88(s0)
    1c78:	409040ef          	jal	6880 <close>
    for(n = 0; n < N; n++){
    1c7c:	0000cb17          	auipc	s6,0xc
    1c80:	03cb0b13          	addi	s6,s6,60 # dcb8 <buf>
    1c84:	416004bb          	negw	s1,s6
    1c88:	0ff4f493          	zext.b	s1,s1
    1c8c:	409b0913          	addi	s2,s6,1033
      if(write(fds[1], buf, SZ) != SZ){
    1c90:	40900a13          	li	s4,1033
    1c94:	000b0b93          	mv	s7,s6
    for(n = 0; n < N; n++){
    1c98:	00001ab7          	lui	s5,0x1
    1c9c:	42da8a93          	addi	s5,s5,1069 # 142d <bigdir+0x91>
{
    1ca0:	000b0793          	mv	a5,s6
        buf[i] = seq++;
    1ca4:	0097873b          	addw	a4,a5,s1
    1ca8:	00e78023          	sb	a4,0(a5) # 3000 <sbrkmuch+0x1ac>
      for(i = 0; i < SZ; i++)
    1cac:	00178793          	addi	a5,a5,1
    1cb0:	ff279ae3          	bne	a5,s2,1ca4 <pipe1+0x12c>
      if(write(fds[1], buf, SZ) != SZ){
    1cb4:	000a0613          	mv	a2,s4
    1cb8:	000b8593          	mv	a1,s7
    1cbc:	fac42503          	lw	a0,-84(s0)
    1cc0:	3b5040ef          	jal	6874 <write>
    1cc4:	01451e63          	bne	a0,s4,1ce0 <pipe1+0x168>
    1cc8:	4099899b          	addiw	s3,s3,1033
    for(n = 0; n < N; n++){
    1ccc:	0094849b          	addiw	s1,s1,9
    1cd0:	0ff4f493          	zext.b	s1,s1
    1cd4:	fd5996e3          	bne	s3,s5,1ca0 <pipe1+0x128>
    exit(0);
    1cd8:	00000513          	li	a0,0
    1cdc:	369040ef          	jal	6844 <exit>
        printf("%s: pipe1 oops 1\n", s);
    1ce0:	000c0593          	mv	a1,s8
    1ce4:	00006517          	auipc	a0,0x6
    1ce8:	ea450513          	addi	a0,a0,-348 # 7b88 <malloc+0xb60>
    1cec:	230050ef          	jal	6f1c <printf>
        exit(1);
    1cf0:	00100513          	li	a0,1
    1cf4:	351040ef          	jal	6844 <exit>
          printf("%s: pipe1 oops 2\n", s);
    1cf8:	000c0593          	mv	a1,s8
    1cfc:	00006517          	auipc	a0,0x6
    1d00:	ea450513          	addi	a0,a0,-348 # 7ba0 <malloc+0xb78>
    1d04:	218050ef          	jal	6f1c <printf>
          return;
    1d08:	04813483          	ld	s1,72(sp)
    1d0c:	04013903          	ld	s2,64(sp)
    1d10:	03813983          	ld	s3,56(sp)
    1d14:	03013a03          	ld	s4,48(sp)
}
    1d18:	05813083          	ld	ra,88(sp)
    1d1c:	05013403          	ld	s0,80(sp)
    1d20:	01013c03          	ld	s8,16(sp)
    1d24:	06010113          	addi	sp,sp,96
    1d28:	00008067          	ret
    if(total != N * SZ){
    1d2c:	000017b7          	lui	a5,0x1
    1d30:	42d78793          	addi	a5,a5,1069 # 142d <bigdir+0x91>
    1d34:	02f98663          	beq	s3,a5,1d60 <pipe1+0x1e8>
    1d38:	03513423          	sd	s5,40(sp)
    1d3c:	03613023          	sd	s6,32(sp)
    1d40:	01713c23          	sd	s7,24(sp)
      printf("%s: pipe1 oops 3 total %d\n", s, total);
    1d44:	00098613          	mv	a2,s3
    1d48:	000c0593          	mv	a1,s8
    1d4c:	00006517          	auipc	a0,0x6
    1d50:	e6c50513          	addi	a0,a0,-404 # 7bb8 <malloc+0xb90>
    1d54:	1c8050ef          	jal	6f1c <printf>
      exit(1);
    1d58:	00100513          	li	a0,1
    1d5c:	2e9040ef          	jal	6844 <exit>
    1d60:	03513423          	sd	s5,40(sp)
    1d64:	03613023          	sd	s6,32(sp)
    1d68:	01713c23          	sd	s7,24(sp)
    close(fds[0]);
    1d6c:	fa842503          	lw	a0,-88(s0)
    1d70:	311040ef          	jal	6880 <close>
    wait(&xstatus);
    1d74:	fa440513          	addi	a0,s0,-92
    1d78:	2d9040ef          	jal	6850 <wait>
    exit(xstatus);
    1d7c:	fa442503          	lw	a0,-92(s0)
    1d80:	2c5040ef          	jal	6844 <exit>
    1d84:	05213023          	sd	s2,64(sp)
    1d88:	03413823          	sd	s4,48(sp)
    1d8c:	03513423          	sd	s5,40(sp)
    1d90:	03613023          	sd	s6,32(sp)
    1d94:	01713c23          	sd	s7,24(sp)
    printf("%s: fork() failed\n", s);
    1d98:	000c0593          	mv	a1,s8
    1d9c:	00006517          	auipc	a0,0x6
    1da0:	e3c50513          	addi	a0,a0,-452 # 7bd8 <malloc+0xbb0>
    1da4:	178050ef          	jal	6f1c <printf>
    exit(1);
    1da8:	00100513          	li	a0,1
    1dac:	299040ef          	jal	6844 <exit>

0000000000001db0 <exitwait>:
{
    1db0:	fb010113          	addi	sp,sp,-80
    1db4:	04113423          	sd	ra,72(sp)
    1db8:	04813023          	sd	s0,64(sp)
    1dbc:	02913c23          	sd	s1,56(sp)
    1dc0:	03213823          	sd	s2,48(sp)
    1dc4:	03313423          	sd	s3,40(sp)
    1dc8:	03413023          	sd	s4,32(sp)
    1dcc:	01513c23          	sd	s5,24(sp)
    1dd0:	05010413          	addi	s0,sp,80
    1dd4:	00050a93          	mv	s5,a0
  for(i = 0; i < 100; i++){
    1dd8:	00000913          	li	s2,0
      if(wait(&xstate) != pid){
    1ddc:	fbc40993          	addi	s3,s0,-68
  for(i = 0; i < 100; i++){
    1de0:	06400a13          	li	s4,100
    pid = fork();
    1de4:	255040ef          	jal	6838 <fork>
    1de8:	00050493          	mv	s1,a0
    if(pid < 0){
    1dec:	04054463          	bltz	a0,1e34 <exitwait+0x84>
    if(pid){
    1df0:	08050663          	beqz	a0,1e7c <exitwait+0xcc>
      if(wait(&xstate) != pid){
    1df4:	00098513          	mv	a0,s3
    1df8:	259040ef          	jal	6850 <wait>
    1dfc:	04951863          	bne	a0,s1,1e4c <exitwait+0x9c>
      if(i != xstate) {
    1e00:	fbc42783          	lw	a5,-68(s0)
    1e04:	07279063          	bne	a5,s2,1e64 <exitwait+0xb4>
  for(i = 0; i < 100; i++){
    1e08:	0019091b          	addiw	s2,s2,1
    1e0c:	fd491ce3          	bne	s2,s4,1de4 <exitwait+0x34>
}
    1e10:	04813083          	ld	ra,72(sp)
    1e14:	04013403          	ld	s0,64(sp)
    1e18:	03813483          	ld	s1,56(sp)
    1e1c:	03013903          	ld	s2,48(sp)
    1e20:	02813983          	ld	s3,40(sp)
    1e24:	02013a03          	ld	s4,32(sp)
    1e28:	01813a83          	ld	s5,24(sp)
    1e2c:	05010113          	addi	sp,sp,80
    1e30:	00008067          	ret
      printf("%s: fork failed\n", s);
    1e34:	000a8593          	mv	a1,s5
    1e38:	00006517          	auipc	a0,0x6
    1e3c:	c3050513          	addi	a0,a0,-976 # 7a68 <malloc+0xa40>
    1e40:	0dc050ef          	jal	6f1c <printf>
      exit(1);
    1e44:	00100513          	li	a0,1
    1e48:	1fd040ef          	jal	6844 <exit>
        printf("%s: wait wrong pid\n", s);
    1e4c:	000a8593          	mv	a1,s5
    1e50:	00006517          	auipc	a0,0x6
    1e54:	da050513          	addi	a0,a0,-608 # 7bf0 <malloc+0xbc8>
    1e58:	0c4050ef          	jal	6f1c <printf>
        exit(1);
    1e5c:	00100513          	li	a0,1
    1e60:	1e5040ef          	jal	6844 <exit>
        printf("%s: wait wrong exit status\n", s);
    1e64:	000a8593          	mv	a1,s5
    1e68:	00006517          	auipc	a0,0x6
    1e6c:	da050513          	addi	a0,a0,-608 # 7c08 <malloc+0xbe0>
    1e70:	0ac050ef          	jal	6f1c <printf>
        exit(1);
    1e74:	00100513          	li	a0,1
    1e78:	1cd040ef          	jal	6844 <exit>
      exit(i);
    1e7c:	00090513          	mv	a0,s2
    1e80:	1c5040ef          	jal	6844 <exit>

0000000000001e84 <twochildren>:
{
    1e84:	fe010113          	addi	sp,sp,-32
    1e88:	00113c23          	sd	ra,24(sp)
    1e8c:	00813823          	sd	s0,16(sp)
    1e90:	00913423          	sd	s1,8(sp)
    1e94:	01213023          	sd	s2,0(sp)
    1e98:	02010413          	addi	s0,sp,32
    1e9c:	00050913          	mv	s2,a0
    1ea0:	3e800493          	li	s1,1000
    int pid1 = fork();
    1ea4:	195040ef          	jal	6838 <fork>
    if(pid1 < 0){
    1ea8:	04054263          	bltz	a0,1eec <twochildren+0x68>
    if(pid1 == 0){
    1eac:	04050c63          	beqz	a0,1f04 <twochildren+0x80>
      int pid2 = fork();
    1eb0:	189040ef          	jal	6838 <fork>
      if(pid2 < 0){
    1eb4:	04054a63          	bltz	a0,1f08 <twochildren+0x84>
      if(pid2 == 0){
    1eb8:	06050463          	beqz	a0,1f20 <twochildren+0x9c>
        wait(0);
    1ebc:	00000513          	li	a0,0
    1ec0:	191040ef          	jal	6850 <wait>
        wait(0);
    1ec4:	00000513          	li	a0,0
    1ec8:	189040ef          	jal	6850 <wait>
  for(int i = 0; i < 1000; i++){
    1ecc:	fff4849b          	addiw	s1,s1,-1
    1ed0:	fc049ae3          	bnez	s1,1ea4 <twochildren+0x20>
}
    1ed4:	01813083          	ld	ra,24(sp)
    1ed8:	01013403          	ld	s0,16(sp)
    1edc:	00813483          	ld	s1,8(sp)
    1ee0:	00013903          	ld	s2,0(sp)
    1ee4:	02010113          	addi	sp,sp,32
    1ee8:	00008067          	ret
      printf("%s: fork failed\n", s);
    1eec:	00090593          	mv	a1,s2
    1ef0:	00006517          	auipc	a0,0x6
    1ef4:	b7850513          	addi	a0,a0,-1160 # 7a68 <malloc+0xa40>
    1ef8:	024050ef          	jal	6f1c <printf>
      exit(1);
    1efc:	00100513          	li	a0,1
    1f00:	145040ef          	jal	6844 <exit>
      exit(0);
    1f04:	141040ef          	jal	6844 <exit>
        printf("%s: fork failed\n", s);
    1f08:	00090593          	mv	a1,s2
    1f0c:	00006517          	auipc	a0,0x6
    1f10:	b5c50513          	addi	a0,a0,-1188 # 7a68 <malloc+0xa40>
    1f14:	008050ef          	jal	6f1c <printf>
        exit(1);
    1f18:	00100513          	li	a0,1
    1f1c:	129040ef          	jal	6844 <exit>
        exit(0);
    1f20:	125040ef          	jal	6844 <exit>

0000000000001f24 <forkfork>:
{
    1f24:	fd010113          	addi	sp,sp,-48
    1f28:	02113423          	sd	ra,40(sp)
    1f2c:	02813023          	sd	s0,32(sp)
    1f30:	00913c23          	sd	s1,24(sp)
    1f34:	03010413          	addi	s0,sp,48
    1f38:	00050493          	mv	s1,a0
    int pid = fork();
    1f3c:	0fd040ef          	jal	6838 <fork>
    if(pid < 0){
    1f40:	04054463          	bltz	a0,1f88 <forkfork+0x64>
    if(pid == 0){
    1f44:	04050e63          	beqz	a0,1fa0 <forkfork+0x7c>
    int pid = fork();
    1f48:	0f1040ef          	jal	6838 <fork>
    if(pid < 0){
    1f4c:	02054e63          	bltz	a0,1f88 <forkfork+0x64>
    if(pid == 0){
    1f50:	04050863          	beqz	a0,1fa0 <forkfork+0x7c>
    wait(&xstatus);
    1f54:	fdc40513          	addi	a0,s0,-36
    1f58:	0f9040ef          	jal	6850 <wait>
    if(xstatus != 0) {
    1f5c:	fdc42783          	lw	a5,-36(s0)
    1f60:	06079a63          	bnez	a5,1fd4 <forkfork+0xb0>
    wait(&xstatus);
    1f64:	fdc40513          	addi	a0,s0,-36
    1f68:	0e9040ef          	jal	6850 <wait>
    if(xstatus != 0) {
    1f6c:	fdc42783          	lw	a5,-36(s0)
    1f70:	06079263          	bnez	a5,1fd4 <forkfork+0xb0>
}
    1f74:	02813083          	ld	ra,40(sp)
    1f78:	02013403          	ld	s0,32(sp)
    1f7c:	01813483          	ld	s1,24(sp)
    1f80:	03010113          	addi	sp,sp,48
    1f84:	00008067          	ret
      printf("%s: fork failed", s);
    1f88:	00048593          	mv	a1,s1
    1f8c:	00006517          	auipc	a0,0x6
    1f90:	c9c50513          	addi	a0,a0,-868 # 7c28 <malloc+0xc00>
    1f94:	789040ef          	jal	6f1c <printf>
      exit(1);
    1f98:	00100513          	li	a0,1
    1f9c:	0a9040ef          	jal	6844 <exit>
{
    1fa0:	0c800493          	li	s1,200
        int pid1 = fork();
    1fa4:	095040ef          	jal	6838 <fork>
        if(pid1 < 0){
    1fa8:	02054063          	bltz	a0,1fc8 <forkfork+0xa4>
        if(pid1 == 0){
    1fac:	02050263          	beqz	a0,1fd0 <forkfork+0xac>
        wait(0);
    1fb0:	00000513          	li	a0,0
    1fb4:	09d040ef          	jal	6850 <wait>
      for(int j = 0; j < 200; j++){
    1fb8:	fff4849b          	addiw	s1,s1,-1
    1fbc:	fe0494e3          	bnez	s1,1fa4 <forkfork+0x80>
      exit(0);
    1fc0:	00000513          	li	a0,0
    1fc4:	081040ef          	jal	6844 <exit>
          exit(1);
    1fc8:	00100513          	li	a0,1
    1fcc:	079040ef          	jal	6844 <exit>
          exit(0);
    1fd0:	075040ef          	jal	6844 <exit>
      printf("%s: fork in child failed", s);
    1fd4:	00048593          	mv	a1,s1
    1fd8:	00006517          	auipc	a0,0x6
    1fdc:	c6050513          	addi	a0,a0,-928 # 7c38 <malloc+0xc10>
    1fe0:	73d040ef          	jal	6f1c <printf>
      exit(1);
    1fe4:	00100513          	li	a0,1
    1fe8:	05d040ef          	jal	6844 <exit>

0000000000001fec <reparent2>:
{
    1fec:	fe010113          	addi	sp,sp,-32
    1ff0:	00113c23          	sd	ra,24(sp)
    1ff4:	00813823          	sd	s0,16(sp)
    1ff8:	00913423          	sd	s1,8(sp)
    1ffc:	02010413          	addi	s0,sp,32
    2000:	32000493          	li	s1,800
    int pid1 = fork();
    2004:	035040ef          	jal	6838 <fork>
    if(pid1 < 0){
    2008:	02054063          	bltz	a0,2028 <reparent2+0x3c>
    if(pid1 == 0){
    200c:	02050863          	beqz	a0,203c <reparent2+0x50>
    wait(0);
    2010:	00000513          	li	a0,0
    2014:	03d040ef          	jal	6850 <wait>
  for(int i = 0; i < 800; i++){
    2018:	fff4849b          	addiw	s1,s1,-1
    201c:	fe0494e3          	bnez	s1,2004 <reparent2+0x18>
  exit(0);
    2020:	00000513          	li	a0,0
    2024:	021040ef          	jal	6844 <exit>
      printf("fork failed\n");
    2028:	00007517          	auipc	a0,0x7
    202c:	fe850513          	addi	a0,a0,-24 # 9010 <malloc+0x1fe8>
    2030:	6ed040ef          	jal	6f1c <printf>
      exit(1);
    2034:	00100513          	li	a0,1
    2038:	00d040ef          	jal	6844 <exit>
      fork();
    203c:	7fc040ef          	jal	6838 <fork>
      fork();
    2040:	7f8040ef          	jal	6838 <fork>
      exit(0);
    2044:	00000513          	li	a0,0
    2048:	7fc040ef          	jal	6844 <exit>

000000000000204c <createdelete>:
{
    204c:	f6010113          	addi	sp,sp,-160
    2050:	08113c23          	sd	ra,152(sp)
    2054:	08813823          	sd	s0,144(sp)
    2058:	08913423          	sd	s1,136(sp)
    205c:	09213023          	sd	s2,128(sp)
    2060:	07313c23          	sd	s3,120(sp)
    2064:	07413823          	sd	s4,112(sp)
    2068:	07513423          	sd	s5,104(sp)
    206c:	07613023          	sd	s6,96(sp)
    2070:	05713c23          	sd	s7,88(sp)
    2074:	05813823          	sd	s8,80(sp)
    2078:	05913423          	sd	s9,72(sp)
    207c:	05a13023          	sd	s10,64(sp)
    2080:	03b13c23          	sd	s11,56(sp)
    2084:	0a010413          	addi	s0,sp,160
    2088:	00050d93          	mv	s11,a0
  for(pi = 0; pi < NCHILD; pi++){
    208c:	00000913          	li	s2,0
    2090:	00400993          	li	s3,4
    pid = fork();
    2094:	7a4040ef          	jal	6838 <fork>
    2098:	00050493          	mv	s1,a0
    if(pid < 0){
    209c:	04054a63          	bltz	a0,20f0 <createdelete+0xa4>
    if(pid == 0){
    20a0:	06050463          	beqz	a0,2108 <createdelete+0xbc>
  for(pi = 0; pi < NCHILD; pi++){
    20a4:	0019091b          	addiw	s2,s2,1
    20a8:	ff3916e3          	bne	s2,s3,2094 <createdelete+0x48>
    20ac:	00400493          	li	s1,4
    wait(&xstatus);
    20b0:	f6c40913          	addi	s2,s0,-148
    20b4:	00090513          	mv	a0,s2
    20b8:	798040ef          	jal	6850 <wait>
    if(xstatus != 0)
    20bc:	f6c42a83          	lw	s5,-148(s0)
    20c0:	0e0a9863          	bnez	s5,21b0 <createdelete+0x164>
  for(pi = 0; pi < NCHILD; pi++){
    20c4:	fff4849b          	addiw	s1,s1,-1
    20c8:	fe0496e3          	bnez	s1,20b4 <createdelete+0x68>
  name[0] = name[1] = name[2] = 0;
    20cc:	f6040923          	sb	zero,-142(s0)
    20d0:	03000913          	li	s2,48
    20d4:	fff00a13          	li	s4,-1
      if((i == 0 || i >= N/2) && fd < 0){
    20d8:	00900d13          	li	s10,9
    20dc:	07000c93          	li	s9,112
      fd = open(name, 0);
    20e0:	f7040c13          	addi	s8,s0,-144
      } else if((i >= 1 && i < N/2) && fd >= 0){
    20e4:	00800b93          	li	s7,8
    for(pi = 0; pi < NCHILD; pi++){
    20e8:	07400b13          	li	s6,116
    20ec:	15c0006f          	j	2248 <createdelete+0x1fc>
      printf("%s: fork failed\n", s);
    20f0:	000d8593          	mv	a1,s11
    20f4:	00006517          	auipc	a0,0x6
    20f8:	97450513          	addi	a0,a0,-1676 # 7a68 <malloc+0xa40>
    20fc:	621040ef          	jal	6f1c <printf>
      exit(1);
    2100:	00100513          	li	a0,1
    2104:	740040ef          	jal	6844 <exit>
      name[0] = 'p' + pi;
    2108:	0709091b          	addiw	s2,s2,112
    210c:	f7240823          	sb	s2,-144(s0)
      name[2] = '\0';
    2110:	f6040923          	sb	zero,-142(s0)
        fd = open(name, O_CREATE | O_RDWR);
    2114:	f7040913          	addi	s2,s0,-144
    2118:	20200993          	li	s3,514
      for(i = 0; i < N; i++){
    211c:	01400a13          	li	s4,20
    2120:	0400006f          	j	2160 <createdelete+0x114>
          printf("%s: create failed\n", s);
    2124:	000d8593          	mv	a1,s11
    2128:	00006517          	auipc	a0,0x6
    212c:	9d850513          	addi	a0,a0,-1576 # 7b00 <malloc+0xad8>
    2130:	5ed040ef          	jal	6f1c <printf>
          exit(1);
    2134:	00100513          	li	a0,1
    2138:	70c040ef          	jal	6844 <exit>
          name[1] = '0' + (i / 2);
    213c:	01f4d79b          	srliw	a5,s1,0x1f
    2140:	009787bb          	addw	a5,a5,s1
    2144:	4017d79b          	sraiw	a5,a5,0x1
    2148:	0307879b          	addiw	a5,a5,48
    214c:	f6f408a3          	sb	a5,-143(s0)
          if(unlink(name) < 0){
    2150:	00090513          	mv	a0,s2
    2154:	768040ef          	jal	68bc <unlink>
    2158:	04054063          	bltz	a0,2198 <createdelete+0x14c>
      for(i = 0; i < N; i++){
    215c:	0014849b          	addiw	s1,s1,1
        name[1] = '0' + i;
    2160:	0304879b          	addiw	a5,s1,48
    2164:	f6f408a3          	sb	a5,-143(s0)
        fd = open(name, O_CREATE | O_RDWR);
    2168:	00098593          	mv	a1,s3
    216c:	00090513          	mv	a0,s2
    2170:	734040ef          	jal	68a4 <open>
        if(fd < 0){
    2174:	fa0548e3          	bltz	a0,2124 <createdelete+0xd8>
        close(fd);
    2178:	708040ef          	jal	6880 <close>
        if(i > 0 && (i % 2 ) == 0){
    217c:	fe9050e3          	blez	s1,215c <createdelete+0x110>
    2180:	0014f793          	andi	a5,s1,1
    2184:	fa078ce3          	beqz	a5,213c <createdelete+0xf0>
      for(i = 0; i < N; i++){
    2188:	0014849b          	addiw	s1,s1,1
    218c:	fd449ae3          	bne	s1,s4,2160 <createdelete+0x114>
      exit(0);
    2190:	00000513          	li	a0,0
    2194:	6b0040ef          	jal	6844 <exit>
            printf("%s: unlink failed\n", s);
    2198:	000d8593          	mv	a1,s11
    219c:	00006517          	auipc	a0,0x6
    21a0:	abc50513          	addi	a0,a0,-1348 # 7c58 <malloc+0xc30>
    21a4:	579040ef          	jal	6f1c <printf>
            exit(1);
    21a8:	00100513          	li	a0,1
    21ac:	698040ef          	jal	6844 <exit>
      exit(1);
    21b0:	00100513          	li	a0,1
    21b4:	690040ef          	jal	6844 <exit>
      } else if((i >= 1 && i < N/2) && fd >= 0){
    21b8:	054bf863          	bgeu	s7,s4,2208 <createdelete+0x1bc>
      if(fd >= 0)
    21bc:	06055663          	bgez	a0,2228 <createdelete+0x1dc>
    for(pi = 0; pi < NCHILD; pi++){
    21c0:	0014849b          	addiw	s1,s1,1
    21c4:	0ff4f493          	zext.b	s1,s1
    21c8:	07648463          	beq	s1,s6,2230 <createdelete+0x1e4>
      name[0] = 'p' + pi;
    21cc:	f6940823          	sb	s1,-144(s0)
      name[1] = '0' + i;
    21d0:	f72408a3          	sb	s2,-143(s0)
      fd = open(name, 0);
    21d4:	00000593          	li	a1,0
    21d8:	000c0513          	mv	a0,s8
    21dc:	6c8040ef          	jal	68a4 <open>
      if((i == 0 || i >= N/2) && fd < 0){
    21e0:	01f5579b          	srliw	a5,a0,0x1f
    21e4:	fc078ae3          	beqz	a5,21b8 <createdelete+0x16c>
    21e8:	fc0988e3          	beqz	s3,21b8 <createdelete+0x16c>
        printf("%s: oops createdelete %s didn't exist\n", s, name);
    21ec:	f7040613          	addi	a2,s0,-144
    21f0:	000d8593          	mv	a1,s11
    21f4:	00006517          	auipc	a0,0x6
    21f8:	a7c50513          	addi	a0,a0,-1412 # 7c70 <malloc+0xc48>
    21fc:	521040ef          	jal	6f1c <printf>
        exit(1);
    2200:	00100513          	li	a0,1
    2204:	640040ef          	jal	6844 <exit>
      } else if((i >= 1 && i < N/2) && fd >= 0){
    2208:	fa054ce3          	bltz	a0,21c0 <createdelete+0x174>
        printf("%s: oops createdelete %s did exist\n", s, name);
    220c:	f7040613          	addi	a2,s0,-144
    2210:	000d8593          	mv	a1,s11
    2214:	00006517          	auipc	a0,0x6
    2218:	a8450513          	addi	a0,a0,-1404 # 7c98 <malloc+0xc70>
    221c:	501040ef          	jal	6f1c <printf>
        exit(1);
    2220:	00100513          	li	a0,1
    2224:	620040ef          	jal	6844 <exit>
        close(fd);
    2228:	658040ef          	jal	6880 <close>
    222c:	f95ff06f          	j	21c0 <createdelete+0x174>
  for(i = 0; i < N; i++){
    2230:	001a8a9b          	addiw	s5,s5,1
    2234:	001a0a1b          	addiw	s4,s4,1
    2238:	0019091b          	addiw	s2,s2,1
    223c:	0ff97913          	zext.b	s2,s2
    2240:	01400793          	li	a5,20
    2244:	00fa8c63          	beq	s5,a5,225c <createdelete+0x210>
      if((i == 0 || i >= N/2) && fd < 0){
    2248:	001ab993          	seqz	s3,s5
    224c:	015d27b3          	slt	a5,s10,s5
    2250:	00f9e9b3          	or	s3,s3,a5
    2254:	000c8493          	mv	s1,s9
    2258:	f75ff06f          	j	21cc <createdelete+0x180>
    225c:	03000913          	li	s2,48
  name[0] = name[1] = name[2] = 0;
    2260:	07000b13          	li	s6,112
      unlink(name);
    2264:	f7040a13          	addi	s4,s0,-144
    for(pi = 0; pi < NCHILD; pi++){
    2268:	07400993          	li	s3,116
  for(i = 0; i < N; i++){
    226c:	04400a93          	li	s5,68
  name[0] = name[1] = name[2] = 0;
    2270:	000b0493          	mv	s1,s6
      name[0] = 'p' + pi;
    2274:	f6940823          	sb	s1,-144(s0)
      name[1] = '0' + i;
    2278:	f72408a3          	sb	s2,-143(s0)
      unlink(name);
    227c:	000a0513          	mv	a0,s4
    2280:	63c040ef          	jal	68bc <unlink>
    for(pi = 0; pi < NCHILD; pi++){
    2284:	0014849b          	addiw	s1,s1,1
    2288:	0ff4f493          	zext.b	s1,s1
    228c:	ff3494e3          	bne	s1,s3,2274 <createdelete+0x228>
  for(i = 0; i < N; i++){
    2290:	0019091b          	addiw	s2,s2,1
    2294:	0ff97913          	zext.b	s2,s2
    2298:	fd591ce3          	bne	s2,s5,2270 <createdelete+0x224>
}
    229c:	09813083          	ld	ra,152(sp)
    22a0:	09013403          	ld	s0,144(sp)
    22a4:	08813483          	ld	s1,136(sp)
    22a8:	08013903          	ld	s2,128(sp)
    22ac:	07813983          	ld	s3,120(sp)
    22b0:	07013a03          	ld	s4,112(sp)
    22b4:	06813a83          	ld	s5,104(sp)
    22b8:	06013b03          	ld	s6,96(sp)
    22bc:	05813b83          	ld	s7,88(sp)
    22c0:	05013c03          	ld	s8,80(sp)
    22c4:	04813c83          	ld	s9,72(sp)
    22c8:	04013d03          	ld	s10,64(sp)
    22cc:	03813d83          	ld	s11,56(sp)
    22d0:	0a010113          	addi	sp,sp,160
    22d4:	00008067          	ret

00000000000022d8 <linkunlink>:
{
    22d8:	fa010113          	addi	sp,sp,-96
    22dc:	04113c23          	sd	ra,88(sp)
    22e0:	04813823          	sd	s0,80(sp)
    22e4:	04913423          	sd	s1,72(sp)
    22e8:	05213023          	sd	s2,64(sp)
    22ec:	03313c23          	sd	s3,56(sp)
    22f0:	03413823          	sd	s4,48(sp)
    22f4:	03513423          	sd	s5,40(sp)
    22f8:	03613023          	sd	s6,32(sp)
    22fc:	01713c23          	sd	s7,24(sp)
    2300:	01813823          	sd	s8,16(sp)
    2304:	01913423          	sd	s9,8(sp)
    2308:	01a13023          	sd	s10,0(sp)
    230c:	06010413          	addi	s0,sp,96
    2310:	00050493          	mv	s1,a0
  unlink("x");
    2314:	00005517          	auipc	a0,0x5
    2318:	f3450513          	addi	a0,a0,-204 # 7248 <malloc+0x220>
    231c:	5a0040ef          	jal	68bc <unlink>
  pid = fork();
    2320:	518040ef          	jal	6838 <fork>
  if(pid < 0){
    2324:	04054a63          	bltz	a0,2378 <linkunlink+0xa0>
    2328:	00050d13          	mv	s10,a0
  unsigned int x = (pid ? 1 : 97);
    232c:	06100913          	li	s2,97
    2330:	00050463          	beqz	a0,2338 <linkunlink+0x60>
    2334:	00100913          	li	s2,1
    2338:	06400493          	li	s1,100
    x = x * 1103515245 + 12345;
    233c:	41c65ab7          	lui	s5,0x41c65
    2340:	e6da8a9b          	addiw	s5,s5,-403 # 41c64e6d <base+0x41c54135>
    2344:	00003a37          	lui	s4,0x3
    2348:	039a0a1b          	addiw	s4,s4,57 # 3039 <sbrkarg+0x35>
    if((x % 3) == 0){
    234c:	000ab9b7          	lui	s3,0xab
    2350:	aab98993          	addi	s3,s3,-1365 # aaaab <base+0x99d73>
    2354:	00c99993          	slli	s3,s3,0xc
    2358:	aab98993          	addi	s3,s3,-1365
    } else if((x % 3) == 1){
    235c:	00100b93          	li	s7,1
      unlink("x");
    2360:	00005b17          	auipc	s6,0x5
    2364:	ee8b0b13          	addi	s6,s6,-280 # 7248 <malloc+0x220>
      link("cat", "x");
    2368:	00006c97          	auipc	s9,0x6
    236c:	958c8c93          	addi	s9,s9,-1704 # 7cc0 <malloc+0xc98>
      close(open("x", O_RDWR | O_CREATE));
    2370:	20200c13          	li	s8,514
    2374:	0400006f          	j	23b4 <linkunlink+0xdc>
    printf("%s: fork failed\n", s);
    2378:	00048593          	mv	a1,s1
    237c:	00005517          	auipc	a0,0x5
    2380:	6ec50513          	addi	a0,a0,1772 # 7a68 <malloc+0xa40>
    2384:	399040ef          	jal	6f1c <printf>
    exit(1);
    2388:	00100513          	li	a0,1
    238c:	4b8040ef          	jal	6844 <exit>
      close(open("x", O_RDWR | O_CREATE));
    2390:	000c0593          	mv	a1,s8
    2394:	000b0513          	mv	a0,s6
    2398:	50c040ef          	jal	68a4 <open>
    239c:	4e4040ef          	jal	6880 <close>
    23a0:	00c0006f          	j	23ac <linkunlink+0xd4>
      unlink("x");
    23a4:	000b0513          	mv	a0,s6
    23a8:	514040ef          	jal	68bc <unlink>
  for(i = 0; i < 100; i++){
    23ac:	fff4849b          	addiw	s1,s1,-1
    23b0:	04048263          	beqz	s1,23f4 <linkunlink+0x11c>
    x = x * 1103515245 + 12345;
    23b4:	035907bb          	mulw	a5,s2,s5
    23b8:	00fa07bb          	addw	a5,s4,a5
    23bc:	00078913          	mv	s2,a5
    if((x % 3) == 0){
    23c0:	02079713          	slli	a4,a5,0x20
    23c4:	02075713          	srli	a4,a4,0x20
    23c8:	03370733          	mul	a4,a4,s3
    23cc:	02175713          	srli	a4,a4,0x21
    23d0:	0017169b          	slliw	a3,a4,0x1
    23d4:	00e6873b          	addw	a4,a3,a4
    23d8:	40e787bb          	subw	a5,a5,a4
    23dc:	fa078ae3          	beqz	a5,2390 <linkunlink+0xb8>
    } else if((x % 3) == 1){
    23e0:	fd7792e3          	bne	a5,s7,23a4 <linkunlink+0xcc>
      link("cat", "x");
    23e4:	000b0593          	mv	a1,s6
    23e8:	000c8513          	mv	a0,s9
    23ec:	4e8040ef          	jal	68d4 <link>
    23f0:	fbdff06f          	j	23ac <linkunlink+0xd4>
  if(pid)
    23f4:	040d0263          	beqz	s10,2438 <linkunlink+0x160>
    wait(0);
    23f8:	00000513          	li	a0,0
    23fc:	454040ef          	jal	6850 <wait>
}
    2400:	05813083          	ld	ra,88(sp)
    2404:	05013403          	ld	s0,80(sp)
    2408:	04813483          	ld	s1,72(sp)
    240c:	04013903          	ld	s2,64(sp)
    2410:	03813983          	ld	s3,56(sp)
    2414:	03013a03          	ld	s4,48(sp)
    2418:	02813a83          	ld	s5,40(sp)
    241c:	02013b03          	ld	s6,32(sp)
    2420:	01813b83          	ld	s7,24(sp)
    2424:	01013c03          	ld	s8,16(sp)
    2428:	00813c83          	ld	s9,8(sp)
    242c:	00013d03          	ld	s10,0(sp)
    2430:	06010113          	addi	sp,sp,96
    2434:	00008067          	ret
    exit(0);
    2438:	00000513          	li	a0,0
    243c:	408040ef          	jal	6844 <exit>

0000000000002440 <forktest>:
{
    2440:	fd010113          	addi	sp,sp,-48
    2444:	02113423          	sd	ra,40(sp)
    2448:	02813023          	sd	s0,32(sp)
    244c:	00913c23          	sd	s1,24(sp)
    2450:	01213823          	sd	s2,16(sp)
    2454:	01313423          	sd	s3,8(sp)
    2458:	03010413          	addi	s0,sp,48
    245c:	00050993          	mv	s3,a0
  for(n=0; n<N; n++){
    2460:	00000493          	li	s1,0
    2464:	3e800913          	li	s2,1000
    pid = fork();
    2468:	3d0040ef          	jal	6838 <fork>
    if(pid < 0)
    246c:	06054a63          	bltz	a0,24e0 <forktest+0xa0>
    if(pid == 0)
    2470:	02050263          	beqz	a0,2494 <forktest+0x54>
  for(n=0; n<N; n++){
    2474:	0014849b          	addiw	s1,s1,1
    2478:	ff2498e3          	bne	s1,s2,2468 <forktest+0x28>
    printf("%s: fork claimed to work 1000 times!\n", s);
    247c:	00098593          	mv	a1,s3
    2480:	00006517          	auipc	a0,0x6
    2484:	89050513          	addi	a0,a0,-1904 # 7d10 <malloc+0xce8>
    2488:	295040ef          	jal	6f1c <printf>
    exit(1);
    248c:	00100513          	li	a0,1
    2490:	3b4040ef          	jal	6844 <exit>
      exit(0);
    2494:	3b0040ef          	jal	6844 <exit>
    printf("%s: no fork at all!\n", s);
    2498:	00098593          	mv	a1,s3
    249c:	00006517          	auipc	a0,0x6
    24a0:	82c50513          	addi	a0,a0,-2004 # 7cc8 <malloc+0xca0>
    24a4:	279040ef          	jal	6f1c <printf>
    exit(1);
    24a8:	00100513          	li	a0,1
    24ac:	398040ef          	jal	6844 <exit>
      printf("%s: wait stopped early\n", s);
    24b0:	00098593          	mv	a1,s3
    24b4:	00006517          	auipc	a0,0x6
    24b8:	82c50513          	addi	a0,a0,-2004 # 7ce0 <malloc+0xcb8>
    24bc:	261040ef          	jal	6f1c <printf>
      exit(1);
    24c0:	00100513          	li	a0,1
    24c4:	380040ef          	jal	6844 <exit>
    printf("%s: wait got too many\n", s);
    24c8:	00098593          	mv	a1,s3
    24cc:	00006517          	auipc	a0,0x6
    24d0:	82c50513          	addi	a0,a0,-2004 # 7cf8 <malloc+0xcd0>
    24d4:	249040ef          	jal	6f1c <printf>
    exit(1);
    24d8:	00100513          	li	a0,1
    24dc:	368040ef          	jal	6844 <exit>
  if (n == 0) {
    24e0:	fa048ce3          	beqz	s1,2498 <forktest+0x58>
  for(; n > 0; n--){
    24e4:	00905c63          	blez	s1,24fc <forktest+0xbc>
    if(wait(0) < 0){
    24e8:	00000513          	li	a0,0
    24ec:	364040ef          	jal	6850 <wait>
    24f0:	fc0540e3          	bltz	a0,24b0 <forktest+0x70>
  for(; n > 0; n--){
    24f4:	fff4849b          	addiw	s1,s1,-1
    24f8:	fe0498e3          	bnez	s1,24e8 <forktest+0xa8>
  if(wait(0) != -1){
    24fc:	00000513          	li	a0,0
    2500:	350040ef          	jal	6850 <wait>
    2504:	fff00793          	li	a5,-1
    2508:	fcf510e3          	bne	a0,a5,24c8 <forktest+0x88>
}
    250c:	02813083          	ld	ra,40(sp)
    2510:	02013403          	ld	s0,32(sp)
    2514:	01813483          	ld	s1,24(sp)
    2518:	01013903          	ld	s2,16(sp)
    251c:	00813983          	ld	s3,8(sp)
    2520:	03010113          	addi	sp,sp,48
    2524:	00008067          	ret

0000000000002528 <kernmem>:
{
    2528:	fb010113          	addi	sp,sp,-80
    252c:	04113423          	sd	ra,72(sp)
    2530:	04813023          	sd	s0,64(sp)
    2534:	02913c23          	sd	s1,56(sp)
    2538:	03213823          	sd	s2,48(sp)
    253c:	03313423          	sd	s3,40(sp)
    2540:	03413023          	sd	s4,32(sp)
    2544:	01513c23          	sd	s5,24(sp)
    2548:	01613823          	sd	s6,16(sp)
    254c:	05010413          	addi	s0,sp,80
    2550:	00050b13          	mv	s6,a0
  for(a = (char*)(KERNBASE); a < (char*) (KERNBASE+2000000); a += 50000){
    2554:	00100493          	li	s1,1
    2558:	01f49493          	slli	s1,s1,0x1f
    wait(&xstatus);
    255c:	fbc40a93          	addi	s5,s0,-68
    if(xstatus != -1)  // did kernel kill child?
    2560:	fff00a13          	li	s4,-1
  for(a = (char*)(KERNBASE); a < (char*) (KERNBASE+2000000); a += 50000){
    2564:	0000c9b7          	lui	s3,0xc
    2568:	35098993          	addi	s3,s3,848 # c350 <uninit+0xda8>
    256c:	1003d937          	lui	s2,0x1003d
    2570:	00391913          	slli	s2,s2,0x3
    2574:	48090913          	addi	s2,s2,1152 # 1003d480 <base+0x1002c748>
    pid = fork();
    2578:	2c0040ef          	jal	6838 <fork>
    if(pid < 0){
    257c:	04054463          	bltz	a0,25c4 <kernmem+0x9c>
    if(pid == 0){
    2580:	04050e63          	beqz	a0,25dc <kernmem+0xb4>
    wait(&xstatus);
    2584:	000a8513          	mv	a0,s5
    2588:	2c8040ef          	jal	6850 <wait>
    if(xstatus != -1)  // did kernel kill child?
    258c:	fbc42783          	lw	a5,-68(s0)
    2590:	07479663          	bne	a5,s4,25fc <kernmem+0xd4>
  for(a = (char*)(KERNBASE); a < (char*) (KERNBASE+2000000); a += 50000){
    2594:	013484b3          	add	s1,s1,s3
    2598:	ff2490e3          	bne	s1,s2,2578 <kernmem+0x50>
}
    259c:	04813083          	ld	ra,72(sp)
    25a0:	04013403          	ld	s0,64(sp)
    25a4:	03813483          	ld	s1,56(sp)
    25a8:	03013903          	ld	s2,48(sp)
    25ac:	02813983          	ld	s3,40(sp)
    25b0:	02013a03          	ld	s4,32(sp)
    25b4:	01813a83          	ld	s5,24(sp)
    25b8:	01013b03          	ld	s6,16(sp)
    25bc:	05010113          	addi	sp,sp,80
    25c0:	00008067          	ret
      printf("%s: fork failed\n", s);
    25c4:	000b0593          	mv	a1,s6
    25c8:	00005517          	auipc	a0,0x5
    25cc:	4a050513          	addi	a0,a0,1184 # 7a68 <malloc+0xa40>
    25d0:	14d040ef          	jal	6f1c <printf>
      exit(1);
    25d4:	00100513          	li	a0,1
    25d8:	26c040ef          	jal	6844 <exit>
      printf("%s: oops could read %p = %x\n", s, a, *a);
    25dc:	0004c683          	lbu	a3,0(s1)
    25e0:	00048613          	mv	a2,s1
    25e4:	000b0593          	mv	a1,s6
    25e8:	00005517          	auipc	a0,0x5
    25ec:	75050513          	addi	a0,a0,1872 # 7d38 <malloc+0xd10>
    25f0:	12d040ef          	jal	6f1c <printf>
      exit(1);
    25f4:	00100513          	li	a0,1
    25f8:	24c040ef          	jal	6844 <exit>
      exit(1);
    25fc:	00100513          	li	a0,1
    2600:	244040ef          	jal	6844 <exit>

0000000000002604 <MAXVAplus>:
{
    2604:	fc010113          	addi	sp,sp,-64
    2608:	02113c23          	sd	ra,56(sp)
    260c:	02813823          	sd	s0,48(sp)
    2610:	04010413          	addi	s0,sp,64
  volatile uint64 a = MAXVA;
    2614:	00100793          	li	a5,1
    2618:	02679793          	slli	a5,a5,0x26
    261c:	fcf43423          	sd	a5,-56(s0)
  for( ; a != 0; a <<= 1){
    2620:	fc843783          	ld	a5,-56(s0)
    2624:	04078c63          	beqz	a5,267c <MAXVAplus+0x78>
    2628:	02913423          	sd	s1,40(sp)
    262c:	03213023          	sd	s2,32(sp)
    2630:	01313c23          	sd	s3,24(sp)
    2634:	00050993          	mv	s3,a0
    wait(&xstatus);
    2638:	fc440913          	addi	s2,s0,-60
    if(xstatus != -1)  // did kernel kill child?
    263c:	fff00493          	li	s1,-1
    pid = fork();
    2640:	1f8040ef          	jal	6838 <fork>
    if(pid < 0){
    2644:	04054463          	bltz	a0,268c <MAXVAplus+0x88>
    if(pid == 0){
    2648:	04050e63          	beqz	a0,26a4 <MAXVAplus+0xa0>
    wait(&xstatus);
    264c:	00090513          	mv	a0,s2
    2650:	200040ef          	jal	6850 <wait>
    if(xstatus != -1)  // did kernel kill child?
    2654:	fc442783          	lw	a5,-60(s0)
    2658:	06979a63          	bne	a5,s1,26cc <MAXVAplus+0xc8>
  for( ; a != 0; a <<= 1){
    265c:	fc843783          	ld	a5,-56(s0)
    2660:	00179793          	slli	a5,a5,0x1
    2664:	fcf43423          	sd	a5,-56(s0)
    2668:	fc843783          	ld	a5,-56(s0)
    266c:	fc079ae3          	bnez	a5,2640 <MAXVAplus+0x3c>
    2670:	02813483          	ld	s1,40(sp)
    2674:	02013903          	ld	s2,32(sp)
    2678:	01813983          	ld	s3,24(sp)
}
    267c:	03813083          	ld	ra,56(sp)
    2680:	03013403          	ld	s0,48(sp)
    2684:	04010113          	addi	sp,sp,64
    2688:	00008067          	ret
      printf("%s: fork failed\n", s);
    268c:	00098593          	mv	a1,s3
    2690:	00005517          	auipc	a0,0x5
    2694:	3d850513          	addi	a0,a0,984 # 7a68 <malloc+0xa40>
    2698:	085040ef          	jal	6f1c <printf>
      exit(1);
    269c:	00100513          	li	a0,1
    26a0:	1a4040ef          	jal	6844 <exit>
      *(char*)a = 99;
    26a4:	fc843783          	ld	a5,-56(s0)
    26a8:	06300713          	li	a4,99
    26ac:	00e78023          	sb	a4,0(a5)
      printf("%s: oops wrote %p\n", s, (void*)a);
    26b0:	fc843603          	ld	a2,-56(s0)
    26b4:	00098593          	mv	a1,s3
    26b8:	00005517          	auipc	a0,0x5
    26bc:	6a050513          	addi	a0,a0,1696 # 7d58 <malloc+0xd30>
    26c0:	05d040ef          	jal	6f1c <printf>
      exit(1);
    26c4:	00100513          	li	a0,1
    26c8:	17c040ef          	jal	6844 <exit>
      exit(1);
    26cc:	00100513          	li	a0,1
    26d0:	174040ef          	jal	6844 <exit>

00000000000026d4 <stacktest>:
{
    26d4:	fd010113          	addi	sp,sp,-48
    26d8:	02113423          	sd	ra,40(sp)
    26dc:	02813023          	sd	s0,32(sp)
    26e0:	00913c23          	sd	s1,24(sp)
    26e4:	03010413          	addi	s0,sp,48
    26e8:	00050493          	mv	s1,a0
  pid = fork();
    26ec:	14c040ef          	jal	6838 <fork>
  if(pid == 0) {
    26f0:	02050063          	beqz	a0,2710 <stacktest+0x3c>
  } else if(pid < 0){
    26f4:	04054063          	bltz	a0,2734 <stacktest+0x60>
  wait(&xstatus);
    26f8:	fdc40513          	addi	a0,s0,-36
    26fc:	154040ef          	jal	6850 <wait>
  if(xstatus == -1)  // kernel killed child?
    2700:	fdc42503          	lw	a0,-36(s0)
    2704:	fff00793          	li	a5,-1
    2708:	04f50263          	beq	a0,a5,274c <stacktest+0x78>
    exit(xstatus);
    270c:	138040ef          	jal	6844 <exit>

static inline uint64
r_sp()
{
  uint64 x;
  asm volatile("mv %0, sp" : "=r"(x));
    2710:	00010793          	mv	a5,sp
    printf("%s: stacktest: read below stack %d\n", s, *sp);
    2714:	80078793          	addi	a5,a5,-2048
    2718:	8007c603          	lbu	a2,-2048(a5)
    271c:	00048593          	mv	a1,s1
    2720:	00005517          	auipc	a0,0x5
    2724:	65050513          	addi	a0,a0,1616 # 7d70 <malloc+0xd48>
    2728:	7f4040ef          	jal	6f1c <printf>
    exit(1);
    272c:	00100513          	li	a0,1
    2730:	114040ef          	jal	6844 <exit>
    printf("%s: fork failed\n", s);
    2734:	00048593          	mv	a1,s1
    2738:	00005517          	auipc	a0,0x5
    273c:	33050513          	addi	a0,a0,816 # 7a68 <malloc+0xa40>
    2740:	7dc040ef          	jal	6f1c <printf>
    exit(1);
    2744:	00100513          	li	a0,1
    2748:	0fc040ef          	jal	6844 <exit>
    exit(0);
    274c:	00000513          	li	a0,0
    2750:	0f4040ef          	jal	6844 <exit>

0000000000002754 <nowrite>:
{
    2754:	f9010113          	addi	sp,sp,-112
    2758:	06113423          	sd	ra,104(sp)
    275c:	06813023          	sd	s0,96(sp)
    2760:	04913c23          	sd	s1,88(sp)
    2764:	05213823          	sd	s2,80(sp)
    2768:	05313423          	sd	s3,72(sp)
    276c:	05413023          	sd	s4,64(sp)
    2770:	07010413          	addi	s0,sp,112
    2774:	00050a13          	mv	s4,a0
  uint64 addrs[] = { 0, 0x80000000LL, 0x3fffffe000, 0x3ffffff000, 0x4000000000,
    2778:	00007797          	auipc	a5,0x7
    277c:	fa878793          	addi	a5,a5,-88 # 9720 <malloc+0x26f8>
    2780:	0287b503          	ld	a0,40(a5)
    2784:	0307b583          	ld	a1,48(a5)
    2788:	0387b603          	ld	a2,56(a5)
    278c:	0407b683          	ld	a3,64(a5)
    2790:	0487b703          	ld	a4,72(a5)
    2794:	f8a43c23          	sd	a0,-104(s0)
    2798:	fab43023          	sd	a1,-96(s0)
    279c:	fac43423          	sd	a2,-88(s0)
    27a0:	fad43823          	sd	a3,-80(s0)
    27a4:	fae43c23          	sd	a4,-72(s0)
    27a8:	0507b783          	ld	a5,80(a5)
    27ac:	fcf43023          	sd	a5,-64(s0)
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
    27b0:	00000493          	li	s1,0
    wait(&xstatus);
    27b4:	fcc40913          	addi	s2,s0,-52
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
    27b8:	00600993          	li	s3,6
    pid = fork();
    27bc:	07c040ef          	jal	6838 <fork>
    if(pid == 0) {
    27c0:	02050463          	beqz	a0,27e8 <nowrite+0x94>
    } else if(pid < 0){
    27c4:	04054a63          	bltz	a0,2818 <nowrite+0xc4>
    wait(&xstatus);
    27c8:	00090513          	mv	a0,s2
    27cc:	084040ef          	jal	6850 <wait>
    if(xstatus == 0){
    27d0:	fcc42783          	lw	a5,-52(s0)
    27d4:	04078e63          	beqz	a5,2830 <nowrite+0xdc>
  for(int ai = 0; ai < sizeof(addrs)/sizeof(addrs[0]); ai++){
    27d8:	0014849b          	addiw	s1,s1,1
    27dc:	ff3490e3          	bne	s1,s3,27bc <nowrite+0x68>
  exit(0);
    27e0:	00000513          	li	a0,0
    27e4:	060040ef          	jal	6844 <exit>
      volatile int *addr = (int *) addrs[ai];
    27e8:	00349493          	slli	s1,s1,0x3
    27ec:	fd048793          	addi	a5,s1,-48
    27f0:	008784b3          	add	s1,a5,s0
    27f4:	fc84b603          	ld	a2,-56(s1)
      *addr = 10;
    27f8:	00a00793          	li	a5,10
    27fc:	00f62023          	sw	a5,0(a2) # 3000 <sbrkmuch+0x1ac>
      printf("%s: write to %p did not fail!\n", s, addr);
    2800:	000a0593          	mv	a1,s4
    2804:	00005517          	auipc	a0,0x5
    2808:	59450513          	addi	a0,a0,1428 # 7d98 <malloc+0xd70>
    280c:	710040ef          	jal	6f1c <printf>
      exit(0);
    2810:	00000513          	li	a0,0
    2814:	030040ef          	jal	6844 <exit>
      printf("%s: fork failed\n", s);
    2818:	000a0593          	mv	a1,s4
    281c:	00005517          	auipc	a0,0x5
    2820:	24c50513          	addi	a0,a0,588 # 7a68 <malloc+0xa40>
    2824:	6f8040ef          	jal	6f1c <printf>
      exit(1);
    2828:	00100513          	li	a0,1
    282c:	018040ef          	jal	6844 <exit>
      exit(1);
    2830:	00100513          	li	a0,1
    2834:	010040ef          	jal	6844 <exit>

0000000000002838 <manywrites>:
{
    2838:	f9010113          	addi	sp,sp,-112
    283c:	06113423          	sd	ra,104(sp)
    2840:	06813023          	sd	s0,96(sp)
    2844:	04913c23          	sd	s1,88(sp)
    2848:	05213823          	sd	s2,80(sp)
    284c:	05313423          	sd	s3,72(sp)
    2850:	01913c23          	sd	s9,24(sp)
    2854:	07010413          	addi	s0,sp,112
    2858:	00050c93          	mv	s9,a0
  for(int ci = 0; ci < nchildren; ci++){
    285c:	00000913          	li	s2,0
    2860:	00400993          	li	s3,4
    int pid = fork();
    2864:	7d5030ef          	jal	6838 <fork>
    2868:	00050493          	mv	s1,a0
    if(pid < 0){
    286c:	04054863          	bltz	a0,28bc <manywrites+0x84>
    if(pid == 0){
    2870:	06050c63          	beqz	a0,28e8 <manywrites+0xb0>
  for(int ci = 0; ci < nchildren; ci++){
    2874:	0019091b          	addiw	s2,s2,1
    2878:	ff3916e3          	bne	s2,s3,2864 <manywrites+0x2c>
    287c:	00400493          	li	s1,4
    wait(&st);
    2880:	f9840913          	addi	s2,s0,-104
    int st = 0;
    2884:	f8042c23          	sw	zero,-104(s0)
    wait(&st);
    2888:	00090513          	mv	a0,s2
    288c:	7c5030ef          	jal	6850 <wait>
    if(st != 0)
    2890:	f9842503          	lw	a0,-104(s0)
    2894:	14051063          	bnez	a0,29d4 <manywrites+0x19c>
  for(int ci = 0; ci < nchildren; ci++){
    2898:	fff4849b          	addiw	s1,s1,-1
    289c:	fe0494e3          	bnez	s1,2884 <manywrites+0x4c>
    28a0:	05413023          	sd	s4,64(sp)
    28a4:	03513c23          	sd	s5,56(sp)
    28a8:	03613823          	sd	s6,48(sp)
    28ac:	03713423          	sd	s7,40(sp)
    28b0:	03813023          	sd	s8,32(sp)
    28b4:	01a13823          	sd	s10,16(sp)
  exit(0);
    28b8:	78d030ef          	jal	6844 <exit>
    28bc:	05413023          	sd	s4,64(sp)
    28c0:	03513c23          	sd	s5,56(sp)
    28c4:	03613823          	sd	s6,48(sp)
    28c8:	03713423          	sd	s7,40(sp)
    28cc:	03813023          	sd	s8,32(sp)
    28d0:	01a13823          	sd	s10,16(sp)
      printf("fork failed\n");
    28d4:	00006517          	auipc	a0,0x6
    28d8:	73c50513          	addi	a0,a0,1852 # 9010 <malloc+0x1fe8>
    28dc:	640040ef          	jal	6f1c <printf>
      exit(1);
    28e0:	00100513          	li	a0,1
    28e4:	761030ef          	jal	6844 <exit>
    28e8:	05413023          	sd	s4,64(sp)
    28ec:	03513c23          	sd	s5,56(sp)
    28f0:	03613823          	sd	s6,48(sp)
    28f4:	03713423          	sd	s7,40(sp)
    28f8:	03813023          	sd	s8,32(sp)
    28fc:	01a13823          	sd	s10,16(sp)
      name[0] = 'b';
    2900:	06200793          	li	a5,98
    2904:	f8f40c23          	sb	a5,-104(s0)
      name[1] = 'a' + ci;
    2908:	0619079b          	addiw	a5,s2,97
    290c:	f8f40ca3          	sb	a5,-103(s0)
      name[2] = '\0';
    2910:	f8040d23          	sb	zero,-102(s0)
      unlink(name);
    2914:	f9840513          	addi	a0,s0,-104
    2918:	7a5030ef          	jal	68bc <unlink>
    291c:	01e00793          	li	a5,30
    2920:	00078d13          	mv	s10,a5
          int fd = open(name, O_CREATE | O_RDWR);
    2924:	f9840b93          	addi	s7,s0,-104
    2928:	20200b13          	li	s6,514
          int cc = write(fd, buf, sz);
    292c:	00003ab7          	lui	s5,0x3
    2930:	0000bc17          	auipc	s8,0xb
    2934:	388c0c13          	addi	s8,s8,904 # dcb8 <buf>
        for(int i = 0; i < ci+1; i++){
    2938:	00048a13          	mv	s4,s1
    293c:	02094c63          	bltz	s2,2974 <manywrites+0x13c>
          int fd = open(name, O_CREATE | O_RDWR);
    2940:	000b0593          	mv	a1,s6
    2944:	000b8513          	mv	a0,s7
    2948:	75d030ef          	jal	68a4 <open>
    294c:	00050993          	mv	s3,a0
          if(fd < 0){
    2950:	04054463          	bltz	a0,2998 <manywrites+0x160>
          int cc = write(fd, buf, sz);
    2954:	000a8613          	mv	a2,s5
    2958:	000c0593          	mv	a1,s8
    295c:	719030ef          	jal	6874 <write>
          if(cc != sz){
    2960:	05551a63          	bne	a0,s5,29b4 <manywrites+0x17c>
          close(fd);
    2964:	00098513          	mv	a0,s3
    2968:	719030ef          	jal	6880 <close>
        for(int i = 0; i < ci+1; i++){
    296c:	001a0a1b          	addiw	s4,s4,1
    2970:	fd4958e3          	bge	s2,s4,2940 <manywrites+0x108>
        unlink(name);
    2974:	f9840513          	addi	a0,s0,-104
    2978:	745030ef          	jal	68bc <unlink>
      for(int iters = 0; iters < howmany; iters++){
    297c:	fffd079b          	addiw	a5,s10,-1
    2980:	00078d13          	mv	s10,a5
    2984:	fa079ae3          	bnez	a5,2938 <manywrites+0x100>
      unlink(name);
    2988:	f9840513          	addi	a0,s0,-104
    298c:	731030ef          	jal	68bc <unlink>
      exit(0);
    2990:	00000513          	li	a0,0
    2994:	6b1030ef          	jal	6844 <exit>
            printf("%s: cannot create %s\n", s, name);
    2998:	f9840613          	addi	a2,s0,-104
    299c:	000c8593          	mv	a1,s9
    29a0:	00005517          	auipc	a0,0x5
    29a4:	41850513          	addi	a0,a0,1048 # 7db8 <malloc+0xd90>
    29a8:	574040ef          	jal	6f1c <printf>
            exit(1);
    29ac:	00100513          	li	a0,1
    29b0:	695030ef          	jal	6844 <exit>
            printf("%s: write(%d) ret %d\n", s, sz, cc);
    29b4:	00050693          	mv	a3,a0
    29b8:	00003637          	lui	a2,0x3
    29bc:	000c8593          	mv	a1,s9
    29c0:	00005517          	auipc	a0,0x5
    29c4:	8e850513          	addi	a0,a0,-1816 # 72a8 <malloc+0x280>
    29c8:	554040ef          	jal	6f1c <printf>
            exit(1);
    29cc:	00100513          	li	a0,1
    29d0:	675030ef          	jal	6844 <exit>
    29d4:	05413023          	sd	s4,64(sp)
    29d8:	03513c23          	sd	s5,56(sp)
    29dc:	03613823          	sd	s6,48(sp)
    29e0:	03713423          	sd	s7,40(sp)
    29e4:	03813023          	sd	s8,32(sp)
    29e8:	01a13823          	sd	s10,16(sp)
      exit(st);
    29ec:	659030ef          	jal	6844 <exit>

00000000000029f0 <copyinstr3>:
{
    29f0:	fd010113          	addi	sp,sp,-48
    29f4:	02113423          	sd	ra,40(sp)
    29f8:	02813023          	sd	s0,32(sp)
    29fc:	00913c23          	sd	s1,24(sp)
    2a00:	03010413          	addi	s0,sp,48
  sbrk(8192);
    2a04:	00002537          	lui	a0,0x2
    2a08:	5e1030ef          	jal	67e8 <sbrk>
  uint64 top = (uint64) sbrk(0);
    2a0c:	00000513          	li	a0,0
    2a10:	5d9030ef          	jal	67e8 <sbrk>
  if((top % PGSIZE) != 0){
    2a14:	03451793          	slli	a5,a0,0x34
    2a18:	08079863          	bnez	a5,2aa8 <copyinstr3+0xb8>
  top = (uint64) sbrk(0);
    2a1c:	00000513          	li	a0,0
    2a20:	5c9030ef          	jal	67e8 <sbrk>
  if(top % PGSIZE){
    2a24:	03451793          	slli	a5,a0,0x34
    2a28:	08079a63          	bnez	a5,2abc <copyinstr3+0xcc>
  char *b = (char *) (top - 1);
    2a2c:	fff50493          	addi	s1,a0,-1 # 1fff <reparent2+0x13>
  *b = 'x';
    2a30:	07800793          	li	a5,120
    2a34:	fef50fa3          	sb	a5,-1(a0)
  int ret = unlink(b);
    2a38:	00048513          	mv	a0,s1
    2a3c:	681030ef          	jal	68bc <unlink>
  if(ret != -1){
    2a40:	fff00793          	li	a5,-1
    2a44:	08f51663          	bne	a0,a5,2ad0 <copyinstr3+0xe0>
  int fd = open(b, O_CREATE | O_WRONLY);
    2a48:	20100593          	li	a1,513
    2a4c:	00048513          	mv	a0,s1
    2a50:	655030ef          	jal	68a4 <open>
  if(fd != -1){
    2a54:	fff00793          	li	a5,-1
    2a58:	08f51a63          	bne	a0,a5,2aec <copyinstr3+0xfc>
  ret = link(b, b);
    2a5c:	00048593          	mv	a1,s1
    2a60:	00048513          	mv	a0,s1
    2a64:	671030ef          	jal	68d4 <link>
  if(ret != -1){
    2a68:	fff00793          	li	a5,-1
    2a6c:	08f51e63          	bne	a0,a5,2b08 <copyinstr3+0x118>
  char *args[] = { "xx", 0 };
    2a70:	00006797          	auipc	a5,0x6
    2a74:	04878793          	addi	a5,a5,72 # 8ab8 <malloc+0x1a90>
    2a78:	fcf43823          	sd	a5,-48(s0)
    2a7c:	fc043c23          	sd	zero,-40(s0)
  ret = exec(b, args);
    2a80:	fd040593          	addi	a1,s0,-48
    2a84:	00048513          	mv	a0,s1
    2a88:	611030ef          	jal	6898 <exec>
  if(ret != -1){
    2a8c:	fff00793          	li	a5,-1
    2a90:	08f51c63          	bne	a0,a5,2b28 <copyinstr3+0x138>
}
    2a94:	02813083          	ld	ra,40(sp)
    2a98:	02013403          	ld	s0,32(sp)
    2a9c:	01813483          	ld	s1,24(sp)
    2aa0:	03010113          	addi	sp,sp,48
    2aa4:	00008067          	ret
    sbrk(PGSIZE - (top % PGSIZE));
    2aa8:	0347d513          	srli	a0,a5,0x34
    2aac:	000017b7          	lui	a5,0x1
    2ab0:	40a7853b          	subw	a0,a5,a0
    2ab4:	535030ef          	jal	67e8 <sbrk>
    2ab8:	f65ff06f          	j	2a1c <copyinstr3+0x2c>
    printf("oops\n");
    2abc:	00005517          	auipc	a0,0x5
    2ac0:	31450513          	addi	a0,a0,788 # 7dd0 <malloc+0xda8>
    2ac4:	458040ef          	jal	6f1c <printf>
    exit(1);
    2ac8:	00100513          	li	a0,1
    2acc:	579030ef          	jal	6844 <exit>
    printf("unlink(%s) returned %d, not -1\n", b, ret);
    2ad0:	00050613          	mv	a2,a0
    2ad4:	00048593          	mv	a1,s1
    2ad8:	00005517          	auipc	a0,0x5
    2adc:	eb050513          	addi	a0,a0,-336 # 7988 <malloc+0x960>
    2ae0:	43c040ef          	jal	6f1c <printf>
    exit(1);
    2ae4:	00100513          	li	a0,1
    2ae8:	55d030ef          	jal	6844 <exit>
    printf("open(%s) returned %d, not -1\n", b, fd);
    2aec:	00050613          	mv	a2,a0
    2af0:	00048593          	mv	a1,s1
    2af4:	00005517          	auipc	a0,0x5
    2af8:	eb450513          	addi	a0,a0,-332 # 79a8 <malloc+0x980>
    2afc:	420040ef          	jal	6f1c <printf>
    exit(1);
    2b00:	00100513          	li	a0,1
    2b04:	541030ef          	jal	6844 <exit>
    printf("link(%s, %s) returned %d, not -1\n", b, b, ret);
    2b08:	00050693          	mv	a3,a0
    2b0c:	00048613          	mv	a2,s1
    2b10:	00048593          	mv	a1,s1
    2b14:	00005517          	auipc	a0,0x5
    2b18:	eb450513          	addi	a0,a0,-332 # 79c8 <malloc+0x9a0>
    2b1c:	400040ef          	jal	6f1c <printf>
    exit(1);
    2b20:	00100513          	li	a0,1
    2b24:	521030ef          	jal	6844 <exit>
    printf("exec(%s) returned %d, not -1\n", b, fd);
    2b28:	00078613          	mv	a2,a5
    2b2c:	00048593          	mv	a1,s1
    2b30:	00005517          	auipc	a0,0x5
    2b34:	ec050513          	addi	a0,a0,-320 # 79f0 <malloc+0x9c8>
    2b38:	3e4040ef          	jal	6f1c <printf>
    exit(1);
    2b3c:	00100513          	li	a0,1
    2b40:	505030ef          	jal	6844 <exit>

0000000000002b44 <rwsbrk>:
{
    2b44:	fe010113          	addi	sp,sp,-32
    2b48:	00113c23          	sd	ra,24(sp)
    2b4c:	00813823          	sd	s0,16(sp)
    2b50:	02010413          	addi	s0,sp,32
  uint64 a = (uint64) sbrk(8192);
    2b54:	00002537          	lui	a0,0x2
    2b58:	491030ef          	jal	67e8 <sbrk>
  if(a == (uint64) SBRK_ERROR) {
    2b5c:	fff00793          	li	a5,-1
    2b60:	06f50663          	beq	a0,a5,2bcc <rwsbrk+0x88>
    2b64:	00913423          	sd	s1,8(sp)
    2b68:	00050493          	mv	s1,a0
  if (sbrk(-8192) == SBRK_ERROR) {
    2b6c:	ffffe537          	lui	a0,0xffffe
    2b70:	479030ef          	jal	67e8 <sbrk>
    2b74:	fff00793          	li	a5,-1
    2b78:	06f50863          	beq	a0,a5,2be8 <rwsbrk+0xa4>
    2b7c:	01213023          	sd	s2,0(sp)
  fd = open("rwsbrk", O_CREATE|O_WRONLY);
    2b80:	20100593          	li	a1,513
    2b84:	00005517          	auipc	a0,0x5
    2b88:	28c50513          	addi	a0,a0,652 # 7e10 <malloc+0xde8>
    2b8c:	519030ef          	jal	68a4 <open>
    2b90:	00050913          	mv	s2,a0
  if(fd < 0){
    2b94:	06054663          	bltz	a0,2c00 <rwsbrk+0xbc>
  n = write(fd, (void*)(a+PGSIZE), 1024);
    2b98:	000017b7          	lui	a5,0x1
    2b9c:	00f484b3          	add	s1,s1,a5
    2ba0:	40000613          	li	a2,1024
    2ba4:	00048593          	mv	a1,s1
    2ba8:	4cd030ef          	jal	6874 <write>
    2bac:	00050613          	mv	a2,a0
  if(n >= 0){
    2bb0:	06054263          	bltz	a0,2c14 <rwsbrk+0xd0>
    printf("write(fd, %p, 1024) returned %d, not -1\n", (void*)a+PGSIZE, n);
    2bb4:	00048593          	mv	a1,s1
    2bb8:	00005517          	auipc	a0,0x5
    2bbc:	27850513          	addi	a0,a0,632 # 7e30 <malloc+0xe08>
    2bc0:	35c040ef          	jal	6f1c <printf>
    exit(1);
    2bc4:	00100513          	li	a0,1
    2bc8:	47d030ef          	jal	6844 <exit>
    2bcc:	00913423          	sd	s1,8(sp)
    2bd0:	01213023          	sd	s2,0(sp)
    printf("sbrk(rwsbrk) failed\n");
    2bd4:	00005517          	auipc	a0,0x5
    2bd8:	20450513          	addi	a0,a0,516 # 7dd8 <malloc+0xdb0>
    2bdc:	340040ef          	jal	6f1c <printf>
    exit(1);
    2be0:	00100513          	li	a0,1
    2be4:	461030ef          	jal	6844 <exit>
    2be8:	01213023          	sd	s2,0(sp)
    printf("sbrk(rwsbrk) shrink failed\n");
    2bec:	00005517          	auipc	a0,0x5
    2bf0:	20450513          	addi	a0,a0,516 # 7df0 <malloc+0xdc8>
    2bf4:	328040ef          	jal	6f1c <printf>
    exit(1);
    2bf8:	00100513          	li	a0,1
    2bfc:	449030ef          	jal	6844 <exit>
    printf("open(rwsbrk) failed\n");
    2c00:	00005517          	auipc	a0,0x5
    2c04:	21850513          	addi	a0,a0,536 # 7e18 <malloc+0xdf0>
    2c08:	314040ef          	jal	6f1c <printf>
    exit(1);
    2c0c:	00100513          	li	a0,1
    2c10:	435030ef          	jal	6844 <exit>
  close(fd);
    2c14:	00090513          	mv	a0,s2
    2c18:	469030ef          	jal	6880 <close>
  unlink("rwsbrk");
    2c1c:	00005517          	auipc	a0,0x5
    2c20:	1f450513          	addi	a0,a0,500 # 7e10 <malloc+0xde8>
    2c24:	499030ef          	jal	68bc <unlink>
  fd = open("README", O_RDONLY);
    2c28:	00000593          	li	a1,0
    2c2c:	00004517          	auipc	a0,0x4
    2c30:	78450513          	addi	a0,a0,1924 # 73b0 <malloc+0x388>
    2c34:	471030ef          	jal	68a4 <open>
    2c38:	00050913          	mv	s2,a0
  if(fd < 0){
    2c3c:	02054863          	bltz	a0,2c6c <rwsbrk+0x128>
  n = read(fd, (void*)(a+PGSIZE), 10);
    2c40:	00a00613          	li	a2,10
    2c44:	00048593          	mv	a1,s1
    2c48:	421030ef          	jal	6868 <read>
    2c4c:	00050613          	mv	a2,a0
  if(n >= 0){
    2c50:	02054863          	bltz	a0,2c80 <rwsbrk+0x13c>
    printf("read(fd, %p, 10) returned %d, not -1\n", (void*)a+PGSIZE, n);
    2c54:	00048593          	mv	a1,s1
    2c58:	00005517          	auipc	a0,0x5
    2c5c:	20850513          	addi	a0,a0,520 # 7e60 <malloc+0xe38>
    2c60:	2bc040ef          	jal	6f1c <printf>
    exit(1);
    2c64:	00100513          	li	a0,1
    2c68:	3dd030ef          	jal	6844 <exit>
    printf("open(README) failed\n");
    2c6c:	00004517          	auipc	a0,0x4
    2c70:	74c50513          	addi	a0,a0,1868 # 73b8 <malloc+0x390>
    2c74:	2a8040ef          	jal	6f1c <printf>
    exit(1);
    2c78:	00100513          	li	a0,1
    2c7c:	3c9030ef          	jal	6844 <exit>
  close(fd);
    2c80:	00090513          	mv	a0,s2
    2c84:	3fd030ef          	jal	6880 <close>
  exit(0);
    2c88:	00000513          	li	a0,0
    2c8c:	3b9030ef          	jal	6844 <exit>

0000000000002c90 <sbrkbasic>:
{
    2c90:	fb010113          	addi	sp,sp,-80
    2c94:	04113423          	sd	ra,72(sp)
    2c98:	04813023          	sd	s0,64(sp)
    2c9c:	01513c23          	sd	s5,24(sp)
    2ca0:	05010413          	addi	s0,sp,80
    2ca4:	00050a93          	mv	s5,a0
  pid = fork();
    2ca8:	391030ef          	jal	6838 <fork>
  if(pid < 0){
    2cac:	04054663          	bltz	a0,2cf8 <sbrkbasic+0x68>
  if(pid == 0){
    2cb0:	08051263          	bnez	a0,2d34 <sbrkbasic+0xa4>
    a = sbrk(TOOMUCH);
    2cb4:	40000537          	lui	a0,0x40000
    2cb8:	331030ef          	jal	67e8 <sbrk>
    if(a == (char*)SBRK_ERROR){
    2cbc:	fff00793          	li	a5,-1
    2cc0:	04f50e63          	beq	a0,a5,2d1c <sbrkbasic+0x8c>
    2cc4:	02913c23          	sd	s1,56(sp)
    2cc8:	03213823          	sd	s2,48(sp)
    2ccc:	03313423          	sd	s3,40(sp)
    2cd0:	03413023          	sd	s4,32(sp)
    for(b = a; b < a+TOOMUCH; b += PGSIZE){
    2cd4:	400007b7          	lui	a5,0x40000
    2cd8:	00f507b3          	add	a5,a0,a5
      *b = 99;
    2cdc:	06300693          	li	a3,99
    for(b = a; b < a+TOOMUCH; b += PGSIZE){
    2ce0:	00001737          	lui	a4,0x1
      *b = 99;
    2ce4:	00d50023          	sb	a3,0(a0) # 40000000 <base+0x3ffef2c8>
    for(b = a; b < a+TOOMUCH; b += PGSIZE){
    2ce8:	00e50533          	add	a0,a0,a4
    2cec:	fef51ce3          	bne	a0,a5,2ce4 <sbrkbasic+0x54>
    exit(1);
    2cf0:	00100513          	li	a0,1
    2cf4:	351030ef          	jal	6844 <exit>
    2cf8:	02913c23          	sd	s1,56(sp)
    2cfc:	03213823          	sd	s2,48(sp)
    2d00:	03313423          	sd	s3,40(sp)
    2d04:	03413023          	sd	s4,32(sp)
    printf("fork failed in sbrkbasic\n");
    2d08:	00005517          	auipc	a0,0x5
    2d0c:	18050513          	addi	a0,a0,384 # 7e88 <malloc+0xe60>
    2d10:	20c040ef          	jal	6f1c <printf>
    exit(1);
    2d14:	00100513          	li	a0,1
    2d18:	32d030ef          	jal	6844 <exit>
    2d1c:	02913c23          	sd	s1,56(sp)
    2d20:	03213823          	sd	s2,48(sp)
    2d24:	03313423          	sd	s3,40(sp)
    2d28:	03413023          	sd	s4,32(sp)
      exit(0);
    2d2c:	00000513          	li	a0,0
    2d30:	315030ef          	jal	6844 <exit>
  wait(&xstatus);
    2d34:	fbc40513          	addi	a0,s0,-68
    2d38:	319030ef          	jal	6850 <wait>
  if(xstatus == 1){
    2d3c:	fbc42703          	lw	a4,-68(s0)
    2d40:	00100793          	li	a5,1
    2d44:	02f70a63          	beq	a4,a5,2d78 <sbrkbasic+0xe8>
    2d48:	02913c23          	sd	s1,56(sp)
    2d4c:	03213823          	sd	s2,48(sp)
    2d50:	03313423          	sd	s3,40(sp)
    2d54:	03413023          	sd	s4,32(sp)
  a = sbrk(0);
    2d58:	00000513          	li	a0,0
    2d5c:	28d030ef          	jal	67e8 <sbrk>
    2d60:	00050493          	mv	s1,a0
  for(i = 0; i < 5000; i++){
    2d64:	00000913          	li	s2,0
    b = sbrk(1);
    2d68:	00100993          	li	s3,1
  for(i = 0; i < 5000; i++){
    2d6c:	00001a37          	lui	s4,0x1
    2d70:	388a0a13          	addi	s4,s4,904 # 1388 <validatetest+0x88>
    2d74:	0300006f          	j	2da4 <sbrkbasic+0x114>
    2d78:	02913c23          	sd	s1,56(sp)
    2d7c:	03213823          	sd	s2,48(sp)
    2d80:	03313423          	sd	s3,40(sp)
    2d84:	03413023          	sd	s4,32(sp)
    printf("%s: too much memory allocated!\n", s);
    2d88:	000a8593          	mv	a1,s5
    2d8c:	00005517          	auipc	a0,0x5
    2d90:	11c50513          	addi	a0,a0,284 # 7ea8 <malloc+0xe80>
    2d94:	188040ef          	jal	6f1c <printf>
    exit(1);
    2d98:	00100513          	li	a0,1
    2d9c:	2a9030ef          	jal	6844 <exit>
    2da0:	00078493          	mv	s1,a5
    b = sbrk(1);
    2da4:	00098513          	mv	a0,s3
    2da8:	241030ef          	jal	67e8 <sbrk>
    if(b != a){
    2dac:	04951863          	bne	a0,s1,2dfc <sbrkbasic+0x16c>
    *b = 1;
    2db0:	01348023          	sb	s3,0(s1)
    a = b + 1;
    2db4:	00148793          	addi	a5,s1,1
  for(i = 0; i < 5000; i++){
    2db8:	0019091b          	addiw	s2,s2,1
    2dbc:	ff4912e3          	bne	s2,s4,2da0 <sbrkbasic+0x110>
  pid = fork();
    2dc0:	279030ef          	jal	6838 <fork>
    2dc4:	00050913          	mv	s2,a0
  if(pid < 0){
    2dc8:	04054c63          	bltz	a0,2e20 <sbrkbasic+0x190>
  c = sbrk(1);
    2dcc:	00100513          	li	a0,1
    2dd0:	219030ef          	jal	67e8 <sbrk>
  c = sbrk(1);
    2dd4:	00100513          	li	a0,1
    2dd8:	211030ef          	jal	67e8 <sbrk>
  if(c != a + 1){
    2ddc:	00248493          	addi	s1,s1,2
    2de0:	04950c63          	beq	a0,s1,2e38 <sbrkbasic+0x1a8>
    printf("%s: sbrk test failed post-fork\n", s);
    2de4:	000a8593          	mv	a1,s5
    2de8:	00005517          	auipc	a0,0x5
    2dec:	12050513          	addi	a0,a0,288 # 7f08 <malloc+0xee0>
    2df0:	12c040ef          	jal	6f1c <printf>
    exit(1);
    2df4:	00100513          	li	a0,1
    2df8:	24d030ef          	jal	6844 <exit>
      printf("%s: sbrk test failed %d %p %p\n", s, i, a, b);
    2dfc:	00050713          	mv	a4,a0
    2e00:	00048693          	mv	a3,s1
    2e04:	00090613          	mv	a2,s2
    2e08:	000a8593          	mv	a1,s5
    2e0c:	00005517          	auipc	a0,0x5
    2e10:	0bc50513          	addi	a0,a0,188 # 7ec8 <malloc+0xea0>
    2e14:	108040ef          	jal	6f1c <printf>
      exit(1);
    2e18:	00100513          	li	a0,1
    2e1c:	229030ef          	jal	6844 <exit>
    printf("%s: sbrk test fork failed\n", s);
    2e20:	000a8593          	mv	a1,s5
    2e24:	00005517          	auipc	a0,0x5
    2e28:	0c450513          	addi	a0,a0,196 # 7ee8 <malloc+0xec0>
    2e2c:	0f0040ef          	jal	6f1c <printf>
    exit(1);
    2e30:	00100513          	li	a0,1
    2e34:	211030ef          	jal	6844 <exit>
  if(pid == 0)
    2e38:	00091663          	bnez	s2,2e44 <sbrkbasic+0x1b4>
    exit(0);
    2e3c:	00000513          	li	a0,0
    2e40:	205030ef          	jal	6844 <exit>
  wait(&xstatus);
    2e44:	fbc40513          	addi	a0,s0,-68
    2e48:	209030ef          	jal	6850 <wait>
  exit(xstatus);
    2e4c:	fbc42503          	lw	a0,-68(s0)
    2e50:	1f5030ef          	jal	6844 <exit>

0000000000002e54 <sbrkmuch>:
{
    2e54:	fd010113          	addi	sp,sp,-48
    2e58:	02113423          	sd	ra,40(sp)
    2e5c:	02813023          	sd	s0,32(sp)
    2e60:	00913c23          	sd	s1,24(sp)
    2e64:	01213823          	sd	s2,16(sp)
    2e68:	01313423          	sd	s3,8(sp)
    2e6c:	01413023          	sd	s4,0(sp)
    2e70:	03010413          	addi	s0,sp,48
    2e74:	00050993          	mv	s3,a0
  oldbrk = sbrk(0);
    2e78:	00000513          	li	a0,0
    2e7c:	16d030ef          	jal	67e8 <sbrk>
    2e80:	00050913          	mv	s2,a0
  a = sbrk(0);
    2e84:	00000513          	li	a0,0
    2e88:	161030ef          	jal	67e8 <sbrk>
    2e8c:	00050493          	mv	s1,a0
  p = sbrk(amt);
    2e90:	06400537          	lui	a0,0x6400
    2e94:	4095053b          	subw	a0,a0,s1
    2e98:	151030ef          	jal	67e8 <sbrk>
  if (p != a) {
    2e9c:	0ca49063          	bne	s1,a0,2f5c <sbrkmuch+0x108>
  *lastaddr = 99;
    2ea0:	064007b7          	lui	a5,0x6400
    2ea4:	06300713          	li	a4,99
    2ea8:	fee78fa3          	sb	a4,-1(a5) # 63fffff <base+0x63ef2c7>
  a = sbrk(0);
    2eac:	00000513          	li	a0,0
    2eb0:	139030ef          	jal	67e8 <sbrk>
    2eb4:	00050493          	mv	s1,a0
  c = sbrk(-PGSIZE);
    2eb8:	fffff537          	lui	a0,0xfffff
    2ebc:	12d030ef          	jal	67e8 <sbrk>
  if(c == (char*)SBRK_ERROR){
    2ec0:	fff00793          	li	a5,-1
    2ec4:	0af50863          	beq	a0,a5,2f74 <sbrkmuch+0x120>
  c = sbrk(0);
    2ec8:	00000513          	li	a0,0
    2ecc:	11d030ef          	jal	67e8 <sbrk>
  if(c != a - PGSIZE){
    2ed0:	80048793          	addi	a5,s1,-2048
    2ed4:	80078793          	addi	a5,a5,-2048
    2ed8:	0af51a63          	bne	a0,a5,2f8c <sbrkmuch+0x138>
  a = sbrk(0);
    2edc:	00000513          	li	a0,0
    2ee0:	109030ef          	jal	67e8 <sbrk>
    2ee4:	00050493          	mv	s1,a0
  c = sbrk(PGSIZE);
    2ee8:	00001537          	lui	a0,0x1
    2eec:	0fd030ef          	jal	67e8 <sbrk>
    2ef0:	00050a13          	mv	s4,a0
  if(c != a || sbrk(0) != a + PGSIZE){
    2ef4:	0aa49c63          	bne	s1,a0,2fac <sbrkmuch+0x158>
    2ef8:	00000513          	li	a0,0
    2efc:	0ed030ef          	jal	67e8 <sbrk>
    2f00:	000017b7          	lui	a5,0x1
    2f04:	00f487b3          	add	a5,s1,a5
    2f08:	0af51263          	bne	a0,a5,2fac <sbrkmuch+0x158>
  if(*lastaddr == 99){
    2f0c:	064007b7          	lui	a5,0x6400
    2f10:	fff7c703          	lbu	a4,-1(a5) # 63fffff <base+0x63ef2c7>
    2f14:	06300793          	li	a5,99
    2f18:	0af70a63          	beq	a4,a5,2fcc <sbrkmuch+0x178>
  a = sbrk(0);
    2f1c:	00000513          	li	a0,0
    2f20:	0c9030ef          	jal	67e8 <sbrk>
    2f24:	00050493          	mv	s1,a0
  c = sbrk(-(sbrk(0) - oldbrk));
    2f28:	00000513          	li	a0,0
    2f2c:	0bd030ef          	jal	67e8 <sbrk>
    2f30:	40a9053b          	subw	a0,s2,a0
    2f34:	0b5030ef          	jal	67e8 <sbrk>
  if(c != a){
    2f38:	0aa49663          	bne	s1,a0,2fe4 <sbrkmuch+0x190>
}
    2f3c:	02813083          	ld	ra,40(sp)
    2f40:	02013403          	ld	s0,32(sp)
    2f44:	01813483          	ld	s1,24(sp)
    2f48:	01013903          	ld	s2,16(sp)
    2f4c:	00813983          	ld	s3,8(sp)
    2f50:	00013a03          	ld	s4,0(sp)
    2f54:	03010113          	addi	sp,sp,48
    2f58:	00008067          	ret
    printf("%s: sbrk test failed to grow big address space; enough phys mem?\n", s);
    2f5c:	00098593          	mv	a1,s3
    2f60:	00005517          	auipc	a0,0x5
    2f64:	fc850513          	addi	a0,a0,-56 # 7f28 <malloc+0xf00>
    2f68:	7b5030ef          	jal	6f1c <printf>
    exit(1);
    2f6c:	00100513          	li	a0,1
    2f70:	0d5030ef          	jal	6844 <exit>
    printf("%s: sbrk could not deallocate\n", s);
    2f74:	00098593          	mv	a1,s3
    2f78:	00005517          	auipc	a0,0x5
    2f7c:	ff850513          	addi	a0,a0,-8 # 7f70 <malloc+0xf48>
    2f80:	79d030ef          	jal	6f1c <printf>
    exit(1);
    2f84:	00100513          	li	a0,1
    2f88:	0bd030ef          	jal	6844 <exit>
    printf("%s: sbrk deallocation produced wrong address, a %p c %p\n", s, a, c);
    2f8c:	00050693          	mv	a3,a0
    2f90:	00048613          	mv	a2,s1
    2f94:	00098593          	mv	a1,s3
    2f98:	00005517          	auipc	a0,0x5
    2f9c:	ff850513          	addi	a0,a0,-8 # 7f90 <malloc+0xf68>
    2fa0:	77d030ef          	jal	6f1c <printf>
    exit(1);
    2fa4:	00100513          	li	a0,1
    2fa8:	09d030ef          	jal	6844 <exit>
    printf("%s: sbrk re-allocation failed, a %p c %p\n", s, a, c);
    2fac:	000a0693          	mv	a3,s4
    2fb0:	00048613          	mv	a2,s1
    2fb4:	00098593          	mv	a1,s3
    2fb8:	00005517          	auipc	a0,0x5
    2fbc:	01850513          	addi	a0,a0,24 # 7fd0 <malloc+0xfa8>
    2fc0:	75d030ef          	jal	6f1c <printf>
    exit(1);
    2fc4:	00100513          	li	a0,1
    2fc8:	07d030ef          	jal	6844 <exit>
    printf("%s: sbrk de-allocation didn't really deallocate\n", s);
    2fcc:	00098593          	mv	a1,s3
    2fd0:	00005517          	auipc	a0,0x5
    2fd4:	03050513          	addi	a0,a0,48 # 8000 <malloc+0xfd8>
    2fd8:	745030ef          	jal	6f1c <printf>
    exit(1);
    2fdc:	00100513          	li	a0,1
    2fe0:	065030ef          	jal	6844 <exit>
    printf("%s: sbrk downsize failed, a %p c %p\n", s, a, c);
    2fe4:	00050693          	mv	a3,a0
    2fe8:	00048613          	mv	a2,s1
    2fec:	00098593          	mv	a1,s3
    2ff0:	00005517          	auipc	a0,0x5
    2ff4:	04850513          	addi	a0,a0,72 # 8038 <malloc+0x1010>
    2ff8:	725030ef          	jal	6f1c <printf>
    exit(1);
    2ffc:	00100513          	li	a0,1
    3000:	045030ef          	jal	6844 <exit>

0000000000003004 <sbrkarg>:
{
    3004:	fd010113          	addi	sp,sp,-48
    3008:	02113423          	sd	ra,40(sp)
    300c:	02813023          	sd	s0,32(sp)
    3010:	00913c23          	sd	s1,24(sp)
    3014:	01213823          	sd	s2,16(sp)
    3018:	01313423          	sd	s3,8(sp)
    301c:	03010413          	addi	s0,sp,48
    3020:	00050993          	mv	s3,a0
  a = sbrk(PGSIZE);
    3024:	00001537          	lui	a0,0x1
    3028:	7c0030ef          	jal	67e8 <sbrk>
    302c:	00050913          	mv	s2,a0
  fd = open("sbrk", O_CREATE|O_WRONLY);
    3030:	20100593          	li	a1,513
    3034:	00005517          	auipc	a0,0x5
    3038:	02c50513          	addi	a0,a0,44 # 8060 <malloc+0x1038>
    303c:	069030ef          	jal	68a4 <open>
    3040:	00050493          	mv	s1,a0
  unlink("sbrk");
    3044:	00005517          	auipc	a0,0x5
    3048:	01c50513          	addi	a0,a0,28 # 8060 <malloc+0x1038>
    304c:	071030ef          	jal	68bc <unlink>
  if(fd < 0)  {
    3050:	0404c663          	bltz	s1,309c <sbrkarg+0x98>
  if ((n = write(fd, a, PGSIZE)) < 0) {
    3054:	00001637          	lui	a2,0x1
    3058:	00090593          	mv	a1,s2
    305c:	00048513          	mv	a0,s1
    3060:	015030ef          	jal	6874 <write>
    3064:	04054863          	bltz	a0,30b4 <sbrkarg+0xb0>
  close(fd);
    3068:	00048513          	mv	a0,s1
    306c:	015030ef          	jal	6880 <close>
  a = sbrk(PGSIZE);
    3070:	00001537          	lui	a0,0x1
    3074:	774030ef          	jal	67e8 <sbrk>
  if(pipe((int *) a) != 0){
    3078:	7e4030ef          	jal	685c <pipe>
    307c:	04051863          	bnez	a0,30cc <sbrkarg+0xc8>
}
    3080:	02813083          	ld	ra,40(sp)
    3084:	02013403          	ld	s0,32(sp)
    3088:	01813483          	ld	s1,24(sp)
    308c:	01013903          	ld	s2,16(sp)
    3090:	00813983          	ld	s3,8(sp)
    3094:	03010113          	addi	sp,sp,48
    3098:	00008067          	ret
    printf("%s: open sbrk failed\n", s);
    309c:	00098593          	mv	a1,s3
    30a0:	00005517          	auipc	a0,0x5
    30a4:	fc850513          	addi	a0,a0,-56 # 8068 <malloc+0x1040>
    30a8:	675030ef          	jal	6f1c <printf>
    exit(1);
    30ac:	00100513          	li	a0,1
    30b0:	794030ef          	jal	6844 <exit>
    printf("%s: write sbrk failed\n", s);
    30b4:	00098593          	mv	a1,s3
    30b8:	00005517          	auipc	a0,0x5
    30bc:	fc850513          	addi	a0,a0,-56 # 8080 <malloc+0x1058>
    30c0:	65d030ef          	jal	6f1c <printf>
    exit(1);
    30c4:	00100513          	li	a0,1
    30c8:	77c030ef          	jal	6844 <exit>
    printf("%s: pipe() failed\n", s);
    30cc:	00098593          	mv	a1,s3
    30d0:	00005517          	auipc	a0,0x5
    30d4:	aa050513          	addi	a0,a0,-1376 # 7b70 <malloc+0xb48>
    30d8:	645030ef          	jal	6f1c <printf>
    exit(1);
    30dc:	00100513          	li	a0,1
    30e0:	764030ef          	jal	6844 <exit>

00000000000030e4 <argptest>:
{
    30e4:	fe010113          	addi	sp,sp,-32
    30e8:	00113c23          	sd	ra,24(sp)
    30ec:	00813823          	sd	s0,16(sp)
    30f0:	00913423          	sd	s1,8(sp)
    30f4:	01213023          	sd	s2,0(sp)
    30f8:	02010413          	addi	s0,sp,32
    30fc:	00050913          	mv	s2,a0
  fd = open("init", O_RDONLY);
    3100:	00000593          	li	a1,0
    3104:	00005517          	auipc	a0,0x5
    3108:	f9450513          	addi	a0,a0,-108 # 8098 <malloc+0x1070>
    310c:	798030ef          	jal	68a4 <open>
  if (fd < 0) {
    3110:	04054063          	bltz	a0,3150 <argptest+0x6c>
    3114:	00050493          	mv	s1,a0
  read(fd, sbrk(0) - 1, -1);
    3118:	00000513          	li	a0,0
    311c:	6cc030ef          	jal	67e8 <sbrk>
    3120:	fff00613          	li	a2,-1
    3124:	00c505b3          	add	a1,a0,a2
    3128:	00048513          	mv	a0,s1
    312c:	73c030ef          	jal	6868 <read>
  close(fd);
    3130:	00048513          	mv	a0,s1
    3134:	74c030ef          	jal	6880 <close>
}
    3138:	01813083          	ld	ra,24(sp)
    313c:	01013403          	ld	s0,16(sp)
    3140:	00813483          	ld	s1,8(sp)
    3144:	00013903          	ld	s2,0(sp)
    3148:	02010113          	addi	sp,sp,32
    314c:	00008067          	ret
    printf("%s: open failed\n", s);
    3150:	00090593          	mv	a1,s2
    3154:	00005517          	auipc	a0,0x5
    3158:	92c50513          	addi	a0,a0,-1748 # 7a80 <malloc+0xa58>
    315c:	5c1030ef          	jal	6f1c <printf>
    exit(1);
    3160:	00100513          	li	a0,1
    3164:	6e0030ef          	jal	6844 <exit>

0000000000003168 <sbrkbugs>:
{
    3168:	ff010113          	addi	sp,sp,-16
    316c:	00113423          	sd	ra,8(sp)
    3170:	00813023          	sd	s0,0(sp)
    3174:	01010413          	addi	s0,sp,16
  int pid = fork();
    3178:	6c0030ef          	jal	6838 <fork>
  if(pid < 0){
    317c:	00054e63          	bltz	a0,3198 <sbrkbugs+0x30>
  if(pid == 0){
    3180:	02051663          	bnez	a0,31ac <sbrkbugs+0x44>
    int sz = (uint64) sbrk(0);
    3184:	664030ef          	jal	67e8 <sbrk>
    sbrk(-sz);
    3188:	40a0053b          	negw	a0,a0
    318c:	65c030ef          	jal	67e8 <sbrk>
    exit(0);
    3190:	00000513          	li	a0,0
    3194:	6b0030ef          	jal	6844 <exit>
    printf("fork failed\n");
    3198:	00006517          	auipc	a0,0x6
    319c:	e7850513          	addi	a0,a0,-392 # 9010 <malloc+0x1fe8>
    31a0:	57d030ef          	jal	6f1c <printf>
    exit(1);
    31a4:	00100513          	li	a0,1
    31a8:	69c030ef          	jal	6844 <exit>
  wait(0);
    31ac:	00000513          	li	a0,0
    31b0:	6a0030ef          	jal	6850 <wait>
  pid = fork();
    31b4:	684030ef          	jal	6838 <fork>
  if(pid < 0){
    31b8:	02054263          	bltz	a0,31dc <sbrkbugs+0x74>
  if(pid == 0){
    31bc:	02051a63          	bnez	a0,31f0 <sbrkbugs+0x88>
    int sz = (uint64) sbrk(0);
    31c0:	628030ef          	jal	67e8 <sbrk>
    sbrk(-(sz - 3500));
    31c4:	000017b7          	lui	a5,0x1
    31c8:	dac7879b          	addiw	a5,a5,-596 # dac <writebig+0x44>
    31cc:	40a7853b          	subw	a0,a5,a0
    31d0:	618030ef          	jal	67e8 <sbrk>
    exit(0);
    31d4:	00000513          	li	a0,0
    31d8:	66c030ef          	jal	6844 <exit>
    printf("fork failed\n");
    31dc:	00006517          	auipc	a0,0x6
    31e0:	e3450513          	addi	a0,a0,-460 # 9010 <malloc+0x1fe8>
    31e4:	539030ef          	jal	6f1c <printf>
    exit(1);
    31e8:	00100513          	li	a0,1
    31ec:	658030ef          	jal	6844 <exit>
  wait(0);
    31f0:	00000513          	li	a0,0
    31f4:	65c030ef          	jal	6850 <wait>
  pid = fork();
    31f8:	640030ef          	jal	6838 <fork>
  if(pid < 0){
    31fc:	02054663          	bltz	a0,3228 <sbrkbugs+0xc0>
  if(pid == 0){
    3200:	02051e63          	bnez	a0,323c <sbrkbugs+0xd4>
    sbrk((10*PGSIZE + 2048) - (uint64)sbrk(0));
    3204:	5e4030ef          	jal	67e8 <sbrk>
    3208:	0000b7b7          	lui	a5,0xb
    320c:	8007879b          	addiw	a5,a5,-2048 # a800 <big.0+0x260>
    3210:	40a7853b          	subw	a0,a5,a0
    3214:	5d4030ef          	jal	67e8 <sbrk>
    sbrk(-10);
    3218:	ff600513          	li	a0,-10
    321c:	5cc030ef          	jal	67e8 <sbrk>
    exit(0);
    3220:	00000513          	li	a0,0
    3224:	620030ef          	jal	6844 <exit>
    printf("fork failed\n");
    3228:	00006517          	auipc	a0,0x6
    322c:	de850513          	addi	a0,a0,-536 # 9010 <malloc+0x1fe8>
    3230:	4ed030ef          	jal	6f1c <printf>
    exit(1);
    3234:	00100513          	li	a0,1
    3238:	60c030ef          	jal	6844 <exit>
  wait(0);
    323c:	00000513          	li	a0,0
    3240:	610030ef          	jal	6850 <wait>
  exit(0);
    3244:	00000513          	li	a0,0
    3248:	5fc030ef          	jal	6844 <exit>

000000000000324c <sbrklast>:
{
    324c:	fd010113          	addi	sp,sp,-48
    3250:	02113423          	sd	ra,40(sp)
    3254:	02813023          	sd	s0,32(sp)
    3258:	00913c23          	sd	s1,24(sp)
    325c:	01213823          	sd	s2,16(sp)
    3260:	01313423          	sd	s3,8(sp)
    3264:	01413023          	sd	s4,0(sp)
    3268:	03010413          	addi	s0,sp,48
  uint64 top = (uint64) sbrk(0);
    326c:	00000513          	li	a0,0
    3270:	578030ef          	jal	67e8 <sbrk>
  if((top % PGSIZE) != 0)
    3274:	03451793          	slli	a5,a0,0x34
    3278:	0a079063          	bnez	a5,3318 <sbrklast+0xcc>
  sbrk(PGSIZE);
    327c:	00001537          	lui	a0,0x1
    3280:	568030ef          	jal	67e8 <sbrk>
  sbrk(10);
    3284:	00a00513          	li	a0,10
    3288:	560030ef          	jal	67e8 <sbrk>
  sbrk(-20);
    328c:	fec00513          	li	a0,-20
    3290:	558030ef          	jal	67e8 <sbrk>
  top = (uint64) sbrk(0);
    3294:	00000513          	li	a0,0
    3298:	550030ef          	jal	67e8 <sbrk>
    329c:	00050493          	mv	s1,a0
  char *p = (char *) (top - 64);
    32a0:	fc050913          	addi	s2,a0,-64 # fc0 <unlinkread+0x88>
  p[0] = 'x';
    32a4:	07800993          	li	s3,120
    32a8:	fd350023          	sb	s3,-64(a0)
  p[1] = '\0';
    32ac:	fc0500a3          	sb	zero,-63(a0)
  int fd = open(p, O_RDWR|O_CREATE);
    32b0:	20200593          	li	a1,514
    32b4:	00090513          	mv	a0,s2
    32b8:	5ec030ef          	jal	68a4 <open>
    32bc:	00050a13          	mv	s4,a0
  write(fd, p, 1);
    32c0:	00100613          	li	a2,1
    32c4:	00090593          	mv	a1,s2
    32c8:	5ac030ef          	jal	6874 <write>
  close(fd);
    32cc:	000a0513          	mv	a0,s4
    32d0:	5b0030ef          	jal	6880 <close>
  fd = open(p, O_RDWR);
    32d4:	00200593          	li	a1,2
    32d8:	00090513          	mv	a0,s2
    32dc:	5c8030ef          	jal	68a4 <open>
  p[0] = '\0';
    32e0:	fc048023          	sb	zero,-64(s1)
  read(fd, p, 1);
    32e4:	00100613          	li	a2,1
    32e8:	00090593          	mv	a1,s2
    32ec:	57c030ef          	jal	6868 <read>
  if(p[0] != 'x')
    32f0:	fc04c783          	lbu	a5,-64(s1)
    32f4:	03379c63          	bne	a5,s3,332c <sbrklast+0xe0>
}
    32f8:	02813083          	ld	ra,40(sp)
    32fc:	02013403          	ld	s0,32(sp)
    3300:	01813483          	ld	s1,24(sp)
    3304:	01013903          	ld	s2,16(sp)
    3308:	00813983          	ld	s3,8(sp)
    330c:	00013a03          	ld	s4,0(sp)
    3310:	03010113          	addi	sp,sp,48
    3314:	00008067          	ret
    sbrk(PGSIZE - (top % PGSIZE));
    3318:	0347d513          	srli	a0,a5,0x34
    331c:	000017b7          	lui	a5,0x1
    3320:	40a7853b          	subw	a0,a5,a0
    3324:	4c4030ef          	jal	67e8 <sbrk>
    3328:	f55ff06f          	j	327c <sbrklast+0x30>
    exit(1);
    332c:	00100513          	li	a0,1
    3330:	514030ef          	jal	6844 <exit>

0000000000003334 <sbrk8000>:
{
    3334:	ff010113          	addi	sp,sp,-16
    3338:	00113423          	sd	ra,8(sp)
    333c:	00813023          	sd	s0,0(sp)
    3340:	01010413          	addi	s0,sp,16
  sbrk(0x80000004);
    3344:	80000537          	lui	a0,0x80000
    3348:	00450513          	addi	a0,a0,4 # ffffffff80000004 <base+0xffffffff7ffef2cc>
    334c:	49c030ef          	jal	67e8 <sbrk>
  volatile char *top = sbrk(0);
    3350:	00000513          	li	a0,0
    3354:	494030ef          	jal	67e8 <sbrk>
  *(top-1) = *(top-1) + 1;
    3358:	fff54783          	lbu	a5,-1(a0)
    335c:	00178793          	addi	a5,a5,1 # 1001 <unlinkread+0xc9>
    3360:	0ff7f793          	zext.b	a5,a5
    3364:	fef50fa3          	sb	a5,-1(a0)
}
    3368:	00813083          	ld	ra,8(sp)
    336c:	00013403          	ld	s0,0(sp)
    3370:	01010113          	addi	sp,sp,16
    3374:	00008067          	ret

0000000000003378 <execout>:
{
    3378:	fa010113          	addi	sp,sp,-96
    337c:	04113c23          	sd	ra,88(sp)
    3380:	04813823          	sd	s0,80(sp)
    3384:	04913423          	sd	s1,72(sp)
    3388:	05213023          	sd	s2,64(sp)
    338c:	03313c23          	sd	s3,56(sp)
    3390:	06010413          	addi	s0,sp,96
  for(int avail = 0; avail < 15; avail++){
    3394:	00000913          	li	s2,0
    3398:	00f00993          	li	s3,15
    int pid = fork();
    339c:	49c030ef          	jal	6838 <fork>
    33a0:	00050493          	mv	s1,a0
    if(pid < 0){
    33a4:	02054463          	bltz	a0,33cc <execout+0x54>
    } else if(pid == 0){
    33a8:	04050063          	beqz	a0,33e8 <execout+0x70>
      wait((int*)0);
    33ac:	00000513          	li	a0,0
    33b0:	4a0030ef          	jal	6850 <wait>
  for(int avail = 0; avail < 15; avail++){
    33b4:	0019091b          	addiw	s2,s2,1
    33b8:	ff3912e3          	bne	s2,s3,339c <execout+0x24>
    33bc:	03413823          	sd	s4,48(sp)
    33c0:	03513423          	sd	s5,40(sp)
  exit(0);
    33c4:	00000513          	li	a0,0
    33c8:	47c030ef          	jal	6844 <exit>
    33cc:	03413823          	sd	s4,48(sp)
    33d0:	03513423          	sd	s5,40(sp)
      printf("fork failed\n");
    33d4:	00006517          	auipc	a0,0x6
    33d8:	c3c50513          	addi	a0,a0,-964 # 9010 <malloc+0x1fe8>
    33dc:	341030ef          	jal	6f1c <printf>
      exit(1);
    33e0:	00100513          	li	a0,1
    33e4:	460030ef          	jal	6844 <exit>
    33e8:	03413823          	sd	s4,48(sp)
    33ec:	03513423          	sd	s5,40(sp)
        char *a = sbrk(PGSIZE);
    33f0:	000019b7          	lui	s3,0x1
        if(a == SBRK_ERROR)
    33f4:	fff00a13          	li	s4,-1
        *(a + PGSIZE - 1) = 1;
    33f8:	00100a93          	li	s5,1
        char *a = sbrk(PGSIZE);
    33fc:	00098513          	mv	a0,s3
    3400:	3e8030ef          	jal	67e8 <sbrk>
        if(a == SBRK_ERROR)
    3404:	01450863          	beq	a0,s4,3414 <execout+0x9c>
        *(a + PGSIZE - 1) = 1;
    3408:	01350533          	add	a0,a0,s3
    340c:	ff550fa3          	sb	s5,-1(a0)
      while(1){
    3410:	fedff06f          	j	33fc <execout+0x84>
        sbrk(-PGSIZE);
    3414:	fffff9b7          	lui	s3,0xfffff
      for(int i = 0; i < avail; i++)
    3418:	01205a63          	blez	s2,342c <execout+0xb4>
        sbrk(-PGSIZE);
    341c:	00098513          	mv	a0,s3
    3420:	3c8030ef          	jal	67e8 <sbrk>
      for(int i = 0; i < avail; i++)
    3424:	0014849b          	addiw	s1,s1,1
    3428:	ff249ae3          	bne	s1,s2,341c <execout+0xa4>
      close(1);
    342c:	00100513          	li	a0,1
    3430:	450030ef          	jal	6880 <close>
      char *args[] = { "echo", "x", 0 };
    3434:	00004797          	auipc	a5,0x4
    3438:	da478793          	addi	a5,a5,-604 # 71d8 <malloc+0x1b0>
    343c:	faf43423          	sd	a5,-88(s0)
    3440:	00004797          	auipc	a5,0x4
    3444:	e0878793          	addi	a5,a5,-504 # 7248 <malloc+0x220>
    3448:	faf43823          	sd	a5,-80(s0)
    344c:	fa043c23          	sd	zero,-72(s0)
      exec("echo", args);
    3450:	fa840593          	addi	a1,s0,-88
    3454:	00004517          	auipc	a0,0x4
    3458:	d8450513          	addi	a0,a0,-636 # 71d8 <malloc+0x1b0>
    345c:	43c030ef          	jal	6898 <exec>
      exit(0);
    3460:	00000513          	li	a0,0
    3464:	3e0030ef          	jal	6844 <exit>

0000000000003468 <fourteen>:
{
    3468:	fe010113          	addi	sp,sp,-32
    346c:	00113c23          	sd	ra,24(sp)
    3470:	00813823          	sd	s0,16(sp)
    3474:	00913423          	sd	s1,8(sp)
    3478:	02010413          	addi	s0,sp,32
    347c:	00050493          	mv	s1,a0
  if(mkdir("12345678901234") != 0){
    3480:	00005517          	auipc	a0,0x5
    3484:	df050513          	addi	a0,a0,-528 # 8270 <malloc+0x1248>
    3488:	458030ef          	jal	68e0 <mkdir>
    348c:	0c051063          	bnez	a0,354c <fourteen+0xe4>
  if(mkdir("12345678901234/123456789012345") != 0){
    3490:	00005517          	auipc	a0,0x5
    3494:	c3850513          	addi	a0,a0,-968 # 80c8 <malloc+0x10a0>
    3498:	448030ef          	jal	68e0 <mkdir>
    349c:	0c051463          	bnez	a0,3564 <fourteen+0xfc>
  fd = open("123456789012345/123456789012345/123456789012345", O_CREATE);
    34a0:	20000593          	li	a1,512
    34a4:	00005517          	auipc	a0,0x5
    34a8:	c7c50513          	addi	a0,a0,-900 # 8120 <malloc+0x10f8>
    34ac:	3f8030ef          	jal	68a4 <open>
  if(fd < 0){
    34b0:	0c054663          	bltz	a0,357c <fourteen+0x114>
  close(fd);
    34b4:	3cc030ef          	jal	6880 <close>
  fd = open("12345678901234/12345678901234/12345678901234", 0);
    34b8:	00000593          	li	a1,0
    34bc:	00005517          	auipc	a0,0x5
    34c0:	cdc50513          	addi	a0,a0,-804 # 8198 <malloc+0x1170>
    34c4:	3e0030ef          	jal	68a4 <open>
  if(fd < 0){
    34c8:	0c054663          	bltz	a0,3594 <fourteen+0x12c>
  close(fd);
    34cc:	3b4030ef          	jal	6880 <close>
  if(mkdir("12345678901234/12345678901234") == 0){
    34d0:	00005517          	auipc	a0,0x5
    34d4:	d3850513          	addi	a0,a0,-712 # 8208 <malloc+0x11e0>
    34d8:	408030ef          	jal	68e0 <mkdir>
    34dc:	0c050863          	beqz	a0,35ac <fourteen+0x144>
  if(mkdir("123456789012345/12345678901234") == 0){
    34e0:	00005517          	auipc	a0,0x5
    34e4:	d8050513          	addi	a0,a0,-640 # 8260 <malloc+0x1238>
    34e8:	3f8030ef          	jal	68e0 <mkdir>
    34ec:	0c050c63          	beqz	a0,35c4 <fourteen+0x15c>
  unlink("123456789012345/12345678901234");
    34f0:	00005517          	auipc	a0,0x5
    34f4:	d7050513          	addi	a0,a0,-656 # 8260 <malloc+0x1238>
    34f8:	3c4030ef          	jal	68bc <unlink>
  unlink("12345678901234/12345678901234");
    34fc:	00005517          	auipc	a0,0x5
    3500:	d0c50513          	addi	a0,a0,-756 # 8208 <malloc+0x11e0>
    3504:	3b8030ef          	jal	68bc <unlink>
  unlink("12345678901234/12345678901234/12345678901234");
    3508:	00005517          	auipc	a0,0x5
    350c:	c9050513          	addi	a0,a0,-880 # 8198 <malloc+0x1170>
    3510:	3ac030ef          	jal	68bc <unlink>
  unlink("123456789012345/123456789012345/123456789012345");
    3514:	00005517          	auipc	a0,0x5
    3518:	c0c50513          	addi	a0,a0,-1012 # 8120 <malloc+0x10f8>
    351c:	3a0030ef          	jal	68bc <unlink>
  unlink("12345678901234/123456789012345");
    3520:	00005517          	auipc	a0,0x5
    3524:	ba850513          	addi	a0,a0,-1112 # 80c8 <malloc+0x10a0>
    3528:	394030ef          	jal	68bc <unlink>
  unlink("12345678901234");
    352c:	00005517          	auipc	a0,0x5
    3530:	d4450513          	addi	a0,a0,-700 # 8270 <malloc+0x1248>
    3534:	388030ef          	jal	68bc <unlink>
}
    3538:	01813083          	ld	ra,24(sp)
    353c:	01013403          	ld	s0,16(sp)
    3540:	00813483          	ld	s1,8(sp)
    3544:	02010113          	addi	sp,sp,32
    3548:	00008067          	ret
    printf("%s: mkdir 12345678901234 failed\n", s);
    354c:	00048593          	mv	a1,s1
    3550:	00005517          	auipc	a0,0x5
    3554:	b5050513          	addi	a0,a0,-1200 # 80a0 <malloc+0x1078>
    3558:	1c5030ef          	jal	6f1c <printf>
    exit(1);
    355c:	00100513          	li	a0,1
    3560:	2e4030ef          	jal	6844 <exit>
    printf("%s: mkdir 12345678901234/123456789012345 failed\n", s);
    3564:	00048593          	mv	a1,s1
    3568:	00005517          	auipc	a0,0x5
    356c:	b8050513          	addi	a0,a0,-1152 # 80e8 <malloc+0x10c0>
    3570:	1ad030ef          	jal	6f1c <printf>
    exit(1);
    3574:	00100513          	li	a0,1
    3578:	2cc030ef          	jal	6844 <exit>
    printf("%s: create 123456789012345/123456789012345/123456789012345 failed\n", s);
    357c:	00048593          	mv	a1,s1
    3580:	00005517          	auipc	a0,0x5
    3584:	bd050513          	addi	a0,a0,-1072 # 8150 <malloc+0x1128>
    3588:	195030ef          	jal	6f1c <printf>
    exit(1);
    358c:	00100513          	li	a0,1
    3590:	2b4030ef          	jal	6844 <exit>
    printf("%s: open 12345678901234/12345678901234/12345678901234 failed\n", s);
    3594:	00048593          	mv	a1,s1
    3598:	00005517          	auipc	a0,0x5
    359c:	c3050513          	addi	a0,a0,-976 # 81c8 <malloc+0x11a0>
    35a0:	17d030ef          	jal	6f1c <printf>
    exit(1);
    35a4:	00100513          	li	a0,1
    35a8:	29c030ef          	jal	6844 <exit>
    printf("%s: mkdir 12345678901234/12345678901234 succeeded!\n", s);
    35ac:	00048593          	mv	a1,s1
    35b0:	00005517          	auipc	a0,0x5
    35b4:	c7850513          	addi	a0,a0,-904 # 8228 <malloc+0x1200>
    35b8:	165030ef          	jal	6f1c <printf>
    exit(1);
    35bc:	00100513          	li	a0,1
    35c0:	284030ef          	jal	6844 <exit>
    printf("%s: mkdir 12345678901234/123456789012345 succeeded!\n", s);
    35c4:	00048593          	mv	a1,s1
    35c8:	00005517          	auipc	a0,0x5
    35cc:	cb850513          	addi	a0,a0,-840 # 8280 <malloc+0x1258>
    35d0:	14d030ef          	jal	6f1c <printf>
    exit(1);
    35d4:	00100513          	li	a0,1
    35d8:	26c030ef          	jal	6844 <exit>

00000000000035dc <diskfull>:
{
    35dc:	b6010113          	addi	sp,sp,-1184
    35e0:	48113c23          	sd	ra,1176(sp)
    35e4:	48813823          	sd	s0,1168(sp)
    35e8:	48913423          	sd	s1,1160(sp)
    35ec:	49213023          	sd	s2,1152(sp)
    35f0:	47313c23          	sd	s3,1144(sp)
    35f4:	47413823          	sd	s4,1136(sp)
    35f8:	47513423          	sd	s5,1128(sp)
    35fc:	47613023          	sd	s6,1120(sp)
    3600:	45713c23          	sd	s7,1112(sp)
    3604:	45813823          	sd	s8,1104(sp)
    3608:	45913423          	sd	s9,1096(sp)
    360c:	45a13023          	sd	s10,1088(sp)
    3610:	43b13c23          	sd	s11,1080(sp)
    3614:	4a010413          	addi	s0,sp,1184
    3618:	b6a43423          	sd	a0,-1176(s0)
  unlink("diskfulldir");
    361c:	00005517          	auipc	a0,0x5
    3620:	c9c50513          	addi	a0,a0,-868 # 82b8 <malloc+0x1290>
    3624:	298030ef          	jal	68bc <unlink>
    3628:	03000a93          	li	s5,48
    name[0] = 'b';
    362c:	06200d13          	li	s10,98
    name[1] = 'i';
    3630:	06900c93          	li	s9,105
    name[2] = 'g';
    3634:	06700c13          	li	s8,103
    unlink(name);
    3638:	b7040b13          	addi	s6,s0,-1168
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
    363c:	60200b93          	li	s7,1538
    3640:	10c00d93          	li	s11,268
      if(write(fd, buf, BSIZE) != BSIZE){
    3644:	b9040a13          	addi	s4,s0,-1136
    3648:	19c0006f          	j	37e4 <diskfull+0x208>
      printf("%s: could not create file %s\n", s, name);
    364c:	b7040613          	addi	a2,s0,-1168
    3650:	b6843583          	ld	a1,-1176(s0)
    3654:	00005517          	auipc	a0,0x5
    3658:	c7450513          	addi	a0,a0,-908 # 82c8 <malloc+0x12a0>
    365c:	0c1030ef          	jal	6f1c <printf>
      break;
    3660:	0140006f          	j	3674 <diskfull+0x98>
        close(fd);
    3664:	00098513          	mv	a0,s3
    3668:	218030ef          	jal	6880 <close>
    close(fd);
    366c:	00098513          	mv	a0,s3
    3670:	210030ef          	jal	6880 <close>
  for(int i = 0; i < nzz; i++){
    3674:	00000493          	li	s1,0
    name[0] = 'z';
    3678:	07a00993          	li	s3,122
    unlink(name);
    367c:	b9040913          	addi	s2,s0,-1136
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
    3680:	60200a13          	li	s4,1538
  for(int i = 0; i < nzz; i++){
    3684:	08000a93          	li	s5,128
    name[0] = 'z';
    3688:	b9340823          	sb	s3,-1136(s0)
    name[1] = 'z';
    368c:	b93408a3          	sb	s3,-1135(s0)
    name[2] = '0' + (i / 32);
    3690:	41f4d71b          	sraiw	a4,s1,0x1f
    3694:	01b7571b          	srliw	a4,a4,0x1b
    3698:	009707bb          	addw	a5,a4,s1
    369c:	4057d69b          	sraiw	a3,a5,0x5
    36a0:	0306869b          	addiw	a3,a3,48
    36a4:	b8d40923          	sb	a3,-1134(s0)
    name[3] = '0' + (i % 32);
    36a8:	01f7f793          	andi	a5,a5,31
    36ac:	40e787bb          	subw	a5,a5,a4
    36b0:	0307879b          	addiw	a5,a5,48
    36b4:	b8f409a3          	sb	a5,-1133(s0)
    name[4] = '\0';
    36b8:	b8040a23          	sb	zero,-1132(s0)
    unlink(name);
    36bc:	00090513          	mv	a0,s2
    36c0:	1fc030ef          	jal	68bc <unlink>
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
    36c4:	000a0593          	mv	a1,s4
    36c8:	00090513          	mv	a0,s2
    36cc:	1d8030ef          	jal	68a4 <open>
    if(fd < 0)
    36d0:	00054863          	bltz	a0,36e0 <diskfull+0x104>
    close(fd);
    36d4:	1ac030ef          	jal	6880 <close>
  for(int i = 0; i < nzz; i++){
    36d8:	0014849b          	addiw	s1,s1,1
    36dc:	fb5496e3          	bne	s1,s5,3688 <diskfull+0xac>
  if(mkdir("diskfulldir") == 0)
    36e0:	00005517          	auipc	a0,0x5
    36e4:	bd850513          	addi	a0,a0,-1064 # 82b8 <malloc+0x1290>
    36e8:	1f8030ef          	jal	68e0 <mkdir>
    36ec:	14050863          	beqz	a0,383c <diskfull+0x260>
  unlink("diskfulldir");
    36f0:	00005517          	auipc	a0,0x5
    36f4:	bc850513          	addi	a0,a0,-1080 # 82b8 <malloc+0x1290>
    36f8:	1c4030ef          	jal	68bc <unlink>
  for(int i = 0; i < nzz; i++){
    36fc:	00000493          	li	s1,0
    name[0] = 'z';
    3700:	07a00913          	li	s2,122
    unlink(name);
    3704:	b9040a13          	addi	s4,s0,-1136
  for(int i = 0; i < nzz; i++){
    3708:	08000993          	li	s3,128
    name[0] = 'z';
    370c:	b9240823          	sb	s2,-1136(s0)
    name[1] = 'z';
    3710:	b92408a3          	sb	s2,-1135(s0)
    name[2] = '0' + (i / 32);
    3714:	41f4d71b          	sraiw	a4,s1,0x1f
    3718:	01b7571b          	srliw	a4,a4,0x1b
    371c:	009707bb          	addw	a5,a4,s1
    3720:	4057d69b          	sraiw	a3,a5,0x5
    3724:	0306869b          	addiw	a3,a3,48
    3728:	b8d40923          	sb	a3,-1134(s0)
    name[3] = '0' + (i % 32);
    372c:	01f7f793          	andi	a5,a5,31
    3730:	40e787bb          	subw	a5,a5,a4
    3734:	0307879b          	addiw	a5,a5,48
    3738:	b8f409a3          	sb	a5,-1133(s0)
    name[4] = '\0';
    373c:	b8040a23          	sb	zero,-1132(s0)
    unlink(name);
    3740:	000a0513          	mv	a0,s4
    3744:	178030ef          	jal	68bc <unlink>
  for(int i = 0; i < nzz; i++){
    3748:	0014849b          	addiw	s1,s1,1
    374c:	fd3490e3          	bne	s1,s3,370c <diskfull+0x130>
    3750:	03000493          	li	s1,48
    name[0] = 'b';
    3754:	06200b13          	li	s6,98
    name[1] = 'i';
    3758:	06900a93          	li	s5,105
    name[2] = 'g';
    375c:	06700a13          	li	s4,103
    unlink(name);
    3760:	b9040993          	addi	s3,s0,-1136
  for(int i = 0; '0' + i < 0177; i++){
    3764:	07f00913          	li	s2,127
    name[0] = 'b';
    3768:	b9640823          	sb	s6,-1136(s0)
    name[1] = 'i';
    376c:	b95408a3          	sb	s5,-1135(s0)
    name[2] = 'g';
    3770:	b9440923          	sb	s4,-1134(s0)
    name[3] = '0' + i;
    3774:	b89409a3          	sb	s1,-1133(s0)
    name[4] = '\0';
    3778:	b8040a23          	sb	zero,-1132(s0)
    unlink(name);
    377c:	00098513          	mv	a0,s3
    3780:	13c030ef          	jal	68bc <unlink>
  for(int i = 0; '0' + i < 0177; i++){
    3784:	0014849b          	addiw	s1,s1,1
    3788:	0ff4f493          	zext.b	s1,s1
    378c:	fd249ee3          	bne	s1,s2,3768 <diskfull+0x18c>
}
    3790:	49813083          	ld	ra,1176(sp)
    3794:	49013403          	ld	s0,1168(sp)
    3798:	48813483          	ld	s1,1160(sp)
    379c:	48013903          	ld	s2,1152(sp)
    37a0:	47813983          	ld	s3,1144(sp)
    37a4:	47013a03          	ld	s4,1136(sp)
    37a8:	46813a83          	ld	s5,1128(sp)
    37ac:	46013b03          	ld	s6,1120(sp)
    37b0:	45813b83          	ld	s7,1112(sp)
    37b4:	45013c03          	ld	s8,1104(sp)
    37b8:	44813c83          	ld	s9,1096(sp)
    37bc:	44013d03          	ld	s10,1088(sp)
    37c0:	43813d83          	ld	s11,1080(sp)
    37c4:	4a010113          	addi	sp,sp,1184
    37c8:	00008067          	ret
    close(fd);
    37cc:	00098513          	mv	a0,s3
    37d0:	0b0030ef          	jal	6880 <close>
  for(fi = 0; done == 0 && '0' + fi < 0177; fi++){
    37d4:	001a8a9b          	addiw	s5,s5,1 # 3001 <sbrkmuch+0x1ad>
    37d8:	0ffafa93          	zext.b	s5,s5
    37dc:	07f00793          	li	a5,127
    37e0:	e8fa8ae3          	beq	s5,a5,3674 <diskfull+0x98>
    name[0] = 'b';
    37e4:	b7a40823          	sb	s10,-1168(s0)
    name[1] = 'i';
    37e8:	b79408a3          	sb	s9,-1167(s0)
    name[2] = 'g';
    37ec:	b7840923          	sb	s8,-1166(s0)
    name[3] = '0' + fi;
    37f0:	b75409a3          	sb	s5,-1165(s0)
    name[4] = '\0';
    37f4:	b6040a23          	sb	zero,-1164(s0)
    unlink(name);
    37f8:	000b0513          	mv	a0,s6
    37fc:	0c0030ef          	jal	68bc <unlink>
    int fd = open(name, O_CREATE|O_RDWR|O_TRUNC);
    3800:	000b8593          	mv	a1,s7
    3804:	000b0513          	mv	a0,s6
    3808:	09c030ef          	jal	68a4 <open>
    380c:	00050993          	mv	s3,a0
    if(fd < 0){
    3810:	e2054ee3          	bltz	a0,364c <diskfull+0x70>
    3814:	000d8493          	mv	s1,s11
      if(write(fd, buf, BSIZE) != BSIZE){
    3818:	40000913          	li	s2,1024
    381c:	00090613          	mv	a2,s2
    3820:	000a0593          	mv	a1,s4
    3824:	00098513          	mv	a0,s3
    3828:	04c030ef          	jal	6874 <write>
    382c:	e3251ce3          	bne	a0,s2,3664 <diskfull+0x88>
    for(int i = 0; i < MAXFILE; i++){
    3830:	fff4849b          	addiw	s1,s1,-1
    3834:	fe0494e3          	bnez	s1,381c <diskfull+0x240>
    3838:	f95ff06f          	j	37cc <diskfull+0x1f0>
    printf("%s: mkdir(diskfulldir) unexpectedly succeeded!\n", s);
    383c:	b6843583          	ld	a1,-1176(s0)
    3840:	00005517          	auipc	a0,0x5
    3844:	aa850513          	addi	a0,a0,-1368 # 82e8 <malloc+0x12c0>
    3848:	6d4030ef          	jal	6f1c <printf>
    384c:	ea5ff06f          	j	36f0 <diskfull+0x114>

0000000000003850 <iputtest>:
{
    3850:	fe010113          	addi	sp,sp,-32
    3854:	00113c23          	sd	ra,24(sp)
    3858:	00813823          	sd	s0,16(sp)
    385c:	00913423          	sd	s1,8(sp)
    3860:	02010413          	addi	s0,sp,32
    3864:	00050493          	mv	s1,a0
  if(mkdir("iputdir") < 0){
    3868:	00005517          	auipc	a0,0x5
    386c:	ab050513          	addi	a0,a0,-1360 # 8318 <malloc+0x12f0>
    3870:	070030ef          	jal	68e0 <mkdir>
    3874:	04054463          	bltz	a0,38bc <iputtest+0x6c>
  if(chdir("iputdir") < 0){
    3878:	00005517          	auipc	a0,0x5
    387c:	aa050513          	addi	a0,a0,-1376 # 8318 <malloc+0x12f0>
    3880:	06c030ef          	jal	68ec <chdir>
    3884:	04054863          	bltz	a0,38d4 <iputtest+0x84>
  if(unlink("../iputdir") < 0){
    3888:	00005517          	auipc	a0,0x5
    388c:	ad050513          	addi	a0,a0,-1328 # 8358 <malloc+0x1330>
    3890:	02c030ef          	jal	68bc <unlink>
    3894:	04054c63          	bltz	a0,38ec <iputtest+0x9c>
  if(chdir("/") < 0){
    3898:	00005517          	auipc	a0,0x5
    389c:	af050513          	addi	a0,a0,-1296 # 8388 <malloc+0x1360>
    38a0:	04c030ef          	jal	68ec <chdir>
    38a4:	06054063          	bltz	a0,3904 <iputtest+0xb4>
}
    38a8:	01813083          	ld	ra,24(sp)
    38ac:	01013403          	ld	s0,16(sp)
    38b0:	00813483          	ld	s1,8(sp)
    38b4:	02010113          	addi	sp,sp,32
    38b8:	00008067          	ret
    printf("%s: mkdir failed\n", s);
    38bc:	00048593          	mv	a1,s1
    38c0:	00005517          	auipc	a0,0x5
    38c4:	a6050513          	addi	a0,a0,-1440 # 8320 <malloc+0x12f8>
    38c8:	654030ef          	jal	6f1c <printf>
    exit(1);
    38cc:	00100513          	li	a0,1
    38d0:	775020ef          	jal	6844 <exit>
    printf("%s: chdir iputdir failed\n", s);
    38d4:	00048593          	mv	a1,s1
    38d8:	00005517          	auipc	a0,0x5
    38dc:	a6050513          	addi	a0,a0,-1440 # 8338 <malloc+0x1310>
    38e0:	63c030ef          	jal	6f1c <printf>
    exit(1);
    38e4:	00100513          	li	a0,1
    38e8:	75d020ef          	jal	6844 <exit>
    printf("%s: unlink ../iputdir failed\n", s);
    38ec:	00048593          	mv	a1,s1
    38f0:	00005517          	auipc	a0,0x5
    38f4:	a7850513          	addi	a0,a0,-1416 # 8368 <malloc+0x1340>
    38f8:	624030ef          	jal	6f1c <printf>
    exit(1);
    38fc:	00100513          	li	a0,1
    3900:	745020ef          	jal	6844 <exit>
    printf("%s: chdir / failed\n", s);
    3904:	00048593          	mv	a1,s1
    3908:	00005517          	auipc	a0,0x5
    390c:	a8850513          	addi	a0,a0,-1400 # 8390 <malloc+0x1368>
    3910:	60c030ef          	jal	6f1c <printf>
    exit(1);
    3914:	00100513          	li	a0,1
    3918:	72d020ef          	jal	6844 <exit>

000000000000391c <exitiputtest>:
{
    391c:	fd010113          	addi	sp,sp,-48
    3920:	02113423          	sd	ra,40(sp)
    3924:	02813023          	sd	s0,32(sp)
    3928:	00913c23          	sd	s1,24(sp)
    392c:	03010413          	addi	s0,sp,48
    3930:	00050493          	mv	s1,a0
  pid = fork();
    3934:	705020ef          	jal	6838 <fork>
  if(pid < 0){
    3938:	04054063          	bltz	a0,3978 <exitiputtest+0x5c>
  if(pid == 0){
    393c:	08051e63          	bnez	a0,39d8 <exitiputtest+0xbc>
    if(mkdir("iputdir") < 0){
    3940:	00005517          	auipc	a0,0x5
    3944:	9d850513          	addi	a0,a0,-1576 # 8318 <malloc+0x12f0>
    3948:	799020ef          	jal	68e0 <mkdir>
    394c:	04054263          	bltz	a0,3990 <exitiputtest+0x74>
    if(chdir("iputdir") < 0){
    3950:	00005517          	auipc	a0,0x5
    3954:	9c850513          	addi	a0,a0,-1592 # 8318 <malloc+0x12f0>
    3958:	795020ef          	jal	68ec <chdir>
    395c:	04054663          	bltz	a0,39a8 <exitiputtest+0x8c>
    if(unlink("../iputdir") < 0){
    3960:	00005517          	auipc	a0,0x5
    3964:	9f850513          	addi	a0,a0,-1544 # 8358 <malloc+0x1330>
    3968:	755020ef          	jal	68bc <unlink>
    396c:	04054a63          	bltz	a0,39c0 <exitiputtest+0xa4>
    exit(0);
    3970:	00000513          	li	a0,0
    3974:	6d1020ef          	jal	6844 <exit>
    printf("%s: fork failed\n", s);
    3978:	00048593          	mv	a1,s1
    397c:	00004517          	auipc	a0,0x4
    3980:	0ec50513          	addi	a0,a0,236 # 7a68 <malloc+0xa40>
    3984:	598030ef          	jal	6f1c <printf>
    exit(1);
    3988:	00100513          	li	a0,1
    398c:	6b9020ef          	jal	6844 <exit>
      printf("%s: mkdir failed\n", s);
    3990:	00048593          	mv	a1,s1
    3994:	00005517          	auipc	a0,0x5
    3998:	98c50513          	addi	a0,a0,-1652 # 8320 <malloc+0x12f8>
    399c:	580030ef          	jal	6f1c <printf>
      exit(1);
    39a0:	00100513          	li	a0,1
    39a4:	6a1020ef          	jal	6844 <exit>
      printf("%s: child chdir failed\n", s);
    39a8:	00048593          	mv	a1,s1
    39ac:	00005517          	auipc	a0,0x5
    39b0:	9fc50513          	addi	a0,a0,-1540 # 83a8 <malloc+0x1380>
    39b4:	568030ef          	jal	6f1c <printf>
      exit(1);
    39b8:	00100513          	li	a0,1
    39bc:	689020ef          	jal	6844 <exit>
      printf("%s: unlink ../iputdir failed\n", s);
    39c0:	00048593          	mv	a1,s1
    39c4:	00005517          	auipc	a0,0x5
    39c8:	9a450513          	addi	a0,a0,-1628 # 8368 <malloc+0x1340>
    39cc:	550030ef          	jal	6f1c <printf>
      exit(1);
    39d0:	00100513          	li	a0,1
    39d4:	671020ef          	jal	6844 <exit>
  wait(&xstatus);
    39d8:	fdc40513          	addi	a0,s0,-36
    39dc:	675020ef          	jal	6850 <wait>
  exit(xstatus);
    39e0:	fdc42503          	lw	a0,-36(s0)
    39e4:	661020ef          	jal	6844 <exit>

00000000000039e8 <dirtest>:
{
    39e8:	fe010113          	addi	sp,sp,-32
    39ec:	00113c23          	sd	ra,24(sp)
    39f0:	00813823          	sd	s0,16(sp)
    39f4:	00913423          	sd	s1,8(sp)
    39f8:	02010413          	addi	s0,sp,32
    39fc:	00050493          	mv	s1,a0
  if(mkdir("dir0") < 0){
    3a00:	00005517          	auipc	a0,0x5
    3a04:	9c050513          	addi	a0,a0,-1600 # 83c0 <malloc+0x1398>
    3a08:	6d9020ef          	jal	68e0 <mkdir>
    3a0c:	04054463          	bltz	a0,3a54 <dirtest+0x6c>
  if(chdir("dir0") < 0){
    3a10:	00005517          	auipc	a0,0x5
    3a14:	9b050513          	addi	a0,a0,-1616 # 83c0 <malloc+0x1398>
    3a18:	6d5020ef          	jal	68ec <chdir>
    3a1c:	04054863          	bltz	a0,3a6c <dirtest+0x84>
  if(chdir("..") < 0){
    3a20:	00005517          	auipc	a0,0x5
    3a24:	9c050513          	addi	a0,a0,-1600 # 83e0 <malloc+0x13b8>
    3a28:	6c5020ef          	jal	68ec <chdir>
    3a2c:	04054c63          	bltz	a0,3a84 <dirtest+0x9c>
  if(unlink("dir0") < 0){
    3a30:	00005517          	auipc	a0,0x5
    3a34:	99050513          	addi	a0,a0,-1648 # 83c0 <malloc+0x1398>
    3a38:	685020ef          	jal	68bc <unlink>
    3a3c:	06054063          	bltz	a0,3a9c <dirtest+0xb4>
}
    3a40:	01813083          	ld	ra,24(sp)
    3a44:	01013403          	ld	s0,16(sp)
    3a48:	00813483          	ld	s1,8(sp)
    3a4c:	02010113          	addi	sp,sp,32
    3a50:	00008067          	ret
    printf("%s: mkdir failed\n", s);
    3a54:	00048593          	mv	a1,s1
    3a58:	00005517          	auipc	a0,0x5
    3a5c:	8c850513          	addi	a0,a0,-1848 # 8320 <malloc+0x12f8>
    3a60:	4bc030ef          	jal	6f1c <printf>
    exit(1);
    3a64:	00100513          	li	a0,1
    3a68:	5dd020ef          	jal	6844 <exit>
    printf("%s: chdir dir0 failed\n", s);
    3a6c:	00048593          	mv	a1,s1
    3a70:	00005517          	auipc	a0,0x5
    3a74:	95850513          	addi	a0,a0,-1704 # 83c8 <malloc+0x13a0>
    3a78:	4a4030ef          	jal	6f1c <printf>
    exit(1);
    3a7c:	00100513          	li	a0,1
    3a80:	5c5020ef          	jal	6844 <exit>
    printf("%s: chdir .. failed\n", s);
    3a84:	00048593          	mv	a1,s1
    3a88:	00005517          	auipc	a0,0x5
    3a8c:	96050513          	addi	a0,a0,-1696 # 83e8 <malloc+0x13c0>
    3a90:	48c030ef          	jal	6f1c <printf>
    exit(1);
    3a94:	00100513          	li	a0,1
    3a98:	5ad020ef          	jal	6844 <exit>
    printf("%s: unlink dir0 failed\n", s);
    3a9c:	00048593          	mv	a1,s1
    3aa0:	00005517          	auipc	a0,0x5
    3aa4:	96050513          	addi	a0,a0,-1696 # 8400 <malloc+0x13d8>
    3aa8:	474030ef          	jal	6f1c <printf>
    exit(1);
    3aac:	00100513          	li	a0,1
    3ab0:	595020ef          	jal	6844 <exit>

0000000000003ab4 <subdir>:
{
    3ab4:	fe010113          	addi	sp,sp,-32
    3ab8:	00113c23          	sd	ra,24(sp)
    3abc:	00813823          	sd	s0,16(sp)
    3ac0:	00913423          	sd	s1,8(sp)
    3ac4:	01213023          	sd	s2,0(sp)
    3ac8:	02010413          	addi	s0,sp,32
    3acc:	00050913          	mv	s2,a0
  unlink("ff");
    3ad0:	00005517          	auipc	a0,0x5
    3ad4:	a7850513          	addi	a0,a0,-1416 # 8548 <malloc+0x1520>
    3ad8:	5e5020ef          	jal	68bc <unlink>
  if(mkdir("dd") != 0){
    3adc:	00005517          	auipc	a0,0x5
    3ae0:	93c50513          	addi	a0,a0,-1732 # 8418 <malloc+0x13f0>
    3ae4:	5fd020ef          	jal	68e0 <mkdir>
    3ae8:	30051c63          	bnez	a0,3e00 <subdir+0x34c>
  fd = open("dd/ff", O_CREATE | O_RDWR);
    3aec:	20200593          	li	a1,514
    3af0:	00005517          	auipc	a0,0x5
    3af4:	94850513          	addi	a0,a0,-1720 # 8438 <malloc+0x1410>
    3af8:	5ad020ef          	jal	68a4 <open>
    3afc:	00050493          	mv	s1,a0
  if(fd < 0){
    3b00:	30054c63          	bltz	a0,3e18 <subdir+0x364>
  write(fd, "ff", 2);
    3b04:	00200613          	li	a2,2
    3b08:	00005597          	auipc	a1,0x5
    3b0c:	a4058593          	addi	a1,a1,-1472 # 8548 <malloc+0x1520>
    3b10:	565020ef          	jal	6874 <write>
  close(fd);
    3b14:	00048513          	mv	a0,s1
    3b18:	569020ef          	jal	6880 <close>
  if(unlink("dd") >= 0){
    3b1c:	00005517          	auipc	a0,0x5
    3b20:	8fc50513          	addi	a0,a0,-1796 # 8418 <malloc+0x13f0>
    3b24:	599020ef          	jal	68bc <unlink>
    3b28:	30055463          	bgez	a0,3e30 <subdir+0x37c>
  if(mkdir("/dd/dd") != 0){
    3b2c:	00005517          	auipc	a0,0x5
    3b30:	96450513          	addi	a0,a0,-1692 # 8490 <malloc+0x1468>
    3b34:	5ad020ef          	jal	68e0 <mkdir>
    3b38:	30051863          	bnez	a0,3e48 <subdir+0x394>
  fd = open("dd/dd/ff", O_CREATE | O_RDWR);
    3b3c:	20200593          	li	a1,514
    3b40:	00005517          	auipc	a0,0x5
    3b44:	97850513          	addi	a0,a0,-1672 # 84b8 <malloc+0x1490>
    3b48:	55d020ef          	jal	68a4 <open>
    3b4c:	00050493          	mv	s1,a0
  if(fd < 0){
    3b50:	30054863          	bltz	a0,3e60 <subdir+0x3ac>
  write(fd, "FF", 2);
    3b54:	00200613          	li	a2,2
    3b58:	00005597          	auipc	a1,0x5
    3b5c:	99058593          	addi	a1,a1,-1648 # 84e8 <malloc+0x14c0>
    3b60:	515020ef          	jal	6874 <write>
  close(fd);
    3b64:	00048513          	mv	a0,s1
    3b68:	519020ef          	jal	6880 <close>
  fd = open("dd/dd/../ff", 0);
    3b6c:	00000593          	li	a1,0
    3b70:	00005517          	auipc	a0,0x5
    3b74:	98050513          	addi	a0,a0,-1664 # 84f0 <malloc+0x14c8>
    3b78:	52d020ef          	jal	68a4 <open>
    3b7c:	00050493          	mv	s1,a0
  if(fd < 0){
    3b80:	2e054c63          	bltz	a0,3e78 <subdir+0x3c4>
  cc = read(fd, buf, sizeof(buf));
    3b84:	00003637          	lui	a2,0x3
    3b88:	0000a597          	auipc	a1,0xa
    3b8c:	13058593          	addi	a1,a1,304 # dcb8 <buf>
    3b90:	4d9020ef          	jal	6868 <read>
  if(cc != 2 || buf[0] != 'f'){
    3b94:	00200793          	li	a5,2
    3b98:	2ef51c63          	bne	a0,a5,3e90 <subdir+0x3dc>
    3b9c:	0000a717          	auipc	a4,0xa
    3ba0:	11c74703          	lbu	a4,284(a4) # dcb8 <buf>
    3ba4:	06600793          	li	a5,102
    3ba8:	2ef71463          	bne	a4,a5,3e90 <subdir+0x3dc>
  close(fd);
    3bac:	00048513          	mv	a0,s1
    3bb0:	4d1020ef          	jal	6880 <close>
  if(link("dd/dd/ff", "dd/dd/ffff") != 0){
    3bb4:	00005597          	auipc	a1,0x5
    3bb8:	98c58593          	addi	a1,a1,-1652 # 8540 <malloc+0x1518>
    3bbc:	00005517          	auipc	a0,0x5
    3bc0:	8fc50513          	addi	a0,a0,-1796 # 84b8 <malloc+0x1490>
    3bc4:	511020ef          	jal	68d4 <link>
    3bc8:	2e051063          	bnez	a0,3ea8 <subdir+0x3f4>
  if(unlink("dd/dd/ff") != 0){
    3bcc:	00005517          	auipc	a0,0x5
    3bd0:	8ec50513          	addi	a0,a0,-1812 # 84b8 <malloc+0x1490>
    3bd4:	4e9020ef          	jal	68bc <unlink>
    3bd8:	2e051463          	bnez	a0,3ec0 <subdir+0x40c>
  if(open("dd/dd/ff", O_RDONLY) >= 0){
    3bdc:	00000593          	li	a1,0
    3be0:	00005517          	auipc	a0,0x5
    3be4:	8d850513          	addi	a0,a0,-1832 # 84b8 <malloc+0x1490>
    3be8:	4bd020ef          	jal	68a4 <open>
    3bec:	2e055663          	bgez	a0,3ed8 <subdir+0x424>
  if(chdir("dd") != 0){
    3bf0:	00005517          	auipc	a0,0x5
    3bf4:	82850513          	addi	a0,a0,-2008 # 8418 <malloc+0x13f0>
    3bf8:	4f5020ef          	jal	68ec <chdir>
    3bfc:	2e051a63          	bnez	a0,3ef0 <subdir+0x43c>
  if(chdir("dd/../../dd") != 0){
    3c00:	00005517          	auipc	a0,0x5
    3c04:	9d850513          	addi	a0,a0,-1576 # 85d8 <malloc+0x15b0>
    3c08:	4e5020ef          	jal	68ec <chdir>
    3c0c:	2e051e63          	bnez	a0,3f08 <subdir+0x454>
  if(chdir("dd/../../../dd") != 0){
    3c10:	00005517          	auipc	a0,0x5
    3c14:	9f850513          	addi	a0,a0,-1544 # 8608 <malloc+0x15e0>
    3c18:	4d5020ef          	jal	68ec <chdir>
    3c1c:	30051263          	bnez	a0,3f20 <subdir+0x46c>
  if(chdir("./..") != 0){
    3c20:	00005517          	auipc	a0,0x5
    3c24:	a2050513          	addi	a0,a0,-1504 # 8640 <malloc+0x1618>
    3c28:	4c5020ef          	jal	68ec <chdir>
    3c2c:	30051663          	bnez	a0,3f38 <subdir+0x484>
  fd = open("dd/dd/ffff", 0);
    3c30:	00000593          	li	a1,0
    3c34:	00005517          	auipc	a0,0x5
    3c38:	90c50513          	addi	a0,a0,-1780 # 8540 <malloc+0x1518>
    3c3c:	469020ef          	jal	68a4 <open>
    3c40:	00050493          	mv	s1,a0
  if(fd < 0){
    3c44:	30054663          	bltz	a0,3f50 <subdir+0x49c>
  if(read(fd, buf, sizeof(buf)) != 2){
    3c48:	00003637          	lui	a2,0x3
    3c4c:	0000a597          	auipc	a1,0xa
    3c50:	06c58593          	addi	a1,a1,108 # dcb8 <buf>
    3c54:	415020ef          	jal	6868 <read>
    3c58:	00200793          	li	a5,2
    3c5c:	30f51663          	bne	a0,a5,3f68 <subdir+0x4b4>
  close(fd);
    3c60:	00048513          	mv	a0,s1
    3c64:	41d020ef          	jal	6880 <close>
  if(open("dd/dd/ff", O_RDONLY) >= 0){
    3c68:	00000593          	li	a1,0
    3c6c:	00005517          	auipc	a0,0x5
    3c70:	84c50513          	addi	a0,a0,-1972 # 84b8 <malloc+0x1490>
    3c74:	431020ef          	jal	68a4 <open>
    3c78:	30055463          	bgez	a0,3f80 <subdir+0x4cc>
  if(open("dd/ff/ff", O_CREATE|O_RDWR) >= 0){
    3c7c:	20200593          	li	a1,514
    3c80:	00005517          	auipc	a0,0x5
    3c84:	a5050513          	addi	a0,a0,-1456 # 86d0 <malloc+0x16a8>
    3c88:	41d020ef          	jal	68a4 <open>
    3c8c:	30055663          	bgez	a0,3f98 <subdir+0x4e4>
  if(open("dd/xx/ff", O_CREATE|O_RDWR) >= 0){
    3c90:	20200593          	li	a1,514
    3c94:	00005517          	auipc	a0,0x5
    3c98:	a6c50513          	addi	a0,a0,-1428 # 8700 <malloc+0x16d8>
    3c9c:	409020ef          	jal	68a4 <open>
    3ca0:	30055863          	bgez	a0,3fb0 <subdir+0x4fc>
  if(open("dd", O_CREATE) >= 0){
    3ca4:	20000593          	li	a1,512
    3ca8:	00004517          	auipc	a0,0x4
    3cac:	77050513          	addi	a0,a0,1904 # 8418 <malloc+0x13f0>
    3cb0:	3f5020ef          	jal	68a4 <open>
    3cb4:	30055a63          	bgez	a0,3fc8 <subdir+0x514>
  if(open("dd", O_RDWR) >= 0){
    3cb8:	00200593          	li	a1,2
    3cbc:	00004517          	auipc	a0,0x4
    3cc0:	75c50513          	addi	a0,a0,1884 # 8418 <malloc+0x13f0>
    3cc4:	3e1020ef          	jal	68a4 <open>
    3cc8:	30055c63          	bgez	a0,3fe0 <subdir+0x52c>
  if(open("dd", O_WRONLY) >= 0){
    3ccc:	00100593          	li	a1,1
    3cd0:	00004517          	auipc	a0,0x4
    3cd4:	74850513          	addi	a0,a0,1864 # 8418 <malloc+0x13f0>
    3cd8:	3cd020ef          	jal	68a4 <open>
    3cdc:	30055e63          	bgez	a0,3ff8 <subdir+0x544>
  if(link("dd/ff/ff", "dd/dd/xx") == 0){
    3ce0:	00005597          	auipc	a1,0x5
    3ce4:	ab058593          	addi	a1,a1,-1360 # 8790 <malloc+0x1768>
    3ce8:	00005517          	auipc	a0,0x5
    3cec:	9e850513          	addi	a0,a0,-1560 # 86d0 <malloc+0x16a8>
    3cf0:	3e5020ef          	jal	68d4 <link>
    3cf4:	30050e63          	beqz	a0,4010 <subdir+0x55c>
  if(link("dd/xx/ff", "dd/dd/xx") == 0){
    3cf8:	00005597          	auipc	a1,0x5
    3cfc:	a9858593          	addi	a1,a1,-1384 # 8790 <malloc+0x1768>
    3d00:	00005517          	auipc	a0,0x5
    3d04:	a0050513          	addi	a0,a0,-1536 # 8700 <malloc+0x16d8>
    3d08:	3cd020ef          	jal	68d4 <link>
    3d0c:	30050e63          	beqz	a0,4028 <subdir+0x574>
  if(link("dd/ff", "dd/dd/ffff") == 0){
    3d10:	00005597          	auipc	a1,0x5
    3d14:	83058593          	addi	a1,a1,-2000 # 8540 <malloc+0x1518>
    3d18:	00004517          	auipc	a0,0x4
    3d1c:	72050513          	addi	a0,a0,1824 # 8438 <malloc+0x1410>
    3d20:	3b5020ef          	jal	68d4 <link>
    3d24:	30050e63          	beqz	a0,4040 <subdir+0x58c>
  if(mkdir("dd/ff/ff") == 0){
    3d28:	00005517          	auipc	a0,0x5
    3d2c:	9a850513          	addi	a0,a0,-1624 # 86d0 <malloc+0x16a8>
    3d30:	3b1020ef          	jal	68e0 <mkdir>
    3d34:	32050263          	beqz	a0,4058 <subdir+0x5a4>
  if(mkdir("dd/xx/ff") == 0){
    3d38:	00005517          	auipc	a0,0x5
    3d3c:	9c850513          	addi	a0,a0,-1592 # 8700 <malloc+0x16d8>
    3d40:	3a1020ef          	jal	68e0 <mkdir>
    3d44:	32050663          	beqz	a0,4070 <subdir+0x5bc>
  if(mkdir("dd/dd/ffff") == 0){
    3d48:	00004517          	auipc	a0,0x4
    3d4c:	7f850513          	addi	a0,a0,2040 # 8540 <malloc+0x1518>
    3d50:	391020ef          	jal	68e0 <mkdir>
    3d54:	32050a63          	beqz	a0,4088 <subdir+0x5d4>
  if(unlink("dd/xx/ff") == 0){
    3d58:	00005517          	auipc	a0,0x5
    3d5c:	9a850513          	addi	a0,a0,-1624 # 8700 <malloc+0x16d8>
    3d60:	35d020ef          	jal	68bc <unlink>
    3d64:	32050e63          	beqz	a0,40a0 <subdir+0x5ec>
  if(unlink("dd/ff/ff") == 0){
    3d68:	00005517          	auipc	a0,0x5
    3d6c:	96850513          	addi	a0,a0,-1688 # 86d0 <malloc+0x16a8>
    3d70:	34d020ef          	jal	68bc <unlink>
    3d74:	34050263          	beqz	a0,40b8 <subdir+0x604>
  if(chdir("dd/ff") == 0){
    3d78:	00004517          	auipc	a0,0x4
    3d7c:	6c050513          	addi	a0,a0,1728 # 8438 <malloc+0x1410>
    3d80:	36d020ef          	jal	68ec <chdir>
    3d84:	34050663          	beqz	a0,40d0 <subdir+0x61c>
  if(chdir("dd/xx") == 0){
    3d88:	00005517          	auipc	a0,0x5
    3d8c:	b5850513          	addi	a0,a0,-1192 # 88e0 <malloc+0x18b8>
    3d90:	35d020ef          	jal	68ec <chdir>
    3d94:	34050a63          	beqz	a0,40e8 <subdir+0x634>
  if(unlink("dd/dd/ffff") != 0){
    3d98:	00004517          	auipc	a0,0x4
    3d9c:	7a850513          	addi	a0,a0,1960 # 8540 <malloc+0x1518>
    3da0:	31d020ef          	jal	68bc <unlink>
    3da4:	34051e63          	bnez	a0,4100 <subdir+0x64c>
  if(unlink("dd/ff") != 0){
    3da8:	00004517          	auipc	a0,0x4
    3dac:	69050513          	addi	a0,a0,1680 # 8438 <malloc+0x1410>
    3db0:	30d020ef          	jal	68bc <unlink>
    3db4:	36051263          	bnez	a0,4118 <subdir+0x664>
  if(unlink("dd") == 0){
    3db8:	00004517          	auipc	a0,0x4
    3dbc:	66050513          	addi	a0,a0,1632 # 8418 <malloc+0x13f0>
    3dc0:	2fd020ef          	jal	68bc <unlink>
    3dc4:	36050663          	beqz	a0,4130 <subdir+0x67c>
  if(unlink("dd/dd") < 0){
    3dc8:	00005517          	auipc	a0,0x5
    3dcc:	b8850513          	addi	a0,a0,-1144 # 8950 <malloc+0x1928>
    3dd0:	2ed020ef          	jal	68bc <unlink>
    3dd4:	36054a63          	bltz	a0,4148 <subdir+0x694>
  if(unlink("dd") < 0){
    3dd8:	00004517          	auipc	a0,0x4
    3ddc:	64050513          	addi	a0,a0,1600 # 8418 <malloc+0x13f0>
    3de0:	2dd020ef          	jal	68bc <unlink>
    3de4:	36054e63          	bltz	a0,4160 <subdir+0x6ac>
}
    3de8:	01813083          	ld	ra,24(sp)
    3dec:	01013403          	ld	s0,16(sp)
    3df0:	00813483          	ld	s1,8(sp)
    3df4:	00013903          	ld	s2,0(sp)
    3df8:	02010113          	addi	sp,sp,32
    3dfc:	00008067          	ret
    printf("%s: mkdir dd failed\n", s);
    3e00:	00090593          	mv	a1,s2
    3e04:	00004517          	auipc	a0,0x4
    3e08:	61c50513          	addi	a0,a0,1564 # 8420 <malloc+0x13f8>
    3e0c:	110030ef          	jal	6f1c <printf>
    exit(1);
    3e10:	00100513          	li	a0,1
    3e14:	231020ef          	jal	6844 <exit>
    printf("%s: create dd/ff failed\n", s);
    3e18:	00090593          	mv	a1,s2
    3e1c:	00004517          	auipc	a0,0x4
    3e20:	62450513          	addi	a0,a0,1572 # 8440 <malloc+0x1418>
    3e24:	0f8030ef          	jal	6f1c <printf>
    exit(1);
    3e28:	00100513          	li	a0,1
    3e2c:	219020ef          	jal	6844 <exit>
    printf("%s: unlink dd (non-empty dir) succeeded!\n", s);
    3e30:	00090593          	mv	a1,s2
    3e34:	00004517          	auipc	a0,0x4
    3e38:	62c50513          	addi	a0,a0,1580 # 8460 <malloc+0x1438>
    3e3c:	0e0030ef          	jal	6f1c <printf>
    exit(1);
    3e40:	00100513          	li	a0,1
    3e44:	201020ef          	jal	6844 <exit>
    printf("%s: subdir mkdir dd/dd failed\n", s);
    3e48:	00090593          	mv	a1,s2
    3e4c:	00004517          	auipc	a0,0x4
    3e50:	64c50513          	addi	a0,a0,1612 # 8498 <malloc+0x1470>
    3e54:	0c8030ef          	jal	6f1c <printf>
    exit(1);
    3e58:	00100513          	li	a0,1
    3e5c:	1e9020ef          	jal	6844 <exit>
    printf("%s: create dd/dd/ff failed\n", s);
    3e60:	00090593          	mv	a1,s2
    3e64:	00004517          	auipc	a0,0x4
    3e68:	66450513          	addi	a0,a0,1636 # 84c8 <malloc+0x14a0>
    3e6c:	0b0030ef          	jal	6f1c <printf>
    exit(1);
    3e70:	00100513          	li	a0,1
    3e74:	1d1020ef          	jal	6844 <exit>
    printf("%s: open dd/dd/../ff failed\n", s);
    3e78:	00090593          	mv	a1,s2
    3e7c:	00004517          	auipc	a0,0x4
    3e80:	68450513          	addi	a0,a0,1668 # 8500 <malloc+0x14d8>
    3e84:	098030ef          	jal	6f1c <printf>
    exit(1);
    3e88:	00100513          	li	a0,1
    3e8c:	1b9020ef          	jal	6844 <exit>
    printf("%s: dd/dd/../ff wrong content\n", s);
    3e90:	00090593          	mv	a1,s2
    3e94:	00004517          	auipc	a0,0x4
    3e98:	68c50513          	addi	a0,a0,1676 # 8520 <malloc+0x14f8>
    3e9c:	080030ef          	jal	6f1c <printf>
    exit(1);
    3ea0:	00100513          	li	a0,1
    3ea4:	1a1020ef          	jal	6844 <exit>
    printf("%s: link dd/dd/ff dd/dd/ffff failed\n", s);
    3ea8:	00090593          	mv	a1,s2
    3eac:	00004517          	auipc	a0,0x4
    3eb0:	6a450513          	addi	a0,a0,1700 # 8550 <malloc+0x1528>
    3eb4:	068030ef          	jal	6f1c <printf>
    exit(1);
    3eb8:	00100513          	li	a0,1
    3ebc:	189020ef          	jal	6844 <exit>
    printf("%s: unlink dd/dd/ff failed\n", s);
    3ec0:	00090593          	mv	a1,s2
    3ec4:	00004517          	auipc	a0,0x4
    3ec8:	6b450513          	addi	a0,a0,1716 # 8578 <malloc+0x1550>
    3ecc:	050030ef          	jal	6f1c <printf>
    exit(1);
    3ed0:	00100513          	li	a0,1
    3ed4:	171020ef          	jal	6844 <exit>
    printf("%s: open (unlinked) dd/dd/ff succeeded\n", s);
    3ed8:	00090593          	mv	a1,s2
    3edc:	00004517          	auipc	a0,0x4
    3ee0:	6bc50513          	addi	a0,a0,1724 # 8598 <malloc+0x1570>
    3ee4:	038030ef          	jal	6f1c <printf>
    exit(1);
    3ee8:	00100513          	li	a0,1
    3eec:	159020ef          	jal	6844 <exit>
    printf("%s: chdir dd failed\n", s);
    3ef0:	00090593          	mv	a1,s2
    3ef4:	00004517          	auipc	a0,0x4
    3ef8:	6cc50513          	addi	a0,a0,1740 # 85c0 <malloc+0x1598>
    3efc:	020030ef          	jal	6f1c <printf>
    exit(1);
    3f00:	00100513          	li	a0,1
    3f04:	141020ef          	jal	6844 <exit>
    printf("%s: chdir dd/../../dd failed\n", s);
    3f08:	00090593          	mv	a1,s2
    3f0c:	00004517          	auipc	a0,0x4
    3f10:	6dc50513          	addi	a0,a0,1756 # 85e8 <malloc+0x15c0>
    3f14:	008030ef          	jal	6f1c <printf>
    exit(1);
    3f18:	00100513          	li	a0,1
    3f1c:	129020ef          	jal	6844 <exit>
    printf("%s: chdir dd/../../../dd failed\n", s);
    3f20:	00090593          	mv	a1,s2
    3f24:	00004517          	auipc	a0,0x4
    3f28:	6f450513          	addi	a0,a0,1780 # 8618 <malloc+0x15f0>
    3f2c:	7f1020ef          	jal	6f1c <printf>
    exit(1);
    3f30:	00100513          	li	a0,1
    3f34:	111020ef          	jal	6844 <exit>
    printf("%s: chdir ./.. failed\n", s);
    3f38:	00090593          	mv	a1,s2
    3f3c:	00004517          	auipc	a0,0x4
    3f40:	70c50513          	addi	a0,a0,1804 # 8648 <malloc+0x1620>
    3f44:	7d9020ef          	jal	6f1c <printf>
    exit(1);
    3f48:	00100513          	li	a0,1
    3f4c:	0f9020ef          	jal	6844 <exit>
    printf("%s: open dd/dd/ffff failed\n", s);
    3f50:	00090593          	mv	a1,s2
    3f54:	00004517          	auipc	a0,0x4
    3f58:	70c50513          	addi	a0,a0,1804 # 8660 <malloc+0x1638>
    3f5c:	7c1020ef          	jal	6f1c <printf>
    exit(1);
    3f60:	00100513          	li	a0,1
    3f64:	0e1020ef          	jal	6844 <exit>
    printf("%s: read dd/dd/ffff wrong len\n", s);
    3f68:	00090593          	mv	a1,s2
    3f6c:	00004517          	auipc	a0,0x4
    3f70:	71450513          	addi	a0,a0,1812 # 8680 <malloc+0x1658>
    3f74:	7a9020ef          	jal	6f1c <printf>
    exit(1);
    3f78:	00100513          	li	a0,1
    3f7c:	0c9020ef          	jal	6844 <exit>
    printf("%s: open (unlinked) dd/dd/ff succeeded!\n", s);
    3f80:	00090593          	mv	a1,s2
    3f84:	00004517          	auipc	a0,0x4
    3f88:	71c50513          	addi	a0,a0,1820 # 86a0 <malloc+0x1678>
    3f8c:	791020ef          	jal	6f1c <printf>
    exit(1);
    3f90:	00100513          	li	a0,1
    3f94:	0b1020ef          	jal	6844 <exit>
    printf("%s: create dd/ff/ff succeeded!\n", s);
    3f98:	00090593          	mv	a1,s2
    3f9c:	00004517          	auipc	a0,0x4
    3fa0:	74450513          	addi	a0,a0,1860 # 86e0 <malloc+0x16b8>
    3fa4:	779020ef          	jal	6f1c <printf>
    exit(1);
    3fa8:	00100513          	li	a0,1
    3fac:	099020ef          	jal	6844 <exit>
    printf("%s: create dd/xx/ff succeeded!\n", s);
    3fb0:	00090593          	mv	a1,s2
    3fb4:	00004517          	auipc	a0,0x4
    3fb8:	75c50513          	addi	a0,a0,1884 # 8710 <malloc+0x16e8>
    3fbc:	761020ef          	jal	6f1c <printf>
    exit(1);
    3fc0:	00100513          	li	a0,1
    3fc4:	081020ef          	jal	6844 <exit>
    printf("%s: create dd succeeded!\n", s);
    3fc8:	00090593          	mv	a1,s2
    3fcc:	00004517          	auipc	a0,0x4
    3fd0:	76450513          	addi	a0,a0,1892 # 8730 <malloc+0x1708>
    3fd4:	749020ef          	jal	6f1c <printf>
    exit(1);
    3fd8:	00100513          	li	a0,1
    3fdc:	069020ef          	jal	6844 <exit>
    printf("%s: open dd rdwr succeeded!\n", s);
    3fe0:	00090593          	mv	a1,s2
    3fe4:	00004517          	auipc	a0,0x4
    3fe8:	76c50513          	addi	a0,a0,1900 # 8750 <malloc+0x1728>
    3fec:	731020ef          	jal	6f1c <printf>
    exit(1);
    3ff0:	00100513          	li	a0,1
    3ff4:	051020ef          	jal	6844 <exit>
    printf("%s: open dd wronly succeeded!\n", s);
    3ff8:	00090593          	mv	a1,s2
    3ffc:	00004517          	auipc	a0,0x4
    4000:	77450513          	addi	a0,a0,1908 # 8770 <malloc+0x1748>
    4004:	719020ef          	jal	6f1c <printf>
    exit(1);
    4008:	00100513          	li	a0,1
    400c:	039020ef          	jal	6844 <exit>
    printf("%s: link dd/ff/ff dd/dd/xx succeeded!\n", s);
    4010:	00090593          	mv	a1,s2
    4014:	00004517          	auipc	a0,0x4
    4018:	78c50513          	addi	a0,a0,1932 # 87a0 <malloc+0x1778>
    401c:	701020ef          	jal	6f1c <printf>
    exit(1);
    4020:	00100513          	li	a0,1
    4024:	021020ef          	jal	6844 <exit>
    printf("%s: link dd/xx/ff dd/dd/xx succeeded!\n", s);
    4028:	00090593          	mv	a1,s2
    402c:	00004517          	auipc	a0,0x4
    4030:	79c50513          	addi	a0,a0,1948 # 87c8 <malloc+0x17a0>
    4034:	6e9020ef          	jal	6f1c <printf>
    exit(1);
    4038:	00100513          	li	a0,1
    403c:	009020ef          	jal	6844 <exit>
    printf("%s: link dd/ff dd/dd/ffff succeeded!\n", s);
    4040:	00090593          	mv	a1,s2
    4044:	00004517          	auipc	a0,0x4
    4048:	7ac50513          	addi	a0,a0,1964 # 87f0 <malloc+0x17c8>
    404c:	6d1020ef          	jal	6f1c <printf>
    exit(1);
    4050:	00100513          	li	a0,1
    4054:	7f0020ef          	jal	6844 <exit>
    printf("%s: mkdir dd/ff/ff succeeded!\n", s);
    4058:	00090593          	mv	a1,s2
    405c:	00004517          	auipc	a0,0x4
    4060:	7bc50513          	addi	a0,a0,1980 # 8818 <malloc+0x17f0>
    4064:	6b9020ef          	jal	6f1c <printf>
    exit(1);
    4068:	00100513          	li	a0,1
    406c:	7d8020ef          	jal	6844 <exit>
    printf("%s: mkdir dd/xx/ff succeeded!\n", s);
    4070:	00090593          	mv	a1,s2
    4074:	00004517          	auipc	a0,0x4
    4078:	7c450513          	addi	a0,a0,1988 # 8838 <malloc+0x1810>
    407c:	6a1020ef          	jal	6f1c <printf>
    exit(1);
    4080:	00100513          	li	a0,1
    4084:	7c0020ef          	jal	6844 <exit>
    printf("%s: mkdir dd/dd/ffff succeeded!\n", s);
    4088:	00090593          	mv	a1,s2
    408c:	00004517          	auipc	a0,0x4
    4090:	7cc50513          	addi	a0,a0,1996 # 8858 <malloc+0x1830>
    4094:	689020ef          	jal	6f1c <printf>
    exit(1);
    4098:	00100513          	li	a0,1
    409c:	7a8020ef          	jal	6844 <exit>
    printf("%s: unlink dd/xx/ff succeeded!\n", s);
    40a0:	00090593          	mv	a1,s2
    40a4:	00004517          	auipc	a0,0x4
    40a8:	7dc50513          	addi	a0,a0,2012 # 8880 <malloc+0x1858>
    40ac:	671020ef          	jal	6f1c <printf>
    exit(1);
    40b0:	00100513          	li	a0,1
    40b4:	790020ef          	jal	6844 <exit>
    printf("%s: unlink dd/ff/ff succeeded!\n", s);
    40b8:	00090593          	mv	a1,s2
    40bc:	00004517          	auipc	a0,0x4
    40c0:	7e450513          	addi	a0,a0,2020 # 88a0 <malloc+0x1878>
    40c4:	659020ef          	jal	6f1c <printf>
    exit(1);
    40c8:	00100513          	li	a0,1
    40cc:	778020ef          	jal	6844 <exit>
    printf("%s: chdir dd/ff succeeded!\n", s);
    40d0:	00090593          	mv	a1,s2
    40d4:	00004517          	auipc	a0,0x4
    40d8:	7ec50513          	addi	a0,a0,2028 # 88c0 <malloc+0x1898>
    40dc:	641020ef          	jal	6f1c <printf>
    exit(1);
    40e0:	00100513          	li	a0,1
    40e4:	760020ef          	jal	6844 <exit>
    printf("%s: chdir dd/xx succeeded!\n", s);
    40e8:	00090593          	mv	a1,s2
    40ec:	00004517          	auipc	a0,0x4
    40f0:	7fc50513          	addi	a0,a0,2044 # 88e8 <malloc+0x18c0>
    40f4:	629020ef          	jal	6f1c <printf>
    exit(1);
    40f8:	00100513          	li	a0,1
    40fc:	748020ef          	jal	6844 <exit>
    printf("%s: unlink dd/dd/ff failed\n", s);
    4100:	00090593          	mv	a1,s2
    4104:	00004517          	auipc	a0,0x4
    4108:	47450513          	addi	a0,a0,1140 # 8578 <malloc+0x1550>
    410c:	611020ef          	jal	6f1c <printf>
    exit(1);
    4110:	00100513          	li	a0,1
    4114:	730020ef          	jal	6844 <exit>
    printf("%s: unlink dd/ff failed\n", s);
    4118:	00090593          	mv	a1,s2
    411c:	00004517          	auipc	a0,0x4
    4120:	7ec50513          	addi	a0,a0,2028 # 8908 <malloc+0x18e0>
    4124:	5f9020ef          	jal	6f1c <printf>
    exit(1);
    4128:	00100513          	li	a0,1
    412c:	718020ef          	jal	6844 <exit>
    printf("%s: unlink non-empty dd succeeded!\n", s);
    4130:	00090593          	mv	a1,s2
    4134:	00004517          	auipc	a0,0x4
    4138:	7f450513          	addi	a0,a0,2036 # 8928 <malloc+0x1900>
    413c:	5e1020ef          	jal	6f1c <printf>
    exit(1);
    4140:	00100513          	li	a0,1
    4144:	700020ef          	jal	6844 <exit>
    printf("%s: unlink dd/dd failed\n", s);
    4148:	00090593          	mv	a1,s2
    414c:	00005517          	auipc	a0,0x5
    4150:	80c50513          	addi	a0,a0,-2036 # 8958 <malloc+0x1930>
    4154:	5c9020ef          	jal	6f1c <printf>
    exit(1);
    4158:	00100513          	li	a0,1
    415c:	6e8020ef          	jal	6844 <exit>
    printf("%s: unlink dd failed\n", s);
    4160:	00090593          	mv	a1,s2
    4164:	00005517          	auipc	a0,0x5
    4168:	81450513          	addi	a0,a0,-2028 # 8978 <malloc+0x1950>
    416c:	5b1020ef          	jal	6f1c <printf>
    exit(1);
    4170:	00100513          	li	a0,1
    4174:	6d0020ef          	jal	6844 <exit>

0000000000004178 <rmdot>:
{
    4178:	fe010113          	addi	sp,sp,-32
    417c:	00113c23          	sd	ra,24(sp)
    4180:	00813823          	sd	s0,16(sp)
    4184:	00913423          	sd	s1,8(sp)
    4188:	02010413          	addi	s0,sp,32
    418c:	00050493          	mv	s1,a0
  if(mkdir("dots") != 0){
    4190:	00005517          	auipc	a0,0x5
    4194:	80050513          	addi	a0,a0,-2048 # 8990 <malloc+0x1968>
    4198:	748020ef          	jal	68e0 <mkdir>
    419c:	08051463          	bnez	a0,4224 <rmdot+0xac>
  if(chdir("dots") != 0){
    41a0:	00004517          	auipc	a0,0x4
    41a4:	7f050513          	addi	a0,a0,2032 # 8990 <malloc+0x1968>
    41a8:	744020ef          	jal	68ec <chdir>
    41ac:	08051863          	bnez	a0,423c <rmdot+0xc4>
  if(unlink(".") == 0){
    41b0:	00003517          	auipc	a0,0x3
    41b4:	71050513          	addi	a0,a0,1808 # 78c0 <malloc+0x898>
    41b8:	704020ef          	jal	68bc <unlink>
    41bc:	08050c63          	beqz	a0,4254 <rmdot+0xdc>
  if(unlink("..") == 0){
    41c0:	00004517          	auipc	a0,0x4
    41c4:	22050513          	addi	a0,a0,544 # 83e0 <malloc+0x13b8>
    41c8:	6f4020ef          	jal	68bc <unlink>
    41cc:	0a050063          	beqz	a0,426c <rmdot+0xf4>
  if(chdir("/") != 0){
    41d0:	00004517          	auipc	a0,0x4
    41d4:	1b850513          	addi	a0,a0,440 # 8388 <malloc+0x1360>
    41d8:	714020ef          	jal	68ec <chdir>
    41dc:	0a051463          	bnez	a0,4284 <rmdot+0x10c>
  if(unlink("dots/.") == 0){
    41e0:	00005517          	auipc	a0,0x5
    41e4:	81850513          	addi	a0,a0,-2024 # 89f8 <malloc+0x19d0>
    41e8:	6d4020ef          	jal	68bc <unlink>
    41ec:	0a050863          	beqz	a0,429c <rmdot+0x124>
  if(unlink("dots/..") == 0){
    41f0:	00005517          	auipc	a0,0x5
    41f4:	83050513          	addi	a0,a0,-2000 # 8a20 <malloc+0x19f8>
    41f8:	6c4020ef          	jal	68bc <unlink>
    41fc:	0a050c63          	beqz	a0,42b4 <rmdot+0x13c>
  if(unlink("dots") != 0){
    4200:	00004517          	auipc	a0,0x4
    4204:	79050513          	addi	a0,a0,1936 # 8990 <malloc+0x1968>
    4208:	6b4020ef          	jal	68bc <unlink>
    420c:	0c051063          	bnez	a0,42cc <rmdot+0x154>
}
    4210:	01813083          	ld	ra,24(sp)
    4214:	01013403          	ld	s0,16(sp)
    4218:	00813483          	ld	s1,8(sp)
    421c:	02010113          	addi	sp,sp,32
    4220:	00008067          	ret
    printf("%s: mkdir dots failed\n", s);
    4224:	00048593          	mv	a1,s1
    4228:	00004517          	auipc	a0,0x4
    422c:	77050513          	addi	a0,a0,1904 # 8998 <malloc+0x1970>
    4230:	4ed020ef          	jal	6f1c <printf>
    exit(1);
    4234:	00100513          	li	a0,1
    4238:	60c020ef          	jal	6844 <exit>
    printf("%s: chdir dots failed\n", s);
    423c:	00048593          	mv	a1,s1
    4240:	00004517          	auipc	a0,0x4
    4244:	77050513          	addi	a0,a0,1904 # 89b0 <malloc+0x1988>
    4248:	4d5020ef          	jal	6f1c <printf>
    exit(1);
    424c:	00100513          	li	a0,1
    4250:	5f4020ef          	jal	6844 <exit>
    printf("%s: rm . worked!\n", s);
    4254:	00048593          	mv	a1,s1
    4258:	00004517          	auipc	a0,0x4
    425c:	77050513          	addi	a0,a0,1904 # 89c8 <malloc+0x19a0>
    4260:	4bd020ef          	jal	6f1c <printf>
    exit(1);
    4264:	00100513          	li	a0,1
    4268:	5dc020ef          	jal	6844 <exit>
    printf("%s: rm .. worked!\n", s);
    426c:	00048593          	mv	a1,s1
    4270:	00004517          	auipc	a0,0x4
    4274:	77050513          	addi	a0,a0,1904 # 89e0 <malloc+0x19b8>
    4278:	4a5020ef          	jal	6f1c <printf>
    exit(1);
    427c:	00100513          	li	a0,1
    4280:	5c4020ef          	jal	6844 <exit>
    printf("%s: chdir / failed\n", s);
    4284:	00048593          	mv	a1,s1
    4288:	00004517          	auipc	a0,0x4
    428c:	10850513          	addi	a0,a0,264 # 8390 <malloc+0x1368>
    4290:	48d020ef          	jal	6f1c <printf>
    exit(1);
    4294:	00100513          	li	a0,1
    4298:	5ac020ef          	jal	6844 <exit>
    printf("%s: unlink dots/. worked!\n", s);
    429c:	00048593          	mv	a1,s1
    42a0:	00004517          	auipc	a0,0x4
    42a4:	76050513          	addi	a0,a0,1888 # 8a00 <malloc+0x19d8>
    42a8:	475020ef          	jal	6f1c <printf>
    exit(1);
    42ac:	00100513          	li	a0,1
    42b0:	594020ef          	jal	6844 <exit>
    printf("%s: unlink dots/.. worked!\n", s);
    42b4:	00048593          	mv	a1,s1
    42b8:	00004517          	auipc	a0,0x4
    42bc:	77050513          	addi	a0,a0,1904 # 8a28 <malloc+0x1a00>
    42c0:	45d020ef          	jal	6f1c <printf>
    exit(1);
    42c4:	00100513          	li	a0,1
    42c8:	57c020ef          	jal	6844 <exit>
    printf("%s: unlink dots failed!\n", s);
    42cc:	00048593          	mv	a1,s1
    42d0:	00004517          	auipc	a0,0x4
    42d4:	77850513          	addi	a0,a0,1912 # 8a48 <malloc+0x1a20>
    42d8:	445020ef          	jal	6f1c <printf>
    exit(1);
    42dc:	00100513          	li	a0,1
    42e0:	564020ef          	jal	6844 <exit>

00000000000042e4 <dirfile>:
{
    42e4:	fe010113          	addi	sp,sp,-32
    42e8:	00113c23          	sd	ra,24(sp)
    42ec:	00813823          	sd	s0,16(sp)
    42f0:	00913423          	sd	s1,8(sp)
    42f4:	01213023          	sd	s2,0(sp)
    42f8:	02010413          	addi	s0,sp,32
    42fc:	00050913          	mv	s2,a0
  fd = open("dirfile", O_CREATE);
    4300:	20000593          	li	a1,512
    4304:	00004517          	auipc	a0,0x4
    4308:	76450513          	addi	a0,a0,1892 # 8a68 <malloc+0x1a40>
    430c:	598020ef          	jal	68a4 <open>
  if(fd < 0){
    4310:	0e054263          	bltz	a0,43f4 <dirfile+0x110>
  close(fd);
    4314:	56c020ef          	jal	6880 <close>
  if(chdir("dirfile") == 0){
    4318:	00004517          	auipc	a0,0x4
    431c:	75050513          	addi	a0,a0,1872 # 8a68 <malloc+0x1a40>
    4320:	5cc020ef          	jal	68ec <chdir>
    4324:	0e050463          	beqz	a0,440c <dirfile+0x128>
  fd = open("dirfile/xx", 0);
    4328:	00000593          	li	a1,0
    432c:	00004517          	auipc	a0,0x4
    4330:	78450513          	addi	a0,a0,1924 # 8ab0 <malloc+0x1a88>
    4334:	570020ef          	jal	68a4 <open>
  if(fd >= 0){
    4338:	0e055663          	bgez	a0,4424 <dirfile+0x140>
  fd = open("dirfile/xx", O_CREATE);
    433c:	20000593          	li	a1,512
    4340:	00004517          	auipc	a0,0x4
    4344:	77050513          	addi	a0,a0,1904 # 8ab0 <malloc+0x1a88>
    4348:	55c020ef          	jal	68a4 <open>
  if(fd >= 0){
    434c:	0e055863          	bgez	a0,443c <dirfile+0x158>
  if(mkdir("dirfile/xx") == 0){
    4350:	00004517          	auipc	a0,0x4
    4354:	76050513          	addi	a0,a0,1888 # 8ab0 <malloc+0x1a88>
    4358:	588020ef          	jal	68e0 <mkdir>
    435c:	0e050c63          	beqz	a0,4454 <dirfile+0x170>
  if(unlink("dirfile/xx") == 0){
    4360:	00004517          	auipc	a0,0x4
    4364:	75050513          	addi	a0,a0,1872 # 8ab0 <malloc+0x1a88>
    4368:	554020ef          	jal	68bc <unlink>
    436c:	10050063          	beqz	a0,446c <dirfile+0x188>
  if(link("README", "dirfile/xx") == 0){
    4370:	00004597          	auipc	a1,0x4
    4374:	74058593          	addi	a1,a1,1856 # 8ab0 <malloc+0x1a88>
    4378:	00003517          	auipc	a0,0x3
    437c:	03850513          	addi	a0,a0,56 # 73b0 <malloc+0x388>
    4380:	554020ef          	jal	68d4 <link>
    4384:	10050063          	beqz	a0,4484 <dirfile+0x1a0>
  if(unlink("dirfile") != 0){
    4388:	00004517          	auipc	a0,0x4
    438c:	6e050513          	addi	a0,a0,1760 # 8a68 <malloc+0x1a40>
    4390:	52c020ef          	jal	68bc <unlink>
    4394:	10051463          	bnez	a0,449c <dirfile+0x1b8>
  fd = open(".", O_RDWR);
    4398:	00200593          	li	a1,2
    439c:	00003517          	auipc	a0,0x3
    43a0:	52450513          	addi	a0,a0,1316 # 78c0 <malloc+0x898>
    43a4:	500020ef          	jal	68a4 <open>
  if(fd >= 0){
    43a8:	10055663          	bgez	a0,44b4 <dirfile+0x1d0>
  fd = open(".", 0);
    43ac:	00000593          	li	a1,0
    43b0:	00003517          	auipc	a0,0x3
    43b4:	51050513          	addi	a0,a0,1296 # 78c0 <malloc+0x898>
    43b8:	4ec020ef          	jal	68a4 <open>
    43bc:	00050493          	mv	s1,a0
  if(write(fd, "x", 1) > 0){
    43c0:	00100613          	li	a2,1
    43c4:	00003597          	auipc	a1,0x3
    43c8:	e8458593          	addi	a1,a1,-380 # 7248 <malloc+0x220>
    43cc:	4a8020ef          	jal	6874 <write>
    43d0:	0ea04e63          	bgtz	a0,44cc <dirfile+0x1e8>
  close(fd);
    43d4:	00048513          	mv	a0,s1
    43d8:	4a8020ef          	jal	6880 <close>
}
    43dc:	01813083          	ld	ra,24(sp)
    43e0:	01013403          	ld	s0,16(sp)
    43e4:	00813483          	ld	s1,8(sp)
    43e8:	00013903          	ld	s2,0(sp)
    43ec:	02010113          	addi	sp,sp,32
    43f0:	00008067          	ret
    printf("%s: create dirfile failed\n", s);
    43f4:	00090593          	mv	a1,s2
    43f8:	00004517          	auipc	a0,0x4
    43fc:	67850513          	addi	a0,a0,1656 # 8a70 <malloc+0x1a48>
    4400:	31d020ef          	jal	6f1c <printf>
    exit(1);
    4404:	00100513          	li	a0,1
    4408:	43c020ef          	jal	6844 <exit>
    printf("%s: chdir dirfile succeeded!\n", s);
    440c:	00090593          	mv	a1,s2
    4410:	00004517          	auipc	a0,0x4
    4414:	68050513          	addi	a0,a0,1664 # 8a90 <malloc+0x1a68>
    4418:	305020ef          	jal	6f1c <printf>
    exit(1);
    441c:	00100513          	li	a0,1
    4420:	424020ef          	jal	6844 <exit>
    printf("%s: create dirfile/xx succeeded!\n", s);
    4424:	00090593          	mv	a1,s2
    4428:	00004517          	auipc	a0,0x4
    442c:	69850513          	addi	a0,a0,1688 # 8ac0 <malloc+0x1a98>
    4430:	2ed020ef          	jal	6f1c <printf>
    exit(1);
    4434:	00100513          	li	a0,1
    4438:	40c020ef          	jal	6844 <exit>
    printf("%s: create dirfile/xx succeeded!\n", s);
    443c:	00090593          	mv	a1,s2
    4440:	00004517          	auipc	a0,0x4
    4444:	68050513          	addi	a0,a0,1664 # 8ac0 <malloc+0x1a98>
    4448:	2d5020ef          	jal	6f1c <printf>
    exit(1);
    444c:	00100513          	li	a0,1
    4450:	3f4020ef          	jal	6844 <exit>
    printf("%s: mkdir dirfile/xx succeeded!\n", s);
    4454:	00090593          	mv	a1,s2
    4458:	00004517          	auipc	a0,0x4
    445c:	69050513          	addi	a0,a0,1680 # 8ae8 <malloc+0x1ac0>
    4460:	2bd020ef          	jal	6f1c <printf>
    exit(1);
    4464:	00100513          	li	a0,1
    4468:	3dc020ef          	jal	6844 <exit>
    printf("%s: unlink dirfile/xx succeeded!\n", s);
    446c:	00090593          	mv	a1,s2
    4470:	00004517          	auipc	a0,0x4
    4474:	6a050513          	addi	a0,a0,1696 # 8b10 <malloc+0x1ae8>
    4478:	2a5020ef          	jal	6f1c <printf>
    exit(1);
    447c:	00100513          	li	a0,1
    4480:	3c4020ef          	jal	6844 <exit>
    printf("%s: link to dirfile/xx succeeded!\n", s);
    4484:	00090593          	mv	a1,s2
    4488:	00004517          	auipc	a0,0x4
    448c:	6b050513          	addi	a0,a0,1712 # 8b38 <malloc+0x1b10>
    4490:	28d020ef          	jal	6f1c <printf>
    exit(1);
    4494:	00100513          	li	a0,1
    4498:	3ac020ef          	jal	6844 <exit>
    printf("%s: unlink dirfile failed!\n", s);
    449c:	00090593          	mv	a1,s2
    44a0:	00004517          	auipc	a0,0x4
    44a4:	6c050513          	addi	a0,a0,1728 # 8b60 <malloc+0x1b38>
    44a8:	275020ef          	jal	6f1c <printf>
    exit(1);
    44ac:	00100513          	li	a0,1
    44b0:	394020ef          	jal	6844 <exit>
    printf("%s: open . for writing succeeded!\n", s);
    44b4:	00090593          	mv	a1,s2
    44b8:	00004517          	auipc	a0,0x4
    44bc:	6c850513          	addi	a0,a0,1736 # 8b80 <malloc+0x1b58>
    44c0:	25d020ef          	jal	6f1c <printf>
    exit(1);
    44c4:	00100513          	li	a0,1
    44c8:	37c020ef          	jal	6844 <exit>
    printf("%s: write . succeeded!\n", s);
    44cc:	00090593          	mv	a1,s2
    44d0:	00004517          	auipc	a0,0x4
    44d4:	6d850513          	addi	a0,a0,1752 # 8ba8 <malloc+0x1b80>
    44d8:	245020ef          	jal	6f1c <printf>
    exit(1);
    44dc:	00100513          	li	a0,1
    44e0:	364020ef          	jal	6844 <exit>

00000000000044e4 <iref>:
{
    44e4:	fb010113          	addi	sp,sp,-80
    44e8:	04113423          	sd	ra,72(sp)
    44ec:	04813023          	sd	s0,64(sp)
    44f0:	02913c23          	sd	s1,56(sp)
    44f4:	03213823          	sd	s2,48(sp)
    44f8:	03313423          	sd	s3,40(sp)
    44fc:	03413023          	sd	s4,32(sp)
    4500:	01513c23          	sd	s5,24(sp)
    4504:	01613823          	sd	s6,16(sp)
    4508:	01713423          	sd	s7,8(sp)
    450c:	05010413          	addi	s0,sp,80
    4510:	00050b93          	mv	s7,a0
    4514:	03300913          	li	s2,51
    if(mkdir("irefd") != 0){
    4518:	00004a97          	auipc	s5,0x4
    451c:	6a8a8a93          	addi	s5,s5,1704 # 8bc0 <malloc+0x1b98>
    mkdir("");
    4520:	00004497          	auipc	s1,0x4
    4524:	1a848493          	addi	s1,s1,424 # 86c8 <malloc+0x16a0>
    link("README", "");
    4528:	00003b17          	auipc	s6,0x3
    452c:	e88b0b13          	addi	s6,s6,-376 # 73b0 <malloc+0x388>
    fd = open("", O_CREATE);
    4530:	20000a13          	li	s4,512
    fd = open("xx", O_CREATE);
    4534:	00004997          	auipc	s3,0x4
    4538:	58498993          	addi	s3,s3,1412 # 8ab8 <malloc+0x1a90>
    453c:	04c0006f          	j	4588 <iref+0xa4>
      printf("%s: mkdir irefd failed\n", s);
    4540:	000b8593          	mv	a1,s7
    4544:	00004517          	auipc	a0,0x4
    4548:	68450513          	addi	a0,a0,1668 # 8bc8 <malloc+0x1ba0>
    454c:	1d1020ef          	jal	6f1c <printf>
      exit(1);
    4550:	00100513          	li	a0,1
    4554:	2f0020ef          	jal	6844 <exit>
      printf("%s: chdir irefd failed\n", s);
    4558:	000b8593          	mv	a1,s7
    455c:	00004517          	auipc	a0,0x4
    4560:	68450513          	addi	a0,a0,1668 # 8be0 <malloc+0x1bb8>
    4564:	1b9020ef          	jal	6f1c <printf>
      exit(1);
    4568:	00100513          	li	a0,1
    456c:	2d8020ef          	jal	6844 <exit>
      close(fd);
    4570:	310020ef          	jal	6880 <close>
    4574:	0500006f          	j	45c4 <iref+0xe0>
    unlink("xx");
    4578:	00098513          	mv	a0,s3
    457c:	340020ef          	jal	68bc <unlink>
  for(i = 0; i < NINODE + 1; i++){
    4580:	fff9091b          	addiw	s2,s2,-1
    4584:	04090c63          	beqz	s2,45dc <iref+0xf8>
    if(mkdir("irefd") != 0){
    4588:	000a8513          	mv	a0,s5
    458c:	354020ef          	jal	68e0 <mkdir>
    4590:	fa0518e3          	bnez	a0,4540 <iref+0x5c>
    if(chdir("irefd") != 0){
    4594:	000a8513          	mv	a0,s5
    4598:	354020ef          	jal	68ec <chdir>
    459c:	fa051ee3          	bnez	a0,4558 <iref+0x74>
    mkdir("");
    45a0:	00048513          	mv	a0,s1
    45a4:	33c020ef          	jal	68e0 <mkdir>
    link("README", "");
    45a8:	00048593          	mv	a1,s1
    45ac:	000b0513          	mv	a0,s6
    45b0:	324020ef          	jal	68d4 <link>
    fd = open("", O_CREATE);
    45b4:	000a0593          	mv	a1,s4
    45b8:	00048513          	mv	a0,s1
    45bc:	2e8020ef          	jal	68a4 <open>
    if(fd >= 0)
    45c0:	fa0558e3          	bgez	a0,4570 <iref+0x8c>
    fd = open("xx", O_CREATE);
    45c4:	000a0593          	mv	a1,s4
    45c8:	00098513          	mv	a0,s3
    45cc:	2d8020ef          	jal	68a4 <open>
    if(fd >= 0)
    45d0:	fa0544e3          	bltz	a0,4578 <iref+0x94>
      close(fd);
    45d4:	2ac020ef          	jal	6880 <close>
    45d8:	fa1ff06f          	j	4578 <iref+0x94>
    45dc:	03300493          	li	s1,51
    chdir("..");
    45e0:	00004997          	auipc	s3,0x4
    45e4:	e0098993          	addi	s3,s3,-512 # 83e0 <malloc+0x13b8>
    unlink("irefd");
    45e8:	00004917          	auipc	s2,0x4
    45ec:	5d890913          	addi	s2,s2,1496 # 8bc0 <malloc+0x1b98>
    chdir("..");
    45f0:	00098513          	mv	a0,s3
    45f4:	2f8020ef          	jal	68ec <chdir>
    unlink("irefd");
    45f8:	00090513          	mv	a0,s2
    45fc:	2c0020ef          	jal	68bc <unlink>
  for(i = 0; i < NINODE + 1; i++){
    4600:	fff4849b          	addiw	s1,s1,-1
    4604:	fe0496e3          	bnez	s1,45f0 <iref+0x10c>
  chdir("/");
    4608:	00004517          	auipc	a0,0x4
    460c:	d8050513          	addi	a0,a0,-640 # 8388 <malloc+0x1360>
    4610:	2dc020ef          	jal	68ec <chdir>
}
    4614:	04813083          	ld	ra,72(sp)
    4618:	04013403          	ld	s0,64(sp)
    461c:	03813483          	ld	s1,56(sp)
    4620:	03013903          	ld	s2,48(sp)
    4624:	02813983          	ld	s3,40(sp)
    4628:	02013a03          	ld	s4,32(sp)
    462c:	01813a83          	ld	s5,24(sp)
    4630:	01013b03          	ld	s6,16(sp)
    4634:	00813b83          	ld	s7,8(sp)
    4638:	05010113          	addi	sp,sp,80
    463c:	00008067          	ret

0000000000004640 <openiputtest>:
{
    4640:	fd010113          	addi	sp,sp,-48
    4644:	02113423          	sd	ra,40(sp)
    4648:	02813023          	sd	s0,32(sp)
    464c:	00913c23          	sd	s1,24(sp)
    4650:	03010413          	addi	s0,sp,48
    4654:	00050493          	mv	s1,a0
  if(mkdir("oidir") < 0){
    4658:	00004517          	auipc	a0,0x4
    465c:	5a050513          	addi	a0,a0,1440 # 8bf8 <malloc+0x1bd0>
    4660:	280020ef          	jal	68e0 <mkdir>
    4664:	02054e63          	bltz	a0,46a0 <openiputtest+0x60>
  pid = fork();
    4668:	1d0020ef          	jal	6838 <fork>
  if(pid < 0){
    466c:	04054663          	bltz	a0,46b8 <openiputtest+0x78>
  if(pid == 0){
    4670:	06051463          	bnez	a0,46d8 <openiputtest+0x98>
    int fd = open("oidir", O_RDWR);
    4674:	00200593          	li	a1,2
    4678:	00004517          	auipc	a0,0x4
    467c:	58050513          	addi	a0,a0,1408 # 8bf8 <malloc+0x1bd0>
    4680:	224020ef          	jal	68a4 <open>
    if(fd >= 0){
    4684:	04054663          	bltz	a0,46d0 <openiputtest+0x90>
      printf("%s: open directory for write succeeded\n", s);
    4688:	00048593          	mv	a1,s1
    468c:	00004517          	auipc	a0,0x4
    4690:	58c50513          	addi	a0,a0,1420 # 8c18 <malloc+0x1bf0>
    4694:	089020ef          	jal	6f1c <printf>
      exit(1);
    4698:	00100513          	li	a0,1
    469c:	1a8020ef          	jal	6844 <exit>
    printf("%s: mkdir oidir failed\n", s);
    46a0:	00048593          	mv	a1,s1
    46a4:	00004517          	auipc	a0,0x4
    46a8:	55c50513          	addi	a0,a0,1372 # 8c00 <malloc+0x1bd8>
    46ac:	071020ef          	jal	6f1c <printf>
    exit(1);
    46b0:	00100513          	li	a0,1
    46b4:	190020ef          	jal	6844 <exit>
    printf("%s: fork failed\n", s);
    46b8:	00048593          	mv	a1,s1
    46bc:	00003517          	auipc	a0,0x3
    46c0:	3ac50513          	addi	a0,a0,940 # 7a68 <malloc+0xa40>
    46c4:	059020ef          	jal	6f1c <printf>
    exit(1);
    46c8:	00100513          	li	a0,1
    46cc:	178020ef          	jal	6844 <exit>
    exit(0);
    46d0:	00000513          	li	a0,0
    46d4:	170020ef          	jal	6844 <exit>
  pause(1);
    46d8:	00100513          	li	a0,1
    46dc:	240020ef          	jal	691c <pause>
  if(unlink("oidir") != 0){
    46e0:	00004517          	auipc	a0,0x4
    46e4:	51850513          	addi	a0,a0,1304 # 8bf8 <malloc+0x1bd0>
    46e8:	1d4020ef          	jal	68bc <unlink>
    46ec:	00050e63          	beqz	a0,4708 <openiputtest+0xc8>
    printf("%s: unlink failed\n", s);
    46f0:	00048593          	mv	a1,s1
    46f4:	00003517          	auipc	a0,0x3
    46f8:	56450513          	addi	a0,a0,1380 # 7c58 <malloc+0xc30>
    46fc:	021020ef          	jal	6f1c <printf>
    exit(1);
    4700:	00100513          	li	a0,1
    4704:	140020ef          	jal	6844 <exit>
  wait(&xstatus);
    4708:	fdc40513          	addi	a0,s0,-36
    470c:	144020ef          	jal	6850 <wait>
  exit(xstatus);
    4710:	fdc42503          	lw	a0,-36(s0)
    4714:	130020ef          	jal	6844 <exit>

0000000000004718 <forkforkfork>:
{
    4718:	fe010113          	addi	sp,sp,-32
    471c:	00113c23          	sd	ra,24(sp)
    4720:	00813823          	sd	s0,16(sp)
    4724:	00913423          	sd	s1,8(sp)
    4728:	02010413          	addi	s0,sp,32
    472c:	00050493          	mv	s1,a0
  unlink("stopforking");
    4730:	00004517          	auipc	a0,0x4
    4734:	51050513          	addi	a0,a0,1296 # 8c40 <malloc+0x1c18>
    4738:	184020ef          	jal	68bc <unlink>
  int pid = fork();
    473c:	0fc020ef          	jal	6838 <fork>
  if(pid < 0){
    4740:	04054463          	bltz	a0,4788 <forkforkfork+0x70>
  if(pid == 0){
    4744:	04050e63          	beqz	a0,47a0 <forkforkfork+0x88>
  pause(20); // two seconds
    4748:	01400513          	li	a0,20
    474c:	1d0020ef          	jal	691c <pause>
  close(open("stopforking", O_CREATE|O_RDWR));
    4750:	20200593          	li	a1,514
    4754:	00004517          	auipc	a0,0x4
    4758:	4ec50513          	addi	a0,a0,1260 # 8c40 <malloc+0x1c18>
    475c:	148020ef          	jal	68a4 <open>
    4760:	120020ef          	jal	6880 <close>
  wait(0);
    4764:	00000513          	li	a0,0
    4768:	0e8020ef          	jal	6850 <wait>
  pause(10); // one second
    476c:	00a00513          	li	a0,10
    4770:	1ac020ef          	jal	691c <pause>
}
    4774:	01813083          	ld	ra,24(sp)
    4778:	01013403          	ld	s0,16(sp)
    477c:	00813483          	ld	s1,8(sp)
    4780:	02010113          	addi	sp,sp,32
    4784:	00008067          	ret
    printf("%s: fork failed", s);
    4788:	00048593          	mv	a1,s1
    478c:	00003517          	auipc	a0,0x3
    4790:	49c50513          	addi	a0,a0,1180 # 7c28 <malloc+0xc00>
    4794:	788020ef          	jal	6f1c <printf>
    exit(1);
    4798:	00100513          	li	a0,1
    479c:	0a8020ef          	jal	6844 <exit>
      int fd = open("stopforking", 0);
    47a0:	00000593          	li	a1,0
    47a4:	00004517          	auipc	a0,0x4
    47a8:	49c50513          	addi	a0,a0,1180 # 8c40 <malloc+0x1c18>
    47ac:	0f8020ef          	jal	68a4 <open>
      if(fd >= 0){
    47b0:	02055263          	bgez	a0,47d4 <forkforkfork+0xbc>
      if(fork() < 0){
    47b4:	084020ef          	jal	6838 <fork>
    47b8:	fe0554e3          	bgez	a0,47a0 <forkforkfork+0x88>
        close(open("stopforking", O_CREATE|O_RDWR));
    47bc:	20200593          	li	a1,514
    47c0:	00004517          	auipc	a0,0x4
    47c4:	48050513          	addi	a0,a0,1152 # 8c40 <malloc+0x1c18>
    47c8:	0dc020ef          	jal	68a4 <open>
    47cc:	0b4020ef          	jal	6880 <close>
    47d0:	fd1ff06f          	j	47a0 <forkforkfork+0x88>
        exit(0);
    47d4:	00000513          	li	a0,0
    47d8:	06c020ef          	jal	6844 <exit>

00000000000047dc <killstatus>:
{
    47dc:	fb010113          	addi	sp,sp,-80
    47e0:	04113423          	sd	ra,72(sp)
    47e4:	04813023          	sd	s0,64(sp)
    47e8:	02913c23          	sd	s1,56(sp)
    47ec:	03213823          	sd	s2,48(sp)
    47f0:	03313423          	sd	s3,40(sp)
    47f4:	03413023          	sd	s4,32(sp)
    47f8:	01513c23          	sd	s5,24(sp)
    47fc:	01613823          	sd	s6,16(sp)
    4800:	05010413          	addi	s0,sp,80
    4804:	00050b13          	mv	s6,a0
    4808:	06400913          	li	s2,100
    pause(1);
    480c:	00100a93          	li	s5,1
    wait(&xst);
    4810:	fbc40a13          	addi	s4,s0,-68
    if(xst != -1) {
    4814:	fff00993          	li	s3,-1
    int pid1 = fork();
    4818:	020020ef          	jal	6838 <fork>
    481c:	00050493          	mv	s1,a0
    if(pid1 < 0){
    4820:	02054c63          	bltz	a0,4858 <killstatus+0x7c>
    if(pid1 == 0){
    4824:	04050663          	beqz	a0,4870 <killstatus+0x94>
    pause(1);
    4828:	000a8513          	mv	a0,s5
    482c:	0f0020ef          	jal	691c <pause>
    kill(pid1);
    4830:	00048513          	mv	a0,s1
    4834:	058020ef          	jal	688c <kill>
    wait(&xst);
    4838:	000a0513          	mv	a0,s4
    483c:	014020ef          	jal	6850 <wait>
    if(xst != -1) {
    4840:	fbc42783          	lw	a5,-68(s0)
    4844:	03379a63          	bne	a5,s3,4878 <killstatus+0x9c>
  for(int i = 0; i < 100; i++){
    4848:	fff9091b          	addiw	s2,s2,-1
    484c:	fc0916e3          	bnez	s2,4818 <killstatus+0x3c>
  exit(0);
    4850:	00000513          	li	a0,0
    4854:	7f1010ef          	jal	6844 <exit>
      printf("%s: fork failed\n", s);
    4858:	000b0593          	mv	a1,s6
    485c:	00003517          	auipc	a0,0x3
    4860:	20c50513          	addi	a0,a0,524 # 7a68 <malloc+0xa40>
    4864:	6b8020ef          	jal	6f1c <printf>
      exit(1);
    4868:	00100513          	li	a0,1
    486c:	7d9010ef          	jal	6844 <exit>
        getpid();
    4870:	094020ef          	jal	6904 <getpid>
      while(1) {
    4874:	ffdff06f          	j	4870 <killstatus+0x94>
       printf("%s: status should be -1\n", s);
    4878:	000b0593          	mv	a1,s6
    487c:	00004517          	auipc	a0,0x4
    4880:	3d450513          	addi	a0,a0,980 # 8c50 <malloc+0x1c28>
    4884:	698020ef          	jal	6f1c <printf>
       exit(1);
    4888:	00100513          	li	a0,1
    488c:	7b9010ef          	jal	6844 <exit>

0000000000004890 <preempt>:
{
    4890:	fc010113          	addi	sp,sp,-64
    4894:	02113c23          	sd	ra,56(sp)
    4898:	02813823          	sd	s0,48(sp)
    489c:	02913423          	sd	s1,40(sp)
    48a0:	03213023          	sd	s2,32(sp)
    48a4:	01313c23          	sd	s3,24(sp)
    48a8:	01413823          	sd	s4,16(sp)
    48ac:	04010413          	addi	s0,sp,64
    48b0:	00050913          	mv	s2,a0
  pid1 = fork();
    48b4:	785010ef          	jal	6838 <fork>
  if(pid1 < 0) {
    48b8:	00054863          	bltz	a0,48c8 <preempt+0x38>
    48bc:	00050493          	mv	s1,a0
  if(pid1 == 0)
    48c0:	02051063          	bnez	a0,48e0 <preempt+0x50>
    for(;;)
    48c4:	0000006f          	j	48c4 <preempt+0x34>
    printf("%s: fork failed", s);
    48c8:	00090593          	mv	a1,s2
    48cc:	00003517          	auipc	a0,0x3
    48d0:	35c50513          	addi	a0,a0,860 # 7c28 <malloc+0xc00>
    48d4:	648020ef          	jal	6f1c <printf>
    exit(1);
    48d8:	00100513          	li	a0,1
    48dc:	769010ef          	jal	6844 <exit>
  pid2 = fork();
    48e0:	759010ef          	jal	6838 <fork>
    48e4:	00050993          	mv	s3,a0
  if(pid2 < 0) {
    48e8:	00054663          	bltz	a0,48f4 <preempt+0x64>
  if(pid2 == 0)
    48ec:	02051063          	bnez	a0,490c <preempt+0x7c>
    for(;;)
    48f0:	0000006f          	j	48f0 <preempt+0x60>
    printf("%s: fork failed\n", s);
    48f4:	00090593          	mv	a1,s2
    48f8:	00003517          	auipc	a0,0x3
    48fc:	17050513          	addi	a0,a0,368 # 7a68 <malloc+0xa40>
    4900:	61c020ef          	jal	6f1c <printf>
    exit(1);
    4904:	00100513          	li	a0,1
    4908:	73d010ef          	jal	6844 <exit>
  pipe(pfds);
    490c:	fc840513          	addi	a0,s0,-56
    4910:	74d010ef          	jal	685c <pipe>
  pid3 = fork();
    4914:	725010ef          	jal	6838 <fork>
    4918:	00050a13          	mv	s4,a0
  if(pid3 < 0) {
    491c:	02054c63          	bltz	a0,4954 <preempt+0xc4>
  if(pid3 == 0){
    4920:	06051063          	bnez	a0,4980 <preempt+0xf0>
    close(pfds[0]);
    4924:	fc842503          	lw	a0,-56(s0)
    4928:	759010ef          	jal	6880 <close>
    if(write(pfds[1], "x", 1) != 1)
    492c:	00100613          	li	a2,1
    4930:	00003597          	auipc	a1,0x3
    4934:	91858593          	addi	a1,a1,-1768 # 7248 <malloc+0x220>
    4938:	fcc42503          	lw	a0,-52(s0)
    493c:	739010ef          	jal	6874 <write>
    4940:	00100793          	li	a5,1
    4944:	02f51463          	bne	a0,a5,496c <preempt+0xdc>
    close(pfds[1]);
    4948:	fcc42503          	lw	a0,-52(s0)
    494c:	735010ef          	jal	6880 <close>
    for(;;)
    4950:	0000006f          	j	4950 <preempt+0xc0>
     printf("%s: fork failed\n", s);
    4954:	00090593          	mv	a1,s2
    4958:	00003517          	auipc	a0,0x3
    495c:	11050513          	addi	a0,a0,272 # 7a68 <malloc+0xa40>
    4960:	5bc020ef          	jal	6f1c <printf>
     exit(1);
    4964:	00100513          	li	a0,1
    4968:	6dd010ef          	jal	6844 <exit>
      printf("%s: preempt write error", s);
    496c:	00090593          	mv	a1,s2
    4970:	00004517          	auipc	a0,0x4
    4974:	30050513          	addi	a0,a0,768 # 8c70 <malloc+0x1c48>
    4978:	5a4020ef          	jal	6f1c <printf>
    497c:	fcdff06f          	j	4948 <preempt+0xb8>
  close(pfds[1]);
    4980:	fcc42503          	lw	a0,-52(s0)
    4984:	6fd010ef          	jal	6880 <close>
  if(read(pfds[0], buf, sizeof(buf)) != 1){
    4988:	00003637          	lui	a2,0x3
    498c:	00009597          	auipc	a1,0x9
    4990:	32c58593          	addi	a1,a1,812 # dcb8 <buf>
    4994:	fc842503          	lw	a0,-56(s0)
    4998:	6d1010ef          	jal	6868 <read>
    499c:	00100793          	li	a5,1
    49a0:	02f50a63          	beq	a0,a5,49d4 <preempt+0x144>
    printf("%s: preempt read error", s);
    49a4:	00090593          	mv	a1,s2
    49a8:	00004517          	auipc	a0,0x4
    49ac:	2e050513          	addi	a0,a0,736 # 8c88 <malloc+0x1c60>
    49b0:	56c020ef          	jal	6f1c <printf>
}
    49b4:	03813083          	ld	ra,56(sp)
    49b8:	03013403          	ld	s0,48(sp)
    49bc:	02813483          	ld	s1,40(sp)
    49c0:	02013903          	ld	s2,32(sp)
    49c4:	01813983          	ld	s3,24(sp)
    49c8:	01013a03          	ld	s4,16(sp)
    49cc:	04010113          	addi	sp,sp,64
    49d0:	00008067          	ret
  close(pfds[0]);
    49d4:	fc842503          	lw	a0,-56(s0)
    49d8:	6a9010ef          	jal	6880 <close>
  printf("kill... ");
    49dc:	00004517          	auipc	a0,0x4
    49e0:	2c450513          	addi	a0,a0,708 # 8ca0 <malloc+0x1c78>
    49e4:	538020ef          	jal	6f1c <printf>
  kill(pid1);
    49e8:	00048513          	mv	a0,s1
    49ec:	6a1010ef          	jal	688c <kill>
  kill(pid2);
    49f0:	00098513          	mv	a0,s3
    49f4:	699010ef          	jal	688c <kill>
  kill(pid3);
    49f8:	000a0513          	mv	a0,s4
    49fc:	691010ef          	jal	688c <kill>
  printf("wait... ");
    4a00:	00004517          	auipc	a0,0x4
    4a04:	2b050513          	addi	a0,a0,688 # 8cb0 <malloc+0x1c88>
    4a08:	514020ef          	jal	6f1c <printf>
  wait(0);
    4a0c:	00000513          	li	a0,0
    4a10:	641010ef          	jal	6850 <wait>
  wait(0);
    4a14:	00000513          	li	a0,0
    4a18:	639010ef          	jal	6850 <wait>
  wait(0);
    4a1c:	00000513          	li	a0,0
    4a20:	631010ef          	jal	6850 <wait>
    4a24:	f91ff06f          	j	49b4 <preempt+0x124>

0000000000004a28 <reparent>:
{
    4a28:	fd010113          	addi	sp,sp,-48
    4a2c:	02113423          	sd	ra,40(sp)
    4a30:	02813023          	sd	s0,32(sp)
    4a34:	00913c23          	sd	s1,24(sp)
    4a38:	01213823          	sd	s2,16(sp)
    4a3c:	01313423          	sd	s3,8(sp)
    4a40:	01413023          	sd	s4,0(sp)
    4a44:	03010413          	addi	s0,sp,48
    4a48:	00050993          	mv	s3,a0
  int master_pid = getpid();
    4a4c:	6b9010ef          	jal	6904 <getpid>
    4a50:	00050a13          	mv	s4,a0
    4a54:	0c800913          	li	s2,200
    int pid = fork();
    4a58:	5e1010ef          	jal	6838 <fork>
    4a5c:	00050493          	mv	s1,a0
    if(pid < 0){
    4a60:	02054263          	bltz	a0,4a84 <reparent+0x5c>
    if(pid){
    4a64:	04050863          	beqz	a0,4ab4 <reparent+0x8c>
      if(wait(0) != pid){
    4a68:	00000513          	li	a0,0
    4a6c:	5e5010ef          	jal	6850 <wait>
    4a70:	02951663          	bne	a0,s1,4a9c <reparent+0x74>
  for(int i = 0; i < 200; i++){
    4a74:	fff9091b          	addiw	s2,s2,-1
    4a78:	fe0910e3          	bnez	s2,4a58 <reparent+0x30>
  exit(0);
    4a7c:	00000513          	li	a0,0
    4a80:	5c5010ef          	jal	6844 <exit>
      printf("%s: fork failed\n", s);
    4a84:	00098593          	mv	a1,s3
    4a88:	00003517          	auipc	a0,0x3
    4a8c:	fe050513          	addi	a0,a0,-32 # 7a68 <malloc+0xa40>
    4a90:	48c020ef          	jal	6f1c <printf>
      exit(1);
    4a94:	00100513          	li	a0,1
    4a98:	5ad010ef          	jal	6844 <exit>
        printf("%s: wait wrong pid\n", s);
    4a9c:	00098593          	mv	a1,s3
    4aa0:	00003517          	auipc	a0,0x3
    4aa4:	15050513          	addi	a0,a0,336 # 7bf0 <malloc+0xbc8>
    4aa8:	474020ef          	jal	6f1c <printf>
        exit(1);
    4aac:	00100513          	li	a0,1
    4ab0:	595010ef          	jal	6844 <exit>
      int pid2 = fork();
    4ab4:	585010ef          	jal	6838 <fork>
      if(pid2 < 0){
    4ab8:	00054663          	bltz	a0,4ac4 <reparent+0x9c>
      exit(0);
    4abc:	00000513          	li	a0,0
    4ac0:	585010ef          	jal	6844 <exit>
        kill(master_pid);
    4ac4:	000a0513          	mv	a0,s4
    4ac8:	5c5010ef          	jal	688c <kill>
        exit(1);
    4acc:	00100513          	li	a0,1
    4ad0:	575010ef          	jal	6844 <exit>

0000000000004ad4 <sbrkfail>:
{
    4ad4:	f7010113          	addi	sp,sp,-144
    4ad8:	08113423          	sd	ra,136(sp)
    4adc:	08813023          	sd	s0,128(sp)
    4ae0:	06913c23          	sd	s1,120(sp)
    4ae4:	07213823          	sd	s2,112(sp)
    4ae8:	07313423          	sd	s3,104(sp)
    4aec:	07413023          	sd	s4,96(sp)
    4af0:	05513c23          	sd	s5,88(sp)
    4af4:	05613823          	sd	s6,80(sp)
    4af8:	05713423          	sd	s7,72(sp)
    4afc:	05813023          	sd	s8,64(sp)
    4b00:	09010413          	addi	s0,sp,144
    4b04:	00050c13          	mv	s8,a0
  if(pipe(fds) != 0){
    4b08:	fa040513          	addi	a0,s0,-96
    4b0c:	551010ef          	jal	685c <pipe>
    4b10:	02051263          	bnez	a0,4b34 <sbrkfail+0x60>
    4b14:	00050b93          	mv	s7,a0
    4b18:	f7040493          	addi	s1,s0,-144
    4b1c:	f9840993          	addi	s3,s0,-104
    4b20:	00048913          	mv	s2,s1
    if(pids[i] != -1) {
    4b24:	fff00a13          	li	s4,-1
      read(fds[0], &scratch, 1);
    4b28:	f9f40b13          	addi	s6,s0,-97
    4b2c:	00100a93          	li	s5,1
    4b30:	0780006f          	j	4ba8 <sbrkfail+0xd4>
    printf("%s: pipe() failed\n", s);
    4b34:	000c0593          	mv	a1,s8
    4b38:	00003517          	auipc	a0,0x3
    4b3c:	03850513          	addi	a0,a0,56 # 7b70 <malloc+0xb48>
    4b40:	3dc020ef          	jal	6f1c <printf>
    exit(1);
    4b44:	00100513          	li	a0,1
    4b48:	4fd010ef          	jal	6844 <exit>
      if (sbrk(BIG - (uint64)sbrk(0)) ==  (char*)SBRK_ERROR)
    4b4c:	49d010ef          	jal	67e8 <sbrk>
    4b50:	064007b7          	lui	a5,0x6400
    4b54:	40a7853b          	subw	a0,a5,a0
    4b58:	491010ef          	jal	67e8 <sbrk>
    4b5c:	fff00793          	li	a5,-1
    4b60:	02f50463          	beq	a0,a5,4b88 <sbrkfail+0xb4>
        write(fds[1], "1", 1);
    4b64:	00100613          	li	a2,1
    4b68:	00005597          	auipc	a1,0x5
    4b6c:	8d058593          	addi	a1,a1,-1840 # 9438 <malloc+0x2410>
    4b70:	fa442503          	lw	a0,-92(s0)
    4b74:	501010ef          	jal	6874 <write>
      for(;;) pause(1000);
    4b78:	3e800493          	li	s1,1000
    4b7c:	00048513          	mv	a0,s1
    4b80:	59d010ef          	jal	691c <pause>
    4b84:	ff9ff06f          	j	4b7c <sbrkfail+0xa8>
        write(fds[1], "0", 1);
    4b88:	00100613          	li	a2,1
    4b8c:	00004597          	auipc	a1,0x4
    4b90:	13458593          	addi	a1,a1,308 # 8cc0 <malloc+0x1c98>
    4b94:	fa442503          	lw	a0,-92(s0)
    4b98:	4dd010ef          	jal	6874 <write>
    4b9c:	fddff06f          	j	4b78 <sbrkfail+0xa4>
  for(i = 0; i < sizeof(pids)/sizeof(pids[0]); i++){
    4ba0:	00490913          	addi	s2,s2,4
    4ba4:	03390e63          	beq	s2,s3,4be0 <sbrkfail+0x10c>
    if((pids[i] = fork()) == 0){
    4ba8:	491010ef          	jal	6838 <fork>
    4bac:	00a92023          	sw	a0,0(s2)
    4bb0:	f8050ee3          	beqz	a0,4b4c <sbrkfail+0x78>
    if(pids[i] != -1) {
    4bb4:	ff4506e3          	beq	a0,s4,4ba0 <sbrkfail+0xcc>
      read(fds[0], &scratch, 1);
    4bb8:	000a8613          	mv	a2,s5
    4bbc:	000b0593          	mv	a1,s6
    4bc0:	fa042503          	lw	a0,-96(s0)
    4bc4:	4a5010ef          	jal	6868 <read>
      if(scratch == '0')
    4bc8:	f9f44783          	lbu	a5,-97(s0)
    4bcc:	fd078793          	addi	a5,a5,-48 # 63fffd0 <base+0x63ef298>
    4bd0:	0017b793          	seqz	a5,a5
    4bd4:	00fbe7b3          	or	a5,s7,a5
    4bd8:	00078b9b          	sext.w	s7,a5
    4bdc:	fc5ff06f          	j	4ba0 <sbrkfail+0xcc>
  if(!failed) {
    4be0:	000b8c63          	beqz	s7,4bf8 <sbrkfail+0x124>
  c = sbrk(PGSIZE);
    4be4:	00001537          	lui	a0,0x1
    4be8:	401010ef          	jal	67e8 <sbrk>
    4bec:	00050a13          	mv	s4,a0
    if(pids[i] == -1)
    4bf0:	fff00913          	li	s2,-1
    4bf4:	0200006f          	j	4c14 <sbrkfail+0x140>
    printf("%s: no allocation failed; allocate more?\n", s);
    4bf8:	000c0593          	mv	a1,s8
    4bfc:	00004517          	auipc	a0,0x4
    4c00:	0cc50513          	addi	a0,a0,204 # 8cc8 <malloc+0x1ca0>
    4c04:	318020ef          	jal	6f1c <printf>
    4c08:	fddff06f          	j	4be4 <sbrkfail+0x110>
  for(i = 0; i < sizeof(pids)/sizeof(pids[0]); i++){
    4c0c:	00448493          	addi	s1,s1,4
    4c10:	01348e63          	beq	s1,s3,4c2c <sbrkfail+0x158>
    if(pids[i] == -1)
    4c14:	0004a503          	lw	a0,0(s1)
    4c18:	ff250ae3          	beq	a0,s2,4c0c <sbrkfail+0x138>
    kill(pids[i]);
    4c1c:	471010ef          	jal	688c <kill>
    wait(0);
    4c20:	00000513          	li	a0,0
    4c24:	42d010ef          	jal	6850 <wait>
    4c28:	fe5ff06f          	j	4c0c <sbrkfail+0x138>
  if(c == (char*)SBRK_ERROR){
    4c2c:	fff00793          	li	a5,-1
    4c30:	02fa0e63          	beq	s4,a5,4c6c <sbrkfail+0x198>
  pid = fork();
    4c34:	405010ef          	jal	6838 <fork>
  if(pid < 0){
    4c38:	04054663          	bltz	a0,4c84 <sbrkfail+0x1b0>
  if(pid == 0){
    4c3c:	06051463          	bnez	a0,4ca4 <sbrkfail+0x1d0>
    a = sbrk(10*BIG);
    4c40:	3e800537          	lui	a0,0x3e800
    4c44:	3a5010ef          	jal	67e8 <sbrk>
    if(a == (char*)SBRK_ERROR){
    4c48:	fff00793          	li	a5,-1
    4c4c:	04f50863          	beq	a0,a5,4c9c <sbrkfail+0x1c8>
    printf("%s: allocate a lot of memory succeeded %d\n", s, 10*BIG);
    4c50:	3e800637          	lui	a2,0x3e800
    4c54:	000c0593          	mv	a1,s8
    4c58:	00004517          	auipc	a0,0x4
    4c5c:	0c050513          	addi	a0,a0,192 # 8d18 <malloc+0x1cf0>
    4c60:	2bc020ef          	jal	6f1c <printf>
    exit(1);
    4c64:	00100513          	li	a0,1
    4c68:	3dd010ef          	jal	6844 <exit>
    printf("%s: failed sbrk leaked memory\n", s);
    4c6c:	000c0593          	mv	a1,s8
    4c70:	00004517          	auipc	a0,0x4
    4c74:	08850513          	addi	a0,a0,136 # 8cf8 <malloc+0x1cd0>
    4c78:	2a4020ef          	jal	6f1c <printf>
    exit(1);
    4c7c:	00100513          	li	a0,1
    4c80:	3c5010ef          	jal	6844 <exit>
    printf("%s: fork failed\n", s);
    4c84:	000c0593          	mv	a1,s8
    4c88:	00003517          	auipc	a0,0x3
    4c8c:	de050513          	addi	a0,a0,-544 # 7a68 <malloc+0xa40>
    4c90:	28c020ef          	jal	6f1c <printf>
    exit(1);
    4c94:	00100513          	li	a0,1
    4c98:	3ad010ef          	jal	6844 <exit>
      exit(0);
    4c9c:	00000513          	li	a0,0
    4ca0:	3a5010ef          	jal	6844 <exit>
  wait(&xstatus);
    4ca4:	fac40513          	addi	a0,s0,-84
    4ca8:	3a9010ef          	jal	6850 <wait>
  if(xstatus != 0)
    4cac:	fac42783          	lw	a5,-84(s0)
    4cb0:	02079a63          	bnez	a5,4ce4 <sbrkfail+0x210>
}
    4cb4:	08813083          	ld	ra,136(sp)
    4cb8:	08013403          	ld	s0,128(sp)
    4cbc:	07813483          	ld	s1,120(sp)
    4cc0:	07013903          	ld	s2,112(sp)
    4cc4:	06813983          	ld	s3,104(sp)
    4cc8:	06013a03          	ld	s4,96(sp)
    4ccc:	05813a83          	ld	s5,88(sp)
    4cd0:	05013b03          	ld	s6,80(sp)
    4cd4:	04813b83          	ld	s7,72(sp)
    4cd8:	04013c03          	ld	s8,64(sp)
    4cdc:	09010113          	addi	sp,sp,144
    4ce0:	00008067          	ret
    exit(1);
    4ce4:	00100513          	li	a0,1
    4ce8:	35d010ef          	jal	6844 <exit>

0000000000004cec <mem>:
{
    4cec:	fc010113          	addi	sp,sp,-64
    4cf0:	02113c23          	sd	ra,56(sp)
    4cf4:	02813823          	sd	s0,48(sp)
    4cf8:	02913423          	sd	s1,40(sp)
    4cfc:	03213023          	sd	s2,32(sp)
    4d00:	01313c23          	sd	s3,24(sp)
    4d04:	04010413          	addi	s0,sp,64
    4d08:	00050993          	mv	s3,a0
  if((pid = fork()) == 0){
    4d0c:	32d010ef          	jal	6838 <fork>
    m1 = 0;
    4d10:	00000493          	li	s1,0
    while((m2 = malloc(10001)) != 0){
    4d14:	00002937          	lui	s2,0x2
    4d18:	71190913          	addi	s2,s2,1809 # 2711 <stacktest+0x3d>
  if((pid = fork()) == 0){
    4d1c:	02050263          	beqz	a0,4d40 <mem+0x54>
    wait(&xstatus);
    4d20:	fcc40513          	addi	a0,s0,-52
    4d24:	32d010ef          	jal	6850 <wait>
    if(xstatus == -1){
    4d28:	fcc42503          	lw	a0,-52(s0)
    4d2c:	fff00793          	li	a5,-1
    4d30:	06f50063          	beq	a0,a5,4d90 <mem+0xa4>
    exit(xstatus);
    4d34:	311010ef          	jal	6844 <exit>
      *(char**)m2 = m1;
    4d38:	00953023          	sd	s1,0(a0)
      m1 = m2;
    4d3c:	00050493          	mv	s1,a0
    while((m2 = malloc(10001)) != 0){
    4d40:	00090513          	mv	a0,s2
    4d44:	2e4020ef          	jal	7028 <malloc>
    4d48:	fe0518e3          	bnez	a0,4d38 <mem+0x4c>
    while(m1){
    4d4c:	00048a63          	beqz	s1,4d60 <mem+0x74>
      m2 = *(char**)m1;
    4d50:	00048513          	mv	a0,s1
    4d54:	0004b483          	ld	s1,0(s1)
      free(m1);
    4d58:	218020ef          	jal	6f70 <free>
    while(m1){
    4d5c:	fe049ae3          	bnez	s1,4d50 <mem+0x64>
    m1 = malloc(1024*20);
    4d60:	00005537          	lui	a0,0x5
    4d64:	2c4020ef          	jal	7028 <malloc>
    if(m1 == 0){
    4d68:	00050863          	beqz	a0,4d78 <mem+0x8c>
    free(m1);
    4d6c:	204020ef          	jal	6f70 <free>
    exit(0);
    4d70:	00000513          	li	a0,0
    4d74:	2d1010ef          	jal	6844 <exit>
      printf("%s: couldn't allocate mem?!!\n", s);
    4d78:	00098593          	mv	a1,s3
    4d7c:	00004517          	auipc	a0,0x4
    4d80:	fcc50513          	addi	a0,a0,-52 # 8d48 <malloc+0x1d20>
    4d84:	198020ef          	jal	6f1c <printf>
      exit(1);
    4d88:	00100513          	li	a0,1
    4d8c:	2b9010ef          	jal	6844 <exit>
      exit(0);
    4d90:	00000513          	li	a0,0
    4d94:	2b1010ef          	jal	6844 <exit>

0000000000004d98 <sharedfd>:
{
    4d98:	f9010113          	addi	sp,sp,-112
    4d9c:	06113423          	sd	ra,104(sp)
    4da0:	06813023          	sd	s0,96(sp)
    4da4:	04913c23          	sd	s1,88(sp)
    4da8:	03613823          	sd	s6,48(sp)
    4dac:	07010413          	addi	s0,sp,112
    4db0:	00050493          	mv	s1,a0
    4db4:	00050b13          	mv	s6,a0
  unlink("sharedfd");
    4db8:	00004517          	auipc	a0,0x4
    4dbc:	fb050513          	addi	a0,a0,-80 # 8d68 <malloc+0x1d40>
    4dc0:	2fd010ef          	jal	68bc <unlink>
  fd = open("sharedfd", O_CREATE|O_RDWR);
    4dc4:	20200593          	li	a1,514
    4dc8:	00004517          	auipc	a0,0x4
    4dcc:	fa050513          	addi	a0,a0,-96 # 8d68 <malloc+0x1d40>
    4dd0:	2d5010ef          	jal	68a4 <open>
  if(fd < 0){
    4dd4:	06054863          	bltz	a0,4e44 <sharedfd+0xac>
    4dd8:	05213823          	sd	s2,80(sp)
    4ddc:	05313423          	sd	s3,72(sp)
    4de0:	05413023          	sd	s4,64(sp)
    4de4:	03513c23          	sd	s5,56(sp)
    4de8:	00050993          	mv	s3,a0
  pid = fork();
    4dec:	24d010ef          	jal	6838 <fork>
    4df0:	00050a93          	mv	s5,a0
  memset(buf, pid==0?'c':'p', sizeof(buf));
    4df4:	07000593          	li	a1,112
    4df8:	00051463          	bnez	a0,4e00 <sharedfd+0x68>
    4dfc:	06300593          	li	a1,99
    4e00:	00a00613          	li	a2,10
    4e04:	fa040513          	addi	a0,s0,-96
    4e08:	6bc010ef          	jal	64c4 <memset>
    4e0c:	3e800493          	li	s1,1000
    if(write(fd, buf, sizeof(buf)) != sizeof(buf)){
    4e10:	fa040a13          	addi	s4,s0,-96
    4e14:	00a00913          	li	s2,10
    4e18:	00090613          	mv	a2,s2
    4e1c:	000a0593          	mv	a1,s4
    4e20:	00098513          	mv	a0,s3
    4e24:	251010ef          	jal	6874 <write>
    4e28:	05251463          	bne	a0,s2,4e70 <sharedfd+0xd8>
  for(i = 0; i < N; i++){
    4e2c:	fff4849b          	addiw	s1,s1,-1
    4e30:	fe0494e3          	bnez	s1,4e18 <sharedfd+0x80>
  if(pid == 0) {
    4e34:	040a9c63          	bnez	s5,4e8c <sharedfd+0xf4>
    4e38:	03713423          	sd	s7,40(sp)
    exit(0);
    4e3c:	00000513          	li	a0,0
    4e40:	205010ef          	jal	6844 <exit>
    4e44:	05213823          	sd	s2,80(sp)
    4e48:	05313423          	sd	s3,72(sp)
    4e4c:	05413023          	sd	s4,64(sp)
    4e50:	03513c23          	sd	s5,56(sp)
    4e54:	03713423          	sd	s7,40(sp)
    printf("%s: cannot open sharedfd for writing", s);
    4e58:	00048593          	mv	a1,s1
    4e5c:	00004517          	auipc	a0,0x4
    4e60:	f1c50513          	addi	a0,a0,-228 # 8d78 <malloc+0x1d50>
    4e64:	0b8020ef          	jal	6f1c <printf>
    exit(1);
    4e68:	00100513          	li	a0,1
    4e6c:	1d9010ef          	jal	6844 <exit>
    4e70:	03713423          	sd	s7,40(sp)
      printf("%s: write sharedfd failed\n", s);
    4e74:	000b0593          	mv	a1,s6
    4e78:	00004517          	auipc	a0,0x4
    4e7c:	f2850513          	addi	a0,a0,-216 # 8da0 <malloc+0x1d78>
    4e80:	09c020ef          	jal	6f1c <printf>
      exit(1);
    4e84:	00100513          	li	a0,1
    4e88:	1bd010ef          	jal	6844 <exit>
    wait(&xstatus);
    4e8c:	f9c40513          	addi	a0,s0,-100
    4e90:	1c1010ef          	jal	6850 <wait>
    if(xstatus != 0)
    4e94:	f9c42a03          	lw	s4,-100(s0)
    4e98:	000a0863          	beqz	s4,4ea8 <sharedfd+0x110>
    4e9c:	03713423          	sd	s7,40(sp)
      exit(xstatus);
    4ea0:	000a0513          	mv	a0,s4
    4ea4:	1a1010ef          	jal	6844 <exit>
    4ea8:	03713423          	sd	s7,40(sp)
  close(fd);
    4eac:	00098513          	mv	a0,s3
    4eb0:	1d1010ef          	jal	6880 <close>
  fd = open("sharedfd", 0);
    4eb4:	00000593          	li	a1,0
    4eb8:	00004517          	auipc	a0,0x4
    4ebc:	eb050513          	addi	a0,a0,-336 # 8d68 <malloc+0x1d40>
    4ec0:	1e5010ef          	jal	68a4 <open>
    4ec4:	00050b93          	mv	s7,a0
  nc = np = 0;
    4ec8:	000a0993          	mv	s3,s4
  if(fd < 0){
    4ecc:	02054663          	bltz	a0,4ef8 <sharedfd+0x160>
    4ed0:	faa40913          	addi	s2,s0,-86
      if(buf[i] == 'c')
    4ed4:	06300493          	li	s1,99
      if(buf[i] == 'p')
    4ed8:	07000a93          	li	s5,112
  while((n = read(fd, buf, sizeof(buf))) > 0){
    4edc:	00a00613          	li	a2,10
    4ee0:	fa040593          	addi	a1,s0,-96
    4ee4:	000b8513          	mv	a0,s7
    4ee8:	181010ef          	jal	6868 <read>
    4eec:	04a05263          	blez	a0,4f30 <sharedfd+0x198>
    4ef0:	fa040793          	addi	a5,s0,-96
    4ef4:	0280006f          	j	4f1c <sharedfd+0x184>
    printf("%s: cannot open sharedfd for reading\n", s);
    4ef8:	000b0593          	mv	a1,s6
    4efc:	00004517          	auipc	a0,0x4
    4f00:	ec450513          	addi	a0,a0,-316 # 8dc0 <malloc+0x1d98>
    4f04:	018020ef          	jal	6f1c <printf>
    exit(1);
    4f08:	00100513          	li	a0,1
    4f0c:	139010ef          	jal	6844 <exit>
        nc++;
    4f10:	001a0a1b          	addiw	s4,s4,1
    for(i = 0; i < sizeof(buf); i++){
    4f14:	00178793          	addi	a5,a5,1
    4f18:	fd2782e3          	beq	a5,s2,4edc <sharedfd+0x144>
      if(buf[i] == 'c')
    4f1c:	0007c703          	lbu	a4,0(a5)
    4f20:	fe9708e3          	beq	a4,s1,4f10 <sharedfd+0x178>
      if(buf[i] == 'p')
    4f24:	ff5718e3          	bne	a4,s5,4f14 <sharedfd+0x17c>
        np++;
    4f28:	0019899b          	addiw	s3,s3,1
    4f2c:	fe9ff06f          	j	4f14 <sharedfd+0x17c>
  close(fd);
    4f30:	000b8513          	mv	a0,s7
    4f34:	14d010ef          	jal	6880 <close>
  unlink("sharedfd");
    4f38:	00004517          	auipc	a0,0x4
    4f3c:	e3050513          	addi	a0,a0,-464 # 8d68 <malloc+0x1d40>
    4f40:	17d010ef          	jal	68bc <unlink>
  if(nc == N*SZ && np == N*SZ){
    4f44:	000027b7          	lui	a5,0x2
    4f48:	71078793          	addi	a5,a5,1808 # 2710 <stacktest+0x3c>
    4f4c:	00fa1863          	bne	s4,a5,4f5c <sharedfd+0x1c4>
    4f50:	01499663          	bne	s3,s4,4f5c <sharedfd+0x1c4>
    exit(0);
    4f54:	00000513          	li	a0,0
    4f58:	0ed010ef          	jal	6844 <exit>
    printf("%s: nc/np test fails\n", s);
    4f5c:	000b0593          	mv	a1,s6
    4f60:	00004517          	auipc	a0,0x4
    4f64:	e8850513          	addi	a0,a0,-376 # 8de8 <malloc+0x1dc0>
    4f68:	7b5010ef          	jal	6f1c <printf>
    exit(1);
    4f6c:	00100513          	li	a0,1
    4f70:	0d5010ef          	jal	6844 <exit>

0000000000004f74 <fourfiles>:
{
    4f74:	f6010113          	addi	sp,sp,-160
    4f78:	08113c23          	sd	ra,152(sp)
    4f7c:	08813823          	sd	s0,144(sp)
    4f80:	08913423          	sd	s1,136(sp)
    4f84:	09213023          	sd	s2,128(sp)
    4f88:	07313c23          	sd	s3,120(sp)
    4f8c:	07413823          	sd	s4,112(sp)
    4f90:	07513423          	sd	s5,104(sp)
    4f94:	07613023          	sd	s6,96(sp)
    4f98:	05713c23          	sd	s7,88(sp)
    4f9c:	05813823          	sd	s8,80(sp)
    4fa0:	05913423          	sd	s9,72(sp)
    4fa4:	05a13023          	sd	s10,64(sp)
    4fa8:	03b13c23          	sd	s11,56(sp)
    4fac:	0a010413          	addi	s0,sp,160
    4fb0:	00050c93          	mv	s9,a0
  char *names[] = { "f0", "f1", "f2", "f3" };
    4fb4:	00004797          	auipc	a5,0x4
    4fb8:	e4c78793          	addi	a5,a5,-436 # 8e00 <malloc+0x1dd8>
    4fbc:	f6f43823          	sd	a5,-144(s0)
    4fc0:	00004797          	auipc	a5,0x4
    4fc4:	e4878793          	addi	a5,a5,-440 # 8e08 <malloc+0x1de0>
    4fc8:	f6f43c23          	sd	a5,-136(s0)
    4fcc:	00004797          	auipc	a5,0x4
    4fd0:	e4478793          	addi	a5,a5,-444 # 8e10 <malloc+0x1de8>
    4fd4:	f8f43023          	sd	a5,-128(s0)
    4fd8:	00004797          	auipc	a5,0x4
    4fdc:	e4078793          	addi	a5,a5,-448 # 8e18 <malloc+0x1df0>
    4fe0:	f8f43423          	sd	a5,-120(s0)
  for(pi = 0; pi < NCHILD; pi++){
    4fe4:	f7040b93          	addi	s7,s0,-144
  char *names[] = { "f0", "f1", "f2", "f3" };
    4fe8:	000b8913          	mv	s2,s7
  for(pi = 0; pi < NCHILD; pi++){
    4fec:	00000493          	li	s1,0
    4ff0:	00400a13          	li	s4,4
    fname = names[pi];
    4ff4:	00093983          	ld	s3,0(s2)
    unlink(fname);
    4ff8:	00098513          	mv	a0,s3
    4ffc:	0c1010ef          	jal	68bc <unlink>
    pid = fork();
    5000:	039010ef          	jal	6838 <fork>
    if(pid < 0){
    5004:	04054a63          	bltz	a0,5058 <fourfiles+0xe4>
    if(pid == 0){
    5008:	06050463          	beqz	a0,5070 <fourfiles+0xfc>
  for(pi = 0; pi < NCHILD; pi++){
    500c:	0014849b          	addiw	s1,s1,1
    5010:	00890913          	addi	s2,s2,8
    5014:	ff4490e3          	bne	s1,s4,4ff4 <fourfiles+0x80>
    5018:	00400493          	li	s1,4
    wait(&xstatus);
    501c:	f6c40913          	addi	s2,s0,-148
    5020:	00090513          	mv	a0,s2
    5024:	02d010ef          	jal	6850 <wait>
    if(xstatus != 0)
    5028:	f6c42b03          	lw	s6,-148(s0)
    502c:	0c0b1863          	bnez	s6,50fc <fourfiles+0x188>
  for(pi = 0; pi < NCHILD; pi++){
    5030:	fff4849b          	addiw	s1,s1,-1
    5034:	fe0496e3          	bnez	s1,5020 <fourfiles+0xac>
    5038:	03000493          	li	s1,48
    while((n = read(fd, buf, sizeof(buf))) > 0){
    503c:	00003ab7          	lui	s5,0x3
    5040:	00009a17          	auipc	s4,0x9
    5044:	c78a0a13          	addi	s4,s4,-904 # dcb8 <buf>
    if(total != N*SZ){
    5048:	00001d37          	lui	s10,0x1
    504c:	770d0d13          	addi	s10,s10,1904 # 1770 <copyinstr2+0x1a8>
  for(i = 0; i < NCHILD; i++){
    5050:	03400d93          	li	s11,52
    5054:	0e80006f          	j	513c <fourfiles+0x1c8>
      printf("%s: fork failed\n", s);
    5058:	000c8593          	mv	a1,s9
    505c:	00003517          	auipc	a0,0x3
    5060:	a0c50513          	addi	a0,a0,-1524 # 7a68 <malloc+0xa40>
    5064:	6b9010ef          	jal	6f1c <printf>
      exit(1);
    5068:	00100513          	li	a0,1
    506c:	7d8010ef          	jal	6844 <exit>
      fd = open(fname, O_CREATE | O_RDWR);
    5070:	20200593          	li	a1,514
    5074:	00098513          	mv	a0,s3
    5078:	02d010ef          	jal	68a4 <open>
    507c:	00050913          	mv	s2,a0
      if(fd < 0){
    5080:	04054863          	bltz	a0,50d0 <fourfiles+0x15c>
      memset(buf, '0'+pi, SZ);
    5084:	1f400613          	li	a2,500
    5088:	0304859b          	addiw	a1,s1,48
    508c:	00009517          	auipc	a0,0x9
    5090:	c2c50513          	addi	a0,a0,-980 # dcb8 <buf>
    5094:	430010ef          	jal	64c4 <memset>
    5098:	00c00493          	li	s1,12
        if((n = write(fd, buf, SZ)) != SZ){
    509c:	1f400993          	li	s3,500
    50a0:	00009a17          	auipc	s4,0x9
    50a4:	c18a0a13          	addi	s4,s4,-1000 # dcb8 <buf>
    50a8:	00098613          	mv	a2,s3
    50ac:	000a0593          	mv	a1,s4
    50b0:	00090513          	mv	a0,s2
    50b4:	7c0010ef          	jal	6874 <write>
    50b8:	00050593          	mv	a1,a0
    50bc:	03351663          	bne	a0,s3,50e8 <fourfiles+0x174>
      for(i = 0; i < N; i++){
    50c0:	fff4849b          	addiw	s1,s1,-1
    50c4:	fe0492e3          	bnez	s1,50a8 <fourfiles+0x134>
      exit(0);
    50c8:	00000513          	li	a0,0
    50cc:	778010ef          	jal	6844 <exit>
        printf("%s: create failed\n", s);
    50d0:	000c8593          	mv	a1,s9
    50d4:	00003517          	auipc	a0,0x3
    50d8:	a2c50513          	addi	a0,a0,-1492 # 7b00 <malloc+0xad8>
    50dc:	641010ef          	jal	6f1c <printf>
        exit(1);
    50e0:	00100513          	li	a0,1
    50e4:	760010ef          	jal	6844 <exit>
          printf("write failed %d\n", n);
    50e8:	00004517          	auipc	a0,0x4
    50ec:	d3850513          	addi	a0,a0,-712 # 8e20 <malloc+0x1df8>
    50f0:	62d010ef          	jal	6f1c <printf>
          exit(1);
    50f4:	00100513          	li	a0,1
    50f8:	74c010ef          	jal	6844 <exit>
      exit(xstatus);
    50fc:	000b0513          	mv	a0,s6
    5100:	744010ef          	jal	6844 <exit>
          printf("%s: wrong char\n", s);
    5104:	000c8593          	mv	a1,s9
    5108:	00004517          	auipc	a0,0x4
    510c:	d3050513          	addi	a0,a0,-720 # 8e38 <malloc+0x1e10>
    5110:	60d010ef          	jal	6f1c <printf>
          exit(1);
    5114:	00100513          	li	a0,1
    5118:	72c010ef          	jal	6844 <exit>
    close(fd);
    511c:	00098513          	mv	a0,s3
    5120:	760010ef          	jal	6880 <close>
    if(total != N*SZ){
    5124:	07a91463          	bne	s2,s10,518c <fourfiles+0x218>
    unlink(fname);
    5128:	000c0513          	mv	a0,s8
    512c:	790010ef          	jal	68bc <unlink>
  for(i = 0; i < NCHILD; i++){
    5130:	008b8b93          	addi	s7,s7,8
    5134:	0014849b          	addiw	s1,s1,1
    5138:	07b48663          	beq	s1,s11,51a4 <fourfiles+0x230>
    fname = names[i];
    513c:	000bbc03          	ld	s8,0(s7)
    fd = open(fname, 0);
    5140:	00000593          	li	a1,0
    5144:	000c0513          	mv	a0,s8
    5148:	75c010ef          	jal	68a4 <open>
    514c:	00050993          	mv	s3,a0
    total = 0;
    5150:	000b0913          	mv	s2,s6
    while((n = read(fd, buf, sizeof(buf))) > 0){
    5154:	000a8613          	mv	a2,s5
    5158:	000a0593          	mv	a1,s4
    515c:	00098513          	mv	a0,s3
    5160:	708010ef          	jal	6868 <read>
    5164:	faa05ce3          	blez	a0,511c <fourfiles+0x1a8>
    5168:	00009797          	auipc	a5,0x9
    516c:	b5078793          	addi	a5,a5,-1200 # dcb8 <buf>
    5170:	00f506b3          	add	a3,a0,a5
        if(buf[j] != '0'+i){
    5174:	0007c703          	lbu	a4,0(a5)
    5178:	f89716e3          	bne	a4,s1,5104 <fourfiles+0x190>
      for(j = 0; j < n; j++){
    517c:	00178793          	addi	a5,a5,1
    5180:	fed79ae3          	bne	a5,a3,5174 <fourfiles+0x200>
      total += n;
    5184:	00a9093b          	addw	s2,s2,a0
    5188:	fcdff06f          	j	5154 <fourfiles+0x1e0>
      printf("wrong length %d\n", total);
    518c:	00090593          	mv	a1,s2
    5190:	00004517          	auipc	a0,0x4
    5194:	cb850513          	addi	a0,a0,-840 # 8e48 <malloc+0x1e20>
    5198:	585010ef          	jal	6f1c <printf>
      exit(1);
    519c:	00100513          	li	a0,1
    51a0:	6a4010ef          	jal	6844 <exit>
}
    51a4:	09813083          	ld	ra,152(sp)
    51a8:	09013403          	ld	s0,144(sp)
    51ac:	08813483          	ld	s1,136(sp)
    51b0:	08013903          	ld	s2,128(sp)
    51b4:	07813983          	ld	s3,120(sp)
    51b8:	07013a03          	ld	s4,112(sp)
    51bc:	06813a83          	ld	s5,104(sp)
    51c0:	06013b03          	ld	s6,96(sp)
    51c4:	05813b83          	ld	s7,88(sp)
    51c8:	05013c03          	ld	s8,80(sp)
    51cc:	04813c83          	ld	s9,72(sp)
    51d0:	04013d03          	ld	s10,64(sp)
    51d4:	03813d83          	ld	s11,56(sp)
    51d8:	0a010113          	addi	sp,sp,160
    51dc:	00008067          	ret

00000000000051e0 <concreate>:
{
    51e0:	f5010113          	addi	sp,sp,-176
    51e4:	0a113423          	sd	ra,168(sp)
    51e8:	0a813023          	sd	s0,160(sp)
    51ec:	08913c23          	sd	s1,152(sp)
    51f0:	09213823          	sd	s2,144(sp)
    51f4:	09313423          	sd	s3,136(sp)
    51f8:	09413023          	sd	s4,128(sp)
    51fc:	07513c23          	sd	s5,120(sp)
    5200:	07613823          	sd	s6,112(sp)
    5204:	07713423          	sd	s7,104(sp)
    5208:	07813023          	sd	s8,96(sp)
    520c:	05913c23          	sd	s9,88(sp)
    5210:	05a13823          	sd	s10,80(sp)
    5214:	0b010413          	addi	s0,sp,176
    5218:	00050d13          	mv	s10,a0
  file[0] = 'C';
    521c:	04300793          	li	a5,67
    5220:	f8f40c23          	sb	a5,-104(s0)
  file[2] = '\0';
    5224:	f8040d23          	sb	zero,-102(s0)
  for(i = 0; i < N; i++){
    5228:	00000913          	li	s2,0
    unlink(file);
    522c:	f9840993          	addi	s3,s0,-104
    if(pid && (i % 3) == 1){
    5230:	55555b37          	lui	s6,0x55555
    5234:	556b0b13          	addi	s6,s6,1366 # 55555556 <base+0x5554481e>
    5238:	00100b93          	li	s7,1
      fd = open(file, O_CREATE | O_RDWR);
    523c:	20200c13          	li	s8,514
      link("C0", file);
    5240:	00004c97          	auipc	s9,0x4
    5244:	c20c8c93          	addi	s9,s9,-992 # 8e60 <malloc+0x1e38>
      wait(&xstatus);
    5248:	f5c40a93          	addi	s5,s0,-164
  for(i = 0; i < N; i++){
    524c:	02800a13          	li	s4,40
    5250:	2c80006f          	j	5518 <concreate+0x338>
      link("C0", file);
    5254:	00098593          	mv	a1,s3
    5258:	000c8513          	mv	a0,s9
    525c:	678010ef          	jal	68d4 <link>
    if(pid == 0) {
    5260:	2a00006f          	j	5500 <concreate+0x320>
    } else if(pid == 0 && (i % 5) == 1){
    5264:	666667b7          	lui	a5,0x66666
    5268:	66778793          	addi	a5,a5,1639 # 66666667 <base+0x6665592f>
    526c:	02f907b3          	mul	a5,s2,a5
    5270:	4217d793          	srai	a5,a5,0x21
    5274:	41f9571b          	sraiw	a4,s2,0x1f
    5278:	40e787bb          	subw	a5,a5,a4
    527c:	0027971b          	slliw	a4,a5,0x2
    5280:	00f707bb          	addw	a5,a4,a5
    5284:	40f9093b          	subw	s2,s2,a5
    5288:	00100793          	li	a5,1
    528c:	02f90663          	beq	s2,a5,52b8 <concreate+0xd8>
      fd = open(file, O_CREATE | O_RDWR);
    5290:	20200593          	li	a1,514
    5294:	f9840513          	addi	a0,s0,-104
    5298:	60c010ef          	jal	68a4 <open>
      if(fd < 0){
    529c:	24055c63          	bgez	a0,54f4 <concreate+0x314>
        printf("concreate create %s failed\n", file);
    52a0:	f9840593          	addi	a1,s0,-104
    52a4:	00004517          	auipc	a0,0x4
    52a8:	bc450513          	addi	a0,a0,-1084 # 8e68 <malloc+0x1e40>
    52ac:	471010ef          	jal	6f1c <printf>
        exit(1);
    52b0:	00100513          	li	a0,1
    52b4:	590010ef          	jal	6844 <exit>
      link("C0", file);
    52b8:	f9840593          	addi	a1,s0,-104
    52bc:	00004517          	auipc	a0,0x4
    52c0:	ba450513          	addi	a0,a0,-1116 # 8e60 <malloc+0x1e38>
    52c4:	610010ef          	jal	68d4 <link>
      exit(0);
    52c8:	00000513          	li	a0,0
    52cc:	578010ef          	jal	6844 <exit>
        exit(1);
    52d0:	00100513          	li	a0,1
    52d4:	570010ef          	jal	6844 <exit>
  memset(fa, 0, sizeof(fa));
    52d8:	02800613          	li	a2,40
    52dc:	00000593          	li	a1,0
    52e0:	f7040513          	addi	a0,s0,-144
    52e4:	1e0010ef          	jal	64c4 <memset>
  fd = open(".", 0);
    52e8:	00000593          	li	a1,0
    52ec:	00002517          	auipc	a0,0x2
    52f0:	5d450513          	addi	a0,a0,1492 # 78c0 <malloc+0x898>
    52f4:	5b0010ef          	jal	68a4 <open>
    52f8:	00050913          	mv	s2,a0
  n = 0;
    52fc:	00048b13          	mv	s6,s1
  while(read(fd, &de, sizeof(de)) > 0){
    5300:	f6040a13          	addi	s4,s0,-160
    5304:	01000993          	li	s3,16
    if(de.name[0] == 'C' && de.name[2] == '\0'){
    5308:	04300a93          	li	s5,67
      if(i < 0 || i >= sizeof(fa)){
    530c:	02700b93          	li	s7,39
      fa[i] = 1;
    5310:	00100c13          	li	s8,1
  while(read(fd, &de, sizeof(de)) > 0){
    5314:	00098613          	mv	a2,s3
    5318:	000a0593          	mv	a1,s4
    531c:	00090513          	mv	a0,s2
    5320:	548010ef          	jal	6868 <read>
    5324:	08a05263          	blez	a0,53a8 <concreate+0x1c8>
    if(de.inum == 0)
    5328:	f6045783          	lhu	a5,-160(s0)
    532c:	fe0784e3          	beqz	a5,5314 <concreate+0x134>
    if(de.name[0] == 'C' && de.name[2] == '\0'){
    5330:	f6244783          	lbu	a5,-158(s0)
    5334:	ff5790e3          	bne	a5,s5,5314 <concreate+0x134>
    5338:	f6444783          	lbu	a5,-156(s0)
    533c:	fc079ce3          	bnez	a5,5314 <concreate+0x134>
      i = de.name[1] - '0';
    5340:	f6344783          	lbu	a5,-157(s0)
    5344:	fd07879b          	addiw	a5,a5,-48
      if(i < 0 || i >= sizeof(fa)){
    5348:	02fbe463          	bltu	s7,a5,5370 <concreate+0x190>
      if(fa[i]){
    534c:	fa078713          	addi	a4,a5,-96
    5350:	00870733          	add	a4,a4,s0
    5354:	fd074703          	lbu	a4,-48(a4)
    5358:	02071a63          	bnez	a4,538c <concreate+0x1ac>
      fa[i] = 1;
    535c:	fa078793          	addi	a5,a5,-96
    5360:	008787b3          	add	a5,a5,s0
    5364:	fd878823          	sb	s8,-48(a5)
      n++;
    5368:	001b0b1b          	addiw	s6,s6,1
    536c:	fa9ff06f          	j	5314 <concreate+0x134>
        printf("%s: concreate weird file %s\n", s, de.name);
    5370:	f6240613          	addi	a2,s0,-158
    5374:	000d0593          	mv	a1,s10
    5378:	00004517          	auipc	a0,0x4
    537c:	b1050513          	addi	a0,a0,-1264 # 8e88 <malloc+0x1e60>
    5380:	39d010ef          	jal	6f1c <printf>
        exit(1);
    5384:	00100513          	li	a0,1
    5388:	4bc010ef          	jal	6844 <exit>
        printf("%s: concreate duplicate file %s\n", s, de.name);
    538c:	f6240613          	addi	a2,s0,-158
    5390:	000d0593          	mv	a1,s10
    5394:	00004517          	auipc	a0,0x4
    5398:	b1450513          	addi	a0,a0,-1260 # 8ea8 <malloc+0x1e80>
    539c:	381010ef          	jal	6f1c <printf>
        exit(1);
    53a0:	00100513          	li	a0,1
    53a4:	4a0010ef          	jal	6844 <exit>
  close(fd);
    53a8:	00090513          	mv	a0,s2
    53ac:	4d4010ef          	jal	6880 <close>
  if(n != N){
    53b0:	02800793          	li	a5,40
    53b4:	00fb1c63          	bne	s6,a5,53cc <concreate+0x1ec>
    if(((i % 3) == 0 && pid == 0) ||
    53b8:	55555a37          	lui	s4,0x55555
    53bc:	556a0a13          	addi	s4,s4,1366 # 55555556 <base+0x5554481e>
      close(open(file, 0));
    53c0:	f9840993          	addi	s3,s0,-104
  for(i = 0; i < N; i++){
    53c4:	000b0a93          	mv	s5,s6
    53c8:	0a80006f          	j	5470 <concreate+0x290>
    printf("%s: concreate not enough files in directory listing\n", s);
    53cc:	000d0593          	mv	a1,s10
    53d0:	00004517          	auipc	a0,0x4
    53d4:	b0050513          	addi	a0,a0,-1280 # 8ed0 <malloc+0x1ea8>
    53d8:	345010ef          	jal	6f1c <printf>
    exit(1);
    53dc:	00100513          	li	a0,1
    53e0:	464010ef          	jal	6844 <exit>
      printf("%s: fork failed\n", s);
    53e4:	000d0593          	mv	a1,s10
    53e8:	00002517          	auipc	a0,0x2
    53ec:	68050513          	addi	a0,a0,1664 # 7a68 <malloc+0xa40>
    53f0:	32d010ef          	jal	6f1c <printf>
      exit(1);
    53f4:	00100513          	li	a0,1
    53f8:	44c010ef          	jal	6844 <exit>
      close(open(file, 0));
    53fc:	00000593          	li	a1,0
    5400:	00098513          	mv	a0,s3
    5404:	4a0010ef          	jal	68a4 <open>
    5408:	478010ef          	jal	6880 <close>
      close(open(file, 0));
    540c:	00000593          	li	a1,0
    5410:	00098513          	mv	a0,s3
    5414:	490010ef          	jal	68a4 <open>
    5418:	468010ef          	jal	6880 <close>
      close(open(file, 0));
    541c:	00000593          	li	a1,0
    5420:	00098513          	mv	a0,s3
    5424:	480010ef          	jal	68a4 <open>
    5428:	458010ef          	jal	6880 <close>
      close(open(file, 0));
    542c:	00000593          	li	a1,0
    5430:	00098513          	mv	a0,s3
    5434:	470010ef          	jal	68a4 <open>
    5438:	448010ef          	jal	6880 <close>
      close(open(file, 0));
    543c:	00000593          	li	a1,0
    5440:	00098513          	mv	a0,s3
    5444:	460010ef          	jal	68a4 <open>
    5448:	438010ef          	jal	6880 <close>
      close(open(file, 0));
    544c:	00000593          	li	a1,0
    5450:	00098513          	mv	a0,s3
    5454:	450010ef          	jal	68a4 <open>
    5458:	428010ef          	jal	6880 <close>
    if(pid == 0)
    545c:	08090863          	beqz	s2,54ec <concreate+0x30c>
      wait(0);
    5460:	00000513          	li	a0,0
    5464:	3ec010ef          	jal	6850 <wait>
  for(i = 0; i < N; i++){
    5468:	0014849b          	addiw	s1,s1,1
    546c:	0f548c63          	beq	s1,s5,5564 <concreate+0x384>
    file[1] = '0' + i;
    5470:	0304879b          	addiw	a5,s1,48
    5474:	f8f40ca3          	sb	a5,-103(s0)
    pid = fork();
    5478:	3c0010ef          	jal	6838 <fork>
    547c:	00050913          	mv	s2,a0
    if(pid < 0){
    5480:	f60542e3          	bltz	a0,53e4 <concreate+0x204>
    if(((i % 3) == 0 && pid == 0) ||
    5484:	03448733          	mul	a4,s1,s4
    5488:	02075713          	srli	a4,a4,0x20
    548c:	41f4d79b          	sraiw	a5,s1,0x1f
    5490:	40f7073b          	subw	a4,a4,a5
    5494:	0017179b          	slliw	a5,a4,0x1
    5498:	00e787bb          	addw	a5,a5,a4
    549c:	40f487bb          	subw	a5,s1,a5
    54a0:	00a7e733          	or	a4,a5,a0
    54a4:	0007071b          	sext.w	a4,a4
    54a8:	f4070ae3          	beqz	a4,53fc <concreate+0x21c>
       ((i % 3) == 1 && pid != 0)){
    54ac:	00050663          	beqz	a0,54b8 <concreate+0x2d8>
    if(((i % 3) == 0 && pid == 0) ||
    54b0:	fff78793          	addi	a5,a5,-1
       ((i % 3) == 1 && pid != 0)){
    54b4:	f40784e3          	beqz	a5,53fc <concreate+0x21c>
      unlink(file);
    54b8:	00098513          	mv	a0,s3
    54bc:	400010ef          	jal	68bc <unlink>
      unlink(file);
    54c0:	00098513          	mv	a0,s3
    54c4:	3f8010ef          	jal	68bc <unlink>
      unlink(file);
    54c8:	00098513          	mv	a0,s3
    54cc:	3f0010ef          	jal	68bc <unlink>
      unlink(file);
    54d0:	00098513          	mv	a0,s3
    54d4:	3e8010ef          	jal	68bc <unlink>
      unlink(file);
    54d8:	00098513          	mv	a0,s3
    54dc:	3e0010ef          	jal	68bc <unlink>
      unlink(file);
    54e0:	00098513          	mv	a0,s3
    54e4:	3d8010ef          	jal	68bc <unlink>
    54e8:	f75ff06f          	j	545c <concreate+0x27c>
      exit(0);
    54ec:	00000513          	li	a0,0
    54f0:	354010ef          	jal	6844 <exit>
      close(fd);
    54f4:	38c010ef          	jal	6880 <close>
    if(pid == 0) {
    54f8:	dd1ff06f          	j	52c8 <concreate+0xe8>
      close(fd);
    54fc:	384010ef          	jal	6880 <close>
      wait(&xstatus);
    5500:	000a8513          	mv	a0,s5
    5504:	34c010ef          	jal	6850 <wait>
      if(xstatus != 0)
    5508:	f5c42483          	lw	s1,-164(s0)
    550c:	dc0492e3          	bnez	s1,52d0 <concreate+0xf0>
  for(i = 0; i < N; i++){
    5510:	0019091b          	addiw	s2,s2,1
    5514:	dd4902e3          	beq	s2,s4,52d8 <concreate+0xf8>
    file[1] = '0' + i;
    5518:	0309079b          	addiw	a5,s2,48
    551c:	f8f40ca3          	sb	a5,-103(s0)
    unlink(file);
    5520:	00098513          	mv	a0,s3
    5524:	398010ef          	jal	68bc <unlink>
    pid = fork();
    5528:	310010ef          	jal	6838 <fork>
    if(pid && (i % 3) == 1){
    552c:	d2050ce3          	beqz	a0,5264 <concreate+0x84>
    5530:	036907b3          	mul	a5,s2,s6
    5534:	0207d793          	srli	a5,a5,0x20
    5538:	41f9571b          	sraiw	a4,s2,0x1f
    553c:	40e787bb          	subw	a5,a5,a4
    5540:	0017971b          	slliw	a4,a5,0x1
    5544:	00f707bb          	addw	a5,a4,a5
    5548:	40f907bb          	subw	a5,s2,a5
    554c:	d17784e3          	beq	a5,s7,5254 <concreate+0x74>
      fd = open(file, O_CREATE | O_RDWR);
    5550:	000c0593          	mv	a1,s8
    5554:	00098513          	mv	a0,s3
    5558:	34c010ef          	jal	68a4 <open>
      if(fd < 0){
    555c:	fa0550e3          	bgez	a0,54fc <concreate+0x31c>
    5560:	d41ff06f          	j	52a0 <concreate+0xc0>
}
    5564:	0a813083          	ld	ra,168(sp)
    5568:	0a013403          	ld	s0,160(sp)
    556c:	09813483          	ld	s1,152(sp)
    5570:	09013903          	ld	s2,144(sp)
    5574:	08813983          	ld	s3,136(sp)
    5578:	08013a03          	ld	s4,128(sp)
    557c:	07813a83          	ld	s5,120(sp)
    5580:	07013b03          	ld	s6,112(sp)
    5584:	06813b83          	ld	s7,104(sp)
    5588:	06013c03          	ld	s8,96(sp)
    558c:	05813c83          	ld	s9,88(sp)
    5590:	05013d03          	ld	s10,80(sp)
    5594:	0b010113          	addi	sp,sp,176
    5598:	00008067          	ret

000000000000559c <bigfile>:
{
    559c:	fc010113          	addi	sp,sp,-64
    55a0:	02113c23          	sd	ra,56(sp)
    55a4:	02813823          	sd	s0,48(sp)
    55a8:	02913423          	sd	s1,40(sp)
    55ac:	03213023          	sd	s2,32(sp)
    55b0:	01313c23          	sd	s3,24(sp)
    55b4:	01413823          	sd	s4,16(sp)
    55b8:	01513423          	sd	s5,8(sp)
    55bc:	01613023          	sd	s6,0(sp)
    55c0:	04010413          	addi	s0,sp,64
    55c4:	00050b13          	mv	s6,a0
  unlink("bigfile.dat");
    55c8:	00004517          	auipc	a0,0x4
    55cc:	94050513          	addi	a0,a0,-1728 # 8f08 <malloc+0x1ee0>
    55d0:	2ec010ef          	jal	68bc <unlink>
  fd = open("bigfile.dat", O_CREATE | O_RDWR);
    55d4:	20200593          	li	a1,514
    55d8:	00004517          	auipc	a0,0x4
    55dc:	93050513          	addi	a0,a0,-1744 # 8f08 <malloc+0x1ee0>
    55e0:	2c4010ef          	jal	68a4 <open>
  if(fd < 0){
    55e4:	0c054063          	bltz	a0,56a4 <bigfile+0x108>
    55e8:	00050a13          	mv	s4,a0
    55ec:	00000493          	li	s1,0
    memset(buf, i, SZ);
    55f0:	25800913          	li	s2,600
    55f4:	00008997          	auipc	s3,0x8
    55f8:	6c498993          	addi	s3,s3,1732 # dcb8 <buf>
  for(i = 0; i < N; i++){
    55fc:	01400a93          	li	s5,20
    memset(buf, i, SZ);
    5600:	00090613          	mv	a2,s2
    5604:	00048593          	mv	a1,s1
    5608:	00098513          	mv	a0,s3
    560c:	6b9000ef          	jal	64c4 <memset>
    if(write(fd, buf, SZ) != SZ){
    5610:	00090613          	mv	a2,s2
    5614:	00098593          	mv	a1,s3
    5618:	000a0513          	mv	a0,s4
    561c:	258010ef          	jal	6874 <write>
    5620:	09251e63          	bne	a0,s2,56bc <bigfile+0x120>
  for(i = 0; i < N; i++){
    5624:	0014849b          	addiw	s1,s1,1
    5628:	fd549ce3          	bne	s1,s5,5600 <bigfile+0x64>
  close(fd);
    562c:	000a0513          	mv	a0,s4
    5630:	250010ef          	jal	6880 <close>
  fd = open("bigfile.dat", 0);
    5634:	00000593          	li	a1,0
    5638:	00004517          	auipc	a0,0x4
    563c:	8d050513          	addi	a0,a0,-1840 # 8f08 <malloc+0x1ee0>
    5640:	264010ef          	jal	68a4 <open>
    5644:	00050a93          	mv	s5,a0
  total = 0;
    5648:	00000a13          	li	s4,0
  for(i = 0; ; i++){
    564c:	00000493          	li	s1,0
    cc = read(fd, buf, SZ/2);
    5650:	12c00993          	li	s3,300
    5654:	00008917          	auipc	s2,0x8
    5658:	66490913          	addi	s2,s2,1636 # dcb8 <buf>
  if(fd < 0){
    565c:	06054c63          	bltz	a0,56d4 <bigfile+0x138>
    cc = read(fd, buf, SZ/2);
    5660:	00098613          	mv	a2,s3
    5664:	00090593          	mv	a1,s2
    5668:	000a8513          	mv	a0,s5
    566c:	1fc010ef          	jal	6868 <read>
    if(cc < 0){
    5670:	06054e63          	bltz	a0,56ec <bigfile+0x150>
    if(cc == 0)
    5674:	0c050063          	beqz	a0,5734 <bigfile+0x198>
    if(cc != SZ/2){
    5678:	09351663          	bne	a0,s3,5704 <bigfile+0x168>
    if(buf[0] != i/2 || buf[SZ/2-1] != i/2){
    567c:	01f4d79b          	srliw	a5,s1,0x1f
    5680:	009787bb          	addw	a5,a5,s1
    5684:	4017d79b          	sraiw	a5,a5,0x1
    5688:	00094703          	lbu	a4,0(s2)
    568c:	08f71863          	bne	a4,a5,571c <bigfile+0x180>
    5690:	12b94703          	lbu	a4,299(s2)
    5694:	08f71463          	bne	a4,a5,571c <bigfile+0x180>
    total += cc;
    5698:	12ca0a1b          	addiw	s4,s4,300
  for(i = 0; ; i++){
    569c:	0014849b          	addiw	s1,s1,1
    cc = read(fd, buf, SZ/2);
    56a0:	fc1ff06f          	j	5660 <bigfile+0xc4>
    printf("%s: cannot create bigfile", s);
    56a4:	000b0593          	mv	a1,s6
    56a8:	00004517          	auipc	a0,0x4
    56ac:	87050513          	addi	a0,a0,-1936 # 8f18 <malloc+0x1ef0>
    56b0:	06d010ef          	jal	6f1c <printf>
    exit(1);
    56b4:	00100513          	li	a0,1
    56b8:	18c010ef          	jal	6844 <exit>
      printf("%s: write bigfile failed\n", s);
    56bc:	000b0593          	mv	a1,s6
    56c0:	00004517          	auipc	a0,0x4
    56c4:	87850513          	addi	a0,a0,-1928 # 8f38 <malloc+0x1f10>
    56c8:	055010ef          	jal	6f1c <printf>
      exit(1);
    56cc:	00100513          	li	a0,1
    56d0:	174010ef          	jal	6844 <exit>
    printf("%s: cannot open bigfile\n", s);
    56d4:	000b0593          	mv	a1,s6
    56d8:	00004517          	auipc	a0,0x4
    56dc:	88050513          	addi	a0,a0,-1920 # 8f58 <malloc+0x1f30>
    56e0:	03d010ef          	jal	6f1c <printf>
    exit(1);
    56e4:	00100513          	li	a0,1
    56e8:	15c010ef          	jal	6844 <exit>
      printf("%s: read bigfile failed\n", s);
    56ec:	000b0593          	mv	a1,s6
    56f0:	00004517          	auipc	a0,0x4
    56f4:	88850513          	addi	a0,a0,-1912 # 8f78 <malloc+0x1f50>
    56f8:	025010ef          	jal	6f1c <printf>
      exit(1);
    56fc:	00100513          	li	a0,1
    5700:	144010ef          	jal	6844 <exit>
      printf("%s: short read bigfile\n", s);
    5704:	000b0593          	mv	a1,s6
    5708:	00004517          	auipc	a0,0x4
    570c:	89050513          	addi	a0,a0,-1904 # 8f98 <malloc+0x1f70>
    5710:	00d010ef          	jal	6f1c <printf>
      exit(1);
    5714:	00100513          	li	a0,1
    5718:	12c010ef          	jal	6844 <exit>
      printf("%s: read bigfile wrong data\n", s);
    571c:	000b0593          	mv	a1,s6
    5720:	00004517          	auipc	a0,0x4
    5724:	89050513          	addi	a0,a0,-1904 # 8fb0 <malloc+0x1f88>
    5728:	7f4010ef          	jal	6f1c <printf>
      exit(1);
    572c:	00100513          	li	a0,1
    5730:	114010ef          	jal	6844 <exit>
  close(fd);
    5734:	000a8513          	mv	a0,s5
    5738:	148010ef          	jal	6880 <close>
  if(total != N*SZ){
    573c:	000037b7          	lui	a5,0x3
    5740:	ee078793          	addi	a5,a5,-288 # 2ee0 <sbrkmuch+0x8c>
    5744:	02fa1c63          	bne	s4,a5,577c <bigfile+0x1e0>
  unlink("bigfile.dat");
    5748:	00003517          	auipc	a0,0x3
    574c:	7c050513          	addi	a0,a0,1984 # 8f08 <malloc+0x1ee0>
    5750:	16c010ef          	jal	68bc <unlink>
}
    5754:	03813083          	ld	ra,56(sp)
    5758:	03013403          	ld	s0,48(sp)
    575c:	02813483          	ld	s1,40(sp)
    5760:	02013903          	ld	s2,32(sp)
    5764:	01813983          	ld	s3,24(sp)
    5768:	01013a03          	ld	s4,16(sp)
    576c:	00813a83          	ld	s5,8(sp)
    5770:	00013b03          	ld	s6,0(sp)
    5774:	04010113          	addi	sp,sp,64
    5778:	00008067          	ret
    printf("%s: read bigfile wrong total\n", s);
    577c:	000b0593          	mv	a1,s6
    5780:	00004517          	auipc	a0,0x4
    5784:	85050513          	addi	a0,a0,-1968 # 8fd0 <malloc+0x1fa8>
    5788:	794010ef          	jal	6f1c <printf>
    exit(1);
    578c:	00100513          	li	a0,1
    5790:	0b4010ef          	jal	6844 <exit>

0000000000005794 <bigargtest>:
{
    5794:	e4010113          	addi	sp,sp,-448
    5798:	1a113c23          	sd	ra,440(sp)
    579c:	1a813823          	sd	s0,432(sp)
    57a0:	1a913423          	sd	s1,424(sp)
    57a4:	1c010413          	addi	s0,sp,448
    57a8:	00050493          	mv	s1,a0
  unlink("bigarg-ok");
    57ac:	00004517          	auipc	a0,0x4
    57b0:	84450513          	addi	a0,a0,-1980 # 8ff0 <malloc+0x1fc8>
    57b4:	108010ef          	jal	68bc <unlink>
  pid = fork();
    57b8:	080010ef          	jal	6838 <fork>
  if(pid == 0){
    57bc:	04050263          	beqz	a0,5800 <bigargtest+0x6c>
  } else if(pid < 0){
    57c0:	0a054663          	bltz	a0,586c <bigargtest+0xd8>
  wait(&xstatus);
    57c4:	fdc40513          	addi	a0,s0,-36
    57c8:	088010ef          	jal	6850 <wait>
  if(xstatus != 0)
    57cc:	fdc42503          	lw	a0,-36(s0)
    57d0:	0a051a63          	bnez	a0,5884 <bigargtest+0xf0>
  fd = open("bigarg-ok", 0);
    57d4:	00000593          	li	a1,0
    57d8:	00004517          	auipc	a0,0x4
    57dc:	81850513          	addi	a0,a0,-2024 # 8ff0 <malloc+0x1fc8>
    57e0:	0c4010ef          	jal	68a4 <open>
  if(fd < 0){
    57e4:	0a054263          	bltz	a0,5888 <bigargtest+0xf4>
  close(fd);
    57e8:	098010ef          	jal	6880 <close>
}
    57ec:	1b813083          	ld	ra,440(sp)
    57f0:	1b013403          	ld	s0,432(sp)
    57f4:	1a813483          	ld	s1,424(sp)
    57f8:	1c010113          	addi	sp,sp,448
    57fc:	00008067          	ret
    memset(big, ' ', sizeof(big));
    5800:	19000613          	li	a2,400
    5804:	02000593          	li	a1,32
    5808:	e4840513          	addi	a0,s0,-440
    580c:	4b9000ef          	jal	64c4 <memset>
    big[sizeof(big)-1] = '\0';
    5810:	fc040ba3          	sb	zero,-41(s0)
    for(i = 0; i < MAXARG-1; i++)
    5814:	00005797          	auipc	a5,0x5
    5818:	c8c78793          	addi	a5,a5,-884 # a4a0 <args.1>
    581c:	00005697          	auipc	a3,0x5
    5820:	d7c68693          	addi	a3,a3,-644 # a598 <args.1+0xf8>
      args[i] = big;
    5824:	e4840713          	addi	a4,s0,-440
    5828:	00e7b023          	sd	a4,0(a5)
    for(i = 0; i < MAXARG-1; i++)
    582c:	00878793          	addi	a5,a5,8
    5830:	fed79ce3          	bne	a5,a3,5828 <bigargtest+0x94>
    args[MAXARG-1] = 0;
    5834:	00005797          	auipc	a5,0x5
    5838:	d607b223          	sd	zero,-668(a5) # a598 <args.1+0xf8>
    exec("echo", args);
    583c:	00005597          	auipc	a1,0x5
    5840:	c6458593          	addi	a1,a1,-924 # a4a0 <args.1>
    5844:	00002517          	auipc	a0,0x2
    5848:	99450513          	addi	a0,a0,-1644 # 71d8 <malloc+0x1b0>
    584c:	04c010ef          	jal	6898 <exec>
    fd = open("bigarg-ok", O_CREATE);
    5850:	20000593          	li	a1,512
    5854:	00003517          	auipc	a0,0x3
    5858:	79c50513          	addi	a0,a0,1948 # 8ff0 <malloc+0x1fc8>
    585c:	048010ef          	jal	68a4 <open>
    close(fd);
    5860:	020010ef          	jal	6880 <close>
    exit(0);
    5864:	00000513          	li	a0,0
    5868:	7dd000ef          	jal	6844 <exit>
    printf("%s: bigargtest: fork failed\n", s);
    586c:	00048593          	mv	a1,s1
    5870:	00003517          	auipc	a0,0x3
    5874:	79050513          	addi	a0,a0,1936 # 9000 <malloc+0x1fd8>
    5878:	6a4010ef          	jal	6f1c <printf>
    exit(1);
    587c:	00100513          	li	a0,1
    5880:	7c5000ef          	jal	6844 <exit>
    exit(xstatus);
    5884:	7c1000ef          	jal	6844 <exit>
    printf("%s: bigarg test failed!\n", s);
    5888:	00048593          	mv	a1,s1
    588c:	00003517          	auipc	a0,0x3
    5890:	79450513          	addi	a0,a0,1940 # 9020 <malloc+0x1ff8>
    5894:	688010ef          	jal	6f1c <printf>
    exit(1);
    5898:	00100513          	li	a0,1
    589c:	7a9000ef          	jal	6844 <exit>

00000000000058a0 <lazy_alloc>:
{
    58a0:	ff010113          	addi	sp,sp,-16
    58a4:	00113423          	sd	ra,8(sp)
    58a8:	00813023          	sd	s0,0(sp)
    58ac:	01010413          	addi	s0,sp,16
  prev_end = sbrklazy(REGION_SZ);
    58b0:	40000537          	lui	a0,0x40000
    58b4:	75d000ef          	jal	6810 <sbrklazy>
  if (prev_end == (char *) SBRK_ERROR) {
    58b8:	fff00793          	li	a5,-1
    58bc:	04f50263          	beq	a0,a5,5900 <lazy_alloc+0x60>
  for (i = prev_end + PGSIZE; i < new_end; i += 64 * PGSIZE)
    58c0:	00001637          	lui	a2,0x1
    58c4:	00c50633          	add	a2,a0,a2
    58c8:	400017b7          	lui	a5,0x40001
    58cc:	00f50733          	add	a4,a0,a5
    58d0:	00060793          	mv	a5,a2
    58d4:	000406b7          	lui	a3,0x40
    *(char **)i = i;
    58d8:	00f7b023          	sd	a5,0(a5) # 40001000 <base+0x3fff02c8>
  for (i = prev_end + PGSIZE; i < new_end; i += 64 * PGSIZE)
    58dc:	00d787b3          	add	a5,a5,a3
    58e0:	fee79ce3          	bne	a5,a4,58d8 <lazy_alloc+0x38>
  for (i = prev_end + PGSIZE; i < new_end; i += 64 * PGSIZE) {
    58e4:	000406b7          	lui	a3,0x40
    if (*(char **)i != i) {
    58e8:	00063783          	ld	a5,0(a2) # 1000 <unlinkread+0xc8>
    58ec:	02c79463          	bne	a5,a2,5914 <lazy_alloc+0x74>
  for (i = prev_end + PGSIZE; i < new_end; i += 64 * PGSIZE) {
    58f0:	00d60633          	add	a2,a2,a3
    58f4:	fee61ae3          	bne	a2,a4,58e8 <lazy_alloc+0x48>
  exit(0);
    58f8:	00000513          	li	a0,0
    58fc:	749000ef          	jal	6844 <exit>
    printf("sbrklazy() failed\n");
    5900:	00003517          	auipc	a0,0x3
    5904:	74050513          	addi	a0,a0,1856 # 9040 <malloc+0x2018>
    5908:	614010ef          	jal	6f1c <printf>
    exit(1);
    590c:	00100513          	li	a0,1
    5910:	735000ef          	jal	6844 <exit>
      printf("failed to read value from memory\n");
    5914:	00003517          	auipc	a0,0x3
    5918:	74450513          	addi	a0,a0,1860 # 9058 <malloc+0x2030>
    591c:	600010ef          	jal	6f1c <printf>
      exit(1);
    5920:	00100513          	li	a0,1
    5924:	721000ef          	jal	6844 <exit>

0000000000005928 <lazy_unmap>:
{
    5928:	fc010113          	addi	sp,sp,-64
    592c:	02113c23          	sd	ra,56(sp)
    5930:	02813823          	sd	s0,48(sp)
    5934:	04010413          	addi	s0,sp,64
  prev_end = sbrklazy(REGION_SZ);
    5938:	40000537          	lui	a0,0x40000
    593c:	6d5000ef          	jal	6810 <sbrklazy>
  if (prev_end == (char*)SBRK_ERROR) {
    5940:	fff00793          	li	a5,-1
    5944:	06f50663          	beq	a0,a5,59b0 <lazy_unmap+0x88>
    5948:	02913423          	sd	s1,40(sp)
    594c:	03213023          	sd	s2,32(sp)
    5950:	01313c23          	sd	s3,24(sp)
    5954:	01413823          	sd	s4,16(sp)
  for (i = prev_end + PGSIZE; i < new_end; i += PGSIZE * PGSIZE)
    5958:	00001937          	lui	s2,0x1
    595c:	01250933          	add	s2,a0,s2
    5960:	400017b7          	lui	a5,0x40001
    5964:	00f504b3          	add	s1,a0,a5
    5968:	00090793          	mv	a5,s2
    596c:	01000737          	lui	a4,0x1000
    *(char **)i = i;
    5970:	00f7b023          	sd	a5,0(a5) # 40001000 <base+0x3fff02c8>
  for (i = prev_end + PGSIZE; i < new_end; i += PGSIZE * PGSIZE)
    5974:	00e787b3          	add	a5,a5,a4
    5978:	fe979ce3          	bne	a5,s1,5970 <lazy_unmap+0x48>
      wait(&status);
    597c:	fcc40993          	addi	s3,s0,-52
  for (i = prev_end + PGSIZE; i < new_end; i += PGSIZE * PGSIZE) {
    5980:	01000a37          	lui	s4,0x1000
    pid = fork();
    5984:	6b5000ef          	jal	6838 <fork>
    if (pid < 0) {
    5988:	04054663          	bltz	a0,59d4 <lazy_unmap+0xac>
    } else if (pid == 0) {
    598c:	04050e63          	beqz	a0,59e8 <lazy_unmap+0xc0>
      wait(&status);
    5990:	00098513          	mv	a0,s3
    5994:	6bd000ef          	jal	6850 <wait>
      if (status == 0) {
    5998:	fcc42783          	lw	a5,-52(s0)
    599c:	06078063          	beqz	a5,59fc <lazy_unmap+0xd4>
  for (i = prev_end + PGSIZE; i < new_end; i += PGSIZE * PGSIZE) {
    59a0:	01490933          	add	s2,s2,s4
    59a4:	fe9910e3          	bne	s2,s1,5984 <lazy_unmap+0x5c>
  exit(0);
    59a8:	00000513          	li	a0,0
    59ac:	699000ef          	jal	6844 <exit>
    59b0:	02913423          	sd	s1,40(sp)
    59b4:	03213023          	sd	s2,32(sp)
    59b8:	01313c23          	sd	s3,24(sp)
    59bc:	01413823          	sd	s4,16(sp)
    printf("sbrklazy() failed\n");
    59c0:	00003517          	auipc	a0,0x3
    59c4:	68050513          	addi	a0,a0,1664 # 9040 <malloc+0x2018>
    59c8:	554010ef          	jal	6f1c <printf>
    exit(1);
    59cc:	00100513          	li	a0,1
    59d0:	675000ef          	jal	6844 <exit>
      printf("error forking\n");
    59d4:	00003517          	auipc	a0,0x3
    59d8:	6ac50513          	addi	a0,a0,1708 # 9080 <malloc+0x2058>
    59dc:	540010ef          	jal	6f1c <printf>
      exit(1);
    59e0:	00100513          	li	a0,1
    59e4:	661000ef          	jal	6844 <exit>
      sbrklazy(-1L * REGION_SZ);
    59e8:	c0000537          	lui	a0,0xc0000
    59ec:	625000ef          	jal	6810 <sbrklazy>
      *(char **)i = i;
    59f0:	01293023          	sd	s2,0(s2) # 1000 <unlinkread+0xc8>
      exit(0);
    59f4:	00000513          	li	a0,0
    59f8:	64d000ef          	jal	6844 <exit>
        printf("memory not unmapped\n");
    59fc:	00003517          	auipc	a0,0x3
    5a00:	69450513          	addi	a0,a0,1684 # 9090 <malloc+0x2068>
    5a04:	518010ef          	jal	6f1c <printf>
        exit(1);
    5a08:	00100513          	li	a0,1
    5a0c:	639000ef          	jal	6844 <exit>

0000000000005a10 <lazy_copy>:
{
    5a10:	f8010113          	addi	sp,sp,-128
    5a14:	06113c23          	sd	ra,120(sp)
    5a18:	06813823          	sd	s0,112(sp)
    5a1c:	06913423          	sd	s1,104(sp)
    5a20:	07213023          	sd	s2,96(sp)
    5a24:	05313c23          	sd	s3,88(sp)
    5a28:	05413823          	sd	s4,80(sp)
    5a2c:	05513423          	sd	s5,72(sp)
    5a30:	05613023          	sd	s6,64(sp)
    5a34:	03713c23          	sd	s7,56(sp)
    5a38:	08010413          	addi	s0,sp,128
    char *p = sbrk(0);
    5a3c:	00000513          	li	a0,0
    5a40:	5a9000ef          	jal	67e8 <sbrk>
    5a44:	00050493          	mv	s1,a0
    sbrklazy(4*PGSIZE);
    5a48:	00004537          	lui	a0,0x4
    5a4c:	5c5000ef          	jal	6810 <sbrklazy>
    open(p + 8192, 0);
    5a50:	00000593          	li	a1,0
    5a54:	00002537          	lui	a0,0x2
    5a58:	00a48533          	add	a0,s1,a0
    5a5c:	649000ef          	jal	68a4 <open>
    void *xx = sbrk(0);
    5a60:	00000513          	li	a0,0
    5a64:	585000ef          	jal	67e8 <sbrk>
    5a68:	00050493          	mv	s1,a0
    void *ret = sbrk(-(((uint64) xx)+1));
    5a6c:	fff54513          	not	a0,a0
    5a70:	0005051b          	sext.w	a0,a0
    5a74:	575000ef          	jal	67e8 <sbrk>
    if(ret != xx){
    5a78:	00a48e63          	beq	s1,a0,5a94 <lazy_copy+0x84>
    5a7c:	00050593          	mv	a1,a0
      printf("sbrk(sbrk(0)+1) returned %p, not old sz\n", ret);
    5a80:	00003517          	auipc	a0,0x3
    5a84:	62850513          	addi	a0,a0,1576 # 90a8 <malloc+0x2080>
    5a88:	494010ef          	jal	6f1c <printf>
      exit(1);
    5a8c:	00100513          	li	a0,1
    5a90:	5b5000ef          	jal	6844 <exit>
  unsigned long bad[] = {
    5a94:	00004797          	auipc	a5,0x4
    5a98:	c8c78793          	addi	a5,a5,-884 # 9720 <malloc+0x26f8>
    5a9c:	0787b503          	ld	a0,120(a5)
    5aa0:	0807b583          	ld	a1,128(a5)
    5aa4:	0887b603          	ld	a2,136(a5)
    5aa8:	0907b683          	ld	a3,144(a5)
    5aac:	0987b703          	ld	a4,152(a5)
    5ab0:	f8a43023          	sd	a0,-128(s0)
    5ab4:	f8b43423          	sd	a1,-120(s0)
    5ab8:	f8c43823          	sd	a2,-112(s0)
    5abc:	f8d43c23          	sd	a3,-104(s0)
    5ac0:	fae43023          	sd	a4,-96(s0)
    5ac4:	0a07b783          	ld	a5,160(a5)
    5ac8:	faf43423          	sd	a5,-88(s0)
  for(int i = 0; i < sizeof(bad)/sizeof(bad[0]); i++){
    5acc:	f8040913          	addi	s2,s0,-128
    int fd = open("README", 0);
    5ad0:	00002a97          	auipc	s5,0x2
    5ad4:	8e0a8a93          	addi	s5,s5,-1824 # 73b0 <malloc+0x388>
    if(read(fd, (char*)bad[i], 512) >= 0) { printf("read succeeded\n");  exit(1); }
    5ad8:	20000a13          	li	s4,512
    fd = open("junk", O_CREATE|O_RDWR|O_TRUNC);
    5adc:	60200b93          	li	s7,1538
    5ae0:	00001b17          	auipc	s6,0x1
    5ae4:	7e0b0b13          	addi	s6,s6,2016 # 72c0 <malloc+0x298>
    int fd = open("README", 0);
    5ae8:	00000593          	li	a1,0
    5aec:	000a8513          	mv	a0,s5
    5af0:	5b5000ef          	jal	68a4 <open>
    5af4:	00050493          	mv	s1,a0
    if(fd < 0) { printf("cannot open README\n"); exit(1); }
    5af8:	06054063          	bltz	a0,5b58 <lazy_copy+0x148>
    if(read(fd, (char*)bad[i], 512) >= 0) { printf("read succeeded\n");  exit(1); }
    5afc:	00093983          	ld	s3,0(s2)
    5b00:	000a0613          	mv	a2,s4
    5b04:	00098593          	mv	a1,s3
    5b08:	561000ef          	jal	6868 <read>
    5b0c:	06055063          	bgez	a0,5b6c <lazy_copy+0x15c>
    close(fd);
    5b10:	00048513          	mv	a0,s1
    5b14:	56d000ef          	jal	6880 <close>
    fd = open("junk", O_CREATE|O_RDWR|O_TRUNC);
    5b18:	000b8593          	mv	a1,s7
    5b1c:	000b0513          	mv	a0,s6
    5b20:	585000ef          	jal	68a4 <open>
    5b24:	00050493          	mv	s1,a0
    if(fd < 0) { printf("cannot open junk\n"); exit(1); }
    5b28:	04054c63          	bltz	a0,5b80 <lazy_copy+0x170>
    if(write(fd, (char*)bad[i], 512) >= 0) { printf("write succeeded\n"); exit(1); }
    5b2c:	000a0613          	mv	a2,s4
    5b30:	00098593          	mv	a1,s3
    5b34:	541000ef          	jal	6874 <write>
    5b38:	04055e63          	bgez	a0,5b94 <lazy_copy+0x184>
    close(fd);
    5b3c:	00048513          	mv	a0,s1
    5b40:	541000ef          	jal	6880 <close>
  for(int i = 0; i < sizeof(bad)/sizeof(bad[0]); i++){
    5b44:	00890913          	addi	s2,s2,8
    5b48:	fb040793          	addi	a5,s0,-80
    5b4c:	f8f91ee3          	bne	s2,a5,5ae8 <lazy_copy+0xd8>
  exit(0);
    5b50:	00000513          	li	a0,0
    5b54:	4f1000ef          	jal	6844 <exit>
    if(fd < 0) { printf("cannot open README\n"); exit(1); }
    5b58:	00003517          	auipc	a0,0x3
    5b5c:	58050513          	addi	a0,a0,1408 # 90d8 <malloc+0x20b0>
    5b60:	3bc010ef          	jal	6f1c <printf>
    5b64:	00100513          	li	a0,1
    5b68:	4dd000ef          	jal	6844 <exit>
    if(read(fd, (char*)bad[i], 512) >= 0) { printf("read succeeded\n");  exit(1); }
    5b6c:	00003517          	auipc	a0,0x3
    5b70:	58450513          	addi	a0,a0,1412 # 90f0 <malloc+0x20c8>
    5b74:	3a8010ef          	jal	6f1c <printf>
    5b78:	00100513          	li	a0,1
    5b7c:	4c9000ef          	jal	6844 <exit>
    if(fd < 0) { printf("cannot open junk\n"); exit(1); }
    5b80:	00003517          	auipc	a0,0x3
    5b84:	58050513          	addi	a0,a0,1408 # 9100 <malloc+0x20d8>
    5b88:	394010ef          	jal	6f1c <printf>
    5b8c:	00100513          	li	a0,1
    5b90:	4b5000ef          	jal	6844 <exit>
    if(write(fd, (char*)bad[i], 512) >= 0) { printf("write succeeded\n"); exit(1); }
    5b94:	00003517          	auipc	a0,0x3
    5b98:	58450513          	addi	a0,a0,1412 # 9118 <malloc+0x20f0>
    5b9c:	380010ef          	jal	6f1c <printf>
    5ba0:	00100513          	li	a0,1
    5ba4:	4a1000ef          	jal	6844 <exit>

0000000000005ba8 <lazy_sbrk>:
{
    5ba8:	fd010113          	addi	sp,sp,-48
    5bac:	02113423          	sd	ra,40(sp)
    5bb0:	02813023          	sd	s0,32(sp)
    5bb4:	00913c23          	sd	s1,24(sp)
    5bb8:	01213823          	sd	s2,16(sp)
    5bbc:	01313423          	sd	s3,8(sp)
    5bc0:	03010413          	addi	s0,sp,48
  char *p = sbrk(0);
    5bc4:	00000513          	li	a0,0
    5bc8:	421000ef          	jal	67e8 <sbrk>
    5bcc:	00050493          	mv	s1,a0
  while ((uint64)p < MAXVA-(1<<30)) {
    5bd0:	0ff00793          	li	a5,255
    5bd4:	01e79793          	slli	a5,a5,0x1e
    5bd8:	02f57263          	bgeu	a0,a5,5bfc <lazy_sbrk+0x54>
    p = sbrklazy(1<<30);
    5bdc:	400009b7          	lui	s3,0x40000
  while ((uint64)p < MAXVA-(1<<30)) {
    5be0:	00078913          	mv	s2,a5
    p = sbrklazy(1<<30);
    5be4:	00098513          	mv	a0,s3
    5be8:	429000ef          	jal	6810 <sbrklazy>
    p = sbrklazy(0);
    5bec:	00000513          	li	a0,0
    5bf0:	421000ef          	jal	6810 <sbrklazy>
    5bf4:	00050493          	mv	s1,a0
  while ((uint64)p < MAXVA-(1<<30)) {
    5bf8:	ff2566e3          	bltu	a0,s2,5be4 <lazy_sbrk+0x3c>
  int n = TRAPFRAME-PGSIZE-(uint64)p;
    5bfc:	ffffd937          	lui	s2,0xffffd
    5c00:	4099093b          	subw	s2,s2,s1
  char *p1 = sbrklazy(n);
    5c04:	00090513          	mv	a0,s2
    5c08:	409000ef          	jal	6810 <sbrklazy>
    5c0c:	00050613          	mv	a2,a0
  if (p1 < 0 || p1 != p) {
    5c10:	02950063          	beq	a0,s1,5c30 <lazy_sbrk+0x88>
    printf("sbrklazy(%d) returned %p, not expected %p\n", n, p1, p);
    5c14:	00048693          	mv	a3,s1
    5c18:	00090593          	mv	a1,s2
    5c1c:	00003517          	auipc	a0,0x3
    5c20:	51450513          	addi	a0,a0,1300 # 9130 <malloc+0x2108>
    5c24:	2f8010ef          	jal	6f1c <printf>
    exit(1);
    5c28:	00100513          	li	a0,1
    5c2c:	419000ef          	jal	6844 <exit>
  p = sbrk(PGSIZE);
    5c30:	00001537          	lui	a0,0x1
    5c34:	3b5000ef          	jal	67e8 <sbrk>
    5c38:	00050613          	mv	a2,a0
  if (p < 0 || (uint64)p != TRAPFRAME-PGSIZE) {
    5c3c:	040007b7          	lui	a5,0x4000
    5c40:	ffd78793          	addi	a5,a5,-3 # 3fffffd <base+0x3fef2c5>
    5c44:	00c79793          	slli	a5,a5,0xc
    5c48:	00f50e63          	beq	a0,a5,5c64 <lazy_sbrk+0xbc>
    printf("sbrk(%d) returned %p, not expected TRAPFRAME-PGSIZE\n", PGSIZE, p);
    5c4c:	000015b7          	lui	a1,0x1
    5c50:	00003517          	auipc	a0,0x3
    5c54:	51050513          	addi	a0,a0,1296 # 9160 <malloc+0x2138>
    5c58:	2c4010ef          	jal	6f1c <printf>
    exit(1);
    5c5c:	00100513          	li	a0,1
    5c60:	3e5000ef          	jal	6844 <exit>
  p[0] = 1;
    5c64:	040007b7          	lui	a5,0x4000
    5c68:	ffd78793          	addi	a5,a5,-3 # 3fffffd <base+0x3fef2c5>
    5c6c:	00c79793          	slli	a5,a5,0xc
    5c70:	00100713          	li	a4,1
    5c74:	00e78023          	sb	a4,0(a5)
  if (p[1] != 0) {
    5c78:	0017c783          	lbu	a5,1(a5)
    5c7c:	00078c63          	beqz	a5,5c94 <lazy_sbrk+0xec>
    printf("sbrk() returned non-zero-filled memory\n");
    5c80:	00003517          	auipc	a0,0x3
    5c84:	51850513          	addi	a0,a0,1304 # 9198 <malloc+0x2170>
    5c88:	294010ef          	jal	6f1c <printf>
    exit(1);
    5c8c:	00100513          	li	a0,1
    5c90:	3b5000ef          	jal	6844 <exit>
  p = sbrk(1);
    5c94:	00100513          	li	a0,1
    5c98:	351000ef          	jal	67e8 <sbrk>
    5c9c:	00050593          	mv	a1,a0
  if ((uint64)p != -1) {
    5ca0:	fff00793          	li	a5,-1
    5ca4:	00f50c63          	beq	a0,a5,5cbc <lazy_sbrk+0x114>
    printf("sbrk(1) returned %p, expected error\n", p);
    5ca8:	00003517          	auipc	a0,0x3
    5cac:	51850513          	addi	a0,a0,1304 # 91c0 <malloc+0x2198>
    5cb0:	26c010ef          	jal	6f1c <printf>
    exit(1);
    5cb4:	00100513          	li	a0,1
    5cb8:	38d000ef          	jal	6844 <exit>
  p = sbrklazy(1);
    5cbc:	00100513          	li	a0,1
    5cc0:	351000ef          	jal	6810 <sbrklazy>
    5cc4:	00050593          	mv	a1,a0
  if ((uint64)p != -1) {
    5cc8:	fff00793          	li	a5,-1
    5ccc:	00f50c63          	beq	a0,a5,5ce4 <lazy_sbrk+0x13c>
    printf("sbrklazy(1) returned %p, expected error\n", p);
    5cd0:	00003517          	auipc	a0,0x3
    5cd4:	51850513          	addi	a0,a0,1304 # 91e8 <malloc+0x21c0>
    5cd8:	244010ef          	jal	6f1c <printf>
    exit(1);
    5cdc:	00100513          	li	a0,1
    5ce0:	365000ef          	jal	6844 <exit>
  exit(0);
    5ce4:	00000513          	li	a0,0
    5ce8:	35d000ef          	jal	6844 <exit>

0000000000005cec <fsfull>:
{
    5cec:	f5010113          	addi	sp,sp,-176
    5cf0:	0a113423          	sd	ra,168(sp)
    5cf4:	0a813023          	sd	s0,160(sp)
    5cf8:	08913c23          	sd	s1,152(sp)
    5cfc:	09213823          	sd	s2,144(sp)
    5d00:	09313423          	sd	s3,136(sp)
    5d04:	09413023          	sd	s4,128(sp)
    5d08:	07513c23          	sd	s5,120(sp)
    5d0c:	07613823          	sd	s6,112(sp)
    5d10:	07713423          	sd	s7,104(sp)
    5d14:	07813023          	sd	s8,96(sp)
    5d18:	05913c23          	sd	s9,88(sp)
    5d1c:	05a13823          	sd	s10,80(sp)
    5d20:	05b13423          	sd	s11,72(sp)
    5d24:	0b010413          	addi	s0,sp,176
  printf("fsfull test\n");
    5d28:	00003517          	auipc	a0,0x3
    5d2c:	4f050513          	addi	a0,a0,1264 # 9218 <malloc+0x21f0>
    5d30:	1ec010ef          	jal	6f1c <printf>
  for(nfiles = 0; ; nfiles++){
    5d34:	00000493          	li	s1,0
    name[0] = 'f';
    5d38:	06600d93          	li	s11,102
    name[1] = '0' + nfiles / 1000;
    5d3c:	10625cb7          	lui	s9,0x10625
    5d40:	dd3c8c93          	addi	s9,s9,-557 # 10624dd3 <base+0x1061409b>
    name[2] = '0' + (nfiles % 1000) / 100;
    5d44:	51eb8ab7          	lui	s5,0x51eb8
    5d48:	51fa8a93          	addi	s5,s5,1311 # 51eb851f <base+0x51ea77e7>
    name[3] = '0' + (nfiles % 100) / 10;
    5d4c:	66666a37          	lui	s4,0x66666
    5d50:	667a0a13          	addi	s4,s4,1639 # 66666667 <base+0x6665592f>
    printf("writing %s\n", name);
    5d54:	f5040d13          	addi	s10,s0,-176
    name[0] = 'f';
    5d58:	f5b40823          	sb	s11,-176(s0)
    name[1] = '0' + nfiles / 1000;
    5d5c:	039487b3          	mul	a5,s1,s9
    5d60:	4267d793          	srai	a5,a5,0x26
    5d64:	41f4d69b          	sraiw	a3,s1,0x1f
    5d68:	40d787bb          	subw	a5,a5,a3
    5d6c:	0307871b          	addiw	a4,a5,48
    5d70:	f4e408a3          	sb	a4,-175(s0)
    name[2] = '0' + (nfiles % 1000) / 100;
    5d74:	3e800713          	li	a4,1000
    5d78:	02f707bb          	mulw	a5,a4,a5
    5d7c:	40f487bb          	subw	a5,s1,a5
    5d80:	03578733          	mul	a4,a5,s5
    5d84:	42575713          	srai	a4,a4,0x25
    5d88:	41f7d79b          	sraiw	a5,a5,0x1f
    5d8c:	40f707bb          	subw	a5,a4,a5
    5d90:	0307879b          	addiw	a5,a5,48
    5d94:	f4f40923          	sb	a5,-174(s0)
    name[3] = '0' + (nfiles % 100) / 10;
    5d98:	035487b3          	mul	a5,s1,s5
    5d9c:	4257d793          	srai	a5,a5,0x25
    5da0:	40d787bb          	subw	a5,a5,a3
    5da4:	06400713          	li	a4,100
    5da8:	02f707bb          	mulw	a5,a4,a5
    5dac:	40f487bb          	subw	a5,s1,a5
    5db0:	03478733          	mul	a4,a5,s4
    5db4:	42275713          	srai	a4,a4,0x22
    5db8:	41f7d79b          	sraiw	a5,a5,0x1f
    5dbc:	40f707bb          	subw	a5,a4,a5
    5dc0:	0307879b          	addiw	a5,a5,48
    5dc4:	f4f409a3          	sb	a5,-173(s0)
    name[4] = '0' + (nfiles % 10);
    5dc8:	03448733          	mul	a4,s1,s4
    5dcc:	42275713          	srai	a4,a4,0x22
    5dd0:	40d7073b          	subw	a4,a4,a3
    5dd4:	0027179b          	slliw	a5,a4,0x2
    5dd8:	00e787bb          	addw	a5,a5,a4
    5ddc:	0017979b          	slliw	a5,a5,0x1
    5de0:	40f487bb          	subw	a5,s1,a5
    5de4:	0307879b          	addiw	a5,a5,48
    5de8:	f4f40a23          	sb	a5,-172(s0)
    name[5] = '\0';
    5dec:	f4040aa3          	sb	zero,-171(s0)
    printf("writing %s\n", name);
    5df0:	000d0593          	mv	a1,s10
    5df4:	00003517          	auipc	a0,0x3
    5df8:	43450513          	addi	a0,a0,1076 # 9228 <malloc+0x2200>
    5dfc:	120010ef          	jal	6f1c <printf>
    int fd = open(name, O_CREATE|O_RDWR);
    5e00:	20200593          	li	a1,514
    5e04:	000d0513          	mv	a0,s10
    5e08:	29d000ef          	jal	68a4 <open>
    5e0c:	00050913          	mv	s2,a0
    if(fd < 0){
    5e10:	12055663          	bgez	a0,5f3c <fsfull+0x250>
      printf("open %s failed\n", name);
    5e14:	f5040593          	addi	a1,s0,-176
    5e18:	00003517          	auipc	a0,0x3
    5e1c:	42050513          	addi	a0,a0,1056 # 9238 <malloc+0x2210>
    5e20:	0fc010ef          	jal	6f1c <printf>
  while(nfiles >= 0){
    5e24:	0c04c863          	bltz	s1,5ef4 <fsfull+0x208>
    name[0] = 'f';
    5e28:	06600c13          	li	s8,102
    name[1] = '0' + nfiles / 1000;
    5e2c:	10625a37          	lui	s4,0x10625
    5e30:	dd3a0a13          	addi	s4,s4,-557 # 10624dd3 <base+0x1061409b>
    name[2] = '0' + (nfiles % 1000) / 100;
    5e34:	3e800b93          	li	s7,1000
    5e38:	51eb89b7          	lui	s3,0x51eb8
    5e3c:	51f98993          	addi	s3,s3,1311 # 51eb851f <base+0x51ea77e7>
    name[3] = '0' + (nfiles % 100) / 10;
    5e40:	06400b13          	li	s6,100
    5e44:	66666937          	lui	s2,0x66666
    5e48:	66790913          	addi	s2,s2,1639 # 66666667 <base+0x6665592f>
    unlink(name);
    5e4c:	f5040a93          	addi	s5,s0,-176
    name[0] = 'f';
    5e50:	f5840823          	sb	s8,-176(s0)
    name[1] = '0' + nfiles / 1000;
    5e54:	034487b3          	mul	a5,s1,s4
    5e58:	4267d793          	srai	a5,a5,0x26
    5e5c:	41f4d69b          	sraiw	a3,s1,0x1f
    5e60:	40d787bb          	subw	a5,a5,a3
    5e64:	0307871b          	addiw	a4,a5,48
    5e68:	f4e408a3          	sb	a4,-175(s0)
    name[2] = '0' + (nfiles % 1000) / 100;
    5e6c:	02fb87bb          	mulw	a5,s7,a5
    5e70:	40f487bb          	subw	a5,s1,a5
    5e74:	03378733          	mul	a4,a5,s3
    5e78:	42575713          	srai	a4,a4,0x25
    5e7c:	41f7d79b          	sraiw	a5,a5,0x1f
    5e80:	40f707bb          	subw	a5,a4,a5
    5e84:	0307879b          	addiw	a5,a5,48
    5e88:	f4f40923          	sb	a5,-174(s0)
    name[3] = '0' + (nfiles % 100) / 10;
    5e8c:	033487b3          	mul	a5,s1,s3
    5e90:	4257d793          	srai	a5,a5,0x25
    5e94:	40d787bb          	subw	a5,a5,a3
    5e98:	02fb07bb          	mulw	a5,s6,a5
    5e9c:	40f487bb          	subw	a5,s1,a5
    5ea0:	03278733          	mul	a4,a5,s2
    5ea4:	42275713          	srai	a4,a4,0x22
    5ea8:	41f7d79b          	sraiw	a5,a5,0x1f
    5eac:	40f707bb          	subw	a5,a4,a5
    5eb0:	0307879b          	addiw	a5,a5,48
    5eb4:	f4f409a3          	sb	a5,-173(s0)
    name[4] = '0' + (nfiles % 10);
    5eb8:	03248733          	mul	a4,s1,s2
    5ebc:	42275713          	srai	a4,a4,0x22
    5ec0:	40d7073b          	subw	a4,a4,a3
    5ec4:	0027179b          	slliw	a5,a4,0x2
    5ec8:	00e787bb          	addw	a5,a5,a4
    5ecc:	0017979b          	slliw	a5,a5,0x1
    5ed0:	40f487bb          	subw	a5,s1,a5
    5ed4:	0307879b          	addiw	a5,a5,48
    5ed8:	f4f40a23          	sb	a5,-172(s0)
    name[5] = '\0';
    5edc:	f4040aa3          	sb	zero,-171(s0)
    unlink(name);
    5ee0:	000a8513          	mv	a0,s5
    5ee4:	1d9000ef          	jal	68bc <unlink>
    nfiles--;
    5ee8:	fff4849b          	addiw	s1,s1,-1
  while(nfiles >= 0){
    5eec:	fff00793          	li	a5,-1
    5ef0:	f6f490e3          	bne	s1,a5,5e50 <fsfull+0x164>
  printf("fsfull test finished\n");
    5ef4:	00003517          	auipc	a0,0x3
    5ef8:	36450513          	addi	a0,a0,868 # 9258 <malloc+0x2230>
    5efc:	020010ef          	jal	6f1c <printf>
}
    5f00:	0a813083          	ld	ra,168(sp)
    5f04:	0a013403          	ld	s0,160(sp)
    5f08:	09813483          	ld	s1,152(sp)
    5f0c:	09013903          	ld	s2,144(sp)
    5f10:	08813983          	ld	s3,136(sp)
    5f14:	08013a03          	ld	s4,128(sp)
    5f18:	07813a83          	ld	s5,120(sp)
    5f1c:	07013b03          	ld	s6,112(sp)
    5f20:	06813b83          	ld	s7,104(sp)
    5f24:	06013c03          	ld	s8,96(sp)
    5f28:	05813c83          	ld	s9,88(sp)
    5f2c:	05013d03          	ld	s10,80(sp)
    5f30:	04813d83          	ld	s11,72(sp)
    5f34:	0b010113          	addi	sp,sp,176
    5f38:	00008067          	ret
    int total = 0;
    5f3c:	00000993          	li	s3,0
      int cc = write(fd, buf, BSIZE);
    5f40:	40000c13          	li	s8,1024
    5f44:	00008b97          	auipc	s7,0x8
    5f48:	d74b8b93          	addi	s7,s7,-652 # dcb8 <buf>
      if(cc < BSIZE)
    5f4c:	3ff00b13          	li	s6,1023
      int cc = write(fd, buf, BSIZE);
    5f50:	000c0613          	mv	a2,s8
    5f54:	000b8593          	mv	a1,s7
    5f58:	00090513          	mv	a0,s2
    5f5c:	119000ef          	jal	6874 <write>
      if(cc < BSIZE)
    5f60:	00ab5663          	bge	s6,a0,5f6c <fsfull+0x280>
      total += cc;
    5f64:	00a989bb          	addw	s3,s3,a0
    while(1){
    5f68:	fe9ff06f          	j	5f50 <fsfull+0x264>
    printf("wrote %d bytes\n", total);
    5f6c:	00098593          	mv	a1,s3
    5f70:	00003517          	auipc	a0,0x3
    5f74:	2d850513          	addi	a0,a0,728 # 9248 <malloc+0x2220>
    5f78:	7a5000ef          	jal	6f1c <printf>
    close(fd);
    5f7c:	00090513          	mv	a0,s2
    5f80:	101000ef          	jal	6880 <close>
    if(total == 0)
    5f84:	ea0980e3          	beqz	s3,5e24 <fsfull+0x138>
  for(nfiles = 0; ; nfiles++){
    5f88:	0014849b          	addiw	s1,s1,1
    5f8c:	dcdff06f          	j	5d58 <fsfull+0x6c>

0000000000005f90 <run>:
//

// run each test in its own process. run returns 1 if child's exit()
// indicates success.
int
run(void f(char *), char *s) {
    5f90:	fd010113          	addi	sp,sp,-48
    5f94:	02113423          	sd	ra,40(sp)
    5f98:	02813023          	sd	s0,32(sp)
    5f9c:	00913c23          	sd	s1,24(sp)
    5fa0:	01213823          	sd	s2,16(sp)
    5fa4:	03010413          	addi	s0,sp,48
    5fa8:	00050493          	mv	s1,a0
    5fac:	00058913          	mv	s2,a1
  int pid;
  int xstatus;

  printf("test %s: ", s);
    5fb0:	00003517          	auipc	a0,0x3
    5fb4:	2c050513          	addi	a0,a0,704 # 9270 <malloc+0x2248>
    5fb8:	765000ef          	jal	6f1c <printf>
  if((pid = fork()) < 0) {
    5fbc:	07d000ef          	jal	6838 <fork>
    5fc0:	04054263          	bltz	a0,6004 <run+0x74>
    printf("runtest: fork error\n");
    exit(1);
  }
  if(pid == 0) {
    5fc4:	04050a63          	beqz	a0,6018 <run+0x88>
    f(s);
    exit(0);
  } else {
    wait(&xstatus);
    5fc8:	fdc40513          	addi	a0,s0,-36
    5fcc:	085000ef          	jal	6850 <wait>
    if(xstatus != 0) 
    5fd0:	fdc42783          	lw	a5,-36(s0)
    5fd4:	04078a63          	beqz	a5,6028 <run+0x98>
      printf("FAILED\n");
    5fd8:	00003517          	auipc	a0,0x3
    5fdc:	2c050513          	addi	a0,a0,704 # 9298 <malloc+0x2270>
    5fe0:	73d000ef          	jal	6f1c <printf>
    else
      printf("OK\n");
    return xstatus == 0;
    5fe4:	fdc42503          	lw	a0,-36(s0)
  }
}
    5fe8:	00153513          	seqz	a0,a0
    5fec:	02813083          	ld	ra,40(sp)
    5ff0:	02013403          	ld	s0,32(sp)
    5ff4:	01813483          	ld	s1,24(sp)
    5ff8:	01013903          	ld	s2,16(sp)
    5ffc:	03010113          	addi	sp,sp,48
    6000:	00008067          	ret
    printf("runtest: fork error\n");
    6004:	00003517          	auipc	a0,0x3
    6008:	27c50513          	addi	a0,a0,636 # 9280 <malloc+0x2258>
    600c:	711000ef          	jal	6f1c <printf>
    exit(1);
    6010:	00100513          	li	a0,1
    6014:	031000ef          	jal	6844 <exit>
    f(s);
    6018:	00090513          	mv	a0,s2
    601c:	000480e7          	jalr	s1
    exit(0);
    6020:	00000513          	li	a0,0
    6024:	021000ef          	jal	6844 <exit>
      printf("OK\n");
    6028:	00003517          	auipc	a0,0x3
    602c:	27850513          	addi	a0,a0,632 # 92a0 <malloc+0x2278>
    6030:	6ed000ef          	jal	6f1c <printf>
    6034:	fb1ff06f          	j	5fe4 <run+0x54>

0000000000006038 <runtests>:

int
runtests(struct test *tests, char *justone, int continuous) {
    6038:	fd010113          	addi	sp,sp,-48
    603c:	02113423          	sd	ra,40(sp)
    6040:	02813023          	sd	s0,32(sp)
    6044:	00913c23          	sd	s1,24(sp)
    6048:	01313423          	sd	s3,8(sp)
    604c:	03010413          	addi	s0,sp,48
    6050:	00050493          	mv	s1,a0
  int ntests = 0;
  for (struct test *t = tests; t->s != 0; t++) {
    6054:	00853503          	ld	a0,8(a0)
    6058:	08050a63          	beqz	a0,60ec <runtests+0xb4>
    605c:	01213823          	sd	s2,16(sp)
    6060:	01413023          	sd	s4,0(sp)
    6064:	00058913          	mv	s2,a1
    if((justone == 0) || strcmp(t->s, justone) == 0) {
      ntests++;
      if(!run(t->f, t->s)){
        if(continuous != 2){
    6068:	ffe60613          	addi	a2,a2,-2
    606c:	00c03a33          	snez	s4,a2
  int ntests = 0;
    6070:	00000993          	li	s3,0
    6074:	0140006f          	j	6088 <runtests+0x50>
      ntests++;
    6078:	0019899b          	addiw	s3,s3,1
  for (struct test *t = tests; t->s != 0; t++) {
    607c:	01048493          	addi	s1,s1,16
    6080:	0084b503          	ld	a0,8(s1)
    6084:	04050263          	beqz	a0,60c8 <runtests+0x90>
    if((justone == 0) || strcmp(t->s, justone) == 0) {
    6088:	00090863          	beqz	s2,6098 <runtests+0x60>
    608c:	00090593          	mv	a1,s2
    6090:	3a4000ef          	jal	6434 <strcmp>
    6094:	fe0514e3          	bnez	a0,607c <runtests+0x44>
      if(!run(t->f, t->s)){
    6098:	0084b583          	ld	a1,8(s1)
    609c:	0004b503          	ld	a0,0(s1)
    60a0:	ef1ff0ef          	jal	5f90 <run>
        if(continuous != 2){
    60a4:	fc051ae3          	bnez	a0,6078 <runtests+0x40>
    60a8:	fc0a08e3          	beqz	s4,6078 <runtests+0x40>
          printf("SOME TESTS FAILED\n");
    60ac:	00003517          	auipc	a0,0x3
    60b0:	1fc50513          	addi	a0,a0,508 # 92a8 <malloc+0x2280>
    60b4:	669000ef          	jal	6f1c <printf>
          return -1;
    60b8:	fff00993          	li	s3,-1
    60bc:	01013903          	ld	s2,16(sp)
    60c0:	00013a03          	ld	s4,0(sp)
    60c4:	00c0006f          	j	60d0 <runtests+0x98>
    60c8:	01013903          	ld	s2,16(sp)
    60cc:	00013a03          	ld	s4,0(sp)
        }
      }
    }
  }
  return ntests;
}
    60d0:	00098513          	mv	a0,s3
    60d4:	02813083          	ld	ra,40(sp)
    60d8:	02013403          	ld	s0,32(sp)
    60dc:	01813483          	ld	s1,24(sp)
    60e0:	00813983          	ld	s3,8(sp)
    60e4:	03010113          	addi	sp,sp,48
    60e8:	00008067          	ret
  return ntests;
    60ec:	00000993          	li	s3,0
    60f0:	fe1ff06f          	j	60d0 <runtests+0x98>

00000000000060f4 <countfree>:


// use sbrk() to count how many free physical memory pages there are.
int
countfree()
{
    60f4:	fd010113          	addi	sp,sp,-48
    60f8:	02113423          	sd	ra,40(sp)
    60fc:	02813023          	sd	s0,32(sp)
    6100:	00913c23          	sd	s1,24(sp)
    6104:	01213823          	sd	s2,16(sp)
    6108:	01313423          	sd	s3,8(sp)
    610c:	01413023          	sd	s4,0(sp)
    6110:	03010413          	addi	s0,sp,48
  int n = 0;
  uint64 sz0 = (uint64)sbrk(0);
    6114:	00000513          	li	a0,0
    6118:	6d0000ef          	jal	67e8 <sbrk>
    611c:	00050a13          	mv	s4,a0
  int n = 0;
    6120:	00000493          	li	s1,0
  while(1){
    char *a = sbrk(PGSIZE);
    6124:	000019b7          	lui	s3,0x1
    if(a == SBRK_ERROR){
    6128:	fff00913          	li	s2,-1
    char *a = sbrk(PGSIZE);
    612c:	00098513          	mv	a0,s3
    6130:	6b8000ef          	jal	67e8 <sbrk>
    if(a == SBRK_ERROR){
    6134:	01250663          	beq	a0,s2,6140 <countfree+0x4c>
      break;
    }
    n += 1;
    6138:	0014849b          	addiw	s1,s1,1
  while(1){
    613c:	ff1ff06f          	j	612c <countfree+0x38>
  }
  sbrk(-((uint64)sbrk(0) - sz0));  
    6140:	00000513          	li	a0,0
    6144:	6a4000ef          	jal	67e8 <sbrk>
    6148:	40aa053b          	subw	a0,s4,a0
    614c:	69c000ef          	jal	67e8 <sbrk>
  return n;
}
    6150:	00048513          	mv	a0,s1
    6154:	02813083          	ld	ra,40(sp)
    6158:	02013403          	ld	s0,32(sp)
    615c:	01813483          	ld	s1,24(sp)
    6160:	01013903          	ld	s2,16(sp)
    6164:	00813983          	ld	s3,8(sp)
    6168:	00013a03          	ld	s4,0(sp)
    616c:	03010113          	addi	sp,sp,48
    6170:	00008067          	ret

0000000000006174 <drivetests>:

int
drivetests(int quick, int continuous, char *justone) {
    6174:	f9010113          	addi	sp,sp,-112
    6178:	06113423          	sd	ra,104(sp)
    617c:	06813023          	sd	s0,96(sp)
    6180:	04913c23          	sd	s1,88(sp)
    6184:	05213823          	sd	s2,80(sp)
    6188:	05313423          	sd	s3,72(sp)
    618c:	05413023          	sd	s4,64(sp)
    6190:	03513c23          	sd	s5,56(sp)
    6194:	03613823          	sd	s6,48(sp)
    6198:	03713423          	sd	s7,40(sp)
    619c:	03813023          	sd	s8,32(sp)
    61a0:	01913c23          	sd	s9,24(sp)
    61a4:	01a13823          	sd	s10,16(sp)
    61a8:	01b13423          	sd	s11,8(sp)
    61ac:	07010413          	addi	s0,sp,112
    61b0:	00050a93          	mv	s5,a0
    61b4:	00058993          	mv	s3,a1
    61b8:	00060a13          	mv	s4,a2
      printf("FAILED -- lost some free pages %d (out of %d)\n", free1, free0);
      if(continuous != 2) {
        return 1;
      }
    }
    if (justone != 0 && ntests == 0) {
    61bc:	00c03d33          	snez	s10,a2
    printf("usertests starting\n");
    61c0:	00003c17          	auipc	s8,0x3
    61c4:	100c0c13          	addi	s8,s8,256 # 92c0 <malloc+0x2298>
    n = runtests(quicktests, justone, continuous);
    61c8:	00004b97          	auipc	s7,0x4
    61cc:	e48b8b93          	addi	s7,s7,-440 # a010 <quicktests>
      if(continuous != 2) {
    61d0:	00200b13          	li	s6,2
      n = runtests(slowtests, justone, continuous);
    61d4:	00004c97          	auipc	s9,0x4
    61d8:	24cc8c93          	addi	s9,s9,588 # a420 <slowtests>
      printf("FAILED -- lost some free pages %d (out of %d)\n", free1, free0);
    61dc:	00003d97          	auipc	s11,0x3
    61e0:	11cd8d93          	addi	s11,s11,284 # 92f8 <malloc+0x22d0>
    61e4:	0500006f          	j	6234 <drivetests+0xc0>
      if(continuous != 2) {
    61e8:	0f699863          	bne	s3,s6,62d8 <drivetests+0x164>
    int ntests = 0;
    61ec:	00000493          	li	s1,0
    61f0:	06c0006f          	j	625c <drivetests+0xe8>
        printf("usertests slow tests starting\n");
    61f4:	00003517          	auipc	a0,0x3
    61f8:	0e450513          	addi	a0,a0,228 # 92d8 <malloc+0x22b0>
    61fc:	521000ef          	jal	6f1c <printf>
    6200:	0640006f          	j	6264 <drivetests+0xf0>
        if(continuous != 2) {
    6204:	07698c63          	beq	s3,s6,627c <drivetests+0x108>
          return 1;
    6208:	00100513          	li	a0,1
    620c:	0900006f          	j	629c <drivetests+0x128>
      printf("FAILED -- lost some free pages %d (out of %d)\n", free1, free0);
    6210:	00090613          	mv	a2,s2
    6214:	00050593          	mv	a1,a0
    6218:	000d8513          	mv	a0,s11
    621c:	501000ef          	jal	6f1c <printf>
      if(continuous != 2) {
    6220:	0d699063          	bne	s3,s6,62e0 <drivetests+0x16c>
    if (justone != 0 && ntests == 0) {
    6224:	00049863          	bnez	s1,6234 <drivetests+0xc0>
    6228:	000d0663          	beqz	s10,6234 <drivetests+0xc0>
    622c:	0600006f          	j	628c <drivetests+0x118>
      printf("NO TESTS EXECUTED\n");
      return 1;
    }
  } while(continuous);
    6230:	0a098c63          	beqz	s3,62e8 <drivetests+0x174>
    printf("usertests starting\n");
    6234:	000c0513          	mv	a0,s8
    6238:	4e5000ef          	jal	6f1c <printf>
    int free0 = countfree();
    623c:	eb9ff0ef          	jal	60f4 <countfree>
    6240:	00050913          	mv	s2,a0
    n = runtests(quicktests, justone, continuous);
    6244:	00098613          	mv	a2,s3
    6248:	000a0593          	mv	a1,s4
    624c:	000b8513          	mv	a0,s7
    6250:	de9ff0ef          	jal	6038 <runtests>
    6254:	00050493          	mv	s1,a0
    if (n < 0) {
    6258:	f80548e3          	bltz	a0,61e8 <drivetests+0x74>
    if(!quick) {
    625c:	020a9063          	bnez	s5,627c <drivetests+0x108>
      if (justone == 0)
    6260:	f80a0ae3          	beqz	s4,61f4 <drivetests+0x80>
      n = runtests(slowtests, justone, continuous);
    6264:	00098613          	mv	a2,s3
    6268:	000a0593          	mv	a1,s4
    626c:	000c8513          	mv	a0,s9
    6270:	dc9ff0ef          	jal	6038 <runtests>
      if (n < 0) {
    6274:	f80548e3          	bltz	a0,6204 <drivetests+0x90>
        ntests += n;
    6278:	00a484bb          	addw	s1,s1,a0
    if((free1 = countfree()) < free0) {
    627c:	e79ff0ef          	jal	60f4 <countfree>
    6280:	f92548e3          	blt	a0,s2,6210 <drivetests+0x9c>
    if (justone != 0 && ntests == 0) {
    6284:	fa0496e3          	bnez	s1,6230 <drivetests+0xbc>
    6288:	fa0d04e3          	beqz	s10,6230 <drivetests+0xbc>
      printf("NO TESTS EXECUTED\n");
    628c:	00003517          	auipc	a0,0x3
    6290:	09c50513          	addi	a0,a0,156 # 9328 <malloc+0x2300>
    6294:	489000ef          	jal	6f1c <printf>
      return 1;
    6298:	00100513          	li	a0,1
  return 0;
}
    629c:	06813083          	ld	ra,104(sp)
    62a0:	06013403          	ld	s0,96(sp)
    62a4:	05813483          	ld	s1,88(sp)
    62a8:	05013903          	ld	s2,80(sp)
    62ac:	04813983          	ld	s3,72(sp)
    62b0:	04013a03          	ld	s4,64(sp)
    62b4:	03813a83          	ld	s5,56(sp)
    62b8:	03013b03          	ld	s6,48(sp)
    62bc:	02813b83          	ld	s7,40(sp)
    62c0:	02013c03          	ld	s8,32(sp)
    62c4:	01813c83          	ld	s9,24(sp)
    62c8:	01013d03          	ld	s10,16(sp)
    62cc:	00813d83          	ld	s11,8(sp)
    62d0:	07010113          	addi	sp,sp,112
    62d4:	00008067          	ret
        return 1;
    62d8:	00100513          	li	a0,1
    62dc:	fc1ff06f          	j	629c <drivetests+0x128>
        return 1;
    62e0:	00100513          	li	a0,1
    62e4:	fb9ff06f          	j	629c <drivetests+0x128>
  return 0;
    62e8:	00098513          	mv	a0,s3
    62ec:	fb1ff06f          	j	629c <drivetests+0x128>

00000000000062f0 <main>:

int
main(int argc, char *argv[])
{
    62f0:	fe010113          	addi	sp,sp,-32
    62f4:	00113c23          	sd	ra,24(sp)
    62f8:	00813823          	sd	s0,16(sp)
    62fc:	00913423          	sd	s1,8(sp)
    6300:	01213023          	sd	s2,0(sp)
    6304:	02010413          	addi	s0,sp,32
    6308:	00050493          	mv	s1,a0
  int continuous = 0;
  int quick = 0;
  char *justone = 0;

  if(argc == 2 && strcmp(argv[1], "-q") == 0){
    630c:	00200793          	li	a5,2
    6310:	02f50463          	beq	a0,a5,6338 <main+0x48>
    continuous = 1;
  } else if(argc == 2 && strcmp(argv[1], "-C") == 0){
    continuous = 2;
  } else if(argc == 2 && argv[1][0] != '-'){
    justone = argv[1];
  } else if(argc > 1){
    6314:	00100793          	li	a5,1
    6318:	08a7c663          	blt	a5,a0,63a4 <main+0xb4>
  char *justone = 0;
    631c:	00000613          	li	a2,0
  int quick = 0;
    6320:	00000513          	li	a0,0
  int continuous = 0;
    6324:	00000593          	li	a1,0
    printf("Usage: usertests [-c] [-C] [-q] [testname]\n");
    exit(1);
  }
  if (drivetests(quick, continuous, justone)) {
    6328:	e4dff0ef          	jal	6174 <drivetests>
    632c:	0a050263          	beqz	a0,63d0 <main+0xe0>
    exit(1);
    6330:	00100513          	li	a0,1
    6334:	510000ef          	jal	6844 <exit>
    6338:	00058913          	mv	s2,a1
  if(argc == 2 && strcmp(argv[1], "-q") == 0){
    633c:	00003597          	auipc	a1,0x3
    6340:	00458593          	addi	a1,a1,4 # 9340 <malloc+0x2318>
    6344:	00893503          	ld	a0,8(s2)
    6348:	0ec000ef          	jal	6434 <strcmp>
    634c:	00050593          	mv	a1,a0
    6350:	00051863          	bnez	a0,6360 <main+0x70>
  char *justone = 0;
    6354:	00000613          	li	a2,0
    quick = 1;
    6358:	00100513          	li	a0,1
    635c:	fcdff06f          	j	6328 <main+0x38>
  } else if(argc == 2 && strcmp(argv[1], "-c") == 0){
    6360:	00003597          	auipc	a1,0x3
    6364:	fe858593          	addi	a1,a1,-24 # 9348 <malloc+0x2320>
    6368:	00893503          	ld	a0,8(s2)
    636c:	0c8000ef          	jal	6434 <strcmp>
    6370:	04050463          	beqz	a0,63b8 <main+0xc8>
  } else if(argc == 2 && strcmp(argv[1], "-C") == 0){
    6374:	00003597          	auipc	a1,0x3
    6378:	02458593          	addi	a1,a1,36 # 9398 <malloc+0x2370>
    637c:	00893503          	ld	a0,8(s2)
    6380:	0b4000ef          	jal	6434 <strcmp>
    6384:	04050063          	beqz	a0,63c4 <main+0xd4>
  } else if(argc == 2 && argv[1][0] != '-'){
    6388:	00893603          	ld	a2,8(s2)
    638c:	00064703          	lbu	a4,0(a2)
    6390:	02d00793          	li	a5,45
    6394:	00f70863          	beq	a4,a5,63a4 <main+0xb4>
  int quick = 0;
    6398:	00000513          	li	a0,0
  int continuous = 0;
    639c:	00000593          	li	a1,0
    63a0:	f89ff06f          	j	6328 <main+0x38>
    printf("Usage: usertests [-c] [-C] [-q] [testname]\n");
    63a4:	00003517          	auipc	a0,0x3
    63a8:	fac50513          	addi	a0,a0,-84 # 9350 <malloc+0x2328>
    63ac:	371000ef          	jal	6f1c <printf>
    exit(1);
    63b0:	00100513          	li	a0,1
    63b4:	490000ef          	jal	6844 <exit>
  char *justone = 0;
    63b8:	00000613          	li	a2,0
    continuous = 1;
    63bc:	00100593          	li	a1,1
    63c0:	f69ff06f          	j	6328 <main+0x38>
    continuous = 2;
    63c4:	00048593          	mv	a1,s1
  char *justone = 0;
    63c8:	00000613          	li	a2,0
    63cc:	f5dff06f          	j	6328 <main+0x38>
  }
  printf("ALL TESTS PASSED\n");
    63d0:	00003517          	auipc	a0,0x3
    63d4:	fb050513          	addi	a0,a0,-80 # 9380 <malloc+0x2358>
    63d8:	345000ef          	jal	6f1c <printf>
  exit(0);
    63dc:	00000513          	li	a0,0
    63e0:	464000ef          	jal	6844 <exit>

00000000000063e4 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
    63e4:	ff010113          	addi	sp,sp,-16
    63e8:	00113423          	sd	ra,8(sp)
    63ec:	00813023          	sd	s0,0(sp)
    63f0:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
    63f4:	efdff0ef          	jal	62f0 <main>
  exit(r);
    63f8:	44c000ef          	jal	6844 <exit>

00000000000063fc <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
    63fc:	ff010113          	addi	sp,sp,-16
    6400:	00113423          	sd	ra,8(sp)
    6404:	00813023          	sd	s0,0(sp)
    6408:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
    640c:	00050793          	mv	a5,a0
    6410:	00158593          	addi	a1,a1,1
    6414:	00178793          	addi	a5,a5,1
    6418:	fff5c703          	lbu	a4,-1(a1)
    641c:	fee78fa3          	sb	a4,-1(a5)
    6420:	fe0718e3          	bnez	a4,6410 <strcpy+0x14>
    ;
  return os;
}
    6424:	00813083          	ld	ra,8(sp)
    6428:	00013403          	ld	s0,0(sp)
    642c:	01010113          	addi	sp,sp,16
    6430:	00008067          	ret

0000000000006434 <strcmp>:

int
strcmp(const char *p, const char *q)
{
    6434:	ff010113          	addi	sp,sp,-16
    6438:	00113423          	sd	ra,8(sp)
    643c:	00813023          	sd	s0,0(sp)
    6440:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
    6444:	00054783          	lbu	a5,0(a0)
    6448:	00078e63          	beqz	a5,6464 <strcmp+0x30>
    644c:	0005c703          	lbu	a4,0(a1)
    6450:	00f71a63          	bne	a4,a5,6464 <strcmp+0x30>
    p++, q++;
    6454:	00150513          	addi	a0,a0,1
    6458:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
    645c:	00054783          	lbu	a5,0(a0)
    6460:	fe0796e3          	bnez	a5,644c <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
    6464:	0005c503          	lbu	a0,0(a1)
}
    6468:	40a7853b          	subw	a0,a5,a0
    646c:	00813083          	ld	ra,8(sp)
    6470:	00013403          	ld	s0,0(sp)
    6474:	01010113          	addi	sp,sp,16
    6478:	00008067          	ret

000000000000647c <strlen>:

uint
strlen(const char *s)
{
    647c:	ff010113          	addi	sp,sp,-16
    6480:	00113423          	sd	ra,8(sp)
    6484:	00813023          	sd	s0,0(sp)
    6488:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
    648c:	00054783          	lbu	a5,0(a0)
    6490:	02078663          	beqz	a5,64bc <strlen+0x40>
    6494:	00150793          	addi	a5,a0,1
    6498:	00078693          	mv	a3,a5
    649c:	00178793          	addi	a5,a5,1
    64a0:	fff7c703          	lbu	a4,-1(a5)
    64a4:	fe071ae3          	bnez	a4,6498 <strlen+0x1c>
    64a8:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
    64ac:	00813083          	ld	ra,8(sp)
    64b0:	00013403          	ld	s0,0(sp)
    64b4:	01010113          	addi	sp,sp,16
    64b8:	00008067          	ret
  for(n = 0; s[n]; n++)
    64bc:	00000513          	li	a0,0
    64c0:	fedff06f          	j	64ac <strlen+0x30>

00000000000064c4 <memset>:

void*
memset(void *dst, int c, uint n)
{
    64c4:	ff010113          	addi	sp,sp,-16
    64c8:	00113423          	sd	ra,8(sp)
    64cc:	00813023          	sd	s0,0(sp)
    64d0:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
    64d4:	02060063          	beqz	a2,64f4 <memset+0x30>
    64d8:	00050793          	mv	a5,a0
    64dc:	02061613          	slli	a2,a2,0x20
    64e0:	02065613          	srli	a2,a2,0x20
    64e4:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
    64e8:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
    64ec:	00178793          	addi	a5,a5,1
    64f0:	fee79ce3          	bne	a5,a4,64e8 <memset+0x24>
  }
  return dst;
}
    64f4:	00813083          	ld	ra,8(sp)
    64f8:	00013403          	ld	s0,0(sp)
    64fc:	01010113          	addi	sp,sp,16
    6500:	00008067          	ret

0000000000006504 <strchr>:

char*
strchr(const char *s, char c)
{
    6504:	ff010113          	addi	sp,sp,-16
    6508:	00113423          	sd	ra,8(sp)
    650c:	00813023          	sd	s0,0(sp)
    6510:	01010413          	addi	s0,sp,16
  for(; *s; s++)
    6514:	00054783          	lbu	a5,0(a0)
    6518:	02078463          	beqz	a5,6540 <strchr+0x3c>
    if(*s == c)
    651c:	00f58a63          	beq	a1,a5,6530 <strchr+0x2c>
  for(; *s; s++)
    6520:	00150513          	addi	a0,a0,1
    6524:	00054783          	lbu	a5,0(a0)
    6528:	fe079ae3          	bnez	a5,651c <strchr+0x18>
      return (char*)s;
  return 0;
    652c:	00000513          	li	a0,0
}
    6530:	00813083          	ld	ra,8(sp)
    6534:	00013403          	ld	s0,0(sp)
    6538:	01010113          	addi	sp,sp,16
    653c:	00008067          	ret
  return 0;
    6540:	00000513          	li	a0,0
    6544:	fedff06f          	j	6530 <strchr+0x2c>

0000000000006548 <gets>:

char*
gets(char *buf, int max)
{
    6548:	fa010113          	addi	sp,sp,-96
    654c:	04113c23          	sd	ra,88(sp)
    6550:	04813823          	sd	s0,80(sp)
    6554:	04913423          	sd	s1,72(sp)
    6558:	05213023          	sd	s2,64(sp)
    655c:	03313c23          	sd	s3,56(sp)
    6560:	03413823          	sd	s4,48(sp)
    6564:	03513423          	sd	s5,40(sp)
    6568:	03613023          	sd	s6,32(sp)
    656c:	01713c23          	sd	s7,24(sp)
    6570:	01813823          	sd	s8,16(sp)
    6574:	06010413          	addi	s0,sp,96
    6578:	00050b93          	mv	s7,a0
    657c:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    6580:	00050913          	mv	s2,a0
    6584:	00000493          	li	s1,0
    cc = read(0, &c, 1);
    6588:	faf40b13          	addi	s6,s0,-81
    658c:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
    6590:	00048c13          	mv	s8,s1
    6594:	0014899b          	addiw	s3,s1,1
    6598:	00098493          	mv	s1,s3
    659c:	0349dc63          	bge	s3,s4,65d4 <gets+0x8c>
    cc = read(0, &c, 1);
    65a0:	000a8613          	mv	a2,s5
    65a4:	000b0593          	mv	a1,s6
    65a8:	00000513          	li	a0,0
    65ac:	2bc000ef          	jal	6868 <read>
    if(cc < 1)
    65b0:	02a05263          	blez	a0,65d4 <gets+0x8c>
      break;
    buf[i++] = c;
    65b4:	faf44783          	lbu	a5,-81(s0)
    65b8:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
    65bc:	00190913          	addi	s2,s2,1
    65c0:	ff678713          	addi	a4,a5,-10
    65c4:	00070663          	beqz	a4,65d0 <gets+0x88>
    65c8:	ff378793          	addi	a5,a5,-13
    65cc:	fc0792e3          	bnez	a5,6590 <gets+0x48>
    buf[i++] = c;
    65d0:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
    65d4:	018b8c33          	add	s8,s7,s8
    65d8:	000c0023          	sb	zero,0(s8)
  return buf;
}
    65dc:	000b8513          	mv	a0,s7
    65e0:	05813083          	ld	ra,88(sp)
    65e4:	05013403          	ld	s0,80(sp)
    65e8:	04813483          	ld	s1,72(sp)
    65ec:	04013903          	ld	s2,64(sp)
    65f0:	03813983          	ld	s3,56(sp)
    65f4:	03013a03          	ld	s4,48(sp)
    65f8:	02813a83          	ld	s5,40(sp)
    65fc:	02013b03          	ld	s6,32(sp)
    6600:	01813b83          	ld	s7,24(sp)
    6604:	01013c03          	ld	s8,16(sp)
    6608:	06010113          	addi	sp,sp,96
    660c:	00008067          	ret

0000000000006610 <stat>:

int
stat(const char *n, struct stat *st)
{
    6610:	fe010113          	addi	sp,sp,-32
    6614:	00113c23          	sd	ra,24(sp)
    6618:	00813823          	sd	s0,16(sp)
    661c:	01213023          	sd	s2,0(sp)
    6620:	02010413          	addi	s0,sp,32
    6624:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
    6628:	00000593          	li	a1,0
    662c:	278000ef          	jal	68a4 <open>
  if(fd < 0)
    6630:	02054e63          	bltz	a0,666c <stat+0x5c>
    6634:	00913423          	sd	s1,8(sp)
    6638:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
    663c:	00090593          	mv	a1,s2
    6640:	288000ef          	jal	68c8 <fstat>
    6644:	00050913          	mv	s2,a0
  close(fd);
    6648:	00048513          	mv	a0,s1
    664c:	234000ef          	jal	6880 <close>
  return r;
    6650:	00813483          	ld	s1,8(sp)
}
    6654:	00090513          	mv	a0,s2
    6658:	01813083          	ld	ra,24(sp)
    665c:	01013403          	ld	s0,16(sp)
    6660:	00013903          	ld	s2,0(sp)
    6664:	02010113          	addi	sp,sp,32
    6668:	00008067          	ret
    return -1;
    666c:	fff00793          	li	a5,-1
    6670:	00078913          	mv	s2,a5
    6674:	fe1ff06f          	j	6654 <stat+0x44>

0000000000006678 <atoi>:

int
atoi(const char *s)
{
    6678:	ff010113          	addi	sp,sp,-16
    667c:	00113423          	sd	ra,8(sp)
    6680:	00813023          	sd	s0,0(sp)
    6684:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    6688:	00054683          	lbu	a3,0(a0)
    668c:	fd06879b          	addiw	a5,a3,-48 # 3ffd0 <base+0x2f298>
    6690:	0ff7f793          	zext.b	a5,a5
    6694:	00900613          	li	a2,9
    6698:	04f66263          	bltu	a2,a5,66dc <atoi+0x64>
    669c:	00050713          	mv	a4,a0
  n = 0;
    66a0:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
    66a4:	00170713          	addi	a4,a4,1 # 1000001 <base+0xfef2c9>
    66a8:	0025179b          	slliw	a5,a0,0x2
    66ac:	00a787bb          	addw	a5,a5,a0
    66b0:	0017979b          	slliw	a5,a5,0x1
    66b4:	00d787bb          	addw	a5,a5,a3
    66b8:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
    66bc:	00074683          	lbu	a3,0(a4)
    66c0:	fd06879b          	addiw	a5,a3,-48
    66c4:	0ff7f793          	zext.b	a5,a5
    66c8:	fcf67ee3          	bgeu	a2,a5,66a4 <atoi+0x2c>
  return n;
}
    66cc:	00813083          	ld	ra,8(sp)
    66d0:	00013403          	ld	s0,0(sp)
    66d4:	01010113          	addi	sp,sp,16
    66d8:	00008067          	ret
  n = 0;
    66dc:	00000513          	li	a0,0
    66e0:	fedff06f          	j	66cc <atoi+0x54>

00000000000066e4 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
    66e4:	ff010113          	addi	sp,sp,-16
    66e8:	00113423          	sd	ra,8(sp)
    66ec:	00813023          	sd	s0,0(sp)
    66f0:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
    66f4:	02b57e63          	bgeu	a0,a1,6730 <memmove+0x4c>
    while(n-- > 0)
    66f8:	02c05463          	blez	a2,6720 <memmove+0x3c>
    66fc:	02061613          	slli	a2,a2,0x20
    6700:	02065613          	srli	a2,a2,0x20
    6704:	00c507b3          	add	a5,a0,a2
  dst = vdst;
    6708:	00050713          	mv	a4,a0
      *dst++ = *src++;
    670c:	00158593          	addi	a1,a1,1
    6710:	00170713          	addi	a4,a4,1
    6714:	fff5c683          	lbu	a3,-1(a1)
    6718:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
    671c:	fee798e3          	bne	a5,a4,670c <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
    6720:	00813083          	ld	ra,8(sp)
    6724:	00013403          	ld	s0,0(sp)
    6728:	01010113          	addi	sp,sp,16
    672c:	00008067          	ret
    while(n-- > 0)
    6730:	fec058e3          	blez	a2,6720 <memmove+0x3c>
    dst += n;
    6734:	00c50733          	add	a4,a0,a2
    src += n;
    6738:	00c585b3          	add	a1,a1,a2
    673c:	fff6079b          	addiw	a5,a2,-1
    6740:	02079793          	slli	a5,a5,0x20
    6744:	0207d793          	srli	a5,a5,0x20
    6748:	fff7c793          	not	a5,a5
    674c:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
    6750:	fff58593          	addi	a1,a1,-1
    6754:	fff70713          	addi	a4,a4,-1
    6758:	0005c683          	lbu	a3,0(a1)
    675c:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
    6760:	fef718e3          	bne	a4,a5,6750 <memmove+0x6c>
    6764:	fbdff06f          	j	6720 <memmove+0x3c>

0000000000006768 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
    6768:	ff010113          	addi	sp,sp,-16
    676c:	00113423          	sd	ra,8(sp)
    6770:	00813023          	sd	s0,0(sp)
    6774:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
    6778:	04060263          	beqz	a2,67bc <memcmp+0x54>
    677c:	02061613          	slli	a2,a2,0x20
    6780:	02065613          	srli	a2,a2,0x20
    6784:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
    6788:	00054783          	lbu	a5,0(a0)
    678c:	0005c703          	lbu	a4,0(a1)
    6790:	00e79c63          	bne	a5,a4,67a8 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
    6794:	00150513          	addi	a0,a0,1
    p2++;
    6798:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
    679c:	fed516e3          	bne	a0,a3,6788 <memcmp+0x20>
  }
  return 0;
    67a0:	00000513          	li	a0,0
    67a4:	0080006f          	j	67ac <memcmp+0x44>
      return *p1 - *p2;
    67a8:	40e7853b          	subw	a0,a5,a4
}
    67ac:	00813083          	ld	ra,8(sp)
    67b0:	00013403          	ld	s0,0(sp)
    67b4:	01010113          	addi	sp,sp,16
    67b8:	00008067          	ret
  return 0;
    67bc:	00000513          	li	a0,0
    67c0:	fedff06f          	j	67ac <memcmp+0x44>

00000000000067c4 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
    67c4:	ff010113          	addi	sp,sp,-16
    67c8:	00113423          	sd	ra,8(sp)
    67cc:	00813023          	sd	s0,0(sp)
    67d0:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
    67d4:	f11ff0ef          	jal	66e4 <memmove>
}
    67d8:	00813083          	ld	ra,8(sp)
    67dc:	00013403          	ld	s0,0(sp)
    67e0:	01010113          	addi	sp,sp,16
    67e4:	00008067          	ret

00000000000067e8 <sbrk>:

char *
sbrk(int n) {
    67e8:	ff010113          	addi	sp,sp,-16
    67ec:	00113423          	sd	ra,8(sp)
    67f0:	00813023          	sd	s0,0(sp)
    67f4:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
    67f8:	00100593          	li	a1,1
    67fc:	114000ef          	jal	6910 <sys_sbrk>
}
    6800:	00813083          	ld	ra,8(sp)
    6804:	00013403          	ld	s0,0(sp)
    6808:	01010113          	addi	sp,sp,16
    680c:	00008067          	ret

0000000000006810 <sbrklazy>:

char *
sbrklazy(int n) {
    6810:	ff010113          	addi	sp,sp,-16
    6814:	00113423          	sd	ra,8(sp)
    6818:	00813023          	sd	s0,0(sp)
    681c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
    6820:	00200593          	li	a1,2
    6824:	0ec000ef          	jal	6910 <sys_sbrk>
}
    6828:	00813083          	ld	ra,8(sp)
    682c:	00013403          	ld	s0,0(sp)
    6830:	01010113          	addi	sp,sp,16
    6834:	00008067          	ret

0000000000006838 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
    6838:	00100893          	li	a7,1
 ecall
    683c:	00000073          	ecall
 ret
    6840:	00008067          	ret

0000000000006844 <exit>:
.global exit
exit:
 li a7, SYS_exit
    6844:	00200893          	li	a7,2
 ecall
    6848:	00000073          	ecall
 ret
    684c:	00008067          	ret

0000000000006850 <wait>:
.global wait
wait:
 li a7, SYS_wait
    6850:	00300893          	li	a7,3
 ecall
    6854:	00000073          	ecall
 ret
    6858:	00008067          	ret

000000000000685c <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
    685c:	00400893          	li	a7,4
 ecall
    6860:	00000073          	ecall
 ret
    6864:	00008067          	ret

0000000000006868 <read>:
.global read
read:
 li a7, SYS_read
    6868:	00500893          	li	a7,5
 ecall
    686c:	00000073          	ecall
 ret
    6870:	00008067          	ret

0000000000006874 <write>:
.global write
write:
 li a7, SYS_write
    6874:	01000893          	li	a7,16
 ecall
    6878:	00000073          	ecall
 ret
    687c:	00008067          	ret

0000000000006880 <close>:
.global close
close:
 li a7, SYS_close
    6880:	01500893          	li	a7,21
 ecall
    6884:	00000073          	ecall
 ret
    6888:	00008067          	ret

000000000000688c <kill>:
.global kill
kill:
 li a7, SYS_kill
    688c:	00600893          	li	a7,6
 ecall
    6890:	00000073          	ecall
 ret
    6894:	00008067          	ret

0000000000006898 <exec>:
.global exec
exec:
 li a7, SYS_exec
    6898:	00700893          	li	a7,7
 ecall
    689c:	00000073          	ecall
 ret
    68a0:	00008067          	ret

00000000000068a4 <open>:
.global open
open:
 li a7, SYS_open
    68a4:	00f00893          	li	a7,15
 ecall
    68a8:	00000073          	ecall
 ret
    68ac:	00008067          	ret

00000000000068b0 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
    68b0:	01100893          	li	a7,17
 ecall
    68b4:	00000073          	ecall
 ret
    68b8:	00008067          	ret

00000000000068bc <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
    68bc:	01200893          	li	a7,18
 ecall
    68c0:	00000073          	ecall
 ret
    68c4:	00008067          	ret

00000000000068c8 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
    68c8:	00800893          	li	a7,8
 ecall
    68cc:	00000073          	ecall
 ret
    68d0:	00008067          	ret

00000000000068d4 <link>:
.global link
link:
 li a7, SYS_link
    68d4:	01300893          	li	a7,19
 ecall
    68d8:	00000073          	ecall
 ret
    68dc:	00008067          	ret

00000000000068e0 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
    68e0:	01400893          	li	a7,20
 ecall
    68e4:	00000073          	ecall
 ret
    68e8:	00008067          	ret

00000000000068ec <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
    68ec:	00900893          	li	a7,9
 ecall
    68f0:	00000073          	ecall
 ret
    68f4:	00008067          	ret

00000000000068f8 <dup>:
.global dup
dup:
 li a7, SYS_dup
    68f8:	00a00893          	li	a7,10
 ecall
    68fc:	00000073          	ecall
 ret
    6900:	00008067          	ret

0000000000006904 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
    6904:	00b00893          	li	a7,11
 ecall
    6908:	00000073          	ecall
 ret
    690c:	00008067          	ret

0000000000006910 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
    6910:	00c00893          	li	a7,12
 ecall
    6914:	00000073          	ecall
 ret
    6918:	00008067          	ret

000000000000691c <pause>:
.global pause
pause:
 li a7, SYS_pause
    691c:	00d00893          	li	a7,13
 ecall
    6920:	00000073          	ecall
 ret
    6924:	00008067          	ret

0000000000006928 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
    6928:	00e00893          	li	a7,14
 ecall
    692c:	00000073          	ecall
 ret
    6930:	00008067          	ret

0000000000006934 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
    6934:	00004617          	auipc	a2,0x4
    6938:	b5c62603          	lw	a2,-1188(a2) # a490 <putc_n>
    693c:	00c04463          	bgtz	a2,6944 <putc_flush+0x10>
    6940:	00008067          	ret
{
    6944:	ff010113          	addi	sp,sp,-16
    6948:	00113423          	sd	ra,8(sp)
    694c:	00813023          	sd	s0,0(sp)
    6950:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
    6954:	0000a597          	auipc	a1,0xa
    6958:	36458593          	addi	a1,a1,868 # 10cb8 <putc_buf>
    695c:	00003517          	auipc	a0,0x3
    6960:	6ac52503          	lw	a0,1708(a0) # a008 <putc_fd>
    6964:	f11ff0ef          	jal	6874 <write>
    putc_n = 0;
    6968:	00004797          	auipc	a5,0x4
    696c:	b207a423          	sw	zero,-1240(a5) # a490 <putc_n>
  }
}
    6970:	00813083          	ld	ra,8(sp)
    6974:	00013403          	ld	s0,0(sp)
    6978:	01010113          	addi	sp,sp,16
    697c:	00008067          	ret

0000000000006980 <putc>:

static void
putc(int fd, char c)
{
    6980:	fe010113          	addi	sp,sp,-32
    6984:	00113c23          	sd	ra,24(sp)
    6988:	00813823          	sd	s0,16(sp)
    698c:	00913423          	sd	s1,8(sp)
    6990:	02010413          	addi	s0,sp,32
    6994:	00058493          	mv	s1,a1
  if (putc_fd != fd)
    6998:	00003797          	auipc	a5,0x3
    699c:	6707a783          	lw	a5,1648(a5) # a008 <putc_fd>
    69a0:	04a79663          	bne	a5,a0,69ec <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
    69a4:	00004717          	auipc	a4,0x4
    69a8:	aec70713          	addi	a4,a4,-1300 # a490 <putc_n>
    69ac:	00072683          	lw	a3,0(a4)
    69b0:	0016879b          	addiw	a5,a3,1
    69b4:	00f72023          	sw	a5,0(a4)
    69b8:	0000a717          	auipc	a4,0xa
    69bc:	30070713          	addi	a4,a4,768 # 10cb8 <putc_buf>
    69c0:	00d70733          	add	a4,a4,a3
    69c4:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
    69c8:	ff648493          	addi	s1,s1,-10
    69cc:	02048e63          	beqz	s1,6a08 <putc+0x88>
    69d0:	f8078793          	addi	a5,a5,-128
    69d4:	02078a63          	beqz	a5,6a08 <putc+0x88>
    putc_flush();
}
    69d8:	01813083          	ld	ra,24(sp)
    69dc:	01013403          	ld	s0,16(sp)
    69e0:	00813483          	ld	s1,8(sp)
    69e4:	02010113          	addi	sp,sp,32
    69e8:	00008067          	ret
    69ec:	01213023          	sd	s2,0(sp)
    69f0:	00050913          	mv	s2,a0
    putc_flush();
    69f4:	f41ff0ef          	jal	6934 <putc_flush>
    putc_fd = fd;
    69f8:	00003797          	auipc	a5,0x3
    69fc:	6127a823          	sw	s2,1552(a5) # a008 <putc_fd>
    6a00:	00013903          	ld	s2,0(sp)
    6a04:	fa1ff06f          	j	69a4 <putc+0x24>
    putc_flush();
    6a08:	f2dff0ef          	jal	6934 <putc_flush>
}
    6a0c:	fcdff06f          	j	69d8 <putc+0x58>

0000000000006a10 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
    6a10:	fb010113          	addi	sp,sp,-80
    6a14:	04113423          	sd	ra,72(sp)
    6a18:	04813023          	sd	s0,64(sp)
    6a1c:	03213823          	sd	s2,48(sp)
    6a20:	03313423          	sd	s3,40(sp)
    6a24:	05010413          	addi	s0,sp,80
    6a28:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
    6a2c:	0a068e63          	beqz	a3,6ae8 <printint+0xd8>
    6a30:	0a05dc63          	bgez	a1,6ae8 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
    6a34:	40b005b3          	neg	a1,a1
    neg = 1;
    6a38:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
    6a3c:	fb840993          	addi	s3,s0,-72
  neg = 0;
    6a40:	00098693          	mv	a3,s3
  i = 0;
    6a44:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
    6a48:	00003817          	auipc	a6,0x3
    6a4c:	d8080813          	addi	a6,a6,-640 # 97c8 <digits>
    6a50:	00070893          	mv	a7,a4
    6a54:	0017051b          	addiw	a0,a4,1
    6a58:	00050713          	mv	a4,a0
    6a5c:	02c5f7b3          	remu	a5,a1,a2
    6a60:	00f807b3          	add	a5,a6,a5
    6a64:	0007c783          	lbu	a5,0(a5)
    6a68:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
    6a6c:	00058793          	mv	a5,a1
    6a70:	02c5d5b3          	divu	a1,a1,a2
    6a74:	00168693          	addi	a3,a3,1
    6a78:	fcc7fce3          	bgeu	a5,a2,6a50 <printint+0x40>
  if (neg)
    6a7c:	00030c63          	beqz	t1,6a94 <printint+0x84>
    buf[i++] = '-';
    6a80:	fd050793          	addi	a5,a0,-48
    6a84:	00878533          	add	a0,a5,s0
    6a88:	02d00793          	li	a5,45
    6a8c:	fef50423          	sb	a5,-24(a0)
    6a90:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
    6a94:	02e05e63          	blez	a4,6ad0 <printint+0xc0>
    6a98:	02913c23          	sd	s1,56(sp)
    6a9c:	fff7071b          	addiw	a4,a4,-1
    6aa0:	00e984b3          	add	s1,s3,a4
    6aa4:	fff98993          	addi	s3,s3,-1 # fff <unlinkread+0xc7>
    6aa8:	00e989b3          	add	s3,s3,a4
    6aac:	02071713          	slli	a4,a4,0x20
    6ab0:	02075713          	srli	a4,a4,0x20
    6ab4:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
    6ab8:	0004c583          	lbu	a1,0(s1)
    6abc:	00090513          	mv	a0,s2
    6ac0:	ec1ff0ef          	jal	6980 <putc>
  while (--i >= 0)
    6ac4:	fff48493          	addi	s1,s1,-1
    6ac8:	ff3498e3          	bne	s1,s3,6ab8 <printint+0xa8>
    6acc:	03813483          	ld	s1,56(sp)
}
    6ad0:	04813083          	ld	ra,72(sp)
    6ad4:	04013403          	ld	s0,64(sp)
    6ad8:	03013903          	ld	s2,48(sp)
    6adc:	02813983          	ld	s3,40(sp)
    6ae0:	05010113          	addi	sp,sp,80
    6ae4:	00008067          	ret
  neg = 0;
    6ae8:	00000313          	li	t1,0
    6aec:	f51ff06f          	j	6a3c <printint+0x2c>

0000000000006af0 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
    6af0:	fa010113          	addi	sp,sp,-96
    6af4:	04113c23          	sd	ra,88(sp)
    6af8:	04813823          	sd	s0,80(sp)
    6afc:	04913423          	sd	s1,72(sp)
    6b00:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
    6b04:	0005c483          	lbu	s1,0(a1)
    6b08:	32048263          	beqz	s1,6e2c <vprintf+0x33c>
    6b0c:	05213023          	sd	s2,64(sp)
    6b10:	03313c23          	sd	s3,56(sp)
    6b14:	03413823          	sd	s4,48(sp)
    6b18:	03513423          	sd	s5,40(sp)
    6b1c:	03613023          	sd	s6,32(sp)
    6b20:	01713c23          	sd	s7,24(sp)
    6b24:	01813823          	sd	s8,16(sp)
    6b28:	00050b13          	mv	s6,a0
    6b2c:	00058a13          	mv	s4,a1
    6b30:	00060b93          	mv	s7,a2
  state = 0;
    6b34:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
    6b38:	00000913          	li	s2,0
    6b3c:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
    6b40:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
    6b44:	06400c13          	li	s8,100
    6b48:	0300006f          	j	6b78 <vprintf+0x88>
        putc(fd, c0);
    6b4c:	00048593          	mv	a1,s1
    6b50:	000b0513          	mv	a0,s6
    6b54:	e2dff0ef          	jal	6980 <putc>
    6b58:	0080006f          	j	6b60 <vprintf+0x70>
    else if (state == '%')
    6b5c:	03598863          	beq	s3,s5,6b8c <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
    6b60:	0019079b          	addiw	a5,s2,1
    6b64:	00078913          	mv	s2,a5
    6b68:	00078713          	mv	a4,a5
    6b6c:	00fa07b3          	add	a5,s4,a5
    6b70:	0007c483          	lbu	s1,0(a5)
    6b74:	28048e63          	beqz	s1,6e10 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
    6b78:	0004879b          	sext.w	a5,s1
    if (state == 0)
    6b7c:	fe0990e3          	bnez	s3,6b5c <vprintf+0x6c>
      if (c0 == '%')
    6b80:	fd5796e3          	bne	a5,s5,6b4c <vprintf+0x5c>
        state = '%';
    6b84:	00078993          	mv	s3,a5
    6b88:	fd9ff06f          	j	6b60 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
    6b8c:	00ea06b3          	add	a3,s4,a4
    6b90:	0016c603          	lbu	a2,1(a3)
      if (c1)
    6b94:	2a060663          	beqz	a2,6e40 <vprintf+0x350>
      if (c0 == 'd')
    6b98:	05878063          	beq	a5,s8,6bd8 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
    6b9c:	f9478693          	addi	a3,a5,-108
    6ba0:	0016b693          	seqz	a3,a3
    6ba4:	f9c60593          	addi	a1,a2,-100
    6ba8:	04059a63          	bnez	a1,6bfc <vprintf+0x10c>
    6bac:	04068863          	beqz	a3,6bfc <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
    6bb0:	008b8493          	addi	s1,s7,8
    6bb4:	00100693          	li	a3,1
    6bb8:	00a00613          	li	a2,10
    6bbc:	000bb583          	ld	a1,0(s7)
    6bc0:	000b0513          	mv	a0,s6
    6bc4:	e4dff0ef          	jal	6a10 <printint>
        i += 1;
    6bc8:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
    6bcc:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
    6bd0:	00000993          	li	s3,0
    6bd4:	f8dff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
    6bd8:	008b8493          	addi	s1,s7,8
    6bdc:	00100693          	li	a3,1
    6be0:	00a00613          	li	a2,10
    6be4:	000ba583          	lw	a1,0(s7)
    6be8:	000b0513          	mv	a0,s6
    6bec:	e25ff0ef          	jal	6a10 <printint>
    6bf0:	00048b93          	mv	s7,s1
      state = 0;
    6bf4:	00000993          	li	s3,0
    6bf8:	f69ff06f          	j	6b60 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
    6bfc:	00ea0733          	add	a4,s4,a4
    6c00:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    6c04:	f9460713          	addi	a4,a2,-108
    6c08:	00173713          	seqz	a4,a4
    6c0c:	00e6f733          	and	a4,a3,a4
    6c10:	f9c58513          	addi	a0,a1,-100
    6c14:	24051263          	bnez	a0,6e58 <vprintf+0x368>
    6c18:	24070063          	beqz	a4,6e58 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
    6c1c:	008b8493          	addi	s1,s7,8
    6c20:	00100693          	li	a3,1
    6c24:	00a00613          	li	a2,10
    6c28:	000bb583          	ld	a1,0(s7)
    6c2c:	000b0513          	mv	a0,s6
    6c30:	de1ff0ef          	jal	6a10 <printint>
        i += 2;
    6c34:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
    6c38:	00048b93          	mv	s7,s1
      state = 0;
    6c3c:	00000993          	li	s3,0
        i += 2;
    6c40:	f21ff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
    6c44:	008b8493          	addi	s1,s7,8
    6c48:	00000693          	li	a3,0
    6c4c:	00a00613          	li	a2,10
    6c50:	000be583          	lwu	a1,0(s7)
    6c54:	000b0513          	mv	a0,s6
    6c58:	db9ff0ef          	jal	6a10 <printint>
    6c5c:	00048b93          	mv	s7,s1
      state = 0;
    6c60:	00000993          	li	s3,0
    6c64:	efdff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    6c68:	008b8493          	addi	s1,s7,8
    6c6c:	00000693          	li	a3,0
    6c70:	00a00613          	li	a2,10
    6c74:	000bb583          	ld	a1,0(s7)
    6c78:	000b0513          	mv	a0,s6
    6c7c:	d95ff0ef          	jal	6a10 <printint>
        i += 1;
    6c80:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
    6c84:	00048b93          	mv	s7,s1
      state = 0;
    6c88:	00000993          	li	s3,0
    6c8c:	ed5ff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    6c90:	008b8493          	addi	s1,s7,8
    6c94:	00000693          	li	a3,0
    6c98:	00a00613          	li	a2,10
    6c9c:	000bb583          	ld	a1,0(s7)
    6ca0:	000b0513          	mv	a0,s6
    6ca4:	d6dff0ef          	jal	6a10 <printint>
        i += 2;
    6ca8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
    6cac:	00048b93          	mv	s7,s1
      state = 0;
    6cb0:	00000993          	li	s3,0
        i += 2;
    6cb4:	eadff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
    6cb8:	008b8493          	addi	s1,s7,8
    6cbc:	00000693          	li	a3,0
    6cc0:	01000613          	li	a2,16
    6cc4:	000be583          	lwu	a1,0(s7)
    6cc8:	000b0513          	mv	a0,s6
    6ccc:	d45ff0ef          	jal	6a10 <printint>
    6cd0:	00048b93          	mv	s7,s1
      state = 0;
    6cd4:	00000993          	li	s3,0
    6cd8:	e89ff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    6cdc:	008b8493          	addi	s1,s7,8
    6ce0:	00000693          	li	a3,0
    6ce4:	01000613          	li	a2,16
    6ce8:	000bb583          	ld	a1,0(s7)
    6cec:	000b0513          	mv	a0,s6
    6cf0:	d21ff0ef          	jal	6a10 <printint>
        i += 1;
    6cf4:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
    6cf8:	00048b93          	mv	s7,s1
      state = 0;
    6cfc:	00000993          	li	s3,0
    6d00:	e61ff06f          	j	6b60 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    6d04:	008b8493          	addi	s1,s7,8
    6d08:	00000693          	li	a3,0
    6d0c:	01000613          	li	a2,16
    6d10:	000bb583          	ld	a1,0(s7)
    6d14:	000b0513          	mv	a0,s6
    6d18:	cf9ff0ef          	jal	6a10 <printint>
        i += 2;
    6d1c:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
    6d20:	00048b93          	mv	s7,s1
      state = 0;
    6d24:	00000993          	li	s3,0
        i += 2;
    6d28:	e39ff06f          	j	6b60 <vprintf+0x70>
    6d2c:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
    6d30:	008b8793          	addi	a5,s7,8
    6d34:	00078c93          	mv	s9,a5
    6d38:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
    6d3c:	03000593          	li	a1,48
    6d40:	000b0513          	mv	a0,s6
    6d44:	c3dff0ef          	jal	6980 <putc>
  putc(fd, 'x');
    6d48:	07800593          	li	a1,120
    6d4c:	000b0513          	mv	a0,s6
    6d50:	c31ff0ef          	jal	6980 <putc>
    6d54:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
    6d58:	00003b97          	auipc	s7,0x3
    6d5c:	a70b8b93          	addi	s7,s7,-1424 # 97c8 <digits>
    6d60:	03c9d793          	srli	a5,s3,0x3c
    6d64:	00fb87b3          	add	a5,s7,a5
    6d68:	0007c583          	lbu	a1,0(a5)
    6d6c:	000b0513          	mv	a0,s6
    6d70:	c11ff0ef          	jal	6980 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
    6d74:	00499993          	slli	s3,s3,0x4
    6d78:	fff4849b          	addiw	s1,s1,-1
    6d7c:	fe0492e3          	bnez	s1,6d60 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
    6d80:	000c8b93          	mv	s7,s9
      state = 0;
    6d84:	00000993          	li	s3,0
    6d88:	00813c83          	ld	s9,8(sp)
    6d8c:	dd5ff06f          	j	6b60 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
    6d90:	008b8493          	addi	s1,s7,8
    6d94:	000bc583          	lbu	a1,0(s7)
    6d98:	000b0513          	mv	a0,s6
    6d9c:	be5ff0ef          	jal	6980 <putc>
    6da0:	00048b93          	mv	s7,s1
      state = 0;
    6da4:	00000993          	li	s3,0
    6da8:	db9ff06f          	j	6b60 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    6dac:	008b8993          	addi	s3,s7,8
    6db0:	000bb483          	ld	s1,0(s7)
    6db4:	02048663          	beqz	s1,6de0 <vprintf+0x2f0>
        for (; *s; s++)
    6db8:	0004c583          	lbu	a1,0(s1)
    6dbc:	04058463          	beqz	a1,6e04 <vprintf+0x314>
          putc(fd, *s);
    6dc0:	000b0513          	mv	a0,s6
    6dc4:	bbdff0ef          	jal	6980 <putc>
        for (; *s; s++)
    6dc8:	00148493          	addi	s1,s1,1
    6dcc:	0004c583          	lbu	a1,0(s1)
    6dd0:	fe0598e3          	bnez	a1,6dc0 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
    6dd4:	00098b93          	mv	s7,s3
      state = 0;
    6dd8:	00000993          	li	s3,0
    6ddc:	d85ff06f          	j	6b60 <vprintf+0x70>
          s = "(null)";
    6de0:	00003497          	auipc	s1,0x3
    6de4:	93848493          	addi	s1,s1,-1736 # 9718 <malloc+0x26f0>
        for (; *s; s++)
    6de8:	02800593          	li	a1,40
    6dec:	fd5ff06f          	j	6dc0 <vprintf+0x2d0>
        putc(fd, '%');
    6df0:	00078593          	mv	a1,a5
    6df4:	000b0513          	mv	a0,s6
    6df8:	b89ff0ef          	jal	6980 <putc>
      state = 0;
    6dfc:	00000993          	li	s3,0
    6e00:	d61ff06f          	j	6b60 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    6e04:	00098b93          	mv	s7,s3
      state = 0;
    6e08:	00000993          	li	s3,0
    6e0c:	d55ff06f          	j	6b60 <vprintf+0x70>
    6e10:	04013903          	ld	s2,64(sp)
    6e14:	03813983          	ld	s3,56(sp)
    6e18:	03013a03          	ld	s4,48(sp)
    6e1c:	02813a83          	ld	s5,40(sp)
    6e20:	02013b03          	ld	s6,32(sp)
    6e24:	01813b83          	ld	s7,24(sp)
    6e28:	01013c03          	ld	s8,16(sp)
    }
  }
}
    6e2c:	05813083          	ld	ra,88(sp)
    6e30:	05013403          	ld	s0,80(sp)
    6e34:	04813483          	ld	s1,72(sp)
    6e38:	06010113          	addi	sp,sp,96
    6e3c:	00008067          	ret
      if (c0 == 'd')
    6e40:	06400713          	li	a4,100
    6e44:	d8e78ae3          	beq	a5,a4,6bd8 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
    6e48:	f9478693          	addi	a3,a5,-108
    6e4c:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
    6e50:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    6e54:	00000713          	li	a4,0
      else if (c0 == 'u')
    6e58:	07500513          	li	a0,117
    6e5c:	dea784e3          	beq	a5,a0,6c44 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
    6e60:	f8b60513          	addi	a0,a2,-117
    6e64:	00051463          	bnez	a0,6e6c <vprintf+0x37c>
    6e68:	e00690e3          	bnez	a3,6c68 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
    6e6c:	f8b58513          	addi	a0,a1,-117
    6e70:	00051463          	bnez	a0,6e78 <vprintf+0x388>
    6e74:	e0071ee3          	bnez	a4,6c90 <vprintf+0x1a0>
      else if (c0 == 'x')
    6e78:	07800513          	li	a0,120
    6e7c:	e2a78ee3          	beq	a5,a0,6cb8 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
    6e80:	f8860613          	addi	a2,a2,-120
    6e84:	00061463          	bnez	a2,6e8c <vprintf+0x39c>
    6e88:	e4069ae3          	bnez	a3,6cdc <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
    6e8c:	f8858593          	addi	a1,a1,-120
    6e90:	00059463          	bnez	a1,6e98 <vprintf+0x3a8>
    6e94:	e60718e3          	bnez	a4,6d04 <vprintf+0x214>
      else if (c0 == 'p')
    6e98:	07000713          	li	a4,112
    6e9c:	e8e788e3          	beq	a5,a4,6d2c <vprintf+0x23c>
      else if (c0 == 'c')
    6ea0:	06300713          	li	a4,99
    6ea4:	eee786e3          	beq	a5,a4,6d90 <vprintf+0x2a0>
      else if (c0 == 's')
    6ea8:	07300713          	li	a4,115
    6eac:	f0e780e3          	beq	a5,a4,6dac <vprintf+0x2bc>
      else if (c0 == '%')
    6eb0:	02500713          	li	a4,37
    6eb4:	f2e78ee3          	beq	a5,a4,6df0 <vprintf+0x300>
        putc(fd, '%');
    6eb8:	02500593          	li	a1,37
    6ebc:	000b0513          	mv	a0,s6
    6ec0:	ac1ff0ef          	jal	6980 <putc>
        putc(fd, c0);
    6ec4:	00048593          	mv	a1,s1
    6ec8:	000b0513          	mv	a0,s6
    6ecc:	ab5ff0ef          	jal	6980 <putc>
      state = 0;
    6ed0:	00000993          	li	s3,0
    6ed4:	c8dff06f          	j	6b60 <vprintf+0x70>

0000000000006ed8 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
    6ed8:	fb010113          	addi	sp,sp,-80
    6edc:	00113c23          	sd	ra,24(sp)
    6ee0:	00813823          	sd	s0,16(sp)
    6ee4:	02010413          	addi	s0,sp,32
    6ee8:	00c43023          	sd	a2,0(s0)
    6eec:	00d43423          	sd	a3,8(s0)
    6ef0:	00e43823          	sd	a4,16(s0)
    6ef4:	00f43c23          	sd	a5,24(s0)
    6ef8:	03043023          	sd	a6,32(s0)
    6efc:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
    6f00:	00040613          	mv	a2,s0
    6f04:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
    6f08:	be9ff0ef          	jal	6af0 <vprintf>
}
    6f0c:	01813083          	ld	ra,24(sp)
    6f10:	01013403          	ld	s0,16(sp)
    6f14:	05010113          	addi	sp,sp,80
    6f18:	00008067          	ret

0000000000006f1c <printf>:

void printf(const char *fmt, ...)
{
    6f1c:	fa010113          	addi	sp,sp,-96
    6f20:	00113c23          	sd	ra,24(sp)
    6f24:	00813823          	sd	s0,16(sp)
    6f28:	02010413          	addi	s0,sp,32
    6f2c:	00b43423          	sd	a1,8(s0)
    6f30:	00c43823          	sd	a2,16(s0)
    6f34:	00d43c23          	sd	a3,24(s0)
    6f38:	02e43023          	sd	a4,32(s0)
    6f3c:	02f43423          	sd	a5,40(s0)
    6f40:	03043823          	sd	a6,48(s0)
    6f44:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
    6f48:	00840613          	addi	a2,s0,8
    6f4c:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
    6f50:	00050593          	mv	a1,a0
    6f54:	00100513          	li	a0,1
    6f58:	b99ff0ef          	jal	6af0 <vprintf>
  putc_flush();
    6f5c:	9d9ff0ef          	jal	6934 <putc_flush>
}
    6f60:	01813083          	ld	ra,24(sp)
    6f64:	01013403          	ld	s0,16(sp)
    6f68:	06010113          	addi	sp,sp,96
    6f6c:	00008067          	ret

0000000000006f70 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
    6f70:	ff010113          	addi	sp,sp,-16
    6f74:	00113423          	sd	ra,8(sp)
    6f78:	00813023          	sd	s0,0(sp)
    6f7c:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
    6f80:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    6f84:	00003797          	auipc	a5,0x3
    6f88:	5147b783          	ld	a5,1300(a5) # a498 <freep>
    6f8c:	0140006f          	j	6fa0 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    6f90:	0007b703          	ld	a4,0(a5)
    6f94:	00e7e463          	bltu	a5,a4,6f9c <free+0x2c>
    6f98:	00e6ec63          	bltu	a3,a4,6fb0 <free+0x40>
{
    6f9c:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    6fa0:	fed7f8e3          	bgeu	a5,a3,6f90 <free+0x20>
    6fa4:	0007b703          	ld	a4,0(a5)
    6fa8:	00e6e463          	bltu	a3,a4,6fb0 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    6fac:	fee7e8e3          	bltu	a5,a4,6f9c <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
    6fb0:	ff852583          	lw	a1,-8(a0)
    6fb4:	0007b603          	ld	a2,0(a5)
    6fb8:	02059813          	slli	a6,a1,0x20
    6fbc:	01c85713          	srli	a4,a6,0x1c
    6fc0:	00e68733          	add	a4,a3,a4
    6fc4:	02e60c63          	beq	a2,a4,6ffc <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
    6fc8:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    6fcc:	0087a603          	lw	a2,8(a5)
    6fd0:	02061593          	slli	a1,a2,0x20
    6fd4:	01c5d713          	srli	a4,a1,0x1c
    6fd8:	00e78733          	add	a4,a5,a4
    6fdc:	02e68c63          	beq	a3,a4,7014 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
    6fe0:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
    6fe4:	00003717          	auipc	a4,0x3
    6fe8:	4af73a23          	sd	a5,1204(a4) # a498 <freep>
}
    6fec:	00813083          	ld	ra,8(sp)
    6ff0:	00013403          	ld	s0,0(sp)
    6ff4:	01010113          	addi	sp,sp,16
    6ff8:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
    6ffc:	00862703          	lw	a4,8(a2)
    7000:	00b7073b          	addw	a4,a4,a1
    7004:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
    7008:	0007b703          	ld	a4,0(a5)
    700c:	00073603          	ld	a2,0(a4)
    7010:	fb9ff06f          	j	6fc8 <free+0x58>
    p->s.size += bp->s.size;
    7014:	ff852703          	lw	a4,-8(a0)
    7018:	00c7073b          	addw	a4,a4,a2
    701c:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
    7020:	ff053683          	ld	a3,-16(a0)
    7024:	fbdff06f          	j	6fe0 <free+0x70>

0000000000007028 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
    7028:	fc010113          	addi	sp,sp,-64
    702c:	02113c23          	sd	ra,56(sp)
    7030:	02813823          	sd	s0,48(sp)
    7034:	03213023          	sd	s2,32(sp)
    7038:	01313c23          	sd	s3,24(sp)
    703c:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    7040:	02051993          	slli	s3,a0,0x20
    7044:	0209d993          	srli	s3,s3,0x20
    7048:	00f98993          	addi	s3,s3,15
    704c:	0049d993          	srli	s3,s3,0x4
    7050:	0019899b          	addiw	s3,s3,1
    7054:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
    7058:	00003517          	auipc	a0,0x3
    705c:	44053503          	ld	a0,1088(a0) # a498 <freep>
    7060:	04050463          	beqz	a0,70a8 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    7064:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    7068:	0087a703          	lw	a4,8(a5)
    706c:	0d377a63          	bgeu	a4,s3,7140 <malloc+0x118>
    7070:	02913423          	sd	s1,40(sp)
    7074:	01413823          	sd	s4,16(sp)
    7078:	01513423          	sd	s5,8(sp)
    707c:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
    7080:	00098a13          	mv	s4,s3
    7084:	00001737          	lui	a4,0x1
    7088:	00e9f463          	bgeu	s3,a4,7090 <malloc+0x68>
    708c:	00001a37          	lui	s4,0x1
    7090:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
    7094:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    7098:	00003497          	auipc	s1,0x3
    709c:	40048493          	addi	s1,s1,1024 # a498 <freep>
  if(p == SBRK_ERROR)
    70a0:	fff00a93          	li	s5,-1
    70a4:	05c0006f          	j	7100 <malloc+0xd8>
    70a8:	02913423          	sd	s1,40(sp)
    70ac:	01413823          	sd	s4,16(sp)
    70b0:	01513423          	sd	s5,8(sp)
    70b4:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
    70b8:	0000a797          	auipc	a5,0xa
    70bc:	c8078793          	addi	a5,a5,-896 # 10d38 <base>
    70c0:	00003717          	auipc	a4,0x3
    70c4:	3cf73c23          	sd	a5,984(a4) # a498 <freep>
    70c8:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
    70cc:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
    70d0:	fb1ff06f          	j	7080 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
    70d4:	0007b703          	ld	a4,0(a5)
    70d8:	00e53023          	sd	a4,0(a0)
    70dc:	0800006f          	j	715c <malloc+0x134>
  hp->s.size = nu;
    70e0:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
    70e4:	01050513          	addi	a0,a0,16
    70e8:	e89ff0ef          	jal	6f70 <free>
  return freep;
    70ec:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    70f0:	08050863          	beqz	a0,7180 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    70f4:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    70f8:	0087a703          	lw	a4,8(a5)
    70fc:	03277a63          	bgeu	a4,s2,7130 <malloc+0x108>
    if(p == freep)
    7100:	0004b703          	ld	a4,0(s1)
    7104:	00078513          	mv	a0,a5
    7108:	fef716e3          	bne	a4,a5,70f4 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    710c:	000a0513          	mv	a0,s4
    7110:	ed8ff0ef          	jal	67e8 <sbrk>
  if(p == SBRK_ERROR)
    7114:	fd5516e3          	bne	a0,s5,70e0 <malloc+0xb8>
        return 0;
    7118:	00000513          	li	a0,0
    711c:	02813483          	ld	s1,40(sp)
    7120:	01013a03          	ld	s4,16(sp)
    7124:	00813a83          	ld	s5,8(sp)
    7128:	00013b03          	ld	s6,0(sp)
    712c:	03c0006f          	j	7168 <malloc+0x140>
    7130:	02813483          	ld	s1,40(sp)
    7134:	01013a03          	ld	s4,16(sp)
    7138:	00813a83          	ld	s5,8(sp)
    713c:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    7140:	f8e90ae3          	beq	s2,a4,70d4 <malloc+0xac>
        p->s.size -= nunits;
    7144:	4137073b          	subw	a4,a4,s3
    7148:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    714c:	02071693          	slli	a3,a4,0x20
    7150:	01c6d713          	srli	a4,a3,0x1c
    7154:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    7158:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    715c:	00003717          	auipc	a4,0x3
    7160:	32a73e23          	sd	a0,828(a4) # a498 <freep>
      return (void*)(p + 1);
    7164:	01078513          	addi	a0,a5,16
  }
}
    7168:	03813083          	ld	ra,56(sp)
    716c:	03013403          	ld	s0,48(sp)
    7170:	02013903          	ld	s2,32(sp)
    7174:	01813983          	ld	s3,24(sp)
    7178:	04010113          	addi	sp,sp,64
    717c:	00008067          	ret
    7180:	02813483          	ld	s1,40(sp)
    7184:	01013a03          	ld	s4,16(sp)
    7188:	00813a83          	ld	s5,8(sp)
    718c:	00013b03          	ld	s6,0(sp)
    7190:	fd9ff06f          	j	7168 <malloc+0x140>
