#include "AccountCreation.h"
#include <iostream>
#include <random> // random number generation
#include <iomanip> // formatting output
#include <sstream>

using namespace std;

AccountCreation::AccountCreation(const string& n, const string& p, const string& ci, float s, const string& id, const string& iban, const string& pwd) : nume(n), prenume(p), CI(ci), balanta(s), ID(id), iban(iban), pwd(pwd) {}

AccountCreation AccountCreation::operator+=(float suma)
{
    cout << "Operator de depozitare" << endl;
    balanta += suma;
    return *this;
}

AccountCreation AccountCreation::operator-=(float suma)
{
    cout << "Operator de retragere" << endl;
    balanta -= suma;
    return *this;
}

void AccountCreation::afisareINT() const
{
    cout << "Unique ID generated for this account: \033[31m" << ID << "\033[0m" << " # This will serve as account login information(username)." << endl;
    cout << "Welcome to HaucaBank! Below you will have all your personal information including account Balance which starts at 0." << endl;
    cout << "Full Name: " << nume << " " << prenume << " || CNP:  " << CI << " || Balance: " << balanta << endl;
    cout << "Iban for this account is: \033[31m" << iban << "\033[0m" << "" << endl;
}

void AccountCreation::afisareNP() const
{
    cout << "The name you have written is: " << nume << " " << prenume << endl;
}

string AccountCreation::toString() const
{
    stringstream ss;
    ss<< nume << "," << prenume << "," << CI << "," << balanta << "," << ID << "," << iban << "," << pwd;
    return ss.str();
}