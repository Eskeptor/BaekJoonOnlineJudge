/*
https://www.acmicpc.net/problem/2292
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	int path = 1;
	int root = 1;
	int adder = 0;
	while (path < num)
	{
		adder += 6;
		path += adder;
		root++;
	}

	printf("%d", root);

	return 0;
}