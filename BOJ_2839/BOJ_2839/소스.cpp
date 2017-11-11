/*
https://www.acmicpc.net/problem/2839
*/

#include <iostream>
using namespace std;

int main(void)
{
	const int SUGAR_NORMAL = 3;
	const int SUGAR_BIG = 5;

	int n;
	cin >> n;

	int countN = 0;
	int countB = 0;
	
	while (true)
	{
		if (n % 5 == 0)
		{
			countB = n / 5;
			break;
		}
		else if (n < 3)
		{
			countN = -1;
			countB = 0;
			break;
		}
		n -= SUGAR_NORMAL;
		countN++;
	}

	cout << countN + countB << endl;

	return 0;
}