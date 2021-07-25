/*
C语言技巧，匿名结构与匿名数组
2021年2月1日19:42:26
copy　code. 
*/
#include <stdio.h>

typedef struct person {
    const char *name;
    int age;
} person[1], person_t;

int main(void)
{
    struct person a;
    struct person *p = NULL;
    struct person *q = NULL;
    
    a = (person_t){"person1", 25};
    p = (person){{"person2", 27}};
    q = (struct person[]){{"person3", 22}};

    printf("%s %d\n", a.name, a.age);
    printf("%s %d\n", p->name, p->age);
    printf("%s %d\n", q->name, q->age);
    printf("%s %d\n", q->name, q->age);


    return 0;
}
