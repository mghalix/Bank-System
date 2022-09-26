#pragma once
#include "data_source_interface.h"
#include <string>
#include <fstream>
class FileManager : DataSourceInterface {
public:
  // Metwally's Task
  void addClient(Client cli) override {
    std::ofstream clientInfo("Clients.txt", std::ios::app); // short for append
    std::string line; // id|name|password|balance
    line = std::to_string(cli.getID()) + '|' + cli.getName() + '|' + cli.getPassword() + '|' + std::to_string(cli.getBalance());
    clientInfo << line << std::endl;
    clientInfo.close();
  }

  void addEmployee(Employee emp) override {
    std::ofstream employeeInfo("Employee.txt", std::ios::app);
    std::string line;
    line = std::to_string(emp.getID()) + '|' + emp.getName() + '|' + emp.getPassword() + '|' + std::to_string(emp.getSalary());
    employeeInfo << line << std::endl;
    employeeInfo.close();
  }

  void addAdmin(Admin adm) override {
    std::ofstream adminInfo("Admin.txt", std::ios::app);
    std::string line;
    line = std::to_string(adm.getID()) + '|' + adm.getName() + '|' + adm.getPassword() + '|' + std::to_string(adm.getSalary());
    adminInfo << line << std::endl;
    adminInfo.close();
  }

  // Ghali's Task
  std::vector<Client> getAllClients() override {
    std::vector<Client> clients;
    std::ifstream fin("Clients.txt");
    fin.seekg(0, std::ios::beg); // beginning  
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      clients.push_back(Client(stoi(arr[0]), arr[1], arr[2], stof(arr[3])));
    }
    fin.close();
    return clients;
  }

  std::vector<Employee> getAllEmployees() override {
    std::vector<Employee> employees;
    std::ifstream fin("Employee.txt");
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      employees.push_back(Employee(stoi(arr[0]), arr[1], arr[2], stof(arr[3])));
    }
    fin.close();
    return employees;
  }

  std::vector<Admin> getAllAdmins() override {
    std::vector<Admin> admins;
    std::ifstream fin("Admin.txt");
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      admins.push_back(Admin(stoi(arr[0]), arr[1], arr[2], stof(arr[3])));
    }
    fin.close();
    return admins;
  }

  void removeAllClients() override {
    std::ofstream ofs("Clients.txt", std::ios::trunc); // truncate
    ofs.close();
  }

  void removeAllEmployees() override {
    std::ofstream ofs("Employee.txt", std::ios::trunc);
    ofs.close();
  }

  void removeAllAdmins() override {
    std::ofstream ofs("Admin.txt", std::ios::trunc);
    ofs.close();
  }
};