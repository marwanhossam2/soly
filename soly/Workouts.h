#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Workouts
{
	protected:
	string name;
	float calories;
public:
	Workouts();
	Workouts(string n, float c);
	void setname(string n);
	void setcal(float c);
	string getname();
	float getcal();
	void writetofile(string filename);
	static vector<Workouts> readallfile(string filename);


};