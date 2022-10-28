#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"

class ClientManager {
public:
  static Client *login(int id, std::string password) {
    return Login::login<Client>(id, password);
  }
  static void printClientMenu() {
    std::cout << "\t\t***** Welcome Client *****\nWhat do you want to do today?\n1. View Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n0. Back\n> ";
  }
};