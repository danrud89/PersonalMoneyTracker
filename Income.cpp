#include <iostream>
#include <string>
#include "Income.h"

using namespace std;

void Income::setIncomeId(unsigned int newId)
{
    if (newId >= 0)
        incomeId = newId;
}
void Income::setUserId(unsigned int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Income::setIncomeDate(unsigned int newDate)
{
    incomeDate = newDate;
}
void Income::setIncomePurpose(string newPurpose)
{
    incomePurpose = newPurpose;
}
void Income::setIncomeAmount(float newAmount)
{
    incomeAmount = newAmount;
}

unsigned int Income::getIncomeId()const
{
    return incomeId;
}
unsigned int Income::getUserId()const
{
    return userId;
}
unsigned int Income::getIncomeDate()const
{
    return incomeDate;
}
string Income::getIncomePurpose()const
{
    return incomePurpose;
}
float Income::getIncomeAmount()const
{
    return incomeAmount;
}
