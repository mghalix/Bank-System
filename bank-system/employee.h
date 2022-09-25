#pragma once
#include <iostream>
#include "person.h"
#include "validation.h"
class Employee : public Person {
private:
  //Attributes
  float salary;
public:
  //Constructors 
  Employee() : Person() {
    salary = 0.0;
  }

  Employee(int id, std::string name, std::string password, float salary) : Person(id, name, password) {
    Validation::checkSalary(salary); // min 5000
    this->salary = salary;
  }

  //Setters
  void setSalary(float salary) {
    Validation::checkSalary(salary);
    this->salary = salary;
  }

  //Getters
  float getSalary() const { return salary; }

  //Methods
  void display() override {
    std::cout << "Name: " << getName() << std::endl
      //<< "password: " << getPassword() << std::endl
      << "ID: #" << getID() << std::endl
      << "Salary: $" << salary << std::endl;
  }
};