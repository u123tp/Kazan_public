// axi4 stream の定義

interface AXI_stream_if ();
  // rgb
  logic [23:0] tdata;
  logic tdest;
  logic tid;
  logic [5:0] tkeep;
  logic tlast;
  logic tready;
  logic [5:0] tstrb;
  logic tuser;
  logic tvalid;

  modport master(
      output tdata,
      output tdest,
      output tid,
      output tkeep,
      output tlast,
      input tready,
      output tstrb,
      output tuser,
      output tvalid
  );
  modport slave(
      input tdata,
      input tdest,
      input tid,
      input tkeep,
      input tlast,
      output tready,
      input tstrb,
      input tuser,
      input tvalid
  );
endinterface
