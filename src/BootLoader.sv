// BootLoader
// 一応メモリとして作る.
// 役割は0x8000_0000に飛ばすこと.
// req_in,res_outともに,icacheの代わりに使用する.
// bootloader自体の書き換えは行わないことを想定しているので,lsuとは接続しない.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"

module BootLoader
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
(
    input logic clock,
    input logic reset,

    input  bootloader_req_t req_in,
    output bootloader_res_t res_out
);

  // 8KiBのブートローダを用意する.
  logic [31:0] mem[1024];

  // 本来はこのbootloaderを用いる必要があるが,
  // 面倒なのでとりあえずは0x8000_0000から始める.
  // TODO: 後で実装.
  

  always_ff @(posedge clock, posedge reset) begin

  end

endmodule
