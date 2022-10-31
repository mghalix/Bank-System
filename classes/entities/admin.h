#pragma once
#include "../entities/employee.h"
class Admin : public Employee {
private:
  static int id;
  int admID;
public:
  // Constructor
  Admin() : Employee() {}
  Admin(std::string name, std::string password, double salary) : Employee(name, password, salary), admID(++id) {}
  ~Admin() { id--; }
  // Methods
  void editEmployee(int id, std::string name, std::string password, double salary);

  //Getters
  int getID() const override { return admID; }

  // Setters
  void setID(int id) override { admID = id; }

  static void initID() { id = FilesHelper::getLastID(FilesHelper::adminFile); }

  void addEmployee(Employee &employee);
  void listEmployee();
  Employee *searchEmployee(const int &id);
  static Client *searchClient(const int &id);
};
int Admin::id = 0;