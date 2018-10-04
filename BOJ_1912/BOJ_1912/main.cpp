#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(vector<int> v, int line)
{
	if (line == 1)
	{
		printf("%d", v.back());
		return;
	}

	vector<int> maxV;
	vector<int> dp;
	int tmpPlusTotal = 0;
	bool isAdded = false;

	// 1차적으로 양수인 숫자는 전부 더해준 후 새로운 maxV 벡터에 넣어준다.
	// 10 -4 3 1 5 6 -35 12 21 -1
	// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	// 10 -4 15 -35 33 -1
	for (int i = 0; i < line; i++)
	{
		if (v[i] >= 0)
		{
			tmpPlusTotal += v[i];
			isAdded = true;
		}
		else
		{
			if (i != 0 && isAdded)
			{
				maxV.push_back(tmpPlusTotal);
				tmpPlusTotal = 0;
				isAdded = false;
			}
			maxV.push_back(v[i]);
		}
	}
	if (v[line - 1] >= 0)
		maxV.push_back(tmpPlusTotal);

	// 새롭게 만들어진 maxV 벡터의 길이를 구한다.
	int maxVlength = maxV.size();

	// maxV 벡터의 길이가 1인 경우에는 추가적인 연산이 필요없으므로 바로 반환한다.
	if (maxVlength < 2)
	{
		printf("%d", maxV.back());
		return;
	}
	// maxV 벡터의 길이가 원본 벡터의 길이와 같으면 모든 원소는 음수라는 것이다.
	// 그러므로 음수 중에서 가장 큰 값을 찾아서 반환한다.
	else if (maxVlength == v.size())
	{
		sort(maxV.begin(), maxV.end());
		printf("%d", maxV.back());
		return;
	}

	// DP를 이용하여 최대값을 구한다.
	dp.push_back(maxV[0]);
	dp.push_back(maxV[0] + maxV[1]);
	int max = ::max(dp[0], dp[1]);
	for (int i = 2; i < maxVlength; i++)
	{
		dp.push_back(::max(::max(maxV[i], maxV[i] + maxV[i-1]), dp[i - 1] + maxV[i]));
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d", max);
}

int main(void)
{
	int line;
	scanf("%d", &line);

	int input;
	vector<int> v;
	for (int i = 0; i < line; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	solution(v, line);

	return 0;
}