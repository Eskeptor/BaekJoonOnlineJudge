#include <iostream>

int gcd(int num1, int num2)
{
	int num3;
	while (num2 != 0)
	{
		num3 = num1 % num2;
		num1 = num2;
		num2 = num3;
	}
	return num1;
}

void lcm(int num1, int num2)
{
	int _gcd = gcd(num1, num2);
	printf("%d\n", num1 * num2 / _gcd);
}

int main(void)
{
	int lines;
	scanf("%d", &lines);

	int num1, num2;
	for (int i = 0; i < lines; i++)
	{
		scanf("%d %d", &num1, &num2);
		lcm(num1, num2);
	}

	return 0;
}