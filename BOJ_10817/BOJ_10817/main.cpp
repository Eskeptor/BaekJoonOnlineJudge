/*
https://www.acmicpc.net/problem/10817
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 > num2)
	{
		if (num1 > num3)
		{
			if (num2 > num3)
				printf("%d", num2);
			else
				printf("%d", num3);
		}
		else // num3 > num1
		{
			printf("%d", num1);
		}
	}
	else // num2 > num1
	{
		if (num1 > num3)
		{
			printf("%d", num1);
		}
		else // num3 > num1
		{
			if (num2 > num3)
				printf("%d", num3);
			else
				printf("%d", num2);
		}
	}

	return 0;
}