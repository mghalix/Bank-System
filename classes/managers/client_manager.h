#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/login.h"

class ClientManager {
public:
  static Client *login(int id, std::string password) {
    return Login::login<Client>(id, password);
  }

};