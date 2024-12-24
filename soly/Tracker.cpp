#include "Tracker.h"

vector<Workouts> Tracker::workouts;
vector<Food> Tracker::foods;
Tracker::Tracker()
{
	string workout = "Workouts.txt";
	string food = "Foods.txt";
	foods = Food::readallfile(food);
	workouts = Workouts::readallfile(workout);

}
float Tracker::Food_calc(Food f, float grams)
{
	return f.getc() * grams;
}
float Tracker::Work_calc(Workouts w, float s, float d)
{
	return w.getcal() * d * s;
}
void Tracker::addFood(const Food& f) { foods.push_back(f); }
void Tracker::addWorkout(const Workouts& w) { workouts.push_back(w); }

vector<Food> Tracker::getFoods() { return foods; }
vector<Workouts> Tracker::getWorkouts() { return workouts; }
