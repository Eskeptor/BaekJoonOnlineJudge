#include <iostream>
using namespace std;

int zeroCnt = 0;
int oneCnt = 0;

int fibo(int _num)
{
	if (_num == 0) 
	{
		zeroCnt++;
		return 0;
	}
	else if (_num == 1) 
	{
		oneCnt++;
		return 1;
	}
	else 
	{
		return fibo(_num - 1) + fibo(_num - 2);
	}
}


int main(void) 
{
	int cnt = 0;
	cin >> cnt;
	int *arr_cnt = new int[cnt];
	int **arr = new int*[cnt];

	for (int i = 0; i < cnt; i++) 
	{
		cin >> arr_cnt[i];
		if (arr_cnt[i] > 40 || arr_cnt[i] < 0) 
		{
			cout << "잘못된 입력" << endl;
			i--;
		}
		arr[i] = new int[2];
	}
	for (int i = 0; i < cnt; i++)
	{
		fibo(arr_cnt[i]);
		arr[i][0] = zeroCnt;
		arr[i][1] = oneCnt;
		zeroCnt = 0;
		oneCnt = 0;
	}
	for (int i = 0; i < cnt; i++) 
	{
		for (int j = 0; j < 2; j++) 
		{
			cout << arr[i][j];
			cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < cnt; i++) 
	{
		delete[] arr[i];
	}
	delete[] arr;
	delete[] arr_cnt;
	return 0;
}
