#pragma once
#include <iostream>
#include "person.h"
#include "validation.h"
#include <fstream>
class Employee : public Person {
private:
  //Attributes
  double salary;
public:
  //Constructors
  Employee(int id, std::string name, std::string password, double salary) : Person(id, name, password) {
    Validation::checkSalary(salary); // min 5000
    this->salary = salary;
  }

  //Setters
  void setSalary(float salary) {
    Validation::checkSalary(salary);
    this->salary = salary;
  }

  //Getters
  double getSalary() const { return salary; }

  //Methods
  void display() override {
    std::cout << "Name: " << getName() << std::endl
      // << "password: " << getPassword() << std::endl
      << "ID: #" << getID() << std::endl
      << "Salary: $" << salary << std::endl;
  }

  void editClient(int id, std::string name, std::string password, double balance);
};