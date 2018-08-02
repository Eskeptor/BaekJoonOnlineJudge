/*
https://www.acmicpc.net/problem/2908
*/

#include <iostream>
using namespace std;

int main(void)
{
	char chNum1[4] = { 0, };
	char chNum2[4] = { 0, };

	scanf("%s %s", chNum1, chNum2);

	int num1 = 100 * (chNum1[2] - '0') + 10 * (chNum1[1] - '0') + (chNum1[0] - '0');
	int num2 = 100 * (chNum2[2] - '0') + 10 * (chNum2[1] - '0') + (chNum2[0] - '0');

	num1 > num2 ? printf("%d", num1) : printf("%d", num2);

	return 0;
}