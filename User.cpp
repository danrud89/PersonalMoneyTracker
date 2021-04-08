#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "User.h"
#include "auxiliaryMethods.h"

using namespace std;

void User::setId(unsigned int newId)
{
    userId = newId;
}
void User::setName(string newName)
{
    userName = newName;
}
void User::setLastName(string newLastName)
{
    userLastName = newLastName;
}
void User::setLogin(string newLogin)
{
    userLogin = newLogin;
}
void User::setPassword(string newPassword)
{
    userPassword = newPassword;
}

unsigned int User::getId() const
{
    return userId;
}
string User::getName() const
{
    return userName;
}
string User::getLastName() const
{
    return userLastName;
}
string User::getLogin() const
{
    return userLogin;
}
string User::getPassword() const
{
    return userPassword;
}
