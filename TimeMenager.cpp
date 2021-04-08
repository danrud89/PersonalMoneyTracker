#include "TimeMenager.h"
using namespace std;

string TimeMenager::getLocalTime()
{
    time_t currentTime;
    char todayDate[ 80 ];
    time( & currentTime );
    tm data = *localtime( & currentTime );
    strftime( todayDate, sizeof(todayDate), "%Y-%m-%d", &data );
    string now = {};
    unsigned const int dateLength = 10;
    for (int index = 0; index < dateLength; ++ index)
    {
        now += todayDate[index];
    }
    return now;
}

int TimeMenager::getInscribedDate()
{
    string loadDate = {};
    while(true)
    {
        loadDate = auxiliaryMethods::loadInputLine();
        if(isDataValidate(loadDate))
        {
            return convertDateToInt(loadDate);
            break;
        }
        else cout << "Wprawdzono niepoprawny format daty. Sprobuj ponownie." << endl;
    }
}
int TimeMenager::setCurrentMonthStartDate(string inputDate)
{
    string month = unzipMonthFromData(inputDate);
    string year = unzipYearFromData(inputDate);
    string firstDayOfCurrentMonth = getFirstDayOfMonth();
    string startDate = year+ "-" +month+ "-" + firstDayOfCurrentMonth;
    unsigned int startingDate = convertDateToInt(startDate);
    return startingDate;
}

int TimeMenager::setCurrentMonthEndDate(string inputDate)
{
    string month = unzipMonthFromData(inputDate);
    string year = unzipYearFromData(inputDate);
    unsigned int Month = extractMonthFromData(inputDate);
    unsigned int Year = extractYearFromData(inputDate);
    int lastDay = calculateDaysInMonth(Month, Year);
    string lastDayOfCurrentMonth = auxiliaryMethods::intToString(lastDay);
    string endDate = year+ "-" +month+ "-" +lastDayOfCurrentMonth;
    unsigned int endingDate = convertDateToInt(endDate);
    return endingDate;
}

int TimeMenager::setPreviousMonthStartDate(string inputDate)
{
    unsigned int month = extractMonthFromData(inputDate);
    unsigned int year = extractYearFromData(inputDate);
    string previousMonth = getPreviousMonth(month);
    string firstDayOfPreviousMonth = getFirstDayOfMonth();
    string startDate = auxiliaryMethods::intToString(year)+ "-" +previousMonth+ "-" + firstDayOfPreviousMonth;
    unsigned int startingDate = convertDateToInt(startDate);
    return startingDate;
}

int TimeMenager::setPreviousMonthEndDate(string inputDate)
{
    string month = unzipMonthFromData(inputDate);
    string previousMonth = getPreviousMonth(auxiliaryMethods::stringToInt(month));
    string year = unzipYearFromData(inputDate);
    unsigned int Month = extractMonthFromData(inputDate)-1;
    unsigned int Year = extractYearFromData(inputDate);
    int lastDay = calculateDaysInMonth(Month, Year);
    string lastDayOfPreviousMonth = auxiliaryMethods::intToString(lastDay);
    string endDate = year+ "-" +previousMonth+ "-" +lastDayOfPreviousMonth;
    unsigned int endingDate = convertDateToInt(endDate);
    return endingDate;
}

string TimeMenager::getFirstDayOfMonth()
{
    string firstDayOfPreviousMonth = "01";
    return firstDayOfPreviousMonth;
}

string TimeMenager::getPreviousMonth(unsigned int currentMonth)
{
    int previousMonth = {};
    string previousMonthAsString = {};
    unsigned const int January = 1;
    unsigned const int October = 10;

    if (January < currentMonth)
    {
        if (currentMonth <= October)
        {
            previousMonth = currentMonth -1;
            previousMonthAsString = "0" + auxiliaryMethods::intToString(previousMonth);
            return previousMonthAsString;
        }
        else
        {
            previousMonth = currentMonth -1;
            previousMonthAsString = auxiliaryMethods::intToString(previousMonth);
            return previousMonthAsString;
        }
    }
    else if(January == currentMonth)
    {
        previousMonthAsString = "12";
        return previousMonthAsString;
    }
    else cout << "Niepoprawny format miesiaca !";
    return 0;
}

bool TimeMenager::leapYear (int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;

    else return false;
}

int TimeMenager::extractMonthFromData(string date)
{
    unsigned int intMonth = auxiliaryMethods::stringToInt(date.substr(5,2));
    return intMonth;
}
int TimeMenager::extractYearFromData(string date)
{
    unsigned int intYear = auxiliaryMethods::stringToInt(date.substr(0,4));
    return intYear;
}
int TimeMenager::extractDayFromData(string date)
{
    unsigned int intDay = auxiliaryMethods::stringToInt(date.substr(8,2));
    return intDay;
}

int TimeMenager::setMaxYear()
{
    unsigned int maxYear = extractYearFromData(getLocalTime());
    return maxYear;
}

bool TimeMenager::compareRangeOfYears(int year)
{
    unsigned const int minYear = 2000;
    unsigned int currentYear = setMaxYear();
    if (minYear <= year && year <= currentYear) return true;
    else return false;
}

bool TimeMenager::compareRangeOfMonths(int month)
{
    unsigned const int January = 1;
    unsigned const int December = 12;
    if (January <= month && month <= December) return true;
    else return false;
}
bool TimeMenager::compareRangeOfDays (int day)
{
    unsigned const int firstDayOfMonth = 1;
    unsigned const int lastDayOfMonth = 31;
    if (firstDayOfMonth <= day && day <= lastDayOfMonth) return true;
    else return false;
}
int TimeMenager::calculateDaysInMonth(int monthNumber, int year)
{
    map <int, int> calendar {

        { 1, 31 },
        { 2, 28 },
        { 3, 31 },
        { 4, 30 },
        { 5, 31 },
        { 6, 30 },
        { 7, 31 },
        { 8, 31 },
        { 9, 30 },
        { 10, 31 },
        { 11, 30 },
        { 12, 31 },
    };

    if (1 <= monthNumber && monthNumber <= 12)
    {
        unsigned int numberOfDays;
        auto it = calendar.find(monthNumber);

        if (it != calendar.end())
        {
            if (monthNumber == 2 && leapYear(year)) return numberOfDays = 29;
            else numberOfDays = it -> second;
            return numberOfDays;
        }
    }
    else cout << "Podany numer miesiaca jest niepoprawny." << endl;
}

bool TimeMenager::isDataValidate (string inputDate)
{
    if (inputDate.length() != 10) throw invalid_argument("Niepoprawny format daty !");
    else
    {
    unsigned int intYear = extractYearFromData(inputDate);
    unsigned int intMonth = extractMonthFromData(inputDate);
    unsigned int intDay = extractDayFromData(inputDate);

    if ((compareRangeOfYears(intYear) && compareRangeOfMonths(intMonth) && compareRangeOfDays(intDay)) != false)
    return true;

    else return false;
    }
}

string TimeMenager::convertDateToString (int inputDate)
 {
    string stringDate = auxiliaryMethods::intToString(inputDate);
    stringDate.insert(4,"-");
    stringDate.insert(7,"-");
    return stringDate;
}
 int TimeMenager::convertDateToInt(string inputDate)
 {
    int integerDate = {};
    inputDate.erase(4,1);
    inputDate.erase(6,1);
    integerDate = auxiliaryMethods::stringToInt(inputDate);
    return integerDate;
}

string TimeMenager::unzipMonthFromData(string date)
{
    string month = date.substr(5,2);
    return month;
}
string TimeMenager::unzipYearFromData(string date)
{
    string year = date.substr(0,4);
    return year;
}
string TimeMenager::unzipDayFromData(string date)
{
    string day = date.substr(8,2);
    return day;
}
