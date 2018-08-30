#include <iostream>
#include <cstring>
#include <stack>

void solution(char* str, int length)
{
	std::stack<char> st;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(')
			st.push('(');
		else
		{
			if (st.empty())
			{
				printf("NO\n");
				return;
			}
			else
			{
				if (st.top() == '(')
					st.pop();
				else
				{
					printf("NO\n");
					return;
				}
			}
			
		}
	}

	if (st.empty())
		printf("YES\n");
	else
		printf("NO\n");
}

int main(void)
{
	int lines;
	char str[51] = { 0, };
	scanf("%d", &lines);

	for (int i = 0; i < lines; i++)
	{
		scanf("%s", str);
		solution(str, strlen(str));
	}
	return 0;
}