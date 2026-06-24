

interface AXI_if ();


  // メインメモリにアクセスするための幅64bitのAXI
  // aw_は書き込みアドレス, w_は書き込みデータ,
  // b_は書き込みレスポンス, ar_は読み込みアドレス, r_は読み込みデータ.
  logic aruser;
  logic awuser;

  // リクエストのid. 返信時にはbidがこれに相当.
  logic [5:0] awid;
  logic [48:0] awaddr;
  logic [7:0] awlen;
  // 64bitなので, 3'b011になるはず.
  logic [2:0] awsize;
  // バースト時のアドレスの更新方法.
  logic [1:0] awburst;
  // 排他的アクセスの指定. 今回は使わないので0にする.
  logic awlock;
  logic [3:0] awcache;
  // 保護属性.
  logic [2:0] awprot;
  // awid, awaddrなどが有効かを示す信号.
  logic awvalid;
  logic awready;

  logic [63:0] wdata;
  logic [7:0] wstrb;
  logic wlast;
  logic wvalid;
  logic wready;

  logic [5:0] bid;
  logic [1:0] bresp;
  logic bvalid;
  logic bready;

  logic [5:0] arid;
  logic [48:0] araddr;
  logic [7:0] arlen;
  logic [2:0] arsize;
  logic [1:0] arburst;
  logic arlock;
  logic [3:0] arcache;
  logic [2:0] arprot;
  logic arvalid;
  logic arready;

  logic [5:0] rid;
  logic [63:0] rdata;
  logic [1:0] rresp;
  logic rlast;
  logic rvalid;
  logic rready;

  logic [3:0] awqos;
  logic [3:0] arqos;

  modport master(
      output awuser,
      output aruser,
      output awid,
      output awaddr,
      output awlen,
      output awsize,
      output awburst,
      output awlock,
      output awcache,
      output awprot,
      output awvalid,
      input awready,

      output wdata,
      output wstrb,
      output wlast,
      output wvalid,
      input wready,

      input bid,
      input bresp,
      input bvalid,
      output bready,

      output arid,
      output araddr,
      output arlen,
      output arsize,
      output arburst,
      output arlock,
      output arcache,
      output arprot,
      output arvalid,
      input arready,

      input rid,
      input rdata,
      input rresp,
      input rlast,
      input rvalid,
      output rready,

      output awqos,
      output arqos
  );

  modport slave(
      input awuser,
      input aruser,

      input awid,
      input awaddr,
      input awlen,
      input awsize,
      input awburst,
      input awlock,
      input awcache,
      input awprot,
      input awvalid,
      output awready,

      input wdata,
      input wstrb,
      input wlast,
      input wvalid,
      output wready,

      output bid,
      output bresp,
      output bvalid,
      input bready,

      input arid,
      input araddr,
      input arlen,
      input arsize,
      input arburst,
      input arlock,
      input arcache,
      input arprot,
      input arvalid,
      output arready,

      output rid,
      output rdata,
      output rresp,
      output rlast,
      output rvalid,
      input rready,
      input awqos,
      input arqos
  );


endinterface  //AXI_if

