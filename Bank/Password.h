#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

using namespace std;
#include <string>

class Password {
private:
	string pwd;
	char ch;
public:
	Password();
	void createPWD();
	string getPWD() const { return pwd; }
};

#endif