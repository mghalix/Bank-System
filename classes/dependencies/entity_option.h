//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../entities/admin.h"
#include "../dependencies/print_entity_menu.h"
class Options {
public:
  struct Adm {
    struct Search {
      static void printMenu() {
        Menus::printMenu('A', 'S');
      }
      static void options(char &choice, Admin &adm) {
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
            std::cout << "------\n> ";
            std::cin >> choice;
            options(choice, adm);
          }
          std::cout << "------\n> ";
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
        case 'q': case 'Q':
          Load::rewriteAll();
          exit(0);
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
      static void options(char &choice, Admin &adm) {
        switch (choice) {
        case '1':
          try {
            adm.listEmployee();
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
        case '2':
          std::cout << "------\n";
          try {
            adm.listClient();
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
        case 'q': case 'Q':
          Load::rewriteAll();
          exit(0);
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
    };

    struct Remove {
      static void printMenu() {
        Menus::printMenu('A', 'R');
      }
    };
  };

  struct Emp {
    struct Search {
      static void printMenu() {
        Menus::printMenu('E', 'S');
      }
      static void options(char &choice, Employee &emp) {
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
            std::cout << "------\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          std::cout << "------\n> ";
          std::cin >> choice;
          options(choice, emp);
          break;
        case 'q': case 'Q':
          Load::rewriteAll();
          exit(0);
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
      static void options(char &choice, Employee &emp) {
        switch (choice) {
        case '1':
          try {
            emp.listClient();
          }
          catch (std::string msg) {
            std::cerr << msg;
            std::cout << "------\n> ";
            std::cin >> choice;
            options(choice, emp);
          }
          std::cout << "------\n> ";
          std::cin >> choice;
          options(choice, emp);
          break;
        case 'q': case 'Q':
          Load::rewriteAll();
          exit(0);
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
    };
  };


  struct Client {
    struct Balance {
      static void printMenu() {

      }
    };

    struct Deposit {
      static void printMenu() {

      }
    };

    struct Withdraw {
      static void printMenu() {

      }
    };

    struct Transfer {
      static void printMenu() {

      }
    };
  };

private:
  static void optEntity(int &id, std::string entity) {
    std::cout << "Search for an " << entity << " by id : #";
    std::cin >> id;
  }
};
//------------------------------------------------------------------------------