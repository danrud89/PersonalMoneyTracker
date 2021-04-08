#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include "UsersFile.h"
#include "User.h"
#include "auxiliaryMethods.h"

using namespace std;

class UserMenager
{
    vector <User> singleUser;
    UsersFile usersFile;
    int LoggedInUserId;

    public:
        UserMenager(string usersFileName): usersFile(usersFileName)
        {
            LoggedInUserId = {};
            singleUser = usersFile.ImportAllUsers();
        }
        bool CheckUserId();
        int LoggTheUserIn ();
        void RegisterNewUser();
        void LoggTheUserOut();
        void ChangeUserPassword();
        int getLoggedInUserID();
};

#endif
