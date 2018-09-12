#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

void solution(int** arr, int com)
{
	queue<int> q;
	bool* arrEntered = new bool[com];
	for (int i = 0; i < com; i++)
		arrEntered[i] = false;
	int curCom = 0;
	int counter = 0;

	q.push(curCom);
	arrEntered[curCom] = true;

	while (!q.empty())
	{
		curCom = q.front();
		q.pop();

		for (int i = 0; i < com; i++)
		{
			if (arr[curCom][i] == 1 && !arrEntered[i])
			{
				arrEntered[i] = true;
				q.push(i);
				counter++;
			}
		}
	}

	printf("%d", counter);
}

int main(void)
{
	int com;
	scanf("%d", &com);

	int line;
	scanf("%d", &line);

	int** arr = new int*[com];
	int v1, v2;
	for (int i = 0; i < com; i++)
	{
		arr[i] = new int[com];
		memset(arr[i], 0, sizeof(int) * com);
	}

	for (int i = 0; i < line; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1 - 1][v2 - 1] = 1;
		arr[v2 - 1][v1 - 1] = 1;
	}

	solution(arr, com);

	for (int i = 0; i < com; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}