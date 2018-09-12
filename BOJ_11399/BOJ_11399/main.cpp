#include <iostream>
#include <algorithm>

int main(void)
{
	int line;
	scanf("%d", &line);
	
	int* arr = new int[line];
	for (int i = 0; i < line; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + line, std::greater<int>());

	int total = 0;
	for (int i = 0; i < line; i++)
		for (int j = 0; j <= i; j++)
			total += arr[i];

	printf("%d", total);

	delete[] arr;
	return 0;
}