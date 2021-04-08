#ifndef CASHFLOWSHEETMENAGER_H
#define CASHFLOWSHEETMENAGER_H
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
#include "TimeMenager.h"
#include "Income.h"
#include "Expense.h"
#include "IncomeMenager.h"
#include "ExpenseMenager.h"

using namespace std;

class CashFlowSheetMenager
{
    friend class IncomeMenager;
    friend class ExpenseMenager;
    float sumOfIncomes;
    float sumOfExpenses;
    float cashFlowDifference;
    vector<Income> extractedIncomes;
    vector<Expense> extractedExpenses;
    void displayAssumedPeriodBalanceSheet(vector<Income> incomes, vector<Expense> expenses, unsigned int startingDate, unsigned int endingDate);
    void displayExtractedIncomes(Income singleIncome);
    void displayExtractedExpenses(Expense singleExpense);
    void displayBalanceSummary();
    vector<Income> extractIncomes(vector<Income> incomes, unsigned int startingDate, unsigned int endingDate);
    vector<Expense> extractExpenses(vector<Expense> expenses, unsigned int startingDate, unsigned int endingDate);
    void resetToDefaultValue();

  public:
      CashFlowSheetMenager()
      {
        sumOfIncomes = {};
        sumOfExpenses = {};
        cashFlowDifference = {};
      }
    void displayCurrentMonthSummary(vector<Income> incomes, vector<Expense> expenses);
    void displayPreviousMonthSummary(vector<Income> incomes, vector<Expense> expenses);
    void displaySelectedPeriodSummary(vector<Income> incomes, vector<Expense> expenses);

};
#endif
