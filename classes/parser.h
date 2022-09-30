#pragma once
#include "custom_methods.h"
#include "fstream"
#include "client.h"
#include "admin.h"
#include "custom_methods.h"
#include "employee.h"
#include <fstream>
// #include <string>
class Parser {
private:
  static std::string clientFile;
  static std::string employeeFile;
  static std::string adminFile;
public:
  static Client parseToClient(std::string id) {
    std::ifstream ifs(clientFile, std::ios::in);
    std::string record;
    while (ifs.peek() != EOF) {
      getline(ifs, record);
      std::vector<std::string> vec = CustomMethods::split(record, '|');
      if (vec[0] != id)
        continue;
      Client c(vec[1], vec[2], stod(vec[3]));
      c.setID(stoi(vec[0]));
      ifs.close();
      return c;
    }
    ifs.close();
    throw("Client ID doesn't Exist");
  }

  static Employee parseToEmployee(std::string line) {
    std::ifstream ifs(employeeFile, std::ios::in);
    std::string record;
    while (ifs.peek() != EOF) {
      getline(ifs, record);
      std::vector<std::string> vec = CustomMethods::split(record, '|');
      if (vec[0] != line)
        continue;
      Employee e(vec[1], vec[2], stod(vec[3]));
      e.setID(stoi(vec[0]));
      ifs.close();
      return e;
    }
    ifs.close();
    throw("Employee ID doesn't Exist");
  }

  static Admin parseToAdmin(std::string line) {
    std::ifstream ifs(adminFile, std::ios::in);
    std::string record;
    while (ifs.peek() != EOF) {
      getline(ifs, record);
      std::vector<std::string> vec = CustomMethods::split(record, '|');
      if (vec[0] != line)
        continue;
      Admin a(vec[1], vec[2], stod(vec[3]));
      a.setID(stoi(vec[0]));
      ifs.close();
      return a;
    }
    ifs.close();
    throw("Admin ID doesn't Exist");
  }
};
std::string Parser::clientFile = "db/Clients.txt";
std::string Parser::employeeFile = "db/Employee.txt";
std::string Parser::adminFile = "db/Admin.txt";
