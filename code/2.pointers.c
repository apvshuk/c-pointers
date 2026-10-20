#include<stdio.h>

int main(void) {
	int x = 0, y;
	int *p;

	p = &x; // p points to x

	x = 10; // change x normally
	printf("%d\n", x);
	*p = 11; // or change x using pointer
	printf("%d\n", x);
	
	p = &y; // p points to y now
	*p = 100; // change y using pointer
	printf("%d\n", y);

	return 0;
}
