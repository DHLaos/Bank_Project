#include<iostream>
#include<string>
#include "NumPren.h"
#include "FileHandler.h"
#include "Login.h"
using namespace std;


int main()
{
	int reRun = 1;
	while (reRun) {
		cout << "############################################################################" << endl;
		cout << "##                         WELCOME TO HAUCA BANK!                         ##" << endl;
		cout << "############################################################################" << endl;
		cout << "## Please select an operation from the following list                     ##" << endl;
		cout << "## 1. Create an account.                                                  ##" << endl;
		cout << "## 2. Login.                                                              ##" << endl;
		cout << "## 3. Exit.                                                               ##" << endl;
		cout << "############################################################################" << endl;
		int nr;
		do {
			cout << "## Enter a number from the above list [1/2/3]:";
			cin >> nr;
			cout << "############################################################################" << endl;
			switch (nr)
			{
			case 1: //Access to NumPren.cpp to create an account
			{
				NumPren np;
				np.scriereNP();    // First Name - Last Name
				np.scriereCI();   // Personal Number Code
				np.confirmare(); //Confirm account Creation -> AccountCreation.cpp from NumPren
				break;
			}
			case 2: //
			{
				Login log; //Login.cpp is used to create this object
				log.scriereDate(); //
				int option = log.actiuni();

				if (option == 5) {
					cout << "## 0.Exit Bank                                                            ##" << endl;
					cout << "## 1.Loggout                                                              ##" << endl;
					cout << "## Enter option: ";
					cin >> reRun;
					if (reRun == 0)
					{
						cout << "############################################################################" << endl;
					}
				}
				break;
			}
			case 3:
				return 0;
			default:
				cout << "## Invalid Option, choose a number from the available operation list      ##" << endl;
				break;
			}
		} while (nr != 1 && nr != 2 && nr != 3);
	}
	return 0;
	cout << endl;
}