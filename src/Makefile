
# ソースファイル
SRC_DIR := $(CURDIR)

SRC = $(shell find $(SRC_DIR) -type f -name '*.sv') uart_device.cpp
TOPMODULE = Top

# 出力ファイル
IVERILOG_OUT = sim_iverilog.out
VERILATOR_OBJ_DIR = obj_dir
VERILATOR_EXEC = sim_verilator
LOG_DIR = log

# verilator用のオプション指定
VFLAGS = --cc --exe --build -j $(shell nproc) --threads 3 -O3
VFLAGS += -CFLAGS "-O3 -march=native -mtune=native -DNDEBUG"
VFLAGS += --x-assign fast --x-initial fast --noassert
VFLAGS += -Wall --Wno-UNDRIVEN --Wno-BLKSEQ -I$(VERILATOR_ROOT)/include --Wno-UNUSED
VFLAGS += --top-module Top

VPROFFLAGS = --cc --exe --build -j $(shell nproc) --threads 1 -O3
VPROFFLAGS += -CFLAGS "-O3 -march=native -mtune=native -DNDEBUG"
VPROFFLAGS += --x-assign fast --x-initial fast --noassert
VPROFFLAGS += -Wall --Wno-UNDRIVEN --Wno-BLKSEQ -I$(VERILATOR_ROOT)/include --Wno-UNUSED
VPROFFLAGS += --top-module Top
VPROFFLAGS += --prof-cfuncs

# trace
# VFLAGS += --trace --trace-params --trace-structs --trace-underscore


# Verilator の Lint チェック
lint:
	verilator --lint-only --timing $(SRC)

# 
compile:
	verilator $(VFLAGS) $(SRC) testbench.cpp

# Verilator でシミュレーション実行
run: compile
	mkdir -p $(LOG_DIR)
	./$(VERILATOR_OBJ_DIR)/V$(TOPMODULE)

compile_prof:
	verilator $(VPROFFLAGS) $(SRC) testbench_prof.cpp

run_prof:
	mkdir -p $(LOG_DIR)
	./$(VERILATOR_OBJ_DIR)/V$(TOPMODULE)
	gprof $(VERILATOR_OBJ_DIR)/VTop gmon.out > gprof.log
	verilator_profcfunc gprof.log > profcfunc.log

wave: compile
	./$(VERILATOR_OBJ_DIR)/V$(TOPMODULE)
	gtkwave waveform.vcd

clean:
	rm -rf $(VERILATOR_OBJ_DIR) $(VERILATOR_EXEC) $(LOG_DIR) waveform.vcd gprof.log profcfunc.log

