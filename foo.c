#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <dest_file>\n", argv[0]);
		exit(1);
	}
	 printf("hello,world\n");
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen()");
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	printf("%ld\n", ftell(fp));
		

	
	exit(0);
}