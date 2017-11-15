/*
https://www.acmicpc.net/problem/8393
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num, total = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		total += i;
	printf("%d", total);
	return 0;
}