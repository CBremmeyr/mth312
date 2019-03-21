/**
 * Macros
 */
#define FILE_NAME "affine-message.txt"

// Start and end of visable ASCII characters
#define CODE_START (32)
#define CODE_END   (126)


/**
 * Function declerations
 */
#ifndef MULT_INVERSE
#define MULT_INVERSE
    int multInverse(int mult, int mod);
#endif

#ifndef AFFINE_SHIFT_E
#define AFFINE_SHIFT_E
    int affineShiftE(int mult, int offset, const char *clearText, char *cipherText);
#endif

#ifndef AFFINE_SHIFT_D
#define AFFINE_SHIFT_D
    int affineShiftD(int mult, int offset, char *clearText, char *cipherText);
#endif

#ifndef SHIFT
#define SHIFT
    int shift(int val, const int mult, const int offset);
#endif

#ifndef MOD
#define MOD
    int mod(int val, int divisor);
#endif
