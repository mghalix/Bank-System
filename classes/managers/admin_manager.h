#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/login.h"

class AdminManager {
public:
  static Admin *login(int id, std::string password) {
    return Login::login<Admin>(id, password);
  }
};