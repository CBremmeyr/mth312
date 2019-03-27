#!/bin/bash

BASE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
SRC_DIR="$BASE_DIR/src"

# Make program directory structure
cd $BASE_DIR
mkdir programs
cd programs
mkdir affine-shift
cd $BASE_DIR

# Build Affine shift
cd $SRC_DIR/affine-shift/
make build all
mv decipher encipher $BASE_DIR/programs/affine-shift/
cd $BASE_DIR

cd $BASE_DIR

