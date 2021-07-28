#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 80
/*
找出字符ss中的整数，并存储到数
组a中，函数返回找到的整数个数
*/
int divide (char *ss, int *a)
{
	int count = 0; //字符串中数字串的个数

	for (int i = 0; ss[i]; i++) {
		int pos = i;   //当前位置
		int number = 0;

		if (!isdigit(ss[i]))  //不是数字就直接跳过下面的所有语句
			continue;

		while (isdigit(ss[i])) {
			number = number * 10 + (ss[i] - '0');
			i++;
		}
		i--; //复位i到最后不满足条件的前一位置,防止for i++越界

		if (pos > 0 && ss[pos - 1] == '-') {
			a[count++] = -number;
		} else {
			a[count++] = number;
		}

	}
	return count;
}

/*
统计整数数组元素之和
*/
int getSum(int *a, int size)
{
	int sum = 0;
        for (int i = 0; i < size; ++i) {
          sum += a[i];
        }

	return sum;
}

int main()
{
	char ss[LEN] = {'\0'};
	int a[LEN] = {0};

	scanf("%s", ss);
	printf("sum = %d\n", getSum(a, divide(ss, a)));

	exit(0);
}
