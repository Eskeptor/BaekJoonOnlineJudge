#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int moveX[] = { 0, 1, 0, -1 };
int moveY[] = { -1, 0, 1, 0 };
int total = 0;

void selector(int** map, int size, int x, int y)
{
	int sizeX, sideY;
	if (x >= 0 && x < size && y >= 0 && y < size
		&& map[y][x] == 1)
	{
		total++;
		map[y][x] = 0;

		for (int k = 0; k < 4; k++)
		{
			sizeX = x + moveX[k];
			sideY = y + moveY[k];
			selector(map, size, sizeX, sideY);
		}
	}
}

void solution(int** map, int size)
{
	vector<int> v;
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			selector(map, size, x, y);
			if (total != 0)
				v.push_back(total);
			total = 0;
		}
	}

	sort(v.begin(), v.end());
	
	printf("%d\n", v.size());
	for_each(v.begin(), v.end(), [](int i) { printf("%d\n", i); });
}

int main(void)
{
	int size;
	scanf("%d", &size);

	int** map = new int*[size];
	for (int i = 0; i < size; i++)
		map[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%1d", &map[i][j]);

	solution(map, size);

	for (int i = 0; i < size; i++)
		delete[] map[i];
	delete[] map;
	map = nullptr;
	return 0;
}