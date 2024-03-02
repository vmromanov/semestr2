#pragma once

/**
 * @brief Дата
*/
typedef struct Date
{
	 int year;		 /// Год
	 int month;     /// Месяц
	 int day;       /// День
	 int hour;      /// Час
	 int minutes;   /// Минуты
	 int seconds;   /// Секунды
} Date;

/**
 * @brief является ли год високосным
*/
int LeapYear(Date* date);

/**
 * @brief  вычисляет разницу во времени между двумя датами
 * @return 
*/
void TimeDifference(Date* OldDate, Date* NewDate );


/**
 * @brief считает кол-во добавленых дней между двух дат
 * @param OldDate 
 * @param NewDate 
 * @return 
*/
int extraDaysCount(Date* OldDate, Date* NewDate);
