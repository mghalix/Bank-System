//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../managers/file_manager.h"
#include "load.h"
class Login {
public:
  template<typename T>
  static T *login(const int &id, const std::string &password) {
    if (typeid(T) == typeid(Client))
      return loginEntity<T>(id, password, "db/Clients.txt", Load::cliIdx);
    else if (typeid(T) == typeid(Employee))
      return loginEntity<T>(id, password, "db/Employee.txt", Load::empIdx);
    else return loginEntity<T>(id, password, "db/Admin.txt", Load::admIdx);
    // // TODO: make parseTo method use template
    // static T entity = Parser::parseTo<T>(std::to_string(id));
    throw("No such us in the bank\n");
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
    if (record[2] != password || record[0] != std::to_string(id)) {
      throw("User doesn't exist, please try again.\n");
    }
    std::cout << "Login Successfully\n";
    T *entity = Parser::parseTo<T>(record[0]);
    return entity;
  }
};
//------------------------------------------------------------------------------