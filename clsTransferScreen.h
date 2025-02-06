#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"fstream"
#include "clsDate.h"


class clsTransferScreen :
    protected clsScreen
{
 
private:
    struct stTransferInfo;
    
   
   
    static string  _ReadAccountNumber() {
        string AccountNumber= "";
        cout << "\nPlease Enter Account Number to transfer from : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }
    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
      
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
   

public:
   
    static void ShowTransferScreen() {
        clsScreen::_DrawScreenHeader("\t\t transfer Screen");

        clsBankClient SourceAcc = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceAcc);

        clsBankClient DestinationAcc = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationAcc);

        double transferAmount = _ReadAmount(SourceAcc);

        char c = 'n';
             cout << "Are you sure you want to Perform this operation? y/n?";
             cin >> c;
             if (c == 'y' || c == 'Y')
             {
                 if (SourceAcc.Transfer(DestinationAcc,transferAmount))
                 {
                    
                    
                     cout << "\nTransfer done Successfully\n";
                  
                     _PrintClient(SourceAcc);
                     _PrintClient(DestinationAcc);

                }
                 
             }
             else {
                 cout << "\nOperation is cancelled\n";
             }
        


        //clsBankClient::enTranserStatus TransferResult;

        //switch (TransferResult)
        //{
        //case clsBankClient::TransferFailedAmountExceedBalnace:
        //{
        //    cout<<"Amount Exceeds the available Balance, enter another Amount ? ";
        //}
        //    break;
        //case clsBankClient::TransferCancelled:
        //    break;
        //case clsBankClient::TranserSucseeded:
        //    break;
        //default:
        //    break;
        //}

       /* bool TransferFalid = false;

        while (TransferFalid) {
            if (!(clsBankClient::Transfer(Client1, Client2, TransferAmount)))
            {
                TransferFalid = true;
                cout << "Amount Exceeds the available Balance , enter another Amount?";
                TransferAmount = clsInputValidate::ReadDblNumber();
            }
            else {

            }
        }*/


    }


};

