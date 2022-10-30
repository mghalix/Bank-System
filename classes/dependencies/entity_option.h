//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../entities/admin.h"
#include "../entities/client.h"
#include "../dependencies/print_entity_menu.h"
class Options {
public:
  struct Adm {
    struct Search {
      static void printMenu() {
        Menus::printMenu('A', 'S');
      }
      static void options(char& choice, Admin& adm) {
        int id;
        switch (choice) {
        case '1':
          optEntity(id, "Employee");
          std::cout << "------\n";
          try {
            adm.searchEmployee(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "------\nSelect another option\n> ";
          std::cin >> choice;
          options(choice, adm);
          break;
        case '2':
          optEntity(id, "Client");
          std::cout << "------\n";
          try {
            adm.searchClient(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "------\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "------\n> ";
          std::cin >> choice;
          options(choice, adm);
          break;
        case '0':
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, adm);
        }
      }
    };

    struct Edit {
      static void printMenu() {
        Menus::printMenu('A', 'E');
      }
    };

    struct List {
      static void printMenu() {
        Menus::printMenu('A', 'L');
      }
      static void options(char& choice, Admin& adm) {
        switch (choice) {
        case '1':
          try {
            adm.listEmployee();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "------\nSelect another option\n> ";
          std::cin >> choice;
          options(choice, adm);
          break;
        case '2':
          std::cout << "------\n";
          try {
            adm.listClient();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "------\nSelect another option\n> ";
          std::cin >> choice;
          options(choice, adm);
          break;
        case '0':
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, adm);
        }
      }
    };


    struct Add {
      static void printMenu() {
        Menus::printMenu('A', 'A');
      }
      static void options(char& choice, Admin& adm) {
        double salary;
        std::string name, password;
        FileManager fm;
        switch (choice) {
        case '1': // Employee
          system("clear");
          std::cout << "\t\t\t***** Please fill employee's info *****\n";
        x:
          std::cout << "Name: ";
          std::cin >> name;
          std::cout << "Salary: $";
          std::cin >> salary;
          std::cout << "Password: ";
          std::cin >> password;
          try {
            Employee emp(name, password, salary);
            std::cout << "Employee with name " << name << " and id #" << emp.getID() << " has been added succesfuly\n";
            adm.addEmployee(emp);
            std::cout << "Enter any key to continue\n";
            std::cin.ignore(200, '\n');
            std::cin.get();
            // thread second(1)
          }
          catch (const char* msg) {
            std::cerr << "-------------\n" << msg;
            std::cout << " please try again\n-------------\n";
            goto x;
          }
          // std::cout << "------\nSelect another option\n> ";
          throw(-1);
          // std::cin >> choice;
          // options(choice, adm);
          break;
        case '2': // Client
          break;
        case '3':
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, adm);
        }
      }
    };

    struct Remove {
      static void printMenu() {
        Menus::printMenu('A', 'R');
      }
      static void options(char& choice, Admin& adm) {
        std::cin.ignore(200, '\n');
        int id;
        char rev;
        switch (choice) {
        case '1': // Employee
          std::cout << "Enter the Employee id: #";
          std::cin >> id;
          try {
            adm.searchEmployee(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "Are you sure you want to remove? (Y/n)\n> ";
          std::cin >> rev;
          if (toupper(rev) == 'Y') {
            // FileManager::deleteAnEmployee(id);
            std::cout << "Removed successfully!\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          else if (tolower(rev) == 'n') {
            std::cout << "Select another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          break;
        case '2': // Client
          std::cout << "Enter the Client id: #";
          std::cin >> id;
          try {
            adm.searchClient(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "Are you sure you want to remove? (Y/n)\n> ";
          std::cin >> rev;
          if (toupper(rev) == 'Y') {
            //FileManager::deleteAClient(id);
            std::cout << "Removed successfully!\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          else if (tolower(rev) == 'n') {
            std::cout << "Select another option\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          break;
        case '0': // Back
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, adm);
        }
      }
    };
  };

  struct Emp {
    struct Search {
      static void printMenu() {
        Menus::printMenu('E', 'S');
      }
      static void options(char& choice, Employee& emp) {
        int id;
        switch (choice) {
        case '1':
          optEntity(id, "Client");
          std::cout << "------\n";
          try {
            emp.searchClient(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          std::cout << "------\nSelect another option\n> ";
          std::cin >> choice;
          options(choice, emp);
          break;
        case '0':
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, emp);
        }
      }

    };
    struct List {
      static void printMenu() {
        Menus::printMenu('E', 'L');
      }
      static void options(char& choice, Employee& emp) {
        switch (choice) {
        case '1':
          try {
            emp.listClient();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          std::cout << "------\nSelect another option\n> ";
          std::cin >> choice;
          options(choice, emp);
          break;
        case '0':
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, emp);
        }
      }
    };

    struct Edit {
      static void printMenu() {
        Menus::printMenu('E', 'E');
      }
    };


    struct Add {
      static void printMenu() {
        Menus::printMenu('E', 'A');
      }
    };

    struct Remove {
      static void printMenu() {
        Menus::printMenu('E', 'R');
      }
      static void options(char& choice, Employee& emp) {
        std::cin.ignore(200, '\n');
        int id;
        char rev;
        switch (choice) {
        case '1': // Client
          std::cout << "Enter the Client id: #";
          std::cin >> id;
          try {
            emp.searchClient(id)->display();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          std::cout << "Are you sure you want to remove? (Y/n)\n> ";
          std::cin >> rev;
          if (toupper(rev) == 'Y') {
            FileManager::deleteAClient(id);
            std::cout << "Removed successfully!\nSelect another option\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          else if (tolower(rev) == 'n') {
            std::cout << "Select another option\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          break;
        case '0': // Back
          throw(-1);
        default:
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, emp);
        }
      }
    };
  };
  struct Cli {
    struct Balance {
      static void printMenu() {
        Menus::printMenu('C', 'B');
      }
      static void options(char& choice, Client& cli) {
        if (choice == '0')
          throw(-1);
        else {
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, cli);
        }
      };
    };
    struct Deposit {
      static void printMenu() {
        Menus::printMenu('C', 'D');
      }
      static void options(char& choice, Client& cli) {
        if (choice == '0')
          throw(-1);
        else {
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, cli);
        }
      }
    };

    struct Withdraw {
      static void printMenu() {
        Menus::printMenu('C', 'W');
      }
      static void options(char& choice, Client& cli) {
        if (choice == '0')
          throw(-1);
        else {
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, cli);
        }
      }
    };

    struct Transfer {
      static void printMenu() {
        Menus::printMenu('C', 'T');
      }
      static void options(char& choice, Client& cli) {
        if (choice == '0')
          throw(-1);
        else {
          std::cout << "No such option, please try again\n> ";
          std::cin >> choice;
          options(choice, cli);
        }
      }
    };
  };

private:
  static void optEntity(int& id, std::string entity) {
    std::cout << "Search for an " << entity << " by id : #";
    std::cin >> id;
  }
};
//------------------------------------------------------------------------------