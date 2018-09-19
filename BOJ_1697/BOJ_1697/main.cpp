#include <iostream>
#include <memory.h>
#include <queue>

template <typename T>
constexpr void SafeDeleteArray(T* arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

using namespace std;

void bfs(int n, int k)
{
	if (n == k)
	{
		printf("0");
		return;
	}

	queue<int> q;
	int curPos;
	int max;
	if (n < k)
		max = k;
	else
		max = n;
	int* arr = new int[max + 2];
	memset(arr, 0, sizeof(int) * (max + 2));
	int next[3];

	q.push(n);
	arr[n] = 1;

	while (!q.empty())
	{
		curPos = q.front();
		q.pop();
		if (curPos == k)
			break;
		
		next[0] = curPos * 2;
		next[1] = curPos + 1;
		next[2] = curPos - 1;

		for (int i = 0; i < 3; i++)
		{
			if (next[i] < max + 2 && next[i] >= 0 && arr[next[i]] == 0)
			{
				arr[next[i]] = arr[curPos] + 1;
				q.push(next[i]);
			}
		}
	}

	printf("%d", arr[k] - 1);

	SafeDeleteArray<int>(arr);
}


int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	bfs(n, k);
	return 0;
}