#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
//#define DEBUG

typedef struct student {
    char id_number[16]; //证件号码最长15位
    char sign_in[9];    //签到时间15:30:28
    char leave[9];      //签离时间17:00:10
} studend_t;

//输入每天的记录行
void input(studend_t *s, size_t num)
{
       for (size_t i = 0; i < num; ++i) {
       char buf[64] = {0};
       memset(buf, 0, sizeof(buf));
       fgets(buf,64, stdin);
#ifdef DEBUG
        fprintf(stderr, "%s\n", buf);
#endif 
       sscanf(buf, "%16s %9s %9s", s[i].id_number, s[i].sign_in, s[i].leave);
#ifdef DEBUG
        fprintf(stderr, "%s\t%s\t%s\n", s[i].id_number, s[i].sign_in, s[i].leave);
#endif 

   } 
}
//true 比较签到，否则签离
bool isbig(const studend_t *a, const studend_t *b, bool type)
{
    size_t hours;  //时
    size_t minutes; //分
    size_t seconds; //秒
     if (type == true) { //签到
        sscanf(a->sign_in, "%zu:%zu:%zu", &hours, &minutes, &seconds);
        size_t t1 = hours*60*60  + minutes*60 + seconds;
        sscanf(b->sign_in, "%zu:%zu:%zu", &hours, &minutes, &seconds);
        size_t t2 = hours*60*60  + minutes*60 + seconds;
        return t1 < t2;  //返回早到的
    } else {
        sscanf(a->leave, "%zu:%zu:%zu", &hours, &minutes, &seconds);
        size_t t1 = hours*60*60  + minutes*60 + seconds;
        sscanf(b->leave, "%zu:%zu:%zu", &hours, &minutes, &seconds);
        size_t t2 = hours*60*60  + minutes*60 + seconds;
        return t1 > t2; //返回晚离的
   }
}

//返回早到与晚离的下标
size_t * sort(const studend_t *s, size_t num)
 {
     static size_t index[2] = {0, 0}; //存早到与晚离的索引
     for (size_t i = 1; i < num; ++i) {
        index[0] = isbig(s+index[0], s+i, true) ?  index[0] : i;
        index[1] = isbig(s+index[1], s+i, false) ? index[1] : i;
     }
     return index;
 }

 //clean input buffer
 void clean_buf(void)
 {
     int ch;
     while ((ch=getchar()) != EOF && ch != '\n')
        ; //跳过循环
 }

int main(void)
{
    size_t m;
    scanf("%zu", &m);
    studend_t arr[m];
    clean_buf();
    input(arr, m);
    size_t *ptr = sort(arr, m);
    printf("%s %s\n", arr[ptr[0]].id_number, arr[ptr[1]].id_number);
    return 0;
}