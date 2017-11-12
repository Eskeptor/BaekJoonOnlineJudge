/*
https://www.acmicpc.net/problem/1924
*/

#include <iostream>
#include <string>
using namespace std;

namespace DAY {
	enum {
		Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
	};
	const int MONTH[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const string DAY[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
}

int monthToDay(const int _month, const int _day)
{
	int days = 0;
	for (int i = 0; i <= _month - 2; i++)
	{
		days += DAY::MONTH[i];
	}
	days += _day;
	return days;
}

string dayToChar(const int _days)
{
	int divDays = _days % 7;
	return DAY::DAY[divDays];
}

int main(void)
{
	int month, day;
	scanf("%d %d", &month, &day);
	
	int days = monthToDay(month, day);
	printf("%s", dayToChar(days).c_str());

	return 0;
}