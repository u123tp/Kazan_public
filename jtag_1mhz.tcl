# jtagで書き込む周波数を1MHzにして接続する.

open_hw_manager
connect_hw_server

set t [lindex [get_hw_targets *XFL1Y4OCBCKGA*] 0]
current_hw_target $t

set_property PARAM.FREQUENCY 1000000 $t
open_hw_target $t