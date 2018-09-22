#include <iostream>

void solution(int _h, int _w, int _n)
{
	int floor = _n % _h;
	int ho = _n / _h;

	if (floor == 0)
	{
		printf("%d", _h);
	}
	else
	{
		ho += 1;
		printf("%d", floor);
	}
	if (ho < 10)
		printf("0%d\n", ho);
	else
		printf("%d\n", ho);
}

int main(void)
{
	int line;
	scanf("%d", &line);

	int h, w, n;
	for (int i = 0; i < line; i++)
	{
		scanf("%d %d %d", &h, &w, &n);
		solution(h, w, n);
	}

	return 0;
}