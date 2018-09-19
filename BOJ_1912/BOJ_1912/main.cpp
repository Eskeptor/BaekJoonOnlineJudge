// 아직 못품

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
constexpr void SafeDeleteArray(T* arr) noexcept
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}


void solution(int* arr, int n)
{
	if (n == 1)
	{
		printf("%d", arr[0]);
		return;
	}

	int lineAdder = arr[0];
	int max = arr[0];
	bool isContinue = true;


	for (int i = 1; i < n; i++)
	{
		
	}
}

void autoRandom(int* arr, int length)
{
	int flag;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++)
	{
		flag = rand() % 2 == 0 ? -1 : 1;
		arr[i] = rand() % 1000 * flag;
		_sleep(1);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	//autoRandom(arr, n);

	solution(arr, n);

	SafeDeleteArray(arr);
	return 0;
}