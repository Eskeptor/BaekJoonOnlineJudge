#include <iostream>

int count = 0;

void solution(int input)
{
	if (input == 0)
	{
		count += 1;
		return;
	}
	else if (input < 0)
		return;
	solution(input - 1);
	solution(input - 2);
	solution(input - 3);
}

int main(void)
{
	int lines;
	int input;
	scanf("%d", &lines);

	for (int i = 0; i < lines; i++)
	{
		scanf("%d", &input);
		solution(input);
		printf("%d\n", count);
		count = 0;
	}

	return 0;
}