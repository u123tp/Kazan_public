
user/_2048:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <xorshift64>:

// ---- 小さな乱数 (xorshift64) ----
static uint64 rng_state;

static uint64 xorshift64(void)
{
       0:	ff010113          	addi	sp,sp,-16
       4:	00113423          	sd	ra,8(sp)
       8:	00813023          	sd	s0,0(sp)
       c:	01010413          	addi	s0,sp,16
    uint64 x = rng_state;
      10:	00002697          	auipc	a3,0x2
      14:	00068693          	mv	a3,a3
      18:	0006b783          	ld	a5,0(a3) # 2010 <rng_state>
    x ^= x << 13;
      1c:	00d79713          	slli	a4,a5,0xd
      20:	00f74733          	xor	a4,a4,a5
    x ^= x >> 7;
      24:	00775793          	srli	a5,a4,0x7
      28:	00e7c7b3          	xor	a5,a5,a4
    x ^= x << 17;
      2c:	01179513          	slli	a0,a5,0x11
      30:	00f54533          	xor	a0,a0,a5
    rng_state = x;
      34:	00a6b023          	sd	a0,0(a3)
    return x;
}
      38:	00813083          	ld	ra,8(sp)
      3c:	00013403          	ld	s0,0(sp)
      40:	01010113          	addi	sp,sp,16
      44:	00008067          	ret

0000000000000048 <clear_board>:
    return (int)(xorshift64() % (uint64)mod);
}

// ---- 盤面ユーティリティ ----
static void clear_board(void)
{
      48:	ff010113          	addi	sp,sp,-16
      4c:	00113423          	sd	ra,8(sp)
      50:	00813023          	sd	s0,0(sp)
      54:	01010413          	addi	s0,sp,16
    for (int y = 0; y < N; y++)
      58:	00002797          	auipc	a5,0x2
      5c:	fd878793          	addi	a5,a5,-40 # 2030 <board>
      60:	00002717          	auipc	a4,0x2
      64:	01070713          	addi	a4,a4,16 # 2070 <putc_buf>
        for (int x = 0; x < N; x++)
            board[y][x] = 0;
      68:	0007a023          	sw	zero,0(a5)
      6c:	0007a223          	sw	zero,4(a5)
      70:	0007a423          	sw	zero,8(a5)
      74:	0007a623          	sw	zero,12(a5)
    for (int y = 0; y < N; y++)
      78:	01078793          	addi	a5,a5,16
      7c:	fee796e3          	bne	a5,a4,68 <clear_board+0x20>
    score = 0;
      80:	00002797          	auipc	a5,0x2
      84:	f807ac23          	sw	zero,-104(a5) # 2018 <score>
}
      88:	00813083          	ld	ra,8(sp)
      8c:	00013403          	ld	s0,0(sp)
      90:	01010113          	addi	sp,sp,16
      94:	00008067          	ret

0000000000000098 <count_empty>:

static int count_empty(void)
{
      98:	ff010113          	addi	sp,sp,-16
      9c:	00113423          	sd	ra,8(sp)
      a0:	00813023          	sd	s0,0(sp)
      a4:	01010413          	addi	s0,sp,16
    int c = 0;
    for (int y = 0; y < N; y++)
      a8:	00002717          	auipc	a4,0x2
      ac:	f9870713          	addi	a4,a4,-104 # 2040 <board+0x10>
      b0:	00002617          	auipc	a2,0x2
      b4:	fd060613          	addi	a2,a2,-48 # 2080 <putc_buf+0x10>
    int c = 0;
      b8:	00000513          	li	a0,0
      bc:	0240006f          	j	e0 <count_empty+0x48>
        for (int x = 0; x < N; x++)
      c0:	00478793          	addi	a5,a5,4
      c4:	00e78a63          	beq	a5,a4,d8 <count_empty+0x40>
            if (board[y][x] == 0)
      c8:	0007a683          	lw	a3,0(a5)
      cc:	fe069ae3          	bnez	a3,c0 <count_empty+0x28>
                c++;
      d0:	0015051b          	addiw	a0,a0,1
      d4:	fedff06f          	j	c0 <count_empty+0x28>
    for (int y = 0; y < N; y++)
      d8:	01070713          	addi	a4,a4,16
      dc:	00c70663          	beq	a4,a2,e8 <count_empty+0x50>
        for (int x = 0; x < N; x++)
      e0:	ff070793          	addi	a5,a4,-16
      e4:	fe5ff06f          	j	c8 <count_empty+0x30>
    return c;
}
      e8:	00813083          	ld	ra,8(sp)
      ec:	00013403          	ld	s0,0(sp)
      f0:	01010113          	addi	sp,sp,16
      f4:	00008067          	ret

00000000000000f8 <slide_merge_left>:
}

// ---- 行(4要素)を左に詰めてマージする ----
// 戻り値: 変更があったら 1
static int slide_merge_left(int line[4])
{
      f8:	fc010113          	addi	sp,sp,-64
      fc:	02113c23          	sd	ra,56(sp)
     100:	02813823          	sd	s0,48(sp)
     104:	04010413          	addi	s0,sp,64
    int orig[4];
    for (int i = 0; i < 4; i++)
        orig[i] = line[i];
     108:	00052783          	lw	a5,0(a0)
     10c:	fef42023          	sw	a5,-32(s0)
     110:	00452783          	lw	a5,4(a0)
     114:	fef42223          	sw	a5,-28(s0)
     118:	00852783          	lw	a5,8(a0)
     11c:	fef42423          	sw	a5,-24(s0)
     120:	00c52783          	lw	a5,12(a0)
     124:	fef42623          	sw	a5,-20(s0)

    // compress
    int tmp[4] = {0, 0, 0, 0};
     128:	fc042823          	sw	zero,-48(s0)
     12c:	fc042a23          	sw	zero,-44(s0)
     130:	fc042c23          	sw	zero,-40(s0)
     134:	fc042e23          	sw	zero,-36(s0)
    int t = 0;
    for (int i = 0; i < 4; i++)
     138:	00050593          	mv	a1,a0
     13c:	01050613          	addi	a2,a0,16
    int t = 0;
     140:	00000693          	li	a3,0
    {
        if (line[i] != 0)
            tmp[t++] = line[i];
     144:	fd040813          	addi	a6,s0,-48
     148:	00c0006f          	j	154 <slide_merge_left+0x5c>
    for (int i = 0; i < 4; i++)
     14c:	00450513          	addi	a0,a0,4
     150:	02c50063          	beq	a0,a2,170 <slide_merge_left+0x78>
        if (line[i] != 0)
     154:	00052783          	lw	a5,0(a0)
     158:	fe078ae3          	beqz	a5,14c <slide_merge_left+0x54>
            tmp[t++] = line[i];
     15c:	00269713          	slli	a4,a3,0x2
     160:	01070733          	add	a4,a4,a6
     164:	00f72023          	sw	a5,0(a4)
     168:	0016869b          	addiw	a3,a3,1
     16c:	fe1ff06f          	j	14c <slide_merge_left+0x54>
     170:	00002897          	auipc	a7,0x2
     174:	ea88a883          	lw	a7,-344(a7) # 2018 <score>
    for (int i = 0; i < 4; i++)
     178:	00000313          	li	t1,0
    }

    // merge
    for (int i = 0; i < 3; i++)
     17c:	00000793          	li	a5,0
    {
        if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
     180:	fd040613          	addi	a2,s0,-48
        {
            tmp[i] *= 2;
            score += tmp[i];
            tmp[i + 1] = 0;
     184:	00100e13          	li	t3,1
    for (int i = 0; i < 3; i++)
     188:	00200813          	li	a6,2
     18c:	00c0006f          	j	198 <slide_merge_left+0xa0>
     190:	0017879b          	addiw	a5,a5,1
     194:	04f84a63          	blt	a6,a5,1e8 <slide_merge_left+0xf0>
        if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
     198:	00279713          	slli	a4,a5,0x2
     19c:	00c70733          	add	a4,a4,a2
     1a0:	00072703          	lw	a4,0(a4)
     1a4:	fe0706e3          	beqz	a4,190 <slide_merge_left+0x98>
     1a8:	0017851b          	addiw	a0,a5,1
     1ac:	00251693          	slli	a3,a0,0x2
     1b0:	00c686b3          	add	a3,a3,a2
     1b4:	0006a683          	lw	a3,0(a3)
     1b8:	fce69ce3          	bne	a3,a4,190 <slide_merge_left+0x98>
            tmp[i] *= 2;
     1bc:	0017171b          	slliw	a4,a4,0x1
     1c0:	00279793          	slli	a5,a5,0x2
     1c4:	00c787b3          	add	a5,a5,a2
     1c8:	00e7a023          	sw	a4,0(a5)
            score += tmp[i];
     1cc:	011708bb          	addw	a7,a4,a7
            tmp[i + 1] = 0;
     1d0:	00251793          	slli	a5,a0,0x2
     1d4:	00c787b3          	add	a5,a5,a2
     1d8:	0007a023          	sw	zero,0(a5)
            i++; // 次はスキップ
     1dc:	00050793          	mv	a5,a0
            tmp[i + 1] = 0;
     1e0:	000e0313          	mv	t1,t3
     1e4:	fadff06f          	j	190 <slide_merge_left+0x98>
     1e8:	00030663          	beqz	t1,1f4 <slide_merge_left+0xfc>
     1ec:	00002797          	auipc	a5,0x2
     1f0:	e317a623          	sw	a7,-468(a5) # 2018 <score>
        }
    }

    // compress again
    int out[4] = {0, 0, 0, 0};
     1f4:	fc042023          	sw	zero,-64(s0)
     1f8:	fc042223          	sw	zero,-60(s0)
     1fc:	fc042423          	sw	zero,-56(s0)
     200:	fc042623          	sw	zero,-52(s0)
    t = 0;
    for (int i = 0; i < 4; i++)
     204:	fd040793          	addi	a5,s0,-48
     208:	fe040513          	addi	a0,s0,-32
    t = 0;
     20c:	00000613          	li	a2,0
    {
        if (tmp[i] != 0)
            out[t++] = tmp[i];
     210:	fc040813          	addi	a6,s0,-64
     214:	00c0006f          	j	220 <slide_merge_left+0x128>
    for (int i = 0; i < 4; i++)
     218:	00478793          	addi	a5,a5,4
     21c:	02a78063          	beq	a5,a0,23c <slide_merge_left+0x144>
        if (tmp[i] != 0)
     220:	0007a703          	lw	a4,0(a5)
     224:	fe070ae3          	beqz	a4,218 <slide_merge_left+0x120>
            out[t++] = tmp[i];
     228:	00261693          	slli	a3,a2,0x2
     22c:	010686b3          	add	a3,a3,a6
     230:	00e6a023          	sw	a4,0(a3)
     234:	0016061b          	addiw	a2,a2,1
     238:	fe1ff06f          	j	218 <slide_merge_left+0x120>
     23c:	fc040713          	addi	a4,s0,-64
     240:	fe040693          	addi	a3,s0,-32
     244:	fd040813          	addi	a6,s0,-48
    }

    int changed = 0;
     248:	00000513          	li	a0,0
    for (int i = 0; i < 4; i++)
    {
        line[i] = out[i];
     24c:	00072603          	lw	a2,0(a4)
     250:	00c5a023          	sw	a2,0(a1)
        if (line[i] != orig[i])
     254:	0006a783          	lw	a5,0(a3)
     258:	40c787b3          	sub	a5,a5,a2
     25c:	00f037b3          	snez	a5,a5
     260:	00f56533          	or	a0,a0,a5
    for (int i = 0; i < 4; i++)
     264:	00470713          	addi	a4,a4,4
     268:	00458593          	addi	a1,a1,4
     26c:	00468693          	addi	a3,a3,4
     270:	fd071ee3          	bne	a4,a6,24c <slide_merge_left+0x154>
            changed = 1;
    }
    return changed;
}
     274:	03813083          	ld	ra,56(sp)
     278:	03013403          	ld	s0,48(sp)
     27c:	04010113          	addi	sp,sp,64
     280:	00008067          	ret

0000000000000284 <add_random_tile>:
{
     284:	fe010113          	addi	sp,sp,-32
     288:	00113c23          	sd	ra,24(sp)
     28c:	00813823          	sd	s0,16(sp)
     290:	02010413          	addi	s0,sp,32
    int empty = count_empty();
     294:	e05ff0ef          	jal	98 <count_empty>
    if (empty == 0)
     298:	00051a63          	bnez	a0,2ac <add_random_tile+0x28>
}
     29c:	01813083          	ld	ra,24(sp)
     2a0:	01013403          	ld	s0,16(sp)
     2a4:	02010113          	addi	sp,sp,32
     2a8:	00008067          	ret
     2ac:	00913423          	sd	s1,8(sp)
     2b0:	01213023          	sd	s2,0(sp)
     2b4:	00050493          	mv	s1,a0
        return 0;
     2b8:	00000693          	li	a3,0
    if (mod <= 0)
     2bc:	00a05863          	blez	a0,2cc <add_random_tile+0x48>
    return (int)(xorshift64() % (uint64)mod);
     2c0:	d41ff0ef          	jal	0 <xorshift64>
     2c4:	029576b3          	remu	a3,a0,s1
     2c8:	0006869b          	sext.w	a3,a3
    for (int y = 0; y < N; y++)
     2cc:	00002597          	auipc	a1,0x2
     2d0:	d6458593          	addi	a1,a1,-668 # 2030 <board>
     2d4:	00000913          	li	s2,0
        for (int x = 0; x < N; x++)
     2d8:	00400613          	li	a2,4
     2dc:	0900006f          	j	36c <add_random_tile+0xe8>
    return (int)(xorshift64() % (uint64)mod);
     2e0:	d21ff0ef          	jal	0 <xorshift64>
     2e4:	ccccd737          	lui	a4,0xccccd
     2e8:	ccd70713          	addi	a4,a4,-819 # ffffffffcccccccd <base+0xffffffffccccabdd>
     2ec:	02071793          	slli	a5,a4,0x20
     2f0:	00e787b3          	add	a5,a5,a4
     2f4:	02f537b3          	mulhu	a5,a0,a5
     2f8:	0037d793          	srli	a5,a5,0x3
     2fc:	00279713          	slli	a4,a5,0x2
     300:	00f707b3          	add	a5,a4,a5
     304:	00179793          	slli	a5,a5,0x1
                    int v = (rand_int(10) == 0) ? 4 : 2;
     308:	40f5053b          	subw	a0,a0,a5
     30c:	00200693          	li	a3,2
     310:	00051463          	bnez	a0,318 <add_random_tile+0x94>
     314:	00400693          	li	a3,4
                    board[y][x] = v;
     318:	00291793          	slli	a5,s2,0x2
     31c:	009787b3          	add	a5,a5,s1
     320:	00279793          	slli	a5,a5,0x2
     324:	00002717          	auipc	a4,0x2
     328:	d0c70713          	addi	a4,a4,-756 # 2030 <board>
     32c:	00f707b3          	add	a5,a4,a5
     330:	00d7a023          	sw	a3,0(a5)
                    return;
     334:	00813483          	ld	s1,8(sp)
     338:	00013903          	ld	s2,0(sp)
     33c:	f61ff06f          	j	29c <add_random_tile+0x18>
        for (int x = 0; x < N; x++)
     340:	0014849b          	addiw	s1,s1,1
     344:	00478793          	addi	a5,a5,4
     348:	00c48c63          	beq	s1,a2,360 <add_random_tile+0xdc>
            if (board[y][x] == 0)
     34c:	0007a703          	lw	a4,0(a5)
     350:	fe0718e3          	bnez	a4,340 <add_random_tile+0xbc>
                if (k == 0)
     354:	f80686e3          	beqz	a3,2e0 <add_random_tile+0x5c>
                k--;
     358:	fff6869b          	addiw	a3,a3,-1
     35c:	fe5ff06f          	j	340 <add_random_tile+0xbc>
    for (int y = 0; y < N; y++)
     360:	0019091b          	addiw	s2,s2,1
     364:	01058593          	addi	a1,a1,16
     368:	00c90863          	beq	s2,a2,378 <add_random_tile+0xf4>
        return 0;
     36c:	00058793          	mv	a5,a1
        for (int x = 0; x < N; x++)
     370:	00000493          	li	s1,0
     374:	fd9ff06f          	j	34c <add_random_tile+0xc8>
     378:	00813483          	ld	s1,8(sp)
     37c:	00013903          	ld	s2,0(sp)
     380:	f1dff06f          	j	29c <add_random_tile+0x18>

0000000000000384 <main>:
        return 0;
    return buf[0];
}

int main(void)
{
     384:	f7010113          	addi	sp,sp,-144
     388:	08113423          	sd	ra,136(sp)
     38c:	08813023          	sd	s0,128(sp)
     390:	06913c23          	sd	s1,120(sp)
     394:	07213823          	sd	s2,112(sp)
     398:	07313423          	sd	s3,104(sp)
     39c:	07413023          	sd	s4,96(sp)
     3a0:	05513c23          	sd	s5,88(sp)
     3a4:	05613823          	sd	s6,80(sp)
     3a8:	05713423          	sd	s7,72(sp)
     3ac:	05813023          	sd	s8,64(sp)
     3b0:	03913c23          	sd	s9,56(sp)
     3b4:	03a13823          	sd	s10,48(sp)
     3b8:	03b13423          	sd	s11,40(sp)
     3bc:	09010413          	addi	s0,sp,144
    // seed
    rng_state = ((uint64)uptime() << 32) ^ (uint64)getpid() ^ 0x9e3779b97f4a7c15ULL;
     3c0:	275000ef          	jal	e34 <uptime>
     3c4:	00050493          	mv	s1,a0
     3c8:	249000ef          	jal	e10 <getpid>
     3cc:	02049493          	slli	s1,s1,0x20
     3d0:	00a4c4b3          	xor	s1,s1,a0
     3d4:	7f4a8737          	lui	a4,0x7f4a8
     3d8:	c1570713          	addi	a4,a4,-1003 # 7f4a7c15 <base+0x7f4a5b25>
     3dc:	13c6f7b7          	lui	a5,0x13c6f
     3e0:	00379793          	slli	a5,a5,0x3
     3e4:	9b978793          	addi	a5,a5,-1607 # 13c6e9b9 <base+0x13c6c8c9>
     3e8:	02079793          	slli	a5,a5,0x20
     3ec:	00e787b3          	add	a5,a5,a4
     3f0:	00f4c7b3          	xor	a5,s1,a5
     3f4:	00002717          	auipc	a4,0x2
     3f8:	c0f73e23          	sd	a5,-996(a4) # 2010 <rng_state>
    clear_board();
     3fc:	c4dff0ef          	jal	48 <clear_board>
    add_random_tile();
     400:	e85ff0ef          	jal	284 <add_random_tile>
    add_random_tile();
     404:	e81ff0ef          	jal	284 <add_random_tile>
     408:	00100993          	li	s3,1
     40c:	40000bb7          	lui	s7,0x40000
     410:	020b9b93          	slli	s7,s7,0x20
     414:	400047b7          	lui	a5,0x40004
     418:	00fb8bb3          	add	s7,s7,a5
            if (x + 1 < N && board[y][x + 1] == v)
     41c:	00200b13          	li	s6,2
     420:	3e00006f          	j	800 <main+0x47c>
     424:	02059e63          	bnez	a1,460 <main+0xdc>
                printf("|      ");
     428:	00001517          	auipc	a0,0x1
     42c:	2f850513          	addi	a0,a0,760 # 1720 <malloc+0x1ec>
     430:	7f9000ef          	jal	1428 <printf>
        for (int x = 0; x < N; x++)
     434:	00448493          	addi	s1,s1,4
     438:	07248a63          	beq	s1,s2,4ac <main+0x128>
            int v = board[y][x];
     43c:	0004a583          	lw	a1,0(s1)
            if (v == 0)
     440:	02ba4663          	blt	s4,a1,46c <main+0xe8>
     444:	feb9d0e3          	bge	s3,a1,424 <main+0xa0>
     448:	ffe5879b          	addiw	a5,a1,-2
     44c:	00f997b3          	sll	a5,s3,a5
     450:	0177f733          	and	a4,a5,s7
     454:	04071463          	bnez	a4,49c <main+0x118>
     458:	0457f793          	andi	a5,a5,69
     45c:	02079863          	bnez	a5,48c <main+0x108>
                printf("|  %d ", v);
     460:	000c0513          	mv	a0,s8
     464:	7c5000ef          	jal	1428 <printf>
     468:	fcdff06f          	j	434 <main+0xb0>
     46c:	f805879b          	addiw	a5,a1,-128
     470:	f7f7f793          	andi	a5,a5,-129
     474:	00078663          	beqz	a5,480 <main+0xfc>
     478:	20000793          	li	a5,512
     47c:	fef592e3          	bne	a1,a5,460 <main+0xdc>
                printf("|  %d ", v);
     480:	000c0513          	mv	a0,s8
     484:	7a5000ef          	jal	1428 <printf>
     488:	fadff06f          	j	434 <main+0xb0>
                printf("|   %d  ", v);
     48c:	00001517          	auipc	a0,0x1
     490:	29c50513          	addi	a0,a0,668 # 1728 <malloc+0x1f4>
     494:	795000ef          	jal	1428 <printf>
     498:	f9dff06f          	j	434 <main+0xb0>
                printf("|  %d  ", v);
     49c:	00001517          	auipc	a0,0x1
     4a0:	29c50513          	addi	a0,a0,668 # 1738 <malloc+0x204>
     4a4:	785000ef          	jal	1428 <printf>
     4a8:	f8dff06f          	j	434 <main+0xb0>
        printf("|\n");
     4ac:	00001517          	auipc	a0,0x1
     4b0:	29c50513          	addi	a0,a0,668 # 1748 <malloc+0x214>
     4b4:	775000ef          	jal	1428 <printf>
    for (int y = 0; y < N; y++)
     4b8:	01090913          	addi	s2,s2,16
     4bc:	012d0a63          	beq	s10,s2,4d0 <main+0x14c>
        printf("+------+------+------+------+\n");
     4c0:	000c8513          	mv	a0,s9
     4c4:	765000ef          	jal	1428 <printf>
        for (int x = 0; x < N; x++)
     4c8:	ff090493          	addi	s1,s2,-16
     4cc:	f71ff06f          	j	43c <main+0xb8>
    printf("+------+------+------+------+\n");
     4d0:	00001517          	auipc	a0,0x1
     4d4:	23050513          	addi	a0,a0,560 # 1700 <malloc+0x1cc>
     4d8:	751000ef          	jal	1428 <printf>
    if (count_empty() > 0)
     4dc:	bbdff0ef          	jal	98 <count_empty>
     4e0:	2aa04a63          	bgtz	a0,794 <main+0x410>
     4e4:	01000593          	li	a1,16
    for (int y = 0; y < N; y++)
     4e8:	00000513          	li	a0,0
     4ec:	ff0a8e13          	addi	t3,s5,-16
            if (y + 1 < N && board[y + 1][x] == v)
     4f0:	00058313          	mv	t1,a1
        for (int x = 0; x < N; x++)
     4f4:	00400893          	li	a7,4
     4f8:	0400006f          	j	538 <main+0x1b4>
     4fc:	00478793          	addi	a5,a5,4 # 40004004 <base+0x40001f14>
            int v = board[y][x];
     500:	0007a603          	lw	a2,0(a5)
            if (x + 1 < N && board[y][x + 1] == v)
     504:	28eb4063          	blt	s6,a4,784 <main+0x400>
     508:	0047a683          	lw	a3,4(a5)
     50c:	28c68463          	beq	a3,a2,794 <main+0x410>
            if (y + 1 < N && board[y + 1][x] == v)
     510:	3cab4a63          	blt	s6,a0,8e4 <main+0x560>
     514:	00f806b3          	add	a3,a6,a5
     518:	00b686b3          	add	a3,a3,a1
     51c:	0006a683          	lw	a3,0(a3)
     520:	26c68a63          	beq	a3,a2,794 <main+0x410>
        for (int x = 0; x < N; x++)
     524:	0017071b          	addiw	a4,a4,1
     528:	fd171ae3          	bne	a4,a7,4fc <main+0x178>
    for (int y = 0; y < N; y++)
     52c:	0015051b          	addiw	a0,a0,1
     530:	01058593          	addi	a1,a1,16
     534:	25150a63          	beq	a0,a7,788 <main+0x404>
        for (int x = 0; x < N; x++)
     538:	00be07b3          	add	a5,t3,a1
     53c:	00000713          	li	a4,0
            if (y + 1 < N && board[y + 1][x] == v)
     540:	40b30833          	sub	a6,t1,a1
     544:	fbdff06f          	j	500 <main+0x17c>
     548:	00010637          	lui	a2,0x10
     54c:	02061693          	slli	a3,a2,0x20
     550:	00c686b3          	add	a3,a3,a2
     554:	00d77733          	and	a4,a4,a3
     558:	00070c63          	beqz	a4,570 <main+0x1ec>
                score = before_score;
            }
        }
    }

    printf("bye.\n");
     55c:	00001517          	auipc	a0,0x1
     560:	1fc50513          	addi	a0,a0,508 # 1758 <malloc+0x224>
     564:	6c5000ef          	jal	1428 <printf>
    exit(0);
     568:	00000513          	li	a0,0
     56c:	7e4000ef          	jal	d50 <exit>
     570:	fff00493          	li	s1,-1
     574:	0080006f          	j	57c <main+0x1f8>
     578:	00000493          	li	s1,0
        if (c == 'd' || c == 'l' || c == 'D' || c == 'L')
     57c:	fbc7869b          	addiw	a3,a5,-68
     580:	0ff6f693          	zext.b	a3,a3
     584:	02800713          	li	a4,40
     588:	34d76463          	bltu	a4,a3,8d0 <main+0x54c>
     58c:	10100613          	li	a2,257
     590:	02061713          	slli	a4,a2,0x20
     594:	00c70733          	add	a4,a4,a2
     598:	00d75733          	srl	a4,a4,a3
     59c:	00177713          	andi	a4,a4,1
     5a0:	00070463          	beqz	a4,5a8 <main+0x224>
     5a4:	00098493          	mv	s1,s3
        if (c == 'w' || c == 'k' || c == 'W' || c == 'K')
     5a8:	fb57869b          	addiw	a3,a5,-75
     5ac:	0ff6f693          	zext.b	a3,a3
     5b0:	02c00713          	li	a4,44
     5b4:	02d76e63          	bltu	a4,a3,5f0 <main+0x26c>
     5b8:	00001637          	lui	a2,0x1
     5bc:	00160613          	addi	a2,a2,1 # 1001 <vprintf+0x5>
     5c0:	02061713          	slli	a4,a2,0x20
     5c4:	00c70733          	add	a4,a4,a2
     5c8:	00d75733          	srl	a4,a4,a3
     5cc:	00177713          	andi	a4,a4,1
     5d0:	02070063          	beqz	a4,5f0 <main+0x26c>
        if (c == 's' || c == 'j' || c == 'S' || c == 'J')
     5d4:	fb67879b          	addiw	a5,a5,-74
     5d8:	0ff7f713          	zext.b	a4,a5
     5dc:	02900793          	li	a5,41
     5e0:	00200493          	li	s1,2
     5e4:	00e7fe63          	bgeu	a5,a4,600 <main+0x27c>
     5e8:	00200493          	li	s1,2
     5ec:	0300006f          	j	61c <main+0x298>
     5f0:	fb67879b          	addiw	a5,a5,-74
     5f4:	0ff7f713          	zext.b	a4,a5
     5f8:	02900793          	li	a5,41
     5fc:	00e7ee63          	bltu	a5,a4,618 <main+0x294>
     600:	20100693          	li	a3,513
     604:	02069793          	slli	a5,a3,0x20
     608:	00d787b3          	add	a5,a5,a3
     60c:	00e7d7b3          	srl	a5,a5,a4
     610:	0017f793          	andi	a5,a5,1
     614:	24079663          	bnez	a5,860 <main+0x4dc>
        if (dir >= 0)
     618:	1e04c463          	bltz	s1,800 <main+0x47c>
            int before_score = score;
     61c:	00002a17          	auipc	s4,0x2
     620:	9fca2a03          	lw	s4,-1540(s4) # 2018 <score>
    if (dir == 0)
     624:	06049c63          	bnez	s1,69c <main+0x318>
     628:	00002c17          	auipc	s8,0x2
     62c:	a48c0c13          	addi	s8,s8,-1464 # 2070 <putc_buf>
            if (slide_merge_left(line))
     630:	f7040913          	addi	s2,s0,-144
                line[i] = board[y][i];
     634:	000aa783          	lw	a5,0(s5)
     638:	f6f42823          	sw	a5,-144(s0)
     63c:	004aa783          	lw	a5,4(s5)
     640:	f6f42a23          	sw	a5,-140(s0)
     644:	008aa783          	lw	a5,8(s5)
     648:	f6f42c23          	sw	a5,-136(s0)
     64c:	00caa783          	lw	a5,12(s5)
     650:	f6f42e23          	sw	a5,-132(s0)
            if (slide_merge_left(line))
     654:	00090513          	mv	a0,s2
     658:	aa1ff0ef          	jal	f8 <slide_merge_left>
     65c:	00a03533          	snez	a0,a0
     660:	00a4e4b3          	or	s1,s1,a0
                board[y][i] = line[i];
     664:	f7042783          	lw	a5,-144(s0)
     668:	00faa023          	sw	a5,0(s5)
     66c:	f7442783          	lw	a5,-140(s0)
     670:	00faa223          	sw	a5,4(s5)
     674:	f7842783          	lw	a5,-136(s0)
     678:	00faa423          	sw	a5,8(s5)
     67c:	f7c42783          	lw	a5,-132(s0)
     680:	00faa623          	sw	a5,12(s5)
        for (int y = 0; y < N; y++)
     684:	010a8a93          	addi	s5,s5,16
     688:	fb8a96e3          	bne	s5,s8,634 <main+0x2b0>
            if (changed)
     68c:	0e049863          	bnez	s1,77c <main+0x3f8>
                score = before_score;
     690:	00002797          	auipc	a5,0x2
     694:	9947a423          	sw	s4,-1656(a5) # 2018 <score>
     698:	1680006f          	j	800 <main+0x47c>
    else if (dir == 1)
     69c:	00100793          	li	a5,1
     6a0:	06f49863          	bne	s1,a5,710 <main+0x38c>
     6a4:	00002c17          	auipc	s8,0x2
     6a8:	9ccc0c13          	addi	s8,s8,-1588 # 2070 <putc_buf>
    int changed = 0;
     6ac:	00000493          	li	s1,0
            if (slide_merge_left(line))
     6b0:	f7040913          	addi	s2,s0,-144
                line[i] = board[y][3 - i];
     6b4:	00caa783          	lw	a5,12(s5)
     6b8:	f6f42823          	sw	a5,-144(s0)
     6bc:	008aa783          	lw	a5,8(s5)
     6c0:	f6f42a23          	sw	a5,-140(s0)
     6c4:	004aa783          	lw	a5,4(s5)
     6c8:	f6f42c23          	sw	a5,-136(s0)
     6cc:	000aa783          	lw	a5,0(s5)
     6d0:	f6f42e23          	sw	a5,-132(s0)
            if (slide_merge_left(line))
     6d4:	00090513          	mv	a0,s2
     6d8:	a21ff0ef          	jal	f8 <slide_merge_left>
     6dc:	00a037b3          	snez	a5,a0
     6e0:	00f4e4b3          	or	s1,s1,a5
                board[y][3 - i] = line[i];
     6e4:	f7042783          	lw	a5,-144(s0)
     6e8:	00faa623          	sw	a5,12(s5)
     6ec:	f7442783          	lw	a5,-140(s0)
     6f0:	00faa423          	sw	a5,8(s5)
     6f4:	f7842783          	lw	a5,-136(s0)
     6f8:	00faa223          	sw	a5,4(s5)
     6fc:	f7c42783          	lw	a5,-132(s0)
     700:	00faa023          	sw	a5,0(s5)
        for (int y = 0; y < N; y++)
     704:	010a8a93          	addi	s5,s5,16
     708:	fb8a96e3          	bne	s5,s8,6b4 <main+0x330>
     70c:	f81ff06f          	j	68c <main+0x308>
    else if (dir == 2)
     710:	00200793          	li	a5,2
     714:	14f49a63          	bne	s1,a5,868 <main+0x4e4>
    int changed = 0;
     718:	00000493          	li	s1,0
            if (slide_merge_left(line))
     71c:	f7040913          	addi	s2,s0,-144
                line[i] = board[i][x];
     720:	000aa783          	lw	a5,0(s5)
     724:	f6f42823          	sw	a5,-144(s0)
     728:	010aa783          	lw	a5,16(s5)
     72c:	f6f42a23          	sw	a5,-140(s0)
     730:	020aa783          	lw	a5,32(s5)
     734:	f6f42c23          	sw	a5,-136(s0)
     738:	030aa783          	lw	a5,48(s5)
     73c:	f6f42e23          	sw	a5,-132(s0)
            if (slide_merge_left(line))
     740:	00090513          	mv	a0,s2
     744:	9b5ff0ef          	jal	f8 <slide_merge_left>
     748:	00a037b3          	snez	a5,a0
     74c:	00f4e4b3          	or	s1,s1,a5
                board[i][x] = line[i];
     750:	f7042783          	lw	a5,-144(s0)
     754:	00faa023          	sw	a5,0(s5)
     758:	f7442783          	lw	a5,-140(s0)
     75c:	00faa823          	sw	a5,16(s5)
     760:	f7842783          	lw	a5,-136(s0)
     764:	02faa023          	sw	a5,32(s5)
     768:	f7c42783          	lw	a5,-132(s0)
     76c:	02faa823          	sw	a5,48(s5)
        for (int x = 0; x < N; x++)
     770:	004a8a93          	addi	s5,s5,4
     774:	fbba96e3          	bne	s5,s11,720 <main+0x39c>
     778:	f15ff06f          	j	68c <main+0x308>
                add_random_tile();
     77c:	b09ff0ef          	jal	284 <add_random_tile>
     780:	0800006f          	j	800 <main+0x47c>
            if (y + 1 < N && board[y + 1][x] == v)
     784:	d8ab58e3          	bge	s6,a0,514 <main+0x190>
        printf("\nGAME OVER. (r=restart, q=quit)\n");
     788:	00001517          	auipc	a0,0x1
     78c:	fd850513          	addi	a0,a0,-40 # 1760 <malloc+0x22c>
     790:	499000ef          	jal	1428 <printf>
        printf("\n> ");
     794:	00001517          	auipc	a0,0x1
     798:	fbc50513          	addi	a0,a0,-68 # 1750 <malloc+0x21c>
     79c:	48d000ef          	jal	1428 <printf>
    if (gets(buf, sizeof(buf)) == 0)
     7a0:	02000593          	li	a1,32
     7a4:	f7040513          	addi	a0,s0,-144
     7a8:	2ac000ef          	jal	a54 <gets>
     7ac:	da0508e3          	beqz	a0,55c <main+0x1d8>
    if (buf[0] == 0)
     7b0:	f7044783          	lbu	a5,-144(s0)
        if (c == 0)
     7b4:	04078663          	beqz	a5,800 <main+0x47c>
     7b8:	fbf7871b          	addiw	a4,a5,-65
     7bc:	0ff77713          	zext.b	a4,a4
     7c0:	03100693          	li	a3,49
     7c4:	10e6e463          	bltu	a3,a4,8cc <main+0x548>
     7c8:	00e99733          	sll	a4,s3,a4
     7cc:	08100613          	li	a2,129
     7d0:	02061693          	slli	a3,a2,0x20
     7d4:	00c686b3          	add	a3,a3,a2
     7d8:	00d776b3          	and	a3,a4,a3
     7dc:	d8069ee3          	bnez	a3,578 <main+0x1f4>
     7e0:	00020637          	lui	a2,0x20
     7e4:	02061693          	slli	a3,a2,0x20
     7e8:	00c686b3          	add	a3,a3,a2
     7ec:	00d776b3          	and	a3,a4,a3
     7f0:	d4068ce3          	beqz	a3,548 <main+0x1c4>
            clear_board();
     7f4:	855ff0ef          	jal	48 <clear_board>
            add_random_tile();
     7f8:	a8dff0ef          	jal	284 <add_random_tile>
            add_random_tile();
     7fc:	a89ff0ef          	jal	284 <add_random_tile>
    printf("\x1b[H\x1b[2J");
     800:	00001517          	auipc	a0,0x1
     804:	ea050513          	addi	a0,a0,-352 # 16a0 <malloc+0x16c>
     808:	421000ef          	jal	1428 <printf>
    printf("2048 on xv6 | score=%d\n", score);
     80c:	00002597          	auipc	a1,0x2
     810:	80c5a583          	lw	a1,-2036(a1) # 2018 <score>
     814:	00001517          	auipc	a0,0x1
     818:	e9450513          	addi	a0,a0,-364 # 16a8 <malloc+0x174>
     81c:	40d000ef          	jal	1428 <printf>
    printf("controls: w/a/s/d (or k/h/j/l) + Enter, r=restart, q=quit\n\n");
     820:	00001517          	auipc	a0,0x1
     824:	ea050513          	addi	a0,a0,-352 # 16c0 <malloc+0x18c>
     828:	401000ef          	jal	1428 <printf>
    for (int y = 0; y < N; y++)
     82c:	00002a97          	auipc	s5,0x2
     830:	804a8a93          	addi	s5,s5,-2044 # 2030 <board>
     834:	00002d97          	auipc	s11,0x2
     838:	80cd8d93          	addi	s11,s11,-2036 # 2040 <board+0x10>
     83c:	00002d17          	auipc	s10,0x2
     840:	844d0d13          	addi	s10,s10,-1980 # 2080 <putc_buf+0x10>
    printf("controls: w/a/s/d (or k/h/j/l) + Enter, r=restart, q=quit\n\n");
     844:	000d8913          	mv	s2,s11
        printf("+------+------+------+------+\n");
     848:	00001c97          	auipc	s9,0x1
     84c:	eb8c8c93          	addi	s9,s9,-328 # 1700 <malloc+0x1cc>
     850:	04000a13          	li	s4,64
                printf("|  %d ", v);
     854:	00001c17          	auipc	s8,0x1
     858:	eecc0c13          	addi	s8,s8,-276 # 1740 <malloc+0x20c>
     85c:	c65ff06f          	j	4c0 <main+0x13c>
            int before_score = score;
     860:	00001a17          	auipc	s4,0x1
     864:	7b8a2a03          	lw	s4,1976(s4) # 2018 <score>
    int changed = 0;
     868:	00000493          	li	s1,0
            if (slide_merge_left(line))
     86c:	f7040913          	addi	s2,s0,-144
                line[i] = board[3 - i][x];
     870:	030aa783          	lw	a5,48(s5)
     874:	f6f42823          	sw	a5,-144(s0)
     878:	020aa783          	lw	a5,32(s5)
     87c:	f6f42a23          	sw	a5,-140(s0)
     880:	010aa783          	lw	a5,16(s5)
     884:	f6f42c23          	sw	a5,-136(s0)
     888:	000aa783          	lw	a5,0(s5)
     88c:	f6f42e23          	sw	a5,-132(s0)
            if (slide_merge_left(line))
     890:	00090513          	mv	a0,s2
     894:	865ff0ef          	jal	f8 <slide_merge_left>
     898:	00a037b3          	snez	a5,a0
     89c:	00f4e4b3          	or	s1,s1,a5
                board[3 - i][x] = line[i];
     8a0:	f7042783          	lw	a5,-144(s0)
     8a4:	02faa823          	sw	a5,48(s5)
     8a8:	f7442783          	lw	a5,-140(s0)
     8ac:	02faa023          	sw	a5,32(s5)
     8b0:	f7842783          	lw	a5,-136(s0)
     8b4:	00faa823          	sw	a5,16(s5)
     8b8:	f7c42783          	lw	a5,-132(s0)
     8bc:	00faa023          	sw	a5,0(s5)
        for (int x = 0; x < N; x++)
     8c0:	004a8a93          	addi	s5,s5,4
     8c4:	fb5d96e3          	bne	s11,s5,870 <main+0x4ec>
     8c8:	dc5ff06f          	j	68c <main+0x308>
     8cc:	fff00493          	li	s1,-1
        if (c == 'w' || c == 'k' || c == 'W' || c == 'K')
     8d0:	fb57869b          	addiw	a3,a5,-75
     8d4:	0ff6f693          	zext.b	a3,a3
     8d8:	02c00713          	li	a4,44
     8dc:	ccd77ee3          	bgeu	a4,a3,5b8 <main+0x234>
     8e0:	d39ff06f          	j	618 <main+0x294>
        for (int x = 0; x < N; x++)
     8e4:	0017071b          	addiw	a4,a4,1
     8e8:	00478793          	addi	a5,a5,4
     8ec:	c15ff06f          	j	500 <main+0x17c>

00000000000008f0 <start>:
//
// wrapper so that it's OK if main() does not call exit().
//
void
start(int argc, char **argv)
{
     8f0:	ff010113          	addi	sp,sp,-16
     8f4:	00113423          	sd	ra,8(sp)
     8f8:	00813023          	sd	s0,0(sp)
     8fc:	01010413          	addi	s0,sp,16
  int r;
  extern int main(int argc, char **argv);
  r = main(argc, argv);
     900:	a85ff0ef          	jal	384 <main>
  exit(r);
     904:	44c000ef          	jal	d50 <exit>

0000000000000908 <strcpy>:
}

char*
strcpy(char *s, const char *t)
{
     908:	ff010113          	addi	sp,sp,-16
     90c:	00113423          	sd	ra,8(sp)
     910:	00813023          	sd	s0,0(sp)
     914:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
     918:	00050793          	mv	a5,a0
     91c:	00158593          	addi	a1,a1,1
     920:	00178793          	addi	a5,a5,1
     924:	fff5c703          	lbu	a4,-1(a1)
     928:	fee78fa3          	sb	a4,-1(a5)
     92c:	fe0718e3          	bnez	a4,91c <strcpy+0x14>
    ;
  return os;
}
     930:	00813083          	ld	ra,8(sp)
     934:	00013403          	ld	s0,0(sp)
     938:	01010113          	addi	sp,sp,16
     93c:	00008067          	ret

0000000000000940 <strcmp>:

int
strcmp(const char *p, const char *q)
{
     940:	ff010113          	addi	sp,sp,-16
     944:	00113423          	sd	ra,8(sp)
     948:	00813023          	sd	s0,0(sp)
     94c:	01010413          	addi	s0,sp,16
  while(*p && *p == *q)
     950:	00054783          	lbu	a5,0(a0)
     954:	00078e63          	beqz	a5,970 <strcmp+0x30>
     958:	0005c703          	lbu	a4,0(a1)
     95c:	00f71a63          	bne	a4,a5,970 <strcmp+0x30>
    p++, q++;
     960:	00150513          	addi	a0,a0,1
     964:	00158593          	addi	a1,a1,1
  while(*p && *p == *q)
     968:	00054783          	lbu	a5,0(a0)
     96c:	fe0796e3          	bnez	a5,958 <strcmp+0x18>
  return (uchar)*p - (uchar)*q;
     970:	0005c503          	lbu	a0,0(a1)
}
     974:	40a7853b          	subw	a0,a5,a0
     978:	00813083          	ld	ra,8(sp)
     97c:	00013403          	ld	s0,0(sp)
     980:	01010113          	addi	sp,sp,16
     984:	00008067          	ret

0000000000000988 <strlen>:

uint
strlen(const char *s)
{
     988:	ff010113          	addi	sp,sp,-16
     98c:	00113423          	sd	ra,8(sp)
     990:	00813023          	sd	s0,0(sp)
     994:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
     998:	00054783          	lbu	a5,0(a0)
     99c:	02078663          	beqz	a5,9c8 <strlen+0x40>
     9a0:	00150793          	addi	a5,a0,1
     9a4:	00078693          	mv	a3,a5
     9a8:	00178793          	addi	a5,a5,1
     9ac:	fff7c703          	lbu	a4,-1(a5)
     9b0:	fe071ae3          	bnez	a4,9a4 <strlen+0x1c>
     9b4:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
     9b8:	00813083          	ld	ra,8(sp)
     9bc:	00013403          	ld	s0,0(sp)
     9c0:	01010113          	addi	sp,sp,16
     9c4:	00008067          	ret
  for(n = 0; s[n]; n++)
     9c8:	00000513          	li	a0,0
     9cc:	fedff06f          	j	9b8 <strlen+0x30>

00000000000009d0 <memset>:

void*
memset(void *dst, int c, uint n)
{
     9d0:	ff010113          	addi	sp,sp,-16
     9d4:	00113423          	sd	ra,8(sp)
     9d8:	00813023          	sd	s0,0(sp)
     9dc:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
     9e0:	02060063          	beqz	a2,a00 <memset+0x30>
     9e4:	00050793          	mv	a5,a0
     9e8:	02061613          	slli	a2,a2,0x20
     9ec:	02065613          	srli	a2,a2,0x20
     9f0:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
     9f4:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
     9f8:	00178793          	addi	a5,a5,1
     9fc:	fee79ce3          	bne	a5,a4,9f4 <memset+0x24>
  }
  return dst;
}
     a00:	00813083          	ld	ra,8(sp)
     a04:	00013403          	ld	s0,0(sp)
     a08:	01010113          	addi	sp,sp,16
     a0c:	00008067          	ret

0000000000000a10 <strchr>:

char*
strchr(const char *s, char c)
{
     a10:	ff010113          	addi	sp,sp,-16
     a14:	00113423          	sd	ra,8(sp)
     a18:	00813023          	sd	s0,0(sp)
     a1c:	01010413          	addi	s0,sp,16
  for(; *s; s++)
     a20:	00054783          	lbu	a5,0(a0)
     a24:	02078463          	beqz	a5,a4c <strchr+0x3c>
    if(*s == c)
     a28:	00f58a63          	beq	a1,a5,a3c <strchr+0x2c>
  for(; *s; s++)
     a2c:	00150513          	addi	a0,a0,1
     a30:	00054783          	lbu	a5,0(a0)
     a34:	fe079ae3          	bnez	a5,a28 <strchr+0x18>
      return (char*)s;
  return 0;
     a38:	00000513          	li	a0,0
}
     a3c:	00813083          	ld	ra,8(sp)
     a40:	00013403          	ld	s0,0(sp)
     a44:	01010113          	addi	sp,sp,16
     a48:	00008067          	ret
  return 0;
     a4c:	00000513          	li	a0,0
     a50:	fedff06f          	j	a3c <strchr+0x2c>

0000000000000a54 <gets>:

char*
gets(char *buf, int max)
{
     a54:	fa010113          	addi	sp,sp,-96
     a58:	04113c23          	sd	ra,88(sp)
     a5c:	04813823          	sd	s0,80(sp)
     a60:	04913423          	sd	s1,72(sp)
     a64:	05213023          	sd	s2,64(sp)
     a68:	03313c23          	sd	s3,56(sp)
     a6c:	03413823          	sd	s4,48(sp)
     a70:	03513423          	sd	s5,40(sp)
     a74:	03613023          	sd	s6,32(sp)
     a78:	01713c23          	sd	s7,24(sp)
     a7c:	01813823          	sd	s8,16(sp)
     a80:	06010413          	addi	s0,sp,96
     a84:	00050b93          	mv	s7,a0
     a88:	00058a13          	mv	s4,a1
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
     a8c:	00050913          	mv	s2,a0
     a90:	00000493          	li	s1,0
    cc = read(0, &c, 1);
     a94:	faf40b13          	addi	s6,s0,-81
     a98:	00100a93          	li	s5,1
  for(i=0; i+1 < max; ){
     a9c:	00048c13          	mv	s8,s1
     aa0:	0014899b          	addiw	s3,s1,1
     aa4:	00098493          	mv	s1,s3
     aa8:	0349dc63          	bge	s3,s4,ae0 <gets+0x8c>
    cc = read(0, &c, 1);
     aac:	000a8613          	mv	a2,s5
     ab0:	000b0593          	mv	a1,s6
     ab4:	00000513          	li	a0,0
     ab8:	2bc000ef          	jal	d74 <read>
    if(cc < 1)
     abc:	02a05263          	blez	a0,ae0 <gets+0x8c>
      break;
    buf[i++] = c;
     ac0:	faf44783          	lbu	a5,-81(s0)
     ac4:	00f90023          	sb	a5,0(s2)
    if(c == '\n' || c == '\r')
     ac8:	00190913          	addi	s2,s2,1
     acc:	ff678713          	addi	a4,a5,-10
     ad0:	00070663          	beqz	a4,adc <gets+0x88>
     ad4:	ff378793          	addi	a5,a5,-13
     ad8:	fc0792e3          	bnez	a5,a9c <gets+0x48>
    buf[i++] = c;
     adc:	00098c13          	mv	s8,s3
      break;
  }
  buf[i] = '\0';
     ae0:	018b8c33          	add	s8,s7,s8
     ae4:	000c0023          	sb	zero,0(s8)
  return buf;
}
     ae8:	000b8513          	mv	a0,s7
     aec:	05813083          	ld	ra,88(sp)
     af0:	05013403          	ld	s0,80(sp)
     af4:	04813483          	ld	s1,72(sp)
     af8:	04013903          	ld	s2,64(sp)
     afc:	03813983          	ld	s3,56(sp)
     b00:	03013a03          	ld	s4,48(sp)
     b04:	02813a83          	ld	s5,40(sp)
     b08:	02013b03          	ld	s6,32(sp)
     b0c:	01813b83          	ld	s7,24(sp)
     b10:	01013c03          	ld	s8,16(sp)
     b14:	06010113          	addi	sp,sp,96
     b18:	00008067          	ret

0000000000000b1c <stat>:

int
stat(const char *n, struct stat *st)
{
     b1c:	fe010113          	addi	sp,sp,-32
     b20:	00113c23          	sd	ra,24(sp)
     b24:	00813823          	sd	s0,16(sp)
     b28:	01213023          	sd	s2,0(sp)
     b2c:	02010413          	addi	s0,sp,32
     b30:	00058913          	mv	s2,a1
  int fd;
  int r;

  fd = open(n, O_RDONLY);
     b34:	00000593          	li	a1,0
     b38:	278000ef          	jal	db0 <open>
  if(fd < 0)
     b3c:	02054e63          	bltz	a0,b78 <stat+0x5c>
     b40:	00913423          	sd	s1,8(sp)
     b44:	00050493          	mv	s1,a0
    return -1;
  r = fstat(fd, st);
     b48:	00090593          	mv	a1,s2
     b4c:	288000ef          	jal	dd4 <fstat>
     b50:	00050913          	mv	s2,a0
  close(fd);
     b54:	00048513          	mv	a0,s1
     b58:	234000ef          	jal	d8c <close>
  return r;
     b5c:	00813483          	ld	s1,8(sp)
}
     b60:	00090513          	mv	a0,s2
     b64:	01813083          	ld	ra,24(sp)
     b68:	01013403          	ld	s0,16(sp)
     b6c:	00013903          	ld	s2,0(sp)
     b70:	02010113          	addi	sp,sp,32
     b74:	00008067          	ret
    return -1;
     b78:	fff00793          	li	a5,-1
     b7c:	00078913          	mv	s2,a5
     b80:	fe1ff06f          	j	b60 <stat+0x44>

0000000000000b84 <atoi>:

int
atoi(const char *s)
{
     b84:	ff010113          	addi	sp,sp,-16
     b88:	00113423          	sd	ra,8(sp)
     b8c:	00813023          	sd	s0,0(sp)
     b90:	01010413          	addi	s0,sp,16
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
     b94:	00054683          	lbu	a3,0(a0)
     b98:	fd06879b          	addiw	a5,a3,-48
     b9c:	0ff7f793          	zext.b	a5,a5
     ba0:	00900613          	li	a2,9
     ba4:	04f66263          	bltu	a2,a5,be8 <atoi+0x64>
     ba8:	00050713          	mv	a4,a0
  n = 0;
     bac:	00000513          	li	a0,0
    n = n*10 + *s++ - '0';
     bb0:	00170713          	addi	a4,a4,1
     bb4:	0025179b          	slliw	a5,a0,0x2
     bb8:	00a787bb          	addw	a5,a5,a0
     bbc:	0017979b          	slliw	a5,a5,0x1
     bc0:	00d787bb          	addw	a5,a5,a3
     bc4:	fd07851b          	addiw	a0,a5,-48
  while('0' <= *s && *s <= '9')
     bc8:	00074683          	lbu	a3,0(a4)
     bcc:	fd06879b          	addiw	a5,a3,-48
     bd0:	0ff7f793          	zext.b	a5,a5
     bd4:	fcf67ee3          	bgeu	a2,a5,bb0 <atoi+0x2c>
  return n;
}
     bd8:	00813083          	ld	ra,8(sp)
     bdc:	00013403          	ld	s0,0(sp)
     be0:	01010113          	addi	sp,sp,16
     be4:	00008067          	ret
  n = 0;
     be8:	00000513          	li	a0,0
     bec:	fedff06f          	j	bd8 <atoi+0x54>

0000000000000bf0 <memmove>:

void*
memmove(void *vdst, const void *vsrc, int n)
{
     bf0:	ff010113          	addi	sp,sp,-16
     bf4:	00113423          	sd	ra,8(sp)
     bf8:	00813023          	sd	s0,0(sp)
     bfc:	01010413          	addi	s0,sp,16
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
     c00:	02b57e63          	bgeu	a0,a1,c3c <memmove+0x4c>
    while(n-- > 0)
     c04:	02c05463          	blez	a2,c2c <memmove+0x3c>
     c08:	02061613          	slli	a2,a2,0x20
     c0c:	02065613          	srli	a2,a2,0x20
     c10:	00c507b3          	add	a5,a0,a2
  dst = vdst;
     c14:	00050713          	mv	a4,a0
      *dst++ = *src++;
     c18:	00158593          	addi	a1,a1,1
     c1c:	00170713          	addi	a4,a4,1
     c20:	fff5c683          	lbu	a3,-1(a1)
     c24:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
     c28:	fee798e3          	bne	a5,a4,c18 <memmove+0x28>
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}
     c2c:	00813083          	ld	ra,8(sp)
     c30:	00013403          	ld	s0,0(sp)
     c34:	01010113          	addi	sp,sp,16
     c38:	00008067          	ret
    while(n-- > 0)
     c3c:	fec058e3          	blez	a2,c2c <memmove+0x3c>
    dst += n;
     c40:	00c50733          	add	a4,a0,a2
    src += n;
     c44:	00c585b3          	add	a1,a1,a2
     c48:	fff6079b          	addiw	a5,a2,-1 # 1ffff <base+0x1df0f>
     c4c:	02079793          	slli	a5,a5,0x20
     c50:	0207d793          	srli	a5,a5,0x20
     c54:	fff7c793          	not	a5,a5
     c58:	00f707b3          	add	a5,a4,a5
      *--dst = *--src;
     c5c:	fff58593          	addi	a1,a1,-1
     c60:	fff70713          	addi	a4,a4,-1
     c64:	0005c683          	lbu	a3,0(a1)
     c68:	00d70023          	sb	a3,0(a4)
    while(n-- > 0)
     c6c:	fef718e3          	bne	a4,a5,c5c <memmove+0x6c>
     c70:	fbdff06f          	j	c2c <memmove+0x3c>

0000000000000c74 <memcmp>:

int
memcmp(const void *s1, const void *s2, uint n)
{
     c74:	ff010113          	addi	sp,sp,-16
     c78:	00113423          	sd	ra,8(sp)
     c7c:	00813023          	sd	s0,0(sp)
     c80:	01010413          	addi	s0,sp,16
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
     c84:	04060263          	beqz	a2,cc8 <memcmp+0x54>
     c88:	02061613          	slli	a2,a2,0x20
     c8c:	02065613          	srli	a2,a2,0x20
     c90:	00c506b3          	add	a3,a0,a2
    if (*p1 != *p2) {
     c94:	00054783          	lbu	a5,0(a0)
     c98:	0005c703          	lbu	a4,0(a1)
     c9c:	00e79c63          	bne	a5,a4,cb4 <memcmp+0x40>
      return *p1 - *p2;
    }
    p1++;
     ca0:	00150513          	addi	a0,a0,1
    p2++;
     ca4:	00158593          	addi	a1,a1,1
  while (n-- > 0) {
     ca8:	fed516e3          	bne	a0,a3,c94 <memcmp+0x20>
  }
  return 0;
     cac:	00000513          	li	a0,0
     cb0:	0080006f          	j	cb8 <memcmp+0x44>
      return *p1 - *p2;
     cb4:	40e7853b          	subw	a0,a5,a4
}
     cb8:	00813083          	ld	ra,8(sp)
     cbc:	00013403          	ld	s0,0(sp)
     cc0:	01010113          	addi	sp,sp,16
     cc4:	00008067          	ret
  return 0;
     cc8:	00000513          	li	a0,0
     ccc:	fedff06f          	j	cb8 <memcmp+0x44>

0000000000000cd0 <memcpy>:

void *
memcpy(void *dst, const void *src, uint n)
{
     cd0:	ff010113          	addi	sp,sp,-16
     cd4:	00113423          	sd	ra,8(sp)
     cd8:	00813023          	sd	s0,0(sp)
     cdc:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
     ce0:	f11ff0ef          	jal	bf0 <memmove>
}
     ce4:	00813083          	ld	ra,8(sp)
     ce8:	00013403          	ld	s0,0(sp)
     cec:	01010113          	addi	sp,sp,16
     cf0:	00008067          	ret

0000000000000cf4 <sbrk>:

char *
sbrk(int n) {
     cf4:	ff010113          	addi	sp,sp,-16
     cf8:	00113423          	sd	ra,8(sp)
     cfc:	00813023          	sd	s0,0(sp)
     d00:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_EAGER);
     d04:	00100593          	li	a1,1
     d08:	114000ef          	jal	e1c <sys_sbrk>
}
     d0c:	00813083          	ld	ra,8(sp)
     d10:	00013403          	ld	s0,0(sp)
     d14:	01010113          	addi	sp,sp,16
     d18:	00008067          	ret

0000000000000d1c <sbrklazy>:

char *
sbrklazy(int n) {
     d1c:	ff010113          	addi	sp,sp,-16
     d20:	00113423          	sd	ra,8(sp)
     d24:	00813023          	sd	s0,0(sp)
     d28:	01010413          	addi	s0,sp,16
  return sys_sbrk(n, SBRK_LAZY);
     d2c:	00200593          	li	a1,2
     d30:	0ec000ef          	jal	e1c <sys_sbrk>
}
     d34:	00813083          	ld	ra,8(sp)
     d38:	00013403          	ld	s0,0(sp)
     d3c:	01010113          	addi	sp,sp,16
     d40:	00008067          	ret

0000000000000d44 <fork>:
# generated by usys.pl - do not edit
#include "kernel/syscall.h"
.global fork
fork:
 li a7, SYS_fork
     d44:	00100893          	li	a7,1
 ecall
     d48:	00000073          	ecall
 ret
     d4c:	00008067          	ret

0000000000000d50 <exit>:
.global exit
exit:
 li a7, SYS_exit
     d50:	00200893          	li	a7,2
 ecall
     d54:	00000073          	ecall
 ret
     d58:	00008067          	ret

0000000000000d5c <wait>:
.global wait
wait:
 li a7, SYS_wait
     d5c:	00300893          	li	a7,3
 ecall
     d60:	00000073          	ecall
 ret
     d64:	00008067          	ret

0000000000000d68 <pipe>:
.global pipe
pipe:
 li a7, SYS_pipe
     d68:	00400893          	li	a7,4
 ecall
     d6c:	00000073          	ecall
 ret
     d70:	00008067          	ret

0000000000000d74 <read>:
.global read
read:
 li a7, SYS_read
     d74:	00500893          	li	a7,5
 ecall
     d78:	00000073          	ecall
 ret
     d7c:	00008067          	ret

0000000000000d80 <write>:
.global write
write:
 li a7, SYS_write
     d80:	01000893          	li	a7,16
 ecall
     d84:	00000073          	ecall
 ret
     d88:	00008067          	ret

0000000000000d8c <close>:
.global close
close:
 li a7, SYS_close
     d8c:	01500893          	li	a7,21
 ecall
     d90:	00000073          	ecall
 ret
     d94:	00008067          	ret

0000000000000d98 <kill>:
.global kill
kill:
 li a7, SYS_kill
     d98:	00600893          	li	a7,6
 ecall
     d9c:	00000073          	ecall
 ret
     da0:	00008067          	ret

0000000000000da4 <exec>:
.global exec
exec:
 li a7, SYS_exec
     da4:	00700893          	li	a7,7
 ecall
     da8:	00000073          	ecall
 ret
     dac:	00008067          	ret

0000000000000db0 <open>:
.global open
open:
 li a7, SYS_open
     db0:	00f00893          	li	a7,15
 ecall
     db4:	00000073          	ecall
 ret
     db8:	00008067          	ret

0000000000000dbc <mknod>:
.global mknod
mknod:
 li a7, SYS_mknod
     dbc:	01100893          	li	a7,17
 ecall
     dc0:	00000073          	ecall
 ret
     dc4:	00008067          	ret

0000000000000dc8 <unlink>:
.global unlink
unlink:
 li a7, SYS_unlink
     dc8:	01200893          	li	a7,18
 ecall
     dcc:	00000073          	ecall
 ret
     dd0:	00008067          	ret

0000000000000dd4 <fstat>:
.global fstat
fstat:
 li a7, SYS_fstat
     dd4:	00800893          	li	a7,8
 ecall
     dd8:	00000073          	ecall
 ret
     ddc:	00008067          	ret

0000000000000de0 <link>:
.global link
link:
 li a7, SYS_link
     de0:	01300893          	li	a7,19
 ecall
     de4:	00000073          	ecall
 ret
     de8:	00008067          	ret

0000000000000dec <mkdir>:
.global mkdir
mkdir:
 li a7, SYS_mkdir
     dec:	01400893          	li	a7,20
 ecall
     df0:	00000073          	ecall
 ret
     df4:	00008067          	ret

0000000000000df8 <chdir>:
.global chdir
chdir:
 li a7, SYS_chdir
     df8:	00900893          	li	a7,9
 ecall
     dfc:	00000073          	ecall
 ret
     e00:	00008067          	ret

0000000000000e04 <dup>:
.global dup
dup:
 li a7, SYS_dup
     e04:	00a00893          	li	a7,10
 ecall
     e08:	00000073          	ecall
 ret
     e0c:	00008067          	ret

0000000000000e10 <getpid>:
.global getpid
getpid:
 li a7, SYS_getpid
     e10:	00b00893          	li	a7,11
 ecall
     e14:	00000073          	ecall
 ret
     e18:	00008067          	ret

0000000000000e1c <sys_sbrk>:
.global sys_sbrk
sys_sbrk:
 li a7, SYS_sbrk
     e1c:	00c00893          	li	a7,12
 ecall
     e20:	00000073          	ecall
 ret
     e24:	00008067          	ret

0000000000000e28 <pause>:
.global pause
pause:
 li a7, SYS_pause
     e28:	00d00893          	li	a7,13
 ecall
     e2c:	00000073          	ecall
 ret
     e30:	00008067          	ret

0000000000000e34 <uptime>:
.global uptime
uptime:
 li a7, SYS_uptime
     e34:	00e00893          	li	a7,14
 ecall
     e38:	00000073          	ecall
 ret
     e3c:	00008067          	ret

0000000000000e40 <putc_flush>:

// 1文字ずつwriteすると毎回syscallすることになり,時間がかかるのでバッファリングしてから行う.
static void
putc_flush(void)
{
  if (putc_n > 0)
     e40:	00001617          	auipc	a2,0x1
     e44:	1dc62603          	lw	a2,476(a2) # 201c <putc_n>
     e48:	00c04463          	bgtz	a2,e50 <putc_flush+0x10>
     e4c:	00008067          	ret
{
     e50:	ff010113          	addi	sp,sp,-16
     e54:	00113423          	sd	ra,8(sp)
     e58:	00813023          	sd	s0,0(sp)
     e5c:	01010413          	addi	s0,sp,16
  {
    write(putc_fd, putc_buf, putc_n);
     e60:	00001597          	auipc	a1,0x1
     e64:	21058593          	addi	a1,a1,528 # 2070 <putc_buf>
     e68:	00001517          	auipc	a0,0x1
     e6c:	19852503          	lw	a0,408(a0) # 2000 <putc_fd>
     e70:	f11ff0ef          	jal	d80 <write>
    putc_n = 0;
     e74:	00001797          	auipc	a5,0x1
     e78:	1a07a423          	sw	zero,424(a5) # 201c <putc_n>
  }
}
     e7c:	00813083          	ld	ra,8(sp)
     e80:	00013403          	ld	s0,0(sp)
     e84:	01010113          	addi	sp,sp,16
     e88:	00008067          	ret

0000000000000e8c <putc>:

static void
putc(int fd, char c)
{
     e8c:	fe010113          	addi	sp,sp,-32
     e90:	00113c23          	sd	ra,24(sp)
     e94:	00813823          	sd	s0,16(sp)
     e98:	00913423          	sd	s1,8(sp)
     e9c:	02010413          	addi	s0,sp,32
     ea0:	00058493          	mv	s1,a1
  if (putc_fd != fd)
     ea4:	00001797          	auipc	a5,0x1
     ea8:	15c7a783          	lw	a5,348(a5) # 2000 <putc_fd>
     eac:	04a79663          	bne	a5,a0,ef8 <putc+0x6c>
  {
    putc_flush();
    putc_fd = fd;
  }

  putc_buf[putc_n++] = c;
     eb0:	00001717          	auipc	a4,0x1
     eb4:	16c70713          	addi	a4,a4,364 # 201c <putc_n>
     eb8:	00072683          	lw	a3,0(a4)
     ebc:	0016879b          	addiw	a5,a3,1
     ec0:	00f72023          	sw	a5,0(a4)
     ec4:	00001717          	auipc	a4,0x1
     ec8:	1ac70713          	addi	a4,a4,428 # 2070 <putc_buf>
     ecc:	00d70733          	add	a4,a4,a3
     ed0:	00970023          	sb	s1,0(a4)

  if (putc_n == PRINTF_BUFSZ || c == '\n')
     ed4:	ff648493          	addi	s1,s1,-10
     ed8:	02048e63          	beqz	s1,f14 <putc+0x88>
     edc:	f8078793          	addi	a5,a5,-128
     ee0:	02078a63          	beqz	a5,f14 <putc+0x88>
    putc_flush();
}
     ee4:	01813083          	ld	ra,24(sp)
     ee8:	01013403          	ld	s0,16(sp)
     eec:	00813483          	ld	s1,8(sp)
     ef0:	02010113          	addi	sp,sp,32
     ef4:	00008067          	ret
     ef8:	01213023          	sd	s2,0(sp)
     efc:	00050913          	mv	s2,a0
    putc_flush();
     f00:	f41ff0ef          	jal	e40 <putc_flush>
    putc_fd = fd;
     f04:	00001797          	auipc	a5,0x1
     f08:	0f27ae23          	sw	s2,252(a5) # 2000 <putc_fd>
     f0c:	00013903          	ld	s2,0(sp)
     f10:	fa1ff06f          	j	eb0 <putc+0x24>
    putc_flush();
     f14:	f2dff0ef          	jal	e40 <putc_flush>
}
     f18:	fcdff06f          	j	ee4 <putc+0x58>

0000000000000f1c <printint>:

static void
printint(int fd, long long xx, int base, int sgn)
{
     f1c:	fb010113          	addi	sp,sp,-80
     f20:	04113423          	sd	ra,72(sp)
     f24:	04813023          	sd	s0,64(sp)
     f28:	03213823          	sd	s2,48(sp)
     f2c:	03313423          	sd	s3,40(sp)
     f30:	05010413          	addi	s0,sp,80
     f34:	00050913          	mv	s2,a0
  char buf[20];
  int i, neg;
  unsigned long long x;

  neg = 0;
  if (sgn && xx < 0)
     f38:	0a068e63          	beqz	a3,ff4 <printint+0xd8>
     f3c:	0a05dc63          	bgez	a1,ff4 <printint+0xd8>
  {
    neg = 1;
    x = -xx;
     f40:	40b005b3          	neg	a1,a1
    neg = 1;
     f44:	00100313          	li	t1,1
  else
  {
    x = xx;
  }

  i = 0;
     f48:	fb840993          	addi	s3,s0,-72
  neg = 0;
     f4c:	00098693          	mv	a3,s3
  i = 0;
     f50:	00000713          	li	a4,0
  do
  {
    buf[i++] = digits[x % base];
     f54:	00001817          	auipc	a6,0x1
     f58:	83c80813          	addi	a6,a6,-1988 # 1790 <digits>
     f5c:	00070893          	mv	a7,a4
     f60:	0017051b          	addiw	a0,a4,1
     f64:	00050713          	mv	a4,a0
     f68:	02c5f7b3          	remu	a5,a1,a2
     f6c:	00f807b3          	add	a5,a6,a5
     f70:	0007c783          	lbu	a5,0(a5)
     f74:	00f68023          	sb	a5,0(a3)
  } while ((x /= base) != 0);
     f78:	00058793          	mv	a5,a1
     f7c:	02c5d5b3          	divu	a1,a1,a2
     f80:	00168693          	addi	a3,a3,1
     f84:	fcc7fce3          	bgeu	a5,a2,f5c <printint+0x40>
  if (neg)
     f88:	00030c63          	beqz	t1,fa0 <printint+0x84>
    buf[i++] = '-';
     f8c:	fd050793          	addi	a5,a0,-48
     f90:	00878533          	add	a0,a5,s0
     f94:	02d00793          	li	a5,45
     f98:	fef50423          	sb	a5,-24(a0)
     f9c:	0028871b          	addiw	a4,a7,2

  while (--i >= 0)
     fa0:	02e05e63          	blez	a4,fdc <printint+0xc0>
     fa4:	02913c23          	sd	s1,56(sp)
     fa8:	fff7071b          	addiw	a4,a4,-1
     fac:	00e984b3          	add	s1,s3,a4
     fb0:	fff98993          	addi	s3,s3,-1
     fb4:	00e989b3          	add	s3,s3,a4
     fb8:	02071713          	slli	a4,a4,0x20
     fbc:	02075713          	srli	a4,a4,0x20
     fc0:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
     fc4:	0004c583          	lbu	a1,0(s1)
     fc8:	00090513          	mv	a0,s2
     fcc:	ec1ff0ef          	jal	e8c <putc>
  while (--i >= 0)
     fd0:	fff48493          	addi	s1,s1,-1
     fd4:	ff3498e3          	bne	s1,s3,fc4 <printint+0xa8>
     fd8:	03813483          	ld	s1,56(sp)
}
     fdc:	04813083          	ld	ra,72(sp)
     fe0:	04013403          	ld	s0,64(sp)
     fe4:	03013903          	ld	s2,48(sp)
     fe8:	02813983          	ld	s3,40(sp)
     fec:	05010113          	addi	sp,sp,80
     ff0:	00008067          	ret
  neg = 0;
     ff4:	00000313          	li	t1,0
     ff8:	f51ff06f          	j	f48 <printint+0x2c>

0000000000000ffc <vprintf>:
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
}

// Print to the given fd. Only understands %d, %x, %p, %c, %s.
void vprintf(int fd, const char *fmt, va_list ap)
{
     ffc:	fa010113          	addi	sp,sp,-96
    1000:	04113c23          	sd	ra,88(sp)
    1004:	04813823          	sd	s0,80(sp)
    1008:	04913423          	sd	s1,72(sp)
    100c:	06010413          	addi	s0,sp,96
  char *s;
  int c0, c1, c2, i, state;

  state = 0;
  for (i = 0; fmt[i]; i++)
    1010:	0005c483          	lbu	s1,0(a1)
    1014:	32048263          	beqz	s1,1338 <vprintf+0x33c>
    1018:	05213023          	sd	s2,64(sp)
    101c:	03313c23          	sd	s3,56(sp)
    1020:	03413823          	sd	s4,48(sp)
    1024:	03513423          	sd	s5,40(sp)
    1028:	03613023          	sd	s6,32(sp)
    102c:	01713c23          	sd	s7,24(sp)
    1030:	01813823          	sd	s8,16(sp)
    1034:	00050b13          	mv	s6,a0
    1038:	00058a13          	mv	s4,a1
    103c:	00060b93          	mv	s7,a2
  state = 0;
    1040:	00000993          	li	s3,0
  for (i = 0; fmt[i]; i++)
    1044:	00000913          	li	s2,0
    1048:	00000713          	li	a4,0
      else
      {
        putc(fd, c0);
      }
    }
    else if (state == '%')
    104c:	02500a93          	li	s5,37
      c1 = c2 = 0;
      if (c0)
        c1 = fmt[i + 1] & 0xff;
      if (c1)
        c2 = fmt[i + 2] & 0xff;
      if (c0 == 'd')
    1050:	06400c13          	li	s8,100
    1054:	0300006f          	j	1084 <vprintf+0x88>
        putc(fd, c0);
    1058:	00048593          	mv	a1,s1
    105c:	000b0513          	mv	a0,s6
    1060:	e2dff0ef          	jal	e8c <putc>
    1064:	0080006f          	j	106c <vprintf+0x70>
    else if (state == '%')
    1068:	03598863          	beq	s3,s5,1098 <vprintf+0x9c>
  for (i = 0; fmt[i]; i++)
    106c:	0019079b          	addiw	a5,s2,1
    1070:	00078913          	mv	s2,a5
    1074:	00078713          	mv	a4,a5
    1078:	00fa07b3          	add	a5,s4,a5
    107c:	0007c483          	lbu	s1,0(a5)
    1080:	28048e63          	beqz	s1,131c <vprintf+0x320>
    c0 = fmt[i] & 0xff;
    1084:	0004879b          	sext.w	a5,s1
    if (state == 0)
    1088:	fe0990e3          	bnez	s3,1068 <vprintf+0x6c>
      if (c0 == '%')
    108c:	fd5796e3          	bne	a5,s5,1058 <vprintf+0x5c>
        state = '%';
    1090:	00078993          	mv	s3,a5
    1094:	fd9ff06f          	j	106c <vprintf+0x70>
        c1 = fmt[i + 1] & 0xff;
    1098:	00ea06b3          	add	a3,s4,a4
    109c:	0016c603          	lbu	a2,1(a3)
      if (c1)
    10a0:	2a060663          	beqz	a2,134c <vprintf+0x350>
      if (c0 == 'd')
    10a4:	05878063          	beq	a5,s8,10e4 <vprintf+0xe8>
      {
        printint(fd, va_arg(ap, int), 10, 1);
      }
      else if (c0 == 'l' && c1 == 'd')
    10a8:	f9478693          	addi	a3,a5,-108
    10ac:	0016b693          	seqz	a3,a3
    10b0:	f9c60593          	addi	a1,a2,-100
    10b4:	04059a63          	bnez	a1,1108 <vprintf+0x10c>
    10b8:	04068863          	beqz	a3,1108 <vprintf+0x10c>
      {
        printint(fd, va_arg(ap, uint64), 10, 1);
    10bc:	008b8493          	addi	s1,s7,8 # 40000008 <base+0x3fffdf18>
    10c0:	00100693          	li	a3,1
    10c4:	00a00613          	li	a2,10
    10c8:	000bb583          	ld	a1,0(s7)
    10cc:	000b0513          	mv	a0,s6
    10d0:	e4dff0ef          	jal	f1c <printint>
        i += 1;
    10d4:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 1);
    10d8:	00048b93          	mv	s7,s1
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c0);
      }

      state = 0;
    10dc:	00000993          	li	s3,0
    10e0:	f8dff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, int), 10, 1);
    10e4:	008b8493          	addi	s1,s7,8
    10e8:	00100693          	li	a3,1
    10ec:	00a00613          	li	a2,10
    10f0:	000ba583          	lw	a1,0(s7)
    10f4:	000b0513          	mv	a0,s6
    10f8:	e25ff0ef          	jal	f1c <printint>
    10fc:	00048b93          	mv	s7,s1
      state = 0;
    1100:	00000993          	li	s3,0
    1104:	f69ff06f          	j	106c <vprintf+0x70>
        c2 = fmt[i + 2] & 0xff;
    1108:	00ea0733          	add	a4,s4,a4
    110c:	00274583          	lbu	a1,2(a4)
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    1110:	f9460713          	addi	a4,a2,-108
    1114:	00173713          	seqz	a4,a4
    1118:	00e6f733          	and	a4,a3,a4
    111c:	f9c58513          	addi	a0,a1,-100
    1120:	24051263          	bnez	a0,1364 <vprintf+0x368>
    1124:	24070063          	beqz	a4,1364 <vprintf+0x368>
        printint(fd, va_arg(ap, uint64), 10, 1);
    1128:	008b8493          	addi	s1,s7,8
    112c:	00100693          	li	a3,1
    1130:	00a00613          	li	a2,10
    1134:	000bb583          	ld	a1,0(s7)
    1138:	000b0513          	mv	a0,s6
    113c:	de1ff0ef          	jal	f1c <printint>
        i += 2;
    1140:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 1);
    1144:	00048b93          	mv	s7,s1
      state = 0;
    1148:	00000993          	li	s3,0
        i += 2;
    114c:	f21ff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 10, 0);
    1150:	008b8493          	addi	s1,s7,8
    1154:	00000693          	li	a3,0
    1158:	00a00613          	li	a2,10
    115c:	000be583          	lwu	a1,0(s7)
    1160:	000b0513          	mv	a0,s6
    1164:	db9ff0ef          	jal	f1c <printint>
    1168:	00048b93          	mv	s7,s1
      state = 0;
    116c:	00000993          	li	s3,0
    1170:	efdff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    1174:	008b8493          	addi	s1,s7,8
    1178:	00000693          	li	a3,0
    117c:	00a00613          	li	a2,10
    1180:	000bb583          	ld	a1,0(s7)
    1184:	000b0513          	mv	a0,s6
    1188:	d95ff0ef          	jal	f1c <printint>
        i += 1;
    118c:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 10, 0);
    1190:	00048b93          	mv	s7,s1
      state = 0;
    1194:	00000993          	li	s3,0
    1198:	ed5ff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 10, 0);
    119c:	008b8493          	addi	s1,s7,8
    11a0:	00000693          	li	a3,0
    11a4:	00a00613          	li	a2,10
    11a8:	000bb583          	ld	a1,0(s7)
    11ac:	000b0513          	mv	a0,s6
    11b0:	d6dff0ef          	jal	f1c <printint>
        i += 2;
    11b4:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 10, 0);
    11b8:	00048b93          	mv	s7,s1
      state = 0;
    11bc:	00000993          	li	s3,0
        i += 2;
    11c0:	eadff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint32), 16, 0);
    11c4:	008b8493          	addi	s1,s7,8
    11c8:	00000693          	li	a3,0
    11cc:	01000613          	li	a2,16
    11d0:	000be583          	lwu	a1,0(s7)
    11d4:	000b0513          	mv	a0,s6
    11d8:	d45ff0ef          	jal	f1c <printint>
    11dc:	00048b93          	mv	s7,s1
      state = 0;
    11e0:	00000993          	li	s3,0
    11e4:	e89ff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    11e8:	008b8493          	addi	s1,s7,8
    11ec:	00000693          	li	a3,0
    11f0:	01000613          	li	a2,16
    11f4:	000bb583          	ld	a1,0(s7)
    11f8:	000b0513          	mv	a0,s6
    11fc:	d21ff0ef          	jal	f1c <printint>
        i += 1;
    1200:	0019091b          	addiw	s2,s2,1
        printint(fd, va_arg(ap, uint64), 16, 0);
    1204:	00048b93          	mv	s7,s1
      state = 0;
    1208:	00000993          	li	s3,0
    120c:	e61ff06f          	j	106c <vprintf+0x70>
        printint(fd, va_arg(ap, uint64), 16, 0);
    1210:	008b8493          	addi	s1,s7,8
    1214:	00000693          	li	a3,0
    1218:	01000613          	li	a2,16
    121c:	000bb583          	ld	a1,0(s7)
    1220:	000b0513          	mv	a0,s6
    1224:	cf9ff0ef          	jal	f1c <printint>
        i += 2;
    1228:	0029091b          	addiw	s2,s2,2
        printint(fd, va_arg(ap, uint64), 16, 0);
    122c:	00048b93          	mv	s7,s1
      state = 0;
    1230:	00000993          	li	s3,0
        i += 2;
    1234:	e39ff06f          	j	106c <vprintf+0x70>
    1238:	01913423          	sd	s9,8(sp)
        printptr(fd, va_arg(ap, uint64));
    123c:	008b8793          	addi	a5,s7,8
    1240:	00078c93          	mv	s9,a5
    1244:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
    1248:	03000593          	li	a1,48
    124c:	000b0513          	mv	a0,s6
    1250:	c3dff0ef          	jal	e8c <putc>
  putc(fd, 'x');
    1254:	07800593          	li	a1,120
    1258:	000b0513          	mv	a0,s6
    125c:	c31ff0ef          	jal	e8c <putc>
    1260:	01000493          	li	s1,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
    1264:	00000b97          	auipc	s7,0x0
    1268:	52cb8b93          	addi	s7,s7,1324 # 1790 <digits>
    126c:	03c9d793          	srli	a5,s3,0x3c
    1270:	00fb87b3          	add	a5,s7,a5
    1274:	0007c583          	lbu	a1,0(a5)
    1278:	000b0513          	mv	a0,s6
    127c:	c11ff0ef          	jal	e8c <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
    1280:	00499993          	slli	s3,s3,0x4
    1284:	fff4849b          	addiw	s1,s1,-1
    1288:	fe0492e3          	bnez	s1,126c <vprintf+0x270>
        printptr(fd, va_arg(ap, uint64));
    128c:	000c8b93          	mv	s7,s9
      state = 0;
    1290:	00000993          	li	s3,0
    1294:	00813c83          	ld	s9,8(sp)
    1298:	dd5ff06f          	j	106c <vprintf+0x70>
        putc(fd, va_arg(ap, uint32));
    129c:	008b8493          	addi	s1,s7,8
    12a0:	000bc583          	lbu	a1,0(s7)
    12a4:	000b0513          	mv	a0,s6
    12a8:	be5ff0ef          	jal	e8c <putc>
    12ac:	00048b93          	mv	s7,s1
      state = 0;
    12b0:	00000993          	li	s3,0
    12b4:	db9ff06f          	j	106c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    12b8:	008b8993          	addi	s3,s7,8
    12bc:	000bb483          	ld	s1,0(s7)
    12c0:	02048663          	beqz	s1,12ec <vprintf+0x2f0>
        for (; *s; s++)
    12c4:	0004c583          	lbu	a1,0(s1)
    12c8:	04058463          	beqz	a1,1310 <vprintf+0x314>
          putc(fd, *s);
    12cc:	000b0513          	mv	a0,s6
    12d0:	bbdff0ef          	jal	e8c <putc>
        for (; *s; s++)
    12d4:	00148493          	addi	s1,s1,1
    12d8:	0004c583          	lbu	a1,0(s1)
    12dc:	fe0598e3          	bnez	a1,12cc <vprintf+0x2d0>
        if ((s = va_arg(ap, char *)) == 0)
    12e0:	00098b93          	mv	s7,s3
      state = 0;
    12e4:	00000993          	li	s3,0
    12e8:	d85ff06f          	j	106c <vprintf+0x70>
          s = "(null)";
    12ec:	00000497          	auipc	s1,0x0
    12f0:	49c48493          	addi	s1,s1,1180 # 1788 <malloc+0x254>
        for (; *s; s++)
    12f4:	02800593          	li	a1,40
    12f8:	fd5ff06f          	j	12cc <vprintf+0x2d0>
        putc(fd, '%');
    12fc:	00078593          	mv	a1,a5
    1300:	000b0513          	mv	a0,s6
    1304:	b89ff0ef          	jal	e8c <putc>
      state = 0;
    1308:	00000993          	li	s3,0
    130c:	d61ff06f          	j	106c <vprintf+0x70>
        if ((s = va_arg(ap, char *)) == 0)
    1310:	00098b93          	mv	s7,s3
      state = 0;
    1314:	00000993          	li	s3,0
    1318:	d55ff06f          	j	106c <vprintf+0x70>
    131c:	04013903          	ld	s2,64(sp)
    1320:	03813983          	ld	s3,56(sp)
    1324:	03013a03          	ld	s4,48(sp)
    1328:	02813a83          	ld	s5,40(sp)
    132c:	02013b03          	ld	s6,32(sp)
    1330:	01813b83          	ld	s7,24(sp)
    1334:	01013c03          	ld	s8,16(sp)
    }
  }
}
    1338:	05813083          	ld	ra,88(sp)
    133c:	05013403          	ld	s0,80(sp)
    1340:	04813483          	ld	s1,72(sp)
    1344:	06010113          	addi	sp,sp,96
    1348:	00008067          	ret
      if (c0 == 'd')
    134c:	06400713          	li	a4,100
    1350:	d8e78ae3          	beq	a5,a4,10e4 <vprintf+0xe8>
      else if (c0 == 'l' && c1 == 'd')
    1354:	f9478693          	addi	a3,a5,-108
    1358:	0016b693          	seqz	a3,a3
      c1 = c2 = 0;
    135c:	00060593          	mv	a1,a2
      else if (c0 == 'l' && c1 == 'l' && c2 == 'd')
    1360:	00000713          	li	a4,0
      else if (c0 == 'u')
    1364:	07500513          	li	a0,117
    1368:	dea784e3          	beq	a5,a0,1150 <vprintf+0x154>
      else if (c0 == 'l' && c1 == 'u')
    136c:	f8b60513          	addi	a0,a2,-117
    1370:	00051463          	bnez	a0,1378 <vprintf+0x37c>
    1374:	e00690e3          	bnez	a3,1174 <vprintf+0x178>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'u')
    1378:	f8b58513          	addi	a0,a1,-117
    137c:	00051463          	bnez	a0,1384 <vprintf+0x388>
    1380:	e0071ee3          	bnez	a4,119c <vprintf+0x1a0>
      else if (c0 == 'x')
    1384:	07800513          	li	a0,120
    1388:	e2a78ee3          	beq	a5,a0,11c4 <vprintf+0x1c8>
      else if (c0 == 'l' && c1 == 'x')
    138c:	f8860613          	addi	a2,a2,-120
    1390:	00061463          	bnez	a2,1398 <vprintf+0x39c>
    1394:	e4069ae3          	bnez	a3,11e8 <vprintf+0x1ec>
      else if (c0 == 'l' && c1 == 'l' && c2 == 'x')
    1398:	f8858593          	addi	a1,a1,-120
    139c:	00059463          	bnez	a1,13a4 <vprintf+0x3a8>
    13a0:	e60718e3          	bnez	a4,1210 <vprintf+0x214>
      else if (c0 == 'p')
    13a4:	07000713          	li	a4,112
    13a8:	e8e788e3          	beq	a5,a4,1238 <vprintf+0x23c>
      else if (c0 == 'c')
    13ac:	06300713          	li	a4,99
    13b0:	eee786e3          	beq	a5,a4,129c <vprintf+0x2a0>
      else if (c0 == 's')
    13b4:	07300713          	li	a4,115
    13b8:	f0e780e3          	beq	a5,a4,12b8 <vprintf+0x2bc>
      else if (c0 == '%')
    13bc:	02500713          	li	a4,37
    13c0:	f2e78ee3          	beq	a5,a4,12fc <vprintf+0x300>
        putc(fd, '%');
    13c4:	02500593          	li	a1,37
    13c8:	000b0513          	mv	a0,s6
    13cc:	ac1ff0ef          	jal	e8c <putc>
        putc(fd, c0);
    13d0:	00048593          	mv	a1,s1
    13d4:	000b0513          	mv	a0,s6
    13d8:	ab5ff0ef          	jal	e8c <putc>
      state = 0;
    13dc:	00000993          	li	s3,0
    13e0:	c8dff06f          	j	106c <vprintf+0x70>

00000000000013e4 <fprintf>:

void fprintf(int fd, const char *fmt, ...)
{
    13e4:	fb010113          	addi	sp,sp,-80
    13e8:	00113c23          	sd	ra,24(sp)
    13ec:	00813823          	sd	s0,16(sp)
    13f0:	02010413          	addi	s0,sp,32
    13f4:	00c43023          	sd	a2,0(s0)
    13f8:	00d43423          	sd	a3,8(s0)
    13fc:	00e43823          	sd	a4,16(s0)
    1400:	00f43c23          	sd	a5,24(s0)
    1404:	03043023          	sd	a6,32(s0)
    1408:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
    140c:	00040613          	mv	a2,s0
    1410:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
    1414:	be9ff0ef          	jal	ffc <vprintf>
}
    1418:	01813083          	ld	ra,24(sp)
    141c:	01013403          	ld	s0,16(sp)
    1420:	05010113          	addi	sp,sp,80
    1424:	00008067          	ret

0000000000001428 <printf>:

void printf(const char *fmt, ...)
{
    1428:	fa010113          	addi	sp,sp,-96
    142c:	00113c23          	sd	ra,24(sp)
    1430:	00813823          	sd	s0,16(sp)
    1434:	02010413          	addi	s0,sp,32
    1438:	00b43423          	sd	a1,8(s0)
    143c:	00c43823          	sd	a2,16(s0)
    1440:	00d43c23          	sd	a3,24(s0)
    1444:	02e43023          	sd	a4,32(s0)
    1448:	02f43423          	sd	a5,40(s0)
    144c:	03043823          	sd	a6,48(s0)
    1450:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
    1454:	00840613          	addi	a2,s0,8
    1458:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
    145c:	00050593          	mv	a1,a0
    1460:	00100513          	li	a0,1
    1464:	b99ff0ef          	jal	ffc <vprintf>
  putc_flush();
    1468:	9d9ff0ef          	jal	e40 <putc_flush>
}
    146c:	01813083          	ld	ra,24(sp)
    1470:	01013403          	ld	s0,16(sp)
    1474:	06010113          	addi	sp,sp,96
    1478:	00008067          	ret

000000000000147c <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
    147c:	ff010113          	addi	sp,sp,-16
    1480:	00113423          	sd	ra,8(sp)
    1484:	00813023          	sd	s0,0(sp)
    1488:	01010413          	addi	s0,sp,16
  Header *bp, *p;

  bp = (Header*)ap - 1;
    148c:	ff050693          	addi	a3,a0,-16
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1490:	00001797          	auipc	a5,0x1
    1494:	b907b783          	ld	a5,-1136(a5) # 2020 <freep>
    1498:	0140006f          	j	14ac <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    149c:	0007b703          	ld	a4,0(a5)
    14a0:	00e7e463          	bltu	a5,a4,14a8 <free+0x2c>
    14a4:	00e6ec63          	bltu	a3,a4,14bc <free+0x40>
{
    14a8:	00070793          	mv	a5,a4
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    14ac:	fed7f8e3          	bgeu	a5,a3,149c <free+0x20>
    14b0:	0007b703          	ld	a4,0(a5)
    14b4:	00e6e463          	bltu	a3,a4,14bc <free+0x40>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    14b8:	fee7e8e3          	bltu	a5,a4,14a8 <free+0x2c>
      break;
  if(bp + bp->s.size == p->s.ptr){
    14bc:	ff852583          	lw	a1,-8(a0)
    14c0:	0007b603          	ld	a2,0(a5)
    14c4:	02059813          	slli	a6,a1,0x20
    14c8:	01c85713          	srli	a4,a6,0x1c
    14cc:	00e68733          	add	a4,a3,a4
    14d0:	02e60c63          	beq	a2,a4,1508 <free+0x8c>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
    14d4:	fec53823          	sd	a2,-16(a0)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    14d8:	0087a603          	lw	a2,8(a5)
    14dc:	02061593          	slli	a1,a2,0x20
    14e0:	01c5d713          	srli	a4,a1,0x1c
    14e4:	00e78733          	add	a4,a5,a4
    14e8:	02e68c63          	beq	a3,a4,1520 <free+0xa4>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
    14ec:	00d7b023          	sd	a3,0(a5)
  } else
    p->s.ptr = bp;
  freep = p;
    14f0:	00001717          	auipc	a4,0x1
    14f4:	b2f73823          	sd	a5,-1232(a4) # 2020 <freep>
}
    14f8:	00813083          	ld	ra,8(sp)
    14fc:	00013403          	ld	s0,0(sp)
    1500:	01010113          	addi	sp,sp,16
    1504:	00008067          	ret
    bp->s.size += p->s.ptr->s.size;
    1508:	00862703          	lw	a4,8(a2)
    150c:	00b7073b          	addw	a4,a4,a1
    1510:	fee52c23          	sw	a4,-8(a0)
    bp->s.ptr = p->s.ptr->s.ptr;
    1514:	0007b703          	ld	a4,0(a5)
    1518:	00073603          	ld	a2,0(a4)
    151c:	fb9ff06f          	j	14d4 <free+0x58>
    p->s.size += bp->s.size;
    1520:	ff852703          	lw	a4,-8(a0)
    1524:	00c7073b          	addw	a4,a4,a2
    1528:	00e7a423          	sw	a4,8(a5)
    p->s.ptr = bp->s.ptr;
    152c:	ff053683          	ld	a3,-16(a0)
    1530:	fbdff06f          	j	14ec <free+0x70>

0000000000001534 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
    1534:	fc010113          	addi	sp,sp,-64
    1538:	02113c23          	sd	ra,56(sp)
    153c:	02813823          	sd	s0,48(sp)
    1540:	03213023          	sd	s2,32(sp)
    1544:	01313c23          	sd	s3,24(sp)
    1548:	04010413          	addi	s0,sp,64
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    154c:	02051993          	slli	s3,a0,0x20
    1550:	0209d993          	srli	s3,s3,0x20
    1554:	00f98993          	addi	s3,s3,15
    1558:	0049d993          	srli	s3,s3,0x4
    155c:	0019899b          	addiw	s3,s3,1
    1560:	00098913          	mv	s2,s3
  if((prevp = freep) == 0){
    1564:	00001517          	auipc	a0,0x1
    1568:	abc53503          	ld	a0,-1348(a0) # 2020 <freep>
    156c:	04050463          	beqz	a0,15b4 <malloc+0x80>
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1570:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1574:	0087a703          	lw	a4,8(a5)
    1578:	0d377a63          	bgeu	a4,s3,164c <malloc+0x118>
    157c:	02913423          	sd	s1,40(sp)
    1580:	01413823          	sd	s4,16(sp)
    1584:	01513423          	sd	s5,8(sp)
    1588:	01613023          	sd	s6,0(sp)
  if(nu < 4096)
    158c:	00098a13          	mv	s4,s3
    1590:	00001737          	lui	a4,0x1
    1594:	00e9f463          	bgeu	s3,a4,159c <malloc+0x68>
    1598:	00001a37          	lui	s4,0x1
    159c:	000a0b1b          	sext.w	s6,s4
  p = sbrk(nu * sizeof(Header));
    15a0:	004a1a1b          	slliw	s4,s4,0x4
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    15a4:	00001497          	auipc	s1,0x1
    15a8:	a7c48493          	addi	s1,s1,-1412 # 2020 <freep>
  if(p == SBRK_ERROR)
    15ac:	fff00a93          	li	s5,-1
    15b0:	05c0006f          	j	160c <malloc+0xd8>
    15b4:	02913423          	sd	s1,40(sp)
    15b8:	01413823          	sd	s4,16(sp)
    15bc:	01513423          	sd	s5,8(sp)
    15c0:	01613023          	sd	s6,0(sp)
    base.s.ptr = freep = prevp = &base;
    15c4:	00001797          	auipc	a5,0x1
    15c8:	b2c78793          	addi	a5,a5,-1236 # 20f0 <base>
    15cc:	00001717          	auipc	a4,0x1
    15d0:	a4f73a23          	sd	a5,-1452(a4) # 2020 <freep>
    15d4:	00f7b023          	sd	a5,0(a5)
    base.s.size = 0;
    15d8:	0007a423          	sw	zero,8(a5)
    if(p->s.size >= nunits){
    15dc:	fb1ff06f          	j	158c <malloc+0x58>
        prevp->s.ptr = p->s.ptr;
    15e0:	0007b703          	ld	a4,0(a5)
    15e4:	00e53023          	sd	a4,0(a0)
    15e8:	0800006f          	j	1668 <malloc+0x134>
  hp->s.size = nu;
    15ec:	01652423          	sw	s6,8(a0)
  free((void*)(hp + 1));
    15f0:	01050513          	addi	a0,a0,16
    15f4:	e89ff0ef          	jal	147c <free>
  return freep;
    15f8:	0004b503          	ld	a0,0(s1)
      if((p = morecore(nunits)) == 0)
    15fc:	08050863          	beqz	a0,168c <malloc+0x158>
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    1600:	00053783          	ld	a5,0(a0)
    if(p->s.size >= nunits){
    1604:	0087a703          	lw	a4,8(a5)
    1608:	03277a63          	bgeu	a4,s2,163c <malloc+0x108>
    if(p == freep)
    160c:	0004b703          	ld	a4,0(s1)
    1610:	00078513          	mv	a0,a5
    1614:	fef716e3          	bne	a4,a5,1600 <malloc+0xcc>
  p = sbrk(nu * sizeof(Header));
    1618:	000a0513          	mv	a0,s4
    161c:	ed8ff0ef          	jal	cf4 <sbrk>
  if(p == SBRK_ERROR)
    1620:	fd5516e3          	bne	a0,s5,15ec <malloc+0xb8>
        return 0;
    1624:	00000513          	li	a0,0
    1628:	02813483          	ld	s1,40(sp)
    162c:	01013a03          	ld	s4,16(sp)
    1630:	00813a83          	ld	s5,8(sp)
    1634:	00013b03          	ld	s6,0(sp)
    1638:	03c0006f          	j	1674 <malloc+0x140>
    163c:	02813483          	ld	s1,40(sp)
    1640:	01013a03          	ld	s4,16(sp)
    1644:	00813a83          	ld	s5,8(sp)
    1648:	00013b03          	ld	s6,0(sp)
      if(p->s.size == nunits)
    164c:	f8e90ae3          	beq	s2,a4,15e0 <malloc+0xac>
        p->s.size -= nunits;
    1650:	4137073b          	subw	a4,a4,s3
    1654:	00e7a423          	sw	a4,8(a5)
        p += p->s.size;
    1658:	02071693          	slli	a3,a4,0x20
    165c:	01c6d713          	srli	a4,a3,0x1c
    1660:	00e787b3          	add	a5,a5,a4
        p->s.size = nunits;
    1664:	0137a423          	sw	s3,8(a5)
      freep = prevp;
    1668:	00001717          	auipc	a4,0x1
    166c:	9aa73c23          	sd	a0,-1608(a4) # 2020 <freep>
      return (void*)(p + 1);
    1670:	01078513          	addi	a0,a5,16
  }
}
    1674:	03813083          	ld	ra,56(sp)
    1678:	03013403          	ld	s0,48(sp)
    167c:	02013903          	ld	s2,32(sp)
    1680:	01813983          	ld	s3,24(sp)
    1684:	04010113          	addi	sp,sp,64
    1688:	00008067          	ret
    168c:	02813483          	ld	s1,40(sp)
    1690:	01013a03          	ld	s4,16(sp)
    1694:	00813a83          	ld	s5,8(sp)
    1698:	00013b03          	ld	s6,0(sp)
    169c:	fd9ff06f          	j	1674 <malloc+0x140>
