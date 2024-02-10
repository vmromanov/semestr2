#pragma once

/**
 * @brief Дата
*/
typedef struct Date
{
	unsigned int year;		/// Год
	unsigned int month;     /// Месяц
	unsigned int day;       /// День
	unsigned int hour;      /// Час
	unsigned int minutes;   /// Минуты
	unsigned int seconds;   /// Секунды
} Date;

/**
 * @brief является ли год високосным
*/
int LeapYear(Date date);

/**
 * @brief 
 * @return 
*/
int TimeDifference(Date date1, Date date2);


/**
 * @brief 
 * @param date 
 * @return 
*/
int FromNewYear(Date date);
