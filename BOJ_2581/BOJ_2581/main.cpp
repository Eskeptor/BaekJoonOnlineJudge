#include <iostream>

void solution(int m, int n)
{
	bool arr[10001];
	for (int i = 2; i < 10001; i++)
		arr[i] = true;

	for (int i = 2; i * i < 10001; i++)
		if (arr[i])
			for (int j = 2 * i; j < 10001; j += i)
				arr[j] = false;
			
	int total = 0;
	bool isFirst = true;
	int first = 0;
	for (int i = m; i <= n; i++)
	{
		if (arr[i])
		{
			total += i;
			if (isFirst)
			{
				isFirst = false;
				first = i;
			}
		}
			
	}
	if (total)
	{
		printf("%d\n", total);
		printf("%d\n", first);
	}
	else
		printf("-1");
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	solution(m, n);
	return 0;
}