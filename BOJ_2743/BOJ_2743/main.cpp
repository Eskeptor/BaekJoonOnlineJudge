#include <iostream>

int solution(char* str)
{
	int length = 0;
	int i = 0;
	if (str)
		while (str[i++] != '\0')
			length++;
		
	
	return length;
}

int main(void)
{
	char str[101] = { 0, };
	scanf("%s", str);
	printf("%d", solution(str));

	return 0;
}