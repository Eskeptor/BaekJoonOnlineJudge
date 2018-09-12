#include <iostream>

void solution(int pibo)
{
	long long* dp = new long long[pibo + 1];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < pibo + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[pibo]);

	delete[] dp;
}

int main(void)
{
	int pibo;
	scanf("%d", &pibo);
	solution(pibo);

	return 0;
}