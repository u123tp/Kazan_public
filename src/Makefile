
# ソースファイル
SRC_DIR := $(CURDIR)

SRC = $(shell find $(SRC_DIR) -type f -name '*.sv' ! -name 'vivado_*.sv') uart_device.cpp
TOPMODULE = Top

# 出力ファイル
IVERILOG_OUT = sim_iverilog.out
VERILATOR_OBJ_DIR = obj_dir
VERILATOR_EXEC = sim_verilator
LOG_DIR = log

# verilator用のオプション指定
# Verilator共通オプション
COMMON_VFLAGS = --cc --exe --build -j $(shell nproc) --threads 2 -O3
COMMON_VFLAGS += -CFLAGS "-O3 -march=native -mtune=native -DNDEBUG"
COMMON_VFLAGS += --x-assign fast --x-initial fast --noassert
COMMON_VFLAGS += -Wall
COMMON_VFLAGS += --Wno-UNDRIVEN
COMMON_VFLAGS += --Wno-BLKSEQ
COMMON_VFLAGS += --Wno-UNUSED
COMMON_VFLAGS += -I$(VERILATOR_ROOT)/include
COMMON_VFLAGS += -I$(SRC_DIR)
COMMON_VFLAGS += -DVERILATOR_COMPILE

# 通常シミュレーション用
VFLAGS = $(COMMON_VFLAGS)
VFLAGS += --top-module $(TOPMODULE)

DIVIDER_TOP := sim_divider_top
DIVIDER_OBJ_DIR := obj_dir_divider
DIVIDER_SRC := Divider.sv sim_divider_top.sv
DIVIDER_CPP := sim_divider.cpp

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


divider_test:
	verilator $(COMMON_VFLAGS) \
		--top-module $(DIVIDER_TOP) \
		--Mdir $(DIVIDER_OBJ_DIR) \
		$(DIVIDER_SRC) \
		$(DIVIDER_CPP)
	mkdir -p $(LOG_DIR)
	./$(DIVIDER_OBJ_DIR)/V$(DIVIDER_TOP) --print-success