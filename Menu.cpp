#include <iostream>
#include "Menu.h"


char MENU::displayUserMenu()
{
            system("cls");
            cout << "\t******************************************" << endl;
            cout << "\t>>>>>>>>>>> PERSONAL MONEY TRACKER <<<<<<<" << endl;
            cout << "\t******************************************" << endl << endl;
            cout << "\t************ 1.REJESTRACJA ***************" << endl;
            cout << "\t************* 2.LOGOWANIE ****************" << endl;
            cout << "\t************** 3.WYJSCIE *****************" << endl;
            cout << endl;
            cout << "Prosze wybrac opcje ==> ";
            char userFirstSelection = auxiliaryMethods::loadInput();
            return userFirstSelection;

}
char MENU::displayLoggedUserMenu()
{
            system("cls");
            cout << "\t**********************************************" << endl;
            cout << "\t>>>>>>>>>>>>>>> MENU GLOWNE <<<<<<<<<<<<<" << endl;
            cout << "\t**********************************************" << endl << endl;
            cout << "\t************ 1.DODAJ NOWY PRZYCHOD ************" << endl;
            cout << "\t************ 2.DODAJ NOWY WYDATEK **************" << endl;
            cout << "\t**********************************************" << endl;
            cout << "\t************ 3.WYSWIETL WSZYSTKIE PRZYCHODY **************" << endl;
            cout << "\t************ 4.WYSWIETL WSZYSTKIE WYDATKI ********" << endl;
            cout << "\t**********************************************" << endl;
            cout << "\t************ 5.WYSWIETL BILANS Z BIEZACEGO MIESIACA **************" << endl;
            cout << "\t************ 6.WYSWIETL BILANS Z POPRZEDNIEGO MIESIACA ********" << endl;
            cout << "\t************ 7.WYSWIETL BILANS Z WYBRANEGO OKRESU ***************" << endl;
            cout << "\t**********************************************" << endl;
            cout << "\t************ 8.ZMIANA HASLA *****************" << endl;
            cout << "\t************ 9.WYLOGUJ *********************" << endl;
            cout << endl;
            cout << "Prosze wybrac opcje ==> ";
            char userSecondSelection = auxiliaryMethods::loadInput();
            return userSecondSelection;

}
bool MENU::CheckUserId()
{
    userMenager.CheckUserId();
}
int  MENU::LoggTheUserIn ()
{
    userMenager.LoggTheUserIn();
    if (userMenager.CheckUserId())
    {
        incomeMenager = new IncomeMenager(INCOMES_FILE_NAME, userMenager.getLoggedInUserID());
        expenseMenager = new ExpenseMenager(EXPENSES_FILE_NAME, userMenager.getLoggedInUserID());
        cashFlowSheetMenager = new CashFlowSheetMenager();
    }
}
void  MENU::RegisterNewUser()
{
    userMenager.RegisterNewUser();
}
void  MENU::ChangeUserPassword ()
{
    userMenager.ChangeUserPassword();
}
void MENU::AddNewIncome()
{
    incomeMenager -> AddNewIncome();
}
void MENU::AddNewExpense()
{
    expenseMenager -> AddNewExpense();
}
void MENU::DisplayAllIncomes()
{
    incomeMenager -> DisplayAllIncomes();
}
void MENU::DisplayAllExpenses()
{
    expenseMenager -> DisplayAllExpenses();
}
void MENU::DisplayCurrentMonthSummary()
{
    if (userMenager.CheckUserId())
    cashFlowSheetMenager -> displayCurrentMonthSummary(incomeMenager -> getLoggedUserIncomes(), expenseMenager -> getLoggedUserExpenses());
}
void MENU::DisplayPreviousMonthSummary()
{
    if (userMenager.CheckUserId())
    cashFlowSheetMenager -> displayPreviousMonthSummary(incomeMenager -> getLoggedUserIncomes(), expenseMenager -> getLoggedUserExpenses());
}
void MENU::DisplaySelectedPeriodSummary()
{
    if (userMenager.CheckUserId())
    cashFlowSheetMenager -> displaySelectedPeriodSummary(incomeMenager -> getLoggedUserIncomes(), expenseMenager -> getLoggedUserExpenses());
}

void MENU::LoggTheUserOut()
{
    userMenager.LoggTheUserOut();
    delete incomeMenager;
    incomeMenager = NULL;
    delete expenseMenager;
    expenseMenager = NULL;
    delete cashFlowSheetMenager;
    cashFlowSheetMenager = NULL;
}
