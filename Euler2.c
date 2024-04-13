#include <math.h>
#include "BigNumber.h"

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

int Prime(unsigned int a)
{
	if (a == 2) return 1;

	if (a % 2 == 0)
		return 0;

	for (unsigned long long i = 3; i * i <= a; i+=2)
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

int problem8(BigNumber* num_)
{
	int max = 0;
	for (int i = 0; i < num_->size - 14; ++i)
	{
		int multiple = 1;
		for (int j = i; j < i + 13; ++j)
		{
			multiple = multiple*(num_->digits[j]);
		}
		if (multiple > max) max = multiple;
	}

	return max;
}


int is_Pythagoras(int* a, int* b, int* c)
{
	return ((*a) * (*a) + (*b) * (*b) == (*c) * (*c));
}

int is_Special(int* a, int*b, int* c)
{
	return ((*a) + (*b) + (*c) == 1000);
}

int problem9(int sp)
{
	int a, b, c, anb;
	for (c = sp - 2; c > 0; --c)
	{
		anb = sp - c;
		for (b = anb; b > 0; --b)
		{
			a = anb - b;
			if (a > b)break;
			if (is_Pythagoras(&a, &b, &c) && is_Special(&a, &b, &c) && a < b && b < c)
				return (a * b * c);
		}
	}
	return -1;
}



