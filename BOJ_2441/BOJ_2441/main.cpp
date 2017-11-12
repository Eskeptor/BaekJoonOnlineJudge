/*
https://www.acmicpc.net/problem/2441
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < num - i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}