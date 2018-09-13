// 아직 못품

#include <iostream>
#include <memory>
#include <algorithm>
constexpr void SafeDeleteArray(int* arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}
constexpr void SafeDeleteArray(int** arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void solution(int* arr, int length)
{
	if (length == 1)
	{
		printf("%d", arr[0]);
		return;
	}

	int* dp = new int[length];
	memset(dp, 0, sizeof(int) * length);

	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			dp[i] = std::max(dp[i], dp[i - j] + arr[j]);
	printf("%d", dp[length - 1]);
	SafeDeleteArray(dp);
}

int main(void)
{
	int input;
	scanf("%d", &input);
	int* arr = new int[input];
	for (int i = 0; i < input; i++)
		scanf("%d", &arr[i]);
	
	solution(arr, input);

	SafeDeleteArray(arr);
	return 0;
}