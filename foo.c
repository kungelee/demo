#include <stdio.h>
#include <stdlib.h>

void reverse_print(int arr[], int size)
{
  while (--size >= 0) {
    if (size == 0)
      printf("%d\n", arr[0]);
    else
      printf("%d ", arr[size]);
  }

}


int main(void)
{
  int size = 0;

  while (scanf("%d", &size) != EOF) {
    int arr[size];
    for (int i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
    }
    reverse_print(arr, size);
  }

    return 0;
}
