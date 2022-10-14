#pragma once

#include <iostream>
#include "../abstract/person.h"
#include "../managers/file_manager.h"
#include <fstream>

class Employee : public Person {
private:
  //Attributes
  double salary;
  static int id;
  int empID;
public:
  //Constructors
  Employee(std::string name, std::string password, double salary) : Person(name, password), empID(id += 10) {
    Validation::checkSalary(salary); // min 5000
    this->salary = salary;
  }
  ~Employee() { id -= 10; }

  //Setters
  void setSalary(float salary) {
    Validation::checkSalary(salary);
    this->salary = salary;
  }

  //Getters
  double getSalary() const { return salary; }

  int getID() const override { return empID; }

  //Setters
  void setID(int id) override { empID = id; }

  //Methods
  static void initID() { id = FilesHelper::getLast("db/Employee.txt"); } // for runApp task in phase 3

  void display() override {
    std::cout << "Name: " << getName() << std::endl
      // << "password: " << getPassword() << std::endl
      << "ID: #" << getID() << std::endl
      << "Salary: $" << CustomMethods::correctView(salary) << std::endl;
  }

  void addClient(Client &client);

  void  listClient();

  Client *searchClient(int id);

  void editClient(int id, std::string name, std::string password, double balance);
};
int Employee::id = 1990;