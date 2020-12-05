#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{

	long m, n;
	cin >> m >> n;
	long arr[m][n];

	//input score
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	//copy arr
	long temp[m][n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = arr[i][j];

	//sort array
	sort(&temp[0][0], &temp[0][0] + m*n);
	int the_max = abs(temp[0][0]) > abs(temp[m-1][n-1]) ? temp[0][0] : temp[m-1][n-1];

	//find where the_max
	bool flag = true;
	int i, j;
	for (i = 0; i < m && flag; i++) {  
		for (j = 0; j < n; j++)  { //exit for j, i= i+ 1;
			if (arr[i][j] == the_max) {
				j += 1;  
				flag = false;
				break;
			}
		}
	}

	cout <<  i << " " << j << " " << the_max << endl;

	return 0;

}