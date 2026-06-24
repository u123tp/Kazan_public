
user/_sh:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <getcmd>:
  exit(0);
}

int
getcmd(char *buf, int nbuf)
{
       0:	fe010113          	addi	sp,sp,-32
       4:	00113c23          	sd	ra,24(sp)
       8:	00813823          	sd	s0,16(sp)
       c:	00913423          	sd	s1,8(sp)
      10:	01213023          	sd	s2,0(sp)
      14:	02010413          	addi	s0,sp,32
      18:	00050493          	mv	s1,a0
      1c:	00058913          	mv	s2,a1
  write(2, "$ ", 2);
      20:	00200613          	li	a2,2
      24:	00002597          	auipc	a1,0x2
      28:	c0c58593          	addi	a1,a1,-1012 # 1c30 <malloc+0x16c>
      2c:	00060513          	mv	a0,a2
      30:	2e0010ef          	jal	1310 <write>
  memset(buf, 0, nbuf);
      34:	00090613          	mv	a2,s2
      38:	00000593          	li	a1,0
      3c:	00048513          	mv	a0,s1
      40:	721000ef          	jal	f60 <memset>
  gets(buf, nbuf);
      44:	00090593          	mv	a1,s2
      48:	00048513          	mv	a0,s1
      4c:	799000ef          	jal	fe4 <gets>
  if(buf[0] == 0) // EOF
      50:	0004c503          	lbu	a0,0(s1)
      54:	00153513          	seqz	a0,a0
    return -1;
  return 0;
}
      58:	40a0053b          	negw	a0,a0
      5c:	01813083          	ld	ra,24(sp)
      60:	01013403          	ld	s0,16(sp)
      64:	00813483          	ld	s1,8(sp)
      68:	00013903          	ld	s2,0(sp)
      6c:	02010113          	addi	sp,sp,32
      70:	00008067          	ret

0000000000000074 <panic>:
  exit(0);
}

void
panic(char *s)
{
      74:	ff010113          	addi	sp,sp,-16
      78:	00113423          	sd	ra,8(sp)
      7c:	00813023          	sd	s0,0(sp)
      80:	01010413          	addi	s0,sp,16
      84:	00050613          	mv	a2,a0
  fprintf(2, "%s\n", s);
      88:	00002597          	auipc	a1,0x2
      8c:	bb858593          	addi	a1,a1,-1096 # 1c40 <malloc+0x17c>
      90:	00200513          	li	a0,2
      94:	0e1010ef          	jal	1974 <fprintf>
  exit(1);
      98:	00100513          	li	a0,1
      9c:	244010ef          	jal	12e0 <exit>

00000000000000a0 <fork1>:
}

int
fork1(void)
{
      a0:	ff010113          	addi	sp,sp,-16
      a4:	00113423          	sd	ra,8(sp)
      a8:	00813023          	sd	s0,0(sp)
      ac:	01010413          	addi	s0,sp,16
  int pid;

  pid = fork();
      b0:	224010ef          	jal	12d4 <fork>
  if(pid == -1)
      b4:	fff00793          	li	a5,-1
      b8:	00f50a63          	beq	a0,a5,cc <fork1+0x2c>
    panic("fork");
  return pid;
}
      bc:	00813083          	ld	ra,8(sp)
      c0:	00013403          	ld	s0,0(sp)
      c4:	01010113          	addi	sp,sp,16
      c8:	00008067          	ret
    panic("fork");
      cc:	00002517          	auipc	a0,0x2
      d0:	b7c50513          	addi	a0,a0,-1156 # 1c48 <malloc+0x184>
      d4:	fa1ff0ef          	jal	74 <panic>

00000000000000d8 <runcmd>:
{
      d8:	fd010113          	addi	sp,sp,-48
      dc:	02113423          	sd	ra,40(sp)
      e0:	02813023          	sd	s0,32(sp)
      e4:	03010413          	addi	s0,sp,48
  if(cmd == 0)
      e8:	02050c63          	beqz	a0,120 <runcmd+0x48>
      ec:	00913c23          	sd	s1,24(sp)
      f0:	00050493          	mv	s1,a0
  switch(cmd->type){
      f4:	00052703          	lw	a4,0(a0)
      f8:	00500793          	li	a5,5
      fc:	02e7e863          	bltu	a5,a4,12c <runcmd+0x54>
     100:	00056783          	lwu	a5,0(a0)
     104:	00279793          	slli	a5,a5,0x2
     108:	00002717          	auipc	a4,0x2
     10c:	c4070713          	addi	a4,a4,-960 # 1d48 <malloc+0x284>
     110:	00e787b3          	add	a5,a5,a4
     114:	0007a783          	lw	a5,0(a5)
     118:	00e787b3          	add	a5,a5,a4
     11c:	00078067          	jr	a5
     120:	00913c23          	sd	s1,24(sp)
    exit(1);
     124:	00100513          	li	a0,1
     128:	1b8010ef          	jal	12e0 <exit>
    panic("runcmd");
     12c:	00002517          	auipc	a0,0x2
     130:	b2450513          	addi	a0,a0,-1244 # 1c50 <malloc+0x18c>
     134:	f41ff0ef          	jal	74 <panic>
    if(ecmd->argv[0] == 0)
     138:	00853503          	ld	a0,8(a0)
     13c:	02050463          	beqz	a0,164 <runcmd+0x8c>
    exec(ecmd->argv[0], ecmd->argv);
     140:	00848593          	addi	a1,s1,8
     144:	1f0010ef          	jal	1334 <exec>
    fprintf(2, "exec %s failed\n", ecmd->argv[0]);
     148:	0084b603          	ld	a2,8(s1)
     14c:	00002597          	auipc	a1,0x2
     150:	b0c58593          	addi	a1,a1,-1268 # 1c58 <malloc+0x194>
     154:	00200513          	li	a0,2
     158:	01d010ef          	jal	1974 <fprintf>
  exit(0);
     15c:	00000513          	li	a0,0
     160:	180010ef          	jal	12e0 <exit>
      exit(1);
     164:	00100513          	li	a0,1
     168:	178010ef          	jal	12e0 <exit>
    close(rcmd->fd);
     16c:	02452503          	lw	a0,36(a0)
     170:	1ac010ef          	jal	131c <close>
    if(open(rcmd->file, rcmd->mode) < 0){
     174:	0204a583          	lw	a1,32(s1)
     178:	0104b503          	ld	a0,16(s1)
     17c:	1c4010ef          	jal	1340 <open>
     180:	00054663          	bltz	a0,18c <runcmd+0xb4>
    runcmd(rcmd->cmd);
     184:	0084b503          	ld	a0,8(s1)
     188:	f51ff0ef          	jal	d8 <runcmd>
      fprintf(2, "open %s failed\n", rcmd->file);
     18c:	0104b603          	ld	a2,16(s1)
     190:	00002597          	auipc	a1,0x2
     194:	ad858593          	addi	a1,a1,-1320 # 1c68 <malloc+0x1a4>
     198:	00200513          	li	a0,2
     19c:	7d8010ef          	jal	1974 <fprintf>
      exit(1);
     1a0:	00100513          	li	a0,1
     1a4:	13c010ef          	jal	12e0 <exit>
    if(fork1() == 0)
     1a8:	ef9ff0ef          	jal	a0 <fork1>
     1ac:	00051663          	bnez	a0,1b8 <runcmd+0xe0>
      runcmd(lcmd->left);
     1b0:	0084b503          	ld	a0,8(s1)
     1b4:	f25ff0ef          	jal	d8 <runcmd>
    wait(0);
     1b8:	00000513          	li	a0,0
     1bc:	130010ef          	jal	12ec <wait>
    runcmd(lcmd->right);
     1c0:	0104b503          	ld	a0,16(s1)
     1c4:	f15ff0ef          	jal	d8 <runcmd>
    if(pipe(p) < 0)
     1c8:	fd840513          	addi	a0,s0,-40
     1cc:	12c010ef          	jal	12f8 <pipe>
     1d0:	02054a63          	bltz	a0,204 <runcmd+0x12c>
    if(fork1() == 0){
     1d4:	ecdff0ef          	jal	a0 <fork1>
     1d8:	02051c63          	bnez	a0,210 <runcmd+0x138>
      close(1);
     1dc:	00100513          	li	a0,1
     1e0:	13c010ef          	jal	131c <close>
      dup(p[1]);
     1e4:	fdc42503          	lw	a0,-36(s0)
     1e8:	1ac010ef          	jal	1394 <dup>
      close(p[0]);
     1ec:	fd842503          	lw	a0,-40(s0)
     1f0:	12c010ef          	jal	131c <close>
      close(p[1]);
     1f4:	fdc42503          	lw	a0,-36(s0)
     1f8:	124010ef          	jal	131c <close>
      runcmd(pcmd->left);
     1fc:	0084b503          	ld	a0,8(s1)
     200:	ed9ff0ef          	jal	d8 <runcmd>
      panic("pipe");
     204:	00002517          	auipc	a0,0x2
     208:	a7450513          	addi	a0,a0,-1420 # 1c78 <malloc+0x1b4>
     20c:	e69ff0ef          	jal	74 <panic>
    if(fork1() == 0){
     210:	e91ff0ef          	jal	a0 <fork1>
     214:	02051463          	bnez	a0,23c <runcmd+0x164>
      close(0);
     218:	104010ef          	jal	131c <close>
      dup(p[0]);
     21c:	fd842503          	lw	a0,-40(s0)
     220:	174010ef          	jal	1394 <dup>
      close(p[0]);
     224:	fd842503          	lw	a0,-40(s0)
     228:	0f4010ef          	jal	131c <close>
      close(p[1]);
     22c:	fdc42503          	lw	a0,-36(s0)
     230:	0ec010ef          	jal	131c <close>
      runcmd(pcmd->right);
     234:	0104b503          	ld	a0,16(s1)
     238:	ea1ff0ef          	jal	d8 <runcmd>
    close(p[0]);
     23c:	fd842503          	lw	a0,-40(s0)
     240:	0dc010ef          	jal	131c <close>
    close(p[1]);
     244:	fdc42503          	lw	a0,-36(s0)
     248:	0d4010ef          	jal	131c <close>
    wait(0);
     24c:	00000513          	li	a0,0
     250:	09c010ef          	jal	12ec <wait>
    wait(0);
     254:	00000513          	li	a0,0
     258:	094010ef          	jal	12ec <wait>
    break;
     25c:	f01ff06f          	j	15c <runcmd+0x84>
    if(fork1() == 0)
     260:	e41ff0ef          	jal	a0 <fork1>
     264:	ee051ce3          	bnez	a0,15c <runcmd+0x84>
      runcmd(bcmd->cmd);
     268:	0084b503          	ld	a0,8(s1)
     26c:	e6dff0ef          	jal	d8 <runcmd>

0000000000000270 <execcmd>:
//PAGEBREAK!
// Constructors

struct cmd*
execcmd(void)
{
     270:	fe010113          	addi	sp,sp,-32
     274:	00113c23          	sd	ra,24(sp)
     278:	00813823          	sd	s0,16(sp)
     27c:	00913423          	sd	s1,8(sp)
     280:	02010413          	addi	s0,sp,32
  struct execcmd *cmd;

  cmd = malloc(sizeof(*cmd));
     284:	0a800513          	li	a0,168
     288:	03d010ef          	jal	1ac4 <malloc>
     28c:	00050493          	mv	s1,a0
  memset(cmd, 0, sizeof(*cmd));
     290:	0a800613          	li	a2,168
     294:	00000593          	li	a1,0
     298:	4c9000ef          	jal	f60 <memset>
  cmd->type = EXEC;
     29c:	00100793          	li	a5,1
     2a0:	00f4a023          	sw	a5,0(s1)
  return (struct cmd*)cmd;
}
     2a4:	00048513          	mv	a0,s1
     2a8:	01813083          	ld	ra,24(sp)
     2ac:	01013403          	ld	s0,16(sp)
     2b0:	00813483          	ld	s1,8(sp)
     2b4:	02010113          	addi	sp,sp,32
     2b8:	00008067          	ret

00000000000002bc <redircmd>:

struct cmd*
redircmd(struct cmd *subcmd, char *file, char *efile, int mode, int fd)
{
     2bc:	fc010113          	addi	sp,sp,-64
     2c0:	02113c23          	sd	ra,56(sp)
     2c4:	02813823          	sd	s0,48(sp)
     2c8:	02913423          	sd	s1,40(sp)
     2cc:	03213023          	sd	s2,32(sp)
     2d0:	01313c23          	sd	s3,24(sp)
     2d4:	01413823          	sd	s4,16(sp)
     2d8:	01513423          	sd	s5,8(sp)
     2dc:	01613023          	sd	s6,0(sp)
     2e0:	04010413          	addi	s0,sp,64
     2e4:	00050913          	mv	s2,a0
     2e8:	00058993          	mv	s3,a1
     2ec:	00060a13          	mv	s4,a2
     2f0:	00068a93          	mv	s5,a3
     2f4:	00070b13          	mv	s6,a4
  struct redircmd *cmd;

  cmd = malloc(sizeof(*cmd));
     2f8:	02800513          	li	a0,40
     2fc:	7c8010ef          	jal	1ac4 <malloc>
     300:	00050493          	mv	s1,a0
  memset(cmd, 0, sizeof(*cmd));
     304:	02800613          	li	a2,40
     308:	00000593          	li	a1,0
     30c:	455000ef          	jal	f60 <memset>
  cmd->type = REDIR;
     310:	00200793          	li	a5,2
     314:	00f4a023          	sw	a5,0(s1)
  cmd->cmd = subcmd;
     318:	0124b423          	sd	s2,8(s1)
  cmd->file = file;
     31c:	0134b823          	sd	s3,16(s1)
  cmd->efile = efile;
     320:	0144bc23          	sd	s4,24(s1)
  cmd->mode = mode;
     324:	0354a023          	sw	s5,32(s1)
  cmd->fd = fd;
     328:	0364a223          	sw	s6,36(s1)
  return (struct cmd*)cmd;
}
     32c:	00048513          	mv	a0,s1
     330:	03813083          	ld	ra,56(sp)
     334:	03013403          	ld	s0,48(sp)
     338:	02813483          	ld	s1,40(sp)
     33c:	02013903          	ld	s2,32(sp)
     340:	01813983          	ld	s3,24(sp)
     344:	01013a03          	ld	s4,16(sp)
     348:	00813a83          	ld	s5,8(sp)
     34c:	00013b03          	ld	s6,0(sp)
     350:	04010113          	addi	sp,sp,64
     354:	00008067          	ret

0000000000000358 <pipecmd>:

struct cmd*
pipecmd(struct cmd *left, struct cmd *right)
{
     358:	fd010113          	addi	sp,sp,-48
     35c:	02113423          	sd	ra,40(sp)
     360:	02813023          	sd	s0,32(sp)
     364:	00913c23          	sd	s1,24(sp)
     368:	01213823          	sd	s2,16(sp)
     36c:	01313423          	sd	s3,8(sp)
     370:	03010413          	addi	s0,sp,48
     374:	00050913          	mv	s2,a0
     378:	00058993          	mv	s3,a1
  struct pipecmd *cmd;

  cmd = malloc(sizeof(*cmd));
     37c:	01800513          	li	a0,24
     380:	744010ef          	jal	1ac4 <malloc>
     384:	00050493          	mv	s1,a0
  memset(cmd, 0, sizeof(*cmd));
     388:	01800613          	li	a2,24
     38c:	00000593          	li	a1,0
     390:	3d1000ef          	jal	f60 <memset>
  cmd->type = PIPE;
     394:	00300793          	li	a5,3
     398:	00f4a023          	sw	a5,0(s1)
  cmd->left = left;
     39c:	0124b423          	sd	s2,8(s1)
  cmd->right = right;
     3a0:	0134b823          	sd	s3,16(s1)
  return (struct cmd*)cmd;
}
     3a4:	00048513          	mv	a0,s1
     3a8:	02813083          	ld	ra,40(sp)
     3ac:	02013403          	ld	s0,32(sp)
     3b0:	01813483          	ld	s1,24(sp)
     3b4:	01013903          	ld	s2,16(sp)
     3b8:	00813983          	ld	s3,8(sp)
     3bc:	03010113          	addi	sp,sp,48
     3c0:	00008067          	ret

00000000000003c4 <listcmd>:

struct cmd*
listcmd(struct cmd *left, struct cmd *right)
{
     3c4:	fd010113          	addi	sp,sp,-48
     3c8:	02113423          	sd	ra,40(sp)
     3cc:	02813023          	sd	s0,32(sp)
     3d0:	00913c23          	sd	s1,24(sp)
     3d4:	01213823          	sd	s2,16(sp)
     3d8:	01313423          	sd	s3,8(sp)
     3dc:	03010413          	addi	s0,sp,48
     3e0:	00050913          	mv	s2,a0
     3e4:	00058993          	mv	s3,a1
  struct listcmd *cmd;

  cmd = malloc(sizeof(*cmd));
     3e8:	01800513          	li	a0,24
     3ec:	6d8010ef          	jal	1ac4 <malloc>
     3f0:	00050493          	mv	s1,a0
  memset(cmd, 0, sizeof(*cmd));
     3f4:	01800613          	li	a2,24
     3f8:	00000593          	li	a1,0
     3fc:	365000ef          	jal	f60 <memset>
  cmd->type = LIST;
     400:	00400793          	li	a5,4
     404:	00f4a023          	sw	a5,0(s1)
  cmd->left = left;
     408:	0124b423          	sd	s2,8(s1)
  cmd->right = right;
     40c:	0134b823          	sd	s3,16(s1)
  return (struct cmd*)cmd;
}
     410:	00048513          	mv	a0,s1
     414:	02813083          	ld	ra,40(sp)
     418:	02013403          	ld	s0,32(sp)
     41c:	01813483          	ld	s1,24(sp)
     420:	01013903          	ld	s2,16(sp)
     424:	00813983          	ld	s3,8(sp)
     428:	03010113          	addi	sp,sp,48
     42c:	00008067          	ret

0000000000000430 <backcmd>:

struct cmd*
backcmd(struct cmd *subcmd)
{
     430:	fe010113          	addi	sp,sp,-32
     434:	00113c23          	sd	ra,24(sp)
     438:	00813823          	sd	s0,16(sp)
     43c:	00913423          	sd	s1,8(sp)
     440:	01213023          	sd	s2,0(sp)
     444:	02010413          	addi	s0,sp,32
     448:	00050913          	mv	s2,a0
  struct backcmd *cmd;

  cmd = malloc(sizeof(*cmd));
     44c:	01000513          	li	a0,16
     450:	674010ef          	jal	1ac4 <malloc>
     454:	00050493          	mv	s1,a0
  memset(cmd, 0, sizeof(*cmd));
     458:	01000613          	li	a2,16
     45c:	00000593          	li	a1,0
     460:	301000ef          	jal	f60 <memset>
  cmd->type = BACK;
     464:	00500793          	li	a5,5
     468:	00f4a023          	sw	a5,0(s1)
  cmd->cmd = subcmd;
     46c:	0124b423          	sd	s2,8(s1)
  return (struct cmd*)cmd;
}
     470:	00048513          	mv	a0,s1
     474:	01813083          	ld	ra,24(sp)
     478:	01013403          	ld	s0,16(sp)
     47c:	00813483          	ld	s1,8(sp)
     480:	00013903          	ld	s2,0(sp)
     484:	02010113          	addi	sp,sp,32
     488:	00008067          	ret

000000000000048c <gettoken>:
char whitespace[] = " \t\r\n\v";
char symbols[] = "<|>&;()";

int
gettoken(char **ps, char *es, char **q, char **eq)
{
     48c:	fc010113          	addi	sp,sp,-64
     490:	02113c23          	sd	ra,56(sp)
     494:	02813823          	sd	s0,48(sp)
     498:	02913423          	sd	s1,40(sp)
     49c:	03213023          	sd	s2,32(sp)
     4a0:	01313c23          	sd	s3,24(sp)
     4a4:	01413823          	sd	s4,16(sp)
     4a8:	01513423          	sd	s5,8(sp)
     4ac:	01613023          	sd	s6,0(sp)
     4b0:	04010413          	addi	s0,sp,64
     4b4:	00050a13          	mv	s4,a0
     4b8:	00058913          	mv	s2,a1
     4bc:	00060a93          	mv	s5,a2
     4c0:	00068b13          	mv	s6,a3
  char *s;
  int ret;

  s = *ps;
     4c4:	00053483          	ld	s1,0(a0)
  while(s < es && strchr(whitespace, *s))
     4c8:	00002997          	auipc	s3,0x2
     4cc:	b4098993          	addi	s3,s3,-1216 # 2008 <whitespace>
     4d0:	02b4f063          	bgeu	s1,a1,4f0 <gettoken+0x64>
     4d4:	0004c583          	lbu	a1,0(s1)
     4d8:	00098513          	mv	a0,s3
     4dc:	2c5000ef          	jal	fa0 <strchr>
     4e0:	00050863          	beqz	a0,4f0 <gettoken+0x64>
    s++;
     4e4:	00148493          	addi	s1,s1,1
  while(s < es && strchr(whitespace, *s))
     4e8:	fe9916e3          	bne	s2,s1,4d4 <gettoken+0x48>
     4ec:	00090493          	mv	s1,s2
  if(q)
     4f0:	000a8463          	beqz	s5,4f8 <gettoken+0x6c>
    *q = s;
     4f4:	009ab023          	sd	s1,0(s5)
  ret = *s;
     4f8:	0004c783          	lbu	a5,0(s1)
     4fc:	00078a9b          	sext.w	s5,a5
  switch(*s){
     500:	03c00713          	li	a4,60
     504:	08f76663          	bltu	a4,a5,590 <gettoken+0x104>
     508:	03a00713          	li	a4,58
     50c:	02f76063          	bltu	a4,a5,52c <gettoken+0xa0>
     510:	02078063          	beqz	a5,530 <gettoken+0xa4>
     514:	02600713          	li	a4,38
     518:	00e78a63          	beq	a5,a4,52c <gettoken+0xa0>
     51c:	fd87879b          	addiw	a5,a5,-40
     520:	0ff7f793          	zext.b	a5,a5
     524:	00100713          	li	a4,1
     528:	08f76863          	bltu	a4,a5,5b8 <gettoken+0x12c>
  case '(':
  case ')':
  case ';':
  case '&':
  case '<':
    s++;
     52c:	00148493          	addi	s1,s1,1
    ret = 'a';
    while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
      s++;
    break;
  }
  if(eq)
     530:	000b0463          	beqz	s6,538 <gettoken+0xac>
    *eq = s;
     534:	009b3023          	sd	s1,0(s6)

  while(s < es && strchr(whitespace, *s))
     538:	00002997          	auipc	s3,0x2
     53c:	ad098993          	addi	s3,s3,-1328 # 2008 <whitespace>
     540:	0324f063          	bgeu	s1,s2,560 <gettoken+0xd4>
     544:	0004c583          	lbu	a1,0(s1)
     548:	00098513          	mv	a0,s3
     54c:	255000ef          	jal	fa0 <strchr>
     550:	00050863          	beqz	a0,560 <gettoken+0xd4>
    s++;
     554:	00148493          	addi	s1,s1,1
  while(s < es && strchr(whitespace, *s))
     558:	fe9916e3          	bne	s2,s1,544 <gettoken+0xb8>
     55c:	00090493          	mv	s1,s2
  *ps = s;
     560:	009a3023          	sd	s1,0(s4)
  return ret;
}
     564:	000a8513          	mv	a0,s5
     568:	03813083          	ld	ra,56(sp)
     56c:	03013403          	ld	s0,48(sp)
     570:	02813483          	ld	s1,40(sp)
     574:	02013903          	ld	s2,32(sp)
     578:	01813983          	ld	s3,24(sp)
     57c:	01013a03          	ld	s4,16(sp)
     580:	00813a83          	ld	s5,8(sp)
     584:	00013b03          	ld	s6,0(sp)
     588:	04010113          	addi	sp,sp,64
     58c:	00008067          	ret
  switch(*s){
     590:	03e00713          	li	a4,62
     594:	00e79e63          	bne	a5,a4,5b0 <gettoken+0x124>
    if(*s == '>'){
     598:	0014c703          	lbu	a4,1(s1)
     59c:	03e00793          	li	a5,62
     5a0:	06f70263          	beq	a4,a5,604 <gettoken+0x178>
    s++;
     5a4:	00148493          	addi	s1,s1,1
  ret = *s;
     5a8:	00078a93          	mv	s5,a5
     5ac:	f85ff06f          	j	530 <gettoken+0xa4>
  switch(*s){
     5b0:	07c00713          	li	a4,124
     5b4:	f6e78ce3          	beq	a5,a4,52c <gettoken+0xa0>
    while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
     5b8:	00002997          	auipc	s3,0x2
     5bc:	a5098993          	addi	s3,s3,-1456 # 2008 <whitespace>
     5c0:	00002a97          	auipc	s5,0x2
     5c4:	a40a8a93          	addi	s5,s5,-1472 # 2000 <symbols>
     5c8:	0524fc63          	bgeu	s1,s2,620 <gettoken+0x194>
     5cc:	0004c583          	lbu	a1,0(s1)
     5d0:	00098513          	mv	a0,s3
     5d4:	1cd000ef          	jal	fa0 <strchr>
     5d8:	04051063          	bnez	a0,618 <gettoken+0x18c>
     5dc:	0004c583          	lbu	a1,0(s1)
     5e0:	000a8513          	mv	a0,s5
     5e4:	1bd000ef          	jal	fa0 <strchr>
     5e8:	02051463          	bnez	a0,610 <gettoken+0x184>
      s++;
     5ec:	00148493          	addi	s1,s1,1
    while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
     5f0:	fc991ee3          	bne	s2,s1,5cc <gettoken+0x140>
  if(eq)
     5f4:	00090493          	mv	s1,s2
    ret = 'a';
     5f8:	06100a93          	li	s5,97
  if(eq)
     5fc:	f20b1ce3          	bnez	s6,534 <gettoken+0xa8>
     600:	f61ff06f          	j	560 <gettoken+0xd4>
      s++;
     604:	00248493          	addi	s1,s1,2
      ret = '+';
     608:	02b00a93          	li	s5,43
     60c:	f25ff06f          	j	530 <gettoken+0xa4>
    ret = 'a';
     610:	06100a93          	li	s5,97
     614:	f1dff06f          	j	530 <gettoken+0xa4>
     618:	06100a93          	li	s5,97
     61c:	f15ff06f          	j	530 <gettoken+0xa4>
     620:	06100a93          	li	s5,97
  if(eq)
     624:	f00b18e3          	bnez	s6,534 <gettoken+0xa8>
     628:	f39ff06f          	j	560 <gettoken+0xd4>

000000000000062c <peek>:

int
peek(char **ps, char *es, char *toks)
{
     62c:	fc010113          	addi	sp,sp,-64
     630:	02113c23          	sd	ra,56(sp)
     634:	02813823          	sd	s0,48(sp)
     638:	02913423          	sd	s1,40(sp)
     63c:	03213023          	sd	s2,32(sp)
     640:	01313c23          	sd	s3,24(sp)
     644:	01413823          	sd	s4,16(sp)
     648:	01513423          	sd	s5,8(sp)
     64c:	04010413          	addi	s0,sp,64
     650:	00050a13          	mv	s4,a0
     654:	00058913          	mv	s2,a1
     658:	00060a93          	mv	s5,a2
  char *s;

  s = *ps;
     65c:	00053483          	ld	s1,0(a0)
  while(s < es && strchr(whitespace, *s))
     660:	00002997          	auipc	s3,0x2
     664:	9a898993          	addi	s3,s3,-1624 # 2008 <whitespace>
     668:	02b4f063          	bgeu	s1,a1,688 <peek+0x5c>
     66c:	0004c583          	lbu	a1,0(s1)
     670:	00098513          	mv	a0,s3
     674:	12d000ef          	jal	fa0 <strchr>
     678:	00050863          	beqz	a0,688 <peek+0x5c>
    s++;
     67c:	00148493          	addi	s1,s1,1
  while(s < es && strchr(whitespace, *s))
     680:	fe9916e3          	bne	s2,s1,66c <peek+0x40>
     684:	00090493          	mv	s1,s2
  *ps = s;
     688:	009a3023          	sd	s1,0(s4)
  return *s && strchr(toks, *s);
     68c:	0004c583          	lbu	a1,0(s1)
     690:	00000513          	li	a0,0
     694:	02059463          	bnez	a1,6bc <peek+0x90>
}
     698:	03813083          	ld	ra,56(sp)
     69c:	03013403          	ld	s0,48(sp)
     6a0:	02813483          	ld	s1,40(sp)
     6a4:	02013903          	ld	s2,32(sp)
     6a8:	01813983          	ld	s3,24(sp)
     6ac:	01013a03          	ld	s4,16(sp)
     6b0:	00813a83          	ld	s5,8(sp)
     6b4:	04010113          	addi	sp,sp,64
     6b8:	00008067          	ret
  return *s && strchr(toks, *s);
     6bc:	000a8513          	mv	a0,s5
     6c0:	0e1000ef          	jal	fa0 <strchr>
     6c4:	00a03533          	snez	a0,a0
     6c8:	fd1ff06f          	j	698 <peek+0x6c>

00000000000006cc <parseredirs>:
  return cmd;
}

struct cmd*
parseredirs(struct cmd *cmd, char **ps, char *es)
{
     6cc:	f9010113          	addi	sp,sp,-112
     6d0:	06113423          	sd	ra,104(sp)
     6d4:	06813023          	sd	s0,96(sp)
     6d8:	04913c23          	sd	s1,88(sp)
     6dc:	05213823          	sd	s2,80(sp)
     6e0:	05313423          	sd	s3,72(sp)
     6e4:	05413023          	sd	s4,64(sp)
     6e8:	03513c23          	sd	s5,56(sp)
     6ec:	03613823          	sd	s6,48(sp)
     6f0:	03713423          	sd	s7,40(sp)
     6f4:	03813023          	sd	s8,32(sp)
     6f8:	01913c23          	sd	s9,24(sp)
     6fc:	07010413          	addi	s0,sp,112
     700:	00050a13          	mv	s4,a0
     704:	00058993          	mv	s3,a1
     708:	00060913          	mv	s2,a2
  int tok;
  char *q, *eq;

  while(peek(ps, es, "<>")){
     70c:	00001b17          	auipc	s6,0x1
     710:	594b0b13          	addi	s6,s6,1428 # 1ca0 <malloc+0x1dc>
    tok = gettoken(ps, es, 0, 0);
    if(gettoken(ps, es, &q, &eq) != 'a')
     714:	f9040c93          	addi	s9,s0,-112
     718:	f9840c13          	addi	s8,s0,-104
     71c:	06100b93          	li	s7,97
  while(peek(ps, es, "<>")){
     720:	02c0006f          	j	74c <parseredirs+0x80>
      panic("missing file for redirection");
     724:	00001517          	auipc	a0,0x1
     728:	55c50513          	addi	a0,a0,1372 # 1c80 <malloc+0x1bc>
     72c:	949ff0ef          	jal	74 <panic>
    switch(tok){
    case '<':
      cmd = redircmd(cmd, q, eq, O_RDONLY, 0);
     730:	00000713          	li	a4,0
     734:	00000693          	li	a3,0
     738:	f9043603          	ld	a2,-112(s0)
     73c:	f9843583          	ld	a1,-104(s0)
     740:	000a0513          	mv	a0,s4
     744:	b79ff0ef          	jal	2bc <redircmd>
     748:	00050a13          	mv	s4,a0
    switch(tok){
     74c:	03c00a93          	li	s5,60
  while(peek(ps, es, "<>")){
     750:	000b0613          	mv	a2,s6
     754:	00090593          	mv	a1,s2
     758:	00098513          	mv	a0,s3
     75c:	ed1ff0ef          	jal	62c <peek>
     760:	08050463          	beqz	a0,7e8 <parseredirs+0x11c>
    tok = gettoken(ps, es, 0, 0);
     764:	00000693          	li	a3,0
     768:	00000613          	li	a2,0
     76c:	00090593          	mv	a1,s2
     770:	00098513          	mv	a0,s3
     774:	d19ff0ef          	jal	48c <gettoken>
     778:	00050493          	mv	s1,a0
    if(gettoken(ps, es, &q, &eq) != 'a')
     77c:	000c8693          	mv	a3,s9
     780:	000c0613          	mv	a2,s8
     784:	00090593          	mv	a1,s2
     788:	00098513          	mv	a0,s3
     78c:	d01ff0ef          	jal	48c <gettoken>
     790:	f9751ae3          	bne	a0,s7,724 <parseredirs+0x58>
    switch(tok){
     794:	f9548ee3          	beq	s1,s5,730 <parseredirs+0x64>
     798:	03e00793          	li	a5,62
     79c:	02f48663          	beq	s1,a5,7c8 <parseredirs+0xfc>
     7a0:	02b00793          	li	a5,43
     7a4:	faf496e3          	bne	s1,a5,750 <parseredirs+0x84>
      break;
    case '>':
      cmd = redircmd(cmd, q, eq, O_WRONLY|O_CREATE|O_TRUNC, 1);
      break;
    case '+':  // >>
      cmd = redircmd(cmd, q, eq, O_WRONLY|O_CREATE, 1);
     7a8:	00100713          	li	a4,1
     7ac:	20100693          	li	a3,513
     7b0:	f9043603          	ld	a2,-112(s0)
     7b4:	f9843583          	ld	a1,-104(s0)
     7b8:	000a0513          	mv	a0,s4
     7bc:	b01ff0ef          	jal	2bc <redircmd>
     7c0:	00050a13          	mv	s4,a0
      break;
     7c4:	f89ff06f          	j	74c <parseredirs+0x80>
      cmd = redircmd(cmd, q, eq, O_WRONLY|O_CREATE|O_TRUNC, 1);
     7c8:	00100713          	li	a4,1
     7cc:	60100693          	li	a3,1537
     7d0:	f9043603          	ld	a2,-112(s0)
     7d4:	f9843583          	ld	a1,-104(s0)
     7d8:	000a0513          	mv	a0,s4
     7dc:	ae1ff0ef          	jal	2bc <redircmd>
     7e0:	00050a13          	mv	s4,a0
      break;
     7e4:	f69ff06f          	j	74c <parseredirs+0x80>
    }
  }
  return cmd;
}
     7e8:	000a0513          	mv	a0,s4
     7ec:	06813083          	ld	ra,104(sp)
     7f0:	06013403          	ld	s0,96(sp)
     7f4:	05813483          	ld	s1,88(sp)
     7f8:	05013903          	ld	s2,80(sp)
     7fc:	04813983          	ld	s3,72(sp)
     800:	04013a03          	ld	s4,64(sp)
     804:	03813a83          	ld	s5,56(sp)
     808:	03013b03          	ld	s6,48(sp)
     80c:	02813b83          	ld	s7,40(sp)
     810:	02013c03          	ld	s8,32(sp)
     814:	01813c83          	ld	s9,24(sp)
     818:	07010113          	addi	sp,sp,112
     81c:	00008067          	ret

0000000000000820 <parseexec>:
  return cmd;
}

struct cmd*
parseexec(char **ps, char *es)
{
     820:	f8010113          	addi	sp,sp,-128
     824:	06113c23          	sd	ra,120(sp)
     828:	06813823          	sd	s0,112(sp)
     82c:	06913423          	sd	s1,104(sp)
     830:	05413823          	sd	s4,80(sp)
     834:	05513423          	sd	s5,72(sp)
     838:	08010413          	addi	s0,sp,128
     83c:	00050a13          	mv	s4,a0
     840:	00058a93          	mv	s5,a1
  char *q, *eq;
  int tok, argc;
  struct execcmd *cmd;
  struct cmd *ret;

  if(peek(ps, es, "("))
     844:	00001617          	auipc	a2,0x1
     848:	46460613          	addi	a2,a2,1124 # 1ca8 <malloc+0x1e4>
     84c:	de1ff0ef          	jal	62c <peek>
     850:	06051263          	bnez	a0,8b4 <parseexec+0x94>
     854:	07213023          	sd	s2,96(sp)
     858:	05313c23          	sd	s3,88(sp)
     85c:	05613023          	sd	s6,64(sp)
     860:	03713c23          	sd	s7,56(sp)
     864:	03813823          	sd	s8,48(sp)
     868:	03913423          	sd	s9,40(sp)
     86c:	03a13023          	sd	s10,32(sp)
     870:	01b13c23          	sd	s11,24(sp)
     874:	00050913          	mv	s2,a0
    return parseblock(ps, es);

  ret = execcmd();
     878:	9f9ff0ef          	jal	270 <execcmd>
     87c:	00050993          	mv	s3,a0
     880:	00050d93          	mv	s11,a0
  cmd = (struct execcmd*)ret;

  argc = 0;
  ret = parseredirs(ret, ps, es);
     884:	000a8613          	mv	a2,s5
     888:	000a0593          	mv	a1,s4
     88c:	e41ff0ef          	jal	6cc <parseredirs>
     890:	00050493          	mv	s1,a0
  while(!peek(ps, es, "|)&;")){
     894:	00898993          	addi	s3,s3,8
     898:	00001b17          	auipc	s6,0x1
     89c:	430b0b13          	addi	s6,s6,1072 # 1cc8 <malloc+0x204>
    if((tok=gettoken(ps, es, &q, &eq)) == 0)
     8a0:	f8040c13          	addi	s8,s0,-128
     8a4:	f8840b93          	addi	s7,s0,-120
      break;
    if(tok != 'a')
     8a8:	06100d13          	li	s10,97
      panic("syntax");
    cmd->argv[argc] = q;
    cmd->eargv[argc] = eq;
    argc++;
    if(argc >= MAXARGS)
     8ac:	00a00c93          	li	s9,10
  while(!peek(ps, es, "|)&;")){
     8b0:	0580006f          	j	908 <parseexec+0xe8>
    return parseblock(ps, es);
     8b4:	000a8593          	mv	a1,s5
     8b8:	000a0513          	mv	a0,s4
     8bc:	258000ef          	jal	b14 <parseblock>
     8c0:	00050493          	mv	s1,a0
    ret = parseredirs(ret, ps, es);
  }
  cmd->argv[argc] = 0;
  cmd->eargv[argc] = 0;
  return ret;
}
     8c4:	00048513          	mv	a0,s1
     8c8:	07813083          	ld	ra,120(sp)
     8cc:	07013403          	ld	s0,112(sp)
     8d0:	06813483          	ld	s1,104(sp)
     8d4:	05013a03          	ld	s4,80(sp)
     8d8:	04813a83          	ld	s5,72(sp)
     8dc:	08010113          	addi	sp,sp,128
     8e0:	00008067          	ret
      panic("syntax");
     8e4:	00001517          	auipc	a0,0x1
     8e8:	3cc50513          	addi	a0,a0,972 # 1cb0 <malloc+0x1ec>
     8ec:	f88ff0ef          	jal	74 <panic>
    if(argc >= MAXARGS)
     8f0:	00898993          	addi	s3,s3,8
    ret = parseredirs(ret, ps, es);
     8f4:	000a8613          	mv	a2,s5
     8f8:	000a0593          	mv	a1,s4
     8fc:	00048513          	mv	a0,s1
     900:	dcdff0ef          	jal	6cc <parseredirs>
     904:	00050493          	mv	s1,a0
  while(!peek(ps, es, "|)&;")){
     908:	000b0613          	mv	a2,s6
     90c:	000a8593          	mv	a1,s5
     910:	000a0513          	mv	a0,s4
     914:	d19ff0ef          	jal	62c <peek>
     918:	04051263          	bnez	a0,95c <parseexec+0x13c>
    if((tok=gettoken(ps, es, &q, &eq)) == 0)
     91c:	000c0693          	mv	a3,s8
     920:	000b8613          	mv	a2,s7
     924:	000a8593          	mv	a1,s5
     928:	000a0513          	mv	a0,s4
     92c:	b61ff0ef          	jal	48c <gettoken>
     930:	02050663          	beqz	a0,95c <parseexec+0x13c>
    if(tok != 'a')
     934:	fba518e3          	bne	a0,s10,8e4 <parseexec+0xc4>
    cmd->argv[argc] = q;
     938:	f8843783          	ld	a5,-120(s0)
     93c:	00f9b023          	sd	a5,0(s3)
    cmd->eargv[argc] = eq;
     940:	f8043783          	ld	a5,-128(s0)
     944:	04f9b823          	sd	a5,80(s3)
    argc++;
     948:	0019091b          	addiw	s2,s2,1
    if(argc >= MAXARGS)
     94c:	fb9912e3          	bne	s2,s9,8f0 <parseexec+0xd0>
      panic("too many args");
     950:	00001517          	auipc	a0,0x1
     954:	36850513          	addi	a0,a0,872 # 1cb8 <malloc+0x1f4>
     958:	f1cff0ef          	jal	74 <panic>
  cmd->argv[argc] = 0;
     95c:	00391913          	slli	s2,s2,0x3
     960:	012d87b3          	add	a5,s11,s2
     964:	0007b423          	sd	zero,8(a5)
  cmd->eargv[argc] = 0;
     968:	0407bc23          	sd	zero,88(a5)
     96c:	06013903          	ld	s2,96(sp)
     970:	05813983          	ld	s3,88(sp)
     974:	04013b03          	ld	s6,64(sp)
     978:	03813b83          	ld	s7,56(sp)
     97c:	03013c03          	ld	s8,48(sp)
     980:	02813c83          	ld	s9,40(sp)
     984:	02013d03          	ld	s10,32(sp)
     988:	01813d83          	ld	s11,24(sp)
  return ret;
     98c:	f39ff06f          	j	8c4 <parseexec+0xa4>

0000000000000990 <parsepipe>:
{
     990:	fd010113          	addi	sp,sp,-48
     994:	02113423          	sd	ra,40(sp)
     998:	02813023          	sd	s0,32(sp)
     99c:	00913c23          	sd	s1,24(sp)
     9a0:	01213823          	sd	s2,16(sp)
     9a4:	01313423          	sd	s3,8(sp)
     9a8:	01413023          	sd	s4,0(sp)
     9ac:	03010413          	addi	s0,sp,48
     9b0:	00050913          	mv	s2,a0
     9b4:	00050a13          	mv	s4,a0
     9b8:	00058493          	mv	s1,a1
  cmd = parseexec(ps, es);
     9bc:	e65ff0ef          	jal	820 <parseexec>
     9c0:	00050993          	mv	s3,a0
  if(peek(ps, es, "|")){
     9c4:	00001617          	auipc	a2,0x1
     9c8:	30c60613          	addi	a2,a2,780 # 1cd0 <malloc+0x20c>
     9cc:	00048593          	mv	a1,s1
     9d0:	00090513          	mv	a0,s2
     9d4:	c59ff0ef          	jal	62c <peek>
     9d8:	02051463          	bnez	a0,a00 <parsepipe+0x70>
}
     9dc:	00098513          	mv	a0,s3
     9e0:	02813083          	ld	ra,40(sp)
     9e4:	02013403          	ld	s0,32(sp)
     9e8:	01813483          	ld	s1,24(sp)
     9ec:	01013903          	ld	s2,16(sp)
     9f0:	00813983          	ld	s3,8(sp)
     9f4:	00013a03          	ld	s4,0(sp)
     9f8:	03010113          	addi	sp,sp,48
     9fc:	00008067          	ret
    gettoken(ps, es, 0, 0);
     a00:	00000693          	li	a3,0
     a04:	00000613          	li	a2,0
     a08:	00048593          	mv	a1,s1
     a0c:	000a0513          	mv	a0,s4
     a10:	a7dff0ef          	jal	48c <gettoken>
    cmd = pipecmd(cmd, parsepipe(ps, es));
     a14:	00048593          	mv	a1,s1
     a18:	000a0513          	mv	a0,s4
     a1c:	f75ff0ef          	jal	990 <parsepipe>
     a20:	00050593          	mv	a1,a0
     a24:	00098513          	mv	a0,s3
     a28:	931ff0ef          	jal	358 <pipecmd>
     a2c:	00050993          	mv	s3,a0
  return cmd;
     a30:	fadff06f          	j	9dc <parsepipe+0x4c>

0000000000000a34 <parseline>:
{
     a34:	fd010113          	addi	sp,sp,-48
     a38:	02113423          	sd	ra,40(sp)
     a3c:	02813023          	sd	s0,32(sp)
     a40:	00913c23          	sd	s1,24(sp)
     a44:	01213823          	sd	s2,16(sp)
     a48:	01313423          	sd	s3,8(sp)
     a4c:	01413023          	sd	s4,0(sp)
     a50:	03010413          	addi	s0,sp,48
     a54:	00050913          	mv	s2,a0
     a58:	00058993          	mv	s3,a1
  cmd = parsepipe(ps, es);
     a5c:	f35ff0ef          	jal	990 <parsepipe>
     a60:	00050493          	mv	s1,a0
  while(peek(ps, es, "&")){
     a64:	00001a17          	auipc	s4,0x1
     a68:	274a0a13          	addi	s4,s4,628 # 1cd8 <malloc+0x214>
     a6c:	0240006f          	j	a90 <parseline+0x5c>
    gettoken(ps, es, 0, 0);
     a70:	00000693          	li	a3,0
     a74:	00000613          	li	a2,0
     a78:	00098593          	mv	a1,s3
     a7c:	00090513          	mv	a0,s2
     a80:	a0dff0ef          	jal	48c <gettoken>
    cmd = backcmd(cmd);
     a84:	00048513          	mv	a0,s1
     a88:	9a9ff0ef          	jal	430 <backcmd>
     a8c:	00050493          	mv	s1,a0
  while(peek(ps, es, "&")){
     a90:	000a0613          	mv	a2,s4
     a94:	00098593          	mv	a1,s3
     a98:	00090513          	mv	a0,s2
     a9c:	b91ff0ef          	jal	62c <peek>
     aa0:	fc0518e3          	bnez	a0,a70 <parseline+0x3c>
  if(peek(ps, es, ";")){
     aa4:	00001617          	auipc	a2,0x1
     aa8:	23c60613          	addi	a2,a2,572 # 1ce0 <malloc+0x21c>
     aac:	00098593          	mv	a1,s3
     ab0:	00090513          	mv	a0,s2
     ab4:	b79ff0ef          	jal	62c <peek>
     ab8:	02051463          	bnez	a0,ae0 <parseline+0xac>
}
     abc:	00048513          	mv	a0,s1
     ac0:	02813083          	ld	ra,40(sp)
     ac4:	02013403          	ld	s0,32(sp)
     ac8:	01813483          	ld	s1,24(sp)
     acc:	01013903          	ld	s2,16(sp)
     ad0:	00813983          	ld	s3,8(sp)
     ad4:	00013a03          	ld	s4,0(sp)
     ad8:	03010113          	addi	sp,sp,48
     adc:	00008067          	ret
    gettoken(ps, es, 0, 0);
     ae0:	00000693          	li	a3,0
     ae4:	00000613          	li	a2,0
     ae8:	00098593          	mv	a1,s3
     aec:	00090513          	mv	a0,s2
     af0:	99dff0ef          	jal	48c <gettoken>
    cmd = listcmd(cmd, parseline(ps, es));
     af4:	00098593          	mv	a1,s3
     af8:	00090513          	mv	a0,s2
     afc:	f39ff0ef          	jal	a34 <parseline>
     b00:	00050593          	mv	a1,a0
     b04:	00048513          	mv	a0,s1
     b08:	8bdff0ef          	jal	3c4 <listcmd>
     b0c:	00050493          	mv	s1,a0
  return cmd;
     b10:	fadff06f          	j	abc <parseline+0x88>

0000000000000b14 <parseblock>:
{
     b14:	fd010113          	addi	sp,sp,-48
     b18:	02113423          	sd	ra,40(sp)
     b1c:	02813023          	sd	s0,32(sp)
     b20:	00913c23          	sd	s1,24(sp)
     b24:	01213823          	sd	s2,16(sp)
     b28:	01313423          	sd	s3,8(sp)
     b2c:	03010413          	addi	s0,sp,48
     b30:	00050493          	mv	s1,a0
     b34:	00058913          	mv	s2,a1
  if(!peek(ps, es, "("))
     b38:	00001617          	auipc	a2,0x1
     b3c:	17060613          	addi	a2,a2,368 # 1ca8 <malloc+0x1e4>
     b40:	aedff0ef          	jal	62c <peek>
     b44:	08050063          	beqz	a0,bc4 <parseblock+0xb0>
  gettoken(ps, es, 0, 0);
     b48:	00000693          	li	a3,0
     b4c:	00000613          	li	a2,0
     b50:	00090593          	mv	a1,s2
     b54:	00048513          	mv	a0,s1
     b58:	935ff0ef          	jal	48c <gettoken>
  cmd = parseline(ps, es);
     b5c:	00090593          	mv	a1,s2
     b60:	00048513          	mv	a0,s1
     b64:	ed1ff0ef          	jal	a34 <parseline>
     b68:	00050993          	mv	s3,a0
  if(!peek(ps, es, ")"))
     b6c:	00001617          	auipc	a2,0x1
     b70:	18c60613          	addi	a2,a2,396 # 1cf8 <malloc+0x234>
     b74:	00090593          	mv	a1,s2
     b78:	00048513          	mv	a0,s1
     b7c:	ab1ff0ef          	jal	62c <peek>
     b80:	04050863          	beqz	a0,bd0 <parseblock+0xbc>
  gettoken(ps, es, 0, 0);
     b84:	00000693          	li	a3,0
     b88:	00000613          	li	a2,0
     b8c:	00090593          	mv	a1,s2
     b90:	00048513          	mv	a0,s1
     b94:	8f9ff0ef          	jal	48c <gettoken>
  cmd = parseredirs(cmd, ps, es);
     b98:	00090613          	mv	a2,s2
     b9c:	00048593          	mv	a1,s1
     ba0:	00098513          	mv	a0,s3
     ba4:	b29ff0ef          	jal	6cc <parseredirs>
}
     ba8:	02813083          	ld	ra,40(sp)
     bac:	02013403          	ld	s0,32(sp)
     bb0:	01813483          	ld	s1,24(sp)
     bb4:	01013903          	ld	s2,16(sp)
     bb8:	00813983          	ld	s3,8(sp)
     bbc:	03010113          	addi	sp,sp,48
     bc0:	00008067          	ret
    panic("parseblock");
     bc4:	00001517          	auipc	a0,0x1
     bc8:	12450513          	addi	a0,a0,292 # 1ce8 <malloc+0x224>
     bcc:	ca8ff0ef          	jal	74 <panic>
    panic("syntax - missing )");
     bd0:	00001517          	auipc	a0,0x1
     bd4:	13050513          	addi	a0,a0,304 # 1d00 <malloc+0x23c>
     bd8:	c9cff0ef          	jal	74 <panic>

0000000000000bdc <nulterminate>:

// NUL-terminate all the counted strings.
struct cmd*
nulterminate(struct cmd *cmd)
{
     bdc:	fe010113          	addi	sp,sp,-32
     be0:	00113c23          	sd	ra,24(sp)
     be4:	00813823          	sd	s0,16(sp)
     be8:	00913423          	sd	s1,8(sp)
     bec:	02010413          	addi	s0,sp,32
     bf0:	00050493          	mv	s1,a0
  struct execcmd *ecmd;
  struct listcmd *lcmd;
  struct pipecmd *pcmd;
  struct redircmd *rcmd;

  if(cmd == 0)
     bf4:	06050263          	beqz	a0,c58 <nulterminate+0x7c>
    return 0;

  switch(cmd->type){
     bf8:	00052703          	lw	a4,0(a0)
     bfc:	00500793          	li	a5,5
     c00:	04e7ec63          	bltu	a5,a4,c58 <nulterminate+0x7c>
     c04:	00056783          	lwu	a5,0(a0)
     c08:	00279793          	slli	a5,a5,0x2
     c0c:	00001717          	auipc	a4,0x1
     c10:	15470713          	addi	a4,a4,340 # 1d60 <malloc+0x29c>
     c14:	00e787b3          	add	a5,a5,a4
     c18:	0007a783          	lw	a5,0(a5)
     c1c:	00e787b3          	add	a5,a5,a4
     c20:	00078067          	jr	a5
  case EXEC:
    ecmd = (struct execcmd*)cmd;
    for(i=0; ecmd->argv[i]; i++)
     c24:	00853783          	ld	a5,8(a0)
     c28:	02078863          	beqz	a5,c58 <nulterminate+0x7c>
     c2c:	01050793          	addi	a5,a0,16
      *ecmd->eargv[i] = 0;
     c30:	0487b703          	ld	a4,72(a5)
     c34:	00070023          	sb	zero,0(a4)
    for(i=0; ecmd->argv[i]; i++)
     c38:	00878793          	addi	a5,a5,8
     c3c:	ff87b703          	ld	a4,-8(a5)
     c40:	fe0718e3          	bnez	a4,c30 <nulterminate+0x54>
     c44:	0140006f          	j	c58 <nulterminate+0x7c>
    break;

  case REDIR:
    rcmd = (struct redircmd*)cmd;
    nulterminate(rcmd->cmd);
     c48:	00853503          	ld	a0,8(a0)
     c4c:	f91ff0ef          	jal	bdc <nulterminate>
    *rcmd->efile = 0;
     c50:	0184b783          	ld	a5,24(s1)
     c54:	00078023          	sb	zero,0(a5)
    bcmd = (struct backcmd*)cmd;
    nulterminate(bcmd->cmd);
    break;
  }
  return cmd;
}
     c58:	00048513          	mv	a0,s1
     c5c:	01813083          	ld	ra,24(sp)
     c60:	01013403          	ld	s0,16(sp)
     c64:	00813483          	ld	s1,8(sp)
     c68:	02010113          	addi	sp,sp,32
     c6c:	00008067          	ret
    nulterminate(pcmd->left);
     c70:	00853503          	ld	a0,8(a0)
     c74:	f69ff0ef          	jal	bdc <nulterminate>
    nulterminate(pcmd->right);
     c78:	0104b503          	ld	a0,16(s1)
     c7c:	f61ff0ef          	jal	bdc <nulterminate>
    break;
     c80:	fd9ff06f          	j	c58 <nulterminate+0x7c>
    nulterminate(lcmd->left);
     c84:	00853503          	ld	a0,8(a0)
     c88:	f55ff0ef          	jal	bdc <nulterminate>
    nulterminate(lcmd->right);
     c8c:	0104b503          	ld	a0,16(s1)
     c90:	f4dff0ef          	jal	bdc <nulterminate>
    break;
     c94:	fc5ff06f          	j	c58 <nulterminate+0x7c>
    nulterminate(bcmd->cmd);
     c98:	00853503          	ld	a0,8(a0)
     c9c:	f41ff0ef          	jal	bdc <nulterminate>
    break;
     ca0:	fb9ff06f          	j	c58 <nulterminate+0x7c>

0000000000000ca4 <parsecmd>:
{
     ca4:	fc010113          	addi	sp,sp,-64
     ca8:	02113c23          	sd	ra,56(sp)
     cac:	02813823          	sd	s0,48(sp)
     cb0:	02913423          	sd	s1,40(sp)
     cb4:	03213023          	sd	s2,32(sp)
     cb8:	01313c23          	sd	s3,24(sp)
     cbc:	04010413          	addi	s0,sp,64
     cc0:	fca43423          	sd	a0,-56(s0)
  es = s + strlen(s);
     cc4:	00050493          	mv	s1,a0
     cc8:	250000ef          	jal	f18 <strlen>
     ccc:	02051513          	slli	a0,a0,0x20
     cd0:	02055513          	srli	a0,a0,0x20
     cd4:	00a484b3          	add	s1,s1,a0
  cmd = parseline(&s, es);
     cd8:	fc840913          	addi	s2,s0,-56
     cdc:	00048593          	mv	a1,s1
     ce0:	00090513          	mv	a0,s2
     ce4:	d51ff0ef          	jal	a34 <parseline>
     ce8:	00050993          	mv	s3,a0
  peek(&s, es, "");
     cec:	00001617          	auipc	a2,0x1
     cf0:	f4c60613          	addi	a2,a2,-180 # 1c38 <malloc+0x174>
     cf4:	00048593          	mv	a1,s1
     cf8:	00090513          	mv	a0,s2
     cfc:	931ff0ef          	jal	62c <peek>
  if(s != es){
     d00:	fc843603          	ld	a2,-56(s0)
     d04:	02961663          	bne	a2,s1,d30 <parsecmd+0x8c>
  nulterminate(cmd);
     d08:	00098513          	mv	a0,s3
     d0c:	ed1ff0ef          	jal	bdc <nulterminate>
}
     d10:	00098513          	mv	a0,s3
     d14:	03813083          	ld	ra,56(sp)
     d18:	03013403          	ld	s0,48(sp)
     d1c:	02813483          	ld	s1,40(sp)
     d20:	02013903          	ld	s2,32(sp)
     d24:	01813983          	ld	s3,24(sp)
     d28:	04010113          	addi	sp,sp,64
     d2c:	00008067          	ret
    fprintf(2, "leftovers: %s\n", s);
     d30:	00001597          	auipc	a1,0x1
     d34:	fe858593          	addi	a1,a1,-24 # 1d18 <malloc+0x254>
     d38:	00200513          	li	a0,2
     d3c:	439000ef          	jal	1974 <fprintf>
    panic("syntax");
     d40:	00001517          	auipc	a0,0x1
     d44:	f7050513          	addi	a0,a0,-144 # 1cb0 <malloc+0x1ec>
     d48:	b2cff0ef          	jal	74 <panic>

0000000000000d4c <main>:
{
     d4c:	fc010113          	addi	sp,sp,-64
     d50:	02113c23          	sd	ra,56(sp)
     d54:	02813823          	sd	s0,48(sp)
     d58:	02913423          	sd	s1,40(sp)
     d5c:	03213023          	sd	s2,32(sp)
     d60:	01313c23          	sd	s3,24(sp)
     d64:	01413823          	sd	s4,16(sp)
     d68:	01513423          	sd	s5,8(sp)
     d6c:	01613023          	sd	s6,0(sp)
     d70:	04010413          	addi	s0,sp,64
  while((fd = open("console", O_RDWR)) >= 0){
     d74:	00200493          	li	s1,2
     d78:	00001917          	auipc	s2,0x1
     d7c:	fb090913          	addi	s2,s2,-80 # 1d28 <malloc+0x264>
     d80:	00048593          	mv	a1,s1
     d84:	00090513          	mv	a0,s2
     d88:	5b8000ef          	jal	1340 <open>
     d8c:	00054663          	bltz	a0,d98 <main+0x4c>
    if(fd >= 3){
     d90:	fea4d8e3          	bge	s1,a0,d80 <main+0x34>
      close(fd);
     d94:	588000ef          	jal	131c <close>
  while(getcmd(buf, sizeof(buf)) >= 0){
     d98:	06400993          	li	s3,100
     d9c:	00001917          	auipc	s2,0x1
     da0:	29490913          	addi	s2,s2,660 # 2030 <buf.0>
    if (*cmd == '\n') // is a blank command
     da4:	00a00a13          	li	s4,10
    if(cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == ' '){
     da8:	06300a93          	li	s5,99
     dac:	02000b13          	li	s6,32
     db0:	0140006f          	j	dc4 <main+0x78>
      if(fork1() == 0)
     db4:	aecff0ef          	jal	a0 <fork1>
     db8:	0a050a63          	beqz	a0,e6c <main+0x120>
      wait(0);
     dbc:	00000513          	li	a0,0
     dc0:	52c000ef          	jal	12ec <wait>
  while(getcmd(buf, sizeof(buf)) >= 0){
     dc4:	00098593          	mv	a1,s3
     dc8:	00090513          	mv	a0,s2
     dcc:	a34ff0ef          	jal	0 <getcmd>
     dd0:	0a054463          	bltz	a0,e78 <main+0x12c>
    while (*cmd == ' ' || *cmd == '\t')
     dd4:	00094783          	lbu	a5,0(s2)
     dd8:	fe078713          	addi	a4,a5,-32
     ddc:	00070a63          	beqz	a4,df0 <main+0xa4>
     de0:	ff778713          	addi	a4,a5,-9
    char *cmd = buf;
     de4:	00001497          	auipc	s1,0x1
     de8:	24c48493          	addi	s1,s1,588 # 2030 <buf.0>
    while (*cmd == ' ' || *cmd == '\t')
     dec:	02071263          	bnez	a4,e10 <main+0xc4>
    char *cmd = buf;
     df0:	00001497          	auipc	s1,0x1
     df4:	24048493          	addi	s1,s1,576 # 2030 <buf.0>
      cmd++;
     df8:	00148493          	addi	s1,s1,1
    while (*cmd == ' ' || *cmd == '\t')
     dfc:	0004c783          	lbu	a5,0(s1)
     e00:	fe078713          	addi	a4,a5,-32
     e04:	fe070ae3          	beqz	a4,df8 <main+0xac>
     e08:	ff778713          	addi	a4,a5,-9
     e0c:	fe0706e3          	beqz	a4,df8 <main+0xac>
    if (*cmd == '\n') // is a blank command
     e10:	fb478ae3          	beq	a5,s4,dc4 <main+0x78>
    if(cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == ' '){
     e14:	fb5790e3          	bne	a5,s5,db4 <main+0x68>
     e18:	0014c783          	lbu	a5,1(s1)
     e1c:	f9379ce3          	bne	a5,s3,db4 <main+0x68>
     e20:	0024c783          	lbu	a5,2(s1)
     e24:	f96798e3          	bne	a5,s6,db4 <main+0x68>
      cmd[strlen(cmd)-1] = 0;  // chop \n
     e28:	00048513          	mv	a0,s1
     e2c:	0ec000ef          	jal	f18 <strlen>
     e30:	fff5079b          	addiw	a5,a0,-1
     e34:	02079793          	slli	a5,a5,0x20
     e38:	0207d793          	srli	a5,a5,0x20
     e3c:	00f487b3          	add	a5,s1,a5
     e40:	00078023          	sb	zero,0(a5)
      if(chdir(cmd+3) < 0)
     e44:	00348493          	addi	s1,s1,3
     e48:	00048513          	mv	a0,s1
     e4c:	53c000ef          	jal	1388 <chdir>
     e50:	f6055ae3          	bgez	a0,dc4 <main+0x78>
        fprintf(2, "cannot cd %s\n", cmd+3);
     e54:	00048613          	mv	a2,s1
     e58:	00001597          	auipc	a1,0x1
     e5c:	ed858593          	addi	a1,a1,-296 # 1d30 <malloc+0x26c>
     e60:	00200513          	li	a0,2
     e64:	311000ef          	jal	1974 <fprintf>
     e68:	f5dff06f          	j	dc4 <main+0x78>
        runcmd(parsecmd(cmd));
     e6c:	00048513          	mv	a0,s1
     e70:	e35ff0ef          	jal	ca4 <parsecmd>
     e74:	a64ff0ef          	jal	d8 <runcmd>
  exit(0);
     e78:	00000513          	li	a0,0
     e7c:	464000ef          	jal	12e0 <exit>

0000000000000e80 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
     e80:	ff010113          	addi	sp,sp,-16
     e84:	00113423          	sd	ra,8(sp)
     e88:	00813023          	sd	s0,0(sp)
     e8c:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
     e90:	ebdff0ef          	jal	d4c <main>
  exit(r);
     e94:	44c000ef          	jal	12e0 <exit>

0000000000000e98 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
     e98:	ff010113          	addi	sp,sp,-16
     e9c:	00113423          	sd	ra,8(sp)
     ea0:	00813023          	sd	s0,0(sp)
     ea4:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
     ea8:	00050793          	mv	a5,a0
     eac:	00158593          	addi	a1,a1,1
     eb0:	00178793          	addi	a5,a5,1
     eb4:	fff5c703          	lbu	a4,-1(a1)
     eb8:	fee78fa3          	sb	a4,-1(a5)
     ebc:	fe0718e3          	bnez	a4,eac <strcpy+0x14>
    ;
  return os;
}
     ec0:	00813083          	ld	ra,8(sp)
     ec4:	00013403          	ld	s0,0(sp)
     ec8:	01010113          	addi	sp,sp,16
     ecc:	00008067          	ret

0000000000000ed0 <strcmp>:

int
strcmp(const char *p, const char *q)
{
     ed0:	ff010113          	addi	sp,sp,-16
     ed4:	00113423          	sd	ra,8(sp)
     ed8:	00813023          	sd	s0,0(sp)
     edc:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
     ee0:	00054783          	lbu	a5,0(a0)
     ee4:	00078e63          	beqz	a5,f00 <strcmp+0x30>
     ee8:	0005c703          	lbu	a4,0(a1)
     eec:	00f71a63          	bne	a4,a5,f00 <strcmp+0x30>
    p++, q++;
     ef0:	00150513          	addi	a0,a0,1
     ef4:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
     ef8:	00054783          	lbu	a5,0(a0)
     efc:	fe0796e3          	bnez	a5,ee8 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
     f00:	0005c503          	lbu	a0,0(a1)
}
     f04:	40a7853b          	subw	a0,a5,a0
     f08:	00813083          	ld	ra,8(sp)
     f0c:	00013403          	ld	s0,0(sp)
     f10:	01010113          	addi	sp,sp,16
     f14:	00008067          	ret

0000000000000f18 <strlen>:

uint
strlen(const char *s)
{
     f18:	ff010113          	addi	sp,sp,-16
     f1c:	00113423          	sd	ra,8(sp)
     f20:	00813023          	sd	s0,0(sp)
     f24:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
     f28:	00054783          	lbu	a5,0(a0)
     f2c:	02078663          	beqz	a5,f58 <strlen+0x40>
     f30:	00150793          	addi	a5,a0,1
     f34:	00078693          	mv	a3,a5
     f38:	00178793          	addi	a5,a5,1
     f3c:	fff7c703          	lbu	a4,-1(a5)
     f40:	fe071ae3          	bnez	a4,f34 <strlen+0x1c>
     f44:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
     f48:	00813083          	ld	ra,8(sp)
     f4c:	00013403          	ld	s0,0(sp)
     f50:	01010113          	addi	sp,sp,16
     f54:	00008067          	ret
  for(n = 0; s[n]; n++)
     f58:	00000513          	li	a0,0
     f5c:	fedff06f          	j	f48 <strlen+0x30>

0000000000000f60 <memset>:

void*
memset(void *dst, int c, uint n)
{
     f60:	ff010113          	addi	sp,sp,-16
     f64:	00113423          	sd	ra,8(sp)
     f68:	00813023          	sd	s0,0(sp)
     f6c:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
     f70:	02060063          	beqz	a2,f90 <memset+0x30>
     f74:	00050793          	mv	a5,a0
     f78:	02061613          	slli	a2,a2,0x20
     f7c:	02065613          	srli	a2,a2,0x20
     f80:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
     f84:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
     f88:	00178793          	addi	a5,a5,1
     f8c:	fee79ce3          	bne	a5,a4,f84 <memset+0x24>
  }
  return dst;
}
     f90:	00813083          	ld	ra,8(sp)
     f94:	00013403          	ld	s0,0(sp)
     f98:	01010113          	addi	sp,sp,16
     f9c:	00008067          	ret

0000000000000fa0 <strchr>:

char*
strchr(const char *s, char c)
{
     fa0:	ff010113          	addi	sp,sp,-16
     fa4:	00113423          	sd	ra,8(sp)
     fa8:	00813023          	sd	s0,0(sp)
     fac:	01010413          	addi	s0,sp,16
  for(; *s; s++)
     fb0:	00054783          	lbu	a5,0(a0)
     fb4:	02078463          	beqz	a5,fdc <strchr+0x3c>
    if(*s == c)
     fb8:	00f58a63          	beq	a1,a5,fcc <strchr+0x2c>
  for(; *s; s++)
     fbc:	00150513          	addi	a0,a0,1
     fc0:	00054783          	lbu	a5,0(a0)
     fc4:	fe079ae3          	bnez	a5,fb8 <strchr+0x18>
      return (char*)s;
  return 0;
     fc8:	00000513          	li	a0,0
}
     fcc:	00813083          	ld	ra,8(sp)
     fd0:	00013403          	ld	s0,0(sp)
     fd4:	01010113          	addi	sp,sp,16
     fd8:	00008067          	ret
  return 0;
     fdc:	00000513          	li	a0,0
     fe0:	fedff06f          	j	fcc <strchr+0x2c>

0000000000000fe4 <gets>:

char*
gets(char *buf, int max)
{
     fe4:	fa010113          	addi	sp,sp,-96
     fe8:	04113c23          	sd	ra,88(sp)
     fec:	04813823          	sd	s0,80(sp)
     ff0:	04913423          	sd	s1,72(sp)
     ff4:	05213023          	sd	s2,64(sp)
     ff8:	03313c23          	sd	s3,56(sp)
     ffc:	03413823          	sd	s4,48(sp)
    1000:	03513423          	sd	s5,40(sp)
    1004:	03613023          	sd	s6,32(sp)
    1008:	01713c23          	sd	s7,24(sp)
    100c:	01813823          	sd	s8,16(sp)
    1010:	06010413          	addi	s0,sp,96
    1014:	00050b93          	mv	s7,a0
    1018:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    101c:	00050913          	mv	s2,a0
    1020:	00000493          	li	s1,0
    cc = read(0, &c, 1);
    1024:	faf40b13          	addi	s6,s0,-81
    1028:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
    102c:	00048c13          	mv	s8,s1
    1030:	0014899b          	addiw	s3,s1,1
    1034:	00098493          	mv	s1,s3
    1038:	0349dc63          	bge	s3,s4,1070 <gets+0x8c>
    cc = read(0, &c, 1);
    103c:	000a8613          	mv	a2,s5
    1040:	000b0593          	mv	a1,s6
    1044:	00000513          	li	a0,0
    1048:	2bc000ef          	jal	1304 <read>
    if(cc < 1)
    104c:	02a05263          	blez	a0,1070 <gets+0x8c>
      break;
    buf[i++] = c;
    1050:	faf44783          	lbu	a5,-81(s0)
    1054:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
    1058:	00190913          	addi	s2,s2,1
    105c:	ff678713          	addi	a4,a5,-10
    1060:	00070663          	beqz	a4,106c <gets+0x88>
    1064:	ff378793          	addi	a5,a5,-13
    1068:	fc0792e3          	bnez	a5,102c <gets+0x48>
    buf[i++] = c;
    106c:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
    1070:	018b8c33          	add	s8,s7,s8
    1074:	000c0023          	sb	zero,0(s8)
  return buf;
}
    1078:	000b8513          	mv	a0,s7
    107c:	05813083          	ld	ra,88(sp)
    1080:	05013403          	ld	s0,80(sp)
    1084:	04813483          	ld	s1,72(sp)
    1088:	04013903          	ld	s2,64(sp)
    108c:	03813983          	ld	s3,56(sp)
    1090:	03013a03          	ld	s4,48(sp)
    1094:	02813a83          	ld	s5,40(sp)
    1098:	02013b03          	ld	s6,32(sp)
    109c:	01813b83          	ld	s7,24(sp)
    10a0:	01013c03          	ld	s8,16(sp)
    10a4:	06010113          	addi	sp,sp,96
    10a8:	00008067          	ret

00000000000010ac <stat>:

int
stat(const char *n, struct stat *st)
{
    10ac:	fe010113          	addi	sp,sp,-32
    10b0:	00113c23          	sd	ra,24(sp)
    10b4:	00813823          	sd	s0,16(sp)
    10b8:	01213023          	sd	s2,0(sp)
    10bc:	02010413          	addi	s0,sp,32
    10c0:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
    10c4:	00000593          	li	a1,0
    10c8:	278000ef          	jal	1340 <open>
  if(fd < 0)
    10cc:	02054e63          	bltz	a0,1108 <stat+0x5c>
    10d0:	00913423          	sd	s1,8(sp)
    10d4:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
    10d8:	00090593          	mv	a1,s2
    10dc:	288000ef          	jal	1364 <fstat>
    10e0:	00050913          	mv	s2,a0
  close(fd);
    10e4:	00048513          	mv	a0,s1
    10e8:	234000ef          	jal	131c <close>
  return r;
    10ec:	00813483          	ld	s1,8(sp)
}
    10f0:	00090513          	mv	a0,s2
    10f4:	01813083          	ld	ra,24(sp)
    10f8:	01013403          	ld	s0,16(sp)
    10fc:	00013903          	ld	s2,0(sp)
    1100:	02010113          	addi	sp,sp,32
    1104:	00008067          	ret
    return -1;
    1108:	fff00793          	li	a5,-1
    110c:	00078913          	mv	s2,a5
    1110:	fe1ff06f          	j	10f0 <stat+0x44>

0000000000001114 <atoi>:

int
atoi(const char *s)
{
    1114:	ff010113          	addi	sp,sp,-16
    1118:	00113423          	sd	ra,8(sp)
    111c:	00813023          	sd	s0,0(sp)
    1120:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    1124:	00054683          	lbu	a3,0(a0)
    1128:	fd06879b          	addiw	a5,a3,-48
    112c:	0ff7f793          	zext.b	a5,a5
    1130:	00900613          	li	a2,9
    1134:	04f66263          	bltu	a2,a5,1178 <atoi+0x64>
    1138:	00050713          	mv	a4,a0
  n = 0;
    113c:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
    1140:	00170713          	addi	a4,a4,1
    1144:	0025179b          	slliw	a5,a0,0x2
    1148:	00a787bb          	addw	a5,a5,a0
    114c:	0017979b          	slliw	a5,a5,0x1
    1150:	00d787bb          	addw	a5,a5,a3
    1154:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
    1158:	00074683          	lbu	a3,0(a4)
    115c:	fd06879b          	addiw	a5,a3,-48
    1160:	0ff7f793          	zext.b	a5,a5
    1164:	fcf67ee3          	bgeu	a2,a5,1140 <atoi+0x2c>
  return n;
}
    1168:	00813083          	ld	ra,8(sp)
    116c:	00013403          	ld	s0,0(sp)
    1170:	01010113          	addi	sp,sp,16
    1174:	00008067          	ret
  n = 0;
    1178:	00000513          	li	a0,0
    117c:	fedff06f          	j	1168 <atoi+0x54>

0000000000001180 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
    1180:	ff010113          	addi	sp,sp,-16
    1184:	00113423          	sd	ra,8(sp)
    1188:	00813023          	sd	s0,0(sp)
    118c:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
    1190:	02b57e63          	bgeu	a0,a1,11cc <memmove+0x4c>
    while(n-- > 0)
    1194:	02c05463          	blez	a2,11bc <memmove+0x3c>
    1198:	02061613          	slli	a2,a2,0x20
    119c:	02065613          	srli	a2,a2,0x20
    11a0:	00c507b3          	add	a5,a0,a2
  dst = vdst;
    11a4:	00050713          	mv	a4,a0
      *dst++ = *src++;
    11a8:	00158593          	addi	a1,a1,1
    11ac:	00170713          	addi	a4,a4,1
    11b0:	fff5c683          	lbu	a3,-1(a1)
    11b4:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
    11b8:	fee798e3          	bne	a5,a4,11a8 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
    11bc:	00813083          	ld	ra,8(sp)
    11c0:	00013403          	ld	s0,0(sp)
    11c4:	01010113          	addi	sp,sp,16
    11c8:	00008067          	ret
    while(n-- > 0)
    11cc:	fec058e3          	blez	a2,11bc <memmove+0x3c>
    dst += n;
    11d0:	00c50733          	add	a4,a0,a2
    src += n;
    11d4:	00c585b3          	add	a1,a1,a2
    11d8:	fff6079b          	addiw	a5,a2,-1
    11dc:	02079793          	slli	a5,a5,0x20
    11e0:	0207d793          	srli	a5,a5,0x20
    11e4:	fff7c793          	not	a5,a5
    11e8:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
    11ec:	fff58593          	addi	a1,a1,-1
    11f0:	fff70713          	addi	a4,a4,-1
    11f4:	0005c683          	lbu	a3,0(a1)
    11f8:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
    11fc:	fef718e3          	bne	a4,a5,11ec <memmove+0x6c>
    1200:	fbdff06f          	j	11bc <memmove+0x3c>

0000000000001204 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
    1204:	ff010113          	addi	sp,sp,-16
    1208:	00113423          	sd	ra,8(sp)
    120c:	00813023          	sd	s0,0(sp)
    1210:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
    1214:	04060263          	beqz	a2,1258 <memcmp+0x54>
    1218:	02061613          	slli	a2,a2,0x20
    121c:	02065613          	srli	a2,a2,0x20
    1220:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
    1224:	00054783          	lbu	a5,0(a0)
    1228:	0005c703          	lbu	a4,0(a1)
    122c:	00e79c63          	bne	a5,a4,1244 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
    1230:	00150513          	addi	a0,a0,1
    p2++;
    1234:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
    1238:	fed516e3          	bne	a0,a3,1224 <memcmp+0x20>
  }
  return 0;
    123c:	00000513          	li	a0,0
    1240:	0080006f          	j	1248 <memcmp+0x44>
      return *p1 - *p2;
    1244:	40e7853b          	subw	a0,a5,a4
}
    1248:	00813083          	ld	ra,8(sp)
    124c:	00013403          	ld	s0,0(sp)
    1250:	01010113          	addi	sp,sp,16
    1254:	00008067          	ret
  return 0;
    1258:	00000513          	li	a0,0
    125c:	fedff06f          	j	1248 <memcmp+0x44>

0000000000001260 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
    1260:	ff010113          	addi	sp,sp,-16
    1264:	00113423          	sd	ra,8(sp)
    1268:	00813023          	sd	s0,0(sp)
    126c:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
    1270:	f11ff0ef          	jal	1180 <memmove>
}
    1274:	00813083          	ld	ra,8(sp)
    1278:	00013403          	ld	s0,0(sp)
    127c:	01010113          	addi	sp,sp,16
    1280:	00008067          	ret

0000000000001284 <sbrk>:

char *
sbrk(int n) {
    1284:	ff010113          	addi	sp,sp,-16
    1288:	00113423          	sd	ra,8(sp)
    128c:	00813023          	sd	s0,0(sp)
    1290:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
    1294:	00100593          	li	a1,1
    1298:	114000ef          	jal	13ac <sys_sbrk>
}
    129c:	00813083          	ld	ra,8(sp)
    12a0:	00013403          	ld	s0,0(sp)
    12a4:	01010113          	addi	sp,sp,16
    12a8:	00008067          	ret

00000000000012ac <sbrklazy>:

char *
sbrklazy(int n) {
    12ac:	ff010113          	addi	sp,sp,-16
    12b0:	00113423          	sd	ra,8(sp)
    12b4:	00813023          	sd	s0,0(sp)
    12b8:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
    12bc:	00200593          	li	a1,2
    12c0:	0ec000ef          	jal	13ac <sys_sbrk>
}
    12c4:	00813083          	ld	ra,8(sp)
    12c8:	00013403          	ld	s0,0(sp)
    12cc:	01010113          	addi	sp,sp,16
    12d0:	00008067          	ret

00000000000012d4 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
    12d4:	00100893          	li	a7,1
 ecall
    12d8:	00000073          	ecall
 ret
    12dc:	00008067          	ret

00000000000012e0 <exit>:
.global exit
exit:
 li a7, SYS_exit
    12e0:	00200893          	li	a7,2
 ecall
    12e4:	00000073          	ecall
 ret
    12e8:	00008067          	ret

00000000000012ec <wait>:
.global wait
wait:
 li a7, SYS_wait
    12ec:	00300893          	li	a7,3
 ecall
    12f0:	00000073          	ecall
 ret
    12f4:	00008067          	ret

00000000000012f8 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
    12f8:	00400893          	li	a7,4
 ecall
    12fc:	00000073          	ecall
 ret
    1300:	00008067          	ret

0000000000001304 <read>:
.global read
read:
 li a7, SYS_read
    1304:	00500893          	li	a7,5
 ecall
    1308:	00000073          	ecall
 ret
    130c:	00008067          	ret

0000000000001310 <write>:
.global write
write:
 li a7, SYS_write
    1310:	01000893          	li	a7,16
 ecall
    1314:	00000073          	ecall
 ret
    1318:	00008067          	ret

000000000000131c <close>:
.global close
close:
 li a7, SYS_close
    131c:	01500893          	li	a7,21
 ecall
    1320:	00000073          	ecall
 ret
    1324:	00008067          	ret

0000000000001328 <kill>:
.global kill
kill:
 li a7, SYS_kill
    1328:	00600893          	li	a7,6
 ecall
    132c:	00000073          	ecall
 ret
    1330:	00008067          	ret

0000000000001334 <exec>:
.global exec
exec:
 li a7, SYS_exec
    1334:	00700893          	li	a7,7
 ecall
    1338:	00000073          	ecall
 ret
    133c:	00008067          	ret

0000000000001340 <open>:
.global open
open:
 li a7, SYS_open
    1340:	00f00893          	li	a7,15
 ecall
    1344:	00000073          	ecall
 ret
    1348:	00008067          	ret

000000000000134c <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
    134c:	01100893          	li	a7,17
 ecall
    1350:	00000073          	ecall
 ret
    1354:	00008067          	ret

0000000000001358 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
    1358:	01200893          	li	a7,18
 ecall
    135c:	00000073          	ecall
 ret
    1360:	00008067          	ret

0000000000001364 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
    1364:	00800893          	li	a7,8
 ecall
    1368:	00000073          	ecall
 ret
    136c:	00008067          	ret

0000000000001370 <link>:
.global link
link:
 li a7, SYS_link
    1370:	01300893          	li	a7,19
 ecall
    1374:	00000073          	ecall
 ret
    1378:	00008067          	ret

000000000000137c <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
    137c:	01400893          	li	a7,20
 ecall
    1380:	00000073          	ecall
 ret
    1384:	00008067          	ret

0000000000001388 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
    1388:	00900893          	li	a7,9
 ecall
    138c:	00000073          	ecall
 ret
    1390:	00008067          	ret

0000000000001394 <dup>:
.global dup
dup:
 li a7, SYS_dup
    1394:	00a00893          	li	a7,10
 ecall
    1398:	00000073          	ecall
 ret
    139c:	00008067          	ret

00000000000013a0 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
    13a0:	00b00893          	li	a7,11
 ecall
    13a4:	00000073          	ecall
 ret
    13a8:	00008067          	ret

00000000000013ac <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
    13ac:	00c00893          	li	a7,12
 ecall
    13b0:	00000073          	ecall
 ret
    13b4:	00008067          	ret

00000000000013b8 <pause>:
.global pause
pause:
 li a7, SYS_pause
    13b8:	00d00893          	li	a7,13
 ecall
    13bc:	00000073          	ecall
 ret
    13c0:	00008067          	ret

00000000000013c4 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
    13c4:	00e00893          	li	a7,14
 ecall
    13c8:	00000073          	ecall
 ret
    13cc:	00008067          	ret

00000000000013d0 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
    13d0:	00001617          	auipc	a2,0x1
    13d4:	c5062603          	lw	a2,-944(a2) # 2020 <putc_n>
    13d8:	00c04463          	bgtz	a2,13e0 <putc_flush+0x10>
    13dc:	00008067          	ret
{
    13e0:	ff010113          	addi	sp,sp,-16
    13e4:	00113423          	sd	ra,8(sp)
    13e8:	00813023          	sd	s0,0(sp)
    13ec:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
    13f0:	00001597          	auipc	a1,0x1
    13f4:	ca858593          	addi	a1,a1,-856 # 2098 <putc_buf>
    13f8:	00001517          	auipc	a0,0x1
    13fc:	c1852503          	lw	a0,-1000(a0) # 2010 <putc_fd>
    1400:	f11ff0ef          	jal	1310 <write>
    putc_n = 0;
    1404:	00001797          	auipc	a5,0x1
    1408:	c007ae23          	sw	zero,-996(a5) # 2020 <putc_n>
  }
}
    140c:	00813083          	ld	ra,8(sp)
    1410:	00013403          	ld	s0,0(sp)
    1414:	01010113          	addi	sp,sp,16
    1418:	00008067          	ret

000000000000141c <putc>:

static void
putc(int fd, char c)
{
    141c:	fe010113          	addi	sp,sp,-32
    1420:	00113c23          	sd	ra,24(sp)
    1424:	00813823          	sd	s0,16(sp)
    1428:	00913423          	sd	s1,8(sp)
    142c:	02010413          	addi	s0,sp,32
    1430:	00058493          	mv	s1,a1
  if (putc_fd != fd)
    1434:	00001797          	auipc	a5,0x1
    1438:	bdc7a783          	lw	a5,-1060(a5) # 2010 <putc_fd>
    143c:	04a79663          	bne	a5,a0,1488 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
    1440:	00001717          	auipc	a4,0x1
    1444:	be070713          	addi	a4,a4,-1056 # 2020 <putc_n>
    1448:	00072683          	lw	a3,0(a4)
    144c:	0016879b          	addiw	a5,a3,1
    1450:	00f72023          	sw	a5,0(a4)
    1454:	00001717          	auipc	a4,0x1
    1458:	c4470713          	addi	a4,a4,-956 # 2098 <putc_buf>
    145c:	00d70733          	add	a4,a4,a3
    1460:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
    1464:	ff648493          	addi	s1,s1,-10
    1468:	02048e63          	beqz	s1,14a4 <putc+0x88>
    146c:	f8078793          	addi	a5,a5,-128
    1470:	02078a63          	beqz	a5,14a4 <putc+0x88>
    putc_flush();
}
    1474:	01813083          	ld	ra,24(sp)
    1478:	01013403          	ld	s0,16(sp)
    147c:	00813483          	ld	s1,8(sp)
    1480:	02010113          	addi	sp,sp,32
    1484:	00008067          	ret
    1488:	01213023          	sd	s2,0(sp)
    148c:	00050913          	mv	s2,a0
    putc_flush();
    1490:	f41ff0ef          	jal	13d0 <putc_flush>
    putc_fd = fd;
    1494:	00001797          	auipc	a5,0x1
    1498:	b727ae23          	sw	s2,-1156(a5) # 2010 <putc_fd>
    149c:	00013903          	ld	s2,0(sp)
    14a0:	fa1ff06f          	j	1440 <putc+0x24>
    putc_flush();
    14a4:	f2dff0ef          	jal	13d0 <putc_flush>
}
    14a8:	fcdff06f          	j	1474 <putc+0x58>

00000000000014ac <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
    14ac:	fb010113          	addi	sp,sp,-80
    14b0:	04113423          	sd	ra,72(sp)
    14b4:	04813023          	sd	s0,64(sp)
    14b8:	03213823          	sd	s2,48(sp)
    14bc:	03313423          	sd	s3,40(sp)
    14c0:	05010413          	addi	s0,sp,80
    14c4:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
    14c8:	0a068e63          	beqz	a3,1584 <printint+0xd8>
    14cc:	0a05dc63          	bgez	a1,1584 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
    14d0:	40b005b3          	neg	a1,a1
    neg = 1;
    14d4:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
    14d8:	fb840993          	addi	s3,s0,-72
  neg = 0;
    14dc:	00098693          	mv	a3,s3
  i = 0;
    14e0:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
    14e4:	00001817          	auipc	a6,0x1
    14e8:	89480813          	addi	a6,a6,-1900 # 1d78 <digits>
    14ec:	00070893          	mv	a7,a4
    14f0:	0017051b          	addiw	a0,a4,1
    14f4:	00050713          	mv	a4,a0
    14f8:	02c5f7b3          	remu	a5,a1,a2
    14fc:	00f807b3          	add	a5,a6,a5
    1500:	0007c783          	lbu	a5,0(a5)
    1504:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
    1508:	00058793          	mv	a5,a1
    150c:	02c5d5b3          	divu	a1,a1,a2
    1510:	00168693          	addi	a3,a3,1
    1514:	fcc7fce3          	bgeu	a5,a2,14ec <printint+0x40>
  if (neg)
    1518:	00030c63          	beqz	t1,1530 <printint+0x84>
    buf[i++] = '-';
    151c:	fd050793          	addi	a5,a0,-48
    1520:	00878533          	add	a0,a5,s0
    1524:	02d00793          	li	a5,45
    1528:	fef50423          	sb	a5,-24(a0)
    152c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
    1530:	02e05e63          	blez	a4,156c <printint+0xc0>
    1534:	02913c23          	sd	s1,56(sp)
    1538:	fff7071b          	addiw	a4,a4,-1
    153c:	00e984b3          	add	s1,s3,a4
    1540:	fff98993          	addi	s3,s3,-1
    1544:	00e989b3          	add	s3,s3,a4
    1548:	02071713          	slli	a4,a4,0x20
    154c:	02075713          	srli	a4,a4,0x20
    1550:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
    1554:	0004c583          	lbu	a1,0(s1)
    1558:	00090513          	mv	a0,s2
    155c:	ec1ff0ef          	jal	141c <putc>
  while (--i >= 0)
    1560:	fff48493          	addi	s1,s1,-1
    1564:	ff3498e3          	bne	s1,s3,1554 <printint+0xa8>
    1568:	03813483          	ld	s1,56(sp)
}
    156c:	04813083          	ld	ra,72(sp)
    1570:	04013403          	ld	s0,64(sp)
    1574:	03013903          	ld	s2,48(sp)
    1578:	02813983          	ld	s3,40(sp)
    157c:	05010113          	addi	sp,sp,80
    1580:	00008067          	ret
  neg = 0;
    1584:	00000313          	li	t1,0
    1588:	f51ff06f          	j	14d8 <printint+0x2c>

000000000000158c <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
    158c:	fa010113          	addi	sp,sp,-96
    1590:	04113c23          	sd	ra,88(sp)
    1594:	04813823          	sd	s0,80(sp)
    1598:	04913423          	sd	s1,72(sp)
    159c:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
    15a0:	0005c483          	lbu	s1,0(a1)
    15a4:	32048263          	beqz	s1,18c8 <vprintf+0x33c>
    15a8:	05213023          	sd	s2,64(sp)
    15ac:	03313c23          	sd	s3,56(sp)
    15b0:	03413823          	sd	s4,48(sp)
    15b4:	03513423          	sd	s5,40(sp)
    15b8:	03613023          	sd	s6,32(sp)
    15bc:	01713c23          	sd	s7,24(sp)
    15c0:	01813823          	sd	s8,16(sp)
    15c4:	00050b13          	mv	s6,a0
    15c8:	00058a13          	mv	s4,a1
    15cc:	00060b93          	mv	s7,a2
  state = 0;
    15d0:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
    15d4:	00000913          	li	s2,0
    15d8:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
    15dc:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
    15e0:	06400c13          	li	s8,100
    15e4:	0300006f          	j	1614 <vprintf+0x88>
        putc(fd, c0);
    15e8:	00048593          	mv	a1,s1
    15ec:	000b0513          	mv	a0,s6
    15f0:	e2dff0ef          	jal	141c <putc>
    15f4:	0080006f          	j	15fc <vprintf+0x70>
    else if (state == '%')
    15f8:	03598863          	beq	s3,s5,1628 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
    15fc:	0019079b          	addiw	a5,s2,1
    1600:	00078913          	mv	s2,a5
    1604:	00078713          	mv	a4,a5
    1608:	00fa07b3          	add	a5,s4,a5
    160c:	0007c483          	lbu	s1,0(a5)
    1610:	28048e63          	beqz	s1,18ac <vprintf+0x320>
    c0 = fmt[i] & 0xff;
    1614:	0004879b          	sext.w	a5,s1
    if (state == 0)
    1618:	fe0990e3          	bnez	s3,15f8 <vprintf+0x6c>
      if (c0 == '%')
    161c:	fd5796e3          	bne	a5,s5,15e8 <vprintf+0x5c>
        state = '%';
    1620:	00078993          	mv	s3,a5
    1624:	fd9ff06f          	j	15fc <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
    1628:	00ea06b3          	add	a3,s4,a4
    162c:	0016c603          	lbu	a2,1(a3)
      if (c1)
    1630:	2a060663          	beqz	a2,18dc <vprintf+0x350>
      if (c0 == 'd')
    1634:	05878063          	beq	a5,s8,1674 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
    1638:	f9478693          	addi	a3,a5,-108
    163c:	0016b693          	seqz	a3,a3
    1640:	f9c60593          	addi	a1,a2,-100
    1644:	04059a63          	bnez	a1,1698 <vprintf+0x10c>
    1648:	04068863          	beqz	a3,1698 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
    164c:	008b8493          	addi	s1,s7,8
    1650:	00100693          	li	a3,1
    1654:	00a00613          	li	a2,10
    1658:	000bb583          	ld	a1,0(s7)
    165c:	000b0513          	mv	a0,s6
    1660:	e4dff0ef          	jal	14ac <printint>
        i += 1;
    1664:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
    1668:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
    166c:	00000993          	li	s3,0
    1670:	f8dff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
    1674:	008b8493          	addi	s1,s7,8
    1678:	00100693          	li	a3,1
    167c:	00a00613          	li	a2,10
    1680:	000ba583          	lw	a1,0(s7)
    1684:	000b0513          	mv	a0,s6
    1688:	e25ff0ef          	jal	14ac <printint>
    168c:	00048b93          	mv	s7,s1
      state = 0;
    1690:	00000993          	li	s3,0
    1694:	f69ff06f          	j	15fc <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
    1698:	00ea0733          	add	a4,s4,a4
    169c:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    16a0:	f9460713          	addi	a4,a2,-108
    16a4:	00173713          	seqz	a4,a4
    16a8:	00e6f733          	and	a4,a3,a4
    16ac:	f9c58513          	addi	a0,a1,-100
    16b0:	24051263          	bnez	a0,18f4 <vprintf+0x368>
    16b4:	24070063          	beqz	a4,18f4 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
    16b8:	008b8493          	addi	s1,s7,8
    16bc:	00100693          	li	a3,1
    16c0:	00a00613          	li	a2,10
    16c4:	000bb583          	ld	a1,0(s7)
    16c8:	000b0513          	mv	a0,s6
    16cc:	de1ff0ef          	jal	14ac <printint>
        i += 2;
    16d0:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
    16d4:	00048b93          	mv	s7,s1
      state = 0;
    16d8:	00000993          	li	s3,0
        i += 2;
    16dc:	f21ff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
    16e0:	008b8493          	addi	s1,s7,8
    16e4:	00000693          	li	a3,0
    16e8:	00a00613          	li	a2,10
    16ec:	000be583          	lwu	a1,0(s7)
    16f0:	000b0513          	mv	a0,s6
    16f4:	db9ff0ef          	jal	14ac <printint>
    16f8:	00048b93          	mv	s7,s1
      state = 0;
    16fc:	00000993          	li	s3,0
    1700:	efdff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    1704:	008b8493          	addi	s1,s7,8
    1708:	00000693          	li	a3,0
    170c:	00a00613          	li	a2,10
    1710:	000bb583          	ld	a1,0(s7)
    1714:	000b0513          	mv	a0,s6
    1718:	d95ff0ef          	jal	14ac <printint>
        i += 1;
    171c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
    1720:	00048b93          	mv	s7,s1
      state = 0;
    1724:	00000993          	li	s3,0
    1728:	ed5ff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    172c:	008b8493          	addi	s1,s7,8
    1730:	00000693          	li	a3,0
    1734:	00a00613          	li	a2,10
    1738:	000bb583          	ld	a1,0(s7)
    173c:	000b0513          	mv	a0,s6
    1740:	d6dff0ef          	jal	14ac <printint>
        i += 2;
    1744:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
    1748:	00048b93          	mv	s7,s1
      state = 0;
    174c:	00000993          	li	s3,0
        i += 2;
    1750:	eadff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
    1754:	008b8493          	addi	s1,s7,8
    1758:	00000693          	li	a3,0
    175c:	01000613          	li	a2,16
    1760:	000be583          	lwu	a1,0(s7)
    1764:	000b0513          	mv	a0,s6
    1768:	d45ff0ef          	jal	14ac <printint>
    176c:	00048b93          	mv	s7,s1
      state = 0;
    1770:	00000993          	li	s3,0
    1774:	e89ff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    1778:	008b8493          	addi	s1,s7,8
    177c:	00000693          	li	a3,0
    1780:	01000613          	li	a2,16
    1784:	000bb583          	ld	a1,0(s7)
    1788:	000b0513          	mv	a0,s6
    178c:	d21ff0ef          	jal	14ac <printint>
        i += 1;
    1790:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
    1794:	00048b93          	mv	s7,s1
      state = 0;
    1798:	00000993          	li	s3,0
    179c:	e61ff06f          	j	15fc <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    17a0:	008b8493          	addi	s1,s7,8
    17a4:	00000693          	li	a3,0
    17a8:	01000613          	li	a2,16
    17ac:	000bb583          	ld	a1,0(s7)
    17b0:	000b0513          	mv	a0,s6
    17b4:	cf9ff0ef          	jal	14ac <printint>
        i += 2;
    17b8:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
    17bc:	00048b93          	mv	s7,s1
      state = 0;
    17c0:	00000993          	li	s3,0
        i += 2;
    17c4:	e39ff06f          	j	15fc <vprintf+0x70>
    17c8:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
    17cc:	008b8793          	addi	a5,s7,8
    17d0:	00078c93          	mv	s9,a5
    17d4:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
    17d8:	03000593          	li	a1,48
    17dc:	000b0513          	mv	a0,s6
    17e0:	c3dff0ef          	jal	141c <putc>
  putc(fd, 'x');
    17e4:	07800593          	li	a1,120
    17e8:	000b0513          	mv	a0,s6
    17ec:	c31ff0ef          	jal	141c <putc>
    17f0:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
    17f4:	00000b97          	auipc	s7,0x0
    17f8:	584b8b93          	addi	s7,s7,1412 # 1d78 <digits>
    17fc:	03c9d793          	srli	a5,s3,0x3c
    1800:	00fb87b3          	add	a5,s7,a5
    1804:	0007c583          	lbu	a1,0(a5)
    1808:	000b0513          	mv	a0,s6
    180c:	c11ff0ef          	jal	141c <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
    1810:	00499993          	slli	s3,s3,0x4
    1814:	fff4849b          	addiw	s1,s1,-1
    1818:	fe0492e3          	bnez	s1,17fc <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
    181c:	000c8b93          	mv	s7,s9
      state = 0;
    1820:	00000993          	li	s3,0
    1824:	00813c83          	ld	s9,8(sp)
    1828:	dd5ff06f          	j	15fc <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
    182c:	008b8493          	addi	s1,s7,8
    1830:	000bc583          	lbu	a1,0(s7)
    1834:	000b0513          	mv	a0,s6
    1838:	be5ff0ef          	jal	141c <putc>
    183c:	00048b93          	mv	s7,s1
      state = 0;
    1840:	00000993          	li	s3,0
    1844:	db9ff06f          	j	15fc <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    1848:	008b8993          	addi	s3,s7,8
    184c:	000bb483          	ld	s1,0(s7)
    1850:	02048663          	beqz	s1,187c <vprintf+0x2f0>
        for (; *s; s++)
    1854:	0004c583          	lbu	a1,0(s1)
    1858:	04058463          	beqz	a1,18a0 <vprintf+0x314>
          putc(fd, *s);
    185c:	000b0513          	mv	a0,s6
    1860:	bbdff0ef          	jal	141c <putc>
        for (; *s; s++)
    1864:	00148493          	addi	s1,s1,1
    1868:	0004c583          	lbu	a1,0(s1)
    186c:	fe0598e3          	bnez	a1,185c <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
    1870:	00098b93          	mv	s7,s3
      state = 0;
    1874:	00000993          	li	s3,0
    1878:	d85ff06f          	j	15fc <vprintf+0x70>
          s = "(null)";
    187c:	00000497          	auipc	s1,0x0
    1880:	4c448493          	addi	s1,s1,1220 # 1d40 <malloc+0x27c>
        for (; *s; s++)
    1884:	02800593          	li	a1,40
    1888:	fd5ff06f          	j	185c <vprintf+0x2d0>
        putc(fd, '%');
    188c:	00078593          	mv	a1,a5
    1890:	000b0513          	mv	a0,s6
    1894:	b89ff0ef          	jal	141c <putc>
      state = 0;
    1898:	00000993          	li	s3,0
    189c:	d61ff06f          	j	15fc <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    18a0:	00098b93          	mv	s7,s3
      state = 0;
    18a4:	00000993          	li	s3,0
    18a8:	d55ff06f          	j	15fc <vprintf+0x70>
    18ac:	04013903          	ld	s2,64(sp)
    18b0:	03813983          	ld	s3,56(sp)
    18b4:	03013a03          	ld	s4,48(sp)
    18b8:	02813a83          	ld	s5,40(sp)
    18bc:	02013b03          	ld	s6,32(sp)
    18c0:	01813b83          	ld	s7,24(sp)
    18c4:	01013c03          	ld	s8,16(sp)
    }
  }
}
    18c8:	05813083          	ld	ra,88(sp)
    18cc:	05013403          	ld	s0,80(sp)
    18d0:	04813483          	ld	s1,72(sp)
    18d4:	06010113          	addi	sp,sp,96
    18d8:	00008067          	ret
      if (c0 == 'd')
    18dc:	06400713          	li	a4,100
    18e0:	d8e78ae3          	beq	a5,a4,1674 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
    18e4:	f9478693          	addi	a3,a5,-108
    18e8:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
    18ec:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    18f0:	00000713          	li	a4,0
      else if (c0 == 'u')
    18f4:	07500513          	li	a0,117
    18f8:	dea784e3          	beq	a5,a0,16e0 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
    18fc:	f8b60513          	addi	a0,a2,-117
    1900:	00051463          	bnez	a0,1908 <vprintf+0x37c>
    1904:	e00690e3          	bnez	a3,1704 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
    1908:	f8b58513          	addi	a0,a1,-117
    190c:	00051463          	bnez	a0,1914 <vprintf+0x388>
    1910:	e0071ee3          	bnez	a4,172c <vprintf+0x1a0>
      else if (c0 == 'x')
    1914:	07800513          	li	a0,120
    1918:	e2a78ee3          	beq	a5,a0,1754 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
    191c:	f8860613          	addi	a2,a2,-120
    1920:	00061463          	bnez	a2,1928 <vprintf+0x39c>
    1924:	e4069ae3          	bnez	a3,1778 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
    1928:	f8858593          	addi	a1,a1,-120
    192c:	00059463          	bnez	a1,1934 <vprintf+0x3a8>
    1930:	e60718e3          	bnez	a4,17a0 <vprintf+0x214>
      else if (c0 == 'p')
    1934:	07000713          	li	a4,112
    1938:	e8e788e3          	beq	a5,a4,17c8 <vprintf+0x23c>
      else if (c0 == 'c')
    193c:	06300713          	li	a4,99
    1940:	eee786e3          	beq	a5,a4,182c <vprintf+0x2a0>
      else if (c0 == 's')
    1944:	07300713          	li	a4,115
    1948:	f0e780e3          	beq	a5,a4,1848 <vprintf+0x2bc>
      else if (c0 == '%')
    194c:	02500713          	li	a4,37
    1950:	f2e78ee3          	beq	a5,a4,188c <vprintf+0x300>
        putc(fd, '%');
    1954:	02500593          	li	a1,37
    1958:	000b0513          	mv	a0,s6
    195c:	ac1ff0ef          	jal	141c <putc>
        putc(fd, c0);
    1960:	00048593          	mv	a1,s1
    1964:	000b0513          	mv	a0,s6
    1968:	ab5ff0ef          	jal	141c <putc>
      state = 0;
    196c:	00000993          	li	s3,0
    1970:	c8dff06f          	j	15fc <vprintf+0x70>

0000000000001974 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
    1974:	fb010113          	addi	sp,sp,-80
    1978:	00113c23          	sd	ra,24(sp)
    197c:	00813823          	sd	s0,16(sp)
    1980:	02010413          	addi	s0,sp,32
    1984:	00c43023          	sd	a2,0(s0)
    1988:	00d43423          	sd	a3,8(s0)
    198c:	00e43823          	sd	a4,16(s0)
    1990:	00f43c23          	sd	a5,24(s0)
    1994:	03043023          	sd	a6,32(s0)
    1998:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
    199c:	00040613          	mv	a2,s0
    19a0:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
    19a4:	be9ff0ef          	jal	158c <vprintf>
}
    19a8:	01813083          	ld	ra,24(sp)
    19ac:	01013403          	ld	s0,16(sp)
    19b0:	05010113          	addi	sp,sp,80
    19b4:	00008067          	ret

00000000000019b8 <printf>:

void printf(const char *fmt, ...)
{
    19b8:	fa010113          	addi	sp,sp,-96
    19bc:	00113c23          	sd	ra,24(sp)
    19c0:	00813823          	sd	s0,16(sp)
    19c4:	02010413          	addi	s0,sp,32
    19c8:	00b43423          	sd	a1,8(s0)
    19cc:	00c43823          	sd	a2,16(s0)
    19d0:	00d43c23          	sd	a3,24(s0)
    19d4:	02e43023          	sd	a4,32(s0)
    19d8:	02f43423          	sd	a5,40(s0)
    19dc:	03043823          	sd	a6,48(s0)
    19e0:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
    19e4:	00840613          	addi	a2,s0,8
    19e8:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
    19ec:	00050593          	mv	a1,a0
    19f0:	00100513          	li	a0,1
    19f4:	b99ff0ef          	jal	158c <vprintf>
  putc_flush();
    19f8:	9d9ff0ef          	jal	13d0 <putc_flush>
}
    19fc:	01813083          	ld	ra,24(sp)
    1a00:	01013403          	ld	s0,16(sp)
    1a04:	06010113          	addi	sp,sp,96
    1a08:	00008067          	ret

0000000000001a0c <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
    1a0c:	ff010113          	addi	sp,sp,-16
    1a10:	00113423          	sd	ra,8(sp)
    1a14:	00813023          	sd	s0,0(sp)
    1a18:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
    1a1c:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1a20:	00000797          	auipc	a5,0x0
    1a24:	6087b783          	ld	a5,1544(a5) # 2028 <freep>
    1a28:	0140006f          	j	1a3c <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    1a2c:	0007b703          	ld	a4,0(a5)
    1a30:	00e7e463          	bltu	a5,a4,1a38 <free+0x2c>
    1a34:	00e6ec63          	bltu	a3,a4,1a4c <free+0x40>
{
    1a38:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1a3c:	fed7f8e3          	bgeu	a5,a3,1a2c <free+0x20>
    1a40:	0007b703          	ld	a4,0(a5)
    1a44:	00e6e463          	bltu	a3,a4,1a4c <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    1a48:	fee7e8e3          	bltu	a5,a4,1a38 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
    1a4c:	ff852583          	lw	a1,-8(a0)
    1a50:	0007b603          	ld	a2,0(a5)
    1a54:	02059813          	slli	a6,a1,0x20
    1a58:	01c85713          	srli	a4,a6,0x1c
    1a5c:	00e68733          	add	a4,a3,a4
    1a60:	02e60c63          	beq	a2,a4,1a98 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
    1a64:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    1a68:	0087a603          	lw	a2,8(a5)
    1a6c:	02061593          	slli	a1,a2,0x20
    1a70:	01c5d713          	srli	a4,a1,0x1c
    1a74:	00e78733          	add	a4,a5,a4
    1a78:	02e68c63          	beq	a3,a4,1ab0 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
    1a7c:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
    1a80:	00000717          	auipc	a4,0x0
    1a84:	5af73423          	sd	a5,1448(a4) # 2028 <freep>
}
    1a88:	00813083          	ld	ra,8(sp)
    1a8c:	00013403          	ld	s0,0(sp)
    1a90:	01010113          	addi	sp,sp,16
    1a94:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
    1a98:	00862703          	lw	a4,8(a2)
    1a9c:	00b7073b          	addw	a4,a4,a1
    1aa0:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
    1aa4:	0007b703          	ld	a4,0(a5)
    1aa8:	00073603          	ld	a2,0(a4)
    1aac:	fb9ff06f          	j	1a64 <free+0x58>
    p->s.size += bp->s.size;
    1ab0:	ff852703          	lw	a4,-8(a0)
    1ab4:	00c7073b          	addw	a4,a4,a2
    1ab8:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
    1abc:	ff053683          	ld	a3,-16(a0)
    1ac0:	fbdff06f          	j	1a7c <free+0x70>

0000000000001ac4 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
    1ac4:	fc010113          	addi	sp,sp,-64
    1ac8:	02113c23          	sd	ra,56(sp)
    1acc:	02813823          	sd	s0,48(sp)
    1ad0:	03213023          	sd	s2,32(sp)
    1ad4:	01313c23          	sd	s3,24(sp)
    1ad8:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    1adc:	02051993          	slli	s3,a0,0x20
    1ae0:	0209d993          	srli	s3,s3,0x20
    1ae4:	00f98993          	addi	s3,s3,15
    1ae8:	0049d993          	srli	s3,s3,0x4
    1aec:	0019899b          	addiw	s3,s3,1
    1af0:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
    1af4:	00000517          	auipc	a0,0x0
    1af8:	53453503          	ld	a0,1332(a0) # 2028 <freep>
    1afc:	04050463          	beqz	a0,1b44 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1b00:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1b04:	0087a703          	lw	a4,8(a5)
    1b08:	0d377a63          	bgeu	a4,s3,1bdc <malloc+0x118>
    1b0c:	02913423          	sd	s1,40(sp)
    1b10:	01413823          	sd	s4,16(sp)
    1b14:	01513423          	sd	s5,8(sp)
    1b18:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
    1b1c:	00098a13          	mv	s4,s3
    1b20:	00001737          	lui	a4,0x1
    1b24:	00e9f463          	bgeu	s3,a4,1b2c <malloc+0x68>
    1b28:	00001a37          	lui	s4,0x1
    1b2c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
    1b30:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    1b34:	00000497          	auipc	s1,0x0
    1b38:	4f448493          	addi	s1,s1,1268 # 2028 <freep>
  if(p == SBRK_ERROR)
    1b3c:	fff00a93          	li	s5,-1
    1b40:	05c0006f          	j	1b9c <malloc+0xd8>
    1b44:	02913423          	sd	s1,40(sp)
    1b48:	01413823          	sd	s4,16(sp)
    1b4c:	01513423          	sd	s5,8(sp)
    1b50:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
    1b54:	00000797          	auipc	a5,0x0
    1b58:	5c478793          	addi	a5,a5,1476 # 2118 <base>
    1b5c:	00000717          	auipc	a4,0x0
    1b60:	4cf73623          	sd	a5,1228(a4) # 2028 <freep>
    1b64:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
    1b68:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
    1b6c:	fb1ff06f          	j	1b1c <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
    1b70:	0007b703          	ld	a4,0(a5)
    1b74:	00e53023          	sd	a4,0(a0)
    1b78:	0800006f          	j	1bf8 <malloc+0x134>
  hp->s.size = nu;
    1b7c:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
    1b80:	01050513          	addi	a0,a0,16
    1b84:	e89ff0ef          	jal	1a0c <free>
  return freep;
    1b88:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    1b8c:	08050863          	beqz	a0,1c1c <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1b90:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1b94:	0087a703          	lw	a4,8(a5)
    1b98:	03277a63          	bgeu	a4,s2,1bcc <malloc+0x108>
    if(p == freep)
    1b9c:	0004b703          	ld	a4,0(s1)
    1ba0:	00078513          	mv	a0,a5
    1ba4:	fef716e3          	bne	a4,a5,1b90 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    1ba8:	000a0513          	mv	a0,s4
    1bac:	ed8ff0ef          	jal	1284 <sbrk>
  if(p == SBRK_ERROR)
    1bb0:	fd5516e3          	bne	a0,s5,1b7c <malloc+0xb8>
        return 0;
    1bb4:	00000513          	li	a0,0
    1bb8:	02813483          	ld	s1,40(sp)
    1bbc:	01013a03          	ld	s4,16(sp)
    1bc0:	00813a83          	ld	s5,8(sp)
    1bc4:	00013b03          	ld	s6,0(sp)
    1bc8:	03c0006f          	j	1c04 <malloc+0x140>
    1bcc:	02813483          	ld	s1,40(sp)
    1bd0:	01013a03          	ld	s4,16(sp)
    1bd4:	00813a83          	ld	s5,8(sp)
    1bd8:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    1bdc:	f8e90ae3          	beq	s2,a4,1b70 <malloc+0xac>
        p->s.size -= nunits;
    1be0:	4137073b          	subw	a4,a4,s3
    1be4:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    1be8:	02071693          	slli	a3,a4,0x20
    1bec:	01c6d713          	srli	a4,a3,0x1c
    1bf0:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    1bf4:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    1bf8:	00000717          	auipc	a4,0x0
    1bfc:	42a73823          	sd	a0,1072(a4) # 2028 <freep>
      return (void*)(p + 1);
    1c00:	01078513          	addi	a0,a5,16
  }
}
    1c04:	03813083          	ld	ra,56(sp)
    1c08:	03013403          	ld	s0,48(sp)
    1c0c:	02013903          	ld	s2,32(sp)
    1c10:	01813983          	ld	s3,24(sp)
    1c14:	04010113          	addi	sp,sp,64
    1c18:	00008067          	ret
    1c1c:	02813483          	ld	s1,40(sp)
    1c20:	01013a03          	ld	s4,16(sp)
    1c24:	00813a83          	ld	s5,8(sp)
    1c28:	00013b03          	ld	s6,0(sp)
    1c2c:	fd9ff06f          	j	1c04 <malloc+0x140>
