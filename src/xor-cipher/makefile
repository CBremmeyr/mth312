SYNTH = iverilog
DEPENDS = xor_cipher_tb.v xor_cipher.v

all: xor_cipher_tb.o
default: all

xor_cipher_tb.o: $(DEPENDS)
	$(SYNTH) -o xor_cipher_tb.o -c module_list.txt
