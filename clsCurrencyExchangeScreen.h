#pragma once
#include "clsScreen.h"
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include"clsString.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsCurrencyListScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
#include"clsFindCurrencyScreen.h"
class clsCurrencyExchangeScreen :
    protected clsScreen
{
private:
    enum enCurrencyEchangeMenueOption {
        listCurrenciesOP = 1,
        FindCurrencyOp = 2,
        UpdateCurrencyOp = 3,
        CurrencyCalculatorOP = 4,
        MainMenueOp = 5
    };
    static enCurrencyEchangeMenueOption _ReadCurrencyExchangeMenueOPtion()
    {
        int option;
        option = clsInputValidate::ReadIntNumberBetween(1, 6);
        return (enCurrencyEchangeMenueOption)option;

    }
    static void _GoBackToExchangeMenue()
    {
        cout << setw(37) << left  <<"press any key to go Back to menue\n\n";
        system("pause>0");
        ShowCureencyExchangeScreen();

    }
    static void _ListCurrenciesScreen() {
        clsCurrencyListScreen::ShowCurrencyExchangeScreen();
    }
    static void _FindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }
    static void _UpdateCurrencyScreen() {
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScrren();

    }
    static void _CurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }
    static void _PerformCurrencyExchangeMenueOPtion(enCurrencyEchangeMenueOption Option) {
        switch (Option)
        {
        case clsCurrencyExchangeScreen::listCurrenciesOP:
        {
            system("cls");
            _ListCurrenciesScreen();
            _GoBackToExchangeMenue();

            break;

        }
        case clsCurrencyExchangeScreen::FindCurrencyOp:
        {
            system("cls");
            _FindCurrencyScreen();
            _GoBackToExchangeMenue();

            break;

        }
        case clsCurrencyExchangeScreen::UpdateCurrencyOp:
        {
            system("cls");
            _UpdateCurrencyScreen();
            _GoBackToExchangeMenue();

            break;

        }
        case clsCurrencyExchangeScreen::CurrencyCalculatorOP:
        {
            system("cls");
            _CurrencyCalculatorScreen();
            _GoBackToExchangeMenue();

            break;

        }
        case clsCurrencyExchangeScreen::MainMenueOp:
        {

         
        }
        default:
            break;
        }
    }

public:
    static void ShowCureencyExchangeScreen() {
        system("cls");
        clsScreen::_DrawScreenHeader("\t Currency Exchange Main Screen");
        cout << "\t\t\t\t\t====================================";
        cout << "\n\n\t\t\t\t\t    Currency Exchange Menue\n";  
        cout << "\t\t\t\t\t====================================\n\n";

        
        cout << setw(37) << left << "" << "\t[1] List Currencies .\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] currency Calculator\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue\n";
        cout << "\t\t\t\t\t====================================\n\n";

        cout << "\t\t\t\tChoose what do you want to do ? [1,5]  ";
        _PerformCurrencyExchangeMenueOPtion(_ReadCurrencyExchangeMenueOPtion());

    }
};

