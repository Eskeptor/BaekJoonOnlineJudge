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

int directX[] = { 0, 1, 0, -1 };	// x������ �ð��������
int directY[] = { -1, 0, 1, 0 };	// y������ �ð��������
int zeroCounter = 0;				// 0�� ������ŭ 1�� ä�����°� ���� �Ǵ�

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
	// 1�� �ִ� ��ġ�� ��Ÿ���� �� ť
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

			// 1�� �ԷµǾ��ٸ�
			// ť�� 1�� �Էµ� ������ �ִ´�.
			if (arr[i][j] == 1)
			{
				point.push(Point());
				point.back().x = j;
				point.back().y = i;
			}
			// 0�� �ԷµǾ��ٸ�
			// ����ī���͸� ������Ų��.
			else if (arr[i][j] == 0)
				zeroCounter++;
		}
			

	int result;
	int days = 0;

	while (true)
	{
		result = spread(arr, x, y, &point);
		//����� 0�̸� 1�� ä���� �ʾҴٴ� ���̹Ƿ� while�� ����
		if (result == 0)
			break;
		days += result;
	}

	// ���� ����ī���Ͱ� 0�� ���� �ʾҴٴ� ���� ��� 0�� 1�� �ٲ��� �ʾҴٴ� ���̹Ƿ�
	// -1�� days�� �ٲ۴�.
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