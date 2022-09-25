#pragma once
#include "data_source_interface.h"
#include <fstream>
#include <string>
class FileManager : DataSourceInterface {
public:
  // Metwally's Task
  void addClient(Client cli) override {
    ofstream clientInfo;
    clientInfo.open("Clients.txt", ios::app); // short for append
    string line; // id|name|password|balance
    line = to_string(cli.getID()) + '|' + cli.getName() + '|' + cli.getPassword() + '|' + to_string(cli.getBalance());
    clientInfo << line << endl;
    clientInfo.close();
  }

  void addEmployee(Employee emp) override {
    ofstream employeeInfo;
    employeeInfo.open("Employee.txt", ios::app);
    string line;
    line = to_string(emp.getID()) + '|' + emp.getName() + '|' + emp.getPassword() + '|' + to_string(emp.getSalary());
    employeeInfo << line << endl;
    employeeInfo.close();
  }

  void addAdmin(Admin adm) override {
    ofstream adminInfo;
    adminInfo.open("Admin.txt", ios::app);
    string line;
    line = to_string(adm.getID()) + '|' + adm.getName() + '|' + adm.getPassword() + '|' + to_string(adm.getSalary());
    adminInfo << line << endl;
    adminInfo.close();
  }

  // Ghali's Task
  vector<Client> getAllClients() override {
    vector<Client> clients;
    ifstream fin("Clients.txt");
    fin.seekg(0, ios::beg);
    while (fin.peek() != EOF) {
      string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      clients.push_back(Client(stoi(arr[0]), arr[1], arr[2], stod(arr[3])));
    }
    fin.close();
    return clients;
  }

  vector<Employee> getAllEmployees() override {
    vector<Employee> employees;
    ifstream fin("Employee.txt");
    fin.seekg(0, ios::beg);
    while (fin.peek() != EOF) {
      string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      employees.push_back(Employee(stoi(arr[0]), arr[1], arr[2], stof(arr[3])));
    }
    fin.close();
    return employees;
  }

  vector<Admin> getAllAdmins() override {
    vector<Admin> admins;
    ifstream fin("Admin.txt");
    fin.seekg(0, ios::beg);
    while (fin.peek() != EOF) {
      string arr[4];
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
    ofstream ofs("Clients.txt", ios::trunc);
    ofs.close();
  }

  void removeAllEmployees() override {
    ofstream ofs("Employee.txt", ios::trunc);
    ofs.close();
  }

  void removeAllAdmins() override {
    ofstream ofs("Admin.txt", ios::trunc);
    ofs.close();
  }
};