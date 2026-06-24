#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"

volatile static int started = 0;

// start() jumps here in supervisor mode on all CPUs.
void main()
{
  if (cpuid() == 0)
  {
    consoleinit();
    printfinit();
    printf("\n");
    printf("xv6 kernel is booting (ver 5.0)\n");
    printf("\n");
    kinit(); // physical page allocator
    printf("[LOG][main.c] kinit() done.\n");
    kvminit(); // create kernel page table
    printf("[LOG][main.c] kvminit() done.\n");
    kvminithart(); // turn on paging
    printf("[LOG][main.c] kvminithart() done.\n");
    procinit(); // process table
    printf("[LOG][main.c] procinit() done.\n");
    trapinit(); // trap vectors
    printf("[LOG][main.c] trapinit() done.\n");
    trapinithart(); // install kernel trap vector
    printf("[LOG][main.c] trapinithart() done.\n");
    plicinit(); // set up interrupt controller
    printf("[LOG][main.c] plicinit() done.\n");
    plicinithart(); // ask PLIC for device interrupts
    printf("[LOG][main.c] plicinithart() done.\n");
    binit(); // buffer cache
    printf("[LOG][main.c] binit() done.\n");
    iinit(); // inode table
    printf("[LOG][main.c] iinit() done.\n");
    fileinit(); // file table
    printf("[LOG][main.c] fileinit() done.\n");
    virtio_disk_init(); // emulated hard disk
    printf("[LOG][main.c] virtio_disk_init() done.\n");
    userinit(); // first user process
    printf("[LOG][main.c] userinit() done.\n");
    __sync_synchronize();
    started = 1;
  }
  else
  {
    while (started == 0)
      ;
    __sync_synchronize();
    printf("hart %d starting\n", cpuid());
    kvminithart();  // turn on paging
    trapinithart(); // install kernel trap vector
    plicinithart(); // ask PLIC for device interrupts
  }

  printf("[LOG][main.c] Boot process has done. scheduler() will be called.\n");
  scheduler();
}
