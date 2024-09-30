#pragma once
#ifndef NUMPREN_H
#define NUMPREN_H

using namespace std;
#include <string>

class NumPren{
private:
    string nume;   
    string prenume;
    string CI;
public:
    NumPren();
    void scriereNP();
    void scriereCI();
    void confirmare();
};

#endif