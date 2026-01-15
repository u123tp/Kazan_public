// 使ってない物理レジスタを管理するフリーリスト.
//
// 初期状態では論理レジスタx4は物理レジスタp4に対応する(x?はp?に対応する)
//
// x0はrenamerの方で判別してfreelistに入力しない.
//
// alからはコミットした命令のprdがfreelistに返される.
// freelistから取り出されるのは、renamerで物理アドレスに変換する時.
//
// flushしたら時にどのようにしてin flightの命令から、貸し出した物理アドレスを取り戻すのか。
// ratとrratみたいな感じのものを作るのが良いのかも知れない。これをrfl(retirement free list)と呼称する。
// rflは、命令の変換時にflから出ていった物理レジスタを削除しない。
// つまり,flは名前変換のときにrdのためのレジスタを貸して,コミットの時に,previou physical registerを返してもらうが,
// rflは名前変換でレジスタを貸さず,コミットの時にその命令のrdのレジスタを貸して(削除して),previous physical registerを返してもらう.
//

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module FreeList
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,


    // Renamerに渡す使用可能な物理レジスタ.
    output logic [$clog2(NUM_OF_PHYREGS)-1:0] available_prd[NUM_OF_FETCH],

    // available_prdの内,使用したものがrenamerから伝達される.
    input logic prd_used[NUM_OF_FETCH],

    // コミットした命令の持っているprevious physical registerとphysical register
    input logic committed_rd_valid[NUM_OF_GRADUATE],
    input logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_phyreg[NUM_OF_GRADUATE],
    input logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_prev_phyreg[NUM_OF_GRADUATE],

    // mispredictionや例外発生時
    input logic flush_in
);


  localparam int unsigned FL_SIZE = NUM_OF_PHYREGS;
  localparam int unsigned FL_IDX_WIDTH = $clog2(FL_SIZE);

  // 現在使用可能なものを1,不可能なものを0とする
  logic fl[FL_SIZE];
  logic fl_next[FL_SIZE];

  logic rfl[FL_SIZE];
  logic rfl_next[FL_SIZE];


  // always_ffの中のforの中でノンブロッキング代入できないからfl_initをalways_combで作成.
  logic fl_init[FL_SIZE];


  // 初期化用のal_initの作成
  // 初期状態ではx0=>p0,x1=>p1,...x31=>p31となっているので,フリーリストに入っているのはp32~p95の64エントリ.
  always_comb begin
    for (int unsigned i = 0; i < FL_SIZE; i++) begin
      if (i < NUM_OF_LOGREGS) begin
        fl_init[i] = 0;
      end else begin
        fl_init[i] = 1;
      end
    end
  end

  // flの先頭4つを使用可能な物理レジスタとして提示
  always_comb begin
    int unsigned propose_counter = 0;
    available_prd = '{default: 0};

    for (int unsigned i = 1; i < FL_SIZE; i++) begin
      if (fl[i] && propose_counter < NUM_OF_FETCH) begin
        available_prd[propose_counter] = $clog2(NUM_OF_PHYREGS)'(i);
        propose_counter++;
      end
    end
  end


  always_comb begin
    fl_next  = fl;

    rfl_next = rfl;

    // flの先頭の４つの内,使用したものをフリーでないと記録.
    begin
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (prd_used[i]) begin
          fl_next[available_prd[i]] = 0;
        end
      end
    end

    // コミットされた命令でfl,rflを更新.
    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      if (committed_rd_valid[i]) begin
        //flの更新.
        fl_next[committed_prev_phyreg[i]] = 1;
        // rflの更新
        rfl_next[committed_prev_phyreg[i]] = 1;
        rfl_next[committed_phyreg[i]] = 0;
      end
    end

  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      fl  <= fl_init;
      rfl <= fl_init;
    end else if (flush_in) begin
      fl  <= rfl_next;
      rfl <= rfl_next;
    end else begin
      fl  <= fl_next;
      rfl <= rfl_next;
    end
  end



endmodule
