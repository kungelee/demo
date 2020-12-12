#include <stdio.h>
#include <stdlib.h>

typedef struct _cat {
	char name[10];
	char color[10];
	void (*say)(void);  //叫
	void (*jump)(void); //跳
} CAT;


void say(void)
{
	printf("Miao\n");
}

void jump(void)
{
	printf("jump\n");
}


int main()
{

	//创建5只独
	//初始化第一只
	CAT arr[5] = {
		{
		name: "小花",
		color: "白色",
		say:say,
		jump:jump
		},
	};

	printf("Skill output:\n");
	//打印技能
	printf("name = %s, color = %s\n", arr[0].name, arr[0].color);
	arr[0].say();
	arr[0].jump();

	exit(0);
}