#include <iostream>

void solution(int star)
{
	for (int i = 0; i < star; i++)
	{
		for (int j = star - 1 - i; j > 0; j--)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}

	star--;
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j <= i; j++)
			printf(" ");
		for (int j = 2 * (star - i) - 1; j > 0; j--)
			printf("*");
		printf("\n");
	}
}

int main(void)
{
	int star;
	scanf("%d", &star);

	solution(star);

	return 0;
}