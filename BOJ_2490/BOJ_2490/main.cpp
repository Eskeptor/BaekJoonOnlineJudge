#include <iostream>
constexpr auto YOOT = 4;
constexpr auto LINE = 3;

void solution(int* yoot)
{
	int total = 0;
	for (int i = 0; i < YOOT; i++)
		total += yoot[i];

	switch (total)
	{
	case 0:
		printf("D\n");
		break;
	case 1:
		printf("C\n");
		break;
	case 2:
		printf("B\n");
		break;
	case 3:
		printf("A\n");
		break;
	case 4:
		printf("E\n");
		break;
	}
}

int main(void)
{
	int yoot[YOOT] = { 0, };

	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < YOOT; j++)
			scanf("%d", &yoot[j]);
		solution(yoot);
	}

	return 0;
}