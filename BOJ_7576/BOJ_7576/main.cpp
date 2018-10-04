#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

template <typename T>
constexpr void SafeDeleteArray(T** arr, int length) noexcept
{
	if (arr)
	{
		for (int i = 0; i < length; i++)
			delete[] arr[i];
		delete[] arr;
		arr = nullptr;
	}
}

struct Point
{
	int x;
	int y;
};

int directX[] = { 0, 1, 0, -1 };	// x축으로 시계방향으로
int directY[] = { -1, 0, 1, 0 };	// y축으로 시계방향으로
int zeroCounter = 0;				// 0의 개수만큼 1이 채워졌는가 유무 판단

int spread(int** arr, int x, int y, queue<Point>* point)
{
	int result = 0;
	int sideX, sideY;
	int length = point->size();
	struct Point p;

	for (int i = 0; i < length; i++)
	{
		p = point->front();
		point->pop();

		if (arr[p.y][p.x] == 1)
		{
			for (int k = 0; k < 4; k++)
			{
				sideX = p.x + directX[k];
				sideY = p.y + directY[k];

				if (sideX >= 0 && sideX < x && sideY >= 0 && sideY < y
					&& arr[sideY][sideX] == 0)
				{
					point->push(Point());
					point->back().x = sideX;
					point->back().y = sideY;
					arr[sideY][sideX] = 1;
					result = 1;
					zeroCounter--;
				}
			}
		}
	}
	return result;
}

void solution(int x, int y)
{
	int** arr = new int*[y];
	// 1이 있는 위치를 나타내어 줄 큐
	queue<Point> point;
	for (int i = 0; i < y; i++)
	{
		arr[i] = new int[x];
		memset(arr[i], 0, sizeof(int) * x);
	}

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
		{
			scanf("%d", &arr[i][j]);

			// 1이 입력되었다면
			// 큐에 1이 입력된 지점을 넣는다.
			if (arr[i][j] == 1)
			{
				point.push(Point());
				point.back().x = j;
				point.back().y = i;
			}
			// 0이 입력되었다면
			// 제로카운터를 증가시킨다.
			else if (arr[i][j] == 0)
				zeroCounter++;
		}
			

	int result;
	int days = 0;

	while (true)
	{
		result = spread(arr, x, y, &point);
		//결과가 0이면 1로 채우지 않았다는 것이므로 while문 종료
		if (result == 0)
			break;
		days += result;
	}

	// 만약 제로카운터가 0이 되지 않았다는 것은 모든 0을 1로 바꾸지 않았다는 것이므로
	// -1로 days를 바꾼다.
	if (zeroCounter != 0)
		days = -1;
	printf("%d", days);

	SafeDeleteArray(arr, y);
}

int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);

	solution(x, y);

	return 0;
}