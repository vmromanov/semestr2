#include <stdio.h>
#include "Euler2.h"
#include "Date.h"
#include "BigNumber.h"

int main()
{  // 
	////problem 6
	//printf("enter amount of numbers\n");
	//int amount=0;
	//scanf_s("%d", &amount);
	//printf("\neuler 6 problem answer:");
	//printf("%d", Problem6(amount));
	
	////problem7
	//printf("enter prime number's number\n");
	//int number = 0;
	//scanf_s("%d", &number);
	//printf("\n");
	//printf("%d prime number is : %d", number, Problem7(number));

	////LeapYear
	//printf("enter year");
	//Date date;
	//scanf_s("%d", &date.year);

	//time difference

	/*Date earlyDate; Date lateDate;
	printf("enter year month day hour minutes seconds for earlyer date\n");
	scanf_s("%d %d %d %d %d %d", &earlyDate.year, &earlyDate.month, &earlyDate.day, &earlyDate.hour, &earlyDate.minutes, &earlyDate.seconds);

	printf("enter year month day hour minutes seconds for later date\n");
	scanf_s("%d %d %d %d %d %d", &lateDate.year, &lateDate.month, &lateDate.day, &lateDate.hour, &lateDate.minutes, &lateDate.seconds);

	TimeDifference(&earlyDate, &lateDate);*/

	//BigNUm

	char number1[] = "555555555555555555555";
	char number2[] = " 43333333333333333333";
	printf(" 555555555555555555555\n");
	printf("  33333333333333333333\n");
	BigNumber* num1 = BignumCreate(number1);
	BigNumber* num2 = BignumCreate(number2);
	PrintBN(SummBig(num1, num2));

	DeleteBN(&num1);
	DeleteBN(&num2);


	return 0;
}
















































