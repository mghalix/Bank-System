#pragma once
#include "data_source_interface.h"
#include <fstream>
#include <string>
class FileManager : Data {
public:
  // Metwally's Task
  void addClient(Client cli) override {
    fstream ClientInfo;
    ClientInfo.open("Clients.txt", ios::app);
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