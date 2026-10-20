#include <stdio.h>
#include <string.h>

int main(void) {
	char a[] = "Hello!";
	int i, tmp;

	int length = (int)strlen(a);
	printf("%d\n", length);

	size_t length_ = strlen(a);
	printf("%zu\n", length_);

	for (i = 0; i < ((length % 2 == 0) ? (length/2) : ((length+1)/2)); ++i) {
		tmp = a[i];
		a[i] = a[length - 1 - i];
		a[length - 1 - i] = tmp;
	}

	printf("%s\n", a);

	return 0;
}
