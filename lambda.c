#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define lambda(function_name, OPS)       \
double function_name(double a, double b) \
{                                        \
	if ('/' == #OPS[0]  &&  b < 1e-8)    \
		abort();                         \
	else                                 \
		return (a) OPS (b);              \
}                                       

lambda(add, +)              //生成加法函数
lambda(sub, -)              //生成减法函数
lambda(mul, *)              //生成乘法函数
lambda(division, /)         //生成除法函数

double (*fun[])(double, double) = {add, sub, mul, division}; /* + - * / function */

int main(void) {
	
	char buf[BUFSIZ];
	char const *prompt = "lambda > "; 
	double a, b;
	char c;
	
	printf("请输入要计算的式子(格式a+b), q退出\n");
	for (;;) {
		printf("%s", prompt);
		fflush(stdout);
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == 'q') {
			break;
		} else if (sscanf(buf, "%lf%c%lf", &a, &c, &b) != 3) {
			fprintf(stderr, "%s", "格式错误，请重新输入\n");
		} else  {
			char ops[] = "+-*/";
			char *p = strchr(ops, c);
			assert(p);
			size_t pos = p - ops;
			//printf("%f\n", fun[pos](a,b));
			printf("%.2f %c %.2f  = %.2f\n", a, c, b, fun[pos](a, b));
		}
	}
	
	//system("pause>nul");
	return 0;
}