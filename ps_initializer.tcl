connect
targets
targets -set -nocase -filter {name =~ "PSU"}

source /home/ishida/Documents/Kazan_tmp-master/vivado/project_1/project_1.gen/sources_1/bd/design_1/ip/design_1_zynq_ultra_ps_e_0_0/psu_init.tcl

psu_init
after 1000

psu_ps_pl_isolation_removal
after 1000

psu_ps_pl_reset_config
after 1000

psu_post_config
after 1000
