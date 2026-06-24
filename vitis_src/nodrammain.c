#include "ff.h"
#include "xil_cache.h"
#include "xil_printf.h"
#include "xil_types.h"

#include <string.h>

#define LOAD_ADDR ((UINTPTR)0x10000000U)
#define CHUNK_SIZE (64U * 1024U)
#define MAX_IMAGE_SIZE (512U * 1024U * 1024U)

int main(void)
{
    FATFS fatfs;
    FIL fil;
    FRESULT fr;
    UINT br;
    u32 total = 0U;

    static u8 io_buf[CHUNK_SIZE] __attribute__((aligned(64)));

    xil_printf("\r\nloader start\r\n");

    fr = f_mount(&fatfs, "0:/", 1);
    if (fr != FR_OK)
    {
        xil_printf("ERROR: f_mount failed: %d\r\n", fr);
        return -1;
    }

    fr = f_open(&fil, "0:/kernel.bin", FA_READ);
    if (fr != FR_OK)
    {
        xil_printf("ERROR: f_open 0:/kernel.bin failed: %d\r\n", fr);
        return -1;
    }

    FSIZE_t file_size = f_size(&fil);

    if (file_size == 0U)
    {
        xil_printf("ERROR: kernel.bin size is zero\r\n");
        f_close(&fil);
        return -1;
    }

    if (file_size > MAX_IMAGE_SIZE)
    {
        xil_printf("ERROR: kernel.bin too large\r\n");
        f_close(&fil);
        return -1;
    }

    xil_printf("kernel.bin size = %u bytes\r\n", (u32)file_size);
    xil_printf("load address    = 0x%08lx\r\n", (unsigned long)LOAD_ADDR);

    while (total < (u32)file_size)
    {
        UINT req = CHUNK_SIZE;

        if (((u32)file_size - total) < CHUNK_SIZE)
        {
            req = (UINT)((u32)file_size - total);
        }

        fr = f_read(&fil, io_buf, req, &br);
        if (fr != FR_OK)
        {
            xil_printf("ERROR: f_read failed: %d\r\n", fr);
            f_close(&fil);
            return -1;
        }

        if (br == 0U)
        {
            xil_printf("ERROR: unexpected EOF\r\n");
            f_close(&fil);
            return -1;
        }

        memcpy((void *)(LOAD_ADDR + total), io_buf, br);
        total += br;
    }

    f_close(&fil);

    /*
     * A53 が DDR に書いた内容を PL 側から見えるようにする。
     */
    Xil_DCacheFlushRange((INTPTR)LOAD_ADDR, total);

    __asm__ volatile("dsb sy");
    __asm__ volatile("isb");

    xil_printf("loaded %u bytes to 0x%08lx\r\n",
               total, (unsigned long)LOAD_ADDR);
    xil_printf("D-cache flushed\r\n");
    xil_printf("loader done\r\n");

    xil_printf("dump loaded data:\r\n");
    for (u32 off = 0; off < 64; off += 8)
    {
        u64 v = *(volatile u64 *)(LOAD_ADDR + off);
        xil_printf("0x%08lx : 0x%016llx\r\n",
                   (unsigned long)(LOAD_ADDR + off),
                   (unsigned long long)v);
    }

    while (1)
    {
        /* stop here */
    }

    return 0;
}