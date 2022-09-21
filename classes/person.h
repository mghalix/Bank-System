#pragma once
#include "validation.h"
class Person {
private:
	//Attributes
	int id;
	std::string name, password;
	virtual void display() = 0;

public:
	//Constructors
	Person() {
		id = 123;
		name = "no_name";
		password = "no_password";
	}

	Person(int id, std::string name, std::string password) {
		this->id = id;
		Validation::checkPassword(password);
		this->password = password;
		Validation::checkName(name);
		this->name = name;
	}

	//Getters
	int getID() const { return id; }

	std::string getName() const { return name; }

	std::string getPassword() const { return password; }

	//Setters
	void setID(int id) { this->id = id; }

	void setName(std::string name) {
		Validation::checkName(name);
		this->name = name;
	}

	void setPassword(std::string password) {
		Validation::checkPassword(password);
		this->password = password;
	}

};