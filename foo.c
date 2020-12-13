#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int main()
{

  char *ptr = "我是一条狗啊";
  srand((unsigned) time(NULL));
  bool condition = false;
  
  ptr  = (condition = rand() % 2) ? "我是旺财" : "我是铁蛋";
  fprintf(stdout, "%d: ", condition);
  puts(ptr);
  
  exit(0);
}

