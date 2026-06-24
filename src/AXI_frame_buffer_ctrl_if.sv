interface AXI_frame_buffer_ctrl_if ();

  logic [6:0] araddr;
  logic arready;
  logic arvalid;

  logic [6:0] awaddr;
  logic awready;
  logic awvalid;

  logic bready;
  logic [1:0] bresp;
  logic bvalid;

  logic [31:0] rdata;
  logic rready;
  logic [1:0] rresp;
  logic rvalid;

  logic [31:0] wdata;
  logic wready;
  logic [3:0] wstrb;
  logic wvalid;

  modport master(
      output araddr,
      input arready,
      output arvalid,

      output awaddr,
      input awready,
      output awvalid,

      output bready,
      input bresp,
      input bvalid,

      input rdata,
      output rready,
      input rresp,
      input rvalid,

      output wdata,
      input wready,
      output wstrb,
      output wvalid
  );

  modport slave(
      input araddr,
      output arready,
      input arvalid,

      input awaddr,
      output awready,
      input awvalid,

      input bready,
      output bresp,
      output bvalid,

      output rdata,
      input rready,
      output rresp,
      output rvalid,

      input wdata,
      output wready,
      input wstrb,
      input wvalid
  );

endinterface
