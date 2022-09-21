#pragma once
#include "Validation.h"
using namespace std;
class Person
{
public:
	int id;
	string name, password;
	virtual void display() = 0;
public:
	//constructor
	Person() {
		id = 123;
		name = "no_name";
		password = "no_password";
	}
	Person(int id, string name, string password) {
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
		Validation::checkPassword(password);
		this->password = password;
	}
};


