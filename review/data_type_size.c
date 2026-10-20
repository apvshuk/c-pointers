#include <stdio.h>

#define TYPE_SIZE_BYTES(var) ({ \
    int bits = 0; \
    __typeof__(var) temp = 1; \
    \
    while (temp != 0) { \
        temp <<= 1; \
        bits++; \
    } \
    \
    bits; \
})

int main(void) {
	char a;
	int b;
	short c;
	long d;
	size_t e;

	printf("Bit Size of CHAR: %d\n", TYPE_SIZE_BYTES(a));
	printf("Bit Size of INT: %d\n", TYPE_SIZE_BYTES(b));
	printf("Bit Size of SHORT: %d\n", TYPE_SIZE_BYTES(c));
	printf("Bit Size of LONG: %d\n", TYPE_SIZE_BYTES(d));
	printf("Bit Size of SIZE_T: %d\n", TYPE_SIZE_BYTES(e));
	return 0;
}

// How does this work:
// Suppose variable "a" is 4-bit. if a = 1 (base 10) then a = 0001 (base 2).
// We do a = a << 1. Which makes a = 0010 (left shift once)
// a = 0100 (left shift twice)
// a = 1000 (left shift thrice)
// a = 0000 (left shift fourth time). Now a = 0. For making it zero we had to shift it 4 times => four bits totally => variable is 4-bit.

