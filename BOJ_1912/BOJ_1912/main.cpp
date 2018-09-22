// 아직 못품

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(int* arr, int n)
{
	if (n == 1)
	{
		printf("%d", arr[0]);
		return;
	}

	int minusCounter = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
			minusCounter++;

	if (minusCounter == n)
	{
		sort(arr, arr + n);
		printf("%d", arr[n - 1]);
		return;
	}

	vector<int> v;
	int total = 0, tmp;
	bool resetFlag = false;
	int next;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			total += arr[i];
			resetFlag = false;
		}
		else
		{
			next = i + 1;
			tmp = total + arr[i];
			if (next < n && arr[next] + tmp > 0)
			{
				if (arr[next] + tmp >= arr[next])
				{
					total += arr[i];
					resetFlag = false;
				}
				else 
				{
					total = 0;
				}
			}
			else 
			{
				if (!resetFlag)
				{
					v.push_back(total);
					total = 0;
					resetFlag = true;
				}
			}
		}
	}
	v.push_back(total);

	sort(v.begin(), v.end());
	printf("%d", v.back());
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	solution(arr, n);

	delete[] arr;
	arr = nullptr;
	return 0;
}