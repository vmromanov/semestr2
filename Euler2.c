#include <math.h>


int Problem6(int n)
{
	int summ = 0;
	int summsq = 0;
	for (int i = 1; i <= n; i++)
	{
		summ += i;
		summsq += i * i;

	}
	summ = summ * summ;

	return abs(summsq - summ);
}

int Prime(int a)
{
	if (a % 2 == 0)
		return 0;

	for (int i = 3; i * i <= a; i+=2)
		if (a % i == 0)
			return 0;

	return 1;
}

int Problem7(int number)
{
	if (number == 1) { return 2; }
	else 
	{
		int amount = 1; // 2 - prime
		int primeNum = 3;
		while (amount < number)
		{
			if (Prime(primeNum) == 1) amount++;
			if (amount == number) break;
			primeNum += 2;
		}

		return primeNum;
	}
}