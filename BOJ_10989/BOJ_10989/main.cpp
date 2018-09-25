#include <iostream>
constexpr auto MAX = 10001;

void solution(int* nums, int max)
{
	for (int i = 1; i <= max; i++)
		if (nums[i])
			for (int j = 0; j < nums[i]; j++)
				printf("%d\n", i);
}

int main(void)
{
	int line;
	scanf("%d", &line);

	int nums[MAX] = { 0, };
	int input, max = 0;
	for (int i = 0; i < line; i++)
	{
		scanf("%d", &input);
		if (max < input)
			max = input;
		nums[input]++;
	}

	solution(nums, max);
	
	return 0;
}