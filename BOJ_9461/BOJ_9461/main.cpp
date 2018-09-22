#include <iostream>

long long* arr;

void solution()
{
	arr = new long long[100];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i < 100; i++)
	{
		arr[i] = arr[i - 3] + arr[i - 2];
	}
}

int main(void)
{
	int line;
	scanf("%d", &line);

	solution();

	int input;
	for (int i = 0; i < line; i++)
	{
		scanf("%d", &input);
		printf("%lld\n", arr[input - 1]);
	}

	delete[] arr;
	arr = nullptr;
	return 0;
}