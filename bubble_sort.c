#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))   //count element of array
#define INT_RANGE 32767                             //integer range [0,32767-1]
void bubble_sort(int *arr, int size);
void swap(int *a, int *b);
void init(int *arr, int size);
void show(int *arr, int size);

//bubble sort, from small to big
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i -1; ++j)  {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

//swap a and b's value
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//rand a int number
void init(int *arr, int size)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % INT_RANGE;   //0~32767-1
}

//out puts array info
void show(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        fprintf(stdout, "%d\n", arr[i]);
}

int main(void)
{
    int arr[10];
    init(arr, NELEM(arr));
    puts("\n-----------------begin----------------------");
    show(arr, NELEM(arr));
    puts("\n------------------end-----------------------");
    bubble_sort(arr, NELEM(arr));
    show(arr, NELEM(arr));
    return 0;
}
