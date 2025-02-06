#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:
    struct stTransferInfo;

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;



    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    string  PrepareTransferLog(clsBankClient DstinationAcc, double TarnsferAmount, string Separtor = "#//#") {
     //   stTransferInfo TransferLog;
     
        string TransferLog="";
        TransferLog += clsDate::GetSystemDatetimeString() + Separtor;
        TransferLog += this->AccountNumber() + Separtor;
        TransferLog += DstinationAcc.AccountNumber() + Separtor;
        TransferLog += to_string(TarnsferAmount) + Separtor;
        TransferLog += to_string(AccountBalance) + Separtor;
        TransferLog += to_string(DstinationAcc.AccountBalance) + Separtor;
        TransferLog+= CurrentUser.UserName;
        return TransferLog;

    }
    static  stTransferInfo _getTransferLogStruct(string line , string Separtor = "#//#") {
         vector<string > vTransferInfo = clsString::Split(line, Separtor);
         stTransferInfo TransferLog;
         TransferLog.Date =vTransferInfo[0];
         TransferLog.SourceAcc = vTransferInfo[1];
         TransferLog.DestinationAcc = vTransferInfo[2];
         TransferLog.TransferAmount = stod(vTransferInfo[3]);
         TransferLog.SourceAccNewBalance = stod(vTransferInfo[4]);
         TransferLog.DestinationAccNewBalance = stod(vTransferInfo[5]);
         TransferLog.userName = vTransferInfo[6];
         return TransferLog;


     }
  /*  static string _getTransferRecord(stTransferInfo TrunsferInfo , string Separtor = "#//#") {

        string TransferRecordLine = "";
        TransferRecordLine += TrunsferInfo.Date + Separtor;
        TransferRecordLine += TrunsferInfo.SourceAcc + Separtor;
        TransferRecordLine += TrunsferInfo.DestinationAcc + Separtor;
        TransferRecordLine += to_string(TrunsferInfo.TransferAmount) + Separtor;
        TransferRecordLine += TrunsferInfo.userName;

        return TransferRecordLine;


    }*/
    ///////////////////////////////////////////////////////

     void _RegisterTransferLog(clsBankClient DstinationAcc, double TarnsferAmount ) {
         string TransferLogInfo = PrepareTransferLog(DstinationAcc, TarnsferAmount);
        fstream Myfile;
        Myfile.open("TransferLogs.txt", ios::app | ios::out);
        if (Myfile.is_open())
        {
            Myfile << TransferLogInfo << endl;
            Myfile.close();
        }
    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }
   
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }
  

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }
   // enum enTranserStatus {
   //     TransferFailedAmountExceedBalnace,
   //     TransferCancelled,
   //     TranserSucseeded

   // };
   //static enTranserStatus Transfer(clsBankClient TransferFromAcc, clsBankClient TransferToAcc, double TransferAmount)
   // {
   //     if (TransferAmount > TransferFromAcc.AccountBalance)
   //     {
   //         return enTranserStatus::TransferFailedAmountExceedBalnace;

   //     }
   //     char c = 'n';
   //     cout << "Are you sure you want to Perform this operation? y/n?";
   //     cin >> c;
   //     if (c == 'y' || c == 'Y')
   //     {
   //         TransferFromAcc.Withdraw(TransferAmount);
   //         TransferToAcc.Deposit(TransferAmount);
   //         return enTranserStatus::TranserSucseeded;

   //     }
   //     else {
   //         return enTranserStatus::TransferCancelled;
   //     }

   // }
   
  /* static bool Transfer(clsBankClient &TransferFromAcc, clsBankClient &TransferToAcc, double TransferAmount) {

                 TransferFromAcc.Withdraw(TransferAmount);
                 TransferToAcc.Deposit(TransferAmount);
                 
                 return true;


    }*/

    struct stTransferInfo {
        string  SourceAcc;
        string  DestinationAcc;
        double TransferAmount;
        double SourceAccNewBalance;
        double DestinationAccNewBalance;
        string userName;
        string Date;


    };

    bool Transfer(clsBankClient &DestinationAcc, double TransferAmount)
    {
        if (this->AccountBalance < TransferAmount)
        {
            return false;
        }
        else {
            this->Withdraw(TransferAmount);
            DestinationAcc.Deposit(TransferAmount);
            _RegisterTransferLog(DestinationAcc, TransferAmount);

          // _logTransferOperations( PrepareTransferLog(DestinationAcc.AccountNumber(), TransferAmount));

            return true;
        }
    }
    static vector<stTransferInfo>getTransferLogsList() {
        fstream MyFile;
        vector<stTransferInfo> vTransferLogsList;
        MyFile.open("TransferLogs.txt", ios::in);
        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                vTransferLogsList.push_back(_getTransferLogStruct(line));

            }
            MyFile.close();
        }
        return vTransferLogsList;

    }
};
