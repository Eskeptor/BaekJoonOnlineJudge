/*
https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

void dfs(int** arr, int length, int start)
{
	bool* enter = new bool[length];
	for (int i = 0; i < length; i++)
		enter[i] = false;
	bool isEnter = false;
	stack<int> st;
	int curPointer = 0;
	int enterCounter = 0;

	st.push(start - 1);
	enter[start - 1] = true;
	enterCounter++;

	printf("%d ", start);

	while (!st.empty())
	{
		curPointer = st.top();
		isEnter = false;

		for (int i = 0; i < length; i++)
		{
			if (arr[curPointer][i] == 1 && !enter[i])
			{
				st.push(i);
				enterCounter++;
				isEnter = true;
				enter[i] = true;

				printf("%d", i + 1);
				if (enterCounter == length)
					printf("\n");
				else
					printf(" ");
				break;
			}
		}

		if (!isEnter)
		{
			st.pop();
		}
	}

	delete[] enter;
}

void bfs(int** arr, int length, int start)
{
	bool* enter = new bool[length];
	for (int i = 0; i < length; i++)
		enter[i] = false;
	queue<int> q;
	int curPoint;
	int enterCounter = 0;

	q.push(start - 1);
	enter[start - 1] = true;
	enterCounter++;

	while (!q.empty())
	{
		curPoint = q.front();
		q.pop();
		printf("%d", curPoint + 1);
		if (enterCounter != length)
			printf(" ");

		for (int i = 0; i < length; i++)
		{
			if (arr[curPoint][i] == 1 && !enter[i])
			{
				q.push(i);
				enter[i] = true;
			}
		}
	}

	delete[] enter;
}

int main(void)
{
	// n : 정점의 개수
	// m : 간선의 개수
	// v : 시작 정점의 번호
	int n, m, v;
	int** arr;


	scanf("%d %d %d", &n, &m, &v);

	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		memset(arr[i], 0, sizeof(int) * n);
	}

	int v1, v2;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1 - 1][v2 - 1] = 1;
		arr[v2 - 1][v1 - 1] = 1;
	}


	dfs(arr, n, v);
	bfs(arr, n, v);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}