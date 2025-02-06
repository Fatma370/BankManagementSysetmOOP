#pragma once

#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include<fstream>
#include "Global.h"
#include"clsDate.h"
static string LoginFile = "LogIns.txt";


class clsLoginScreen :protected clsScreen
{
    


private:
  /*  static string _getUserLoginRecord()
    {
        string delim = "#//#";
        clsDate Date = clsDate::GetSystemDate();
        string date = clsDate::FormatDate(Date, "dd/MM/yyyy");
        string time = clsDate::getCurrentTime();
        return date + " - " + time + delim + CurrentUser.UserName + delim + CurrentUser.Password + delim +to_string( CurrentUser.Permissions);


    }*/
   /* static void RegisterLogin() {
     
        fstream Myfile;
        Myfile.open(LoginFile, ios::app);
            if(Myfile.is_open())
        {
                Myfile << _getUserLoginRecord() << endl;
                Myfile.close();

        }
    }*/
static bool _Login()
{
    bool LoginFaild = false;
    int failCounter = 0;

    string Username, Password;
    do
    {
        if (failCounter == 2)
        {
            cout << "\n\nyou are Locked after 3 falid trails!!\n\n";
            return 0;
        }

        if (LoginFaild)
        {
            cout << "\nInvlaid Username/Password!\n\n";
            failCounter++;
            cout << "you have " <<to_string( 3 - failCounter) << "trails left!" << endl;
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        CurrentUser = clsUser::Find(Username, Password);

        LoginFaild = CurrentUser.IsEmpty();

    } while (LoginFaild);

   /* RegisterLogin();*/
    CurrentUser.RegisterLogIn();

    clsMainScreen::ShowMainMenue();
    return true;

}

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return  _Login();

    }

};
