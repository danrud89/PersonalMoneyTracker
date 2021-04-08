#include <iostream>
#include "UserMenager.h"
using namespace std;

User::User(unsigned int userId, string userName, string userLastName, string userLogin, string userPassword)
{
    this -> userId = userId;
    this -> userName = userName;
    this -> userLastName = userLastName;
    this -> userLogin = userLogin;
    this -> userPassword = userPassword;
}

void UserMenager::RegisterNewUser()
{
    system("cls");
    cout<< ">>>REJESTRACJA NOWEGO UZYTKOWNIKA<<<" <<endl;
    cout<< "************************************" <<endl;
    cout<< endl;

    User singleUserForExport;
    unsigned int userCounter = singleUser.size();
    string userName, userLastName, userLogin, userPassword, userId;
    singleUserForExport.setId(userCounter + 1);
    cout << "Podaj imie uzytkownika: ";
    userName = auxiliaryMethods::loadInputLine();
    singleUserForExport.setName(auxiliaryMethods::capitaliseFirstLetter(userName));
    cout << "Podaj nazwisko uzytkownika: ";
    userLastName = auxiliaryMethods::loadInputLine();
    singleUserForExport.setLastName(auxiliaryMethods::capitaliseFirstLetter(userLastName));
    cout << "Podaj login uzytkownika: ";
    userLogin = auxiliaryMethods::loadInputLine();
    singleUserForExport.setLogin(userLogin);
    for (auto itr = singleUser.begin(); itr != singleUser.end(); ++ itr)
    {
        if (itr -> getLogin() == userLogin)
        {
            cout << "Uzytkownik o takim loginie juz istnieje! Podaj inny login: ";
            userName = auxiliaryMethods::loadInputLine();
            singleUserForExport.setName(userName);
        }
    }
    cout<< auxiliaryMethods::PL("Podaj haslo: ");
    userPassword = auxiliaryMethods::loadInputLine();
    singleUserForExport.setPassword(userPassword);
    singleUser.push_back(singleUserForExport);
    usersFile.ExportNewUser(singleUserForExport);
}

int UserMenager::LoggTheUserIn ()
{
    system("cls");
    cout << ">>>LOGOWANIE<<<" << endl;
    cout << "***************" << endl;
    cout << endl;
    if (singleUser.empty() != true)
    {
        string userLogin = {};
        string userPassword = {};
        cout << "Podaj login: ";
        userLogin = auxiliaryMethods::loadInputLine();
        for (auto itr = singleUser.begin(); itr != singleUser.end(); ++ itr )
        {
            if (userLogin == itr -> getLogin())
            {
                for(auto attempt = 0; attempt < 3; attempt ++)
                {
                    cout << "Podaj haslo. Pozostalo prob" << " " << "(" << (3 - attempt) << ")" << ": " ;
                    userPassword = auxiliaryMethods::loadInputLine();
                    if (userPassword == itr -> getPassword())
                    {
                        cout << "Logowanie poprawne" << endl;
                        LoggedInUserId = itr -> getId();
                        Sleep(1000);
                        return 0;
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo. Zaczekaj 3 sekundy przed kolejna proba..." << endl;
                Sleep(3000);
                return 0;
            }
        }
        cout << "Nie znaleziono uzytkowanika o podanym loginie. Sprobuj ponownie." <<endl;
        Sleep(1500);
    }
    else
    cout << "Brak zarejestrowanych uzytkownikow! Utworz konto.";
    Sleep(1500);
}

void UserMenager::ChangeUserPassword()
{
    system("cls");
    cout<< ">>>ZMIANA HASLA<<<" <<endl;
    cout<< "******************" <<endl;
    cout<< endl;
    string newUserPassword = {};
    string oldUserPassword = {};
    cout<< "Podaj stare haslo: ";
    oldUserPassword = auxiliaryMethods::loadInputLine();
    cout<< "Podaj nowe haslo (min. 4 znaki): ";
    while(true)
    {
        newUserPassword = auxiliaryMethods::loadInputLine();
        if (auxiliaryMethods::checkUserPasswordLength(newUserPassword))
            break;
        else cout << "Podane haslo jest za krotkie. Sprobuj jeszcze raz: ";
    }

    for(auto itr = singleUser.begin(); itr != singleUser.end(); ++ itr)
    {
        if (LoggedInUserId ==  itr -> getId())
        {
            if (oldUserPassword == itr -> getPassword())
            {
                itr -> setPassword(newUserPassword);
                usersFile.ChangePasswordInFile(LoggedInUserId, newUserPassword);
                cout << "Haslo zmienione pomyslnie!";
                Sleep(2000);
                break;
            }
            else cout << "Nie udalo sie zmienic hasla";
        }
    }
}

bool UserMenager::CheckUserId()
{
    if (LoggedInUserId > 0)
        return true;
    else
        return false;
}

void UserMenager::LoggTheUserOut()
{
    LoggedInUserId = 0;
}

int UserMenager::getLoggedInUserID()
{
    return LoggedInUserId;
}
