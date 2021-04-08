#ifndef TIMEMENAGER_H
#define TIMEMENAGER_H
#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <clocale>
#include <cstdio>
#include <utility>
#include <map>
#include "auxiliaryMethods.h"

using namespace std;

class TimeMenager
{
  public :

    static bool isDataValidate (string inputDate);
    static string convertDateToString (int inputDate);
    static int convertDateToInt(string inputDate);
    static int extractMonthFromData(string date);
    static int extractYearFromData(string date);
    static int extractDayFromData(string date);
    static int calculateDaysInMonth(int monthNumber, int year);
    static string getLocalTime();
    static int getInscribedDate();
    static string getFirstDayOfMonth();
    static int setCurrentMonthStartDate(string inputDate);
    static int setCurrentMonthEndDate(string inputDate);
    static int setPreviousMonthStartDate(string inputDate);
    static int setPreviousMonthEndDate(string inputDate);
    static string getPreviousMonth(unsigned int currentMonth);
    static bool leapYear (int year);
    static int setMaxYear();
    static bool compareRangeOfYears(int year);
    static bool compareRangeOfMonths(int month);
    static bool compareRangeOfDays (int day);
    static string unzipMonthFromData(string date);
    static string unzipYearFromData(string date);
    static string unzipDayFromData(string date);
};

#endif
