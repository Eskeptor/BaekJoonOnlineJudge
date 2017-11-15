/*
https://www.acmicpc.net/problem/1110
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int initNum;
	scanf("%d", &initNum);
	int initA = initNum / 10;
	int initB = initNum % 10;
	int length = 0;

	int aA = initNum / 10;
	int aB = initNum % 10;
	int bA = (aA + aB) / 10;
	int bB = (aA + aB) % 10;

	while (true)
	{
		initNum = aB + bB;
		length++;
		if (initA == aB && initB == bB)
			break;

		aA = aB;
		aB = bB;
		bA = (aA + aB) / 10;
		bB = (aA + aB) % 10;
	}
	printf("%d", length);
	return 0;
}