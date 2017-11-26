/*
https://www.acmicpc.net/problem/2920
*/

#include <iostream>
using namespace std;

enum Check
{
	None, Ascending, Descending, Mixed
};

int main(void)
{
	int arr[8] = { 0, };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		scanf("%d", &arr[i]);

	Check checker = Check::None;
	for (int i = 1; i < sizeof(arr) / sizeof(int) - 1; i++)
	{
		int check1 = arr[i - 1] - arr[i];
		int check2 = arr[i] - arr[i + 1];
		if (check1 == check2)
		{
			if (check1 > 0)
				checker = Check::Descending;
			else
				checker = Check::Ascending;
		}
		else if ((check1 == -7 && check2 == 1) || (check1 == 1 && check2 == -7))
			checker = Check::Descending;
		else if ((check1 == 7 && check2 == -1) || (check1 == -1 && check2 == 7))
			checker = Check::Ascending;
		else
		{
			checker = Check::Mixed;
			break;
		}
	}

	switch (checker)
	{
	case None:
		break;
	case Ascending:
		printf("ascending");
		break;
	case Descending:
		printf("descending");
		break;
	case Mixed:
		printf("mixed");
		break;
	default:
		break;
	}

	return 0;
}