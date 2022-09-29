#pragma once
#include "validation.h"
#include "files_helper.h"
#include "custom_methods.h"
class Person {
private:
	//Attributes
	std::string name, password;
	virtual void display() = 0;
public:
	//Constructors
	Person() {
		name = "no_name";
		password = "no_password";
	}

	Person(std::string name, std::string password) {
		Validation::checkPassword(password);
		this->password = password;
		Validation::checkName(name);
		this->name = name;
	}

	//Getters
	virtual int getID() const = 0;

	std::string getName() const { return name; }

	std::string getPassword() const { return password; }

	//Setters
	virtual void setID(int id) = 0;

	void setName(std::string name) {
		Validation::checkName(name);
		this->name = name;
	}

	void setPassword(std::string password) {
		Validation::checkPassword(password);
		this->password = password;
	}

	// Methods
	/**
	 * @brief when we rerun the program we don't want the static id to be reset,
	 * so we correct its value based on the last id on the file.
	 * @param id
	 */
	 // virtual void initID(int id) = 0;
};