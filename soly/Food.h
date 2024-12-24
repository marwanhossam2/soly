#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Food
{
protected:
	string name;
	float calories;
public:
	Food();
	Food(string n, float c);
	void setName(string n);
	void setCal(float c);
	string getn();
	float getc();
	void writetofile(string filename);
	static vector<Food> readallfile(string filename);
};

