// dtlb, itlbへのアクセスに用いる
// tlbはなるべく先にリクエストされたものを優先して返す.
//

`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"

`include "CSR_PROPS.svh"


interface itlb_if #(
    parameter int unsigned NUM_OF_REQ = NUM_OF_REQ_TO_ITLB,
    parameter int unsigned NUM_OF_RES = NUM_OF_RES_FROM_ITLB
);
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import HART_DEFS::*;

  tlb_req_t req[NUM_OF_REQ];

  tlb_res_t res[NUM_OF_RES];

  logic stall_req_to_itlb;

  // ------------------------------------------
  // ready信号
  // ------------------------------------------
  // tlbがNUM_OF_REQ以上の空きを持たないときに0になる
  // logic ready;

  modport host(input req, output res, stall_req_to_itlb);
  modport client(output req, input res, stall_req_to_itlb);


endinterface
