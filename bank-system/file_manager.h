#pragma once
#include "data_source_interface.h"
class FileManager : Data {
  // Metwally's Task
  void addClient(Client cli) override {

  }
  void addEmployee(Employee emp) override {

  }

  void addAdmin(Admin adm) override {

  }



  // Ghali's Task
  vector<Client> getAllClients() override {
    vector<Client> clients;






    return clients;
  }

  vector<Employee> getAllEmployees() override {
    vector<Employee> employees;






    return employees;
  }

  vector<Admin> getAllAdmins() override {
    vector<Admin> admins;






    return admins;
  }

  void removeAllClients() override {

  }

  void removeAllEmployees() override {

  }

  void removeAllAdmins() override {

  }
};