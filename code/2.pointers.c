#include<stdio.h>

int main(void) {
	int *a = 10;

	printf("%p\n", &a);
	printf("%d\n", *a);

	return 0;
}
