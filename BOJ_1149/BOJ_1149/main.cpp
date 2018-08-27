#include <iostream>
#include <algorithm>


int main(void)
{
	int n;
	scanf("%d", &n);

	int** originArr = new int*[n];
	int** solArr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		originArr[i] = new int[3];
		solArr[i] = new int[3];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &originArr[i][j]);
		}

		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
				solArr[0][j] = originArr[0][j];
		}
		else
		{
			solArr[i][0] = std::min(solArr[i - 1][1], solArr[i - 1][2]) + originArr[i][0];
			solArr[i][1] = std::min(solArr[i - 1][0], solArr[i - 1][2]) + originArr[i][1];
			solArr[i][2] = std::min(solArr[i - 1][0], solArr[i - 1][1]) + originArr[i][2];
		}
	}

	int min = std::min(solArr[n - 1][0], std::min(solArr[n - 1][1], solArr[n - 1][2]));
	printf("%d", min);

	for (int i = 0; i < n; i++)
	{
		delete[] originArr[i];
		delete[] solArr[i];
	}
	delete[] originArr;
	delete[] solArr;

	return 0;
}