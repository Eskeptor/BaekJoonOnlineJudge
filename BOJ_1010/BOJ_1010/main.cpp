#include <iostream>
constexpr auto MAX = 30;

int dp[MAX][MAX] = { 0, };
void solution()
{
	int tmp;
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			if (i == 1)
				dp[i][j] = j;
			else if (i == j)
				dp[i][j] = 1;
			else if (j < i)
				continue;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}
}

int main(void)
{
	int line;
	scanf("%d", &line);
	solution();

	int west, east;
	for (int i = 0; i < line; i++)
	{
		scanf("%d %d", &west, &east);
		printf("%d\n", dp[west][east]);
	}

	return 0;
}