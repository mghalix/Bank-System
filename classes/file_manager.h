//------------------------------------------------------------------------------
#pragma once
#include "data_source_interface.h"
#include <string>
#include <fstream>
#include "custom_methods.h"
#include "files_helper.h"
class FileManager : DataSourceInterface {
private:
  //Attributes
  const std::string clientFile = "db/Clients.txt";
  const std::string employeeFile = "db/Employee.txt";
  const std::string adminFile = "db/Admin.txt";
public:
  // Write
  void addClient(Client cli) override {
    std::ofstream clientInfo(clientFile, std::ios::app); // short for append
    if (clientInfo.fail()) {
      throw ("Error opening file\n");
    }
    std::string line; // id|name|password|balance
    line = std::to_string(cli.getID()) + '|' + cli.getName() + '|' + cli.getPassword() + '|' + CustomMethods::correctView(cli.getBalance());
    clientInfo << line << std::endl;
    clientInfo.close();
  }

  void addEmployee(Employee emp) override {
    std::ofstream employeeInfo(employeeFile, std::ios::app);
    if (employeeInfo.fail()) {
      throw ("Error opening file\n");
    }
    std::string line;
    line = std::to_string(emp.getID()) + '|' + emp.getName() + '|' + emp.getPassword() + '|' + CustomMethods::correctView(emp.getSalary());
    employeeInfo << line << std::endl;
    employeeInfo.close();
  }

  void addAdmin(Admin adm) override {
    std::ofstream adminInfo(adminFile, std::ios::app);
    if (adminInfo.fail()) {
      throw ("Error opening file\n");
    }
    std::string line;
    line = std::to_string(adm.getID()) + '|' + adm.getName() + '|' + adm.getPassword() + '|' + CustomMethods::correctView(adm.getSalary());
    adminInfo << line << std::endl;
    adminInfo.close();
  }

  // Read
  std::vector<Client> getAllClients() override {
    std::vector<Client> clients;
    std::ifstream fin(clientFile);
    if (fin.fail()) {
      throw ("Error opening file\n");
    } // Guard Clauses
    fin.seekg(0, std::ios::beg); // short for beginning  
    while (fin.peek() != EOF) { // End of file
      std::string arr[4];
      getline(fin, arr[0], '|');  // arr[0] = id
      getline(fin, arr[1], '|');  // arr[1] = name
      getline(fin, arr[2], '|');  // arr[2] = password 
      getline(fin, arr[3], '\n'); // arr[3] = balance
      Client cli(arr[1], arr[2], stod(arr[3]));
      cli.setID(stoi(arr[0]));
      clients.push_back(cli);
    }
    fin.close();
    return clients;
  }

  std::vector<Employee> getAllEmployees() override {
    std::vector<Employee> employees;
    std::ifstream fin(employeeFile);
    if (!fin) {
      throw ("Error opening file\n");
    }
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      Employee emp(arr[1], arr[2], stod(arr[3]));
      emp.setID(stoi(arr[0]));
      employees.push_back(emp);
    }
    fin.close();
    return employees;
  }

  std::vector<Admin> getAllAdmins() override {
    std::vector<Admin> admins;
    std::ifstream fin(adminFile);
    if (fin.fail()) {
      throw ("Error opening file\n");
    }
    fin.seekg(0, std::ios::beg);
    while (fin.peek() != EOF) {
      std::string arr[4];
      getline(fin, arr[0], '|');
      getline(fin, arr[1], '|');
      getline(fin, arr[2], '|');
      getline(fin, arr[3], '\n');
      Admin adm(arr[1], arr[2], stod(arr[3]));
      adm.setID(stoi(arr[0]));
      admins.push_back(adm);
    }
    fin.close();
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
//TODO change the use of objects to pointers to not access classes destructors and modify id to wrong values
void FilesHelper::showClients() {
  FileManager fm;
  std::vector<Client> clis = fm.getAllClients();
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