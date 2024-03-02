#pragma once

/**
 * @brief ����
*/
typedef struct Date
{
	 int year;		 /// ���
	 int month;     /// �����
	 int day;       /// ����
	 int hour;      /// ���
	 int minutes;   /// ������
	 int seconds;   /// �������
} Date;

/**
 * @brief �������� �� ��� ����������
*/
int LeapYear(Date* date);

/**
 * @brief  ��������� ������� �� ������� ����� ����� ������
 * @return 
*/
void TimeDifference(Date* OldDate, Date* NewDate );


/**
 * @brief ������� ���-�� ���������� ���� ����� ���� ���
 * @param OldDate 
 * @param NewDate 
 * @return 
*/
int extraDaysCount(Date* OldDate, Date* NewDate);
