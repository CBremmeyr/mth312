CC = gcc -g
LIBS = affine-shift.h
DEPENDS = affine-shift-e.o affine-shift-d.o mult-inverse.o shift.o mod.o

all: $(DEPENDS) encipher decipher clean

affine-shift-e.o: affine-shift-e.c
	$(CC) -c affine-shift-e.c

affine-shift-d.o: affine-shift-d.c
	$(CC) -c affine-shift-d.c

mod.o: mod.c
	$(CC) -c mod.c

mult-inverse.o: mult-inverse.c
	$(CC) -c mult-inverse.c

shift.o: shift.c
	$(CC) -c shift.c

encipher: encipher.c $(DEPENDS)
	$(CC) -o encipher encipher.c $(DEPENDS)

decipher: decipher.c $(DEPENDS)
	$(CC) -o decipher decipher.c $(DEPENDS)

clean:
	rm -f *.o
