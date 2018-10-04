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

	// 1�������� ����� ���ڴ� ���� ������ �� ���ο� maxV ���Ϳ� �־��ش�.
	// 10 -4 3 1 5 6 -35 12 21 -1
	// ��������������������������
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

	// ���Ӱ� ������� maxV ������ ���̸� ���Ѵ�.
	int maxVlength = maxV.size();

	// maxV ������ ���̰� 1�� ��쿡�� �߰����� ������ �ʿ�����Ƿ� �ٷ� ��ȯ�Ѵ�.
	if (maxVlength < 2)
	{
		printf("%d", maxV.back());
		return;
	}
	// maxV ������ ���̰� ���� ������ ���̿� ������ ��� ���Ҵ� ������� ���̴�.
	// �׷��Ƿ� ���� �߿��� ���� ū ���� ã�Ƽ� ��ȯ�Ѵ�.
	else if (maxVlength == v.size())
	{
		sort(maxV.begin(), maxV.end());
		printf("%d", maxV.back());
		return;
	}

	// DP�� �̿��Ͽ� �ִ밪�� ���Ѵ�.
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