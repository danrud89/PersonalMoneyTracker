#include <iostream>
#include "User.h"
#include "auxiliaryMethods.h"
#include "UsersFile.h"
#include "UserMenager.h"
#include <conio.h>
#include <stdio.h>

vector<User> UsersFile::ImportAllUsers()
{
    User individualUser;
    vector<User> Users;
    bool fileExists = xml.Load(getFileName());
    if (fileExists)
    {
        xml.FindElem("Users");
        xml.IntoElem(); // into Users
        while(xml.FindElem("User"))
        {
            xml.IntoElem(); //into User
            xml.FindElem("ID");
            individualUser.setId(auxiliaryMethods::stringToInt(xml.GetData()));
            xml.FindElem("Name");
            individualUser.setName(xml.GetData());
            xml.FindElem("Surname");
            individualUser.setLastName(xml.GetData());
            xml.FindElem("Login");
            individualUser.setLogin(xml.GetData());
            xml.FindElem("Password");
            individualUser.setPassword(xml.GetData());
            xml.OutOfElem();
            Users.push_back(individualUser);
        }
    }
    return Users;
}

void UsersFile::ExportNewUser(User singleUser)
{
    bool fileExists = xml.Load(getFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("ID", singleUser.getId());
        xml.AddElem("Name", singleUser.getName());
        xml.AddElem("Surname", singleUser.getLastName());
        xml.AddElem("Login", singleUser.getLogin());
        xml.AddElem("Password", singleUser.getPassword());
        xml.OutOfElem();
        xml.Save(getFileName());
}

void UsersFile::ChangePasswordInFile(int loggedUserId, string newUserPassword)
{
    bool fileExists = xml.Load(getFileName());
    unsigned int userIdInFile = {};
    if (fileExists)
    {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("ID");
            userIdInFile = auxiliaryMethods::stringToInt(xml.GetData());
            if (userIdInFile == loggedUserId)
            {
                xml.FindElem("Password");
                xml.SetData(newUserPassword);
                break;
            }
            xml.OutOfElem();
        }
        xml.Save("Users.xml");
    }
    else
        cout << "Nie można otworzyc pliku !" << endl;
}

string UsersFile::getFileName() const
{
    return USERS_FILE_NAME;
}
