#pragma once
#include <iostream>
#include "Validation.h"

using namespace std;

class Person
{
private:
	int id;
	string name;
	string password;

public:
	//constructor
	Person(int id , string name , string password) {
		
		this->id = id;
		Validation::checkPassword(password);
		this->password = password;
		Validation::checkName(name);
		this->name = name;
	}
	//getters
	int getId() { return id; }

	string getName() { return name; }
	string getPassword() { return password; }
	//setters
	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		Validation::checkName(name);
		this->name = name;
	}

	void setPassword(string password) {
		Validation::checkName(password);
		this->password = password;
	}

};


