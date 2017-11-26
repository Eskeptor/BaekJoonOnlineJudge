/*
https://www.acmicpc.net/problem/1152
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	istringstream iss(str);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

	printf("%d", tokens.size());

	return 0;
}