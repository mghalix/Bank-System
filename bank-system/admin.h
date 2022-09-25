#pragma once
#include <iostream>
#include "employee.h"
class Admin : public Employee {
public:
  Admin(int id, std::string name, std::string password, float salary) : Employee(id, name, password, salary) {}
};