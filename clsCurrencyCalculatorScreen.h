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
#include "clsScreen.h"
class clsCurrencyCalculatorScreen :
    protected clsScreen
{
private:
    static string _ReadCurrencyCode() {
        string code;
        code = clsInputValidate::ReadString();
        while (!(clsCurrency::isCurrencyExist(code)))
        {
            cout << "\nCurrency not Found please enter another currency code\n";
            code = clsInputValidate::ReadString();
        }
        return code;

    }
 static  clsCurrency  _GetCurrency(string message) {
      return clsCurrency::FindByCode(_ReadCurrencyCode());
    }

 static float _ReadAmount() {
     cout << "\nEnter Amount to Exchange: ";
     return  clsInputValidate::ReadFloatNumber();
 }

    void static _Print(clsCurrency Currency) {
       
        cout << "\n______________________________________\n";
        cout << "Country: " << Currency.getCountry() << endl;
        cout << "Code: " << Currency.getCurrencyCode() << endl;
        cout << "Name : " << Currency.getCurrencyName() << endl;
        cout << "Rate(1$): " << Currency.getCurrencyRate() << endl;
        cout << "\n______________________________________\n";
    }
    static void _PrintCalculatiionsResults(clsCurrency Currency1, clsCurrency Currency2, float AmountToChange) {
        
        float AmountInUSD = Currency1.ConvertToUSD(AmountToChange);

        Currency1.ConverToOtherCurrency(AmountToChange, Currency2);

        cout << AmountToChange << " " << Currency2.getCurrencyCode() << " = " << AmountInUSD << " USD\n";

        cout << "\nConvert Form :\n";
        _Print(Currency1);

        if (Currency2.getCurrencyCode() == "USD")
        {
            return;

        }
        cout << "Converting from USD to:\n";

        _Print(Currency2);
        float AmountInCurrency2 = Currency1.ConverToOtherCurrency(AmountToChange, Currency2);
        cout << AmountToChange << " " << Currency2.getCurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.getCurrencyCode();

    }
   

public:
    static void ShowCurrencyCalculatorScreen() {
      
        char Again = 'n';

        do {
            system("cls");

            clsScreen::_DrawScreenHeader("\t Currency Calculator Screen");

            clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 code: ");
            clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 code : ");

      
            float AmountToChange = _ReadAmount();


            _PrintCalculatiionsResults(Currency1, Currency2, AmountToChange);



            cout << "Do You Want To Perform another calculation ? y/n? " ;
            Again = clsInputValidate::ReadChar();


        }while (toupper(Again) == 'Y');



    }
};

