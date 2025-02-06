#pragma once
#include "clsScreen.h"
#include<vector>
#include"clsString.h"
#include"clsUser.h"
#include <fstream>
#include<iomanip>



class clsLoginRegisterScreen :
    protected clsScreen
{
private :
  
    static void   _getRegisterDataLine(clsUser::stLoginInfo stLogin)
    {
        cout << setw(8) << left << "" << "| " << setw(40) << left <<stLogin.Time_date;

        cout << "| " << setw(20) << left <<stLogin.UserName;
        cout << "| " << setw(10) << left << stLogin.PassWord;
        cout << "| " << setw(12) << left <<stLogin.Permissions;
    }
public:
    static void ShowLoginRegisterScreen() {
        if (!CheckAccessRigths(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("Login Register Screen");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Date /time";
       // cout << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(20) << "UserNmae";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;


        vector <clsUser::stLoginInfo>vLogins = clsUser::getLoginRegisterList();


        for (clsUser::stLoginInfo U : vLogins)
        {
            _getRegisterDataLine(U);
            cout<<endl;

        }




    }

};

