#include <stdio.h>

int isprime(int n)
{
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0)
			break;
	}

	return i == n;
}

int main(void)
{
	int x;
	for (x = 1; x <= 1000; x++) {
		static int count = 0;
		if (isprime(x)) {
			if (count % 10 == 0 && count != 0)
				printf("\n");
			printf("%4d", x);
			count++;
		}
	}
	return 0;
}

