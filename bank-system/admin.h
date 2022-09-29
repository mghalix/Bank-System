#pragma once
#include <iostream>
#include "employee.h"
class Admin : public Employee {
public:
  // Constructor
  Admin(int id, std::string name, std::string password, double salary) : Employee(id, name, password, salary) {}

  void addEmployee(Employee &employee) {

  }
  Employee *searshEmployee(int id) {

  }										   
  void listEmployee() {

  }
  void display() {
	  cout << " kosom albdaaaan !!!!!!!!!!!!!!";
  }
  // Methods
  void editEmployee(int id, std::string name, std::string password, double salary);
};