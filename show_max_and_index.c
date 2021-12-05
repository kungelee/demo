/*
Q2 输入一个六行六列的整数型二维数组，找出每行中的最大值，并输出该最大值以及最大值所对应的下标

编译器：GNU GCC 10.2.0
2021-12-4
*/

#define _CRT_SECURE_NO_WARNINGS  /* if msvc */
#include <stdio.h>
#include <stdlib.h>
#define ROW_SIZ  6 /* 行数 */
#define COL_SIZ  6 /* 列数 */
int main(void)
{
	
	int num[ROW_SIZ][COL_SIZ]; //六行六列整型二维数组

	/* 数据输入*/
	for (int row = 0; row < ROW_SIZ; row++) // 行数
	{
		printf("Enter the %d data in row %d :\n", COL_SIZ, row + 1); // 行数从1开始
		for (int col = 0; col < COL_SIZ; col++)
		{
			scanf("%d", &num[row][col]);
		}
	}


	for (int row = 0; row < ROW_SIZ; row++)
	{
		int col_index = 0; // 最大值列下标(从0开始)		
		for (int col = 1; col < COL_SIZ; col++)  	// 找出每行最大值及下标位置
		{
			if (num[row][col_index] < num[row][col])  
				col_index = col;
		}
		
		/* 输出每行最大值及对应的下标 */
		printf("The maximum of line %d is %d and the index is [%d][%d]\n", 
				row + 1,     // 行数从1开始
				num[row][col_index],
				row,
				col_index); 
	}
	system("pause>nul"); //any key to exit.
	return 0;
}

