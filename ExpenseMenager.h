#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include "Expense.h"
#include "ExpenseFile.h"
#include "auxiliaryMethods.h"
#include "TimeMenager.h"

using namespace std;

class ExpenseMenager
{
    friend class CashFlowSheetMenager;
    unsigned const int LOGGED_USER_ID;
    vector<Expense> singleExpense;
    float sumOfAllExpenses;
    unsigned int lastExpenseId;
    Expense getSingleExpenseData();
    void DisplaySortedExpenses(Expense expense);
    struct sort_via_dates_ascendingly
    {
        inline bool operator()(Expense& firstExpense, Expense& secondExpense)
        {
            return (firstExpense.getExpenseDate() < secondExpense.getExpenseDate());
        }
    };
   ExpenseFile expenseFile;

    public:
    ExpenseMenager(string expensesFileName, unsigned int LoggedInUserId )
     : expenseFile(expensesFileName), LOGGED_USER_ID(LoggedInUserId)
    {
        singleExpense = expenseFile.ImportExpensesForLoggedUser(LOGGED_USER_ID);
        sumOfAllExpenses = {};
        lastExpenseId = {};
    };
    void AddNewExpense();
    float getAllExpensesSum();
    void DisplayAllExpenses();
    unsigned int setLastExpenseId();
    unsigned int getLastExpenseId()const;
    vector <Expense> getLoggedUserExpenses();
};
#endif
