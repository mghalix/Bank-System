#pragma once
#include <limits>
#include <chrono>
#include <thread>
#include <typeinfo>
#include <string>
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
  static void admMenu(char& choice); // complete (6/6)
  static void empMenu(char& choice); // complete (6/6)
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
      std::cout << "1. Login as\nq. Quit\n> ";
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
  std::string id;
  std::string password;
  // attemps > 5 -> too many attempts, please try again later
  bool notExecuted = true;
  int attempts{};
  do {
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1': // Admin
      while (attempts < 5) {
        while (true) {
          std::cout << "Enter admin id: ";
          std::cin >> id;
          try {
            stoi(id);
            break;
          }
          catch (std::exception e) {
            std::cout << "ID must be numeric digits only, please try again\n";
            continue;
          }
        }
        std::cout << "Enter admin password: ";
        std::cin >> password;
        try {
          adm = *Login::login<Admin>(stoi(id), password);
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
      break;
    case '2': // Employee
      while (attempts < 5) {
        while (true) {
          std::cout << "Enter employee id: ";
          std::cin >> id;
          try {
            stoi(id);
            break;
          }
          catch (std::exception e) {
            std::cout << "ID must be numeric digits only, please try again\n";
            continue;
          }
        }
        std::cout << "Enter employee password: ";
        std::cin >> password;
        // std::chrono::seconds dura(1);
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        try {
          emp = *Login::login<Employee>(stoi(id), password);
          empMenu(choice);
          break;
        }
        catch (const char* msg) {
          std::cerr << msg << std::endl;
          attempts++;
        }
      }
      break;
    case '3': // Client
      while (attempts < 5) {
        while (true) {
          std::cout << "Enter client id: ";
          std::cin >> id;
          try {
            stoi(id);
            break;
          }
          catch (std::exception e) {
            std::cout << "ID must be numeric digits only, please try again\n";
            continue;
          }
        }
        std::cout << "Enter client password: ";
        std::cin >> password;
        try {
          cli = *Login::login<Client>(stoi(id), password);
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
      break;
    case 'q': case 'Q': // Quit
      Load::rewriteAll();
      exit(0);
    case '0': // Back
      mainMenu(choice);
    default:
      std::cout << "No such option, please try again.\n" <<
        "1. Admin\n" << "2. Employee\n" << "3. Client\n" << "0. Back\n"
        << "q. Quit\n> ";
      notExecuted = true;
    }
  } while (notExecuted);
  std::cout << "Too many attempts, press any key to try again\n";
  std::cin.ignore(200, '\n');
  std::cin.get();
  system("clear");
  loginAs(choice);
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
      while (true) {
        system("clear");
        Options::Adm::Edit::printMenu();
        std::cin >> choice;
        try {
          Options::Adm::Edit::options(choice, adm);
          break;
        }
        catch (int x) {
          if (x == -1)
            admMenu(choice);
          if (x == -2)
            continue;
        }
      }
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
    case '1': // Search
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
    case '2': // List All
      system("clear");
      Options::Emp::List::printMenu();
      std::cin >> choice;
      try {
        Options::Emp::List::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          empMenu(choice);
      }
      catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
      break;
    case '3': // Edit
      while (true) {
        system("clear");
        Options::Emp::Edit::printMenu();
        std::cin >> choice;
        try {
          Options::Emp::Edit::options(choice, emp);
          break;
        }
        catch (int x) {
          if (x == -1)
            empMenu(choice);
          if (x == -2)
            continue;
        }
      }
      break;
    case '4': // Add
      system("clear");
      Menus::printMenu('E', 'A');
      try {
        std::cin >> choice;
        Options::Emp::Add::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          empMenu(choice);
      }
      break;
    case '5': // Remove
      system("clear");
      Menus::printMenu('E', 'R');
      try {
        std::cin >> choice;
        Options::Emp::Remove::options(choice, adm);
      }
      catch (int x) {
        if (x == -1)
          empMenu(choice);
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
void Screens::cliMenu(char& choice) {
  system("clear");
  Menus::printMenu('C', 'M');
  bool notExecuted = true;
  while (notExecuted) {
    std::cin >> choice;
    notExecuted = false;
    switch (choice) {
    case '1': // View Balance
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
    case '2': // Deposit
      system("clear");
      Options::Cli::Deposit::printMenu();
      try {
        int amount;
        std::cin >> amount;
        cli.deposit(amount);
        emp.editClient(cli.getID(), cli.getName(), cli.getPassword(), cli.getBalance());
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
    case '3': // Withdraw
      system("clear");
      try {
        int amount;
        bool notExecuted = true;
        Options::Cli::Withdraw::printMenu();
        while (notExecuted) {
          try {
            notExecuted = false;
            std::cin >> amount;
            cli.withdraw(amount);
            emp.editClient(cli.getID(), cli.getName(), cli.getPassword(), cli.getBalance());
          }
          catch (const char* msg) {
            std::cerr << msg << " please try again\n";
            std::cout << "Enter an amount: $";
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
    case '4': // Transfer
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
            Client cli2 = *Load::search<Client>(id); // 133123
            cli.transferTo(amount, cli2); // 133123 - amount
            emp.editClient(cli.getID(), cli.getName(), cli.getPassword(), cli.getBalance());
            emp.editClient(cli2.getID(), cli2.getName(), cli2.getPassword(), cli2.getBalance());
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
Admin Screens::adm;
Employee Screens::emp;
Client Screens::cli;
//------------------------------------------------------------------------------