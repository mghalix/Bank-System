#pragma once
#include <limits>
#include <chrono>
#include <thread>
#include <typeinfo>
#include <windows.h>
#include <iostream>
#include "../classes/dependencies/login.h"
#include "../classes/dependencies/entity_option.h"
#include "../classes/managers/file_manager.h"
#include "../classes/managers/admin_manager.h"
#include "../classes/managers/client_manager.h"
#include "../classes/managers/employee_manager.h"
#include "../classes/dependencies/print_entity_menu.h"
class Screens {
private:
  static void mainMenu(char& choice); // complete
  static void loginAs(char& choice); // complete
  static void admMenu(char& choice); // complete (4/6)
  static void empMenu(char& choice); // complete (4/6)
  static void cliMenu(char& choice); // complete (6/6)
  static Admin adm;
  static Client cli;
  static Employee emp;
public:
  static void runApp();
};
//------------------------------------------------------------------------------
void Screens::mainMenu(char& choice) {
  system("clear");
  Menus::printMenu('S', 'M');
  bool notExecuted = true;
  while (notExecuted) {
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1':
      system("clear");
      loginAs(choice);
      break;
    case 'q': case 'Q':
      return;
    default:
      std::cout << "No such option, please try again.\n";
      std::cout << "1. Login as\n2. About us\nq. Quit\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
void Screens::runApp() {
  char choice;
  Load::loadAll();
  mainMenu(choice);
  // last step
  Load::rewriteAll();
}
//------------------------------------------------------------------------------
void Screens::loginAs(char& choice) {
  Menus::printMenu('S', 'L');
  int id;
  std::string password;
  // attemps > 5 -> too many attempts, please try again later
  bool notExecuted = true;
  int attempts{};
  do {
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1':
      while (attempts < 5) {
        std::cout << "Enter admin id: ";
        std::cin >> id;
        std::cout << "Enter admin password: ";
        std::cin >> password;
        try {
          adm = *Login::login<Admin>(id, password);
          // std::chrono::seconds dura(1);
          // std::this_thread::sleep_for(std::chrono::seconds(1));
          admMenu(choice);
          break;
        }
        catch (const char* msg) {
          std::cerr << msg << std::endl;
          attempts++;
        }
      }
      return;
    case '2':
      while (attempts < 5) {
        std::cout << "Enter employee id: ";
        std::cin >> id;
        std::cout << "Enter employee password: ";
        std::cin >> password;
        emp = *Login::login<Employee>(id, password);
        // std::chrono::seconds dura(1);
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        try {
          empMenu(choice);
          break;
        }
        catch (const char* msg) {
          std::cerr << msg << std::endl;
          attempts++;
        }
      }
      return;
    case '3':
      while (attempts < 5) {
        try {
          std::cout << "Enter client id: ";
          std::cin >> id;
          std::cout << "Enter client password: ";
          std::cin >> password;
          cli = *Login::login<Client>(id, password);
          // std::chrono::seconds dura(1);
          // std::this_thread::sleep_for(std::chrono::seconds(1));
          cliMenu(choice);
          break;
        }
        catch (const char* msg) {
          std::cerr << msg << std::endl;
          attempts++;
        }
      }
      return;
    case 'q': case 'Q':
      Load::rewriteAll();
      exit(0);
    case '0':
      mainMenu(choice);
      return;
    default:
      std::cout << "No such option, please try again.\n" <<
        "1. Admin\n" << "2. Employee\n" << "3. Client\n" << "0. Back\n"
        << "q. Quit\n> ";
      notExecuted = true;
    }
  } while (notExecuted);
  std::cout << "Too many attempts, please try again later\n";
}
//------------------------------------------------------------------------------
void Screens::admMenu(char& choice) {
  system("clear");
  Menus::printMenu('A', 'M');
  bool notExecuted = true;
  while (notExecuted) {
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1': // Search
      system("clear");
      Options::Adm::Search::printMenu();
      std::cin >> choice;
      try {
        Options::Adm::Search::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          admMenu(choice);
      }
      catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
      break;
    case '2': // List All
      system("clear");
      Options::Adm::List::printMenu();
      std::cin >> choice;
      try {
        Options::Adm::List::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          admMenu(choice);
      }
      catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
      break;
    case '3': // Edit
      break;
    case '4': // Add
      system("clear");
      Menus::printMenu('A', 'A');
      try {
        std::cin >> choice;
        Options::Adm::Add::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          admMenu(choice);
      }
      break;
    case '5': // Remove
      system("clear");
      Menus::printMenu('A', 'R');
      try {
        std::cin >> choice;
        Options::Adm::Remove::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          admMenu(choice);
      }
      break;
    case 'q': case 'Q': // Quit
      Load::rewriteAll();
      exit(0);
    case '0': // Back
      system("clear");
      loginAs(choice);
      break;
    default:
      std::cout << "No such option, please try again.\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
void Screens::empMenu(char& choice) {
  system("clear");
  Menus::printMenu('E', 'M');
  bool notExecuted = true;
  while (notExecuted) {
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1':
      system("clear");
      Options::Emp::Search::printMenu();
      std::cin >> choice;
      try {
        Options::Emp::Search::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          empMenu(choice);
      }
      catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    case '2':
      system("clear");
      Options::Emp::List::printMenu();
      std::cin >> choice;
      try {
        Options::Emp::List::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          admMenu(choice);
      }
      catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      system("clear");
      Menus::printMenu('E', 'R');
      try {
        std::cin >> choice;
        Options::Emp::Remove::options(choice, emp);
      }
      catch (int x) {
        if (x == -1)
          empMenu(choice);
      }
      break;
    case 'q': case 'Q':
      Load::rewriteAll();
      exit(0);
    case '0':
      system("clear");
      loginAs(choice);
      break;
    default:
      std::cout << "No such option, please try again.\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
void Screens::cliMenu(char& choice) {
  system("clear");
  Menus::printMenu('C', 'M');
  bool notExecuted = true;
  while (notExecuted) {
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1':
      system("clear");
      std::cout << "\t\t\t***** Balance *****\n";
      cli.checkBalance();
      Options::Cli::Balance::printMenu();
      try {
        std::cin >> choice;
        Options::Cli::Balance::options(choice, cli);
      }
      catch (int x) {
        if (x == -1) {
          cliMenu(choice);
        }
      }
      break;
    case '2':
      system("clear");
      Options::Cli::Deposit::printMenu();
      try {
        int amount;
        std::cin >> amount;
        cli.deposit(amount);
        std::cout << "Deposit Successful\n0. Back\n> ";
        std::cin >> choice;
        Options::Cli::Deposit::options(choice, cli);
      }
      catch (int x) {
        if (x == -1) {
          cliMenu(choice);
        }
      }
      break;
    case '3':
      system("clear");
      Options::Cli::Withdraw::printMenu();
      try {
        int amount;
        bool notExecuted = true;
        while (notExecuted) {
          try {
            notExecuted = false;
            std::cin >> amount;
            cli.withdraw(amount);
          }
          catch (const char* msg) {
            std::cerr << msg << std::endl;
            notExecuted = true;
          }
        }
        std::cout << "Withdraw Successful\n0. Back\n> ";
        std::cin >> choice;
        Options::Cli::Deposit::options(choice, cli);
      }
      catch (int x) {
        if (x == -1) {
          cliMenu(choice);
        }
      }
      break;
    case '4':
    x:
      system("clear");
      Options::Cli::Transfer::printMenu();
      try {
        double amount;
        int id;
        bool notExecuted = true;
        while (notExecuted) {
          try {
            notExecuted = false;
            std::cin >> amount;
            std::cout << "Enter the recipient id: #";
            std::cin >> id;
            // TODO: disallow transferring to self.
            cli.transferTo(amount, *Load::search<Client>(id));
          }
          catch (const char* msg) {
            char err;
            std::cerr << msg << std::endl;
            notExecuted = true;
            bool notExecuted2 = true;
            while (notExecuted2) {
              notExecuted2 = false;
              std::cout << "do you want to try again (Y/n)?";
              std::cin >> err;
              if (toupper(err) == 'Y') {
                goto x;
              }
              else if (tolower(err) == 'n')
                cliMenu(choice);
              else {
                std::cout << "No such option, please try again\n> ";
                std::cin >> err;
                notExecuted2 = true;
              }
            }

          }
          catch (std::string msg) {
            char err;
            std::cerr << msg << std::endl;
            notExecuted = true;
            bool notExecuted2 = true;
            while (notExecuted2) {
              notExecuted2 = false;
              std::cout << "do you want to try again (Y/n)?";
              std::cin >> err;
              if (toupper(err) == 'Y')
                goto x;
              else if (tolower(err) == 'n')
                cliMenu(choice);
              else {
                std::cout << "No such option, please try again\n> ";
                std::cin >> err;
                notExecuted2 = true;
              }
            }
          }
        }
        std::cout << "\n0. Back\n> ";
        std::cin >> choice;
        Options::Cli::Transfer::options(choice, cli);
      }
      catch (int x) {
        if (x == -1) {
          cliMenu(choice);
        }
      }
      break;
    case 'q': case 'Q':
      Load::rewriteAll();
      exit(0);
    case '0':
      system("clear");
      loginAs(choice);
      break;
    default:
      std::cout << "No such option, please try again.\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
Admin Screens::adm;
Employee Screens::emp;
Client Screens::cli;
//------------------------------------------------------------------------------