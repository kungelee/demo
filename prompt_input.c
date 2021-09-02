#include <stdio.h>

void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int get_unsigned_int(const char *prompt,unsigned *u)
{
	printf("%s: ", prompt);
	fflush(stdout);
	int ret = scanf("%u", u);
	return ret;
}


int main(void)
{
	
	unsigned n;
	while (get_unsigned_int("Enter an integer", &n) != 1) {
		fprintf(stderr, "%s\n", "Input error, try again!!");
		flushstdin();
	}
	
	printf("%u\n", n);
	return 0;
}