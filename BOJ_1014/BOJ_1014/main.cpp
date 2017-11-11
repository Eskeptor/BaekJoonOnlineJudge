// ´ú Ç¬¹®Á¦
/*
https://www.acmicpc.net/problem/1014
*/

#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;

	int* resArr = new int[testCase] {0, };
	int n, m, count = 0;
	for (int i = 0; i < testCase; i++)
	{
		cin >> n >> m;
		char** arr = new char*[n];
		for (int j = 0; j < n; j++)
		{
			arr[j] = new char[m];
			for (int k = 0; k < m; k++)
				cin >> arr[j][k];
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (j == 0)
				{
					if (k == 0)
					{
						count++;
					}
					else
					{

					}
				}
			}
		}

		for (int j = 0; j < n; j++)
			delete[] arr[j];
		delete[] arr;
	}

	delete[] resArr;
	return 0;
}