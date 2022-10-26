//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../managers/file_manager.h"
#include "load.h"
class Login {
public:
  template<typename T>
  static T *login(const int &id, const std::string &password) {
    static T *entity;
    if (typeid(T) == typeid(Client))
      entity = loginEntity<T>(id, password, "db/Clients.txt", Load::cliIdx);
    else if (typeid(T) == typeid(Employee))
      entity = loginEntity<T>(id, password, "db/Employee.txt", Load::empIdx);
    else entity = loginEntity<T>(id, password, "db/Admin.txt", Load::admIdx);
    // // TODO: make parseTo method use template
    // static T entity = Parser::parseTo<T>(std::to_string(id));
    return entity;
  }
private:
  template<typename T>
  static T *loginEntity(const int &id, const std::string &password, const std::string &fileName, std::map<int, int> &idx) {
    std::ifstream fin;
    fin.open(fileName);
    if (!fin) {
      fin.close();
      throw("No such file!\n");
    }
    std::string line;
    fin.seekg(idx[id]);
    getline(fin, line);
    std::vector<std::string> record = CustomMethods::split(line, '|');
    fin.close();
    if (record[2] != password) {
      throw("User doesn't exist, please try again.\n");
    }
    std::cout << "Login Successfully\n";
    return Parser::parseTo<T>(record[0]);
  }
};
//------------------------------------------------------------------------------