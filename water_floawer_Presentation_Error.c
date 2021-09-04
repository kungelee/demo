#include <stdio.h>


int main(void)
{
	for (;;) {
		int m, n;
		int ret = scanf("%d%d", &m, &n);
		if (ret == EOF || ret != 2)
			break;

		int count = 0; //count flower numbers
		for (int i = m; i <= n; ++i) {
			int a, b, c; 
			a = i / 100;
			b = i / 10 % 10;
			c = i % 10;
			if (i == a*a*a + b*b*b + c*c*c) {
				count++;
				if (count == 1) // 每行首位满足条件的
					printf("%d", i);
				else
#ifdef DEBUG
				printf("(SPACE)%d",i);
#else
				printf("% d", i);
#endif
				count++;
			}
		}
		if (count == 0)
			printf("no");
		printf("\n");
	}
	return 0;
}