#pragma once
#include "Validation.h"
using namespace std;
class Person {
private:
	//Attributes
	int id;
	string name, password;
	virtual void display() = 0;

public:
	//Constructors
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

	//Getters
	int getID() const { return id; }

	string getName() const { return name; }

	string getPassword() const { return password; }

	//Setters
	void setID(int id) { this->id = id; }

	void setName(string name) {
		Validation::checkName(name);
		this->name = name;
	}

	void setPassword(string password) {
		Validation::checkPassword(password);
		this->password = password;
	}

};