#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
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

class auxiliaryMethods
{
    public :
    static string intToString(int input);
    static int stringToInt(string input);
    static bool fileExists (const string& fileName);
    static string PL (string mark);
    static char loadInput();
    static string loadInputLine();
    static string capitaliseFirstLetter(string inputText);
    static float stringToFloat(string inputText);
    static string floatToString(float inputFloat);
    static bool checkUserLoginLength(string userLogin);
    static bool checkUserPasswordLength(string userPassword);
    static string swapCommaWithDot(string inputText);

};
#endif
