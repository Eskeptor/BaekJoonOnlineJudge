#include <iostream>
#include <unordered_set>
using namespace std;

void solution(unordered_set<int> nMap, int* mArr, int mLength)
{
	unordered_set<int>::iterator iter;

	for (int i = 0; i < mLength; i++)
	{
		iter = nMap.find(mArr[i]);
		if (iter != nMap.end())
			mArr[i] = 1;
		else
			mArr[i] = 0;
	}

	for (int i = 0; i < mLength; i++)
		printf("%d\n", mArr[i]);
}

int main(void)
{
	int n, m;
	scanf("%d", &n);

	unordered_set<int> nMap;
	int input;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		nMap.insert(input);
	}

	scanf("%d", &m);
	int* mArr = new int[m];
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &input);
		mArr[i] = input;
	}

	solution(nMap, mArr, m);

	delete[] mArr;
	mArr = nullptr;

	return 0;
}