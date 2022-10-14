#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"

class EmployeeManager {
public:
  static Employee *login(int id, std::string password) {
    Login::login<Employee>(id, password);
  }
};