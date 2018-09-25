#include <iostream>

void solution(int star)
{
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		for (int j = 0; j < (star - i - 1) * 2; j++)
			printf(" ");
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}

	for (int i = 0; i < star - 1; i++)
	{
		for (int j = 0; j < star - i - 1; j++)
			printf("*");
		for (int j = 0; j < (i + 1) * 2; j++)
			printf(" ");
		for (int j = 0; j < star - i - 1; j++)
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