#include <iostream>
#include <memory.h>

template <typename T>
constexpr void SafeDeleteArray(T** arr, int length) noexcept
{
	if (arr)
	{
		for (int i = 0; i < length; i++)
			delete[] arr[i];
		delete[] arr;
		arr = nullptr;
	}
}

int directX[] = { 0, 1, 0, -1 };
int directY[] = { -1, 0, 1, 0 };
bool isComplete = true;

int spread(int** arr, int** copy, int x, int y)
{
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			copy[i][j] = arr[i][j];
	
	int result = 0;
	int sideX, sideY;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (arr[i][j] == 1 && arr[i][j] == copy[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					sideX = j + directX[k];
					sideY = i + directY[k];

					if (sideX >= 0 && sideX < x && sideY >= 0 && sideY < y
						&& arr[sideY][sideX] == 0)
					{
						arr[sideY][sideX] = 1;
						result = 1;
						isComplete = true;
					}
				}
			}

			if (arr[i][j] == 0)
				isComplete = false;
		}
	}
	return result;
}

void solution(int x, int y)
{
	int** arr = new int*[y];
	int** copy = new int*[y];
	for (int i = 0; i < y; i++)
	{
		arr[i] = new int[x];
		copy[i] = new int[x];
		memset(arr[i], 0, sizeof(int) * x);
		memset(copy[i], 0, sizeof(int) * x);
	}

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			scanf("%d", &arr[i][j]);

	int result;
	int days = 0;
	while (true)
	{
		result = spread(arr, copy, x, y);
		if (result == 0)
			break;
		days += result;
	}

	if (!isComplete)
		days = -1;
	printf("%d", days);

	SafeDeleteArray(arr, y);
	SafeDeleteArray(copy, y);
}

int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);

	solution(x, y);

	return 0;
}