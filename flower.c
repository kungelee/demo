#include <stdio.h>
#include <stdbool.h>
#define POW(x) ((x) * (x) *(x))

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while(0)
#endif

bool isWaterFlowerNum(int num)
{
	if (num < 100 || num > 999)
		return false;
	int  a, b, c;  //a: 百位， b:十位， c:个位
	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	DEBUG_PRINT(("num = %d, %d, %d, %d\n", num, a, b, c));
	return num == POW(a) + POW(b) + POW(c);
}


void printWaterFlowers(int m, int n)
{
	int count = 0;
	for (int i = m; i <= n; ++i) {
		if (isWaterFlowerNum(i)) {
			printf("%d ", i);
			count++;
		}
	}
	if (count == 0)
		printf("no");
}


int main(void)
{
	for (;;) {
		int m, n;
		int ret = scanf("%d%d", &m, &n);
		if (ret == EOF || ret != 2)
			break;
		printWaterFlowers(m, n);
		printf("\n");
	}
	
	return 0;
}