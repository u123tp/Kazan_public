// kernel/virtio_disk.c  (ramdisk 版)
// もともとのvirtioを,virtioを使わなくても動くように置き換えたもの.

#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "buf.h"


// xv6 のブロック数(FSSIZE) * 1KB(BSIZE) 分をRAMに持つ
#define RAMDISK_NBLK  FSSIZE
#define RAMDISK_SIZE  ((uint64)RAMDISK_NBLK * BSIZE)

static struct spinlock ramdisk_lock;
static uchar ramdisk[RAMDISK_SIZE];

// Makefileで fs.img を kernel に埋め込むと、このシンボルが生える
extern char _binary_fs_img_start[];
extern char _binary_fs_img_end[];

void
virtio_disk_init(void)
{
  initlock(&ramdisk_lock, "ramdisk");

  uint64 img_sz = (uint64)(_binary_fs_img_end - _binary_fs_img_start);
  if(img_sz > RAMDISK_SIZE)
    img_sz = RAMDISK_SIZE;

  // fs.img の中身を ramdisk にコピー
  memmove(ramdisk, _binary_fs_img_start, img_sz);

  // 余りはゼロで埋める（fs.img が RAMDISK_SIZE より小さい場合）
  if(img_sz < RAMDISK_SIZE)
    memset(ramdisk + img_sz, 0, RAMDISK_SIZE - img_sz);
}

void
virtio_disk_rw(struct buf *b, int write)
{
  if(b->blockno >= RAMDISK_NBLK)
    panic("ramdisk: blockno out of range");

  acquire(&ramdisk_lock);

  uchar *p = &ramdisk[(uint64)b->blockno * BSIZE];
  if(write)
    memmove(p, b->data, BSIZE);
  else
    memmove(b->data, p, BSIZE);

  release(&ramdisk_lock);

  // ここ重要：virtio みたいに割り込み完了を待たせない（同期完了）
  b->valid = 1;
  b->disk = 0;
}

void
virtio_disk_intr(void)
{
  // ramdisk は割り込み不要
}
