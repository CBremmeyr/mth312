CC = gcc
FLAGS = -g -Wall
LIBS = affine-shift.h
DEPENDS = affine-shift-e.o affine-shift-d.o mult-inverse.o shift.o mod.o

all: $(DEPENDS) encipher decipher clean
build: $(DEPENDS) encipher decipher

test: $(DEPENDS) m

affine-shift-e.o: affine-shift-e.c
	$(CC) $(FLAGS) -c affine-shift-e.c

affine-shift-d.o: affine-shift-d.c
	$(CC) $(FLAGS) -c affine-shift-d.c

mod.o: mod.c
	$(CC) $(FLAGS) -c mod.c

mult-inverse.o: mult-inverse.c
	$(CC) $(FLAGS) -c mult-inverse.c

shift.o: shift.c
	$(CC) $(FLAGS) -c shift.c

encipher: encipher.c $(DEPENDS)
	$(CC) $(FLAGS)  -o encipher encipher.c $(DEPENDS)

decipher: decipher.c $(DEPENDS)
	$(CC) $(FLAGS) -o decipher decipher.c $(DEPENDS)

clean:
	rm -f *.o
