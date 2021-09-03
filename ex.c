/*************************************************************************
* 教学信息管理系统
* 作者：
* 日期:
* gcc std=c99 (开启c99支持)
* 控制台cmd （not PowerShell)
* chcp 936  简体中文 GBK
* gcc ex.c -std=c99 -fexec-charset=gbk -o ex
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS   /* 如果用VC编译器，关掉scanf警告 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64       /* 姓名、电话、学历等最大长度 */
#define ARR_SIZE 500  /* 默认存储最大长度 */

/***************************基础信息开始**********************************/
/* 教师信息 */
typedef struct teacher {
    unsigned teach_no;            //教师号(固定值) > 1  
    char name[SIZE];              //姓名
    char sex[SIZE];               //性别
    char education[SIZE];         //学历
    unsigned age;                 //年龄
    char tel[SIZE];               //电话
} teacher_t;

/* 学生信息 */
typedef struct student {
    unsigned stu_no;              //学号 (固定值) 
    char name[SIZE];              //姓名
    
} student_t;

/* 课程信息 */
typedef struct course {
    unsigned course_no;           //课程号(固定值)
    char name[SIZE];              //课程名称
} course_t;

/* 教师与课程关联信息 */
typedef struct tc {
    unsigned tc_no;               //教师与课程关联序号(简称：教课号) > 1
    unsigned date;                //开课时间
    unsigned teach_no;            //教师号 (固定值)
    unsigned course_no;           //课程号(固定值) 主键
} tc_t;

/* 学生与课程关联信息 */
typedef struct sc {
    unsigned sc_no;               //学生与课程关联序号(简称：学课号) > 1
    unsigned stu_no;              //学号
    unsigned course_no;           //课程号(固定值) 主键
} sc_t;


/* 加g_前辍（global），区别普通局部变量 */
teacher_t teacher[ARR_SIZE];  /* 教师信息 */
unsigned  g_teacher_sum;      /* 记录的教师数量 */

student_t student[ARR_SIZE];  /* 学生信息 */
unsigned  g_student_sum;      /* 记录的学生数量 */

course_t  course[ARR_SIZE];   /* 课程信息 */
unsigned  g_course_sum;       /* 记录的课程数量 */

tc_t      tc[ARR_SIZE];       /* 教师与课程关联信息 */
unsigned  g_tc_sum;           /* 记录的教师与课课关联信息数量 */

sc_t      sc[ARR_SIZE];       /* 学生与课程关联信息 */
unsigned  g_sc_sum;           /* 记录学生与课程关联信息*/


/***************************基础信息结束**********************************/


/***************************工具函数 开始**********************************/
/* 清除输入缓冲区 */
void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

/* 返回选择 y or n */
char yes_or_no(void)
{
     int ch = 0;
     do {
         ch = getchar();
     } while (strchr("YyNn", ch) == NULL);
     
     return  (ch == 'Y' || ch == 'y') ? 'y' : 'n';
}

/* 退出信息 */
void byebye(void) 
{
    printf(
        "\n"
        "All rights reserved.\n"
        "Thanks for use and have a nice day.\n\n"
    );
}

/***************************工具函数 结束**********************************/


/***************************录入信息 开始**********************************/
/* 录入教师信息 */
void input_teacher(void)
{
    for (unsigned i = g_teacher_sum; i < ARR_SIZE; i++) {
        printf("请录入教师号: ");
        scanf("%u", &teacher[i].teach_no);

        printf("请录入教师姓名: ");
        scanf("%s", teacher[i].name);

        printf("请录入教师性别: ");
        scanf("%s", teacher[i].sex);

        printf("请录入教师学历: ");
        scanf("%s", teacher[i].education);

        printf("请录入教师年龄: ");
        scanf("%u", &teacher[i].age);
        
        printf("请录入教师电话: ");
        scanf("%s", teacher[i].tel);
        g_teacher_sum += 1;
        printf("续续添加吗? [y/n]: ");
        if (yes_or_no() == 'n')
            break;
    }
}

/* 录入学生信息 */
void input_student(void)
{
    for (unsigned i = g_student_sum; i < ARR_SIZE; i++) {
        printf("请录入学生学号: ");
        scanf("%u", &student[i].stu_no);

        printf("请录入学生姓名: ");
        scanf("%s", student[i].name);

        g_student_sum += 1;
        printf("续续添加吗? [y/n]: ");
        if (yes_or_no() == 'n')
            break;
    }
}


/* 录入课程信息 */
void input_course(void)
{
    for (unsigned i = g_course_sum; i < ARR_SIZE; i++) {
        printf("请录入课程号: ");
        scanf("%u", &course[i].course_no);

        printf("请录入课程名称: ");
        scanf("%s", course[i].name);

        g_course_sum += 1;
        printf("续续添加吗? [y/n]: ");
        if (yes_or_no() == 'n')
            break;
    }
}

/* 录入教师与课程关联信息 */
void input_tc(void)
{
    for (unsigned i = g_tc_sum; i < ARR_SIZE; i++) {
        printf("请录入教课号: ");
        scanf("%u", &tc[i].tc_no);

        printf("请录入开课时间: ");
        scanf("%u", &tc[i].date);

        printf("请录入教师号: ");
        scanf("%u", &tc[i].teach_no);

        printf("请录入课程号: ");
        scanf("%u", &tc[i].course_no);

        g_tc_sum += 1;
        printf("续续添加吗? [y/n]: ");
        if (yes_or_no() == 'n')
            break;
    }
}


/* 录入学生与课程关联信息 */
void input_sc(void)
{
    for (int i = g_sc_sum; i < ARR_SIZE; i++) {
        printf("请录入学课号: ");
        scanf("%u", &sc[i].sc_no);

        printf("请录入学号: ");
        scanf("%u", &sc[i].stu_no);
        
        printf("请录入课程号: ");
        scanf("%u", &sc[i].course_no);

        g_sc_sum += 1;
        printf("续续添加吗? [y/n]: ");
        if (yes_or_no() == 'n')
            break;
    }
}

/***************************录入信息 结束**********************************/


/***************************浏览信息 开始**********************************/
/* 浏览教师信息 */
void output_teacher(void)
{
    for (unsigned i = 0; i < g_teacher_sum; i++) {
        printf(
            "教师号:%u\n"
            "姓名：%s\n"
            "性别：%s\n"
            "学历：%s\n"
            "年龄：%u\n"
            "电话：%s\n",
            teacher[i].teach_no,
            teacher[i].name,
            teacher[i].sex,
            teacher[i].education,
            teacher[i].age,
            teacher[i].tel
        );
        printf("\n");
    }
}

/* 浏览学生信息 */
void output_student(void)
{
    for (unsigned i = 0; i < g_student_sum; i++) {
        printf(
            "学生号: %u\n"
            "姓名：%s\n",
            student[i].stu_no,
            student[i].name
        );
        printf("\n");
    }
}


/* 浏览课程信息 */
void output_course(void)
{
    for (unsigned i = 0; i < g_course_sum; i++) {
        printf(
            "课程号: %u\n"
            "课程名称：%s\n",
            course[i].course_no,
            course[i].name
        );
        printf("\n");
    }
}

/* 浏览教师与课程关联信息 */
void output_tc(void)
{
    for (unsigned i = 0; i < g_tc_sum; i++) {
        printf(
            "教课号: %u\n"
            "开课时间：%u\n"
            "教师号：%u\n"
            "课程号：%u\n",
            tc[i].tc_no,
            tc[i].date,
            tc[i].teach_no,
            tc[i].course_no
        );
        printf("\n");
    }   
}

/* 浏览学生与课程关联信息 */
void output_sc(void)
{
    for (unsigned i = 0; i < g_sc_sum; i++) {
        printf(
            "学课号: %u\n"
            "学号：%u\n"
            "课程号：%u\n",
            sc[i].sc_no,
            sc[i].stu_no,
            sc[i].course_no
        );
        printf("\n");
    }
}

/***************************浏览信息 结束**********************************/



/***************************查询信息 开始**********************************/
/* 查询教师与关联课程信息 */
void query_teacher(void)
{
    char name[SIZE] = "";
    printf("请输入教师姓名: ");
    scanf("%s", name);
    unsigned i, j;
    for (i = 0; i < g_teacher_sum; ++i) {
        if (strcmp(teacher[i].name, name) == 0) { //找到教师
            printf(
            "教师号:%u\n"
            "姓名：%s\n"
            "性别：%s\n"
            "学历：%s\n"
            "年龄：%u\n"
            "电话：%s\n",
            teacher[i].teach_no,
            teacher[i].name,
            teacher[i].sex,
            teacher[i].education,
            teacher[i].age,
            teacher[i].tel
        );
        for (j = 0; j < g_tc_sum; ++j) { //查找教师与课程关联信息
            if(teacher[i].teach_no == tc[j].teach_no) {
                printf(
                "教课号: %u\n"
                "开课时间：%u\n"
                "教师号：%u\n"
                "课程号：%u\n",
                tc[i].tc_no,
                tc[i].date,
                tc[i].teach_no,
                tc[i].course_no
                );
            }
        } // end for j
      } 
    }//end for i
}

/* 查询学生及关联课课信息 */
void query_student(void)
{
        char name[SIZE] = "";
        printf("请输入学生姓名: ");
        scanf("%s", name);
        unsigned i, j;
        for (i = 0; i < g_student_sum; ++i) {
            if (strcmp(student[i].name, name) == 0) { //找到学生
               printf(
                "学生号: %u\n"
                "姓名：%s\n",
                student[i].stu_no,
                student[i].name
                );
            for (j = 0; j < g_sc_sum; ++j) { //查找学生与课程关联信息
                if(student[i].stu_no == sc[j].stu_no) {
                    printf(
                        "学课号: %u\n"
                        "学号：%u\n"
                        "课程号：%u\n",
                        sc[i].sc_no,
                        sc[i].stu_no,
                        sc[i].course_no
                    );
                }
            } // end for j
        }
    } //end for i
}

/***************************查询信息 结束**********************************/


/***************************修改信息 开始**********************************/
/* 修改教师信息 */
void modify_teacher(void)
{
     char name[SIZE] = "";
     printf("请输入教师姓名：");
     scanf("%s", name);
     for (unsigned i = 0; i < g_teacher_sum; ++i) {
         if (strcmp(teacher[i].name, name) == 0) {
                printf("请输入教师姓名: ");
                scanf("%s", teacher[i].name);

                printf("请输入教师性别: ");
                scanf("%s", teacher[i].sex);

                printf("请输入教师学历: ");
                scanf("%s", teacher[i].education);

                printf("请输入教师年龄: ");
                scanf("%u", &teacher[i].age);
                
                printf("请输入教师电话: ");
                scanf("%s", teacher[i].tel);
                printf("修改完毕\n");
                return;
         }
     }
     printf("error: %s无信息\n", name);
}

/* 修改学生信息 */
void modify_student(void)
{
    unsigned stu_no;
    printf("请输入学生学号: ");
    scanf("%u", &stu_no);
    for (unsigned i = 0; i < g_student_sum; i++) {
        if (student[i].stu_no == stu_no) {
            printf("请输入新学生姓名: ");
            scanf("%s", student[i].name);
            printf("修改完毕\n");
            return;
        }
    }
     printf("error: %u无信息\n", stu_no);
}


/* 修改课程信息 */
void modify_course(void)
{
    unsigned course_no;
    printf("请输入课程号: ");
    scanf("%u", &course_no);
    for (unsigned i = 0; i < g_course_sum; i++) {
        if (course[i].course_no == course_no) {
            printf("请输入课程名称: ");
            scanf("%s", course[i].name);
            printf("修改完毕\n");
            return;
        }
    }
    printf("error: %u无信息\n", course_no);
}

/* 修改教师与课程关联信息 */
void modify_tc(void)
{
    unsigned teach_no;
    printf("请输入教师号: ");
    scanf("%u", &teach_no);
    for (unsigned i = 0; i < g_tc_sum; i++) {
        if (tc[i].teach_no == teach_no) {
            printf("请输入开课时间: ");
            scanf("%u", &tc[i].date);
            printf("修改完毕\n");
            return;
        }
    }
    printf("error: %u无信息\n", teach_no);    
}

/***************************修改信息 结束**********************************/


/***************************选择菜单 开始**********************************/
/* 返回选择的数值 */
int choice(const char *str_range)
{
    int ch;
    do {
        ch = getchar();
    } while (strchr(str_range, ch) == NULL);

    return ch - '0';
}

/* 录入主菜单 */
void input_menu(void)
{
    const char *msg = 
        "\n"
        "教学信息管理系统\n"
        "----------------\n"
        "1)录入教师信息\n" 
        "2)录入课程信息\n"
        "3)录入教师与课程关联信息\n"
        "4)录入学生信息\n"
        "5)录入学生与课程关联信息\n"
        "----------------\n"
        "0. 返回   9. 清屏\n"
        "\n";

    for (;;) {
        fprintf(stdout, "%s", msg); 
        switch(choice("0123459")) {
            case 0: return;
            case 1: input_teacher(); break;
            case 2: input_course();  break;
            case 3: input_tc();      break;
            case 4: input_student(); break;
            case 5: input_tc();      break;
            case 9: system("cls");   break;
            default:break;
        }
    }
}

/* 浏览主菜单 */
void output_menu(void)
{
    const char *msg = 
        "\n"
        "教学信息管理系统\n"
        "----------------\n"
        "1)浏览教师信息\n" 
        "2)浏览课程信息\n"
        "3)浏览教师与课程关联信息\n"
        "4)浏览学生信息\n"
        "5)浏览学生与课程关联信息\n"
        "----------------\n"
        "0. 返回   9. 清屏\n"
        "\n";

    for (;;) {
        fprintf(stdout, "%s", msg); 
        switch(choice("0123459")) {
            case 0: return;
            case 1: output_teacher(); break;
            case 2: output_course();  break;
            case 3: output_tc();      break;
            case 4: output_student(); break;
            case 5: output_tc();      break;
            case 9: system("cls");    break;
            default:break;
        }
    }
}

/* 查询主菜单 */
void query_menu(void)
{
     const char *msg = 
        "\n"
        "教学信息管理系统\n"
        "----------------\n"
        "1)查询教师与课程关联信息\n"
        "2)查询学生与课程关联信息\n"
        "----------------\n"
        "0. 返回   9. 清屏\n"
         "\n";

    for (;;) {
        fprintf(stdout, "%s", msg); 
        switch(choice("0129")) {
            case 0: return;
            case 1: query_teacher(); break;
            case 2: query_student(); break;
            case 9: system("cls");   break;
            default:break;
        }
    }
}

/* 修改主菜单 */
void modify_menu(void)
{
     const char *msg = 
         "\n"
        "教学信息管理系统\n"
        "----------------\n"
        "1)修改教师信息\n" 
        "2)修改课程信息\n"
        "3)修改教师与课程关联信息\n"
        "4)修改学生信息\n"
        /* 修改学生与课程关联信息\n 该项禁止修改*/ 
        "----------------\n"
        "0. 返回   9. 清屏\n"
         "\n";

    for (;;) {
        fprintf(stdout, "%s", msg); 
        switch(choice("012349")) {
            case 0: return;
            case 1: modify_teacher(); break;
            case 2: modify_course();  break;
            case 3: modify_tc();      break;
            case 4: modify_student(); break;
            case 9: system("cls");    break;
            default:break;
        }
    }
}


/* 显示主菜单  */
void menu(void)
{
    const char *msg = 
        "\n"
        "教学信息管理系统\n"
        "----------------\n"
        "教师信息\n" 
        "课程信息\n"
        "教师与课程关联信息\n"
        "学生信息\n"
        "学生与课程关联信息\n"
        "----------------\n"
        "1. 录入   2. 浏览\n" 
        "3. 查询   4. 修改\n"
        "0. 退出   9. 清屏\n"
        "\n";

    for (;;) {
        fprintf(stdout, "%s", msg); 
        switch(choice("012349")) {
            case 0: exit(0);
            case 1: input_menu();  break;
            case 2: output_menu(); break;
            case 3: query_menu();  break;
            case 4: modify_menu(); break;
            case 9: system("cls"); break;
            default:break;
        }
    }
}
/***************************选择菜单 结束**********************************/

/* 程序入口主函数 */
int main(void)
{
   atexit(byebye);
   menu();
   return 0; 
}





