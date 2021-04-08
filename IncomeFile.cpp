#include "IncomeFile.h"

using namespace std;

vector<Income> IncomeFile::ImportIncomesForLoggedUser (int loggedUserId)
{
    vector<Income> Incomes;
    Income income;
    unsigned int userIdInFile = {};
    bool fileExists = xml.Load(getFileName());
    if (fileExists)
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");
            userIdInFile = auxiliaryMethods::stringToInt(xml.GetData());
            if (userIdInFile == loggedUserId)
            {
             xml.ResetMainPos();
             xml.FindElem("LP");
             income.setIncomeId(auxiliaryMethods::stringToInt(xml.GetData()));
             xml.FindElem("UserID");
            income.setUserId(userIdInFile);
            xml.FindElem("Date");
            income.setIncomeDate(TimeMenager::convertDateToInt(xml.GetData()));
            xml.FindElem("Purpose");
            income.setIncomePurpose(xml.GetData());
            xml.FindElem("Amount");
            income.setIncomeAmount(auxiliaryMethods::stringToFloat(xml.GetData()));
            Incomes.push_back(income);
            }
            xml.OutOfElem();
            lastIncomeId ++;
        }
    }
    return Incomes;
}

void IncomeFile::ExportIncomeIntoFile (Income singleIncomeForExport )
{
    bool fileExists = xml.Load(getFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("LP", auxiliaryMethods::intToString(singleIncomeForExport.getIncomeId()));
        xml.AddElem("UserID", auxiliaryMethods::intToString(singleIncomeForExport.getUserId()));
        xml.AddElem("Date", TimeMenager::convertDateToString(singleIncomeForExport.getIncomeDate()));
        xml.AddElem("Purpose", singleIncomeForExport.getIncomePurpose());
        xml.AddElem("Amount", auxiliaryMethods::floatToString(singleIncomeForExport.getIncomeAmount()));
        xml.Save(getFileName());
        lastIncomeId ++;
}

string IncomeFile::getFileName() const
{
    return INCOMES_FILE_NAME;
}

unsigned int IncomeFile::getLastIncomeId()const
{
     return lastIncomeId;
}
