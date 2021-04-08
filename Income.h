#ifndef INCOME_H
#define INCOME_H
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

class Income
{
    unsigned int incomeId;
    unsigned int userId;
    unsigned int incomeDate;
    string incomePurpose;
    float incomeAmount;

public:
    Income(unsigned int incomeId = 0, unsigned int userId = 0, unsigned int incomeDate = 0,
            string incomePurpose = "", float incomeAmount = 0.0);

    void setIncomeId(unsigned int newId);
    void setUserId(unsigned int newUserId);
    void setIncomeDate(unsigned int newDate);
    void setIncomePurpose(string newPurpose);
    void setIncomeAmount(float newAmount);

    unsigned int getIncomeId()const;
    unsigned int getUserId()const;
    unsigned int getIncomeDate()const;
    string getIncomePurpose()const;
    float getIncomeAmount()const;

};
#endif
