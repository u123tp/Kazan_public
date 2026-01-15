
module Top (
    input logic clock,
    input logic reset
);

  logic [10:0] a;
  always_comb begin
    a = 11'(signed'(1'b1));
    // 結果は 11'b11111111111 になる.
    $display("a=%0b", a);
  end

endmodule
