#include <iostream>
#include <algorithm>

void solution(int x, int y, int w, int h)
{
	int distance[4] = { 0, };
	distance[0] = x;
	distance[1] = y;
	distance[2] = w - x;
	distance[3] = h - y;
	std::sort(distance, distance + 4);
	printf("%d", distance[0]);
}

int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	solution(x, y, w, h);
	return 0;
}