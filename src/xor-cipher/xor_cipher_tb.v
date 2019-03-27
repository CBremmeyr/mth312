`timescale 1ns / 1ps

module xor_cipher_tb;

reg [7:0]pre;
reg [7:0]key;
wire [7:0]post;

xor_cipher c(pre,key, post);

initial begin

	$dumpfile("xor_tb_output.vcd");
	$dumpvars(0, xor_cipher_tb);

	pre <= 8'h00;
	key <= 8'hA5;
end

always #5 pre <= pre + 1'b1;

initial #1000 $finish;

endmodule

