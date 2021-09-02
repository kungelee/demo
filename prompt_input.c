#include <stdio.h>

void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int input_unsigned_int(const char *prompt,unsigned *u)
{
	printf("%s: ", prompt);
	fflush(stdout);
	return scanf("%u", u);
}


int main(void)
{
	
	unsigned n;
	while (input_unsigned_int("Enter an integer", &n) != 1) {
		fprintf(stderr, "%s\n", "Input error, try again!!");
		flushstdin();
	}
	
	printf("%u\n", n);
	return 0;
}
