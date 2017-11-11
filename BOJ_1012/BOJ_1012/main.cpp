/*
https://www.acmicpc.net/problem/1012
*/

#include <iostream>
using namespace std;

void print(int** _arr, const int _w, const int _h)
{
	for (int i = 0; i < _h; i++)
	{
		for (int j = 0; j < _w; j++)
		{
			cout << _arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	int testCase;
	cin >> testCase;

	int* result = new int[testCase] {0, };
	for (int i = 0; i < testCase; i++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		int** arr = new int*[n];
		for (int j = 0; j < n; j++)
			arr[j] = new int[m] {0, };

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;

			if (x - 1 >= 0)
			{
				if (y - 1 >= 0)
				{
					if (arr[y][x - 1] != 1 && arr[y - 1][x] != 1)
						result[i] += 1;
				}
				else
				{
					if (arr[y][x - 1] != 1)
						result[i] += 1;
				}
			}
			else
			{
				if (y - 1 >= 0)
				{
					if (arr[y - 1][x] != 1)
						result[i] += 1;
				}
				else
				{
					result[i] += 1;
				}
			}
		}
		print(arr, m, n);

		for (int j = 0; j < n; j++)
			delete[] arr[j];
		delete[] arr;
	}

	for (int i = 0; i < testCase; i++)
	{
		cout << result[i] << endl;
	}

	delete[] result;
	return 0;
}