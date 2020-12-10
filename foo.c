#include <stdio.h>
#include <stdlib.h>

int main() {
	int x = 0;
	if (scanf("%d", &x) != 1 || (x <= -5) || (x >= 8)) {
		printf("scanf() error!\n");
		exit(1);
	}
	int y = 0;
	int codition = 0;
	codition = (x > -5 && x < 0) ? -1 : 1;

	switch (codition) {
	case -1:
		y  = x - 1;
		break;
	case 0:
		y = 0;
		break;
	case 1:
		y = x + 1;
	default:
		break;

	}

	printf("y = %d\n", y);

	exit(0);
}