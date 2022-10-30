//------------------------------------------------------------------------------
#pragma once
class Menus {
public:
  static void printMenu(const char &entity, const char &option) {
    switch (entity) {
    case 'S': { // start menu 
      switch (option) {
      case 'M': // main menu
        printf("\033[36m");
        std::cout << "\t\t\t\b\b\b\b***** Welcome to Route Bank *****" << std::endl
          << "1. Login as\nQ. Quit\n> ";
        break;
      case 'L': // login
        std::cout << "\t\t\t\t\b\b\b\b\b***** Login Page *****\nAre you a/an:\n"
          << "1. Admin\n" << "2. Employee\n" << "3. Client\n" << "0. Back\n"
          << "Q. Quit\n> ";
        break;
      }
      break;
    } // end of start(admin) switch

    case 'A': { // admin
      switch (option) {
      case 'M': { // menu
        std::cout << "\t\t\t***** Welcome Admin *****\nWhat do you want to do today?\n1. Search (Employees|Clients)\n2. List all (Employees|Clients)\n3. Edit (Employees|Clients)\n4. Add (Employees|Clients)\n5. Remove (Employees|Clients)\n0. Back\nQ. Quit\n> ";
        break;
      }

      case 'S': { // search
        std::cout << "\t\t\t***** Search *****" << std::endl
          << "1. Employees" << std::endl
          << "2. Clients" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'L': { // list all
        std::cout << "\t\t***** List All *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'E': { // edit
        std::cout << "\t\t***** Edit *****" << std::endl
          << "1. Employees" << std::endl
          << "2. Clients" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'A': { // add
        std::cout << "\t\t***** Add *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'R': {// remove
        std::cout << "\t\t***** Remove *****" << std::endl
          << "1. Employee" << std::endl
          << "2. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      } // end of option(of admin) switch
      break;
    } // end of entity(admin) switch
            //-----------------------------------------------------------------
    case 'E': { // employee
      switch (option) {
      case 'M': { // menu
        std::cout << "\t\t***** Welcome Employee *****\nWhat do you want to do today?\n1. Search (Clients)\n2. List all (Clients)\n3. Edit (Clients)\n4. Add (Clients)\n5. Remove (Clients)\n0. Back\nQ. Quit\n> ";
        break;
      }

      case 'S': { // search
        std::cout << "\t\t\t***** Search *****" << std::endl
          << "1. Clients" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'L': { // list all
        std::cout << "\t\t***** List All *****" << std::endl
          << "1. Clients" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'E': { // edit
        std::cout << "\t\t***** Edit *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'A': { // add
        std::cout << "\t\t***** Add *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      case 'R': { // remove
        std::cout << "\t\t***** Remove *****" << std::endl
          << "1. Client" << std::endl <<
          "0. Back\n> ";
        break;
      }

      } // end of option(of employee) switch
      break;
    } // end of entity(employee) switch
            //------------------------------------------------------------------
    case 'C': { // client
      switch (option) {
      case 'M': // menu
        std::cout << "\t\t***** Welcome Client *****\nWhat do you want to do today?\n1. View Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n0. Back\nQ. Quit\n> ";
        break;
      case 'B': // balance
        std::cout << "\n0. Back\n> ";
        break;
      case 'D': // deposit
        std::cout << "\t\t\t***** Deposit *****\nEnter an amount: $";
        break;
      case 'W': // withdraw
        std::cout << "\t\t\t***** Withdraw *****\nEnter an amount: $";
        break;
      case 'T': // transfer
        std::cout << "\t\t\t***** Transfer *****\nEnter an amount: $";
        break;
      } // end of option(of client) switch
      break;
    } //  end of entity(client) switch
            //------------------------------------------------------------------
    } // end of the whole switch case
  } // end of the method
};
//------------------------------------------------------------------------------