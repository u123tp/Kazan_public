# 2026-06-24T14:14:04.342735
import vitis

client = vitis.create_client()
client.set_workspace(path="www")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../../../vivado/project_1/design_1_wrapper.xsa",os = "standalone",cpu = "psu_cortexa53_0",domain_name = "standalone_psu_cortexa53_0",is_pmufw_req = True)

platform = client.get_component(name="platform")
status = platform.build()

comp = client.create_app_component(name="app_component",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_psu_cortexa53_0")

client.delete_component(name="app_component")

domain = platform.get_domain(name="standalone_psu_cortexa53_0")

status = domain.set_lib(lib_name="xilffs", path="/tools/Xilinx/Vitis/2024.2/data/embeddedsw/lib/sw_services/xilffs_v5_3")

status = platform.build()

comp = client.create_app_component(name="app_component",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_psu_cortexa53_0")

status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

vitis.dispose()

