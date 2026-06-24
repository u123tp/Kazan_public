# PMOD pin assign
# Pin1  => HDA11    => A17 => H12
# Pin2  => HDA15    => B20 => B10
# Pin3  => HDA12    => D20 => E10
# Pin4  => HDA16_CC => B21 => E12
# Pin5  => HDA13    => D21 => D10
# Pin6  => HDA17    => B22 => D11
# Pin7                        C11
# Pin8  => HDA18    => C22 => B11
# Pin9  => GND
# Pin10 => GND
# Pin11 => VCC(5V)
# Pin12 => VCC(5V)

# PMODのピンアサインは以下のようになっている.
# https://www.amd.com/en/products/system-on-modules/kria/k26/k26c-commercial.html#tabs-dc35e3aa31-item-0c7f19fef9-tab
# ---------
# | 1 | 2 |
# | 3 | 4 |
# | 5 | 6 |
# | 7 | 8 |
# | 9 | 10|
# |11 | 12|
# ---------

# -------------------------------------------------------
# uart
# -------------------------------------------------------

# Pin1
set_property PACKAGE_PIN H12 [get_ports rts]
set_property IOSTANDARD LVCMOS33 [get_ports rts]
# Pin3
set_property PACKAGE_PIN E10 [get_ports cts]
set_property IOSTANDARD LVCMOS33 [get_ports cts]
# Pin5
set_property PACKAGE_PIN D10 [get_ports rxd]
set_property IOSTANDARD LVCMOS33 [get_ports rxd]
# Pin7
set_property PACKAGE_PIN C11 [get_ports txd]
set_property IOSTANDARD LVCMOS33 [get_ports txd]


# -------------------------------------------------------
# led,btn
# -------------------------------------------------------

# Pin2
set_property PACKAGE_PIN B10 [get_ports btn]
set_property IOSTANDARD LVCMOS33 [get_ports btn]
set_property PULLTYPE PULLUP [get_ports btn]
# Pin4
set_property PACKAGE_PIN E12 [get_ports led0]
set_property IOSTANDARD LVCMOS33 [get_ports led0]
# Pin6
set_property PACKAGE_PIN D11 [get_ports led1]
set_property IOSTANDARD LVCMOS33 [get_ports led1]
# Pin8
set_property PACKAGE_PIN B11 [get_ports led2]
set_property IOSTANDARD LVCMOS33 [get_ports led2]

