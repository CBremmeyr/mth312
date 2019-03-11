CC = gcc
BUILD_DIR = build/
BUILD_LIST = affine-shift.o

all: $(BUILD_LIST)
	cd build/

# Compile Affine Shift
affine-shift.o: affine-shift.c
	gcc -o affine-shift.o ../src/affine-shift/affine-shift.c

