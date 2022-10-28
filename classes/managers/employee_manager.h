#pragma once

#include "../dependencies/entity_option.h"
#include "../dependencies/print_entity_menu.h"
#include "../dependencies/login.h"

class EmployeeManager {
public:
  static Employee *login(int id, std::string password) {
    return Login::login<Employee>(id, password);
  }
  static void printEmployeeMenu() {
    std::cout << "\t\t***** Welcome Employee *****\nWhat do you want to do today?\n1. Search (clients)\n2. List all (clients)\n3. edit (clients)\n4. Add (clients)\n5. Remove (clients)\n0. Back\n> ";
  }
};