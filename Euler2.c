#include <stdlib.h>
#include <math.h>
#include <string.h>
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

	for (unsigned long long i = 3; i <= sqrt(a) + 1; i+=2)
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

unsigned long long problem8(BigNumber* num_)
{
	unsigned long long max = 0;
	unsigned long long multiple = 1;
	for (int i = 0; i < (num_->size) - 13; ++i)
	{
		multiple = 1;
		for (int j = 0; j < 13; ++j)
		{
			multiple = multiple * ((num_->digits)[j + i]);
		}
		if (multiple > max) { max = multiple; }
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

unsigned long long problem10(int n)
{
	unsigned long long summ = 0;
	char* arr = (char*)(calloc(n,sizeof(int)));
	if (arr == NULL)
		return 0;

	for (int i = 2; i<n; ++i)
		arr[i] = 1;

	for (int i = 2; i * i <= n; ++i)
		if (arr[i] == 1)
			for (int j = (i) * (i); j <= n; j += (i))
				arr[j] = 0;

	for (int i = 2; i < n; ++i)
		if (arr[i] == 1)summ += i;
	return summ;
}













