write_hw_ila_data -force /home/ishida/capture.ila [upload_hw_ila_data [get_hw_ilas hw_ila_1]]

set d [read_hw_ila_data /home/ishida/capture.ila]
display_hw_ila_data $d