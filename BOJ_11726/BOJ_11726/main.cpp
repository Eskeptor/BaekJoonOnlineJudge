#include <iostream>

void solution(int block)
{
	if (block == 1)
	{
		printf("1");
		return;
	}

	int* dp = new int[block + 1];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= block; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	printf("%d", dp[block]);

	delete[] dp;
	dp = nullptr;
}

int main(void)
{
	int block;
	scanf("%d", &block);
	solution(block);
	return 0;
}