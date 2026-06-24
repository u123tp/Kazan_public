# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/sleep.h"
  "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xiltimer.h"
  "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/include/xtimer_config.h"
  "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp/lib/libxiltimer.a"
  )
endif()
