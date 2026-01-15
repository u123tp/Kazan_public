# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VTop.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  VTop_vm_classes_0 \
  VTop_vm_classes_1 \
  VTop_vm_classes_2 \
  VTop_vm_classes_3 \
  VTop_vm_classes_4 \
  VTop_vm_classes_5 \
  VTop_vm_classes_6 \
  VTop_vm_classes_7 \
  VTop_vm_classes_8 \
  VTop_vm_classes_9 \
  VTop_vm_classes_10 \
  VTop_vm_classes_11 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  VTop_vm_classes_Slow_0 \
  VTop_vm_classes_Slow_1 \
  VTop_vm_classes_Slow_2 \
  VTop_vm_classes_Slow_3 \
  VTop_vm_classes_Slow_4 \
  VTop_vm_classes_Slow_5 \
  VTop_vm_classes_Slow_6 \
  VTop___024root__DepSet_hc590b6dd__21__Slow \
  VTop___024root__DepSet_hc590b6dd__22__Slow \
  VTop___024root__DepSet_hc590b6dd__23__Slow \
  VTop___024root__DepSet_hc590b6dd__24__Slow \
  VTop___024root__DepSet_hc590b6dd__25__Slow \
  VTop_vm_classes_Slow_7 \
  VTop_vm_classes_Slow_8 \
  VTop___024root__DepSet_hc590b6dd__30__Slow \
  VTop___024root__DepSet_hc590b6dd__31__Slow \
  VTop___024root__DepSet_hc590b6dd__32__Slow \
  VTop___024root__DepSet_hc590b6dd__33__Slow \
  VTop_vm_classes_Slow_9 \
  VTop_vm_classes_Slow_10 \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  VTop__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  VTop__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_dpi \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
