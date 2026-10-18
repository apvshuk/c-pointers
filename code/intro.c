#include <stdio.h>

void change_value(int *nb) {
	*nb = 100;
}

int main(void) {
	int nb = 42;

	change_value(&nb);
	printf("%d", nb);
	return 0;
}
