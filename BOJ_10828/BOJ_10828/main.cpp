#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

class Stack 
{
private:
	int* datas;
	int length;
	int curPoint;
public:
	Stack() :length(100000), curPoint(-1)
	{
		datas = new int[100000];
	}
	~Stack()
	{
		delete[] datas;
	}

	void push(int data)
	{
		if (curPoint < length - 1)
		{
			curPoint += 1;
			datas[curPoint] = data;
		}
	}

	int pop()
	{
		int data = -1;
		if (curPoint >= 0)
		{
			data = datas[curPoint];
			curPoint -= 1;
		}
		return data;
	}

	int top()
	{
		int data = -1;
		if (curPoint >= 0)
			data = datas[curPoint];
		return data;
	}

	int size()
	{
		return curPoint + 1;
	}

	int empty()
	{
		if (curPoint >= 0)
			return 0;
		else
			return 1;
	}
};


int main(void)
{
	int lines;
	scanf("%d", &lines);
	while (getchar() != '\n');
	Stack stack;

	string str;
	vector<string> tokens;
	
	for (int i = 0; i < lines; i++)
	{
		getline(cin, str);
		istringstream iss(str);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

		if (tokens[0] == "push")
			stack.push(atoi(tokens[1].c_str()));
		else if (tokens[0] == "top")
			printf("%d\n", stack.top());
		else if (tokens[0] == "size")
			printf("%d\n", stack.size());
		else if (tokens[0] == "empty")
			printf("%d\n", stack.empty());
		else if (tokens[0] == "pop")
			printf("%d\n", stack.pop());
		tokens.clear();
	}

	
	return 0;
}