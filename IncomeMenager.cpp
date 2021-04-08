#include "IncomeMenager.h"

using namespace std;

Income::Income(unsigned int incomeId, unsigned int userId, unsigned int incomeDate, string incomePurpose, float incomeAmount)
{
    this -> incomeId = incomeId;
    this -> userId = userId;
    this -> incomeDate = incomeDate;
    this -> incomePurpose = incomePurpose;
    this -> incomeAmount = incomeAmount;
}
void IncomeMenager::AddNewIncome()
{
    system("cls");
    cout << " >>> DODAJ PRZYCHOD <<<" << endl << endl;
    Income incomeForExport = getSingleIncomeData();
    singleIncome.push_back(incomeForExport);
    incomeFile.ExportIncomeIntoFile(incomeForExport);
    lastIncomeId ++;
    cout << "Dodano nowy przychod." << endl;
    Sleep (2000);
}
Income IncomeMenager::getSingleIncomeData()
{
    Income income;
    unsigned int IncomeId = setLastIncomeId();
    income.setUserId(LOGGED_USER_ID);
    income.setIncomeId(IncomeId);

    cout << "Czy dodac przychod z dzisiejsza data ?" << endl;
    cout << "1. Tak" << endl;
    cout << "2. Chce podac inna date" << endl;
    char userChoice = auxiliaryMethods::loadInput();
    while(true)
    {
        if(userChoice == '1')
        {
            income.setIncomeDate(TimeMenager::convertDateToInt(TimeMenager::getLocalTime()));
            break;
        }
        else if(userChoice == '2')
        {
            cout << "Podaj date w formacie yyyy-mm-dd: ";
            int inputDate = TimeMenager::getInscribedDate();
            income.setIncomeDate(inputDate);
            break;
        }
        else
            cout << "Niepoprawny wybor. Sprobuj ponownie:";
    }

    cout << "Podaj zrodlo przychodu: ";
    income.setIncomePurpose(auxiliaryMethods::loadInputLine());

    cout << "Podaj kwote przychodu [PLN]: ";
    string correctAmount = auxiliaryMethods::swapCommaWithDot(auxiliaryMethods::loadInputLine());
    float amountFloat = auxiliaryMethods::stringToFloat(correctAmount);
    income.setIncomeAmount(amountFloat);

    return income;
}

float IncomeMenager::getAllIncomesSum()
{
    if(!singleIncome.empty())
    {   for (auto index = 0; index < singleIncome.size(); index ++)
        sumOfAllIncomes += singleIncome[index].getIncomeAmount();
    }
    return sumOfAllIncomes;
}
void IncomeMenager::DisplayAllIncomes()
{
    system("cls");
    cout << ">>>LISTA WSZYSTKICH PRZYCHODOW<<<" << endl;
    cout << "********************************" << endl;

    if (!singleIncome.empty())
    {
        sort(singleIncome.begin(), singleIncome.end(), sort_via_dates_ascendingly());
        for (vector<Income>::const_iterator itr = singleIncome.begin(); itr != singleIncome.end(); ++ itr)
        {
            DisplaySortedIncomes(*itr);
        }
        cout << "===============" << endl;
        cout << "Suma przychodow: " << getAllIncomesSum() << endl;
        sumOfAllIncomes = {};
    }
    else cout << "Lista przychodow jest pusta. Dodaj nowy przychod" << endl;
    cout << "Wcisnij dowolny klawisz aby kontynuowac...";
    getch();
}
void IncomeMenager::DisplaySortedIncomes(Income income)
{
    cout << "ID: " << income.getIncomeId() << endl;
    cout << "Data dodania: " << TimeMenager::convertDateToString(income.getIncomeDate()) << endl;
    cout << "Zrodlo przychodu: " << income.getIncomePurpose() << endl;
    cout <<"Kwota: " << income.getIncomeAmount() << endl;
}

unsigned int IncomeMenager::setLastIncomeId()
{
    if (singleIncome.empty()) return 1;
    else return singleIncome.size()+1;
}
unsigned int IncomeMenager::getLastIncomeId() const
{
    return lastIncomeId;
}
vector<Income> IncomeMenager::getLoggedUserIncomes()
{
    return singleIncome;
}
