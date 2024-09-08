#pragma once
#ifndef ACCOUNTCREATION_H
#define ACCOUNTCREATION_H
using namespace std;
#include <string>

class AccountCreation
{
private:
    string nume;
    string prenume;
    string CI;
    float balanta;
    string ID;
    string iban;
    string pwd;
public:
    AccountCreation(const string& n,const string& p, const string& CI, float s, const string& id, const string& iban, const string& pwd);

    AccountCreation operator+=(float suma);
    AccountCreation operator-=(float suma);
    void afisareINT() const; // interogarea tuturor elementelor pentru testare.
    void afisareNP() const; //doar nume si prenume
    string toString() const;

    string getCI() const { return CI; }
    string getID() const { return ID; }
    string getIBAN() const { return iban; }
};

#endif