#include <iostream>

int main(void)
{
	int star;
	scanf("%d", &star);

	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < star - 1 - i; j++)
			printf(" ");

		for (int j = 0; j < i * 2 + 1; j++)
			printf("*");
		
		printf("\n");
	}

	return 0;
}