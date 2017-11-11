#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int size;
	int cur;
	cin >> size;

	vector<pair<int, int>> v;
	for (int i = 0; i < size; i++)
	{
		cin >> cur;
		v.push_back(make_pair(cur, i));
	}

	sort(v.begin(), v.end());

	int arr[50];
	for (int i = 0; i < size; i++)
	{
		arr[v[i].second] = i;
	}

	for_each(arr, arr + size, [](int num) {cout << num << " "; });
	return 0;
}