#pragma once
#include "data_source_interface.h"
#include <fstream>
#include <string>
class FileManager : Data {
  // Metwally's Task
  void addClient(Client cli) override {
      fstream ClientInfo;
      ClientInfo.open("Client.txt", ios::app);
      string line;
      line = to_string(cli.getID()) + '|' + cli.getName() + '|' + cli.getPassword() + '|' + to_string(cli.getBalance());
      ClientInfo << line << endl;
      ClientInfo.close();
  }
  void addEmployee(Employee emp) override {
      fstream ClientInfo;
      ClientInfo.open("Employee.txt", ios::app);
      string line;
      line = to_string(emp.getID()) + '|' + emp.getName() + '|' + emp.getPassword() + '|' + to_string(emp.getSalary());
      ClientInfo << line << endl;
      ClientInfo.close();
  }

  void addAdmin(Admin adm) override {
      fstream ClientInfo;
      ClientInfo.open("Admin.txt", ios::app);
      string line;
      line = to_string(adm.getID()) + '|' + adm.getName() + '|' + adm.getPassword() + '|' + to_string(adm.getSalary());
      ClientInfo << line << endl;
      ClientInfo.close();
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