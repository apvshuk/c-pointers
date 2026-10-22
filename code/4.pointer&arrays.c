#include <stdio.h>

// strlen: return length of string s
int strlen_(char *);


int main(void) {
	char a[] = "Hello My name is Apoorva";

	printf("%d", strlen_(&a[3]));

	return 0;
}

int strlen_(char *s) {
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
