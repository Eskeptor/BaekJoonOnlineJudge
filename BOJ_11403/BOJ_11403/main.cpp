#include <iostream>
#include <queue>
using namespace std;

void clearQueue(queue<int> &q)
{
	queue<int> empty;
	swap(q, empty);
}

void printArr(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void bfs(int** arr, int n)
{
	queue<int> q;
	int curPos;
	bool* enterArr = new bool[n];
	for (int i = 0; i < n; i++)
		enterArr[i] = false;

	for (int i = 0; i < n; i++)
	{
		q.push(i);

		while (!q.empty())
		{
			curPos = q.front();
			q.pop();

			for (int j = 0; j < n; j++)
			{
				if (arr[curPos][j] == 1 && !enterArr[j])
				{
					q.push(j);
					arr[i][j] = 1;
					enterArr[j] = true;
				}
			}
		}
		clearQueue(q);
		for (int i = 0; i < n; i++)
			enterArr[i] = false;
	}
	printArr(arr, n);

	delete[] enterArr;
	enterArr = nullptr;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	bfs(arr, n);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;

	return 0;
}