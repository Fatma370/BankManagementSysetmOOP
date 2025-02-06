#pragma once
#include "clsScreen.h"
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include"clsString.h"
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyScreen :
    public clsScreen
{

private:
    static string _ReadCode() {
        cout << "\n Please enter Currency Code? ";
        return  clsInputValidate::ReadString();

    }
   
    void static _Print(clsCurrency Currency) {
        cout << "\n Currency Card: \n";
        cout << "\n______________________________________\n";
        cout << "Country: " << Currency.getCountry() << endl;
        cout << "Code: " << Currency.getCurrencyCode() << endl;
        cout << "Name : " << Currency.getCurrencyName() << endl;
        cout << "Rate(1$): " << Currency.getCurrencyRate() << endl;
        cout << "\n______________________________________\n";
    }
    static  void _Update(clsCurrency &Currency) {
        cout << "\n Update Currency Rete: \n";
        cout << "_________________________________\n";
        cout << "\n please enter the new rate? ";
        float NewRate = clsInputValidate::ReadFloatNumber();
        Currency.UpdateCurrencyRate(NewRate);

    }


public:
    static void ShowUpdateCurrencyScrren() {
        clsScreen::_DrawScreenHeader("\t Update Currency Screen");
        string code = _ReadCode();
        while (!clsCurrency::isCurrencyExist(code))
        {
            cout << "\ncurrency is no found , please choose another one\n ";
            code = _ReadCode();
        }
        clsCurrency Currency = clsCurrency::FindByCode(code);


        
        _Print(Currency);

        cout << "\n Are you Sure YounWant to Update the rate of this Currency y/n ? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            _Update(Currency);
            cout << "Currency Rate Updated Sucessfully ";
            _Print(Currency);


        }
        else {
            cout << "\n operation is Cancelled\n";

        }

    }
};

