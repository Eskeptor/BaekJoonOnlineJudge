/*
¿€º∫¡ﬂ...
https://www.acmicpc.net/problem/2448
*/

#include <iostream>
#include <string>
#define SHIFT 3
using namespace std;

bool isK(const int _num)
{
	for (int k = 0; k <= 10; k++)
	{
		if (_num == 3 * (int)pow(2, k))
			return true;
	}
	return false;
}

void printStar(const int _num)
{
	char shape[3][6] = { "  *  ", " * * " , "*****" };
	int triangleIdx = _num / SHIFT;
	string* triangle = new string[_num];

	triangle[0] = shape[0];
	triangle[1] = shape[1];
	triangle[2] = shape[2];

	int n = 0;
	for (int i = 0; i < triangleIdx; i++)
	{
		for (int j = 0; j < SHIFT; j++)
		{
			int index = j + (i * 3);
			if (isK(index))
				n = 0;
			if (i != 0)
				triangle[index] = string(triangle[n]).append(" ").append(triangle[n]);
			n++;
		}
	}

	for (int i = 0; i < triangleIdx; i++)
	{
		for (int j = 0; j < SHIFT; j++)
		{
			int index = j + (i * 3);
			if (i < triangleIdx / 2)
			{
				string blank;
				for (int k = 0; k < _num / 2; k++)
					blank.append(" ");
				triangle[index] = string(blank).append(triangle[index]);
			}
		}
	}


	for (int i = 0; i < _num; i++)
	{
		printf("%s\n", triangle[i].c_str());
	}

	delete[] triangle;
}


int main(void)
{
	int num;
	scanf("%d", &num);
	printStar(num);
	return 0;
}