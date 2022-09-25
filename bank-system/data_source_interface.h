#pragma once
#include "client.h"
#include <vector>
#include "admin.h"
#include "employee.h"
class DataSourceInterface { // abstract
  virtual void addClient(Client) = 0;
  virtual void addEmployee(Employee) = 0;
  virtual void addAdmin(Admin) = 0;

  virtual vector<Client> getAllClients() = 0;
  virtual vector<Employee> getAllEmployees() = 0;
  virtual vector<Admin> getAllAdmins() = 0;

  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};