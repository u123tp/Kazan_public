`timescale 1ns/1ps

// VivadoでAdd moduleを行うときに,svでなく.vでないとできない.

module TopWrapper(
    // COMMON_PARAMS.svhのCLK_HZと合わせること.
    (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 clock_in CLK" *)
    (* X_INTERFACE_PARAMETER = "ASSOCIATED_BUSIF axi_dcache_port:axi_icache_port" *)
    input wire clock_in,

    // axi_icache_port
    output wire axi_icache_port_awuser,
    output wire axi_icache_port_aruser,

    output wire [5:0] axi_icache_port_awid,
    output wire [48:0] axi_icache_port_awaddr,
    output wire [7:0] axi_icache_port_awlen,
    output wire [2:0] axi_icache_port_awsize,
    output wire [1:0] axi_icache_port_awburst,
    output wire axi_icache_port_awlock,
    output wire [3:0] axi_icache_port_awcache,
    output wire [2:0] axi_icache_port_awprot,
    output wire axi_icache_port_awvalid,
    input  wire axi_icache_port_awready,

    output wire [127:0] axi_icache_port_wdata,
    output wire [15:0] axi_icache_port_wstrb,
    output wire axi_icache_port_wlast,
    output wire axi_icache_port_wvalid,
    input  wire axi_icache_port_wready,

    input  wire [5:0] axi_icache_port_bid,
    input  wire [1:0] axi_icache_port_bresp,
    input  wire axi_icache_port_bvalid,
    output wire axi_icache_port_bready,

    output wire [5:0] axi_icache_port_arid,
    output wire [48:0] axi_icache_port_araddr,
    output wire [7:0] axi_icache_port_arlen,
    output wire [2:0] axi_icache_port_arsize,
    output wire [1:0] axi_icache_port_arburst,
    output wire axi_icache_port_arlock,
    output wire [3:0] axi_icache_port_arcache,
    output wire [2:0] axi_icache_port_arprot,
    output wire axi_icache_port_arvalid,
    input  wire axi_icache_port_arready,

    input  wire [5:0] axi_icache_port_rid,
    input  wire [127:0] axi_icache_port_rdata,
    input  wire [1:0] axi_icache_port_rresp,
    input  wire axi_icache_port_rlast,
    input  wire axi_icache_port_rvalid,
    output wire axi_icache_port_rready,

    output wire [3:0] axi_icache_port_awqos,
    output wire [3:0] axi_icache_port_arqos,

    // axi_dcache_port
    output wire axi_dcache_port_awuser,
    output wire axi_dcache_port_aruser,

    output wire [5:0] axi_dcache_port_awid,
    output wire [48:0] axi_dcache_port_awaddr,
    output wire [7:0] axi_dcache_port_awlen,
    output wire [2:0] axi_dcache_port_awsize,
    output wire [1:0] axi_dcache_port_awburst,
    output wire axi_dcache_port_awlock,
    output wire [3:0] axi_dcache_port_awcache,
    output wire [2:0] axi_dcache_port_awprot,
    output wire axi_dcache_port_awvalid,
    input  wire axi_dcache_port_awready,

    output wire [63:0] axi_dcache_port_wdata,
    output wire [7:0] axi_dcache_port_wstrb,
    output wire axi_dcache_port_wlast,
    output wire axi_dcache_port_wvalid,
    input  wire axi_dcache_port_wready,

    input  wire [5:0] axi_dcache_port_bid,
    input  wire [1:0] axi_dcache_port_bresp,
    input  wire axi_dcache_port_bvalid,
    output wire axi_dcache_port_bready,

    output wire [5:0] axi_dcache_port_arid,
    output wire [48:0] axi_dcache_port_araddr,
    output wire [7:0] axi_dcache_port_arlen,
    output wire [2:0] axi_dcache_port_arsize,
    output wire [1:0] axi_dcache_port_arburst,
    output wire axi_dcache_port_arlock,
    output wire [3:0] axi_dcache_port_arcache,
    output wire [2:0] axi_dcache_port_arprot,
    output wire axi_dcache_port_arvalid,
    input  wire axi_dcache_port_arready,

    input  wire [5:0] axi_dcache_port_rid,
    input  wire [63:0] axi_dcache_port_rdata,
    input  wire [1:0] axi_dcache_port_rresp,
    input  wire axi_dcache_port_rlast,
    input  wire axi_dcache_port_rvalid,
    output wire axi_dcache_port_rready,

    output wire [3:0] axi_dcache_port_awqos,
    output wire [3:0] axi_dcache_port_arqos,

     // pmodのuart用入出力
    output wire rts,
    input wire cts,
    input wire rxd,
    output wire txd,

    // プルアップのアクティブローなボタンをrst用として扱う.
    input wire resetn_in2,

    // デバッグ用led
    output wire led0,
    output wire led1,
    output wire led2
);



wire reset_in;
wire resetn_in2_clean;

// assign reset_in = reset_in0 | reset_in1 | !resetn_in2_clean;
assign reset_in =  !resetn_in2_clean;


    resetn_release_debounce rrd(
        .clock(clock_in),
        .resetn_raw(resetn_in2),
        .resetn_clean(resetn_in2_clean)
    );



    // VIVADO_COMPILEがVERILATORでは効いていないので,エラーが出るが無視.
    Top top(

        .axi_icache_port_awuser(axi_icache_port_awuser),
        .axi_icache_port_aruser(axi_icache_port_aruser),

        .axi_icache_port_awid(axi_icache_port_awid),
        .axi_icache_port_awaddr(axi_icache_port_awaddr),
        .axi_icache_port_awlen(axi_icache_port_awlen),
        .axi_icache_port_awsize(axi_icache_port_awsize),
        .axi_icache_port_awburst(axi_icache_port_awburst),
        .axi_icache_port_awlock(axi_icache_port_awlock),
        .axi_icache_port_awcache(axi_icache_port_awcache),
        .axi_icache_port_awprot(axi_icache_port_awprot),
        .axi_icache_port_awvalid(axi_icache_port_awvalid),
        .axi_icache_port_awready(axi_icache_port_awready),

        .axi_icache_port_wdata(axi_icache_port_wdata),
        .axi_icache_port_wstrb(axi_icache_port_wstrb),
        .axi_icache_port_wlast(axi_icache_port_wlast),
        .axi_icache_port_wvalid(axi_icache_port_wvalid),
        .axi_icache_port_wready(axi_icache_port_wready),

        .axi_icache_port_bid(axi_icache_port_bid),
        .axi_icache_port_bresp(axi_icache_port_bresp),
        .axi_icache_port_bvalid(axi_icache_port_bvalid),
        .axi_icache_port_bready(axi_icache_port_bready),

        .axi_icache_port_arid(axi_icache_port_arid),
        .axi_icache_port_araddr(axi_icache_port_araddr),
        .axi_icache_port_arlen(axi_icache_port_arlen),
        .axi_icache_port_arsize(axi_icache_port_arsize),
        .axi_icache_port_arburst(axi_icache_port_arburst),
        .axi_icache_port_arlock(axi_icache_port_arlock),
        .axi_icache_port_arcache(axi_icache_port_arcache),
        .axi_icache_port_arprot(axi_icache_port_arprot),
        .axi_icache_port_arvalid(axi_icache_port_arvalid),
        .axi_icache_port_arready(axi_icache_port_arready),

        .axi_icache_port_rid(axi_icache_port_rid),
        .axi_icache_port_rdata(axi_icache_port_rdata),
        .axi_icache_port_rresp(axi_icache_port_rresp),
        .axi_icache_port_rlast(axi_icache_port_rlast),
        .axi_icache_port_rvalid(axi_icache_port_rvalid),
        .axi_icache_port_rready(axi_icache_port_rready),

        .axi_icache_port_awqos(axi_icache_port_awqos),
        .axi_icache_port_arqos(axi_icache_port_arqos),

        .axi_dcache_port_awuser(axi_dcache_port_awuser),
        .axi_dcache_port_aruser(axi_dcache_port_aruser),

        .axi_dcache_port_awid(axi_dcache_port_awid),
        .axi_dcache_port_awaddr(axi_dcache_port_awaddr),
        .axi_dcache_port_awlen(axi_dcache_port_awlen),
        .axi_dcache_port_awsize(axi_dcache_port_awsize),
        .axi_dcache_port_awburst(axi_dcache_port_awburst),
        .axi_dcache_port_awlock(axi_dcache_port_awlock),
        .axi_dcache_port_awcache(axi_dcache_port_awcache),
        .axi_dcache_port_awprot(axi_dcache_port_awprot),
        .axi_dcache_port_awvalid(axi_dcache_port_awvalid),
        .axi_dcache_port_awready(axi_dcache_port_awready),

        .axi_dcache_port_wdata(axi_dcache_port_wdata),
        .axi_dcache_port_wstrb(axi_dcache_port_wstrb),
        .axi_dcache_port_wlast(axi_dcache_port_wlast),
        .axi_dcache_port_wvalid(axi_dcache_port_wvalid),
        .axi_dcache_port_wready(axi_dcache_port_wready),

        .axi_dcache_port_bid(axi_dcache_port_bid),
        .axi_dcache_port_bresp(axi_dcache_port_bresp),
        .axi_dcache_port_bvalid(axi_dcache_port_bvalid),
        .axi_dcache_port_bready(axi_dcache_port_bready),

        .axi_dcache_port_arid(axi_dcache_port_arid),
        .axi_dcache_port_araddr(axi_dcache_port_araddr),
        .axi_dcache_port_arlen(axi_dcache_port_arlen),
        .axi_dcache_port_arsize(axi_dcache_port_arsize),
        .axi_dcache_port_arburst(axi_dcache_port_arburst),
        .axi_dcache_port_arlock(axi_dcache_port_arlock),
        .axi_dcache_port_arcache(axi_dcache_port_arcache),
        .axi_dcache_port_arprot(axi_dcache_port_arprot),
        .axi_dcache_port_arvalid(axi_dcache_port_arvalid),
        .axi_dcache_port_arready(axi_dcache_port_arready),

        .axi_dcache_port_rid(axi_dcache_port_rid),
        .axi_dcache_port_rdata(axi_dcache_port_rdata),
        .axi_dcache_port_rresp(axi_dcache_port_rresp),
        .axi_dcache_port_rlast(axi_dcache_port_rlast),
        .axi_dcache_port_rvalid(axi_dcache_port_rvalid),
        .axi_dcache_port_rready(axi_dcache_port_rready),

        .axi_dcache_port_awqos(axi_dcache_port_awqos),
        .axi_dcache_port_arqos(axi_dcache_port_arqos),
        


        .clock_in(clock_in),
        .reset_in(reset_in),

        .rts(rts),
        .cts(cts),
        .rxd(rxd),
        .txd(txd),

        .led0(led0),
        .led1(led1),
        .led2(led2)
        
    );

endmodule
