// csrレジスタ本体とCSR Unit を接続する

`include "CSR_PROPS.svh"
`include "COMMON_PARAMS.svh"



interface csr_csru_if ();
  import CSR_PROPS::*;
  import COMMON_PARAMS::*;

  typedef struct packed {
    logic valid;
    csr_name_e csr_name;
    logic [XLEN-1:0] data;
  } csr_write_req_t;
  csr_write_req_t write_req;

  typedef struct packed {
    logic valid;
    csr_name_e csr_name;
  } csr_read_req_t;
  csr_read_req_t read_req;

  typedef struct packed {
    logic valid;
    logic [XLEN-1:0] data;
  } csr_read_res_t;
  csr_read_res_t read_res;


  modport csru(input read_res, output read_req, write_req);
  modport csrrf(output read_res, input read_req, write_req);
endinterface
