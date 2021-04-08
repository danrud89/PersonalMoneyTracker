#include <iostream>
#include <string>
#include "auxiliaryMethods.h"

using namespace std;

bool auxiliaryMethods::fileExists (const string& fileName)
{
    fstream inputFile;
    inputFile.open(fileName.c_str(), ios::in);
    if ( inputFile.is_open() )
    {
        inputFile.close();
        return true;
    }
    inputFile.close();
    return false;
}

string auxiliaryMethods::loadInputLine()
{
    string loadedLine = {};
    getline(cin, loadedLine);
    return loadedLine;
}

string auxiliaryMethods::intToString(int IdNumber)
{
    ostringstream ss;
    ss << IdNumber;
    return  ss.str();
}

int auxiliaryMethods::stringToInt(string number)
{
    int intNumber;
    istringstream ss(number);
    ss >> intNumber;
    return intNumber;
}

char auxiliaryMethods::loadInput()
{
    string input = "";
    char mark  = {0};
    cin.sync();

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            mark = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return mark;
}

string auxiliaryMethods::PL (string singleMark)
{
    for( auto index = 0; index < singleMark.length(); index ++ ) {
        switch( singleMark[ index ] ) {
        case 'π':
            singleMark[ index ] = static_cast < char >( 165 );
            break;

        case 'Ê':
            singleMark[ index ] = static_cast < char >( 134 );
            break;

        case 'Í':
            singleMark[ index ] = static_cast < char >( 169 );
            break;

        case '≥':
            singleMark[ index ] = static_cast < char >( 136 );
            break;

        case 'Ò':
            singleMark[ index ] = static_cast < char >( 228 );
            break;

        case 'Û':
            singleMark[ index ] = static_cast < char >( 162 );
            break;

        case 'ú':
            singleMark[ index ] = static_cast < char >( 152 );
            break;

        case 'ü':
            singleMark[ index ] = static_cast < char >( 171 );
            break;

        case 'ø':
            singleMark[ index ] = static_cast < char >( 190 );
            break;

        case '•':
            singleMark[ index ] = static_cast < char >( 164 );
            break;

        case '∆':
            singleMark[ index ] = static_cast < char >( 143 );
            break;

        case ' ':
            singleMark[ index ] = static_cast < char >( 168 );
            break;

        case '£':
            singleMark[ index ] = static_cast < char >( 157 );
            break;

        case '—':
            singleMark[ index ] = static_cast < char >( 227 );
            break;

        case '”':
            singleMark[ index ] = static_cast < char >( 224 );
            break;

        case 'å':
            singleMark[ index ] = static_cast < char >( 151 );
            break;

        case 'è':
            singleMark[ index ] = static_cast < char >( 141 );
            break;

        case 'Ø':
            singleMark[ index ] = static_cast < char >( 189 );
            break;
        }
    }
    return singleMark;
}

 string auxiliaryMethods::capitaliseFirstLetter(string inputText)
 {
    if (!inputText.empty())
    {
        transform(inputText.begin(), inputText.end(), inputText.begin(), ::tolower);
        inputText[0] = toupper(inputText[0]);
    }
    return inputText;
}
float auxiliaryMethods::stringToFloat(string inputText)
{
  float output =  atof(inputText.c_str());
  return output;
}
 string auxiliaryMethods::floatToString(float inputFloat)
 {
    stringstream stream;
    stream << inputFloat;
    string outputString = stream.str();
    return outputString;
}

 bool auxiliaryMethods::checkUserLoginLength(string userLogin)
 {
    const int minLoginLength = 4;
    if(userLogin.length() < minLoginLength) return false;
    else return true;
 }
 bool auxiliaryMethods::checkUserPasswordLength(string userPassword)
 {
     const int minPasswordLength = 4;
     if (userPassword.length() < minPasswordLength) return false;
     return true;
 }
 string auxiliaryMethods::swapCommaWithDot(string inputText)
 {
     unsigned const int inputLength = inputText.length();
     for (auto index = 0; index < inputLength; ++ index)
     {
        if (inputText[index] == ',')
        inputText[index] = '.';
     }
     return inputText;
 }
