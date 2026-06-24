
user/_grind:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <do_rand>:
#include "kernel/riscv.h"

// from FreeBSD.
int
do_rand(unsigned long *ctx)
{
       0:	ff010113          	addi	sp,sp,-16
       4:	00113423          	sd	ra,8(sp)
       8:	00813023          	sd	s0,0(sp)
       c:	01010413          	addi	s0,sp,16
 * October 1988, p. 1195.
 */
    long hi, lo, x;

    /* Transform to [1, 0x7ffffffe] range. */
    x = (*ctx % 0x7ffffffe) + 1;
      10:	00053783          	ld	a5,0(a0)
      14:	0017d693          	srli	a3,a5,0x1
      18:	c0000737          	lui	a4,0xc0000
      1c:	00170713          	addi	a4,a4,1 # ffffffffc0000001 <base+0xffffffffbfffdb79>
      20:	02171713          	slli	a4,a4,0x21
      24:	00970713          	addi	a4,a4,9
      28:	02e6b733          	mulhu	a4,a3,a4
      2c:	01d75713          	srli	a4,a4,0x1d
      30:	01e71693          	slli	a3,a4,0x1e
      34:	40e68733          	sub	a4,a3,a4
      38:	00171713          	slli	a4,a4,0x1
      3c:	40e787b3          	sub	a5,a5,a4
      40:	00178793          	addi	a5,a5,1
    hi = x / 127773;
    lo = x % 127773;
      44:	1fe406b7          	lui	a3,0x1fe40
      48:	b7968693          	addi	a3,a3,-1159 # 1fe3fb79 <base+0x1fe3d6f1>
      4c:	41a70737          	lui	a4,0x41a70
      50:	5af70713          	addi	a4,a4,1455 # 41a705af <base+0x41a6e127>
      54:	02071713          	slli	a4,a4,0x20
      58:	00d70733          	add	a4,a4,a3
      5c:	02e79733          	mulh	a4,a5,a4
      60:	40f75713          	srai	a4,a4,0xf
      64:	43f7d693          	srai	a3,a5,0x3f
      68:	40d70733          	sub	a4,a4,a3
      6c:	0001f6b7          	lui	a3,0x1f
      70:	31d68693          	addi	a3,a3,797 # 1f31d <base+0x1ce95>
      74:	02d706b3          	mul	a3,a4,a3
      78:	40d787b3          	sub	a5,a5,a3
    x = 16807 * lo - 2836 * hi;
      7c:	000046b7          	lui	a3,0x4
      80:	1a768693          	addi	a3,a3,423 # 41a7 <base+0x1d1f>
      84:	02d787b3          	mul	a5,a5,a3
      88:	fffff6b7          	lui	a3,0xfffff
      8c:	4ec68693          	addi	a3,a3,1260 # fffffffffffff4ec <base+0xffffffffffffd064>
      90:	02d70733          	mul	a4,a4,a3
      94:	00e787b3          	add	a5,a5,a4
    if (x < 0)
      98:	0207c063          	bltz	a5,b8 <do_rand+0xb8>
        x += 0x7fffffff;
    /* Transform to [0, 0x7ffffffd] range. */
    x--;
      9c:	fff78793          	addi	a5,a5,-1
    *ctx = x;
      a0:	00f53023          	sd	a5,0(a0)
    return (x);
}
      a4:	0007851b          	sext.w	a0,a5
      a8:	00813083          	ld	ra,8(sp)
      ac:	00013403          	ld	s0,0(sp)
      b0:	01010113          	addi	sp,sp,16
      b4:	00008067          	ret
        x += 0x7fffffff;
      b8:	80000737          	lui	a4,0x80000
      bc:	fff74713          	not	a4,a4
      c0:	00e787b3          	add	a5,a5,a4
      c4:	fd9ff06f          	j	9c <do_rand+0x9c>

00000000000000c8 <rand>:

unsigned long rand_next = 1;

int
rand(void)
{
      c8:	ff010113          	addi	sp,sp,-16
      cc:	00113423          	sd	ra,8(sp)
      d0:	00813023          	sd	s0,0(sp)
      d4:	01010413          	addi	s0,sp,16
    return (do_rand(&rand_next));
      d8:	00002517          	auipc	a0,0x2
      dc:	f2850513          	addi	a0,a0,-216 # 2000 <rand_next>
      e0:	f21ff0ef          	jal	0 <do_rand>
}
      e4:	00813083          	ld	ra,8(sp)
      e8:	00013403          	ld	s0,0(sp)
      ec:	01010113          	addi	sp,sp,16
      f0:	00008067          	ret

00000000000000f4 <go>:

void
go(int which_child)
{
      f4:	f5010113          	addi	sp,sp,-176
      f8:	0a113423          	sd	ra,168(sp)
      fc:	0a813023          	sd	s0,160(sp)
     100:	08913c23          	sd	s1,152(sp)
     104:	0b010413          	addi	s0,sp,176
     108:	00050493          	mv	s1,a0
  int fd = -1;
  static char buf[999];
  char *break0 = sbrk(0);
     10c:	00000513          	li	a0,0
     110:	651000ef          	jal	f60 <sbrk>
     114:	f4a43c23          	sd	a0,-168(s0)
  uint64 iters = 0;

  mkdir("grindir");
     118:	00001517          	auipc	a0,0x1
     11c:	7f850513          	addi	a0,a0,2040 # 1910 <malloc+0x170>
     120:	739000ef          	jal	1058 <mkdir>
  if(chdir("grindir") != 0){
     124:	00001517          	auipc	a0,0x1
     128:	7ec50513          	addi	a0,a0,2028 # 1910 <malloc+0x170>
     12c:	739000ef          	jal	1064 <chdir>
     130:	04050063          	beqz	a0,170 <go+0x7c>
     134:	09213823          	sd	s2,144(sp)
     138:	09313423          	sd	s3,136(sp)
     13c:	09413023          	sd	s4,128(sp)
     140:	07513c23          	sd	s5,120(sp)
     144:	07613823          	sd	s6,112(sp)
     148:	07713423          	sd	s7,104(sp)
     14c:	07813023          	sd	s8,96(sp)
     150:	05913c23          	sd	s9,88(sp)
     154:	05a13823          	sd	s10,80(sp)
     158:	05b13423          	sd	s11,72(sp)
    printf("grind: chdir grindir failed\n");
     15c:	00001517          	auipc	a0,0x1
     160:	7bc50513          	addi	a0,a0,1980 # 1918 <malloc+0x178>
     164:	530010ef          	jal	1694 <printf>
    exit(1);
     168:	00100513          	li	a0,1
     16c:	651000ef          	jal	fbc <exit>
     170:	09213823          	sd	s2,144(sp)
     174:	09313423          	sd	s3,136(sp)
     178:	09413023          	sd	s4,128(sp)
     17c:	07513c23          	sd	s5,120(sp)
     180:	07613823          	sd	s6,112(sp)
     184:	07713423          	sd	s7,104(sp)
     188:	07813023          	sd	s8,96(sp)
     18c:	05913c23          	sd	s9,88(sp)
     190:	05a13823          	sd	s10,80(sp)
     194:	05b13423          	sd	s11,72(sp)
  }
  chdir("/");
     198:	00001517          	auipc	a0,0x1
     19c:	7a850513          	addi	a0,a0,1960 # 1940 <malloc+0x1a0>
     1a0:	6c5000ef          	jal	1064 <chdir>
     1a4:	00001c17          	auipc	s8,0x1
     1a8:	7acc0c13          	addi	s8,s8,1964 # 1950 <malloc+0x1b0>
     1ac:	00048663          	beqz	s1,1b8 <go+0xc4>
     1b0:	00001c17          	auipc	s8,0x1
     1b4:	798c0c13          	addi	s8,s8,1944 # 1948 <malloc+0x1a8>
  uint64 iters = 0;
     1b8:	00000493          	li	s1,0
  int fd = -1;
     1bc:	fff00c93          	li	s9,-1
  
  while(1){
    iters++;
    if((iters % 500) == 0)
     1c0:	106259b7          	lui	s3,0x10625
     1c4:	dd398993          	addi	s3,s3,-557 # 10624dd3 <base+0x1062294b>
     1c8:	00f99993          	slli	s3,s3,0xf
     1cc:	8d598993          	addi	s3,s3,-1835
     1d0:	01299993          	slli	s3,s3,0x12
     1d4:	80098993          	addi	s3,s3,-2048
     1d8:	fcf98993          	addi	s3,s3,-49
     1dc:	1f400b93          	li	s7,500
      write(1, which_child?"B":"A", 1);
     1e0:	00100a13          	li	s4,1
    int what = rand() % 23;
     1e4:	b2164ab7          	lui	s5,0xb2164
     1e8:	2c9a8a93          	addi	s5,s5,713 # ffffffffb21642c9 <base+0xffffffffb2161e41>
     1ec:	01600b13          	li	s6,22
     1f0:	00002917          	auipc	s2,0x2
     1f4:	a3090913          	addi	s2,s2,-1488 # 1c20 <malloc+0x480>
      close(fd1);
      unlink("c");
    } else if(what == 22){
      // echo hi | cat
      int aa[2], bb[2];
      if(pipe(aa) < 0){
     1f8:	f6840d93          	addi	s11,s0,-152
     1fc:	0180006f          	j	214 <go+0x120>
      close(open("grindir/../a", O_CREATE|O_RDWR));
     200:	20200593          	li	a1,514
     204:	00001517          	auipc	a0,0x1
     208:	75450513          	addi	a0,a0,1876 # 1958 <malloc+0x1b8>
     20c:	611000ef          	jal	101c <open>
     210:	5e9000ef          	jal	ff8 <close>
    iters++;
     214:	00148493          	addi	s1,s1,1
    if((iters % 500) == 0)
     218:	0024d793          	srli	a5,s1,0x2
     21c:	0337b7b3          	mulhu	a5,a5,s3
     220:	0047d793          	srli	a5,a5,0x4
     224:	037787b3          	mul	a5,a5,s7
     228:	00f49a63          	bne	s1,a5,23c <go+0x148>
      write(1, which_child?"B":"A", 1);
     22c:	000a0613          	mv	a2,s4
     230:	000c0593          	mv	a1,s8
     234:	000a0513          	mv	a0,s4
     238:	5b5000ef          	jal	fec <write>
    int what = rand() % 23;
     23c:	e8dff0ef          	jal	c8 <rand>
     240:	035507b3          	mul	a5,a0,s5
     244:	0207d793          	srli	a5,a5,0x20
     248:	00f507bb          	addw	a5,a0,a5
     24c:	4047d79b          	sraiw	a5,a5,0x4
     250:	41f5571b          	sraiw	a4,a0,0x1f
     254:	40e787bb          	subw	a5,a5,a4
     258:	0017971b          	slliw	a4,a5,0x1
     25c:	00f7073b          	addw	a4,a4,a5
     260:	0037171b          	slliw	a4,a4,0x3
     264:	40f707bb          	subw	a5,a4,a5
     268:	40f5053b          	subw	a0,a0,a5
     26c:	faab64e3          	bltu	s6,a0,214 <go+0x120>
     270:	02051793          	slli	a5,a0,0x20
     274:	01e7d513          	srli	a0,a5,0x1e
     278:	01250533          	add	a0,a0,s2
     27c:	00052783          	lw	a5,0(a0)
     280:	012787b3          	add	a5,a5,s2
     284:	00078067          	jr	a5
      close(open("grindir/../grindir/../b", O_CREATE|O_RDWR));
     288:	20200593          	li	a1,514
     28c:	00001517          	auipc	a0,0x1
     290:	6dc50513          	addi	a0,a0,1756 # 1968 <malloc+0x1c8>
     294:	589000ef          	jal	101c <open>
     298:	561000ef          	jal	ff8 <close>
     29c:	f79ff06f          	j	214 <go+0x120>
      unlink("grindir/../a");
     2a0:	00001517          	auipc	a0,0x1
     2a4:	6b850513          	addi	a0,a0,1720 # 1958 <malloc+0x1b8>
     2a8:	58d000ef          	jal	1034 <unlink>
     2ac:	f69ff06f          	j	214 <go+0x120>
      if(chdir("grindir") != 0){
     2b0:	00001517          	auipc	a0,0x1
     2b4:	66050513          	addi	a0,a0,1632 # 1910 <malloc+0x170>
     2b8:	5ad000ef          	jal	1064 <chdir>
     2bc:	02051063          	bnez	a0,2dc <go+0x1e8>
      unlink("../b");
     2c0:	00001517          	auipc	a0,0x1
     2c4:	6c050513          	addi	a0,a0,1728 # 1980 <malloc+0x1e0>
     2c8:	56d000ef          	jal	1034 <unlink>
      chdir("/");
     2cc:	00001517          	auipc	a0,0x1
     2d0:	67450513          	addi	a0,a0,1652 # 1940 <malloc+0x1a0>
     2d4:	591000ef          	jal	1064 <chdir>
     2d8:	f3dff06f          	j	214 <go+0x120>
        printf("grind: chdir grindir failed\n");
     2dc:	00001517          	auipc	a0,0x1
     2e0:	63c50513          	addi	a0,a0,1596 # 1918 <malloc+0x178>
     2e4:	3b0010ef          	jal	1694 <printf>
        exit(1);
     2e8:	00100513          	li	a0,1
     2ec:	4d1000ef          	jal	fbc <exit>
      close(fd);
     2f0:	000c8513          	mv	a0,s9
     2f4:	505000ef          	jal	ff8 <close>
      fd = open("/grindir/../a", O_CREATE|O_RDWR);
     2f8:	20200593          	li	a1,514
     2fc:	00001517          	auipc	a0,0x1
     300:	68c50513          	addi	a0,a0,1676 # 1988 <malloc+0x1e8>
     304:	519000ef          	jal	101c <open>
     308:	00050c93          	mv	s9,a0
     30c:	f09ff06f          	j	214 <go+0x120>
      close(fd);
     310:	000c8513          	mv	a0,s9
     314:	4e5000ef          	jal	ff8 <close>
      fd = open("/./grindir/./../b", O_CREATE|O_RDWR);
     318:	20200593          	li	a1,514
     31c:	00001517          	auipc	a0,0x1
     320:	67c50513          	addi	a0,a0,1660 # 1998 <malloc+0x1f8>
     324:	4f9000ef          	jal	101c <open>
     328:	00050c93          	mv	s9,a0
     32c:	ee9ff06f          	j	214 <go+0x120>
      write(fd, buf, sizeof(buf));
     330:	3e700613          	li	a2,999
     334:	00002597          	auipc	a1,0x2
     338:	cec58593          	addi	a1,a1,-788 # 2020 <buf.0>
     33c:	000c8513          	mv	a0,s9
     340:	4ad000ef          	jal	fec <write>
     344:	ed1ff06f          	j	214 <go+0x120>
      read(fd, buf, sizeof(buf));
     348:	3e700613          	li	a2,999
     34c:	00002597          	auipc	a1,0x2
     350:	cd458593          	addi	a1,a1,-812 # 2020 <buf.0>
     354:	000c8513          	mv	a0,s9
     358:	489000ef          	jal	fe0 <read>
     35c:	eb9ff06f          	j	214 <go+0x120>
      mkdir("grindir/../a");
     360:	00001517          	auipc	a0,0x1
     364:	5f850513          	addi	a0,a0,1528 # 1958 <malloc+0x1b8>
     368:	4f1000ef          	jal	1058 <mkdir>
      close(open("a/../a/./a", O_CREATE|O_RDWR));
     36c:	20200593          	li	a1,514
     370:	00001517          	auipc	a0,0x1
     374:	64050513          	addi	a0,a0,1600 # 19b0 <malloc+0x210>
     378:	4a5000ef          	jal	101c <open>
     37c:	47d000ef          	jal	ff8 <close>
      unlink("a/a");
     380:	00001517          	auipc	a0,0x1
     384:	64050513          	addi	a0,a0,1600 # 19c0 <malloc+0x220>
     388:	4ad000ef          	jal	1034 <unlink>
     38c:	e89ff06f          	j	214 <go+0x120>
      mkdir("/../b");
     390:	00001517          	auipc	a0,0x1
     394:	63850513          	addi	a0,a0,1592 # 19c8 <malloc+0x228>
     398:	4c1000ef          	jal	1058 <mkdir>
      close(open("grindir/../b/b", O_CREATE|O_RDWR));
     39c:	20200593          	li	a1,514
     3a0:	00001517          	auipc	a0,0x1
     3a4:	63050513          	addi	a0,a0,1584 # 19d0 <malloc+0x230>
     3a8:	475000ef          	jal	101c <open>
     3ac:	44d000ef          	jal	ff8 <close>
      unlink("b/b");
     3b0:	00001517          	auipc	a0,0x1
     3b4:	63050513          	addi	a0,a0,1584 # 19e0 <malloc+0x240>
     3b8:	47d000ef          	jal	1034 <unlink>
     3bc:	e59ff06f          	j	214 <go+0x120>
      unlink("b");
     3c0:	00001517          	auipc	a0,0x1
     3c4:	62850513          	addi	a0,a0,1576 # 19e8 <malloc+0x248>
     3c8:	46d000ef          	jal	1034 <unlink>
      link("../grindir/./../a", "../b");
     3cc:	00001597          	auipc	a1,0x1
     3d0:	5b458593          	addi	a1,a1,1460 # 1980 <malloc+0x1e0>
     3d4:	00001517          	auipc	a0,0x1
     3d8:	61c50513          	addi	a0,a0,1564 # 19f0 <malloc+0x250>
     3dc:	471000ef          	jal	104c <link>
     3e0:	e35ff06f          	j	214 <go+0x120>
      unlink("../grindir/../a");
     3e4:	00001517          	auipc	a0,0x1
     3e8:	62450513          	addi	a0,a0,1572 # 1a08 <malloc+0x268>
     3ec:	449000ef          	jal	1034 <unlink>
      link(".././b", "/grindir/../a");
     3f0:	00001597          	auipc	a1,0x1
     3f4:	59858593          	addi	a1,a1,1432 # 1988 <malloc+0x1e8>
     3f8:	00001517          	auipc	a0,0x1
     3fc:	62050513          	addi	a0,a0,1568 # 1a18 <malloc+0x278>
     400:	44d000ef          	jal	104c <link>
     404:	e11ff06f          	j	214 <go+0x120>
      int pid = fork();
     408:	3a9000ef          	jal	fb0 <fork>
      if(pid == 0){
     40c:	00050a63          	beqz	a0,420 <go+0x32c>
      } else if(pid < 0){
     410:	00054a63          	bltz	a0,424 <go+0x330>
      wait(0);
     414:	00000513          	li	a0,0
     418:	3b1000ef          	jal	fc8 <wait>
     41c:	df9ff06f          	j	214 <go+0x120>
        exit(0);
     420:	39d000ef          	jal	fbc <exit>
        printf("grind: fork failed\n");
     424:	00001517          	auipc	a0,0x1
     428:	5fc50513          	addi	a0,a0,1532 # 1a20 <malloc+0x280>
     42c:	268010ef          	jal	1694 <printf>
        exit(1);
     430:	00100513          	li	a0,1
     434:	389000ef          	jal	fbc <exit>
      int pid = fork();
     438:	379000ef          	jal	fb0 <fork>
      if(pid == 0){
     43c:	00050a63          	beqz	a0,450 <go+0x35c>
      } else if(pid < 0){
     440:	02054063          	bltz	a0,460 <go+0x36c>
      wait(0);
     444:	00000513          	li	a0,0
     448:	381000ef          	jal	fc8 <wait>
     44c:	dc9ff06f          	j	214 <go+0x120>
        fork();
     450:	361000ef          	jal	fb0 <fork>
        fork();
     454:	35d000ef          	jal	fb0 <fork>
        exit(0);
     458:	00000513          	li	a0,0
     45c:	361000ef          	jal	fbc <exit>
        printf("grind: fork failed\n");
     460:	00001517          	auipc	a0,0x1
     464:	5c050513          	addi	a0,a0,1472 # 1a20 <malloc+0x280>
     468:	22c010ef          	jal	1694 <printf>
        exit(1);
     46c:	00100513          	li	a0,1
     470:	34d000ef          	jal	fbc <exit>
      sbrk(6011);
     474:	00001537          	lui	a0,0x1
     478:	77b50513          	addi	a0,a0,1915 # 177b <free+0x93>
     47c:	2e5000ef          	jal	f60 <sbrk>
     480:	d95ff06f          	j	214 <go+0x120>
      if(sbrk(0) > break0)
     484:	00000513          	li	a0,0
     488:	2d9000ef          	jal	f60 <sbrk>
     48c:	f5843783          	ld	a5,-168(s0)
     490:	d8a7f2e3          	bgeu	a5,a0,214 <go+0x120>
        sbrk(-(sbrk(0) - break0));
     494:	00000513          	li	a0,0
     498:	2c9000ef          	jal	f60 <sbrk>
     49c:	f5843783          	ld	a5,-168(s0)
     4a0:	40a7853b          	subw	a0,a5,a0
     4a4:	2bd000ef          	jal	f60 <sbrk>
     4a8:	d6dff06f          	j	214 <go+0x120>
      int pid = fork();
     4ac:	305000ef          	jal	fb0 <fork>
     4b0:	00050d13          	mv	s10,a0
      if(pid == 0){
     4b4:	02050663          	beqz	a0,4e0 <go+0x3ec>
      } else if(pid < 0){
     4b8:	04054263          	bltz	a0,4fc <go+0x408>
      if(chdir("../grindir/..") != 0){
     4bc:	00001517          	auipc	a0,0x1
     4c0:	58450513          	addi	a0,a0,1412 # 1a40 <malloc+0x2a0>
     4c4:	3a1000ef          	jal	1064 <chdir>
     4c8:	04051463          	bnez	a0,510 <go+0x41c>
      kill(pid);
     4cc:	000d0513          	mv	a0,s10
     4d0:	335000ef          	jal	1004 <kill>
      wait(0);
     4d4:	00000513          	li	a0,0
     4d8:	2f1000ef          	jal	fc8 <wait>
     4dc:	d39ff06f          	j	214 <go+0x120>
        close(open("a", O_CREATE|O_RDWR));
     4e0:	20200593          	li	a1,514
     4e4:	00001517          	auipc	a0,0x1
     4e8:	55450513          	addi	a0,a0,1364 # 1a38 <malloc+0x298>
     4ec:	331000ef          	jal	101c <open>
     4f0:	309000ef          	jal	ff8 <close>
        exit(0);
     4f4:	00000513          	li	a0,0
     4f8:	2c5000ef          	jal	fbc <exit>
        printf("grind: fork failed\n");
     4fc:	00001517          	auipc	a0,0x1
     500:	52450513          	addi	a0,a0,1316 # 1a20 <malloc+0x280>
     504:	190010ef          	jal	1694 <printf>
        exit(1);
     508:	00100513          	li	a0,1
     50c:	2b1000ef          	jal	fbc <exit>
        printf("grind: chdir failed\n");
     510:	00001517          	auipc	a0,0x1
     514:	54050513          	addi	a0,a0,1344 # 1a50 <malloc+0x2b0>
     518:	17c010ef          	jal	1694 <printf>
        exit(1);
     51c:	00100513          	li	a0,1
     520:	29d000ef          	jal	fbc <exit>
      int pid = fork();
     524:	28d000ef          	jal	fb0 <fork>
      if(pid == 0){
     528:	00050a63          	beqz	a0,53c <go+0x448>
      } else if(pid < 0){
     52c:	02054063          	bltz	a0,54c <go+0x458>
      wait(0);
     530:	00000513          	li	a0,0
     534:	295000ef          	jal	fc8 <wait>
     538:	cddff06f          	j	214 <go+0x120>
        kill(getpid());
     53c:	341000ef          	jal	107c <getpid>
     540:	2c5000ef          	jal	1004 <kill>
        exit(0);
     544:	00000513          	li	a0,0
     548:	275000ef          	jal	fbc <exit>
        printf("grind: fork failed\n");
     54c:	00001517          	auipc	a0,0x1
     550:	4d450513          	addi	a0,a0,1236 # 1a20 <malloc+0x280>
     554:	140010ef          	jal	1694 <printf>
        exit(1);
     558:	00100513          	li	a0,1
     55c:	261000ef          	jal	fbc <exit>
      if(pipe(fds) < 0){
     560:	f7840513          	addi	a0,s0,-136
     564:	271000ef          	jal	fd4 <pipe>
     568:	02054663          	bltz	a0,594 <go+0x4a0>
      int pid = fork();
     56c:	245000ef          	jal	fb0 <fork>
      if(pid == 0){
     570:	02050c63          	beqz	a0,5a8 <go+0x4b4>
      } else if(pid < 0){
     574:	08054c63          	bltz	a0,60c <go+0x518>
      close(fds[0]);
     578:	f7842503          	lw	a0,-136(s0)
     57c:	27d000ef          	jal	ff8 <close>
      close(fds[1]);
     580:	f7c42503          	lw	a0,-132(s0)
     584:	275000ef          	jal	ff8 <close>
      wait(0);
     588:	00000513          	li	a0,0
     58c:	23d000ef          	jal	fc8 <wait>
     590:	c85ff06f          	j	214 <go+0x120>
        printf("grind: pipe failed\n");
     594:	00001517          	auipc	a0,0x1
     598:	4d450513          	addi	a0,a0,1236 # 1a68 <malloc+0x2c8>
     59c:	0f8010ef          	jal	1694 <printf>
        exit(1);
     5a0:	00100513          	li	a0,1
     5a4:	219000ef          	jal	fbc <exit>
        fork();
     5a8:	209000ef          	jal	fb0 <fork>
        fork();
     5ac:	205000ef          	jal	fb0 <fork>
        if(write(fds[1], "x", 1) != 1)
     5b0:	00100613          	li	a2,1
     5b4:	00001597          	auipc	a1,0x1
     5b8:	4cc58593          	addi	a1,a1,1228 # 1a80 <malloc+0x2e0>
     5bc:	f7c42503          	lw	a0,-132(s0)
     5c0:	22d000ef          	jal	fec <write>
     5c4:	00100793          	li	a5,1
     5c8:	02f51263          	bne	a0,a5,5ec <go+0x4f8>
        if(read(fds[0], &c, 1) != 1)
     5cc:	00100613          	li	a2,1
     5d0:	f7040593          	addi	a1,s0,-144
     5d4:	f7842503          	lw	a0,-136(s0)
     5d8:	209000ef          	jal	fe0 <read>
     5dc:	00100793          	li	a5,1
     5e0:	00f51e63          	bne	a0,a5,5fc <go+0x508>
        exit(0);
     5e4:	00000513          	li	a0,0
     5e8:	1d5000ef          	jal	fbc <exit>
          printf("grind: pipe write failed\n");
     5ec:	00001517          	auipc	a0,0x1
     5f0:	49c50513          	addi	a0,a0,1180 # 1a88 <malloc+0x2e8>
     5f4:	0a0010ef          	jal	1694 <printf>
     5f8:	fd5ff06f          	j	5cc <go+0x4d8>
          printf("grind: pipe read failed\n");
     5fc:	00001517          	auipc	a0,0x1
     600:	4ac50513          	addi	a0,a0,1196 # 1aa8 <malloc+0x308>
     604:	090010ef          	jal	1694 <printf>
     608:	fddff06f          	j	5e4 <go+0x4f0>
        printf("grind: fork failed\n");
     60c:	00001517          	auipc	a0,0x1
     610:	41450513          	addi	a0,a0,1044 # 1a20 <malloc+0x280>
     614:	080010ef          	jal	1694 <printf>
        exit(1);
     618:	00100513          	li	a0,1
     61c:	1a1000ef          	jal	fbc <exit>
      int pid = fork();
     620:	191000ef          	jal	fb0 <fork>
      if(pid == 0){
     624:	00050a63          	beqz	a0,638 <go+0x544>
      } else if(pid < 0){
     628:	06054263          	bltz	a0,68c <go+0x598>
      wait(0);
     62c:	00000513          	li	a0,0
     630:	199000ef          	jal	fc8 <wait>
     634:	be1ff06f          	j	214 <go+0x120>
        unlink("a");
     638:	00001517          	auipc	a0,0x1
     63c:	40050513          	addi	a0,a0,1024 # 1a38 <malloc+0x298>
     640:	1f5000ef          	jal	1034 <unlink>
        mkdir("a");
     644:	00001517          	auipc	a0,0x1
     648:	3f450513          	addi	a0,a0,1012 # 1a38 <malloc+0x298>
     64c:	20d000ef          	jal	1058 <mkdir>
        chdir("a");
     650:	00001517          	auipc	a0,0x1
     654:	3e850513          	addi	a0,a0,1000 # 1a38 <malloc+0x298>
     658:	20d000ef          	jal	1064 <chdir>
        unlink("../a");
     65c:	00001517          	auipc	a0,0x1
     660:	46c50513          	addi	a0,a0,1132 # 1ac8 <malloc+0x328>
     664:	1d1000ef          	jal	1034 <unlink>
        fd = open("x", O_CREATE|O_RDWR);
     668:	20200593          	li	a1,514
     66c:	00001517          	auipc	a0,0x1
     670:	41450513          	addi	a0,a0,1044 # 1a80 <malloc+0x2e0>
     674:	1a9000ef          	jal	101c <open>
        unlink("x");
     678:	00001517          	auipc	a0,0x1
     67c:	40850513          	addi	a0,a0,1032 # 1a80 <malloc+0x2e0>
     680:	1b5000ef          	jal	1034 <unlink>
        exit(0);
     684:	00000513          	li	a0,0
     688:	135000ef          	jal	fbc <exit>
        printf("grind: fork failed\n");
     68c:	00001517          	auipc	a0,0x1
     690:	39450513          	addi	a0,a0,916 # 1a20 <malloc+0x280>
     694:	000010ef          	jal	1694 <printf>
        exit(1);
     698:	00100513          	li	a0,1
     69c:	121000ef          	jal	fbc <exit>
      unlink("c");
     6a0:	00001517          	auipc	a0,0x1
     6a4:	43050513          	addi	a0,a0,1072 # 1ad0 <malloc+0x330>
     6a8:	18d000ef          	jal	1034 <unlink>
      int fd1 = open("c", O_CREATE|O_RDWR);
     6ac:	20200593          	li	a1,514
     6b0:	00001517          	auipc	a0,0x1
     6b4:	42050513          	addi	a0,a0,1056 # 1ad0 <malloc+0x330>
     6b8:	165000ef          	jal	101c <open>
     6bc:	00050d13          	mv	s10,a0
      if(fd1 < 0){
     6c0:	04054a63          	bltz	a0,714 <go+0x620>
      if(write(fd1, "x", 1) != 1){
     6c4:	000a0613          	mv	a2,s4
     6c8:	00001597          	auipc	a1,0x1
     6cc:	3b858593          	addi	a1,a1,952 # 1a80 <malloc+0x2e0>
     6d0:	11d000ef          	jal	fec <write>
     6d4:	05451a63          	bne	a0,s4,728 <go+0x634>
      if(fstat(fd1, &st) != 0){
     6d8:	f7840593          	addi	a1,s0,-136
     6dc:	000d0513          	mv	a0,s10
     6e0:	161000ef          	jal	1040 <fstat>
     6e4:	04051c63          	bnez	a0,73c <go+0x648>
      if(st.size != 1){
     6e8:	f8843583          	ld	a1,-120(s0)
     6ec:	07459263          	bne	a1,s4,750 <go+0x65c>
      if(st.ino > 200){
     6f0:	f7c42583          	lw	a1,-132(s0)
     6f4:	0c800793          	li	a5,200
     6f8:	06b7e863          	bltu	a5,a1,768 <go+0x674>
      close(fd1);
     6fc:	000d0513          	mv	a0,s10
     700:	0f9000ef          	jal	ff8 <close>
      unlink("c");
     704:	00001517          	auipc	a0,0x1
     708:	3cc50513          	addi	a0,a0,972 # 1ad0 <malloc+0x330>
     70c:	129000ef          	jal	1034 <unlink>
     710:	b05ff06f          	j	214 <go+0x120>
        printf("grind: create c failed\n");
     714:	00001517          	auipc	a0,0x1
     718:	3c450513          	addi	a0,a0,964 # 1ad8 <malloc+0x338>
     71c:	779000ef          	jal	1694 <printf>
        exit(1);
     720:	00100513          	li	a0,1
     724:	099000ef          	jal	fbc <exit>
        printf("grind: write c failed\n");
     728:	00001517          	auipc	a0,0x1
     72c:	3c850513          	addi	a0,a0,968 # 1af0 <malloc+0x350>
     730:	765000ef          	jal	1694 <printf>
        exit(1);
     734:	00100513          	li	a0,1
     738:	085000ef          	jal	fbc <exit>
        printf("grind: fstat failed\n");
     73c:	00001517          	auipc	a0,0x1
     740:	3cc50513          	addi	a0,a0,972 # 1b08 <malloc+0x368>
     744:	751000ef          	jal	1694 <printf>
        exit(1);
     748:	00100513          	li	a0,1
     74c:	071000ef          	jal	fbc <exit>
        printf("grind: fstat reports wrong size %d\n", (int)st.size);
     750:	0005859b          	sext.w	a1,a1
     754:	00001517          	auipc	a0,0x1
     758:	3cc50513          	addi	a0,a0,972 # 1b20 <malloc+0x380>
     75c:	739000ef          	jal	1694 <printf>
        exit(1);
     760:	00100513          	li	a0,1
     764:	059000ef          	jal	fbc <exit>
        printf("grind: fstat reports crazy i-number %d\n", st.ino);
     768:	00001517          	auipc	a0,0x1
     76c:	3e050513          	addi	a0,a0,992 # 1b48 <malloc+0x3a8>
     770:	725000ef          	jal	1694 <printf>
        exit(1);
     774:	00100513          	li	a0,1
     778:	045000ef          	jal	fbc <exit>
      if(pipe(aa) < 0){
     77c:	000d8513          	mv	a0,s11
     780:	055000ef          	jal	fd4 <pipe>
     784:	0c054863          	bltz	a0,854 <go+0x760>
        fprintf(2, "grind: pipe failed\n");
        exit(1);
      }
      if(pipe(bb) < 0){
     788:	f7040513          	addi	a0,s0,-144
     78c:	049000ef          	jal	fd4 <pipe>
     790:	0c054e63          	bltz	a0,86c <go+0x778>
        fprintf(2, "grind: pipe failed\n");
        exit(1);
      }
      int pid1 = fork();
     794:	01d000ef          	jal	fb0 <fork>
      if(pid1 == 0){
     798:	0e050663          	beqz	a0,884 <go+0x790>
        close(aa[1]);
        char *args[3] = { "echo", "hi", 0 };
        exec("grindir/../echo", args);
        fprintf(2, "grind: echo: not found\n");
        exit(2);
      } else if(pid1 < 0){
     79c:	16054e63          	bltz	a0,918 <go+0x824>
        fprintf(2, "grind: fork failed\n");
        exit(3);
      }
      int pid2 = fork();
     7a0:	011000ef          	jal	fb0 <fork>
      if(pid2 == 0){
     7a4:	18050663          	beqz	a0,930 <go+0x83c>
        close(bb[1]);
        char *args[2] = { "cat", 0 };
        exec("/cat", args);
        fprintf(2, "grind: cat: not found\n");
        exit(6);
      } else if(pid2 < 0){
     7a8:	22054e63          	bltz	a0,9e4 <go+0x8f0>
        fprintf(2, "grind: fork failed\n");
        exit(7);
      }
      close(aa[0]);
     7ac:	f6842503          	lw	a0,-152(s0)
     7b0:	049000ef          	jal	ff8 <close>
      close(aa[1]);
     7b4:	f6c42503          	lw	a0,-148(s0)
     7b8:	041000ef          	jal	ff8 <close>
      close(bb[1]);
     7bc:	f7442503          	lw	a0,-140(s0)
     7c0:	039000ef          	jal	ff8 <close>
      char buf[4] = { 0, 0, 0, 0 };
     7c4:	f6042023          	sw	zero,-160(s0)
      read(bb[0], buf+0, 1);
     7c8:	000a0613          	mv	a2,s4
     7cc:	f6040593          	addi	a1,s0,-160
     7d0:	f7042503          	lw	a0,-144(s0)
     7d4:	00d000ef          	jal	fe0 <read>
      read(bb[0], buf+1, 1);
     7d8:	000a0613          	mv	a2,s4
     7dc:	f6140593          	addi	a1,s0,-159
     7e0:	f7042503          	lw	a0,-144(s0)
     7e4:	7fc000ef          	jal	fe0 <read>
      read(bb[0], buf+2, 1);
     7e8:	000a0613          	mv	a2,s4
     7ec:	f6240593          	addi	a1,s0,-158
     7f0:	f7042503          	lw	a0,-144(s0)
     7f4:	7ec000ef          	jal	fe0 <read>
      close(bb[0]);
     7f8:	f7042503          	lw	a0,-144(s0)
     7fc:	7fc000ef          	jal	ff8 <close>
      int st1, st2;
      wait(&st1);
     800:	f6440513          	addi	a0,s0,-156
     804:	7c4000ef          	jal	fc8 <wait>
      wait(&st2);
     808:	f7840513          	addi	a0,s0,-136
     80c:	7bc000ef          	jal	fc8 <wait>
      if(st1 != 0 || st2 != 0 || strcmp(buf, "hi\n") != 0){
     810:	f6442783          	lw	a5,-156(s0)
     814:	f7842703          	lw	a4,-136(s0)
     818:	00e7e7b3          	or	a5,a5,a4
     81c:	00079c63          	bnez	a5,834 <go+0x740>
     820:	00001597          	auipc	a1,0x1
     824:	3c858593          	addi	a1,a1,968 # 1be8 <malloc+0x448>
     828:	f6040513          	addi	a0,s0,-160
     82c:	380000ef          	jal	bac <strcmp>
     830:	9e0502e3          	beqz	a0,214 <go+0x120>
        printf("grind: exec pipeline failed %d %d \"%s\"\n", st1, st2, buf);
     834:	f6040693          	addi	a3,s0,-160
     838:	f7842603          	lw	a2,-136(s0)
     83c:	f6442583          	lw	a1,-156(s0)
     840:	00001517          	auipc	a0,0x1
     844:	3b050513          	addi	a0,a0,944 # 1bf0 <malloc+0x450>
     848:	64d000ef          	jal	1694 <printf>
        exit(1);
     84c:	00100513          	li	a0,1
     850:	76c000ef          	jal	fbc <exit>
        fprintf(2, "grind: pipe failed\n");
     854:	00001597          	auipc	a1,0x1
     858:	21458593          	addi	a1,a1,532 # 1a68 <malloc+0x2c8>
     85c:	00200513          	li	a0,2
     860:	5f1000ef          	jal	1650 <fprintf>
        exit(1);
     864:	00100513          	li	a0,1
     868:	754000ef          	jal	fbc <exit>
        fprintf(2, "grind: pipe failed\n");
     86c:	00001597          	auipc	a1,0x1
     870:	1fc58593          	addi	a1,a1,508 # 1a68 <malloc+0x2c8>
     874:	00200513          	li	a0,2
     878:	5d9000ef          	jal	1650 <fprintf>
        exit(1);
     87c:	00100513          	li	a0,1
     880:	73c000ef          	jal	fbc <exit>
        close(bb[0]);
     884:	f7042503          	lw	a0,-144(s0)
     888:	770000ef          	jal	ff8 <close>
        close(bb[1]);
     88c:	f7442503          	lw	a0,-140(s0)
     890:	768000ef          	jal	ff8 <close>
        close(aa[0]);
     894:	f6842503          	lw	a0,-152(s0)
     898:	760000ef          	jal	ff8 <close>
        close(1);
     89c:	00100513          	li	a0,1
     8a0:	758000ef          	jal	ff8 <close>
        if(dup(aa[1]) != 1){
     8a4:	f6c42503          	lw	a0,-148(s0)
     8a8:	7c8000ef          	jal	1070 <dup>
     8ac:	00100793          	li	a5,1
     8b0:	00f50e63          	beq	a0,a5,8cc <go+0x7d8>
          fprintf(2, "grind: dup failed\n");
     8b4:	00001597          	auipc	a1,0x1
     8b8:	2bc58593          	addi	a1,a1,700 # 1b70 <malloc+0x3d0>
     8bc:	00200513          	li	a0,2
     8c0:	591000ef          	jal	1650 <fprintf>
          exit(1);
     8c4:	00100513          	li	a0,1
     8c8:	6f4000ef          	jal	fbc <exit>
        close(aa[1]);
     8cc:	f6c42503          	lw	a0,-148(s0)
     8d0:	728000ef          	jal	ff8 <close>
        char *args[3] = { "echo", "hi", 0 };
     8d4:	00001797          	auipc	a5,0x1
     8d8:	2b478793          	addi	a5,a5,692 # 1b88 <malloc+0x3e8>
     8dc:	f6f43c23          	sd	a5,-136(s0)
     8e0:	00001797          	auipc	a5,0x1
     8e4:	2b078793          	addi	a5,a5,688 # 1b90 <malloc+0x3f0>
     8e8:	f8f43023          	sd	a5,-128(s0)
     8ec:	f8043423          	sd	zero,-120(s0)
        exec("grindir/../echo", args);
     8f0:	f7840593          	addi	a1,s0,-136
     8f4:	00001517          	auipc	a0,0x1
     8f8:	2a450513          	addi	a0,a0,676 # 1b98 <malloc+0x3f8>
     8fc:	714000ef          	jal	1010 <exec>
        fprintf(2, "grind: echo: not found\n");
     900:	00001597          	auipc	a1,0x1
     904:	2a858593          	addi	a1,a1,680 # 1ba8 <malloc+0x408>
     908:	00200513          	li	a0,2
     90c:	545000ef          	jal	1650 <fprintf>
        exit(2);
     910:	00200513          	li	a0,2
     914:	6a8000ef          	jal	fbc <exit>
        fprintf(2, "grind: fork failed\n");
     918:	00001597          	auipc	a1,0x1
     91c:	10858593          	addi	a1,a1,264 # 1a20 <malloc+0x280>
     920:	00200513          	li	a0,2
     924:	52d000ef          	jal	1650 <fprintf>
        exit(3);
     928:	00300513          	li	a0,3
     92c:	690000ef          	jal	fbc <exit>
        close(aa[1]);
     930:	f6c42503          	lw	a0,-148(s0)
     934:	6c4000ef          	jal	ff8 <close>
        close(bb[0]);
     938:	f7042503          	lw	a0,-144(s0)
     93c:	6bc000ef          	jal	ff8 <close>
        close(0);
     940:	00000513          	li	a0,0
     944:	6b4000ef          	jal	ff8 <close>
        if(dup(aa[0]) != 0){
     948:	f6842503          	lw	a0,-152(s0)
     94c:	724000ef          	jal	1070 <dup>
     950:	00050e63          	beqz	a0,96c <go+0x878>
          fprintf(2, "grind: dup failed\n");
     954:	00001597          	auipc	a1,0x1
     958:	21c58593          	addi	a1,a1,540 # 1b70 <malloc+0x3d0>
     95c:	00200513          	li	a0,2
     960:	4f1000ef          	jal	1650 <fprintf>
          exit(4);
     964:	00400513          	li	a0,4
     968:	654000ef          	jal	fbc <exit>
        close(aa[0]);
     96c:	f6842503          	lw	a0,-152(s0)
     970:	688000ef          	jal	ff8 <close>
        close(1);
     974:	00100513          	li	a0,1
     978:	680000ef          	jal	ff8 <close>
        if(dup(bb[1]) != 1){
     97c:	f7442503          	lw	a0,-140(s0)
     980:	6f0000ef          	jal	1070 <dup>
     984:	00100793          	li	a5,1
     988:	00f50e63          	beq	a0,a5,9a4 <go+0x8b0>
          fprintf(2, "grind: dup failed\n");
     98c:	00001597          	auipc	a1,0x1
     990:	1e458593          	addi	a1,a1,484 # 1b70 <malloc+0x3d0>
     994:	00200513          	li	a0,2
     998:	4b9000ef          	jal	1650 <fprintf>
          exit(5);
     99c:	00500513          	li	a0,5
     9a0:	61c000ef          	jal	fbc <exit>
        close(bb[1]);
     9a4:	f7442503          	lw	a0,-140(s0)
     9a8:	650000ef          	jal	ff8 <close>
        char *args[2] = { "cat", 0 };
     9ac:	00001797          	auipc	a5,0x1
     9b0:	21478793          	addi	a5,a5,532 # 1bc0 <malloc+0x420>
     9b4:	f6f43c23          	sd	a5,-136(s0)
     9b8:	f8043023          	sd	zero,-128(s0)
        exec("/cat", args);
     9bc:	f7840593          	addi	a1,s0,-136
     9c0:	00001517          	auipc	a0,0x1
     9c4:	20850513          	addi	a0,a0,520 # 1bc8 <malloc+0x428>
     9c8:	648000ef          	jal	1010 <exec>
        fprintf(2, "grind: cat: not found\n");
     9cc:	00001597          	auipc	a1,0x1
     9d0:	20458593          	addi	a1,a1,516 # 1bd0 <malloc+0x430>
     9d4:	00200513          	li	a0,2
     9d8:	479000ef          	jal	1650 <fprintf>
        exit(6);
     9dc:	00600513          	li	a0,6
     9e0:	5dc000ef          	jal	fbc <exit>
        fprintf(2, "grind: fork failed\n");
     9e4:	00001597          	auipc	a1,0x1
     9e8:	03c58593          	addi	a1,a1,60 # 1a20 <malloc+0x280>
     9ec:	00200513          	li	a0,2
     9f0:	461000ef          	jal	1650 <fprintf>
        exit(7);
     9f4:	00700513          	li	a0,7
     9f8:	5c4000ef          	jal	fbc <exit>

00000000000009fc <iter>:
  }
}

void
iter()
{
     9fc:	fd010113          	addi	sp,sp,-48
     a00:	02113423          	sd	ra,40(sp)
     a04:	02813023          	sd	s0,32(sp)
     a08:	03010413          	addi	s0,sp,48
  unlink("a");
     a0c:	00001517          	auipc	a0,0x1
     a10:	02c50513          	addi	a0,a0,44 # 1a38 <malloc+0x298>
     a14:	620000ef          	jal	1034 <unlink>
  unlink("b");
     a18:	00001517          	auipc	a0,0x1
     a1c:	fd050513          	addi	a0,a0,-48 # 19e8 <malloc+0x248>
     a20:	614000ef          	jal	1034 <unlink>
  
  int pid1 = fork();
     a24:	58c000ef          	jal	fb0 <fork>
  if(pid1 < 0){
     a28:	02054863          	bltz	a0,a58 <iter+0x5c>
     a2c:	00913c23          	sd	s1,24(sp)
     a30:	00050493          	mv	s1,a0
    printf("grind: fork failed\n");
    exit(1);
  }
  if(pid1 == 0){
     a34:	04051063          	bnez	a0,a74 <iter+0x78>
     a38:	01213823          	sd	s2,16(sp)
    rand_next ^= 31;
     a3c:	00001717          	auipc	a4,0x1
     a40:	5c470713          	addi	a4,a4,1476 # 2000 <rand_next>
     a44:	00073783          	ld	a5,0(a4)
     a48:	01f7c793          	xori	a5,a5,31
     a4c:	00f73023          	sd	a5,0(a4)
    go(0);
     a50:	00000513          	li	a0,0
     a54:	ea0ff0ef          	jal	f4 <go>
     a58:	00913c23          	sd	s1,24(sp)
     a5c:	01213823          	sd	s2,16(sp)
    printf("grind: fork failed\n");
     a60:	00001517          	auipc	a0,0x1
     a64:	fc050513          	addi	a0,a0,-64 # 1a20 <malloc+0x280>
     a68:	42d000ef          	jal	1694 <printf>
    exit(1);
     a6c:	00100513          	li	a0,1
     a70:	54c000ef          	jal	fbc <exit>
     a74:	01213823          	sd	s2,16(sp)
    exit(0);
  }

  int pid2 = fork();
     a78:	538000ef          	jal	fb0 <fork>
     a7c:	00050913          	mv	s2,a0
  if(pid2 < 0){
     a80:	02054663          	bltz	a0,aac <iter+0xb0>
    printf("grind: fork failed\n");
    exit(1);
  }
  if(pid2 == 0){
     a84:	02051e63          	bnez	a0,ac0 <iter+0xc4>
    rand_next ^= 7177;
     a88:	00001697          	auipc	a3,0x1
     a8c:	57868693          	addi	a3,a3,1400 # 2000 <rand_next>
     a90:	0006b783          	ld	a5,0(a3)
     a94:	00002737          	lui	a4,0x2
     a98:	c0970713          	addi	a4,a4,-1015 # 1c09 <malloc+0x469>
     a9c:	00e7c7b3          	xor	a5,a5,a4
     aa0:	00f6b023          	sd	a5,0(a3)
    go(1);
     aa4:	00100513          	li	a0,1
     aa8:	e4cff0ef          	jal	f4 <go>
    printf("grind: fork failed\n");
     aac:	00001517          	auipc	a0,0x1
     ab0:	f7450513          	addi	a0,a0,-140 # 1a20 <malloc+0x280>
     ab4:	3e1000ef          	jal	1694 <printf>
    exit(1);
     ab8:	00100513          	li	a0,1
     abc:	500000ef          	jal	fbc <exit>
    exit(0);
  }

  int st1 = -1;
     ac0:	fff00793          	li	a5,-1
     ac4:	fcf42e23          	sw	a5,-36(s0)
  wait(&st1);
     ac8:	fdc40513          	addi	a0,s0,-36
     acc:	4fc000ef          	jal	fc8 <wait>
  if(st1 != 0){
     ad0:	fdc42783          	lw	a5,-36(s0)
     ad4:	00079e63          	bnez	a5,af0 <iter+0xf4>
    kill(pid1);
    kill(pid2);
  }
  int st2 = -1;
     ad8:	fff00793          	li	a5,-1
     adc:	fcf42c23          	sw	a5,-40(s0)
  wait(&st2);
     ae0:	fd840513          	addi	a0,s0,-40
     ae4:	4e4000ef          	jal	fc8 <wait>

  exit(0);
     ae8:	00000513          	li	a0,0
     aec:	4d0000ef          	jal	fbc <exit>
    kill(pid1);
     af0:	00048513          	mv	a0,s1
     af4:	510000ef          	jal	1004 <kill>
    kill(pid2);
     af8:	00090513          	mv	a0,s2
     afc:	508000ef          	jal	1004 <kill>
     b00:	fd9ff06f          	j	ad8 <iter+0xdc>

0000000000000b04 <main>:
}

int
main()
{
     b04:	fe010113          	addi	sp,sp,-32
     b08:	00113c23          	sd	ra,24(sp)
     b0c:	00813823          	sd	s0,16(sp)
     b10:	00913423          	sd	s1,8(sp)
     b14:	01213023          	sd	s2,0(sp)
     b18:	02010413          	addi	s0,sp,32
      exit(0);
    }
    if(pid > 0){
      wait(0);
    }
    pause(20);
     b1c:	01400913          	li	s2,20
    rand_next += 1;
     b20:	00001497          	auipc	s1,0x1
     b24:	4e048493          	addi	s1,s1,1248 # 2000 <rand_next>
     b28:	01c0006f          	j	b44 <main+0x40>
      iter();
     b2c:	ed1ff0ef          	jal	9fc <iter>
    pause(20);
     b30:	00090513          	mv	a0,s2
     b34:	560000ef          	jal	1094 <pause>
    rand_next += 1;
     b38:	0004b783          	ld	a5,0(s1)
     b3c:	00178793          	addi	a5,a5,1
     b40:	00f4b023          	sd	a5,0(s1)
    int pid = fork();
     b44:	46c000ef          	jal	fb0 <fork>
    if(pid == 0){
     b48:	fe0502e3          	beqz	a0,b2c <main+0x28>
    if(pid > 0){
     b4c:	fea052e3          	blez	a0,b30 <main+0x2c>
      wait(0);
     b50:	00000513          	li	a0,0
     b54:	474000ef          	jal	fc8 <wait>
     b58:	fd9ff06f          	j	b30 <main+0x2c>

0000000000000b5c <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
     b5c:	ff010113          	addi	sp,sp,-16
     b60:	00113423          	sd	ra,8(sp)
     b64:	00813023          	sd	s0,0(sp)
     b68:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
     b6c:	f99ff0ef          	jal	b04 <main>
  exit(r);
     b70:	44c000ef          	jal	fbc <exit>

0000000000000b74 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
     b74:	ff010113          	addi	sp,sp,-16
     b78:	00113423          	sd	ra,8(sp)
     b7c:	00813023          	sd	s0,0(sp)
     b80:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
     b84:	00050793          	mv	a5,a0
     b88:	00158593          	addi	a1,a1,1
     b8c:	00178793          	addi	a5,a5,1
     b90:	fff5c703          	lbu	a4,-1(a1)
     b94:	fee78fa3          	sb	a4,-1(a5)
     b98:	fe0718e3          	bnez	a4,b88 <strcpy+0x14>
    ;
  return os;
}
     b9c:	00813083          	ld	ra,8(sp)
     ba0:	00013403          	ld	s0,0(sp)
     ba4:	01010113          	addi	sp,sp,16
     ba8:	00008067          	ret

0000000000000bac <strcmp>:

int
strcmp(const char *p, const char *q)
{
     bac:	ff010113          	addi	sp,sp,-16
     bb0:	00113423          	sd	ra,8(sp)
     bb4:	00813023          	sd	s0,0(sp)
     bb8:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
     bbc:	00054783          	lbu	a5,0(a0)
     bc0:	00078e63          	beqz	a5,bdc <strcmp+0x30>
     bc4:	0005c703          	lbu	a4,0(a1)
     bc8:	00f71a63          	bne	a4,a5,bdc <strcmp+0x30>
    p++, q++;
     bcc:	00150513          	addi	a0,a0,1
     bd0:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
     bd4:	00054783          	lbu	a5,0(a0)
     bd8:	fe0796e3          	bnez	a5,bc4 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
     bdc:	0005c503          	lbu	a0,0(a1)
}
     be0:	40a7853b          	subw	a0,a5,a0
     be4:	00813083          	ld	ra,8(sp)
     be8:	00013403          	ld	s0,0(sp)
     bec:	01010113          	addi	sp,sp,16
     bf0:	00008067          	ret

0000000000000bf4 <strlen>:

uint
strlen(const char *s)
{
     bf4:	ff010113          	addi	sp,sp,-16
     bf8:	00113423          	sd	ra,8(sp)
     bfc:	00813023          	sd	s0,0(sp)
     c00:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
     c04:	00054783          	lbu	a5,0(a0)
     c08:	02078663          	beqz	a5,c34 <strlen+0x40>
     c0c:	00150793          	addi	a5,a0,1
     c10:	00078693          	mv	a3,a5
     c14:	00178793          	addi	a5,a5,1
     c18:	fff7c703          	lbu	a4,-1(a5)
     c1c:	fe071ae3          	bnez	a4,c10 <strlen+0x1c>
     c20:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
     c24:	00813083          	ld	ra,8(sp)
     c28:	00013403          	ld	s0,0(sp)
     c2c:	01010113          	addi	sp,sp,16
     c30:	00008067          	ret
  for(n = 0; s[n]; n++)
     c34:	00000513          	li	a0,0
     c38:	fedff06f          	j	c24 <strlen+0x30>

0000000000000c3c <memset>:

void*
memset(void *dst, int c, uint n)
{
     c3c:	ff010113          	addi	sp,sp,-16
     c40:	00113423          	sd	ra,8(sp)
     c44:	00813023          	sd	s0,0(sp)
     c48:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
     c4c:	02060063          	beqz	a2,c6c <memset+0x30>
     c50:	00050793          	mv	a5,a0
     c54:	02061613          	slli	a2,a2,0x20
     c58:	02065613          	srli	a2,a2,0x20
     c5c:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
     c60:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
     c64:	00178793          	addi	a5,a5,1
     c68:	fee79ce3          	bne	a5,a4,c60 <memset+0x24>
  }
  return dst;
}
     c6c:	00813083          	ld	ra,8(sp)
     c70:	00013403          	ld	s0,0(sp)
     c74:	01010113          	addi	sp,sp,16
     c78:	00008067          	ret

0000000000000c7c <strchr>:

char*
strchr(const char *s, char c)
{
     c7c:	ff010113          	addi	sp,sp,-16
     c80:	00113423          	sd	ra,8(sp)
     c84:	00813023          	sd	s0,0(sp)
     c88:	01010413          	addi	s0,sp,16
  for(; *s; s++)
     c8c:	00054783          	lbu	a5,0(a0)
     c90:	02078463          	beqz	a5,cb8 <strchr+0x3c>
    if(*s == c)
     c94:	00f58a63          	beq	a1,a5,ca8 <strchr+0x2c>
  for(; *s; s++)
     c98:	00150513          	addi	a0,a0,1
     c9c:	00054783          	lbu	a5,0(a0)
     ca0:	fe079ae3          	bnez	a5,c94 <strchr+0x18>
      return (char*)s;
  return 0;
     ca4:	00000513          	li	a0,0
}
     ca8:	00813083          	ld	ra,8(sp)
     cac:	00013403          	ld	s0,0(sp)
     cb0:	01010113          	addi	sp,sp,16
     cb4:	00008067          	ret
  return 0;
     cb8:	00000513          	li	a0,0
     cbc:	fedff06f          	j	ca8 <strchr+0x2c>

0000000000000cc0 <gets>:

char*
gets(char *buf, int max)
{
     cc0:	fa010113          	addi	sp,sp,-96
     cc4:	04113c23          	sd	ra,88(sp)
     cc8:	04813823          	sd	s0,80(sp)
     ccc:	04913423          	sd	s1,72(sp)
     cd0:	05213023          	sd	s2,64(sp)
     cd4:	03313c23          	sd	s3,56(sp)
     cd8:	03413823          	sd	s4,48(sp)
     cdc:	03513423          	sd	s5,40(sp)
     ce0:	03613023          	sd	s6,32(sp)
     ce4:	01713c23          	sd	s7,24(sp)
     ce8:	01813823          	sd	s8,16(sp)
     cec:	06010413          	addi	s0,sp,96
     cf0:	00050b93          	mv	s7,a0
     cf4:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
     cf8:	00050913          	mv	s2,a0
     cfc:	00000493          	li	s1,0
    cc = read(0, &c, 1);
     d00:	faf40b13          	addi	s6,s0,-81
     d04:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
     d08:	00048c13          	mv	s8,s1
     d0c:	0014899b          	addiw	s3,s1,1
     d10:	00098493          	mv	s1,s3
     d14:	0349dc63          	bge	s3,s4,d4c <gets+0x8c>
    cc = read(0, &c, 1);
     d18:	000a8613          	mv	a2,s5
     d1c:	000b0593          	mv	a1,s6
     d20:	00000513          	li	a0,0
     d24:	2bc000ef          	jal	fe0 <read>
    if(cc < 1)
     d28:	02a05263          	blez	a0,d4c <gets+0x8c>
      break;
    buf[i++] = c;
     d2c:	faf44783          	lbu	a5,-81(s0)
     d30:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
     d34:	00190913          	addi	s2,s2,1
     d38:	ff678713          	addi	a4,a5,-10
     d3c:	00070663          	beqz	a4,d48 <gets+0x88>
     d40:	ff378793          	addi	a5,a5,-13
     d44:	fc0792e3          	bnez	a5,d08 <gets+0x48>
    buf[i++] = c;
     d48:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
     d4c:	018b8c33          	add	s8,s7,s8
     d50:	000c0023          	sb	zero,0(s8)
  return buf;
}
     d54:	000b8513          	mv	a0,s7
     d58:	05813083          	ld	ra,88(sp)
     d5c:	05013403          	ld	s0,80(sp)
     d60:	04813483          	ld	s1,72(sp)
     d64:	04013903          	ld	s2,64(sp)
     d68:	03813983          	ld	s3,56(sp)
     d6c:	03013a03          	ld	s4,48(sp)
     d70:	02813a83          	ld	s5,40(sp)
     d74:	02013b03          	ld	s6,32(sp)
     d78:	01813b83          	ld	s7,24(sp)
     d7c:	01013c03          	ld	s8,16(sp)
     d80:	06010113          	addi	sp,sp,96
     d84:	00008067          	ret

0000000000000d88 <stat>:

int
stat(const char *n, struct stat *st)
{
     d88:	fe010113          	addi	sp,sp,-32
     d8c:	00113c23          	sd	ra,24(sp)
     d90:	00813823          	sd	s0,16(sp)
     d94:	01213023          	sd	s2,0(sp)
     d98:	02010413          	addi	s0,sp,32
     d9c:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
     da0:	00000593          	li	a1,0
     da4:	278000ef          	jal	101c <open>
  if(fd < 0)
     da8:	02054e63          	bltz	a0,de4 <stat+0x5c>
     dac:	00913423          	sd	s1,8(sp)
     db0:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
     db4:	00090593          	mv	a1,s2
     db8:	288000ef          	jal	1040 <fstat>
     dbc:	00050913          	mv	s2,a0
  close(fd);
     dc0:	00048513          	mv	a0,s1
     dc4:	234000ef          	jal	ff8 <close>
  return r;
     dc8:	00813483          	ld	s1,8(sp)
}
     dcc:	00090513          	mv	a0,s2
     dd0:	01813083          	ld	ra,24(sp)
     dd4:	01013403          	ld	s0,16(sp)
     dd8:	00013903          	ld	s2,0(sp)
     ddc:	02010113          	addi	sp,sp,32
     de0:	00008067          	ret
    return -1;
     de4:	fff00793          	li	a5,-1
     de8:	00078913          	mv	s2,a5
     dec:	fe1ff06f          	j	dcc <stat+0x44>

0000000000000df0 <atoi>:

int
atoi(const char *s)
{
     df0:	ff010113          	addi	sp,sp,-16
     df4:	00113423          	sd	ra,8(sp)
     df8:	00813023          	sd	s0,0(sp)
     dfc:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
     e00:	00054683          	lbu	a3,0(a0)
     e04:	fd06879b          	addiw	a5,a3,-48
     e08:	0ff7f793          	zext.b	a5,a5
     e0c:	00900613          	li	a2,9
     e10:	04f66263          	bltu	a2,a5,e54 <atoi+0x64>
     e14:	00050713          	mv	a4,a0
  n = 0;
     e18:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
     e1c:	00170713          	addi	a4,a4,1
     e20:	0025179b          	slliw	a5,a0,0x2
     e24:	00a787bb          	addw	a5,a5,a0
     e28:	0017979b          	slliw	a5,a5,0x1
     e2c:	00d787bb          	addw	a5,a5,a3
     e30:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
     e34:	00074683          	lbu	a3,0(a4)
     e38:	fd06879b          	addiw	a5,a3,-48
     e3c:	0ff7f793          	zext.b	a5,a5
     e40:	fcf67ee3          	bgeu	a2,a5,e1c <atoi+0x2c>
  return n;
}
     e44:	00813083          	ld	ra,8(sp)
     e48:	00013403          	ld	s0,0(sp)
     e4c:	01010113          	addi	sp,sp,16
     e50:	00008067          	ret
  n = 0;
     e54:	00000513          	li	a0,0
     e58:	fedff06f          	j	e44 <atoi+0x54>

0000000000000e5c <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
     e5c:	ff010113          	addi	sp,sp,-16
     e60:	00113423          	sd	ra,8(sp)
     e64:	00813023          	sd	s0,0(sp)
     e68:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
     e6c:	02b57e63          	bgeu	a0,a1,ea8 <memmove+0x4c>
    while(n-- > 0)
     e70:	02c05463          	blez	a2,e98 <memmove+0x3c>
     e74:	02061613          	slli	a2,a2,0x20
     e78:	02065613          	srli	a2,a2,0x20
     e7c:	00c507b3          	add	a5,a0,a2
  dst = vdst;
     e80:	00050713          	mv	a4,a0
      *dst++ = *src++;
     e84:	00158593          	addi	a1,a1,1
     e88:	00170713          	addi	a4,a4,1
     e8c:	fff5c683          	lbu	a3,-1(a1)
     e90:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
     e94:	fee798e3          	bne	a5,a4,e84 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
     e98:	00813083          	ld	ra,8(sp)
     e9c:	00013403          	ld	s0,0(sp)
     ea0:	01010113          	addi	sp,sp,16
     ea4:	00008067          	ret
    while(n-- > 0)
     ea8:	fec058e3          	blez	a2,e98 <memmove+0x3c>
    dst += n;
     eac:	00c50733          	add	a4,a0,a2
    src += n;
     eb0:	00c585b3          	add	a1,a1,a2
     eb4:	fff6079b          	addiw	a5,a2,-1
     eb8:	02079793          	slli	a5,a5,0x20
     ebc:	0207d793          	srli	a5,a5,0x20
     ec0:	fff7c793          	not	a5,a5
     ec4:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
     ec8:	fff58593          	addi	a1,a1,-1
     ecc:	fff70713          	addi	a4,a4,-1
     ed0:	0005c683          	lbu	a3,0(a1)
     ed4:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
     ed8:	fef718e3          	bne	a4,a5,ec8 <memmove+0x6c>
     edc:	fbdff06f          	j	e98 <memmove+0x3c>

0000000000000ee0 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
     ee0:	ff010113          	addi	sp,sp,-16
     ee4:	00113423          	sd	ra,8(sp)
     ee8:	00813023          	sd	s0,0(sp)
     eec:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
     ef0:	04060263          	beqz	a2,f34 <memcmp+0x54>
     ef4:	02061613          	slli	a2,a2,0x20
     ef8:	02065613          	srli	a2,a2,0x20
     efc:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
     f00:	00054783          	lbu	a5,0(a0)
     f04:	0005c703          	lbu	a4,0(a1)
     f08:	00e79c63          	bne	a5,a4,f20 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
     f0c:	00150513          	addi	a0,a0,1
    p2++;
     f10:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
     f14:	fed516e3          	bne	a0,a3,f00 <memcmp+0x20>
  }
  return 0;
     f18:	00000513          	li	a0,0
     f1c:	0080006f          	j	f24 <memcmp+0x44>
      return *p1 - *p2;
     f20:	40e7853b          	subw	a0,a5,a4
}
     f24:	00813083          	ld	ra,8(sp)
     f28:	00013403          	ld	s0,0(sp)
     f2c:	01010113          	addi	sp,sp,16
     f30:	00008067          	ret
  return 0;
     f34:	00000513          	li	a0,0
     f38:	fedff06f          	j	f24 <memcmp+0x44>

0000000000000f3c <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
     f3c:	ff010113          	addi	sp,sp,-16
     f40:	00113423          	sd	ra,8(sp)
     f44:	00813023          	sd	s0,0(sp)
     f48:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
     f4c:	f11ff0ef          	jal	e5c <memmove>
}
     f50:	00813083          	ld	ra,8(sp)
     f54:	00013403          	ld	s0,0(sp)
     f58:	01010113          	addi	sp,sp,16
     f5c:	00008067          	ret

0000000000000f60 <sbrk>:

char *
sbrk(int n) {
     f60:	ff010113          	addi	sp,sp,-16
     f64:	00113423          	sd	ra,8(sp)
     f68:	00813023          	sd	s0,0(sp)
     f6c:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
     f70:	00100593          	li	a1,1
     f74:	114000ef          	jal	1088 <sys_sbrk>
}
     f78:	00813083          	ld	ra,8(sp)
     f7c:	00013403          	ld	s0,0(sp)
     f80:	01010113          	addi	sp,sp,16
     f84:	00008067          	ret

0000000000000f88 <sbrklazy>:

char *
sbrklazy(int n) {
     f88:	ff010113          	addi	sp,sp,-16
     f8c:	00113423          	sd	ra,8(sp)
     f90:	00813023          	sd	s0,0(sp)
     f94:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
     f98:	00200593          	li	a1,2
     f9c:	0ec000ef          	jal	1088 <sys_sbrk>
}
     fa0:	00813083          	ld	ra,8(sp)
     fa4:	00013403          	ld	s0,0(sp)
     fa8:	01010113          	addi	sp,sp,16
     fac:	00008067          	ret

0000000000000fb0 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
     fb0:	00100893          	li	a7,1
 ecall
     fb4:	00000073          	ecall
 ret
     fb8:	00008067          	ret

0000000000000fbc <exit>:
.global exit
exit:
 li a7, SYS_exit
     fbc:	00200893          	li	a7,2
 ecall
     fc0:	00000073          	ecall
 ret
     fc4:	00008067          	ret

0000000000000fc8 <wait>:
.global wait
wait:
 li a7, SYS_wait
     fc8:	00300893          	li	a7,3
 ecall
     fcc:	00000073          	ecall
 ret
     fd0:	00008067          	ret

0000000000000fd4 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
     fd4:	00400893          	li	a7,4
 ecall
     fd8:	00000073          	ecall
 ret
     fdc:	00008067          	ret

0000000000000fe0 <read>:
.global read
read:
 li a7, SYS_read
     fe0:	00500893          	li	a7,5
 ecall
     fe4:	00000073          	ecall
 ret
     fe8:	00008067          	ret

0000000000000fec <write>:
.global write
write:
 li a7, SYS_write
     fec:	01000893          	li	a7,16
 ecall
     ff0:	00000073          	ecall
 ret
     ff4:	00008067          	ret

0000000000000ff8 <close>:
.global close
close:
 li a7, SYS_close
     ff8:	01500893          	li	a7,21
 ecall
     ffc:	00000073          	ecall
 ret
    1000:	00008067          	ret

0000000000001004 <kill>:
.global kill
kill:
 li a7, SYS_kill
    1004:	00600893          	li	a7,6
 ecall
    1008:	00000073          	ecall
 ret
    100c:	00008067          	ret

0000000000001010 <exec>:
.global exec
exec:
 li a7, SYS_exec
    1010:	00700893          	li	a7,7
 ecall
    1014:	00000073          	ecall
 ret
    1018:	00008067          	ret

000000000000101c <open>:
.global open
open:
 li a7, SYS_open
    101c:	00f00893          	li	a7,15
 ecall
    1020:	00000073          	ecall
 ret
    1024:	00008067          	ret

0000000000001028 <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
    1028:	01100893          	li	a7,17
 ecall
    102c:	00000073          	ecall
 ret
    1030:	00008067          	ret

0000000000001034 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
    1034:	01200893          	li	a7,18
 ecall
    1038:	00000073          	ecall
 ret
    103c:	00008067          	ret

0000000000001040 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
    1040:	00800893          	li	a7,8
 ecall
    1044:	00000073          	ecall
 ret
    1048:	00008067          	ret

000000000000104c <link>:
.global link
link:
 li a7, SYS_link
    104c:	01300893          	li	a7,19
 ecall
    1050:	00000073          	ecall
 ret
    1054:	00008067          	ret

0000000000001058 <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
    1058:	01400893          	li	a7,20
 ecall
    105c:	00000073          	ecall
 ret
    1060:	00008067          	ret

0000000000001064 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
    1064:	00900893          	li	a7,9
 ecall
    1068:	00000073          	ecall
 ret
    106c:	00008067          	ret

0000000000001070 <dup>:
.global dup
dup:
 li a7, SYS_dup
    1070:	00a00893          	li	a7,10
 ecall
    1074:	00000073          	ecall
 ret
    1078:	00008067          	ret

000000000000107c <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
    107c:	00b00893          	li	a7,11
 ecall
    1080:	00000073          	ecall
 ret
    1084:	00008067          	ret

0000000000001088 <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
    1088:	00c00893          	li	a7,12
 ecall
    108c:	00000073          	ecall
 ret
    1090:	00008067          	ret

0000000000001094 <pause>:
.global pause
pause:
 li a7, SYS_pause
    1094:	00d00893          	li	a7,13
 ecall
    1098:	00000073          	ecall
 ret
    109c:	00008067          	ret

00000000000010a0 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
    10a0:	00e00893          	li	a7,14
 ecall
    10a4:	00000073          	ecall
 ret
    10a8:	00008067          	ret

00000000000010ac <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
    10ac:	00001617          	auipc	a2,0x1
    10b0:	f6462603          	lw	a2,-156(a2) # 2010 <putc_n>
    10b4:	00c04463          	bgtz	a2,10bc <putc_flush+0x10>
    10b8:	00008067          	ret
{
    10bc:	ff010113          	addi	sp,sp,-16
    10c0:	00113423          	sd	ra,8(sp)
    10c4:	00813023          	sd	s0,0(sp)
    10c8:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
    10cc:	00001597          	auipc	a1,0x1
    10d0:	33c58593          	addi	a1,a1,828 # 2408 <putc_buf>
    10d4:	00001517          	auipc	a0,0x1
    10d8:	f3452503          	lw	a0,-204(a0) # 2008 <putc_fd>
    10dc:	f11ff0ef          	jal	fec <write>
    putc_n = 0;
    10e0:	00001797          	auipc	a5,0x1
    10e4:	f207a823          	sw	zero,-208(a5) # 2010 <putc_n>
  }
}
    10e8:	00813083          	ld	ra,8(sp)
    10ec:	00013403          	ld	s0,0(sp)
    10f0:	01010113          	addi	sp,sp,16
    10f4:	00008067          	ret

00000000000010f8 <putc>:

static void
putc(int fd, char c)
{
    10f8:	fe010113          	addi	sp,sp,-32
    10fc:	00113c23          	sd	ra,24(sp)
    1100:	00813823          	sd	s0,16(sp)
    1104:	00913423          	sd	s1,8(sp)
    1108:	02010413          	addi	s0,sp,32
    110c:	00058493          	mv	s1,a1
  if (putc_fd != fd)
    1110:	00001797          	auipc	a5,0x1
    1114:	ef87a783          	lw	a5,-264(a5) # 2008 <putc_fd>
    1118:	04a79663          	bne	a5,a0,1164 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
    111c:	00001717          	auipc	a4,0x1
    1120:	ef470713          	addi	a4,a4,-268 # 2010 <putc_n>
    1124:	00072683          	lw	a3,0(a4)
    1128:	0016879b          	addiw	a5,a3,1
    112c:	00f72023          	sw	a5,0(a4)
    1130:	00001717          	auipc	a4,0x1
    1134:	2d870713          	addi	a4,a4,728 # 2408 <putc_buf>
    1138:	00d70733          	add	a4,a4,a3
    113c:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
    1140:	ff648493          	addi	s1,s1,-10
    1144:	02048e63          	beqz	s1,1180 <putc+0x88>
    1148:	f8078793          	addi	a5,a5,-128
    114c:	02078a63          	beqz	a5,1180 <putc+0x88>
    putc_flush();
}
    1150:	01813083          	ld	ra,24(sp)
    1154:	01013403          	ld	s0,16(sp)
    1158:	00813483          	ld	s1,8(sp)
    115c:	02010113          	addi	sp,sp,32
    1160:	00008067          	ret
    1164:	01213023          	sd	s2,0(sp)
    1168:	00050913          	mv	s2,a0
    putc_flush();
    116c:	f41ff0ef          	jal	10ac <putc_flush>
    putc_fd = fd;
    1170:	00001797          	auipc	a5,0x1
    1174:	e927ac23          	sw	s2,-360(a5) # 2008 <putc_fd>
    1178:	00013903          	ld	s2,0(sp)
    117c:	fa1ff06f          	j	111c <putc+0x24>
    putc_flush();
    1180:	f2dff0ef          	jal	10ac <putc_flush>
}
    1184:	fcdff06f          	j	1150 <putc+0x58>

0000000000001188 <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
    1188:	fb010113          	addi	sp,sp,-80
    118c:	04113423          	sd	ra,72(sp)
    1190:	04813023          	sd	s0,64(sp)
    1194:	03213823          	sd	s2,48(sp)
    1198:	03313423          	sd	s3,40(sp)
    119c:	05010413          	addi	s0,sp,80
    11a0:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
    11a4:	0a068e63          	beqz	a3,1260 <printint+0xd8>
    11a8:	0a05dc63          	bgez	a1,1260 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
    11ac:	40b005b3          	neg	a1,a1
    neg = 1;
    11b0:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
    11b4:	fb840993          	addi	s3,s0,-72
  neg = 0;
    11b8:	00098693          	mv	a3,s3
  i = 0;
    11bc:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
    11c0:	00001817          	auipc	a6,0x1
    11c4:	ac080813          	addi	a6,a6,-1344 # 1c80 <digits>
    11c8:	00070893          	mv	a7,a4
    11cc:	0017051b          	addiw	a0,a4,1
    11d0:	00050713          	mv	a4,a0
    11d4:	02c5f7b3          	remu	a5,a1,a2
    11d8:	00f807b3          	add	a5,a6,a5
    11dc:	0007c783          	lbu	a5,0(a5)
    11e0:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
    11e4:	00058793          	mv	a5,a1
    11e8:	02c5d5b3          	divu	a1,a1,a2
    11ec:	00168693          	addi	a3,a3,1
    11f0:	fcc7fce3          	bgeu	a5,a2,11c8 <printint+0x40>
  if (neg)
    11f4:	00030c63          	beqz	t1,120c <printint+0x84>
    buf[i++] = '-';
    11f8:	fd050793          	addi	a5,a0,-48
    11fc:	00878533          	add	a0,a5,s0
    1200:	02d00793          	li	a5,45
    1204:	fef50423          	sb	a5,-24(a0)
    1208:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
    120c:	02e05e63          	blez	a4,1248 <printint+0xc0>
    1210:	02913c23          	sd	s1,56(sp)
    1214:	fff7071b          	addiw	a4,a4,-1
    1218:	00e984b3          	add	s1,s3,a4
    121c:	fff98993          	addi	s3,s3,-1
    1220:	00e989b3          	add	s3,s3,a4
    1224:	02071713          	slli	a4,a4,0x20
    1228:	02075713          	srli	a4,a4,0x20
    122c:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
    1230:	0004c583          	lbu	a1,0(s1)
    1234:	00090513          	mv	a0,s2
    1238:	ec1ff0ef          	jal	10f8 <putc>
  while (--i >= 0)
    123c:	fff48493          	addi	s1,s1,-1
    1240:	ff3498e3          	bne	s1,s3,1230 <printint+0xa8>
    1244:	03813483          	ld	s1,56(sp)
}
    1248:	04813083          	ld	ra,72(sp)
    124c:	04013403          	ld	s0,64(sp)
    1250:	03013903          	ld	s2,48(sp)
    1254:	02813983          	ld	s3,40(sp)
    1258:	05010113          	addi	sp,sp,80
    125c:	00008067          	ret
  neg = 0;
    1260:	00000313          	li	t1,0
    1264:	f51ff06f          	j	11b4 <printint+0x2c>

0000000000001268 <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
    1268:	fa010113          	addi	sp,sp,-96
    126c:	04113c23          	sd	ra,88(sp)
    1270:	04813823          	sd	s0,80(sp)
    1274:	04913423          	sd	s1,72(sp)
    1278:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
    127c:	0005c483          	lbu	s1,0(a1)
    1280:	32048263          	beqz	s1,15a4 <vprintf+0x33c>
    1284:	05213023          	sd	s2,64(sp)
    1288:	03313c23          	sd	s3,56(sp)
    128c:	03413823          	sd	s4,48(sp)
    1290:	03513423          	sd	s5,40(sp)
    1294:	03613023          	sd	s6,32(sp)
    1298:	01713c23          	sd	s7,24(sp)
    129c:	01813823          	sd	s8,16(sp)
    12a0:	00050b13          	mv	s6,a0
    12a4:	00058a13          	mv	s4,a1
    12a8:	00060b93          	mv	s7,a2
  state = 0;
    12ac:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
    12b0:	00000913          	li	s2,0
    12b4:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
    12b8:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
    12bc:	06400c13          	li	s8,100
    12c0:	0300006f          	j	12f0 <vprintf+0x88>
        putc(fd, c0);
    12c4:	00048593          	mv	a1,s1
    12c8:	000b0513          	mv	a0,s6
    12cc:	e2dff0ef          	jal	10f8 <putc>
    12d0:	0080006f          	j	12d8 <vprintf+0x70>
    else if (state == '%')
    12d4:	03598863          	beq	s3,s5,1304 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
    12d8:	0019079b          	addiw	a5,s2,1
    12dc:	00078913          	mv	s2,a5
    12e0:	00078713          	mv	a4,a5
    12e4:	00fa07b3          	add	a5,s4,a5
    12e8:	0007c483          	lbu	s1,0(a5)
    12ec:	28048e63          	beqz	s1,1588 <vprintf+0x320>
    c0 = fmt[i] & 0xff;
    12f0:	0004879b          	sext.w	a5,s1
    if (state == 0)
    12f4:	fe0990e3          	bnez	s3,12d4 <vprintf+0x6c>
      if (c0 == '%')
    12f8:	fd5796e3          	bne	a5,s5,12c4 <vprintf+0x5c>
        state = '%';
    12fc:	00078993          	mv	s3,a5
    1300:	fd9ff06f          	j	12d8 <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
    1304:	00ea06b3          	add	a3,s4,a4
    1308:	0016c603          	lbu	a2,1(a3)
      if (c1)
    130c:	2a060663          	beqz	a2,15b8 <vprintf+0x350>
      if (c0 == 'd')
    1310:	05878063          	beq	a5,s8,1350 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
    1314:	f9478693          	addi	a3,a5,-108
    1318:	0016b693          	seqz	a3,a3
    131c:	f9c60593          	addi	a1,a2,-100
    1320:	04059a63          	bnez	a1,1374 <vprintf+0x10c>
    1324:	04068863          	beqz	a3,1374 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
    1328:	008b8493          	addi	s1,s7,8
    132c:	00100693          	li	a3,1
    1330:	00a00613          	li	a2,10
    1334:	000bb583          	ld	a1,0(s7)
    1338:	000b0513          	mv	a0,s6
    133c:	e4dff0ef          	jal	1188 <printint>
        i += 1;
    1340:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
    1344:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
    1348:	00000993          	li	s3,0
    134c:	f8dff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
    1350:	008b8493          	addi	s1,s7,8
    1354:	00100693          	li	a3,1
    1358:	00a00613          	li	a2,10
    135c:	000ba583          	lw	a1,0(s7)
    1360:	000b0513          	mv	a0,s6
    1364:	e25ff0ef          	jal	1188 <printint>
    1368:	00048b93          	mv	s7,s1
      state = 0;
    136c:	00000993          	li	s3,0
    1370:	f69ff06f          	j	12d8 <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
    1374:	00ea0733          	add	a4,s4,a4
    1378:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    137c:	f9460713          	addi	a4,a2,-108
    1380:	00173713          	seqz	a4,a4
    1384:	00e6f733          	and	a4,a3,a4
    1388:	f9c58513          	addi	a0,a1,-100
    138c:	24051263          	bnez	a0,15d0 <vprintf+0x368>
    1390:	24070063          	beqz	a4,15d0 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
    1394:	008b8493          	addi	s1,s7,8
    1398:	00100693          	li	a3,1
    139c:	00a00613          	li	a2,10
    13a0:	000bb583          	ld	a1,0(s7)
    13a4:	000b0513          	mv	a0,s6
    13a8:	de1ff0ef          	jal	1188 <printint>
        i += 2;
    13ac:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
    13b0:	00048b93          	mv	s7,s1
      state = 0;
    13b4:	00000993          	li	s3,0
        i += 2;
    13b8:	f21ff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
    13bc:	008b8493          	addi	s1,s7,8
    13c0:	00000693          	li	a3,0
    13c4:	00a00613          	li	a2,10
    13c8:	000be583          	lwu	a1,0(s7)
    13cc:	000b0513          	mv	a0,s6
    13d0:	db9ff0ef          	jal	1188 <printint>
    13d4:	00048b93          	mv	s7,s1
      state = 0;
    13d8:	00000993          	li	s3,0
    13dc:	efdff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    13e0:	008b8493          	addi	s1,s7,8
    13e4:	00000693          	li	a3,0
    13e8:	00a00613          	li	a2,10
    13ec:	000bb583          	ld	a1,0(s7)
    13f0:	000b0513          	mv	a0,s6
    13f4:	d95ff0ef          	jal	1188 <printint>
        i += 1;
    13f8:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
    13fc:	00048b93          	mv	s7,s1
      state = 0;
    1400:	00000993          	li	s3,0
    1404:	ed5ff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    1408:	008b8493          	addi	s1,s7,8
    140c:	00000693          	li	a3,0
    1410:	00a00613          	li	a2,10
    1414:	000bb583          	ld	a1,0(s7)
    1418:	000b0513          	mv	a0,s6
    141c:	d6dff0ef          	jal	1188 <printint>
        i += 2;
    1420:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
    1424:	00048b93          	mv	s7,s1
      state = 0;
    1428:	00000993          	li	s3,0
        i += 2;
    142c:	eadff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
    1430:	008b8493          	addi	s1,s7,8
    1434:	00000693          	li	a3,0
    1438:	01000613          	li	a2,16
    143c:	000be583          	lwu	a1,0(s7)
    1440:	000b0513          	mv	a0,s6
    1444:	d45ff0ef          	jal	1188 <printint>
    1448:	00048b93          	mv	s7,s1
      state = 0;
    144c:	00000993          	li	s3,0
    1450:	e89ff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    1454:	008b8493          	addi	s1,s7,8
    1458:	00000693          	li	a3,0
    145c:	01000613          	li	a2,16
    1460:	000bb583          	ld	a1,0(s7)
    1464:	000b0513          	mv	a0,s6
    1468:	d21ff0ef          	jal	1188 <printint>
        i += 1;
    146c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
    1470:	00048b93          	mv	s7,s1
      state = 0;
    1474:	00000993          	li	s3,0
    1478:	e61ff06f          	j	12d8 <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    147c:	008b8493          	addi	s1,s7,8
    1480:	00000693          	li	a3,0
    1484:	01000613          	li	a2,16
    1488:	000bb583          	ld	a1,0(s7)
    148c:	000b0513          	mv	a0,s6
    1490:	cf9ff0ef          	jal	1188 <printint>
        i += 2;
    1494:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
    1498:	00048b93          	mv	s7,s1
      state = 0;
    149c:	00000993          	li	s3,0
        i += 2;
    14a0:	e39ff06f          	j	12d8 <vprintf+0x70>
    14a4:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
    14a8:	008b8793          	addi	a5,s7,8
    14ac:	00078c93          	mv	s9,a5
    14b0:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
    14b4:	03000593          	li	a1,48
    14b8:	000b0513          	mv	a0,s6
    14bc:	c3dff0ef          	jal	10f8 <putc>
  putc(fd, 'x');
    14c0:	07800593          	li	a1,120
    14c4:	000b0513          	mv	a0,s6
    14c8:	c31ff0ef          	jal	10f8 <putc>
    14cc:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
    14d0:	00000b97          	auipc	s7,0x0
    14d4:	7b0b8b93          	addi	s7,s7,1968 # 1c80 <digits>
    14d8:	03c9d793          	srli	a5,s3,0x3c
    14dc:	00fb87b3          	add	a5,s7,a5
    14e0:	0007c583          	lbu	a1,0(a5)
    14e4:	000b0513          	mv	a0,s6
    14e8:	c11ff0ef          	jal	10f8 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
    14ec:	00499993          	slli	s3,s3,0x4
    14f0:	fff4849b          	addiw	s1,s1,-1
    14f4:	fe0492e3          	bnez	s1,14d8 <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
    14f8:	000c8b93          	mv	s7,s9
      state = 0;
    14fc:	00000993          	li	s3,0
    1500:	00813c83          	ld	s9,8(sp)
    1504:	dd5ff06f          	j	12d8 <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
    1508:	008b8493          	addi	s1,s7,8
    150c:	000bc583          	lbu	a1,0(s7)
    1510:	000b0513          	mv	a0,s6
    1514:	be5ff0ef          	jal	10f8 <putc>
    1518:	00048b93          	mv	s7,s1
      state = 0;
    151c:	00000993          	li	s3,0
    1520:	db9ff06f          	j	12d8 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    1524:	008b8993          	addi	s3,s7,8
    1528:	000bb483          	ld	s1,0(s7)
    152c:	02048663          	beqz	s1,1558 <vprintf+0x2f0>
        for (; *s; s++)
    1530:	0004c583          	lbu	a1,0(s1)
    1534:	04058463          	beqz	a1,157c <vprintf+0x314>
          putc(fd, *s);
    1538:	000b0513          	mv	a0,s6
    153c:	bbdff0ef          	jal	10f8 <putc>
        for (; *s; s++)
    1540:	00148493          	addi	s1,s1,1
    1544:	0004c583          	lbu	a1,0(s1)
    1548:	fe0598e3          	bnez	a1,1538 <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
    154c:	00098b93          	mv	s7,s3
      state = 0;
    1550:	00000993          	li	s3,0
    1554:	d85ff06f          	j	12d8 <vprintf+0x70>
          s = "(null)";
    1558:	00000497          	auipc	s1,0x0
    155c:	6c048493          	addi	s1,s1,1728 # 1c18 <malloc+0x478>
        for (; *s; s++)
    1560:	02800593          	li	a1,40
    1564:	fd5ff06f          	j	1538 <vprintf+0x2d0>
        putc(fd, '%');
    1568:	00078593          	mv	a1,a5
    156c:	000b0513          	mv	a0,s6
    1570:	b89ff0ef          	jal	10f8 <putc>
      state = 0;
    1574:	00000993          	li	s3,0
    1578:	d61ff06f          	j	12d8 <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    157c:	00098b93          	mv	s7,s3
      state = 0;
    1580:	00000993          	li	s3,0
    1584:	d55ff06f          	j	12d8 <vprintf+0x70>
    1588:	04013903          	ld	s2,64(sp)
    158c:	03813983          	ld	s3,56(sp)
    1590:	03013a03          	ld	s4,48(sp)
    1594:	02813a83          	ld	s5,40(sp)
    1598:	02013b03          	ld	s6,32(sp)
    159c:	01813b83          	ld	s7,24(sp)
    15a0:	01013c03          	ld	s8,16(sp)
    }
  }
}
    15a4:	05813083          	ld	ra,88(sp)
    15a8:	05013403          	ld	s0,80(sp)
    15ac:	04813483          	ld	s1,72(sp)
    15b0:	06010113          	addi	sp,sp,96
    15b4:	00008067          	ret
      if (c0 == 'd')
    15b8:	06400713          	li	a4,100
    15bc:	d8e78ae3          	beq	a5,a4,1350 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
    15c0:	f9478693          	addi	a3,a5,-108
    15c4:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
    15c8:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    15cc:	00000713          	li	a4,0
      else if (c0 == 'u')
    15d0:	07500513          	li	a0,117
    15d4:	dea784e3          	beq	a5,a0,13bc <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
    15d8:	f8b60513          	addi	a0,a2,-117
    15dc:	00051463          	bnez	a0,15e4 <vprintf+0x37c>
    15e0:	e00690e3          	bnez	a3,13e0 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
    15e4:	f8b58513          	addi	a0,a1,-117
    15e8:	00051463          	bnez	a0,15f0 <vprintf+0x388>
    15ec:	e0071ee3          	bnez	a4,1408 <vprintf+0x1a0>
      else if (c0 == 'x')
    15f0:	07800513          	li	a0,120
    15f4:	e2a78ee3          	beq	a5,a0,1430 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
    15f8:	f8860613          	addi	a2,a2,-120
    15fc:	00061463          	bnez	a2,1604 <vprintf+0x39c>
    1600:	e4069ae3          	bnez	a3,1454 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
    1604:	f8858593          	addi	a1,a1,-120
    1608:	00059463          	bnez	a1,1610 <vprintf+0x3a8>
    160c:	e60718e3          	bnez	a4,147c <vprintf+0x214>
      else if (c0 == 'p')
    1610:	07000713          	li	a4,112
    1614:	e8e788e3          	beq	a5,a4,14a4 <vprintf+0x23c>
      else if (c0 == 'c')
    1618:	06300713          	li	a4,99
    161c:	eee786e3          	beq	a5,a4,1508 <vprintf+0x2a0>
      else if (c0 == 's')
    1620:	07300713          	li	a4,115
    1624:	f0e780e3          	beq	a5,a4,1524 <vprintf+0x2bc>
      else if (c0 == '%')
    1628:	02500713          	li	a4,37
    162c:	f2e78ee3          	beq	a5,a4,1568 <vprintf+0x300>
        putc(fd, '%');
    1630:	02500593          	li	a1,37
    1634:	000b0513          	mv	a0,s6
    1638:	ac1ff0ef          	jal	10f8 <putc>
        putc(fd, c0);
    163c:	00048593          	mv	a1,s1
    1640:	000b0513          	mv	a0,s6
    1644:	ab5ff0ef          	jal	10f8 <putc>
      state = 0;
    1648:	00000993          	li	s3,0
    164c:	c8dff06f          	j	12d8 <vprintf+0x70>

0000000000001650 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
    1650:	fb010113          	addi	sp,sp,-80
    1654:	00113c23          	sd	ra,24(sp)
    1658:	00813823          	sd	s0,16(sp)
    165c:	02010413          	addi	s0,sp,32
    1660:	00c43023          	sd	a2,0(s0)
    1664:	00d43423          	sd	a3,8(s0)
    1668:	00e43823          	sd	a4,16(s0)
    166c:	00f43c23          	sd	a5,24(s0)
    1670:	03043023          	sd	a6,32(s0)
    1674:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
    1678:	00040613          	mv	a2,s0
    167c:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
    1680:	be9ff0ef          	jal	1268 <vprintf>
}
    1684:	01813083          	ld	ra,24(sp)
    1688:	01013403          	ld	s0,16(sp)
    168c:	05010113          	addi	sp,sp,80
    1690:	00008067          	ret

0000000000001694 <printf>:

void printf(const char *fmt, ...)
{
    1694:	fa010113          	addi	sp,sp,-96
    1698:	00113c23          	sd	ra,24(sp)
    169c:	00813823          	sd	s0,16(sp)
    16a0:	02010413          	addi	s0,sp,32
    16a4:	00b43423          	sd	a1,8(s0)
    16a8:	00c43823          	sd	a2,16(s0)
    16ac:	00d43c23          	sd	a3,24(s0)
    16b0:	02e43023          	sd	a4,32(s0)
    16b4:	02f43423          	sd	a5,40(s0)
    16b8:	03043823          	sd	a6,48(s0)
    16bc:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
    16c0:	00840613          	addi	a2,s0,8
    16c4:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
    16c8:	00050593          	mv	a1,a0
    16cc:	00100513          	li	a0,1
    16d0:	b99ff0ef          	jal	1268 <vprintf>
  putc_flush();
    16d4:	9d9ff0ef          	jal	10ac <putc_flush>
}
    16d8:	01813083          	ld	ra,24(sp)
    16dc:	01013403          	ld	s0,16(sp)
    16e0:	06010113          	addi	sp,sp,96
    16e4:	00008067          	ret

00000000000016e8 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
    16e8:	ff010113          	addi	sp,sp,-16
    16ec:	00113423          	sd	ra,8(sp)
    16f0:	00813023          	sd	s0,0(sp)
    16f4:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
    16f8:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    16fc:	00001797          	auipc	a5,0x1
    1700:	91c7b783          	ld	a5,-1764(a5) # 2018 <freep>
    1704:	0140006f          	j	1718 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    1708:	0007b703          	ld	a4,0(a5)
    170c:	00e7e463          	bltu	a5,a4,1714 <free+0x2c>
    1710:	00e6ec63          	bltu	a3,a4,1728 <free+0x40>
{
    1714:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1718:	fed7f8e3          	bgeu	a5,a3,1708 <free+0x20>
    171c:	0007b703          	ld	a4,0(a5)
    1720:	00e6e463          	bltu	a3,a4,1728 <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    1724:	fee7e8e3          	bltu	a5,a4,1714 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
    1728:	ff852583          	lw	a1,-8(a0)
    172c:	0007b603          	ld	a2,0(a5)
    1730:	02059813          	slli	a6,a1,0x20
    1734:	01c85713          	srli	a4,a6,0x1c
    1738:	00e68733          	add	a4,a3,a4
    173c:	02e60c63          	beq	a2,a4,1774 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
    1740:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    1744:	0087a603          	lw	a2,8(a5)
    1748:	02061593          	slli	a1,a2,0x20
    174c:	01c5d713          	srli	a4,a1,0x1c
    1750:	00e78733          	add	a4,a5,a4
    1754:	02e68c63          	beq	a3,a4,178c <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
    1758:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
    175c:	00001717          	auipc	a4,0x1
    1760:	8af73e23          	sd	a5,-1860(a4) # 2018 <freep>
}
    1764:	00813083          	ld	ra,8(sp)
    1768:	00013403          	ld	s0,0(sp)
    176c:	01010113          	addi	sp,sp,16
    1770:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
    1774:	00862703          	lw	a4,8(a2)
    1778:	00b7073b          	addw	a4,a4,a1
    177c:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
    1780:	0007b703          	ld	a4,0(a5)
    1784:	00073603          	ld	a2,0(a4)
    1788:	fb9ff06f          	j	1740 <free+0x58>
    p->s.size += bp->s.size;
    178c:	ff852703          	lw	a4,-8(a0)
    1790:	00c7073b          	addw	a4,a4,a2
    1794:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
    1798:	ff053683          	ld	a3,-16(a0)
    179c:	fbdff06f          	j	1758 <free+0x70>

00000000000017a0 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
    17a0:	fc010113          	addi	sp,sp,-64
    17a4:	02113c23          	sd	ra,56(sp)
    17a8:	02813823          	sd	s0,48(sp)
    17ac:	03213023          	sd	s2,32(sp)
    17b0:	01313c23          	sd	s3,24(sp)
    17b4:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    17b8:	02051993          	slli	s3,a0,0x20
    17bc:	0209d993          	srli	s3,s3,0x20
    17c0:	00f98993          	addi	s3,s3,15
    17c4:	0049d993          	srli	s3,s3,0x4
    17c8:	0019899b          	addiw	s3,s3,1
    17cc:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
    17d0:	00001517          	auipc	a0,0x1
    17d4:	84853503          	ld	a0,-1976(a0) # 2018 <freep>
    17d8:	04050463          	beqz	a0,1820 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    17dc:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    17e0:	0087a703          	lw	a4,8(a5)
    17e4:	0d377a63          	bgeu	a4,s3,18b8 <malloc+0x118>
    17e8:	02913423          	sd	s1,40(sp)
    17ec:	01413823          	sd	s4,16(sp)
    17f0:	01513423          	sd	s5,8(sp)
    17f4:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
    17f8:	00098a13          	mv	s4,s3
    17fc:	00001737          	lui	a4,0x1
    1800:	00e9f463          	bgeu	s3,a4,1808 <malloc+0x68>
    1804:	00001a37          	lui	s4,0x1
    1808:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
    180c:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    1810:	00001497          	auipc	s1,0x1
    1814:	80848493          	addi	s1,s1,-2040 # 2018 <freep>
  if(p == SBRK_ERROR)
    1818:	fff00a93          	li	s5,-1
    181c:	05c0006f          	j	1878 <malloc+0xd8>
    1820:	02913423          	sd	s1,40(sp)
    1824:	01413823          	sd	s4,16(sp)
    1828:	01513423          	sd	s5,8(sp)
    182c:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
    1830:	00001797          	auipc	a5,0x1
    1834:	c5878793          	addi	a5,a5,-936 # 2488 <base>
    1838:	00000717          	auipc	a4,0x0
    183c:	7ef73023          	sd	a5,2016(a4) # 2018 <freep>
    1840:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
    1844:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
    1848:	fb1ff06f          	j	17f8 <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
    184c:	0007b703          	ld	a4,0(a5)
    1850:	00e53023          	sd	a4,0(a0)
    1854:	0800006f          	j	18d4 <malloc+0x134>
  hp->s.size = nu;
    1858:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
    185c:	01050513          	addi	a0,a0,16
    1860:	e89ff0ef          	jal	16e8 <free>
  return freep;
    1864:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    1868:	08050863          	beqz	a0,18f8 <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    186c:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1870:	0087a703          	lw	a4,8(a5)
    1874:	03277a63          	bgeu	a4,s2,18a8 <malloc+0x108>
    if(p == freep)
    1878:	0004b703          	ld	a4,0(s1)
    187c:	00078513          	mv	a0,a5
    1880:	fef716e3          	bne	a4,a5,186c <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    1884:	000a0513          	mv	a0,s4
    1888:	ed8ff0ef          	jal	f60 <sbrk>
  if(p == SBRK_ERROR)
    188c:	fd5516e3          	bne	a0,s5,1858 <malloc+0xb8>
        return 0;
    1890:	00000513          	li	a0,0
    1894:	02813483          	ld	s1,40(sp)
    1898:	01013a03          	ld	s4,16(sp)
    189c:	00813a83          	ld	s5,8(sp)
    18a0:	00013b03          	ld	s6,0(sp)
    18a4:	03c0006f          	j	18e0 <malloc+0x140>
    18a8:	02813483          	ld	s1,40(sp)
    18ac:	01013a03          	ld	s4,16(sp)
    18b0:	00813a83          	ld	s5,8(sp)
    18b4:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    18b8:	f8e90ae3          	beq	s2,a4,184c <malloc+0xac>
        p->s.size -= nunits;
    18bc:	4137073b          	subw	a4,a4,s3
    18c0:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    18c4:	02071693          	slli	a3,a4,0x20
    18c8:	01c6d713          	srli	a4,a3,0x1c
    18cc:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    18d0:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    18d4:	00000717          	auipc	a4,0x0
    18d8:	74a73223          	sd	a0,1860(a4) # 2018 <freep>
      return (void*)(p + 1);
    18dc:	01078513          	addi	a0,a5,16
  }
}
    18e0:	03813083          	ld	ra,56(sp)
    18e4:	03013403          	ld	s0,48(sp)
    18e8:	02013903          	ld	s2,32(sp)
    18ec:	01813983          	ld	s3,24(sp)
    18f0:	04010113          	addi	sp,sp,64
    18f4:	00008067          	ret
    18f8:	02813483          	ld	s1,40(sp)
    18fc:	01013a03          	ld	s4,16(sp)
    1900:	00813a83          	ld	s5,8(sp)
    1904:	00013b03          	ld	s6,0(sp)
    1908:	fd9ff06f          	j	18e0 <malloc+0x140>
