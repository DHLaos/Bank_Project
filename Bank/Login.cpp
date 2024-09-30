#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Login.h"
#include "AccountCreation.h"
#include "FileHandler.h"
using namespace std;

Login::Login() : id(""), pass("") {}

void Login::scriereDate()
{
	cout << "## Please enter your username(ID): ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, id);
	cout << "## Please enter your password: ";
	getline(cin, pass);
	cout << "############################################################################" << endl;
}

int Login::actiuni()
{
	FileHandler auth("accounts.txt");
	AccountCreation login = auth.authenticate(id, pass);
	int nr2=0;
	if (login.getID() != "")
	{
		cout << "## Login Succesfull!                                                      ##" << endl;
		cout << "## Please select an operation for your account!                           ##" << endl;
		cout << "############################################################################" << endl;
		cout << "## 1. Interogate account (IBAN & Balance)                                 ##" << endl;
		cout << "## 2. Add balance to account (Simulation of local ATM)                    ##" << endl;
		cout << "## 3. Cash out of ATM (Simulation of local ATM)                    ##" << endl;
		cout << "## 4. Transfer balance                                                    ##" << endl;
		cout << "## 5. Logout                                                              ##" << endl;
		cout << "############################################################################" << endl;
		do {
			cout << "## Select a number corresponding to your operation [1/2/3/4]: ";
			cin >> nr2;
			cout << "############################################################################" << endl;
			switch (nr2)
			{
			case 1:
			{
				cout << "## IBAN: " << login.getIBAN() << "|| Balance: " << login.getBalance() << endl;
				cout << "############################################################################" << endl;
				break;
			}
			case 2:
			{
				float suma;
				cout << "## Insert cash into the ATM: "; cin >> suma;
				login += suma;
				cout << "## New account Balance: " << login.getBalance() << endl;
				auth.saveChanges(login);
				cout << "############################################################################" << endl;
				break;
			}
			case 3:
			{
				float suma2;
				cout << "## Retrieve money from ATM: "; cin >> suma2;
				login -= suma2;
				cout << "## New account Balance: " << login.getBalance() << endl;
				auth.saveChanges(login);
				cout << "############################################################################" << endl;
				break;
			}
			case 4:
			{
				string ib;
				float suma3;
				cout << "## Please write the IBAN of the person you want to transfer money.     ##" << endl;
				cout << "## IBAN: "; cin >> ib;
				vector<AccountCreation> accounts = auth.readAcc();
				bool found = false;
				AccountCreation* recipient = nullptr;
				for (AccountCreation& acc : accounts)
				{
					if (acc.getIBAN() == ib)
					{
						recipient = &acc;
						found = true;
						break;
					}
				}
				if (found && recipient != nullptr)
				{
					cout << "## Sum to transfer: "; cin >> suma3;
					if (login.transferMoney(*recipient, suma3))
					{
						cout << "## Transfer was succesfull!                                               ##" << endl;
						auth.saveChanges(login);
						auth.saveChanges(*recipient);
					}
					else 
					{
						cout << "## Insuficient funds                                                      ##" << endl;
					}
				}
				else
				{
					cout << "## IBAN is invalid, please try again!                                     ##" << endl;
				}
				cout << "############################################################################" << endl;
				break;
			}
			default:
				cout << "## Invalid Option, choose a number from the available operation list      ##" << endl;
				break;
			}
		} while (nr2 != 5);
	}
	else
	{
		cout << "Invalid Login. Please try again.\n";
	}
	return nr2;
}