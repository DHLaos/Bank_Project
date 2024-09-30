#pragma once
#ifndef IDGENERATOR_H
#define IDGENERATOR_H

using namespace std;
#include <string>

class IdGenerator {
private:
    string nume;
    string prenume;
    string id; // ID unic per utilizator format (XY12345678) Unde X reprezinta prima litera din nume, Y prima litera din prenume, si un numar random din 8 cifre.
    string generateUniqueID(); // Generator de ID unic
    string iban;
    string generateUniqueIban();
public:
    IdGenerator(const string& n, const string& p);
    string getID() const { return id; }
    string getIban() const { return iban; }
};

#endif