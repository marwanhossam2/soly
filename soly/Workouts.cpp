#include "Workouts.h"

Workouts::Workouts()
{
	name = "Unknown";
	calories = 0;
}

Workouts::Workouts(string n, float c)
{
	this->name = n;
	this->calories = c;
}

void Workouts::setname(string n)
{
	name = n;
}

void Workouts::setcal(float c)
{
	calories = c;
}

string Workouts::getname()
{
	return name;
}

float Workouts::getcal()
{
	return calories;
}

void Workouts::writetofile(string filename)
{
	ofstream outfile(filename, ios::app);
	if (outfile.is_open()) {
		outfile << name << endl << calories << endl;
		outfile.close();

	}
	else {
		cerr << "Unable to open file!!" << filename << endl;
	}
}

vector<Workouts> Workouts::readallfile(string filename)
{
	vector<Workouts> workout;
	ifstream infile(filename);
	if (infile.is_open()) {
		string name;
		float calories;
		while (getline(infile, name)) {
			infile >> calories;
			infile.ignore();
			workout.push_back(Workouts(name, calories));
		}
		infile.close();
	}
	else {
		cerr << "Unable to open the file" << filename << endl;

	}
	return workout;
}
