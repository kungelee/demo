#include<iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 10
typedef struct {
	char data[MAX_SIZE];
	int top;
} SqStack_t;

//栈初始化
void InitStack(SqStack_t &s) {
	s.top = -1;
}

//栈空
bool StackIsEmpty(const SqStack_t &s) {
	return s.top == -1;
}

//栈满
bool StackIsFull(const SqStack_t &s) {
	return s.top == MAX_SIZE - 1; //合法下标范围[0 - 9]
}

//入栈
bool Push(SqStack_t &s, char ch) {
	if (StackIsFull(s))
		return false;
	s.top += 1;
	s.data[s.top] = ch;
	return  true;
}
//出栈
bool Pop(SqStack_t &s, char *ch) {
	if (StackIsEmpty(s)) 
		return false;
	*ch = s.data[s.top];
	s.top -= 1;
	return true;
}

bool BreaketCheck(const char *str, int length) {
	SqStack_t s;
	InitStack(s);//初始化栈
	
	for (int i = 0; i < length; i++) {
		if (StackIsFull(s) != true && strchr("([{", str[i]) != nullptr)
			Push(s, str[i]);
		else {
			if (StackIsEmpty(s))
				return false;
			char ch = s.data[s.top];
			if ((str[i] == ')' && ch != '(') ||
				(str[i] == ']' && ch != '[') ||
				(str[i] == '}' && ch != '{'))
					return false;
			Pop(s, &ch);
		} //end if
	} //end for
	return StackIsEmpty(s);
}

int main(void)
 {
	char str[MAX_SIZE];
	fgets(str, MAX_SIZE, stdin);
	char *fund = strchr(str, '\n');
	if (fund != nullptr)
		*fund = '\0';
	int len = strlen(str);
	cout << str  << ": " << BreaketCheck(str, len) << endl;
	
	return 0;
}