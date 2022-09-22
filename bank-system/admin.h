#pragma once
#include <iostream>
#include "person.h"
#include "validation.h"
using namespace std;
class admin : 
{
public:

	admin(int id, string name, string password, float balance)
	{

	}

	void display() override
	{
		cout << "admin name    : " << Person::getName() << endl;
		cout << "admin id      : " << Person::getID() << endl;
		cout << "admin balance : " << Person::
	}

};
