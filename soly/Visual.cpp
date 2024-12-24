#include "Visual.h"
using namespace std;
ofstream f1("count.txt", ios::app);
string filename;
string fileacc;
int Visual::count = 0;
Visual::Visual()
{
	int c;
	ifstream counter("count.txt");
	if (!counter)
	{
		cerr << "Unable to open file!!";
	}
	while (counter >> c)
	{
		count = c;
	}
	counter.close();

}
void Visual::login_p()
{
	system("cls");
	int c;
	cout << "1-Login\n2-Register\n3-Exit\n" << filename << "\nChoice:";
	cin >> c;
	switch (c)
	{
	case 1:
		if (count != 0)
		{
			login();
		}
		else
		{
			cout << "no accounts registerd";
		}
		cin.ignore();
		cin.get();
		
		break;
	case 2:register_p();
		break;
	case 3:exit_a();
		break;
	default:cout << "Not recognized!!";
		
		break;
	}
}
void Visual::login()
{
	string email, password, femail, fpassword;
	int check = 0;
	int c;
	Account a;
	system("cls");
	cout << "\t\tLogin\n\nEmail:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, email);
	cout << "Password:";
	getline(cin, password);
	for (int i = 1; i <= count; i++)
	{
		string first = "account";
		string middle = "info";
		string last = to_string(i);
		fileacc = first + middle + last + ".txt";
		ifstream f1(fileacc);
		if (f1.is_open())
		{
			while (f1 >> femail >> fpassword)
			{
				if (femail == email && fpassword == password)
				{
					check = 1;
					break;
				}
			}
			f1.close();
		}
		else
		{
			cerr << "can't access file:" << fileacc;
		}
		if (check == 1)
		{
			break;
		}
	}
	if (check == 1)
	{
		system("cls");
		cout << "\tLogin Successful!! ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		
	}
	else
	{
		cout << "Account not found!!";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		login_p();
		exit(0);
	}
	
	
}

void Visual::create_file()
{
	int c;
	ifstream counter("count.txt");
	if (!counter)
	{
		cerr << "Unable to open file!!";
	}
	if (counter.tellg() != 0 && count == 0)
	{
		while (counter >> c)
		{
			count = c;
		}
		counter.close();
	}
	else
	{
		count++;
		string first = "account";
		string middle = "info";
		string last = to_string(count);
		filename = first + last + ".txt";
		fileacc = first + middle + last + ".txt";
		ofstream f1(filename, ios::app);
		ofstream f2(fileacc, ios::app);
	}
}

void Visual::register_p()
{
	string name, gender, email, password;
	float weight, length;
	double bmr;
	int age;
	bool g = false;
	Account a;
	system("cls");
	create_file();
	cout << "\t\tRegister\n\nenter your Name:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Enter your Email:";
	getline(cin, email);
	cout << "Enter your password:";
	getline(cin, password);
	while (!g)
	{

		cout << "Enter your Gender:";
		getline(cin, gender);
		transform(gender.begin(), gender.end(), gender.begin(), [](unsigned char c) { return tolower(c); });
		if (gender == "male" || gender == "female")
		{
			g = true;
		}
		else
		{
			cout << "Not recognized!!\n";
			g = false;
		}
	}
	do
	{
		cout << "Enter your Age:";
		cin >> age;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!!\n";
			cout << "Enter your Age:";
			cin >> age;
		}
		if (age <= 0 || age > 100)
		{
			cout << "Age is invalid!!";
			g = false;
		}
		else
		{
			g = true;
		}
	} while (!g);
	do
	{
		cout << "Enter your Weight(Kg):";
		cin >> weight;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!!\n";
			cout << "Enter your Weight(Kg):";
			cin >> weight;
		}
		if (weight <= 0 || weight > 200)
		{
			cout << "Weight invalid!!";
			g = false;
		}
		else
		{
			g = true;
		}
	} while (!g);
	do
	{
		cout << "Enter your Lenght(centimeter):";
		cin >> length;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!!\n";
			cout << "Enter your Lenght(centimeter):";
			cin >> length;
		}
		if (length <= 120 || length > 272)
		{
			cout << "Length is invalid!!";
			g = false;
		}
		else
		{
			g = true;
		}
	} while (!g);
	a.setactivitylevel();
	bmr=a.Cal_clc(activitylevel);
	ofstream f1(fileacc);
	f1 << email << endl << password << endl;
	f1.close();
	ofstream f2(filename);
	f2 << age << endl << weight << endl << length << endl << bmr << endl;
	f2.close();
	system("cls");
	cout << "\tRegisteration successful!!";
	cin.ignore();
	cin.get();
	login_p();
}
void Visual::exit_a()
{
	if (count == 0)
	{
		exit(0);
	}
	else
	{
		ofstream counter("count.txt");
		counter << count << endl;
		counter.close();
		exit(0);
	}
}
void Visual::createfoodtxt()
{
	ofstream f1("food.txt", ios::app);
	if (!f1)
	{
		cerr << "Unable to open file!!";
	}
	f1.close();
}
void Visual::fillfoodtxt()
{
	int c;
	string name;
	float calories;
	system("cls");
	
		Food f;
		cout << "Enter the name of the food:";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
		cout << "Enter the calories of the food per gram:";
		cin >> calories;
		cout << '\n';
		f.setName(name);
		f.setCal(calories);
		f.writetofile("food.txt");
	
}
void Visual::viewspecificuser()
{
	for(int i=1;i<=count;i++)
	{
		string first = "account";
		string middle = "info";
		string last = to_string(i);
		filename = first + last + ".txt";
		fileacc = first + middle + last + ".txt";
		ifstream f1(filename);
		ifstream f2(fileacc);
		if (f1.is_open()&& f2.is_open())
		{
			int age , weight , length;
			string email, password;
			float bmr;
			while (f1 >> age >> weight >> length >> bmr)
			{
				cout << "Age:" << age << endl;
				cout << "Weight:" << weight << endl;
				cout << "Length:" << length << endl;
				cout << "BMR:" << bmr << endl;
				cin.get();
			}
			f1.close();
			while(f2 >> email >> password)
			{
				cout << "Email:" << email << endl;
				cout << "Password:" << password << endl;
				cin.get();
			}

		}
		else
		{
			cerr << "can't access file:" << fileacc;
		}
	}

}
void Visual::createworkouttxt()
{
	ofstream f1("workout.txt", ios::app);
	if (!f1)
	{
		cerr << "Unable to open file!!";
	}
	f1.close();
}
void Visual::fillworkouttxt()
{
	int c;
	string name;
	float calories;
	system("cls");
	cout << "1-Add workout\n2-Exit\nChoice:";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		Workouts w;
		cout << "Enter the name of the workout:";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
		cout << "Enter the calories of the workout:";
		cin >> calories;
		w.setname(name);
		w.setcal(calories);
		w.writetofile("workout.txt");
		break;
	}
	break;
	case 2:exit(0);
		break;
	default:cout << "Not recognized!!";
		fillworkouttxt();
		break;
	}
}
void Visual::viewfood()
{
	vector<Food> food = Food::readallfile("food.txt");
	for (int i = 0; i < food.size(); i++)
	{
		cout << "Name:" << food[i].getn() << endl;
		cout << "Calories:" << food[i].getc() << endl;
	}
}
void Visual::viewworkout()
{
	vector<Workouts> workout = Workouts::readallfile("workout.txt");
	for (int i = 0; i < workout.size(); i++)
	{
		cout << "Name:" << workout[i].getname() << endl;
		cout << "Calories:" << workout[i].getcal() << endl;
	}
}
void Visual::selectfood()
{
	vector<Food> food = Food::readallfile("food.txt");
	int c;
	cout << "Select the food you want:" << endl;
	for (int i = 0; i < food.size(); i++)
	{
		cout << i+1 << "." << food[i].getn() << endl;
	}
	cin >> c;
	if (c > food.size())
	{
		cout << "Not recognized!!";
	}
	else
	{
		cout << "You have selected:" << food[c-1].getn() << endl;
	}
}
void Visual::selectworkout()
{
	vector<Workouts> workout = Workouts::readallfile("workout.txt");
	int c;
	cout << "Select the workout you want:" << endl;
	for (int i = 0; i < workout.size(); i++)
	{
		cout << i+1 << "." << workout[i].getname() << endl;
	}
	cin >> c;
	if (c > workout.size())
	{
		cout << "Not recognized!!";
	}
	else
	{
		cout << "You have selected:" << workout[c].getname() << endl;
	}
}
void Visual::calcfoodbmr()
{
	vector<Food> food = Food::readallfile("food.txt");
	vector<Workouts> workout = Workouts::readallfile("workout.txt");
	float grams, s, d;
	int c;
	Account a;
	cout << "1.Calculate food\n2.Calculate workout\nChoice:";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		cout << "Enter the grams of the food:";
		cin >> grams;
		selectfood();
		cout << "The calories of the food are:" << Tracker::Food_calc(food[c-1], grams) << endl;
		cout << "your daily remaining calories are:" << a.Cal_clc(activitylevel) << "-"<<  Tracker::Food_calc(food[c - 1], grams) << " = " << a.Cal_clc(activitylevel) - Tracker::Food_calc(food[c - 1], grams) << " calories\n";
		break;
	}
	case 2:
	{
		cout << "Enter the duration of the workout:";
		cin >> d;
		cout << "Enter the sets of the workout:";
		cin >> s;
		selectworkout();
		cout << "The calories of the workout are:" << Tracker::Work_calc(workout[c-1], s, d) << endl;
		break;
	}
	default:cout << "Not recognized!!";
		break;
	}
}
