// 出生日期.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
int manyday(int year, int month, int day);
int dayscounter(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
int main()
{
	int s_year, s_month, s_day, e_year, e_month, e_day;
	scanf_s("%d %d %d %d %d %d", &s_year, &s_month, &s_day, &e_year, &e_month, &e_day);
	printf("%d", dayscounter(s_year, s_month, s_day, e_year, e_month, e_day));

	return 0;
}
int manyday(int year, int month, int day)
{
	int i, s = 0, total, a[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
		a[2] = 29;
	for (i = 0; i < month; i++)
		s += a[i];
	total = s + day;
	return total;
}
int dayscounter(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day)
{
	int j, counter = 0;
	if (start_year == end_year)
	{
		counter += manyday(end_year, end_month, end_day) - manyday(start_year, start_month, start_day);
		return counter + 1;
	}
	if (start_year % 400 == 0 || start_year % 100 != 0 && start_year % 4 == 0)
		counter = 366 - manyday(start_year, start_month, start_day);
	else
		counter = 365 - manyday(start_year, start_month, start_day);
	for (j = start_year + 1; j < end_year; j++)
	{
		if (j % 400 == 0 || j % 100 != 0 && j % 4 == 0)
			counter += 366;
		else
			counter += 365;
	}
	counter += manyday(end_year, end_month, end_day);
	return counter + 1;
}