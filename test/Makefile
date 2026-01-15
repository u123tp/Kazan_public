
# ソースファイル

SRC =  $(shell find $(SRC_DIR) -type f -name '*.sv')  testbench.cpp
TOPMODULE = Top

# 出力ファイル
IVERILOG_OUT = sim_iverilog.out
VERILATOR_OBJ_DIR = obj_dir
VERILATOR_EXEC = sim_verilator

# デフォルトのターゲット
# all: iverilog_run

### --- Icarus Verilog 用のターゲット --- ###
# # iverilog でコンパイル
# iverilog_compile:
# 	iverilog -g2012 -Wall -o $(IVERILOG_OUT) -s $(TOPMODULE) $(SRC)

# # iverilog でシミュレーション実行
# iverilog_run: iverilog_compile
# 	vvp $(IVERILOG_OUT)

# # iverilog のクリーンアップ
# iverilog_clean:
# 	rm -f $(IVERILOG_OUT) *.vcd

### --- Verilator 用のターゲット --- ###
# Verilator の Lint チェック
lint:
	verilator --lint-only --timing $(SRC)

# Verilator で C++ シミュレーションモデル生成
# -cc C++のアウトプットを得る
compile:
	verilator --cc --exe --build -j $(shell nproc) -Wall --Wno-UNDRIVEN -I$(VERILATOR_ROOT)/include \
	--Wno-UNUSED --top-module Top --trace --trace-params --trace-structs --trace-underscore $(SRC) 

# Verilator でシミュレーション実行
run: compile
	./$(VERILATOR_OBJ_DIR)/V$(TOPMODULE)
	gtkwave waveform.vcd

# Verilator のクリーンアップ
clean:
	rm -rf $(VERILATOR_OBJ_DIR) $(VERILATOR_EXEC)

# 全体のクリーンアップ
#clean: verilator_clean
