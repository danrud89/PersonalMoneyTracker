#ifndef USER_H
#define USER_H
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

class User
{
    unsigned int userId;
    string userName;
    string userLastName;
    string userLogin;
    string userPassword;

    public:
    User(unsigned int userId = 0, string userName = "", string userLastName = "",
         string userLogin = "", string userPassword = "");

    void setId(unsigned int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    unsigned int getId() const;
    string getName()const;
    string getLastName() const;
    string getLogin()const;
    string getPassword()const;

};
#endif
