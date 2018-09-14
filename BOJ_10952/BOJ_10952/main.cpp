#include <iostream>

int main(void)
{
	int num1, num2;
	while (true)
	{
		scanf("%d %d", &num1, &num2);
		if (!num1 && !num2)
			break;
		printf("%d\n", num1 + num2);
	}
	return 0;
}