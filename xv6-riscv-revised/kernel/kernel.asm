
kernel/kernel:     file format elf64-littleriscv


Disassembly of section .text:

0000000080000000 <_entry>:
_entry:
        # set up a stack for C.
        # stack0 is declared in start.c,
        # with a 4096-byte stack per CPU.
        # sp = stack0 + ((hartid + 1) * 4096)
        la sp, stack0
    80000000:	001fe117          	auipc	sp,0x1fe
    80000004:	b8010113          	addi	sp,sp,-1152 # 801fdb80 <stack0>
        li a0, 1024*4
    80000008:	00001537          	lui	a0,0x1
        csrr a1, mhartid
    8000000c:	f14025f3          	csrr	a1,mhartid
        addi a1, a1, 1
    80000010:	00158593          	addi	a1,a1,1
        mul a0, a0, a1
    80000014:	02b50533          	mul	a0,a0,a1
        add sp, sp, a0
    80000018:	00a10133          	add	sp,sp,a0
        # jump to start() in start.c
        call start
    8000001c:	068000ef          	jal	80000084 <start>

0000000080000020 <spin>:
spin:
        j spin
    80000020:	0000006f          	j	80000020 <spin>

0000000080000024 <timerinit>:
}

// ask each hart to generate timer interrupts.
void
timerinit()
{
    80000024:	ff010113          	addi	sp,sp,-16
    80000028:	00113423          	sd	ra,8(sp)
    8000002c:	00813023          	sd	s0,0(sp)
    80000030:	01010413          	addi	s0,sp,16
#define MIE_STIE (1L << 5) // supervisor timer
static inline uint64
r_mie()
{
  uint64 x;
  asm volatile("csrr %0, mie" : "=r"(x));
    80000034:	304027f3          	csrr	a5,mie
  // enable supervisor-mode timer interrupts.
  w_mie(r_mie() | MIE_STIE);
    80000038:	0207e793          	ori	a5,a5,32
}

static inline void
w_mie(uint64 x)
{
  asm volatile("csrw mie, %0" : : "r"(x));
    8000003c:	30479073          	csrw	mie,a5
static inline uint64
r_menvcfg()
{
  uint64 x;
  // asm volatile("csrr %0, menvcfg" : "=r" (x) );
  asm volatile("csrr %0, 0x30a" : "=r"(x));
    80000040:	30a027f3          	csrr	a5,0x30a
  
  // enable the sstc extension (i.e. stimecmp).
  w_menvcfg(r_menvcfg() | (1L << 63)); 
    80000044:	fff00713          	li	a4,-1
    80000048:	03f71713          	slli	a4,a4,0x3f
    8000004c:	00e7e7b3          	or	a5,a5,a4

static inline void
w_menvcfg(uint64 x)
{
  // asm volatile("csrw menvcfg, %0" : : "r" (x));
  asm volatile("csrw 0x30a, %0" : : "r"(x));
    80000050:	30a79073          	csrw	0x30a,a5

static inline uint64
r_mcounteren()
{
  uint64 x;
  asm volatile("csrr %0, mcounteren" : "=r"(x));
    80000054:	306027f3          	csrr	a5,mcounteren
  
  // allow supervisor to use stimecmp and time.
  w_mcounteren(r_mcounteren() | 2);
    80000058:	0027e793          	ori	a5,a5,2
  asm volatile("csrw mcounteren, %0" : : "r"(x));
    8000005c:	30679073          	csrw	mcounteren,a5
// machine-mode cycle counter
static inline uint64
r_time()
{
  uint64 x;
  asm volatile("csrr %0, time" : "=r"(x));
    80000060:	c01027f3          	rdtime	a5
  
  // ask for the very first timer interrupt.
  w_stimecmp(r_time() + 1000000);
    80000064:	000f4737          	lui	a4,0xf4
    80000068:	24070713          	addi	a4,a4,576 # f4240 <_binary_fs_img_size-0xffdc0>
    8000006c:	00e787b3          	add	a5,a5,a4
  asm volatile("csrw 0x14d, %0" : : "r"(x));
    80000070:	14d79073          	csrw	stimecmp,a5
}
    80000074:	00813083          	ld	ra,8(sp)
    80000078:	00013403          	ld	s0,0(sp)
    8000007c:	01010113          	addi	sp,sp,16
    80000080:	00008067          	ret

0000000080000084 <start>:
{
    80000084:	ff010113          	addi	sp,sp,-16
    80000088:	00113423          	sd	ra,8(sp)
    8000008c:	00813023          	sd	s0,0(sp)
    80000090:	01010413          	addi	s0,sp,16
  asm volatile("csrr %0, mstatus" : "=r"(x));
    80000094:	300027f3          	csrr	a5,mstatus
  x &= ~MSTATUS_MPP_MASK;
    80000098:	ffffe737          	lui	a4,0xffffe
    8000009c:	7ff70713          	addi	a4,a4,2047 # ffffffffffffe7ff <end+0xffffffff7fbf3a9f>
    800000a0:	00e7f7b3          	and	a5,a5,a4
  x |= MSTATUS_MPP_S;
    800000a4:	00001737          	lui	a4,0x1
    800000a8:	80070713          	addi	a4,a4,-2048 # 800 <_binary_fs_img_size-0x1f3800>
    800000ac:	00e7e7b3          	or	a5,a5,a4
  asm volatile("csrw mstatus, %0" : : "r"(x));
    800000b0:	30079073          	csrw	mstatus,a5
  asm volatile("csrw mepc, %0" : : "r"(x));
    800000b4:	00001797          	auipc	a5,0x1
    800000b8:	3dc78793          	addi	a5,a5,988 # 80001490 <main>
    800000bc:	34179073          	csrw	mepc,a5
  asm volatile("csrw satp, %0" : : "r"(x));
    800000c0:	00000793          	li	a5,0
    800000c4:	18079073          	csrw	satp,a5
  asm volatile("csrw medeleg, %0" : : "r"(x));
    800000c8:	000107b7          	lui	a5,0x10
    800000cc:	fff78793          	addi	a5,a5,-1 # ffff <_binary_fs_img_size-0x1e4001>
    800000d0:	30279073          	csrw	medeleg,a5
  asm volatile("csrw mideleg, %0" : : "r"(x));
    800000d4:	30379073          	csrw	mideleg,a5
  asm volatile("csrr %0, sie" : "=r"(x));
    800000d8:	104027f3          	csrr	a5,sie
  w_sie(r_sie() | SIE_SEIE | SIE_STIE);
    800000dc:	2207e793          	ori	a5,a5,544
  asm volatile("csrw sie, %0" : : "r"(x));
    800000e0:	10479073          	csrw	sie,a5
  asm volatile("csrw pmpaddr0, %0" : : "r"(x));
    800000e4:	fff00793          	li	a5,-1
    800000e8:	00a7d793          	srli	a5,a5,0xa
    800000ec:	3b079073          	csrw	pmpaddr0,a5
  asm volatile("csrw pmpcfg0, %0" : : "r"(x));
    800000f0:	00f00793          	li	a5,15
    800000f4:	3a079073          	csrw	pmpcfg0,a5
  timerinit();
    800000f8:	f2dff0ef          	jal	80000024 <timerinit>
  asm volatile("csrr %0, mhartid" : "=r"(x));
    800000fc:	f14027f3          	csrr	a5,mhartid
  w_tp(id);
    80000100:	0007879b          	sext.w	a5,a5
}

static inline void
w_tp(uint64 x)
{
  asm volatile("mv tp, %0" : : "r"(x));
    80000104:	00078213          	mv	tp,a5
  asm volatile("mret");
    80000108:	30200073          	mret
}
    8000010c:	00813083          	ld	ra,8(sp)
    80000110:	00013403          	ld	s0,0(sp)
    80000114:	01010113          	addi	sp,sp,16
    80000118:	00008067          	ret

000000008000011c <consolewrite>:
// user write() system calls to the console go here.
// uses sleep() and UART interrupts.
//
int
consolewrite(int user_src, uint64 src, int n)
{
    8000011c:	f8010113          	addi	sp,sp,-128
    80000120:	06113c23          	sd	ra,120(sp)
    80000124:	06813823          	sd	s0,112(sp)
    80000128:	06913423          	sd	s1,104(sp)
    8000012c:	08010413          	addi	s0,sp,128
  char buf[32]; // move batches from user space to uart.
  int i = 0;

  while(i < n){
    80000130:	0ac05c63          	blez	a2,800001e8 <consolewrite+0xcc>
    80000134:	07213023          	sd	s2,96(sp)
    80000138:	05313c23          	sd	s3,88(sp)
    8000013c:	05413823          	sd	s4,80(sp)
    80000140:	05513423          	sd	s5,72(sp)
    80000144:	05613023          	sd	s6,64(sp)
    80000148:	03713c23          	sd	s7,56(sp)
    8000014c:	03813823          	sd	s8,48(sp)
    80000150:	03913423          	sd	s9,40(sp)
    80000154:	03a13023          	sd	s10,32(sp)
    80000158:	00050b13          	mv	s6,a0
    8000015c:	00058b93          	mv	s7,a1
    80000160:	00060a13          	mv	s4,a2
  int i = 0;
    80000164:	00000493          	li	s1,0
    int nn = sizeof(buf);
    if(nn > n - i)
    80000168:	02000c93          	li	s9,32
    8000016c:	02000d13          	li	s10,32
      nn = n - i;
    if(either_copyin(buf, user_src, src+i, nn) == -1)
    80000170:	f8040a93          	addi	s5,s0,-128
    80000174:	fff00c13          	li	s8,-1
    80000178:	0340006f          	j	800001ac <consolewrite+0x90>
    if(nn > n - i)
    8000017c:	0009099b          	sext.w	s3,s2
    if(either_copyin(buf, user_src, src+i, nn) == -1)
    80000180:	00098693          	mv	a3,s3
    80000184:	01748633          	add	a2,s1,s7
    80000188:	000b0593          	mv	a1,s6
    8000018c:	000a8513          	mv	a0,s5
    80000190:	2d8030ef          	jal	80003468 <either_copyin>
    80000194:	05850e63          	beq	a0,s8,800001f0 <consolewrite+0xd4>
      break;
    uartwrite(buf, nn);
    80000198:	00098593          	mv	a1,s3
    8000019c:	000a8513          	mv	a0,s5
    800001a0:	2c1000ef          	jal	80000c60 <uartwrite>
    i += nn;
    800001a4:	009904bb          	addw	s1,s2,s1
  while(i < n){
    800001a8:	0144dc63          	bge	s1,s4,800001c0 <consolewrite+0xa4>
    if(nn > n - i)
    800001ac:	409a07bb          	subw	a5,s4,s1
    800001b0:	00078913          	mv	s2,a5
    800001b4:	fcfcd4e3          	bge	s9,a5,8000017c <consolewrite+0x60>
    800001b8:	000d0913          	mv	s2,s10
    800001bc:	fc1ff06f          	j	8000017c <consolewrite+0x60>
    800001c0:	06013903          	ld	s2,96(sp)
    800001c4:	05813983          	ld	s3,88(sp)
    800001c8:	05013a03          	ld	s4,80(sp)
    800001cc:	04813a83          	ld	s5,72(sp)
    800001d0:	04013b03          	ld	s6,64(sp)
    800001d4:	03813b83          	ld	s7,56(sp)
    800001d8:	03013c03          	ld	s8,48(sp)
    800001dc:	02813c83          	ld	s9,40(sp)
    800001e0:	02013d03          	ld	s10,32(sp)
    800001e4:	0300006f          	j	80000214 <consolewrite+0xf8>
  int i = 0;
    800001e8:	00000493          	li	s1,0
    800001ec:	0280006f          	j	80000214 <consolewrite+0xf8>
    800001f0:	06013903          	ld	s2,96(sp)
    800001f4:	05813983          	ld	s3,88(sp)
    800001f8:	05013a03          	ld	s4,80(sp)
    800001fc:	04813a83          	ld	s5,72(sp)
    80000200:	04013b03          	ld	s6,64(sp)
    80000204:	03813b83          	ld	s7,56(sp)
    80000208:	03013c03          	ld	s8,48(sp)
    8000020c:	02813c83          	ld	s9,40(sp)
    80000210:	02013d03          	ld	s10,32(sp)
  }

  return i;
}
    80000214:	00048513          	mv	a0,s1
    80000218:	07813083          	ld	ra,120(sp)
    8000021c:	07013403          	ld	s0,112(sp)
    80000220:	06813483          	ld	s1,104(sp)
    80000224:	08010113          	addi	sp,sp,128
    80000228:	00008067          	ret

000000008000022c <consoleread>:
// user_dst indicates whether dst is a user
// or kernel address.
//
int
consoleread(int user_dst, uint64 dst, int n)
{
    8000022c:	fa010113          	addi	sp,sp,-96
    80000230:	04113c23          	sd	ra,88(sp)
    80000234:	04813823          	sd	s0,80(sp)
    80000238:	04913423          	sd	s1,72(sp)
    8000023c:	05213023          	sd	s2,64(sp)
    80000240:	03313c23          	sd	s3,56(sp)
    80000244:	03413823          	sd	s4,48(sp)
    80000248:	03613023          	sd	s6,32(sp)
    8000024c:	01713c23          	sd	s7,24(sp)
    80000250:	06010413          	addi	s0,sp,96
    80000254:	00050b13          	mv	s6,a0
    80000258:	00058a13          	mv	s4,a1
    8000025c:	00060993          	mv	s3,a2
  uint target;
  int c;
  char cbuf;

  target = n;
    80000260:	00060b93          	mv	s7,a2
  acquire(&cons.lock);
    80000264:	00206517          	auipc	a0,0x206
    80000268:	91c50513          	addi	a0,a0,-1764 # 80205b80 <cons>
    8000026c:	5d5000ef          	jal	80001040 <acquire>
  while(n > 0){
    // wait until interrupt handler has put some
    // input into cons.buffer.
    while(cons.r == cons.w){
    80000270:	00206497          	auipc	s1,0x206
    80000274:	91048493          	addi	s1,s1,-1776 # 80205b80 <cons>
      if(killed(myproc())){
        release(&cons.lock);
        return -1;
      }
      sleep(&cons.r, &cons.lock);
    80000278:	00206917          	auipc	s2,0x206
    8000027c:	9a090913          	addi	s2,s2,-1632 # 80205c18 <cons+0x98>
  while(n > 0){
    80000280:	0f305c63          	blez	s3,80000378 <consoleread+0x14c>
    while(cons.r == cons.w){
    80000284:	0984a783          	lw	a5,152(s1)
    80000288:	09c4a703          	lw	a4,156(s1)
    8000028c:	0cf71c63          	bne	a4,a5,80000364 <consoleread+0x138>
      if(killed(myproc())){
    80000290:	364020ef          	jal	800025f4 <myproc>
    80000294:	7ad020ef          	jal	80003240 <killed>
    80000298:	08051063          	bnez	a0,80000318 <consoleread+0xec>
      sleep(&cons.r, &cons.lock);
    8000029c:	00048593          	mv	a1,s1
    800002a0:	00090513          	mv	a0,s2
    800002a4:	45d020ef          	jal	80002f00 <sleep>
    while(cons.r == cons.w){
    800002a8:	0984a783          	lw	a5,152(s1)
    800002ac:	09c4a703          	lw	a4,156(s1)
    800002b0:	fef700e3          	beq	a4,a5,80000290 <consoleread+0x64>
    800002b4:	03513423          	sd	s5,40(sp)
    }

    c = cons.buf[cons.r++ % INPUT_BUF_SIZE];
    800002b8:	00206717          	auipc	a4,0x206
    800002bc:	8c870713          	addi	a4,a4,-1848 # 80205b80 <cons>
    800002c0:	0017869b          	addiw	a3,a5,1
    800002c4:	08d72c23          	sw	a3,152(a4)
    800002c8:	07f7f693          	andi	a3,a5,127
    800002cc:	00d70733          	add	a4,a4,a3
    800002d0:	01874703          	lbu	a4,24(a4)
    800002d4:	00070a9b          	sext.w	s5,a4

    if(c == C('D')){  // end-of-file
    800002d8:	00400693          	li	a3,4
    800002dc:	06da8a63          	beq	s5,a3,80000350 <consoleread+0x124>
      }
      break;
    }

    // copy the input byte to the user-space buffer.
    cbuf = c;
    800002e0:	fae407a3          	sb	a4,-81(s0)
    if(either_copyout(user_dst, dst, &cbuf, 1) == -1)
    800002e4:	00100693          	li	a3,1
    800002e8:	faf40613          	addi	a2,s0,-81
    800002ec:	000a0593          	mv	a1,s4
    800002f0:	000b0513          	mv	a0,s6
    800002f4:	0f0030ef          	jal	800033e4 <either_copyout>
    800002f8:	fff00793          	li	a5,-1
    800002fc:	06f50c63          	beq	a0,a5,80000374 <consoleread+0x148>
      break;

    dst++;
    80000300:	001a0a13          	addi	s4,s4,1
    --n;
    80000304:	fff9899b          	addiw	s3,s3,-1

    if(c == '\n'){
    80000308:	00a00793          	li	a5,10
    8000030c:	08fa8063          	beq	s5,a5,8000038c <consoleread+0x160>
    80000310:	02813a83          	ld	s5,40(sp)
    80000314:	f6dff06f          	j	80000280 <consoleread+0x54>
        release(&cons.lock);
    80000318:	00206517          	auipc	a0,0x206
    8000031c:	86850513          	addi	a0,a0,-1944 # 80205b80 <cons>
    80000320:	5f9000ef          	jal	80001118 <release>
        return -1;
    80000324:	fff00513          	li	a0,-1
    }
  }
  release(&cons.lock);

  return target - n;
}
    80000328:	05813083          	ld	ra,88(sp)
    8000032c:	05013403          	ld	s0,80(sp)
    80000330:	04813483          	ld	s1,72(sp)
    80000334:	04013903          	ld	s2,64(sp)
    80000338:	03813983          	ld	s3,56(sp)
    8000033c:	03013a03          	ld	s4,48(sp)
    80000340:	02013b03          	ld	s6,32(sp)
    80000344:	01813b83          	ld	s7,24(sp)
    80000348:	06010113          	addi	sp,sp,96
    8000034c:	00008067          	ret
      if(n < target){
    80000350:	0179fe63          	bgeu	s3,s7,8000036c <consoleread+0x140>
        cons.r--;
    80000354:	00206717          	auipc	a4,0x206
    80000358:	8cf72223          	sw	a5,-1852(a4) # 80205c18 <cons+0x98>
    8000035c:	02813a83          	ld	s5,40(sp)
    80000360:	0180006f          	j	80000378 <consoleread+0x14c>
    80000364:	03513423          	sd	s5,40(sp)
    80000368:	f51ff06f          	j	800002b8 <consoleread+0x8c>
    8000036c:	02813a83          	ld	s5,40(sp)
    80000370:	0080006f          	j	80000378 <consoleread+0x14c>
    80000374:	02813a83          	ld	s5,40(sp)
  release(&cons.lock);
    80000378:	00206517          	auipc	a0,0x206
    8000037c:	80850513          	addi	a0,a0,-2040 # 80205b80 <cons>
    80000380:	599000ef          	jal	80001118 <release>
  return target - n;
    80000384:	413b853b          	subw	a0,s7,s3
    80000388:	fa1ff06f          	j	80000328 <consoleread+0xfc>
    8000038c:	02813a83          	ld	s5,40(sp)
    80000390:	fe9ff06f          	j	80000378 <consoleread+0x14c>

0000000080000394 <consputc>:
{
    80000394:	ff010113          	addi	sp,sp,-16
    80000398:	00113423          	sd	ra,8(sp)
    8000039c:	00813023          	sd	s0,0(sp)
    800003a0:	01010413          	addi	s0,sp,16
  if(c == BACKSPACE){
    800003a4:	10000793          	li	a5,256
    800003a8:	00f50c63          	beq	a0,a5,800003c0 <consputc+0x2c>
    uartputc_sync(c);
    800003ac:	031000ef          	jal	80000bdc <uartputc_sync>
}
    800003b0:	00813083          	ld	ra,8(sp)
    800003b4:	00013403          	ld	s0,0(sp)
    800003b8:	01010113          	addi	sp,sp,16
    800003bc:	00008067          	ret
    uartputc_sync('\b'); uartputc_sync(' '); uartputc_sync('\b');
    800003c0:	00800513          	li	a0,8
    800003c4:	019000ef          	jal	80000bdc <uartputc_sync>
    800003c8:	02000513          	li	a0,32
    800003cc:	011000ef          	jal	80000bdc <uartputc_sync>
    800003d0:	00800513          	li	a0,8
    800003d4:	009000ef          	jal	80000bdc <uartputc_sync>
    800003d8:	fd9ff06f          	j	800003b0 <consputc+0x1c>

00000000800003dc <consoleintr>:
// do erase/kill processing, append to cons.buf,
// wake up consoleread() if a whole line has arrived.
//
void
consoleintr(int c)
{
    800003dc:	fe010113          	addi	sp,sp,-32
    800003e0:	00113c23          	sd	ra,24(sp)
    800003e4:	00813823          	sd	s0,16(sp)
    800003e8:	00913423          	sd	s1,8(sp)
    800003ec:	02010413          	addi	s0,sp,32
    800003f0:	00050493          	mv	s1,a0
  acquire(&cons.lock);
    800003f4:	00205517          	auipc	a0,0x205
    800003f8:	78c50513          	addi	a0,a0,1932 # 80205b80 <cons>
    800003fc:	445000ef          	jal	80001040 <acquire>

  switch(c){
    80000400:	01500793          	li	a5,21
    80000404:	0af48e63          	beq	s1,a5,800004c0 <consoleintr+0xe4>
    80000408:	0297cc63          	blt	a5,s1,80000440 <consoleintr+0x64>
    8000040c:	00800793          	li	a5,8
    80000410:	10f48c63          	beq	s1,a5,80000528 <consoleintr+0x14c>
    80000414:	01000793          	li	a5,16
    80000418:	12f49e63          	bne	s1,a5,80000554 <consoleintr+0x178>
  case C('P'):  // Print process list.
    procdump();
    8000041c:	0d0030ef          	jal	800034ec <procdump>
      }
    }
    break;
  }
  
  release(&cons.lock);
    80000420:	00205517          	auipc	a0,0x205
    80000424:	76050513          	addi	a0,a0,1888 # 80205b80 <cons>
    80000428:	4f1000ef          	jal	80001118 <release>
}
    8000042c:	01813083          	ld	ra,24(sp)
    80000430:	01013403          	ld	s0,16(sp)
    80000434:	00813483          	ld	s1,8(sp)
    80000438:	02010113          	addi	sp,sp,32
    8000043c:	00008067          	ret
  switch(c){
    80000440:	07f00793          	li	a5,127
    80000444:	0ef48263          	beq	s1,a5,80000528 <consoleintr+0x14c>
    if(c != 0 && cons.e-cons.r < INPUT_BUF_SIZE){
    80000448:	00205717          	auipc	a4,0x205
    8000044c:	73870713          	addi	a4,a4,1848 # 80205b80 <cons>
    80000450:	0a072783          	lw	a5,160(a4)
    80000454:	09872703          	lw	a4,152(a4)
    80000458:	40e787bb          	subw	a5,a5,a4
    8000045c:	07f00713          	li	a4,127
    80000460:	fcf760e3          	bltu	a4,a5,80000420 <consoleintr+0x44>
      c = (c == '\r') ? '\n' : c;
    80000464:	00d00793          	li	a5,13
    80000468:	0ef48a63          	beq	s1,a5,8000055c <consoleintr+0x180>
      consputc(c);
    8000046c:	00048513          	mv	a0,s1
    80000470:	f25ff0ef          	jal	80000394 <consputc>
      cons.buf[cons.e++ % INPUT_BUF_SIZE] = c;
    80000474:	00205717          	auipc	a4,0x205
    80000478:	70c70713          	addi	a4,a4,1804 # 80205b80 <cons>
    8000047c:	0a072683          	lw	a3,160(a4)
    80000480:	0016879b          	addiw	a5,a3,1
    80000484:	00078613          	mv	a2,a5
    80000488:	0af72023          	sw	a5,160(a4)
    8000048c:	07f6f693          	andi	a3,a3,127
    80000490:	00d70733          	add	a4,a4,a3
    80000494:	00970c23          	sb	s1,24(a4)
      if(c == '\n' || c == C('D') || cons.e-cons.r == INPUT_BUF_SIZE){
    80000498:	ff648713          	addi	a4,s1,-10
    8000049c:	0e070863          	beqz	a4,8000058c <consoleintr+0x1b0>
    800004a0:	ffc48493          	addi	s1,s1,-4
    800004a4:	0e048463          	beqz	s1,8000058c <consoleintr+0x1b0>
    800004a8:	00205717          	auipc	a4,0x205
    800004ac:	77072703          	lw	a4,1904(a4) # 80205c18 <cons+0x98>
    800004b0:	40e787bb          	subw	a5,a5,a4
    800004b4:	08000713          	li	a4,128
    800004b8:	f6e794e3          	bne	a5,a4,80000420 <consoleintr+0x44>
    800004bc:	0d00006f          	j	8000058c <consoleintr+0x1b0>
    800004c0:	01213023          	sd	s2,0(sp)
    while(cons.e != cons.w &&
    800004c4:	00205717          	auipc	a4,0x205
    800004c8:	6bc70713          	addi	a4,a4,1724 # 80205b80 <cons>
    800004cc:	0a072783          	lw	a5,160(a4)
    800004d0:	09c72703          	lw	a4,156(a4)
          cons.buf[(cons.e-1) % INPUT_BUF_SIZE] != '\n'){
    800004d4:	00205497          	auipc	s1,0x205
    800004d8:	6ac48493          	addi	s1,s1,1708 # 80205b80 <cons>
    while(cons.e != cons.w &&
    800004dc:	00a00913          	li	s2,10
    800004e0:	02f70c63          	beq	a4,a5,80000518 <consoleintr+0x13c>
          cons.buf[(cons.e-1) % INPUT_BUF_SIZE] != '\n'){
    800004e4:	fff7879b          	addiw	a5,a5,-1
    800004e8:	07f7f713          	andi	a4,a5,127
    800004ec:	00e48733          	add	a4,s1,a4
    while(cons.e != cons.w &&
    800004f0:	01874703          	lbu	a4,24(a4)
    800004f4:	03270663          	beq	a4,s2,80000520 <consoleintr+0x144>
      cons.e--;
    800004f8:	0af4a023          	sw	a5,160(s1)
      consputc(BACKSPACE);
    800004fc:	10000513          	li	a0,256
    80000500:	e95ff0ef          	jal	80000394 <consputc>
    while(cons.e != cons.w &&
    80000504:	0a04a783          	lw	a5,160(s1)
    80000508:	09c4a703          	lw	a4,156(s1)
    8000050c:	fcf71ce3          	bne	a4,a5,800004e4 <consoleintr+0x108>
    80000510:	00013903          	ld	s2,0(sp)
    80000514:	f0dff06f          	j	80000420 <consoleintr+0x44>
    80000518:	00013903          	ld	s2,0(sp)
    8000051c:	f05ff06f          	j	80000420 <consoleintr+0x44>
    80000520:	00013903          	ld	s2,0(sp)
    80000524:	efdff06f          	j	80000420 <consoleintr+0x44>
    if(cons.e != cons.w){
    80000528:	00205717          	auipc	a4,0x205
    8000052c:	65870713          	addi	a4,a4,1624 # 80205b80 <cons>
    80000530:	0a072783          	lw	a5,160(a4)
    80000534:	09c72703          	lw	a4,156(a4)
    80000538:	eef704e3          	beq	a4,a5,80000420 <consoleintr+0x44>
      cons.e--;
    8000053c:	fff7879b          	addiw	a5,a5,-1
    80000540:	00205717          	auipc	a4,0x205
    80000544:	6ef72023          	sw	a5,1760(a4) # 80205c20 <cons+0xa0>
      consputc(BACKSPACE);
    80000548:	10000513          	li	a0,256
    8000054c:	e49ff0ef          	jal	80000394 <consputc>
    80000550:	ed1ff06f          	j	80000420 <consoleintr+0x44>
    if(c != 0 && cons.e-cons.r < INPUT_BUF_SIZE){
    80000554:	ec0486e3          	beqz	s1,80000420 <consoleintr+0x44>
    80000558:	ef1ff06f          	j	80000448 <consoleintr+0x6c>
      consputc(c);
    8000055c:	00a00513          	li	a0,10
    80000560:	e35ff0ef          	jal	80000394 <consputc>
      cons.buf[cons.e++ % INPUT_BUF_SIZE] = c;
    80000564:	00205797          	auipc	a5,0x205
    80000568:	61c78793          	addi	a5,a5,1564 # 80205b80 <cons>
    8000056c:	0a07a703          	lw	a4,160(a5)
    80000570:	0017069b          	addiw	a3,a4,1
    80000574:	00068613          	mv	a2,a3
    80000578:	0ad7a023          	sw	a3,160(a5)
    8000057c:	07f77713          	andi	a4,a4,127
    80000580:	00e787b3          	add	a5,a5,a4
    80000584:	00a00713          	li	a4,10
    80000588:	00e78c23          	sb	a4,24(a5)
        cons.w = cons.e;
    8000058c:	00205797          	auipc	a5,0x205
    80000590:	68c7a823          	sw	a2,1680(a5) # 80205c1c <cons+0x9c>
        wakeup(&cons.r);
    80000594:	00205517          	auipc	a0,0x205
    80000598:	68450513          	addi	a0,a0,1668 # 80205c18 <cons+0x98>
    8000059c:	1dd020ef          	jal	80002f78 <wakeup>
    800005a0:	e81ff06f          	j	80000420 <consoleintr+0x44>

00000000800005a4 <consoleinit>:

void
consoleinit(void)
{
    800005a4:	ff010113          	addi	sp,sp,-16
    800005a8:	00113423          	sd	ra,8(sp)
    800005ac:	00813023          	sd	s0,0(sp)
    800005b0:	01010413          	addi	s0,sp,16
  initlock(&cons.lock, "cons");
    800005b4:	00009597          	auipc	a1,0x9
    800005b8:	a4c58593          	addi	a1,a1,-1460 # 80009000 <etext>
    800005bc:	00205517          	auipc	a0,0x205
    800005c0:	5c450513          	addi	a0,a0,1476 # 80205b80 <cons>
    800005c4:	199000ef          	jal	80000f5c <initlock>

  uartinit();
    800005c8:	5a8000ef          	jal	80000b70 <uartinit>

  // connect read and write system calls
  // to consoleread and consolewrite.
  devsw[CONSOLE].read = consoleread;
    800005cc:	00215797          	auipc	a5,0x215
    800005d0:	72478793          	addi	a5,a5,1828 # 80215cf0 <devsw>
    800005d4:	00000717          	auipc	a4,0x0
    800005d8:	c5870713          	addi	a4,a4,-936 # 8000022c <consoleread>
    800005dc:	00e7b823          	sd	a4,16(a5)
  devsw[CONSOLE].write = consolewrite;
    800005e0:	00000717          	auipc	a4,0x0
    800005e4:	b3c70713          	addi	a4,a4,-1220 # 8000011c <consolewrite>
    800005e8:	00e7bc23          	sd	a4,24(a5)
}
    800005ec:	00813083          	ld	ra,8(sp)
    800005f0:	00013403          	ld	s0,0(sp)
    800005f4:	01010113          	addi	sp,sp,16
    800005f8:	00008067          	ret

00000000800005fc <printint>:

static char digits[] = "0123456789abcdef";

static void
printint(long long xx, int base, int sign)
{
    800005fc:	fc010113          	addi	sp,sp,-64
    80000600:	02113c23          	sd	ra,56(sp)
    80000604:	02813823          	sd	s0,48(sp)
    80000608:	03213023          	sd	s2,32(sp)
    8000060c:	04010413          	addi	s0,sp,64
  char buf[20];
  int i;
  unsigned long long x;

  if(sign && (sign = (xx < 0)))
    80000610:	00060463          	beqz	a2,80000618 <printint+0x1c>
    80000614:	0a054663          	bltz	a0,800006c0 <printint+0xc4>
    x = -xx;
  else
    x = xx;
    80000618:	00000313          	li	t1,0

  i = 0;
    8000061c:	fc840913          	addi	s2,s0,-56
    x = xx;
    80000620:	00090693          	mv	a3,s2
  i = 0;
    80000624:	00000713          	li	a4,0
  do {
    buf[i++] = digits[x % base];
    80000628:	00009817          	auipc	a6,0x9
    8000062c:	40880813          	addi	a6,a6,1032 # 80009a30 <digits>
    80000630:	00070893          	mv	a7,a4
    80000634:	0017061b          	addiw	a2,a4,1
    80000638:	00060713          	mv	a4,a2
    8000063c:	02b577b3          	remu	a5,a0,a1
    80000640:	00f807b3          	add	a5,a6,a5
    80000644:	0007c783          	lbu	a5,0(a5)
    80000648:	00f68023          	sb	a5,0(a3)
  } while((x /= base) != 0);
    8000064c:	00050793          	mv	a5,a0
    80000650:	02b55533          	divu	a0,a0,a1
    80000654:	00168693          	addi	a3,a3,1
    80000658:	fcb7fce3          	bgeu	a5,a1,80000630 <printint+0x34>

  if(sign)
    8000065c:	00030c63          	beqz	t1,80000674 <printint+0x78>
    buf[i++] = '-';
    80000660:	fe060793          	addi	a5,a2,-32
    80000664:	00878633          	add	a2,a5,s0
    80000668:	02d00793          	li	a5,45
    8000066c:	fef60423          	sb	a5,-24(a2)
    80000670:	0028871b          	addiw	a4,a7,2

  while(--i >= 0)
    80000674:	02e05c63          	blez	a4,800006ac <printint+0xb0>
    80000678:	02913423          	sd	s1,40(sp)
    8000067c:	fff7071b          	addiw	a4,a4,-1
    80000680:	00e904b3          	add	s1,s2,a4
    80000684:	fff90913          	addi	s2,s2,-1
    80000688:	00e90933          	add	s2,s2,a4
    8000068c:	02071713          	slli	a4,a4,0x20
    80000690:	02075713          	srli	a4,a4,0x20
    80000694:	40e90933          	sub	s2,s2,a4
    consputc(buf[i]);
    80000698:	0004c503          	lbu	a0,0(s1)
    8000069c:	cf9ff0ef          	jal	80000394 <consputc>
  while(--i >= 0)
    800006a0:	fff48493          	addi	s1,s1,-1
    800006a4:	ff249ae3          	bne	s1,s2,80000698 <printint+0x9c>
    800006a8:	02813483          	ld	s1,40(sp)
}
    800006ac:	03813083          	ld	ra,56(sp)
    800006b0:	03013403          	ld	s0,48(sp)
    800006b4:	02013903          	ld	s2,32(sp)
    800006b8:	04010113          	addi	sp,sp,64
    800006bc:	00008067          	ret
    x = -xx;
    800006c0:	40a00533          	neg	a0,a0
  if(sign && (sign = (xx < 0)))
    800006c4:	00100313          	li	t1,1
    x = -xx;
    800006c8:	f55ff06f          	j	8000061c <printint+0x20>

00000000800006cc <printf>:
}

// Print to the console.
int
printf(char *fmt, ...)
{
    800006cc:	f4010113          	addi	sp,sp,-192
    800006d0:	06113c23          	sd	ra,120(sp)
    800006d4:	06813823          	sd	s0,112(sp)
    800006d8:	07213023          	sd	s2,96(sp)
    800006dc:	08010413          	addi	s0,sp,128
    800006e0:	00050913          	mv	s2,a0
    800006e4:	00b43423          	sd	a1,8(s0)
    800006e8:	00c43823          	sd	a2,16(s0)
    800006ec:	00d43c23          	sd	a3,24(s0)
    800006f0:	02e43023          	sd	a4,32(s0)
    800006f4:	02f43423          	sd	a5,40(s0)
    800006f8:	03043823          	sd	a6,48(s0)
    800006fc:	03143c23          	sd	a7,56(s0)
  va_list ap;
  int i, cx, c0, c1, c2;
  char *s;

  if(panicking == 0)
    80000700:	001fd797          	auipc	a5,0x1fd
    80000704:	4547a783          	lw	a5,1108(a5) # 801fdb54 <panicking>
    80000708:	04078c63          	beqz	a5,80000760 <printf+0x94>
    acquire(&pr.lock);

  va_start(ap, fmt);
    8000070c:	00840793          	addi	a5,s0,8
    80000710:	f8f43423          	sd	a5,-120(s0)
  for(i = 0; (cx = fmt[i] & 0xff) != 0; i++){
    80000714:	00094503          	lbu	a0,0(s2)
    80000718:	2c050663          	beqz	a0,800009e4 <printf+0x318>
    8000071c:	06913423          	sd	s1,104(sp)
    80000720:	05313c23          	sd	s3,88(sp)
    80000724:	05413823          	sd	s4,80(sp)
    80000728:	05513423          	sd	s5,72(sp)
    8000072c:	05613023          	sd	s6,64(sp)
    80000730:	03713c23          	sd	s7,56(sp)
    80000734:	03813823          	sd	s8,48(sp)
    80000738:	03a13023          	sd	s10,32(sp)
    8000073c:	01b13c23          	sd	s11,24(sp)
    80000740:	00000a13          	li	s4,0
    if(cx != '%'){
    80000744:	02500993          	li	s3,37
      printint(va_arg(ap, uint64), 10, 1);
      i += 1;
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'd'){
      printint(va_arg(ap, uint64), 10, 1);
      i += 2;
    } else if(c0 == 'u'){
    80000748:	07500c13          	li	s8,117
      printint(va_arg(ap, uint64), 10, 0);
      i += 1;
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'u'){
      printint(va_arg(ap, uint64), 10, 0);
      i += 2;
    } else if(c0 == 'x'){
    8000074c:	07800d13          	li	s10,120
      printint(va_arg(ap, uint64), 16, 0);
      i += 1;
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'x'){
      printint(va_arg(ap, uint64), 16, 0);
      i += 2;
    } else if(c0 == 'p'){
    80000750:	07000d93          	li	s11,112
      printint(va_arg(ap, uint64), 10, 0);
    80000754:	00a00b13          	li	s6,10
    if(c0 == 'd'){
    80000758:	06400b93          	li	s7,100
    8000075c:	0300006f          	j	8000078c <printf+0xc0>
    acquire(&pr.lock);
    80000760:	00205517          	auipc	a0,0x205
    80000764:	4c850513          	addi	a0,a0,1224 # 80205c28 <pr>
    80000768:	0d9000ef          	jal	80001040 <acquire>
    8000076c:	fa1ff06f          	j	8000070c <printf+0x40>
      consputc(cx);
    80000770:	c25ff0ef          	jal	80000394 <consputc>
      continue;
    80000774:	000a0493          	mv	s1,s4
  for(i = 0; (cx = fmt[i] & 0xff) != 0; i++){
    80000778:	0014849b          	addiw	s1,s1,1
    8000077c:	00048a13          	mv	s4,s1
    80000780:	009904b3          	add	s1,s2,s1
    80000784:	0004c503          	lbu	a0,0(s1)
    80000788:	22050c63          	beqz	a0,800009c0 <printf+0x2f4>
    if(cx != '%'){
    8000078c:	ff3512e3          	bne	a0,s3,80000770 <printf+0xa4>
    i++;
    80000790:	001a079b          	addiw	a5,s4,1
    80000794:	00078493          	mv	s1,a5
    c0 = fmt[i+0] & 0xff;
    80000798:	00f90733          	add	a4,s2,a5
    8000079c:	00074a83          	lbu	s5,0(a4)
    if(c0) c1 = fmt[i+1] & 0xff;
    800007a0:	2a0a8c63          	beqz	s5,80000a58 <printf+0x38c>
    800007a4:	00174683          	lbu	a3,1(a4)
    if(c1) c2 = fmt[i+2] & 0xff;
    800007a8:	28068c63          	beqz	a3,80000a40 <printf+0x374>
    if(c0 == 'd'){
    800007ac:	037a8e63          	beq	s5,s7,800007e8 <printf+0x11c>
    } else if(c0 == 'l' && c1 == 'd'){
    800007b0:	f94a8713          	addi	a4,s5,-108
    800007b4:	00173713          	seqz	a4,a4
    800007b8:	f9c68613          	addi	a2,a3,-100
    800007bc:	04061663          	bnez	a2,80000808 <printf+0x13c>
    800007c0:	04070463          	beqz	a4,80000808 <printf+0x13c>
      printint(va_arg(ap, uint64), 10, 1);
    800007c4:	f8843783          	ld	a5,-120(s0)
    800007c8:	00878713          	addi	a4,a5,8
    800007cc:	f8e43423          	sd	a4,-120(s0)
    800007d0:	00100613          	li	a2,1
    800007d4:	000b0593          	mv	a1,s6
    800007d8:	0007b503          	ld	a0,0(a5)
    800007dc:	e21ff0ef          	jal	800005fc <printint>
      i += 1;
    800007e0:	002a049b          	addiw	s1,s4,2
    800007e4:	f95ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, int), 10, 1);
    800007e8:	f8843783          	ld	a5,-120(s0)
    800007ec:	00878713          	addi	a4,a5,8
    800007f0:	f8e43423          	sd	a4,-120(s0)
    800007f4:	00100613          	li	a2,1
    800007f8:	000b0593          	mv	a1,s6
    800007fc:	0007a503          	lw	a0,0(a5)
    80000800:	dfdff0ef          	jal	800005fc <printint>
    80000804:	f75ff06f          	j	80000778 <printf+0xac>
    if(c1) c2 = fmt[i+2] & 0xff;
    80000808:	00f907b3          	add	a5,s2,a5
    8000080c:	00068613          	mv	a2,a3
    80000810:	0027c683          	lbu	a3,2(a5)
    80000814:	2540006f          	j	80000a68 <printf+0x39c>
      printint(va_arg(ap, uint64), 10, 1);
    80000818:	f8843783          	ld	a5,-120(s0)
    8000081c:	00878713          	addi	a4,a5,8
    80000820:	f8e43423          	sd	a4,-120(s0)
    80000824:	00100613          	li	a2,1
    80000828:	00a00593          	li	a1,10
    8000082c:	0007b503          	ld	a0,0(a5)
    80000830:	dcdff0ef          	jal	800005fc <printint>
      i += 2;
    80000834:	003a049b          	addiw	s1,s4,3
    80000838:	f41ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint32), 10, 0);
    8000083c:	f8843783          	ld	a5,-120(s0)
    80000840:	00878713          	addi	a4,a5,8
    80000844:	f8e43423          	sd	a4,-120(s0)
    80000848:	00000613          	li	a2,0
    8000084c:	000b0593          	mv	a1,s6
    80000850:	0007e503          	lwu	a0,0(a5)
    80000854:	da9ff0ef          	jal	800005fc <printint>
    80000858:	f21ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint64), 10, 0);
    8000085c:	f8843783          	ld	a5,-120(s0)
    80000860:	00878713          	addi	a4,a5,8
    80000864:	f8e43423          	sd	a4,-120(s0)
    80000868:	00000613          	li	a2,0
    8000086c:	000b0593          	mv	a1,s6
    80000870:	0007b503          	ld	a0,0(a5)
    80000874:	d89ff0ef          	jal	800005fc <printint>
      i += 1;
    80000878:	002a049b          	addiw	s1,s4,2
    8000087c:	efdff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint64), 10, 0);
    80000880:	f8843783          	ld	a5,-120(s0)
    80000884:	00878713          	addi	a4,a5,8
    80000888:	f8e43423          	sd	a4,-120(s0)
    8000088c:	00000613          	li	a2,0
    80000890:	00a00593          	li	a1,10
    80000894:	0007b503          	ld	a0,0(a5)
    80000898:	d65ff0ef          	jal	800005fc <printint>
      i += 2;
    8000089c:	003a049b          	addiw	s1,s4,3
    800008a0:	ed9ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint32), 16, 0);
    800008a4:	f8843783          	ld	a5,-120(s0)
    800008a8:	00878713          	addi	a4,a5,8
    800008ac:	f8e43423          	sd	a4,-120(s0)
    800008b0:	00000613          	li	a2,0
    800008b4:	01000593          	li	a1,16
    800008b8:	0007e503          	lwu	a0,0(a5)
    800008bc:	d41ff0ef          	jal	800005fc <printint>
    800008c0:	eb9ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint64), 16, 0);
    800008c4:	f8843783          	ld	a5,-120(s0)
    800008c8:	00878713          	addi	a4,a5,8
    800008cc:	f8e43423          	sd	a4,-120(s0)
    800008d0:	01000593          	li	a1,16
    800008d4:	0007b503          	ld	a0,0(a5)
    800008d8:	d25ff0ef          	jal	800005fc <printint>
      i += 1;
    800008dc:	002a049b          	addiw	s1,s4,2
    800008e0:	e99ff06f          	j	80000778 <printf+0xac>
      printint(va_arg(ap, uint64), 16, 0);
    800008e4:	f8843783          	ld	a5,-120(s0)
    800008e8:	00878713          	addi	a4,a5,8
    800008ec:	f8e43423          	sd	a4,-120(s0)
    800008f0:	00000613          	li	a2,0
    800008f4:	01000593          	li	a1,16
    800008f8:	0007b503          	ld	a0,0(a5)
    800008fc:	d01ff0ef          	jal	800005fc <printint>
      i += 2;
    80000900:	003a049b          	addiw	s1,s4,3
    80000904:	e75ff06f          	j	80000778 <printf+0xac>
    80000908:	03913423          	sd	s9,40(sp)
      printptr(va_arg(ap, uint64));
    8000090c:	f8843783          	ld	a5,-120(s0)
    80000910:	00878713          	addi	a4,a5,8
    80000914:	f8e43423          	sd	a4,-120(s0)
    80000918:	0007ba83          	ld	s5,0(a5)
  consputc('0');
    8000091c:	03000513          	li	a0,48
    80000920:	a75ff0ef          	jal	80000394 <consputc>
  consputc('x');
    80000924:	07800513          	li	a0,120
    80000928:	a6dff0ef          	jal	80000394 <consputc>
    8000092c:	01000a13          	li	s4,16
    consputc(digits[x >> (sizeof(uint64) * 8 - 4)]);
    80000930:	00009c97          	auipc	s9,0x9
    80000934:	100c8c93          	addi	s9,s9,256 # 80009a30 <digits>
    80000938:	03cad793          	srli	a5,s5,0x3c
    8000093c:	00fc87b3          	add	a5,s9,a5
    80000940:	0007c503          	lbu	a0,0(a5)
    80000944:	a51ff0ef          	jal	80000394 <consputc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
    80000948:	004a9a93          	slli	s5,s5,0x4
    8000094c:	fffa0a1b          	addiw	s4,s4,-1
    80000950:	fe0a14e3          	bnez	s4,80000938 <printf+0x26c>
    80000954:	02813c83          	ld	s9,40(sp)
    80000958:	e21ff06f          	j	80000778 <printf+0xac>
    } else if(c0 == 'c'){
      consputc(va_arg(ap, uint));
    8000095c:	f8843783          	ld	a5,-120(s0)
    80000960:	00878713          	addi	a4,a5,8
    80000964:	f8e43423          	sd	a4,-120(s0)
    80000968:	0007a503          	lw	a0,0(a5)
    8000096c:	a29ff0ef          	jal	80000394 <consputc>
    80000970:	e09ff06f          	j	80000778 <printf+0xac>
    } else if(c0 == 's'){
      if((s = va_arg(ap, char*)) == 0)
    80000974:	f8843783          	ld	a5,-120(s0)
    80000978:	00878713          	addi	a4,a5,8
    8000097c:	f8e43423          	sd	a4,-120(s0)
    80000980:	0007ba03          	ld	s4,0(a5)
    80000984:	020a0063          	beqz	s4,800009a4 <printf+0x2d8>
        s = "(null)";
      for(; *s; s++)
    80000988:	000a4503          	lbu	a0,0(s4)
    8000098c:	de0506e3          	beqz	a0,80000778 <printf+0xac>
        consputc(*s);
    80000990:	a05ff0ef          	jal	80000394 <consputc>
      for(; *s; s++)
    80000994:	001a0a13          	addi	s4,s4,1
    80000998:	000a4503          	lbu	a0,0(s4)
    8000099c:	fe051ae3          	bnez	a0,80000990 <printf+0x2c4>
    800009a0:	dd9ff06f          	j	80000778 <printf+0xac>
        s = "(null)";
    800009a4:	00008a17          	auipc	s4,0x8
    800009a8:	664a0a13          	addi	s4,s4,1636 # 80009008 <etext+0x8>
      for(; *s; s++)
    800009ac:	02800513          	li	a0,40
    800009b0:	fe1ff06f          	j	80000990 <printf+0x2c4>
    } else if(c0 == '%'){
      consputc('%');
    800009b4:	000a8513          	mv	a0,s5
    800009b8:	9ddff0ef          	jal	80000394 <consputc>
    800009bc:	dbdff06f          	j	80000778 <printf+0xac>
    800009c0:	06813483          	ld	s1,104(sp)
    800009c4:	05813983          	ld	s3,88(sp)
    800009c8:	05013a03          	ld	s4,80(sp)
    800009cc:	04813a83          	ld	s5,72(sp)
    800009d0:	04013b03          	ld	s6,64(sp)
    800009d4:	03813b83          	ld	s7,56(sp)
    800009d8:	03013c03          	ld	s8,48(sp)
    800009dc:	02013d03          	ld	s10,32(sp)
    800009e0:	01813d83          	ld	s11,24(sp)
    }

  }
  va_end(ap);

  if(panicking == 0)
    800009e4:	001fd797          	auipc	a5,0x1fd
    800009e8:	1707a783          	lw	a5,368(a5) # 801fdb54 <panicking>
    800009ec:	04078263          	beqz	a5,80000a30 <printf+0x364>
    release(&pr.lock);

  return 0;
}
    800009f0:	00000513          	li	a0,0
    800009f4:	07813083          	ld	ra,120(sp)
    800009f8:	07013403          	ld	s0,112(sp)
    800009fc:	06013903          	ld	s2,96(sp)
    80000a00:	0c010113          	addi	sp,sp,192
    80000a04:	00008067          	ret
    80000a08:	06813483          	ld	s1,104(sp)
    80000a0c:	05813983          	ld	s3,88(sp)
    80000a10:	05013a03          	ld	s4,80(sp)
    80000a14:	04813a83          	ld	s5,72(sp)
    80000a18:	04013b03          	ld	s6,64(sp)
    80000a1c:	03813b83          	ld	s7,56(sp)
    80000a20:	03013c03          	ld	s8,48(sp)
    80000a24:	02013d03          	ld	s10,32(sp)
    80000a28:	01813d83          	ld	s11,24(sp)
    80000a2c:	fb9ff06f          	j	800009e4 <printf+0x318>
    release(&pr.lock);
    80000a30:	00205517          	auipc	a0,0x205
    80000a34:	1f850513          	addi	a0,a0,504 # 80205c28 <pr>
    80000a38:	6e0000ef          	jal	80001118 <release>
  return 0;
    80000a3c:	fb5ff06f          	j	800009f0 <printf+0x324>
    if(c0 == 'd'){
    80000a40:	db7a84e3          	beq	s5,s7,800007e8 <printf+0x11c>
    } else if(c0 == 'l' && c1 == 'd'){
    80000a44:	f94a8713          	addi	a4,s5,-108
    80000a48:	00173713          	seqz	a4,a4
    80000a4c:	00068613          	mv	a2,a3
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'd'){
    80000a50:	00000793          	li	a5,0
    80000a54:	02c0006f          	j	80000a80 <printf+0x3b4>
    } else if(c0 == 'l' && c1 == 'd'){
    80000a58:	f94a8713          	addi	a4,s5,-108
    80000a5c:	00173713          	seqz	a4,a4
    c1 = c2 = 0;
    80000a60:	000a8613          	mv	a2,s5
    80000a64:	000a8693          	mv	a3,s5
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'd'){
    80000a68:	f9460793          	addi	a5,a2,-108
    80000a6c:	0017b793          	seqz	a5,a5
    80000a70:	00f777b3          	and	a5,a4,a5
    80000a74:	f9c68593          	addi	a1,a3,-100
    80000a78:	00059463          	bnez	a1,80000a80 <printf+0x3b4>
    80000a7c:	d8079ee3          	bnez	a5,80000818 <printf+0x14c>
    } else if(c0 == 'u'){
    80000a80:	db8a8ee3          	beq	s5,s8,8000083c <printf+0x170>
    } else if(c0 == 'l' && c1 == 'u'){
    80000a84:	f8b60593          	addi	a1,a2,-117
    80000a88:	00059463          	bnez	a1,80000a90 <printf+0x3c4>
    80000a8c:	dc0718e3          	bnez	a4,8000085c <printf+0x190>
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'u'){
    80000a90:	f8b68593          	addi	a1,a3,-117
    80000a94:	00059463          	bnez	a1,80000a9c <printf+0x3d0>
    80000a98:	de0794e3          	bnez	a5,80000880 <printf+0x1b4>
    } else if(c0 == 'x'){
    80000a9c:	e1aa84e3          	beq	s5,s10,800008a4 <printf+0x1d8>
    } else if(c0 == 'l' && c1 == 'x'){
    80000aa0:	f8860613          	addi	a2,a2,-120
    80000aa4:	00061463          	bnez	a2,80000aac <printf+0x3e0>
    80000aa8:	e0071ee3          	bnez	a4,800008c4 <printf+0x1f8>
    } else if(c0 == 'l' && c1 == 'l' && c2 == 'x'){
    80000aac:	f8868693          	addi	a3,a3,-120
    80000ab0:	00069463          	bnez	a3,80000ab8 <printf+0x3ec>
    80000ab4:	e20798e3          	bnez	a5,800008e4 <printf+0x218>
    } else if(c0 == 'p'){
    80000ab8:	e5ba88e3          	beq	s5,s11,80000908 <printf+0x23c>
    } else if(c0 == 'c'){
    80000abc:	06300793          	li	a5,99
    80000ac0:	e8fa8ee3          	beq	s5,a5,8000095c <printf+0x290>
    } else if(c0 == 's'){
    80000ac4:	07300793          	li	a5,115
    80000ac8:	eafa86e3          	beq	s5,a5,80000974 <printf+0x2a8>
    } else if(c0 == '%'){
    80000acc:	02500793          	li	a5,37
    80000ad0:	eefa82e3          	beq	s5,a5,800009b4 <printf+0x2e8>
    } else if(c0 == 0){
    80000ad4:	f20a8ae3          	beqz	s5,80000a08 <printf+0x33c>
      consputc('%');
    80000ad8:	02500513          	li	a0,37
    80000adc:	8b9ff0ef          	jal	80000394 <consputc>
      consputc(c0);
    80000ae0:	000a8513          	mv	a0,s5
    80000ae4:	8b1ff0ef          	jal	80000394 <consputc>
    80000ae8:	c91ff06f          	j	80000778 <printf+0xac>

0000000080000aec <panic>:

void
panic(char *s)
{
    80000aec:	fe010113          	addi	sp,sp,-32
    80000af0:	00113c23          	sd	ra,24(sp)
    80000af4:	00813823          	sd	s0,16(sp)
    80000af8:	00913423          	sd	s1,8(sp)
    80000afc:	01213023          	sd	s2,0(sp)
    80000b00:	02010413          	addi	s0,sp,32
    80000b04:	00050913          	mv	s2,a0
  panicking = 1;
    80000b08:	00100493          	li	s1,1
    80000b0c:	001fd797          	auipc	a5,0x1fd
    80000b10:	0497a423          	sw	s1,72(a5) # 801fdb54 <panicking>
  printf("panic: ");
    80000b14:	00008517          	auipc	a0,0x8
    80000b18:	50450513          	addi	a0,a0,1284 # 80009018 <etext+0x18>
    80000b1c:	bb1ff0ef          	jal	800006cc <printf>
  printf("%s\n", s);
    80000b20:	00090593          	mv	a1,s2
    80000b24:	00008517          	auipc	a0,0x8
    80000b28:	4fc50513          	addi	a0,a0,1276 # 80009020 <etext+0x20>
    80000b2c:	ba1ff0ef          	jal	800006cc <printf>
  panicked = 1; // freeze uart output from other CPUs
    80000b30:	001fd797          	auipc	a5,0x1fd
    80000b34:	0297a023          	sw	s1,32(a5) # 801fdb50 <panicked>
  for(;;)
    80000b38:	0000006f          	j	80000b38 <panic+0x4c>

0000000080000b3c <printfinit>:
    ;
}

void
printfinit(void)
{
    80000b3c:	ff010113          	addi	sp,sp,-16
    80000b40:	00113423          	sd	ra,8(sp)
    80000b44:	00813023          	sd	s0,0(sp)
    80000b48:	01010413          	addi	s0,sp,16
  initlock(&pr.lock, "pr");
    80000b4c:	00008597          	auipc	a1,0x8
    80000b50:	4dc58593          	addi	a1,a1,1244 # 80009028 <etext+0x28>
    80000b54:	00205517          	auipc	a0,0x205
    80000b58:	0d450513          	addi	a0,a0,212 # 80205c28 <pr>
    80000b5c:	400000ef          	jal	80000f5c <initlock>
}
    80000b60:	00813083          	ld	ra,8(sp)
    80000b64:	00013403          	ld	s0,0(sp)
    80000b68:	01010113          	addi	sp,sp,16
    80000b6c:	00008067          	ret

0000000080000b70 <uartinit>:

extern volatile int panicking; // from printf.c
extern volatile int panicked;  // from printf.c

void uartinit(void)
{
    80000b70:	ff010113          	addi	sp,sp,-16
    80000b74:	00113423          	sd	ra,8(sp)
    80000b78:	00813023          	sd	s0,0(sp)
    80000b7c:	01010413          	addi	s0,sp,16
  // disable interrupts.
  WriteReg(IER, 0x00);
    80000b80:	100007b7          	lui	a5,0x10000
    80000b84:	000780a3          	sb	zero,1(a5) # 10000001 <_binary_fs_img_size+0xfe0c001>

  // special mode to set baud rate.
  WriteReg(LCR, LCR_BAUD_LATCH);
    80000b88:	10000737          	lui	a4,0x10000
    80000b8c:	f8000693          	li	a3,-128
    80000b90:	00d701a3          	sb	a3,3(a4) # 10000003 <_binary_fs_img_size+0xfe0c003>

  // LSB for baud rate of 38.4K.
  WriteReg(0, 0x03);
    80000b94:	00300693          	li	a3,3
    80000b98:	10000637          	lui	a2,0x10000
    80000b9c:	00d60023          	sb	a3,0(a2) # 10000000 <_binary_fs_img_size+0xfe0c000>

  // MSB for baud rate of 38.4K.
  WriteReg(1, 0x00);
    80000ba0:	000780a3          	sb	zero,1(a5)

  // leave set-baud mode,
  // and set word length to 8 bits, no parity.
  WriteReg(LCR, LCR_EIGHT_BITS);
    80000ba4:	00d701a3          	sb	a3,3(a4)

  // reset and enable FIFOs.
  WriteReg(FCR, FCR_FIFO_ENABLE | FCR_FIFO_CLEAR);
    80000ba8:	00060713          	mv	a4,a2
    80000bac:	00700613          	li	a2,7
    80000bb0:	00c70123          	sb	a2,2(a4)

  // enable transmit and receive interrupts.
  WriteReg(IER, IER_TX_ENABLE | IER_RX_ENABLE);
    80000bb4:	00d780a3          	sb	a3,1(a5)

  initlock(&tx_lock, "uart");
    80000bb8:	00008597          	auipc	a1,0x8
    80000bbc:	47858593          	addi	a1,a1,1144 # 80009030 <etext+0x30>
    80000bc0:	00205517          	auipc	a0,0x205
    80000bc4:	08050513          	addi	a0,a0,128 # 80205c40 <tx_lock>
    80000bc8:	394000ef          	jal	80000f5c <initlock>
}
    80000bcc:	00813083          	ld	ra,8(sp)
    80000bd0:	00013403          	ld	s0,0(sp)
    80000bd4:	01010113          	addi	sp,sp,16
    80000bd8:	00008067          	ret

0000000080000bdc <uartputc_sync>:
// write a byte to the uart without using
// interrupts, for use by kernel printf() and
// to echo characters. it spins waiting for the uart's
// output register to be empty.
void uartputc_sync(int c)
{
    80000bdc:	fe010113          	addi	sp,sp,-32
    80000be0:	00113c23          	sd	ra,24(sp)
    80000be4:	00813823          	sd	s0,16(sp)
    80000be8:	00913423          	sd	s1,8(sp)
    80000bec:	02010413          	addi	s0,sp,32
    80000bf0:	00050493          	mv	s1,a0
  if (panicking == 0)
    80000bf4:	001fd797          	auipc	a5,0x1fd
    80000bf8:	f607a783          	lw	a5,-160(a5) # 801fdb54 <panicking>
    80000bfc:	04078863          	beqz	a5,80000c4c <uartputc_sync+0x70>
    push_off();

  if (panicked)
    80000c00:	001fd797          	auipc	a5,0x1fd
    80000c04:	f507a783          	lw	a5,-176(a5) # 801fdb50 <panicked>
    80000c08:	04079663          	bnez	a5,80000c54 <uartputc_sync+0x78>
    for (;;)
      ;
  }

  // wait for UART to set Transmit Holding Empty in LSR.
  while ((ReadReg(LSR) & LSR_TX_IDLE) == 0)
    80000c0c:	10000737          	lui	a4,0x10000
    80000c10:	00570713          	addi	a4,a4,5 # 10000005 <_binary_fs_img_size+0xfe0c005>
    80000c14:	00074783          	lbu	a5,0(a4)
    80000c18:	0207f793          	andi	a5,a5,32
    80000c1c:	fe078ce3          	beqz	a5,80000c14 <uartputc_sync+0x38>
    ;
  WriteReg(THR, c);
    80000c20:	0ff4f513          	zext.b	a0,s1
    80000c24:	100007b7          	lui	a5,0x10000
    80000c28:	00a78023          	sb	a0,0(a5) # 10000000 <_binary_fs_img_size+0xfe0c000>

  if (panicking == 0)
    80000c2c:	001fd797          	auipc	a5,0x1fd
    80000c30:	f287a783          	lw	a5,-216(a5) # 801fdb54 <panicking>
    80000c34:	02078263          	beqz	a5,80000c58 <uartputc_sync+0x7c>
    pop_off();
}
    80000c38:	01813083          	ld	ra,24(sp)
    80000c3c:	01013403          	ld	s0,16(sp)
    80000c40:	00813483          	ld	s1,8(sp)
    80000c44:	02010113          	addi	sp,sp,32
    80000c48:	00008067          	ret
    push_off();
    80000c4c:	388000ef          	jal	80000fd4 <push_off>
    80000c50:	fb1ff06f          	j	80000c00 <uartputc_sync+0x24>
    for (;;)
    80000c54:	0000006f          	j	80000c54 <uartputc_sync+0x78>
    pop_off();
    80000c58:	450000ef          	jal	800010a8 <pop_off>
}
    80000c5c:	fddff06f          	j	80000c38 <uartputc_sync+0x5c>

0000000080000c60 <uartwrite>:
{
    80000c60:	fd010113          	addi	sp,sp,-48
    80000c64:	02113423          	sd	ra,40(sp)
    80000c68:	02813023          	sd	s0,32(sp)
    80000c6c:	01213823          	sd	s2,16(sp)
    80000c70:	01313423          	sd	s3,8(sp)
    80000c74:	03010413          	addi	s0,sp,48
    80000c78:	00050913          	mv	s2,a0
    80000c7c:	00058993          	mv	s3,a1
  acquire(&tx_lock);
    80000c80:	00205517          	auipc	a0,0x205
    80000c84:	fc050513          	addi	a0,a0,-64 # 80205c40 <tx_lock>
    80000c88:	3b8000ef          	jal	80001040 <acquire>
  while (i < n)
    80000c8c:	03305263          	blez	s3,80000cb0 <uartwrite+0x50>
    80000c90:	00913c23          	sd	s1,24(sp)
    80000c94:	00090493          	mv	s1,s2
    80000c98:	01390933          	add	s2,s2,s3
    uartputc_sync(buf[i]);
    80000c9c:	0004c503          	lbu	a0,0(s1)
    80000ca0:	f3dff0ef          	jal	80000bdc <uartputc_sync>
  while (i < n)
    80000ca4:	00148493          	addi	s1,s1,1
    80000ca8:	ff249ae3          	bne	s1,s2,80000c9c <uartwrite+0x3c>
    80000cac:	01813483          	ld	s1,24(sp)
  release(&tx_lock);
    80000cb0:	00205517          	auipc	a0,0x205
    80000cb4:	f9050513          	addi	a0,a0,-112 # 80205c40 <tx_lock>
    80000cb8:	460000ef          	jal	80001118 <release>
}
    80000cbc:	02813083          	ld	ra,40(sp)
    80000cc0:	02013403          	ld	s0,32(sp)
    80000cc4:	01013903          	ld	s2,16(sp)
    80000cc8:	00813983          	ld	s3,8(sp)
    80000ccc:	03010113          	addi	sp,sp,48
    80000cd0:	00008067          	ret

0000000080000cd4 <uartgetc>:

// try to read one input character from the UART.
// return -1 if none is waiting.
int uartgetc(void)
{
    80000cd4:	ff010113          	addi	sp,sp,-16
    80000cd8:	00113423          	sd	ra,8(sp)
    80000cdc:	00813023          	sd	s0,0(sp)
    80000ce0:	01010413          	addi	s0,sp,16
  if (ReadReg(LSR) & LSR_RX_READY)
    80000ce4:	100007b7          	lui	a5,0x10000
    80000ce8:	0057c783          	lbu	a5,5(a5) # 10000005 <_binary_fs_img_size+0xfe0c005>
    80000cec:	0017f793          	andi	a5,a5,1
    80000cf0:	00078e63          	beqz	a5,80000d0c <uartgetc+0x38>
  {
    // input data is ready.
    return ReadReg(RHR);
    80000cf4:	100007b7          	lui	a5,0x10000
    80000cf8:	0007c503          	lbu	a0,0(a5) # 10000000 <_binary_fs_img_size+0xfe0c000>
  }
  else
  {
    return -1;
  }
}
    80000cfc:	00813083          	ld	ra,8(sp)
    80000d00:	00013403          	ld	s0,0(sp)
    80000d04:	01010113          	addi	sp,sp,16
    80000d08:	00008067          	ret
    return -1;
    80000d0c:	fff00513          	li	a0,-1
    80000d10:	fedff06f          	j	80000cfc <uartgetc+0x28>

0000000080000d14 <uartintr>:

// handle a uart interrupt, raised because input has
// arrived, or the uart is ready for more output, or
// both. called from devintr().
void uartintr(void)
{
    80000d14:	fe010113          	addi	sp,sp,-32
    80000d18:	00113c23          	sd	ra,24(sp)
    80000d1c:	00813823          	sd	s0,16(sp)
    80000d20:	00913423          	sd	s1,8(sp)
    80000d24:	02010413          	addi	s0,sp,32
  // printf("[LOG][uart.c] uartintr()");
  ReadReg(ISR); // acknowledge the interrupt
    80000d28:	100007b7          	lui	a5,0x10000
    80000d2c:	0027c783          	lbu	a5,2(a5) # 10000002 <_binary_fs_img_size+0xfe0c002>

  acquire(&tx_lock);
    80000d30:	00205517          	auipc	a0,0x205
    80000d34:	f1050513          	addi	a0,a0,-240 # 80205c40 <tx_lock>
    80000d38:	308000ef          	jal	80001040 <acquire>
  if (ReadReg(LSR) & LSR_TX_IDLE)
    80000d3c:	100007b7          	lui	a5,0x10000
    80000d40:	0057c783          	lbu	a5,5(a5) # 10000005 <_binary_fs_img_size+0xfe0c005>
    80000d44:	0207f793          	andi	a5,a5,32
    80000d48:	02079263          	bnez	a5,80000d6c <uartintr+0x58>
  {
    // UART finished transmitting; wake up sending thread.
    tx_busy = 0;
    wakeup(&tx_chan);
  }
  release(&tx_lock);
    80000d4c:	00205517          	auipc	a0,0x205
    80000d50:	ef450513          	addi	a0,a0,-268 # 80205c40 <tx_lock>
    80000d54:	3c4000ef          	jal	80001118 <release>
  // read and process incoming characters, if any.
  while (1)
  {
    int c = uartgetc();
    // printf("[LOG][uart.c] return val of uartgetc() is %0d\n", c);
    if (c == -1)
    80000d58:	fff00493          	li	s1,-1
    int c = uartgetc();
    80000d5c:	f79ff0ef          	jal	80000cd4 <uartgetc>
    if (c == -1)
    80000d60:	00950e63          	beq	a0,s1,80000d7c <uartintr+0x68>
      break;
    consoleintr(c);
    80000d64:	e78ff0ef          	jal	800003dc <consoleintr>
  {
    80000d68:	ff5ff06f          	j	80000d5c <uartintr+0x48>
    wakeup(&tx_chan);
    80000d6c:	001fd517          	auipc	a0,0x1fd
    80000d70:	dec50513          	addi	a0,a0,-532 # 801fdb58 <tx_chan>
    80000d74:	204020ef          	jal	80002f78 <wakeup>
    80000d78:	fd5ff06f          	j	80000d4c <uartintr+0x38>
  }
}
    80000d7c:	01813083          	ld	ra,24(sp)
    80000d80:	01013403          	ld	s0,16(sp)
    80000d84:	00813483          	ld	s1,8(sp)
    80000d88:	02010113          	addi	sp,sp,32
    80000d8c:	00008067          	ret

0000000080000d90 <kfree>:
// Free the page of physical memory pointed at by pa,
// which normally should have been returned by a
// call to kalloc().  (The exception is when
// initializing the allocator; see kinit above.)
void kfree(void *pa)
{
    80000d90:	fe010113          	addi	sp,sp,-32
    80000d94:	00113c23          	sd	ra,24(sp)
    80000d98:	00813823          	sd	s0,16(sp)
    80000d9c:	00913423          	sd	s1,8(sp)
    80000da0:	01213023          	sd	s2,0(sp)
    80000da4:	02010413          	addi	s0,sp,32
  struct run *r;

  if (((uint64)pa % PGSIZE) != 0 || (char *)pa < end || (uint64)pa >= PHYSTOP)
    80000da8:	0040a797          	auipc	a5,0x40a
    80000dac:	fb878793          	addi	a5,a5,-72 # 8040ad60 <end>
    80000db0:	00f53733          	sltu	a4,a0,a5
    80000db4:	08100793          	li	a5,129
    80000db8:	01879793          	slli	a5,a5,0x18
    80000dbc:	fff78793          	addi	a5,a5,-1
    80000dc0:	00a7b7b3          	sltu	a5,a5,a0
    80000dc4:	00f767b3          	or	a5,a4,a5
    80000dc8:	04079663          	bnez	a5,80000e14 <kfree+0x84>
    80000dcc:	00050493          	mv	s1,a0
    80000dd0:	03451793          	slli	a5,a0,0x34
    80000dd4:	04079063          	bnez	a5,80000e14 <kfree+0x84>
  // 起動確認が重くなるのでコメントアウト.
  // memset(pa, 1, PGSIZE);

  r = (struct run *)pa;

  acquire(&kmem.lock);
    80000dd8:	00205917          	auipc	s2,0x205
    80000ddc:	e8090913          	addi	s2,s2,-384 # 80205c58 <kmem>
    80000de0:	00090513          	mv	a0,s2
    80000de4:	25c000ef          	jal	80001040 <acquire>
  r->next = kmem.freelist;
    80000de8:	01893783          	ld	a5,24(s2)
    80000dec:	00f4b023          	sd	a5,0(s1)
  kmem.freelist = r;
    80000df0:	00993c23          	sd	s1,24(s2)
  release(&kmem.lock);
    80000df4:	00090513          	mv	a0,s2
    80000df8:	320000ef          	jal	80001118 <release>
}
    80000dfc:	01813083          	ld	ra,24(sp)
    80000e00:	01013403          	ld	s0,16(sp)
    80000e04:	00813483          	ld	s1,8(sp)
    80000e08:	00013903          	ld	s2,0(sp)
    80000e0c:	02010113          	addi	sp,sp,32
    80000e10:	00008067          	ret
    panic("kfree");
    80000e14:	00008517          	auipc	a0,0x8
    80000e18:	22450513          	addi	a0,a0,548 # 80009038 <etext+0x38>
    80000e1c:	cd1ff0ef          	jal	80000aec <panic>

0000000080000e20 <freerange>:
{
    80000e20:	fd010113          	addi	sp,sp,-48
    80000e24:	02113423          	sd	ra,40(sp)
    80000e28:	02813023          	sd	s0,32(sp)
    80000e2c:	00913c23          	sd	s1,24(sp)
    80000e30:	03010413          	addi	s0,sp,48
  p = (char *)PGROUNDUP((uint64)pa_start);
    80000e34:	000017b7          	lui	a5,0x1
    80000e38:	fff78713          	addi	a4,a5,-1 # fff <_binary_fs_img_size-0x1f3001>
    80000e3c:	00e504b3          	add	s1,a0,a4
    80000e40:	fffff737          	lui	a4,0xfffff
    80000e44:	00e4f4b3          	and	s1,s1,a4
  for (; p + PGSIZE <= (char *)pa_end; p += PGSIZE)
    80000e48:	00f484b3          	add	s1,s1,a5
    80000e4c:	0295ec63          	bltu	a1,s1,80000e84 <freerange+0x64>
    80000e50:	01213823          	sd	s2,16(sp)
    80000e54:	01313423          	sd	s3,8(sp)
    80000e58:	01413023          	sd	s4,0(sp)
    80000e5c:	00058913          	mv	s2,a1
    kfree(p);
    80000e60:	00070a13          	mv	s4,a4
  for (; p + PGSIZE <= (char *)pa_end; p += PGSIZE)
    80000e64:	00078993          	mv	s3,a5
    kfree(p);
    80000e68:	01448533          	add	a0,s1,s4
    80000e6c:	f25ff0ef          	jal	80000d90 <kfree>
  for (; p + PGSIZE <= (char *)pa_end; p += PGSIZE)
    80000e70:	013484b3          	add	s1,s1,s3
    80000e74:	fe997ae3          	bgeu	s2,s1,80000e68 <freerange+0x48>
    80000e78:	01013903          	ld	s2,16(sp)
    80000e7c:	00813983          	ld	s3,8(sp)
    80000e80:	00013a03          	ld	s4,0(sp)
}
    80000e84:	02813083          	ld	ra,40(sp)
    80000e88:	02013403          	ld	s0,32(sp)
    80000e8c:	01813483          	ld	s1,24(sp)
    80000e90:	03010113          	addi	sp,sp,48
    80000e94:	00008067          	ret

0000000080000e98 <kinit>:
{
    80000e98:	ff010113          	addi	sp,sp,-16
    80000e9c:	00113423          	sd	ra,8(sp)
    80000ea0:	00813023          	sd	s0,0(sp)
    80000ea4:	01010413          	addi	s0,sp,16
  initlock(&kmem.lock, "kmem");
    80000ea8:	00008597          	auipc	a1,0x8
    80000eac:	19858593          	addi	a1,a1,408 # 80009040 <etext+0x40>
    80000eb0:	00205517          	auipc	a0,0x205
    80000eb4:	da850513          	addi	a0,a0,-600 # 80205c58 <kmem>
    80000eb8:	0a4000ef          	jal	80000f5c <initlock>
  freerange(end, (void *)PHYSTOP);
    80000ebc:	08100593          	li	a1,129
    80000ec0:	01859593          	slli	a1,a1,0x18
    80000ec4:	0040a517          	auipc	a0,0x40a
    80000ec8:	e9c50513          	addi	a0,a0,-356 # 8040ad60 <end>
    80000ecc:	f55ff0ef          	jal	80000e20 <freerange>
}
    80000ed0:	00813083          	ld	ra,8(sp)
    80000ed4:	00013403          	ld	s0,0(sp)
    80000ed8:	01010113          	addi	sp,sp,16
    80000edc:	00008067          	ret

0000000080000ee0 <kalloc>:
// Allocate one 4096-byte page of physical memory.
// Returns a pointer that the kernel can use.
// Returns 0 if the memory cannot be allocated.
void *
kalloc(void)
{
    80000ee0:	fe010113          	addi	sp,sp,-32
    80000ee4:	00113c23          	sd	ra,24(sp)
    80000ee8:	00813823          	sd	s0,16(sp)
    80000eec:	00913423          	sd	s1,8(sp)
    80000ef0:	02010413          	addi	s0,sp,32
  struct run *r;

  acquire(&kmem.lock);
    80000ef4:	00205517          	auipc	a0,0x205
    80000ef8:	d6450513          	addi	a0,a0,-668 # 80205c58 <kmem>
    80000efc:	144000ef          	jal	80001040 <acquire>
  r = kmem.freelist;
    80000f00:	00205497          	auipc	s1,0x205
    80000f04:	d704b483          	ld	s1,-656(s1) # 80205c70 <kmem+0x18>
  if (r)
    80000f08:	04048263          	beqz	s1,80000f4c <kalloc+0x6c>
    kmem.freelist = r->next;
    80000f0c:	0004b783          	ld	a5,0(s1)
    80000f10:	00205717          	auipc	a4,0x205
    80000f14:	d6f73023          	sd	a5,-672(a4) # 80205c70 <kmem+0x18>
  release(&kmem.lock);
    80000f18:	00205517          	auipc	a0,0x205
    80000f1c:	d4050513          	addi	a0,a0,-704 # 80205c58 <kmem>
    80000f20:	1f8000ef          	jal	80001118 <release>

  if (r)
    memset((char *)r, 5, PGSIZE); // fill with junk
    80000f24:	00001637          	lui	a2,0x1
    80000f28:	00500593          	li	a1,5
    80000f2c:	00048513          	mv	a0,s1
    80000f30:	2ac000ef          	jal	800011dc <memset>
  return (void *)r;
}
    80000f34:	00048513          	mv	a0,s1
    80000f38:	01813083          	ld	ra,24(sp)
    80000f3c:	01013403          	ld	s0,16(sp)
    80000f40:	00813483          	ld	s1,8(sp)
    80000f44:	02010113          	addi	sp,sp,32
    80000f48:	00008067          	ret
  release(&kmem.lock);
    80000f4c:	00205517          	auipc	a0,0x205
    80000f50:	d0c50513          	addi	a0,a0,-756 # 80205c58 <kmem>
    80000f54:	1c4000ef          	jal	80001118 <release>
  if (r)
    80000f58:	fddff06f          	j	80000f34 <kalloc+0x54>

0000000080000f5c <initlock>:
#include "riscv.h"
#include "proc.h"
#include "defs.h"

void initlock(struct spinlock *lk, char *name)
{
    80000f5c:	ff010113          	addi	sp,sp,-16
    80000f60:	00113423          	sd	ra,8(sp)
    80000f64:	00813023          	sd	s0,0(sp)
    80000f68:	01010413          	addi	s0,sp,16
  lk->name = name;
    80000f6c:	00b53423          	sd	a1,8(a0)
  lk->locked = 0;
    80000f70:	00052023          	sw	zero,0(a0)
  lk->cpu = 0;
    80000f74:	00053823          	sd	zero,16(a0)
}
    80000f78:	00813083          	ld	ra,8(sp)
    80000f7c:	00013403          	ld	s0,0(sp)
    80000f80:	01010113          	addi	sp,sp,16
    80000f84:	00008067          	ret

0000000080000f88 <holding>:
// Check whether this cpu is holding the lock.
// Interrupts must be off.
int holding(struct spinlock *lk)
{
  int r;
  r = (lk->locked && lk->cpu == mycpu());
    80000f88:	00052783          	lw	a5,0(a0)
    80000f8c:	00079663          	bnez	a5,80000f98 <holding+0x10>
    80000f90:	00000513          	li	a0,0
  return r;
}
    80000f94:	00008067          	ret
{
    80000f98:	fe010113          	addi	sp,sp,-32
    80000f9c:	00113c23          	sd	ra,24(sp)
    80000fa0:	00813823          	sd	s0,16(sp)
    80000fa4:	00913423          	sd	s1,8(sp)
    80000fa8:	02010413          	addi	s0,sp,32
  r = (lk->locked && lk->cpu == mycpu());
    80000fac:	01053783          	ld	a5,16(a0)
    80000fb0:	00078493          	mv	s1,a5
    80000fb4:	608010ef          	jal	800025bc <mycpu>
    80000fb8:	40a48533          	sub	a0,s1,a0
    80000fbc:	00153513          	seqz	a0,a0
}
    80000fc0:	01813083          	ld	ra,24(sp)
    80000fc4:	01013403          	ld	s0,16(sp)
    80000fc8:	00813483          	ld	s1,8(sp)
    80000fcc:	02010113          	addi	sp,sp,32
    80000fd0:	00008067          	ret

0000000080000fd4 <push_off>:
// push_off/pop_off are like intr_off()/intr_on() except that they are matched:
// it takes two pop_off()s to undo two push_off()s.  Also, if interrupts
// are initially off, then push_off, pop_off leaves them off.

void push_off(void)
{
    80000fd4:	fe010113          	addi	sp,sp,-32
    80000fd8:	00113c23          	sd	ra,24(sp)
    80000fdc:	00813823          	sd	s0,16(sp)
    80000fe0:	00913423          	sd	s1,8(sp)
    80000fe4:	02010413          	addi	s0,sp,32
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80000fe8:	100027f3          	csrr	a5,sstatus
    80000fec:	00078493          	mv	s1,a5
    80000ff0:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() & ~SSTATUS_SIE);
    80000ff4:	ffd7f793          	andi	a5,a5,-3
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80000ff8:	10079073          	csrw	sstatus,a5

  // disable interrupts to prevent an involuntary context
  // switch while using mycpu().
  intr_off();

  if (mycpu()->noff == 0)
    80000ffc:	5c0010ef          	jal	800025bc <mycpu>
    80001000:	07852783          	lw	a5,120(a0)
    80001004:	02078463          	beqz	a5,8000102c <push_off+0x58>
    mycpu()->intena = old;
  mycpu()->noff += 1;
    80001008:	5b4010ef          	jal	800025bc <mycpu>
    8000100c:	07852783          	lw	a5,120(a0)
    80001010:	0017879b          	addiw	a5,a5,1
    80001014:	06f52c23          	sw	a5,120(a0)
}
    80001018:	01813083          	ld	ra,24(sp)
    8000101c:	01013403          	ld	s0,16(sp)
    80001020:	00813483          	ld	s1,8(sp)
    80001024:	02010113          	addi	sp,sp,32
    80001028:	00008067          	ret
    mycpu()->intena = old;
    8000102c:	590010ef          	jal	800025bc <mycpu>
  return (x & SSTATUS_SIE) != 0;
    80001030:	0014d793          	srli	a5,s1,0x1
    80001034:	0017f793          	andi	a5,a5,1
    80001038:	06f52e23          	sw	a5,124(a0)
    8000103c:	fcdff06f          	j	80001008 <push_off+0x34>

0000000080001040 <acquire>:
{
    80001040:	fe010113          	addi	sp,sp,-32
    80001044:	00113c23          	sd	ra,24(sp)
    80001048:	00813823          	sd	s0,16(sp)
    8000104c:	00913423          	sd	s1,8(sp)
    80001050:	02010413          	addi	s0,sp,32
    80001054:	00050493          	mv	s1,a0
  push_off(); // disable interrupts to avoid deadlock.
    80001058:	f7dff0ef          	jal	80000fd4 <push_off>
  if (holding(lk))
    8000105c:	00048513          	mv	a0,s1
    80001060:	f29ff0ef          	jal	80000f88 <holding>
  while (__sync_lock_test_and_set(&lk->locked, 1) != 0)
    80001064:	00100713          	li	a4,1
  if (holding(lk))
    80001068:	02051a63          	bnez	a0,8000109c <acquire+0x5c>
  while (__sync_lock_test_and_set(&lk->locked, 1) != 0)
    8000106c:	00070793          	mv	a5,a4
    80001070:	0cf4a7af          	amoswap.w.aq	a5,a5,(s1)
    80001074:	0007879b          	sext.w	a5,a5
    80001078:	fe079ae3          	bnez	a5,8000106c <acquire+0x2c>
  __sync_synchronize();
    8000107c:	0330000f          	fence	rw,rw
  lk->cpu = mycpu();
    80001080:	53c010ef          	jal	800025bc <mycpu>
    80001084:	00a4b823          	sd	a0,16(s1)
}
    80001088:	01813083          	ld	ra,24(sp)
    8000108c:	01013403          	ld	s0,16(sp)
    80001090:	00813483          	ld	s1,8(sp)
    80001094:	02010113          	addi	sp,sp,32
    80001098:	00008067          	ret
    panic("acquire");
    8000109c:	00008517          	auipc	a0,0x8
    800010a0:	fac50513          	addi	a0,a0,-84 # 80009048 <etext+0x48>
    800010a4:	a49ff0ef          	jal	80000aec <panic>

00000000800010a8 <pop_off>:

void pop_off(void)
{
    800010a8:	ff010113          	addi	sp,sp,-16
    800010ac:	00113423          	sd	ra,8(sp)
    800010b0:	00813023          	sd	s0,0(sp)
    800010b4:	01010413          	addi	s0,sp,16
  struct cpu *c = mycpu();
    800010b8:	504010ef          	jal	800025bc <mycpu>
  asm volatile("csrr %0, sstatus" : "=r"(x));
    800010bc:	100027f3          	csrr	a5,sstatus
  return (x & SSTATUS_SIE) != 0;
    800010c0:	0027f793          	andi	a5,a5,2
  if (intr_get())
    800010c4:	02079e63          	bnez	a5,80001100 <pop_off+0x58>
    panic("pop_off - interruptible");
  if (c->noff < 1)
    800010c8:	07852783          	lw	a5,120(a0)
    800010cc:	04f05063          	blez	a5,8000110c <pop_off+0x64>
    panic("pop_off");
  c->noff -= 1;
    800010d0:	fff7879b          	addiw	a5,a5,-1
    800010d4:	06f52c23          	sw	a5,120(a0)
  if (c->noff == 0 && c->intena)
    800010d8:	00079c63          	bnez	a5,800010f0 <pop_off+0x48>
    800010dc:	07c52783          	lw	a5,124(a0)
    800010e0:	00078863          	beqz	a5,800010f0 <pop_off+0x48>
  asm volatile("csrr %0, sstatus" : "=r"(x));
    800010e4:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() | SSTATUS_SIE);
    800010e8:	0027e793          	ori	a5,a5,2
  asm volatile("csrw sstatus, %0" : : "r"(x));
    800010ec:	10079073          	csrw	sstatus,a5
    intr_on();
}
    800010f0:	00813083          	ld	ra,8(sp)
    800010f4:	00013403          	ld	s0,0(sp)
    800010f8:	01010113          	addi	sp,sp,16
    800010fc:	00008067          	ret
    panic("pop_off - interruptible");
    80001100:	00008517          	auipc	a0,0x8
    80001104:	f5050513          	addi	a0,a0,-176 # 80009050 <etext+0x50>
    80001108:	9e5ff0ef          	jal	80000aec <panic>
    panic("pop_off");
    8000110c:	00008517          	auipc	a0,0x8
    80001110:	f5c50513          	addi	a0,a0,-164 # 80009068 <etext+0x68>
    80001114:	9d9ff0ef          	jal	80000aec <panic>

0000000080001118 <release>:
{
    80001118:	fc010113          	addi	sp,sp,-64
    8000111c:	02113c23          	sd	ra,56(sp)
    80001120:	02813823          	sd	s0,48(sp)
    80001124:	02913423          	sd	s1,40(sp)
    80001128:	04010413          	addi	s0,sp,64
    8000112c:	00050493          	mv	s1,a0
  if (!holding(lk))
    80001130:	e59ff0ef          	jal	80000f88 <holding>
    80001134:	02050663          	beqz	a0,80001160 <release+0x48>
  lk->cpu = 0;
    80001138:	0004b823          	sd	zero,16(s1)
  __sync_synchronize();
    8000113c:	0330000f          	fence	rw,rw
  __sync_lock_release(&lk->locked);
    80001140:	0310000f          	fence	rw,w
    80001144:	0004a023          	sw	zero,0(s1)
  pop_off();
    80001148:	f61ff0ef          	jal	800010a8 <pop_off>
}
    8000114c:	03813083          	ld	ra,56(sp)
    80001150:	03013403          	ld	s0,48(sp)
    80001154:	02813483          	ld	s1,40(sp)
    80001158:	04010113          	addi	sp,sp,64
    8000115c:	00008067          	ret
    80001160:	03213023          	sd	s2,32(sp)
    80001164:	01313c23          	sd	s3,24(sp)
    80001168:	01413823          	sd	s4,16(sp)
    8000116c:	01513423          	sd	s5,8(sp)
           lk->name ? lk->name : "(null)",
    80001170:	0084b783          	ld	a5,8(s1)
    80001174:	00078993          	mv	s3,a5
    printf("[LOG][spinlock.c] lk=%p name=%s locked=%d lk->cpu=%p mycpu=%p cpuid=%d tp=0x%p\n",
    80001178:	04078a63          	beqz	a5,800011cc <release+0xb4>
    8000117c:	0004a783          	lw	a5,0(s1)
    80001180:	00078a13          	mv	s4,a5
    80001184:	0104b783          	ld	a5,16(s1)
    80001188:	00078a93          	mv	s5,a5
    8000118c:	430010ef          	jal	800025bc <mycpu>
    80001190:	00050913          	mv	s2,a0
    80001194:	400010ef          	jal	80002594 <cpuid>
    80001198:	00050813          	mv	a6,a0
  asm volatile("mv %0, tp" : "=r"(x));
    8000119c:	00020893          	mv	a7,tp
    800011a0:	00090793          	mv	a5,s2
    800011a4:	000a8713          	mv	a4,s5
    800011a8:	000a0693          	mv	a3,s4
    800011ac:	00098613          	mv	a2,s3
    800011b0:	00048593          	mv	a1,s1
    800011b4:	00008517          	auipc	a0,0x8
    800011b8:	ebc50513          	addi	a0,a0,-324 # 80009070 <etext+0x70>
    800011bc:	d10ff0ef          	jal	800006cc <printf>
    panic("release");
    800011c0:	00008517          	auipc	a0,0x8
    800011c4:	f0050513          	addi	a0,a0,-256 # 800090c0 <etext+0xc0>
    800011c8:	925ff0ef          	jal	80000aec <panic>
    printf("[LOG][spinlock.c] lk=%p name=%s locked=%d lk->cpu=%p mycpu=%p cpuid=%d tp=0x%p\n",
    800011cc:	00008797          	auipc	a5,0x8
    800011d0:	e3c78793          	addi	a5,a5,-452 # 80009008 <etext+0x8>
    800011d4:	00078993          	mv	s3,a5
    800011d8:	fa5ff06f          	j	8000117c <release+0x64>

00000000800011dc <memset>:
#include "types.h"

void*
memset(void *dst, int c, uint n)
{
    800011dc:	ff010113          	addi	sp,sp,-16
    800011e0:	00113423          	sd	ra,8(sp)
    800011e4:	00813023          	sd	s0,0(sp)
    800011e8:	01010413          	addi	s0,sp,16
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
    800011ec:	02060063          	beqz	a2,8000120c <memset+0x30>
    800011f0:	00050793          	mv	a5,a0
    800011f4:	02061613          	slli	a2,a2,0x20
    800011f8:	02065613          	srli	a2,a2,0x20
    800011fc:	00a60733          	add	a4,a2,a0
    cdst[i] = c;
    80001200:	00b78023          	sb	a1,0(a5)
  for(i = 0; i < n; i++){
    80001204:	00178793          	addi	a5,a5,1
    80001208:	fee79ce3          	bne	a5,a4,80001200 <memset+0x24>
  }
  return dst;
}
    8000120c:	00813083          	ld	ra,8(sp)
    80001210:	00013403          	ld	s0,0(sp)
    80001214:	01010113          	addi	sp,sp,16
    80001218:	00008067          	ret

000000008000121c <memcmp>:

int
memcmp(const void *v1, const void *v2, uint n)
{
    8000121c:	ff010113          	addi	sp,sp,-16
    80001220:	00113423          	sd	ra,8(sp)
    80001224:	00813023          	sd	s0,0(sp)
    80001228:	01010413          	addi	s0,sp,16
  const uchar *s1, *s2;

  s1 = v1;
  s2 = v2;
  while(n-- > 0){
    8000122c:	04060263          	beqz	a2,80001270 <memcmp+0x54>
    80001230:	02061613          	slli	a2,a2,0x20
    80001234:	02065613          	srli	a2,a2,0x20
    80001238:	00c506b3          	add	a3,a0,a2
    if(*s1 != *s2)
    8000123c:	00054783          	lbu	a5,0(a0)
    80001240:	0005c703          	lbu	a4,0(a1)
    80001244:	00e79c63          	bne	a5,a4,8000125c <memcmp+0x40>
      return *s1 - *s2;
    s1++, s2++;
    80001248:	00150513          	addi	a0,a0,1
    8000124c:	00158593          	addi	a1,a1,1
  while(n-- > 0){
    80001250:	fed516e3          	bne	a0,a3,8000123c <memcmp+0x20>
  }

  return 0;
    80001254:	00000513          	li	a0,0
    80001258:	0080006f          	j	80001260 <memcmp+0x44>
      return *s1 - *s2;
    8000125c:	40e7853b          	subw	a0,a5,a4
}
    80001260:	00813083          	ld	ra,8(sp)
    80001264:	00013403          	ld	s0,0(sp)
    80001268:	01010113          	addi	sp,sp,16
    8000126c:	00008067          	ret
  return 0;
    80001270:	00000513          	li	a0,0
    80001274:	fedff06f          	j	80001260 <memcmp+0x44>

0000000080001278 <memmove>:

void*
memmove(void *dst, const void *src, uint n)
{
    80001278:	ff010113          	addi	sp,sp,-16
    8000127c:	00113423          	sd	ra,8(sp)
    80001280:	00813023          	sd	s0,0(sp)
    80001284:	01010413          	addi	s0,sp,16
  const char *s;
  char *d;

  if(n == 0)
    80001288:	02060663          	beqz	a2,800012b4 <memmove+0x3c>
    return dst;
  
  s = src;
  d = dst;
  if(s < d && s + n > d){
    8000128c:	02a5ec63          	bltu	a1,a0,800012c4 <memmove+0x4c>
    s += n;
    d += n;
    while(n-- > 0)
      *--d = *--s;
  } else
    while(n-- > 0)
    80001290:	02061613          	slli	a2,a2,0x20
    80001294:	02065613          	srli	a2,a2,0x20
    80001298:	00c587b3          	add	a5,a1,a2
{
    8000129c:	00050713          	mv	a4,a0
      *d++ = *s++;
    800012a0:	00158593          	addi	a1,a1,1
    800012a4:	00170713          	addi	a4,a4,1
    800012a8:	fff5c683          	lbu	a3,-1(a1)
    800012ac:	fed70fa3          	sb	a3,-1(a4)
    while(n-- > 0)
    800012b0:	feb798e3          	bne	a5,a1,800012a0 <memmove+0x28>

  return dst;
}
    800012b4:	00813083          	ld	ra,8(sp)
    800012b8:	00013403          	ld	s0,0(sp)
    800012bc:	01010113          	addi	sp,sp,16
    800012c0:	00008067          	ret
  if(s < d && s + n > d){
    800012c4:	02061693          	slli	a3,a2,0x20
    800012c8:	0206d693          	srli	a3,a3,0x20
    800012cc:	00d58733          	add	a4,a1,a3
    800012d0:	fce570e3          	bgeu	a0,a4,80001290 <memmove+0x18>
    d += n;
    800012d4:	00d506b3          	add	a3,a0,a3
    while(n-- > 0)
    800012d8:	fff6079b          	addiw	a5,a2,-1 # fff <_binary_fs_img_size-0x1f3001>
    800012dc:	02079793          	slli	a5,a5,0x20
    800012e0:	0207d793          	srli	a5,a5,0x20
    800012e4:	fff7c793          	not	a5,a5
    800012e8:	00f707b3          	add	a5,a4,a5
      *--d = *--s;
    800012ec:	fff70713          	addi	a4,a4,-1
    800012f0:	fff68693          	addi	a3,a3,-1
    800012f4:	00074603          	lbu	a2,0(a4)
    800012f8:	00c68023          	sb	a2,0(a3)
    while(n-- > 0)
    800012fc:	fee798e3          	bne	a5,a4,800012ec <memmove+0x74>
    80001300:	fb5ff06f          	j	800012b4 <memmove+0x3c>

0000000080001304 <memcpy>:

// memcpy exists to placate GCC.  Use memmove.
void*
memcpy(void *dst, const void *src, uint n)
{
    80001304:	ff010113          	addi	sp,sp,-16
    80001308:	00113423          	sd	ra,8(sp)
    8000130c:	00813023          	sd	s0,0(sp)
    80001310:	01010413          	addi	s0,sp,16
  return memmove(dst, src, n);
    80001314:	f65ff0ef          	jal	80001278 <memmove>
}
    80001318:	00813083          	ld	ra,8(sp)
    8000131c:	00013403          	ld	s0,0(sp)
    80001320:	01010113          	addi	sp,sp,16
    80001324:	00008067          	ret

0000000080001328 <strncmp>:

int
strncmp(const char *p, const char *q, uint n)
{
    80001328:	ff010113          	addi	sp,sp,-16
    8000132c:	00113423          	sd	ra,8(sp)
    80001330:	00813023          	sd	s0,0(sp)
    80001334:	01010413          	addi	s0,sp,16
  while(n > 0 && *p && *p == *q)
    80001338:	02060663          	beqz	a2,80001364 <strncmp+0x3c>
    8000133c:	00054783          	lbu	a5,0(a0)
    80001340:	02078663          	beqz	a5,8000136c <strncmp+0x44>
    80001344:	0005c703          	lbu	a4,0(a1)
    80001348:	02f71263          	bne	a4,a5,8000136c <strncmp+0x44>
    n--, p++, q++;
    8000134c:	fff6061b          	addiw	a2,a2,-1
    80001350:	00150513          	addi	a0,a0,1
    80001354:	00158593          	addi	a1,a1,1
  while(n > 0 && *p && *p == *q)
    80001358:	fe0612e3          	bnez	a2,8000133c <strncmp+0x14>
  if(n == 0)
    return 0;
    8000135c:	00000513          	li	a0,0
    80001360:	0180006f          	j	80001378 <strncmp+0x50>
    80001364:	00000513          	li	a0,0
    80001368:	0100006f          	j	80001378 <strncmp+0x50>
  return (uchar)*p - (uchar)*q;
    8000136c:	00054503          	lbu	a0,0(a0)
    80001370:	0005c783          	lbu	a5,0(a1)
    80001374:	40f5053b          	subw	a0,a0,a5
}
    80001378:	00813083          	ld	ra,8(sp)
    8000137c:	00013403          	ld	s0,0(sp)
    80001380:	01010113          	addi	sp,sp,16
    80001384:	00008067          	ret

0000000080001388 <strncpy>:

char*
strncpy(char *s, const char *t, int n)
{
    80001388:	ff010113          	addi	sp,sp,-16
    8000138c:	00113423          	sd	ra,8(sp)
    80001390:	00813023          	sd	s0,0(sp)
    80001394:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  while(n-- > 0 && (*s++ = *t++) != 0)
    80001398:	00050793          	mv	a5,a0
    8000139c:	0080006f          	j	800013a4 <strncpy+0x1c>
    800013a0:	00068613          	mv	a2,a3
    800013a4:	04c05063          	blez	a2,800013e4 <strncpy+0x5c>
    800013a8:	fff6069b          	addiw	a3,a2,-1
    800013ac:	00068813          	mv	a6,a3
    800013b0:	00178793          	addi	a5,a5,1
    800013b4:	0005c703          	lbu	a4,0(a1)
    800013b8:	fee78fa3          	sb	a4,-1(a5)
    800013bc:	00158593          	addi	a1,a1,1
    800013c0:	fe0710e3          	bnez	a4,800013a0 <strncpy+0x18>
    ;
  while(n-- > 0)
    800013c4:	00078713          	mv	a4,a5
    800013c8:	01005e63          	blez	a6,800013e4 <strncpy+0x5c>
    800013cc:	00c787bb          	addw	a5,a5,a2
    800013d0:	fff7879b          	addiw	a5,a5,-1
    *s++ = 0;
    800013d4:	00170713          	addi	a4,a4,1
    800013d8:	fe070fa3          	sb	zero,-1(a4)
  while(n-- > 0)
    800013dc:	40e786bb          	subw	a3,a5,a4
    800013e0:	fed04ae3          	bgtz	a3,800013d4 <strncpy+0x4c>
  return os;
}
    800013e4:	00813083          	ld	ra,8(sp)
    800013e8:	00013403          	ld	s0,0(sp)
    800013ec:	01010113          	addi	sp,sp,16
    800013f0:	00008067          	ret

00000000800013f4 <safestrcpy>:

// Like strncpy but guaranteed to NUL-terminate.
char*
safestrcpy(char *s, const char *t, int n)
{
    800013f4:	ff010113          	addi	sp,sp,-16
    800013f8:	00113423          	sd	ra,8(sp)
    800013fc:	00813023          	sd	s0,0(sp)
    80001400:	01010413          	addi	s0,sp,16
  char *os;

  os = s;
  if(n <= 0)
    80001404:	02c05a63          	blez	a2,80001438 <safestrcpy+0x44>
    80001408:	fff6069b          	addiw	a3,a2,-1
    8000140c:	02069693          	slli	a3,a3,0x20
    80001410:	0206d693          	srli	a3,a3,0x20
    80001414:	00d586b3          	add	a3,a1,a3
    80001418:	00050793          	mv	a5,a0
    return os;
  while(--n > 0 && (*s++ = *t++) != 0)
    8000141c:	00d58c63          	beq	a1,a3,80001434 <safestrcpy+0x40>
    80001420:	00158593          	addi	a1,a1,1
    80001424:	00178793          	addi	a5,a5,1
    80001428:	fff5c703          	lbu	a4,-1(a1)
    8000142c:	fee78fa3          	sb	a4,-1(a5)
    80001430:	fe0716e3          	bnez	a4,8000141c <safestrcpy+0x28>
    ;
  *s = 0;
    80001434:	00078023          	sb	zero,0(a5)
  return os;
}
    80001438:	00813083          	ld	ra,8(sp)
    8000143c:	00013403          	ld	s0,0(sp)
    80001440:	01010113          	addi	sp,sp,16
    80001444:	00008067          	ret

0000000080001448 <strlen>:

int
strlen(const char *s)
{
    80001448:	ff010113          	addi	sp,sp,-16
    8000144c:	00113423          	sd	ra,8(sp)
    80001450:	00813023          	sd	s0,0(sp)
    80001454:	01010413          	addi	s0,sp,16
  int n;

  for(n = 0; s[n]; n++)
    80001458:	00054783          	lbu	a5,0(a0)
    8000145c:	02078663          	beqz	a5,80001488 <strlen+0x40>
    80001460:	00150793          	addi	a5,a0,1
    80001464:	00078693          	mv	a3,a5
    80001468:	00178793          	addi	a5,a5,1
    8000146c:	fff7c703          	lbu	a4,-1(a5)
    80001470:	fe071ae3          	bnez	a4,80001464 <strlen+0x1c>
    80001474:	40a6853b          	subw	a0,a3,a0
    ;
  return n;
}
    80001478:	00813083          	ld	ra,8(sp)
    8000147c:	00013403          	ld	s0,0(sp)
    80001480:	01010113          	addi	sp,sp,16
    80001484:	00008067          	ret
  for(n = 0; s[n]; n++)
    80001488:	00000513          	li	a0,0
    8000148c:	fedff06f          	j	80001478 <strlen+0x30>

0000000080001490 <main>:

volatile static int started = 0;

// start() jumps here in supervisor mode on all CPUs.
void main()
{
    80001490:	ff010113          	addi	sp,sp,-16
    80001494:	00113423          	sd	ra,8(sp)
    80001498:	00813023          	sd	s0,0(sp)
    8000149c:	01010413          	addi	s0,sp,16
  if (cpuid() == 0)
    800014a0:	0f4010ef          	jal	80002594 <cpuid>
    __sync_synchronize();
    started = 1;
  }
  else
  {
    while (started == 0)
    800014a4:	001fc717          	auipc	a4,0x1fc
    800014a8:	6b870713          	addi	a4,a4,1720 # 801fdb5c <started>
  if (cpuid() == 0)
    800014ac:	04050263          	beqz	a0,800014f0 <main+0x60>
    while (started == 0)
    800014b0:	00072783          	lw	a5,0(a4)
    800014b4:	0007879b          	sext.w	a5,a5
    800014b8:	fe078ce3          	beqz	a5,800014b0 <main+0x20>
      ;
    __sync_synchronize();
    800014bc:	0330000f          	fence	rw,rw
    printf("hart %d starting\n", cpuid());
    800014c0:	0d4010ef          	jal	80002594 <cpuid>
    800014c4:	00050593          	mv	a1,a0
    800014c8:	00008517          	auipc	a0,0x8
    800014cc:	df050513          	addi	a0,a0,-528 # 800092b8 <etext+0x2b8>
    800014d0:	9fcff0ef          	jal	800006cc <printf>
    kvminithart();  // turn on paging
    800014d4:	12c000ef          	jal	80001600 <kvminithart>
    trapinithart(); // install kernel trap vector
    800014d8:	1a4020ef          	jal	8000367c <trapinithart>
    plicinithart(); // ask PLIC for device interrupts
    800014dc:	7b4060ef          	jal	80007c90 <plicinithart>
  }

  printf("[LOG][main.c] Boot process has done. scheduler() will be called.\n");
    800014e0:	00008517          	auipc	a0,0x8
    800014e4:	df050513          	addi	a0,a0,-528 # 800092d0 <etext+0x2d0>
    800014e8:	9e4ff0ef          	jal	800006cc <printf>
  scheduler();
    800014ec:	7d4010ef          	jal	80002cc0 <scheduler>
    consoleinit();
    800014f0:	8b4ff0ef          	jal	800005a4 <consoleinit>
    printfinit();
    800014f4:	e48ff0ef          	jal	80000b3c <printfinit>
    printf("\n");
    800014f8:	00008517          	auipc	a0,0x8
    800014fc:	bd050513          	addi	a0,a0,-1072 # 800090c8 <etext+0xc8>
    80001500:	9ccff0ef          	jal	800006cc <printf>
    printf("xv6 kernel is booting (ver 5.0)\n");
    80001504:	00008517          	auipc	a0,0x8
    80001508:	bcc50513          	addi	a0,a0,-1076 # 800090d0 <etext+0xd0>
    8000150c:	9c0ff0ef          	jal	800006cc <printf>
    printf("\n");
    80001510:	00008517          	auipc	a0,0x8
    80001514:	bb850513          	addi	a0,a0,-1096 # 800090c8 <etext+0xc8>
    80001518:	9b4ff0ef          	jal	800006cc <printf>
    kinit(); // physical page allocator
    8000151c:	97dff0ef          	jal	80000e98 <kinit>
    printf("[LOG][main.c] kinit() done.\n");
    80001520:	00008517          	auipc	a0,0x8
    80001524:	bd850513          	addi	a0,a0,-1064 # 800090f8 <etext+0xf8>
    80001528:	9a4ff0ef          	jal	800006cc <printf>
    kvminit(); // create kernel page table
    8000152c:	4dc000ef          	jal	80001a08 <kvminit>
    printf("[LOG][main.c] kvminit() done.\n");
    80001530:	00008517          	auipc	a0,0x8
    80001534:	be850513          	addi	a0,a0,-1048 # 80009118 <etext+0x118>
    80001538:	994ff0ef          	jal	800006cc <printf>
    kvminithart(); // turn on paging
    8000153c:	0c4000ef          	jal	80001600 <kvminithart>
    printf("[LOG][main.c] kvminithart() done.\n");
    80001540:	00008517          	auipc	a0,0x8
    80001544:	bf850513          	addi	a0,a0,-1032 # 80009138 <etext+0x138>
    80001548:	984ff0ef          	jal	800006cc <printf>
    procinit(); // process table
    8000154c:	751000ef          	jal	8000249c <procinit>
    printf("[LOG][main.c] procinit() done.\n");
    80001550:	00008517          	auipc	a0,0x8
    80001554:	c1050513          	addi	a0,a0,-1008 # 80009160 <etext+0x160>
    80001558:	974ff0ef          	jal	800006cc <printf>
    trapinit(); // trap vectors
    8000155c:	0ec020ef          	jal	80003648 <trapinit>
    printf("[LOG][main.c] trapinit() done.\n");
    80001560:	00008517          	auipc	a0,0x8
    80001564:	c2050513          	addi	a0,a0,-992 # 80009180 <etext+0x180>
    80001568:	964ff0ef          	jal	800006cc <printf>
    trapinithart(); // install kernel trap vector
    8000156c:	110020ef          	jal	8000367c <trapinithart>
    printf("[LOG][main.c] trapinithart() done.\n");
    80001570:	00008517          	auipc	a0,0x8
    80001574:	c3050513          	addi	a0,a0,-976 # 800091a0 <etext+0x1a0>
    80001578:	954ff0ef          	jal	800006cc <printf>
    plicinit(); // set up interrupt controller
    8000157c:	6e4060ef          	jal	80007c60 <plicinit>
    printf("[LOG][main.c] plicinit() done.\n");
    80001580:	00008517          	auipc	a0,0x8
    80001584:	c4850513          	addi	a0,a0,-952 # 800091c8 <etext+0x1c8>
    80001588:	944ff0ef          	jal	800006cc <printf>
    plicinithart(); // ask PLIC for device interrupts
    8000158c:	704060ef          	jal	80007c90 <plicinithart>
    printf("[LOG][main.c] plicinithart() done.\n");
    80001590:	00008517          	auipc	a0,0x8
    80001594:	c5850513          	addi	a0,a0,-936 # 800091e8 <etext+0x1e8>
    80001598:	934ff0ef          	jal	800006cc <printf>
    binit(); // buffer cache
    8000159c:	2ad020ef          	jal	80004048 <binit>
    printf("[LOG][main.c] binit() done.\n");
    800015a0:	00008517          	auipc	a0,0x8
    800015a4:	c7050513          	addi	a0,a0,-912 # 80009210 <etext+0x210>
    800015a8:	924ff0ef          	jal	800006cc <printf>
    iinit(); // inode table
    800015ac:	234030ef          	jal	800047e0 <iinit>
    printf("[LOG][main.c] iinit() done.\n");
    800015b0:	00008517          	auipc	a0,0x8
    800015b4:	c8050513          	addi	a0,a0,-896 # 80009230 <etext+0x230>
    800015b8:	914ff0ef          	jal	800006cc <printf>
    fileinit(); // file table
    800015bc:	0a1040ef          	jal	80005e5c <fileinit>
    printf("[LOG][main.c] fileinit() done.\n");
    800015c0:	00008517          	auipc	a0,0x8
    800015c4:	c9050513          	addi	a0,a0,-880 # 80009250 <etext+0x250>
    800015c8:	904ff0ef          	jal	800006cc <printf>
    virtio_disk_init(); // emulated hard disk
    800015cc:	780060ef          	jal	80007d4c <virtio_disk_init>
    printf("[LOG][main.c] virtio_disk_init() done.\n");
    800015d0:	00008517          	auipc	a0,0x8
    800015d4:	ca050513          	addi	a0,a0,-864 # 80009270 <etext+0x270>
    800015d8:	8f4ff0ef          	jal	800006cc <printf>
    userinit(); // first user process
    800015dc:	480010ef          	jal	80002a5c <userinit>
    printf("[LOG][main.c] userinit() done.\n");
    800015e0:	00008517          	auipc	a0,0x8
    800015e4:	cb850513          	addi	a0,a0,-840 # 80009298 <etext+0x298>
    800015e8:	8e4ff0ef          	jal	800006cc <printf>
    __sync_synchronize();
    800015ec:	0330000f          	fence	rw,rw
    started = 1;
    800015f0:	00100793          	li	a5,1
    800015f4:	001fc717          	auipc	a4,0x1fc
    800015f8:	56f72423          	sw	a5,1384(a4) # 801fdb5c <started>
    800015fc:	ee5ff06f          	j	800014e0 <main+0x50>

0000000080001600 <kvminithart>:
}

// Switch the current CPU's h/w page table register to
// the kernel's page table, and enable paging.
void kvminithart()
{
    80001600:	ff010113          	addi	sp,sp,-16
    80001604:	00113423          	sd	ra,8(sp)
    80001608:	00813023          	sd	s0,0(sp)
    8000160c:	01010413          	addi	s0,sp,16

  printf("[LOG][vm.c] dived into kvminithart()\n");
    80001610:	00008517          	auipc	a0,0x8
    80001614:	d0850513          	addi	a0,a0,-760 # 80009318 <etext+0x318>
    80001618:	8b4ff0ef          	jal	800006cc <printf>
// flush the TLB.
static inline void
sfence_vma()
{
  // the zero, zero means flush all TLB entries.
  asm volatile("sfence.vma zero, zero");
    8000161c:	12000073          	sfence.vma
  // wait for any previous writes to the page table memory to finish.
  sfence_vma();

  printf("[LOG][vm.c] sfence_vma() done\n");
    80001620:	00008517          	auipc	a0,0x8
    80001624:	d2050513          	addi	a0,a0,-736 # 80009340 <etext+0x340>
    80001628:	8a4ff0ef          	jal	800006cc <printf>

  w_satp(MAKE_SATP(kernel_pagetable));
    8000162c:	001fc797          	auipc	a5,0x1fc
    80001630:	5347b783          	ld	a5,1332(a5) # 801fdb60 <kernel_pagetable>
    80001634:	00c7d793          	srli	a5,a5,0xc
    80001638:	fff00713          	li	a4,-1
    8000163c:	03f71713          	slli	a4,a4,0x3f
    80001640:	00e7e7b3          	or	a5,a5,a4
  asm volatile("csrw satp, %0" : : "r"(x));
    80001644:	18079073          	csrw	satp,a5

  printf("[LOG][vm.c] w_satp() done\n");
    80001648:	00008517          	auipc	a0,0x8
    8000164c:	d1850513          	addi	a0,a0,-744 # 80009360 <etext+0x360>
    80001650:	87cff0ef          	jal	800006cc <printf>
  asm volatile("sfence.vma zero, zero");
    80001654:	12000073          	sfence.vma

  // flush stale entries from the TLB.
  sfence_vma();
}
    80001658:	00813083          	ld	ra,8(sp)
    8000165c:	00013403          	ld	s0,0(sp)
    80001660:	01010113          	addi	sp,sp,16
    80001664:	00008067          	ret

0000000080001668 <walk>:
//   21..29 -- 9 bits of level-1 index.
//   12..20 -- 9 bits of level-0 index.
//    0..11 -- 12 bits of byte offset within the page.
pte_t *
walk(pagetable_t pagetable, uint64 va, int alloc)
{
    80001668:	fc010113          	addi	sp,sp,-64
    8000166c:	02113c23          	sd	ra,56(sp)
    80001670:	02813823          	sd	s0,48(sp)
    80001674:	02913423          	sd	s1,40(sp)
    80001678:	03213023          	sd	s2,32(sp)
    8000167c:	01313c23          	sd	s3,24(sp)
    80001680:	01413823          	sd	s4,16(sp)
    80001684:	01513423          	sd	s5,8(sp)
    80001688:	01613023          	sd	s6,0(sp)
    8000168c:	04010413          	addi	s0,sp,64
    80001690:	00050493          	mv	s1,a0
    80001694:	00058993          	mv	s3,a1
    80001698:	00060b13          	mv	s6,a2
  if (va >= MAXVA)
    8000169c:	fff00793          	li	a5,-1
    800016a0:	01a7d793          	srli	a5,a5,0x1a
    800016a4:	01e00a13          	li	s4,30
    panic("walk");

  for (int level = 2; level > 0; level--)
    800016a8:	00c00a93          	li	s5,12
  if (va >= MAXVA)
    800016ac:	06b7e463          	bltu	a5,a1,80001714 <walk+0xac>
  {
    pte_t *pte = &pagetable[PX(level, va)];
    800016b0:	0149d933          	srl	s2,s3,s4
    800016b4:	1ff97913          	andi	s2,s2,511
    800016b8:	00391913          	slli	s2,s2,0x3
    800016bc:	01248933          	add	s2,s1,s2
    if (*pte & PTE_V)
    800016c0:	00093483          	ld	s1,0(s2)
    800016c4:	0014f793          	andi	a5,s1,1
    800016c8:	04078c63          	beqz	a5,80001720 <walk+0xb8>
    {
      pagetable = (pagetable_t)PTE2PA(*pte);
    800016cc:	00a4d493          	srli	s1,s1,0xa
    800016d0:	00c49493          	slli	s1,s1,0xc
  for (int level = 2; level > 0; level--)
    800016d4:	ff7a0a1b          	addiw	s4,s4,-9
    800016d8:	fd5a1ce3          	bne	s4,s5,800016b0 <walk+0x48>
        return 0;
      memset(pagetable, 0, PGSIZE);
      *pte = PA2PTE(pagetable) | PTE_V;
    }
  }
  return &pagetable[PX(0, va)];
    800016dc:	00c9d513          	srli	a0,s3,0xc
    800016e0:	1ff57513          	andi	a0,a0,511
    800016e4:	00351513          	slli	a0,a0,0x3
    800016e8:	00a48533          	add	a0,s1,a0
}
    800016ec:	03813083          	ld	ra,56(sp)
    800016f0:	03013403          	ld	s0,48(sp)
    800016f4:	02813483          	ld	s1,40(sp)
    800016f8:	02013903          	ld	s2,32(sp)
    800016fc:	01813983          	ld	s3,24(sp)
    80001700:	01013a03          	ld	s4,16(sp)
    80001704:	00813a83          	ld	s5,8(sp)
    80001708:	00013b03          	ld	s6,0(sp)
    8000170c:	04010113          	addi	sp,sp,64
    80001710:	00008067          	ret
    panic("walk");
    80001714:	00008517          	auipc	a0,0x8
    80001718:	c6c50513          	addi	a0,a0,-916 # 80009380 <etext+0x380>
    8000171c:	bd0ff0ef          	jal	80000aec <panic>
      if (!alloc || (pagetable = (pde_t *)kalloc()) == 0)
    80001720:	020b0863          	beqz	s6,80001750 <walk+0xe8>
    80001724:	fbcff0ef          	jal	80000ee0 <kalloc>
    80001728:	00050493          	mv	s1,a0
    8000172c:	fc0500e3          	beqz	a0,800016ec <walk+0x84>
      memset(pagetable, 0, PGSIZE);
    80001730:	00001637          	lui	a2,0x1
    80001734:	00000593          	li	a1,0
    80001738:	aa5ff0ef          	jal	800011dc <memset>
      *pte = PA2PTE(pagetable) | PTE_V;
    8000173c:	00c4d793          	srli	a5,s1,0xc
    80001740:	00a79793          	slli	a5,a5,0xa
    80001744:	0017e793          	ori	a5,a5,1
    80001748:	00f93023          	sd	a5,0(s2)
    8000174c:	f89ff06f          	j	800016d4 <walk+0x6c>
        return 0;
    80001750:	00000513          	li	a0,0
    80001754:	f99ff06f          	j	800016ec <walk+0x84>

0000000080001758 <walkaddr>:
walkaddr(pagetable_t pagetable, uint64 va)
{
  pte_t *pte;
  uint64 pa;

  if (va >= MAXVA)
    80001758:	fff00793          	li	a5,-1
    8000175c:	01a7d793          	srli	a5,a5,0x1a
    80001760:	00b7f663          	bgeu	a5,a1,8000176c <walkaddr+0x14>
    return 0;
    80001764:	00000513          	li	a0,0
    return 0;
  if ((*pte & PTE_U) == 0)
    return 0;
  pa = PTE2PA(*pte);
  return pa;
}
    80001768:	00008067          	ret
{
    8000176c:	ff010113          	addi	sp,sp,-16
    80001770:	00113423          	sd	ra,8(sp)
    80001774:	00813023          	sd	s0,0(sp)
    80001778:	01010413          	addi	s0,sp,16
  pte = walk(pagetable, va, 0);
    8000177c:	00000613          	li	a2,0
    80001780:	ee9ff0ef          	jal	80001668 <walk>
  if (pte == 0)
    80001784:	00050c63          	beqz	a0,8000179c <walkaddr+0x44>
  if ((*pte & PTE_V) == 0)
    80001788:	00053783          	ld	a5,0(a0)
  if ((*pte & PTE_U) == 0)
    8000178c:	0117f693          	andi	a3,a5,17
    80001790:	01100713          	li	a4,17
    return 0;
    80001794:	00000513          	li	a0,0
  if ((*pte & PTE_U) == 0)
    80001798:	00e68a63          	beq	a3,a4,800017ac <walkaddr+0x54>
}
    8000179c:	00813083          	ld	ra,8(sp)
    800017a0:	00013403          	ld	s0,0(sp)
    800017a4:	01010113          	addi	sp,sp,16
    800017a8:	00008067          	ret
  pa = PTE2PA(*pte);
    800017ac:	00a7d793          	srli	a5,a5,0xa
    800017b0:	00c79513          	slli	a0,a5,0xc
  return pa;
    800017b4:	fe9ff06f          	j	8000179c <walkaddr+0x44>

00000000800017b8 <mappages>:
// physical addresses starting at pa.
// va and size MUST be page-aligned.
// Returns 0 on success, -1 if walk() couldn't
// allocate a needed page-table page.
int mappages(pagetable_t pagetable, uint64 va, uint64 size, uint64 pa, int perm)
{
    800017b8:	fb010113          	addi	sp,sp,-80
    800017bc:	04113423          	sd	ra,72(sp)
    800017c0:	04813023          	sd	s0,64(sp)
    800017c4:	02913c23          	sd	s1,56(sp)
    800017c8:	03213823          	sd	s2,48(sp)
    800017cc:	03313423          	sd	s3,40(sp)
    800017d0:	03413023          	sd	s4,32(sp)
    800017d4:	01513c23          	sd	s5,24(sp)
    800017d8:	01613823          	sd	s6,16(sp)
    800017dc:	01713423          	sd	s7,8(sp)
    800017e0:	05010413          	addi	s0,sp,80
  uint64 a, last;
  pte_t *pte;

  if ((va % PGSIZE) != 0)
    800017e4:	03459793          	slli	a5,a1,0x34
    800017e8:	06079c63          	bnez	a5,80001860 <mappages+0xa8>
    800017ec:	00050a13          	mv	s4,a0
    800017f0:	00070a93          	mv	s5,a4
    panic("mappages: va not aligned");

  if ((size % PGSIZE) != 0)
    800017f4:	03461793          	slli	a5,a2,0x34
    800017f8:	06079a63          	bnez	a5,8000186c <mappages+0xb4>
    panic("mappages: size not aligned");

  if (size == 0)
    800017fc:	06060e63          	beqz	a2,80001878 <mappages+0xc0>
    panic("mappages: size");

  a = va;
  last = va + size - PGSIZE;
    80001800:	80060613          	addi	a2,a2,-2048 # 800 <_binary_fs_img_size-0x1f3800>
    80001804:	80060613          	addi	a2,a2,-2048
    80001808:	00b60933          	add	s2,a2,a1
  a = va;
    8000180c:	00058493          	mv	s1,a1
  for (;;)
  {
    if ((pte = walk(pagetable, a, 1)) == 0)
    80001810:	00100b13          	li	s6,1
    80001814:	40b689b3          	sub	s3,a3,a1
    if (*pte & PTE_V)
      panic("mappages: remap");
    *pte = PA2PTE(pa) | perm | PTE_V;
    if (a == last)
      break;
    a += PGSIZE;
    80001818:	00001bb7          	lui	s7,0x1
    if ((pte = walk(pagetable, a, 1)) == 0)
    8000181c:	000b0613          	mv	a2,s6
    80001820:	00048593          	mv	a1,s1
    80001824:	000a0513          	mv	a0,s4
    80001828:	e41ff0ef          	jal	80001668 <walk>
    8000182c:	06050263          	beqz	a0,80001890 <mappages+0xd8>
    if (*pte & PTE_V)
    80001830:	00053783          	ld	a5,0(a0)
    80001834:	0017f793          	andi	a5,a5,1
    80001838:	04079663          	bnez	a5,80001884 <mappages+0xcc>
    *pte = PA2PTE(pa) | perm | PTE_V;
    8000183c:	013487b3          	add	a5,s1,s3
    80001840:	00c7d793          	srli	a5,a5,0xc
    80001844:	00a79793          	slli	a5,a5,0xa
    80001848:	0157e7b3          	or	a5,a5,s5
    8000184c:	0017e793          	ori	a5,a5,1
    80001850:	00f53023          	sd	a5,0(a0)
    if (a == last)
    80001854:	07248663          	beq	s1,s2,800018c0 <mappages+0x108>
    a += PGSIZE;
    80001858:	017484b3          	add	s1,s1,s7
    if ((pte = walk(pagetable, a, 1)) == 0)
    8000185c:	fc1ff06f          	j	8000181c <mappages+0x64>
    panic("mappages: va not aligned");
    80001860:	00008517          	auipc	a0,0x8
    80001864:	b2850513          	addi	a0,a0,-1240 # 80009388 <etext+0x388>
    80001868:	a84ff0ef          	jal	80000aec <panic>
    panic("mappages: size not aligned");
    8000186c:	00008517          	auipc	a0,0x8
    80001870:	b3c50513          	addi	a0,a0,-1220 # 800093a8 <etext+0x3a8>
    80001874:	a78ff0ef          	jal	80000aec <panic>
    panic("mappages: size");
    80001878:	00008517          	auipc	a0,0x8
    8000187c:	b5050513          	addi	a0,a0,-1200 # 800093c8 <etext+0x3c8>
    80001880:	a6cff0ef          	jal	80000aec <panic>
      panic("mappages: remap");
    80001884:	00008517          	auipc	a0,0x8
    80001888:	b5450513          	addi	a0,a0,-1196 # 800093d8 <etext+0x3d8>
    8000188c:	a60ff0ef          	jal	80000aec <panic>
      return -1;
    80001890:	fff00513          	li	a0,-1
    pa += PGSIZE;
  }
  return 0;
}
    80001894:	04813083          	ld	ra,72(sp)
    80001898:	04013403          	ld	s0,64(sp)
    8000189c:	03813483          	ld	s1,56(sp)
    800018a0:	03013903          	ld	s2,48(sp)
    800018a4:	02813983          	ld	s3,40(sp)
    800018a8:	02013a03          	ld	s4,32(sp)
    800018ac:	01813a83          	ld	s5,24(sp)
    800018b0:	01013b03          	ld	s6,16(sp)
    800018b4:	00813b83          	ld	s7,8(sp)
    800018b8:	05010113          	addi	sp,sp,80
    800018bc:	00008067          	ret
  return 0;
    800018c0:	00000513          	li	a0,0
    800018c4:	fd1ff06f          	j	80001894 <mappages+0xdc>

00000000800018c8 <kvmmap>:
{
    800018c8:	ff010113          	addi	sp,sp,-16
    800018cc:	00113423          	sd	ra,8(sp)
    800018d0:	00813023          	sd	s0,0(sp)
    800018d4:	01010413          	addi	s0,sp,16
    800018d8:	00068793          	mv	a5,a3
  if (mappages(kpgtbl, va, sz, pa, perm) != 0)
    800018dc:	00060693          	mv	a3,a2
    800018e0:	00078613          	mv	a2,a5
    800018e4:	ed5ff0ef          	jal	800017b8 <mappages>
    800018e8:	00051a63          	bnez	a0,800018fc <kvmmap+0x34>
}
    800018ec:	00813083          	ld	ra,8(sp)
    800018f0:	00013403          	ld	s0,0(sp)
    800018f4:	01010113          	addi	sp,sp,16
    800018f8:	00008067          	ret
    panic("kvmmap");
    800018fc:	00008517          	auipc	a0,0x8
    80001900:	aec50513          	addi	a0,a0,-1300 # 800093e8 <etext+0x3e8>
    80001904:	9e8ff0ef          	jal	80000aec <panic>

0000000080001908 <kvmmake>:
{
    80001908:	fe010113          	addi	sp,sp,-32
    8000190c:	00113c23          	sd	ra,24(sp)
    80001910:	00813823          	sd	s0,16(sp)
    80001914:	00913423          	sd	s1,8(sp)
    80001918:	02010413          	addi	s0,sp,32
  kpgtbl = (pagetable_t)kalloc();
    8000191c:	dc4ff0ef          	jal	80000ee0 <kalloc>
    80001920:	00050493          	mv	s1,a0
  memset(kpgtbl, 0, PGSIZE);
    80001924:	00001637          	lui	a2,0x1
    80001928:	00000593          	li	a1,0
    8000192c:	8b1ff0ef          	jal	800011dc <memset>
  kvmmap(kpgtbl, UART0, UART0, PGSIZE, PTE_R | PTE_W);
    80001930:	00600713          	li	a4,6
    80001934:	000016b7          	lui	a3,0x1
    80001938:	10000637          	lui	a2,0x10000
    8000193c:	00060593          	mv	a1,a2
    80001940:	00048513          	mv	a0,s1
    80001944:	f85ff0ef          	jal	800018c8 <kvmmap>
  kvmmap(kpgtbl, VIRTIO0, VIRTIO0, PGSIZE, PTE_R | PTE_W);
    80001948:	00600713          	li	a4,6
    8000194c:	000016b7          	lui	a3,0x1
    80001950:	10001637          	lui	a2,0x10001
    80001954:	00060593          	mv	a1,a2
    80001958:	00048513          	mv	a0,s1
    8000195c:	f6dff0ef          	jal	800018c8 <kvmmap>
  kvmmap(kpgtbl, PLIC, PLIC, 0x4000000, PTE_R | PTE_W);
    80001960:	00600713          	li	a4,6
    80001964:	040006b7          	lui	a3,0x4000
    80001968:	0c000637          	lui	a2,0xc000
    8000196c:	00060593          	mv	a1,a2
    80001970:	00048513          	mv	a0,s1
    80001974:	f55ff0ef          	jal	800018c8 <kvmmap>
  kvmmap(kpgtbl, KERNBASE, KERNBASE, (uint64)etext - KERNBASE, PTE_R | PTE_X);
    80001978:	00a00713          	li	a4,10
    8000197c:	80007697          	auipc	a3,0x80007
    80001980:	68468693          	addi	a3,a3,1668 # 9000 <_binary_fs_img_size-0x1eb000>
    80001984:	00100613          	li	a2,1
    80001988:	01f61613          	slli	a2,a2,0x1f
    8000198c:	00060593          	mv	a1,a2
    80001990:	00048513          	mv	a0,s1
    80001994:	f35ff0ef          	jal	800018c8 <kvmmap>
  kvmmap(kpgtbl, (uint64)etext, (uint64)etext, PHYSTOP - (uint64)etext, PTE_R | PTE_W);
    80001998:	00600713          	li	a4,6
    8000199c:	00007697          	auipc	a3,0x7
    800019a0:	66468693          	addi	a3,a3,1636 # 80009000 <etext>
    800019a4:	08100793          	li	a5,129
    800019a8:	01879793          	slli	a5,a5,0x18
    800019ac:	40d786b3          	sub	a3,a5,a3
    800019b0:	00007617          	auipc	a2,0x7
    800019b4:	65060613          	addi	a2,a2,1616 # 80009000 <etext>
    800019b8:	00060593          	mv	a1,a2
    800019bc:	00048513          	mv	a0,s1
    800019c0:	f09ff0ef          	jal	800018c8 <kvmmap>
  kvmmap(kpgtbl, TRAMPOLINE, (uint64)trampoline, PGSIZE, PTE_R | PTE_X);
    800019c4:	00a00713          	li	a4,10
    800019c8:	000016b7          	lui	a3,0x1
    800019cc:	00006617          	auipc	a2,0x6
    800019d0:	63460613          	addi	a2,a2,1588 # 80008000 <_trampoline>
    800019d4:	040005b7          	lui	a1,0x4000
    800019d8:	fff58593          	addi	a1,a1,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    800019dc:	00c59593          	slli	a1,a1,0xc
    800019e0:	00048513          	mv	a0,s1
    800019e4:	ee5ff0ef          	jal	800018c8 <kvmmap>
  proc_mapstacks(kpgtbl);
    800019e8:	00048513          	mv	a0,s1
    800019ec:	1b9000ef          	jal	800023a4 <proc_mapstacks>
}
    800019f0:	00048513          	mv	a0,s1
    800019f4:	01813083          	ld	ra,24(sp)
    800019f8:	01013403          	ld	s0,16(sp)
    800019fc:	00813483          	ld	s1,8(sp)
    80001a00:	02010113          	addi	sp,sp,32
    80001a04:	00008067          	ret

0000000080001a08 <kvminit>:
{
    80001a08:	ff010113          	addi	sp,sp,-16
    80001a0c:	00113423          	sd	ra,8(sp)
    80001a10:	00813023          	sd	s0,0(sp)
    80001a14:	01010413          	addi	s0,sp,16
  kernel_pagetable = kvmmake();
    80001a18:	ef1ff0ef          	jal	80001908 <kvmmake>
    80001a1c:	001fc797          	auipc	a5,0x1fc
    80001a20:	14a7b223          	sd	a0,324(a5) # 801fdb60 <kernel_pagetable>
}
    80001a24:	00813083          	ld	ra,8(sp)
    80001a28:	00013403          	ld	s0,0(sp)
    80001a2c:	01010113          	addi	sp,sp,16
    80001a30:	00008067          	ret

0000000080001a34 <uvmcreate>:

// create an empty user page table.
// returns 0 if out of memory.
pagetable_t
uvmcreate()
{
    80001a34:	fe010113          	addi	sp,sp,-32
    80001a38:	00113c23          	sd	ra,24(sp)
    80001a3c:	00813823          	sd	s0,16(sp)
    80001a40:	00913423          	sd	s1,8(sp)
    80001a44:	02010413          	addi	s0,sp,32
  pagetable_t pagetable;
  pagetable = (pagetable_t)kalloc();
    80001a48:	c98ff0ef          	jal	80000ee0 <kalloc>
    80001a4c:	00050493          	mv	s1,a0
  if (pagetable == 0)
    80001a50:	00050863          	beqz	a0,80001a60 <uvmcreate+0x2c>
    return 0;
  memset(pagetable, 0, PGSIZE);
    80001a54:	00001637          	lui	a2,0x1
    80001a58:	00000593          	li	a1,0
    80001a5c:	f80ff0ef          	jal	800011dc <memset>
  return pagetable;
}
    80001a60:	00048513          	mv	a0,s1
    80001a64:	01813083          	ld	ra,24(sp)
    80001a68:	01013403          	ld	s0,16(sp)
    80001a6c:	00813483          	ld	s1,8(sp)
    80001a70:	02010113          	addi	sp,sp,32
    80001a74:	00008067          	ret

0000000080001a78 <uvmunmap>:

// Remove npages of mappings starting from va. va must be
// page-aligned. It's OK if the mappings don't exist.
// Optionally free the physical memory.
void uvmunmap(pagetable_t pagetable, uint64 va, uint64 npages, int do_free)
{
    80001a78:	fc010113          	addi	sp,sp,-64
    80001a7c:	02113c23          	sd	ra,56(sp)
    80001a80:	02813823          	sd	s0,48(sp)
    80001a84:	04010413          	addi	s0,sp,64
  uint64 a;
  pte_t *pte;

  if ((va % PGSIZE) != 0)
    80001a88:	03459793          	slli	a5,a1,0x34
    80001a8c:	02079e63          	bnez	a5,80001ac8 <uvmunmap+0x50>
    80001a90:	03213023          	sd	s2,32(sp)
    80001a94:	01313c23          	sd	s3,24(sp)
    80001a98:	01413823          	sd	s4,16(sp)
    80001a9c:	01513423          	sd	s5,8(sp)
    80001aa0:	01613023          	sd	s6,0(sp)
    80001aa4:	00050a13          	mv	s4,a0
    80001aa8:	00058913          	mv	s2,a1
    80001aac:	00068a93          	mv	s5,a3
    panic("uvmunmap: not aligned");

  for (a = va; a < va + npages * PGSIZE; a += PGSIZE)
    80001ab0:	00c61613          	slli	a2,a2,0xc
    80001ab4:	00b609b3          	add	s3,a2,a1
    80001ab8:	00001b37          	lui	s6,0x1
    80001abc:	0735fc63          	bgeu	a1,s3,80001b34 <uvmunmap+0xbc>
    80001ac0:	02913423          	sd	s1,40(sp)
    80001ac4:	0340006f          	j	80001af8 <uvmunmap+0x80>
    80001ac8:	02913423          	sd	s1,40(sp)
    80001acc:	03213023          	sd	s2,32(sp)
    80001ad0:	01313c23          	sd	s3,24(sp)
    80001ad4:	01413823          	sd	s4,16(sp)
    80001ad8:	01513423          	sd	s5,8(sp)
    80001adc:	01613023          	sd	s6,0(sp)
    panic("uvmunmap: not aligned");
    80001ae0:	00008517          	auipc	a0,0x8
    80001ae4:	91050513          	addi	a0,a0,-1776 # 800093f0 <etext+0x3f0>
    80001ae8:	804ff0ef          	jal	80000aec <panic>
    if (do_free)
    {
      uint64 pa = PTE2PA(*pte);
      kfree((void *)pa);
    }
    *pte = 0;
    80001aec:	0004b023          	sd	zero,0(s1)
  for (a = va; a < va + npages * PGSIZE; a += PGSIZE)
    80001af0:	01690933          	add	s2,s2,s6
    80001af4:	03397e63          	bgeu	s2,s3,80001b30 <uvmunmap+0xb8>
    if ((pte = walk(pagetable, a, 0)) == 0) // leaf page table entry allocated?
    80001af8:	00000613          	li	a2,0
    80001afc:	00090593          	mv	a1,s2
    80001b00:	000a0513          	mv	a0,s4
    80001b04:	b65ff0ef          	jal	80001668 <walk>
    80001b08:	00050493          	mv	s1,a0
    80001b0c:	fe0502e3          	beqz	a0,80001af0 <uvmunmap+0x78>
    if ((*pte & PTE_V) == 0) // has physical page been allocated?
    80001b10:	00053783          	ld	a5,0(a0)
    80001b14:	0017f713          	andi	a4,a5,1
    80001b18:	fc070ce3          	beqz	a4,80001af0 <uvmunmap+0x78>
    if (do_free)
    80001b1c:	fc0a88e3          	beqz	s5,80001aec <uvmunmap+0x74>
      uint64 pa = PTE2PA(*pte);
    80001b20:	00a7d793          	srli	a5,a5,0xa
      kfree((void *)pa);
    80001b24:	00c79513          	slli	a0,a5,0xc
    80001b28:	a68ff0ef          	jal	80000d90 <kfree>
    80001b2c:	fc1ff06f          	j	80001aec <uvmunmap+0x74>
    80001b30:	02813483          	ld	s1,40(sp)
    80001b34:	02013903          	ld	s2,32(sp)
    80001b38:	01813983          	ld	s3,24(sp)
    80001b3c:	01013a03          	ld	s4,16(sp)
    80001b40:	00813a83          	ld	s5,8(sp)
    80001b44:	00013b03          	ld	s6,0(sp)
  }
}
    80001b48:	03813083          	ld	ra,56(sp)
    80001b4c:	03013403          	ld	s0,48(sp)
    80001b50:	04010113          	addi	sp,sp,64
    80001b54:	00008067          	ret

0000000080001b58 <uvmdealloc>:
// newsz.  oldsz and newsz need not be page-aligned, nor does newsz
// need to be less than oldsz.  oldsz can be larger than the actual
// process size.  Returns the new process size.
uint64
uvmdealloc(pagetable_t pagetable, uint64 oldsz, uint64 newsz)
{
    80001b58:	fe010113          	addi	sp,sp,-32
    80001b5c:	00113c23          	sd	ra,24(sp)
    80001b60:	00813823          	sd	s0,16(sp)
    80001b64:	00913423          	sd	s1,8(sp)
    80001b68:	02010413          	addi	s0,sp,32
  if (newsz >= oldsz)
    return oldsz;
    80001b6c:	00058493          	mv	s1,a1
  if (newsz >= oldsz)
    80001b70:	02b67463          	bgeu	a2,a1,80001b98 <uvmdealloc+0x40>
    80001b74:	00060493          	mv	s1,a2

  if (PGROUNDUP(newsz) < PGROUNDUP(oldsz))
    80001b78:	000017b7          	lui	a5,0x1
    80001b7c:	fff78793          	addi	a5,a5,-1 # fff <_binary_fs_img_size-0x1f3001>
    80001b80:	00f60733          	add	a4,a2,a5
    80001b84:	fffff6b7          	lui	a3,0xfffff
    80001b88:	00d77733          	and	a4,a4,a3
    80001b8c:	00f587b3          	add	a5,a1,a5
    80001b90:	00d7f7b3          	and	a5,a5,a3
    80001b94:	00f76e63          	bltu	a4,a5,80001bb0 <uvmdealloc+0x58>
    int npages = (PGROUNDUP(oldsz) - PGROUNDUP(newsz)) / PGSIZE;
    uvmunmap(pagetable, PGROUNDUP(newsz), npages, 1);
  }

  return newsz;
}
    80001b98:	00048513          	mv	a0,s1
    80001b9c:	01813083          	ld	ra,24(sp)
    80001ba0:	01013403          	ld	s0,16(sp)
    80001ba4:	00813483          	ld	s1,8(sp)
    80001ba8:	02010113          	addi	sp,sp,32
    80001bac:	00008067          	ret
    int npages = (PGROUNDUP(oldsz) - PGROUNDUP(newsz)) / PGSIZE;
    80001bb0:	40e787b3          	sub	a5,a5,a4
    80001bb4:	00c7d793          	srli	a5,a5,0xc
    uvmunmap(pagetable, PGROUNDUP(newsz), npages, 1);
    80001bb8:	00100693          	li	a3,1
    80001bbc:	0007861b          	sext.w	a2,a5
    80001bc0:	00070593          	mv	a1,a4
    80001bc4:	eb5ff0ef          	jal	80001a78 <uvmunmap>
    80001bc8:	fd1ff06f          	j	80001b98 <uvmdealloc+0x40>

0000000080001bcc <uvmalloc>:
  if (newsz < oldsz)
    80001bcc:	12b66263          	bltu	a2,a1,80001cf0 <uvmalloc+0x124>
{
    80001bd0:	fb010113          	addi	sp,sp,-80
    80001bd4:	04113423          	sd	ra,72(sp)
    80001bd8:	04813023          	sd	s0,64(sp)
    80001bdc:	03413023          	sd	s4,32(sp)
    80001be0:	01513c23          	sd	s5,24(sp)
    80001be4:	01713423          	sd	s7,8(sp)
    80001be8:	05010413          	addi	s0,sp,80
    80001bec:	00050a93          	mv	s5,a0
    80001bf0:	00060a13          	mv	s4,a2
  oldsz = PGROUNDUP(oldsz);
    80001bf4:	000017b7          	lui	a5,0x1
    80001bf8:	fff78793          	addi	a5,a5,-1 # fff <_binary_fs_img_size-0x1f3001>
    80001bfc:	00f585b3          	add	a1,a1,a5
    80001c00:	fffff7b7          	lui	a5,0xfffff
    80001c04:	00f5f7b3          	and	a5,a1,a5
    80001c08:	00078b93          	mv	s7,a5
  for (a = oldsz; a < newsz; a += PGSIZE)
    80001c0c:	0ec7f663          	bgeu	a5,a2,80001cf8 <uvmalloc+0x12c>
    80001c10:	02913c23          	sd	s1,56(sp)
    80001c14:	03213823          	sd	s2,48(sp)
    80001c18:	03313423          	sd	s3,40(sp)
    80001c1c:	01613823          	sd	s6,16(sp)
    80001c20:	00078913          	mv	s2,a5
    memset(mem, 0, PGSIZE);
    80001c24:	000019b7          	lui	s3,0x1
    if (mappages(pagetable, a, PGSIZE, (uint64)mem, PTE_R | PTE_U | xperm) != 0)
    80001c28:	0126eb13          	ori	s6,a3,18
    mem = kalloc();
    80001c2c:	ab4ff0ef          	jal	80000ee0 <kalloc>
    80001c30:	00050493          	mv	s1,a0
    if (mem == 0)
    80001c34:	04050663          	beqz	a0,80001c80 <uvmalloc+0xb4>
    memset(mem, 0, PGSIZE);
    80001c38:	00098613          	mv	a2,s3
    80001c3c:	00000593          	li	a1,0
    80001c40:	d9cff0ef          	jal	800011dc <memset>
    if (mappages(pagetable, a, PGSIZE, (uint64)mem, PTE_R | PTE_U | xperm) != 0)
    80001c44:	000b0713          	mv	a4,s6
    80001c48:	00048693          	mv	a3,s1
    80001c4c:	00098613          	mv	a2,s3
    80001c50:	00090593          	mv	a1,s2
    80001c54:	000a8513          	mv	a0,s5
    80001c58:	b61ff0ef          	jal	800017b8 <mappages>
    80001c5c:	06051263          	bnez	a0,80001cc0 <uvmalloc+0xf4>
  for (a = oldsz; a < newsz; a += PGSIZE)
    80001c60:	01390933          	add	s2,s2,s3
    80001c64:	fd4964e3          	bltu	s2,s4,80001c2c <uvmalloc+0x60>
  return newsz;
    80001c68:	000a0513          	mv	a0,s4
    80001c6c:	03813483          	ld	s1,56(sp)
    80001c70:	03013903          	ld	s2,48(sp)
    80001c74:	02813983          	ld	s3,40(sp)
    80001c78:	01013b03          	ld	s6,16(sp)
    80001c7c:	0280006f          	j	80001ca4 <uvmalloc+0xd8>
      uvmdealloc(pagetable, a, oldsz);
    80001c80:	000b8613          	mv	a2,s7
    80001c84:	00090593          	mv	a1,s2
    80001c88:	000a8513          	mv	a0,s5
    80001c8c:	ecdff0ef          	jal	80001b58 <uvmdealloc>
      return 0;
    80001c90:	00000513          	li	a0,0
    80001c94:	03813483          	ld	s1,56(sp)
    80001c98:	03013903          	ld	s2,48(sp)
    80001c9c:	02813983          	ld	s3,40(sp)
    80001ca0:	01013b03          	ld	s6,16(sp)
}
    80001ca4:	04813083          	ld	ra,72(sp)
    80001ca8:	04013403          	ld	s0,64(sp)
    80001cac:	02013a03          	ld	s4,32(sp)
    80001cb0:	01813a83          	ld	s5,24(sp)
    80001cb4:	00813b83          	ld	s7,8(sp)
    80001cb8:	05010113          	addi	sp,sp,80
    80001cbc:	00008067          	ret
      kfree(mem);
    80001cc0:	00048513          	mv	a0,s1
    80001cc4:	8ccff0ef          	jal	80000d90 <kfree>
      uvmdealloc(pagetable, a, oldsz);
    80001cc8:	000b8613          	mv	a2,s7
    80001ccc:	00090593          	mv	a1,s2
    80001cd0:	000a8513          	mv	a0,s5
    80001cd4:	e85ff0ef          	jal	80001b58 <uvmdealloc>
      return 0;
    80001cd8:	00000513          	li	a0,0
    80001cdc:	03813483          	ld	s1,56(sp)
    80001ce0:	03013903          	ld	s2,48(sp)
    80001ce4:	02813983          	ld	s3,40(sp)
    80001ce8:	01013b03          	ld	s6,16(sp)
    80001cec:	fb9ff06f          	j	80001ca4 <uvmalloc+0xd8>
    return oldsz;
    80001cf0:	00058513          	mv	a0,a1
}
    80001cf4:	00008067          	ret
  return newsz;
    80001cf8:	00060513          	mv	a0,a2
    80001cfc:	fa9ff06f          	j	80001ca4 <uvmalloc+0xd8>

0000000080001d00 <freewalk>:

// Recursively free page-table pages.
// All leaf mappings must already have been removed.
void freewalk(pagetable_t pagetable)
{
    80001d00:	fd010113          	addi	sp,sp,-48
    80001d04:	02113423          	sd	ra,40(sp)
    80001d08:	02813023          	sd	s0,32(sp)
    80001d0c:	00913c23          	sd	s1,24(sp)
    80001d10:	01213823          	sd	s2,16(sp)
    80001d14:	01313423          	sd	s3,8(sp)
    80001d18:	03010413          	addi	s0,sp,48
    80001d1c:	00050993          	mv	s3,a0
  // there are 2^9 = 512 PTEs in a page table.
  for (int i = 0; i < 512; i++)
    80001d20:	00050493          	mv	s1,a0
    80001d24:	00001937          	lui	s2,0x1
    80001d28:	01250933          	add	s2,a0,s2
    80001d2c:	0180006f          	j	80001d44 <freewalk+0x44>
      freewalk((pagetable_t)child);
      pagetable[i] = 0;
    }
    else if (pte & PTE_V)
    {
      panic("freewalk: leaf");
    80001d30:	00007517          	auipc	a0,0x7
    80001d34:	6d850513          	addi	a0,a0,1752 # 80009408 <etext+0x408>
    80001d38:	db5fe0ef          	jal	80000aec <panic>
  for (int i = 0; i < 512; i++)
    80001d3c:	00848493          	addi	s1,s1,8
    80001d40:	03248663          	beq	s1,s2,80001d6c <freewalk+0x6c>
    pte_t pte = pagetable[i];
    80001d44:	0004b783          	ld	a5,0(s1)
    if ((pte & PTE_V) && (pte & (PTE_R | PTE_W | PTE_X)) == 0)
    80001d48:	0017f713          	andi	a4,a5,1
    80001d4c:	fe0708e3          	beqz	a4,80001d3c <freewalk+0x3c>
    80001d50:	00e7f713          	andi	a4,a5,14
    80001d54:	fc071ee3          	bnez	a4,80001d30 <freewalk+0x30>
      uint64 child = PTE2PA(pte);
    80001d58:	00a7d793          	srli	a5,a5,0xa
      freewalk((pagetable_t)child);
    80001d5c:	00c79513          	slli	a0,a5,0xc
    80001d60:	fa1ff0ef          	jal	80001d00 <freewalk>
      pagetable[i] = 0;
    80001d64:	0004b023          	sd	zero,0(s1)
    {
    80001d68:	fd5ff06f          	j	80001d3c <freewalk+0x3c>
    }
  }
  kfree((void *)pagetable);
    80001d6c:	00098513          	mv	a0,s3
    80001d70:	820ff0ef          	jal	80000d90 <kfree>
}
    80001d74:	02813083          	ld	ra,40(sp)
    80001d78:	02013403          	ld	s0,32(sp)
    80001d7c:	01813483          	ld	s1,24(sp)
    80001d80:	01013903          	ld	s2,16(sp)
    80001d84:	00813983          	ld	s3,8(sp)
    80001d88:	03010113          	addi	sp,sp,48
    80001d8c:	00008067          	ret

0000000080001d90 <uvmfree>:

// Free user memory pages,
// then free page-table pages.
void uvmfree(pagetable_t pagetable, uint64 sz)
{
    80001d90:	fe010113          	addi	sp,sp,-32
    80001d94:	00113c23          	sd	ra,24(sp)
    80001d98:	00813823          	sd	s0,16(sp)
    80001d9c:	00913423          	sd	s1,8(sp)
    80001da0:	02010413          	addi	s0,sp,32
    80001da4:	00050493          	mv	s1,a0
  if (sz > 0)
    80001da8:	02059063          	bnez	a1,80001dc8 <uvmfree+0x38>
    uvmunmap(pagetable, 0, PGROUNDUP(sz) / PGSIZE, 1);
  freewalk(pagetable);
    80001dac:	00048513          	mv	a0,s1
    80001db0:	f51ff0ef          	jal	80001d00 <freewalk>
}
    80001db4:	01813083          	ld	ra,24(sp)
    80001db8:	01013403          	ld	s0,16(sp)
    80001dbc:	00813483          	ld	s1,8(sp)
    80001dc0:	02010113          	addi	sp,sp,32
    80001dc4:	00008067          	ret
    uvmunmap(pagetable, 0, PGROUNDUP(sz) / PGSIZE, 1);
    80001dc8:	000017b7          	lui	a5,0x1
    80001dcc:	fff78793          	addi	a5,a5,-1 # fff <_binary_fs_img_size-0x1f3001>
    80001dd0:	00f585b3          	add	a1,a1,a5
    80001dd4:	00100693          	li	a3,1
    80001dd8:	00c5d613          	srli	a2,a1,0xc
    80001ddc:	00000593          	li	a1,0
    80001de0:	c99ff0ef          	jal	80001a78 <uvmunmap>
    80001de4:	fc9ff06f          	j	80001dac <uvmfree+0x1c>

0000000080001de8 <uvmcopy>:
  pte_t *pte;
  uint64 pa, i;
  uint flags;
  char *mem;

  for (i = 0; i < sz; i += PGSIZE)
    80001de8:	0e060e63          	beqz	a2,80001ee4 <uvmcopy+0xfc>
{
    80001dec:	fb010113          	addi	sp,sp,-80
    80001df0:	04113423          	sd	ra,72(sp)
    80001df4:	04813023          	sd	s0,64(sp)
    80001df8:	02913c23          	sd	s1,56(sp)
    80001dfc:	03213823          	sd	s2,48(sp)
    80001e00:	03313423          	sd	s3,40(sp)
    80001e04:	03413023          	sd	s4,32(sp)
    80001e08:	01513c23          	sd	s5,24(sp)
    80001e0c:	01613823          	sd	s6,16(sp)
    80001e10:	01713423          	sd	s7,8(sp)
    80001e14:	05010413          	addi	s0,sp,80
    80001e18:	00050b13          	mv	s6,a0
    80001e1c:	00058b93          	mv	s7,a1
    80001e20:	00060a93          	mv	s5,a2
  for (i = 0; i < sz; i += PGSIZE)
    80001e24:	00000493          	li	s1,0
      continue; // physical page hasn't been allocated
    pa = PTE2PA(*pte);
    flags = PTE_FLAGS(*pte);
    if ((mem = kalloc()) == 0)
      goto err;
    memmove(mem, (char *)pa, PGSIZE);
    80001e28:	00001a37          	lui	s4,0x1
    80001e2c:	00c0006f          	j	80001e38 <uvmcopy+0x50>
  for (i = 0; i < sz; i += PGSIZE)
    80001e30:	014484b3          	add	s1,s1,s4
    80001e34:	0954f063          	bgeu	s1,s5,80001eb4 <uvmcopy+0xcc>
    if ((pte = walk(old, i, 0)) == 0)
    80001e38:	00000613          	li	a2,0
    80001e3c:	00048593          	mv	a1,s1
    80001e40:	000b0513          	mv	a0,s6
    80001e44:	825ff0ef          	jal	80001668 <walk>
    80001e48:	fe0504e3          	beqz	a0,80001e30 <uvmcopy+0x48>
    if ((*pte & PTE_V) == 0)
    80001e4c:	00053983          	ld	s3,0(a0)
    80001e50:	0019f793          	andi	a5,s3,1
    80001e54:	fc078ee3          	beqz	a5,80001e30 <uvmcopy+0x48>
    if ((mem = kalloc()) == 0)
    80001e58:	888ff0ef          	jal	80000ee0 <kalloc>
    80001e5c:	00050913          	mv	s2,a0
    80001e60:	02050c63          	beqz	a0,80001e98 <uvmcopy+0xb0>
    pa = PTE2PA(*pte);
    80001e64:	00a9d593          	srli	a1,s3,0xa
    memmove(mem, (char *)pa, PGSIZE);
    80001e68:	000a0613          	mv	a2,s4
    80001e6c:	00c59593          	slli	a1,a1,0xc
    80001e70:	c08ff0ef          	jal	80001278 <memmove>
    if (mappages(new, i, PGSIZE, (uint64)mem, flags) != 0)
    80001e74:	3ff9f713          	andi	a4,s3,1023
    80001e78:	00090693          	mv	a3,s2
    80001e7c:	000a0613          	mv	a2,s4
    80001e80:	00048593          	mv	a1,s1
    80001e84:	000b8513          	mv	a0,s7
    80001e88:	931ff0ef          	jal	800017b8 <mappages>
    80001e8c:	fa0502e3          	beqz	a0,80001e30 <uvmcopy+0x48>
    {
      kfree(mem);
    80001e90:	00090513          	mv	a0,s2
    80001e94:	efdfe0ef          	jal	80000d90 <kfree>
    }
  }
  return 0;

err:
  uvmunmap(new, 0, i / PGSIZE, 1);
    80001e98:	00100693          	li	a3,1
    80001e9c:	00c4d613          	srli	a2,s1,0xc
    80001ea0:	00000593          	li	a1,0
    80001ea4:	000b8513          	mv	a0,s7
    80001ea8:	bd1ff0ef          	jal	80001a78 <uvmunmap>
  return -1;
    80001eac:	fff00513          	li	a0,-1
    80001eb0:	0080006f          	j	80001eb8 <uvmcopy+0xd0>
  return 0;
    80001eb4:	00000513          	li	a0,0
}
    80001eb8:	04813083          	ld	ra,72(sp)
    80001ebc:	04013403          	ld	s0,64(sp)
    80001ec0:	03813483          	ld	s1,56(sp)
    80001ec4:	03013903          	ld	s2,48(sp)
    80001ec8:	02813983          	ld	s3,40(sp)
    80001ecc:	02013a03          	ld	s4,32(sp)
    80001ed0:	01813a83          	ld	s5,24(sp)
    80001ed4:	01013b03          	ld	s6,16(sp)
    80001ed8:	00813b83          	ld	s7,8(sp)
    80001edc:	05010113          	addi	sp,sp,80
    80001ee0:	00008067          	ret
  return 0;
    80001ee4:	00000513          	li	a0,0
}
    80001ee8:	00008067          	ret

0000000080001eec <uvmclear>:

// mark a PTE invalid for user access.
// used by exec for the user stack guard page.
void uvmclear(pagetable_t pagetable, uint64 va)
{
    80001eec:	ff010113          	addi	sp,sp,-16
    80001ef0:	00113423          	sd	ra,8(sp)
    80001ef4:	00813023          	sd	s0,0(sp)
    80001ef8:	01010413          	addi	s0,sp,16
  pte_t *pte;

  pte = walk(pagetable, va, 0);
    80001efc:	00000613          	li	a2,0
    80001f00:	f68ff0ef          	jal	80001668 <walk>
  if (pte == 0)
    80001f04:	02050063          	beqz	a0,80001f24 <uvmclear+0x38>
    panic("uvmclear");
  *pte &= ~PTE_U;
    80001f08:	00053783          	ld	a5,0(a0)
    80001f0c:	fef7f793          	andi	a5,a5,-17
    80001f10:	00f53023          	sd	a5,0(a0)
}
    80001f14:	00813083          	ld	ra,8(sp)
    80001f18:	00013403          	ld	s0,0(sp)
    80001f1c:	01010113          	addi	sp,sp,16
    80001f20:	00008067          	ret
    panic("uvmclear");
    80001f24:	00007517          	auipc	a0,0x7
    80001f28:	4f450513          	addi	a0,a0,1268 # 80009418 <etext+0x418>
    80001f2c:	bc1fe0ef          	jal	80000aec <panic>

0000000080001f30 <copyinstr>:
int copyinstr(pagetable_t pagetable, char *dst, uint64 srcva, uint64 max)
{
  uint64 n, va0, pa0;
  int got_null = 0;

  while (got_null == 0 && max > 0)
    80001f30:	10068e63          	beqz	a3,8000204c <copyinstr+0x11c>
{
    80001f34:	fb010113          	addi	sp,sp,-80
    80001f38:	04113423          	sd	ra,72(sp)
    80001f3c:	04813023          	sd	s0,64(sp)
    80001f40:	02913c23          	sd	s1,56(sp)
    80001f44:	03213823          	sd	s2,48(sp)
    80001f48:	03313423          	sd	s3,40(sp)
    80001f4c:	03413023          	sd	s4,32(sp)
    80001f50:	01513c23          	sd	s5,24(sp)
    80001f54:	01613823          	sd	s6,16(sp)
    80001f58:	01713423          	sd	s7,8(sp)
    80001f5c:	05010413          	addi	s0,sp,80
    80001f60:	00050a93          	mv	s5,a0
    80001f64:	00058493          	mv	s1,a1
    80001f68:	00060b93          	mv	s7,a2
    80001f6c:	00068993          	mv	s3,a3
  {
    va0 = PGROUNDDOWN(srcva);
    80001f70:	fffffb37          	lui	s6,0xfffff
    pa0 = walkaddr(pagetable, va0);
    if (pa0 == 0)
      return -1;
    n = PGSIZE - (srcva - va0);
    80001f74:	00001a37          	lui	s4,0x1
    80001f78:	0580006f          	j	80001fd0 <copyinstr+0xa0>
    char *p = (char *)(pa0 + (srcva - va0));
    while (n > 0)
    {
      if (*p == '\0')
      {
        *dst = '\0';
    80001f7c:	00078023          	sb	zero,0(a5)
        got_null = 1;
    80001f80:	00100793          	li	a5,1
      dst++;
    }

    srcva = va0 + PGSIZE;
  }
  if (got_null)
    80001f84:	0017c793          	xori	a5,a5,1
    80001f88:	40f0053b          	negw	a0,a5
  }
  else
  {
    return -1;
  }
}
    80001f8c:	04813083          	ld	ra,72(sp)
    80001f90:	04013403          	ld	s0,64(sp)
    80001f94:	03813483          	ld	s1,56(sp)
    80001f98:	03013903          	ld	s2,48(sp)
    80001f9c:	02813983          	ld	s3,40(sp)
    80001fa0:	02013a03          	ld	s4,32(sp)
    80001fa4:	01813a83          	ld	s5,24(sp)
    80001fa8:	01013b03          	ld	s6,16(sp)
    80001fac:	00813b83          	ld	s7,8(sp)
    80001fb0:	05010113          	addi	sp,sp,80
    80001fb4:	00008067          	ret
    80001fb8:	fff98713          	addi	a4,s3,-1 # fff <_binary_fs_img_size-0x1f3001>
    80001fbc:	00e48733          	add	a4,s1,a4
      --max;
    80001fc0:	40b709b3          	sub	s3,a4,a1
    srcva = va0 + PGSIZE;
    80001fc4:	01490bb3          	add	s7,s2,s4
  while (got_null == 0 && max > 0)
    80001fc8:	06e58263          	beq	a1,a4,8000202c <copyinstr+0xfc>
{
    80001fcc:	00078493          	mv	s1,a5
    va0 = PGROUNDDOWN(srcva);
    80001fd0:	016bf933          	and	s2,s7,s6
    pa0 = walkaddr(pagetable, va0);
    80001fd4:	00090593          	mv	a1,s2
    80001fd8:	000a8513          	mv	a0,s5
    80001fdc:	f7cff0ef          	jal	80001758 <walkaddr>
    if (pa0 == 0)
    80001fe0:	04050a63          	beqz	a0,80002034 <copyinstr+0x104>
    n = PGSIZE - (srcva - va0);
    80001fe4:	417906b3          	sub	a3,s2,s7
    80001fe8:	014686b3          	add	a3,a3,s4
    if (n > max)
    80001fec:	00d9f463          	bgeu	s3,a3,80001ff4 <copyinstr+0xc4>
    80001ff0:	00098693          	mv	a3,s3
    while (n > 0)
    80001ff4:	04068463          	beqz	a3,8000203c <copyinstr+0x10c>
    char *p = (char *)(pa0 + (srcva - va0));
    80001ff8:	01750633          	add	a2,a0,s7
    80001ffc:	41260633          	sub	a2,a2,s2
    80002000:	00048793          	mv	a5,s1
      if (*p == '\0')
    80002004:	40960633          	sub	a2,a2,s1
    while (n > 0)
    80002008:	00d486b3          	add	a3,s1,a3
    8000200c:	00078593          	mv	a1,a5
      if (*p == '\0')
    80002010:	00f60733          	add	a4,a2,a5
    80002014:	00074703          	lbu	a4,0(a4)
    80002018:	f60702e3          	beqz	a4,80001f7c <copyinstr+0x4c>
        *dst = *p;
    8000201c:	00e78023          	sb	a4,0(a5)
      dst++;
    80002020:	00178793          	addi	a5,a5,1
    while (n > 0)
    80002024:	fed794e3          	bne	a5,a3,8000200c <copyinstr+0xdc>
    80002028:	f91ff06f          	j	80001fb8 <copyinstr+0x88>
    8000202c:	00000793          	li	a5,0
    80002030:	f55ff06f          	j	80001f84 <copyinstr+0x54>
      return -1;
    80002034:	fff00513          	li	a0,-1
    80002038:	f55ff06f          	j	80001f8c <copyinstr+0x5c>
    srcva = va0 + PGSIZE;
    8000203c:	00001bb7          	lui	s7,0x1
    80002040:	01790bb3          	add	s7,s2,s7
    80002044:	00048793          	mv	a5,s1
    80002048:	f85ff06f          	j	80001fcc <copyinstr+0x9c>
  int got_null = 0;
    8000204c:	00000793          	li	a5,0
  if (got_null)
    80002050:	0017c793          	xori	a5,a5,1
    80002054:	40f0053b          	negw	a0,a5
}
    80002058:	00008067          	ret

000000008000205c <ismapped>:
  }
  return mem;
}

int ismapped(pagetable_t pagetable, uint64 va)
{
    8000205c:	ff010113          	addi	sp,sp,-16
    80002060:	00113423          	sd	ra,8(sp)
    80002064:	00813023          	sd	s0,0(sp)
    80002068:	01010413          	addi	s0,sp,16
  pte_t *pte = walk(pagetable, va, 0);
    8000206c:	00000613          	li	a2,0
    80002070:	df8ff0ef          	jal	80001668 <walk>
  if (pte == 0)
    80002074:	00050663          	beqz	a0,80002080 <ismapped+0x24>
  {
    return 0;
  }
  if (*pte & PTE_V)
    80002078:	00053503          	ld	a0,0(a0)
    8000207c:	00157513          	andi	a0,a0,1
  {
    return 1;
  }
  return 0;
}
    80002080:	00813083          	ld	ra,8(sp)
    80002084:	00013403          	ld	s0,0(sp)
    80002088:	01010113          	addi	sp,sp,16
    8000208c:	00008067          	ret

0000000080002090 <vmfault>:
{
    80002090:	fd010113          	addi	sp,sp,-48
    80002094:	02113423          	sd	ra,40(sp)
    80002098:	02813023          	sd	s0,32(sp)
    8000209c:	01213823          	sd	s2,16(sp)
    800020a0:	01313423          	sd	s3,8(sp)
    800020a4:	01413023          	sd	s4,0(sp)
    800020a8:	03010413          	addi	s0,sp,48
    800020ac:	00050993          	mv	s3,a0
    800020b0:	00058913          	mv	s2,a1
  struct proc *p = myproc();
    800020b4:	540000ef          	jal	800025f4 <myproc>
  if (va >= p->sz)
    800020b8:	04853783          	ld	a5,72(a0)
    return 0;
    800020bc:	00000a13          	li	s4,0
  if (va >= p->sz)
    800020c0:	02f96263          	bltu	s2,a5,800020e4 <vmfault+0x54>
}
    800020c4:	000a0513          	mv	a0,s4
    800020c8:	02813083          	ld	ra,40(sp)
    800020cc:	02013403          	ld	s0,32(sp)
    800020d0:	01013903          	ld	s2,16(sp)
    800020d4:	00813983          	ld	s3,8(sp)
    800020d8:	00013a03          	ld	s4,0(sp)
    800020dc:	03010113          	addi	sp,sp,48
    800020e0:	00008067          	ret
    800020e4:	00913c23          	sd	s1,24(sp)
    800020e8:	00050493          	mv	s1,a0
  va = PGROUNDDOWN(va);
    800020ec:	fffff7b7          	lui	a5,0xfffff
    800020f0:	00f977b3          	and	a5,s2,a5
  if (ismapped(pagetable, va))
    800020f4:	00078913          	mv	s2,a5
    800020f8:	00078593          	mv	a1,a5
    800020fc:	00098513          	mv	a0,s3
    80002100:	f5dff0ef          	jal	8000205c <ismapped>
    return 0;
    80002104:	00000a13          	li	s4,0
  if (ismapped(pagetable, va))
    80002108:	00050663          	beqz	a0,80002114 <vmfault+0x84>
    8000210c:	01813483          	ld	s1,24(sp)
    80002110:	fb5ff06f          	j	800020c4 <vmfault+0x34>
  mem = (uint64)kalloc();
    80002114:	dcdfe0ef          	jal	80000ee0 <kalloc>
    80002118:	00050993          	mv	s3,a0
  if (mem == 0)
    8000211c:	04050663          	beqz	a0,80002168 <vmfault+0xd8>
  mem = (uint64)kalloc();
    80002120:	00050a13          	mv	s4,a0
  memset((void *)mem, 0, PGSIZE);
    80002124:	00001637          	lui	a2,0x1
    80002128:	00000593          	li	a1,0
    8000212c:	8b0ff0ef          	jal	800011dc <memset>
  if (mappages(p->pagetable, va, PGSIZE, mem, PTE_W | PTE_U | PTE_R) != 0)
    80002130:	01600713          	li	a4,22
    80002134:	00098693          	mv	a3,s3
    80002138:	00001637          	lui	a2,0x1
    8000213c:	00090593          	mv	a1,s2
    80002140:	0504b503          	ld	a0,80(s1)
    80002144:	e74ff0ef          	jal	800017b8 <mappages>
    80002148:	00051663          	bnez	a0,80002154 <vmfault+0xc4>
    8000214c:	01813483          	ld	s1,24(sp)
    80002150:	f75ff06f          	j	800020c4 <vmfault+0x34>
    kfree((void *)mem);
    80002154:	00098513          	mv	a0,s3
    80002158:	c39fe0ef          	jal	80000d90 <kfree>
    return 0;
    8000215c:	00000a13          	li	s4,0
    80002160:	01813483          	ld	s1,24(sp)
    80002164:	f61ff06f          	j	800020c4 <vmfault+0x34>
    80002168:	01813483          	ld	s1,24(sp)
    8000216c:	f59ff06f          	j	800020c4 <vmfault+0x34>

0000000080002170 <copyout>:
  while (len > 0)
    80002170:	0e068863          	beqz	a3,80002260 <copyout+0xf0>
{
    80002174:	fa010113          	addi	sp,sp,-96
    80002178:	04113c23          	sd	ra,88(sp)
    8000217c:	04813823          	sd	s0,80(sp)
    80002180:	04913423          	sd	s1,72(sp)
    80002184:	05213023          	sd	s2,64(sp)
    80002188:	03313c23          	sd	s3,56(sp)
    8000218c:	03413823          	sd	s4,48(sp)
    80002190:	03513423          	sd	s5,40(sp)
    80002194:	03613023          	sd	s6,32(sp)
    80002198:	01713c23          	sd	s7,24(sp)
    8000219c:	01813823          	sd	s8,16(sp)
    800021a0:	01913423          	sd	s9,8(sp)
    800021a4:	01a13023          	sd	s10,0(sp)
    800021a8:	06010413          	addi	s0,sp,96
    800021ac:	00050b93          	mv	s7,a0
    800021b0:	00058a13          	mv	s4,a1
    800021b4:	00060b13          	mv	s6,a2
    800021b8:	00068a93          	mv	s5,a3
    va0 = PGROUNDDOWN(dstva);
    800021bc:	fffffd37          	lui	s10,0xfffff
    if (va0 >= MAXVA)
    800021c0:	fff00c93          	li	s9,-1
    800021c4:	01acdc93          	srli	s9,s9,0x1a
    n = PGSIZE - (dstva - va0);
    800021c8:	00001c37          	lui	s8,0x1
    800021cc:	0280006f          	j	800021f4 <copyout+0x84>
    memmove((void *)(pa0 + (dstva - va0)), src, n);
    800021d0:	409a0533          	sub	a0,s4,s1
    800021d4:	0009061b          	sext.w	a2,s2
    800021d8:	000b0593          	mv	a1,s6
    800021dc:	01350533          	add	a0,a0,s3
    800021e0:	898ff0ef          	jal	80001278 <memmove>
    len -= n;
    800021e4:	412a8ab3          	sub	s5,s5,s2
    src += n;
    800021e8:	012b0b33          	add	s6,s6,s2
    dstva = va0 + PGSIZE;
    800021ec:	01848a33          	add	s4,s1,s8
  while (len > 0)
    800021f0:	060a8463          	beqz	s5,80002258 <copyout+0xe8>
    va0 = PGROUNDDOWN(dstva);
    800021f4:	01aa74b3          	and	s1,s4,s10
    if (va0 >= MAXVA)
    800021f8:	069ce863          	bltu	s9,s1,80002268 <copyout+0xf8>
    pa0 = walkaddr(pagetable, va0);
    800021fc:	00048593          	mv	a1,s1
    80002200:	000b8513          	mv	a0,s7
    80002204:	d54ff0ef          	jal	80001758 <walkaddr>
    80002208:	00050993          	mv	s3,a0
    if (pa0 == 0)
    8000220c:	00051e63          	bnez	a0,80002228 <copyout+0xb8>
      if ((pa0 = vmfault(pagetable, va0, 0)) == 0)
    80002210:	00000613          	li	a2,0
    80002214:	00048593          	mv	a1,s1
    80002218:	000b8513          	mv	a0,s7
    8000221c:	e75ff0ef          	jal	80002090 <vmfault>
    80002220:	00050993          	mv	s3,a0
    80002224:	08050063          	beqz	a0,800022a4 <copyout+0x134>
    pte = walk(pagetable, va0, 0);
    80002228:	00000613          	li	a2,0
    8000222c:	00048593          	mv	a1,s1
    80002230:	000b8513          	mv	a0,s7
    80002234:	c34ff0ef          	jal	80001668 <walk>
    if ((*pte & PTE_W) == 0)
    80002238:	00053783          	ld	a5,0(a0)
    8000223c:	0047f793          	andi	a5,a5,4
    80002240:	06078663          	beqz	a5,800022ac <copyout+0x13c>
    n = PGSIZE - (dstva - va0);
    80002244:	41448933          	sub	s2,s1,s4
    80002248:	01890933          	add	s2,s2,s8
    if (n > len)
    8000224c:	f92af2e3          	bgeu	s5,s2,800021d0 <copyout+0x60>
    80002250:	000a8913          	mv	s2,s5
    80002254:	f7dff06f          	j	800021d0 <copyout+0x60>
  return 0;
    80002258:	00000513          	li	a0,0
    8000225c:	0100006f          	j	8000226c <copyout+0xfc>
    80002260:	00000513          	li	a0,0
}
    80002264:	00008067          	ret
      return -1;
    80002268:	fff00513          	li	a0,-1
}
    8000226c:	05813083          	ld	ra,88(sp)
    80002270:	05013403          	ld	s0,80(sp)
    80002274:	04813483          	ld	s1,72(sp)
    80002278:	04013903          	ld	s2,64(sp)
    8000227c:	03813983          	ld	s3,56(sp)
    80002280:	03013a03          	ld	s4,48(sp)
    80002284:	02813a83          	ld	s5,40(sp)
    80002288:	02013b03          	ld	s6,32(sp)
    8000228c:	01813b83          	ld	s7,24(sp)
    80002290:	01013c03          	ld	s8,16(sp)
    80002294:	00813c83          	ld	s9,8(sp)
    80002298:	00013d03          	ld	s10,0(sp)
    8000229c:	06010113          	addi	sp,sp,96
    800022a0:	00008067          	ret
        return -1;
    800022a4:	fff00513          	li	a0,-1
    800022a8:	fc5ff06f          	j	8000226c <copyout+0xfc>
      return -1;
    800022ac:	fff00513          	li	a0,-1
    800022b0:	fbdff06f          	j	8000226c <copyout+0xfc>

00000000800022b4 <copyin>:
  while (len > 0)
    800022b4:	0e068463          	beqz	a3,8000239c <copyin+0xe8>
{
    800022b8:	fb010113          	addi	sp,sp,-80
    800022bc:	04113423          	sd	ra,72(sp)
    800022c0:	04813023          	sd	s0,64(sp)
    800022c4:	02913c23          	sd	s1,56(sp)
    800022c8:	03213823          	sd	s2,48(sp)
    800022cc:	03313423          	sd	s3,40(sp)
    800022d0:	03413023          	sd	s4,32(sp)
    800022d4:	01513c23          	sd	s5,24(sp)
    800022d8:	01613823          	sd	s6,16(sp)
    800022dc:	01713423          	sd	s7,8(sp)
    800022e0:	01813023          	sd	s8,0(sp)
    800022e4:	05010413          	addi	s0,sp,80
    800022e8:	00050b93          	mv	s7,a0
    800022ec:	00058a93          	mv	s5,a1
    800022f0:	00060913          	mv	s2,a2
    800022f4:	00068a13          	mv	s4,a3
    va0 = PGROUNDDOWN(srcva);
    800022f8:	fffffc37          	lui	s8,0xfffff
    n = PGSIZE - (srcva - va0);
    800022fc:	00001b37          	lui	s6,0x1
    80002300:	0380006f          	j	80002338 <copyin+0x84>
    80002304:	412984b3          	sub	s1,s3,s2
    80002308:	016484b3          	add	s1,s1,s6
    if (n > len)
    8000230c:	009a7463          	bgeu	s4,s1,80002314 <copyin+0x60>
    80002310:	000a0493          	mv	s1,s4
    memmove(dst, (void *)(pa0 + (srcva - va0)), n);
    80002314:	413905b3          	sub	a1,s2,s3
    80002318:	0004861b          	sext.w	a2,s1
    8000231c:	00a585b3          	add	a1,a1,a0
    80002320:	000a8513          	mv	a0,s5
    80002324:	f55fe0ef          	jal	80001278 <memmove>
    len -= n;
    80002328:	409a0a33          	sub	s4,s4,s1
    dst += n;
    8000232c:	009a8ab3          	add	s5,s5,s1
    srcva = va0 + PGSIZE;
    80002330:	01698933          	add	s2,s3,s6
  while (len > 0)
    80002334:	020a0a63          	beqz	s4,80002368 <copyin+0xb4>
    va0 = PGROUNDDOWN(srcva);
    80002338:	018979b3          	and	s3,s2,s8
    pa0 = walkaddr(pagetable, va0);
    8000233c:	00098593          	mv	a1,s3
    80002340:	000b8513          	mv	a0,s7
    80002344:	c14ff0ef          	jal	80001758 <walkaddr>
    if (pa0 == 0)
    80002348:	fa051ee3          	bnez	a0,80002304 <copyin+0x50>
      if ((pa0 = vmfault(pagetable, va0, 0)) == 0)
    8000234c:	00000613          	li	a2,0
    80002350:	00098593          	mv	a1,s3
    80002354:	000b8513          	mv	a0,s7
    80002358:	d39ff0ef          	jal	80002090 <vmfault>
    8000235c:	fa0514e3          	bnez	a0,80002304 <copyin+0x50>
        return -1;
    80002360:	fff00513          	li	a0,-1
    80002364:	0080006f          	j	8000236c <copyin+0xb8>
  return 0;
    80002368:	00000513          	li	a0,0
}
    8000236c:	04813083          	ld	ra,72(sp)
    80002370:	04013403          	ld	s0,64(sp)
    80002374:	03813483          	ld	s1,56(sp)
    80002378:	03013903          	ld	s2,48(sp)
    8000237c:	02813983          	ld	s3,40(sp)
    80002380:	02013a03          	ld	s4,32(sp)
    80002384:	01813a83          	ld	s5,24(sp)
    80002388:	01013b03          	ld	s6,16(sp)
    8000238c:	00813b83          	ld	s7,8(sp)
    80002390:	00013c03          	ld	s8,0(sp)
    80002394:	05010113          	addi	sp,sp,80
    80002398:	00008067          	ret
  return 0;
    8000239c:	00000513          	li	a0,0
}
    800023a0:	00008067          	ret

00000000800023a4 <proc_mapstacks>:

// Allocate a page for each process's kernel stack.
// Map it high in memory, followed by an invalid
// guard page.
void proc_mapstacks(pagetable_t kpgtbl)
{
    800023a4:	fb010113          	addi	sp,sp,-80
    800023a8:	04113423          	sd	ra,72(sp)
    800023ac:	04813023          	sd	s0,64(sp)
    800023b0:	02913c23          	sd	s1,56(sp)
    800023b4:	03213823          	sd	s2,48(sp)
    800023b8:	03313423          	sd	s3,40(sp)
    800023bc:	03413023          	sd	s4,32(sp)
    800023c0:	01513c23          	sd	s5,24(sp)
    800023c4:	01613823          	sd	s6,16(sp)
    800023c8:	01713423          	sd	s7,8(sp)
    800023cc:	01813023          	sd	s8,0(sp)
    800023d0:	05010413          	addi	s0,sp,80
    800023d4:	00050a13          	mv	s4,a0
  struct proc *p;

  for (p = proc; p < &proc[NPROC]; p++)
    800023d8:	00204497          	auipc	s1,0x204
    800023dc:	cd048493          	addi	s1,s1,-816 # 802060a8 <proc>
  {
    char *pa = kalloc();
    if (pa == 0)
      panic("kalloc");
    uint64 va = KSTACK((int)(p - proc));
    800023e0:	00048c13          	mv	s8,s1
    800023e4:	000a57b7          	lui	a5,0xa5
    800023e8:	fa578793          	addi	a5,a5,-91 # a4fa5 <_binary_fs_img_size-0x14f05b>
    800023ec:	00c79793          	slli	a5,a5,0xc
    800023f0:	fa578793          	addi	a5,a5,-91
    800023f4:	4fa50937          	lui	s2,0x4fa50
    800023f8:	a4f90913          	addi	s2,s2,-1457 # 4fa4fa4f <_binary_fs_img_size+0x4f85ba4f>
    800023fc:	02091913          	slli	s2,s2,0x20
    80002400:	00f90933          	add	s2,s2,a5
    80002404:	040009b7          	lui	s3,0x4000
    80002408:	fff98993          	addi	s3,s3,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    8000240c:	00c99993          	slli	s3,s3,0xc
    kvmmap(kpgtbl, va, (uint64)pa, PGSIZE, PTE_R | PTE_W);
    80002410:	00600b93          	li	s7,6
    80002414:	00001b37          	lui	s6,0x1
  for (p = proc; p < &proc[NPROC]; p++)
    80002418:	00209a97          	auipc	s5,0x209
    8000241c:	690a8a93          	addi	s5,s5,1680 # 8020baa8 <tickslock>
    char *pa = kalloc();
    80002420:	ac1fe0ef          	jal	80000ee0 <kalloc>
    80002424:	00050613          	mv	a2,a0
    if (pa == 0)
    80002428:	06050463          	beqz	a0,80002490 <proc_mapstacks+0xec>
    uint64 va = KSTACK((int)(p - proc));
    8000242c:	418485b3          	sub	a1,s1,s8
    80002430:	4035d593          	srai	a1,a1,0x3
    80002434:	032585b3          	mul	a1,a1,s2
    80002438:	00d59593          	slli	a1,a1,0xd
    8000243c:	000027b7          	lui	a5,0x2
    80002440:	00f585bb          	addw	a1,a1,a5
    kvmmap(kpgtbl, va, (uint64)pa, PGSIZE, PTE_R | PTE_W);
    80002444:	000b8713          	mv	a4,s7
    80002448:	000b0693          	mv	a3,s6
    8000244c:	40b985b3          	sub	a1,s3,a1
    80002450:	000a0513          	mv	a0,s4
    80002454:	c74ff0ef          	jal	800018c8 <kvmmap>
  for (p = proc; p < &proc[NPROC]; p++)
    80002458:	16848493          	addi	s1,s1,360
    8000245c:	fd5492e3          	bne	s1,s5,80002420 <proc_mapstacks+0x7c>
  }
}
    80002460:	04813083          	ld	ra,72(sp)
    80002464:	04013403          	ld	s0,64(sp)
    80002468:	03813483          	ld	s1,56(sp)
    8000246c:	03013903          	ld	s2,48(sp)
    80002470:	02813983          	ld	s3,40(sp)
    80002474:	02013a03          	ld	s4,32(sp)
    80002478:	01813a83          	ld	s5,24(sp)
    8000247c:	01013b03          	ld	s6,16(sp)
    80002480:	00813b83          	ld	s7,8(sp)
    80002484:	00013c03          	ld	s8,0(sp)
    80002488:	05010113          	addi	sp,sp,80
    8000248c:	00008067          	ret
      panic("kalloc");
    80002490:	00007517          	auipc	a0,0x7
    80002494:	f9850513          	addi	a0,a0,-104 # 80009428 <etext+0x428>
    80002498:	e54fe0ef          	jal	80000aec <panic>

000000008000249c <procinit>:

// initialize the proc table.
void procinit(void)
{
    8000249c:	fc010113          	addi	sp,sp,-64
    800024a0:	02113c23          	sd	ra,56(sp)
    800024a4:	02813823          	sd	s0,48(sp)
    800024a8:	02913423          	sd	s1,40(sp)
    800024ac:	03213023          	sd	s2,32(sp)
    800024b0:	01313c23          	sd	s3,24(sp)
    800024b4:	01413823          	sd	s4,16(sp)
    800024b8:	01513423          	sd	s5,8(sp)
    800024bc:	01613023          	sd	s6,0(sp)
    800024c0:	04010413          	addi	s0,sp,64
  struct proc *p;

  initlock(&pid_lock, "nextpid");
    800024c4:	00007597          	auipc	a1,0x7
    800024c8:	f6c58593          	addi	a1,a1,-148 # 80009430 <etext+0x430>
    800024cc:	00203517          	auipc	a0,0x203
    800024d0:	7ac50513          	addi	a0,a0,1964 # 80205c78 <pid_lock>
    800024d4:	a89fe0ef          	jal	80000f5c <initlock>
  initlock(&wait_lock, "wait_lock");
    800024d8:	00007597          	auipc	a1,0x7
    800024dc:	f6058593          	addi	a1,a1,-160 # 80009438 <etext+0x438>
    800024e0:	00203517          	auipc	a0,0x203
    800024e4:	7b050513          	addi	a0,a0,1968 # 80205c90 <wait_lock>
    800024e8:	a75fe0ef          	jal	80000f5c <initlock>
  for (p = proc; p < &proc[NPROC]; p++)
    800024ec:	00204497          	auipc	s1,0x204
    800024f0:	bbc48493          	addi	s1,s1,-1092 # 802060a8 <proc>
  {
    initlock(&p->lock, "proc");
    800024f4:	00007b17          	auipc	s6,0x7
    800024f8:	f54b0b13          	addi	s6,s6,-172 # 80009448 <etext+0x448>
    p->state = UNUSED;
    p->kstack = KSTACK((int)(p - proc));
    800024fc:	00048a93          	mv	s5,s1
    80002500:	000a57b7          	lui	a5,0xa5
    80002504:	fa578793          	addi	a5,a5,-91 # a4fa5 <_binary_fs_img_size-0x14f05b>
    80002508:	00c79793          	slli	a5,a5,0xc
    8000250c:	fa578793          	addi	a5,a5,-91
    80002510:	4fa50937          	lui	s2,0x4fa50
    80002514:	a4f90913          	addi	s2,s2,-1457 # 4fa4fa4f <_binary_fs_img_size+0x4f85ba4f>
    80002518:	02091913          	slli	s2,s2,0x20
    8000251c:	00f90933          	add	s2,s2,a5
    80002520:	040009b7          	lui	s3,0x4000
    80002524:	fff98993          	addi	s3,s3,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    80002528:	00c99993          	slli	s3,s3,0xc
  for (p = proc; p < &proc[NPROC]; p++)
    8000252c:	00209a17          	auipc	s4,0x209
    80002530:	57ca0a13          	addi	s4,s4,1404 # 8020baa8 <tickslock>
    initlock(&p->lock, "proc");
    80002534:	000b0593          	mv	a1,s6
    80002538:	00048513          	mv	a0,s1
    8000253c:	a21fe0ef          	jal	80000f5c <initlock>
    p->state = UNUSED;
    80002540:	0004ac23          	sw	zero,24(s1)
    p->kstack = KSTACK((int)(p - proc));
    80002544:	415487b3          	sub	a5,s1,s5
    80002548:	4037d793          	srai	a5,a5,0x3
    8000254c:	032787b3          	mul	a5,a5,s2
    80002550:	00d79793          	slli	a5,a5,0xd
    80002554:	00002737          	lui	a4,0x2
    80002558:	00e787bb          	addw	a5,a5,a4
    8000255c:	40f987b3          	sub	a5,s3,a5
    80002560:	04f4b023          	sd	a5,64(s1)
  for (p = proc; p < &proc[NPROC]; p++)
    80002564:	16848493          	addi	s1,s1,360
    80002568:	fd4496e3          	bne	s1,s4,80002534 <procinit+0x98>
  }
}
    8000256c:	03813083          	ld	ra,56(sp)
    80002570:	03013403          	ld	s0,48(sp)
    80002574:	02813483          	ld	s1,40(sp)
    80002578:	02013903          	ld	s2,32(sp)
    8000257c:	01813983          	ld	s3,24(sp)
    80002580:	01013a03          	ld	s4,16(sp)
    80002584:	00813a83          	ld	s5,8(sp)
    80002588:	00013b03          	ld	s6,0(sp)
    8000258c:	04010113          	addi	sp,sp,64
    80002590:	00008067          	ret

0000000080002594 <cpuid>:

// Must be called with interrupts disabled,
// to prevent race with process being moved
// to a different CPU.
int cpuid()
{
    80002594:	ff010113          	addi	sp,sp,-16
    80002598:	00113423          	sd	ra,8(sp)
    8000259c:	00813023          	sd	s0,0(sp)
    800025a0:	01010413          	addi	s0,sp,16
  asm volatile("mv %0, tp" : "=r"(x));
    800025a4:	00020513          	mv	a0,tp
  int id = r_tp();
  return id;
}
    800025a8:	0005051b          	sext.w	a0,a0
    800025ac:	00813083          	ld	ra,8(sp)
    800025b0:	00013403          	ld	s0,0(sp)
    800025b4:	01010113          	addi	sp,sp,16
    800025b8:	00008067          	ret

00000000800025bc <mycpu>:

// Return this CPU's cpu struct.
// Interrupts must be disabled.
struct cpu *
mycpu(void)
{
    800025bc:	ff010113          	addi	sp,sp,-16
    800025c0:	00113423          	sd	ra,8(sp)
    800025c4:	00813023          	sd	s0,0(sp)
    800025c8:	01010413          	addi	s0,sp,16
    800025cc:	00020793          	mv	a5,tp
  int id = cpuid();
  struct cpu *c = &cpus[id];
    800025d0:	0007879b          	sext.w	a5,a5
    800025d4:	00779793          	slli	a5,a5,0x7
  return c;
}
    800025d8:	00203517          	auipc	a0,0x203
    800025dc:	6d050513          	addi	a0,a0,1744 # 80205ca8 <cpus>
    800025e0:	00f50533          	add	a0,a0,a5
    800025e4:	00813083          	ld	ra,8(sp)
    800025e8:	00013403          	ld	s0,0(sp)
    800025ec:	01010113          	addi	sp,sp,16
    800025f0:	00008067          	ret

00000000800025f4 <myproc>:

// Return the current struct proc *, or zero if none.
struct proc *
myproc(void)
{
    800025f4:	fe010113          	addi	sp,sp,-32
    800025f8:	00113c23          	sd	ra,24(sp)
    800025fc:	00813823          	sd	s0,16(sp)
    80002600:	00913423          	sd	s1,8(sp)
    80002604:	02010413          	addi	s0,sp,32
  push_off();
    80002608:	9cdfe0ef          	jal	80000fd4 <push_off>
    8000260c:	00020793          	mv	a5,tp
  struct cpu *c = mycpu();
  struct proc *p = c->proc;
    80002610:	0007879b          	sext.w	a5,a5
    80002614:	00779793          	slli	a5,a5,0x7
    80002618:	00203717          	auipc	a4,0x203
    8000261c:	66070713          	addi	a4,a4,1632 # 80205c78 <pid_lock>
    80002620:	00f707b3          	add	a5,a4,a5
    80002624:	0307b783          	ld	a5,48(a5)
    80002628:	00078493          	mv	s1,a5
  pop_off();
    8000262c:	a7dfe0ef          	jal	800010a8 <pop_off>
  return p;
}
    80002630:	00048513          	mv	a0,s1
    80002634:	01813083          	ld	ra,24(sp)
    80002638:	01013403          	ld	s0,16(sp)
    8000263c:	00813483          	ld	s1,8(sp)
    80002640:	02010113          	addi	sp,sp,32
    80002644:	00008067          	ret

0000000080002648 <forkret>:
}

// A fork child's very first scheduling by scheduler()
// will swtch to forkret.
void forkret(void)
{
    80002648:	fd010113          	addi	sp,sp,-48
    8000264c:	02113423          	sd	ra,40(sp)
    80002650:	02813023          	sd	s0,32(sp)
    80002654:	00913c23          	sd	s1,24(sp)
    80002658:	03010413          	addi	s0,sp,48
  extern char userret[];
  static int first = 1;
  struct proc *p = myproc();
    8000265c:	f99ff0ef          	jal	800025f4 <myproc>
    80002660:	00050493          	mv	s1,a0

  // Still holding p->lock from scheduler.
  release(&p->lock);
    80002664:	ab5fe0ef          	jal	80001118 <release>

  if (first)
    80002668:	00007797          	auipc	a5,0x7
    8000266c:	4d87a783          	lw	a5,1240(a5) # 80009b40 <first.1>
    80002670:	06078263          	beqz	a5,800026d4 <forkret+0x8c>
  {
    printf("[LOG][proc.c] first forkret() is executing\n");
    80002674:	00007517          	auipc	a0,0x7
    80002678:	ddc50513          	addi	a0,a0,-548 # 80009450 <etext+0x450>
    8000267c:	850fe0ef          	jal	800006cc <printf>
    // File system initialization must be run in the context of a
    // regular process (e.g., because it calls sleep), and thus cannot
    // be run from main().
    fsinit(ROOTDEV);
    80002680:	00100513          	li	a0,1
    80002684:	059020ef          	jal	80004edc <fsinit>

    printf("[LOG][proc.c] fsinit in forkret has ended.\n");
    80002688:	00007517          	auipc	a0,0x7
    8000268c:	df850513          	addi	a0,a0,-520 # 80009480 <etext+0x480>
    80002690:	83cfe0ef          	jal	800006cc <printf>

    first = 0;
    80002694:	00007797          	auipc	a5,0x7
    80002698:	4a07a623          	sw	zero,1196(a5) # 80009b40 <first.1>
    // ensure other cores see first=0.
    __sync_synchronize();
    8000269c:	0330000f          	fence	rw,rw

    // We can invoke kexec() now that file system is initialized.
    // Put the return value (argc) of kexec into a0.
    // ファイルシステムが初期化されたのでkexec()を呼べる.
    // kexecを実行して得られた戻り値をa0に積む.
    p->trapframe->a0 = kexec("/init", (char *[]){"/init", 0});
    800026a0:	00007797          	auipc	a5,0x7
    800026a4:	e1078793          	addi	a5,a5,-496 # 800094b0 <etext+0x4b0>
    800026a8:	fcf43823          	sd	a5,-48(s0)
    800026ac:	fc043c23          	sd	zero,-40(s0)
    800026b0:	fd040593          	addi	a1,s0,-48
    800026b4:	00078513          	mv	a0,a5
    800026b8:	260040ef          	jal	80006918 <kexec>
    800026bc:	0584b783          	ld	a5,88(s1)
    800026c0:	06a7b823          	sd	a0,112(a5)
    if (p->trapframe->a0 == -1)
    800026c4:	0584b783          	ld	a5,88(s1)
    800026c8:	0707b703          	ld	a4,112(a5)
    800026cc:	fff00793          	li	a5,-1
    800026d0:	06f70a63          	beq	a4,a5,80002744 <forkret+0xfc>
    {
      panic("exec");
    }
  }

  printf("[LOG][proc.c] special procedure for first time done.\n");
    800026d4:	00007517          	auipc	a0,0x7
    800026d8:	dec50513          	addi	a0,a0,-532 # 800094c0 <etext+0x4c0>
    800026dc:	ff1fd0ef          	jal	800006cc <printf>

  // return to user space, mimicing usertrap()'s return.
  prepare_return();
    800026e0:	7c9000ef          	jal	800036a8 <prepare_return>
  uint64 satp = MAKE_SATP(p->pagetable);
    800026e4:	0504b783          	ld	a5,80(s1)
    800026e8:	00c7d793          	srli	a5,a5,0xc
    800026ec:	fff00713          	li	a4,-1
    800026f0:	03f71713          	slli	a4,a4,0x3f
    800026f4:	00e7e4b3          	or	s1,a5,a4
  uint64 trampoline_userret = TRAMPOLINE + (userret - trampoline);
  printf("[LOG][proc.c] forkert done. jump to trampoline_userret.\n");
    800026f8:	00007517          	auipc	a0,0x7
    800026fc:	e0050513          	addi	a0,a0,-512 # 800094f8 <etext+0x4f8>
    80002700:	fcdfd0ef          	jal	800006cc <printf>
  uint64 trampoline_userret = TRAMPOLINE + (userret - trampoline);
    80002704:	04000737          	lui	a4,0x4000
    80002708:	fff70713          	addi	a4,a4,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    8000270c:	00c71713          	slli	a4,a4,0xc
    80002710:	00006797          	auipc	a5,0x6
    80002714:	9a078793          	addi	a5,a5,-1632 # 800080b0 <userret>
    80002718:	00006697          	auipc	a3,0x6
    8000271c:	8e868693          	addi	a3,a3,-1816 # 80008000 <_trampoline>
    80002720:	40d787b3          	sub	a5,a5,a3
    80002724:	00e787b3          	add	a5,a5,a4
  ((void (*)(uint64))trampoline_userret)(satp);
    80002728:	00048513          	mv	a0,s1
    8000272c:	000780e7          	jalr	a5
}
    80002730:	02813083          	ld	ra,40(sp)
    80002734:	02013403          	ld	s0,32(sp)
    80002738:	01813483          	ld	s1,24(sp)
    8000273c:	03010113          	addi	sp,sp,48
    80002740:	00008067          	ret
      panic("exec");
    80002744:	00007517          	auipc	a0,0x7
    80002748:	d7450513          	addi	a0,a0,-652 # 800094b8 <etext+0x4b8>
    8000274c:	ba0fe0ef          	jal	80000aec <panic>

0000000080002750 <allocpid>:
{
    80002750:	fe010113          	addi	sp,sp,-32
    80002754:	00113c23          	sd	ra,24(sp)
    80002758:	00813823          	sd	s0,16(sp)
    8000275c:	00913423          	sd	s1,8(sp)
    80002760:	02010413          	addi	s0,sp,32
  acquire(&pid_lock);
    80002764:	00203517          	auipc	a0,0x203
    80002768:	51450513          	addi	a0,a0,1300 # 80205c78 <pid_lock>
    8000276c:	8d5fe0ef          	jal	80001040 <acquire>
  pid = nextpid;
    80002770:	00007797          	auipc	a5,0x7
    80002774:	3d478793          	addi	a5,a5,980 # 80009b44 <nextpid>
    80002778:	0007a483          	lw	s1,0(a5)
  nextpid = nextpid + 1;
    8000277c:	0014871b          	addiw	a4,s1,1
    80002780:	00e7a023          	sw	a4,0(a5)
  release(&pid_lock);
    80002784:	00203517          	auipc	a0,0x203
    80002788:	4f450513          	addi	a0,a0,1268 # 80205c78 <pid_lock>
    8000278c:	98dfe0ef          	jal	80001118 <release>
}
    80002790:	00048513          	mv	a0,s1
    80002794:	01813083          	ld	ra,24(sp)
    80002798:	01013403          	ld	s0,16(sp)
    8000279c:	00813483          	ld	s1,8(sp)
    800027a0:	02010113          	addi	sp,sp,32
    800027a4:	00008067          	ret

00000000800027a8 <proc_pagetable>:
{
    800027a8:	fe010113          	addi	sp,sp,-32
    800027ac:	00113c23          	sd	ra,24(sp)
    800027b0:	00813823          	sd	s0,16(sp)
    800027b4:	00913423          	sd	s1,8(sp)
    800027b8:	01213023          	sd	s2,0(sp)
    800027bc:	02010413          	addi	s0,sp,32
    800027c0:	00050913          	mv	s2,a0
  pagetable = uvmcreate();
    800027c4:	a70ff0ef          	jal	80001a34 <uvmcreate>
    800027c8:	00050493          	mv	s1,a0
  if (pagetable == 0)
    800027cc:	04050663          	beqz	a0,80002818 <proc_pagetable+0x70>
  if (mappages(pagetable, TRAMPOLINE, PGSIZE,
    800027d0:	00a00713          	li	a4,10
    800027d4:	00006697          	auipc	a3,0x6
    800027d8:	82c68693          	addi	a3,a3,-2004 # 80008000 <_trampoline>
    800027dc:	00001637          	lui	a2,0x1
    800027e0:	040005b7          	lui	a1,0x4000
    800027e4:	fff58593          	addi	a1,a1,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    800027e8:	00c59593          	slli	a1,a1,0xc
    800027ec:	fcdfe0ef          	jal	800017b8 <mappages>
    800027f0:	04054263          	bltz	a0,80002834 <proc_pagetable+0x8c>
  if (mappages(pagetable, TRAPFRAME, PGSIZE,
    800027f4:	00600713          	li	a4,6
    800027f8:	05893683          	ld	a3,88(s2)
    800027fc:	00001637          	lui	a2,0x1
    80002800:	020005b7          	lui	a1,0x2000
    80002804:	fff58593          	addi	a1,a1,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    80002808:	00d59593          	slli	a1,a1,0xd
    8000280c:	00048513          	mv	a0,s1
    80002810:	fa9fe0ef          	jal	800017b8 <mappages>
    80002814:	02054a63          	bltz	a0,80002848 <proc_pagetable+0xa0>
}
    80002818:	00048513          	mv	a0,s1
    8000281c:	01813083          	ld	ra,24(sp)
    80002820:	01013403          	ld	s0,16(sp)
    80002824:	00813483          	ld	s1,8(sp)
    80002828:	00013903          	ld	s2,0(sp)
    8000282c:	02010113          	addi	sp,sp,32
    80002830:	00008067          	ret
    uvmfree(pagetable, 0);
    80002834:	00000593          	li	a1,0
    80002838:	00048513          	mv	a0,s1
    8000283c:	d54ff0ef          	jal	80001d90 <uvmfree>
    return 0;
    80002840:	00000493          	li	s1,0
    80002844:	fd5ff06f          	j	80002818 <proc_pagetable+0x70>
    uvmunmap(pagetable, TRAMPOLINE, 1, 0);
    80002848:	00000693          	li	a3,0
    8000284c:	00100613          	li	a2,1
    80002850:	040005b7          	lui	a1,0x4000
    80002854:	fff58593          	addi	a1,a1,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    80002858:	00c59593          	slli	a1,a1,0xc
    8000285c:	00048513          	mv	a0,s1
    80002860:	a18ff0ef          	jal	80001a78 <uvmunmap>
    uvmfree(pagetable, 0);
    80002864:	00000593          	li	a1,0
    80002868:	00048513          	mv	a0,s1
    8000286c:	d24ff0ef          	jal	80001d90 <uvmfree>
    return 0;
    80002870:	00000493          	li	s1,0
    80002874:	fa5ff06f          	j	80002818 <proc_pagetable+0x70>

0000000080002878 <proc_freepagetable>:
{
    80002878:	fe010113          	addi	sp,sp,-32
    8000287c:	00113c23          	sd	ra,24(sp)
    80002880:	00813823          	sd	s0,16(sp)
    80002884:	00913423          	sd	s1,8(sp)
    80002888:	01213023          	sd	s2,0(sp)
    8000288c:	02010413          	addi	s0,sp,32
    80002890:	00050493          	mv	s1,a0
    80002894:	00058913          	mv	s2,a1
  uvmunmap(pagetable, TRAMPOLINE, 1, 0);
    80002898:	00000693          	li	a3,0
    8000289c:	00100613          	li	a2,1
    800028a0:	040005b7          	lui	a1,0x4000
    800028a4:	fff58593          	addi	a1,a1,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    800028a8:	00c59593          	slli	a1,a1,0xc
    800028ac:	9ccff0ef          	jal	80001a78 <uvmunmap>
  uvmunmap(pagetable, TRAPFRAME, 1, 0);
    800028b0:	00000693          	li	a3,0
    800028b4:	00100613          	li	a2,1
    800028b8:	020005b7          	lui	a1,0x2000
    800028bc:	fff58593          	addi	a1,a1,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    800028c0:	00d59593          	slli	a1,a1,0xd
    800028c4:	00048513          	mv	a0,s1
    800028c8:	9b0ff0ef          	jal	80001a78 <uvmunmap>
  uvmfree(pagetable, sz);
    800028cc:	00090593          	mv	a1,s2
    800028d0:	00048513          	mv	a0,s1
    800028d4:	cbcff0ef          	jal	80001d90 <uvmfree>
}
    800028d8:	01813083          	ld	ra,24(sp)
    800028dc:	01013403          	ld	s0,16(sp)
    800028e0:	00813483          	ld	s1,8(sp)
    800028e4:	00013903          	ld	s2,0(sp)
    800028e8:	02010113          	addi	sp,sp,32
    800028ec:	00008067          	ret

00000000800028f0 <freeproc>:
{
    800028f0:	fe010113          	addi	sp,sp,-32
    800028f4:	00113c23          	sd	ra,24(sp)
    800028f8:	00813823          	sd	s0,16(sp)
    800028fc:	00913423          	sd	s1,8(sp)
    80002900:	02010413          	addi	s0,sp,32
    80002904:	00050493          	mv	s1,a0
  if (p->trapframe)
    80002908:	05853503          	ld	a0,88(a0)
    8000290c:	00050463          	beqz	a0,80002914 <freeproc+0x24>
    kfree((void *)p->trapframe);
    80002910:	c80fe0ef          	jal	80000d90 <kfree>
  p->trapframe = 0;
    80002914:	0404bc23          	sd	zero,88(s1)
  if (p->pagetable)
    80002918:	0504b503          	ld	a0,80(s1)
    8000291c:	00050663          	beqz	a0,80002928 <freeproc+0x38>
    proc_freepagetable(p->pagetable, p->sz);
    80002920:	0484b583          	ld	a1,72(s1)
    80002924:	f55ff0ef          	jal	80002878 <proc_freepagetable>
  p->pagetable = 0;
    80002928:	0404b823          	sd	zero,80(s1)
  p->sz = 0;
    8000292c:	0404b423          	sd	zero,72(s1)
  p->pid = 0;
    80002930:	0204a823          	sw	zero,48(s1)
  p->parent = 0;
    80002934:	0204bc23          	sd	zero,56(s1)
  p->name[0] = 0;
    80002938:	14048c23          	sb	zero,344(s1)
  p->chan = 0;
    8000293c:	0204b023          	sd	zero,32(s1)
  p->killed = 0;
    80002940:	0204a423          	sw	zero,40(s1)
  p->xstate = 0;
    80002944:	0204a623          	sw	zero,44(s1)
  p->state = UNUSED;
    80002948:	0004ac23          	sw	zero,24(s1)
}
    8000294c:	01813083          	ld	ra,24(sp)
    80002950:	01013403          	ld	s0,16(sp)
    80002954:	00813483          	ld	s1,8(sp)
    80002958:	02010113          	addi	sp,sp,32
    8000295c:	00008067          	ret

0000000080002960 <allocproc>:
{
    80002960:	fe010113          	addi	sp,sp,-32
    80002964:	00113c23          	sd	ra,24(sp)
    80002968:	00813823          	sd	s0,16(sp)
    8000296c:	00913423          	sd	s1,8(sp)
    80002970:	01213023          	sd	s2,0(sp)
    80002974:	02010413          	addi	s0,sp,32
  for (p = proc; p < &proc[NPROC]; p++)
    80002978:	00203497          	auipc	s1,0x203
    8000297c:	73048493          	addi	s1,s1,1840 # 802060a8 <proc>
    80002980:	00209917          	auipc	s2,0x209
    80002984:	12890913          	addi	s2,s2,296 # 8020baa8 <tickslock>
    acquire(&p->lock);
    80002988:	00048513          	mv	a0,s1
    8000298c:	eb4fe0ef          	jal	80001040 <acquire>
    if (p->state == UNUSED)
    80002990:	0184a783          	lw	a5,24(s1)
    80002994:	00078e63          	beqz	a5,800029b0 <allocproc+0x50>
      release(&p->lock);
    80002998:	00048513          	mv	a0,s1
    8000299c:	f7cfe0ef          	jal	80001118 <release>
  for (p = proc; p < &proc[NPROC]; p++)
    800029a0:	16848493          	addi	s1,s1,360
    800029a4:	ff2492e3          	bne	s1,s2,80002988 <allocproc+0x28>
  return 0;
    800029a8:	00000493          	li	s1,0
    800029ac:	0640006f          	j	80002a10 <allocproc+0xb0>
  p->pid = allocpid();
    800029b0:	da1ff0ef          	jal	80002750 <allocpid>
    800029b4:	02a4a823          	sw	a0,48(s1)
  p->state = USED;
    800029b8:	00100793          	li	a5,1
    800029bc:	00f4ac23          	sw	a5,24(s1)
  if ((p->trapframe = (struct trapframe *)kalloc()) == 0)
    800029c0:	d20fe0ef          	jal	80000ee0 <kalloc>
    800029c4:	00050913          	mv	s2,a0
    800029c8:	04a4bc23          	sd	a0,88(s1)
    800029cc:	06050063          	beqz	a0,80002a2c <allocproc+0xcc>
  p->pagetable = proc_pagetable(p);
    800029d0:	00048513          	mv	a0,s1
    800029d4:	dd5ff0ef          	jal	800027a8 <proc_pagetable>
    800029d8:	00050913          	mv	s2,a0
    800029dc:	04a4b823          	sd	a0,80(s1)
  if (p->pagetable == 0)
    800029e0:	06050263          	beqz	a0,80002a44 <allocproc+0xe4>
  memset(&p->context, 0, sizeof(p->context));
    800029e4:	07000613          	li	a2,112
    800029e8:	00000593          	li	a1,0
    800029ec:	06048513          	addi	a0,s1,96
    800029f0:	fecfe0ef          	jal	800011dc <memset>
  p->context.ra = (uint64)forkret;
    800029f4:	00000797          	auipc	a5,0x0
    800029f8:	c5478793          	addi	a5,a5,-940 # 80002648 <forkret>
    800029fc:	06f4b023          	sd	a5,96(s1)
  p->context.sp = p->kstack + PGSIZE;
    80002a00:	0404b783          	ld	a5,64(s1)
    80002a04:	00001737          	lui	a4,0x1
    80002a08:	00e787b3          	add	a5,a5,a4
    80002a0c:	06f4b423          	sd	a5,104(s1)
}
    80002a10:	00048513          	mv	a0,s1
    80002a14:	01813083          	ld	ra,24(sp)
    80002a18:	01013403          	ld	s0,16(sp)
    80002a1c:	00813483          	ld	s1,8(sp)
    80002a20:	00013903          	ld	s2,0(sp)
    80002a24:	02010113          	addi	sp,sp,32
    80002a28:	00008067          	ret
    freeproc(p);
    80002a2c:	00048513          	mv	a0,s1
    80002a30:	ec1ff0ef          	jal	800028f0 <freeproc>
    release(&p->lock);
    80002a34:	00048513          	mv	a0,s1
    80002a38:	ee0fe0ef          	jal	80001118 <release>
    return 0;
    80002a3c:	00090493          	mv	s1,s2
    80002a40:	fd1ff06f          	j	80002a10 <allocproc+0xb0>
    freeproc(p);
    80002a44:	00048513          	mv	a0,s1
    80002a48:	ea9ff0ef          	jal	800028f0 <freeproc>
    release(&p->lock);
    80002a4c:	00048513          	mv	a0,s1
    80002a50:	ec8fe0ef          	jal	80001118 <release>
    return 0;
    80002a54:	00090493          	mv	s1,s2
    80002a58:	fb9ff06f          	j	80002a10 <allocproc+0xb0>

0000000080002a5c <userinit>:
{
    80002a5c:	fe010113          	addi	sp,sp,-32
    80002a60:	00113c23          	sd	ra,24(sp)
    80002a64:	00813823          	sd	s0,16(sp)
    80002a68:	00913423          	sd	s1,8(sp)
    80002a6c:	02010413          	addi	s0,sp,32
  p = allocproc();
    80002a70:	ef1ff0ef          	jal	80002960 <allocproc>
    80002a74:	00050493          	mv	s1,a0
  initproc = p;
    80002a78:	001fb797          	auipc	a5,0x1fb
    80002a7c:	0ea7b823          	sd	a0,240(a5) # 801fdb68 <initproc>
  p->cwd = namei("/");
    80002a80:	00007517          	auipc	a0,0x7
    80002a84:	ab850513          	addi	a0,a0,-1352 # 80009538 <etext+0x538>
    80002a88:	455020ef          	jal	800056dc <namei>
    80002a8c:	14a4b823          	sd	a0,336(s1)
  p->state = RUNNABLE;
    80002a90:	00300793          	li	a5,3
    80002a94:	00f4ac23          	sw	a5,24(s1)
  release(&p->lock);
    80002a98:	00048513          	mv	a0,s1
    80002a9c:	e7cfe0ef          	jal	80001118 <release>
}
    80002aa0:	01813083          	ld	ra,24(sp)
    80002aa4:	01013403          	ld	s0,16(sp)
    80002aa8:	00813483          	ld	s1,8(sp)
    80002aac:	02010113          	addi	sp,sp,32
    80002ab0:	00008067          	ret

0000000080002ab4 <growproc>:
{
    80002ab4:	fe010113          	addi	sp,sp,-32
    80002ab8:	00113c23          	sd	ra,24(sp)
    80002abc:	00813823          	sd	s0,16(sp)
    80002ac0:	00913423          	sd	s1,8(sp)
    80002ac4:	01213023          	sd	s2,0(sp)
    80002ac8:	02010413          	addi	s0,sp,32
    80002acc:	00050493          	mv	s1,a0
  struct proc *p = myproc();
    80002ad0:	b25ff0ef          	jal	800025f4 <myproc>
    80002ad4:	00050913          	mv	s2,a0
  sz = p->sz;
    80002ad8:	04853583          	ld	a1,72(a0)
  if (n > 0)
    80002adc:	04905663          	blez	s1,80002b28 <growproc+0x74>
    if (sz + n > TRAPFRAME)
    80002ae0:	00b48633          	add	a2,s1,a1
    80002ae4:	020007b7          	lui	a5,0x2000
    80002ae8:	fff78793          	addi	a5,a5,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    80002aec:	00d79793          	slli	a5,a5,0xd
    80002af0:	04c7e863          	bltu	a5,a2,80002b40 <growproc+0x8c>
    if ((sz = uvmalloc(p->pagetable, sz, sz + n, PTE_W)) == 0)
    80002af4:	00400693          	li	a3,4
    80002af8:	05053503          	ld	a0,80(a0)
    80002afc:	8d0ff0ef          	jal	80001bcc <uvmalloc>
    80002b00:	00050593          	mv	a1,a0
    80002b04:	04050263          	beqz	a0,80002b48 <growproc+0x94>
  p->sz = sz;
    80002b08:	04b93423          	sd	a1,72(s2)
  return 0;
    80002b0c:	00000513          	li	a0,0
}
    80002b10:	01813083          	ld	ra,24(sp)
    80002b14:	01013403          	ld	s0,16(sp)
    80002b18:	00813483          	ld	s1,8(sp)
    80002b1c:	00013903          	ld	s2,0(sp)
    80002b20:	02010113          	addi	sp,sp,32
    80002b24:	00008067          	ret
  else if (n < 0)
    80002b28:	fe04d0e3          	bgez	s1,80002b08 <growproc+0x54>
    sz = uvmdealloc(p->pagetable, sz, sz + n);
    80002b2c:	00b48633          	add	a2,s1,a1
    80002b30:	05053503          	ld	a0,80(a0)
    80002b34:	824ff0ef          	jal	80001b58 <uvmdealloc>
    80002b38:	00050593          	mv	a1,a0
    80002b3c:	fcdff06f          	j	80002b08 <growproc+0x54>
      return -1;
    80002b40:	fff00513          	li	a0,-1
    80002b44:	fcdff06f          	j	80002b10 <growproc+0x5c>
      return -1;
    80002b48:	fff00513          	li	a0,-1
    80002b4c:	fc5ff06f          	j	80002b10 <growproc+0x5c>

0000000080002b50 <kfork>:
{
    80002b50:	fc010113          	addi	sp,sp,-64
    80002b54:	02113c23          	sd	ra,56(sp)
    80002b58:	02813823          	sd	s0,48(sp)
    80002b5c:	02913423          	sd	s1,40(sp)
    80002b60:	01513423          	sd	s5,8(sp)
    80002b64:	04010413          	addi	s0,sp,64
  struct proc *p = myproc();
    80002b68:	a8dff0ef          	jal	800025f4 <myproc>
    80002b6c:	00050a93          	mv	s5,a0
  if ((np = allocproc()) == 0)
    80002b70:	df1ff0ef          	jal	80002960 <allocproc>
    80002b74:	14050263          	beqz	a0,80002cb8 <kfork+0x168>
    80002b78:	01413823          	sd	s4,16(sp)
    80002b7c:	00050a13          	mv	s4,a0
  if (uvmcopy(p->pagetable, np->pagetable, p->sz) < 0)
    80002b80:	048ab603          	ld	a2,72(s5)
    80002b84:	05053583          	ld	a1,80(a0)
    80002b88:	050ab503          	ld	a0,80(s5)
    80002b8c:	a5cff0ef          	jal	80001de8 <uvmcopy>
    80002b90:	06054463          	bltz	a0,80002bf8 <kfork+0xa8>
    80002b94:	03213023          	sd	s2,32(sp)
    80002b98:	01313c23          	sd	s3,24(sp)
  np->sz = p->sz;
    80002b9c:	048ab783          	ld	a5,72(s5)
    80002ba0:	04fa3423          	sd	a5,72(s4)
  *(np->trapframe) = *(p->trapframe);
    80002ba4:	058ab683          	ld	a3,88(s5)
    80002ba8:	00068793          	mv	a5,a3
    80002bac:	058a3703          	ld	a4,88(s4)
    80002bb0:	12068693          	addi	a3,a3,288
    80002bb4:	0007b503          	ld	a0,0(a5)
    80002bb8:	0087b583          	ld	a1,8(a5)
    80002bbc:	0107b603          	ld	a2,16(a5)
    80002bc0:	00a73023          	sd	a0,0(a4) # 1000 <_binary_fs_img_size-0x1f3000>
    80002bc4:	00b73423          	sd	a1,8(a4)
    80002bc8:	00c73823          	sd	a2,16(a4)
    80002bcc:	0187b603          	ld	a2,24(a5)
    80002bd0:	00c73c23          	sd	a2,24(a4)
    80002bd4:	02078793          	addi	a5,a5,32
    80002bd8:	02070713          	addi	a4,a4,32
    80002bdc:	fcd79ce3          	bne	a5,a3,80002bb4 <kfork+0x64>
  np->trapframe->a0 = 0;
    80002be0:	058a3783          	ld	a5,88(s4)
    80002be4:	0607b823          	sd	zero,112(a5)
  for (i = 0; i < NOFILE; i++)
    80002be8:	0d0a8493          	addi	s1,s5,208
    80002bec:	0d0a0913          	addi	s2,s4,208
    80002bf0:	150a8993          	addi	s3,s5,336
    80002bf4:	02c0006f          	j	80002c20 <kfork+0xd0>
    freeproc(np);
    80002bf8:	000a0513          	mv	a0,s4
    80002bfc:	cf5ff0ef          	jal	800028f0 <freeproc>
    release(&np->lock);
    80002c00:	000a0513          	mv	a0,s4
    80002c04:	d14fe0ef          	jal	80001118 <release>
    return -1;
    80002c08:	fff00493          	li	s1,-1
    80002c0c:	01013a03          	ld	s4,16(sp)
    80002c10:	08c0006f          	j	80002c9c <kfork+0x14c>
  for (i = 0; i < NOFILE; i++)
    80002c14:	00848493          	addi	s1,s1,8
    80002c18:	00890913          	addi	s2,s2,8
    80002c1c:	01348c63          	beq	s1,s3,80002c34 <kfork+0xe4>
    if (p->ofile[i])
    80002c20:	0004b503          	ld	a0,0(s1)
    80002c24:	fe0508e3          	beqz	a0,80002c14 <kfork+0xc4>
      np->ofile[i] = filedup(p->ofile[i]);
    80002c28:	2e8030ef          	jal	80005f10 <filedup>
    80002c2c:	00a93023          	sd	a0,0(s2)
    80002c30:	fe5ff06f          	j	80002c14 <kfork+0xc4>
  np->cwd = idup(p->cwd);
    80002c34:	150ab503          	ld	a0,336(s5)
    80002c38:	5e5010ef          	jal	80004a1c <idup>
    80002c3c:	14aa3823          	sd	a0,336(s4)
  safestrcpy(np->name, p->name, sizeof(p->name));
    80002c40:	01000613          	li	a2,16
    80002c44:	158a8593          	addi	a1,s5,344
    80002c48:	158a0513          	addi	a0,s4,344
    80002c4c:	fa8fe0ef          	jal	800013f4 <safestrcpy>
  pid = np->pid;
    80002c50:	030a2483          	lw	s1,48(s4)
  release(&np->lock);
    80002c54:	000a0513          	mv	a0,s4
    80002c58:	cc0fe0ef          	jal	80001118 <release>
  acquire(&wait_lock);
    80002c5c:	00203517          	auipc	a0,0x203
    80002c60:	03450513          	addi	a0,a0,52 # 80205c90 <wait_lock>
    80002c64:	bdcfe0ef          	jal	80001040 <acquire>
  np->parent = p;
    80002c68:	035a3c23          	sd	s5,56(s4)
  release(&wait_lock);
    80002c6c:	00203517          	auipc	a0,0x203
    80002c70:	02450513          	addi	a0,a0,36 # 80205c90 <wait_lock>
    80002c74:	ca4fe0ef          	jal	80001118 <release>
  acquire(&np->lock);
    80002c78:	000a0513          	mv	a0,s4
    80002c7c:	bc4fe0ef          	jal	80001040 <acquire>
  np->state = RUNNABLE;
    80002c80:	00300793          	li	a5,3
    80002c84:	00fa2c23          	sw	a5,24(s4)
  release(&np->lock);
    80002c88:	000a0513          	mv	a0,s4
    80002c8c:	c8cfe0ef          	jal	80001118 <release>
  return pid;
    80002c90:	02013903          	ld	s2,32(sp)
    80002c94:	01813983          	ld	s3,24(sp)
    80002c98:	01013a03          	ld	s4,16(sp)
}
    80002c9c:	00048513          	mv	a0,s1
    80002ca0:	03813083          	ld	ra,56(sp)
    80002ca4:	03013403          	ld	s0,48(sp)
    80002ca8:	02813483          	ld	s1,40(sp)
    80002cac:	00813a83          	ld	s5,8(sp)
    80002cb0:	04010113          	addi	sp,sp,64
    80002cb4:	00008067          	ret
    return -1;
    80002cb8:	fff00493          	li	s1,-1
    80002cbc:	fe1ff06f          	j	80002c9c <kfork+0x14c>

0000000080002cc0 <scheduler>:
{
    80002cc0:	fb010113          	addi	sp,sp,-80
    80002cc4:	04113423          	sd	ra,72(sp)
    80002cc8:	04813023          	sd	s0,64(sp)
    80002ccc:	02913c23          	sd	s1,56(sp)
    80002cd0:	03213823          	sd	s2,48(sp)
    80002cd4:	03313423          	sd	s3,40(sp)
    80002cd8:	03413023          	sd	s4,32(sp)
    80002cdc:	01513c23          	sd	s5,24(sp)
    80002ce0:	01613823          	sd	s6,16(sp)
    80002ce4:	01713423          	sd	s7,8(sp)
    80002ce8:	01813023          	sd	s8,0(sp)
    80002cec:	05010413          	addi	s0,sp,80
    80002cf0:	00020793          	mv	a5,tp
  int id = r_tp();
    80002cf4:	0007879b          	sext.w	a5,a5
  c->proc = 0;
    80002cf8:	00779b13          	slli	s6,a5,0x7
    80002cfc:	00203717          	auipc	a4,0x203
    80002d00:	f7c70713          	addi	a4,a4,-132 # 80205c78 <pid_lock>
    80002d04:	01670733          	add	a4,a4,s6
    80002d08:	02073823          	sd	zero,48(a4)
        swtch(&c->context, &p->context);
    80002d0c:	00203717          	auipc	a4,0x203
    80002d10:	fa470713          	addi	a4,a4,-92 # 80205cb0 <cpus+0x8>
    80002d14:	00eb0b33          	add	s6,s6,a4
        p->state = RUNNING;
    80002d18:	00400c13          	li	s8,4
        c->proc = p;
    80002d1c:	00779793          	slli	a5,a5,0x7
    80002d20:	00203a17          	auipc	s4,0x203
    80002d24:	f58a0a13          	addi	s4,s4,-168 # 80205c78 <pid_lock>
    80002d28:	00fa0a33          	add	s4,s4,a5
        found = 1;
    80002d2c:	00100b93          	li	s7,1
    80002d30:	04c0006f          	j	80002d7c <scheduler+0xbc>
      release(&p->lock);
    80002d34:	00048513          	mv	a0,s1
    80002d38:	be0fe0ef          	jal	80001118 <release>
    for (p = proc; p < &proc[NPROC]; p++)
    80002d3c:	16848493          	addi	s1,s1,360
    80002d40:	03248a63          	beq	s1,s2,80002d74 <scheduler+0xb4>
      acquire(&p->lock);
    80002d44:	00048513          	mv	a0,s1
    80002d48:	af8fe0ef          	jal	80001040 <acquire>
      if (p->state == RUNNABLE)
    80002d4c:	0184a783          	lw	a5,24(s1)
    80002d50:	ff3792e3          	bne	a5,s3,80002d34 <scheduler+0x74>
        p->state = RUNNING;
    80002d54:	0184ac23          	sw	s8,24(s1)
        c->proc = p;
    80002d58:	029a3823          	sd	s1,48(s4)
        swtch(&c->context, &p->context);
    80002d5c:	06048593          	addi	a1,s1,96
    80002d60:	000b0513          	mv	a0,s6
    80002d64:	071000ef          	jal	800035d4 <swtch>
        c->proc = 0;
    80002d68:	020a3823          	sd	zero,48(s4)
        found = 1;
    80002d6c:	000b8a93          	mv	s5,s7
    80002d70:	fc5ff06f          	j	80002d34 <scheduler+0x74>
    if (found == 0)
    80002d74:	000a9463          	bnez	s5,80002d7c <scheduler+0xbc>
      asm volatile("wfi");
    80002d78:	10500073          	wfi
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80002d7c:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() | SSTATUS_SIE);
    80002d80:	0027e793          	ori	a5,a5,2
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80002d84:	10079073          	csrw	sstatus,a5
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80002d88:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() & ~SSTATUS_SIE);
    80002d8c:	ffd7f793          	andi	a5,a5,-3
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80002d90:	10079073          	csrw	sstatus,a5
    int found = 0;
    80002d94:	00000a93          	li	s5,0
    for (p = proc; p < &proc[NPROC]; p++)
    80002d98:	00203497          	auipc	s1,0x203
    80002d9c:	31048493          	addi	s1,s1,784 # 802060a8 <proc>
      if (p->state == RUNNABLE)
    80002da0:	00300993          	li	s3,3
    for (p = proc; p < &proc[NPROC]; p++)
    80002da4:	00209917          	auipc	s2,0x209
    80002da8:	d0490913          	addi	s2,s2,-764 # 8020baa8 <tickslock>
    80002dac:	f99ff06f          	j	80002d44 <scheduler+0x84>

0000000080002db0 <sched>:
{
    80002db0:	fd010113          	addi	sp,sp,-48
    80002db4:	02113423          	sd	ra,40(sp)
    80002db8:	02813023          	sd	s0,32(sp)
    80002dbc:	00913c23          	sd	s1,24(sp)
    80002dc0:	01213823          	sd	s2,16(sp)
    80002dc4:	01313423          	sd	s3,8(sp)
    80002dc8:	03010413          	addi	s0,sp,48
  struct proc *p = myproc();
    80002dcc:	829ff0ef          	jal	800025f4 <myproc>
    80002dd0:	00050493          	mv	s1,a0
  if (!holding(&p->lock))
    80002dd4:	9b4fe0ef          	jal	80000f88 <holding>
    80002dd8:	0a050863          	beqz	a0,80002e88 <sched+0xd8>
  asm volatile("mv %0, tp" : "=r"(x));
    80002ddc:	00020793          	mv	a5,tp
  if (mycpu()->noff != 1)
    80002de0:	0007879b          	sext.w	a5,a5
    80002de4:	00779793          	slli	a5,a5,0x7
    80002de8:	00203717          	auipc	a4,0x203
    80002dec:	e9070713          	addi	a4,a4,-368 # 80205c78 <pid_lock>
    80002df0:	00f707b3          	add	a5,a4,a5
    80002df4:	0a87a703          	lw	a4,168(a5)
    80002df8:	00100793          	li	a5,1
    80002dfc:	08f71c63          	bne	a4,a5,80002e94 <sched+0xe4>
  if (p->state == RUNNING)
    80002e00:	0184a703          	lw	a4,24(s1)
    80002e04:	00400793          	li	a5,4
    80002e08:	08f70c63          	beq	a4,a5,80002ea0 <sched+0xf0>
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80002e0c:	100027f3          	csrr	a5,sstatus
  return (x & SSTATUS_SIE) != 0;
    80002e10:	0027f793          	andi	a5,a5,2
  if (intr_get())
    80002e14:	08079c63          	bnez	a5,80002eac <sched+0xfc>
  asm volatile("mv %0, tp" : "=r"(x));
    80002e18:	00020793          	mv	a5,tp
  intena = mycpu()->intena;
    80002e1c:	00203917          	auipc	s2,0x203
    80002e20:	e5c90913          	addi	s2,s2,-420 # 80205c78 <pid_lock>
    80002e24:	0007879b          	sext.w	a5,a5
    80002e28:	00779793          	slli	a5,a5,0x7
    80002e2c:	00f907b3          	add	a5,s2,a5
    80002e30:	0ac7a983          	lw	s3,172(a5)
    80002e34:	00020793          	mv	a5,tp
  swtch(&p->context, &mycpu()->context);
    80002e38:	0007879b          	sext.w	a5,a5
    80002e3c:	00779793          	slli	a5,a5,0x7
    80002e40:	00878793          	addi	a5,a5,8
    80002e44:	00203597          	auipc	a1,0x203
    80002e48:	e6458593          	addi	a1,a1,-412 # 80205ca8 <cpus>
    80002e4c:	00f585b3          	add	a1,a1,a5
    80002e50:	06048513          	addi	a0,s1,96
    80002e54:	780000ef          	jal	800035d4 <swtch>
    80002e58:	00020793          	mv	a5,tp
  mycpu()->intena = intena;
    80002e5c:	0007879b          	sext.w	a5,a5
    80002e60:	00779793          	slli	a5,a5,0x7
    80002e64:	00f90933          	add	s2,s2,a5
    80002e68:	0b392623          	sw	s3,172(s2)
}
    80002e6c:	02813083          	ld	ra,40(sp)
    80002e70:	02013403          	ld	s0,32(sp)
    80002e74:	01813483          	ld	s1,24(sp)
    80002e78:	01013903          	ld	s2,16(sp)
    80002e7c:	00813983          	ld	s3,8(sp)
    80002e80:	03010113          	addi	sp,sp,48
    80002e84:	00008067          	ret
    panic("sched p->lock");
    80002e88:	00006517          	auipc	a0,0x6
    80002e8c:	6b850513          	addi	a0,a0,1720 # 80009540 <etext+0x540>
    80002e90:	c5dfd0ef          	jal	80000aec <panic>
    panic("sched locks");
    80002e94:	00006517          	auipc	a0,0x6
    80002e98:	6bc50513          	addi	a0,a0,1724 # 80009550 <etext+0x550>
    80002e9c:	c51fd0ef          	jal	80000aec <panic>
    panic("sched RUNNING");
    80002ea0:	00006517          	auipc	a0,0x6
    80002ea4:	6c050513          	addi	a0,a0,1728 # 80009560 <etext+0x560>
    80002ea8:	c45fd0ef          	jal	80000aec <panic>
    panic("sched interruptible");
    80002eac:	00006517          	auipc	a0,0x6
    80002eb0:	6c450513          	addi	a0,a0,1732 # 80009570 <etext+0x570>
    80002eb4:	c39fd0ef          	jal	80000aec <panic>

0000000080002eb8 <yield>:
{
    80002eb8:	fe010113          	addi	sp,sp,-32
    80002ebc:	00113c23          	sd	ra,24(sp)
    80002ec0:	00813823          	sd	s0,16(sp)
    80002ec4:	00913423          	sd	s1,8(sp)
    80002ec8:	02010413          	addi	s0,sp,32
  struct proc *p = myproc();
    80002ecc:	f28ff0ef          	jal	800025f4 <myproc>
    80002ed0:	00050493          	mv	s1,a0
  acquire(&p->lock);
    80002ed4:	96cfe0ef          	jal	80001040 <acquire>
  p->state = RUNNABLE;
    80002ed8:	00300793          	li	a5,3
    80002edc:	00f4ac23          	sw	a5,24(s1)
  sched();
    80002ee0:	ed1ff0ef          	jal	80002db0 <sched>
  release(&p->lock);
    80002ee4:	00048513          	mv	a0,s1
    80002ee8:	a30fe0ef          	jal	80001118 <release>
}
    80002eec:	01813083          	ld	ra,24(sp)
    80002ef0:	01013403          	ld	s0,16(sp)
    80002ef4:	00813483          	ld	s1,8(sp)
    80002ef8:	02010113          	addi	sp,sp,32
    80002efc:	00008067          	ret

0000000080002f00 <sleep>:

// Sleep on channel chan, releasing condition lock lk.
// Re-acquires lk when awakened.
void sleep(void *chan, struct spinlock *lk)
{
    80002f00:	fd010113          	addi	sp,sp,-48
    80002f04:	02113423          	sd	ra,40(sp)
    80002f08:	02813023          	sd	s0,32(sp)
    80002f0c:	00913c23          	sd	s1,24(sp)
    80002f10:	01213823          	sd	s2,16(sp)
    80002f14:	01313423          	sd	s3,8(sp)
    80002f18:	03010413          	addi	s0,sp,48
    80002f1c:	00050993          	mv	s3,a0
    80002f20:	00058913          	mv	s2,a1
  struct proc *p = myproc();
    80002f24:	ed0ff0ef          	jal	800025f4 <myproc>
    80002f28:	00050493          	mv	s1,a0
  // Once we hold p->lock, we can be
  // guaranteed that we won't miss any wakeup
  // (wakeup locks p->lock),
  // so it's okay to release lk.

  acquire(&p->lock); // DOC: sleeplock1
    80002f2c:	914fe0ef          	jal	80001040 <acquire>
  release(lk);
    80002f30:	00090513          	mv	a0,s2
    80002f34:	9e4fe0ef          	jal	80001118 <release>

  // Go to sleep.
  p->chan = chan;
    80002f38:	0334b023          	sd	s3,32(s1)
  p->state = SLEEPING;
    80002f3c:	00200793          	li	a5,2
    80002f40:	00f4ac23          	sw	a5,24(s1)

  sched();
    80002f44:	e6dff0ef          	jal	80002db0 <sched>

  // Tidy up.
  p->chan = 0;
    80002f48:	0204b023          	sd	zero,32(s1)

  // Reacquire original lock.
  release(&p->lock);
    80002f4c:	00048513          	mv	a0,s1
    80002f50:	9c8fe0ef          	jal	80001118 <release>
  acquire(lk);
    80002f54:	00090513          	mv	a0,s2
    80002f58:	8e8fe0ef          	jal	80001040 <acquire>
}
    80002f5c:	02813083          	ld	ra,40(sp)
    80002f60:	02013403          	ld	s0,32(sp)
    80002f64:	01813483          	ld	s1,24(sp)
    80002f68:	01013903          	ld	s2,16(sp)
    80002f6c:	00813983          	ld	s3,8(sp)
    80002f70:	03010113          	addi	sp,sp,48
    80002f74:	00008067          	ret

0000000080002f78 <wakeup>:

// Wake up all processes sleeping on channel chan.
// Caller should hold the condition lock.
void wakeup(void *chan)
{
    80002f78:	fc010113          	addi	sp,sp,-64
    80002f7c:	02113c23          	sd	ra,56(sp)
    80002f80:	02813823          	sd	s0,48(sp)
    80002f84:	02913423          	sd	s1,40(sp)
    80002f88:	03213023          	sd	s2,32(sp)
    80002f8c:	01313c23          	sd	s3,24(sp)
    80002f90:	01413823          	sd	s4,16(sp)
    80002f94:	01513423          	sd	s5,8(sp)
    80002f98:	04010413          	addi	s0,sp,64
    80002f9c:	00050a13          	mv	s4,a0
  struct proc *p;

  for (p = proc; p < &proc[NPROC]; p++)
    80002fa0:	00203497          	auipc	s1,0x203
    80002fa4:	10848493          	addi	s1,s1,264 # 802060a8 <proc>
  {
    if (p != myproc())
    {
      acquire(&p->lock);
      if (p->state == SLEEPING && p->chan == chan)
    80002fa8:	00200993          	li	s3,2
      {
        p->state = RUNNABLE;
    80002fac:	00300a93          	li	s5,3
  for (p = proc; p < &proc[NPROC]; p++)
    80002fb0:	00209917          	auipc	s2,0x209
    80002fb4:	af890913          	addi	s2,s2,-1288 # 8020baa8 <tickslock>
    80002fb8:	0140006f          	j	80002fcc <wakeup+0x54>
      }
      release(&p->lock);
    80002fbc:	00048513          	mv	a0,s1
    80002fc0:	958fe0ef          	jal	80001118 <release>
  for (p = proc; p < &proc[NPROC]; p++)
    80002fc4:	16848493          	addi	s1,s1,360
    80002fc8:	03248663          	beq	s1,s2,80002ff4 <wakeup+0x7c>
    if (p != myproc())
    80002fcc:	e28ff0ef          	jal	800025f4 <myproc>
    80002fd0:	fe950ae3          	beq	a0,s1,80002fc4 <wakeup+0x4c>
      acquire(&p->lock);
    80002fd4:	00048513          	mv	a0,s1
    80002fd8:	868fe0ef          	jal	80001040 <acquire>
      if (p->state == SLEEPING && p->chan == chan)
    80002fdc:	0184a783          	lw	a5,24(s1)
    80002fe0:	fd379ee3          	bne	a5,s3,80002fbc <wakeup+0x44>
    80002fe4:	0204b783          	ld	a5,32(s1)
    80002fe8:	fd479ae3          	bne	a5,s4,80002fbc <wakeup+0x44>
        p->state = RUNNABLE;
    80002fec:	0154ac23          	sw	s5,24(s1)
    80002ff0:	fcdff06f          	j	80002fbc <wakeup+0x44>
    }
  }
}
    80002ff4:	03813083          	ld	ra,56(sp)
    80002ff8:	03013403          	ld	s0,48(sp)
    80002ffc:	02813483          	ld	s1,40(sp)
    80003000:	02013903          	ld	s2,32(sp)
    80003004:	01813983          	ld	s3,24(sp)
    80003008:	01013a03          	ld	s4,16(sp)
    8000300c:	00813a83          	ld	s5,8(sp)
    80003010:	04010113          	addi	sp,sp,64
    80003014:	00008067          	ret

0000000080003018 <reparent>:
{
    80003018:	fd010113          	addi	sp,sp,-48
    8000301c:	02113423          	sd	ra,40(sp)
    80003020:	02813023          	sd	s0,32(sp)
    80003024:	00913c23          	sd	s1,24(sp)
    80003028:	01213823          	sd	s2,16(sp)
    8000302c:	01313423          	sd	s3,8(sp)
    80003030:	01413023          	sd	s4,0(sp)
    80003034:	03010413          	addi	s0,sp,48
    80003038:	00050913          	mv	s2,a0
  for (pp = proc; pp < &proc[NPROC]; pp++)
    8000303c:	00203497          	auipc	s1,0x203
    80003040:	06c48493          	addi	s1,s1,108 # 802060a8 <proc>
      pp->parent = initproc;
    80003044:	001fba17          	auipc	s4,0x1fb
    80003048:	b24a0a13          	addi	s4,s4,-1244 # 801fdb68 <initproc>
  for (pp = proc; pp < &proc[NPROC]; pp++)
    8000304c:	00209997          	auipc	s3,0x209
    80003050:	a5c98993          	addi	s3,s3,-1444 # 8020baa8 <tickslock>
    80003054:	00c0006f          	j	80003060 <reparent+0x48>
    80003058:	16848493          	addi	s1,s1,360
    8000305c:	01348e63          	beq	s1,s3,80003078 <reparent+0x60>
    if (pp->parent == p)
    80003060:	0384b783          	ld	a5,56(s1)
    80003064:	ff279ae3          	bne	a5,s2,80003058 <reparent+0x40>
      pp->parent = initproc;
    80003068:	000a3503          	ld	a0,0(s4)
    8000306c:	02a4bc23          	sd	a0,56(s1)
      wakeup(initproc);
    80003070:	f09ff0ef          	jal	80002f78 <wakeup>
    80003074:	fe5ff06f          	j	80003058 <reparent+0x40>
}
    80003078:	02813083          	ld	ra,40(sp)
    8000307c:	02013403          	ld	s0,32(sp)
    80003080:	01813483          	ld	s1,24(sp)
    80003084:	01013903          	ld	s2,16(sp)
    80003088:	00813983          	ld	s3,8(sp)
    8000308c:	00013a03          	ld	s4,0(sp)
    80003090:	03010113          	addi	sp,sp,48
    80003094:	00008067          	ret

0000000080003098 <kexit>:
{
    80003098:	fd010113          	addi	sp,sp,-48
    8000309c:	02113423          	sd	ra,40(sp)
    800030a0:	02813023          	sd	s0,32(sp)
    800030a4:	00913c23          	sd	s1,24(sp)
    800030a8:	01213823          	sd	s2,16(sp)
    800030ac:	01313423          	sd	s3,8(sp)
    800030b0:	01413023          	sd	s4,0(sp)
    800030b4:	03010413          	addi	s0,sp,48
    800030b8:	00050a13          	mv	s4,a0
  struct proc *p = myproc();
    800030bc:	d38ff0ef          	jal	800025f4 <myproc>
    800030c0:	00050993          	mv	s3,a0
  if (p == initproc)
    800030c4:	001fb797          	auipc	a5,0x1fb
    800030c8:	aa47b783          	ld	a5,-1372(a5) # 801fdb68 <initproc>
    800030cc:	0d050493          	addi	s1,a0,208
    800030d0:	15050913          	addi	s2,a0,336
    800030d4:	00a79c63          	bne	a5,a0,800030ec <kexit+0x54>
    panic("init exiting");
    800030d8:	00006517          	auipc	a0,0x6
    800030dc:	4b050513          	addi	a0,a0,1200 # 80009588 <etext+0x588>
    800030e0:	a0dfd0ef          	jal	80000aec <panic>
  for (int fd = 0; fd < NOFILE; fd++)
    800030e4:	00848493          	addi	s1,s1,8
    800030e8:	01248c63          	beq	s1,s2,80003100 <kexit+0x68>
    if (p->ofile[fd])
    800030ec:	0004b503          	ld	a0,0(s1)
    800030f0:	fe050ae3          	beqz	a0,800030e4 <kexit+0x4c>
      fileclose(f);
    800030f4:	681020ef          	jal	80005f74 <fileclose>
      p->ofile[fd] = 0;
    800030f8:	0004b023          	sd	zero,0(s1)
    800030fc:	fe9ff06f          	j	800030e4 <kexit+0x4c>
  begin_op();
    80003100:	099020ef          	jal	80005998 <begin_op>
  iput(p->cwd);
    80003104:	1509b503          	ld	a0,336(s3)
    80003108:	395010ef          	jal	80004c9c <iput>
  end_op();
    8000310c:	131020ef          	jal	80005a3c <end_op>
  p->cwd = 0;
    80003110:	1409b823          	sd	zero,336(s3)
  acquire(&wait_lock);
    80003114:	00203517          	auipc	a0,0x203
    80003118:	b7c50513          	addi	a0,a0,-1156 # 80205c90 <wait_lock>
    8000311c:	f25fd0ef          	jal	80001040 <acquire>
  reparent(p);
    80003120:	00098513          	mv	a0,s3
    80003124:	ef5ff0ef          	jal	80003018 <reparent>
  wakeup(p->parent);
    80003128:	0389b503          	ld	a0,56(s3)
    8000312c:	e4dff0ef          	jal	80002f78 <wakeup>
  acquire(&p->lock);
    80003130:	00098513          	mv	a0,s3
    80003134:	f0dfd0ef          	jal	80001040 <acquire>
  p->xstate = status;
    80003138:	0349a623          	sw	s4,44(s3)
  p->state = ZOMBIE;
    8000313c:	00500793          	li	a5,5
    80003140:	00f9ac23          	sw	a5,24(s3)
  release(&wait_lock);
    80003144:	00203517          	auipc	a0,0x203
    80003148:	b4c50513          	addi	a0,a0,-1204 # 80205c90 <wait_lock>
    8000314c:	fcdfd0ef          	jal	80001118 <release>
  sched();
    80003150:	c61ff0ef          	jal	80002db0 <sched>
  panic("zombie exit");
    80003154:	00006517          	auipc	a0,0x6
    80003158:	44450513          	addi	a0,a0,1092 # 80009598 <etext+0x598>
    8000315c:	991fd0ef          	jal	80000aec <panic>

0000000080003160 <kkill>:

// Kill the process with the given pid.
// The victim won't exit until it tries to return
// to user space (see usertrap() in trap.c).
int kkill(int pid)
{
    80003160:	fd010113          	addi	sp,sp,-48
    80003164:	02113423          	sd	ra,40(sp)
    80003168:	02813023          	sd	s0,32(sp)
    8000316c:	00913c23          	sd	s1,24(sp)
    80003170:	01213823          	sd	s2,16(sp)
    80003174:	01313423          	sd	s3,8(sp)
    80003178:	03010413          	addi	s0,sp,48
    8000317c:	00050913          	mv	s2,a0
  struct proc *p;

  for (p = proc; p < &proc[NPROC]; p++)
    80003180:	00203497          	auipc	s1,0x203
    80003184:	f2848493          	addi	s1,s1,-216 # 802060a8 <proc>
    80003188:	00209997          	auipc	s3,0x209
    8000318c:	92098993          	addi	s3,s3,-1760 # 8020baa8 <tickslock>
  {
    acquire(&p->lock);
    80003190:	00048513          	mv	a0,s1
    80003194:	eadfd0ef          	jal	80001040 <acquire>
    if (p->pid == pid)
    80003198:	0304a783          	lw	a5,48(s1)
    8000319c:	01278e63          	beq	a5,s2,800031b8 <kkill+0x58>
        p->state = RUNNABLE;
      }
      release(&p->lock);
      return 0;
    }
    release(&p->lock);
    800031a0:	00048513          	mv	a0,s1
    800031a4:	f75fd0ef          	jal	80001118 <release>
  for (p = proc; p < &proc[NPROC]; p++)
    800031a8:	16848493          	addi	s1,s1,360
    800031ac:	ff3492e3          	bne	s1,s3,80003190 <kkill+0x30>
  }
  return -1;
    800031b0:	fff00513          	li	a0,-1
    800031b4:	0240006f          	j	800031d8 <kkill+0x78>
      p->killed = 1;
    800031b8:	00100793          	li	a5,1
    800031bc:	02f4a423          	sw	a5,40(s1)
      if (p->state == SLEEPING)
    800031c0:	0184a703          	lw	a4,24(s1)
    800031c4:	00200793          	li	a5,2
    800031c8:	02f70663          	beq	a4,a5,800031f4 <kkill+0x94>
      release(&p->lock);
    800031cc:	00048513          	mv	a0,s1
    800031d0:	f49fd0ef          	jal	80001118 <release>
      return 0;
    800031d4:	00000513          	li	a0,0
}
    800031d8:	02813083          	ld	ra,40(sp)
    800031dc:	02013403          	ld	s0,32(sp)
    800031e0:	01813483          	ld	s1,24(sp)
    800031e4:	01013903          	ld	s2,16(sp)
    800031e8:	00813983          	ld	s3,8(sp)
    800031ec:	03010113          	addi	sp,sp,48
    800031f0:	00008067          	ret
        p->state = RUNNABLE;
    800031f4:	00300793          	li	a5,3
    800031f8:	00f4ac23          	sw	a5,24(s1)
    800031fc:	fd1ff06f          	j	800031cc <kkill+0x6c>

0000000080003200 <setkilled>:

void setkilled(struct proc *p)
{
    80003200:	fe010113          	addi	sp,sp,-32
    80003204:	00113c23          	sd	ra,24(sp)
    80003208:	00813823          	sd	s0,16(sp)
    8000320c:	00913423          	sd	s1,8(sp)
    80003210:	02010413          	addi	s0,sp,32
    80003214:	00050493          	mv	s1,a0
  acquire(&p->lock);
    80003218:	e29fd0ef          	jal	80001040 <acquire>
  p->killed = 1;
    8000321c:	00100793          	li	a5,1
    80003220:	02f4a423          	sw	a5,40(s1)
  release(&p->lock);
    80003224:	00048513          	mv	a0,s1
    80003228:	ef1fd0ef          	jal	80001118 <release>
}
    8000322c:	01813083          	ld	ra,24(sp)
    80003230:	01013403          	ld	s0,16(sp)
    80003234:	00813483          	ld	s1,8(sp)
    80003238:	02010113          	addi	sp,sp,32
    8000323c:	00008067          	ret

0000000080003240 <killed>:

int killed(struct proc *p)
{
    80003240:	fe010113          	addi	sp,sp,-32
    80003244:	00113c23          	sd	ra,24(sp)
    80003248:	00813823          	sd	s0,16(sp)
    8000324c:	00913423          	sd	s1,8(sp)
    80003250:	01213023          	sd	s2,0(sp)
    80003254:	02010413          	addi	s0,sp,32
    80003258:	00050493          	mv	s1,a0
  int k;

  acquire(&p->lock);
    8000325c:	de5fd0ef          	jal	80001040 <acquire>
  k = p->killed;
    80003260:	0284a783          	lw	a5,40(s1)
    80003264:	00078913          	mv	s2,a5
  release(&p->lock);
    80003268:	00048513          	mv	a0,s1
    8000326c:	eadfd0ef          	jal	80001118 <release>
  return k;
}
    80003270:	00090513          	mv	a0,s2
    80003274:	01813083          	ld	ra,24(sp)
    80003278:	01013403          	ld	s0,16(sp)
    8000327c:	00813483          	ld	s1,8(sp)
    80003280:	00013903          	ld	s2,0(sp)
    80003284:	02010113          	addi	sp,sp,32
    80003288:	00008067          	ret

000000008000328c <kwait>:
{
    8000328c:	fb010113          	addi	sp,sp,-80
    80003290:	04113423          	sd	ra,72(sp)
    80003294:	04813023          	sd	s0,64(sp)
    80003298:	02913c23          	sd	s1,56(sp)
    8000329c:	03213823          	sd	s2,48(sp)
    800032a0:	03313423          	sd	s3,40(sp)
    800032a4:	03413023          	sd	s4,32(sp)
    800032a8:	01513c23          	sd	s5,24(sp)
    800032ac:	01613823          	sd	s6,16(sp)
    800032b0:	01713423          	sd	s7,8(sp)
    800032b4:	05010413          	addi	s0,sp,80
    800032b8:	00050b93          	mv	s7,a0
  struct proc *p = myproc();
    800032bc:	b38ff0ef          	jal	800025f4 <myproc>
    800032c0:	00050913          	mv	s2,a0
  acquire(&wait_lock);
    800032c4:	00203517          	auipc	a0,0x203
    800032c8:	9cc50513          	addi	a0,a0,-1588 # 80205c90 <wait_lock>
    800032cc:	d75fd0ef          	jal	80001040 <acquire>
        if (pp->state == ZOMBIE)
    800032d0:	00500a13          	li	s4,5
        havekids = 1;
    800032d4:	00100a93          	li	s5,1
    for (pp = proc; pp < &proc[NPROC]; pp++)
    800032d8:	00208997          	auipc	s3,0x208
    800032dc:	7d098993          	addi	s3,s3,2000 # 8020baa8 <tickslock>
    sleep(p, &wait_lock); // DOC: wait-sleep
    800032e0:	00203b17          	auipc	s6,0x203
    800032e4:	9b0b0b13          	addi	s6,s6,-1616 # 80205c90 <wait_lock>
    800032e8:	0d80006f          	j	800033c0 <kwait+0x134>
          pid = pp->pid;
    800032ec:	0304a983          	lw	s3,48(s1)
          if (addr != 0 && copyout(p->pagetable, addr, (char *)&pp->xstate,
    800032f0:	000b8e63          	beqz	s7,8000330c <kwait+0x80>
    800032f4:	00400693          	li	a3,4
    800032f8:	02c48613          	addi	a2,s1,44
    800032fc:	000b8593          	mv	a1,s7
    80003300:	05093503          	ld	a0,80(s2)
    80003304:	e6dfe0ef          	jal	80002170 <copyout>
    80003308:	04054863          	bltz	a0,80003358 <kwait+0xcc>
          freeproc(pp);
    8000330c:	00048513          	mv	a0,s1
    80003310:	de0ff0ef          	jal	800028f0 <freeproc>
          release(&pp->lock);
    80003314:	00048513          	mv	a0,s1
    80003318:	e01fd0ef          	jal	80001118 <release>
          release(&wait_lock);
    8000331c:	00203517          	auipc	a0,0x203
    80003320:	97450513          	addi	a0,a0,-1676 # 80205c90 <wait_lock>
    80003324:	df5fd0ef          	jal	80001118 <release>
}
    80003328:	00098513          	mv	a0,s3
    8000332c:	04813083          	ld	ra,72(sp)
    80003330:	04013403          	ld	s0,64(sp)
    80003334:	03813483          	ld	s1,56(sp)
    80003338:	03013903          	ld	s2,48(sp)
    8000333c:	02813983          	ld	s3,40(sp)
    80003340:	02013a03          	ld	s4,32(sp)
    80003344:	01813a83          	ld	s5,24(sp)
    80003348:	01013b03          	ld	s6,16(sp)
    8000334c:	00813b83          	ld	s7,8(sp)
    80003350:	05010113          	addi	sp,sp,80
    80003354:	00008067          	ret
            release(&pp->lock);
    80003358:	00048513          	mv	a0,s1
    8000335c:	dbdfd0ef          	jal	80001118 <release>
            release(&wait_lock);
    80003360:	00203517          	auipc	a0,0x203
    80003364:	93050513          	addi	a0,a0,-1744 # 80205c90 <wait_lock>
    80003368:	db1fd0ef          	jal	80001118 <release>
            return -1;
    8000336c:	fff00993          	li	s3,-1
    80003370:	fb9ff06f          	j	80003328 <kwait+0x9c>
    for (pp = proc; pp < &proc[NPROC]; pp++)
    80003374:	16848493          	addi	s1,s1,360
    80003378:	03348663          	beq	s1,s3,800033a4 <kwait+0x118>
      if (pp->parent == p)
    8000337c:	0384b783          	ld	a5,56(s1)
    80003380:	ff279ae3          	bne	a5,s2,80003374 <kwait+0xe8>
        acquire(&pp->lock);
    80003384:	00048513          	mv	a0,s1
    80003388:	cb9fd0ef          	jal	80001040 <acquire>
        if (pp->state == ZOMBIE)
    8000338c:	0184a783          	lw	a5,24(s1)
    80003390:	f5478ee3          	beq	a5,s4,800032ec <kwait+0x60>
        release(&pp->lock);
    80003394:	00048513          	mv	a0,s1
    80003398:	d81fd0ef          	jal	80001118 <release>
        havekids = 1;
    8000339c:	000a8713          	mv	a4,s5
    800033a0:	fd5ff06f          	j	80003374 <kwait+0xe8>
    if (!havekids || killed(p))
    800033a4:	02070663          	beqz	a4,800033d0 <kwait+0x144>
    800033a8:	00090513          	mv	a0,s2
    800033ac:	e95ff0ef          	jal	80003240 <killed>
    800033b0:	02051063          	bnez	a0,800033d0 <kwait+0x144>
    sleep(p, &wait_lock); // DOC: wait-sleep
    800033b4:	000b0593          	mv	a1,s6
    800033b8:	00090513          	mv	a0,s2
    800033bc:	b45ff0ef          	jal	80002f00 <sleep>
    havekids = 0;
    800033c0:	00000713          	li	a4,0
    for (pp = proc; pp < &proc[NPROC]; pp++)
    800033c4:	00203497          	auipc	s1,0x203
    800033c8:	ce448493          	addi	s1,s1,-796 # 802060a8 <proc>
    800033cc:	fb1ff06f          	j	8000337c <kwait+0xf0>
      release(&wait_lock);
    800033d0:	00203517          	auipc	a0,0x203
    800033d4:	8c050513          	addi	a0,a0,-1856 # 80205c90 <wait_lock>
    800033d8:	d41fd0ef          	jal	80001118 <release>
      return -1;
    800033dc:	fff00993          	li	s3,-1
    800033e0:	f49ff06f          	j	80003328 <kwait+0x9c>

00000000800033e4 <either_copyout>:

// Copy to either a user address, or kernel address,
// depending on usr_dst.
// Returns 0 on success, -1 on error.
int either_copyout(int user_dst, uint64 dst, void *src, uint64 len)
{
    800033e4:	fd010113          	addi	sp,sp,-48
    800033e8:	02113423          	sd	ra,40(sp)
    800033ec:	02813023          	sd	s0,32(sp)
    800033f0:	00913c23          	sd	s1,24(sp)
    800033f4:	01213823          	sd	s2,16(sp)
    800033f8:	01313423          	sd	s3,8(sp)
    800033fc:	01413023          	sd	s4,0(sp)
    80003400:	03010413          	addi	s0,sp,48
    80003404:	00050493          	mv	s1,a0
    80003408:	00058a13          	mv	s4,a1
    8000340c:	00060993          	mv	s3,a2
    80003410:	00068913          	mv	s2,a3
  struct proc *p = myproc();
    80003414:	9e0ff0ef          	jal	800025f4 <myproc>
  if (user_dst)
    80003418:	02048c63          	beqz	s1,80003450 <either_copyout+0x6c>
  {
    return copyout(p->pagetable, dst, src, len);
    8000341c:	00090693          	mv	a3,s2
    80003420:	00098613          	mv	a2,s3
    80003424:	000a0593          	mv	a1,s4
    80003428:	05053503          	ld	a0,80(a0)
    8000342c:	d45fe0ef          	jal	80002170 <copyout>
  else
  {
    memmove((char *)dst, src, len);
    return 0;
  }
}
    80003430:	02813083          	ld	ra,40(sp)
    80003434:	02013403          	ld	s0,32(sp)
    80003438:	01813483          	ld	s1,24(sp)
    8000343c:	01013903          	ld	s2,16(sp)
    80003440:	00813983          	ld	s3,8(sp)
    80003444:	00013a03          	ld	s4,0(sp)
    80003448:	03010113          	addi	sp,sp,48
    8000344c:	00008067          	ret
    memmove((char *)dst, src, len);
    80003450:	0009061b          	sext.w	a2,s2
    80003454:	00098593          	mv	a1,s3
    80003458:	000a0513          	mv	a0,s4
    8000345c:	e1dfd0ef          	jal	80001278 <memmove>
    return 0;
    80003460:	00048513          	mv	a0,s1
    80003464:	fcdff06f          	j	80003430 <either_copyout+0x4c>

0000000080003468 <either_copyin>:

// Copy from either a user address, or kernel address,
// depending on usr_src.
// Returns 0 on success, -1 on error.
int either_copyin(void *dst, int user_src, uint64 src, uint64 len)
{
    80003468:	fd010113          	addi	sp,sp,-48
    8000346c:	02113423          	sd	ra,40(sp)
    80003470:	02813023          	sd	s0,32(sp)
    80003474:	00913c23          	sd	s1,24(sp)
    80003478:	01213823          	sd	s2,16(sp)
    8000347c:	01313423          	sd	s3,8(sp)
    80003480:	01413023          	sd	s4,0(sp)
    80003484:	03010413          	addi	s0,sp,48
    80003488:	00050a13          	mv	s4,a0
    8000348c:	00058493          	mv	s1,a1
    80003490:	00060993          	mv	s3,a2
    80003494:	00068913          	mv	s2,a3
  struct proc *p = myproc();
    80003498:	95cff0ef          	jal	800025f4 <myproc>
  if (user_src)
    8000349c:	02048c63          	beqz	s1,800034d4 <either_copyin+0x6c>
  {
    return copyin(p->pagetable, dst, src, len);
    800034a0:	00090693          	mv	a3,s2
    800034a4:	00098613          	mv	a2,s3
    800034a8:	000a0593          	mv	a1,s4
    800034ac:	05053503          	ld	a0,80(a0)
    800034b0:	e05fe0ef          	jal	800022b4 <copyin>
  else
  {
    memmove(dst, (char *)src, len);
    return 0;
  }
}
    800034b4:	02813083          	ld	ra,40(sp)
    800034b8:	02013403          	ld	s0,32(sp)
    800034bc:	01813483          	ld	s1,24(sp)
    800034c0:	01013903          	ld	s2,16(sp)
    800034c4:	00813983          	ld	s3,8(sp)
    800034c8:	00013a03          	ld	s4,0(sp)
    800034cc:	03010113          	addi	sp,sp,48
    800034d0:	00008067          	ret
    memmove(dst, (char *)src, len);
    800034d4:	0009061b          	sext.w	a2,s2
    800034d8:	00098593          	mv	a1,s3
    800034dc:	000a0513          	mv	a0,s4
    800034e0:	d99fd0ef          	jal	80001278 <memmove>
    return 0;
    800034e4:	00048513          	mv	a0,s1
    800034e8:	fcdff06f          	j	800034b4 <either_copyin+0x4c>

00000000800034ec <procdump>:

// Print a process listing to console.  For debugging.
// Runs when user types ^P on console.
// No lock to avoid wedging a stuck machine further.
void procdump(void)
{
    800034ec:	fb010113          	addi	sp,sp,-80
    800034f0:	04113423          	sd	ra,72(sp)
    800034f4:	04813023          	sd	s0,64(sp)
    800034f8:	02913c23          	sd	s1,56(sp)
    800034fc:	03213823          	sd	s2,48(sp)
    80003500:	03313423          	sd	s3,40(sp)
    80003504:	03413023          	sd	s4,32(sp)
    80003508:	01513c23          	sd	s5,24(sp)
    8000350c:	01613823          	sd	s6,16(sp)
    80003510:	01713423          	sd	s7,8(sp)
    80003514:	05010413          	addi	s0,sp,80
      [RUNNING] "run   ",
      [ZOMBIE] "zombie"};
  struct proc *p;
  char *state;

  printf("\n");
    80003518:	00006517          	auipc	a0,0x6
    8000351c:	bb050513          	addi	a0,a0,-1104 # 800090c8 <etext+0xc8>
    80003520:	9acfd0ef          	jal	800006cc <printf>
  for (p = proc; p < &proc[NPROC]; p++)
    80003524:	00203497          	auipc	s1,0x203
    80003528:	cdc48493          	addi	s1,s1,-804 # 80206200 <proc+0x158>
    8000352c:	00208917          	auipc	s2,0x208
    80003530:	6d490913          	addi	s2,s2,1748 # 8020bc00 <bcache+0x140>
  {
    if (p->state == UNUSED)
      continue;
    if (p->state >= 0 && p->state < NELEM(states) && states[p->state])
    80003534:	00500b13          	li	s6,5
      state = states[p->state];
    else
      state = "???";
    80003538:	00006997          	auipc	s3,0x6
    8000353c:	07098993          	addi	s3,s3,112 # 800095a8 <etext+0x5a8>
    printf("%d %s %s", p->pid, state, p->name);
    80003540:	00006a97          	auipc	s5,0x6
    80003544:	070a8a93          	addi	s5,s5,112 # 800095b0 <etext+0x5b0>
    printf("\n");
    80003548:	00006a17          	auipc	s4,0x6
    8000354c:	b80a0a13          	addi	s4,s4,-1152 # 800090c8 <etext+0xc8>
    if (p->state >= 0 && p->state < NELEM(states) && states[p->state])
    80003550:	00006b97          	auipc	s7,0x6
    80003554:	4f8b8b93          	addi	s7,s7,1272 # 80009a48 <states.0>
    80003558:	0200006f          	j	80003578 <procdump+0x8c>
    printf("%d %s %s", p->pid, state, p->name);
    8000355c:	ed86a583          	lw	a1,-296(a3)
    80003560:	000a8513          	mv	a0,s5
    80003564:	968fd0ef          	jal	800006cc <printf>
    printf("\n");
    80003568:	000a0513          	mv	a0,s4
    8000356c:	960fd0ef          	jal	800006cc <printf>
  for (p = proc; p < &proc[NPROC]; p++)
    80003570:	16848493          	addi	s1,s1,360
    80003574:	03248a63          	beq	s1,s2,800035a8 <procdump+0xbc>
    if (p->state == UNUSED)
    80003578:	00048693          	mv	a3,s1
    8000357c:	ec04a783          	lw	a5,-320(s1)
    80003580:	fe0788e3          	beqz	a5,80003570 <procdump+0x84>
      state = "???";
    80003584:	00098613          	mv	a2,s3
    if (p->state >= 0 && p->state < NELEM(states) && states[p->state])
    80003588:	fcfb6ae3          	bltu	s6,a5,8000355c <procdump+0x70>
    8000358c:	02079713          	slli	a4,a5,0x20
    80003590:	01d75793          	srli	a5,a4,0x1d
    80003594:	00fb87b3          	add	a5,s7,a5
    80003598:	0007b603          	ld	a2,0(a5)
    8000359c:	fc0610e3          	bnez	a2,8000355c <procdump+0x70>
      state = "???";
    800035a0:	00098613          	mv	a2,s3
    800035a4:	fb9ff06f          	j	8000355c <procdump+0x70>
  }
}
    800035a8:	04813083          	ld	ra,72(sp)
    800035ac:	04013403          	ld	s0,64(sp)
    800035b0:	03813483          	ld	s1,56(sp)
    800035b4:	03013903          	ld	s2,48(sp)
    800035b8:	02813983          	ld	s3,40(sp)
    800035bc:	02013a03          	ld	s4,32(sp)
    800035c0:	01813a83          	ld	s5,24(sp)
    800035c4:	01013b03          	ld	s6,16(sp)
    800035c8:	00813b83          	ld	s7,8(sp)
    800035cc:	05010113          	addi	sp,sp,80
    800035d0:	00008067          	ret

00000000800035d4 <swtch>:
# Save current registers in old. Load from new.	


.globl swtch
swtch:
        sd ra, 0(a0)
    800035d4:	00153023          	sd	ra,0(a0)
        sd sp, 8(a0)
    800035d8:	00253423          	sd	sp,8(a0)
        sd s0, 16(a0)
    800035dc:	00853823          	sd	s0,16(a0)
        sd s1, 24(a0)
    800035e0:	00953c23          	sd	s1,24(a0)
        sd s2, 32(a0)
    800035e4:	03253023          	sd	s2,32(a0)
        sd s3, 40(a0)
    800035e8:	03353423          	sd	s3,40(a0)
        sd s4, 48(a0)
    800035ec:	03453823          	sd	s4,48(a0)
        sd s5, 56(a0)
    800035f0:	03553c23          	sd	s5,56(a0)
        sd s6, 64(a0)
    800035f4:	05653023          	sd	s6,64(a0)
        sd s7, 72(a0)
    800035f8:	05753423          	sd	s7,72(a0)
        sd s8, 80(a0)
    800035fc:	05853823          	sd	s8,80(a0)
        sd s9, 88(a0)
    80003600:	05953c23          	sd	s9,88(a0)
        sd s10, 96(a0)
    80003604:	07a53023          	sd	s10,96(a0)
        sd s11, 104(a0)
    80003608:	07b53423          	sd	s11,104(a0)

        ld ra, 0(a1)
    8000360c:	0005b083          	ld	ra,0(a1)
        ld sp, 8(a1)
    80003610:	0085b103          	ld	sp,8(a1)
        ld s0, 16(a1)
    80003614:	0105b403          	ld	s0,16(a1)
        ld s1, 24(a1)
    80003618:	0185b483          	ld	s1,24(a1)
        ld s2, 32(a1)
    8000361c:	0205b903          	ld	s2,32(a1)
        ld s3, 40(a1)
    80003620:	0285b983          	ld	s3,40(a1)
        ld s4, 48(a1)
    80003624:	0305ba03          	ld	s4,48(a1)
        ld s5, 56(a1)
    80003628:	0385ba83          	ld	s5,56(a1)
        ld s6, 64(a1)
    8000362c:	0405bb03          	ld	s6,64(a1)
        ld s7, 72(a1)
    80003630:	0485bb83          	ld	s7,72(a1)
        ld s8, 80(a1)
    80003634:	0505bc03          	ld	s8,80(a1)
        ld s9, 88(a1)
    80003638:	0585bc83          	ld	s9,88(a1)
        ld s10, 96(a1)
    8000363c:	0605bd03          	ld	s10,96(a1)
        ld s11, 104(a1)
    80003640:	0685bd83          	ld	s11,104(a1)
        
        ret
    80003644:	00008067          	ret

0000000080003648 <trapinit>:

extern int devintr();

void
trapinit(void)
{
    80003648:	ff010113          	addi	sp,sp,-16
    8000364c:	00113423          	sd	ra,8(sp)
    80003650:	00813023          	sd	s0,0(sp)
    80003654:	01010413          	addi	s0,sp,16
  initlock(&tickslock, "time");
    80003658:	00006597          	auipc	a1,0x6
    8000365c:	f9858593          	addi	a1,a1,-104 # 800095f0 <etext+0x5f0>
    80003660:	00208517          	auipc	a0,0x208
    80003664:	44850513          	addi	a0,a0,1096 # 8020baa8 <tickslock>
    80003668:	8f5fd0ef          	jal	80000f5c <initlock>
}
    8000366c:	00813083          	ld	ra,8(sp)
    80003670:	00013403          	ld	s0,0(sp)
    80003674:	01010113          	addi	sp,sp,16
    80003678:	00008067          	ret

000000008000367c <trapinithart>:

// set up to take exceptions and traps while in the kernel.
void
trapinithart(void)
{
    8000367c:	ff010113          	addi	sp,sp,-16
    80003680:	00113423          	sd	ra,8(sp)
    80003684:	00813023          	sd	s0,0(sp)
    80003688:	01010413          	addi	s0,sp,16
  asm volatile("csrw stvec, %0" : : "r"(x));
    8000368c:	00004797          	auipc	a5,0x4
    80003690:	53478793          	addi	a5,a5,1332 # 80007bc0 <kernelvec>
    80003694:	10579073          	csrw	stvec,a5
  w_stvec((uint64)kernelvec);
}
    80003698:	00813083          	ld	ra,8(sp)
    8000369c:	00013403          	ld	s0,0(sp)
    800036a0:	01010113          	addi	sp,sp,16
    800036a4:	00008067          	ret

00000000800036a8 <prepare_return>:
//
// set up trapframe and control registers for a return to user space
//
void
prepare_return(void)
{
    800036a8:	ff010113          	addi	sp,sp,-16
    800036ac:	00113423          	sd	ra,8(sp)
    800036b0:	00813023          	sd	s0,0(sp)
    800036b4:	01010413          	addi	s0,sp,16
  struct proc *p = myproc();
    800036b8:	f3dfe0ef          	jal	800025f4 <myproc>
  asm volatile("csrr %0, sstatus" : "=r"(x));
    800036bc:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() & ~SSTATUS_SIE);
    800036c0:	ffd7f793          	andi	a5,a5,-3
  asm volatile("csrw sstatus, %0" : : "r"(x));
    800036c4:	10079073          	csrw	sstatus,a5
  // kerneltrap() to usertrap(). because a trap from kernel
  // code to usertrap would be a disaster, turn off interrupts.
  intr_off();

  // send syscalls, interrupts, and exceptions to uservec in trampoline.S
  uint64 trampoline_uservec = TRAMPOLINE + (uservec - trampoline);
    800036c8:	04000737          	lui	a4,0x4000
    800036cc:	fff70713          	addi	a4,a4,-1 # 3ffffff <_binary_fs_img_size+0x3e0bfff>
    800036d0:	00c71713          	slli	a4,a4,0xc
    800036d4:	00005797          	auipc	a5,0x5
    800036d8:	92c78793          	addi	a5,a5,-1748 # 80008000 <_trampoline>
    800036dc:	00005697          	auipc	a3,0x5
    800036e0:	92468693          	addi	a3,a3,-1756 # 80008000 <_trampoline>
    800036e4:	40d787b3          	sub	a5,a5,a3
    800036e8:	00e787b3          	add	a5,a5,a4
  asm volatile("csrw stvec, %0" : : "r"(x));
    800036ec:	10579073          	csrw	stvec,a5
  w_stvec(trampoline_uservec);

  // set up trapframe values that uservec will need when
  // the process next traps into the kernel.
  p->trapframe->kernel_satp = r_satp();         // kernel page table
    800036f0:	05853783          	ld	a5,88(a0)
  asm volatile("csrr %0, satp" : "=r"(x));
    800036f4:	18002773          	csrr	a4,satp
    800036f8:	00e7b023          	sd	a4,0(a5)
  p->trapframe->kernel_sp = p->kstack + PGSIZE; // process's kernel stack
    800036fc:	05853703          	ld	a4,88(a0)
    80003700:	04053783          	ld	a5,64(a0)
    80003704:	000016b7          	lui	a3,0x1
    80003708:	00d787b3          	add	a5,a5,a3
    8000370c:	00f73423          	sd	a5,8(a4)
  p->trapframe->kernel_trap = (uint64)usertrap;
    80003710:	05853783          	ld	a5,88(a0)
    80003714:	00000717          	auipc	a4,0x0
    80003718:	17070713          	addi	a4,a4,368 # 80003884 <usertrap>
    8000371c:	00e7b823          	sd	a4,16(a5)
  p->trapframe->kernel_hartid = r_tp();         // hartid for cpuid()
    80003720:	05853783          	ld	a5,88(a0)
  asm volatile("mv %0, tp" : "=r"(x));
    80003724:	00020713          	mv	a4,tp
    80003728:	02e7b023          	sd	a4,32(a5)
  asm volatile("csrr %0, sstatus" : "=r"(x));
    8000372c:	100027f3          	csrr	a5,sstatus
  // set up the registers that trampoline.S's sret will use
  // to get to user space.
  
  // set S Previous Privilege mode to User.
  unsigned long x = r_sstatus();
  x &= ~SSTATUS_SPP; // clear SPP to 0 for user mode
    80003730:	eff7f793          	andi	a5,a5,-257
  x |= SSTATUS_SPIE; // enable interrupts in user mode
    80003734:	0207e793          	ori	a5,a5,32
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80003738:	10079073          	csrw	sstatus,a5
  w_sstatus(x);

  // set S Exception Program Counter to the saved user pc.
  w_sepc(p->trapframe->epc);
    8000373c:	05853783          	ld	a5,88(a0)
  asm volatile("csrw sepc, %0" : : "r"(x));
    80003740:	0187b783          	ld	a5,24(a5)
    80003744:	14179073          	csrw	sepc,a5
}
    80003748:	00813083          	ld	ra,8(sp)
    8000374c:	00013403          	ld	s0,0(sp)
    80003750:	01010113          	addi	sp,sp,16
    80003754:	00008067          	ret

0000000080003758 <clockintr>:
  w_sstatus(sstatus);
}

void
clockintr()
{
    80003758:	ff010113          	addi	sp,sp,-16
    8000375c:	00113423          	sd	ra,8(sp)
    80003760:	00813023          	sd	s0,0(sp)
    80003764:	01010413          	addi	s0,sp,16
  // printf("[LOG] Dived into clockintr()\n");
  if(cpuid() == 0){
    80003768:	e2dfe0ef          	jal	80002594 <cpuid>
    8000376c:	02050463          	beqz	a0,80003794 <clockintr+0x3c>
  asm volatile("csrr %0, time" : "=r"(x));
    80003770:	c01027f3          	rdtime	a5

  // ask for the next timer interrupt. this also clears
  // the interrupt request. 1000000 is about a tenth
  // of a second.
  // デバッグ用に間隔を大きくした.
  w_stimecmp(r_time() + 5000000);
    80003774:	004c5737          	lui	a4,0x4c5
    80003778:	b4070713          	addi	a4,a4,-1216 # 4c4b40 <_binary_fs_img_size+0x2d0b40>
    8000377c:	00e787b3          	add	a5,a5,a4
  asm volatile("csrw 0x14d, %0" : : "r"(x));
    80003780:	14d79073          	csrw	stimecmp,a5
}
    80003784:	00813083          	ld	ra,8(sp)
    80003788:	00013403          	ld	s0,0(sp)
    8000378c:	01010113          	addi	sp,sp,16
    80003790:	00008067          	ret
    acquire(&tickslock);
    80003794:	00208517          	auipc	a0,0x208
    80003798:	31450513          	addi	a0,a0,788 # 8020baa8 <tickslock>
    8000379c:	8a5fd0ef          	jal	80001040 <acquire>
    ticks++;
    800037a0:	001fa717          	auipc	a4,0x1fa
    800037a4:	3d070713          	addi	a4,a4,976 # 801fdb70 <ticks>
    800037a8:	00072783          	lw	a5,0(a4)
    800037ac:	0017879b          	addiw	a5,a5,1
    800037b0:	00f72023          	sw	a5,0(a4)
    wakeup(&ticks);
    800037b4:	00070513          	mv	a0,a4
    800037b8:	fc0ff0ef          	jal	80002f78 <wakeup>
    release(&tickslock);
    800037bc:	00208517          	auipc	a0,0x208
    800037c0:	2ec50513          	addi	a0,a0,748 # 8020baa8 <tickslock>
    800037c4:	955fd0ef          	jal	80001118 <release>
    800037c8:	fa9ff06f          	j	80003770 <clockintr+0x18>

00000000800037cc <devintr>:
// returns 2 if timer interrupt,
// 1 if other device,
// 0 if not recognized.
int
devintr()
{
    800037cc:	fe010113          	addi	sp,sp,-32
    800037d0:	00113c23          	sd	ra,24(sp)
    800037d4:	00813823          	sd	s0,16(sp)
    800037d8:	02010413          	addi	s0,sp,32
  asm volatile("csrr %0, scause" : "=r"(x));
    800037dc:	14202773          	csrr	a4,scause
  uint64 scause = r_scause();

  if(scause == 0x8000000000000009L){
    800037e0:	fff00793          	li	a5,-1
    800037e4:	03f79793          	slli	a5,a5,0x3f
    800037e8:	00978793          	addi	a5,a5,9
    800037ec:	02f70463          	beq	a4,a5,80003814 <devintr+0x48>
      // printf("[LOG][trap.c] plic_complete(%d) executed\n",irq);
      plic_complete(irq);
    }

    return 1;
  } else if(scause == 0x8000000000000005L){
    800037f0:	fff00793          	li	a5,-1
    800037f4:	03f79793          	slli	a5,a5,0x3f
    800037f8:	00578793          	addi	a5,a5,5
    // timer interrupt.
    clockintr();
    return 2;
  } else {
    return 0;
    800037fc:	00000513          	li	a0,0
  } else if(scause == 0x8000000000000005L){
    80003800:	06f70c63          	beq	a4,a5,80003878 <devintr+0xac>
  }
}
    80003804:	01813083          	ld	ra,24(sp)
    80003808:	01013403          	ld	s0,16(sp)
    8000380c:	02010113          	addi	sp,sp,32
    80003810:	00008067          	ret
    80003814:	00913423          	sd	s1,8(sp)
    int irq = plic_claim();
    80003818:	4c0040ef          	jal	80007cd8 <plic_claim>
    8000381c:	00050713          	mv	a4,a0
    80003820:	00050493          	mv	s1,a0
    if(irq == UART0_IRQ){
    80003824:	00a00793          	li	a5,10
    80003828:	00f50e63          	beq	a0,a5,80003844 <devintr+0x78>
    } else if(irq == VIRTIO0_IRQ){
    8000382c:	00100793          	li	a5,1
    80003830:	00f50e63          	beq	a0,a5,8000384c <devintr+0x80>
    return 1;
    80003834:	00100513          	li	a0,1
    } else if(irq){
    80003838:	00071e63          	bnez	a4,80003854 <devintr+0x88>
    8000383c:	00813483          	ld	s1,8(sp)
    80003840:	fc5ff06f          	j	80003804 <devintr+0x38>
      uartintr();
    80003844:	cd0fd0ef          	jal	80000d14 <uartintr>
    if(irq){
    80003848:	01c0006f          	j	80003864 <devintr+0x98>
      virtio_disk_intr();
    8000384c:	660040ef          	jal	80007eac <virtio_disk_intr>
    if(irq){
    80003850:	0140006f          	j	80003864 <devintr+0x98>
      printf("unexpected interrupt irq=%d\n", irq);
    80003854:	00070593          	mv	a1,a4
    80003858:	00006517          	auipc	a0,0x6
    8000385c:	da050513          	addi	a0,a0,-608 # 800095f8 <etext+0x5f8>
    80003860:	e6dfc0ef          	jal	800006cc <printf>
      plic_complete(irq);
    80003864:	00048513          	mv	a0,s1
    80003868:	4a4040ef          	jal	80007d0c <plic_complete>
    return 1;
    8000386c:	00100513          	li	a0,1
    80003870:	00813483          	ld	s1,8(sp)
    80003874:	f91ff06f          	j	80003804 <devintr+0x38>
    clockintr();
    80003878:	ee1ff0ef          	jal	80003758 <clockintr>
    return 2;
    8000387c:	00200513          	li	a0,2
    80003880:	f85ff06f          	j	80003804 <devintr+0x38>

0000000080003884 <usertrap>:
{
    80003884:	fe010113          	addi	sp,sp,-32
    80003888:	00113c23          	sd	ra,24(sp)
    8000388c:	00813823          	sd	s0,16(sp)
    80003890:	00913423          	sd	s1,8(sp)
    80003894:	01213023          	sd	s2,0(sp)
    80003898:	02010413          	addi	s0,sp,32
  asm volatile("csrr %0, sstatus" : "=r"(x));
    8000389c:	100027f3          	csrr	a5,sstatus
  if((r_sstatus() & SSTATUS_SPP) != 0)
    800038a0:	1007f793          	andi	a5,a5,256
    800038a4:	08079463          	bnez	a5,8000392c <usertrap+0xa8>
  asm volatile("csrw stvec, %0" : : "r"(x));
    800038a8:	00004797          	auipc	a5,0x4
    800038ac:	31878793          	addi	a5,a5,792 # 80007bc0 <kernelvec>
    800038b0:	10579073          	csrw	stvec,a5
  struct proc *p = myproc();
    800038b4:	d41fe0ef          	jal	800025f4 <myproc>
    800038b8:	00050493          	mv	s1,a0
  p->trapframe->epc = r_sepc();
    800038bc:	05853783          	ld	a5,88(a0)
  asm volatile("csrr %0, sepc" : "=r"(x));
    800038c0:	14102773          	csrr	a4,sepc
    800038c4:	00e7bc23          	sd	a4,24(a5)
  asm volatile("csrr %0, scause" : "=r"(x));
    800038c8:	14202773          	csrr	a4,scause
  if(r_scause() == 8){
    800038cc:	00800793          	li	a5,8
    800038d0:	06f70463          	beq	a4,a5,80003938 <usertrap+0xb4>
  } else if((which_dev = devintr()) != 0){
    800038d4:	ef9ff0ef          	jal	800037cc <devintr>
    800038d8:	00050913          	mv	s2,a0
    800038dc:	0e051663          	bnez	a0,800039c8 <usertrap+0x144>
    800038e0:	14202773          	csrr	a4,scause
  } else if((r_scause() == 15 || r_scause() == 13) &&
    800038e4:	00f00793          	li	a5,15
    800038e8:	0cf70063          	beq	a4,a5,800039a8 <usertrap+0x124>
    800038ec:	14202773          	csrr	a4,scause
    800038f0:	00d00793          	li	a5,13
    800038f4:	0af70a63          	beq	a4,a5,800039a8 <usertrap+0x124>
    800038f8:	142025f3          	csrr	a1,scause
    printf("usertrap(): unexpected scause 0x%lx pid=%d\n", r_scause(), p->pid);
    800038fc:	0304a603          	lw	a2,48(s1)
    80003900:	00006517          	auipc	a0,0x6
    80003904:	d3850513          	addi	a0,a0,-712 # 80009638 <etext+0x638>
    80003908:	dc5fc0ef          	jal	800006cc <printf>
  asm volatile("csrr %0, sepc" : "=r"(x));
    8000390c:	141025f3          	csrr	a1,sepc
  asm volatile("csrr %0, stval" : "=r"(x));
    80003910:	14302673          	csrr	a2,stval
    printf("            sepc=0x%lx stval=0x%lx\n", r_sepc(), r_stval());
    80003914:	00006517          	auipc	a0,0x6
    80003918:	d5450513          	addi	a0,a0,-684 # 80009668 <etext+0x668>
    8000391c:	db1fc0ef          	jal	800006cc <printf>
    setkilled(p);
    80003920:	00048513          	mv	a0,s1
    80003924:	8ddff0ef          	jal	80003200 <setkilled>
    80003928:	0380006f          	j	80003960 <usertrap+0xdc>
    panic("usertrap: not from user mode");
    8000392c:	00006517          	auipc	a0,0x6
    80003930:	cec50513          	addi	a0,a0,-788 # 80009618 <etext+0x618>
    80003934:	9b8fd0ef          	jal	80000aec <panic>
    if(killed(p))
    80003938:	909ff0ef          	jal	80003240 <killed>
    8000393c:	06051063          	bnez	a0,8000399c <usertrap+0x118>
    p->trapframe->epc += 4;
    80003940:	0584b703          	ld	a4,88(s1)
    80003944:	01873783          	ld	a5,24(a4)
    80003948:	00478793          	addi	a5,a5,4
    8000394c:	00f73c23          	sd	a5,24(a4)
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80003950:	100027f3          	csrr	a5,sstatus
  w_sstatus(r_sstatus() | SSTATUS_SIE);
    80003954:	0027e793          	ori	a5,a5,2
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80003958:	10079073          	csrw	sstatus,a5
    syscall();
    8000395c:	394000ef          	jal	80003cf0 <syscall>
  if(killed(p))
    80003960:	00048513          	mv	a0,s1
    80003964:	8ddff0ef          	jal	80003240 <killed>
    80003968:	06051863          	bnez	a0,800039d8 <usertrap+0x154>
  prepare_return();
    8000396c:	d3dff0ef          	jal	800036a8 <prepare_return>
  uint64 satp = MAKE_SATP(p->pagetable);
    80003970:	0504b503          	ld	a0,80(s1)
    80003974:	00c55513          	srli	a0,a0,0xc
    80003978:	fff00793          	li	a5,-1
    8000397c:	03f79793          	slli	a5,a5,0x3f
    80003980:	00f56533          	or	a0,a0,a5
}
    80003984:	01813083          	ld	ra,24(sp)
    80003988:	01013403          	ld	s0,16(sp)
    8000398c:	00813483          	ld	s1,8(sp)
    80003990:	00013903          	ld	s2,0(sp)
    80003994:	02010113          	addi	sp,sp,32
    80003998:	00008067          	ret
      kexit(-1);
    8000399c:	fff00513          	li	a0,-1
    800039a0:	ef8ff0ef          	jal	80003098 <kexit>
    800039a4:	f9dff06f          	j	80003940 <usertrap+0xbc>
  asm volatile("csrr %0, stval" : "=r"(x));
    800039a8:	143025f3          	csrr	a1,stval
  asm volatile("csrr %0, scause" : "=r"(x));
    800039ac:	14202673          	csrr	a2,scause
            vmfault(p->pagetable, r_stval(), (r_scause() == 13)? 1 : 0) != 0) {
    800039b0:	ff360613          	addi	a2,a2,-13 # ff3 <_binary_fs_img_size-0x1f300d>
    800039b4:	00163613          	seqz	a2,a2
    800039b8:	0504b503          	ld	a0,80(s1)
    800039bc:	ed4fe0ef          	jal	80002090 <vmfault>
  } else if((r_scause() == 15 || r_scause() == 13) &&
    800039c0:	fa0510e3          	bnez	a0,80003960 <usertrap+0xdc>
    800039c4:	f35ff06f          	j	800038f8 <usertrap+0x74>
  if(killed(p))
    800039c8:	00048513          	mv	a0,s1
    800039cc:	875ff0ef          	jal	80003240 <killed>
    800039d0:	00050a63          	beqz	a0,800039e4 <usertrap+0x160>
    800039d4:	0080006f          	j	800039dc <usertrap+0x158>
    800039d8:	00000913          	li	s2,0
    kexit(-1);
    800039dc:	fff00513          	li	a0,-1
    800039e0:	eb8ff0ef          	jal	80003098 <kexit>
  if(which_dev == 2)
    800039e4:	00200793          	li	a5,2
    800039e8:	f8f912e3          	bne	s2,a5,8000396c <usertrap+0xe8>
    yield();
    800039ec:	cccff0ef          	jal	80002eb8 <yield>
    800039f0:	f7dff06f          	j	8000396c <usertrap+0xe8>

00000000800039f4 <kerneltrap>:
{
    800039f4:	fd010113          	addi	sp,sp,-48
    800039f8:	02113423          	sd	ra,40(sp)
    800039fc:	02813023          	sd	s0,32(sp)
    80003a00:	00913c23          	sd	s1,24(sp)
    80003a04:	01213823          	sd	s2,16(sp)
    80003a08:	01313423          	sd	s3,8(sp)
    80003a0c:	03010413          	addi	s0,sp,48
  asm volatile("csrr %0, sepc" : "=r"(x));
    80003a10:	14102973          	csrr	s2,sepc
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80003a14:	100024f3          	csrr	s1,sstatus
  asm volatile("csrr %0, scause" : "=r"(x));
    80003a18:	142027f3          	csrr	a5,scause
    80003a1c:	00078993          	mv	s3,a5
  if((sstatus & SSTATUS_SPP) == 0)
    80003a20:	1004f793          	andi	a5,s1,256
    80003a24:	04078263          	beqz	a5,80003a68 <kerneltrap+0x74>
  asm volatile("csrr %0, sstatus" : "=r"(x));
    80003a28:	100027f3          	csrr	a5,sstatus
  return (x & SSTATUS_SIE) != 0;
    80003a2c:	0027f793          	andi	a5,a5,2
  if(intr_get() != 0)
    80003a30:	04079263          	bnez	a5,80003a74 <kerneltrap+0x80>
  if((which_dev = devintr()) == 0){
    80003a34:	d99ff0ef          	jal	800037cc <devintr>
    80003a38:	04050463          	beqz	a0,80003a80 <kerneltrap+0x8c>
  if(which_dev == 2 && myproc() != 0)
    80003a3c:	00200793          	li	a5,2
    80003a40:	06f50263          	beq	a0,a5,80003aa4 <kerneltrap+0xb0>
  asm volatile("csrw sepc, %0" : : "r"(x));
    80003a44:	14191073          	csrw	sepc,s2
  asm volatile("csrw sstatus, %0" : : "r"(x));
    80003a48:	10049073          	csrw	sstatus,s1
}
    80003a4c:	02813083          	ld	ra,40(sp)
    80003a50:	02013403          	ld	s0,32(sp)
    80003a54:	01813483          	ld	s1,24(sp)
    80003a58:	01013903          	ld	s2,16(sp)
    80003a5c:	00813983          	ld	s3,8(sp)
    80003a60:	03010113          	addi	sp,sp,48
    80003a64:	00008067          	ret
    panic("kerneltrap: not from supervisor mode");
    80003a68:	00006517          	auipc	a0,0x6
    80003a6c:	c2850513          	addi	a0,a0,-984 # 80009690 <etext+0x690>
    80003a70:	87cfd0ef          	jal	80000aec <panic>
    panic("kerneltrap: interrupts enabled");
    80003a74:	00006517          	auipc	a0,0x6
    80003a78:	c4450513          	addi	a0,a0,-956 # 800096b8 <etext+0x6b8>
    80003a7c:	870fd0ef          	jal	80000aec <panic>
  asm volatile("csrr %0, sepc" : "=r"(x));
    80003a80:	14102673          	csrr	a2,sepc
  asm volatile("csrr %0, stval" : "=r"(x));
    80003a84:	143026f3          	csrr	a3,stval
    printf("scause=0x%lx sepc=0x%lx stval=0x%lx\n", scause, r_sepc(), r_stval());
    80003a88:	00098593          	mv	a1,s3
    80003a8c:	00006517          	auipc	a0,0x6
    80003a90:	c4c50513          	addi	a0,a0,-948 # 800096d8 <etext+0x6d8>
    80003a94:	c39fc0ef          	jal	800006cc <printf>
    panic("kerneltrap");
    80003a98:	00006517          	auipc	a0,0x6
    80003a9c:	c6850513          	addi	a0,a0,-920 # 80009700 <etext+0x700>
    80003aa0:	84cfd0ef          	jal	80000aec <panic>
  if(which_dev == 2 && myproc() != 0)
    80003aa4:	b51fe0ef          	jal	800025f4 <myproc>
    80003aa8:	f8050ee3          	beqz	a0,80003a44 <kerneltrap+0x50>
    yield();
    80003aac:	c0cff0ef          	jal	80002eb8 <yield>
    80003ab0:	f95ff06f          	j	80003a44 <kerneltrap+0x50>

0000000080003ab4 <argraw>:
  return strlen(buf);
}

static uint64
argraw(int n)
{
    80003ab4:	fe010113          	addi	sp,sp,-32
    80003ab8:	00113c23          	sd	ra,24(sp)
    80003abc:	00813823          	sd	s0,16(sp)
    80003ac0:	00913423          	sd	s1,8(sp)
    80003ac4:	02010413          	addi	s0,sp,32
    80003ac8:	00050493          	mv	s1,a0
  struct proc *p = myproc();
    80003acc:	b29fe0ef          	jal	800025f4 <myproc>
  switch (n) {
    80003ad0:	00500793          	li	a5,5
    80003ad4:	0697ec63          	bltu	a5,s1,80003b4c <argraw+0x98>
    80003ad8:	00249493          	slli	s1,s1,0x2
    80003adc:	00006717          	auipc	a4,0x6
    80003ae0:	f9c70713          	addi	a4,a4,-100 # 80009a78 <states.0+0x30>
    80003ae4:	00e484b3          	add	s1,s1,a4
    80003ae8:	0004a783          	lw	a5,0(s1)
    80003aec:	00e787b3          	add	a5,a5,a4
    80003af0:	00078067          	jr	a5
  case 0:
    return p->trapframe->a0;
    80003af4:	05853783          	ld	a5,88(a0)
    80003af8:	0707b503          	ld	a0,112(a5)
  case 5:
    return p->trapframe->a5;
  }
  panic("argraw");
  return -1;
}
    80003afc:	01813083          	ld	ra,24(sp)
    80003b00:	01013403          	ld	s0,16(sp)
    80003b04:	00813483          	ld	s1,8(sp)
    80003b08:	02010113          	addi	sp,sp,32
    80003b0c:	00008067          	ret
    return p->trapframe->a1;
    80003b10:	05853783          	ld	a5,88(a0)
    80003b14:	0787b503          	ld	a0,120(a5)
    80003b18:	fe5ff06f          	j	80003afc <argraw+0x48>
    return p->trapframe->a2;
    80003b1c:	05853783          	ld	a5,88(a0)
    80003b20:	0807b503          	ld	a0,128(a5)
    80003b24:	fd9ff06f          	j	80003afc <argraw+0x48>
    return p->trapframe->a3;
    80003b28:	05853783          	ld	a5,88(a0)
    80003b2c:	0887b503          	ld	a0,136(a5)
    80003b30:	fcdff06f          	j	80003afc <argraw+0x48>
    return p->trapframe->a4;
    80003b34:	05853783          	ld	a5,88(a0)
    80003b38:	0907b503          	ld	a0,144(a5)
    80003b3c:	fc1ff06f          	j	80003afc <argraw+0x48>
    return p->trapframe->a5;
    80003b40:	05853783          	ld	a5,88(a0)
    80003b44:	0987b503          	ld	a0,152(a5)
    80003b48:	fb5ff06f          	j	80003afc <argraw+0x48>
  panic("argraw");
    80003b4c:	00006517          	auipc	a0,0x6
    80003b50:	bc450513          	addi	a0,a0,-1084 # 80009710 <etext+0x710>
    80003b54:	f99fc0ef          	jal	80000aec <panic>

0000000080003b58 <fetchaddr>:
{
    80003b58:	fe010113          	addi	sp,sp,-32
    80003b5c:	00113c23          	sd	ra,24(sp)
    80003b60:	00813823          	sd	s0,16(sp)
    80003b64:	00913423          	sd	s1,8(sp)
    80003b68:	01213023          	sd	s2,0(sp)
    80003b6c:	02010413          	addi	s0,sp,32
    80003b70:	00050493          	mv	s1,a0
    80003b74:	00058913          	mv	s2,a1
  struct proc *p = myproc();
    80003b78:	a7dfe0ef          	jal	800025f4 <myproc>
  if(addr >= p->sz || addr+sizeof(uint64) > p->sz) // both tests needed, in case of overflow
    80003b7c:	04853783          	ld	a5,72(a0)
    80003b80:	04f4f063          	bgeu	s1,a5,80003bc0 <fetchaddr+0x68>
    80003b84:	00848713          	addi	a4,s1,8
    80003b88:	04e7e063          	bltu	a5,a4,80003bc8 <fetchaddr+0x70>
  if(copyin(p->pagetable, (char *)ip, addr, sizeof(*ip)) != 0)
    80003b8c:	00800693          	li	a3,8
    80003b90:	00048613          	mv	a2,s1
    80003b94:	00090593          	mv	a1,s2
    80003b98:	05053503          	ld	a0,80(a0)
    80003b9c:	f18fe0ef          	jal	800022b4 <copyin>
    80003ba0:	00a03533          	snez	a0,a0
    80003ba4:	40a0053b          	negw	a0,a0
}
    80003ba8:	01813083          	ld	ra,24(sp)
    80003bac:	01013403          	ld	s0,16(sp)
    80003bb0:	00813483          	ld	s1,8(sp)
    80003bb4:	00013903          	ld	s2,0(sp)
    80003bb8:	02010113          	addi	sp,sp,32
    80003bbc:	00008067          	ret
    return -1;
    80003bc0:	fff00513          	li	a0,-1
    80003bc4:	fe5ff06f          	j	80003ba8 <fetchaddr+0x50>
    80003bc8:	fff00513          	li	a0,-1
    80003bcc:	fddff06f          	j	80003ba8 <fetchaddr+0x50>

0000000080003bd0 <fetchstr>:
{
    80003bd0:	fd010113          	addi	sp,sp,-48
    80003bd4:	02113423          	sd	ra,40(sp)
    80003bd8:	02813023          	sd	s0,32(sp)
    80003bdc:	00913c23          	sd	s1,24(sp)
    80003be0:	01213823          	sd	s2,16(sp)
    80003be4:	01313423          	sd	s3,8(sp)
    80003be8:	03010413          	addi	s0,sp,48
    80003bec:	00050993          	mv	s3,a0
    80003bf0:	00058493          	mv	s1,a1
    80003bf4:	00060913          	mv	s2,a2
  struct proc *p = myproc();
    80003bf8:	9fdfe0ef          	jal	800025f4 <myproc>
  if(copyinstr(p->pagetable, buf, addr, max) < 0)
    80003bfc:	00090693          	mv	a3,s2
    80003c00:	00098613          	mv	a2,s3
    80003c04:	00048593          	mv	a1,s1
    80003c08:	05053503          	ld	a0,80(a0)
    80003c0c:	b24fe0ef          	jal	80001f30 <copyinstr>
    80003c10:	02054463          	bltz	a0,80003c38 <fetchstr+0x68>
  return strlen(buf);
    80003c14:	00048513          	mv	a0,s1
    80003c18:	831fd0ef          	jal	80001448 <strlen>
}
    80003c1c:	02813083          	ld	ra,40(sp)
    80003c20:	02013403          	ld	s0,32(sp)
    80003c24:	01813483          	ld	s1,24(sp)
    80003c28:	01013903          	ld	s2,16(sp)
    80003c2c:	00813983          	ld	s3,8(sp)
    80003c30:	03010113          	addi	sp,sp,48
    80003c34:	00008067          	ret
    return -1;
    80003c38:	fff00513          	li	a0,-1
    80003c3c:	fe1ff06f          	j	80003c1c <fetchstr+0x4c>

0000000080003c40 <argint>:

// Fetch the nth 32-bit system call argument.
void
argint(int n, int *ip)
{
    80003c40:	fe010113          	addi	sp,sp,-32
    80003c44:	00113c23          	sd	ra,24(sp)
    80003c48:	00813823          	sd	s0,16(sp)
    80003c4c:	00913423          	sd	s1,8(sp)
    80003c50:	02010413          	addi	s0,sp,32
    80003c54:	00058493          	mv	s1,a1
  *ip = argraw(n);
    80003c58:	e5dff0ef          	jal	80003ab4 <argraw>
    80003c5c:	00a4a023          	sw	a0,0(s1)
}
    80003c60:	01813083          	ld	ra,24(sp)
    80003c64:	01013403          	ld	s0,16(sp)
    80003c68:	00813483          	ld	s1,8(sp)
    80003c6c:	02010113          	addi	sp,sp,32
    80003c70:	00008067          	ret

0000000080003c74 <argaddr>:
// Retrieve an argument as a pointer.
// Doesn't check for legality, since
// copyin/copyout will do that.
void
argaddr(int n, uint64 *ip)
{
    80003c74:	fe010113          	addi	sp,sp,-32
    80003c78:	00113c23          	sd	ra,24(sp)
    80003c7c:	00813823          	sd	s0,16(sp)
    80003c80:	00913423          	sd	s1,8(sp)
    80003c84:	02010413          	addi	s0,sp,32
    80003c88:	00058493          	mv	s1,a1
  *ip = argraw(n);
    80003c8c:	e29ff0ef          	jal	80003ab4 <argraw>
    80003c90:	00a4b023          	sd	a0,0(s1)
}
    80003c94:	01813083          	ld	ra,24(sp)
    80003c98:	01013403          	ld	s0,16(sp)
    80003c9c:	00813483          	ld	s1,8(sp)
    80003ca0:	02010113          	addi	sp,sp,32
    80003ca4:	00008067          	ret

0000000080003ca8 <argstr>:
// Fetch the nth word-sized system call argument as a null-terminated string.
// Copies into buf, at most max.
// Returns string length if OK (including nul), -1 if error.
int
argstr(int n, char *buf, int max)
{
    80003ca8:	fe010113          	addi	sp,sp,-32
    80003cac:	00113c23          	sd	ra,24(sp)
    80003cb0:	00813823          	sd	s0,16(sp)
    80003cb4:	00913423          	sd	s1,8(sp)
    80003cb8:	01213023          	sd	s2,0(sp)
    80003cbc:	02010413          	addi	s0,sp,32
    80003cc0:	00058913          	mv	s2,a1
    80003cc4:	00060493          	mv	s1,a2
  *ip = argraw(n);
    80003cc8:	dedff0ef          	jal	80003ab4 <argraw>
  uint64 addr;
  argaddr(n, &addr);
  return fetchstr(addr, buf, max);
    80003ccc:	00048613          	mv	a2,s1
    80003cd0:	00090593          	mv	a1,s2
    80003cd4:	efdff0ef          	jal	80003bd0 <fetchstr>
}
    80003cd8:	01813083          	ld	ra,24(sp)
    80003cdc:	01013403          	ld	s0,16(sp)
    80003ce0:	00813483          	ld	s1,8(sp)
    80003ce4:	00013903          	ld	s2,0(sp)
    80003ce8:	02010113          	addi	sp,sp,32
    80003cec:	00008067          	ret

0000000080003cf0 <syscall>:
[SYS_close]   sys_close,
};

void
syscall(void)
{
    80003cf0:	fe010113          	addi	sp,sp,-32
    80003cf4:	00113c23          	sd	ra,24(sp)
    80003cf8:	00813823          	sd	s0,16(sp)
    80003cfc:	00913423          	sd	s1,8(sp)
    80003d00:	01213023          	sd	s2,0(sp)
    80003d04:	02010413          	addi	s0,sp,32
  int num;
  struct proc *p = myproc();
    80003d08:	8edfe0ef          	jal	800025f4 <myproc>
    80003d0c:	00050493          	mv	s1,a0

  num = p->trapframe->a7;
    80003d10:	05853903          	ld	s2,88(a0)
    80003d14:	0a893783          	ld	a5,168(s2)
    80003d18:	0007869b          	sext.w	a3,a5
  if(num > 0 && num < NELEM(syscalls) && syscalls[num]) {
    80003d1c:	fff7879b          	addiw	a5,a5,-1
    80003d20:	01400713          	li	a4,20
    80003d24:	02f76463          	bltu	a4,a5,80003d4c <syscall+0x5c>
    80003d28:	00369713          	slli	a4,a3,0x3
    80003d2c:	00006797          	auipc	a5,0x6
    80003d30:	d6478793          	addi	a5,a5,-668 # 80009a90 <syscalls>
    80003d34:	00e787b3          	add	a5,a5,a4
    80003d38:	0007b783          	ld	a5,0(a5)
    80003d3c:	00078863          	beqz	a5,80003d4c <syscall+0x5c>
    // Use num to lookup the system call function for num, call it,
    // and store its return value in p->trapframe->a0
    p->trapframe->a0 = syscalls[num]();
    80003d40:	000780e7          	jalr	a5
    80003d44:	06a93823          	sd	a0,112(s2)
    80003d48:	0240006f          	j	80003d6c <syscall+0x7c>
  } else {
    printf("%d %s: unknown sys call %d\n",
    80003d4c:	15848613          	addi	a2,s1,344
    80003d50:	0304a583          	lw	a1,48(s1)
    80003d54:	00006517          	auipc	a0,0x6
    80003d58:	9c450513          	addi	a0,a0,-1596 # 80009718 <etext+0x718>
    80003d5c:	971fc0ef          	jal	800006cc <printf>
            p->pid, p->name, num);
    p->trapframe->a0 = -1;
    80003d60:	0584b783          	ld	a5,88(s1)
    80003d64:	fff00713          	li	a4,-1
    80003d68:	06e7b823          	sd	a4,112(a5)
  }
}
    80003d6c:	01813083          	ld	ra,24(sp)
    80003d70:	01013403          	ld	s0,16(sp)
    80003d74:	00813483          	ld	s1,8(sp)
    80003d78:	00013903          	ld	s2,0(sp)
    80003d7c:	02010113          	addi	sp,sp,32
    80003d80:	00008067          	ret

0000000080003d84 <sys_exit>:
#include "proc.h"
#include "vm.h"

uint64
sys_exit(void)
{
    80003d84:	fe010113          	addi	sp,sp,-32
    80003d88:	00113c23          	sd	ra,24(sp)
    80003d8c:	00813823          	sd	s0,16(sp)
    80003d90:	02010413          	addi	s0,sp,32
  int n;
  argint(0, &n);
    80003d94:	fec40593          	addi	a1,s0,-20
    80003d98:	00000513          	li	a0,0
    80003d9c:	ea5ff0ef          	jal	80003c40 <argint>
  kexit(n);
    80003da0:	fec42503          	lw	a0,-20(s0)
    80003da4:	af4ff0ef          	jal	80003098 <kexit>
  return 0;  // not reached
}
    80003da8:	00000513          	li	a0,0
    80003dac:	01813083          	ld	ra,24(sp)
    80003db0:	01013403          	ld	s0,16(sp)
    80003db4:	02010113          	addi	sp,sp,32
    80003db8:	00008067          	ret

0000000080003dbc <sys_getpid>:

uint64
sys_getpid(void)
{
    80003dbc:	ff010113          	addi	sp,sp,-16
    80003dc0:	00113423          	sd	ra,8(sp)
    80003dc4:	00813023          	sd	s0,0(sp)
    80003dc8:	01010413          	addi	s0,sp,16
  return myproc()->pid;
    80003dcc:	829fe0ef          	jal	800025f4 <myproc>
}
    80003dd0:	03052503          	lw	a0,48(a0)
    80003dd4:	00813083          	ld	ra,8(sp)
    80003dd8:	00013403          	ld	s0,0(sp)
    80003ddc:	01010113          	addi	sp,sp,16
    80003de0:	00008067          	ret

0000000080003de4 <sys_fork>:

uint64
sys_fork(void)
{
    80003de4:	ff010113          	addi	sp,sp,-16
    80003de8:	00113423          	sd	ra,8(sp)
    80003dec:	00813023          	sd	s0,0(sp)
    80003df0:	01010413          	addi	s0,sp,16
  return kfork();
    80003df4:	d5dfe0ef          	jal	80002b50 <kfork>
}
    80003df8:	00813083          	ld	ra,8(sp)
    80003dfc:	00013403          	ld	s0,0(sp)
    80003e00:	01010113          	addi	sp,sp,16
    80003e04:	00008067          	ret

0000000080003e08 <sys_wait>:

uint64
sys_wait(void)
{
    80003e08:	fe010113          	addi	sp,sp,-32
    80003e0c:	00113c23          	sd	ra,24(sp)
    80003e10:	00813823          	sd	s0,16(sp)
    80003e14:	02010413          	addi	s0,sp,32
  uint64 p;
  argaddr(0, &p);
    80003e18:	fe840593          	addi	a1,s0,-24
    80003e1c:	00000513          	li	a0,0
    80003e20:	e55ff0ef          	jal	80003c74 <argaddr>
  return kwait(p);
    80003e24:	fe843503          	ld	a0,-24(s0)
    80003e28:	c64ff0ef          	jal	8000328c <kwait>
}
    80003e2c:	01813083          	ld	ra,24(sp)
    80003e30:	01013403          	ld	s0,16(sp)
    80003e34:	02010113          	addi	sp,sp,32
    80003e38:	00008067          	ret

0000000080003e3c <sys_sbrk>:

uint64
sys_sbrk(void)
{
    80003e3c:	fd010113          	addi	sp,sp,-48
    80003e40:	02113423          	sd	ra,40(sp)
    80003e44:	02813023          	sd	s0,32(sp)
    80003e48:	00913c23          	sd	s1,24(sp)
    80003e4c:	03010413          	addi	s0,sp,48
  uint64 addr;
  int t;
  int n;

  argint(0, &n);
    80003e50:	fd840593          	addi	a1,s0,-40
    80003e54:	00000513          	li	a0,0
    80003e58:	de9ff0ef          	jal	80003c40 <argint>
  argint(1, &t);
    80003e5c:	fdc40593          	addi	a1,s0,-36
    80003e60:	00100513          	li	a0,1
    80003e64:	dddff0ef          	jal	80003c40 <argint>
  addr = myproc()->sz;
    80003e68:	f8cfe0ef          	jal	800025f4 <myproc>
    80003e6c:	04853483          	ld	s1,72(a0)

  if(t == SBRK_EAGER || n < 0) {
    80003e70:	fdc42703          	lw	a4,-36(s0)
    80003e74:	00100793          	li	a5,1
    80003e78:	02f70e63          	beq	a4,a5,80003eb4 <sys_sbrk+0x78>
    80003e7c:	fd842783          	lw	a5,-40(s0)
    80003e80:	0207ca63          	bltz	a5,80003eb4 <sys_sbrk+0x78>
    }
  } else {
    // Lazily allocate memory for this process: increase its memory
    // size but don't allocate memory. If the processes uses the
    // memory, vmfault() will allocate it.
    if(addr + n < addr)
    80003e84:	009787b3          	add	a5,a5,s1
      return -1;
    if(addr + n > TRAPFRAME)
    80003e88:	02000737          	lui	a4,0x2000
    80003e8c:	fff70713          	addi	a4,a4,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    80003e90:	00d71713          	slli	a4,a4,0xd
    80003e94:	04f76663          	bltu	a4,a5,80003ee0 <sys_sbrk+0xa4>
    80003e98:	0497e463          	bltu	a5,s1,80003ee0 <sys_sbrk+0xa4>
      return -1;
    myproc()->sz += n;
    80003e9c:	f58fe0ef          	jal	800025f4 <myproc>
    80003ea0:	fd842703          	lw	a4,-40(s0)
    80003ea4:	04853783          	ld	a5,72(a0)
    80003ea8:	00e787b3          	add	a5,a5,a4
    80003eac:	04f53423          	sd	a5,72(a0)
    80003eb0:	0100006f          	j	80003ec0 <sys_sbrk+0x84>
    if(growproc(n) < 0) {
    80003eb4:	fd842503          	lw	a0,-40(s0)
    80003eb8:	bfdfe0ef          	jal	80002ab4 <growproc>
    80003ebc:	00054e63          	bltz	a0,80003ed8 <sys_sbrk+0x9c>
  }
  return addr;
}
    80003ec0:	00048513          	mv	a0,s1
    80003ec4:	02813083          	ld	ra,40(sp)
    80003ec8:	02013403          	ld	s0,32(sp)
    80003ecc:	01813483          	ld	s1,24(sp)
    80003ed0:	03010113          	addi	sp,sp,48
    80003ed4:	00008067          	ret
      return -1;
    80003ed8:	fff00493          	li	s1,-1
    80003edc:	fe5ff06f          	j	80003ec0 <sys_sbrk+0x84>
      return -1;
    80003ee0:	fff00493          	li	s1,-1
    80003ee4:	fddff06f          	j	80003ec0 <sys_sbrk+0x84>

0000000080003ee8 <sys_pause>:

uint64
sys_pause(void)
{
    80003ee8:	fc010113          	addi	sp,sp,-64
    80003eec:	02113c23          	sd	ra,56(sp)
    80003ef0:	02813823          	sd	s0,48(sp)
    80003ef4:	04010413          	addi	s0,sp,64
  int n;
  uint ticks0;

  argint(0, &n);
    80003ef8:	fcc40593          	addi	a1,s0,-52
    80003efc:	00000513          	li	a0,0
    80003f00:	d41ff0ef          	jal	80003c40 <argint>
  if(n < 0)
    80003f04:	fcc42783          	lw	a5,-52(s0)
    80003f08:	0807c863          	bltz	a5,80003f98 <sys_pause+0xb0>
    n = 0;
  acquire(&tickslock);
    80003f0c:	00208517          	auipc	a0,0x208
    80003f10:	b9c50513          	addi	a0,a0,-1124 # 8020baa8 <tickslock>
    80003f14:	92cfd0ef          	jal	80001040 <acquire>
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    80003f18:	fcc42783          	lw	a5,-52(s0)
    80003f1c:	04078e63          	beqz	a5,80003f78 <sys_pause+0x90>
    80003f20:	02913423          	sd	s1,40(sp)
    80003f24:	03213023          	sd	s2,32(sp)
    80003f28:	01313c23          	sd	s3,24(sp)
  ticks0 = ticks;
    80003f2c:	001fa997          	auipc	s3,0x1fa
    80003f30:	c449a983          	lw	s3,-956(s3) # 801fdb70 <ticks>
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
    80003f34:	00208917          	auipc	s2,0x208
    80003f38:	b7490913          	addi	s2,s2,-1164 # 8020baa8 <tickslock>
    80003f3c:	001fa497          	auipc	s1,0x1fa
    80003f40:	c3448493          	addi	s1,s1,-972 # 801fdb70 <ticks>
    if(killed(myproc())){
    80003f44:	eb0fe0ef          	jal	800025f4 <myproc>
    80003f48:	af8ff0ef          	jal	80003240 <killed>
    80003f4c:	04051a63          	bnez	a0,80003fa0 <sys_pause+0xb8>
    sleep(&ticks, &tickslock);
    80003f50:	00090593          	mv	a1,s2
    80003f54:	00048513          	mv	a0,s1
    80003f58:	fa9fe0ef          	jal	80002f00 <sleep>
  while(ticks - ticks0 < n){
    80003f5c:	0004a783          	lw	a5,0(s1)
    80003f60:	413787bb          	subw	a5,a5,s3
    80003f64:	fcc42703          	lw	a4,-52(s0)
    80003f68:	fce7eee3          	bltu	a5,a4,80003f44 <sys_pause+0x5c>
    80003f6c:	02813483          	ld	s1,40(sp)
    80003f70:	02013903          	ld	s2,32(sp)
    80003f74:	01813983          	ld	s3,24(sp)
  }
  release(&tickslock);
    80003f78:	00208517          	auipc	a0,0x208
    80003f7c:	b3050513          	addi	a0,a0,-1232 # 8020baa8 <tickslock>
    80003f80:	998fd0ef          	jal	80001118 <release>
  return 0;
    80003f84:	00000513          	li	a0,0
}
    80003f88:	03813083          	ld	ra,56(sp)
    80003f8c:	03013403          	ld	s0,48(sp)
    80003f90:	04010113          	addi	sp,sp,64
    80003f94:	00008067          	ret
    n = 0;
    80003f98:	fc042623          	sw	zero,-52(s0)
    80003f9c:	f71ff06f          	j	80003f0c <sys_pause+0x24>
      release(&tickslock);
    80003fa0:	00208517          	auipc	a0,0x208
    80003fa4:	b0850513          	addi	a0,a0,-1272 # 8020baa8 <tickslock>
    80003fa8:	970fd0ef          	jal	80001118 <release>
      return -1;
    80003fac:	fff00513          	li	a0,-1
    80003fb0:	02813483          	ld	s1,40(sp)
    80003fb4:	02013903          	ld	s2,32(sp)
    80003fb8:	01813983          	ld	s3,24(sp)
    80003fbc:	fcdff06f          	j	80003f88 <sys_pause+0xa0>

0000000080003fc0 <sys_kill>:

uint64
sys_kill(void)
{
    80003fc0:	fe010113          	addi	sp,sp,-32
    80003fc4:	00113c23          	sd	ra,24(sp)
    80003fc8:	00813823          	sd	s0,16(sp)
    80003fcc:	02010413          	addi	s0,sp,32
  int pid;

  argint(0, &pid);
    80003fd0:	fec40593          	addi	a1,s0,-20
    80003fd4:	00000513          	li	a0,0
    80003fd8:	c69ff0ef          	jal	80003c40 <argint>
  return kkill(pid);
    80003fdc:	fec42503          	lw	a0,-20(s0)
    80003fe0:	980ff0ef          	jal	80003160 <kkill>
}
    80003fe4:	01813083          	ld	ra,24(sp)
    80003fe8:	01013403          	ld	s0,16(sp)
    80003fec:	02010113          	addi	sp,sp,32
    80003ff0:	00008067          	ret

0000000080003ff4 <sys_uptime>:

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
    80003ff4:	fe010113          	addi	sp,sp,-32
    80003ff8:	00113c23          	sd	ra,24(sp)
    80003ffc:	00813823          	sd	s0,16(sp)
    80004000:	00913423          	sd	s1,8(sp)
    80004004:	02010413          	addi	s0,sp,32
  uint xticks;

  acquire(&tickslock);
    80004008:	00208517          	auipc	a0,0x208
    8000400c:	aa050513          	addi	a0,a0,-1376 # 8020baa8 <tickslock>
    80004010:	830fd0ef          	jal	80001040 <acquire>
  xticks = ticks;
    80004014:	001fa797          	auipc	a5,0x1fa
    80004018:	b5c7a783          	lw	a5,-1188(a5) # 801fdb70 <ticks>
    8000401c:	00078493          	mv	s1,a5
  release(&tickslock);
    80004020:	00208517          	auipc	a0,0x208
    80004024:	a8850513          	addi	a0,a0,-1400 # 8020baa8 <tickslock>
    80004028:	8f0fd0ef          	jal	80001118 <release>
  return xticks;
}
    8000402c:	02049513          	slli	a0,s1,0x20
    80004030:	02055513          	srli	a0,a0,0x20
    80004034:	01813083          	ld	ra,24(sp)
    80004038:	01013403          	ld	s0,16(sp)
    8000403c:	00813483          	ld	s1,8(sp)
    80004040:	02010113          	addi	sp,sp,32
    80004044:	00008067          	ret

0000000080004048 <binit>:
  struct buf head;
} bcache;

void
binit(void)
{
    80004048:	fd010113          	addi	sp,sp,-48
    8000404c:	02113423          	sd	ra,40(sp)
    80004050:	02813023          	sd	s0,32(sp)
    80004054:	00913c23          	sd	s1,24(sp)
    80004058:	01213823          	sd	s2,16(sp)
    8000405c:	01313423          	sd	s3,8(sp)
    80004060:	01413023          	sd	s4,0(sp)
    80004064:	03010413          	addi	s0,sp,48
  struct buf *b;

  initlock(&bcache.lock, "bcache");
    80004068:	00005597          	auipc	a1,0x5
    8000406c:	6d058593          	addi	a1,a1,1744 # 80009738 <etext+0x738>
    80004070:	00208517          	auipc	a0,0x208
    80004074:	a5050513          	addi	a0,a0,-1456 # 8020bac0 <bcache>
    80004078:	ee5fc0ef          	jal	80000f5c <initlock>

  // Create linked list of buffers
  bcache.head.prev = &bcache.head;
    8000407c:	00210797          	auipc	a5,0x210
    80004080:	a4478793          	addi	a5,a5,-1468 # 80213ac0 <bcache+0x8000>
    80004084:	00210717          	auipc	a4,0x210
    80004088:	ca470713          	addi	a4,a4,-860 # 80213d28 <bcache+0x8268>
    8000408c:	2ae7b823          	sd	a4,688(a5)
  bcache.head.next = &bcache.head;
    80004090:	2ae7bc23          	sd	a4,696(a5)
  for(b = bcache.buf; b < bcache.buf+NBUF; b++){
    80004094:	00208497          	auipc	s1,0x208
    80004098:	a4448493          	addi	s1,s1,-1468 # 8020bad8 <bcache+0x18>
    b->next = bcache.head.next;
    8000409c:	00078913          	mv	s2,a5
    b->prev = &bcache.head;
    800040a0:	00070993          	mv	s3,a4
    initsleeplock(&b->lock, "buffer");
    800040a4:	00005a17          	auipc	s4,0x5
    800040a8:	69ca0a13          	addi	s4,s4,1692 # 80009740 <etext+0x740>
    b->next = bcache.head.next;
    800040ac:	2b893783          	ld	a5,696(s2)
    800040b0:	04f4b823          	sd	a5,80(s1)
    b->prev = &bcache.head;
    800040b4:	0534b423          	sd	s3,72(s1)
    initsleeplock(&b->lock, "buffer");
    800040b8:	000a0593          	mv	a1,s4
    800040bc:	01048513          	addi	a0,s1,16
    800040c0:	3fd010ef          	jal	80005cbc <initsleeplock>
    bcache.head.next->prev = b;
    800040c4:	2b893783          	ld	a5,696(s2)
    800040c8:	0497b423          	sd	s1,72(a5)
    bcache.head.next = b;
    800040cc:	2a993c23          	sd	s1,696(s2)
  for(b = bcache.buf; b < bcache.buf+NBUF; b++){
    800040d0:	45848493          	addi	s1,s1,1112
    800040d4:	fd349ce3          	bne	s1,s3,800040ac <binit+0x64>
  }
}
    800040d8:	02813083          	ld	ra,40(sp)
    800040dc:	02013403          	ld	s0,32(sp)
    800040e0:	01813483          	ld	s1,24(sp)
    800040e4:	01013903          	ld	s2,16(sp)
    800040e8:	00813983          	ld	s3,8(sp)
    800040ec:	00013a03          	ld	s4,0(sp)
    800040f0:	03010113          	addi	sp,sp,48
    800040f4:	00008067          	ret

00000000800040f8 <bread>:
}

// Return a locked buf with the contents of the indicated block.
struct buf*
bread(uint dev, uint blockno)
{
    800040f8:	fd010113          	addi	sp,sp,-48
    800040fc:	02113423          	sd	ra,40(sp)
    80004100:	02813023          	sd	s0,32(sp)
    80004104:	00913c23          	sd	s1,24(sp)
    80004108:	01213823          	sd	s2,16(sp)
    8000410c:	01313423          	sd	s3,8(sp)
    80004110:	03010413          	addi	s0,sp,48
    80004114:	00050913          	mv	s2,a0
    80004118:	00058993          	mv	s3,a1
  acquire(&bcache.lock);
    8000411c:	00208517          	auipc	a0,0x208
    80004120:	9a450513          	addi	a0,a0,-1628 # 8020bac0 <bcache>
    80004124:	f1dfc0ef          	jal	80001040 <acquire>
  for(b = bcache.head.next; b != &bcache.head; b = b->next){
    80004128:	00210497          	auipc	s1,0x210
    8000412c:	c504b483          	ld	s1,-944(s1) # 80213d78 <bcache+0x82b8>
    80004130:	00210797          	auipc	a5,0x210
    80004134:	bf878793          	addi	a5,a5,-1032 # 80213d28 <bcache+0x8268>
    80004138:	04f48463          	beq	s1,a5,80004180 <bread+0x88>
    8000413c:	00078713          	mv	a4,a5
    80004140:	00c0006f          	j	8000414c <bread+0x54>
    80004144:	0504b483          	ld	s1,80(s1)
    80004148:	02e48c63          	beq	s1,a4,80004180 <bread+0x88>
    if(b->dev == dev && b->blockno == blockno){
    8000414c:	0084a783          	lw	a5,8(s1)
    80004150:	ff279ae3          	bne	a5,s2,80004144 <bread+0x4c>
    80004154:	00c4a783          	lw	a5,12(s1)
    80004158:	ff3796e3          	bne	a5,s3,80004144 <bread+0x4c>
      b->refcnt++;
    8000415c:	0404a783          	lw	a5,64(s1)
    80004160:	0017879b          	addiw	a5,a5,1
    80004164:	04f4a023          	sw	a5,64(s1)
      release(&bcache.lock);
    80004168:	00208517          	auipc	a0,0x208
    8000416c:	95850513          	addi	a0,a0,-1704 # 8020bac0 <bcache>
    80004170:	fa9fc0ef          	jal	80001118 <release>
      acquiresleep(&b->lock);
    80004174:	01048513          	addi	a0,s1,16
    80004178:	399010ef          	jal	80005d10 <acquiresleep>
      return b;
    8000417c:	0600006f          	j	800041dc <bread+0xe4>
  for(b = bcache.head.prev; b != &bcache.head; b = b->prev){
    80004180:	00210497          	auipc	s1,0x210
    80004184:	bf04b483          	ld	s1,-1040(s1) # 80213d70 <bcache+0x82b0>
    80004188:	00210797          	auipc	a5,0x210
    8000418c:	ba078793          	addi	a5,a5,-1120 # 80213d28 <bcache+0x8268>
    80004190:	00f48c63          	beq	s1,a5,800041a8 <bread+0xb0>
    80004194:	00078713          	mv	a4,a5
    if(b->refcnt == 0) {
    80004198:	0404a783          	lw	a5,64(s1)
    8000419c:	00078c63          	beqz	a5,800041b4 <bread+0xbc>
  for(b = bcache.head.prev; b != &bcache.head; b = b->prev){
    800041a0:	0484b483          	ld	s1,72(s1)
    800041a4:	fee49ae3          	bne	s1,a4,80004198 <bread+0xa0>
  panic("bget: no buffers");
    800041a8:	00005517          	auipc	a0,0x5
    800041ac:	5a050513          	addi	a0,a0,1440 # 80009748 <etext+0x748>
    800041b0:	93dfc0ef          	jal	80000aec <panic>
      b->dev = dev;
    800041b4:	0124a423          	sw	s2,8(s1)
      b->blockno = blockno;
    800041b8:	0134a623          	sw	s3,12(s1)
      b->valid = 0;
    800041bc:	0004a023          	sw	zero,0(s1)
      b->refcnt = 1;
    800041c0:	00100793          	li	a5,1
    800041c4:	04f4a023          	sw	a5,64(s1)
      release(&bcache.lock);
    800041c8:	00208517          	auipc	a0,0x208
    800041cc:	8f850513          	addi	a0,a0,-1800 # 8020bac0 <bcache>
    800041d0:	f49fc0ef          	jal	80001118 <release>
      acquiresleep(&b->lock);
    800041d4:	01048513          	addi	a0,s1,16
    800041d8:	339010ef          	jal	80005d10 <acquiresleep>
  struct buf *b;

  b = bget(dev, blockno);
  if(!b->valid) {
    800041dc:	0004a783          	lw	a5,0(s1)
    800041e0:	02078263          	beqz	a5,80004204 <bread+0x10c>
    virtio_disk_rw(b, 0);
    b->valid = 1;
  }
  return b;
}
    800041e4:	00048513          	mv	a0,s1
    800041e8:	02813083          	ld	ra,40(sp)
    800041ec:	02013403          	ld	s0,32(sp)
    800041f0:	01813483          	ld	s1,24(sp)
    800041f4:	01013903          	ld	s2,16(sp)
    800041f8:	00813983          	ld	s3,8(sp)
    800041fc:	03010113          	addi	sp,sp,48
    80004200:	00008067          	ret
    virtio_disk_rw(b, 0);
    80004204:	00000593          	li	a1,0
    80004208:	00048513          	mv	a0,s1
    8000420c:	3f5030ef          	jal	80007e00 <virtio_disk_rw>
    b->valid = 1;
    80004210:	00100793          	li	a5,1
    80004214:	00f4a023          	sw	a5,0(s1)
  return b;
    80004218:	fcdff06f          	j	800041e4 <bread+0xec>

000000008000421c <bwrite>:

// Write b's contents to disk.  Must be locked.
void
bwrite(struct buf *b)
{
    8000421c:	fe010113          	addi	sp,sp,-32
    80004220:	00113c23          	sd	ra,24(sp)
    80004224:	00813823          	sd	s0,16(sp)
    80004228:	00913423          	sd	s1,8(sp)
    8000422c:	02010413          	addi	s0,sp,32
    80004230:	00050493          	mv	s1,a0
  if(!holdingsleep(&b->lock))
    80004234:	01050513          	addi	a0,a0,16
    80004238:	3a9010ef          	jal	80005de0 <holdingsleep>
    8000423c:	02050263          	beqz	a0,80004260 <bwrite+0x44>
    panic("bwrite");
  virtio_disk_rw(b, 1);
    80004240:	00100593          	li	a1,1
    80004244:	00048513          	mv	a0,s1
    80004248:	3b9030ef          	jal	80007e00 <virtio_disk_rw>
}
    8000424c:	01813083          	ld	ra,24(sp)
    80004250:	01013403          	ld	s0,16(sp)
    80004254:	00813483          	ld	s1,8(sp)
    80004258:	02010113          	addi	sp,sp,32
    8000425c:	00008067          	ret
    panic("bwrite");
    80004260:	00005517          	auipc	a0,0x5
    80004264:	50050513          	addi	a0,a0,1280 # 80009760 <etext+0x760>
    80004268:	885fc0ef          	jal	80000aec <panic>

000000008000426c <brelse>:

// Release a locked buffer.
// Move to the head of the most-recently-used list.
void
brelse(struct buf *b)
{
    8000426c:	fe010113          	addi	sp,sp,-32
    80004270:	00113c23          	sd	ra,24(sp)
    80004274:	00813823          	sd	s0,16(sp)
    80004278:	00913423          	sd	s1,8(sp)
    8000427c:	01213023          	sd	s2,0(sp)
    80004280:	02010413          	addi	s0,sp,32
    80004284:	00050493          	mv	s1,a0
  if(!holdingsleep(&b->lock))
    80004288:	01050913          	addi	s2,a0,16
    8000428c:	00090513          	mv	a0,s2
    80004290:	351010ef          	jal	80005de0 <holdingsleep>
    80004294:	08050463          	beqz	a0,8000431c <brelse+0xb0>
    panic("brelse");

  releasesleep(&b->lock);
    80004298:	00090513          	mv	a0,s2
    8000429c:	2ed010ef          	jal	80005d88 <releasesleep>

  acquire(&bcache.lock);
    800042a0:	00208517          	auipc	a0,0x208
    800042a4:	82050513          	addi	a0,a0,-2016 # 8020bac0 <bcache>
    800042a8:	d99fc0ef          	jal	80001040 <acquire>
  b->refcnt--;
    800042ac:	0404a783          	lw	a5,64(s1)
    800042b0:	fff7879b          	addiw	a5,a5,-1
    800042b4:	04f4a023          	sw	a5,64(s1)
  if (b->refcnt == 0) {
    800042b8:	04079063          	bnez	a5,800042f8 <brelse+0x8c>
    // no one is waiting for it.
    b->next->prev = b->prev;
    800042bc:	0504b703          	ld	a4,80(s1)
    800042c0:	0484b783          	ld	a5,72(s1)
    800042c4:	04f73423          	sd	a5,72(a4)
    b->prev->next = b->next;
    800042c8:	0504b703          	ld	a4,80(s1)
    800042cc:	04e7b823          	sd	a4,80(a5)
    b->next = bcache.head.next;
    800042d0:	0020f797          	auipc	a5,0x20f
    800042d4:	7f078793          	addi	a5,a5,2032 # 80213ac0 <bcache+0x8000>
    800042d8:	2b87b703          	ld	a4,696(a5)
    800042dc:	04e4b823          	sd	a4,80(s1)
    b->prev = &bcache.head;
    800042e0:	00210717          	auipc	a4,0x210
    800042e4:	a4870713          	addi	a4,a4,-1464 # 80213d28 <bcache+0x8268>
    800042e8:	04e4b423          	sd	a4,72(s1)
    bcache.head.next->prev = b;
    800042ec:	2b87b703          	ld	a4,696(a5)
    800042f0:	04973423          	sd	s1,72(a4)
    bcache.head.next = b;
    800042f4:	2a97bc23          	sd	s1,696(a5)
  }
  
  release(&bcache.lock);
    800042f8:	00207517          	auipc	a0,0x207
    800042fc:	7c850513          	addi	a0,a0,1992 # 8020bac0 <bcache>
    80004300:	e19fc0ef          	jal	80001118 <release>
}
    80004304:	01813083          	ld	ra,24(sp)
    80004308:	01013403          	ld	s0,16(sp)
    8000430c:	00813483          	ld	s1,8(sp)
    80004310:	00013903          	ld	s2,0(sp)
    80004314:	02010113          	addi	sp,sp,32
    80004318:	00008067          	ret
    panic("brelse");
    8000431c:	00005517          	auipc	a0,0x5
    80004320:	44c50513          	addi	a0,a0,1100 # 80009768 <etext+0x768>
    80004324:	fc8fc0ef          	jal	80000aec <panic>

0000000080004328 <bpin>:

void
bpin(struct buf *b) {
    80004328:	fe010113          	addi	sp,sp,-32
    8000432c:	00113c23          	sd	ra,24(sp)
    80004330:	00813823          	sd	s0,16(sp)
    80004334:	00913423          	sd	s1,8(sp)
    80004338:	02010413          	addi	s0,sp,32
    8000433c:	00050493          	mv	s1,a0
  acquire(&bcache.lock);
    80004340:	00207517          	auipc	a0,0x207
    80004344:	78050513          	addi	a0,a0,1920 # 8020bac0 <bcache>
    80004348:	cf9fc0ef          	jal	80001040 <acquire>
  b->refcnt++;
    8000434c:	0404a783          	lw	a5,64(s1)
    80004350:	0017879b          	addiw	a5,a5,1
    80004354:	04f4a023          	sw	a5,64(s1)
  release(&bcache.lock);
    80004358:	00207517          	auipc	a0,0x207
    8000435c:	76850513          	addi	a0,a0,1896 # 8020bac0 <bcache>
    80004360:	db9fc0ef          	jal	80001118 <release>
}
    80004364:	01813083          	ld	ra,24(sp)
    80004368:	01013403          	ld	s0,16(sp)
    8000436c:	00813483          	ld	s1,8(sp)
    80004370:	02010113          	addi	sp,sp,32
    80004374:	00008067          	ret

0000000080004378 <bunpin>:

void
bunpin(struct buf *b) {
    80004378:	fe010113          	addi	sp,sp,-32
    8000437c:	00113c23          	sd	ra,24(sp)
    80004380:	00813823          	sd	s0,16(sp)
    80004384:	00913423          	sd	s1,8(sp)
    80004388:	02010413          	addi	s0,sp,32
    8000438c:	00050493          	mv	s1,a0
  acquire(&bcache.lock);
    80004390:	00207517          	auipc	a0,0x207
    80004394:	73050513          	addi	a0,a0,1840 # 8020bac0 <bcache>
    80004398:	ca9fc0ef          	jal	80001040 <acquire>
  b->refcnt--;
    8000439c:	0404a783          	lw	a5,64(s1)
    800043a0:	fff7879b          	addiw	a5,a5,-1
    800043a4:	04f4a023          	sw	a5,64(s1)
  release(&bcache.lock);
    800043a8:	00207517          	auipc	a0,0x207
    800043ac:	71850513          	addi	a0,a0,1816 # 8020bac0 <bcache>
    800043b0:	d69fc0ef          	jal	80001118 <release>
}
    800043b4:	01813083          	ld	ra,24(sp)
    800043b8:	01013403          	ld	s0,16(sp)
    800043bc:	00813483          	ld	s1,8(sp)
    800043c0:	02010113          	addi	sp,sp,32
    800043c4:	00008067          	ret

00000000800043c8 <bfree>:
}

// Free a disk block.
static void
bfree(int dev, uint b)
{
    800043c8:	fe010113          	addi	sp,sp,-32
    800043cc:	00113c23          	sd	ra,24(sp)
    800043d0:	00813823          	sd	s0,16(sp)
    800043d4:	00913423          	sd	s1,8(sp)
    800043d8:	01213023          	sd	s2,0(sp)
    800043dc:	02010413          	addi	s0,sp,32
    800043e0:	00058493          	mv	s1,a1
  struct buf *bp;
  int bi, m;

  bp = bread(dev, BBLOCK(b, sb));
    800043e4:	00d5d79b          	srliw	a5,a1,0xd
    800043e8:	00210597          	auipc	a1,0x210
    800043ec:	db45a583          	lw	a1,-588(a1) # 8021419c <sb+0x1c>
    800043f0:	00f585bb          	addw	a1,a1,a5
    800043f4:	d05ff0ef          	jal	800040f8 <bread>
  bi = b % BPB;
  m = 1 << (bi % 8);
    800043f8:	0074f713          	andi	a4,s1,7
    800043fc:	00100793          	li	a5,1
    80004400:	00e797bb          	sllw	a5,a5,a4
  bi = b % BPB;
    80004404:	03349493          	slli	s1,s1,0x33
  if ((bp->data[bi / 8] & m) == 0)
    80004408:	0364d493          	srli	s1,s1,0x36
    8000440c:	00950733          	add	a4,a0,s1
    80004410:	05874703          	lbu	a4,88(a4)
    80004414:	00e7f6b3          	and	a3,a5,a4
    80004418:	02068e63          	beqz	a3,80004454 <bfree+0x8c>
    8000441c:	00050913          	mv	s2,a0
    panic("freeing free block");
  bp->data[bi / 8] &= ~m;
    80004420:	009504b3          	add	s1,a0,s1
    80004424:	fff7c793          	not	a5,a5
    80004428:	00f77733          	and	a4,a4,a5
    8000442c:	04e48c23          	sb	a4,88(s1)
  log_write(bp);
    80004430:	78c010ef          	jal	80005bbc <log_write>
  brelse(bp);
    80004434:	00090513          	mv	a0,s2
    80004438:	e35ff0ef          	jal	8000426c <brelse>
}
    8000443c:	01813083          	ld	ra,24(sp)
    80004440:	01013403          	ld	s0,16(sp)
    80004444:	00813483          	ld	s1,8(sp)
    80004448:	00013903          	ld	s2,0(sp)
    8000444c:	02010113          	addi	sp,sp,32
    80004450:	00008067          	ret
    panic("freeing free block");
    80004454:	00005517          	auipc	a0,0x5
    80004458:	31c50513          	addi	a0,a0,796 # 80009770 <etext+0x770>
    8000445c:	e90fc0ef          	jal	80000aec <panic>

0000000080004460 <balloc>:
{
    80004460:	fb010113          	addi	sp,sp,-80
    80004464:	04113423          	sd	ra,72(sp)
    80004468:	04813023          	sd	s0,64(sp)
    8000446c:	02913c23          	sd	s1,56(sp)
    80004470:	05010413          	addi	s0,sp,80
  for (b = 0; b < sb.size; b += BPB)
    80004474:	00210797          	auipc	a5,0x210
    80004478:	d107a783          	lw	a5,-752(a5) # 80214184 <sb+0x4>
    8000447c:	14078863          	beqz	a5,800045cc <balloc+0x16c>
    80004480:	03213823          	sd	s2,48(sp)
    80004484:	03313423          	sd	s3,40(sp)
    80004488:	03413023          	sd	s4,32(sp)
    8000448c:	01513c23          	sd	s5,24(sp)
    80004490:	01613823          	sd	s6,16(sp)
    80004494:	01713423          	sd	s7,8(sp)
    80004498:	01813023          	sd	s8,0(sp)
    8000449c:	00050b93          	mv	s7,a0
    800044a0:	00000a93          	li	s5,0
    bp = bread(dev, BBLOCK(b, sb));
    800044a4:	00210b17          	auipc	s6,0x210
    800044a8:	cdcb0b13          	addi	s6,s6,-804 # 80214180 <sb>
      m = 1 << (bi % 8);
    800044ac:	00100993          	li	s3,1
    for (bi = 0; bi < BPB && b + bi < sb.size; bi++)
    800044b0:	00002a37          	lui	s4,0x2
  for (b = 0; b < sb.size; b += BPB)
    800044b4:	00002c37          	lui	s8,0x2
    800044b8:	0980006f          	j	80004550 <balloc+0xf0>
        bp->data[bi / 8] |= m; // Mark block in use.
    800044bc:	00f907b3          	add	a5,s2,a5
    800044c0:	00d66633          	or	a2,a2,a3
    800044c4:	04c78c23          	sb	a2,88(a5)
        log_write(bp);
    800044c8:	00090513          	mv	a0,s2
    800044cc:	6f0010ef          	jal	80005bbc <log_write>
        brelse(bp);
    800044d0:	00090513          	mv	a0,s2
    800044d4:	d99ff0ef          	jal	8000426c <brelse>
  bp = bread(dev, bno);
    800044d8:	00048593          	mv	a1,s1
    800044dc:	000b8513          	mv	a0,s7
    800044e0:	c19ff0ef          	jal	800040f8 <bread>
    800044e4:	00050913          	mv	s2,a0
  memset(bp->data, 0, BSIZE);
    800044e8:	40000613          	li	a2,1024
    800044ec:	00000593          	li	a1,0
    800044f0:	05850513          	addi	a0,a0,88
    800044f4:	ce9fc0ef          	jal	800011dc <memset>
  log_write(bp);
    800044f8:	00090513          	mv	a0,s2
    800044fc:	6c0010ef          	jal	80005bbc <log_write>
  brelse(bp);
    80004500:	00090513          	mv	a0,s2
    80004504:	d69ff0ef          	jal	8000426c <brelse>
}
    80004508:	03013903          	ld	s2,48(sp)
    8000450c:	02813983          	ld	s3,40(sp)
    80004510:	02013a03          	ld	s4,32(sp)
    80004514:	01813a83          	ld	s5,24(sp)
    80004518:	01013b03          	ld	s6,16(sp)
    8000451c:	00813b83          	ld	s7,8(sp)
    80004520:	00013c03          	ld	s8,0(sp)
}
    80004524:	00048513          	mv	a0,s1
    80004528:	04813083          	ld	ra,72(sp)
    8000452c:	04013403          	ld	s0,64(sp)
    80004530:	03813483          	ld	s1,56(sp)
    80004534:	05010113          	addi	sp,sp,80
    80004538:	00008067          	ret
    brelse(bp);
    8000453c:	00090513          	mv	a0,s2
    80004540:	d2dff0ef          	jal	8000426c <brelse>
  for (b = 0; b < sb.size; b += BPB)
    80004544:	015c0abb          	addw	s5,s8,s5
    80004548:	004b2783          	lw	a5,4(s6)
    8000454c:	06faf263          	bgeu	s5,a5,800045b0 <balloc+0x150>
    bp = bread(dev, BBLOCK(b, sb));
    80004550:	40dad59b          	sraiw	a1,s5,0xd
    80004554:	01cb2783          	lw	a5,28(s6)
    80004558:	00b785bb          	addw	a1,a5,a1
    8000455c:	000b8513          	mv	a0,s7
    80004560:	b99ff0ef          	jal	800040f8 <bread>
    80004564:	00050913          	mv	s2,a0
    for (bi = 0; bi < BPB && b + bi < sb.size; bi++)
    80004568:	004b2503          	lw	a0,4(s6)
    8000456c:	000a8493          	mv	s1,s5
    80004570:	00000713          	li	a4,0
    80004574:	fca4f4e3          	bgeu	s1,a0,8000453c <balloc+0xdc>
      m = 1 << (bi % 8);
    80004578:	00777693          	andi	a3,a4,7
    8000457c:	00d996bb          	sllw	a3,s3,a3
      if ((bp->data[bi / 8] & m) == 0)
    80004580:	41f7579b          	sraiw	a5,a4,0x1f
    80004584:	01d7d79b          	srliw	a5,a5,0x1d
    80004588:	00e787bb          	addw	a5,a5,a4
    8000458c:	4037d79b          	sraiw	a5,a5,0x3
    80004590:	00f90633          	add	a2,s2,a5
    80004594:	05864603          	lbu	a2,88(a2)
    80004598:	00c6f5b3          	and	a1,a3,a2
    8000459c:	f20580e3          	beqz	a1,800044bc <balloc+0x5c>
    for (bi = 0; bi < BPB && b + bi < sb.size; bi++)
    800045a0:	0017071b          	addiw	a4,a4,1
    800045a4:	0014849b          	addiw	s1,s1,1
    800045a8:	fd4716e3          	bne	a4,s4,80004574 <balloc+0x114>
    800045ac:	f91ff06f          	j	8000453c <balloc+0xdc>
    800045b0:	03013903          	ld	s2,48(sp)
    800045b4:	02813983          	ld	s3,40(sp)
    800045b8:	02013a03          	ld	s4,32(sp)
    800045bc:	01813a83          	ld	s5,24(sp)
    800045c0:	01013b03          	ld	s6,16(sp)
    800045c4:	00813b83          	ld	s7,8(sp)
    800045c8:	00013c03          	ld	s8,0(sp)
  printf("balloc: out of blocks\n");
    800045cc:	00005517          	auipc	a0,0x5
    800045d0:	1bc50513          	addi	a0,a0,444 # 80009788 <etext+0x788>
    800045d4:	8f8fc0ef          	jal	800006cc <printf>
  return 0;
    800045d8:	00000493          	li	s1,0
    800045dc:	f49ff06f          	j	80004524 <balloc+0xc4>

00000000800045e0 <bmap>:
// Return the disk block address of the nth block in inode ip.
// If there is no such block, bmap allocates one.
// returns 0 if out of disk space.
static uint
bmap(struct inode *ip, uint bn)
{
    800045e0:	fd010113          	addi	sp,sp,-48
    800045e4:	02113423          	sd	ra,40(sp)
    800045e8:	02813023          	sd	s0,32(sp)
    800045ec:	00913c23          	sd	s1,24(sp)
    800045f0:	01213823          	sd	s2,16(sp)
    800045f4:	01313423          	sd	s3,8(sp)
    800045f8:	03010413          	addi	s0,sp,48
    800045fc:	00050913          	mv	s2,a0
  uint addr, *a;
  struct buf *bp;

  if (bn < NDIRECT)
    80004600:	00b00793          	li	a5,11
    80004604:	02b7ea63          	bltu	a5,a1,80004638 <bmap+0x58>
  {
    if ((addr = ip->addrs[bn]) == 0)
    80004608:	02059793          	slli	a5,a1,0x20
    8000460c:	01e7d593          	srli	a1,a5,0x1e
    80004610:	00b507b3          	add	a5,a0,a1
    80004614:	00078993          	mv	s3,a5
    80004618:	0507a483          	lw	s1,80(a5)
    8000461c:	08049663          	bnez	s1,800046a8 <bmap+0xc8>
    {
      addr = balloc(ip->dev);
    80004620:	00052503          	lw	a0,0(a0)
    80004624:	e3dff0ef          	jal	80004460 <balloc>
    80004628:	00050493          	mv	s1,a0
      if (addr == 0)
    8000462c:	06050e63          	beqz	a0,800046a8 <bmap+0xc8>
        return 0;
      ip->addrs[bn] = addr;
    80004630:	04a9a823          	sw	a0,80(s3)
    80004634:	0740006f          	j	800046a8 <bmap+0xc8>
    }
    return addr;
  }
  bn -= NDIRECT;
    80004638:	ff45879b          	addiw	a5,a1,-12
    8000463c:	00078993          	mv	s3,a5

  if (bn < NINDIRECT)
    80004640:	0ff00793          	li	a5,255
    80004644:	0b37e263          	bltu	a5,s3,800046e8 <bmap+0x108>
  {
    // Load indirect block, allocating if necessary.
    if ((addr = ip->addrs[NDIRECT]) == 0)
    80004648:	08052483          	lw	s1,128(a0)
    8000464c:	02049063          	bnez	s1,8000466c <bmap+0x8c>
    {
      addr = balloc(ip->dev);
    80004650:	00052503          	lw	a0,0(a0)
    80004654:	e0dff0ef          	jal	80004460 <balloc>
    80004658:	00050493          	mv	s1,a0
      if (addr == 0)
    8000465c:	04050663          	beqz	a0,800046a8 <bmap+0xc8>
    80004660:	01413023          	sd	s4,0(sp)
        return 0;
      ip->addrs[NDIRECT] = addr;
    80004664:	08a92023          	sw	a0,128(s2)
    80004668:	0080006f          	j	80004670 <bmap+0x90>
    8000466c:	01413023          	sd	s4,0(sp)
    }
    bp = bread(ip->dev, addr);
    80004670:	00048593          	mv	a1,s1
    80004674:	00092503          	lw	a0,0(s2)
    80004678:	a81ff0ef          	jal	800040f8 <bread>
    8000467c:	00050a13          	mv	s4,a0
    a = (uint *)bp->data;
    80004680:	05850793          	addi	a5,a0,88
    if ((addr = a[bn]) == 0)
    80004684:	02099713          	slli	a4,s3,0x20
    80004688:	01e75593          	srli	a1,a4,0x1e
    8000468c:	00b787b3          	add	a5,a5,a1
    80004690:	00078993          	mv	s3,a5
    80004694:	0007a483          	lw	s1,0(a5)
    80004698:	02048863          	beqz	s1,800046c8 <bmap+0xe8>
      {
        a[bn] = addr;
        log_write(bp);
      }
    }
    brelse(bp);
    8000469c:	000a0513          	mv	a0,s4
    800046a0:	bcdff0ef          	jal	8000426c <brelse>
    return addr;
    800046a4:	00013a03          	ld	s4,0(sp)
  }

  panic("bmap: out of range");
}
    800046a8:	00048513          	mv	a0,s1
    800046ac:	02813083          	ld	ra,40(sp)
    800046b0:	02013403          	ld	s0,32(sp)
    800046b4:	01813483          	ld	s1,24(sp)
    800046b8:	01013903          	ld	s2,16(sp)
    800046bc:	00813983          	ld	s3,8(sp)
    800046c0:	03010113          	addi	sp,sp,48
    800046c4:	00008067          	ret
      addr = balloc(ip->dev);
    800046c8:	00092503          	lw	a0,0(s2)
    800046cc:	d95ff0ef          	jal	80004460 <balloc>
    800046d0:	00050493          	mv	s1,a0
      if (addr)
    800046d4:	fc0504e3          	beqz	a0,8000469c <bmap+0xbc>
        a[bn] = addr;
    800046d8:	00a9a023          	sw	a0,0(s3)
        log_write(bp);
    800046dc:	000a0513          	mv	a0,s4
    800046e0:	4dc010ef          	jal	80005bbc <log_write>
    800046e4:	fb9ff06f          	j	8000469c <bmap+0xbc>
    800046e8:	01413023          	sd	s4,0(sp)
  panic("bmap: out of range");
    800046ec:	00005517          	auipc	a0,0x5
    800046f0:	0b450513          	addi	a0,a0,180 # 800097a0 <etext+0x7a0>
    800046f4:	bf8fc0ef          	jal	80000aec <panic>

00000000800046f8 <iget>:
{
    800046f8:	fd010113          	addi	sp,sp,-48
    800046fc:	02113423          	sd	ra,40(sp)
    80004700:	02813023          	sd	s0,32(sp)
    80004704:	00913c23          	sd	s1,24(sp)
    80004708:	01213823          	sd	s2,16(sp)
    8000470c:	01313423          	sd	s3,8(sp)
    80004710:	01413023          	sd	s4,0(sp)
    80004714:	03010413          	addi	s0,sp,48
    80004718:	00050913          	mv	s2,a0
    8000471c:	00058a13          	mv	s4,a1
  acquire(&itable.lock);
    80004720:	00210517          	auipc	a0,0x210
    80004724:	a8050513          	addi	a0,a0,-1408 # 802141a0 <itable>
    80004728:	919fc0ef          	jal	80001040 <acquire>
  empty = 0;
    8000472c:	00000993          	li	s3,0
  for (ip = &itable.inode[0]; ip < &itable.inode[NINODE]; ip++)
    80004730:	00210497          	auipc	s1,0x210
    80004734:	a8848493          	addi	s1,s1,-1400 # 802141b8 <itable+0x18>
    80004738:	00211697          	auipc	a3,0x211
    8000473c:	51068693          	addi	a3,a3,1296 # 80215c48 <log>
    80004740:	0180006f          	j	80004758 <iget+0x60>
    if (empty == 0 && ip->ref == 0) // Remember empty slot.
    80004744:	00079663          	bnez	a5,80004750 <iget+0x58>
    80004748:	00099463          	bnez	s3,80004750 <iget+0x58>
      empty = ip;
    8000474c:	00048993          	mv	s3,s1
  for (ip = &itable.inode[0]; ip < &itable.inode[NINODE]; ip++)
    80004750:	08848493          	addi	s1,s1,136
    80004754:	02d48c63          	beq	s1,a3,8000478c <iget+0x94>
    if (ip->ref > 0 && ip->dev == dev && ip->inum == inum)
    80004758:	0084a783          	lw	a5,8(s1)
    8000475c:	fef054e3          	blez	a5,80004744 <iget+0x4c>
    80004760:	0004a703          	lw	a4,0(s1)
    80004764:	ff2716e3          	bne	a4,s2,80004750 <iget+0x58>
    80004768:	0044a703          	lw	a4,4(s1)
    8000476c:	ff4712e3          	bne	a4,s4,80004750 <iget+0x58>
      ip->ref++;
    80004770:	0017879b          	addiw	a5,a5,1
    80004774:	00f4a423          	sw	a5,8(s1)
      release(&itable.lock);
    80004778:	00210517          	auipc	a0,0x210
    8000477c:	a2850513          	addi	a0,a0,-1496 # 802141a0 <itable>
    80004780:	999fc0ef          	jal	80001118 <release>
      return ip;
    80004784:	00048993          	mv	s3,s1
    80004788:	0280006f          	j	800047b0 <iget+0xb8>
  if (empty == 0)
    8000478c:	04098463          	beqz	s3,800047d4 <iget+0xdc>
  ip->dev = dev;
    80004790:	0129a023          	sw	s2,0(s3)
  ip->inum = inum;
    80004794:	0149a223          	sw	s4,4(s3)
  ip->ref = 1;
    80004798:	00100793          	li	a5,1
    8000479c:	00f9a423          	sw	a5,8(s3)
  ip->valid = 0;
    800047a0:	0409a023          	sw	zero,64(s3)
  release(&itable.lock);
    800047a4:	00210517          	auipc	a0,0x210
    800047a8:	9fc50513          	addi	a0,a0,-1540 # 802141a0 <itable>
    800047ac:	96dfc0ef          	jal	80001118 <release>
}
    800047b0:	00098513          	mv	a0,s3
    800047b4:	02813083          	ld	ra,40(sp)
    800047b8:	02013403          	ld	s0,32(sp)
    800047bc:	01813483          	ld	s1,24(sp)
    800047c0:	01013903          	ld	s2,16(sp)
    800047c4:	00813983          	ld	s3,8(sp)
    800047c8:	00013a03          	ld	s4,0(sp)
    800047cc:	03010113          	addi	sp,sp,48
    800047d0:	00008067          	ret
    panic("iget: no inodes");
    800047d4:	00005517          	auipc	a0,0x5
    800047d8:	fe450513          	addi	a0,a0,-28 # 800097b8 <etext+0x7b8>
    800047dc:	b10fc0ef          	jal	80000aec <panic>

00000000800047e0 <iinit>:
{
    800047e0:	fd010113          	addi	sp,sp,-48
    800047e4:	02113423          	sd	ra,40(sp)
    800047e8:	02813023          	sd	s0,32(sp)
    800047ec:	00913c23          	sd	s1,24(sp)
    800047f0:	01213823          	sd	s2,16(sp)
    800047f4:	01313423          	sd	s3,8(sp)
    800047f8:	03010413          	addi	s0,sp,48
  initlock(&itable.lock, "itable");
    800047fc:	00005597          	auipc	a1,0x5
    80004800:	fcc58593          	addi	a1,a1,-52 # 800097c8 <etext+0x7c8>
    80004804:	00210517          	auipc	a0,0x210
    80004808:	99c50513          	addi	a0,a0,-1636 # 802141a0 <itable>
    8000480c:	f50fc0ef          	jal	80000f5c <initlock>
  for (i = 0; i < NINODE; i++)
    80004810:	00210497          	auipc	s1,0x210
    80004814:	9b848493          	addi	s1,s1,-1608 # 802141c8 <itable+0x28>
    80004818:	00211997          	auipc	s3,0x211
    8000481c:	44098993          	addi	s3,s3,1088 # 80215c58 <log+0x10>
    initsleeplock(&itable.inode[i].lock, "inode");
    80004820:	00005917          	auipc	s2,0x5
    80004824:	fb090913          	addi	s2,s2,-80 # 800097d0 <etext+0x7d0>
    80004828:	00090593          	mv	a1,s2
    8000482c:	00048513          	mv	a0,s1
    80004830:	48c010ef          	jal	80005cbc <initsleeplock>
  for (i = 0; i < NINODE; i++)
    80004834:	08848493          	addi	s1,s1,136
    80004838:	ff3498e3          	bne	s1,s3,80004828 <iinit+0x48>
}
    8000483c:	02813083          	ld	ra,40(sp)
    80004840:	02013403          	ld	s0,32(sp)
    80004844:	01813483          	ld	s1,24(sp)
    80004848:	01013903          	ld	s2,16(sp)
    8000484c:	00813983          	ld	s3,8(sp)
    80004850:	03010113          	addi	sp,sp,48
    80004854:	00008067          	ret

0000000080004858 <ialloc>:
{
    80004858:	fc010113          	addi	sp,sp,-64
    8000485c:	02113c23          	sd	ra,56(sp)
    80004860:	02813823          	sd	s0,48(sp)
    80004864:	04010413          	addi	s0,sp,64
  for (inum = 1; inum < sb.ninodes; inum++)
    80004868:	00210717          	auipc	a4,0x210
    8000486c:	92472703          	lw	a4,-1756(a4) # 8021418c <sb+0xc>
    80004870:	00100793          	li	a5,1
    80004874:	08e7f663          	bgeu	a5,a4,80004900 <ialloc+0xa8>
    80004878:	02913423          	sd	s1,40(sp)
    8000487c:	03213023          	sd	s2,32(sp)
    80004880:	01313c23          	sd	s3,24(sp)
    80004884:	01413823          	sd	s4,16(sp)
    80004888:	01513423          	sd	s5,8(sp)
    8000488c:	01613023          	sd	s6,0(sp)
    80004890:	00050a93          	mv	s5,a0
    80004894:	00058b13          	mv	s6,a1
    80004898:	00078913          	mv	s2,a5
    bp = bread(dev, IBLOCK(inum, sb));
    8000489c:	00210a17          	auipc	s4,0x210
    800048a0:	8e4a0a13          	addi	s4,s4,-1820 # 80214180 <sb>
    800048a4:	00495593          	srli	a1,s2,0x4
    800048a8:	018a2783          	lw	a5,24(s4)
    800048ac:	00b785bb          	addw	a1,a5,a1
    800048b0:	000a8513          	mv	a0,s5
    800048b4:	845ff0ef          	jal	800040f8 <bread>
    800048b8:	00050493          	mv	s1,a0
    dip = (struct dinode *)bp->data + inum % IPB;
    800048bc:	05850993          	addi	s3,a0,88
    800048c0:	00f97793          	andi	a5,s2,15
    800048c4:	00679793          	slli	a5,a5,0x6
    800048c8:	00f989b3          	add	s3,s3,a5
    if (dip->type == 0)
    800048cc:	00099783          	lh	a5,0(s3)
    800048d0:	04078863          	beqz	a5,80004920 <ialloc+0xc8>
    brelse(bp);
    800048d4:	999ff0ef          	jal	8000426c <brelse>
  for (inum = 1; inum < sb.ninodes; inum++)
    800048d8:	00190913          	addi	s2,s2,1
    800048dc:	00ca2703          	lw	a4,12(s4)
    800048e0:	0009079b          	sext.w	a5,s2
    800048e4:	fce7e0e3          	bltu	a5,a4,800048a4 <ialloc+0x4c>
    800048e8:	02813483          	ld	s1,40(sp)
    800048ec:	02013903          	ld	s2,32(sp)
    800048f0:	01813983          	ld	s3,24(sp)
    800048f4:	01013a03          	ld	s4,16(sp)
    800048f8:	00813a83          	ld	s5,8(sp)
    800048fc:	00013b03          	ld	s6,0(sp)
  printf("ialloc: no inodes\n");
    80004900:	00005517          	auipc	a0,0x5
    80004904:	ed850513          	addi	a0,a0,-296 # 800097d8 <etext+0x7d8>
    80004908:	dc5fb0ef          	jal	800006cc <printf>
  return 0;
    8000490c:	00000513          	li	a0,0
}
    80004910:	03813083          	ld	ra,56(sp)
    80004914:	03013403          	ld	s0,48(sp)
    80004918:	04010113          	addi	sp,sp,64
    8000491c:	00008067          	ret
      memset(dip, 0, sizeof(*dip));
    80004920:	04000613          	li	a2,64
    80004924:	00000593          	li	a1,0
    80004928:	00098513          	mv	a0,s3
    8000492c:	8b1fc0ef          	jal	800011dc <memset>
      dip->type = type;
    80004930:	01699023          	sh	s6,0(s3)
      log_write(bp); // mark it allocated on the disk
    80004934:	00048513          	mv	a0,s1
    80004938:	284010ef          	jal	80005bbc <log_write>
      brelse(bp);
    8000493c:	00048513          	mv	a0,s1
    80004940:	92dff0ef          	jal	8000426c <brelse>
      return iget(dev, inum);
    80004944:	0009059b          	sext.w	a1,s2
    80004948:	000a8513          	mv	a0,s5
    8000494c:	dadff0ef          	jal	800046f8 <iget>
    80004950:	02813483          	ld	s1,40(sp)
    80004954:	02013903          	ld	s2,32(sp)
    80004958:	01813983          	ld	s3,24(sp)
    8000495c:	01013a03          	ld	s4,16(sp)
    80004960:	00813a83          	ld	s5,8(sp)
    80004964:	00013b03          	ld	s6,0(sp)
    80004968:	fa9ff06f          	j	80004910 <ialloc+0xb8>

000000008000496c <iupdate>:
{
    8000496c:	fe010113          	addi	sp,sp,-32
    80004970:	00113c23          	sd	ra,24(sp)
    80004974:	00813823          	sd	s0,16(sp)
    80004978:	00913423          	sd	s1,8(sp)
    8000497c:	01213023          	sd	s2,0(sp)
    80004980:	02010413          	addi	s0,sp,32
    80004984:	00050493          	mv	s1,a0
  bp = bread(ip->dev, IBLOCK(ip->inum, sb));
    80004988:	00452783          	lw	a5,4(a0)
    8000498c:	0047d79b          	srliw	a5,a5,0x4
    80004990:	00210597          	auipc	a1,0x210
    80004994:	8085a583          	lw	a1,-2040(a1) # 80214198 <sb+0x18>
    80004998:	00f585bb          	addw	a1,a1,a5
    8000499c:	00052503          	lw	a0,0(a0)
    800049a0:	f58ff0ef          	jal	800040f8 <bread>
    800049a4:	00050913          	mv	s2,a0
  dip = (struct dinode *)bp->data + ip->inum % IPB;
    800049a8:	05850793          	addi	a5,a0,88
    800049ac:	0044a703          	lw	a4,4(s1)
    800049b0:	00f77713          	andi	a4,a4,15
    800049b4:	00671713          	slli	a4,a4,0x6
    800049b8:	00e787b3          	add	a5,a5,a4
  dip->type = ip->type;
    800049bc:	04449703          	lh	a4,68(s1)
    800049c0:	00e79023          	sh	a4,0(a5)
  dip->major = ip->major;
    800049c4:	04649703          	lh	a4,70(s1)
    800049c8:	00e79123          	sh	a4,2(a5)
  dip->minor = ip->minor;
    800049cc:	04849703          	lh	a4,72(s1)
    800049d0:	00e79223          	sh	a4,4(a5)
  dip->nlink = ip->nlink;
    800049d4:	04a49703          	lh	a4,74(s1)
    800049d8:	00e79323          	sh	a4,6(a5)
  dip->size = ip->size;
    800049dc:	04c4a703          	lw	a4,76(s1)
    800049e0:	00e7a423          	sw	a4,8(a5)
  memmove(dip->addrs, ip->addrs, sizeof(ip->addrs));
    800049e4:	03400613          	li	a2,52
    800049e8:	05048593          	addi	a1,s1,80
    800049ec:	00c78513          	addi	a0,a5,12
    800049f0:	889fc0ef          	jal	80001278 <memmove>
  log_write(bp);
    800049f4:	00090513          	mv	a0,s2
    800049f8:	1c4010ef          	jal	80005bbc <log_write>
  brelse(bp);
    800049fc:	00090513          	mv	a0,s2
    80004a00:	86dff0ef          	jal	8000426c <brelse>
}
    80004a04:	01813083          	ld	ra,24(sp)
    80004a08:	01013403          	ld	s0,16(sp)
    80004a0c:	00813483          	ld	s1,8(sp)
    80004a10:	00013903          	ld	s2,0(sp)
    80004a14:	02010113          	addi	sp,sp,32
    80004a18:	00008067          	ret

0000000080004a1c <idup>:
{
    80004a1c:	fe010113          	addi	sp,sp,-32
    80004a20:	00113c23          	sd	ra,24(sp)
    80004a24:	00813823          	sd	s0,16(sp)
    80004a28:	00913423          	sd	s1,8(sp)
    80004a2c:	02010413          	addi	s0,sp,32
    80004a30:	00050493          	mv	s1,a0
  acquire(&itable.lock);
    80004a34:	0020f517          	auipc	a0,0x20f
    80004a38:	76c50513          	addi	a0,a0,1900 # 802141a0 <itable>
    80004a3c:	e04fc0ef          	jal	80001040 <acquire>
  ip->ref++;
    80004a40:	0084a783          	lw	a5,8(s1)
    80004a44:	0017879b          	addiw	a5,a5,1
    80004a48:	00f4a423          	sw	a5,8(s1)
  release(&itable.lock);
    80004a4c:	0020f517          	auipc	a0,0x20f
    80004a50:	75450513          	addi	a0,a0,1876 # 802141a0 <itable>
    80004a54:	ec4fc0ef          	jal	80001118 <release>
}
    80004a58:	00048513          	mv	a0,s1
    80004a5c:	01813083          	ld	ra,24(sp)
    80004a60:	01013403          	ld	s0,16(sp)
    80004a64:	00813483          	ld	s1,8(sp)
    80004a68:	02010113          	addi	sp,sp,32
    80004a6c:	00008067          	ret

0000000080004a70 <ilock>:
{
    80004a70:	fe010113          	addi	sp,sp,-32
    80004a74:	00113c23          	sd	ra,24(sp)
    80004a78:	00813823          	sd	s0,16(sp)
    80004a7c:	00913423          	sd	s1,8(sp)
    80004a80:	02010413          	addi	s0,sp,32
  if (ip == 0 || ip->ref < 1)
    80004a84:	02050a63          	beqz	a0,80004ab8 <ilock+0x48>
    80004a88:	00050493          	mv	s1,a0
    80004a8c:	00852783          	lw	a5,8(a0)
    80004a90:	02f05463          	blez	a5,80004ab8 <ilock+0x48>
  acquiresleep(&ip->lock);
    80004a94:	01050513          	addi	a0,a0,16
    80004a98:	278010ef          	jal	80005d10 <acquiresleep>
  if (ip->valid == 0)
    80004a9c:	0404a783          	lw	a5,64(s1)
    80004aa0:	02078463          	beqz	a5,80004ac8 <ilock+0x58>
}
    80004aa4:	01813083          	ld	ra,24(sp)
    80004aa8:	01013403          	ld	s0,16(sp)
    80004aac:	00813483          	ld	s1,8(sp)
    80004ab0:	02010113          	addi	sp,sp,32
    80004ab4:	00008067          	ret
    80004ab8:	01213023          	sd	s2,0(sp)
    panic("ilock");
    80004abc:	00005517          	auipc	a0,0x5
    80004ac0:	d3450513          	addi	a0,a0,-716 # 800097f0 <etext+0x7f0>
    80004ac4:	828fc0ef          	jal	80000aec <panic>
    80004ac8:	01213023          	sd	s2,0(sp)
    bp = bread(ip->dev, IBLOCK(ip->inum, sb));
    80004acc:	0044a783          	lw	a5,4(s1)
    80004ad0:	0047d79b          	srliw	a5,a5,0x4
    80004ad4:	0020f597          	auipc	a1,0x20f
    80004ad8:	6c45a583          	lw	a1,1732(a1) # 80214198 <sb+0x18>
    80004adc:	00f585bb          	addw	a1,a1,a5
    80004ae0:	0004a503          	lw	a0,0(s1)
    80004ae4:	e14ff0ef          	jal	800040f8 <bread>
    80004ae8:	00050913          	mv	s2,a0
    dip = (struct dinode *)bp->data + ip->inum % IPB;
    80004aec:	05850593          	addi	a1,a0,88
    80004af0:	0044a783          	lw	a5,4(s1)
    80004af4:	00f7f793          	andi	a5,a5,15
    80004af8:	00679793          	slli	a5,a5,0x6
    80004afc:	00f585b3          	add	a1,a1,a5
    ip->type = dip->type;
    80004b00:	00059783          	lh	a5,0(a1)
    80004b04:	04f49223          	sh	a5,68(s1)
    ip->major = dip->major;
    80004b08:	00259783          	lh	a5,2(a1)
    80004b0c:	04f49323          	sh	a5,70(s1)
    ip->minor = dip->minor;
    80004b10:	00459783          	lh	a5,4(a1)
    80004b14:	04f49423          	sh	a5,72(s1)
    ip->nlink = dip->nlink;
    80004b18:	00659783          	lh	a5,6(a1)
    80004b1c:	04f49523          	sh	a5,74(s1)
    ip->size = dip->size;
    80004b20:	0085a783          	lw	a5,8(a1)
    80004b24:	04f4a623          	sw	a5,76(s1)
    memmove(ip->addrs, dip->addrs, sizeof(ip->addrs));
    80004b28:	03400613          	li	a2,52
    80004b2c:	00c58593          	addi	a1,a1,12
    80004b30:	05048513          	addi	a0,s1,80
    80004b34:	f44fc0ef          	jal	80001278 <memmove>
    brelse(bp);
    80004b38:	00090513          	mv	a0,s2
    80004b3c:	f30ff0ef          	jal	8000426c <brelse>
    ip->valid = 1;
    80004b40:	00100793          	li	a5,1
    80004b44:	04f4a023          	sw	a5,64(s1)
    if (ip->type == 0)
    80004b48:	04449783          	lh	a5,68(s1)
    80004b4c:	00078663          	beqz	a5,80004b58 <ilock+0xe8>
    80004b50:	00013903          	ld	s2,0(sp)
    80004b54:	f51ff06f          	j	80004aa4 <ilock+0x34>
      panic("ilock: no type");
    80004b58:	00005517          	auipc	a0,0x5
    80004b5c:	ca050513          	addi	a0,a0,-864 # 800097f8 <etext+0x7f8>
    80004b60:	f8dfb0ef          	jal	80000aec <panic>

0000000080004b64 <iunlock>:
{
    80004b64:	fe010113          	addi	sp,sp,-32
    80004b68:	00113c23          	sd	ra,24(sp)
    80004b6c:	00813823          	sd	s0,16(sp)
    80004b70:	00913423          	sd	s1,8(sp)
    80004b74:	01213023          	sd	s2,0(sp)
    80004b78:	02010413          	addi	s0,sp,32
  if (ip == 0 || !holdingsleep(&ip->lock) || ip->ref < 1)
    80004b7c:	04050063          	beqz	a0,80004bbc <iunlock+0x58>
    80004b80:	00050493          	mv	s1,a0
    80004b84:	01050913          	addi	s2,a0,16
    80004b88:	00090513          	mv	a0,s2
    80004b8c:	254010ef          	jal	80005de0 <holdingsleep>
    80004b90:	02050663          	beqz	a0,80004bbc <iunlock+0x58>
    80004b94:	0084a783          	lw	a5,8(s1)
    80004b98:	02f05263          	blez	a5,80004bbc <iunlock+0x58>
  releasesleep(&ip->lock);
    80004b9c:	00090513          	mv	a0,s2
    80004ba0:	1e8010ef          	jal	80005d88 <releasesleep>
}
    80004ba4:	01813083          	ld	ra,24(sp)
    80004ba8:	01013403          	ld	s0,16(sp)
    80004bac:	00813483          	ld	s1,8(sp)
    80004bb0:	00013903          	ld	s2,0(sp)
    80004bb4:	02010113          	addi	sp,sp,32
    80004bb8:	00008067          	ret
    panic("iunlock");
    80004bbc:	00005517          	auipc	a0,0x5
    80004bc0:	c4c50513          	addi	a0,a0,-948 # 80009808 <etext+0x808>
    80004bc4:	f29fb0ef          	jal	80000aec <panic>

0000000080004bc8 <itrunc>:

// Truncate inode (discard contents).
// Caller must hold ip->lock.
void itrunc(struct inode *ip)
{
    80004bc8:	fd010113          	addi	sp,sp,-48
    80004bcc:	02113423          	sd	ra,40(sp)
    80004bd0:	02813023          	sd	s0,32(sp)
    80004bd4:	00913c23          	sd	s1,24(sp)
    80004bd8:	01213823          	sd	s2,16(sp)
    80004bdc:	01313423          	sd	s3,8(sp)
    80004be0:	03010413          	addi	s0,sp,48
    80004be4:	00050993          	mv	s3,a0
  int i, j;
  struct buf *bp;
  uint *a;

  for (i = 0; i < NDIRECT; i++)
    80004be8:	05050493          	addi	s1,a0,80
    80004bec:	08050913          	addi	s2,a0,128
    80004bf0:	00c0006f          	j	80004bfc <itrunc+0x34>
    80004bf4:	00448493          	addi	s1,s1,4
    80004bf8:	01248e63          	beq	s1,s2,80004c14 <itrunc+0x4c>
  {
    if (ip->addrs[i])
    80004bfc:	0004a583          	lw	a1,0(s1)
    80004c00:	fe058ae3          	beqz	a1,80004bf4 <itrunc+0x2c>
    {
      bfree(ip->dev, ip->addrs[i]);
    80004c04:	0009a503          	lw	a0,0(s3)
    80004c08:	fc0ff0ef          	jal	800043c8 <bfree>
      ip->addrs[i] = 0;
    80004c0c:	0004a023          	sw	zero,0(s1)
    80004c10:	fe5ff06f          	j	80004bf4 <itrunc+0x2c>
    }
  }

  if (ip->addrs[NDIRECT])
    80004c14:	0809a583          	lw	a1,128(s3)
    80004c18:	02059663          	bnez	a1,80004c44 <itrunc+0x7c>
    brelse(bp);
    bfree(ip->dev, ip->addrs[NDIRECT]);
    ip->addrs[NDIRECT] = 0;
  }

  ip->size = 0;
    80004c1c:	0409a623          	sw	zero,76(s3)
  iupdate(ip);
    80004c20:	00098513          	mv	a0,s3
    80004c24:	d49ff0ef          	jal	8000496c <iupdate>
}
    80004c28:	02813083          	ld	ra,40(sp)
    80004c2c:	02013403          	ld	s0,32(sp)
    80004c30:	01813483          	ld	s1,24(sp)
    80004c34:	01013903          	ld	s2,16(sp)
    80004c38:	00813983          	ld	s3,8(sp)
    80004c3c:	03010113          	addi	sp,sp,48
    80004c40:	00008067          	ret
    80004c44:	01413023          	sd	s4,0(sp)
    bp = bread(ip->dev, ip->addrs[NDIRECT]);
    80004c48:	0009a503          	lw	a0,0(s3)
    80004c4c:	cacff0ef          	jal	800040f8 <bread>
    80004c50:	00050a13          	mv	s4,a0
    for (j = 0; j < NINDIRECT; j++)
    80004c54:	05850493          	addi	s1,a0,88
    80004c58:	45850913          	addi	s2,a0,1112
    80004c5c:	00c0006f          	j	80004c68 <itrunc+0xa0>
    80004c60:	00448493          	addi	s1,s1,4
    80004c64:	01248c63          	beq	s1,s2,80004c7c <itrunc+0xb4>
      if (a[j])
    80004c68:	0004a583          	lw	a1,0(s1)
    80004c6c:	fe058ae3          	beqz	a1,80004c60 <itrunc+0x98>
        bfree(ip->dev, a[j]);
    80004c70:	0009a503          	lw	a0,0(s3)
    80004c74:	f54ff0ef          	jal	800043c8 <bfree>
    80004c78:	fe9ff06f          	j	80004c60 <itrunc+0x98>
    brelse(bp);
    80004c7c:	000a0513          	mv	a0,s4
    80004c80:	decff0ef          	jal	8000426c <brelse>
    bfree(ip->dev, ip->addrs[NDIRECT]);
    80004c84:	0809a583          	lw	a1,128(s3)
    80004c88:	0009a503          	lw	a0,0(s3)
    80004c8c:	f3cff0ef          	jal	800043c8 <bfree>
    ip->addrs[NDIRECT] = 0;
    80004c90:	0809a023          	sw	zero,128(s3)
    80004c94:	00013a03          	ld	s4,0(sp)
    80004c98:	f85ff06f          	j	80004c1c <itrunc+0x54>

0000000080004c9c <iput>:
{
    80004c9c:	fe010113          	addi	sp,sp,-32
    80004ca0:	00113c23          	sd	ra,24(sp)
    80004ca4:	00813823          	sd	s0,16(sp)
    80004ca8:	00913423          	sd	s1,8(sp)
    80004cac:	02010413          	addi	s0,sp,32
    80004cb0:	00050493          	mv	s1,a0
  acquire(&itable.lock);
    80004cb4:	0020f517          	auipc	a0,0x20f
    80004cb8:	4ec50513          	addi	a0,a0,1260 # 802141a0 <itable>
    80004cbc:	b84fc0ef          	jal	80001040 <acquire>
  if (ip->ref == 1 && ip->valid && ip->nlink == 0)
    80004cc0:	0084a703          	lw	a4,8(s1)
    80004cc4:	00100793          	li	a5,1
    80004cc8:	02f70863          	beq	a4,a5,80004cf8 <iput+0x5c>
  ip->ref--;
    80004ccc:	0084a783          	lw	a5,8(s1)
    80004cd0:	fff7879b          	addiw	a5,a5,-1
    80004cd4:	00f4a423          	sw	a5,8(s1)
  release(&itable.lock);
    80004cd8:	0020f517          	auipc	a0,0x20f
    80004cdc:	4c850513          	addi	a0,a0,1224 # 802141a0 <itable>
    80004ce0:	c38fc0ef          	jal	80001118 <release>
}
    80004ce4:	01813083          	ld	ra,24(sp)
    80004ce8:	01013403          	ld	s0,16(sp)
    80004cec:	00813483          	ld	s1,8(sp)
    80004cf0:	02010113          	addi	sp,sp,32
    80004cf4:	00008067          	ret
  if (ip->ref == 1 && ip->valid && ip->nlink == 0)
    80004cf8:	0404a783          	lw	a5,64(s1)
    80004cfc:	fc0788e3          	beqz	a5,80004ccc <iput+0x30>
    80004d00:	04a49783          	lh	a5,74(s1)
    80004d04:	fc0794e3          	bnez	a5,80004ccc <iput+0x30>
    80004d08:	01213023          	sd	s2,0(sp)
    acquiresleep(&ip->lock);
    80004d0c:	01048793          	addi	a5,s1,16
    80004d10:	00078913          	mv	s2,a5
    80004d14:	00078513          	mv	a0,a5
    80004d18:	7f9000ef          	jal	80005d10 <acquiresleep>
    release(&itable.lock);
    80004d1c:	0020f517          	auipc	a0,0x20f
    80004d20:	48450513          	addi	a0,a0,1156 # 802141a0 <itable>
    80004d24:	bf4fc0ef          	jal	80001118 <release>
    itrunc(ip);
    80004d28:	00048513          	mv	a0,s1
    80004d2c:	e9dff0ef          	jal	80004bc8 <itrunc>
    ip->type = 0;
    80004d30:	04049223          	sh	zero,68(s1)
    iupdate(ip);
    80004d34:	00048513          	mv	a0,s1
    80004d38:	c35ff0ef          	jal	8000496c <iupdate>
    ip->valid = 0;
    80004d3c:	0404a023          	sw	zero,64(s1)
    releasesleep(&ip->lock);
    80004d40:	00090513          	mv	a0,s2
    80004d44:	044010ef          	jal	80005d88 <releasesleep>
    acquire(&itable.lock);
    80004d48:	0020f517          	auipc	a0,0x20f
    80004d4c:	45850513          	addi	a0,a0,1112 # 802141a0 <itable>
    80004d50:	af0fc0ef          	jal	80001040 <acquire>
    80004d54:	00013903          	ld	s2,0(sp)
    80004d58:	f75ff06f          	j	80004ccc <iput+0x30>

0000000080004d5c <iunlockput>:
{
    80004d5c:	fe010113          	addi	sp,sp,-32
    80004d60:	00113c23          	sd	ra,24(sp)
    80004d64:	00813823          	sd	s0,16(sp)
    80004d68:	00913423          	sd	s1,8(sp)
    80004d6c:	02010413          	addi	s0,sp,32
    80004d70:	00050493          	mv	s1,a0
  iunlock(ip);
    80004d74:	df1ff0ef          	jal	80004b64 <iunlock>
  iput(ip);
    80004d78:	00048513          	mv	a0,s1
    80004d7c:	f21ff0ef          	jal	80004c9c <iput>
}
    80004d80:	01813083          	ld	ra,24(sp)
    80004d84:	01013403          	ld	s0,16(sp)
    80004d88:	00813483          	ld	s1,8(sp)
    80004d8c:	02010113          	addi	sp,sp,32
    80004d90:	00008067          	ret

0000000080004d94 <ireclaim>:
{
    80004d94:	fb010113          	addi	sp,sp,-80
    80004d98:	04113423          	sd	ra,72(sp)
    80004d9c:	04813023          	sd	s0,64(sp)
    80004da0:	05010413          	addi	s0,sp,80
  for (int inum = 1; inum < sb.ninodes; inum++)
    80004da4:	0020f617          	auipc	a2,0x20f
    80004da8:	3e862603          	lw	a2,1000(a2) # 8021418c <sb+0xc>
    80004dac:	00100793          	li	a5,1
    80004db0:	10c7f863          	bgeu	a5,a2,80004ec0 <ireclaim+0x12c>
    80004db4:	02913c23          	sd	s1,56(sp)
    80004db8:	03213823          	sd	s2,48(sp)
    80004dbc:	03313423          	sd	s3,40(sp)
    80004dc0:	03413023          	sd	s4,32(sp)
    80004dc4:	01513c23          	sd	s5,24(sp)
    80004dc8:	01613823          	sd	s6,16(sp)
    80004dcc:	01713423          	sd	s7,8(sp)
    80004dd0:	00050a93          	mv	s5,a0
    80004dd4:	00078493          	mv	s1,a5
    printf("[LOG][fs.c] ireclaim is executing %d/%d\n", inum, sb.ninodes - 1);
    80004dd8:	00005b17          	auipc	s6,0x5
    80004ddc:	a38b0b13          	addi	s6,s6,-1480 # 80009810 <etext+0x810>
    struct buf *bp = bread(dev, IBLOCK(inum, sb));
    80004de0:	0020fa17          	auipc	s4,0x20f
    80004de4:	3a0a0a13          	addi	s4,s4,928 # 80214180 <sb>
      printf("ireclaim: orphaned inode %d\n", inum);
    80004de8:	00005b97          	auipc	s7,0x5
    80004dec:	a58b8b93          	addi	s7,s7,-1448 # 80009840 <etext+0x840>
    80004df0:	05c0006f          	j	80004e4c <ireclaim+0xb8>
    80004df4:	00098593          	mv	a1,s3
    80004df8:	000b8513          	mv	a0,s7
    80004dfc:	8d1fb0ef          	jal	800006cc <printf>
      ip = iget(dev, inum);
    80004e00:	00098593          	mv	a1,s3
    80004e04:	000a8513          	mv	a0,s5
    80004e08:	8f1ff0ef          	jal	800046f8 <iget>
    80004e0c:	00050993          	mv	s3,a0
    brelse(bp);
    80004e10:	00090513          	mv	a0,s2
    80004e14:	c58ff0ef          	jal	8000426c <brelse>
    if (ip)
    80004e18:	02098263          	beqz	s3,80004e3c <ireclaim+0xa8>
      begin_op();
    80004e1c:	37d000ef          	jal	80005998 <begin_op>
      ilock(ip);
    80004e20:	00098513          	mv	a0,s3
    80004e24:	c4dff0ef          	jal	80004a70 <ilock>
      iunlock(ip);
    80004e28:	00098513          	mv	a0,s3
    80004e2c:	d39ff0ef          	jal	80004b64 <iunlock>
      iput(ip);
    80004e30:	00098513          	mv	a0,s3
    80004e34:	e69ff0ef          	jal	80004c9c <iput>
      end_op();
    80004e38:	405000ef          	jal	80005a3c <end_op>
  for (int inum = 1; inum < sb.ninodes; inum++)
    80004e3c:	00ca2603          	lw	a2,12(s4)
    80004e40:	00148493          	addi	s1,s1,1
    80004e44:	0004879b          	sext.w	a5,s1
    80004e48:	04c7fe63          	bgeu	a5,a2,80004ea4 <ireclaim+0x110>
    80004e4c:	0004899b          	sext.w	s3,s1
    printf("[LOG][fs.c] ireclaim is executing %d/%d\n", inum, sb.ninodes - 1);
    80004e50:	fff6061b          	addiw	a2,a2,-1
    80004e54:	00098593          	mv	a1,s3
    80004e58:	000b0513          	mv	a0,s6
    80004e5c:	871fb0ef          	jal	800006cc <printf>
    struct buf *bp = bread(dev, IBLOCK(inum, sb));
    80004e60:	0044d593          	srli	a1,s1,0x4
    80004e64:	018a2783          	lw	a5,24(s4)
    80004e68:	00b785bb          	addw	a1,a5,a1
    80004e6c:	000a8513          	mv	a0,s5
    80004e70:	a88ff0ef          	jal	800040f8 <bread>
    80004e74:	00050913          	mv	s2,a0
    struct dinode *dip = (struct dinode *)bp->data + inum % IPB;
    80004e78:	05850793          	addi	a5,a0,88
    80004e7c:	00f9f713          	andi	a4,s3,15
    80004e80:	00671713          	slli	a4,a4,0x6
    80004e84:	00e787b3          	add	a5,a5,a4
    if (dip->type != 0 && dip->nlink == 0)
    80004e88:	00079703          	lh	a4,0(a5)
    80004e8c:	00070663          	beqz	a4,80004e98 <ireclaim+0x104>
    80004e90:	00679783          	lh	a5,6(a5)
    80004e94:	f60780e3          	beqz	a5,80004df4 <ireclaim+0x60>
    brelse(bp);
    80004e98:	00090513          	mv	a0,s2
    80004e9c:	bd0ff0ef          	jal	8000426c <brelse>
    if (ip)
    80004ea0:	f9dff06f          	j	80004e3c <ireclaim+0xa8>
    80004ea4:	03813483          	ld	s1,56(sp)
    80004ea8:	03013903          	ld	s2,48(sp)
    80004eac:	02813983          	ld	s3,40(sp)
    80004eb0:	02013a03          	ld	s4,32(sp)
    80004eb4:	01813a83          	ld	s5,24(sp)
    80004eb8:	01013b03          	ld	s6,16(sp)
    80004ebc:	00813b83          	ld	s7,8(sp)
  printf("[LOG][fs.c] ireclaim has done\n");
    80004ec0:	00005517          	auipc	a0,0x5
    80004ec4:	9a050513          	addi	a0,a0,-1632 # 80009860 <etext+0x860>
    80004ec8:	805fb0ef          	jal	800006cc <printf>
}
    80004ecc:	04813083          	ld	ra,72(sp)
    80004ed0:	04013403          	ld	s0,64(sp)
    80004ed4:	05010113          	addi	sp,sp,80
    80004ed8:	00008067          	ret

0000000080004edc <fsinit>:
{
    80004edc:	fe010113          	addi	sp,sp,-32
    80004ee0:	00113c23          	sd	ra,24(sp)
    80004ee4:	00813823          	sd	s0,16(sp)
    80004ee8:	00913423          	sd	s1,8(sp)
    80004eec:	01213023          	sd	s2,0(sp)
    80004ef0:	02010413          	addi	s0,sp,32
    80004ef4:	00050913          	mv	s2,a0
  bp = bread(dev, 1);
    80004ef8:	00100593          	li	a1,1
    80004efc:	9fcff0ef          	jal	800040f8 <bread>
    80004f00:	00050493          	mv	s1,a0
  memmove(sb, bp->data, sizeof(*sb));
    80004f04:	02000613          	li	a2,32
    80004f08:	05850593          	addi	a1,a0,88
    80004f0c:	0020f517          	auipc	a0,0x20f
    80004f10:	27450513          	addi	a0,a0,628 # 80214180 <sb>
    80004f14:	b64fc0ef          	jal	80001278 <memmove>
  brelse(bp);
    80004f18:	00048513          	mv	a0,s1
    80004f1c:	b50ff0ef          	jal	8000426c <brelse>
  if (sb.magic != FSMAGIC)
    80004f20:	0020f717          	auipc	a4,0x20f
    80004f24:	26072703          	lw	a4,608(a4) # 80214180 <sb>
    80004f28:	102037b7          	lui	a5,0x10203
    80004f2c:	04078793          	addi	a5,a5,64 # 10203040 <_binary_fs_img_size+0x1000f040>
    80004f30:	02f71a63          	bne	a4,a5,80004f64 <fsinit+0x88>
  initlog(dev, &sb);
    80004f34:	0020f597          	auipc	a1,0x20f
    80004f38:	24c58593          	addi	a1,a1,588 # 80214180 <sb>
    80004f3c:	00090513          	mv	a0,s2
    80004f40:	1a1000ef          	jal	800058e0 <initlog>
  ireclaim(dev);
    80004f44:	00090513          	mv	a0,s2
    80004f48:	e4dff0ef          	jal	80004d94 <ireclaim>
}
    80004f4c:	01813083          	ld	ra,24(sp)
    80004f50:	01013403          	ld	s0,16(sp)
    80004f54:	00813483          	ld	s1,8(sp)
    80004f58:	00013903          	ld	s2,0(sp)
    80004f5c:	02010113          	addi	sp,sp,32
    80004f60:	00008067          	ret
    panic("invalid file system");
    80004f64:	00005517          	auipc	a0,0x5
    80004f68:	91c50513          	addi	a0,a0,-1764 # 80009880 <etext+0x880>
    80004f6c:	b81fb0ef          	jal	80000aec <panic>

0000000080004f70 <stati>:

// Copy stat information from inode.
// Caller must hold ip->lock.
void stati(struct inode *ip, struct stat *st)
{
    80004f70:	ff010113          	addi	sp,sp,-16
    80004f74:	00113423          	sd	ra,8(sp)
    80004f78:	00813023          	sd	s0,0(sp)
    80004f7c:	01010413          	addi	s0,sp,16
  st->dev = ip->dev;
    80004f80:	00052783          	lw	a5,0(a0)
    80004f84:	00f5a023          	sw	a5,0(a1)
  st->ino = ip->inum;
    80004f88:	00452783          	lw	a5,4(a0)
    80004f8c:	00f5a223          	sw	a5,4(a1)
  st->type = ip->type;
    80004f90:	04451783          	lh	a5,68(a0)
    80004f94:	00f59423          	sh	a5,8(a1)
  st->nlink = ip->nlink;
    80004f98:	04a51783          	lh	a5,74(a0)
    80004f9c:	00f59523          	sh	a5,10(a1)
  st->size = ip->size;
    80004fa0:	04c56783          	lwu	a5,76(a0)
    80004fa4:	00f5b823          	sd	a5,16(a1)
}
    80004fa8:	00813083          	ld	ra,8(sp)
    80004fac:	00013403          	ld	s0,0(sp)
    80004fb0:	01010113          	addi	sp,sp,16
    80004fb4:	00008067          	ret

0000000080004fb8 <readi>:
int readi(struct inode *ip, int user_dst, uint64 dst, uint off, uint n)
{
  uint tot, m;
  struct buf *bp;

  if (off > ip->size || off + n < off)
    80004fb8:	04c52783          	lw	a5,76(a0)
    80004fbc:	16d7ec63          	bltu	a5,a3,80005134 <readi+0x17c>
{
    80004fc0:	f9010113          	addi	sp,sp,-112
    80004fc4:	06113423          	sd	ra,104(sp)
    80004fc8:	06813023          	sd	s0,96(sp)
    80004fcc:	04913c23          	sd	s1,88(sp)
    80004fd0:	05413023          	sd	s4,64(sp)
    80004fd4:	03513c23          	sd	s5,56(sp)
    80004fd8:	03613823          	sd	s6,48(sp)
    80004fdc:	03713423          	sd	s7,40(sp)
    80004fe0:	07010413          	addi	s0,sp,112
    80004fe4:	00050b13          	mv	s6,a0
    80004fe8:	00058b93          	mv	s7,a1
    80004fec:	00060a13          	mv	s4,a2
    80004ff0:	00068493          	mv	s1,a3
    80004ff4:	00070a93          	mv	s5,a4
  if (off > ip->size || off + n < off)
    80004ff8:	00e6873b          	addw	a4,a3,a4
    return 0;
    80004ffc:	00000513          	li	a0,0
  if (off > ip->size || off + n < off)
    80005000:	10d76863          	bltu	a4,a3,80005110 <readi+0x158>
    80005004:	05313423          	sd	s3,72(sp)
  if (off + n > ip->size)
    80005008:	00e7f463          	bgeu	a5,a4,80005010 <readi+0x58>
    n = ip->size - off;
    8000500c:	40d78abb          	subw	s5,a5,a3

  for (tot = 0; tot < n; tot += m, off += m, dst += m)
    80005010:	0c0a8e63          	beqz	s5,800050ec <readi+0x134>
    80005014:	05213823          	sd	s2,80(sp)
    80005018:	03813023          	sd	s8,32(sp)
    8000501c:	01913c23          	sd	s9,24(sp)
    80005020:	01a13823          	sd	s10,16(sp)
    80005024:	01b13423          	sd	s11,8(sp)
    80005028:	00000993          	li	s3,0
  {
    uint addr = bmap(ip, off / BSIZE);
    if (addr == 0)
      break;
    bp = bread(ip->dev, addr);
    m = min(n - tot, BSIZE - off % BSIZE);
    8000502c:	40000c93          	li	s9,1024
    if (either_copyout(user_dst, dst, bp->data + (off % BSIZE), m) == -1)
    80005030:	fff00c13          	li	s8,-1
    80005034:	0400006f          	j	80005074 <readi+0xbc>
    80005038:	020d1d93          	slli	s11,s10,0x20
    8000503c:	020ddd93          	srli	s11,s11,0x20
    80005040:	05890613          	addi	a2,s2,88
    80005044:	000d8693          	mv	a3,s11
    80005048:	00f60633          	add	a2,a2,a5
    8000504c:	000a0593          	mv	a1,s4
    80005050:	000b8513          	mv	a0,s7
    80005054:	b90fe0ef          	jal	800033e4 <either_copyout>
    80005058:	05850c63          	beq	a0,s8,800050b0 <readi+0xf8>
    {
      brelse(bp);
      tot = -1;
      break;
    }
    brelse(bp);
    8000505c:	00090513          	mv	a0,s2
    80005060:	a0cff0ef          	jal	8000426c <brelse>
  for (tot = 0; tot < n; tot += m, off += m, dst += m)
    80005064:	013d09bb          	addw	s3,s10,s3
    80005068:	009d04bb          	addw	s1,s10,s1
    8000506c:	01ba0a33          	add	s4,s4,s11
    80005070:	0759f263          	bgeu	s3,s5,800050d4 <readi+0x11c>
    uint addr = bmap(ip, off / BSIZE);
    80005074:	00a4d59b          	srliw	a1,s1,0xa
    80005078:	000b0513          	mv	a0,s6
    8000507c:	d64ff0ef          	jal	800045e0 <bmap>
    80005080:	00050593          	mv	a1,a0
    if (addr == 0)
    80005084:	06050863          	beqz	a0,800050f4 <readi+0x13c>
    bp = bread(ip->dev, addr);
    80005088:	000b2503          	lw	a0,0(s6)
    8000508c:	86cff0ef          	jal	800040f8 <bread>
    80005090:	00050913          	mv	s2,a0
    m = min(n - tot, BSIZE - off % BSIZE);
    80005094:	3ff4f793          	andi	a5,s1,1023
    80005098:	40fc873b          	subw	a4,s9,a5
    8000509c:	413a86bb          	subw	a3,s5,s3
    800050a0:	00070d13          	mv	s10,a4
    800050a4:	f8e6fae3          	bgeu	a3,a4,80005038 <readi+0x80>
    800050a8:	00068d13          	mv	s10,a3
    800050ac:	f8dff06f          	j	80005038 <readi+0x80>
      brelse(bp);
    800050b0:	00090513          	mv	a0,s2
    800050b4:	9b8ff0ef          	jal	8000426c <brelse>
      tot = -1;
    800050b8:	fff00993          	li	s3,-1
      break;
    800050bc:	05013903          	ld	s2,80(sp)
    800050c0:	02013c03          	ld	s8,32(sp)
    800050c4:	01813c83          	ld	s9,24(sp)
    800050c8:	01013d03          	ld	s10,16(sp)
    800050cc:	00813d83          	ld	s11,8(sp)
    800050d0:	0380006f          	j	80005108 <readi+0x150>
    800050d4:	05013903          	ld	s2,80(sp)
    800050d8:	02013c03          	ld	s8,32(sp)
    800050dc:	01813c83          	ld	s9,24(sp)
    800050e0:	01013d03          	ld	s10,16(sp)
    800050e4:	00813d83          	ld	s11,8(sp)
    800050e8:	0200006f          	j	80005108 <readi+0x150>
  for (tot = 0; tot < n; tot += m, off += m, dst += m)
    800050ec:	000a8993          	mv	s3,s5
    800050f0:	0180006f          	j	80005108 <readi+0x150>
    800050f4:	05013903          	ld	s2,80(sp)
    800050f8:	02013c03          	ld	s8,32(sp)
    800050fc:	01813c83          	ld	s9,24(sp)
    80005100:	01013d03          	ld	s10,16(sp)
    80005104:	00813d83          	ld	s11,8(sp)
  }
  return tot;
    80005108:	00098513          	mv	a0,s3
    8000510c:	04813983          	ld	s3,72(sp)
}
    80005110:	06813083          	ld	ra,104(sp)
    80005114:	06013403          	ld	s0,96(sp)
    80005118:	05813483          	ld	s1,88(sp)
    8000511c:	04013a03          	ld	s4,64(sp)
    80005120:	03813a83          	ld	s5,56(sp)
    80005124:	03013b03          	ld	s6,48(sp)
    80005128:	02813b83          	ld	s7,40(sp)
    8000512c:	07010113          	addi	sp,sp,112
    80005130:	00008067          	ret
    return 0;
    80005134:	00000513          	li	a0,0
}
    80005138:	00008067          	ret

000000008000513c <writei>:
int writei(struct inode *ip, int user_src, uint64 src, uint off, uint n)
{
  uint tot, m;
  struct buf *bp;

  if (off > ip->size || off + n < off)
    8000513c:	04c52783          	lw	a5,76(a0)
    80005140:	16d7ea63          	bltu	a5,a3,800052b4 <writei+0x178>
{
    80005144:	f9010113          	addi	sp,sp,-112
    80005148:	06113423          	sd	ra,104(sp)
    8000514c:	06813023          	sd	s0,96(sp)
    80005150:	05213823          	sd	s2,80(sp)
    80005154:	05413023          	sd	s4,64(sp)
    80005158:	03513c23          	sd	s5,56(sp)
    8000515c:	03613823          	sd	s6,48(sp)
    80005160:	03713423          	sd	s7,40(sp)
    80005164:	07010413          	addi	s0,sp,112
    80005168:	00050a93          	mv	s5,a0
    8000516c:	00058b93          	mv	s7,a1
    80005170:	00060a13          	mv	s4,a2
    80005174:	00068913          	mv	s2,a3
    80005178:	00070b13          	mv	s6,a4
  if (off > ip->size || off + n < off)
    8000517c:	00e687bb          	addw	a5,a3,a4
    return -1;
  if (off + n > MAXFILE * BSIZE)
    80005180:	00043737          	lui	a4,0x43
    80005184:	12f76c63          	bltu	a4,a5,800052bc <writei+0x180>
    80005188:	12d7ea63          	bltu	a5,a3,800052bc <writei+0x180>
    8000518c:	05313423          	sd	s3,72(sp)
    return -1;

  for (tot = 0; tot < n; tot += m, off += m, src += m)
    80005190:	100b0263          	beqz	s6,80005294 <writei+0x158>
    80005194:	04913c23          	sd	s1,88(sp)
    80005198:	03813023          	sd	s8,32(sp)
    8000519c:	01913c23          	sd	s9,24(sp)
    800051a0:	01a13823          	sd	s10,16(sp)
    800051a4:	01b13423          	sd	s11,8(sp)
    800051a8:	00000993          	li	s3,0
  {
    uint addr = bmap(ip, off / BSIZE);
    if (addr == 0)
      break;
    bp = bread(ip->dev, addr);
    m = min(n - tot, BSIZE - off % BSIZE);
    800051ac:	40000c93          	li	s9,1024
    if (either_copyin(bp->data + (off % BSIZE), user_src, src, m) == -1)
    800051b0:	fff00c13          	li	s8,-1
    800051b4:	0480006f          	j	800051fc <writei+0xc0>
    800051b8:	020d1d93          	slli	s11,s10,0x20
    800051bc:	020ddd93          	srli	s11,s11,0x20
    800051c0:	05848513          	addi	a0,s1,88
    800051c4:	000d8693          	mv	a3,s11
    800051c8:	000a0613          	mv	a2,s4
    800051cc:	000b8593          	mv	a1,s7
    800051d0:	00f50533          	add	a0,a0,a5
    800051d4:	a94fe0ef          	jal	80003468 <either_copyin>
    800051d8:	07850063          	beq	a0,s8,80005238 <writei+0xfc>
    {
      brelse(bp);
      break;
    }
    log_write(bp);
    800051dc:	00048513          	mv	a0,s1
    800051e0:	1dd000ef          	jal	80005bbc <log_write>
    brelse(bp);
    800051e4:	00048513          	mv	a0,s1
    800051e8:	884ff0ef          	jal	8000426c <brelse>
  for (tot = 0; tot < n; tot += m, off += m, src += m)
    800051ec:	013d09bb          	addw	s3,s10,s3
    800051f0:	012d093b          	addw	s2,s10,s2
    800051f4:	01ba0a33          	add	s4,s4,s11
    800051f8:	0569f463          	bgeu	s3,s6,80005240 <writei+0x104>
    uint addr = bmap(ip, off / BSIZE);
    800051fc:	00a9559b          	srliw	a1,s2,0xa
    80005200:	000a8513          	mv	a0,s5
    80005204:	bdcff0ef          	jal	800045e0 <bmap>
    80005208:	00050593          	mv	a1,a0
    if (addr == 0)
    8000520c:	02050a63          	beqz	a0,80005240 <writei+0x104>
    bp = bread(ip->dev, addr);
    80005210:	000aa503          	lw	a0,0(s5)
    80005214:	ee5fe0ef          	jal	800040f8 <bread>
    80005218:	00050493          	mv	s1,a0
    m = min(n - tot, BSIZE - off % BSIZE);
    8000521c:	3ff97793          	andi	a5,s2,1023
    80005220:	40fc873b          	subw	a4,s9,a5
    80005224:	413b06bb          	subw	a3,s6,s3
    80005228:	00070d13          	mv	s10,a4
    8000522c:	f8e6f6e3          	bgeu	a3,a4,800051b8 <writei+0x7c>
    80005230:	00068d13          	mv	s10,a3
    80005234:	f85ff06f          	j	800051b8 <writei+0x7c>
      brelse(bp);
    80005238:	00048513          	mv	a0,s1
    8000523c:	830ff0ef          	jal	8000426c <brelse>
  }

  if (off > ip->size)
    80005240:	04caa783          	lw	a5,76(s5)
    80005244:	0527fc63          	bgeu	a5,s2,8000529c <writei+0x160>
    ip->size = off;
    80005248:	052aa623          	sw	s2,76(s5)
    8000524c:	05813483          	ld	s1,88(sp)
    80005250:	02013c03          	ld	s8,32(sp)
    80005254:	01813c83          	ld	s9,24(sp)
    80005258:	01013d03          	ld	s10,16(sp)
    8000525c:	00813d83          	ld	s11,8(sp)

  // write the i-node back to disk even if the size didn't change
  // because the loop above might have called bmap() and added a new
  // block to ip->addrs[].
  iupdate(ip);
    80005260:	000a8513          	mv	a0,s5
    80005264:	f08ff0ef          	jal	8000496c <iupdate>

  return tot;
    80005268:	00098513          	mv	a0,s3
    8000526c:	04813983          	ld	s3,72(sp)
}
    80005270:	06813083          	ld	ra,104(sp)
    80005274:	06013403          	ld	s0,96(sp)
    80005278:	05013903          	ld	s2,80(sp)
    8000527c:	04013a03          	ld	s4,64(sp)
    80005280:	03813a83          	ld	s5,56(sp)
    80005284:	03013b03          	ld	s6,48(sp)
    80005288:	02813b83          	ld	s7,40(sp)
    8000528c:	07010113          	addi	sp,sp,112
    80005290:	00008067          	ret
  for (tot = 0; tot < n; tot += m, off += m, src += m)
    80005294:	000b0993          	mv	s3,s6
    80005298:	fc9ff06f          	j	80005260 <writei+0x124>
    8000529c:	05813483          	ld	s1,88(sp)
    800052a0:	02013c03          	ld	s8,32(sp)
    800052a4:	01813c83          	ld	s9,24(sp)
    800052a8:	01013d03          	ld	s10,16(sp)
    800052ac:	00813d83          	ld	s11,8(sp)
    800052b0:	fb1ff06f          	j	80005260 <writei+0x124>
    return -1;
    800052b4:	fff00513          	li	a0,-1
}
    800052b8:	00008067          	ret
    return -1;
    800052bc:	fff00513          	li	a0,-1
    800052c0:	fb1ff06f          	j	80005270 <writei+0x134>

00000000800052c4 <namecmp>:

// Directories

int namecmp(const char *s, const char *t)
{
    800052c4:	ff010113          	addi	sp,sp,-16
    800052c8:	00113423          	sd	ra,8(sp)
    800052cc:	00813023          	sd	s0,0(sp)
    800052d0:	01010413          	addi	s0,sp,16
  return strncmp(s, t, DIRSIZ);
    800052d4:	00e00613          	li	a2,14
    800052d8:	850fc0ef          	jal	80001328 <strncmp>
}
    800052dc:	00813083          	ld	ra,8(sp)
    800052e0:	00013403          	ld	s0,0(sp)
    800052e4:	01010113          	addi	sp,sp,16
    800052e8:	00008067          	ret

00000000800052ec <dirlookup>:

// Look for a directory entry in a directory.
// If found, set *poff to byte offset of entry.
struct inode *
dirlookup(struct inode *dp, char *name, uint *poff)
{
    800052ec:	fa010113          	addi	sp,sp,-96
    800052f0:	04113c23          	sd	ra,88(sp)
    800052f4:	04813823          	sd	s0,80(sp)
    800052f8:	04913423          	sd	s1,72(sp)
    800052fc:	05213023          	sd	s2,64(sp)
    80005300:	03313c23          	sd	s3,56(sp)
    80005304:	03413823          	sd	s4,48(sp)
    80005308:	03513423          	sd	s5,40(sp)
    8000530c:	03613023          	sd	s6,32(sp)
    80005310:	01713c23          	sd	s7,24(sp)
    80005314:	06010413          	addi	s0,sp,96
  uint off, inum;
  struct dirent de;

  if (dp->type != T_DIR)
    80005318:	04451703          	lh	a4,68(a0)
    8000531c:	00100793          	li	a5,1
    80005320:	02f71863          	bne	a4,a5,80005350 <dirlookup+0x64>
    80005324:	00050913          	mv	s2,a0
    80005328:	00058a93          	mv	s5,a1
    8000532c:	00060b93          	mv	s7,a2
    panic("dirlookup not DIR");

  for (off = 0; off < dp->size; off += sizeof(de))
    80005330:	04c52783          	lw	a5,76(a0)
    80005334:	00000493          	li	s1,0
  {
    if (readi(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    80005338:	fa040a13          	addi	s4,s0,-96
    8000533c:	01000993          	li	s3,16
      panic("dirlookup read");
    if (de.inum == 0)
      continue;
    if (namecmp(name, de.name) == 0)
    80005340:	fa240b13          	addi	s6,s0,-94
      inum = de.inum;
      return iget(dp->dev, inum);
    }
  }

  return 0;
    80005344:	00000513          	li	a0,0
  for (off = 0; off < dp->size; off += sizeof(de))
    80005348:	02079663          	bnez	a5,80005374 <dirlookup+0x88>
    8000534c:	0780006f          	j	800053c4 <dirlookup+0xd8>
    panic("dirlookup not DIR");
    80005350:	00004517          	auipc	a0,0x4
    80005354:	54850513          	addi	a0,a0,1352 # 80009898 <etext+0x898>
    80005358:	f94fb0ef          	jal	80000aec <panic>
      panic("dirlookup read");
    8000535c:	00004517          	auipc	a0,0x4
    80005360:	55450513          	addi	a0,a0,1364 # 800098b0 <etext+0x8b0>
    80005364:	f88fb0ef          	jal	80000aec <panic>
  for (off = 0; off < dp->size; off += sizeof(de))
    80005368:	0104849b          	addiw	s1,s1,16
    8000536c:	04c92783          	lw	a5,76(s2)
    80005370:	04f4f863          	bgeu	s1,a5,800053c0 <dirlookup+0xd4>
    if (readi(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    80005374:	00098713          	mv	a4,s3
    80005378:	00048693          	mv	a3,s1
    8000537c:	000a0613          	mv	a2,s4
    80005380:	00000593          	li	a1,0
    80005384:	00090513          	mv	a0,s2
    80005388:	c31ff0ef          	jal	80004fb8 <readi>
    8000538c:	fd3518e3          	bne	a0,s3,8000535c <dirlookup+0x70>
    if (de.inum == 0)
    80005390:	fa045783          	lhu	a5,-96(s0)
    80005394:	fc078ae3          	beqz	a5,80005368 <dirlookup+0x7c>
    if (namecmp(name, de.name) == 0)
    80005398:	000b0593          	mv	a1,s6
    8000539c:	000a8513          	mv	a0,s5
    800053a0:	f25ff0ef          	jal	800052c4 <namecmp>
    800053a4:	fc0512e3          	bnez	a0,80005368 <dirlookup+0x7c>
      if (poff)
    800053a8:	000b8463          	beqz	s7,800053b0 <dirlookup+0xc4>
        *poff = off;
    800053ac:	009ba023          	sw	s1,0(s7)
      return iget(dp->dev, inum);
    800053b0:	fa045583          	lhu	a1,-96(s0)
    800053b4:	00092503          	lw	a0,0(s2)
    800053b8:	b40ff0ef          	jal	800046f8 <iget>
    800053bc:	0080006f          	j	800053c4 <dirlookup+0xd8>
  return 0;
    800053c0:	00000513          	li	a0,0
}
    800053c4:	05813083          	ld	ra,88(sp)
    800053c8:	05013403          	ld	s0,80(sp)
    800053cc:	04813483          	ld	s1,72(sp)
    800053d0:	04013903          	ld	s2,64(sp)
    800053d4:	03813983          	ld	s3,56(sp)
    800053d8:	03013a03          	ld	s4,48(sp)
    800053dc:	02813a83          	ld	s5,40(sp)
    800053e0:	02013b03          	ld	s6,32(sp)
    800053e4:	01813b83          	ld	s7,24(sp)
    800053e8:	06010113          	addi	sp,sp,96
    800053ec:	00008067          	ret

00000000800053f0 <namex>:
// If parent != 0, return the inode for the parent and copy the final
// path element into name, which must have room for DIRSIZ bytes.
// Must be called inside a transaction since it calls iput().
static struct inode *
namex(char *path, int nameiparent, char *name)
{
    800053f0:	fa010113          	addi	sp,sp,-96
    800053f4:	04113c23          	sd	ra,88(sp)
    800053f8:	04813823          	sd	s0,80(sp)
    800053fc:	04913423          	sd	s1,72(sp)
    80005400:	05213023          	sd	s2,64(sp)
    80005404:	03313c23          	sd	s3,56(sp)
    80005408:	03413823          	sd	s4,48(sp)
    8000540c:	03513423          	sd	s5,40(sp)
    80005410:	03613023          	sd	s6,32(sp)
    80005414:	01713c23          	sd	s7,24(sp)
    80005418:	01813823          	sd	s8,16(sp)
    8000541c:	01913423          	sd	s9,8(sp)
    80005420:	01a13023          	sd	s10,0(sp)
    80005424:	06010413          	addi	s0,sp,96
    80005428:	00050493          	mv	s1,a0
    8000542c:	00058b13          	mv	s6,a1
    80005430:	00060a93          	mv	s5,a2
  struct inode *ip, *next;

  if (*path == '/')
    80005434:	00054703          	lbu	a4,0(a0)
    80005438:	02f00793          	li	a5,47
    8000543c:	02f70463          	beq	a4,a5,80005464 <namex+0x74>
    ip = iget(ROOTDEV, ROOTINO);
  else
    ip = idup(myproc()->cwd);
    80005440:	9b4fd0ef          	jal	800025f4 <myproc>
    80005444:	15053503          	ld	a0,336(a0)
    80005448:	dd4ff0ef          	jal	80004a1c <idup>
    8000544c:	00050a13          	mv	s4,a0
  while (*path == '/')
    80005450:	02f00993          	li	s3,47
  if (len >= DIRSIZ)
    80005454:	00d00c13          	li	s8,13
    memmove(name, s, DIRSIZ);
    80005458:	00e00c93          	li	s9,14

  while ((path = skipelem(path, name)) != 0)
  {
    ilock(ip);
    if (ip->type != T_DIR)
    8000545c:	00100b93          	li	s7,1
    80005460:	0f00006f          	j	80005550 <namex+0x160>
    ip = iget(ROOTDEV, ROOTINO);
    80005464:	00100593          	li	a1,1
    80005468:	00058513          	mv	a0,a1
    8000546c:	a8cff0ef          	jal	800046f8 <iget>
    80005470:	00050a13          	mv	s4,a0
    80005474:	fddff06f          	j	80005450 <namex+0x60>
    {
      iunlockput(ip);
    80005478:	000a0513          	mv	a0,s4
    8000547c:	8e1ff0ef          	jal	80004d5c <iunlockput>
      return 0;
    80005480:	00000a13          	li	s4,0
  {
    iput(ip);
    return 0;
  }
  return ip;
}
    80005484:	000a0513          	mv	a0,s4
    80005488:	05813083          	ld	ra,88(sp)
    8000548c:	05013403          	ld	s0,80(sp)
    80005490:	04813483          	ld	s1,72(sp)
    80005494:	04013903          	ld	s2,64(sp)
    80005498:	03813983          	ld	s3,56(sp)
    8000549c:	03013a03          	ld	s4,48(sp)
    800054a0:	02813a83          	ld	s5,40(sp)
    800054a4:	02013b03          	ld	s6,32(sp)
    800054a8:	01813b83          	ld	s7,24(sp)
    800054ac:	01013c03          	ld	s8,16(sp)
    800054b0:	00813c83          	ld	s9,8(sp)
    800054b4:	00013d03          	ld	s10,0(sp)
    800054b8:	06010113          	addi	sp,sp,96
    800054bc:	00008067          	ret
      iunlock(ip);
    800054c0:	000a0513          	mv	a0,s4
    800054c4:	ea0ff0ef          	jal	80004b64 <iunlock>
      return ip;
    800054c8:	fbdff06f          	j	80005484 <namex+0x94>
      iunlockput(ip);
    800054cc:	000a0513          	mv	a0,s4
    800054d0:	88dff0ef          	jal	80004d5c <iunlockput>
      return 0;
    800054d4:	00090a13          	mv	s4,s2
    800054d8:	fadff06f          	j	80005484 <namex+0x94>
  len = path - s;
    800054dc:	40990633          	sub	a2,s2,s1
    800054e0:	00060d1b          	sext.w	s10,a2
  if (len >= DIRSIZ)
    800054e4:	0bac5e63          	bge	s8,s10,800055a0 <namex+0x1b0>
    memmove(name, s, DIRSIZ);
    800054e8:	000c8613          	mv	a2,s9
    800054ec:	00048593          	mv	a1,s1
    800054f0:	000a8513          	mv	a0,s5
    800054f4:	d85fb0ef          	jal	80001278 <memmove>
    800054f8:	00090493          	mv	s1,s2
  while (*path == '/')
    800054fc:	0004c783          	lbu	a5,0(s1)
    80005500:	01379863          	bne	a5,s3,80005510 <namex+0x120>
    path++;
    80005504:	00148493          	addi	s1,s1,1
  while (*path == '/')
    80005508:	0004c783          	lbu	a5,0(s1)
    8000550c:	ff378ce3          	beq	a5,s3,80005504 <namex+0x114>
    ilock(ip);
    80005510:	000a0513          	mv	a0,s4
    80005514:	d5cff0ef          	jal	80004a70 <ilock>
    if (ip->type != T_DIR)
    80005518:	044a1783          	lh	a5,68(s4)
    8000551c:	f5779ee3          	bne	a5,s7,80005478 <namex+0x88>
    if (nameiparent && *path == '\0')
    80005520:	000b0663          	beqz	s6,8000552c <namex+0x13c>
    80005524:	0004c783          	lbu	a5,0(s1)
    80005528:	f8078ce3          	beqz	a5,800054c0 <namex+0xd0>
    if ((next = dirlookup(ip, name, 0)) == 0)
    8000552c:	00000613          	li	a2,0
    80005530:	000a8593          	mv	a1,s5
    80005534:	000a0513          	mv	a0,s4
    80005538:	db5ff0ef          	jal	800052ec <dirlookup>
    8000553c:	00050913          	mv	s2,a0
    80005540:	f80506e3          	beqz	a0,800054cc <namex+0xdc>
    iunlockput(ip);
    80005544:	000a0513          	mv	a0,s4
    80005548:	815ff0ef          	jal	80004d5c <iunlockput>
    ip = next;
    8000554c:	00090a13          	mv	s4,s2
  while (*path == '/')
    80005550:	0004c783          	lbu	a5,0(s1)
    80005554:	01379863          	bne	a5,s3,80005564 <namex+0x174>
    path++;
    80005558:	00148493          	addi	s1,s1,1
  while (*path == '/')
    8000555c:	0004c783          	lbu	a5,0(s1)
    80005560:	ff378ce3          	beq	a5,s3,80005558 <namex+0x168>
  if (*path == 0)
    80005564:	04078e63          	beqz	a5,800055c0 <namex+0x1d0>
  while (*path != '/' && *path != 0)
    80005568:	0004c783          	lbu	a5,0(s1)
    8000556c:	fd178713          	addi	a4,a5,-47
    80005570:	02070263          	beqz	a4,80005594 <namex+0x1a4>
    80005574:	02078063          	beqz	a5,80005594 <namex+0x1a4>
    80005578:	00048913          	mv	s2,s1
    path++;
    8000557c:	00190913          	addi	s2,s2,1
  while (*path != '/' && *path != 0)
    80005580:	00094783          	lbu	a5,0(s2)
    80005584:	fd178713          	addi	a4,a5,-47
    80005588:	f4070ae3          	beqz	a4,800054dc <namex+0xec>
    8000558c:	fe0798e3          	bnez	a5,8000557c <namex+0x18c>
    80005590:	f4dff06f          	j	800054dc <namex+0xec>
    80005594:	00048913          	mv	s2,s1
  len = path - s;
    80005598:	00000d13          	li	s10,0
    8000559c:	00000613          	li	a2,0
    memmove(name, s, len);
    800055a0:	0006061b          	sext.w	a2,a2
    800055a4:	00048593          	mv	a1,s1
    800055a8:	000a8513          	mv	a0,s5
    800055ac:	ccdfb0ef          	jal	80001278 <memmove>
    name[len] = 0;
    800055b0:	01aa8d33          	add	s10,s5,s10
    800055b4:	000d0023          	sb	zero,0(s10) # fffffffffffff000 <end+0xffffffff7fbf42a0>
    800055b8:	00090493          	mv	s1,s2
    800055bc:	f41ff06f          	j	800054fc <namex+0x10c>
  if (nameiparent)
    800055c0:	ec0b02e3          	beqz	s6,80005484 <namex+0x94>
    iput(ip);
    800055c4:	000a0513          	mv	a0,s4
    800055c8:	ed4ff0ef          	jal	80004c9c <iput>
    return 0;
    800055cc:	00000a13          	li	s4,0
    800055d0:	eb5ff06f          	j	80005484 <namex+0x94>

00000000800055d4 <dirlink>:
{
    800055d4:	fb010113          	addi	sp,sp,-80
    800055d8:	04113423          	sd	ra,72(sp)
    800055dc:	04813023          	sd	s0,64(sp)
    800055e0:	03213823          	sd	s2,48(sp)
    800055e4:	01513c23          	sd	s5,24(sp)
    800055e8:	01613823          	sd	s6,16(sp)
    800055ec:	05010413          	addi	s0,sp,80
    800055f0:	00050913          	mv	s2,a0
    800055f4:	00058a93          	mv	s5,a1
    800055f8:	00060b13          	mv	s6,a2
  if ((ip = dirlookup(dp, name, 0)) != 0)
    800055fc:	00000613          	li	a2,0
    80005600:	cedff0ef          	jal	800052ec <dirlookup>
    80005604:	06051063          	bnez	a0,80005664 <dirlink+0x90>
    80005608:	02913c23          	sd	s1,56(sp)
  for (off = 0; off < dp->size; off += sizeof(de))
    8000560c:	04c92483          	lw	s1,76(s2)
    80005610:	06048a63          	beqz	s1,80005684 <dirlink+0xb0>
    80005614:	03313423          	sd	s3,40(sp)
    80005618:	03413023          	sd	s4,32(sp)
    8000561c:	00000493          	li	s1,0
    if (readi(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    80005620:	fb040a13          	addi	s4,s0,-80
    80005624:	01000993          	li	s3,16
    80005628:	00098713          	mv	a4,s3
    8000562c:	00048693          	mv	a3,s1
    80005630:	000a0613          	mv	a2,s4
    80005634:	00000593          	li	a1,0
    80005638:	00090513          	mv	a0,s2
    8000563c:	97dff0ef          	jal	80004fb8 <readi>
    80005640:	03351863          	bne	a0,s3,80005670 <dirlink+0x9c>
    if (de.inum == 0)
    80005644:	fb045783          	lhu	a5,-80(s0)
    80005648:	02078a63          	beqz	a5,8000567c <dirlink+0xa8>
  for (off = 0; off < dp->size; off += sizeof(de))
    8000564c:	0104849b          	addiw	s1,s1,16
    80005650:	04c92783          	lw	a5,76(s2)
    80005654:	fcf4eae3          	bltu	s1,a5,80005628 <dirlink+0x54>
    80005658:	02813983          	ld	s3,40(sp)
    8000565c:	02013a03          	ld	s4,32(sp)
    80005660:	0240006f          	j	80005684 <dirlink+0xb0>
    iput(ip);
    80005664:	e38ff0ef          	jal	80004c9c <iput>
    return -1;
    80005668:	fff00513          	li	a0,-1
    8000566c:	0540006f          	j	800056c0 <dirlink+0xec>
      panic("dirlink read");
    80005670:	00004517          	auipc	a0,0x4
    80005674:	25050513          	addi	a0,a0,592 # 800098c0 <etext+0x8c0>
    80005678:	c74fb0ef          	jal	80000aec <panic>
    8000567c:	02813983          	ld	s3,40(sp)
    80005680:	02013a03          	ld	s4,32(sp)
  strncpy(de.name, name, DIRSIZ);
    80005684:	00e00613          	li	a2,14
    80005688:	000a8593          	mv	a1,s5
    8000568c:	fb240513          	addi	a0,s0,-78
    80005690:	cf9fb0ef          	jal	80001388 <strncpy>
  de.inum = inum;
    80005694:	fb641823          	sh	s6,-80(s0)
  if (writei(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    80005698:	01000713          	li	a4,16
    8000569c:	00048693          	mv	a3,s1
    800056a0:	fb040613          	addi	a2,s0,-80
    800056a4:	00000593          	li	a1,0
    800056a8:	00090513          	mv	a0,s2
    800056ac:	a91ff0ef          	jal	8000513c <writei>
    800056b0:	ff050513          	addi	a0,a0,-16
    800056b4:	00a03533          	snez	a0,a0
    800056b8:	40a0053b          	negw	a0,a0
    800056bc:	03813483          	ld	s1,56(sp)
}
    800056c0:	04813083          	ld	ra,72(sp)
    800056c4:	04013403          	ld	s0,64(sp)
    800056c8:	03013903          	ld	s2,48(sp)
    800056cc:	01813a83          	ld	s5,24(sp)
    800056d0:	01013b03          	ld	s6,16(sp)
    800056d4:	05010113          	addi	sp,sp,80
    800056d8:	00008067          	ret

00000000800056dc <namei>:

struct inode *
namei(char *path)
{
    800056dc:	fe010113          	addi	sp,sp,-32
    800056e0:	00113c23          	sd	ra,24(sp)
    800056e4:	00813823          	sd	s0,16(sp)
    800056e8:	02010413          	addi	s0,sp,32
  char name[DIRSIZ];
  return namex(path, 0, name);
    800056ec:	fe040613          	addi	a2,s0,-32
    800056f0:	00000593          	li	a1,0
    800056f4:	cfdff0ef          	jal	800053f0 <namex>
}
    800056f8:	01813083          	ld	ra,24(sp)
    800056fc:	01013403          	ld	s0,16(sp)
    80005700:	02010113          	addi	sp,sp,32
    80005704:	00008067          	ret

0000000080005708 <nameiparent>:

struct inode *
nameiparent(char *path, char *name)
{
    80005708:	ff010113          	addi	sp,sp,-16
    8000570c:	00113423          	sd	ra,8(sp)
    80005710:	00813023          	sd	s0,0(sp)
    80005714:	01010413          	addi	s0,sp,16
    80005718:	00058613          	mv	a2,a1
  return namex(path, 1, name);
    8000571c:	00100593          	li	a1,1
    80005720:	cd1ff0ef          	jal	800053f0 <namex>
}
    80005724:	00813083          	ld	ra,8(sp)
    80005728:	00013403          	ld	s0,0(sp)
    8000572c:	01010113          	addi	sp,sp,16
    80005730:	00008067          	ret

0000000080005734 <write_head>:
// Write in-memory log header to disk.
// This is the true point at which the
// current transaction commits.
static void
write_head(void)
{
    80005734:	fe010113          	addi	sp,sp,-32
    80005738:	00113c23          	sd	ra,24(sp)
    8000573c:	00813823          	sd	s0,16(sp)
    80005740:	00913423          	sd	s1,8(sp)
    80005744:	01213023          	sd	s2,0(sp)
    80005748:	02010413          	addi	s0,sp,32
  struct buf *buf = bread(log.dev, log.start);
    8000574c:	00210917          	auipc	s2,0x210
    80005750:	4fc90913          	addi	s2,s2,1276 # 80215c48 <log>
    80005754:	01892583          	lw	a1,24(s2)
    80005758:	02492503          	lw	a0,36(s2)
    8000575c:	99dfe0ef          	jal	800040f8 <bread>
    80005760:	00050493          	mv	s1,a0
  struct logheader *hb = (struct logheader *) (buf->data);
  int i;
  hb->n = log.lh.n;
    80005764:	02892603          	lw	a2,40(s2)
    80005768:	04c52c23          	sw	a2,88(a0)
  for (i = 0; i < log.lh.n; i++) {
    8000576c:	02c05663          	blez	a2,80005798 <write_head+0x64>
    80005770:	00210717          	auipc	a4,0x210
    80005774:	50470713          	addi	a4,a4,1284 # 80215c74 <log+0x2c>
    80005778:	00050793          	mv	a5,a0
    8000577c:	00261613          	slli	a2,a2,0x2
    80005780:	00a60633          	add	a2,a2,a0
    hb->block[i] = log.lh.block[i];
    80005784:	00072683          	lw	a3,0(a4)
    80005788:	04d7ae23          	sw	a3,92(a5)
  for (i = 0; i < log.lh.n; i++) {
    8000578c:	00470713          	addi	a4,a4,4
    80005790:	00478793          	addi	a5,a5,4
    80005794:	fec798e3          	bne	a5,a2,80005784 <write_head+0x50>
  }
  bwrite(buf);
    80005798:	00048513          	mv	a0,s1
    8000579c:	a81fe0ef          	jal	8000421c <bwrite>
  brelse(buf);
    800057a0:	00048513          	mv	a0,s1
    800057a4:	ac9fe0ef          	jal	8000426c <brelse>
}
    800057a8:	01813083          	ld	ra,24(sp)
    800057ac:	01013403          	ld	s0,16(sp)
    800057b0:	00813483          	ld	s1,8(sp)
    800057b4:	00013903          	ld	s2,0(sp)
    800057b8:	02010113          	addi	sp,sp,32
    800057bc:	00008067          	ret

00000000800057c0 <install_trans>:
  for (tail = 0; tail < log.lh.n; tail++) {
    800057c0:	00210797          	auipc	a5,0x210
    800057c4:	4b07a783          	lw	a5,1200(a5) # 80215c70 <log+0x28>
    800057c8:	10f05a63          	blez	a5,800058dc <install_trans+0x11c>
{
    800057cc:	fb010113          	addi	sp,sp,-80
    800057d0:	04113423          	sd	ra,72(sp)
    800057d4:	04813023          	sd	s0,64(sp)
    800057d8:	02913c23          	sd	s1,56(sp)
    800057dc:	03213823          	sd	s2,48(sp)
    800057e0:	03313423          	sd	s3,40(sp)
    800057e4:	03413023          	sd	s4,32(sp)
    800057e8:	01513c23          	sd	s5,24(sp)
    800057ec:	01613823          	sd	s6,16(sp)
    800057f0:	01713423          	sd	s7,8(sp)
    800057f4:	01813023          	sd	s8,0(sp)
    800057f8:	05010413          	addi	s0,sp,80
    800057fc:	00050b13          	mv	s6,a0
    80005800:	00210a97          	auipc	s5,0x210
    80005804:	474a8a93          	addi	s5,s5,1140 # 80215c74 <log+0x2c>
  for (tail = 0; tail < log.lh.n; tail++) {
    80005808:	00000993          	li	s3,0
      printf("recovering tail %d dst %d\n", tail, log.lh.block[tail]);
    8000580c:	00004c17          	auipc	s8,0x4
    80005810:	0c4c0c13          	addi	s8,s8,196 # 800098d0 <etext+0x8d0>
    struct buf *lbuf = bread(log.dev, log.start+tail+1); // read log block
    80005814:	00210a17          	auipc	s4,0x210
    80005818:	434a0a13          	addi	s4,s4,1076 # 80215c48 <log>
    memmove(dbuf->data, lbuf->data, BSIZE);  // copy block to dst
    8000581c:	40000b93          	li	s7,1024
    80005820:	0380006f          	j	80005858 <install_trans+0x98>
      printf("recovering tail %d dst %d\n", tail, log.lh.block[tail]);
    80005824:	000aa603          	lw	a2,0(s5)
    80005828:	00098593          	mv	a1,s3
    8000582c:	000c0513          	mv	a0,s8
    80005830:	e9dfa0ef          	jal	800006cc <printf>
    80005834:	0280006f          	j	8000585c <install_trans+0x9c>
    brelse(lbuf);
    80005838:	00090513          	mv	a0,s2
    8000583c:	a31fe0ef          	jal	8000426c <brelse>
    brelse(dbuf);
    80005840:	00048513          	mv	a0,s1
    80005844:	a29fe0ef          	jal	8000426c <brelse>
  for (tail = 0; tail < log.lh.n; tail++) {
    80005848:	0019899b          	addiw	s3,s3,1
    8000584c:	004a8a93          	addi	s5,s5,4
    80005850:	028a2783          	lw	a5,40(s4)
    80005854:	04f9dc63          	bge	s3,a5,800058ac <install_trans+0xec>
    if(recovering) {
    80005858:	fc0b16e3          	bnez	s6,80005824 <install_trans+0x64>
    struct buf *lbuf = bread(log.dev, log.start+tail+1); // read log block
    8000585c:	018a2583          	lw	a1,24(s4)
    80005860:	013585bb          	addw	a1,a1,s3
    80005864:	0015859b          	addiw	a1,a1,1
    80005868:	024a2503          	lw	a0,36(s4)
    8000586c:	88dfe0ef          	jal	800040f8 <bread>
    80005870:	00050913          	mv	s2,a0
    struct buf *dbuf = bread(log.dev, log.lh.block[tail]); // read dst
    80005874:	000aa583          	lw	a1,0(s5)
    80005878:	024a2503          	lw	a0,36(s4)
    8000587c:	87dfe0ef          	jal	800040f8 <bread>
    80005880:	00050493          	mv	s1,a0
    memmove(dbuf->data, lbuf->data, BSIZE);  // copy block to dst
    80005884:	000b8613          	mv	a2,s7
    80005888:	05890593          	addi	a1,s2,88
    8000588c:	05850513          	addi	a0,a0,88
    80005890:	9e9fb0ef          	jal	80001278 <memmove>
    bwrite(dbuf);  // write dst to disk
    80005894:	00048513          	mv	a0,s1
    80005898:	985fe0ef          	jal	8000421c <bwrite>
    if(recovering == 0)
    8000589c:	f80b1ee3          	bnez	s6,80005838 <install_trans+0x78>
      bunpin(dbuf);
    800058a0:	00048513          	mv	a0,s1
    800058a4:	ad5fe0ef          	jal	80004378 <bunpin>
    800058a8:	f91ff06f          	j	80005838 <install_trans+0x78>
}
    800058ac:	04813083          	ld	ra,72(sp)
    800058b0:	04013403          	ld	s0,64(sp)
    800058b4:	03813483          	ld	s1,56(sp)
    800058b8:	03013903          	ld	s2,48(sp)
    800058bc:	02813983          	ld	s3,40(sp)
    800058c0:	02013a03          	ld	s4,32(sp)
    800058c4:	01813a83          	ld	s5,24(sp)
    800058c8:	01013b03          	ld	s6,16(sp)
    800058cc:	00813b83          	ld	s7,8(sp)
    800058d0:	00013c03          	ld	s8,0(sp)
    800058d4:	05010113          	addi	sp,sp,80
    800058d8:	00008067          	ret
    800058dc:	00008067          	ret

00000000800058e0 <initlog>:
{
    800058e0:	fd010113          	addi	sp,sp,-48
    800058e4:	02113423          	sd	ra,40(sp)
    800058e8:	02813023          	sd	s0,32(sp)
    800058ec:	00913c23          	sd	s1,24(sp)
    800058f0:	01213823          	sd	s2,16(sp)
    800058f4:	01313423          	sd	s3,8(sp)
    800058f8:	03010413          	addi	s0,sp,48
    800058fc:	00050493          	mv	s1,a0
    80005900:	00058993          	mv	s3,a1
  initlock(&log.lock, "log");
    80005904:	00210917          	auipc	s2,0x210
    80005908:	34490913          	addi	s2,s2,836 # 80215c48 <log>
    8000590c:	00004597          	auipc	a1,0x4
    80005910:	fe458593          	addi	a1,a1,-28 # 800098f0 <etext+0x8f0>
    80005914:	00090513          	mv	a0,s2
    80005918:	e44fb0ef          	jal	80000f5c <initlock>
  log.start = sb->logstart;
    8000591c:	0149a583          	lw	a1,20(s3)
    80005920:	00b92c23          	sw	a1,24(s2)
  log.dev = dev;
    80005924:	02992223          	sw	s1,36(s2)
  struct buf *buf = bread(log.dev, log.start);
    80005928:	00048513          	mv	a0,s1
    8000592c:	fccfe0ef          	jal	800040f8 <bread>
  log.lh.n = lh->n;
    80005930:	05852603          	lw	a2,88(a0)
    80005934:	02c92423          	sw	a2,40(s2)
  for (i = 0; i < log.lh.n; i++) {
    80005938:	02c05663          	blez	a2,80005964 <initlog+0x84>
    8000593c:	00050793          	mv	a5,a0
    80005940:	00210717          	auipc	a4,0x210
    80005944:	33470713          	addi	a4,a4,820 # 80215c74 <log+0x2c>
    80005948:	00261613          	slli	a2,a2,0x2
    8000594c:	00a60633          	add	a2,a2,a0
    log.lh.block[i] = lh->block[i];
    80005950:	05c7a683          	lw	a3,92(a5)
    80005954:	00d72023          	sw	a3,0(a4)
  for (i = 0; i < log.lh.n; i++) {
    80005958:	00478793          	addi	a5,a5,4
    8000595c:	00470713          	addi	a4,a4,4
    80005960:	fec798e3          	bne	a5,a2,80005950 <initlog+0x70>
  brelse(buf);
    80005964:	909fe0ef          	jal	8000426c <brelse>

static void
recover_from_log(void)
{
  read_head();
  install_trans(1); // if committed, copy from log to disk
    80005968:	00100513          	li	a0,1
    8000596c:	e55ff0ef          	jal	800057c0 <install_trans>
  log.lh.n = 0;
    80005970:	00210797          	auipc	a5,0x210
    80005974:	3007a023          	sw	zero,768(a5) # 80215c70 <log+0x28>
  write_head(); // clear the log
    80005978:	dbdff0ef          	jal	80005734 <write_head>
}
    8000597c:	02813083          	ld	ra,40(sp)
    80005980:	02013403          	ld	s0,32(sp)
    80005984:	01813483          	ld	s1,24(sp)
    80005988:	01013903          	ld	s2,16(sp)
    8000598c:	00813983          	ld	s3,8(sp)
    80005990:	03010113          	addi	sp,sp,48
    80005994:	00008067          	ret

0000000080005998 <begin_op>:
}

// called at the start of each FS system call.
void
begin_op(void)
{
    80005998:	fe010113          	addi	sp,sp,-32
    8000599c:	00113c23          	sd	ra,24(sp)
    800059a0:	00813823          	sd	s0,16(sp)
    800059a4:	00913423          	sd	s1,8(sp)
    800059a8:	01213023          	sd	s2,0(sp)
    800059ac:	02010413          	addi	s0,sp,32
  acquire(&log.lock);
    800059b0:	00210517          	auipc	a0,0x210
    800059b4:	29850513          	addi	a0,a0,664 # 80215c48 <log>
    800059b8:	e88fb0ef          	jal	80001040 <acquire>
  while(1){
    if(log.committing){
    800059bc:	00210497          	auipc	s1,0x210
    800059c0:	28c48493          	addi	s1,s1,652 # 80215c48 <log>
      sleep(&log, &log.lock);
    } else if(log.lh.n + (log.outstanding+1)*MAXOPBLOCKS > LOGBLOCKS){
    800059c4:	01e00913          	li	s2,30
    800059c8:	0100006f          	j	800059d8 <begin_op+0x40>
      sleep(&log, &log.lock);
    800059cc:	00048593          	mv	a1,s1
    800059d0:	00048513          	mv	a0,s1
    800059d4:	d2cfd0ef          	jal	80002f00 <sleep>
    if(log.committing){
    800059d8:	0204a783          	lw	a5,32(s1)
    800059dc:	fe0798e3          	bnez	a5,800059cc <begin_op+0x34>
    } else if(log.lh.n + (log.outstanding+1)*MAXOPBLOCKS > LOGBLOCKS){
    800059e0:	01c4a703          	lw	a4,28(s1)
    800059e4:	0017071b          	addiw	a4,a4,1
    800059e8:	0027179b          	slliw	a5,a4,0x2
    800059ec:	00e787bb          	addw	a5,a5,a4
    800059f0:	0017979b          	slliw	a5,a5,0x1
    800059f4:	0284a683          	lw	a3,40(s1)
    800059f8:	00f687bb          	addw	a5,a3,a5
    800059fc:	00f95a63          	bge	s2,a5,80005a10 <begin_op+0x78>
      // this op might exhaust log space; wait for commit.
      sleep(&log, &log.lock);
    80005a00:	00048593          	mv	a1,s1
    80005a04:	00048513          	mv	a0,s1
    80005a08:	cf8fd0ef          	jal	80002f00 <sleep>
    80005a0c:	fcdff06f          	j	800059d8 <begin_op+0x40>
    } else {
      log.outstanding += 1;
    80005a10:	00210797          	auipc	a5,0x210
    80005a14:	24e7aa23          	sw	a4,596(a5) # 80215c64 <log+0x1c>
      release(&log.lock);
    80005a18:	00210517          	auipc	a0,0x210
    80005a1c:	23050513          	addi	a0,a0,560 # 80215c48 <log>
    80005a20:	ef8fb0ef          	jal	80001118 <release>
      break;
    }
  }
}
    80005a24:	01813083          	ld	ra,24(sp)
    80005a28:	01013403          	ld	s0,16(sp)
    80005a2c:	00813483          	ld	s1,8(sp)
    80005a30:	00013903          	ld	s2,0(sp)
    80005a34:	02010113          	addi	sp,sp,32
    80005a38:	00008067          	ret

0000000080005a3c <end_op>:

// called at the end of each FS system call.
// commits if this was the last outstanding operation.
void
end_op(void)
{
    80005a3c:	fc010113          	addi	sp,sp,-64
    80005a40:	02113c23          	sd	ra,56(sp)
    80005a44:	02813823          	sd	s0,48(sp)
    80005a48:	02913423          	sd	s1,40(sp)
    80005a4c:	03213023          	sd	s2,32(sp)
    80005a50:	04010413          	addi	s0,sp,64
  int do_commit = 0;

  acquire(&log.lock);
    80005a54:	00210497          	auipc	s1,0x210
    80005a58:	1f448493          	addi	s1,s1,500 # 80215c48 <log>
    80005a5c:	00048513          	mv	a0,s1
    80005a60:	de0fb0ef          	jal	80001040 <acquire>
  log.outstanding -= 1;
    80005a64:	01c4a783          	lw	a5,28(s1)
    80005a68:	fff7879b          	addiw	a5,a5,-1
    80005a6c:	00078913          	mv	s2,a5
    80005a70:	00f4ae23          	sw	a5,28(s1)
  if(log.committing)
    80005a74:	0204a783          	lw	a5,32(s1)
    80005a78:	04079c63          	bnez	a5,80005ad0 <end_op+0x94>
    panic("log.committing");
  if(log.outstanding == 0){
    80005a7c:	06091663          	bnez	s2,80005ae8 <end_op+0xac>
    do_commit = 1;
    log.committing = 1;
    80005a80:	00210497          	auipc	s1,0x210
    80005a84:	1c848493          	addi	s1,s1,456 # 80215c48 <log>
    80005a88:	00100793          	li	a5,1
    80005a8c:	02f4a023          	sw	a5,32(s1)
    // begin_op() may be waiting for log space,
    // and decrementing log.outstanding has decreased
    // the amount of reserved space.
    wakeup(&log);
  }
  release(&log.lock);
    80005a90:	00048513          	mv	a0,s1
    80005a94:	e84fb0ef          	jal	80001118 <release>
}

static void
commit()
{
  if (log.lh.n > 0) {
    80005a98:	0284a783          	lw	a5,40(s1)
    80005a9c:	06f04e63          	bgtz	a5,80005b18 <end_op+0xdc>
    acquire(&log.lock);
    80005aa0:	00210517          	auipc	a0,0x210
    80005aa4:	1a850513          	addi	a0,a0,424 # 80215c48 <log>
    80005aa8:	d98fb0ef          	jal	80001040 <acquire>
    log.committing = 0;
    80005aac:	00210797          	auipc	a5,0x210
    80005ab0:	1a07ae23          	sw	zero,444(a5) # 80215c68 <log+0x20>
    wakeup(&log);
    80005ab4:	00210517          	auipc	a0,0x210
    80005ab8:	19450513          	addi	a0,a0,404 # 80215c48 <log>
    80005abc:	cbcfd0ef          	jal	80002f78 <wakeup>
    release(&log.lock);
    80005ac0:	00210517          	auipc	a0,0x210
    80005ac4:	18850513          	addi	a0,a0,392 # 80215c48 <log>
    80005ac8:	e50fb0ef          	jal	80001118 <release>
}
    80005acc:	0340006f          	j	80005b00 <end_op+0xc4>
    80005ad0:	01313c23          	sd	s3,24(sp)
    80005ad4:	01413823          	sd	s4,16(sp)
    80005ad8:	01513423          	sd	s5,8(sp)
    panic("log.committing");
    80005adc:	00004517          	auipc	a0,0x4
    80005ae0:	e1c50513          	addi	a0,a0,-484 # 800098f8 <etext+0x8f8>
    80005ae4:	808fb0ef          	jal	80000aec <panic>
    wakeup(&log);
    80005ae8:	00210517          	auipc	a0,0x210
    80005aec:	16050513          	addi	a0,a0,352 # 80215c48 <log>
    80005af0:	c88fd0ef          	jal	80002f78 <wakeup>
  release(&log.lock);
    80005af4:	00210517          	auipc	a0,0x210
    80005af8:	15450513          	addi	a0,a0,340 # 80215c48 <log>
    80005afc:	e1cfb0ef          	jal	80001118 <release>
}
    80005b00:	03813083          	ld	ra,56(sp)
    80005b04:	03013403          	ld	s0,48(sp)
    80005b08:	02813483          	ld	s1,40(sp)
    80005b0c:	02013903          	ld	s2,32(sp)
    80005b10:	04010113          	addi	sp,sp,64
    80005b14:	00008067          	ret
    80005b18:	01313c23          	sd	s3,24(sp)
    80005b1c:	01413823          	sd	s4,16(sp)
    80005b20:	01513423          	sd	s5,8(sp)
  for (tail = 0; tail < log.lh.n; tail++) {
    80005b24:	00210a97          	auipc	s5,0x210
    80005b28:	150a8a93          	addi	s5,s5,336 # 80215c74 <log+0x2c>
    struct buf *to = bread(log.dev, log.start+tail+1); // log block
    80005b2c:	00210a17          	auipc	s4,0x210
    80005b30:	11ca0a13          	addi	s4,s4,284 # 80215c48 <log>
    80005b34:	018a2583          	lw	a1,24(s4)
    80005b38:	012585bb          	addw	a1,a1,s2
    80005b3c:	0015859b          	addiw	a1,a1,1
    80005b40:	024a2503          	lw	a0,36(s4)
    80005b44:	db4fe0ef          	jal	800040f8 <bread>
    80005b48:	00050493          	mv	s1,a0
    struct buf *from = bread(log.dev, log.lh.block[tail]); // cache block
    80005b4c:	000aa583          	lw	a1,0(s5)
    80005b50:	024a2503          	lw	a0,36(s4)
    80005b54:	da4fe0ef          	jal	800040f8 <bread>
    80005b58:	00050993          	mv	s3,a0
    memmove(to->data, from->data, BSIZE);
    80005b5c:	40000613          	li	a2,1024
    80005b60:	05850593          	addi	a1,a0,88
    80005b64:	05848513          	addi	a0,s1,88
    80005b68:	f10fb0ef          	jal	80001278 <memmove>
    bwrite(to);  // write the log
    80005b6c:	00048513          	mv	a0,s1
    80005b70:	eacfe0ef          	jal	8000421c <bwrite>
    brelse(from);
    80005b74:	00098513          	mv	a0,s3
    80005b78:	ef4fe0ef          	jal	8000426c <brelse>
    brelse(to);
    80005b7c:	00048513          	mv	a0,s1
    80005b80:	eecfe0ef          	jal	8000426c <brelse>
  for (tail = 0; tail < log.lh.n; tail++) {
    80005b84:	0019091b          	addiw	s2,s2,1
    80005b88:	004a8a93          	addi	s5,s5,4
    80005b8c:	028a2783          	lw	a5,40(s4)
    80005b90:	faf942e3          	blt	s2,a5,80005b34 <end_op+0xf8>
    write_log();     // Write modified blocks from cache to log
    write_head();    // Write header to disk -- the real commit
    80005b94:	ba1ff0ef          	jal	80005734 <write_head>
    install_trans(0); // Now install writes to home locations
    80005b98:	00000513          	li	a0,0
    80005b9c:	c25ff0ef          	jal	800057c0 <install_trans>
    log.lh.n = 0;
    80005ba0:	00210797          	auipc	a5,0x210
    80005ba4:	0c07a823          	sw	zero,208(a5) # 80215c70 <log+0x28>
    write_head();    // Erase the transaction from the log
    80005ba8:	b8dff0ef          	jal	80005734 <write_head>
    80005bac:	01813983          	ld	s3,24(sp)
    80005bb0:	01013a03          	ld	s4,16(sp)
    80005bb4:	00813a83          	ld	s5,8(sp)
    80005bb8:	ee9ff06f          	j	80005aa0 <end_op+0x64>

0000000080005bbc <log_write>:
//   modify bp->data[]
//   log_write(bp)
//   brelse(bp)
void
log_write(struct buf *b)
{
    80005bbc:	fe010113          	addi	sp,sp,-32
    80005bc0:	00113c23          	sd	ra,24(sp)
    80005bc4:	00813823          	sd	s0,16(sp)
    80005bc8:	00913423          	sd	s1,8(sp)
    80005bcc:	02010413          	addi	s0,sp,32
    80005bd0:	00050493          	mv	s1,a0
  int i;

  acquire(&log.lock);
    80005bd4:	00210517          	auipc	a0,0x210
    80005bd8:	07450513          	addi	a0,a0,116 # 80215c48 <log>
    80005bdc:	c64fb0ef          	jal	80001040 <acquire>
  if (log.lh.n >= LOGBLOCKS)
    80005be0:	00210617          	auipc	a2,0x210
    80005be4:	09062603          	lw	a2,144(a2) # 80215c70 <log+0x28>
    80005be8:	01d00793          	li	a5,29
    80005bec:	06c7cc63          	blt	a5,a2,80005c64 <log_write+0xa8>
    panic("too big a transaction");
  if (log.outstanding < 1)
    80005bf0:	00210797          	auipc	a5,0x210
    80005bf4:	0747a783          	lw	a5,116(a5) # 80215c64 <log+0x1c>
    80005bf8:	06f05c63          	blez	a5,80005c70 <log_write+0xb4>
    panic("log_write outside of trans");

  for (i = 0; i < log.lh.n; i++) {
    80005bfc:	00000793          	li	a5,0
    80005c00:	06c05e63          	blez	a2,80005c7c <log_write+0xc0>
    if (log.lh.block[i] == b->blockno)   // log absorption
    80005c04:	00c4a583          	lw	a1,12(s1)
    80005c08:	00210717          	auipc	a4,0x210
    80005c0c:	06c70713          	addi	a4,a4,108 # 80215c74 <log+0x2c>
  for (i = 0; i < log.lh.n; i++) {
    80005c10:	00000793          	li	a5,0
    if (log.lh.block[i] == b->blockno)   // log absorption
    80005c14:	00072683          	lw	a3,0(a4)
    80005c18:	06b68263          	beq	a3,a1,80005c7c <log_write+0xc0>
  for (i = 0; i < log.lh.n; i++) {
    80005c1c:	0017879b          	addiw	a5,a5,1
    80005c20:	00470713          	addi	a4,a4,4
    80005c24:	fef618e3          	bne	a2,a5,80005c14 <log_write+0x58>
      break;
  }
  log.lh.block[i] = b->blockno;
    80005c28:	00261613          	slli	a2,a2,0x2
    80005c2c:	02060613          	addi	a2,a2,32
    80005c30:	00210797          	auipc	a5,0x210
    80005c34:	01878793          	addi	a5,a5,24 # 80215c48 <log>
    80005c38:	00c787b3          	add	a5,a5,a2
    80005c3c:	00c4a703          	lw	a4,12(s1)
    80005c40:	00e7a623          	sw	a4,12(a5)
  if (i == log.lh.n) {  // Add new block to log?
    bpin(b);
    80005c44:	00048513          	mv	a0,s1
    80005c48:	ee0fe0ef          	jal	80004328 <bpin>
    log.lh.n++;
    80005c4c:	00210717          	auipc	a4,0x210
    80005c50:	ffc70713          	addi	a4,a4,-4 # 80215c48 <log>
    80005c54:	02872783          	lw	a5,40(a4)
    80005c58:	0017879b          	addiw	a5,a5,1
    80005c5c:	02f72423          	sw	a5,40(a4)
    80005c60:	03c0006f          	j	80005c9c <log_write+0xe0>
    panic("too big a transaction");
    80005c64:	00004517          	auipc	a0,0x4
    80005c68:	ca450513          	addi	a0,a0,-860 # 80009908 <etext+0x908>
    80005c6c:	e81fa0ef          	jal	80000aec <panic>
    panic("log_write outside of trans");
    80005c70:	00004517          	auipc	a0,0x4
    80005c74:	cb050513          	addi	a0,a0,-848 # 80009920 <etext+0x920>
    80005c78:	e75fa0ef          	jal	80000aec <panic>
  log.lh.block[i] = b->blockno;
    80005c7c:	00279693          	slli	a3,a5,0x2
    80005c80:	02068693          	addi	a3,a3,32
    80005c84:	00210717          	auipc	a4,0x210
    80005c88:	fc470713          	addi	a4,a4,-60 # 80215c48 <log>
    80005c8c:	00d70733          	add	a4,a4,a3
    80005c90:	00c4a683          	lw	a3,12(s1)
    80005c94:	00d72623          	sw	a3,12(a4)
  if (i == log.lh.n) {  // Add new block to log?
    80005c98:	faf606e3          	beq	a2,a5,80005c44 <log_write+0x88>
  }
  release(&log.lock);
    80005c9c:	00210517          	auipc	a0,0x210
    80005ca0:	fac50513          	addi	a0,a0,-84 # 80215c48 <log>
    80005ca4:	c74fb0ef          	jal	80001118 <release>
}
    80005ca8:	01813083          	ld	ra,24(sp)
    80005cac:	01013403          	ld	s0,16(sp)
    80005cb0:	00813483          	ld	s1,8(sp)
    80005cb4:	02010113          	addi	sp,sp,32
    80005cb8:	00008067          	ret

0000000080005cbc <initsleeplock>:
#include "proc.h"
#include "sleeplock.h"

void
initsleeplock(struct sleeplock *lk, char *name)
{
    80005cbc:	fe010113          	addi	sp,sp,-32
    80005cc0:	00113c23          	sd	ra,24(sp)
    80005cc4:	00813823          	sd	s0,16(sp)
    80005cc8:	00913423          	sd	s1,8(sp)
    80005ccc:	01213023          	sd	s2,0(sp)
    80005cd0:	02010413          	addi	s0,sp,32
    80005cd4:	00050493          	mv	s1,a0
    80005cd8:	00058913          	mv	s2,a1
  initlock(&lk->lk, "sleep lock");
    80005cdc:	00004597          	auipc	a1,0x4
    80005ce0:	c6458593          	addi	a1,a1,-924 # 80009940 <etext+0x940>
    80005ce4:	00850513          	addi	a0,a0,8
    80005ce8:	a74fb0ef          	jal	80000f5c <initlock>
  lk->name = name;
    80005cec:	0324b023          	sd	s2,32(s1)
  lk->locked = 0;
    80005cf0:	0004a023          	sw	zero,0(s1)
  lk->pid = 0;
    80005cf4:	0204a423          	sw	zero,40(s1)
}
    80005cf8:	01813083          	ld	ra,24(sp)
    80005cfc:	01013403          	ld	s0,16(sp)
    80005d00:	00813483          	ld	s1,8(sp)
    80005d04:	00013903          	ld	s2,0(sp)
    80005d08:	02010113          	addi	sp,sp,32
    80005d0c:	00008067          	ret

0000000080005d10 <acquiresleep>:

void
acquiresleep(struct sleeplock *lk)
{
    80005d10:	fe010113          	addi	sp,sp,-32
    80005d14:	00113c23          	sd	ra,24(sp)
    80005d18:	00813823          	sd	s0,16(sp)
    80005d1c:	00913423          	sd	s1,8(sp)
    80005d20:	01213023          	sd	s2,0(sp)
    80005d24:	02010413          	addi	s0,sp,32
    80005d28:	00050493          	mv	s1,a0
  acquire(&lk->lk);
    80005d2c:	00850913          	addi	s2,a0,8
    80005d30:	00090513          	mv	a0,s2
    80005d34:	b0cfb0ef          	jal	80001040 <acquire>
  while (lk->locked) {
    80005d38:	0004a783          	lw	a5,0(s1)
    80005d3c:	00078c63          	beqz	a5,80005d54 <acquiresleep+0x44>
    sleep(lk, &lk->lk);
    80005d40:	00090593          	mv	a1,s2
    80005d44:	00048513          	mv	a0,s1
    80005d48:	9b8fd0ef          	jal	80002f00 <sleep>
  while (lk->locked) {
    80005d4c:	0004a783          	lw	a5,0(s1)
    80005d50:	fe0798e3          	bnez	a5,80005d40 <acquiresleep+0x30>
  }
  lk->locked = 1;
    80005d54:	00100793          	li	a5,1
    80005d58:	00f4a023          	sw	a5,0(s1)
  lk->pid = myproc()->pid;
    80005d5c:	899fc0ef          	jal	800025f4 <myproc>
    80005d60:	03052783          	lw	a5,48(a0)
    80005d64:	02f4a423          	sw	a5,40(s1)
  release(&lk->lk);
    80005d68:	00090513          	mv	a0,s2
    80005d6c:	bacfb0ef          	jal	80001118 <release>
}
    80005d70:	01813083          	ld	ra,24(sp)
    80005d74:	01013403          	ld	s0,16(sp)
    80005d78:	00813483          	ld	s1,8(sp)
    80005d7c:	00013903          	ld	s2,0(sp)
    80005d80:	02010113          	addi	sp,sp,32
    80005d84:	00008067          	ret

0000000080005d88 <releasesleep>:

void
releasesleep(struct sleeplock *lk)
{
    80005d88:	fe010113          	addi	sp,sp,-32
    80005d8c:	00113c23          	sd	ra,24(sp)
    80005d90:	00813823          	sd	s0,16(sp)
    80005d94:	00913423          	sd	s1,8(sp)
    80005d98:	01213023          	sd	s2,0(sp)
    80005d9c:	02010413          	addi	s0,sp,32
    80005da0:	00050493          	mv	s1,a0
  acquire(&lk->lk);
    80005da4:	00850913          	addi	s2,a0,8
    80005da8:	00090513          	mv	a0,s2
    80005dac:	a94fb0ef          	jal	80001040 <acquire>
  lk->locked = 0;
    80005db0:	0004a023          	sw	zero,0(s1)
  lk->pid = 0;
    80005db4:	0204a423          	sw	zero,40(s1)
  wakeup(lk);
    80005db8:	00048513          	mv	a0,s1
    80005dbc:	9bcfd0ef          	jal	80002f78 <wakeup>
  release(&lk->lk);
    80005dc0:	00090513          	mv	a0,s2
    80005dc4:	b54fb0ef          	jal	80001118 <release>
}
    80005dc8:	01813083          	ld	ra,24(sp)
    80005dcc:	01013403          	ld	s0,16(sp)
    80005dd0:	00813483          	ld	s1,8(sp)
    80005dd4:	00013903          	ld	s2,0(sp)
    80005dd8:	02010113          	addi	sp,sp,32
    80005ddc:	00008067          	ret

0000000080005de0 <holdingsleep>:

int
holdingsleep(struct sleeplock *lk)
{
    80005de0:	fd010113          	addi	sp,sp,-48
    80005de4:	02113423          	sd	ra,40(sp)
    80005de8:	02813023          	sd	s0,32(sp)
    80005dec:	00913c23          	sd	s1,24(sp)
    80005df0:	01213823          	sd	s2,16(sp)
    80005df4:	03010413          	addi	s0,sp,48
    80005df8:	00050493          	mv	s1,a0
  int r;
  
  acquire(&lk->lk);
    80005dfc:	00850913          	addi	s2,a0,8
    80005e00:	00090513          	mv	a0,s2
    80005e04:	a3cfb0ef          	jal	80001040 <acquire>
  r = lk->locked && (lk->pid == myproc()->pid);
    80005e08:	0004a783          	lw	a5,0(s1)
    80005e0c:	02079663          	bnez	a5,80005e38 <holdingsleep+0x58>
    80005e10:	00000493          	li	s1,0
  release(&lk->lk);
    80005e14:	00090513          	mv	a0,s2
    80005e18:	b00fb0ef          	jal	80001118 <release>
  return r;
}
    80005e1c:	00048513          	mv	a0,s1
    80005e20:	02813083          	ld	ra,40(sp)
    80005e24:	02013403          	ld	s0,32(sp)
    80005e28:	01813483          	ld	s1,24(sp)
    80005e2c:	01013903          	ld	s2,16(sp)
    80005e30:	03010113          	addi	sp,sp,48
    80005e34:	00008067          	ret
    80005e38:	01313423          	sd	s3,8(sp)
  r = lk->locked && (lk->pid == myproc()->pid);
    80005e3c:	0284a783          	lw	a5,40(s1)
    80005e40:	00078993          	mv	s3,a5
    80005e44:	fb0fc0ef          	jal	800025f4 <myproc>
    80005e48:	03052483          	lw	s1,48(a0)
    80005e4c:	413484b3          	sub	s1,s1,s3
    80005e50:	0014b493          	seqz	s1,s1
    80005e54:	00813983          	ld	s3,8(sp)
    80005e58:	fbdff06f          	j	80005e14 <holdingsleep+0x34>

0000000080005e5c <fileinit>:
  struct file file[NFILE];
} ftable;

void
fileinit(void)
{
    80005e5c:	ff010113          	addi	sp,sp,-16
    80005e60:	00113423          	sd	ra,8(sp)
    80005e64:	00813023          	sd	s0,0(sp)
    80005e68:	01010413          	addi	s0,sp,16
  initlock(&ftable.lock, "ftable");
    80005e6c:	00004597          	auipc	a1,0x4
    80005e70:	ae458593          	addi	a1,a1,-1308 # 80009950 <etext+0x950>
    80005e74:	00210517          	auipc	a0,0x210
    80005e78:	f1c50513          	addi	a0,a0,-228 # 80215d90 <ftable>
    80005e7c:	8e0fb0ef          	jal	80000f5c <initlock>
}
    80005e80:	00813083          	ld	ra,8(sp)
    80005e84:	00013403          	ld	s0,0(sp)
    80005e88:	01010113          	addi	sp,sp,16
    80005e8c:	00008067          	ret

0000000080005e90 <filealloc>:

// Allocate a file structure.
struct file*
filealloc(void)
{
    80005e90:	fe010113          	addi	sp,sp,-32
    80005e94:	00113c23          	sd	ra,24(sp)
    80005e98:	00813823          	sd	s0,16(sp)
    80005e9c:	00913423          	sd	s1,8(sp)
    80005ea0:	02010413          	addi	s0,sp,32
  struct file *f;

  acquire(&ftable.lock);
    80005ea4:	00210517          	auipc	a0,0x210
    80005ea8:	eec50513          	addi	a0,a0,-276 # 80215d90 <ftable>
    80005eac:	994fb0ef          	jal	80001040 <acquire>
  for(f = ftable.file; f < ftable.file + NFILE; f++){
    80005eb0:	00210497          	auipc	s1,0x210
    80005eb4:	ef848493          	addi	s1,s1,-264 # 80215da8 <ftable+0x18>
    80005eb8:	00211717          	auipc	a4,0x211
    80005ebc:	e9070713          	addi	a4,a4,-368 # 80216d48 <ramdisk_lock>
    if(f->ref == 0){
    80005ec0:	0044a783          	lw	a5,4(s1)
    80005ec4:	02078063          	beqz	a5,80005ee4 <filealloc+0x54>
  for(f = ftable.file; f < ftable.file + NFILE; f++){
    80005ec8:	02848493          	addi	s1,s1,40
    80005ecc:	fee49ae3          	bne	s1,a4,80005ec0 <filealloc+0x30>
      f->ref = 1;
      release(&ftable.lock);
      return f;
    }
  }
  release(&ftable.lock);
    80005ed0:	00210517          	auipc	a0,0x210
    80005ed4:	ec050513          	addi	a0,a0,-320 # 80215d90 <ftable>
    80005ed8:	a40fb0ef          	jal	80001118 <release>
  return 0;
    80005edc:	00000493          	li	s1,0
    80005ee0:	0180006f          	j	80005ef8 <filealloc+0x68>
      f->ref = 1;
    80005ee4:	00100793          	li	a5,1
    80005ee8:	00f4a223          	sw	a5,4(s1)
      release(&ftable.lock);
    80005eec:	00210517          	auipc	a0,0x210
    80005ef0:	ea450513          	addi	a0,a0,-348 # 80215d90 <ftable>
    80005ef4:	a24fb0ef          	jal	80001118 <release>
}
    80005ef8:	00048513          	mv	a0,s1
    80005efc:	01813083          	ld	ra,24(sp)
    80005f00:	01013403          	ld	s0,16(sp)
    80005f04:	00813483          	ld	s1,8(sp)
    80005f08:	02010113          	addi	sp,sp,32
    80005f0c:	00008067          	ret

0000000080005f10 <filedup>:

// Increment ref count for file f.
struct file*
filedup(struct file *f)
{
    80005f10:	fe010113          	addi	sp,sp,-32
    80005f14:	00113c23          	sd	ra,24(sp)
    80005f18:	00813823          	sd	s0,16(sp)
    80005f1c:	00913423          	sd	s1,8(sp)
    80005f20:	02010413          	addi	s0,sp,32
    80005f24:	00050493          	mv	s1,a0
  acquire(&ftable.lock);
    80005f28:	00210517          	auipc	a0,0x210
    80005f2c:	e6850513          	addi	a0,a0,-408 # 80215d90 <ftable>
    80005f30:	910fb0ef          	jal	80001040 <acquire>
  if(f->ref < 1)
    80005f34:	0044a783          	lw	a5,4(s1)
    80005f38:	02f05863          	blez	a5,80005f68 <filedup+0x58>
    panic("filedup");
  f->ref++;
    80005f3c:	0017879b          	addiw	a5,a5,1
    80005f40:	00f4a223          	sw	a5,4(s1)
  release(&ftable.lock);
    80005f44:	00210517          	auipc	a0,0x210
    80005f48:	e4c50513          	addi	a0,a0,-436 # 80215d90 <ftable>
    80005f4c:	9ccfb0ef          	jal	80001118 <release>
  return f;
}
    80005f50:	00048513          	mv	a0,s1
    80005f54:	01813083          	ld	ra,24(sp)
    80005f58:	01013403          	ld	s0,16(sp)
    80005f5c:	00813483          	ld	s1,8(sp)
    80005f60:	02010113          	addi	sp,sp,32
    80005f64:	00008067          	ret
    panic("filedup");
    80005f68:	00004517          	auipc	a0,0x4
    80005f6c:	9f050513          	addi	a0,a0,-1552 # 80009958 <etext+0x958>
    80005f70:	b7dfa0ef          	jal	80000aec <panic>

0000000080005f74 <fileclose>:

// Close file f.  (Decrement ref count, close when reaches 0.)
void
fileclose(struct file *f)
{
    80005f74:	fc010113          	addi	sp,sp,-64
    80005f78:	02113c23          	sd	ra,56(sp)
    80005f7c:	02813823          	sd	s0,48(sp)
    80005f80:	02913423          	sd	s1,40(sp)
    80005f84:	04010413          	addi	s0,sp,64
    80005f88:	00050493          	mv	s1,a0
  struct file ff;

  acquire(&ftable.lock);
    80005f8c:	00210517          	auipc	a0,0x210
    80005f90:	e0450513          	addi	a0,a0,-508 # 80215d90 <ftable>
    80005f94:	8acfb0ef          	jal	80001040 <acquire>
  if(f->ref < 1)
    80005f98:	0044a783          	lw	a5,4(s1)
    80005f9c:	06f05e63          	blez	a5,80006018 <fileclose+0xa4>
    panic("fileclose");
  if(--f->ref > 0){
    80005fa0:	fff7879b          	addiw	a5,a5,-1
    80005fa4:	00f4a223          	sw	a5,4(s1)
    80005fa8:	08f04663          	bgtz	a5,80006034 <fileclose+0xc0>
    80005fac:	03213023          	sd	s2,32(sp)
    80005fb0:	01313c23          	sd	s3,24(sp)
    80005fb4:	01413823          	sd	s4,16(sp)
    80005fb8:	01513423          	sd	s5,8(sp)
    release(&ftable.lock);
    return;
  }
  ff = *f;
    80005fbc:	0004a783          	lw	a5,0(s1)
    80005fc0:	00078913          	mv	s2,a5
    80005fc4:	0094c783          	lbu	a5,9(s1)
    80005fc8:	00078993          	mv	s3,a5
    80005fcc:	0104b783          	ld	a5,16(s1)
    80005fd0:	00078a13          	mv	s4,a5
    80005fd4:	0184b783          	ld	a5,24(s1)
    80005fd8:	00078a93          	mv	s5,a5
  f->ref = 0;
    80005fdc:	0004a223          	sw	zero,4(s1)
  f->type = FD_NONE;
    80005fe0:	0004a023          	sw	zero,0(s1)
  release(&ftable.lock);
    80005fe4:	00210517          	auipc	a0,0x210
    80005fe8:	dac50513          	addi	a0,a0,-596 # 80215d90 <ftable>
    80005fec:	92cfb0ef          	jal	80001118 <release>

  if(ff.type == FD_PIPE){
    80005ff0:	00100793          	li	a5,1
    80005ff4:	06f90063          	beq	s2,a5,80006054 <fileclose+0xe0>
    pipeclose(ff.pipe, ff.writable);
  } else if(ff.type == FD_INODE || ff.type == FD_DEVICE){
    80005ff8:	ffe9079b          	addiw	a5,s2,-2
    80005ffc:	00100713          	li	a4,1
    80006000:	06f77a63          	bgeu	a4,a5,80006074 <fileclose+0x100>
    80006004:	02013903          	ld	s2,32(sp)
    80006008:	01813983          	ld	s3,24(sp)
    8000600c:	01013a03          	ld	s4,16(sp)
    80006010:	00813a83          	ld	s5,8(sp)
    80006014:	02c0006f          	j	80006040 <fileclose+0xcc>
    80006018:	03213023          	sd	s2,32(sp)
    8000601c:	01313c23          	sd	s3,24(sp)
    80006020:	01413823          	sd	s4,16(sp)
    80006024:	01513423          	sd	s5,8(sp)
    panic("fileclose");
    80006028:	00004517          	auipc	a0,0x4
    8000602c:	93850513          	addi	a0,a0,-1736 # 80009960 <etext+0x960>
    80006030:	abdfa0ef          	jal	80000aec <panic>
    release(&ftable.lock);
    80006034:	00210517          	auipc	a0,0x210
    80006038:	d5c50513          	addi	a0,a0,-676 # 80215d90 <ftable>
    8000603c:	8dcfb0ef          	jal	80001118 <release>
    begin_op();
    iput(ff.ip);
    end_op();
  }
}
    80006040:	03813083          	ld	ra,56(sp)
    80006044:	03013403          	ld	s0,48(sp)
    80006048:	02813483          	ld	s1,40(sp)
    8000604c:	04010113          	addi	sp,sp,64
    80006050:	00008067          	ret
    pipeclose(ff.pipe, ff.writable);
    80006054:	00098593          	mv	a1,s3
    80006058:	000a0513          	mv	a0,s4
    8000605c:	518000ef          	jal	80006574 <pipeclose>
    80006060:	02013903          	ld	s2,32(sp)
    80006064:	01813983          	ld	s3,24(sp)
    80006068:	01013a03          	ld	s4,16(sp)
    8000606c:	00813a83          	ld	s5,8(sp)
    80006070:	fd1ff06f          	j	80006040 <fileclose+0xcc>
    begin_op();
    80006074:	925ff0ef          	jal	80005998 <begin_op>
    iput(ff.ip);
    80006078:	000a8513          	mv	a0,s5
    8000607c:	c21fe0ef          	jal	80004c9c <iput>
    end_op();
    80006080:	9bdff0ef          	jal	80005a3c <end_op>
    80006084:	02013903          	ld	s2,32(sp)
    80006088:	01813983          	ld	s3,24(sp)
    8000608c:	01013a03          	ld	s4,16(sp)
    80006090:	00813a83          	ld	s5,8(sp)
    80006094:	fadff06f          	j	80006040 <fileclose+0xcc>

0000000080006098 <filestat>:

// Get metadata about file f.
// addr is a user virtual address, pointing to a struct stat.
int
filestat(struct file *f, uint64 addr)
{
    80006098:	fb010113          	addi	sp,sp,-80
    8000609c:	04113423          	sd	ra,72(sp)
    800060a0:	04813023          	sd	s0,64(sp)
    800060a4:	02913c23          	sd	s1,56(sp)
    800060a8:	03413023          	sd	s4,32(sp)
    800060ac:	05010413          	addi	s0,sp,80
    800060b0:	00050493          	mv	s1,a0
    800060b4:	00058a13          	mv	s4,a1
  struct proc *p = myproc();
    800060b8:	d3cfc0ef          	jal	800025f4 <myproc>
  struct stat st;
  
  if(f->type == FD_INODE || f->type == FD_DEVICE){
    800060bc:	0004a783          	lw	a5,0(s1)
    800060c0:	ffe7879b          	addiw	a5,a5,-2
    800060c4:	00100713          	li	a4,1
    800060c8:	06f76463          	bltu	a4,a5,80006130 <filestat+0x98>
    800060cc:	03213823          	sd	s2,48(sp)
    800060d0:	03313423          	sd	s3,40(sp)
    800060d4:	00050993          	mv	s3,a0
    ilock(f->ip);
    800060d8:	0184b503          	ld	a0,24(s1)
    800060dc:	995fe0ef          	jal	80004a70 <ilock>
    stati(f->ip, &st);
    800060e0:	fb840913          	addi	s2,s0,-72
    800060e4:	00090593          	mv	a1,s2
    800060e8:	0184b503          	ld	a0,24(s1)
    800060ec:	e85fe0ef          	jal	80004f70 <stati>
    iunlock(f->ip);
    800060f0:	0184b503          	ld	a0,24(s1)
    800060f4:	a71fe0ef          	jal	80004b64 <iunlock>
    if(copyout(p->pagetable, addr, (char *)&st, sizeof(st)) < 0)
    800060f8:	01800693          	li	a3,24
    800060fc:	00090613          	mv	a2,s2
    80006100:	000a0593          	mv	a1,s4
    80006104:	0509b503          	ld	a0,80(s3)
    80006108:	868fc0ef          	jal	80002170 <copyout>
    8000610c:	41f5551b          	sraiw	a0,a0,0x1f
    80006110:	03013903          	ld	s2,48(sp)
    80006114:	02813983          	ld	s3,40(sp)
      return -1;
    return 0;
  }
  return -1;
}
    80006118:	04813083          	ld	ra,72(sp)
    8000611c:	04013403          	ld	s0,64(sp)
    80006120:	03813483          	ld	s1,56(sp)
    80006124:	02013a03          	ld	s4,32(sp)
    80006128:	05010113          	addi	sp,sp,80
    8000612c:	00008067          	ret
  return -1;
    80006130:	fff00513          	li	a0,-1
    80006134:	fe5ff06f          	j	80006118 <filestat+0x80>

0000000080006138 <fileread>:

// Read from file f.
// addr is a user virtual address.
int
fileread(struct file *f, uint64 addr, int n)
{
    80006138:	fd010113          	addi	sp,sp,-48
    8000613c:	02113423          	sd	ra,40(sp)
    80006140:	02813023          	sd	s0,32(sp)
    80006144:	01213823          	sd	s2,16(sp)
    80006148:	03010413          	addi	s0,sp,48
  int r = 0;

  if(f->readable == 0)
    8000614c:	00854783          	lbu	a5,8(a0)
    80006150:	0e078c63          	beqz	a5,80006248 <fileread+0x110>
    80006154:	00913c23          	sd	s1,24(sp)
    80006158:	01313423          	sd	s3,8(sp)
    8000615c:	00050493          	mv	s1,a0
    80006160:	00058913          	mv	s2,a1
    80006164:	00060993          	mv	s3,a2
    return -1;

  if(f->type == FD_PIPE){
    80006168:	00052783          	lw	a5,0(a0)
    8000616c:	00100713          	li	a4,1
    80006170:	06e78863          	beq	a5,a4,800061e0 <fileread+0xa8>
    r = piperead(f->pipe, addr, n);
  } else if(f->type == FD_DEVICE){
    80006174:	00300713          	li	a4,3
    80006178:	08e78063          	beq	a5,a4,800061f8 <fileread+0xc0>
    if(f->major < 0 || f->major >= NDEV || !devsw[f->major].read)
      return -1;
    r = devsw[f->major].read(1, addr, n);
  } else if(f->type == FD_INODE){
    8000617c:	00200713          	li	a4,2
    80006180:	0ae79e63          	bne	a5,a4,8000623c <fileread+0x104>
    ilock(f->ip);
    80006184:	01853503          	ld	a0,24(a0)
    80006188:	8e9fe0ef          	jal	80004a70 <ilock>
    if((r = readi(f->ip, 1, addr, f->off, n)) > 0)
    8000618c:	00098713          	mv	a4,s3
    80006190:	0204a683          	lw	a3,32(s1)
    80006194:	00090613          	mv	a2,s2
    80006198:	00100593          	li	a1,1
    8000619c:	0184b503          	ld	a0,24(s1)
    800061a0:	e19fe0ef          	jal	80004fb8 <readi>
    800061a4:	00050913          	mv	s2,a0
    800061a8:	00a05863          	blez	a0,800061b8 <fileread+0x80>
      f->off += r;
    800061ac:	0204a783          	lw	a5,32(s1)
    800061b0:	00a787bb          	addw	a5,a5,a0
    800061b4:	02f4a023          	sw	a5,32(s1)
    iunlock(f->ip);
    800061b8:	0184b503          	ld	a0,24(s1)
    800061bc:	9a9fe0ef          	jal	80004b64 <iunlock>
    800061c0:	01813483          	ld	s1,24(sp)
    800061c4:	00813983          	ld	s3,8(sp)
  } else {
    panic("fileread");
  }

  return r;
}
    800061c8:	00090513          	mv	a0,s2
    800061cc:	02813083          	ld	ra,40(sp)
    800061d0:	02013403          	ld	s0,32(sp)
    800061d4:	01013903          	ld	s2,16(sp)
    800061d8:	03010113          	addi	sp,sp,48
    800061dc:	00008067          	ret
    r = piperead(f->pipe, addr, n);
    800061e0:	01053503          	ld	a0,16(a0)
    800061e4:	594000ef          	jal	80006778 <piperead>
    800061e8:	00050913          	mv	s2,a0
    800061ec:	01813483          	ld	s1,24(sp)
    800061f0:	00813983          	ld	s3,8(sp)
    800061f4:	fd5ff06f          	j	800061c8 <fileread+0x90>
    if(f->major < 0 || f->major >= NDEV || !devsw[f->major].read)
    800061f8:	02451783          	lh	a5,36(a0)
    800061fc:	03079693          	slli	a3,a5,0x30
    80006200:	0306d693          	srli	a3,a3,0x30
    80006204:	00900713          	li	a4,9
    80006208:	04d76663          	bltu	a4,a3,80006254 <fileread+0x11c>
    8000620c:	00479793          	slli	a5,a5,0x4
    80006210:	00210717          	auipc	a4,0x210
    80006214:	ae070713          	addi	a4,a4,-1312 # 80215cf0 <devsw>
    80006218:	00f707b3          	add	a5,a4,a5
    8000621c:	0007b783          	ld	a5,0(a5)
    80006220:	04078463          	beqz	a5,80006268 <fileread+0x130>
    r = devsw[f->major].read(1, addr, n);
    80006224:	00100513          	li	a0,1
    80006228:	000780e7          	jalr	a5
    8000622c:	00050913          	mv	s2,a0
    80006230:	01813483          	ld	s1,24(sp)
    80006234:	00813983          	ld	s3,8(sp)
    80006238:	f91ff06f          	j	800061c8 <fileread+0x90>
    panic("fileread");
    8000623c:	00003517          	auipc	a0,0x3
    80006240:	73450513          	addi	a0,a0,1844 # 80009970 <etext+0x970>
    80006244:	8a9fa0ef          	jal	80000aec <panic>
    return -1;
    80006248:	fff00793          	li	a5,-1
    8000624c:	00078913          	mv	s2,a5
    80006250:	f79ff06f          	j	800061c8 <fileread+0x90>
      return -1;
    80006254:	fff00793          	li	a5,-1
    80006258:	00078913          	mv	s2,a5
    8000625c:	01813483          	ld	s1,24(sp)
    80006260:	00813983          	ld	s3,8(sp)
    80006264:	f65ff06f          	j	800061c8 <fileread+0x90>
    80006268:	fff00793          	li	a5,-1
    8000626c:	00078913          	mv	s2,a5
    80006270:	01813483          	ld	s1,24(sp)
    80006274:	00813983          	ld	s3,8(sp)
    80006278:	f51ff06f          	j	800061c8 <fileread+0x90>

000000008000627c <filewrite>:
int
filewrite(struct file *f, uint64 addr, int n)
{
  int r, ret = 0;

  if(f->writable == 0)
    8000627c:	00954783          	lbu	a5,9(a0)
    80006280:	1a078863          	beqz	a5,80006430 <filewrite+0x1b4>
{
    80006284:	fa010113          	addi	sp,sp,-96
    80006288:	04113c23          	sd	ra,88(sp)
    8000628c:	04813823          	sd	s0,80(sp)
    80006290:	05213023          	sd	s2,64(sp)
    80006294:	03513423          	sd	s5,40(sp)
    80006298:	03613023          	sd	s6,32(sp)
    8000629c:	06010413          	addi	s0,sp,96
    800062a0:	00050913          	mv	s2,a0
    800062a4:	00058b13          	mv	s6,a1
    800062a8:	00060a93          	mv	s5,a2
    return -1;

  if(f->type == FD_PIPE){
    800062ac:	00052783          	lw	a5,0(a0)
    800062b0:	00100713          	li	a4,1
    800062b4:	04e78863          	beq	a5,a4,80006304 <filewrite+0x88>
    ret = pipewrite(f->pipe, addr, n);
  } else if(f->type == FD_DEVICE){
    800062b8:	00300713          	li	a4,3
    800062bc:	04e78a63          	beq	a5,a4,80006310 <filewrite+0x94>
    if(f->major < 0 || f->major >= NDEV || !devsw[f->major].write)
      return -1;
    ret = devsw[f->major].write(1, addr, n);
  } else if(f->type == FD_INODE){
    800062c0:	00200713          	li	a4,2
    800062c4:	14e79463          	bne	a5,a4,8000640c <filewrite+0x190>
    800062c8:	03413823          	sd	s4,48(sp)
    // the maximum log transaction size, including
    // i-node, indirect block, allocation blocks,
    // and 2 blocks of slop for non-aligned writes.
    int max = ((MAXOPBLOCKS-1-1-2) / 2) * BSIZE;
    int i = 0;
    while(i < n){
    800062cc:	0ec05e63          	blez	a2,800063c8 <filewrite+0x14c>
    800062d0:	04913423          	sd	s1,72(sp)
    800062d4:	03313c23          	sd	s3,56(sp)
    800062d8:	01713c23          	sd	s7,24(sp)
    800062dc:	01813823          	sd	s8,16(sp)
    800062e0:	01913423          	sd	s9,8(sp)
    int i = 0;
    800062e4:	00000a13          	li	s4,0
      int n1 = n - i;
      if(n1 > max)
    800062e8:	00001bb7          	lui	s7,0x1
    800062ec:	c00b8b93          	addi	s7,s7,-1024 # c00 <_binary_fs_img_size-0x1f3400>
    800062f0:	000017b7          	lui	a5,0x1
    800062f4:	c007879b          	addiw	a5,a5,-1024 # c00 <_binary_fs_img_size-0x1f3400>
    800062f8:	00078c93          	mv	s9,a5
        n1 = max;

      begin_op();
      ilock(f->ip);
      if ((r = writei(f->ip, 1, addr + i, f->off, n1)) > 0)
    800062fc:	00100c13          	li	s8,1
    80006300:	09c0006f          	j	8000639c <filewrite+0x120>
    ret = pipewrite(f->pipe, addr, n);
    80006304:	01053503          	ld	a0,16(a0)
    80006308:	2f4000ef          	jal	800065fc <pipewrite>
    8000630c:	0e40006f          	j	800063f0 <filewrite+0x174>
    if(f->major < 0 || f->major >= NDEV || !devsw[f->major].write)
    80006310:	02451783          	lh	a5,36(a0)
    80006314:	03079693          	slli	a3,a5,0x30
    80006318:	0306d693          	srli	a3,a3,0x30
    8000631c:	00900713          	li	a4,9
    80006320:	10d76c63          	bltu	a4,a3,80006438 <filewrite+0x1bc>
    80006324:	00479793          	slli	a5,a5,0x4
    80006328:	00210717          	auipc	a4,0x210
    8000632c:	9c870713          	addi	a4,a4,-1592 # 80215cf0 <devsw>
    80006330:	00f707b3          	add	a5,a4,a5
    80006334:	0087b783          	ld	a5,8(a5)
    80006338:	10078463          	beqz	a5,80006440 <filewrite+0x1c4>
    ret = devsw[f->major].write(1, addr, n);
    8000633c:	00100513          	li	a0,1
    80006340:	000780e7          	jalr	a5
    80006344:	0ac0006f          	j	800063f0 <filewrite+0x174>
      if(n1 > max)
    80006348:	0009899b          	sext.w	s3,s3
      begin_op();
    8000634c:	e4cff0ef          	jal	80005998 <begin_op>
      ilock(f->ip);
    80006350:	01893503          	ld	a0,24(s2)
    80006354:	f1cfe0ef          	jal	80004a70 <ilock>
      if ((r = writei(f->ip, 1, addr + i, f->off, n1)) > 0)
    80006358:	00098713          	mv	a4,s3
    8000635c:	02092683          	lw	a3,32(s2)
    80006360:	016a0633          	add	a2,s4,s6
    80006364:	000c0593          	mv	a1,s8
    80006368:	01893503          	ld	a0,24(s2)
    8000636c:	dd1fe0ef          	jal	8000513c <writei>
    80006370:	00050493          	mv	s1,a0
    80006374:	00a05863          	blez	a0,80006384 <filewrite+0x108>
        f->off += r;
    80006378:	02092783          	lw	a5,32(s2)
    8000637c:	00a787bb          	addw	a5,a5,a0
    80006380:	02f92023          	sw	a5,32(s2)
      iunlock(f->ip);
    80006384:	01893503          	ld	a0,24(s2)
    80006388:	fdcfe0ef          	jal	80004b64 <iunlock>
      end_op();
    8000638c:	eb0ff0ef          	jal	80005a3c <end_op>

      if(r != n1){
    80006390:	04999063          	bne	s3,s1,800063d0 <filewrite+0x154>
        // error from writei
        break;
      }
      i += r;
    80006394:	01448a3b          	addw	s4,s1,s4
    while(i < n){
    80006398:	015a5c63          	bge	s4,s5,800063b0 <filewrite+0x134>
      int n1 = n - i;
    8000639c:	414a87bb          	subw	a5,s5,s4
    800063a0:	00078993          	mv	s3,a5
      if(n1 > max)
    800063a4:	fafbd2e3          	bge	s7,a5,80006348 <filewrite+0xcc>
    800063a8:	000c8993          	mv	s3,s9
    800063ac:	f9dff06f          	j	80006348 <filewrite+0xcc>
    800063b0:	04813483          	ld	s1,72(sp)
    800063b4:	03813983          	ld	s3,56(sp)
    800063b8:	01813b83          	ld	s7,24(sp)
    800063bc:	01013c03          	ld	s8,16(sp)
    800063c0:	00813c83          	ld	s9,8(sp)
    800063c4:	0200006f          	j	800063e4 <filewrite+0x168>
    int i = 0;
    800063c8:	00000a13          	li	s4,0
    800063cc:	0180006f          	j	800063e4 <filewrite+0x168>
    800063d0:	04813483          	ld	s1,72(sp)
    800063d4:	03813983          	ld	s3,56(sp)
    800063d8:	01813b83          	ld	s7,24(sp)
    800063dc:	01013c03          	ld	s8,16(sp)
    800063e0:	00813c83          	ld	s9,8(sp)
    }
    ret = (i == n ? n : -1);
    800063e4:	074a9263          	bne	s5,s4,80006448 <filewrite+0x1cc>
    800063e8:	000a8513          	mv	a0,s5
    800063ec:	03013a03          	ld	s4,48(sp)
  } else {
    panic("filewrite");
  }

  return ret;
}
    800063f0:	05813083          	ld	ra,88(sp)
    800063f4:	05013403          	ld	s0,80(sp)
    800063f8:	04013903          	ld	s2,64(sp)
    800063fc:	02813a83          	ld	s5,40(sp)
    80006400:	02013b03          	ld	s6,32(sp)
    80006404:	06010113          	addi	sp,sp,96
    80006408:	00008067          	ret
    8000640c:	04913423          	sd	s1,72(sp)
    80006410:	03313c23          	sd	s3,56(sp)
    80006414:	03413823          	sd	s4,48(sp)
    80006418:	01713c23          	sd	s7,24(sp)
    8000641c:	01813823          	sd	s8,16(sp)
    80006420:	01913423          	sd	s9,8(sp)
    panic("filewrite");
    80006424:	00003517          	auipc	a0,0x3
    80006428:	55c50513          	addi	a0,a0,1372 # 80009980 <etext+0x980>
    8000642c:	ec0fa0ef          	jal	80000aec <panic>
    return -1;
    80006430:	fff00513          	li	a0,-1
}
    80006434:	00008067          	ret
      return -1;
    80006438:	fff00513          	li	a0,-1
    8000643c:	fb5ff06f          	j	800063f0 <filewrite+0x174>
    80006440:	fff00513          	li	a0,-1
    80006444:	fadff06f          	j	800063f0 <filewrite+0x174>
    ret = (i == n ? n : -1);
    80006448:	fff00513          	li	a0,-1
    8000644c:	03013a03          	ld	s4,48(sp)
    80006450:	fa1ff06f          	j	800063f0 <filewrite+0x174>

0000000080006454 <pipealloc>:
  int writeopen;  // write fd is still open
};

int
pipealloc(struct file **f0, struct file **f1)
{
    80006454:	fd010113          	addi	sp,sp,-48
    80006458:	02113423          	sd	ra,40(sp)
    8000645c:	02813023          	sd	s0,32(sp)
    80006460:	00913c23          	sd	s1,24(sp)
    80006464:	01413023          	sd	s4,0(sp)
    80006468:	03010413          	addi	s0,sp,48
    8000646c:	00050493          	mv	s1,a0
    80006470:	00058a13          	mv	s4,a1
  struct pipe *pi;

  pi = 0;
  *f0 = *f1 = 0;
    80006474:	0005b023          	sd	zero,0(a1)
    80006478:	00053023          	sd	zero,0(a0)
  if((*f0 = filealloc()) == 0 || (*f1 = filealloc()) == 0)
    8000647c:	a15ff0ef          	jal	80005e90 <filealloc>
    80006480:	00a4b023          	sd	a0,0(s1)
    80006484:	0a050c63          	beqz	a0,8000653c <pipealloc+0xe8>
    80006488:	a09ff0ef          	jal	80005e90 <filealloc>
    8000648c:	00aa3023          	sd	a0,0(s4)
    80006490:	0a050063          	beqz	a0,80006530 <pipealloc+0xdc>
    80006494:	01213823          	sd	s2,16(sp)
    goto bad;
  if((pi = (struct pipe*)kalloc()) == 0)
    80006498:	a49fa0ef          	jal	80000ee0 <kalloc>
    8000649c:	00050913          	mv	s2,a0
    800064a0:	06050c63          	beqz	a0,80006518 <pipealloc+0xc4>
    800064a4:	01313423          	sd	s3,8(sp)
    goto bad;
  pi->readopen = 1;
    800064a8:	00100993          	li	s3,1
    800064ac:	23352023          	sw	s3,544(a0)
  pi->writeopen = 1;
    800064b0:	23352223          	sw	s3,548(a0)
  pi->nwrite = 0;
    800064b4:	20052e23          	sw	zero,540(a0)
  pi->nread = 0;
    800064b8:	20052c23          	sw	zero,536(a0)
  initlock(&pi->lock, "pipe");
    800064bc:	00003597          	auipc	a1,0x3
    800064c0:	4d458593          	addi	a1,a1,1236 # 80009990 <etext+0x990>
    800064c4:	a99fa0ef          	jal	80000f5c <initlock>
  (*f0)->type = FD_PIPE;
    800064c8:	0004b783          	ld	a5,0(s1)
    800064cc:	0137a023          	sw	s3,0(a5)
  (*f0)->readable = 1;
    800064d0:	0004b783          	ld	a5,0(s1)
    800064d4:	01378423          	sb	s3,8(a5)
  (*f0)->writable = 0;
    800064d8:	0004b783          	ld	a5,0(s1)
    800064dc:	000784a3          	sb	zero,9(a5)
  (*f0)->pipe = pi;
    800064e0:	0004b783          	ld	a5,0(s1)
    800064e4:	0127b823          	sd	s2,16(a5)
  (*f1)->type = FD_PIPE;
    800064e8:	000a3783          	ld	a5,0(s4)
    800064ec:	0137a023          	sw	s3,0(a5)
  (*f1)->readable = 0;
    800064f0:	000a3783          	ld	a5,0(s4)
    800064f4:	00078423          	sb	zero,8(a5)
  (*f1)->writable = 1;
    800064f8:	000a3783          	ld	a5,0(s4)
    800064fc:	013784a3          	sb	s3,9(a5)
  (*f1)->pipe = pi;
    80006500:	000a3783          	ld	a5,0(s4)
    80006504:	0127b823          	sd	s2,16(a5)
  return 0;
    80006508:	00000513          	li	a0,0
    8000650c:	01013903          	ld	s2,16(sp)
    80006510:	00813983          	ld	s3,8(sp)
    80006514:	0400006f          	j	80006554 <pipealloc+0x100>

 bad:
  if(pi)
    kfree((char*)pi);
  if(*f0)
    80006518:	0004b503          	ld	a0,0(s1)
    8000651c:	00050663          	beqz	a0,80006528 <pipealloc+0xd4>
    80006520:	01013903          	ld	s2,16(sp)
    80006524:	0140006f          	j	80006538 <pipealloc+0xe4>
    80006528:	01013903          	ld	s2,16(sp)
    8000652c:	0100006f          	j	8000653c <pipealloc+0xe8>
    80006530:	0004b503          	ld	a0,0(s1)
    80006534:	02050c63          	beqz	a0,8000656c <pipealloc+0x118>
    fileclose(*f0);
    80006538:	a3dff0ef          	jal	80005f74 <fileclose>
  if(*f1)
    8000653c:	000a3783          	ld	a5,0(s4)
    fileclose(*f1);
  return -1;
    80006540:	fff00513          	li	a0,-1
  if(*f1)
    80006544:	00078863          	beqz	a5,80006554 <pipealloc+0x100>
    fileclose(*f1);
    80006548:	00078513          	mv	a0,a5
    8000654c:	a29ff0ef          	jal	80005f74 <fileclose>
  return -1;
    80006550:	fff00513          	li	a0,-1
}
    80006554:	02813083          	ld	ra,40(sp)
    80006558:	02013403          	ld	s0,32(sp)
    8000655c:	01813483          	ld	s1,24(sp)
    80006560:	00013a03          	ld	s4,0(sp)
    80006564:	03010113          	addi	sp,sp,48
    80006568:	00008067          	ret
  return -1;
    8000656c:	fff00513          	li	a0,-1
    80006570:	fe5ff06f          	j	80006554 <pipealloc+0x100>

0000000080006574 <pipeclose>:

void
pipeclose(struct pipe *pi, int writable)
{
    80006574:	fe010113          	addi	sp,sp,-32
    80006578:	00113c23          	sd	ra,24(sp)
    8000657c:	00813823          	sd	s0,16(sp)
    80006580:	00913423          	sd	s1,8(sp)
    80006584:	01213023          	sd	s2,0(sp)
    80006588:	02010413          	addi	s0,sp,32
    8000658c:	00050493          	mv	s1,a0
    80006590:	00058913          	mv	s2,a1
  acquire(&pi->lock);
    80006594:	aadfa0ef          	jal	80001040 <acquire>
  if(writable){
    80006598:	04090063          	beqz	s2,800065d8 <pipeclose+0x64>
    pi->writeopen = 0;
    8000659c:	2204a223          	sw	zero,548(s1)
    wakeup(&pi->nread);
    800065a0:	21848513          	addi	a0,s1,536
    800065a4:	9d5fc0ef          	jal	80002f78 <wakeup>
  } else {
    pi->readopen = 0;
    wakeup(&pi->nwrite);
  }
  if(pi->readopen == 0 && pi->writeopen == 0){
    800065a8:	2204a783          	lw	a5,544(s1)
    800065ac:	00079663          	bnez	a5,800065b8 <pipeclose+0x44>
    800065b0:	2244a783          	lw	a5,548(s1)
    800065b4:	02078a63          	beqz	a5,800065e8 <pipeclose+0x74>
    release(&pi->lock);
    kfree((char*)pi);
  } else
    release(&pi->lock);
    800065b8:	00048513          	mv	a0,s1
    800065bc:	b5dfa0ef          	jal	80001118 <release>
}
    800065c0:	01813083          	ld	ra,24(sp)
    800065c4:	01013403          	ld	s0,16(sp)
    800065c8:	00813483          	ld	s1,8(sp)
    800065cc:	00013903          	ld	s2,0(sp)
    800065d0:	02010113          	addi	sp,sp,32
    800065d4:	00008067          	ret
    pi->readopen = 0;
    800065d8:	2204a023          	sw	zero,544(s1)
    wakeup(&pi->nwrite);
    800065dc:	21c48513          	addi	a0,s1,540
    800065e0:	999fc0ef          	jal	80002f78 <wakeup>
    800065e4:	fc5ff06f          	j	800065a8 <pipeclose+0x34>
    release(&pi->lock);
    800065e8:	00048513          	mv	a0,s1
    800065ec:	b2dfa0ef          	jal	80001118 <release>
    kfree((char*)pi);
    800065f0:	00048513          	mv	a0,s1
    800065f4:	f9cfa0ef          	jal	80000d90 <kfree>
    800065f8:	fc9ff06f          	j	800065c0 <pipeclose+0x4c>

00000000800065fc <pipewrite>:

int
pipewrite(struct pipe *pi, uint64 addr, int n)
{
    800065fc:	f9010113          	addi	sp,sp,-112
    80006600:	06113423          	sd	ra,104(sp)
    80006604:	06813023          	sd	s0,96(sp)
    80006608:	04913c23          	sd	s1,88(sp)
    8000660c:	05213823          	sd	s2,80(sp)
    80006610:	05313423          	sd	s3,72(sp)
    80006614:	05413023          	sd	s4,64(sp)
    80006618:	03513c23          	sd	s5,56(sp)
    8000661c:	07010413          	addi	s0,sp,112
    80006620:	00050493          	mv	s1,a0
    80006624:	00058a93          	mv	s5,a1
    80006628:	00060a13          	mv	s4,a2
  int i = 0;
  struct proc *pr = myproc();
    8000662c:	fc9fb0ef          	jal	800025f4 <myproc>
    80006630:	00050993          	mv	s3,a0

  acquire(&pi->lock);
    80006634:	00048513          	mv	a0,s1
    80006638:	a09fa0ef          	jal	80001040 <acquire>
  while(i < n){
    8000663c:	11405e63          	blez	s4,80006758 <pipewrite+0x15c>
    80006640:	03613823          	sd	s6,48(sp)
    80006644:	03713423          	sd	s7,40(sp)
    80006648:	03813023          	sd	s8,32(sp)
    8000664c:	01913c23          	sd	s9,24(sp)
    80006650:	01a13823          	sd	s10,16(sp)
  int i = 0;
    80006654:	00000913          	li	s2,0
    if(pi->nwrite == pi->nread + PIPESIZE){ //DOC: pipewrite-full
      wakeup(&pi->nread);
      sleep(&pi->nwrite, &pi->lock);
    } else {
      char ch;
      if(copyin(pr->pagetable, &ch, addr + i, 1) == -1)
    80006658:	f9f40c13          	addi	s8,s0,-97
    8000665c:	00100b93          	li	s7,1
    80006660:	fff00b13          	li	s6,-1
      wakeup(&pi->nread);
    80006664:	21848d13          	addi	s10,s1,536
      sleep(&pi->nwrite, &pi->lock);
    80006668:	21c48c93          	addi	s9,s1,540
    8000666c:	0640006f          	j	800066d0 <pipewrite+0xd4>
      release(&pi->lock);
    80006670:	00048513          	mv	a0,s1
    80006674:	aa5fa0ef          	jal	80001118 <release>
      return -1;
    80006678:	fff00913          	li	s2,-1
    8000667c:	03013b03          	ld	s6,48(sp)
    80006680:	02813b83          	ld	s7,40(sp)
    80006684:	02013c03          	ld	s8,32(sp)
    80006688:	01813c83          	ld	s9,24(sp)
    8000668c:	01013d03          	ld	s10,16(sp)
  }
  wakeup(&pi->nread);
  release(&pi->lock);

  return i;
}
    80006690:	00090513          	mv	a0,s2
    80006694:	06813083          	ld	ra,104(sp)
    80006698:	06013403          	ld	s0,96(sp)
    8000669c:	05813483          	ld	s1,88(sp)
    800066a0:	05013903          	ld	s2,80(sp)
    800066a4:	04813983          	ld	s3,72(sp)
    800066a8:	04013a03          	ld	s4,64(sp)
    800066ac:	03813a83          	ld	s5,56(sp)
    800066b0:	07010113          	addi	sp,sp,112
    800066b4:	00008067          	ret
      wakeup(&pi->nread);
    800066b8:	000d0513          	mv	a0,s10
    800066bc:	8bdfc0ef          	jal	80002f78 <wakeup>
      sleep(&pi->nwrite, &pi->lock);
    800066c0:	00048593          	mv	a1,s1
    800066c4:	000c8513          	mv	a0,s9
    800066c8:	839fc0ef          	jal	80002f00 <sleep>
  while(i < n){
    800066cc:	07495263          	bge	s2,s4,80006730 <pipewrite+0x134>
    if(pi->readopen == 0 || killed(pr)){
    800066d0:	2204a783          	lw	a5,544(s1)
    800066d4:	f8078ee3          	beqz	a5,80006670 <pipewrite+0x74>
    800066d8:	00098513          	mv	a0,s3
    800066dc:	b65fc0ef          	jal	80003240 <killed>
    800066e0:	f80518e3          	bnez	a0,80006670 <pipewrite+0x74>
    if(pi->nwrite == pi->nread + PIPESIZE){ //DOC: pipewrite-full
    800066e4:	2184a783          	lw	a5,536(s1)
    800066e8:	21c4a703          	lw	a4,540(s1)
    800066ec:	2007879b          	addiw	a5,a5,512
    800066f0:	fcf704e3          	beq	a4,a5,800066b8 <pipewrite+0xbc>
      if(copyin(pr->pagetable, &ch, addr + i, 1) == -1)
    800066f4:	000b8693          	mv	a3,s7
    800066f8:	01590633          	add	a2,s2,s5
    800066fc:	000c0593          	mv	a1,s8
    80006700:	0509b503          	ld	a0,80(s3)
    80006704:	bb1fb0ef          	jal	800022b4 <copyin>
    80006708:	05650c63          	beq	a0,s6,80006760 <pipewrite+0x164>
      pi->data[pi->nwrite++ % PIPESIZE] = ch;
    8000670c:	21c4a783          	lw	a5,540(s1)
    80006710:	0017871b          	addiw	a4,a5,1
    80006714:	20e4ae23          	sw	a4,540(s1)
    80006718:	1ff7f793          	andi	a5,a5,511
    8000671c:	00f487b3          	add	a5,s1,a5
    80006720:	f9f44703          	lbu	a4,-97(s0)
    80006724:	00e78c23          	sb	a4,24(a5)
      i++;
    80006728:	0019091b          	addiw	s2,s2,1
    8000672c:	fa1ff06f          	j	800066cc <pipewrite+0xd0>
    80006730:	03013b03          	ld	s6,48(sp)
    80006734:	02813b83          	ld	s7,40(sp)
    80006738:	02013c03          	ld	s8,32(sp)
    8000673c:	01813c83          	ld	s9,24(sp)
    80006740:	01013d03          	ld	s10,16(sp)
  wakeup(&pi->nread);
    80006744:	21848513          	addi	a0,s1,536
    80006748:	831fc0ef          	jal	80002f78 <wakeup>
  release(&pi->lock);
    8000674c:	00048513          	mv	a0,s1
    80006750:	9c9fa0ef          	jal	80001118 <release>
  return i;
    80006754:	f3dff06f          	j	80006690 <pipewrite+0x94>
  int i = 0;
    80006758:	00000913          	li	s2,0
    8000675c:	fe9ff06f          	j	80006744 <pipewrite+0x148>
    80006760:	03013b03          	ld	s6,48(sp)
    80006764:	02813b83          	ld	s7,40(sp)
    80006768:	02013c03          	ld	s8,32(sp)
    8000676c:	01813c83          	ld	s9,24(sp)
    80006770:	01013d03          	ld	s10,16(sp)
    80006774:	fd1ff06f          	j	80006744 <pipewrite+0x148>

0000000080006778 <piperead>:

int
piperead(struct pipe *pi, uint64 addr, int n)
{
    80006778:	fa010113          	addi	sp,sp,-96
    8000677c:	04113c23          	sd	ra,88(sp)
    80006780:	04813823          	sd	s0,80(sp)
    80006784:	04913423          	sd	s1,72(sp)
    80006788:	05213023          	sd	s2,64(sp)
    8000678c:	03313c23          	sd	s3,56(sp)
    80006790:	03413823          	sd	s4,48(sp)
    80006794:	03513423          	sd	s5,40(sp)
    80006798:	06010413          	addi	s0,sp,96
    8000679c:	00050493          	mv	s1,a0
    800067a0:	00058913          	mv	s2,a1
    800067a4:	00060a93          	mv	s5,a2
  int i;
  struct proc *pr = myproc();
    800067a8:	e4dfb0ef          	jal	800025f4 <myproc>
    800067ac:	00050a13          	mv	s4,a0
  char ch;

  acquire(&pi->lock);
    800067b0:	00048513          	mv	a0,s1
    800067b4:	88dfa0ef          	jal	80001040 <acquire>
  while(pi->nread == pi->nwrite && pi->writeopen){  //DOC: pipe-empty
    800067b8:	2184a703          	lw	a4,536(s1)
    800067bc:	21c4a783          	lw	a5,540(s1)
    if(killed(pr)){
      release(&pi->lock);
      return -1;
    }
    sleep(&pi->nread, &pi->lock); //DOC: piperead-sleep
    800067c0:	21848993          	addi	s3,s1,536
  while(pi->nread == pi->nwrite && pi->writeopen){  //DOC: pipe-empty
    800067c4:	04f71063          	bne	a4,a5,80006804 <piperead+0x8c>
    800067c8:	2244a783          	lw	a5,548(s1)
    800067cc:	04078c63          	beqz	a5,80006824 <piperead+0xac>
    if(killed(pr)){
    800067d0:	000a0513          	mv	a0,s4
    800067d4:	a6dfc0ef          	jal	80003240 <killed>
    800067d8:	02051e63          	bnez	a0,80006814 <piperead+0x9c>
    sleep(&pi->nread, &pi->lock); //DOC: piperead-sleep
    800067dc:	00048593          	mv	a1,s1
    800067e0:	00098513          	mv	a0,s3
    800067e4:	f1cfc0ef          	jal	80002f00 <sleep>
  while(pi->nread == pi->nwrite && pi->writeopen){  //DOC: pipe-empty
    800067e8:	2184a703          	lw	a4,536(s1)
    800067ec:	21c4a783          	lw	a5,540(s1)
    800067f0:	fcf70ce3          	beq	a4,a5,800067c8 <piperead+0x50>
    800067f4:	03613023          	sd	s6,32(sp)
    800067f8:	01713c23          	sd	s7,24(sp)
    800067fc:	01813823          	sd	s8,16(sp)
    80006800:	0300006f          	j	80006830 <piperead+0xb8>
    80006804:	03613023          	sd	s6,32(sp)
    80006808:	01713c23          	sd	s7,24(sp)
    8000680c:	01813823          	sd	s8,16(sp)
    80006810:	0200006f          	j	80006830 <piperead+0xb8>
      release(&pi->lock);
    80006814:	00048513          	mv	a0,s1
    80006818:	901fa0ef          	jal	80001118 <release>
      return -1;
    8000681c:	fff00993          	li	s3,-1
    80006820:	08c0006f          	j	800068ac <piperead+0x134>
    80006824:	03613023          	sd	s6,32(sp)
    80006828:	01713c23          	sd	s7,24(sp)
    8000682c:	01813823          	sd	s8,16(sp)
  }
  for(i = 0; i < n; i++){  //DOC: piperead-copy
    80006830:	00000993          	li	s3,0
    if(pi->nread == pi->nwrite)
      break;
    ch = pi->data[pi->nread % PIPESIZE];
    if(copyout(pr->pagetable, addr + i, &ch, 1) == -1) {
    80006834:	faf40c13          	addi	s8,s0,-81
    80006838:	00100b93          	li	s7,1
    8000683c:	fff00b13          	li	s6,-1
  for(i = 0; i < n; i++){  //DOC: piperead-copy
    80006840:	05505863          	blez	s5,80006890 <piperead+0x118>
    if(pi->nread == pi->nwrite)
    80006844:	2184a783          	lw	a5,536(s1)
    80006848:	21c4a703          	lw	a4,540(s1)
    8000684c:	04f70263          	beq	a4,a5,80006890 <piperead+0x118>
    ch = pi->data[pi->nread % PIPESIZE];
    80006850:	1ff7f793          	andi	a5,a5,511
    80006854:	00f487b3          	add	a5,s1,a5
    80006858:	0187c783          	lbu	a5,24(a5)
    8000685c:	faf407a3          	sb	a5,-81(s0)
    if(copyout(pr->pagetable, addr + i, &ch, 1) == -1) {
    80006860:	000b8693          	mv	a3,s7
    80006864:	000c0613          	mv	a2,s8
    80006868:	00090593          	mv	a1,s2
    8000686c:	050a3503          	ld	a0,80(s4)
    80006870:	901fb0ef          	jal	80002170 <copyout>
    80006874:	07650063          	beq	a0,s6,800068d4 <piperead+0x15c>
      if(i == 0)
        i = -1;
      break;
    }
    pi->nread++;
    80006878:	2184a783          	lw	a5,536(s1)
    8000687c:	0017879b          	addiw	a5,a5,1
    80006880:	20f4ac23          	sw	a5,536(s1)
  for(i = 0; i < n; i++){  //DOC: piperead-copy
    80006884:	0019899b          	addiw	s3,s3,1
    80006888:	00190913          	addi	s2,s2,1
    8000688c:	fb3a9ce3          	bne	s5,s3,80006844 <piperead+0xcc>
  }
  wakeup(&pi->nwrite);  //DOC: piperead-wakeup
    80006890:	21c48513          	addi	a0,s1,540
    80006894:	ee4fc0ef          	jal	80002f78 <wakeup>
  release(&pi->lock);
    80006898:	00048513          	mv	a0,s1
    8000689c:	87dfa0ef          	jal	80001118 <release>
    800068a0:	02013b03          	ld	s6,32(sp)
    800068a4:	01813b83          	ld	s7,24(sp)
    800068a8:	01013c03          	ld	s8,16(sp)
  return i;
}
    800068ac:	00098513          	mv	a0,s3
    800068b0:	05813083          	ld	ra,88(sp)
    800068b4:	05013403          	ld	s0,80(sp)
    800068b8:	04813483          	ld	s1,72(sp)
    800068bc:	04013903          	ld	s2,64(sp)
    800068c0:	03813983          	ld	s3,56(sp)
    800068c4:	03013a03          	ld	s4,48(sp)
    800068c8:	02813a83          	ld	s5,40(sp)
    800068cc:	06010113          	addi	sp,sp,96
    800068d0:	00008067          	ret
      if(i == 0)
    800068d4:	fa099ee3          	bnez	s3,80006890 <piperead+0x118>
        i = -1;
    800068d8:	00050993          	mv	s3,a0
    800068dc:	fb5ff06f          	j	80006890 <piperead+0x118>

00000000800068e0 <flags2perm>:

static int loadseg(pde_t *, uint64, struct inode *, uint, uint);

// map ELF permissions to PTE permission bits.
int flags2perm(int flags)
{
    800068e0:	ff010113          	addi	sp,sp,-16
    800068e4:	00113423          	sd	ra,8(sp)
    800068e8:	00813023          	sd	s0,0(sp)
    800068ec:	01010413          	addi	s0,sp,16
    800068f0:	00050793          	mv	a5,a0
    int perm = 0;
    if(flags & 0x1)
    800068f4:	0035151b          	slliw	a0,a0,0x3
    800068f8:	00857513          	andi	a0,a0,8
      perm = PTE_X;
    if(flags & 0x2)
    800068fc:	0027f793          	andi	a5,a5,2
    80006900:	00078463          	beqz	a5,80006908 <flags2perm+0x28>
      perm |= PTE_W;
    80006904:	00456513          	ori	a0,a0,4
    return perm;
}
    80006908:	00813083          	ld	ra,8(sp)
    8000690c:	00013403          	ld	s0,0(sp)
    80006910:	01010113          	addi	sp,sp,16
    80006914:	00008067          	ret

0000000080006918 <kexec>:
//
// the implementation of the exec() system call
//
int
kexec(char *path, char **argv)
{
    80006918:	de010113          	addi	sp,sp,-544
    8000691c:	20113c23          	sd	ra,536(sp)
    80006920:	20813823          	sd	s0,528(sp)
    80006924:	20913423          	sd	s1,520(sp)
    80006928:	21213023          	sd	s2,512(sp)
    8000692c:	22010413          	addi	s0,sp,544
    80006930:	00050913          	mv	s2,a0
    80006934:	dea43823          	sd	a0,-528(s0)
    80006938:	e0b43023          	sd	a1,-512(s0)
  uint64 argc, sz = 0, sp, ustack[MAXARG], stackbase;
  struct elfhdr elf;
  struct inode *ip;
  struct proghdr ph;
  pagetable_t pagetable = 0, oldpagetable;
  struct proc *p = myproc();
    8000693c:	cb9fb0ef          	jal	800025f4 <myproc>
    80006940:	00050493          	mv	s1,a0

  begin_op();
    80006944:	854ff0ef          	jal	80005998 <begin_op>

  // Open the executable file.
  if((ip = namei(path)) == 0){
    80006948:	00090513          	mv	a0,s2
    8000694c:	d91fe0ef          	jal	800056dc <namei>
    80006950:	06050663          	beqz	a0,800069bc <kexec+0xa4>
    80006954:	1f413823          	sd	s4,496(sp)
    80006958:	00050a13          	mv	s4,a0
    end_op();
    return -1;
  }
  ilock(ip);
    8000695c:	914fe0ef          	jal	80004a70 <ilock>

  // Read the ELF header.
  if(readi(ip, 0, (uint64)&elf, 0, sizeof(elf)) != sizeof(elf))
    80006960:	04000713          	li	a4,64
    80006964:	00000693          	li	a3,0
    80006968:	e5040613          	addi	a2,s0,-432
    8000696c:	00000593          	li	a1,0
    80006970:	000a0513          	mv	a0,s4
    80006974:	e44fe0ef          	jal	80004fb8 <readi>
    80006978:	04000793          	li	a5,64
    8000697c:	00f51a63          	bne	a0,a5,80006990 <kexec+0x78>
    goto bad;

  // Is this really an ELF file?
  if(elf.magic != ELF_MAGIC)
    80006980:	e5042703          	lw	a4,-432(s0)
    80006984:	464c47b7          	lui	a5,0x464c4
    80006988:	57f78793          	addi	a5,a5,1407 # 464c457f <_binary_fs_img_size+0x462d057f>
    8000698c:	02f70e63          	beq	a4,a5,800069c8 <kexec+0xb0>

 bad:
  if(pagetable)
    proc_freepagetable(pagetable, sz);
  if(ip){
    iunlockput(ip);
    80006990:	000a0513          	mv	a0,s4
    80006994:	bc8fe0ef          	jal	80004d5c <iunlockput>
    end_op();
    80006998:	8a4ff0ef          	jal	80005a3c <end_op>
  }
  return -1;
    8000699c:	fff00513          	li	a0,-1
    800069a0:	1f013a03          	ld	s4,496(sp)
}
    800069a4:	21813083          	ld	ra,536(sp)
    800069a8:	21013403          	ld	s0,528(sp)
    800069ac:	20813483          	ld	s1,520(sp)
    800069b0:	20013903          	ld	s2,512(sp)
    800069b4:	22010113          	addi	sp,sp,544
    800069b8:	00008067          	ret
    end_op();
    800069bc:	880ff0ef          	jal	80005a3c <end_op>
    return -1;
    800069c0:	fff00513          	li	a0,-1
    800069c4:	fe1ff06f          	j	800069a4 <kexec+0x8c>
    800069c8:	1f613023          	sd	s6,480(sp)
  if((pagetable = proc_pagetable(p)) == 0)
    800069cc:	00048513          	mv	a0,s1
    800069d0:	dd9fb0ef          	jal	800027a8 <proc_pagetable>
    800069d4:	00050b13          	mv	s6,a0
    800069d8:	34050a63          	beqz	a0,80006d2c <kexec+0x414>
    800069dc:	1f313c23          	sd	s3,504(sp)
    800069e0:	1f513423          	sd	s5,488(sp)
    800069e4:	1d713c23          	sd	s7,472(sp)
    800069e8:	1d813823          	sd	s8,464(sp)
    800069ec:	1d913423          	sd	s9,456(sp)
    800069f0:	1da13023          	sd	s10,448(sp)
  for(i=0, off=elf.phoff; i<elf.phnum; i++, off+=sizeof(ph)){
    800069f4:	e8845783          	lhu	a5,-376(s0)
    800069f8:	1a078c63          	beqz	a5,80006bb0 <kexec+0x298>
    800069fc:	1bb13c23          	sd	s11,440(sp)
    80006a00:	e7042683          	lw	a3,-400(s0)
  uint64 argc, sz = 0, sp, ustack[MAXARG], stackbase;
    80006a04:	00000913          	li	s2,0
  for(i=0, off=elf.phoff; i<elf.phnum; i++, off+=sizeof(ph)){
    80006a08:	00000d13          	li	s10,0
    if(readi(ip, 0, (uint64)&ph, off, sizeof(ph)) != sizeof(ph))
    80006a0c:	03800d93          	li	s11,56
    if(ph.vaddr % PGSIZE != 0)
    80006a10:	00001cb7          	lui	s9,0x1
    80006a14:	fffc8793          	addi	a5,s9,-1 # fff <_binary_fs_img_size-0x1f3001>
    80006a18:	def43423          	sd	a5,-536(s0)

  for(i = 0; i < sz; i += PGSIZE){
    pa = walkaddr(pagetable, va + i);
    if(pa == 0)
      panic("loadseg: address should exist");
    if(sz - i < PGSIZE)
    80006a1c:	00001ab7          	lui	s5,0x1
    80006a20:	07c0006f          	j	80006a9c <kexec+0x184>
      panic("loadseg: address should exist");
    80006a24:	00003517          	auipc	a0,0x3
    80006a28:	f7450513          	addi	a0,a0,-140 # 80009998 <etext+0x998>
    80006a2c:	8c0fa0ef          	jal	80000aec <panic>
    if(sz - i < PGSIZE)
    80006a30:	0009091b          	sext.w	s2,s2
      n = sz - i;
    else
      n = PGSIZE;
    if(readi(ip, 0, (uint64)pa, offset+i, n) != n)
    80006a34:	00090713          	mv	a4,s2
    80006a38:	009b86bb          	addw	a3,s7,s1
    80006a3c:	00000593          	li	a1,0
    80006a40:	000a0513          	mv	a0,s4
    80006a44:	d74fe0ef          	jal	80004fb8 <readi>
    80006a48:	2ea91863          	bne	s2,a0,80006d38 <kexec+0x420>
  for(i = 0; i < sz; i += PGSIZE){
    80006a4c:	009a84bb          	addw	s1,s5,s1
    80006a50:	0334fa63          	bgeu	s1,s3,80006a84 <kexec+0x16c>
    pa = walkaddr(pagetable, va + i);
    80006a54:	02049593          	slli	a1,s1,0x20
    80006a58:	0205d593          	srli	a1,a1,0x20
    80006a5c:	018585b3          	add	a1,a1,s8
    80006a60:	000b0513          	mv	a0,s6
    80006a64:	cf5fa0ef          	jal	80001758 <walkaddr>
    80006a68:	00050613          	mv	a2,a0
    if(pa == 0)
    80006a6c:	fa050ce3          	beqz	a0,80006a24 <kexec+0x10c>
    if(sz - i < PGSIZE)
    80006a70:	409987bb          	subw	a5,s3,s1
    80006a74:	00078913          	mv	s2,a5
    80006a78:	fafcfce3          	bgeu	s9,a5,80006a30 <kexec+0x118>
    80006a7c:	000a8913          	mv	s2,s5
    80006a80:	fb1ff06f          	j	80006a30 <kexec+0x118>
    sz = sz1;
    80006a84:	df843903          	ld	s2,-520(s0)
  for(i=0, off=elf.phoff; i<elf.phnum; i++, off+=sizeof(ph)){
    80006a88:	001d0d1b          	addiw	s10,s10,1
    80006a8c:	e0843783          	ld	a5,-504(s0)
    80006a90:	0387869b          	addiw	a3,a5,56
    80006a94:	e8845783          	lhu	a5,-376(s0)
    80006a98:	08fd5a63          	bge	s10,a5,80006b2c <kexec+0x214>
    if(readi(ip, 0, (uint64)&ph, off, sizeof(ph)) != sizeof(ph))
    80006a9c:	e0d43423          	sd	a3,-504(s0)
    80006aa0:	000d8713          	mv	a4,s11
    80006aa4:	e1840613          	addi	a2,s0,-488
    80006aa8:	00000593          	li	a1,0
    80006aac:	000a0513          	mv	a0,s4
    80006ab0:	d08fe0ef          	jal	80004fb8 <readi>
    80006ab4:	29b51063          	bne	a0,s11,80006d34 <kexec+0x41c>
    if(ph.type != ELF_PROG_LOAD)
    80006ab8:	e1842783          	lw	a5,-488(s0)
    80006abc:	00100713          	li	a4,1
    80006ac0:	fce794e3          	bne	a5,a4,80006a88 <kexec+0x170>
    if(ph.memsz < ph.filesz)
    80006ac4:	e4043483          	ld	s1,-448(s0)
    80006ac8:	e3843783          	ld	a5,-456(s0)
    80006acc:	28f4ee63          	bltu	s1,a5,80006d68 <kexec+0x450>
    if(ph.vaddr + ph.memsz < ph.vaddr)
    80006ad0:	e2843783          	ld	a5,-472(s0)
    80006ad4:	00f484b3          	add	s1,s1,a5
    80006ad8:	28f4ec63          	bltu	s1,a5,80006d70 <kexec+0x458>
    if(ph.vaddr % PGSIZE != 0)
    80006adc:	de843703          	ld	a4,-536(s0)
    80006ae0:	00e7f7b3          	and	a5,a5,a4
    80006ae4:	28079a63          	bnez	a5,80006d78 <kexec+0x460>
    if((sz1 = uvmalloc(pagetable, sz, ph.vaddr + ph.memsz, flags2perm(ph.flags))) == 0)
    80006ae8:	e1c42503          	lw	a0,-484(s0)
    80006aec:	df5ff0ef          	jal	800068e0 <flags2perm>
    80006af0:	00050693          	mv	a3,a0
    80006af4:	00048613          	mv	a2,s1
    80006af8:	00090593          	mv	a1,s2
    80006afc:	000b0513          	mv	a0,s6
    80006b00:	8ccfb0ef          	jal	80001bcc <uvmalloc>
    80006b04:	dea43c23          	sd	a0,-520(s0)
    80006b08:	26050c63          	beqz	a0,80006d80 <kexec+0x468>
    if(loadseg(pagetable, ph.vaddr, ip, ph.off, ph.filesz) < 0)
    80006b0c:	e3842983          	lw	s3,-456(s0)
  for(i = 0; i < sz; i += PGSIZE){
    80006b10:	00098a63          	beqz	s3,80006b24 <kexec+0x20c>
    if(loadseg(pagetable, ph.vaddr, ip, ph.off, ph.filesz) < 0)
    80006b14:	e2843c03          	ld	s8,-472(s0)
    80006b18:	e2042b83          	lw	s7,-480(s0)
  for(i = 0; i < sz; i += PGSIZE){
    80006b1c:	00000493          	li	s1,0
    80006b20:	f35ff06f          	j	80006a54 <kexec+0x13c>
    sz = sz1;
    80006b24:	df843903          	ld	s2,-520(s0)
    80006b28:	f61ff06f          	j	80006a88 <kexec+0x170>
    80006b2c:	1b813d83          	ld	s11,440(sp)
  iunlockput(ip);
    80006b30:	000a0513          	mv	a0,s4
    80006b34:	a28fe0ef          	jal	80004d5c <iunlockput>
  end_op();
    80006b38:	f05fe0ef          	jal	80005a3c <end_op>
  p = myproc();
    80006b3c:	ab9fb0ef          	jal	800025f4 <myproc>
    80006b40:	00050a93          	mv	s5,a0
  uint64 oldsz = p->sz;
    80006b44:	04853d03          	ld	s10,72(a0)
  sz = PGROUNDUP(sz);
    80006b48:	000019b7          	lui	s3,0x1
    80006b4c:	fff98993          	addi	s3,s3,-1 # fff <_binary_fs_img_size-0x1f3001>
    80006b50:	013909b3          	add	s3,s2,s3
    80006b54:	fffff7b7          	lui	a5,0xfffff
    80006b58:	00f9f9b3          	and	s3,s3,a5
  if((sz1 = uvmalloc(pagetable, sz, sz + (USERSTACK+1)*PGSIZE, PTE_W)) == 0)
    80006b5c:	00400693          	li	a3,4
    80006b60:	00002637          	lui	a2,0x2
    80006b64:	00c98633          	add	a2,s3,a2
    80006b68:	00098593          	mv	a1,s3
    80006b6c:	000b0513          	mv	a0,s6
    80006b70:	85cfb0ef          	jal	80001bcc <uvmalloc>
    80006b74:	00050a13          	mv	s4,a0
    80006b78:	04051063          	bnez	a0,80006bb8 <kexec+0x2a0>
    proc_freepagetable(pagetable, sz);
    80006b7c:	00098593          	mv	a1,s3
    80006b80:	000b0513          	mv	a0,s6
    80006b84:	cf5fb0ef          	jal	80002878 <proc_freepagetable>
  return -1;
    80006b88:	fff00513          	li	a0,-1
    80006b8c:	1f813983          	ld	s3,504(sp)
    80006b90:	1f013a03          	ld	s4,496(sp)
    80006b94:	1e813a83          	ld	s5,488(sp)
    80006b98:	1e013b03          	ld	s6,480(sp)
    80006b9c:	1d813b83          	ld	s7,472(sp)
    80006ba0:	1d013c03          	ld	s8,464(sp)
    80006ba4:	1c813c83          	ld	s9,456(sp)
    80006ba8:	1c013d03          	ld	s10,448(sp)
    80006bac:	df9ff06f          	j	800069a4 <kexec+0x8c>
  uint64 argc, sz = 0, sp, ustack[MAXARG], stackbase;
    80006bb0:	00000913          	li	s2,0
    80006bb4:	f7dff06f          	j	80006b30 <kexec+0x218>
  uvmclear(pagetable, sz-(USERSTACK+1)*PGSIZE);
    80006bb8:	ffffe5b7          	lui	a1,0xffffe
    80006bbc:	00b505b3          	add	a1,a0,a1
    80006bc0:	000b0513          	mv	a0,s6
    80006bc4:	b28fb0ef          	jal	80001eec <uvmclear>
  stackbase = sp - USERSTACK*PGSIZE;
    80006bc8:	800a0b93          	addi	s7,s4,-2048
    80006bcc:	800b8b93          	addi	s7,s7,-2048
  for(argc = 0; argv[argc]; argc++) {
    80006bd0:	e0043783          	ld	a5,-512(s0)
    80006bd4:	0007b503          	ld	a0,0(a5) # fffffffffffff000 <end+0xffffffff7fbf42a0>
  sp = sz;
    80006bd8:	000a0913          	mv	s2,s4
  for(argc = 0; argv[argc]; argc++) {
    80006bdc:	00000493          	li	s1,0
    ustack[argc] = sp;
    80006be0:	e9040c93          	addi	s9,s0,-368
    if(argc >= MAXARG)
    80006be4:	02000c13          	li	s8,32
  for(argc = 0; argv[argc]; argc++) {
    80006be8:	06050863          	beqz	a0,80006c58 <kexec+0x340>
    sp -= strlen(argv[argc]) + 1;
    80006bec:	85dfa0ef          	jal	80001448 <strlen>
    80006bf0:	0015079b          	addiw	a5,a0,1
    80006bf4:	40f907b3          	sub	a5,s2,a5
    sp -= sp % 16; // riscv sp must be 16-byte aligned
    80006bf8:	ff07f913          	andi	s2,a5,-16
    if(sp < stackbase)
    80006bfc:	19796663          	bltu	s2,s7,80006d88 <kexec+0x470>
    if(copyout(pagetable, sp, argv[argc], strlen(argv[argc]) + 1) < 0)
    80006c00:	e0043783          	ld	a5,-512(s0)
    80006c04:	0007b983          	ld	s3,0(a5)
    80006c08:	00098513          	mv	a0,s3
    80006c0c:	83dfa0ef          	jal	80001448 <strlen>
    80006c10:	0015069b          	addiw	a3,a0,1
    80006c14:	00098613          	mv	a2,s3
    80006c18:	00090593          	mv	a1,s2
    80006c1c:	000b0513          	mv	a0,s6
    80006c20:	d50fb0ef          	jal	80002170 <copyout>
    80006c24:	16054663          	bltz	a0,80006d90 <kexec+0x478>
    ustack[argc] = sp;
    80006c28:	00349793          	slli	a5,s1,0x3
    80006c2c:	00fc87b3          	add	a5,s9,a5
    80006c30:	0127b023          	sd	s2,0(a5)
  for(argc = 0; argv[argc]; argc++) {
    80006c34:	00148493          	addi	s1,s1,1
    80006c38:	e0043783          	ld	a5,-512(s0)
    80006c3c:	00878793          	addi	a5,a5,8
    80006c40:	e0f43023          	sd	a5,-512(s0)
    80006c44:	0007b503          	ld	a0,0(a5)
    80006c48:	00050863          	beqz	a0,80006c58 <kexec+0x340>
    if(argc >= MAXARG)
    80006c4c:	fb8490e3          	bne	s1,s8,80006bec <kexec+0x2d4>
  sz = sz1;
    80006c50:	000a0993          	mv	s3,s4
    80006c54:	f29ff06f          	j	80006b7c <kexec+0x264>
  ustack[argc] = 0;
    80006c58:	00349793          	slli	a5,s1,0x3
    80006c5c:	f9078793          	addi	a5,a5,-112
    80006c60:	008787b3          	add	a5,a5,s0
    80006c64:	f007b023          	sd	zero,-256(a5)
  sp -= (argc+1) * sizeof(uint64);
    80006c68:	00349693          	slli	a3,s1,0x3
    80006c6c:	00868693          	addi	a3,a3,8
    80006c70:	40d90933          	sub	s2,s2,a3
  sp -= sp % 16;
    80006c74:	ff097913          	andi	s2,s2,-16
  sz = sz1;
    80006c78:	000a0993          	mv	s3,s4
  if(sp < stackbase)
    80006c7c:	f17960e3          	bltu	s2,s7,80006b7c <kexec+0x264>
  if(copyout(pagetable, sp, (char *)ustack, (argc+1)*sizeof(uint64)) < 0)
    80006c80:	e9040613          	addi	a2,s0,-368
    80006c84:	00090593          	mv	a1,s2
    80006c88:	000b0513          	mv	a0,s6
    80006c8c:	ce4fb0ef          	jal	80002170 <copyout>
    80006c90:	ee0546e3          	bltz	a0,80006b7c <kexec+0x264>
  p->trapframe->a1 = sp;
    80006c94:	058ab783          	ld	a5,88(s5) # 1058 <_binary_fs_img_size-0x1f2fa8>
    80006c98:	0727bc23          	sd	s2,120(a5)
  for(last=s=path; *s; s++)
    80006c9c:	df043783          	ld	a5,-528(s0)
    80006ca0:	0007c703          	lbu	a4,0(a5)
    80006ca4:	02070463          	beqz	a4,80006ccc <kexec+0x3b4>
    80006ca8:	00178793          	addi	a5,a5,1
    if(*s == '/')
    80006cac:	02f00693          	li	a3,47
    80006cb0:	0100006f          	j	80006cc0 <kexec+0x3a8>
  for(last=s=path; *s; s++)
    80006cb4:	00178793          	addi	a5,a5,1
    80006cb8:	fff7c703          	lbu	a4,-1(a5)
    80006cbc:	00070863          	beqz	a4,80006ccc <kexec+0x3b4>
    if(*s == '/')
    80006cc0:	fed71ae3          	bne	a4,a3,80006cb4 <kexec+0x39c>
      last = s+1;
    80006cc4:	def43823          	sd	a5,-528(s0)
    80006cc8:	fedff06f          	j	80006cb4 <kexec+0x39c>
  safestrcpy(p->name, last, sizeof(p->name));
    80006ccc:	01000613          	li	a2,16
    80006cd0:	df043583          	ld	a1,-528(s0)
    80006cd4:	158a8513          	addi	a0,s5,344
    80006cd8:	f1cfa0ef          	jal	800013f4 <safestrcpy>
  oldpagetable = p->pagetable;
    80006cdc:	050ab503          	ld	a0,80(s5)
  p->pagetable = pagetable;
    80006ce0:	056ab823          	sd	s6,80(s5)
  p->sz = sz;
    80006ce4:	054ab423          	sd	s4,72(s5)
  p->trapframe->epc = elf.entry;  // initial program counter = ulib.c:start()
    80006ce8:	058ab783          	ld	a5,88(s5)
    80006cec:	e6843703          	ld	a4,-408(s0)
    80006cf0:	00e7bc23          	sd	a4,24(a5)
  p->trapframe->sp = sp; // initial stack pointer
    80006cf4:	058ab783          	ld	a5,88(s5)
    80006cf8:	0327b823          	sd	s2,48(a5)
  proc_freepagetable(oldpagetable, oldsz);
    80006cfc:	000d0593          	mv	a1,s10
    80006d00:	b79fb0ef          	jal	80002878 <proc_freepagetable>
  return argc; // this ends up in a0, the first argument to main(argc, argv)
    80006d04:	0004851b          	sext.w	a0,s1
    80006d08:	1f813983          	ld	s3,504(sp)
    80006d0c:	1f013a03          	ld	s4,496(sp)
    80006d10:	1e813a83          	ld	s5,488(sp)
    80006d14:	1e013b03          	ld	s6,480(sp)
    80006d18:	1d813b83          	ld	s7,472(sp)
    80006d1c:	1d013c03          	ld	s8,464(sp)
    80006d20:	1c813c83          	ld	s9,456(sp)
    80006d24:	1c013d03          	ld	s10,448(sp)
    80006d28:	c7dff06f          	j	800069a4 <kexec+0x8c>
    80006d2c:	1e013b03          	ld	s6,480(sp)
    80006d30:	c61ff06f          	j	80006990 <kexec+0x78>
    80006d34:	df243c23          	sd	s2,-520(s0)
    proc_freepagetable(pagetable, sz);
    80006d38:	df843583          	ld	a1,-520(s0)
    80006d3c:	000b0513          	mv	a0,s6
    80006d40:	b39fb0ef          	jal	80002878 <proc_freepagetable>
  if(ip){
    80006d44:	1f813983          	ld	s3,504(sp)
    80006d48:	1e813a83          	ld	s5,488(sp)
    80006d4c:	1e013b03          	ld	s6,480(sp)
    80006d50:	1d813b83          	ld	s7,472(sp)
    80006d54:	1d013c03          	ld	s8,464(sp)
    80006d58:	1c813c83          	ld	s9,456(sp)
    80006d5c:	1c013d03          	ld	s10,448(sp)
    80006d60:	1b813d83          	ld	s11,440(sp)
    80006d64:	c2dff06f          	j	80006990 <kexec+0x78>
    80006d68:	df243c23          	sd	s2,-520(s0)
    80006d6c:	fcdff06f          	j	80006d38 <kexec+0x420>
    80006d70:	df243c23          	sd	s2,-520(s0)
    80006d74:	fc5ff06f          	j	80006d38 <kexec+0x420>
    80006d78:	df243c23          	sd	s2,-520(s0)
    80006d7c:	fbdff06f          	j	80006d38 <kexec+0x420>
    80006d80:	df243c23          	sd	s2,-520(s0)
    80006d84:	fb5ff06f          	j	80006d38 <kexec+0x420>
  sz = sz1;
    80006d88:	000a0993          	mv	s3,s4
    80006d8c:	df1ff06f          	j	80006b7c <kexec+0x264>
    80006d90:	000a0993          	mv	s3,s4
    80006d94:	de9ff06f          	j	80006b7c <kexec+0x264>

0000000080006d98 <argfd>:

// Fetch the nth word-sized system call argument as a file descriptor
// and return both the descriptor and the corresponding struct file.
static int
argfd(int n, int *pfd, struct file **pf)
{
    80006d98:	fd010113          	addi	sp,sp,-48
    80006d9c:	02113423          	sd	ra,40(sp)
    80006da0:	02813023          	sd	s0,32(sp)
    80006da4:	00913c23          	sd	s1,24(sp)
    80006da8:	01213823          	sd	s2,16(sp)
    80006dac:	03010413          	addi	s0,sp,48
    80006db0:	00058913          	mv	s2,a1
    80006db4:	00060493          	mv	s1,a2
  int fd;
  struct file *f;

  argint(n, &fd);
    80006db8:	fdc40593          	addi	a1,s0,-36
    80006dbc:	e85fc0ef          	jal	80003c40 <argint>
  if(fd < 0 || fd >= NOFILE || (f=myproc()->ofile[fd]) == 0)
    80006dc0:	fdc42703          	lw	a4,-36(s0)
    80006dc4:	00f00793          	li	a5,15
    80006dc8:	04e7e663          	bltu	a5,a4,80006e14 <argfd+0x7c>
    80006dcc:	829fb0ef          	jal	800025f4 <myproc>
    80006dd0:	fdc42703          	lw	a4,-36(s0)
    80006dd4:	00371793          	slli	a5,a4,0x3
    80006dd8:	0d078793          	addi	a5,a5,208
    80006ddc:	00f50533          	add	a0,a0,a5
    80006de0:	00053783          	ld	a5,0(a0)
    80006de4:	02078c63          	beqz	a5,80006e1c <argfd+0x84>
    return -1;
  if(pfd)
    80006de8:	00090463          	beqz	s2,80006df0 <argfd+0x58>
    *pfd = fd;
    80006dec:	00e92023          	sw	a4,0(s2)
  if(pf)
    *pf = f;
  return 0;
    80006df0:	00000513          	li	a0,0
  if(pf)
    80006df4:	00048463          	beqz	s1,80006dfc <argfd+0x64>
    *pf = f;
    80006df8:	00f4b023          	sd	a5,0(s1)
}
    80006dfc:	02813083          	ld	ra,40(sp)
    80006e00:	02013403          	ld	s0,32(sp)
    80006e04:	01813483          	ld	s1,24(sp)
    80006e08:	01013903          	ld	s2,16(sp)
    80006e0c:	03010113          	addi	sp,sp,48
    80006e10:	00008067          	ret
    return -1;
    80006e14:	fff00513          	li	a0,-1
    80006e18:	fe5ff06f          	j	80006dfc <argfd+0x64>
    80006e1c:	fff00513          	li	a0,-1
    80006e20:	fddff06f          	j	80006dfc <argfd+0x64>

0000000080006e24 <fdalloc>:

// Allocate a file descriptor for the given file.
// Takes over file reference from caller on success.
static int
fdalloc(struct file *f)
{
    80006e24:	fe010113          	addi	sp,sp,-32
    80006e28:	00113c23          	sd	ra,24(sp)
    80006e2c:	00813823          	sd	s0,16(sp)
    80006e30:	00913423          	sd	s1,8(sp)
    80006e34:	02010413          	addi	s0,sp,32
    80006e38:	00050493          	mv	s1,a0
  int fd;
  struct proc *p = myproc();
    80006e3c:	fb8fb0ef          	jal	800025f4 <myproc>
    80006e40:	00050613          	mv	a2,a0

  for(fd = 0; fd < NOFILE; fd++){
    80006e44:	0d050793          	addi	a5,a0,208
    80006e48:	00000513          	li	a0,0
    80006e4c:	01000693          	li	a3,16
    if(p->ofile[fd] == 0){
    80006e50:	0007b703          	ld	a4,0(a5)
    80006e54:	02070463          	beqz	a4,80006e7c <fdalloc+0x58>
  for(fd = 0; fd < NOFILE; fd++){
    80006e58:	0015051b          	addiw	a0,a0,1
    80006e5c:	00878793          	addi	a5,a5,8
    80006e60:	fed518e3          	bne	a0,a3,80006e50 <fdalloc+0x2c>
      p->ofile[fd] = f;
      return fd;
    }
  }
  return -1;
    80006e64:	fff00513          	li	a0,-1
}
    80006e68:	01813083          	ld	ra,24(sp)
    80006e6c:	01013403          	ld	s0,16(sp)
    80006e70:	00813483          	ld	s1,8(sp)
    80006e74:	02010113          	addi	sp,sp,32
    80006e78:	00008067          	ret
      p->ofile[fd] = f;
    80006e7c:	00351793          	slli	a5,a0,0x3
    80006e80:	0d078793          	addi	a5,a5,208
    80006e84:	00f60633          	add	a2,a2,a5
    80006e88:	00963023          	sd	s1,0(a2) # 2000 <_binary_fs_img_size-0x1f2000>
      return fd;
    80006e8c:	fddff06f          	j	80006e68 <fdalloc+0x44>

0000000080006e90 <create>:
  return -1;
}

static struct inode*
create(char *path, short type, short major, short minor)
{
    80006e90:	fb010113          	addi	sp,sp,-80
    80006e94:	04113423          	sd	ra,72(sp)
    80006e98:	04813023          	sd	s0,64(sp)
    80006e9c:	02913c23          	sd	s1,56(sp)
    80006ea0:	03213823          	sd	s2,48(sp)
    80006ea4:	03313423          	sd	s3,40(sp)
    80006ea8:	03413023          	sd	s4,32(sp)
    80006eac:	01513c23          	sd	s5,24(sp)
    80006eb0:	01613823          	sd	s6,16(sp)
    80006eb4:	05010413          	addi	s0,sp,80
    80006eb8:	00058913          	mv	s2,a1
    80006ebc:	00058a13          	mv	s4,a1
    80006ec0:	00060a93          	mv	s5,a2
    80006ec4:	00068b13          	mv	s6,a3
  struct inode *ip, *dp;
  char name[DIRSIZ];

  if((dp = nameiparent(path, name)) == 0)
    80006ec8:	fb040593          	addi	a1,s0,-80
    80006ecc:	83dfe0ef          	jal	80005708 <nameiparent>
    80006ed0:	00050493          	mv	s1,a0
    80006ed4:	16050863          	beqz	a0,80007044 <create+0x1b4>
    return 0;

  ilock(dp);
    80006ed8:	b99fd0ef          	jal	80004a70 <ilock>

  if((ip = dirlookup(dp, name, 0)) != 0){
    80006edc:	00000613          	li	a2,0
    80006ee0:	fb040593          	addi	a1,s0,-80
    80006ee4:	00048513          	mv	a0,s1
    80006ee8:	c04fe0ef          	jal	800052ec <dirlookup>
    80006eec:	00050993          	mv	s3,a0
    80006ef0:	06050863          	beqz	a0,80006f60 <create+0xd0>
    iunlockput(dp);
    80006ef4:	00048513          	mv	a0,s1
    80006ef8:	e65fd0ef          	jal	80004d5c <iunlockput>
    ilock(ip);
    80006efc:	00098513          	mv	a0,s3
    80006f00:	b71fd0ef          	jal	80004a70 <ilock>
    if(type == T_FILE && (ip->type == T_FILE || ip->type == T_DEVICE))
    80006f04:	00200793          	li	a5,2
    80006f08:	04f91463          	bne	s2,a5,80006f50 <create+0xc0>
    80006f0c:	0449d783          	lhu	a5,68(s3)
    80006f10:	ffe7879b          	addiw	a5,a5,-2
    80006f14:	03079793          	slli	a5,a5,0x30
    80006f18:	0307d793          	srli	a5,a5,0x30
    80006f1c:	00100713          	li	a4,1
    80006f20:	02f76863          	bltu	a4,a5,80006f50 <create+0xc0>
  ip->nlink = 0;
  iupdate(ip);
  iunlockput(ip);
  iunlockput(dp);
  return 0;
}
    80006f24:	00098513          	mv	a0,s3
    80006f28:	04813083          	ld	ra,72(sp)
    80006f2c:	04013403          	ld	s0,64(sp)
    80006f30:	03813483          	ld	s1,56(sp)
    80006f34:	03013903          	ld	s2,48(sp)
    80006f38:	02813983          	ld	s3,40(sp)
    80006f3c:	02013a03          	ld	s4,32(sp)
    80006f40:	01813a83          	ld	s5,24(sp)
    80006f44:	01013b03          	ld	s6,16(sp)
    80006f48:	05010113          	addi	sp,sp,80
    80006f4c:	00008067          	ret
    iunlockput(ip);
    80006f50:	00098513          	mv	a0,s3
    80006f54:	e09fd0ef          	jal	80004d5c <iunlockput>
    return 0;
    80006f58:	00000993          	li	s3,0
    80006f5c:	fc9ff06f          	j	80006f24 <create+0x94>
  if((ip = ialloc(dp->dev, type)) == 0){
    80006f60:	00090593          	mv	a1,s2
    80006f64:	0004a503          	lw	a0,0(s1)
    80006f68:	8f1fd0ef          	jal	80004858 <ialloc>
    80006f6c:	00050913          	mv	s2,a0
    80006f70:	04050663          	beqz	a0,80006fbc <create+0x12c>
  ilock(ip);
    80006f74:	afdfd0ef          	jal	80004a70 <ilock>
  ip->major = major;
    80006f78:	05591323          	sh	s5,70(s2)
  ip->minor = minor;
    80006f7c:	05691423          	sh	s6,72(s2)
  ip->nlink = 1;
    80006f80:	00100793          	li	a5,1
    80006f84:	04f91523          	sh	a5,74(s2)
  iupdate(ip);
    80006f88:	00090513          	mv	a0,s2
    80006f8c:	9e1fd0ef          	jal	8000496c <iupdate>
  if(type == T_DIR){  // Create . and .. entries.
    80006f90:	00100713          	li	a4,1
    80006f94:	02ea0a63          	beq	s4,a4,80006fc8 <create+0x138>
  if(dirlink(dp, name, ip->inum) < 0)
    80006f98:	00492603          	lw	a2,4(s2)
    80006f9c:	fb040593          	addi	a1,s0,-80
    80006fa0:	00048513          	mv	a0,s1
    80006fa4:	e30fe0ef          	jal	800055d4 <dirlink>
    80006fa8:	06054e63          	bltz	a0,80007024 <create+0x194>
  iunlockput(dp);
    80006fac:	00048513          	mv	a0,s1
    80006fb0:	dadfd0ef          	jal	80004d5c <iunlockput>
  return ip;
    80006fb4:	00090993          	mv	s3,s2
    80006fb8:	f6dff06f          	j	80006f24 <create+0x94>
    iunlockput(dp);
    80006fbc:	00048513          	mv	a0,s1
    80006fc0:	d9dfd0ef          	jal	80004d5c <iunlockput>
    return 0;
    80006fc4:	f61ff06f          	j	80006f24 <create+0x94>
    if(dirlink(ip, ".", ip->inum) < 0 || dirlink(ip, "..", dp->inum) < 0)
    80006fc8:	00492603          	lw	a2,4(s2)
    80006fcc:	00003597          	auipc	a1,0x3
    80006fd0:	9ec58593          	addi	a1,a1,-1556 # 800099b8 <etext+0x9b8>
    80006fd4:	00090513          	mv	a0,s2
    80006fd8:	dfcfe0ef          	jal	800055d4 <dirlink>
    80006fdc:	04054463          	bltz	a0,80007024 <create+0x194>
    80006fe0:	0044a603          	lw	a2,4(s1)
    80006fe4:	00003597          	auipc	a1,0x3
    80006fe8:	9dc58593          	addi	a1,a1,-1572 # 800099c0 <etext+0x9c0>
    80006fec:	00090513          	mv	a0,s2
    80006ff0:	de4fe0ef          	jal	800055d4 <dirlink>
    80006ff4:	02054863          	bltz	a0,80007024 <create+0x194>
  if(dirlink(dp, name, ip->inum) < 0)
    80006ff8:	00492603          	lw	a2,4(s2)
    80006ffc:	fb040593          	addi	a1,s0,-80
    80007000:	00048513          	mv	a0,s1
    80007004:	dd0fe0ef          	jal	800055d4 <dirlink>
    80007008:	00054e63          	bltz	a0,80007024 <create+0x194>
    dp->nlink++;  // for ".."
    8000700c:	04a4d783          	lhu	a5,74(s1)
    80007010:	0017879b          	addiw	a5,a5,1
    80007014:	04f49523          	sh	a5,74(s1)
    iupdate(dp);
    80007018:	00048513          	mv	a0,s1
    8000701c:	951fd0ef          	jal	8000496c <iupdate>
    80007020:	f8dff06f          	j	80006fac <create+0x11c>
  ip->nlink = 0;
    80007024:	04091523          	sh	zero,74(s2)
  iupdate(ip);
    80007028:	00090513          	mv	a0,s2
    8000702c:	941fd0ef          	jal	8000496c <iupdate>
  iunlockput(ip);
    80007030:	00090513          	mv	a0,s2
    80007034:	d29fd0ef          	jal	80004d5c <iunlockput>
  iunlockput(dp);
    80007038:	00048513          	mv	a0,s1
    8000703c:	d21fd0ef          	jal	80004d5c <iunlockput>
  return 0;
    80007040:	ee5ff06f          	j	80006f24 <create+0x94>
    return 0;
    80007044:	00050993          	mv	s3,a0
    80007048:	eddff06f          	j	80006f24 <create+0x94>

000000008000704c <sys_dup>:
{
    8000704c:	fd010113          	addi	sp,sp,-48
    80007050:	02113423          	sd	ra,40(sp)
    80007054:	02813023          	sd	s0,32(sp)
    80007058:	03010413          	addi	s0,sp,48
  if(argfd(0, 0, &f) < 0)
    8000705c:	fd840613          	addi	a2,s0,-40
    80007060:	00000593          	li	a1,0
    80007064:	00000513          	li	a0,0
    80007068:	d31ff0ef          	jal	80006d98 <argfd>
    return -1;
    8000706c:	fff00793          	li	a5,-1
  if(argfd(0, 0, &f) < 0)
    80007070:	02054e63          	bltz	a0,800070ac <sys_dup+0x60>
    80007074:	00913c23          	sd	s1,24(sp)
    80007078:	01213823          	sd	s2,16(sp)
  if((fd=fdalloc(f)) < 0)
    8000707c:	fd843783          	ld	a5,-40(s0)
    80007080:	00078493          	mv	s1,a5
    80007084:	00078513          	mv	a0,a5
    80007088:	d9dff0ef          	jal	80006e24 <fdalloc>
    8000708c:	00050913          	mv	s2,a0
    return -1;
    80007090:	fff00793          	li	a5,-1
  if((fd=fdalloc(f)) < 0)
    80007094:	02054663          	bltz	a0,800070c0 <sys_dup+0x74>
  filedup(f);
    80007098:	00048513          	mv	a0,s1
    8000709c:	e75fe0ef          	jal	80005f10 <filedup>
  return fd;
    800070a0:	00090793          	mv	a5,s2
    800070a4:	01813483          	ld	s1,24(sp)
    800070a8:	01013903          	ld	s2,16(sp)
}
    800070ac:	00078513          	mv	a0,a5
    800070b0:	02813083          	ld	ra,40(sp)
    800070b4:	02013403          	ld	s0,32(sp)
    800070b8:	03010113          	addi	sp,sp,48
    800070bc:	00008067          	ret
    800070c0:	01813483          	ld	s1,24(sp)
    800070c4:	01013903          	ld	s2,16(sp)
    800070c8:	fe5ff06f          	j	800070ac <sys_dup+0x60>

00000000800070cc <sys_read>:
{
    800070cc:	fd010113          	addi	sp,sp,-48
    800070d0:	02113423          	sd	ra,40(sp)
    800070d4:	02813023          	sd	s0,32(sp)
    800070d8:	03010413          	addi	s0,sp,48
  argaddr(1, &p);
    800070dc:	fd840593          	addi	a1,s0,-40
    800070e0:	00100513          	li	a0,1
    800070e4:	b91fc0ef          	jal	80003c74 <argaddr>
  argint(2, &n);
    800070e8:	fe440593          	addi	a1,s0,-28
    800070ec:	00200513          	li	a0,2
    800070f0:	b51fc0ef          	jal	80003c40 <argint>
  if(argfd(0, 0, &f) < 0)
    800070f4:	fe840613          	addi	a2,s0,-24
    800070f8:	00000593          	li	a1,0
    800070fc:	00000513          	li	a0,0
    80007100:	c99ff0ef          	jal	80006d98 <argfd>
    80007104:	00050793          	mv	a5,a0
    return -1;
    80007108:	fff00513          	li	a0,-1
  if(argfd(0, 0, &f) < 0)
    8000710c:	0007ca63          	bltz	a5,80007120 <sys_read+0x54>
  return fileread(f, p, n);
    80007110:	fe442603          	lw	a2,-28(s0)
    80007114:	fd843583          	ld	a1,-40(s0)
    80007118:	fe843503          	ld	a0,-24(s0)
    8000711c:	81cff0ef          	jal	80006138 <fileread>
}
    80007120:	02813083          	ld	ra,40(sp)
    80007124:	02013403          	ld	s0,32(sp)
    80007128:	03010113          	addi	sp,sp,48
    8000712c:	00008067          	ret

0000000080007130 <sys_write>:
{
    80007130:	fd010113          	addi	sp,sp,-48
    80007134:	02113423          	sd	ra,40(sp)
    80007138:	02813023          	sd	s0,32(sp)
    8000713c:	03010413          	addi	s0,sp,48
  argaddr(1, &p);
    80007140:	fd840593          	addi	a1,s0,-40
    80007144:	00100513          	li	a0,1
    80007148:	b2dfc0ef          	jal	80003c74 <argaddr>
  argint(2, &n);
    8000714c:	fe440593          	addi	a1,s0,-28
    80007150:	00200513          	li	a0,2
    80007154:	aedfc0ef          	jal	80003c40 <argint>
  if(argfd(0, 0, &f) < 0)
    80007158:	fe840613          	addi	a2,s0,-24
    8000715c:	00000593          	li	a1,0
    80007160:	00000513          	li	a0,0
    80007164:	c35ff0ef          	jal	80006d98 <argfd>
    80007168:	00050793          	mv	a5,a0
    return -1;
    8000716c:	fff00513          	li	a0,-1
  if(argfd(0, 0, &f) < 0)
    80007170:	0007ca63          	bltz	a5,80007184 <sys_write+0x54>
  return filewrite(f, p, n);
    80007174:	fe442603          	lw	a2,-28(s0)
    80007178:	fd843583          	ld	a1,-40(s0)
    8000717c:	fe843503          	ld	a0,-24(s0)
    80007180:	8fcff0ef          	jal	8000627c <filewrite>
}
    80007184:	02813083          	ld	ra,40(sp)
    80007188:	02013403          	ld	s0,32(sp)
    8000718c:	03010113          	addi	sp,sp,48
    80007190:	00008067          	ret

0000000080007194 <sys_close>:
{
    80007194:	fe010113          	addi	sp,sp,-32
    80007198:	00113c23          	sd	ra,24(sp)
    8000719c:	00813823          	sd	s0,16(sp)
    800071a0:	02010413          	addi	s0,sp,32
  if(argfd(0, &fd, &f) < 0)
    800071a4:	fe040613          	addi	a2,s0,-32
    800071a8:	fec40593          	addi	a1,s0,-20
    800071ac:	00000513          	li	a0,0
    800071b0:	be9ff0ef          	jal	80006d98 <argfd>
    return -1;
    800071b4:	fff00793          	li	a5,-1
  if(argfd(0, &fd, &f) < 0)
    800071b8:	02054463          	bltz	a0,800071e0 <sys_close+0x4c>
  myproc()->ofile[fd] = 0;
    800071bc:	c38fb0ef          	jal	800025f4 <myproc>
    800071c0:	fec42783          	lw	a5,-20(s0)
    800071c4:	00379793          	slli	a5,a5,0x3
    800071c8:	0d078793          	addi	a5,a5,208
    800071cc:	00f50533          	add	a0,a0,a5
    800071d0:	00053023          	sd	zero,0(a0)
  fileclose(f);
    800071d4:	fe043503          	ld	a0,-32(s0)
    800071d8:	d9dfe0ef          	jal	80005f74 <fileclose>
  return 0;
    800071dc:	00000793          	li	a5,0
}
    800071e0:	00078513          	mv	a0,a5
    800071e4:	01813083          	ld	ra,24(sp)
    800071e8:	01013403          	ld	s0,16(sp)
    800071ec:	02010113          	addi	sp,sp,32
    800071f0:	00008067          	ret

00000000800071f4 <sys_fstat>:
{
    800071f4:	fe010113          	addi	sp,sp,-32
    800071f8:	00113c23          	sd	ra,24(sp)
    800071fc:	00813823          	sd	s0,16(sp)
    80007200:	02010413          	addi	s0,sp,32
  argaddr(1, &st);
    80007204:	fe040593          	addi	a1,s0,-32
    80007208:	00100513          	li	a0,1
    8000720c:	a69fc0ef          	jal	80003c74 <argaddr>
  if(argfd(0, 0, &f) < 0)
    80007210:	fe840613          	addi	a2,s0,-24
    80007214:	00000593          	li	a1,0
    80007218:	00000513          	li	a0,0
    8000721c:	b7dff0ef          	jal	80006d98 <argfd>
    80007220:	00050793          	mv	a5,a0
    return -1;
    80007224:	fff00513          	li	a0,-1
  if(argfd(0, 0, &f) < 0)
    80007228:	0007c863          	bltz	a5,80007238 <sys_fstat+0x44>
  return filestat(f, st);
    8000722c:	fe043583          	ld	a1,-32(s0)
    80007230:	fe843503          	ld	a0,-24(s0)
    80007234:	e65fe0ef          	jal	80006098 <filestat>
}
    80007238:	01813083          	ld	ra,24(sp)
    8000723c:	01013403          	ld	s0,16(sp)
    80007240:	02010113          	addi	sp,sp,32
    80007244:	00008067          	ret

0000000080007248 <sys_link>:
{
    80007248:	ed010113          	addi	sp,sp,-304
    8000724c:	12113423          	sd	ra,296(sp)
    80007250:	12813023          	sd	s0,288(sp)
    80007254:	13010413          	addi	s0,sp,304
  if(argstr(0, old, MAXPATH) < 0 || argstr(1, new, MAXPATH) < 0)
    80007258:	08000613          	li	a2,128
    8000725c:	ed040593          	addi	a1,s0,-304
    80007260:	00000513          	li	a0,0
    80007264:	a45fc0ef          	jal	80003ca8 <argstr>
    return -1;
    80007268:	fff00793          	li	a5,-1
  if(argstr(0, old, MAXPATH) < 0 || argstr(1, new, MAXPATH) < 0)
    8000726c:	12054263          	bltz	a0,80007390 <sys_link+0x148>
    80007270:	08000613          	li	a2,128
    80007274:	f5040593          	addi	a1,s0,-176
    80007278:	00100513          	li	a0,1
    8000727c:	a2dfc0ef          	jal	80003ca8 <argstr>
    return -1;
    80007280:	fff00793          	li	a5,-1
  if(argstr(0, old, MAXPATH) < 0 || argstr(1, new, MAXPATH) < 0)
    80007284:	10054663          	bltz	a0,80007390 <sys_link+0x148>
    80007288:	10913c23          	sd	s1,280(sp)
  begin_op();
    8000728c:	f0cfe0ef          	jal	80005998 <begin_op>
  if((ip = namei(old)) == 0){
    80007290:	ed040513          	addi	a0,s0,-304
    80007294:	c48fe0ef          	jal	800056dc <namei>
    80007298:	00050493          	mv	s1,a0
    8000729c:	08050863          	beqz	a0,8000732c <sys_link+0xe4>
  ilock(ip);
    800072a0:	fd0fd0ef          	jal	80004a70 <ilock>
  if(ip->type == T_DIR){
    800072a4:	04449703          	lh	a4,68(s1)
    800072a8:	00100793          	li	a5,1
    800072ac:	08f70863          	beq	a4,a5,8000733c <sys_link+0xf4>
    800072b0:	11213823          	sd	s2,272(sp)
  ip->nlink++;
    800072b4:	04a4d783          	lhu	a5,74(s1)
    800072b8:	0017879b          	addiw	a5,a5,1
    800072bc:	04f49523          	sh	a5,74(s1)
  iupdate(ip);
    800072c0:	00048513          	mv	a0,s1
    800072c4:	ea8fd0ef          	jal	8000496c <iupdate>
  iunlock(ip);
    800072c8:	00048513          	mv	a0,s1
    800072cc:	899fd0ef          	jal	80004b64 <iunlock>
  if((dp = nameiparent(new, name)) == 0)
    800072d0:	fd040593          	addi	a1,s0,-48
    800072d4:	f5040513          	addi	a0,s0,-176
    800072d8:	c30fe0ef          	jal	80005708 <nameiparent>
    800072dc:	00050913          	mv	s2,a0
    800072e0:	06050e63          	beqz	a0,8000735c <sys_link+0x114>
  ilock(dp);
    800072e4:	f8cfd0ef          	jal	80004a70 <ilock>
  if(dp->dev != ip->dev || dirlink(dp, name, ip->inum) < 0){
    800072e8:	00092703          	lw	a4,0(s2)
    800072ec:	0004a783          	lw	a5,0(s1)
    800072f0:	06f71263          	bne	a4,a5,80007354 <sys_link+0x10c>
    800072f4:	0044a603          	lw	a2,4(s1)
    800072f8:	fd040593          	addi	a1,s0,-48
    800072fc:	00090513          	mv	a0,s2
    80007300:	ad4fe0ef          	jal	800055d4 <dirlink>
    80007304:	04054863          	bltz	a0,80007354 <sys_link+0x10c>
  iunlockput(dp);
    80007308:	00090513          	mv	a0,s2
    8000730c:	a51fd0ef          	jal	80004d5c <iunlockput>
  iput(ip);
    80007310:	00048513          	mv	a0,s1
    80007314:	989fd0ef          	jal	80004c9c <iput>
  end_op();
    80007318:	f24fe0ef          	jal	80005a3c <end_op>
  return 0;
    8000731c:	00000793          	li	a5,0
    80007320:	11813483          	ld	s1,280(sp)
    80007324:	11013903          	ld	s2,272(sp)
    80007328:	0680006f          	j	80007390 <sys_link+0x148>
    end_op();
    8000732c:	f10fe0ef          	jal	80005a3c <end_op>
    return -1;
    80007330:	fff00793          	li	a5,-1
    80007334:	11813483          	ld	s1,280(sp)
    80007338:	0580006f          	j	80007390 <sys_link+0x148>
    iunlockput(ip);
    8000733c:	00048513          	mv	a0,s1
    80007340:	a1dfd0ef          	jal	80004d5c <iunlockput>
    end_op();
    80007344:	ef8fe0ef          	jal	80005a3c <end_op>
    return -1;
    80007348:	fff00793          	li	a5,-1
    8000734c:	11813483          	ld	s1,280(sp)
    80007350:	0400006f          	j	80007390 <sys_link+0x148>
    iunlockput(dp);
    80007354:	00090513          	mv	a0,s2
    80007358:	a05fd0ef          	jal	80004d5c <iunlockput>
  ilock(ip);
    8000735c:	00048513          	mv	a0,s1
    80007360:	f10fd0ef          	jal	80004a70 <ilock>
  ip->nlink--;
    80007364:	04a4d783          	lhu	a5,74(s1)
    80007368:	fff7879b          	addiw	a5,a5,-1
    8000736c:	04f49523          	sh	a5,74(s1)
  iupdate(ip);
    80007370:	00048513          	mv	a0,s1
    80007374:	df8fd0ef          	jal	8000496c <iupdate>
  iunlockput(ip);
    80007378:	00048513          	mv	a0,s1
    8000737c:	9e1fd0ef          	jal	80004d5c <iunlockput>
  end_op();
    80007380:	ebcfe0ef          	jal	80005a3c <end_op>
  return -1;
    80007384:	fff00793          	li	a5,-1
    80007388:	11813483          	ld	s1,280(sp)
    8000738c:	11013903          	ld	s2,272(sp)
}
    80007390:	00078513          	mv	a0,a5
    80007394:	12813083          	ld	ra,296(sp)
    80007398:	12013403          	ld	s0,288(sp)
    8000739c:	13010113          	addi	sp,sp,304
    800073a0:	00008067          	ret

00000000800073a4 <sys_unlink>:
{
    800073a4:	f1010113          	addi	sp,sp,-240
    800073a8:	0e113423          	sd	ra,232(sp)
    800073ac:	0e813023          	sd	s0,224(sp)
    800073b0:	0f010413          	addi	s0,sp,240
  if(argstr(0, path, MAXPATH) < 0)
    800073b4:	08000613          	li	a2,128
    800073b8:	f3040593          	addi	a1,s0,-208
    800073bc:	00000513          	li	a0,0
    800073c0:	8e9fc0ef          	jal	80003ca8 <argstr>
    800073c4:	1a054e63          	bltz	a0,80007580 <sys_unlink+0x1dc>
    800073c8:	0c913c23          	sd	s1,216(sp)
  begin_op();
    800073cc:	dccfe0ef          	jal	80005998 <begin_op>
  if((dp = nameiparent(path, name)) == 0){
    800073d0:	fb040593          	addi	a1,s0,-80
    800073d4:	f3040513          	addi	a0,s0,-208
    800073d8:	b30fe0ef          	jal	80005708 <nameiparent>
    800073dc:	00050493          	mv	s1,a0
    800073e0:	0e050263          	beqz	a0,800074c4 <sys_unlink+0x120>
  ilock(dp);
    800073e4:	e8cfd0ef          	jal	80004a70 <ilock>
  if(namecmp(name, ".") == 0 || namecmp(name, "..") == 0)
    800073e8:	00002597          	auipc	a1,0x2
    800073ec:	5d058593          	addi	a1,a1,1488 # 800099b8 <etext+0x9b8>
    800073f0:	fb040513          	addi	a0,s0,-80
    800073f4:	ed1fd0ef          	jal	800052c4 <namecmp>
    800073f8:	16050263          	beqz	a0,8000755c <sys_unlink+0x1b8>
    800073fc:	00002597          	auipc	a1,0x2
    80007400:	5c458593          	addi	a1,a1,1476 # 800099c0 <etext+0x9c0>
    80007404:	fb040513          	addi	a0,s0,-80
    80007408:	ebdfd0ef          	jal	800052c4 <namecmp>
    8000740c:	14050863          	beqz	a0,8000755c <sys_unlink+0x1b8>
    80007410:	0d213823          	sd	s2,208(sp)
  if((ip = dirlookup(dp, name, &off)) == 0)
    80007414:	f2c40613          	addi	a2,s0,-212
    80007418:	fb040593          	addi	a1,s0,-80
    8000741c:	00048513          	mv	a0,s1
    80007420:	ecdfd0ef          	jal	800052ec <dirlookup>
    80007424:	00050913          	mv	s2,a0
    80007428:	12050863          	beqz	a0,80007558 <sys_unlink+0x1b4>
    8000742c:	0d313423          	sd	s3,200(sp)
  ilock(ip);
    80007430:	e40fd0ef          	jal	80004a70 <ilock>
  if(ip->nlink < 1)
    80007434:	04a91783          	lh	a5,74(s2)
    80007438:	08f05e63          	blez	a5,800074d4 <sys_unlink+0x130>
  if(ip->type == T_DIR && !isdirempty(ip)){
    8000743c:	04491703          	lh	a4,68(s2)
    80007440:	00100793          	li	a5,1
    80007444:	08f70e63          	beq	a4,a5,800074e0 <sys_unlink+0x13c>
  memset(&de, 0, sizeof(de));
    80007448:	fc040993          	addi	s3,s0,-64
    8000744c:	01000613          	li	a2,16
    80007450:	00000593          	li	a1,0
    80007454:	00098513          	mv	a0,s3
    80007458:	d85f90ef          	jal	800011dc <memset>
  if(writei(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    8000745c:	01000713          	li	a4,16
    80007460:	f2c42683          	lw	a3,-212(s0)
    80007464:	00098613          	mv	a2,s3
    80007468:	00000593          	li	a1,0
    8000746c:	00048513          	mv	a0,s1
    80007470:	ccdfd0ef          	jal	8000513c <writei>
    80007474:	01000793          	li	a5,16
    80007478:	0af51e63          	bne	a0,a5,80007534 <sys_unlink+0x190>
  if(ip->type == T_DIR){
    8000747c:	04491703          	lh	a4,68(s2)
    80007480:	00100793          	li	a5,1
    80007484:	0af70e63          	beq	a4,a5,80007540 <sys_unlink+0x19c>
  iunlockput(dp);
    80007488:	00048513          	mv	a0,s1
    8000748c:	8d1fd0ef          	jal	80004d5c <iunlockput>
  ip->nlink--;
    80007490:	04a95783          	lhu	a5,74(s2)
    80007494:	fff7879b          	addiw	a5,a5,-1
    80007498:	04f91523          	sh	a5,74(s2)
  iupdate(ip);
    8000749c:	00090513          	mv	a0,s2
    800074a0:	cccfd0ef          	jal	8000496c <iupdate>
  iunlockput(ip);
    800074a4:	00090513          	mv	a0,s2
    800074a8:	8b5fd0ef          	jal	80004d5c <iunlockput>
  end_op();
    800074ac:	d90fe0ef          	jal	80005a3c <end_op>
  return 0;
    800074b0:	00000513          	li	a0,0
    800074b4:	0d813483          	ld	s1,216(sp)
    800074b8:	0d013903          	ld	s2,208(sp)
    800074bc:	0c813983          	ld	s3,200(sp)
    800074c0:	0b00006f          	j	80007570 <sys_unlink+0x1cc>
    end_op();
    800074c4:	d78fe0ef          	jal	80005a3c <end_op>
    return -1;
    800074c8:	fff00513          	li	a0,-1
    800074cc:	0d813483          	ld	s1,216(sp)
    800074d0:	0a00006f          	j	80007570 <sys_unlink+0x1cc>
    panic("unlink: nlink < 1");
    800074d4:	00002517          	auipc	a0,0x2
    800074d8:	4f450513          	addi	a0,a0,1268 # 800099c8 <etext+0x9c8>
    800074dc:	e10f90ef          	jal	80000aec <panic>
  for(off=2*sizeof(de); off<dp->size; off+=sizeof(de)){
    800074e0:	04c92703          	lw	a4,76(s2)
    800074e4:	02000793          	li	a5,32
    800074e8:	f6e7f0e3          	bgeu	a5,a4,80007448 <sys_unlink+0xa4>
    800074ec:	00078993          	mv	s3,a5
    if(readi(dp, 0, (uint64)&de, off, sizeof(de)) != sizeof(de))
    800074f0:	01000713          	li	a4,16
    800074f4:	00098693          	mv	a3,s3
    800074f8:	f1840613          	addi	a2,s0,-232
    800074fc:	00000593          	li	a1,0
    80007500:	00090513          	mv	a0,s2
    80007504:	ab5fd0ef          	jal	80004fb8 <readi>
    80007508:	01000793          	li	a5,16
    8000750c:	00f51e63          	bne	a0,a5,80007528 <sys_unlink+0x184>
    if(de.inum != 0)
    80007510:	f1845783          	lhu	a5,-232(s0)
    80007514:	06079a63          	bnez	a5,80007588 <sys_unlink+0x1e4>
  for(off=2*sizeof(de); off<dp->size; off+=sizeof(de)){
    80007518:	0109899b          	addiw	s3,s3,16
    8000751c:	04c92783          	lw	a5,76(s2)
    80007520:	fcf9e8e3          	bltu	s3,a5,800074f0 <sys_unlink+0x14c>
    80007524:	f25ff06f          	j	80007448 <sys_unlink+0xa4>
      panic("isdirempty: readi");
    80007528:	00002517          	auipc	a0,0x2
    8000752c:	4b850513          	addi	a0,a0,1208 # 800099e0 <etext+0x9e0>
    80007530:	dbcf90ef          	jal	80000aec <panic>
    panic("unlink: writei");
    80007534:	00002517          	auipc	a0,0x2
    80007538:	4c450513          	addi	a0,a0,1220 # 800099f8 <etext+0x9f8>
    8000753c:	db0f90ef          	jal	80000aec <panic>
    dp->nlink--;
    80007540:	04a4d783          	lhu	a5,74(s1)
    80007544:	fff7879b          	addiw	a5,a5,-1
    80007548:	04f49523          	sh	a5,74(s1)
    iupdate(dp);
    8000754c:	00048513          	mv	a0,s1
    80007550:	c1cfd0ef          	jal	8000496c <iupdate>
    80007554:	f35ff06f          	j	80007488 <sys_unlink+0xe4>
    80007558:	0d013903          	ld	s2,208(sp)
  iunlockput(dp);
    8000755c:	00048513          	mv	a0,s1
    80007560:	ffcfd0ef          	jal	80004d5c <iunlockput>
  end_op();
    80007564:	cd8fe0ef          	jal	80005a3c <end_op>
  return -1;
    80007568:	fff00513          	li	a0,-1
    8000756c:	0d813483          	ld	s1,216(sp)
}
    80007570:	0e813083          	ld	ra,232(sp)
    80007574:	0e013403          	ld	s0,224(sp)
    80007578:	0f010113          	addi	sp,sp,240
    8000757c:	00008067          	ret
    return -1;
    80007580:	fff00513          	li	a0,-1
    80007584:	fedff06f          	j	80007570 <sys_unlink+0x1cc>
    iunlockput(ip);
    80007588:	00090513          	mv	a0,s2
    8000758c:	fd0fd0ef          	jal	80004d5c <iunlockput>
    goto bad;
    80007590:	0d013903          	ld	s2,208(sp)
    80007594:	0c813983          	ld	s3,200(sp)
    80007598:	fc5ff06f          	j	8000755c <sys_unlink+0x1b8>

000000008000759c <sys_open>:

uint64
sys_open(void)
{
    8000759c:	f4010113          	addi	sp,sp,-192
    800075a0:	0a113c23          	sd	ra,184(sp)
    800075a4:	0a813823          	sd	s0,176(sp)
    800075a8:	0c010413          	addi	s0,sp,192
  int fd, omode;
  struct file *f;
  struct inode *ip;
  int n;

  argint(1, &omode);
    800075ac:	f4c40593          	addi	a1,s0,-180
    800075b0:	00100513          	li	a0,1
    800075b4:	e8cfc0ef          	jal	80003c40 <argint>
  if((n = argstr(0, path, MAXPATH)) < 0)
    800075b8:	08000613          	li	a2,128
    800075bc:	f5040593          	addi	a1,s0,-176
    800075c0:	00000513          	li	a0,0
    800075c4:	ee4fc0ef          	jal	80003ca8 <argstr>
    800075c8:	00050793          	mv	a5,a0
    return -1;
    800075cc:	fff00513          	li	a0,-1
  if((n = argstr(0, path, MAXPATH)) < 0)
    800075d0:	0c07ca63          	bltz	a5,800076a4 <sys_open+0x108>
    800075d4:	0a913423          	sd	s1,168(sp)

  begin_op();
    800075d8:	bc0fe0ef          	jal	80005998 <begin_op>

  if(omode & O_CREATE){
    800075dc:	f4c42783          	lw	a5,-180(s0)
    800075e0:	2007f793          	andi	a5,a5,512
    800075e4:	0e078063          	beqz	a5,800076c4 <sys_open+0x128>
    ip = create(path, T_FILE, 0, 0);
    800075e8:	00000693          	li	a3,0
    800075ec:	00000613          	li	a2,0
    800075f0:	00200593          	li	a1,2
    800075f4:	f5040513          	addi	a0,s0,-176
    800075f8:	899ff0ef          	jal	80006e90 <create>
    800075fc:	00050493          	mv	s1,a0
    if(ip == 0){
    80007600:	0a050a63          	beqz	a0,800076b4 <sys_open+0x118>
      end_op();
      return -1;
    }
  }

  if(ip->type == T_DEVICE && (ip->major < 0 || ip->major >= NDEV)){
    80007604:	04449703          	lh	a4,68(s1)
    80007608:	00300793          	li	a5,3
    8000760c:	00f71863          	bne	a4,a5,8000761c <sys_open+0x80>
    80007610:	0464d703          	lhu	a4,70(s1)
    80007614:	00900793          	li	a5,9
    80007618:	0ee7ee63          	bltu	a5,a4,80007714 <sys_open+0x178>
    8000761c:	0b213023          	sd	s2,160(sp)
    iunlockput(ip);
    end_op();
    return -1;
  }

  if((f = filealloc()) == 0 || (fd = fdalloc(f)) < 0){
    80007620:	871fe0ef          	jal	80005e90 <filealloc>
    80007624:	00050913          	mv	s2,a0
    80007628:	10050863          	beqz	a0,80007738 <sys_open+0x19c>
    8000762c:	09313c23          	sd	s3,152(sp)
    80007630:	ff4ff0ef          	jal	80006e24 <fdalloc>
    80007634:	00050993          	mv	s3,a0
    80007638:	0e054a63          	bltz	a0,8000772c <sys_open+0x190>
    iunlockput(ip);
    end_op();
    return -1;
  }

  if(ip->type == T_DEVICE){
    8000763c:	04449703          	lh	a4,68(s1)
    80007640:	00300793          	li	a5,3
    80007644:	10f70863          	beq	a4,a5,80007754 <sys_open+0x1b8>
    f->type = FD_DEVICE;
    f->major = ip->major;
  } else {
    f->type = FD_INODE;
    80007648:	00200793          	li	a5,2
    8000764c:	00f92023          	sw	a5,0(s2)
    f->off = 0;
    80007650:	02092023          	sw	zero,32(s2)
  }
  f->ip = ip;
    80007654:	00993c23          	sd	s1,24(s2)
  f->readable = !(omode & O_WRONLY);
    80007658:	f4c42783          	lw	a5,-180(s0)
    8000765c:	0017f713          	andi	a4,a5,1
    80007660:	00174713          	xori	a4,a4,1
    80007664:	00e90423          	sb	a4,8(s2)
  f->writable = (omode & O_WRONLY) || (omode & O_RDWR);
    80007668:	0037f713          	andi	a4,a5,3
    8000766c:	00e03733          	snez	a4,a4
    80007670:	00e904a3          	sb	a4,9(s2)

  if((omode & O_TRUNC) && ip->type == T_FILE){
    80007674:	4007f793          	andi	a5,a5,1024
    80007678:	00078863          	beqz	a5,80007688 <sys_open+0xec>
    8000767c:	04449703          	lh	a4,68(s1)
    80007680:	00200793          	li	a5,2
    80007684:	0ef70063          	beq	a4,a5,80007764 <sys_open+0x1c8>
    itrunc(ip);
  }

  iunlock(ip);
    80007688:	00048513          	mv	a0,s1
    8000768c:	cd8fd0ef          	jal	80004b64 <iunlock>
  end_op();
    80007690:	bacfe0ef          	jal	80005a3c <end_op>

  return fd;
    80007694:	00098513          	mv	a0,s3
    80007698:	0a813483          	ld	s1,168(sp)
    8000769c:	0a013903          	ld	s2,160(sp)
    800076a0:	09813983          	ld	s3,152(sp)
}
    800076a4:	0b813083          	ld	ra,184(sp)
    800076a8:	0b013403          	ld	s0,176(sp)
    800076ac:	0c010113          	addi	sp,sp,192
    800076b0:	00008067          	ret
      end_op();
    800076b4:	b88fe0ef          	jal	80005a3c <end_op>
      return -1;
    800076b8:	fff00513          	li	a0,-1
    800076bc:	0a813483          	ld	s1,168(sp)
    800076c0:	fe5ff06f          	j	800076a4 <sys_open+0x108>
    if((ip = namei(path)) == 0){
    800076c4:	f5040513          	addi	a0,s0,-176
    800076c8:	814fe0ef          	jal	800056dc <namei>
    800076cc:	00050493          	mv	s1,a0
    800076d0:	02050a63          	beqz	a0,80007704 <sys_open+0x168>
    ilock(ip);
    800076d4:	b9cfd0ef          	jal	80004a70 <ilock>
    if(ip->type == T_DIR && omode != O_RDONLY){
    800076d8:	04449703          	lh	a4,68(s1)
    800076dc:	00100793          	li	a5,1
    800076e0:	f2f712e3          	bne	a4,a5,80007604 <sys_open+0x68>
    800076e4:	f4c42783          	lw	a5,-180(s0)
    800076e8:	f2078ae3          	beqz	a5,8000761c <sys_open+0x80>
      iunlockput(ip);
    800076ec:	00048513          	mv	a0,s1
    800076f0:	e6cfd0ef          	jal	80004d5c <iunlockput>
      end_op();
    800076f4:	b48fe0ef          	jal	80005a3c <end_op>
      return -1;
    800076f8:	fff00513          	li	a0,-1
    800076fc:	0a813483          	ld	s1,168(sp)
    80007700:	fa5ff06f          	j	800076a4 <sys_open+0x108>
      end_op();
    80007704:	b38fe0ef          	jal	80005a3c <end_op>
      return -1;
    80007708:	fff00513          	li	a0,-1
    8000770c:	0a813483          	ld	s1,168(sp)
    80007710:	f95ff06f          	j	800076a4 <sys_open+0x108>
    iunlockput(ip);
    80007714:	00048513          	mv	a0,s1
    80007718:	e44fd0ef          	jal	80004d5c <iunlockput>
    end_op();
    8000771c:	b20fe0ef          	jal	80005a3c <end_op>
    return -1;
    80007720:	fff00513          	li	a0,-1
    80007724:	0a813483          	ld	s1,168(sp)
    80007728:	f7dff06f          	j	800076a4 <sys_open+0x108>
      fileclose(f);
    8000772c:	00090513          	mv	a0,s2
    80007730:	845fe0ef          	jal	80005f74 <fileclose>
    80007734:	09813983          	ld	s3,152(sp)
    iunlockput(ip);
    80007738:	00048513          	mv	a0,s1
    8000773c:	e20fd0ef          	jal	80004d5c <iunlockput>
    end_op();
    80007740:	afcfe0ef          	jal	80005a3c <end_op>
    return -1;
    80007744:	fff00513          	li	a0,-1
    80007748:	0a813483          	ld	s1,168(sp)
    8000774c:	0a013903          	ld	s2,160(sp)
    80007750:	f55ff06f          	j	800076a4 <sys_open+0x108>
    f->type = FD_DEVICE;
    80007754:	00e92023          	sw	a4,0(s2)
    f->major = ip->major;
    80007758:	04649783          	lh	a5,70(s1)
    8000775c:	02f91223          	sh	a5,36(s2)
    80007760:	ef5ff06f          	j	80007654 <sys_open+0xb8>
    itrunc(ip);
    80007764:	00048513          	mv	a0,s1
    80007768:	c60fd0ef          	jal	80004bc8 <itrunc>
    8000776c:	f1dff06f          	j	80007688 <sys_open+0xec>

0000000080007770 <sys_mkdir>:

uint64
sys_mkdir(void)
{
    80007770:	f7010113          	addi	sp,sp,-144
    80007774:	08113423          	sd	ra,136(sp)
    80007778:	08813023          	sd	s0,128(sp)
    8000777c:	09010413          	addi	s0,sp,144
  char path[MAXPATH];
  struct inode *ip;

  begin_op();
    80007780:	a18fe0ef          	jal	80005998 <begin_op>
  if(argstr(0, path, MAXPATH) < 0 || (ip = create(path, T_DIR, 0, 0)) == 0){
    80007784:	08000613          	li	a2,128
    80007788:	f7040593          	addi	a1,s0,-144
    8000778c:	00000513          	li	a0,0
    80007790:	d18fc0ef          	jal	80003ca8 <argstr>
    80007794:	02054c63          	bltz	a0,800077cc <sys_mkdir+0x5c>
    80007798:	00000693          	li	a3,0
    8000779c:	00000613          	li	a2,0
    800077a0:	00100593          	li	a1,1
    800077a4:	f7040513          	addi	a0,s0,-144
    800077a8:	ee8ff0ef          	jal	80006e90 <create>
    800077ac:	02050063          	beqz	a0,800077cc <sys_mkdir+0x5c>
    end_op();
    return -1;
  }
  iunlockput(ip);
    800077b0:	dacfd0ef          	jal	80004d5c <iunlockput>
  end_op();
    800077b4:	a88fe0ef          	jal	80005a3c <end_op>
  return 0;
    800077b8:	00000513          	li	a0,0
}
    800077bc:	08813083          	ld	ra,136(sp)
    800077c0:	08013403          	ld	s0,128(sp)
    800077c4:	09010113          	addi	sp,sp,144
    800077c8:	00008067          	ret
    end_op();
    800077cc:	a70fe0ef          	jal	80005a3c <end_op>
    return -1;
    800077d0:	fff00513          	li	a0,-1
    800077d4:	fe9ff06f          	j	800077bc <sys_mkdir+0x4c>

00000000800077d8 <sys_mknod>:

uint64
sys_mknod(void)
{
    800077d8:	f6010113          	addi	sp,sp,-160
    800077dc:	08113c23          	sd	ra,152(sp)
    800077e0:	08813823          	sd	s0,144(sp)
    800077e4:	0a010413          	addi	s0,sp,160
  struct inode *ip;
  char path[MAXPATH];
  int major, minor;

  begin_op();
    800077e8:	9b0fe0ef          	jal	80005998 <begin_op>
  argint(1, &major);
    800077ec:	f6c40593          	addi	a1,s0,-148
    800077f0:	00100513          	li	a0,1
    800077f4:	c4cfc0ef          	jal	80003c40 <argint>
  argint(2, &minor);
    800077f8:	f6840593          	addi	a1,s0,-152
    800077fc:	00200513          	li	a0,2
    80007800:	c40fc0ef          	jal	80003c40 <argint>
  if((argstr(0, path, MAXPATH)) < 0 ||
    80007804:	08000613          	li	a2,128
    80007808:	f7040593          	addi	a1,s0,-144
    8000780c:	00000513          	li	a0,0
    80007810:	c98fc0ef          	jal	80003ca8 <argstr>
    80007814:	02054c63          	bltz	a0,8000784c <sys_mknod+0x74>
     (ip = create(path, T_DEVICE, major, minor)) == 0){
    80007818:	f6841683          	lh	a3,-152(s0)
    8000781c:	f6c41603          	lh	a2,-148(s0)
    80007820:	00300593          	li	a1,3
    80007824:	f7040513          	addi	a0,s0,-144
    80007828:	e68ff0ef          	jal	80006e90 <create>
  if((argstr(0, path, MAXPATH)) < 0 ||
    8000782c:	02050063          	beqz	a0,8000784c <sys_mknod+0x74>
    end_op();
    return -1;
  }
  iunlockput(ip);
    80007830:	d2cfd0ef          	jal	80004d5c <iunlockput>
  end_op();
    80007834:	a08fe0ef          	jal	80005a3c <end_op>
  return 0;
    80007838:	00000513          	li	a0,0
}
    8000783c:	09813083          	ld	ra,152(sp)
    80007840:	09013403          	ld	s0,144(sp)
    80007844:	0a010113          	addi	sp,sp,160
    80007848:	00008067          	ret
    end_op();
    8000784c:	9f0fe0ef          	jal	80005a3c <end_op>
    return -1;
    80007850:	fff00513          	li	a0,-1
    80007854:	fe9ff06f          	j	8000783c <sys_mknod+0x64>

0000000080007858 <sys_chdir>:

uint64
sys_chdir(void)
{
    80007858:	f6010113          	addi	sp,sp,-160
    8000785c:	08113c23          	sd	ra,152(sp)
    80007860:	08813823          	sd	s0,144(sp)
    80007864:	09213023          	sd	s2,128(sp)
    80007868:	0a010413          	addi	s0,sp,160
  char path[MAXPATH];
  struct inode *ip;
  struct proc *p = myproc();
    8000786c:	d89fa0ef          	jal	800025f4 <myproc>
    80007870:	00050913          	mv	s2,a0
  
  begin_op();
    80007874:	924fe0ef          	jal	80005998 <begin_op>
  if(argstr(0, path, MAXPATH) < 0 || (ip = namei(path)) == 0){
    80007878:	08000613          	li	a2,128
    8000787c:	f6040593          	addi	a1,s0,-160
    80007880:	00000513          	li	a0,0
    80007884:	c24fc0ef          	jal	80003ca8 <argstr>
    80007888:	06054063          	bltz	a0,800078e8 <sys_chdir+0x90>
    8000788c:	08913423          	sd	s1,136(sp)
    80007890:	f6040513          	addi	a0,s0,-160
    80007894:	e49fd0ef          	jal	800056dc <namei>
    80007898:	00050493          	mv	s1,a0
    8000789c:	04050463          	beqz	a0,800078e4 <sys_chdir+0x8c>
    end_op();
    return -1;
  }
  ilock(ip);
    800078a0:	9d0fd0ef          	jal	80004a70 <ilock>
  if(ip->type != T_DIR){
    800078a4:	04449703          	lh	a4,68(s1)
    800078a8:	00100793          	li	a5,1
    800078ac:	04f71463          	bne	a4,a5,800078f4 <sys_chdir+0x9c>
    iunlockput(ip);
    end_op();
    return -1;
  }
  iunlock(ip);
    800078b0:	00048513          	mv	a0,s1
    800078b4:	ab0fd0ef          	jal	80004b64 <iunlock>
  iput(p->cwd);
    800078b8:	15093503          	ld	a0,336(s2)
    800078bc:	be0fd0ef          	jal	80004c9c <iput>
  end_op();
    800078c0:	97cfe0ef          	jal	80005a3c <end_op>
  p->cwd = ip;
    800078c4:	14993823          	sd	s1,336(s2)
  return 0;
    800078c8:	00000513          	li	a0,0
    800078cc:	08813483          	ld	s1,136(sp)
}
    800078d0:	09813083          	ld	ra,152(sp)
    800078d4:	09013403          	ld	s0,144(sp)
    800078d8:	08013903          	ld	s2,128(sp)
    800078dc:	0a010113          	addi	sp,sp,160
    800078e0:	00008067          	ret
    800078e4:	08813483          	ld	s1,136(sp)
    end_op();
    800078e8:	954fe0ef          	jal	80005a3c <end_op>
    return -1;
    800078ec:	fff00513          	li	a0,-1
    800078f0:	fe1ff06f          	j	800078d0 <sys_chdir+0x78>
    iunlockput(ip);
    800078f4:	00048513          	mv	a0,s1
    800078f8:	c64fd0ef          	jal	80004d5c <iunlockput>
    end_op();
    800078fc:	940fe0ef          	jal	80005a3c <end_op>
    return -1;
    80007900:	fff00513          	li	a0,-1
    80007904:	08813483          	ld	s1,136(sp)
    80007908:	fc9ff06f          	j	800078d0 <sys_chdir+0x78>

000000008000790c <sys_exec>:

uint64
sys_exec(void)
{
    8000790c:	e2010113          	addi	sp,sp,-480
    80007910:	1c113c23          	sd	ra,472(sp)
    80007914:	1c813823          	sd	s0,464(sp)
    80007918:	1e010413          	addi	s0,sp,480
  char path[MAXPATH], *argv[MAXARG];
  int i;
  uint64 uargv, uarg;

  argaddr(1, &uargv);
    8000791c:	e2840593          	addi	a1,s0,-472
    80007920:	00100513          	li	a0,1
    80007924:	b50fc0ef          	jal	80003c74 <argaddr>
  if(argstr(0, path, MAXPATH) < 0) {
    80007928:	08000613          	li	a2,128
    8000792c:	f3040593          	addi	a1,s0,-208
    80007930:	00000513          	li	a0,0
    80007934:	b74fc0ef          	jal	80003ca8 <argstr>
    80007938:	00050793          	mv	a5,a0
    return -1;
    8000793c:	fff00513          	li	a0,-1
  if(argstr(0, path, MAXPATH) < 0) {
    80007940:	1407c863          	bltz	a5,80007a90 <sys_exec+0x184>
    80007944:	1c913423          	sd	s1,456(sp)
    80007948:	1d213023          	sd	s2,448(sp)
    8000794c:	1b313c23          	sd	s3,440(sp)
    80007950:	1b413823          	sd	s4,432(sp)
    80007954:	1b513423          	sd	s5,424(sp)
    80007958:	1b613023          	sd	s6,416(sp)
    8000795c:	19713c23          	sd	s7,408(sp)
  }
  memset(argv, 0, sizeof(argv));
    80007960:	e3040a13          	addi	s4,s0,-464
    80007964:	10000613          	li	a2,256
    80007968:	00000593          	li	a1,0
    8000796c:	000a0513          	mv	a0,s4
    80007970:	86df90ef          	jal	800011dc <memset>
  for(i=0;; i++){
    if(i >= NELEM(argv)){
    80007974:	000a0493          	mv	s1,s4
  memset(argv, 0, sizeof(argv));
    80007978:	000a0993          	mv	s3,s4
    8000797c:	00000913          	li	s2,0
      goto bad;
    }
    if(fetchaddr(uargv+sizeof(uint64)*i, (uint64*)&uarg) < 0){
    80007980:	e2040a93          	addi	s5,s0,-480
      break;
    }
    argv[i] = kalloc();
    if(argv[i] == 0)
      goto bad;
    if(fetchstr(uarg, argv[i], PGSIZE) < 0)
    80007984:	00001b37          	lui	s6,0x1
    if(i >= NELEM(argv)){
    80007988:	02000b93          	li	s7,32
    if(fetchaddr(uargv+sizeof(uint64)*i, (uint64*)&uarg) < 0){
    8000798c:	00391513          	slli	a0,s2,0x3
    80007990:	000a8593          	mv	a1,s5
    80007994:	e2843783          	ld	a5,-472(s0)
    80007998:	00f50533          	add	a0,a0,a5
    8000799c:	9bcfc0ef          	jal	80003b58 <fetchaddr>
    800079a0:	02054c63          	bltz	a0,800079d8 <sys_exec+0xcc>
    if(uarg == 0){
    800079a4:	e2043783          	ld	a5,-480(s0)
    800079a8:	06078663          	beqz	a5,80007a14 <sys_exec+0x108>
    argv[i] = kalloc();
    800079ac:	d34f90ef          	jal	80000ee0 <kalloc>
    800079b0:	00050593          	mv	a1,a0
    800079b4:	00a9b023          	sd	a0,0(s3)
    if(argv[i] == 0)
    800079b8:	02050063          	beqz	a0,800079d8 <sys_exec+0xcc>
    if(fetchstr(uarg, argv[i], PGSIZE) < 0)
    800079bc:	000b0613          	mv	a2,s6
    800079c0:	e2043503          	ld	a0,-480(s0)
    800079c4:	a0cfc0ef          	jal	80003bd0 <fetchstr>
    800079c8:	00054863          	bltz	a0,800079d8 <sys_exec+0xcc>
    if(i >= NELEM(argv)){
    800079cc:	00190913          	addi	s2,s2,1
    800079d0:	00898993          	addi	s3,s3,8
    800079d4:	fb791ce3          	bne	s2,s7,8000798c <sys_exec+0x80>
    kfree(argv[i]);

  return ret;

 bad:
  for(i = 0; i < NELEM(argv) && argv[i] != 0; i++)
    800079d8:	100a0a13          	addi	s4,s4,256
    800079dc:	0004b503          	ld	a0,0(s1)
    800079e0:	08050863          	beqz	a0,80007a70 <sys_exec+0x164>
    kfree(argv[i]);
    800079e4:	bacf90ef          	jal	80000d90 <kfree>
  for(i = 0; i < NELEM(argv) && argv[i] != 0; i++)
    800079e8:	00848493          	addi	s1,s1,8
    800079ec:	ff4498e3          	bne	s1,s4,800079dc <sys_exec+0xd0>
  return -1;
    800079f0:	fff00513          	li	a0,-1
    800079f4:	1c813483          	ld	s1,456(sp)
    800079f8:	1c013903          	ld	s2,448(sp)
    800079fc:	1b813983          	ld	s3,440(sp)
    80007a00:	1b013a03          	ld	s4,432(sp)
    80007a04:	1a813a83          	ld	s5,424(sp)
    80007a08:	1a013b03          	ld	s6,416(sp)
    80007a0c:	19813b83          	ld	s7,408(sp)
    80007a10:	0800006f          	j	80007a90 <sys_exec+0x184>
      argv[i] = 0;
    80007a14:	0009079b          	sext.w	a5,s2
    80007a18:	e3040593          	addi	a1,s0,-464
    80007a1c:	00379793          	slli	a5,a5,0x3
    80007a20:	00b787b3          	add	a5,a5,a1
    80007a24:	0007b023          	sd	zero,0(a5)
  int ret = kexec(path, argv);
    80007a28:	f3040513          	addi	a0,s0,-208
    80007a2c:	eedfe0ef          	jal	80006918 <kexec>
    80007a30:	00050913          	mv	s2,a0
  for(i = 0; i < NELEM(argv) && argv[i] != 0; i++)
    80007a34:	100a0a13          	addi	s4,s4,256
    80007a38:	0004b503          	ld	a0,0(s1)
    80007a3c:	00050863          	beqz	a0,80007a4c <sys_exec+0x140>
    kfree(argv[i]);
    80007a40:	b50f90ef          	jal	80000d90 <kfree>
  for(i = 0; i < NELEM(argv) && argv[i] != 0; i++)
    80007a44:	00848493          	addi	s1,s1,8
    80007a48:	ff4498e3          	bne	s1,s4,80007a38 <sys_exec+0x12c>
  return ret;
    80007a4c:	00090513          	mv	a0,s2
    80007a50:	1c813483          	ld	s1,456(sp)
    80007a54:	1c013903          	ld	s2,448(sp)
    80007a58:	1b813983          	ld	s3,440(sp)
    80007a5c:	1b013a03          	ld	s4,432(sp)
    80007a60:	1a813a83          	ld	s5,424(sp)
    80007a64:	1a013b03          	ld	s6,416(sp)
    80007a68:	19813b83          	ld	s7,408(sp)
    80007a6c:	0240006f          	j	80007a90 <sys_exec+0x184>
  return -1;
    80007a70:	fff00513          	li	a0,-1
    80007a74:	1c813483          	ld	s1,456(sp)
    80007a78:	1c013903          	ld	s2,448(sp)
    80007a7c:	1b813983          	ld	s3,440(sp)
    80007a80:	1b013a03          	ld	s4,432(sp)
    80007a84:	1a813a83          	ld	s5,424(sp)
    80007a88:	1a013b03          	ld	s6,416(sp)
    80007a8c:	19813b83          	ld	s7,408(sp)
}
    80007a90:	1d813083          	ld	ra,472(sp)
    80007a94:	1d013403          	ld	s0,464(sp)
    80007a98:	1e010113          	addi	sp,sp,480
    80007a9c:	00008067          	ret

0000000080007aa0 <sys_pipe>:

uint64
sys_pipe(void)
{
    80007aa0:	fc010113          	addi	sp,sp,-64
    80007aa4:	02113c23          	sd	ra,56(sp)
    80007aa8:	02813823          	sd	s0,48(sp)
    80007aac:	02913423          	sd	s1,40(sp)
    80007ab0:	04010413          	addi	s0,sp,64
  uint64 fdarray; // user pointer to array of two integers
  struct file *rf, *wf;
  int fd0, fd1;
  struct proc *p = myproc();
    80007ab4:	b41fa0ef          	jal	800025f4 <myproc>
    80007ab8:	00050493          	mv	s1,a0

  argaddr(0, &fdarray);
    80007abc:	fd840593          	addi	a1,s0,-40
    80007ac0:	00000513          	li	a0,0
    80007ac4:	9b0fc0ef          	jal	80003c74 <argaddr>
  if(pipealloc(&rf, &wf) < 0)
    80007ac8:	fc840593          	addi	a1,s0,-56
    80007acc:	fd040513          	addi	a0,s0,-48
    80007ad0:	985fe0ef          	jal	80006454 <pipealloc>
    return -1;
    80007ad4:	fff00793          	li	a5,-1
  if(pipealloc(&rf, &wf) < 0)
    80007ad8:	0c054663          	bltz	a0,80007ba4 <sys_pipe+0x104>
  fd0 = -1;
    80007adc:	fcf42223          	sw	a5,-60(s0)
  if((fd0 = fdalloc(rf)) < 0 || (fd1 = fdalloc(wf)) < 0){
    80007ae0:	fd043503          	ld	a0,-48(s0)
    80007ae4:	b40ff0ef          	jal	80006e24 <fdalloc>
    80007ae8:	fca42223          	sw	a0,-60(s0)
    80007aec:	0a054263          	bltz	a0,80007b90 <sys_pipe+0xf0>
    80007af0:	fc843503          	ld	a0,-56(s0)
    80007af4:	b30ff0ef          	jal	80006e24 <fdalloc>
    80007af8:	fca42023          	sw	a0,-64(s0)
    80007afc:	06054e63          	bltz	a0,80007b78 <sys_pipe+0xd8>
      p->ofile[fd0] = 0;
    fileclose(rf);
    fileclose(wf);
    return -1;
  }
  if(copyout(p->pagetable, fdarray, (char*)&fd0, sizeof(fd0)) < 0 ||
    80007b00:	00400693          	li	a3,4
    80007b04:	fc440613          	addi	a2,s0,-60
    80007b08:	fd843583          	ld	a1,-40(s0)
    80007b0c:	0504b503          	ld	a0,80(s1)
    80007b10:	e60fa0ef          	jal	80002170 <copyout>
    80007b14:	02054263          	bltz	a0,80007b38 <sys_pipe+0x98>
     copyout(p->pagetable, fdarray+sizeof(fd0), (char *)&fd1, sizeof(fd1)) < 0){
    80007b18:	00400693          	li	a3,4
    80007b1c:	fc040613          	addi	a2,s0,-64
    80007b20:	fd843583          	ld	a1,-40(s0)
    80007b24:	00d585b3          	add	a1,a1,a3
    80007b28:	0504b503          	ld	a0,80(s1)
    80007b2c:	e44fa0ef          	jal	80002170 <copyout>
    p->ofile[fd1] = 0;
    fileclose(rf);
    fileclose(wf);
    return -1;
  }
  return 0;
    80007b30:	00000793          	li	a5,0
  if(copyout(p->pagetable, fdarray, (char*)&fd0, sizeof(fd0)) < 0 ||
    80007b34:	06055863          	bgez	a0,80007ba4 <sys_pipe+0x104>
    p->ofile[fd0] = 0;
    80007b38:	fc442783          	lw	a5,-60(s0)
    80007b3c:	00379793          	slli	a5,a5,0x3
    80007b40:	0d078793          	addi	a5,a5,208
    80007b44:	00f487b3          	add	a5,s1,a5
    80007b48:	0007b023          	sd	zero,0(a5)
    p->ofile[fd1] = 0;
    80007b4c:	fc042783          	lw	a5,-64(s0)
    80007b50:	00379793          	slli	a5,a5,0x3
    80007b54:	0d078793          	addi	a5,a5,208
    80007b58:	00f487b3          	add	a5,s1,a5
    80007b5c:	0007b023          	sd	zero,0(a5)
    fileclose(rf);
    80007b60:	fd043503          	ld	a0,-48(s0)
    80007b64:	c10fe0ef          	jal	80005f74 <fileclose>
    fileclose(wf);
    80007b68:	fc843503          	ld	a0,-56(s0)
    80007b6c:	c08fe0ef          	jal	80005f74 <fileclose>
    return -1;
    80007b70:	fff00793          	li	a5,-1
    80007b74:	0300006f          	j	80007ba4 <sys_pipe+0x104>
    if(fd0 >= 0)
    80007b78:	fc442783          	lw	a5,-60(s0)
    80007b7c:	0007ca63          	bltz	a5,80007b90 <sys_pipe+0xf0>
      p->ofile[fd0] = 0;
    80007b80:	00379793          	slli	a5,a5,0x3
    80007b84:	0d078793          	addi	a5,a5,208
    80007b88:	00f487b3          	add	a5,s1,a5
    80007b8c:	0007b023          	sd	zero,0(a5)
    fileclose(rf);
    80007b90:	fd043503          	ld	a0,-48(s0)
    80007b94:	be0fe0ef          	jal	80005f74 <fileclose>
    fileclose(wf);
    80007b98:	fc843503          	ld	a0,-56(s0)
    80007b9c:	bd8fe0ef          	jal	80005f74 <fileclose>
    return -1;
    80007ba0:	fff00793          	li	a5,-1
}
    80007ba4:	00078513          	mv	a0,a5
    80007ba8:	03813083          	ld	ra,56(sp)
    80007bac:	03013403          	ld	s0,48(sp)
    80007bb0:	02813483          	ld	s1,40(sp)
    80007bb4:	04010113          	addi	sp,sp,64
    80007bb8:	00008067          	ret
    80007bbc:	0000                	.insn	2, 0x0000
	...

0000000080007bc0 <kernelvec>:
.globl kerneltrap
.globl kernelvec
.align 4
kernelvec:
        # make room to save registers.
        addi sp, sp, -256
    80007bc0:	f0010113          	addi	sp,sp,-256

        # save caller-saved registers.
        sd ra, 0(sp)
    80007bc4:	00113023          	sd	ra,0(sp)
        # sd sp, 8(sp)
        sd gp, 16(sp)
    80007bc8:	00313823          	sd	gp,16(sp)
        sd tp, 24(sp)
    80007bcc:	00413c23          	sd	tp,24(sp)
        sd t0, 32(sp)
    80007bd0:	02513023          	sd	t0,32(sp)
        sd t1, 40(sp)
    80007bd4:	02613423          	sd	t1,40(sp)
        sd t2, 48(sp)
    80007bd8:	02713823          	sd	t2,48(sp)
        sd a0, 72(sp)
    80007bdc:	04a13423          	sd	a0,72(sp)
        sd a1, 80(sp)
    80007be0:	04b13823          	sd	a1,80(sp)
        sd a2, 88(sp)
    80007be4:	04c13c23          	sd	a2,88(sp)
        sd a3, 96(sp)
    80007be8:	06d13023          	sd	a3,96(sp)
        sd a4, 104(sp)
    80007bec:	06e13423          	sd	a4,104(sp)
        sd a5, 112(sp)
    80007bf0:	06f13823          	sd	a5,112(sp)
        sd a6, 120(sp)
    80007bf4:	07013c23          	sd	a6,120(sp)
        sd a7, 128(sp)
    80007bf8:	09113023          	sd	a7,128(sp)
        sd t3, 216(sp)
    80007bfc:	0dc13c23          	sd	t3,216(sp)
        sd t4, 224(sp)
    80007c00:	0fd13023          	sd	t4,224(sp)
        sd t5, 232(sp)
    80007c04:	0fe13423          	sd	t5,232(sp)
        sd t6, 240(sp)
    80007c08:	0ff13823          	sd	t6,240(sp)

        # call the C trap handler in trap.c
        call kerneltrap
    80007c0c:	de9fb0ef          	jal	800039f4 <kerneltrap>

        # restore registers.
        ld ra, 0(sp)
    80007c10:	00013083          	ld	ra,0(sp)
        # ld sp, 8(sp)
        ld gp, 16(sp)
    80007c14:	01013183          	ld	gp,16(sp)
        # not tp (contains hartid), in case we moved CPUs
        ld t0, 32(sp)
    80007c18:	02013283          	ld	t0,32(sp)
        ld t1, 40(sp)
    80007c1c:	02813303          	ld	t1,40(sp)
        ld t2, 48(sp)
    80007c20:	03013383          	ld	t2,48(sp)
        ld a0, 72(sp)
    80007c24:	04813503          	ld	a0,72(sp)
        ld a1, 80(sp)
    80007c28:	05013583          	ld	a1,80(sp)
        ld a2, 88(sp)
    80007c2c:	05813603          	ld	a2,88(sp)
        ld a3, 96(sp)
    80007c30:	06013683          	ld	a3,96(sp)
        ld a4, 104(sp)
    80007c34:	06813703          	ld	a4,104(sp)
        ld a5, 112(sp)
    80007c38:	07013783          	ld	a5,112(sp)
        ld a6, 120(sp)
    80007c3c:	07813803          	ld	a6,120(sp)
        ld a7, 128(sp)
    80007c40:	08013883          	ld	a7,128(sp)
        ld t3, 216(sp)
    80007c44:	0d813e03          	ld	t3,216(sp)
        ld t4, 224(sp)
    80007c48:	0e013e83          	ld	t4,224(sp)
        ld t5, 232(sp)
    80007c4c:	0e813f03          	ld	t5,232(sp)
        ld t6, 240(sp)
    80007c50:	0f013f83          	ld	t6,240(sp)

        addi sp, sp, 256
    80007c54:	10010113          	addi	sp,sp,256

        # return to whatever we were doing in the kernel.
        sret
    80007c58:	10200073          	sret
    80007c5c:	00000013          	nop

0000000080007c60 <plicinit>:
// the riscv Platform Level Interrupt Controller (PLIC).
//

void
plicinit(void)
{
    80007c60:	ff010113          	addi	sp,sp,-16
    80007c64:	00113423          	sd	ra,8(sp)
    80007c68:	00813023          	sd	s0,0(sp)
    80007c6c:	01010413          	addi	s0,sp,16
  // set desired IRQ priorities non-zero (otherwise disabled).
  *(uint32*)(PLIC + UART0_IRQ*4) = 1;
    80007c70:	0c000737          	lui	a4,0xc000
    80007c74:	00100793          	li	a5,1
    80007c78:	02f72423          	sw	a5,40(a4) # c000028 <_binary_fs_img_size+0xbe0c028>
  *(uint32*)(PLIC + VIRTIO0_IRQ*4) = 1;
    80007c7c:	00f72223          	sw	a5,4(a4)
}
    80007c80:	00813083          	ld	ra,8(sp)
    80007c84:	00013403          	ld	s0,0(sp)
    80007c88:	01010113          	addi	sp,sp,16
    80007c8c:	00008067          	ret

0000000080007c90 <plicinithart>:

void
plicinithart(void)
{
    80007c90:	ff010113          	addi	sp,sp,-16
    80007c94:	00113423          	sd	ra,8(sp)
    80007c98:	00813023          	sd	s0,0(sp)
    80007c9c:	01010413          	addi	s0,sp,16
  int hart = cpuid();
    80007ca0:	8f5fa0ef          	jal	80002594 <cpuid>
  
  // set enable bits for this hart's S-mode
  // for the uart and virtio disk.
  *(uint32*)PLIC_SENABLE(hart) = (1 << UART0_IRQ) | (1 << VIRTIO0_IRQ);
    80007ca4:	0085171b          	slliw	a4,a0,0x8
    80007ca8:	0c0027b7          	lui	a5,0xc002
    80007cac:	00e787b3          	add	a5,a5,a4
    80007cb0:	40200713          	li	a4,1026
    80007cb4:	08e7a023          	sw	a4,128(a5) # c002080 <_binary_fs_img_size+0xbe0e080>

  // set this hart's S-mode priority threshold to 0.
  *(uint32*)PLIC_SPRIORITY(hart) = 0;
    80007cb8:	00d5151b          	slliw	a0,a0,0xd
    80007cbc:	0c2017b7          	lui	a5,0xc201
    80007cc0:	00a787b3          	add	a5,a5,a0
    80007cc4:	0007a023          	sw	zero,0(a5) # c201000 <_binary_fs_img_size+0xc00d000>
}
    80007cc8:	00813083          	ld	ra,8(sp)
    80007ccc:	00013403          	ld	s0,0(sp)
    80007cd0:	01010113          	addi	sp,sp,16
    80007cd4:	00008067          	ret

0000000080007cd8 <plic_claim>:

// ask the PLIC what interrupt we should serve.
int
plic_claim(void)
{
    80007cd8:	ff010113          	addi	sp,sp,-16
    80007cdc:	00113423          	sd	ra,8(sp)
    80007ce0:	00813023          	sd	s0,0(sp)
    80007ce4:	01010413          	addi	s0,sp,16
  int hart = cpuid();
    80007ce8:	8adfa0ef          	jal	80002594 <cpuid>
  int irq = *(uint32*)PLIC_SCLAIM(hart);
    80007cec:	00d5151b          	slliw	a0,a0,0xd
    80007cf0:	0c2017b7          	lui	a5,0xc201
    80007cf4:	00a787b3          	add	a5,a5,a0
  return irq;
}
    80007cf8:	0047a503          	lw	a0,4(a5) # c201004 <_binary_fs_img_size+0xc00d004>
    80007cfc:	00813083          	ld	ra,8(sp)
    80007d00:	00013403          	ld	s0,0(sp)
    80007d04:	01010113          	addi	sp,sp,16
    80007d08:	00008067          	ret

0000000080007d0c <plic_complete>:

// tell the PLIC we've served this IRQ.
void
plic_complete(int irq)
{
    80007d0c:	fe010113          	addi	sp,sp,-32
    80007d10:	00113c23          	sd	ra,24(sp)
    80007d14:	00813823          	sd	s0,16(sp)
    80007d18:	00913423          	sd	s1,8(sp)
    80007d1c:	02010413          	addi	s0,sp,32
    80007d20:	00050493          	mv	s1,a0
  int hart = cpuid();
    80007d24:	871fa0ef          	jal	80002594 <cpuid>
  *(uint32*)PLIC_SCLAIM(hart) = irq;
    80007d28:	00d5179b          	slliw	a5,a0,0xd
    80007d2c:	0c201737          	lui	a4,0xc201
    80007d30:	00f707b3          	add	a5,a4,a5
    80007d34:	0097a223          	sw	s1,4(a5)
}
    80007d38:	01813083          	ld	ra,24(sp)
    80007d3c:	01013403          	ld	s0,16(sp)
    80007d40:	00813483          	ld	s1,8(sp)
    80007d44:	02010113          	addi	sp,sp,32
    80007d48:	00008067          	ret

0000000080007d4c <virtio_disk_init>:
extern char _binary_fs_img_start[];
extern char _binary_fs_img_end[];

void
virtio_disk_init(void)
{
    80007d4c:	fd010113          	addi	sp,sp,-48
    80007d50:	02113423          	sd	ra,40(sp)
    80007d54:	02813023          	sd	s0,32(sp)
    80007d58:	00913c23          	sd	s1,24(sp)
    80007d5c:	01213823          	sd	s2,16(sp)
    80007d60:	01313423          	sd	s3,8(sp)
    80007d64:	03010413          	addi	s0,sp,48
  initlock(&ramdisk_lock, "ramdisk");
    80007d68:	00002597          	auipc	a1,0x2
    80007d6c:	ca058593          	addi	a1,a1,-864 # 80009a08 <etext+0xa08>
    80007d70:	0020f517          	auipc	a0,0x20f
    80007d74:	fd850513          	addi	a0,a0,-40 # 80216d48 <ramdisk_lock>
    80007d78:	9e4f90ef          	jal	80000f5c <initlock>

  uint64 img_sz = (uint64)(_binary_fs_img_end - _binary_fs_img_start);
    80007d7c:	001f6497          	auipc	s1,0x1f6
    80007d80:	dd448493          	addi	s1,s1,-556 # 801fdb50 <panicked>
    80007d84:	00002797          	auipc	a5,0x2
    80007d88:	dcc78793          	addi	a5,a5,-564 # 80009b50 <_binary_fs_img_start>
    80007d8c:	40f484b3          	sub	s1,s1,a5
  if(img_sz > RAMDISK_SIZE)
    80007d90:	00048993          	mv	s3,s1
    80007d94:	001f47b7          	lui	a5,0x1f4
    80007d98:	0097f463          	bgeu	a5,s1,80007da0 <virtio_disk_init+0x54>
    80007d9c:	00078993          	mv	s3,a5
    img_sz = RAMDISK_SIZE;

  // fs.img の中身を ramdisk にコピー
  memmove(ramdisk, _binary_fs_img_start, img_sz);
    80007da0:	0009891b          	sext.w	s2,s3
    80007da4:	00090613          	mv	a2,s2
    80007da8:	00002597          	auipc	a1,0x2
    80007dac:	da858593          	addi	a1,a1,-600 # 80009b50 <_binary_fs_img_start>
    80007db0:	0020f517          	auipc	a0,0x20f
    80007db4:	fb050513          	addi	a0,a0,-80 # 80216d60 <ramdisk>
    80007db8:	cc0f90ef          	jal	80001278 <memmove>

  // 余りはゼロで埋める（fs.img が RAMDISK_SIZE より小さい場合）
  if(img_sz < RAMDISK_SIZE)
    80007dbc:	001f47b7          	lui	a5,0x1f4
    80007dc0:	02f4e063          	bltu	s1,a5,80007de0 <virtio_disk_init+0x94>
    memset(ramdisk + img_sz, 0, RAMDISK_SIZE - img_sz);
}
    80007dc4:	02813083          	ld	ra,40(sp)
    80007dc8:	02013403          	ld	s0,32(sp)
    80007dcc:	01813483          	ld	s1,24(sp)
    80007dd0:	01013903          	ld	s2,16(sp)
    80007dd4:	00813983          	ld	s3,8(sp)
    80007dd8:	03010113          	addi	sp,sp,48
    80007ddc:	00008067          	ret
    memset(ramdisk + img_sz, 0, RAMDISK_SIZE - img_sz);
    80007de0:	001f4637          	lui	a2,0x1f4
    80007de4:	4126063b          	subw	a2,a2,s2
    80007de8:	00000593          	li	a1,0
    80007dec:	0020f517          	auipc	a0,0x20f
    80007df0:	f7450513          	addi	a0,a0,-140 # 80216d60 <ramdisk>
    80007df4:	01350533          	add	a0,a0,s3
    80007df8:	be4f90ef          	jal	800011dc <memset>
}
    80007dfc:	fc9ff06f          	j	80007dc4 <virtio_disk_init+0x78>

0000000080007e00 <virtio_disk_rw>:

void
virtio_disk_rw(struct buf *b, int write)
{
    80007e00:	fe010113          	addi	sp,sp,-32
    80007e04:	00113c23          	sd	ra,24(sp)
    80007e08:	00813823          	sd	s0,16(sp)
    80007e0c:	00913423          	sd	s1,8(sp)
    80007e10:	01213023          	sd	s2,0(sp)
    80007e14:	02010413          	addi	s0,sp,32
  if(b->blockno >= RAMDISK_NBLK)
    80007e18:	00c52703          	lw	a4,12(a0)
    80007e1c:	7cf00793          	li	a5,1999
    80007e20:	06e7e663          	bltu	a5,a4,80007e8c <virtio_disk_rw+0x8c>
    80007e24:	00050493          	mv	s1,a0
    80007e28:	00058913          	mv	s2,a1
    panic("ramdisk: blockno out of range");

  acquire(&ramdisk_lock);
    80007e2c:	0020f517          	auipc	a0,0x20f
    80007e30:	f1c50513          	addi	a0,a0,-228 # 80216d48 <ramdisk_lock>
    80007e34:	a0cf90ef          	jal	80001040 <acquire>

  uchar *p = &ramdisk[(uint64)b->blockno * BSIZE];
    80007e38:	00c4e503          	lwu	a0,12(s1)
    80007e3c:	00a51513          	slli	a0,a0,0xa
    80007e40:	0020f797          	auipc	a5,0x20f
    80007e44:	f2078793          	addi	a5,a5,-224 # 80216d60 <ramdisk>
    80007e48:	00f50533          	add	a0,a0,a5
  if(write)
    80007e4c:	04090663          	beqz	s2,80007e98 <virtio_disk_rw+0x98>
    memmove(p, b->data, BSIZE);
    80007e50:	40000613          	li	a2,1024
    80007e54:	05848593          	addi	a1,s1,88
    80007e58:	c20f90ef          	jal	80001278 <memmove>
  else
    memmove(b->data, p, BSIZE);

  release(&ramdisk_lock);
    80007e5c:	0020f517          	auipc	a0,0x20f
    80007e60:	eec50513          	addi	a0,a0,-276 # 80216d48 <ramdisk_lock>
    80007e64:	ab4f90ef          	jal	80001118 <release>

  // ここ重要：virtio みたいに割り込み完了を待たせない（同期完了）
  b->valid = 1;
    80007e68:	00100793          	li	a5,1
    80007e6c:	00f4a023          	sw	a5,0(s1)
  b->disk = 0;
    80007e70:	0004a223          	sw	zero,4(s1)
}
    80007e74:	01813083          	ld	ra,24(sp)
    80007e78:	01013403          	ld	s0,16(sp)
    80007e7c:	00813483          	ld	s1,8(sp)
    80007e80:	00013903          	ld	s2,0(sp)
    80007e84:	02010113          	addi	sp,sp,32
    80007e88:	00008067          	ret
    panic("ramdisk: blockno out of range");
    80007e8c:	00002517          	auipc	a0,0x2
    80007e90:	b8450513          	addi	a0,a0,-1148 # 80009a10 <etext+0xa10>
    80007e94:	c59f80ef          	jal	80000aec <panic>
    memmove(b->data, p, BSIZE);
    80007e98:	40000613          	li	a2,1024
    80007e9c:	00050593          	mv	a1,a0
    80007ea0:	05848513          	addi	a0,s1,88
    80007ea4:	bd4f90ef          	jal	80001278 <memmove>
    80007ea8:	fb5ff06f          	j	80007e5c <virtio_disk_rw+0x5c>

0000000080007eac <virtio_disk_intr>:

void
virtio_disk_intr(void)
{
    80007eac:	ff010113          	addi	sp,sp,-16
    80007eb0:	00113423          	sd	ra,8(sp)
    80007eb4:	00813023          	sd	s0,0(sp)
    80007eb8:	01010413          	addi	s0,sp,16
  // ramdisk は割り込み不要
}
    80007ebc:	00813083          	ld	ra,8(sp)
    80007ec0:	00013403          	ld	s0,0(sp)
    80007ec4:	01010113          	addi	sp,sp,16
    80007ec8:	00008067          	ret
	...

0000000080008000 <_trampoline>:
    80008000:	14051073          	csrw	sscratch,a0
    80008004:	02000537          	lui	a0,0x2000
    80008008:	fff5051b          	addiw	a0,a0,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    8000800c:	00d51513          	slli	a0,a0,0xd
    80008010:	02153423          	sd	ra,40(a0)
    80008014:	02253823          	sd	sp,48(a0)
    80008018:	02353c23          	sd	gp,56(a0)
    8000801c:	04453023          	sd	tp,64(a0)
    80008020:	04553423          	sd	t0,72(a0)
    80008024:	04653823          	sd	t1,80(a0)
    80008028:	04753c23          	sd	t2,88(a0)
    8000802c:	06853023          	sd	s0,96(a0)
    80008030:	06953423          	sd	s1,104(a0)
    80008034:	06b53c23          	sd	a1,120(a0)
    80008038:	08c53023          	sd	a2,128(a0)
    8000803c:	08d53423          	sd	a3,136(a0)
    80008040:	08e53823          	sd	a4,144(a0)
    80008044:	08f53c23          	sd	a5,152(a0)
    80008048:	0b053023          	sd	a6,160(a0)
    8000804c:	0b153423          	sd	a7,168(a0)
    80008050:	0b253823          	sd	s2,176(a0)
    80008054:	0b353c23          	sd	s3,184(a0)
    80008058:	0d453023          	sd	s4,192(a0)
    8000805c:	0d553423          	sd	s5,200(a0)
    80008060:	0d653823          	sd	s6,208(a0)
    80008064:	0d753c23          	sd	s7,216(a0)
    80008068:	0f853023          	sd	s8,224(a0)
    8000806c:	0f953423          	sd	s9,232(a0)
    80008070:	0fa53823          	sd	s10,240(a0)
    80008074:	0fb53c23          	sd	s11,248(a0)
    80008078:	11c53023          	sd	t3,256(a0)
    8000807c:	11d53423          	sd	t4,264(a0)
    80008080:	11e53823          	sd	t5,272(a0)
    80008084:	11f53c23          	sd	t6,280(a0)
    80008088:	140022f3          	csrr	t0,sscratch
    8000808c:	06553823          	sd	t0,112(a0)
    80008090:	00853103          	ld	sp,8(a0)
    80008094:	02053203          	ld	tp,32(a0)
    80008098:	01053283          	ld	t0,16(a0)
    8000809c:	00053303          	ld	t1,0(a0)
    800080a0:	12000073          	sfence.vma
    800080a4:	18031073          	csrw	satp,t1
    800080a8:	12000073          	sfence.vma
    800080ac:	000280e7          	jalr	t0

00000000800080b0 <userret>:
    800080b0:	12000073          	sfence.vma
    800080b4:	18051073          	csrw	satp,a0
    800080b8:	12000073          	sfence.vma
    800080bc:	02000537          	lui	a0,0x2000
    800080c0:	fff5051b          	addiw	a0,a0,-1 # 1ffffff <_binary_fs_img_size+0x1e0bfff>
    800080c4:	00d51513          	slli	a0,a0,0xd
    800080c8:	02853083          	ld	ra,40(a0)
    800080cc:	03053103          	ld	sp,48(a0)
    800080d0:	03853183          	ld	gp,56(a0)
    800080d4:	04053203          	ld	tp,64(a0)
    800080d8:	04853283          	ld	t0,72(a0)
    800080dc:	05053303          	ld	t1,80(a0)
    800080e0:	05853383          	ld	t2,88(a0)
    800080e4:	06053403          	ld	s0,96(a0)
    800080e8:	06853483          	ld	s1,104(a0)
    800080ec:	07853583          	ld	a1,120(a0)
    800080f0:	08053603          	ld	a2,128(a0)
    800080f4:	08853683          	ld	a3,136(a0)
    800080f8:	09053703          	ld	a4,144(a0)
    800080fc:	09853783          	ld	a5,152(a0)
    80008100:	0a053803          	ld	a6,160(a0)
    80008104:	0a853883          	ld	a7,168(a0)
    80008108:	0b053903          	ld	s2,176(a0)
    8000810c:	0b853983          	ld	s3,184(a0)
    80008110:	0c053a03          	ld	s4,192(a0)
    80008114:	0c853a83          	ld	s5,200(a0)
    80008118:	0d053b03          	ld	s6,208(a0)
    8000811c:	0d853b83          	ld	s7,216(a0)
    80008120:	0e053c03          	ld	s8,224(a0)
    80008124:	0e853c83          	ld	s9,232(a0)
    80008128:	0f053d03          	ld	s10,240(a0)
    8000812c:	0f853d83          	ld	s11,248(a0)
    80008130:	10053e03          	ld	t3,256(a0)
    80008134:	10853e83          	ld	t4,264(a0)
    80008138:	11053f03          	ld	t5,272(a0)
    8000813c:	11853f83          	ld	t6,280(a0)
    80008140:	07053503          	ld	a0,112(a0)
    80008144:	10200073          	sret
	...
