#include <iostream>
#include <memory.h>

using namespace std;

void solution(int* won, int size, int target)
{
	int* arr = new int[target + 1];
	memset(arr, 0, sizeof(int) * (target + 1));

	arr[0] = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j <= target; j++)
		{
			if (j - won[i] >= 0)
				arr[j] += arr[j - won[i]];
		}
	}

	/*for (int i = 0; i < target; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	printf("%d", arr[target]);

	delete[] arr;
	arr = nullptr;
}

int main(void)
{
	int size, target;
	scanf("%d %d", &size, &target);

	int* won = new int[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &won[i]);

	solution(won, size, target);

	delete[] won;
	won = nullptr;
	return 0;
}