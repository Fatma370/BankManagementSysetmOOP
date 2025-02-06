#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include"clsString.h"
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :
    protected clsScreen
{
private:
    enum enFindOption {
        ByCode=1,
        ByCountry=2
    };
    static enFindOption _ReadFindOPtion() {
        cout << "zn Find By [1] code , [2] Country ?";
        int option = clsInputValidate::ReadIntNumberBetween(1, 2);
        return (enFindOption)option;

    }
    static string _ReadCode() {
        cout << "\n Please enter Currency Code? ";
       return  clsInputValidate::ReadString();
       
    }
    static string _ReadCountry() {
        cout << "\n Please enter Currency Country? ";
        return  clsInputValidate::ReadString();

    }
    static clsCurrency _Find() {
        enFindOption option = _ReadFindOPtion();

        switch (option)
        {
        case clsFindCurrencyScreen::ByCode:
        {
            string code = _ReadCode();
           return clsCurrency::FindByCode(code);
           break;
        }
        case clsFindCurrencyScreen::ByCountry:
        {
            string Country = _ReadCountry();

            return clsCurrency::FindByCountry(Country);
            break;

        }
        default:
            break;
        }
    }
     void static _Print(clsCurrency Currency) {
        cout << "\n Currency Card: \n";
        cout << "\n______________________________________\n";
        cout << "Country: " <<Currency.getCountry() << endl;
        cout << "Code: " << Currency.getCurrencyCode() << endl;
        cout << "Name : " << Currency.getCurrencyName() << endl;
        cout << "Rate(1$): " << Currency.getCurrencyRate() << endl;
        cout << "\n______________________________________\n";
    }

public:
    static void ShowFindCurrencyScreen() {
        clsScreen::_DrawScreenHeader("\t Find Currency Screen ");
       clsCurrency Currency= _Find();

       if (Currency.isEmpty())
       {
           cout << "\n Currency not Found !! \n";

       }
       else {
           cout << "\nCurrency Found :-)\n";
       }
       _Print(Currency);
       return; 

    }
};

