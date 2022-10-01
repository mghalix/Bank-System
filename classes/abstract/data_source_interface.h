#pragma once
#include <vector>
#include "../entities/client.h"
#include "../entities/employee.h"
#include "../entities/admin.h"
class DataSourceInterface { // abstract
  // write methods
  virtual void addClient(Client &) = 0;
  virtual void addEmployee(Employee &) = 0;
  virtual void addAdmin(Admin &) = 0;

  // read
  virtual std::vector<Client> getAllClients() = 0;
  virtual std::vector<Employee> getAllEmployees() = 0;
  virtual std::vector<Admin> getAllAdmins() = 0;

  // delete
  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};