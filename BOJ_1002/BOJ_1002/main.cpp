// 틀린 문제
// 왜 틀린지 모르겠음
/*
https://www.acmicpc.net/problem/1002
*/

#include <iostream>
#include <cmath>
#define MAX 10000
#define BLENGTH 6
using namespace std;

int CountPosition(const int* _pos)
{
	if (_pos[0] == _pos[3] && _pos[1] == _pos[4] && _pos[2] == _pos[5])
		return -1;
	else if (_pos[0] == _pos[3] && _pos[1] == _pos[4] && _pos[2] != _pos[5])
		return 0;

	int distance1To2 = (int)sqrt((_pos[0] - _pos[3])*(_pos[0] - _pos[3]) + (_pos[1] - _pos[4])*(_pos[1] - _pos[4]));
	int maxDistance1And2 = _pos[2] > _pos[5] ? _pos[2] : _pos[5];
	int minDistance1And2 = _pos[2] > _pos[5] ? _pos[5] : _pos[2];

	if (distance1To2 > maxDistance1And2)
	{
		if (_pos[2] + _pos[5] > distance1To2)
			return 2;
		else if (_pos[2] + _pos[5] == distance1To2)
			return 1;
		else
			return 0;
	}
	else if (distance1To2 < maxDistance1And2)
	{
		if (minDistance1And2 + distance1To2 > maxDistance1And2)
			return 2;
		else if (minDistance1And2 + distance1To2 == maxDistance1And2)
			return 1;
		else
			return 0;
	}
	else
	{
		if (minDistance1And2 == 0)
			return 1;
		return 2;
	}
}

int main(void)
{
	int testSize;
	cin >> testSize;
	int** pos = new int*[testSize];
	for (int i = 0; i < testSize; i++)
	{
		pos[i] = new int[BLENGTH];
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3] >> pos[i][4] >> pos[i][5];
	}

	for (int i = 0; i < testSize; i++)
	{
		cout << CountPosition(pos[i]) << endl;
	}

	for (int i = 0; i < testSize; i++)
	{
		delete[] pos[i];
	}
	delete[] pos;
	return 0;
}