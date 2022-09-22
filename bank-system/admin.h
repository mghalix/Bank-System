#pragma once
#include <iostream>
#include "validation.h"
#include "employee.h"
using namespace std;
class Admin : Employee {
public:

    Admin(int id, string name, string password, float balance)
    {

    }

    void display() override
    {
        cout << "admin name    : " << Person::getName() << endl;
        cout << "admin id      : " << Person::getID() << endl;
        cout << "admin balance : " << Person::
    }

};