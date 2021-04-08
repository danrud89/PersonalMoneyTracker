#include <iostream>
#include "ExpenseMenager.h"

using namespace std;

Expense::Expense(unsigned int expenseId, unsigned int userId, unsigned int expenseDate, string expensePurpose, float expenseAmount)
{
    this -> expenseId = expenseId;
    this -> userId = userId;
    this -> expenseDate = expenseDate;
    this -> expensePurpose = expensePurpose;
    this -> expenseAmount = expenseAmount;
}
void ExpenseMenager::AddNewExpense()
{
    system("cls");
    cout << " >>> DODAJ WYDATEK <<<" << endl << endl;
    Expense expenseForExport = getSingleExpenseData();
    singleExpense.push_back(expenseForExport);
    expenseFile.ExportExpenseIntoFile(expenseForExport);
    lastExpenseId ++;
    cout << "Dodano nowy wydatek." << endl;
    Sleep (2000);
}
Expense ExpenseMenager::getSingleExpenseData()
{
    Expense expense;
    unsigned int ExpenseId = setLastExpenseId();
    expense.setUserId(LOGGED_USER_ID);
    expense.setExpenseId(ExpenseId);

    cout << "Czy dodac wydatek z dzisiejsza data ?" << endl;
    cout << "1. Tak" << endl;
    cout << "2. Chce podac inna date" << endl;
    char userChoice = auxiliaryMethods::loadInput();
    while(true)
    {
        if(userChoice == '1')
        {
            expense.setExpenseDate(TimeMenager::convertDateToInt(TimeMenager::getLocalTime()));
            break;
        }
        else if(userChoice == '2')
        {
            cout << "Podaj date w formacie yyyy-mm-dd: ";
            int inputDate = TimeMenager::getInscribedDate();
            expense.setExpenseDate(inputDate);
            break;
        }
        else
            cout << "Niepoprawny wybor. Sprobuj ponownie:";
    }

    cout << "Podaj zrodlo wydatku: ";
    expense.setExpensePurpose(auxiliaryMethods::loadInputLine());

    cout << "Podaj kwote wydatku [PLN]: ";
    string correctAmount = auxiliaryMethods::swapCommaWithDot(auxiliaryMethods::loadInputLine());
    float amount = auxiliaryMethods::stringToFloat(correctAmount);
    expense.setExpenseAmount(amount);
    return expense;
}

float ExpenseMenager::getAllExpensesSum()
{
    if(!singleExpense.empty())
    {   for (auto index = 0; index < singleExpense.size(); index ++)
        sumOfAllExpenses += singleExpense[index].getExpenseAmount();
    }
    return sumOfAllExpenses;
}
void ExpenseMenager::DisplayAllExpenses()
{
    system("cls");
    cout << ">>>LISTA WSZYSTKICH WYDATKOW<<<" << endl;
    cout << "********************************" << endl;

    if (!singleExpense.empty())
    {
        sort(singleExpense.begin(), singleExpense.end(), sort_via_dates_ascendingly());
        for (vector<Expense>::const_iterator itr = singleExpense.begin(); itr != singleExpense.end(); ++ itr)
        {
            DisplaySortedExpenses(*itr);
        }
        cout << "===============" << endl;
        cout << "Suma wydatkow: " << getAllExpensesSum() << endl;
        sumOfAllExpenses = {};
    }
    else cout << "Lista wydatkow jest pusta. Dodaj nowy wydatek" << endl;
    cout << "Wcisnij dowolny klawisz aby kontynuowac...";
    getch();
}
void ExpenseMenager::DisplaySortedExpenses(Expense expense)
{
    cout << "ID: " << expense.getExpenseId() << endl;
    cout << "Data dodania: " << TimeMenager::convertDateToString(expense.getExpenseDate()) << endl;
    cout << "Cel wydatku: " << expense.getExpensePurpose() << endl;
    cout <<"Kwota: " << expense.getExpenseAmount() << endl;
}
unsigned int ExpenseMenager::setLastExpenseId()
{
    if (singleExpense.empty()) return 1;
    else return singleExpense.size()+1;
}
unsigned int ExpenseMenager::getLastExpenseId() const
{
    return lastExpenseId;
}
vector<Expense> ExpenseMenager::getLoggedUserExpenses()
{
    return singleExpense;
}
