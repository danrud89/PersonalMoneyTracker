#include <iostream>
#include "Expense.h"

using namespace std;

void Expense::setExpenseId(unsigned int newId)
{
    if (newId >= 0)
        expenseId = newId;
}
void Expense::setUserId(unsigned int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Expense::setExpenseDate(unsigned int newDate)
{
    expenseDate = newDate;
}
void Expense::setExpensePurpose(string newPurpose)
{
    expensePurpose = newPurpose;
}
void Expense::setExpenseAmount(float newAmount)
{
    expenseAmount = newAmount;
}

unsigned int Expense::getExpenseId()const
{
    return expenseId;
}
unsigned int Expense::getUserId()const
{
    return userId;
}
unsigned int Expense::getExpenseDate()const
{
    return expenseDate;
}
string Expense::getExpensePurpose()const
{
    return expensePurpose;
}
float Expense::getExpenseAmount()const
{
    return expenseAmount;
}
