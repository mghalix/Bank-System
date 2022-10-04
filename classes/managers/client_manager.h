#pragma once
#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"
class ClientManager {
public:
  static Client *login(int id, std::string password) {
    Login::login<Client>(id, password);
  }
};