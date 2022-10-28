#pragma once
#include "../helpers/custom_methods.h"
#include "../entities/client.h"
#include "../entities/admin.h"
#include "../entities/employee.h"
#include <fstream>

class Parser {
private:
  static std::string clientFile;
  static std::string employeeFile;
  static std::string adminFile;
  static std::string correct(const char *name) {
    std::string output = "";
    for (int i = 0; i < name[i] != '\0'; i++) {
      if (name[i] >= '0' && name[i] <= '9')
        continue;
      output += name[i];
    }
    return output;
  }
public:
  template<typename T>
  static T *parseTo(const std::string &id) {
    std::string fileName;
    if (typeid(T) == typeid(Client))
      fileName = clientFile;
    else if (typeid(T) == typeid(Employee))
      fileName = employeeFile;
    else if (typeid(T) == typeid(Admin))
      fileName = adminFile;
    else throw("No such file to open.\n");
    std::ifstream ifs(fileName, std::ios::in);
    std::string record;
    while (ifs.peek() != EOF) {
      getline(ifs, record);
      std::vector<std::string> vec = CustomMethods::split(record, '|');
      if (vec[0] != id)
        continue;
      T *a = new T(vec[1], vec[2], stod(vec[3]));
      a->setID(stoi(vec[0]));
      ifs.close();
      return a;
    }
    ifs.close();
    std::string className = correct(typeid(T).name());
    // Employee id #2030 -> doesn't exist
    throw(className + " ID #" + id + " -> doesn't exist.\n");
  }
};
std::string Parser::clientFile = "db/Clients.txt";
std::string Parser::employeeFile = "db/Employee.txt";
std::string Parser::adminFile = "db/Admin.txt";