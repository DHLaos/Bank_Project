#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
using namespace std;

class Login
{
private:
	string id, pass;
public:
	Login();
	void scriereDate();
	int actiuni();
};

#endif