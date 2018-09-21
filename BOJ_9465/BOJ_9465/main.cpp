#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOVE_X_UP[] = { -2, -2, -1 };
const int MOVE_Y_UP[] = { 0, 1, 1 };
const int MOVE_X_DOWN[] = { -2, -1, -2 };
const int MOVE_Y_DOWN[] = { 0, 0, 1 };

void solution(int** arr, int smallCase)
{
	int** dp = new int*[2];
	for (int i = 0; i < 2; i++)
		dp[i] = new int[smallCase];
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];

	int x, y;
	vector<int> tmp;
	for (int i = 1; i < smallCase; i++)
	{
		// Up side: y == 0
		for (int j = 0; j < 3; j++)
		{
			x = MOVE_X_UP[j] + i;
			y = MOVE_Y_UP[j];
			if (x >= 0 && x < smallCase)
				tmp.push_back(dp[y][x]);
			
		}
		sort(tmp.begin(), tmp.end());
		dp[0][i] = arr[0][i] + tmp.back();
		tmp.clear();

		// Down side: y == 1
		for (int j = 0; j < 3; j++)
		{
			x = MOVE_X_DOWN[j] + i;
			y = MOVE_Y_DOWN[j];
			if (x >= 0 && x < smallCase)
				tmp.push_back(dp[y][x]);
		}
		sort(tmp.begin(), tmp.end());
		dp[1][i] = arr[1][i] + tmp.back();
		tmp.clear();
	}

	sort(dp[0], dp[0] + smallCase);
	sort(dp[1], dp[1] + smallCase);
	printf("%d\n", max(dp[0][smallCase - 1], dp[1][smallCase - 1]));

	for (int i = 0; i < 2; i++)
		delete[] dp[i];
	delete[] dp;
	dp = nullptr;
}

int main(void)
{
	int bigCase, smallCase;
	scanf("%d", &bigCase);
	
	int** arr = new int*[2];

	for (int i = 0; i < bigCase; i++)
	{
		scanf("%d", &smallCase);
		for (int k = 0; k < 2; k++)
			arr[k] = new int[smallCase];
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < smallCase; k++)
				scanf("%d", &arr[j][k]);

		solution(arr, smallCase);

		for (int j = 0; j < 2; j++)
			if (arr[j])
			{
				delete[] arr[j];
				arr[j] = nullptr;
			}
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}