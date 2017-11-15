/*
https://www.acmicpc.net/problem/4673
*/

#include <iostream>
#define MAX 10000
using namespace std;

int checkSelfNumber(const int _num)
{
	int sum = _num;
	int i = _num;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(void)
{
	bool check[MAX + 36] = { false, };

	for (int i = 1; i <= MAX; i++)
	{
		if (!check[i])
			printf("%d\n", i);
		check[checkSelfNumber(i)] = true;
	}

	return 0;
}