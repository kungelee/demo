#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n; 
	scanf("%d", &n);
	//int * a = malloc(n * (sizeof *a));
	//int * a = malloc(n * sizeof(*a));
	int *a = malloc(sizeof(int[n]));
	for (int i = 0; i < n; i++)
		a[i] = i;
	
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);
	free(a);

	return 0;
}