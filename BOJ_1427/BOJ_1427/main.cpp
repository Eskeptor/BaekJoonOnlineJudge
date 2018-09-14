#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solution(string str)
{
	sort(str.begin(), str.end(), greater<int>());
	cout << str;
}

int main(void)
{
	string str;
	cin >> str;

	/*int i;
	while ((i = str.find('0')) != -1)
	{
		str.erase(i, 1);
	}*/
	solution(str);

	return 0;
}