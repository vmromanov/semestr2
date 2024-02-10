//структура с датой, задание напис функции которые: 
// 1 - по 2м датам определяет разницу во времени, 
//2-  весокосный год или нет
//3 - функция кот считает кол-во прошедших дней от нового года 
#include <stdio.h>
#include "Date.h"

int TimeDifference(Date* date1, Date* date2)
{
	Date date3;
	if (date2->seconds - date1->seconds < 0)
	{
		date2->minutes--;
		date3.seconds = 60 + (date2->seconds - date1->seconds);
	}
	else date3.seconds = date2->seconds - date1->seconds;

	if (date2->minutes - date1->minutes < 0)
	{
		date2->hour--;
		date3.minutes = 60 + (date2->minutes - date1->minutes);
	}
	else date3.minutes = date2->minutes - date1->minutes;

	if (date2->hour - date1->hour < 0)
	{
		date2->day--;
		date3.hour = 60 + (date2->hour - date1->hour);
	}
	else date3.hour = date2->hour - date1->hour;

	
}
 //31d - 1,3,5,7,8,10,12
//30d - 4,6,9,11
//28/29d - 2



int LeapYear(Date* date)
{
	if ((date->year % 400 == 0)||(date->year % 4 == 0 && date->year % 100 != 0))
		return 1;

	return 0;
}

int FromNewYear(Date* date)
{

}