#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h> // _getch() function for password.
#include <sstream>
#include "NumPren.h"
#include "AccountCreation.h"
#include "IdGenerator.h"
#include "Password.h"
#include "FileHandler.h"

using namespace std;

// Constructor
NumPren::NumPren() : nume(""), prenume("") { CI[0] = '\0'; }

// Method to input nume and prenume
void NumPren::scriereNP() 
{
    cout << "Please write your First Name, Last Name and Personal Unique Number (CNP) from your Identity Card (CI)." << endl;
    cout << "First Name: ";
    getline(cin, nume);  // Read first name
    cout << "Last Name: ";
    getline(cin, prenume);  // Read last name
}

void NumPren::scriereCI()
{
    cout << "Please write your CNP: ";
    std::getline(std::cin, CI);
    while (CI.length() != 13 || !std::all_of(CI.begin(), CI.end(), ::isdigit)) 
    {
        std::cout << "Invalid CNP. Please enter a valid 13-digit CNP: ";
        std::getline(std::cin, CI);
    }
}

void NumPren::confirmare()
{
   string conf;
   cout << "The name you have written is: " << nume << " " << prenume << " || CI: " << CI << endl;
   cout << "Do you confirm the account creation? [yes/no]: ";
   getline(cin, conf);
   if (conf == "yes")
   {
       FileHandler f("accounts.txt");
       if (!f.isUnique(CI, FileHandler::CI)) 
       {
           std::cout << "Error: This CNP is already a client of this bank, if you've forgotten your credentials please contact Hauca Banking Officials." << std::endl;
       }
       else
       {
           Password p;
           p.createPWD();
           IdGenerator id(nume, prenume);
           if ((!f.isUnique(id.getID(), FileHandler::ID)) || (!f.isUnique(id.getIban(), FileHandler::IBAN)))
           {
               IdGenerator id(nume, prenume);
           }
           AccountCreation acc(nume, prenume, CI, 0, id.getID(), id.getIban(), p.getPWD());
           acc.afisareINT();
           cout << "#####################################################################" << endl;
           f.saveAcc(acc.toString());
           cout << endl;
           f.~FileHandler();
       }
   }
   else if (conf == "no")
   {
       cout << "Account creation canceled.";
       return scriereNP();
   }
   else
   {
        cout << "You did not enter a valid response, please type 'yes' or 'no' for the Account Creation procedure." << endl;
        return confirmare();
   }
}