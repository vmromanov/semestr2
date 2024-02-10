#pragma once

/**
 * @brief ����
*/
typedef struct Date
{
	unsigned int year;		/// ���
	unsigned int month;     /// �����
	unsigned int day;       /// ����
	unsigned int hour;      /// ���
	unsigned int minutes;   /// ������
	unsigned int seconds;   /// �������
} Date;

/**
 * @brief �������� �� ��� ����������
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
