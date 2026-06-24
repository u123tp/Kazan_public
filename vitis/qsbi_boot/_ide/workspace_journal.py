# 2026-06-24T21:09:49.857721
import vitis

client = vitis.create_client()
client.set_workspace(path="qsbi_boot")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../../../vivado/project_1/design_1_wrapper.xsa",os = "standalone",cpu = "psu_cortexa53_0",domain_name = "standalone_psu_cortexa53_0",is_pmufw_req = True)

vitis.dispose()

