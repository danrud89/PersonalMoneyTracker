#include "CashFlowSheetMenager.h"

using namespace std;


void CashFlowSheetMenager::displayCurrentMonthSummary(vector<Income> incomes, vector<Expense> expenses)
{
    string localDate = TimeMenager::getLocalTime();
    unsigned int firstDayOfCurrentMonth = TimeMenager::setCurrentMonthStartDate(localDate);
    unsigned int lastDayOfCurrentMonth = TimeMenager::setCurrentMonthEndDate(localDate);
    displayAssumedPeriodBalanceSheet(incomes,expenses,firstDayOfCurrentMonth, lastDayOfCurrentMonth);
}

void CashFlowSheetMenager::displayPreviousMonthSummary(vector<Income> incomes, vector<Expense> expenses)
{
    string localDate = TimeMenager::getLocalTime();
    unsigned int firstDayOfPreviousMonth = TimeMenager::setPreviousMonthStartDate(localDate);
    unsigned int lastDayOfPreviousMonth = TimeMenager::setPreviousMonthEndDate(localDate);
    displayAssumedPeriodBalanceSheet(incomes,expenses,firstDayOfPreviousMonth, lastDayOfPreviousMonth);
}
void CashFlowSheetMenager::displaySelectedPeriodSummary(vector<Income> incomes, vector<Expense> expenses)
{
    unsigned int firstDayOfPeriodTime = {};
    unsigned int lastDayOfPeriodTime = {};
    START:
    while(true)
    {
        cout << "Podaj date poczatkowa w formacie yyyy-mm-dd: ";
        firstDayOfPeriodTime = TimeMenager::getInscribedDate();
        if (TimeMenager::isDataValidate(TimeMenager::convertDateToString(firstDayOfPeriodTime))) break;
        else cout << "Wprowadzono niepoprawny format daty. Sprobuj ponownie: " << endl;
    }

    while (true)
    {
        cout << "Podaj date koncowa w formacie yyyy-mm-dd: ";
        lastDayOfPeriodTime = TimeMenager::getInscribedDate();
        if (TimeMenager::isDataValidate(TimeMenager::convertDateToString(lastDayOfPeriodTime))) break;
        else cout << "Wprowadzono niepoprawny format daty. Sprobuj ponownie: " << endl;
    }
    if (lastDayOfPeriodTime < firstDayOfPeriodTime)
    {
        cout << "Data koncowa musi byc pozniejsza niz poczatkowa. Sprobuj ponownie." << endl;
        goto START;
    }
    else displayAssumedPeriodBalanceSheet(incomes,expenses,firstDayOfPeriodTime, lastDayOfPeriodTime);
}
 void CashFlowSheetMenager::displayAssumedPeriodBalanceSheet(vector<Income> incomes, vector<Expense> expenses, unsigned int startingDate, unsigned int endingDate)
 {
    system ("cls");
    cout << "***** SALDO FINANSOWE OD " << TimeMenager::convertDateToString(startingDate) << " DO " << TimeMenager::convertDateToString(endingDate) << " *****" << endl;

    cout << endl << "***** PRZYCHODY *****" << endl;
    extractedIncomes = extractIncomes(incomes, startingDate, endingDate);
    if(!extractedIncomes.empty())
    {
        for (vector<Income>::const_iterator itr = extractedIncomes.begin(); itr != extractedIncomes.end(); ++ itr)
        {
            displayExtractedIncomes(*itr);
        }
    }
    else cout << "Lista przychodow jest pusta." << endl;

    cout << endl << "***** WYDATKI *****" << endl;
    extractedExpenses = extractExpenses(expenses, startingDate, endingDate);
    if (!extractedExpenses.empty())
    {
        for (vector<Expense>::const_iterator itr = extractedExpenses.begin(); itr != extractedExpenses.end(); ++ itr)
        {
            displayExtractedExpenses(*itr);
        }
    }
    else cout << "Lista wydatkow jest pusta." << endl;

    displayBalanceSummary();
    resetToDefaultValue();
    cout << "Wcisnij dowolny klawisz aby kontynuowac...";
    getch();
}

void CashFlowSheetMenager::displayExtractedIncomes(Income singleIncome)
{
    cout << "DATA: " << TimeMenager::convertDateToString(singleIncome.getIncomeDate()) << endl;
    cout << "CEL: " << singleIncome.getIncomePurpose() << endl;
    cout << "KWOTA: " << singleIncome.getIncomeAmount() << " PLN" << endl << endl;
}

void CashFlowSheetMenager::displayExtractedExpenses(Expense singleExpense)
{
    cout << "DATA: " << TimeMenager::convertDateToString(singleExpense.getExpenseDate()) << endl;
    cout << "CEL: " << singleExpense.getExpensePurpose() << endl;
    cout << "KWOTA: " << singleExpense.getExpenseAmount() << " PLN" << endl << endl;
}

void CashFlowSheetMenager::displayBalanceSummary()
{
    cout << "===============" << endl;
    cout << "Suma przychodow = " << sumOfIncomes << " PLN" << endl;
    cout << "Suma wydatkow = " << sumOfExpenses << " PLN" << endl;
    cashFlowDifference = sumOfIncomes - sumOfExpenses;
    cout << "===============" << endl;
    if (sumOfIncomes > sumOfExpenses)
    cout << "Oszczednosci za podany okres wynosza: " << cashFlowDifference << " PLN" << endl;
    else cout << "Debet za podany okres wynosi: " << cashFlowDifference << " PLN" <<  endl;
}

vector<Income> CashFlowSheetMenager::extractIncomes(vector<Income> incomes, unsigned int startingDate, unsigned int endingDate)
{
    for (auto index = 0; index < incomes.size(); ++ index)
    {
        if(startingDate <= incomes[index].getIncomeDate() && incomes[index].getIncomeDate() <= endingDate)
        {
            extractedIncomes.push_back(incomes[index]);
            sumOfIncomes += incomes[index].getIncomeAmount();
        }
    }
    sort(extractedIncomes.begin(), extractedIncomes.end(), IncomeMenager::sort_via_dates_ascendingly());
    return extractedIncomes;
    extractedIncomes.clear();
}

vector<Expense> CashFlowSheetMenager::extractExpenses(vector<Expense> expenses, unsigned int startingDate, unsigned int endingDate)
{
    for (auto index = 0; index < expenses.size(); ++ index)
    {
        if(startingDate <= expenses[index].getExpenseDate() && expenses[index].getExpenseDate() <= endingDate)
        {
            extractedExpenses.push_back(expenses[index]);
            sumOfExpenses += expenses[index].getExpenseAmount();
        }
    }
    sort(extractedExpenses.begin(), extractedExpenses.end(), ExpenseMenager::sort_via_dates_ascendingly());
    return extractedExpenses;
    extractedExpenses.clear();
}

void CashFlowSheetMenager::resetToDefaultValue()
{
    sumOfIncomes = {};
    sumOfExpenses = {};
    cashFlowDifference = {};
    extractedIncomes.clear();
    extractedExpenses.clear();
}
