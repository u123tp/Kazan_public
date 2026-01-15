// Tree-plru用の函数をまとめたもの.
// https://msyksphinz.hatenablog.com/entry/2024/09/23/040000
// すべて組み合わせ回路で実現されている.
//
// 下の図の*の部分がplru-treeの本体にあたる.
// 具体的には,第一層が[1:1],第二層が[3:2],第三層が[7:4]...
// それぞれの要素は1なら左,0なら右に進むといったようにbitで管理される.
// 下の図の#,つまりresult layerに最も古い(last recently used)なエントリーが示されている.
//
// アクセスする場合は各レイヤのビットに沿って進んで行けばいい.
// アクセス後に更新する場合は,result layerでそのアクセスしたエントリに至るまでの経路に存在したbitをすべて反転させる.
// これでそのエントリにアクセスしにくくなるのでpresudo last recently used となる.
//
// レイヤの数は$clog2(way_idx)+1で下の例だと4になる.下の図の()はidx_in_layer.
//
//         1          * 0st layer
//        / \         *
//      3(1)  2(0)        * 1st layer
//     /  |  |    \     *
// 7(3) 6(2) 5(1) 4(0)     * 2nd layer
//  / |  ..  ..  / \  *
// 7 6 ....      1 0  # result layer(way_idx)
//
// way_idxからどのように辿って行ったのかを解析するには
// 6 = 4'b110
// 5 = 4'b101
// となるように,レイヤ数-1をNとすると, layer k に対応するのは bit N-k である.
// 上の例から6と5では1,2層目でことなる進路をとったことがわかる.



interface TREE_PLRU_FUNC #(
    parameter int unsigned NUM_OF_WAYS = 4
);


  localparam int unsigned WAYS_IDX_WIDTH = $clog2(NUM_OF_WAYS);
  localparam int unsigned NUM_OF_LAYERS = $clog2(NUM_OF_WAYS);
  localparam int unsigned LAYER_IDX_WIDTH = $clog2(NUM_OF_LAYERS);

  localparam int unsigned IDX_IN_LAYER_WIDTH = NUM_OF_WAYS / 2;

  // 第0層がplru_tree[1:1],第1層がplru_tree[3:2],第2層がplru_tree[7:4]...
  // 第n層がplru_tree[2^(n+1)-1:2^n]になる.
  // これを,to_plru_tree_idx(n,idx_in_layer)で表す.
  // logic plru_tree[NUM_OF_WAYS];

  typedef struct packed {
    logic [LAYER_IDX_WIDTH-1:0] layer_idx;
    logic [IDX_IN_LAYER_WIDTH-1:0] idx_in_layer;
  } structured_idx_t;


  // (layer,そのレイヤ内でのインデックス) => plru_treeのインデックスに変換する.
  function automatic logic [WAYS_IDX_WIDTH-1:0] idx_structured_to_raw(
      input structured_idx_t structured_idx);
    logic [WAYS_IDX_WIDTH-1:0] plru_tree_idx = WAYS_IDX_WIDTH'(1<<structured_idx.layer_idx)+WAYS_IDX_WIDTH'(structured_idx.idx_in_layer);
    return plru_tree_idx;
  endfunction

  // 上記の逆関数.
  function automatic structured_idx_t idx_raw_to_structured(input logic [NUM_OF_WAYS-1:0] raw_idx);
  endfunction


  // 渡されたplru_tree_tmpから,最も昔に使用されたwayのインデックスを返す.
  function automatic logic [WAYS_IDX_WIDTH-1:0] search_oldest(
      input logic [NUM_OF_WAYS-1:0] plru_tree_tmp);
    logic [IDX_IN_LAYER_WIDTH-1:0] idx_in_layer_current = 0;
    logic [IDX_IN_LAYER_WIDTH-1:0] idx_in_layer_next = 0;
    structured_idx_t structured_idx;

    for (int unsigned current_layer = 0; current_layer < NUM_OF_LAYERS; current_layer++) begin
      idx_in_layer_current = idx_in_layer_next;
      structured_idx = '{
          layer_idx: LAYER_IDX_WIDTH'(current_layer),
          idx_in_layer: idx_in_layer_current
      };
      if (plru_tree_tmp[idx_structured_to_raw(structured_idx)]) begin
        // 1なら左に進む.
        idx_in_layer_next = 2 * idx_in_layer_current + 1;
      end else begin
        // 0なら右に進む.
        idx_in_layer_next = 2 * idx_in_layer_current;
      end
    end

    return WAYS_IDX_WIDTH'(idx_in_layer_next);

  endfunction


  // way_idxへアクセスしたことによる,plru_tree_tmpの更新を返す.
  function automatic logic [NUM_OF_WAYS-1:0] update_plru_tree(
      input logic [NUM_OF_WAYS-1:0] plru_tree_tmp, input logic [WAYS_IDX_WIDTH-1:0] way_idx);


    // plru_bool_log[i]はレイヤーiにおける経路上の1,0を記録.
    logic plru_bool_log[$clog2(NUM_OF_WAYS)];
    logic [NUM_OF_WAYS-1:0] plru_tree_new = plru_tree_tmp;

    // plru_bool_logの製作.
    for (int unsigned i = 0; i < NUM_OF_LAYERS; i++) begin
      plru_bool_log[i] = way_idx[NUM_OF_LAYERS-i];
    end

    begin
      logic [WAYS_IDX_WIDTH-1:0] raw_idx;
      structured_idx_t structured_idx;
      logic [IDX_IN_LAYER_WIDTH-1:0] idx_in_layer_current = 0;
      logic [IDX_IN_LAYER_WIDTH-1:0] idx_in_layer_next = 0;

      for (int unsigned current_layer = 0; current_layer < NUM_OF_LAYERS; current_layer++) begin
        idx_in_layer_current = idx_in_layer_next;
        //更新
        structured_idx = '{
            layer_idx: LAYER_IDX_WIDTH'(current_layer),
            idx_in_layer: IDX_IN_LAYER_WIDTH'(idx_in_layer_current)
        };
        raw_idx = idx_structured_to_raw(structured_idx);
        plru_tree_new[raw_idx] = ~plru_tree_new[raw_idx];
        if (plru_bool_log[current_layer]) begin
          // 1なら左に進む
          idx_in_layer_next = 2 * idx_in_layer_current + 1;
        end else begin
          // 0なら右に進む.
          idx_in_layer_next = 2 * idx_in_layer_current;
        end
      end
    end

    return plru_tree_new;

  endfunction


endinterface
