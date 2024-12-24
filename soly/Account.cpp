#include "Account.h"
Account::Account() {
	Name = "Unknown";
	Gender = "Unknown";
	Email = "Unknown";
	Password = "Unknown";
	Weight = 0.0;
	Length = 0.0;
	Calorie_intake = 0.0;
	Age = 0;
	level = LOW;
}
Account::Account(string n, string g, string e, string p, float w, float l, float c, int a, ActivityLevelsEnum v)
{
	Name = n;
	Gender = g;
	Password = p;
	Email = e;
	Weight = w;
	Length = l;
	Age = a;
	Calorie_intake = c;
	level = v;
}

float Account::Cal_clc(string x)
{
	float bmr;
	if (this->Gender == "male") {
		bmr = 66.47 + (13.75 * Weight) + (5.003 * Length) - (6.755 * Age);
	}
	else {
		bmr = 655.1 + (9.563 * Weight) + (1.850 * Length) - (4.676 * Age);
	}
	if (x == "Low")
	{
		bmr *= 1.2;
	}
	else if (x == "Moderate")
	{
		bmr *= 1.55;
	}
	else if (x == "High")
	{
		bmr *= 1.725;
	}
	setbmr(bmr);
	return bmr;
}
void Account::setactivitylevel()
{
	string a;
	int x;
	cout << "Enter your activity level:\n1.Low\n2.Moderate\n3.High\n";
	cin >> x;
	if(x==1)
	{
		level = LOW;
		a= "Low";
	}
	else if(x==2)
	{
		level = MODERATE;
		a="Moderate";
	}
	else if(x==3)
	{
		level = HIGH;
		a = "High";
	}
	else
	{
		cout << "Invalid input!!";
	}
	this->activitylevel = a;
}
void Account::setbmr(double b)
{
	bmr = b;
}
double Account::getbmr()
{
	return bmr;
}
