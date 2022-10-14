#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"

class AdminManager {
public:
  static Admin *login(int id, std::string password) {
    Login::login<Admin>(id, password);
  }
};