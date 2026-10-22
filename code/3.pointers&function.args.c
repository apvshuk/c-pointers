// we implement getint function here

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// getint: get next integer form input to *pn

int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch())) // skips white space
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); // it is not a number
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define SIZE 10

int main(void) {	
	int n, array[SIZE], getint(int *);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		printf("%d\n", array[n]);


	return 0;
}
