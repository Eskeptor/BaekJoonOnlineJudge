/*
https://www.acmicpc.net/problem/10039
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		if (num < 40)
			num = 40;
		total += num;
	}
	total /= 5;
	printf("%d", total);

	return 0;
}