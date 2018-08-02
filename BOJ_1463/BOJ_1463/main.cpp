/*
https://www.acmicpc.net/problem/1463
*/

#include <iostream>

int counter = 0;

void calc(int _num, int _count)
{
	if (counter != 0 && counter < _count)
		return;

	if (_num > 1)
	{
		if (_num % 3 == 0)
			calc(_num / 3, _count + 1);
		if (_num > 2)
			calc(_num - 1, _count + 1);
		if (_num % 2 == 0)
			calc(_num / 2, _count + 1);
	}
	else if (_num == 1)
	{
		if (counter == 0)
			counter = _count;
		else
		{
			if (counter > _count)
				counter = _count;
		}
	}
}

int main(void)
{
	int num;
	scanf("%d", &num);
	
	calc(num, 0);
	printf("%d\n", counter);

	return 0;
}