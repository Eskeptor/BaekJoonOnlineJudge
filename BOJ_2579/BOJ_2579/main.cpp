#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100

using namespace std;

vector<int> totalV;

int counter = 0;
int totalMax;
void solution(int* arr, int length, int start, int tot, int cont)
{
	int total = tot;
	int continueOne = cont;
	if (start == 0)
	{
		counter += 1;
		total += arr[start];
		if (counter == 1 || totalMax < total)
			totalMax = total;
		totalV.push_back(tot);

		if (totalV.size() > MAX)
		{
			totalV.clear();
			totalV.push_back(totalMax);
		}
		return;
	}
	else if (start < 0)
		return;
	total += arr[start];
	if (continueOne < 2) 
	{
		continueOne += 1;
		solution(arr, length, start - 1, total, continueOne);
	}
	else
	{
		continueOne = 0;
	}
	continueOne += 1;
	solution(arr, length, start - 2, total, continueOne);
	
}

int main(void)
{
	int lines;
	int* arr;
	scanf("%d", &lines);

	arr = new int[lines];
	for (int i = 0; i < lines; i++)
		scanf("%d", &arr[i]);
	solution(arr, lines, lines - 1, 0, 0);
	sort(totalV.begin(), totalV.end());
	printf("%d\n", totalV[totalV.size() - 1]);

	delete[] arr;

	return 0;
}