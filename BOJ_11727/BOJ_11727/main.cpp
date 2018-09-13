#include <iostream>
#include <memory.h>

constexpr void SafeDeleteArray(int* arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void solution(int n)
{
	if (n == 1)
	{
		printf("1");
		return;
	}

	int* dp = new int[n + 1];
	memset(dp, 0, sizeof(int) * (n + 1));

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	printf("%d", dp[n]);

	SafeDeleteArray(dp);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	solution(n);
	return 0;
}