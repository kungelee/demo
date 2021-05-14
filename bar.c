/*
C语言技巧，匿名结构与匿名数组
2021年2月1日19:42:26
copy　code. 
*/
#include <stdio.h>

typedef struct persion {
    const char *name;
    int age;
} persion[1], persion_t;

int main(void)
{
    struct persion a;
    struct persion *p = NULL;
    struct persion *q = NULL;

    a = (persion_t){"persion1", 25};
    p = (persion){{"persion2", 27}};
    q = (struct persion[]){{"persion3", 22}};

    printf("%s %d\n", a.name, a.age);
    printf("%s %d\n", p->name, p->age);
    printf("%s %d\n", q->name, q->age);
    printf("%s %d\n", q->name, q->age);


    return 0;
}
