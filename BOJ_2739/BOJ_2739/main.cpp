/*
https://www.acmicpc.net/problem/2739
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= 9; i++)
		printf("%d * %d = %d\n", num, i, i*num);

	return 0;
}