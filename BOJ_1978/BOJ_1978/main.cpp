#include <stdio.h>

int solution(int num)
{
	if (num == 1)
		return 0;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}

	return 1;
}

int main(void)
{
	int lines;
	scanf("%d", &lines);

	int count = 0;
	int input;
	for (int i = 0; i < lines; i++)
	{
		scanf("%d", &input);
		count += solution(input);
	}

	printf("%d", count);

	return 0;
}
