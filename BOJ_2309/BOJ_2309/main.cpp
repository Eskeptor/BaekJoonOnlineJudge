#include <iostream>
#include <algorithm>
#define MAX 9

void solution(int* arr)
{
	int total = 0;
	for (int i = 0; i < MAX; i++)
		total += arr[i];

	int decValue = total - 100;
	int dec1, dec2;
	bool breakFlag = false;
	
	for (int i = 0; i < MAX; i++)
	{
		dec1 = i;
		for (int j = 0; j < MAX; j++)
		{
			if (i == j)
				continue;
			dec2 = j;

			if (arr[dec1] + arr[dec2] == decValue)
			{
				breakFlag = true;
				break;
			}
		}
		if (breakFlag)
			break;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (i != dec1 && i != dec2)
			printf("%d\n", arr[i]);
	}
}

int main(void)
{
	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + MAX);
	solution(arr);

	return 0;
}