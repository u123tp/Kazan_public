connect

targets -set -nocase -filter {name =~ "PSU"}

source /home/ishida/Documents/Kazan2/vivado/project_1/project_1.gen/sources_1/bd/design_1/ip/design_1_zynq_ultra_ps_e_0_0/psu_init.tcl

psu_init
after 1000

psu_ps_pl_isolation_removal
after 1000

psu_ps_pl_reset_config
after 1000

psu_post_config
after 1000

# A53 #0 を選ぶ。ここを1行で入力する
targets -set -nocase -filter {name =~ "Cortex-A53 #0"}

# 念のため現在target確認
targets

# A53を停止/リセット
stop
after 1000
rst -processor -clear-registers
after 1000

# ELFをロード
dow /home/ishida/Documents/Kazan2/vitis/www/app_component/build/app_component.elf

# 実行開始
con