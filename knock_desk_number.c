#include <stdio.h>
#include <stdbool.h>
bool is_knock_desk_num(int num);
int main(void)
{
  for (int i = 1; i <= 100; ++i) {
    printf("%d %s\n", i, is_knock_desk_num(i) ? "is knock desk number." : "");
   }
  return 0;
 }


bool is_knock_desk_num(int num)
{
  return (num % 7 == 0) || (num / 10 % 10 == 7) || (num % 7 == 0);
}
