#include "Visual.h"
#include<iostream>
using namespace std;
int main()
{
	Visual v;
	Account a;
	int c;
	v.login_p();
	while (true)
	{
		cout << "1. view info" << endl;
		cout << "2. Add or choose food" << endl;
		cout << "3. Add workout" << endl;
		cout << "4. View food" << endl;
		cout << "5. View workout" << endl;
		cout << "6. calculate bmr" << endl;
		cout << "7. Exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			v.viewspecificuser();
			break;
		case 2:
			do
				{
			int c;
			cout << "1. Add food" << endl;
			cout << "2. Choose food" << endl;
			cout << "3. Exit" << endl;
			cin >> c;
			switch (c)
			{
				case 1:
				v.fillfoodtxt();
				break;
				case 2:
				v.selectfood();
				break;
				case 3:
				
				default:
				cout << "Not recognized!!";
				break;
				}
			} while (c != 3);
		case 3:
			v.fillworkouttxt();
			break;
		case 4:
			v.viewfood();
			break;
		case 5:
			v.viewworkout();
			break;
			case 6:
				v.calcfoodbmr();
				break;
		case 7:
			v.exit_a();
			break;
		default:
			cout << "Not recognized!!";
			break;
		}
			
	}
	
}