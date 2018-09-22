#include <iostream>

void solution(int star)
{
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < i; j++)
			printf(" ");

		for (int j = 0; j < (star - i) * 2 - 1; j++)
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