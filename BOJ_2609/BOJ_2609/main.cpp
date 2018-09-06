#include <iostream>

int gcd(int num1, int num2)
{
	int mod;
	while (num2)
	{
		mod = num1 % num2;
		num1 = num2;
		num2 = mod;
	}
	return num1;
}

int lcm(int num1, int num2, int gcdV)
{
	return num1 * num2 / gcdV;
}

int main(void)
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	int resultGCD = gcd(num1, num2);
	int resultLCM = lcm(num1, num2, resultGCD);

	printf("%d\n%d", resultGCD, resultLCM);

	return 0;
}