/*
https://www.acmicpc.net/problem/11718
*/
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	while (true)
	{
		getline(cin, str);
		if (str == "" || str.empty() || str == "\n")
			break;
		cout << str << endl;
	}

	return 0;
}