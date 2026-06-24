#include "ff.h"
#include "xil_cache.h"
#include "xil_printf.h"
#include "xil_types.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "sleep.h"

#include <string.h>

#define LOAD_ADDR ((UINTPTR)0x10000000U)
#define CHUNK_SIZE (64U * 1024U)
#define MAX_IMAGE_SIZE (512U * 1024U * 1024U)

/*
 * KV260 / Zynq UltraScale+ MPSoC
 *
 * pl_resetn0 is controlled through PS GPIO.
 * Usually:
 *   GPIO 95 -> pl_resetn0
 *   GPIO 94 -> pl_resetn1
 *   GPIO 93 -> pl_resetn2
 *   GPIO 92 -> pl_resetn3
 *
 * pl_resetn is active-low:
 *   0: reset assert
 *   1: reset deassert
 */
#define PL_RESETN0_GPIO_PIN 95U

static XGpioPs Gpio;

static int pl_reset_init(void)
{
    XGpioPs_Config *Config;
    int Status;

#if defined(XPAR_XGPIOPS_0_DEVICE_ID)
    Config = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID);
#else
    /*
     * Newer SDT-based BSPs may use BASEADDR lookup.
     * If this does not compile in your environment, use the DEVICE_ID branch above.
     */
    Config = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_BASEADDR);
#endif

    if (Config == NULL)
    {
        xil_printf("ERROR: XGpioPs_LookupConfig failed\r\n");
        return -1;
    }

    Status = XGpioPs_CfgInitialize(&Gpio, Config, Config->BaseAddr);
    if (Status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpioPs_CfgInitialize failed: %d\r\n", Status);
        return -1;
    }

    XGpioPs_SetDirectionPin(&Gpio, PL_RESETN0_GPIO_PIN, 1);
    XGpioPs_SetOutputEnablePin(&Gpio, PL_RESETN0_GPIO_PIN, 1);

    return 0;
}

static void pl_reset_assert(void)
{
    XGpioPs_WritePin(&Gpio, PL_RESETN0_GPIO_PIN, 0);

    __asm__ volatile("dsb sy");
    __asm__ volatile("isb");

    usleep(10);
}

static void pl_reset_deassert(void)
{
    XGpioPs_WritePin(&Gpio, PL_RESETN0_GPIO_PIN, 1);

    __asm__ volatile("dsb sy");
    __asm__ volatile("isb");

    usleep(10);
}

int main(void)
{
    FATFS fatfs;
    FIL fil;
    FRESULT fr;
    UINT br;
    u32 total = 0U;

    static u8 io_buf[CHUNK_SIZE] __attribute__((aligned(64)));

    xil_printf("\r\nloader start\r\n");

    if (pl_reset_init() != 0)
    {
        xil_printf("ERROR: PL reset init failed\r\n");
        return -1;
    }

    /*
     * まず PL を reset に入れる。
     * pl_resetn0 は active-low なので 0 で reset assert。
     */
    pl_reset_assert();
    xil_printf("PL reset asserted\r\n");

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
     * CPU が DDR に書いた内容を PL から見えるようにする。
     */
    Xil_DCacheFlushRange((INTPTR)LOAD_ADDR, total);

    __asm__ volatile("dsb sy");
    __asm__ volatile("isb");

    xil_printf("loaded %u bytes to 0x%08lx\r\n",
               total, (unsigned long)LOAD_ADDR);
    xil_printf("D-cache flushed\r\n");

    /*
     * kernel.bin のロードと flush が終わったので PL reset 解除。
     * ここで PL 側 CPU が動き始める。
     */
    sleep(1);
    pl_reset_deassert();

    xil_printf("PL reset deasserted\r\n");
    xil_printf("loader done\r\n");

    while (1)
    {
        /* stop here */
    }

    return 0;
}