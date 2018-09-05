/*
https://www.acmicpc.net/problem/2747
*/

#include <iostream>
#define MAX 46

int dp[MAX] = { 0, };

void solution()
{
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < MAX; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main(void)
{
	int input;
	scanf("%d", &input);
	solution();
	printf("%d", dp[input]);

	return 0;
}