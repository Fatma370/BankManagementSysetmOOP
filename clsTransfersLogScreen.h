#pragma once
#include "clsScreen.h"
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include <fstream>
#include<iomanip>
#include"clsTransferScreen.h"
#include<string>
#include"clsBankClient.h"


class clsTransfersLogScreen :
    protected clsScreen
{
private:
    static void _getTransferDataLine(clsBankClient::stTransferInfo TransferInfo) {

        cout << setw(8) << left << "" << "| " << setw(30) << left <<TransferInfo.Date;

        cout << "| " << setw(10) << left << TransferInfo.SourceAcc;
        cout << "| " << setw(10) << left << TransferInfo.DestinationAcc;
        cout << "| " << setw(20) << left << to_string(TransferInfo.TransferAmount);
        cout << "| " << setw(15) << left << to_string(TransferInfo.SourceAccNewBalance);
        cout << "| " << setw(15) << left << to_string(TransferInfo.DestinationAccNewBalance);
        cout << "| " << setw(20) << left << TransferInfo.userName;


    }

  

public :
    static void ShowTransferLogsScreen() {
     // if(  clsScreen::CheckAccessRigths())
        vector <clsBankClient::stTransferInfo>vTransferLogList = clsBankClient::getTransferLogsList();

        string title = "\t Transfer Log List Screen";
        string subtitle = "\t ( " + to_string(vTransferLogList.size()) + ") Record(s)";

        clsScreen::_DrawScreenHeader(title, subtitle);
        if (vTransferLogList.size() == 0)
        {
            cout << "\n\nNo Transfer Operations Are Registerd On The System \n";
        }
        

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "________________________________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(30) << "Date /time";
            // cout << "| " << left << setw(40) << "Date/Time";
            cout << "| " << left << setw(10) << "S.Acct";
            cout << "| " << left << setw(10) << "d.Acct";
            cout << "| " << left << setw(20) << "Amount";
            cout << "| " << left << setw(15) << "S.Balance";
            cout << "| " << left << setw(15) << "d.Balance";
            cout << "| " << left << setw(20) << "User";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "________________________________________________________________\n" << endl;




        
            for (clsBankClient::stTransferInfo TransferInfo : vTransferLogList)
            {
                _getTransferDataLine(TransferInfo);
                    cout<< endl;
            }

    }
};

