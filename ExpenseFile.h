#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H
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
#include "Markup.h"
#include "Expense.h"
#include "TimeMenager.h"

using namespace std;

class ExpenseFile
{
    const string EXPENSES_FILE_NAME;
    Expense getSingleExpenseData(int loggedUserId);
    CMarkup xml;
    unsigned int lastExpenseId;

    public:
    ExpenseFile(string expenseFileName ) : EXPENSES_FILE_NAME(expenseFileName)
    {
        lastExpenseId = {};
    };
    vector<Expense> ImportExpensesForLoggedUser (int loggedUserId);
    void ExportExpenseIntoFile (Expense singleExpenseForExport);
    string getFileName() const;
    unsigned int getLastExpenseId()const;


};
#endif
