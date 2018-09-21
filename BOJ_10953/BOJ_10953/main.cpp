#include <iostream>

int main(void)
{
	int line;
	scanf("%d", &line);

	int num1, num2;
	for (int i = 0; i < line; i++)
	{
		scanf("%d,%d", &num1, &num2);
		printf("%d\n", num1 + num2);
	}

	return 0;
}