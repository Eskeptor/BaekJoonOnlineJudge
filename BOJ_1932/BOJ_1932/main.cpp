/*
https://www.acmicpc.net/problem/1932
*/

#include <iostream>
#include <algorithm>
#include <cstring>

int** arr;

void solution(int lines)
{
	int max;
	for (int i = 1; i < lines; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				arr[i][j] += arr[i - 1][j];
				max = arr[i][j];
			}
			else if (j == i)
			{
				arr[i][j] += arr[i - 1][j - 1];
				max = std::max(max, arr[i][j]);
			}
			else
			{
				arr[i][j] += std::max(arr[i - 1][j - 1], arr[i - 1][j]);
				max = std::max(max, arr[i][j]);
			}
		}
	}
	printf("%d", max);
}


int main(void)
{
	int lines;
	scanf("%d", &lines);

	arr = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		arr[i] = new int[lines];
		memset(arr[i], 0, sizeof(int) * lines);
	}
		
	for (int i = 0; i < lines; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &arr[i][j]);

	solution(lines);


	for (int i = 0; i < lines; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}