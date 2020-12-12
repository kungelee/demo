#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 80
int  //返回连续数字的个数
count_digit(const char *ss)
{
	int count = 0;
	while (*ss && isdigit(*ss)) {
		count++;
		ss++;
	}
	return count;
}
int divide (char *ss, int *a)
{
	int i = 0;
	while (*ss) {
		if (*ss == '-') {
			int n = 0;
			int len =  count_digit(ss + 1);  //从'-'后开始
			
			for (int i = 1; i <= len; i++) { //从'-'后开始
				n = n * 10 + (ss[i] - '0');
			}
			if (len > 0) { 
				a[i++] = -n;
				ss += len + 1;
			}
		} else if (isdigit(*ss)) {
			int n = 0;
			int len  =  count_digit(ss);
			
			for (int i = 0; i < len; i++) { //从第一位开始
				n = n * 10 + (ss[i] - '0');
			}
			
			ss += len;
			a[i++] = n;
		} else {
			ss++;
		}
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