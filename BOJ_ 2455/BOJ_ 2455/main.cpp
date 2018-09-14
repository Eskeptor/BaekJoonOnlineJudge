#include <iostream>

int main(void)
{
	int total = 0;
	int max = 0;
	int in, out;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &out, &in);

		total -= out;
		if (max < total)
			max = total;

		total += in;
		if (max < total)
			max = total;
	}
	printf("%d", max);

	return 0;
}