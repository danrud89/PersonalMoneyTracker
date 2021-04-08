#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    MENU MainMenu("Users.xml", "Incomes.xml", "Expenses.xml");
    char userSelection;

    while (true)
    {
        if (MainMenu.CheckUserId() == false)
        {
            userSelection = MainMenu.displayUserMenu();

            switch (userSelection)
            {
            case '1':
            {
                MainMenu.RegisterNewUser();
            }
            break;
            case '2':
            {
                MainMenu.LoggTheUserIn();
            }
            break;

            case '3':
            {
                cout << "Nastapi zamkniecie programu...";
                Sleep(1500);
                exit(0);
            }
            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char userSelection = MainMenu.displayLoggedUserMenu();

            switch (userSelection)
            {
            case '1':
            {
               MainMenu.AddNewIncome();
            }
            break;

            case '2':
            {
               MainMenu.AddNewExpense();
            }
            break;

             case '3':
            {
               MainMenu.DisplayAllIncomes();
            }
            break;
            case '4':
            {
               MainMenu.DisplayAllExpenses();
            }
            break;
            case '5':
            {
               MainMenu.DisplayCurrentMonthSummary();
            }
            break;
            case '6':
            {
               MainMenu.DisplayPreviousMonthSummary ();
            }
            break;
            case '7':
            {
               MainMenu.DisplaySelectedPeriodSummary ();
            }
            break;
            case '8':
            {
                MainMenu.ChangeUserPassword();
            }
            break;
            case '9':
            {
                MainMenu.LoggTheUserOut();
                MainMenu.CheckUserId() == false;
                cout << "Wylogowales sie.";
                Sleep(1500);
            }
            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}
