/*
Q3.建立结构体类型Student，该结构体有stuid,name、age、address、score五项。
然后创建结构体Student类型数组，该数组共有十元素,按score升序排列输出。

编译器：GNU GCC 10.2.0
2021-12-4
*/
#define _CRT_SECURE_NO_WARNINGS  /* if msvc */
#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZ 32    /* 学生姓名长度 */
#define ADDR_SIZ 128   /* 学生地址长度 */
#define STU_SIZ  10    /* 学生人数 */

typedef struct Student
{
	size_t stuid;           // 学号 正整数
	char name[NAME_SIZ];    // 姓名 字符串
	size_t age;             // 年龄 正整数
	char address[ADDR_SIZ]; // 地址 字符串
	size_t score;           // 分数 正整数
	
} STU;


/* 输入学生信息 */
void stu_input(STU *stu, int num);

/* 交换学生信息 */
void stu_swap(STU *a, STU *b);

/* 学生信息按score升序排序 */
void stu_select_sort(STU *stu, int num);

/* 输出学生信息 */
void stu_output(STU *stu, int num);

/* 输入学生信息 */
void stu_input(STU *stu, int num)
{	
	for (int i = 0; i < num; ++i)
	{ 
		printf("\nEnter student %d\n", i + 1);
		printf("stuid  : ");          // 学号
		scanf("%zu", &stu[i].stuid);
		
		printf("name   : ");          // 姓名
		scanf("%s", stu[i].name);
		
		printf("age    : ");          // 年龄
		scanf("%zu", &stu[i].age);
			
		printf("score  : ");          // 分数
		scanf("%zu", &stu[i].score);
		
		printf("address: ");          // 地址
		scanf("%s", stu[i].address);
	}
}

/* 学生学据交换 */
void stu_swap(STU *a, STU *b)
{
	STU temp = *a;
	*a = *b;
	*b = temp;
}

/* 学生信息按score升序排序 */
void stu_select_sort(STU *stu, int num)
{
	for (int i = 0; i < num - 1; ++i) 
	{
		int min = i;
		for (int j = i + 1; j < num; ++j) 
		{
				if (stu[min].score > stu[j].score)
					min = j;
		}
		if (min != i) 
			stu_swap(&stu[min], &stu[i]);
	}
}

/* 输出学生信息 */
void stu_output(STU *stu, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("stuid  : %zu\n"
			   "name   : %s\n"
			   "age    : %zu\n"
			   "score  : %zu\n"
			   "address: %s\n",
			   stu[i].stuid,
			   stu[i].name,
			   stu[i].age,
			   stu[i].score,
			   stu[i].address);
		if (i < num -1) // 最后一行，无须分隔线
			printf("-------------------------------------------\n");
	}
}

int main(void)
{
	STU stu[STU_SIZ];
	// input
	printf("Enter the information of %d students:\n", STU_SIZ);
	printf("------------------------------------\n");
	stu_input(stu, STU_SIZ);
	// sort
	stu_select_sort(stu,STU_SIZ);
	// outpus
	printf("\nOutput student information sorted by score:\n");
	printf("-------------------------------------------\n");
	stu_output(stu, STU_SIZ);
	
	system("pause>nul"); //any key to exit.
	return 0;
	
}