/*
https://www.acmicpc.net/problem/1193
*/

#include <iostream>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	for (i = 1; num > 0; i++)
		num -= i;
	i -= 1;

	// i가 홀수인 줄은 내림차(높->낮)
	// i가 짝수인 줄은 오름차(낮->높)
	if (i % 2 == 1)
		printf("%d/%d", 1 - num, i + num);
	else
		printf("%d/%d", i + num, 1 - num);
	return 0;
}