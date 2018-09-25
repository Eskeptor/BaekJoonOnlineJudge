#include <iostream>

void solution(int* coins, int n, int k)
{
	int curMoney = k;
	int curPoint = 0;
	int counter = 0;

	while (curMoney != 0)
	{
		for (int i = curPoint; i < n; i++)
		{
			if (coins[i] <= curMoney)
			{
				curPoint = i;
				break;
			}
		}
			
		while (curMoney >= coins[curPoint])
		{
			curMoney -= coins[curPoint];
			counter++;
		}
	}

	printf("%d", counter);
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* coins = new int[n];
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &coins[i]);

	solution(coins, n, k);

	delete[] coins;
	coins = nullptr;
	return 0;
}