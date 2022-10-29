#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/login.h"

class EmployeeManager {
public:
  static Employee *login(int id, std::string password) {
    return Login::login<Employee>(id, password);
  }
};