#include <iostream>
#include <algorithm>

void solution(int* arr, int length)
{
	int* dp = new int[length];
	dp[0] = arr[0];
	dp[1] = std::max(arr[1], arr[0] + arr[1]);
	dp[2] = std::max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < length; i++)
	{
		dp[i] = std::max(arr[i] + dp[i - 2], arr[i] + dp[i - 3] + arr[i - 1]);
	}

	printf("%d", dp[length - 1]);

	delete[] dp;
}

int main(void)
{
	int lines;
	int* arr;
	scanf("%d", &lines);

	arr = new int[lines];
	for (int i = 0; i < lines; i++)
		scanf("%d", &arr[i]);
	solution(arr, lines);

	delete[] arr;
	return 0;
}