/*
https://www.acmicpc.net/problem/4344
*/

#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	scanf("%d", &testCase);

	double* perArr = new double[testCase];

	for (int i = 0; i < testCase; i++)
	{
		int size;
		scanf("%d", &size);
		
		int* arr = new int[size];
		double avr = 0;
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &arr[j]);
			avr += arr[j];
		}
		avr /= size;

		int idx = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > avr)
				idx++;
		}
		perArr[i] = (double)idx / (double)size * 100;

		delete[] arr;
	}

	for (int i = 0; i < testCase; i++)
		printf("%.3f%%\n", perArr[i]);

	delete[] perArr;
	return 0;
}