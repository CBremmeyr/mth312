module xor_cipher(input [7:0]pre,
				  input [7:0]key,
				  output [7:0]post
				  );

wire [7:0] post;

assign post = pre ^ key;

endmodule
