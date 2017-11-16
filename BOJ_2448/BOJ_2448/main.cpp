/*
https://www.acmicpc.net/problem/2448
*/

#include <iostream>
#define SHIFT 3
using namespace std;

void printStar(const int _num)
{
	char shape[3][6] = { "  *  ", " * * " , "*****" };
	int shifter = _num / SHIFT;
	int index = -1;
	
	for (int i = 0; i < _num; i++)
	{
		if (i%SHIFT == 0)
		{
			index++;
		}
		for (int j = 0; j <= index; j++)
			printf("%s", shape[i%SHIFT]);
		printf("\n");
	}
}


int main(void)
{
	int num;
	scanf("%d", &num);
	printStar(num);
	return 0;
}