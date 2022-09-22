#pragma once
#include <iostream>
#include "validation.h"
#include "employee.h"
using namespace std;
class Admin : public Employee {
public:

    Admin(int id, string name, string password, float balance) : Employee(id, name, password, balance) {}
};