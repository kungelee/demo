/*
 *Compile with GCC 10.2 
 *-std=c99
 *2020-12-15 01:52:22 by jeff lee.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int count_space(const char *src)
{
  int count = 0;

  while (*src) {
    if (isspace(*src))
      count++;
    src++;
  }
  
  return count;
}


int count_char(const char *src)
{

  int count = 0;

  while(*src) {
    if(isalpha(*src))
      count++;
    src++;
  }

  return count;
}

int count_word(const char *src)
{
  int count = 0;
  bool in = false;

  while (*src) {
    if (isalpha(*src)) {
      if (in == false)
	in = true;
    } else {
      if (in == true) {
	in = false;
	count++;
      }
    }
    src++;
  }
  
  return isalpha(*--src) ? count + 1 : count; //fix bug, last word, no space
}


int main(void)
{
  char msg[] = "hello, world";

  printf("space = %d, charactor = %d, word = %d\n",
	 count_space(msg),
	 count_char(msg),
	 count_word(msg));

  return 0;
}
