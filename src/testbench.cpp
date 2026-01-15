#include <stdlib.h>
#include <iostream>
#include <verilated.h>
// #include <verilated_vcd_c.h>
#include "VTop.h" // トップモジュール
// #include "VTop___024unit.h"

#define INITIALIZE_TIME 10
#define MAX_SIM_TIME 10000000
#define DUMP_TIME 10000
vluint64_t sim_time = 0;

int main(int argc, char **argv)
{
  Verilated::commandArgs(argc, argv);

  // https://itsembedded.com/dhd/verilator_1/
  // モジュールを作成し,波形出力をするようにする.
  VTop *top = new VTop;
  // Verilated::traceEverOn(true);
  // VerilatedVcdC *m_trace = new VerilatedVcdC;
  // top->trace(m_trace, 99);
  // m_trace->open("waveform.vcd");

  top->clock = 0;
  top->reset = 0;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  // 初期化
  top->clock = 0;
  top->reset = 1;
  top->inv_dump_sig = 0;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  // リセットのネゲート
  top->clock = 0;
  top->reset = 0;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  // シミュレーションループ
  while (1)
  {
    top->clock ^= 1;
    top->eval();
    // m_trace->dump(sim_time);
    sim_time++;
  }

  // メモリダンプ
  top->inv_dump_sig = 1;
  top->clock ^= 1;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  top->inv_dump_sig = 1;
  top->clock ^= 1;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  top->inv_dump_sig = 0;
  top->clock ^= 1;
  top->eval();
  // m_trace->dump(sim_time);
  sim_time++;

  while (sim_time < MAX_SIM_TIME + DUMP_TIME)
  {
    top->clock ^= 1;
    top->eval();
    // m_trace->dump(sim_time);
    sim_time++;
  }

  // 終了処理
  // m_trace->close();
  top->final();
  delete top;
  // exit(EXIT_SUCCESS);
  return 0;
}
