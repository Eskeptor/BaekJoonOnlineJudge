/*
https://www.acmicpc.net/problem/1065
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int numLength(const int _num)
{
	int length = 0;
	int num = _num;
	while (true)
	{
		num /= 10;
		length++;
		if (num < 1)
			break;
	}
	return length;
}

int isHansue(const int _num)
{
	int num = _num;
	int length = numLength(num);
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = num % 10;
		num /= 10;
	}

	int gap = arr[0] - arr[1];

	for (int i = 0; i < length; i++)
	{
		if (i + 1 != length)
		{
			if (arr[i] - arr[i + 1] != gap)
			{
				delete[] arr;
				return 0;
			}
		}
	}
	delete[] arr;
	return 1;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	int idx = 0;
	if (num < 100)
		printf("%d", num);
	else
	{
		for (int i = num; i > 100; i--)
		{
			idx += isHansue(i);
		}
		idx += 99;
		printf("%d", idx);
	}

	return 0;
}