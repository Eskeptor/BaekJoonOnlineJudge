#include <iostream>

void solution(int n, int m)
{
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	int* joseph = new int[n];
	int counter = m;
	int curPoint = m;
	int vi = 0;

	while (true)
	{
		if (counter == m)
		{
			joseph[vi++] = arr[curPoint];
			arr[curPoint] = 0;
			counter = 0;
		}

		if (vi == n)
			break;

		curPoint++;
		if (curPoint > n)
			curPoint = 1;
		if (arr[curPoint] != 0)
			counter++;
	}

	printf("<");
	for (int i = 0; i < n; i++)
	{
		printf("%d", joseph[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf(">");

	delete[] arr;
	delete[] joseph;
	arr = nullptr;
	joseph = nullptr;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	solution(n, m);

	return 0;
}