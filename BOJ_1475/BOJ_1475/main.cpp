#include <iostream>
#include <cstring>
#include <algorithm>

void solution(char* num, int length)
{
	int numSet[10] = { 0, };
	int realNum;
	for (int i = 0; i < length; i++)
	{
		realNum = num[i] - '0';
		numSet[realNum]++;
	}

	numSet[6] = (numSet[6] + numSet[9] + 1) / 2;
	numSet[9] = 0;

	std::sort(numSet, numSet + 10);
	printf("%d", numSet[9]);
}

int main(void)
{
	char num[8] = { 0, };
	scanf("%s", num);

	int length = strlen(num);
	solution(num, length);

	return 0;
}