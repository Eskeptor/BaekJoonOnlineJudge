#include <iostream>
//										  1     2       1    2
void solution(int** arr, int n, int m, int i, int j, int x, int y)
{
	int total = 0;
	int b;

	for (int a = j - 1; a < y; a++)
	{
		if (a == j - 1)
			b = i - 1;
		else
			b = 0;

		if (a == y - 1)
			n = x;
		for (; b < n; b++)
		{
			total += arr[b][a];
		}
	}
	printf("%d\n", total);
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	int input;
	scanf("%d", &input);
	int i, j, x, y;
	for (int k = 0; k < input; k++)
	{
		scanf("%d %d %d %d", &i, &j, &x, &y);
		solution(arr, n, m, i, j, x, y);
	}


	return 0;
}