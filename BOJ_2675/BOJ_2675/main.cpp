/*
https://www.acmicpc.net/problem/2675
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int testCase;
	scanf("%d", &testCase);

	char** str = new char*[testCase];
	int* looper = new int[testCase];
	for (int i = 0; i < testCase; i++)
	{
		str[i] = new char[20]{ 0, };
		scanf("%d %s", &looper[i], str[i]);
	}

	for (int i = 0; i < testCase; i++)
	{
		int strlength = strlen(str[i]);
		for (int j = 0; j < strlength; j++)
		{
			for (int k = 0; k < looper[i]; k++)
			{
				if (str[i][j] == '\0')
					break;
				printf("%c", str[i][j]);
			}
		}
		printf("\n");
	}

	for (int i = 0; i < testCase; i++)
		delete[] str[i];
	delete[] str;
	delete[] looper;
	return 0;
}