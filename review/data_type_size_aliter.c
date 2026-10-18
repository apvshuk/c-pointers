#include <stdio.h>

int main(void) {
	char a;
	int b;
	short c;
	long d;

	printf("%zu\n", sizeof(a)*8);
	printf("%zu\n", sizeof(b)*8);
	printf("%zu\n", sizeof(c)*8);
	printf("%zu\n", sizeof(d)*8);

	return 0;
}
