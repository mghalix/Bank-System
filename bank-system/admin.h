#pragma once
#include <iostream>
#include "employee.h"
class Admin : public Employee {
public:
  // Constructor
  Admin(int id, std::string name, std::string password, double salary) : Employee(id, name, password, salary) {}

  // Methods
  void editEmployee(int id, std::string name, std::string password, double salary);
};