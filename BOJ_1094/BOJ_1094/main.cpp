#include <iostream>

void solution(int input)
{
	int x = input;
	int div = 64;
	int count = 0;
	while (x > 0)
	{
		if (div > x)
			div /= 2;
		else
		{
			x -= div;
			count++;
		}
	}

	printf("%d", count);
}

int main(void)
{
	int input;
	scanf("%d", &input);
	solution(input);
	return 0;
}