#pragma once
#include <iostream>




using namespace std;
class Validation
{
public:
	static void checkName(string name) {
		if (name.length() < 5 )
			throw("name too short!");
		if  (name.length() > 20)
			throw("name is too long!");
	}
	static void checkPassword(string password) {
		if (password.length() < 5)
			throw("password too short!");
		if (password.length() > 20)
			throw("password is too long!");
	}


};

