#include <iostream>

int facto(int input)
{
	int total = 1;
	for (int i = 2; i <= input; i++)
	{
		total *= i;
	}
	return total;
}

int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%d", facto(input));

	return 0;
}