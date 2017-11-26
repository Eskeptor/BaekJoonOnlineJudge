/*
https://www.acmicpc.net/problem/2577
*/

#include <iostream>
using namespace std;

int getLength(const int _num)
{
	int length = 0;
	int num = _num;
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return length;
}

int main(void)
{
	int num1, num2, num3, result;
	scanf("%d %d %d", &num1, &num2, &num3);
	result = num1 * num2 * num3;

	int length = getLength(result);
	char* str = new char[length];
	sprintf(str, "%d", result);
	
	int numArr[10] = { 0, };
	for (int i = 0; i < length; i++)
	{
		numArr[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", numArr[i]);
	}

	delete[] str;
	str = NULL;
	return 0;
}