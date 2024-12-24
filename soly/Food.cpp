#include "Food.h"
#include <fstream>
Food::Food()
{
	name = "Unknown";
	calories = 0;
}

Food::Food(string name, float calories) {
	this->name = name;
	this->calories = calories;
}

void Food::setName(string n)
{
	name = n;
}

void Food::setCal(float c)
{
	calories = c;
}

string Food::getn()
{
	return name;
}

float Food::getc()
{
	return calories;
}

void Food::writetofile(string filename)
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

vector<Food> Food::readallfile(string filename)
{
	vector<Food> Foods;
	ifstream infile(filename);
	if (infile.is_open()) {
		string name;
		float calories;
		while (getline(infile, name)) {
			infile >> calories;
			infile.ignore();
			Foods.push_back(Food(name, calories));
		}
		infile.close();
	}
	else {
		cerr << "Unable to open the file" << filename << endl;

	}
	return Foods;
}
