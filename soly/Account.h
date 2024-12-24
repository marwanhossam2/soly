#pragma once
#include <iostream>
#include <string>
using namespace std;
class Account
{
protected:
	string Name, Gender, Email, Password;
	float Weight, Length, Calorie_intake;
	int Age;
	double bmr;
	enum ActivityLevelsEnum {
		LOW,
		MODERATE,
		HIGH,
	};
	ActivityLevelsEnum level;
public:
	Account();
	Account(string n, string g, string e, string p, float w, float l, float c, int a, ActivityLevelsEnum v);
	string setactivitylevel();
	float Cal_clc(string x);
	void setbmr(double b);
	double getbmr();
	

};
