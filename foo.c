/*
将1,2....,9共9个数分成3组，分别组成3个三位数，
且使这3个三位数构成1 : 2 : 3的比例，
试求出所有满足条件的3个三位数。
2021年2月3日00:57:59
*/
#include <stdio.h>
int main()
{
    for(int n = 100; n < 333; n++)
    {
		/* 生成满足条件的三个数 */
        int a = n;
		int b = n * 2;
		int c = n * 3;
		
		/* 保存待验证的三个数 */
		const int a1 = a;
		const int b1 = b;
		const int c1 = c;
		/* 统计余数出现的次数 */
		int cnt_number[10] = {0}; 
        while(a)
        {
			cnt_number[a % 10]++;
			cnt_number[b % 10]++;
			cnt_number[c % 10]++;
			
			/* 数字中含有零，条件不满足 */
			if (cnt_number[0] != 0)
				break;
			
        	a /= 10;
            b /= 10;
            c /= 10;
	
        }
		/* 有零值,直接跳过验证 */
		if (cnt_number[0] != 0) 
			continue;
        
		int len = 0;
        for(int i = 1; i < 10; i++)
        {	
			/* 只统计出现过一次的情况 */
            if(1 != cnt_number[i]) 
				break;
            len++;
        }
        if(9 == len)
        {
            printf("%d, %d, %d\n", a1, b1, c1);
        }
    }
    return 0;
}