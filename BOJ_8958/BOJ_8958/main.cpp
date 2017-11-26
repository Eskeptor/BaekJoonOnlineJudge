/*
https://www.acmicpc.net/problem/8958
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int testCase;
	char oxArr[80] = { 0, };
	scanf("%d", &testCase);
	int* scoreArr = new int[testCase] {0, };

	for (int i = 0; i < testCase; i++)
	{
		int adder = 0;
		scanf("%s", oxArr);
		for (int j = 0; j < sizeof(oxArr); j++)
		{
			if (oxArr[j] == 'O')
			{
				adder++;
				scoreArr[i] += adder;
				oxArr[j] = 0;
			}
			else
				adder = 0;
		}
	}

	for_each(scoreArr, scoreArr + testCase, [](int _num) {
		printf("%d\n", _num);
	});

	delete[] scoreArr;
	scoreArr = NULL;
	return 0;
}