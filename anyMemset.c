/*
任意类型赋值，只需添加新的类型回调函数即可
2021-7-29 by jefflee.
 */
#include <stdio.h>
#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

//fill the value for any type
void *anymemset(void *s, void *val, size_t n, void* (*fun)(void *, void *,  size_t))
{
  return fun(s, val, n);
}

//int memset
void* memset_int(void *s, void *val, size_t n)
{
  int *arr = (int *)s;
  for (size_t i = 0; i < n; ++i)
    arr[i] = * (int*)val;
  return s;
}

//float memset
void* memset_float(void *s, void *val, size_t n)
{
  float *arr = (float *)s;
  for (size_t i = 0; i < n; ++i)
    arr[i] = * (float *)val;
  return s;
}

//char memset
void* memset_char(void *s, void *val, size_t n)
{
  char *arr = (char *)s;
  for (size_t i = 0; i < n; ++i)
    arr[i] = * (char *)val;
  return s;
}


int main(void)
{
  char str[] = {"hello,world"};
  int arr[] = {1, 2, 3, 4, 5};
  float farr[] = {3.14, 99.6, 8.0, 9.8, 2.11};


  //init
  anymemset(str,  &(char){'A'}, sizeof(str) - 1, memset_char);
  anymemset(arr,  &(int){985}, NELEM(arr), memset_int);
  anymemset(farr, &(float){3.14}, NELEM(farr), memset_float);

  //output
  puts(str);
  for (size_t i = 0; i < NELEM(arr); ++i)
    printf("%d\t", arr[i]);
  printf("\n\n");

  for (size_t i = 0; i < NELEM(farr); ++i)
    printf("%f\t", farr[i]);
  printf("\n\n");


  return 0;
}
