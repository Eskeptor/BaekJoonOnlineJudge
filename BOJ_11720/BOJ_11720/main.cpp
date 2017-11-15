/*
https://www.acmicpc.net/problem/11720
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char ch[100] = { 0, };
	scanf("%s", ch);

	int length = strlen(ch);

	for (int i = 0; i < length; i++)
	{
		if (i != 0 && i % 10 == 0)
			printf("\n");
		printf("%c", ch[i]);
	}

	return 0;
}