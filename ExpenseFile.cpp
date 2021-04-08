#include "ExpenseFile.h"

using namespace std;

vector<Expense> ExpenseFile::ImportExpensesForLoggedUser (int loggedUserId)
{
    vector<Expense> Expenses;
    Expense expense;
    unsigned int userIdInFile = {};
    bool fileExists = xml.Load(getFileName());
    if (fileExists)
    {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");
            userIdInFile = auxiliaryMethods::stringToInt(xml.GetData());
            if (userIdInFile == loggedUserId)
            {
             xml.ResetMainPos();
             xml.FindElem("LP");
             expense.setExpenseId(auxiliaryMethods::stringToInt(xml.GetData()));
             xml.FindElem("UserID");
            expense.setUserId(userIdInFile);
            xml.FindElem("Date");
            expense.setExpenseDate(TimeMenager::convertDateToInt(xml.GetData()));
            xml.FindElem("Purpose");
            expense.setExpensePurpose(xml.GetData());
            xml.FindElem("Amount");
            expense.setExpenseAmount(auxiliaryMethods::stringToFloat(xml.GetData()));
            Expenses.push_back(expense);
            }
            xml.OutOfElem();
            lastExpenseId ++;
        }
    }
    return Expenses;
}

void ExpenseFile::ExportExpenseIntoFile (Expense singleExpenseForExport )
{
    bool fileExists = xml.Load(getFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("LP", auxiliaryMethods::intToString(singleExpenseForExport.getExpenseId()));
        xml.AddElem("UserID", auxiliaryMethods::intToString(singleExpenseForExport.getUserId()));
        xml.AddElem("Date", TimeMenager::convertDateToString(singleExpenseForExport.getExpenseDate()));
        xml.AddElem("Purpose", singleExpenseForExport.getExpensePurpose());
        xml.AddElem("Amount", auxiliaryMethods::floatToString(singleExpenseForExport.getExpenseAmount()));
        xml.Save(getFileName());
}

string ExpenseFile::getFileName() const
{
    return EXPENSES_FILE_NAME;
}

unsigned int ExpenseFile::getLastExpenseId()const
{
    return lastExpenseId;
}
