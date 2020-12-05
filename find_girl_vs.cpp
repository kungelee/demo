#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
//find the girl
int main(void)
{
	long m, n;
	cin >> m >> n;
	//long arr[m][n];
	long* arr = (long*)malloc(sizeof(long) * m * n); //for vs
	if (nullptr == arr) {
		return -1;
	}

	//input score
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) 
			cin >> *(arr + i * n + j);

	
	//copy arr
	//long temp[m][n];
	long* temp = (long*)malloc(sizeof(long) * m * n); //for vs
	if (nullptr == temp) {
		return -1;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) 
			*(temp + i * n + j) = *(arr + i * n + j);
		
			

	//sort array
	sort(temp, temp + m * n);
	int the_max = abs(*temp) > abs(*(temp + m*n -1)) ?  *temp: *(temp + m*n -1);


	//find where the_max
	bool flag = true;
	int i = 0;
	int j = 0;
	for (i = 0; i < m && flag; i++) {
		for (j = 0; j < n; j++) { //exit for j, i= i+ 1;
			if (*(arr + i * n + j) == the_max) {
				j += 1;
				flag = false;
				break;
			}
		}
	}

	cout << i << " " << j << " " << the_max << endl;
	free(arr);
	free(temp);
	return 0;

}