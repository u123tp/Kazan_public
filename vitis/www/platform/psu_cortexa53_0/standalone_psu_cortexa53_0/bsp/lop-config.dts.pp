#line 2 "lop-config.dts"
/dts-v1/;
/ {
        compatible = "system-device-tree-v1,lop";
        lops {
                lop_0 {
                        compatible = "system-device-tree-v1,lop,load";
                        load = "assists/baremetal_validate_comp_xlnx.py";
                };

                lop_1 {
                    compatible = "system-device-tree-v1,lop,assist-v1";
                    node = "/";
                    outdir = "/home/ishida/Documents/Kazan2/vitis/www/platform/psu_cortexa53_0/standalone_psu_cortexa53_0/bsp";
                    id = "module,baremetal_validate_comp_xlnx";
                    options = "psu_cortexa53_0 /tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_services/xilffs_v5_3/src /home/ishida/Documents/Kazan2/vitis/www/_ide/.wsdata/.repo.yaml";
                };

        };
    };
