/*
https://www.acmicpc.net/problem/1316
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int testCase;
	scanf("%d", &testCase);

	int cnt = 0;

	char** str = new char*[testCase];
	for (int i = 0; i < testCase; i++) 
	{
		str[i] = new char[100]{ 0, };
		scanf("%s", str[i]);

		char tmp[100] = { 0, };
		int strLength = strlen(str[i]);
		int tmpIdx = 0;
		bool noRepeat = false;
		for (int j = 0; j < strLength; j++)
		{
			
			if (j != 0)
			{
				for (int t = 0; t < tmpIdx; t++)
				{
					if (tmp[t] == str[i][j])
					{
						if (str[i][j - 1] == str[i][j])
							break;
						else
						{
							noRepeat = true;
							break;
						}
					}
					if (t == tmpIdx - 1)
					{
						tmp[tmpIdx++] = str[i][j];
						break;
					}
				}
				if (noRepeat)
					break;
			}
			else 
				tmp[tmpIdx++] = str[i][j];
		}

		if (!noRepeat)
			cnt++;
		noRepeat = false;
		
		delete[] str[i];
	}

	printf("%d", cnt);

	delete[] str;
	return 0;
}