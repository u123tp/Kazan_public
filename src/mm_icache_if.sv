
`timescale 1ns / 1ps
// 128bit単位でやり取りする.

`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"

`include "COMMON_PARAMS.svh"


interface mm_icache_if #(
    parameter int unsigned NUM_OF_REQS = 4,
    parameter int unsigned NUM_OF_RES  = 4
) ();
  import HART_DEFS::*;
  import COMMON_PARAMS::*;

  // 次のサイクルでreqの受け入れが可能か.
  logic ready;

  mm_req128_t req[NUM_OF_REQS];

  // メインメモリが複数のreqに対して1サイクルで返答を返すことは無い.
  // つまり,1サイクルではこのresのうちどれかのみに返される.
  // res_idxはreq_idxと対応している.
  mm_res128_t res[NUM_OF_RES];


  modport client(output req, input res, ready);
  modport host(input req, output res, ready);

endinterface

