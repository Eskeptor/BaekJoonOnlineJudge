#include <iostream>
constexpr void SafeDeleteArray(bool* arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void solution(int start, int end)
{
	bool* arr = new bool[end + 1];
	for (int i = 0; i < end + 1; i++)
		arr[i] = false;
	arr[1] = true;

	for (int i = 2; i * i <= end; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; j * i <= end; j++)
				arr[j * i] = true;
		}
	}

	for (int i = start; i <= end; i++)
	{
		if (!arr[i])
			printf("%d\n", i);
	}

	SafeDeleteArray(arr);
}

int main(void)
{
	int start, end;
	scanf("%d %d", &start, &end);
	solution(start, end);

	return 0;
}