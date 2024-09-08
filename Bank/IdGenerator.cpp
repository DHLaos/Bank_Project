#include <iostream>
#include <string>
#include <random> // random number generation
#include <iomanip> // formatting output
#include "IdGenerator.h"
using namespace std;


IdGenerator::IdGenerator(const string& n, const string& p) : nume(n), prenume(p) { id = generateUniqueID(); iban = generateUniqueIban(); }

string IdGenerator::generateUniqueID()
{
    string id = "";
    if (!nume.empty())
    {
        id += toupper(nume[0]); // Adaug prima litera din nume la ID
    }
    if (!prenume.empty())
    {
        id += toupper(prenume[0]); // Adaug prima litera din prenume la ID
    }

    random_device rd; // random_device e o clasa din librarie pentru generare numere random din HW/SW.
    mt19937 random(rd()); // Sursa pentru generator
    uniform_int_distribution<> distr(0, 99999999); // Range-ul de numere generate (In cazul de fata 8).

    int rd_nr = distr(random); // int pentru numarul random
    id += to_string(rd_nr); // cast in string la acel nr pentru a fi adaugat in ID.

    return id;
}

string IdGenerator::generateUniqueIban()
{
    string iban = "RO52HAUB00009999";
    random_device ibd;
    mt19937 randomib(ibd());
    uniform_int_distribution<> distr(0, 99999999);

    int ibd_nr = distr(randomib);
    iban += to_string(ibd_nr);

    return iban;
}