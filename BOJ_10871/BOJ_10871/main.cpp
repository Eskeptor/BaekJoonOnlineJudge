/*
https://www.acmicpc.net/problem/10871
*/

#include <iostream>
using namespace std;

int main(void)
{
	int size, max;
	scanf("%d %d", &size, &max);

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < max)
			printf("%d ", arr[i]);
	}

	delete[] arr;
	return 0;
}