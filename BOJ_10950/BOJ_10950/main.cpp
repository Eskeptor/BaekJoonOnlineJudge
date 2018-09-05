/*
https://www.acmicpc.net/problem/10950
*/

#include <iostream>

int main()
{
	int lines;
	scanf("%d", &lines);

	int input1, input2;
	for (int i = 0; i < lines; i++)
	{
		scanf("%d %d", &input1, &input2);
		printf("%d\n", input1 + input2);
	}

	return 0;
}