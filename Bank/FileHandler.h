#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <fstream>
#include <vector>
#include "AccountCreation.h"
using namespace std;

class FileHandler
{
private:
	string name;
	fstream file;
	string acc;
public:
	enum FieldType { CI, IBAN, ID };

	FileHandler(const string & name);
	void saveAcc(const string& acc);
	void saveChanges(const AccountCreation& updateAcc);
	vector<AccountCreation> readAcc();
	AccountCreation authenticate(const string& id, const string& pass);
	bool isUnique(const string& value, FieldType fieldType) const;
	~FileHandler();
};

#endif