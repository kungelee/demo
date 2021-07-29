#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atoi(const char *s)
{
	int n = 0;
	int sign = 1; //正负
	int i;
	for (i = 0; s[i] != '\0'; ++i) { //找到第一个数的位置
		if (isdigit(s[i])) break;
	}
	
	if (i > 0 && s[i-1] == '-') //正负数判断
		sign = -1;
		
	for (; isdigit(s[i]); ++i) { //累和
		n *= 10;
		n += s[i] - '0'; 
	}

	return sign==-1? -n : n;
}
int main(void)
{
	char s[64] = "";  
	memset(s, 0, sizeof(s));
	fgets(s, sizeof(s), stdin);
	printf("%d\n", atoi(s));
	return 0;
}