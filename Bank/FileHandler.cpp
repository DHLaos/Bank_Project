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

vector<string> FileHandler::readAcc()
{
    vector<string> accounts;

    // Open the file for reading
    ifstream infile(name);  // Use ifstream to ensure we're in read mode
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))  // Read each line from the file
        {
            accounts.push_back(line);  // Store each line in the vector
        }
        infile.close();  // Close the file after reading
    }
    else
    {
        cout << "Error while opening the file for reading." << endl;
    }

    return accounts;  // Return the vector of accounts
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

FileHandler::~FileHandler()
{
    if (file.is_open())
    {
            file.close();
    }
}