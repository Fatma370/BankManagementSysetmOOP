#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
#include"clsString.h"
class clsCurrency
{
private:
	enum enMode {
		UpdateMode=0,
		EmptyMode
	};
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _CurrencyRate;
	enMode _Mode;
static clsCurrency _ConvertLineToCurrencyObj(string line) {
		vector<string>vCurrencyInfo = clsString::Split(line,"#//#");
		return clsCurrency(enMode::UpdateMode, vCurrencyInfo[0], vCurrencyInfo[1], vCurrencyInfo[2], stof(vCurrencyInfo[3]));


	}

static string _getCurrencyDataLine(clsCurrency currency, string Separtor = "#//#")
{
	string CurrencyDataLine = "";
	CurrencyDataLine += currency._Country + Separtor;
	CurrencyDataLine += currency._CurrencyCode + Separtor;
	CurrencyDataLine += currency._CurrencyName + Separtor;
	CurrencyDataLine += to_string(currency._CurrencyRate);
	return CurrencyDataLine;

}

static void _SaveDataToFile(vector<clsCurrency>vCurrencies) {
	fstream Myfile;
	Myfile.open("Currencies.txt", ios::out);
	if (Myfile.is_open())
	{
		for (clsCurrency& c : vCurrencies)
		{
			Myfile << _getCurrencyDataLine(c) << endl;
		}
		Myfile.close();
	}



}
void _Update() {
	vector<clsCurrency>vCurrencies = getCurrenciesList();

	for (clsCurrency& c : vCurrencies)
	{
		if (c._CurrencyCode == this->_CurrencyCode)
		{
			c._CurrencyRate = this->_CurrencyRate;
			break;
		}

	}
	_SaveDataToFile(vCurrencies);

}

	static string  _ConvertCurrencyObjToLine(clsCurrency currency, string Separtor) {
		string CurrencyDataLine = "";
		CurrencyDataLine += currency._Country + Separtor;
		CurrencyDataLine += currency._CurrencyCode + Separtor;
		CurrencyDataLine += currency._CurrencyName + Separtor;
		CurrencyDataLine += to_string(currency._CurrencyRate);
		return CurrencyDataLine;

	}
	static clsCurrency _getEmptyCurrencyObj() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);


	}

public:
	string getCountry() {
		return _Country;
	}
	string getCurrencyCode() {
		return _CurrencyCode;
	}
	string getCurrencyName() {
		return _CurrencyName;
	}
	float getCurrencyRate() {
		return _CurrencyRate;
	}
	///
	void UpdateCurrencyRate(float CurrencyRate) {
		this->_CurrencyRate = CurrencyRate;
		_Update();
	}

	clsCurrency(enMode mode,string Country, string CurrencyCode, string CurrencyName, float CurrencyRate)
	{
		this->_Mode = mode;
		this->_Country = Country;
		this->_CurrencyCode = CurrencyCode;
		this->_CurrencyName = CurrencyName;
		this->_CurrencyRate = CurrencyRate;

	}
	bool isEmpty() {
		return (this->_Mode == enMode::EmptyMode);

	}
	static vector<clsCurrency>getCurrenciesList() {
		vector<clsCurrency>vCurruncies;
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				if (line != "") {
					clsCurrency currency = _ConvertLineToCurrencyObj(line);
					vCurruncies.push_back(_ConvertLineToCurrencyObj(line));

				}
			}
			Myfile.close();
		}
		return vCurruncies;
	}

	 static clsCurrency FindByCode(string code) {
		vector<clsCurrency>vCurruncies;
		fstream Myfile;
		Myfile.open("Currencies.txt");
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				code = clsString::UpperAllString(code);


				clsCurrency currency = _ConvertLineToCurrencyObj(line);
				if (currency._CurrencyCode == code) {
					Myfile.close();
					return currency;
				}
				
			}
		}
		Myfile.close();
		return _getEmptyCurrencyObj();
	}
	 static clsCurrency FindByCountry(string country) {
		vector<clsCurrency>vCurruncies;
		fstream Myfile;
		Myfile.open("Currencies.txt");
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObj(line);
				if (clsString::UpperAllString(currency._Country) == clsString::UpperAllString(country) ){
					Myfile.close();
					return currency;
				}

			}
		}
		Myfile.close();
		return _getEmptyCurrencyObj();
	}

	 static bool isCurrencyExist(string CurrencyCode)
	 {
		 clsCurrency C1 = FindByCode(CurrencyCode);
		 return (!C1.isEmpty());
	 }

	 float  ConvertToUSD(float Amount)
	 {
		 return (float)Amount / this->getCurrencyRate();

	 }
	 float ConverToOtherCurrency(float Amount, clsCurrency Currency2)
	 {

		 if (Currency2.getCurrencyCode() != "USD")
		 {
			 return( ConvertToUSD(Amount)*Currency2.getCurrencyRate());
		 }
		 else {
			 return ConvertToUSD(Amount);

		 }

	 }


};

