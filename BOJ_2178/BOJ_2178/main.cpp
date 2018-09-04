#include <iostream>
#include <queue>

int** arr;

int xAdd[4] = { 0, 1, 0, -1 };
int yAdd[4] = { -1, 0, 1, 0 };


void solution(int n, int m)
{
	// 시작 지점은 무조건 0,0
	// 종료 지점은 맨 마지막 n - 1, m - 1
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(0, 0));

	int x = 0, y = 0;
	int sideX, sideY;
	while (x < m && y < n)
	{
		if (q.empty())
			break;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			sideX = x + xAdd[i];
			sideY = y + yAdd[i];

			if (sideX >= 0 && sideX < m && sideY >= 0 && sideY < n 
				&& arr[sideY][sideX] == 1)
			{
				q.push(std::make_pair(sideX, sideY));
				arr[sideY][sideX] = arr[y][x] + 1;
			}
		}
	}

	printf("%d", arr[n - 1][m - 1]);
}

int main(void)
{

	int n, m;
	scanf("%d %d", &n, &m);

	arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	char* tmp = new char[m + 1];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = (int)tmp[j] - 48;
		}
	}
	
	solution(n, m);

	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] tmp;

	return 0;
}