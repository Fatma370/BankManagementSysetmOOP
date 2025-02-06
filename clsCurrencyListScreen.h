#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include"clsString.h"
#include "clsScreen.h"
#include"clsCurrency.h"



class clsCurrencyListScreen :
    public clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.getCountry();
        cout << "| " << setw(10) << left <<Currency.getCurrencyCode();
        cout << "| " << setw(40) << left << Currency.getCurrencyName();
        cout << "| " << setw(20) << left <<Currency.getCurrencyRate() ;
      

    }

public:
    static void ShowCurrencyExchangeScreen(){
       
        vector<clsCurrency>vCurrencies = clsCurrency::getCurrenciesList();
        string subtitle = "\t   (" + to_string(vCurrencies.size()) + ") Currencie(s)\n";
        clsScreen::_DrawScreenHeader("\t Currency List Screen",subtitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country ";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(20) << "Rate/(1$)";
       
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
        if (vCurrencies.size() == 0)
        {
            cout << "\n No Currencies in the system \n ";
        }

        for (clsCurrency& Currency : vCurrencies)
        {
            _PrintCurrencyRecordLine(Currency);
            cout << endl;
        }


    }

};

