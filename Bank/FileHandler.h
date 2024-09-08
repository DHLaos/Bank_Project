#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <fstream>
#include <vector>
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
	vector<string> readAcc();
	bool isUnique(const string& value, FieldType fieldType) const;
	~FileHandler();
};

#endif