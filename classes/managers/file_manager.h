//------------------------------------------------------------------------------
#pragma once

#include <string>
#include <fstream>
#include "../abstract/data_source_interface.h"
#include "../helpers/custom_methods.h"
#include "../helpers/files_helper.h"
#include "../helpers/parser.h"
#include "../dependencies/load.h"

class FileManager : DataSourceInterface {
public:
  //Attributes
  static std::string clientFile;
  static std::string employeeFile;
  static std::string adminFile;
  // Write
  void addClient(Client &cli) override {
    std::ofstream clientInfo(clientFile, std::ios::app); // short for append
    int loc = clientInfo.tellp();
    if (clientInfo.fail()) {
      throw ("Error opening file\n");
    }
    std::string line; // id|name|password|balance
    line = std::to_string(cli.getID()) + '|' + cli.getName() + '|' + cli.getPassword() + '|' + CustomMethods::correctView(cli.getBalance());
    clientInfo << line << std::endl;
    Load::addIndex<Client>(cli.getID(), loc);
    clientInfo.close();
  }

  void addEmployee(Employee &emp) override {
    std::ofstream employeeInfo(employeeFile, std::ios::app);
    if (employeeInfo.fail()) {
      throw ("Error opening file\n");
    }
    int loc = employeeInfo.tellp();
    std::string line;
    line = std::to_string(emp.getID()) + '|' + emp.getName() + '|' + emp.getPassword() + '|' + CustomMethods::correctView(emp.getSalary());
    employeeInfo << line << std::endl;
    Load::addIndex<Employee>(emp.getID(), loc);
    employeeInfo.close();
  }

  void addAdmin(Admin &adm) override {
    std::ofstream adminInfo(adminFile, std::ios::app);
    if (adminInfo.fail()) {
      throw ("Error opening file\n");
    }
    int loc = adminInfo.tellp();
    std::string line;
    line = std::to_string(adm.getID()) + '|' + adm.getName() + '|' + adm.getPassword() + '|' + CustomMethods::correctView(adm.getSalary());
    adminInfo << line << std::endl;
    Load::addIndex<Admin>(adm.getID(), loc);
    adminInfo.close();
  }

  // Read
  std::vector<Client> getAllClients() override {
    std::vector<Client> clients;
    std::ifstream fin(clientFile);
    if (fin.fail()) {
      throw ("Error opening file\n");
    } // Guard Clauses
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
      throw("Error, file is empty.\n");
    }
    fin.seekg(0, std::ios::beg); // short for beginning  
    while (fin.peek() != EOF) { // End of file
      std::string line;
      getline(fin, line);
      std::vector<std::string> record = CustomMethods::split(line, '|');
      clients.push_back(*Parser::parseToObsolete<Client>(record[0]));
    }
    fin.close();
    Client::initID();
    return clients;
  }

  std::vector<Employee> getAllEmployees() override {
    std::vector<Employee> employees;
    std::ifstream fin(employeeFile);
    if (!fin) {
      throw ("Error opening file\n");
    }
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
      throw("Error, file is empty.\n");
    }
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');

      // Employee emp(arr[1], arr[2], stod(arr[3]));
      // emp.setID(stoi(arr[0]));
      // employees.push_back(emp);

      employees.push_back(*Parser::parseToObsolete<Employee>(arr[0]));
    }
    fin.close();
    Employee::initID();
    return employees;
  }

  std::vector<Admin> getAllAdmins() override {
    std::ifstream fin(adminFile);
    if (fin.fail()) {
      throw ("Error opening file.\n");
    }
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
      throw("Error, file is empty.\n");
    }
    std::vector<Admin> admins;
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');

      // Admin adm(arr[1], arr[2], stod(arr[3]));
      // adm.setID(stoi(arr[0]));
      // admins.push_back(adm);

      admins.push_back(*Parser::parseToObsolete<Admin>(arr[0]));
    }
    fin.close();
    Admin::initID();
    return admins;
  }

  // Delete
  void removeAllClients() override {
    std::ofstream ofs(clientFile, std::ios::trunc); // truncate
    ofs.close();
  }

  void removeAllEmployees() override {
    std::ofstream ofs(employeeFile, std::ios::trunc);
    ofs.close();
  }

  void removeAllAdmins() override {
    std::ofstream ofs(adminFile, std::ios::trunc);
    ofs.close();
  }
};
//------------------------------------------------------------------------------
std::string FileManager::clientFile = "db/Clients.txt";
std::string FileManager::employeeFile = "db/Employee.txt";
std::string FileManager::adminFile = "db/Admin.txt";
//------------------------------------------------------------------------------
void Employee::editClient(int id, std::string name, std::string password, double balance) {
  std::ofstream ofs;
  FileManager fm;
  std::vector<Client> vec = fm.getAllClients();
  bool found = false;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].getID() == id) {
      vec[i].setName(name);
      vec[i].setPassword(password);
      vec[i].setBalance(balance);
      found = true;
      break;
    }
  }
  if (!found) {
    std::cout << "Client not found, please enter correct id\n";
    return;
  }
  ofs.open("db/Clients.txt");
  if (!ofs) {
    throw("Error opening the file\n");
  }
  for (int i = 0; i < vec.size(); i++) {
    ofs << std::to_string(vec[i].getID()) << '|' << vec[i].getName() << '|'
      << vec[i].getPassword() << '|' << CustomMethods::correctView(vec[i].getBalance()) << std::endl;
  }
  ofs.close();
}
//------------------------------------------------------------------------------
void Admin::editEmployee(int id, std::string name, std::string password, double salary) {
  std::ofstream ofs;
  FileManager fm;
  std::vector<Employee> vec = fm.getAllEmployees();
  bool found = false;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].getID() == id) {
      vec[i].setName(name);
      vec[i].setPassword(password);
      vec[i].setSalary(salary);
      found = true;
      break;
    }
  }
  if (!found) {
    std::cout << "Client not found, please enter correct id\n";
    return;
  }
  ofs.open("db/Employee.txt");
  if (!ofs) {
    throw("Error opening the file\n");
  }
  for (int i = 0; i < vec.size(); i++) {
    ofs << std::to_string(vec[i].getID()) << '|' << vec[i].getName() << '|'
      << vec[i].getPassword() << '|' << CustomMethods::correctView(vec[i].getSalary()) << std::endl;
  }
  ofs.close();
}
//------------------------------------------------------------------------------
void FilesHelper::clearFile(std::string fileName) {
  FileManager fm;
  if (fileName == "db/Clients.txt") fm.removeAllClients();
  else if (fileName == "db/Employee.txt") fm.removeAllEmployees();
  else if (fileName == "db/Admin.txt") fm.removeAllAdmins();
  else std::cout << "File doesn't exist.\n";
}
//------------------------------------------------------------------------------
// // bug change the use of objects to pointers to not access classes destructors and modify id to wrong values
void FilesHelper::showClients() {
  FileManager fm;
  static std::vector<Client> clis = fm.getAllClients();
  for (int i = 0; i < clis.size(); ++i) {
    std::cout << "***** Client[" << i + 1 << "] info *****\n";
    clis[i].display();
  }
}
//------------------------------------------------------------------------------
void FilesHelper::showEmployees() {
  FileManager fm;
  std::vector<Employee> emps = fm.getAllEmployees();
  for (int i = 0; i < emps.size(); ++i) {
    std::cout << "***** Employee[" << i + 1 << "] info *****\n";
    emps[i].display();
  }
}
//------------------------------------------------------------------------------
void FilesHelper::showAdmins() {
  FileManager fm;
  std::vector<Admin> adms = fm.getAllAdmins();
  for (int i = 0; i < adms.size(); ++i) {
    std::cout << "***** Admin[" << i + 1 << "] info *****\n";
    adms[i].display();
  }
}
//------------------------------------------------------------------------------
void Employee::addClient(Client &client) {
  FileManager fm;
  fm.addClient(client);
}
//------------------------------------------------------------------------------
void Employee::listClient() {
  // FilesHelper::showClients();
  Load::showEvery<Employee>();
}
//------------------------------------------------------------------------------
Client *Employee::searchClient(int id) {
  // Client *c = Parser::parseTo<Client>(std::to_string(id));
  Client *c = Load::search<Client>(id);
  return c;
}
//------------------------------------------------------------------------------
void Admin::addEmployee(Employee &employee) {
  FileManager fm;
  fm.addEmployee(employee);
}
//------------------------------------------------------------------------------
void Admin::listEmployee() {
  // FilesHelper::showEmployees();
  Load::showEvery<Employee>();
}
//------------------------------------------------------------------------------
Employee *Admin::searchEmployee(const int &id) {
  // Employee *e = Parser::parseTo<Employee>(std::to_string(id));
  Employee *e = Load::search<Employee>(id);
  return e;
}
//------------------------------------------------------------------------------
Client *Admin::searchClient(const int &id) {
  // Client *e = Parser::parseTo<Client>(std::to_string(id));
  Client *c = Load::search<Client>(id);
  return c;
}
//------------------------------------------------------------------------------