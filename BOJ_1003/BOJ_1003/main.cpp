/*
https://www.acmicpc.net/problem/1003
*/

#include <iostream>
#define MAX 41

int arr[MAX] = { 1,1 };

int fibo(int _num)
{
	if (_num <= 1)
		return arr[_num];
	else if (arr[_num] > 0)
		return arr[_num];
	arr[_num] = fibo(_num - 1) + fibo(_num - 2);

	return arr[_num];
}


int main(void)
{
	int lines, input;
	scanf("%d", &lines);

	fibo(40);
	for (int i = 0; i < lines; i++)
	{
		scanf("%d", &input);
		if (input == 0)
			printf("1 0\n");
		else if (input == 1)
			printf("0 1\n");
		else
			printf("%d %d\n", arr[input - 2], arr[input - 1]);
	}
	return 0;
}
