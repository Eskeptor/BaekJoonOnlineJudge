/*
https://www.acmicpc.net/problem/1546
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int size;
	scanf("%d", &size);

	int* scores = new int[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &scores[i]);

	int max = 0;
	for (int i = 0; i < size; i++)
		if (scores[max] < scores[i])
			max = i;
	
	
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += (double)(scores[i]) / (double)(scores[max]) * 100;
	}

	
	printf("%.2f", round(total / size * 100) / 100);

	return 0;
}