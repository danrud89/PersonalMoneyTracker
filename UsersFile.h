#ifndef USERSFILE_H
#define USERSFILE_H
#include "User.h"
#include "auxiliaryMethods.h"
#include "Markup.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h>

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
    CMarkup xml;

    public:
        UsersFile(string fileName):USERS_FILE_NAME(fileName){};
        vector<User> ImportAllUsers();
        void ExportNewUser (User user);
        void ChangePasswordInFile(int loggedUserId, string newPassword);
        string getFileName()const;
};

#endif
