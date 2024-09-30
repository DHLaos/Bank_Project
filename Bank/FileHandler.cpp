#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include<algorithm>
#include "FileHandler.h"
#include "AccountCreation.h"
using namespace std;

FileHandler::FileHandler(const string& name)
{
    this->name = name;
    file.open(name, ios::in | ios::out | ios::app);
    if (file.is_open())
    {
        cout << "File is open." << endl;
    }
    else
    {
        cout << "Error while opening the file" << endl;
    }
}

void FileHandler::saveAcc(const string& acc)
{
    ofstream outfile(name, ios::app);
    if (file.is_open())
    {
        file << "\n" << acc;
    }
    else
    {
        cout << "Unable to open file for writing" << endl;
    }
}

vector<AccountCreation> FileHandler::readAcc()
{
    vector<AccountCreation> accounts;

    // Open the file for reading
    ifstream infile(name);  // Use ifstream to ensure we're in read mode
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))  // Read each line from the file
        {
            stringstream ss2(line);
            string nume, prenume, ID, CI, IBAN, pwd;
            float balance;
            getline(ss2, nume, ',');
            getline(ss2, prenume, ',');
            getline(ss2, CI, ',');
            ss2 >> balance;
            ss2.ignore(1, ',');
            getline(ss2, ID, ',');
            getline(ss2, IBAN, ',');
            getline(ss2, pwd, ',');
            
            accounts.emplace_back(nume, prenume, CI, balance, ID, IBAN, pwd);// Store each line in the vector
        }
        infile.close();  // Close the file after reading
    }
    else
    {
        cout << "Error while opening the file for reading." << endl;
    }

    return accounts;  // Return the vector of accounts
}

AccountCreation FileHandler::authenticate(const string& id, const string& pass)
{
    vector<AccountCreation> accounts = readAcc();
    for (AccountCreation& acc : accounts)
    {
        if (acc.getID() == id && acc.getPWD() == pass)
        {
            return acc; //Return account
        }
    }
    return AccountCreation(); //Return null if nothing found.
}

bool FileHandler::isUnique(const string& value, FieldType fieldType) const
{
    ifstream infile(name);
    string line;
    while (getline(infile, line))
    {
        stringstream ss1(line);
        string nume, prenume, balanta, ID, CI, IBAN, pwd;
        getline(ss1, nume, ',');
        getline(ss1, prenume, ',');
        getline(ss1, CI, ',');
        getline(ss1, balanta, ',');
        getline(ss1, ID, ',');
        getline(ss1, IBAN, ',');
        getline(ss1, pwd, ',');

        switch (fieldType) 
        {
        case FileHandler::CI:
            if (CI == value)
            {
                return false; // Duplicate found
            }
            break;
        case FileHandler::IBAN:
            if (IBAN == value)
            {
                return false; // Duplicate found
            }
            break;
        case FileHandler::ID:
            if (ID == value)
            {
                return false; // Duplicate found
            }
            break;
        }
    }

    return true;  // No duplicates found
}

void FileHandler::saveChanges(const AccountCreation& updateAcc)
{
    vector<AccountCreation> accounts = readAcc();

    ofstream outfile(name, ios::trunc);
    if (outfile.is_open())
    {
        for (AccountCreation& acc : accounts)
        {
            if (acc.getID() == updateAcc.getID())
            {
                acc = updateAcc;
            }
            outfile << acc.getNume() << "," << acc.getPrenume() << "," << acc.getCI() << "," << acc.getBalance() << "," << acc.getID() << "," << acc.getIBAN() << "," << acc.getPWD() << "\n";
        }
        outfile.close();
    }
    else
    {
        cout << "Unable to open file for writing" << endl;
    }
}

FileHandler::~FileHandler()
{
    if (file.is_open())
    {
            file.close();
    }
}