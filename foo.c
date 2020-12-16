#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_up_number(int n)
{

  if (n < 0)
    n = - n;
  if (n / 10 == 0)
    return true;
  else {
    int r = n % 10;
    n /= 10;
    return (r > n % 10 ) && is_up_number(n);
  }
}


int main(void)
{
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%*d: %s\n", -10,  n, is_up_number(n) ? "true" : "false");
  }

  return 0;
}
