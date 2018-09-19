#include <iostream>
#include <vector>
using namespace std;

void solution(int* arr, int size)
{
	if (size == 1)
	{
		printf("1");
		return;
	}

	bool isIn = false;
	vector<int> v;
	v.push_back(arr[0]);

	for (int i = 1; i < size; i++)
	{
		isIn = false;
		for (int j = 0; j < v.size(); j++)
		{
			if (arr[i] <= v[j])
			{
				v[j] = arr[i];
				isIn = true;
				break;
			}
		}
		if (!isIn)
			v.push_back(arr[i]);
	}
	printf("%d", v.size());
}

int main(void)
{
	int size;
	scanf("%d", &size);

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	solution(arr, size);

	delete[] arr;
	arr = nullptr;

	return 0;
}