#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Food.h"
#include"Workouts.h"
using namespace std;
class Tracker
{
	static vector<Workouts> workouts;
	static vector<Food> foods;
public:
	Tracker();
	static float Food_calc(Food f, float grams);
	static float Work_calc(Workouts w, float s, float d);

	static void addFood(const Food& f);
	static void addWorkout(const Workouts& w);
	static vector<Food> getFoods();
	static vector<Workouts> getWorkouts();
};
