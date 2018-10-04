#include <iostream>
#include <cstring>

void solution(char* str, int strLength, int* alphabet)
{
	for (int i = 0; i < strLength; i++)
		alphabet[str[i] - 'a']++;
}

int main(void)
{
	int alphabet[26] = { 0, };
	char str[100];
	scanf("%s", str);

	solution(str, strlen(str), alphabet);

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);

	return 0;
}