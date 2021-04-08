#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include "Income.h"
#include "IncomeFile.h"
#include "auxiliaryMethods.h"
#include "TimeMenager.h"

using namespace std;

class IncomeMenager
{
    friend class CashFlowSheetMenager;
    unsigned const int LOGGED_USER_ID;
    vector<Income> singleIncome;
    float sumOfAllIncomes;
    unsigned int lastIncomeId;
    Income getSingleIncomeData();
    void DisplaySortedIncomes(Income income);
    struct sort_via_dates_ascendingly
    {
        inline bool operator()(Income& firstIncome, Income& secondIncome)
        {
            return (firstIncome.getIncomeDate() < secondIncome.getIncomeDate());
        }
    };
    IncomeFile incomeFile;

    public:
    IncomeMenager(string incomesFileName, unsigned int LoggedInUserId )
     : incomeFile(incomesFileName), LOGGED_USER_ID(LoggedInUserId)
    {
        singleIncome = incomeFile.ImportIncomesForLoggedUser(LOGGED_USER_ID);
        sumOfAllIncomes = {};
        lastIncomeId = {};
    };
    void AddNewIncome();
    float getAllIncomesSum();
    void DisplayAllIncomes();
    unsigned int setLastIncomeId();
    unsigned int getLastIncomeId()const;
    vector<Income> getLoggedUserIncomes();
};
#endif
