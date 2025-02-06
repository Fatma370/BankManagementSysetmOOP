#pragma once
#include <iostream>
#include"Global.h"
#include"clsUser.h"
#include <ctime>
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")

    {
       
        clsDate CurrentTime = clsDate::GetSystemDate();
        string date = clsDate::FormatDate(CurrentTime,"dd/MM/yyyy");
       
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        if(!CurrentUser.IsEmpty()) {
            cout << "\t\t\t\t\t " << date;
            cout << "\n\n\t\t\t\t\t UserName :" << CurrentUser.UserName;
            cout << "\n\t\t\t\t\t______________________________________\n\n";
        }

    }

    static bool CheckAccessRigths(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t_____________________________________________________\n";
            cout << "\n\t\t\t\t\t Access Denied ! Contact Your Admin!!\n\n";
                cout << "\t\t\t\t\t_____________________________________________________\n";
                return false;


        }
        else {
            return true; 
        }
    }
    

};

