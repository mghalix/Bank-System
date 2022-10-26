#pragma once
#include <iostream>
#include "../classes/dependencies/login.h"
#include "../classes/managers/file_manager.h"
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

class Screens {
private:
  static void mainMenu(int &choice); // complete
  static void loginAs(int &choice); // complete
  static void aboutUs(); // bla bla
  static void admMenu(int &choice);
  static void empMenu(int &choice);
  static void cliMenu(int &choice);
public:
  static void runApp();
};
//------------------------------------------------------------------------------
void Screens::mainMenu(int &choice) {
  system("clear");
  cout << "\t\t***** Welcome to Route Bank *****" << endl;
  cout << "1. Login as\n2. About us\n0. Exit\n> ";
  bool notExecuted = true;
  while (notExecuted) {
    notExecuted = false;
    cin >> choice;
    switch (choice) {
    case 1:
      system("clear");
      loginAs(choice);
      break;
    case 2:
      system("clear");
      // aboutUs();
      break;
    case 0:
      exit(0);
    default:
      cout << "No such option, please try again.\n";
      cout << "1. Login as\n2. About us\n0. Exit\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
void Screens::runApp() {
  int choice;
  mainMenu(choice);

  // last step
  Load::rewriteAll();
}
//------------------------------------------------------------------------------
void Screens::loginAs(int &choice) {
  std::cout << "\t\t***** Login Page *****\nAre you a/an:\n"
    << "1. Admin\n" << "2. Employee\n" << "3. Client\n"
    << "0. Back\n\n> ";
  int id;
  string password;
  bool notExecuted = true;
  while (notExecuted) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> choice;
    notExecuted = false;
    switch (choice) {
    case 1:
      while (true) {
        cout << "Enter admin id: ";
        cin >> id;
        cout << "Enter admin password: ";
        cin >> password;
        try {
          Login::login<Admin>(id, password);
          chrono::seconds dura(1);
          this_thread::sleep_for(dura);
          admMenu(choice);
          break;
        }
        catch (const char *msg) {
          cerr << msg << endl;
        }
      }
      break;
    case 2:
      cout << "Enter employee id: ";
      cin >> id;
      cout << "Enter employee password: ";
      cin >> password;
      Login::login<Employee>(id, password);
      break;
    case 3:
      cout << "Enter client id: ";
      cin >> id;
      cout << "Enter client password: ";
      cin >> password;
      Login::login<Client>(id, password);
      break;
    case 0:
      mainMenu(choice);
      return;
    default:
      cout << "No such option, please try again.\n" <<
        "1. Admin\n" << "2. Employee\n" << "3. Client\n"
        << "0. Back\n\n> ";
      notExecuted = true;
    }
  }
}
//------------------------------------------------------------------------------
void Screens::admMenu(int &choice) {
  system("clear");
  cout << "\t\t***** Welcome Admin *****\nWhat do you want to do today?\n1. Search (employee/client/admin)\n2. List all (employees/clients/admins)\n3. edit(employee/client/admin)\n4. Add (employee/client/admin)\n5. Remove (employee/client/admin)\n0. Back\n> ";
  bool notExecuted = true;
  while (notExecuted) {
    cin >> choice;
    notExecuted = false;
    switch (choice) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 0:
      system("clear");
      loginAs(choice);
      break;
    default:
      cout << "No such option, please try again.\n> ";
      notExecuted = true;
    }
  }
}