#include <stdio.h>
#include <stdbool.h>
bool is_water_flower(int number);

int main(void)
{
  int number;
  scanf("%d", &number);
  if (is_water_flower(number))
    printf("%d is a water flower number.\n", number);
  return 0;
}


bool is_water_flower(int number)
{
  if (number >= 100 && number <= 999) {
    int a = number / 100;
    int b = number % 100 / 10;
    int c = number % 10;
    return number == a*a*a + b*b*b + c*c*c;
  }

  return false;
}
