#include "affine-shift.h"

int shift(int val, const int mult, const int offset) {
    return (mult * val + offset);
}