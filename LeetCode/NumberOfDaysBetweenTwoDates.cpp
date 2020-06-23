#include "stdafx.h"
#include "NumberOfDaysBetweenTwoDates.h"

bool is_leap_year(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int m, int year)
{
  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
  if (m == 2) return is_leap_year(year) ? 29 : 28;
  return 30;
}

int date_to_int(string s_date)
{
  int Year = stoi(s_date.substr(0, 4));
  int Month = stoi(s_date.substr(5, 2));
  int Date = stoi(s_date.substr(8, 2));

  int days = 0;
  for (int y = 1971; y < Year; ++y) 
    days += is_leap_year(y) ? 366 : 365;
  for (int m = 1; m < Month; ++m) 
    days += days_in_month(m, Year);

  return days + Date;
}

int Solution::daysBetweenDates(string date1, string date2) {
  return abs(date_to_int(date2) - date_to_int(date1));
}