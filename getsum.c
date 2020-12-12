#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 80
int divide (char *ss, int *a)
{
	int i = 0;
	while (*ss) {
		if (*ss == '-') {
			int move = 0; //指针移动的字节数
			int n = 0;
			
			move++; //移动'-'号下一个字符偏移位置
			while (isdigit(*(ss + move))) {
				n = n * 10 + (*(ss + move) - '0');
				move++;
			}
			if (isdigit(*(ss + 1))) { //存在过数字
				a[i++] = -n;
				ss += move - 1; //去掉最后一个不满足的
			}
		} else if (isdigit(*ss)) {
			int move = 0;
			int n = 0;
			while (isdigit(*(ss + move))) {
				n = n * 10 + (*(ss + move) - '0');
				move++;
			}
			ss += move;
			a[i++] = n;
		}
		
		ss++;
	}
	return i;  
}

int getSum(int *a, int size)
{
	int sum = 0;
	while (--size >= 0) {
		sum += a[size];
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