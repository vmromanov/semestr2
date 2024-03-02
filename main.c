#include <stdio.h>
#include "Euler2.h"
#include "Date.h"


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

	Date earlyDate; Date lateDate;
	printf("enter year month day hour minutes seconds for earlyer date\n");
	scanf_s("%d %d %d %d %d %d", &earlyDate.year, &earlyDate.month, &earlyDate.day, &earlyDate.hour, &earlyDate.minutes, &earlyDate.seconds);

	printf("enter year month day hour minutes seconds for later date\n");
	scanf_s("%d %d %d %d %d %d", &lateDate.year, &lateDate.month, &lateDate.day, &lateDate.hour, &lateDate.minutes, &lateDate.seconds);

	TimeDifference(&earlyDate, &lateDate);

}
















































