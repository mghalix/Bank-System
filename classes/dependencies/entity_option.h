//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../entities/admin.h"
class Options {
public:
  struct Adm {
    struct Search {
      static void printMenu() {
        std::cout << "\t\t***** Search *****" << std::endl
          << "1. Employees" << std::endl
          << "2. Clients" << std::endl <<
          "0. Back\n> ";
      }
      static void options(int &choice, Admin &adm) {
        int id;
        switch (choice) {
        case 1:
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
        case 2:
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
        case 0:
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
        std::cout << "\t\t***** Edit *****" << std::endl
          << "1. Employees" << std::endl
          << "2. Clients" << std::endl <<
          "0. Back\n> ";

      }

    };

    struct List {
      static void printMenu() {
        std::cout << "\t\t***** List All *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
      }
      static void options(int &choice, Admin &adm) {
        switch (choice) {
        case 1:
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
        case 2:
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
        case 0:
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
        std::cout << "\t\t***** Add *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
      }
    };

    struct Remove {
      static void printMenu() {
        std::cout << "\t\t***** Remove *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
      }
    };
  };

  struct Emp {
    struct Search {
      static void printMenu() {
        std::cout << "\t\t***** Search *****" << std::endl
          << "1. Clients" << std::endl <<
          "0. Back\n> ";
      }
      static void options(int &choice, Employee &emp) {
        int id;
        switch (choice) {
        case 1:
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
        case 0:
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
        std::cout << "\t\t***** List All *****" << std::endl
          << "1. Clients" << std::endl <<
          "0. Back\n> ";
      }
      static void options(int &choice, Employee &emp) {
        switch (choice) {
        case 1:
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
        case 0:
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
        std::cout << "\t\t***** Edit *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
      }
    };


    struct Add {
      static void printMenu() {
        std::cout << "\t\t***** Add *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
      }
    };

    struct Remove {
      static void printMenu() {
        std::cout << "\t\t***** Remove *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
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