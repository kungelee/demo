#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c; //方程系数
	int delta;   // b^2 - 4*a*c

	a = b = c = delta = 0;

	if (scanf("%d%d%d", &a, &b, &c) != 3)
		return -1;
	delta = b * b - 4 * a * c;

	if (a == 0 || delta < 0) {
		printf("error");
	}
	else if (delta > 0) {
		printf("x1 = %.0f\n",(float) (-b - sqrt((double)delta)) / (2 * a));
		printf("x2 = %.0f\n", (float)(-b + sqrt((double)delta)) / (2 * a));
	}
	else {

		printf("x1 = x2 = %.0f\n", (float)-b / (2 * a));
	}
	return 0;
}