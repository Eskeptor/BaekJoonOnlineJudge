/*
https://www.acmicpc.net/problem/2941
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[100] = { 0, };
	scanf("%s", str);

	int strLength = strlen(str);

	int alpha = 0;
	bool isSkip = false;
	for (int i = 0; i < strLength;)
	{
		char ch = str[i];

		switch (ch)
		{
		case 'c':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];
				if (ch2 == '=' || ch2 == '-')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		case 'd':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];

				if (ch2 == '-')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else if (ch2 == 'z')
				{
					if (i + 2 < strLength)
					{
						char ch3 = str[i + 2];
						if (ch3 == '=')
						{
							alpha++;
							i += 3;
							isSkip = true;
						}
						else
							alpha++;
					}
					else
						alpha++;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		case 'l':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];
				if (ch2 == 'j')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		case 'n':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];
				if (ch2 == 'j')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		case 's':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];
				if (ch2 == '=')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		case 'z':
			if (i + 1 < strLength)
			{
				char ch2 = str[i + 1];
				if (ch2 == '=')
				{
					alpha++;
					i += 2;
					isSkip = true;
				}
				else
					alpha++;
			}
			else
				alpha++;
			break;
		default:
			alpha++;
			break;
		}

		if (isSkip)
			isSkip = false;
		else
			i++;
	}

	printf("%d", alpha);

	return 0;
}