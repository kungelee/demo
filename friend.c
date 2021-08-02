#include <stdio.h>
#include <stdlib.h>

int  main(void)
{

 typedef struct friend {
    char const *name; 
    int age;
  } friend;

  friend *ptr = malloc(sizeof *ptr);
  aseert(ptr != NULL);
  ptr->name = "joyce";
  ptr->age = 18;
  printf("name = %s, age = %d\n", ptr->name, ptr->age);

  return 0;
}
