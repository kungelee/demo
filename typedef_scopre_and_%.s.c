#include<stdio.h>
#include <stdlib.h>
/*2021-12-27 01:19:22*/
int main(void)
{
	{
		typedef char const *cc;    /*block scope*/
		cc hi = "hello,world";
		printf("%.*s\n", 5, hi);  /*outpus: hello*/
	}
	
	return EXIT_SUCCESS;
}
