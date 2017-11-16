/*
https://www.acmicpc.net/problem/11720
*/

#include <iostream>
using namespace std;

int main(void)
{
	int size;
	scanf("%d", &size);

	char* arr = new char[size + 1];
	int total = 0;
	scanf("%s", arr);
	for (int i = 0; i < size; i++)
		total += arr[i] - 48;
	printf("%d", total);
	delete[] arr;
	return 0;
}