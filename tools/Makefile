CXX      := g++
CXXFLAGS := -std=gnu++17 -Wall -Wextra -Wpedantic

SRT_TARGET  := gen_srt_table
SRT_SRC     := gen_srt_table.cpp

INIT_TARGET := generate_pdtable_init
INIT_SRC    := generate_pdtable_init.cpp

PD_TABLE_HEX := pdtable.hex
PD_TABLE_SVH := pdtable_init.svh

TARGETS := $(SRT_TARGET) $(INIT_TARGET)

.PHONY: all run run-init generate clean debug

all: $(TARGETS)

$(SRT_TARGET): $(SRT_SRC)
	$(CXX) $(CXXFLAGS) -O2 $< -o $@

$(INIT_TARGET): $(INIT_SRC)
	$(CXX) $(CXXFLAGS) -O2 $< -o $@

# pdtable.hexを生成
run: $(SRT_TARGET)
	./$(SRT_TARGET)

# pdtable.hexからSystemVerilog初期化コードを生成
run-init: $(INIT_TARGET)
	./$(INIT_TARGET) $(PD_TABLE_HEX) $(PD_TABLE_SVH)

# pdtable.hexとpdtable_init.svhを順番に生成
generate: $(TARGETS)
	./$(SRT_TARGET)
	./$(INIT_TARGET) $(PD_TABLE_HEX) $(PD_TABLE_SVH)

debug: CXXFLAGS += -O0 -g
debug: clean $(TARGETS)

clean:
	rm -f $(TARGETS) $(PD_TABLE_HEX) $(PD_TABLE_SVH)