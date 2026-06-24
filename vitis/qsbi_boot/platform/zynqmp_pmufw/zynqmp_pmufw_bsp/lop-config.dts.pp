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
                    outdir = "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/zynqmp_pmufw/zynqmp_pmufw_bsp";
                    id = "module,baremetal_validate_comp_xlnx";
                    options = "psu_pmu_0 /tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_apps/zynqmp_pmufw/src /home/ishida/Documents/Kazan2/vitis/qsbi_boot/_ide/.wsdata/.repo.yaml";
                };

                lop_2 {
                    compatible = "system-device-tree-v1,lop,assist-v1";
                    node = "/";
                    outdir = "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/zynqmp_pmufw/zynqmp_pmufw_bsp";
                    id = "module,baremetal_validate_comp_xlnx";
                    options = "psu_pmu_0 /tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_services/xilfpga_v6_7/src /home/ishida/Documents/Kazan2/vitis/qsbi_boot/_ide/.wsdata/.repo.yaml";
                };

                lop_3 {
                    compatible = "system-device-tree-v1,lop,assist-v1";
                    node = "/";
                    outdir = "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/zynqmp_pmufw/zynqmp_pmufw_bsp";
                    id = "module,baremetal_validate_comp_xlnx";
                    options = "psu_pmu_0 /tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_services/xilsecure_v5_4/src /home/ishida/Documents/Kazan2/vitis/qsbi_boot/_ide/.wsdata/.repo.yaml";
                };

                lop_4 {
                    compatible = "system-device-tree-v1,lop,assist-v1";
                    node = "/";
                    outdir = "/home/ishida/Documents/Kazan2/vitis/qsbi_boot/platform/zynqmp_pmufw/zynqmp_pmufw_bsp";
                    id = "module,baremetal_validate_comp_xlnx";
                    options = "psu_pmu_0 /tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_services/xilskey_v7_6/src /home/ishida/Documents/Kazan2/vitis/qsbi_boot/_ide/.wsdata/.repo.yaml";
                };

        };
    };
