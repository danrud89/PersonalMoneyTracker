#ifndef INCOMEFILE_H
#define INCOMEFILE_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include "Markup.h"
#include <cmath>
#include "auxiliaryMethods.h"
#include "Income.h"
#include "TimeMenager.h"

using namespace std;

class IncomeFile
{
    const string INCOMES_FILE_NAME;
    Income getSingleIncomeData(int loggedUserId);
    CMarkup xml;
    unsigned int lastIncomeId;

    public:
    IncomeFile(string incomeFileName ) : INCOMES_FILE_NAME(incomeFileName)
    {
        lastIncomeId = {};
    };
    vector<Income> ImportIncomesForLoggedUser (int loggedUserId);
    void ExportIncomeIntoFile (Income singleIncomeForExport);
    string getFileName() const;
    unsigned int getLastIncomeId()const;

};
#endif
