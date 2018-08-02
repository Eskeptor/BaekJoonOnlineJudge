/*
https://www.acmicpc.net/problem/5622
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[16] = { 0, };
	scanf("%s", str);

	int strLength = strlen(str);
	int total = 0;
	for (int i = 0; i < strLength; i++)
	{
		char ch = str[i];
		switch (ch)
		{
		case 65: case 66: case 67:
			total += 3;
			break;
		case 68: case 69: case 70:
			total += 4;
			break;
		case 71: case 72: case 73:
			total += 5;
			break;
		case 74: case 75: case 76:
			total += 6;
			break;
		case 77: case 78: case 79:
			total += 7;
			break;
		case 80: case 81: case 82: case 83:
			total += 8;
			break;
		case 84: case 85: case 86:
			total += 9;
			break;
		case 87: case 88: case 89: case 90:
			total += 10;
			break;
		default:
			break;
		}
	}
	printf("%d", total);

	return 0;
}