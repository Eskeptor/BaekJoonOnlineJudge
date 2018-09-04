#include <iostream>

void solution(int input)
{
	if (input <= 2)
	{
		printf("1");
		return;
	}

	long long* arr = new long long[input];
	arr[0] = 1, arr[1] = 1;

	for (int i = 2; i < input; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	printf("%lld", arr[input - 1]);

	delete[] arr;
}

int main(void)
{
	int input;
	scanf("%d", &input);
	solution(input);
	return 0;
}