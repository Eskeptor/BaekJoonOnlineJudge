/*
https://www.acmicpc.net/problem/1026
*/

#include <iostream>
#include <algorithm>
#define MAX_ARR 2
using namespace std;

int main(void)
{
	int size;
	cin >> size;

	int* arr1 = new int[size];
	int* arr2 = new int[size];

	for (int i = 0; i < size; i++)
		cin >> arr1[i];

	for (int i = 0; i < size; i++)
		cin >> arr2[i];

	sort(arr1, arr1 + size);
	sort(arr2, arr2 + size);

	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += arr1[i] * arr2[size - 1 - i];
	}
	cout << result << endl;

	delete[] arr1;
	delete[] arr2;
	return 0;
}