/*
https://www.acmicpc.net/problem/10809
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int alphabet[26];
	fill_n(alphabet, 26, -1);
	char input[100] = { 0, };
	scanf("%s", input);

	int index;
	for (int i = 0; i < sizeof(input); i++)
	{
		index = input[i] - 'a';
		if (alphabet[index] == -1)
			alphabet[index] = i;
	}

	for_each(alphabet, alphabet + 26, [](int _num) {
		printf("%d ", _num);
	});

	return 0;
}