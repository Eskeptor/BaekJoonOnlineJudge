#include <iostream>
#include <string>
/*
https://www.acmicpc.net/problem/10845
*/

#include <sstream>
#include <vector>
#include <iterator>
#define MAX 10000

using namespace std;

class Queue
{
private:
	int arr[MAX];
	int frontPos;
	int backPos;
	int _size;
public:
	Queue() : frontPos(0), backPos(0), _size(0) {}

	void push(int value)
	{
		if (_size < MAX)
		{
			arr[backPos++] = value;
			_size++;
		}
	}

	int pop()
	{
		if (_size < 1)
			return -1;

		int tmp = arr[frontPos];
		frontPos++;
		_size--;
		return tmp;
	}

	int empty()
	{
		if (_size > 0)
			return 0;
		return 1;
	}

	int front()
	{
		if (_size > 0)
			return arr[frontPos];
		return -1;
	}

	int back()
	{
		if (_size > 0)
			return arr[backPos - 1];
		return -1;
	}

	int size()
	{
		return _size;
	}
};

int main(void)
{
	Queue queue;
	int lines;
	scanf("%d", &lines);
	while (getchar() != '\n');

	string str;
	vector<string> tokens;
	for (int i = 0; i < lines; i++)
	{
		getline(cin, str);
		istringstream iss(str);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

		if (tokens[0] == "push")
			queue.push(atoi(tokens[1].c_str()));
		else if (tokens[0] == "front")
			printf("%d\n", queue.front());
		else if (tokens[0] == "back")
			printf("%d\n", queue.back());
		else if (tokens[0] == "size")
			printf("%d\n", queue.size());
		else if (tokens[0] == "empty")
			printf("%d\n", queue.empty());
		else if (tokens[0] == "pop")
			printf("%d\n", queue.pop());
		tokens.clear();
	}


	return 0;
}