#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>

using namespace std;

class Expense
{
    unsigned int expenseId;
    unsigned int userId;
    unsigned int expenseDate;
    string expensePurpose;
    float expenseAmount;

public:
    Expense(unsigned int expenseId = 0, unsigned int userId = 0, unsigned int expenseDate = 0,
            string expensePurpose = "", float expenseAmount = 0.0);

    void setExpenseId(unsigned int newId);
    void setUserId(unsigned int newUserId);
    void setExpenseDate(unsigned int newDate);
    void setExpensePurpose(string newPurpose);
    void setExpenseAmount(float newAmount);

    unsigned int getExpenseId()const;
    unsigned int getUserId()const;
    unsigned int getExpenseDate()const;
    string getExpensePurpose()const;
    float getExpenseAmount()const;

};
#endif
