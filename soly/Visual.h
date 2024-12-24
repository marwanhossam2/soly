#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include<cctype>
#include "Account.h"
#include "Food.h"
#include "Workouts.h"
#include "Tracker.h"

using namespace std;
class Visual : public Account, public Food, public Workouts, public Tracker
{
	static int count;
public:
	Visual();
	void login_p();
	void login();
	void create_file();
	void register_p();
	void viewspecificuser();
	void exit_a();
	void createfoodtxt();
	void fillfoodtxt();
	void createworkouttxt();
	void fillworkouttxt();
	void viewfood();
	void viewworkout();
	void selectfood();
	void selectworkout();
	void calcfoodbmr();
};

