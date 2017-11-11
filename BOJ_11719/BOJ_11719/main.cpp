/*
https://www.acmicpc.net/problem/11719
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	/*string str;

	for (int i = 0; i < 100 && !cin.eof(); i++)
	{
		getline(cin, str);
		str.append("\0");
		if (str.empty())
			break;
		cout << str << endl;
	}
*/
	char ch;
	for (int i = 0; i < 100; i++)
	{
		while ((ch = getchar()) && ch != -1) {
			printf("%c", ch);
		}
	}
	return 0;
}