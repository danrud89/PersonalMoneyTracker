#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include "auxiliaryMethods.h"
#include "UserMenager.h"
#include "Income.h"
#include "Expense.h"
#include "IncomeMenager.h"
#include "ExpenseMenager.h"
#include "TimeMenager.h"
#include "CashFlowSheetMenager.h"

using namespace std;

class MENU
{
    UserMenager userMenager;
    IncomeMenager *incomeMenager;
    ExpenseMenager *expenseMenager;
    CashFlowSheetMenager *cashFlowSheetMenager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    public:
        MENU(string usersFileName, string incomesFileName, string expensesFileName)
        : userMenager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
        {
            incomeMenager = NULL;
            expenseMenager = NULL;
            cashFlowSheetMenager = NULL;
        }
        ~MENU()
        {
            delete incomeMenager;
            incomeMenager = NULL;
            delete expenseMenager;
            expenseMenager = NULL;
            delete cashFlowSheetMenager;
            cashFlowSheetMenager = NULL;
        }
        char displayUserMenu();
        char displayLoggedUserMenu();
        bool CheckUserId();
        int LoggTheUserIn ();
        void RegisterNewUser();
        void ChangeUserPassword ();
        void AddNewIncome();
        void AddNewExpense();
        void DisplayAllIncomes();
        void DisplayAllExpenses();
        void DisplayCurrentMonthSummary();
        void DisplayPreviousMonthSummary();
        void DisplaySelectedPeriodSummary();
        void LoggTheUserOut();

};

#endif
