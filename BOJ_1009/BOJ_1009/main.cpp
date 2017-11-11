/*
https://www.acmicpc.net/problem/1009
*/

#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;

	int** arr = new int*[testCase];
	for (int i = 0; i < testCase; i++)
	{
		arr[i] = new int[3];
		cin >> arr[i][0] >> arr[i][1];

		int tmp = arr[i][0];
		for (int j = 1; j < arr[i][1]; j++)
		{
			tmp *= arr[i][0];
			if (tmp > 10)
				tmp %= 10;
		}

		if (tmp == 0)
			tmp = 10;
		arr[i][2] = tmp;
	}

	for (int i = 0; i < testCase; i++)
	{
		cout << arr[i][2] << endl;
	}

	for (int i = 0; i < testCase; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}