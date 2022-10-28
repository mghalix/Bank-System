#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"

class AdminManager {
public:
  static Admin *login(int id, std::string password) {
    return Login::login<Admin>(id, password);
  }
  static void printAdminMenu() {
    std::cout << "\t\t***** Welcome Admin *****\nWhat do you want to do today?\n1. Search (employee/client/admin)\n2. List all (employees/clients/admins)\n3. edit(employee/client/admin)\n4. Add (employee/client/admin)\n5. Remove (employee/client/admin)\n0. Back\n> ";
  }
};