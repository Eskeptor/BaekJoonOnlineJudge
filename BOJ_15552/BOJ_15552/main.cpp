#include <iostream>

int main(void)
{
	int lines;
	scanf("%d", &lines);

	int num1, num2;
	for (int i = 0; i < lines; i++)
	{
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1 + num2);
	}

	return 0;
}