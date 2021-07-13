#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STU_SIZ  5 //分配节点数量

/*学生数据结构定义*/
typedef struct student {
	char name[32];      
 	int  math;           
	int  english;        
	int  data_structure; 
}student_t;

/*输入数据*/
void input(student_t *item)
{
	scanf("%s%d%d%d", item->name,
					&item->math,
					&item->english,
					&item->data_structure);
}

/*检查数据的合法性*/
bool is_valid(const student_t *item)
{
	return ((item->name[0] != '\0') &&
			(item->math > 0 && item->math <= 100) &&
			(item->english > 0 && item->english <= 100) &&
			(item->data_structure > 0 && item->data_structure <= 100));
	
}

/*输出数据*/
void output(const student_t *item)
{
	printf("%s\t%d\t%d\t%d",
			item->name,
			item->math,
			item->english,
			item->data_structure);
			
}

/*clear_buf*/
void clear_buf(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n')
		;
}

int main(void)
{
	student_t *stu_head = (student_t *)malloc(sizeof(student_t) * STU_SIZ); 
	
	if (stu_head == NULL) {
		perror("malloc");
		exit(1);
	}
	memset(stu_head, 0, sizeof(student_t) *  STU_SIZ);
	
	/*输入数据*/
	printf("|Name| Math | English | Data Sturcture |\n");
	for (int i = 0;  i < STU_SIZ; ++i) {
		printf("STU %d: ", i + 1);
		input(&stu_head[i]);
		if (!is_valid(&stu_head[i])) {
			memset(&stu_head[i], 0, sizeof(student_t));
			clear_buf();
			i--;
			printf("Enter error, try again.\n");	
		}	
	}
	/*输出数据*/
	printf("\n|Name| Math | English | Data Sturcture |\n");
	for (int i = 0;  i < STU_SIZ; ++i) {
		output(&stu_head[i]);
		putchar('\n');
	}
}

