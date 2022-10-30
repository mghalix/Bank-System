#pragma once
#include "../helpers/custom_methods.h"
#include "../entities/client.h"
#include "../entities/admin.h"
#include "../entities/employee.h"
#include <typeinfo>
#include <fstream>

class Parser {
public:
  template<typename T>
  static T *parseToObsolete(const std::string &id) {
    std::string fileName;
    if (typeid(T) == typeid(Client))
      fileName = FilesHelper::clientFile;
    else if (typeid(T) == typeid(Employee))
      fileName = FilesHelper::employeeFile;
    else if (typeid(T) == typeid(Admin))
      fileName = FilesHelper::adminFile;
    else throw("No such file to open.\n");
    std::ifstream ifs(fileName, std::ios::in);
    std::string record;
    while (ifs.peek() != EOF) {
      getline(ifs, record);
      std::vector<std::string> vec = Helpers::split(record, '|');
      if (vec[0] != id)
        continue;
      T *a = new T(vec[1], vec[2], stod(vec[3]));
      a->setID(stoi(vec[0]));
      ifs.close();
      return a;
    }
    ifs.close();
    std::string className = Helpers::cName(typeid(T).name());
    // Employee id #2030 -> doesn't exist
    throw(className + " ID #" + id + " -> doesn't exist.\n");
  }
};