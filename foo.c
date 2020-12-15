#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//3)return the max number address
int *max(int arr[], int size)
{
	int the_max = arr[0];
	int index = 0;
	int i = 0;
	for (i = 1; i < size; i++) {
		if (the_max < arr[i]) {
			the_max = arr[i];
			index = i;
		}
	}
	return &arr[index];
	
}


//3)return the min number address
int *min(int arr[], int size)
{
	int the_min = arr[0];
	int index = 0;
	int i = 0;
	for (i = 1; i < size; i++) {
		if (the_min > arr[i]) {
			the_min = arr[i];
			index = i;
		}
	}
	return &arr[index];
	
}



int main(void)
{
	//1)define ten integer numbers 
	int arr[10] = {0};
	int i;
	
	//2)input ten numbers
	printf("Enter ten numbers:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	
	//4)use pointer record the max  and min address
	int *max_ptr = max(arr, 10);
	int *min_ptr = min(arr, 10);
	
	//5)print original array
	printf("Before swap:\n");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	
	//swap
	int temp = *max_ptr;
	*max_ptr = *min_ptr;
	*min_ptr = temp;
	
	
	//5) print swap  array
	printf("\nAfter swap:\n");
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	
	return 0;
}