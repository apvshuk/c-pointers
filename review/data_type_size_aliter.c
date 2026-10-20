#include <stdio.h>

int main(void) {
	char a;
	int b;
	short c;
	long d;
	size_t e;

	// sizeof(..) returns in Bytes, so multiply by 8 to get bits
	// also, sizeof itself is size_t type.
	printf("%zu\n", sizeof(a)*8);
	printf("%zu\n", sizeof(b)*8);
	printf("%zu\n", sizeof(c)*8);	
	printf("%zu\n", sizeof(d)*8);
	printf("%zu\n", sizeof(e)*8);

	return 0;
}
