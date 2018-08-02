/*
https://www.acmicpc.net/problem/1157
*/

#include <iostream>
#include <cstring>
using namespace std;

class Word 
{
private:
	char ch;
	int cnt;
public:
	Word(const char& _ch = 0) :ch(_ch), cnt(1) {}
	void setChar(const char& _ch)
	{
		ch = _ch;
	}
	void addCnt()
	{
		cnt++;
	}
	char getChar() const
	{
		return ch;
	}
	int getCnt() const
	{
		return cnt;
	}
};

int main(void) {
	char str[1000000] = { 0, };
	scanf("%s", str);

	bool isSame = false;
	int strLength = strlen(str);
	int wordsIdx = 0;
	Word* words = new Word[strLength];

	char tmp2 = str[0];
	if (tmp2 > 90)
		tmp2 -= 32;
	words[0] = Word(tmp2);
	for (int i = 1; i < strLength; i++)
	{
		char tmp2 = str[i];
		isSame = false;
		if (tmp2 > 90)
			tmp2 -= 32;
		for (int j = 0; j <= wordsIdx; j++)
		{
			if (tmp2 == words[j].getChar())
			{
				words[j].addCnt();
				isSame = true;
				break;
			}
		}
		if (!isSame)
		{
			words[++wordsIdx] = Word(tmp2);
		}
	}

	int max1 = 0;
	int max2 = -1;
	if (wordsIdx > 0)
	{
		for (int i = 1; i <= wordsIdx; i++)
		{
			if (words[max1].getCnt() < words[i].getCnt())
			{
				max2 = max1;
				max1 = i;
			}
			else
			{
				if (words[max2].getCnt() < words[i].getCnt())
				{
					max2 = i;
				}
			}
		}
	}

	if (words[max1].getCnt() == words[max2].getCnt())
		printf("?");
	else
		printf("%c", words[max1].getChar());

	delete[] words;
	return 0;
}