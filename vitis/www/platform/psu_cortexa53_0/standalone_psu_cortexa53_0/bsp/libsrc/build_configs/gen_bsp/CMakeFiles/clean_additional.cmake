# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/diskio.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/ff.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/ffconf.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/sleep.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xilffs.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xilffs_config.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xiltimer.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xtimer_config.h"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/lib/libxilffs.a"
  "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/lib/libxiltimer.a"
  )
endif()
