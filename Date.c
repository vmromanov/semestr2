//структура с датой, задание напис функции которые: 
// 1 - по 2м датам определяет разницу во времени, 
//2-  весокосный год или нет
//3 - функция кот считает кол-во прошедших дней от нового года 
#include <stdio.h>
#include "Date.h"

void TimeDifference(Date* OldDate, Date* NewDate)
{
	Date timeDif={0};


	/*timeDif.seconds = OldDate->seconds - NewDate->seconds;
	if (timeDif.seconds < 0) { --timeDif.minutes; timeDif.seconds += 60; }
	timeDif.minutes += OldDate->minutes - NewDate->minutes;
	if (timeDif.minutes < 0) { --timeDif.hour; timeDif.minutes += 60; }
	timeDif.hour += OldDate->hour - NewDate->hour;
	if (timeDif.hour < 0) { --timeDif.day; timeDif.hour += 60; }
	timeDif.day += OldDate->day - NewDate->day;
	if (timeDif.day < 0) { --timeDif.month; timeDif.day += 30; }
	timeDif.month += OldDate->month - NewDate->month;
	if (timeDif.month < 0) { timeDif.year=-1; timeDif.month += 12; }
	timeDif.year += (NewDate->year - OldDate->year);*/


	timeDif.year = NewDate->year - OldDate->year;
	timeDif.month = 12 - OldDate->month + (timeDif.year - 1) * 12 + NewDate->month;
	timeDif.day = 365 - untillDate(&OldDate->month) + (timeDif.year - 1) * 365 + untillDate(NewDate) + extraDaysCount(OldDate, NewDate);
	timeDif.hour = 24 - OldDate->hour + (timeDif.day - 1) * 24 + NewDate->hour;
	timeDif.minutes = 60 - OldDate->hour + (timeDif.hour - 1) * 60 + NewDate->minutes;
	timeDif.seconds = 60 - OldDate->seconds + (timeDif.minutes - 1) * 60 + NewDate->seconds;

	printf("\n\nyear:%d month:%d days:%d hours:%d minutes:%d seconds:%d", timeDif.year, timeDif.month, timeDif.day, timeDif.hour, timeDif.minutes, timeDif.seconds);

}

int extraDaysCount(Date* OldDate, Date* NewDate)
{
	int extradays = 0;
	while (OldDate->year != NewDate->year)
	{
		if (LeapYear(OldDate))
			++extradays ;
		OldDate->year++;
	}
	return extradays;
}

int Days(int month)
{
	int x = month;
	if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
		return 31;
	if (x == 2)
		return 28;
	if (x == 9 || x == 4 || x == 6 || x == 11)
		return 30;

}

int untillDate(Date* date)
{
	int days = 0;
	int x = date->month;
	for (int i = 1; i <= x; ++i)
	{
		days += Days(i);
	}
	return days;
}

int LeapYear(Date* date)
{
	if ((date->year % 400 == 0)||(date->year % 4 == 0 && date->year % 100 != 0))
		return 1;

	return 0;
}





















































//timeDif.year = NewDate->year - OldDate->year;
//timeDif.month = (12 - OldDate->month) + (timeDif.year - 1) * 12 + NewDate->month;
//timeDif.day = 365 - OldDate->day + (timeDif.year - 1) * 365 + NewDate->day;
//timeDif.hour = 24 - OldDate->hour + (timeDif.day - 1) * 24 + NewDate->hour;
//timeDif.minutes = 60 - OldDate->minutes + (timeDif.hour - 1) * 60 + NewDate->minutes;
//timeDif.seconds = 60 - OldDate->seconds + (timeDif.minutes - 1) * 60 + NewDate->seconds;
