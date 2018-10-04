#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void solution(char* str, int length)
{
	stack<int> s;
	int total = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			s.pop();
			if (i > 0 && str[i - 1] == '(')
			{
				//이 경우는 레이저일때 () 이렇게 연달아서 올 경우이다.
				total += s.size();
			}
			else
				total += 1;
		}
	}
	printf("%d", total);
}

int main(void)
{
	char str[100001] = { 0, };
	scanf("%s", str);
	solution(str, strlen(str));
	
	return 0;
}