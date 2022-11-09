#include <iostream>
#include "start/screens.h"

using namespace std;

int main() {
  // for testing
  // login as admin:        id -> 1 | pw -> qwerty12345 
  // login as employee:     id -> 2000 | pw -> qwerty12345
  // login as client:       id -> 7000 | pw -> qwerty12345

  try {
    Screens::runApp();
  }
  catch (const char *msg) {
    cerr << msg;
  }



































  //=====================//
  // FileManager fm;
  // Admin::initID();
  // Employee::initID();
  // Client::initID();
  //====================//
  /*****init test*****/
  // //----Admins
  //   Admin a("nonnah", "1234567890", 90302.50);
  //   // a.display();
  //   Admin a2("lollah", "123123123", 75000.304);
  //   // a2.display();
  //   fm.addAdmin(a);
  //   fm.addAdmin(a2);
  //   // ----Employees
  //   Employee emp1("Mohamed", "121312351", 56000);
  //   Employee emp2("Menna", "131512312", 7000.54);
  //   // emp1.display();
  //   // emp2.display();
  //   fm.addEmployee(emp1);
  //   fm.addEmployee(emp2);
  // // ----Clients
  //   Client cli1("Hassan", "9786412495", 12314.413);
  //   Client cli2("ahmedawy", "123124123", 99999);
  //   cli1.display();
  //   cli2.display();
  //   fm.addClient(cli1);
  //   fm.addClient(cli2);
  // Load::rewriteAll();
  //------------------------
  /*****Writing into files*****/
  // Load::loadAll();
  // FileManager fm;
  // fm.removeAllAdmins();
  // fm.removeAllClients();
  // fm.removeAllEmployees();
  // Employee emp1("Mohamed", "qwerty12345", 56000);
  // Employee emp2("Menna", "131512312", 7000.54);
  // fm.addEmployee(emp1);
  // fm.addEmployee(emp2);
  // Client cli1("Hassan", "qwerty12345", 12314.413);
  // Client cli2("Hussein", "923812344", 123123);
  // fm.addClient(cli1);
  // fm.addClient(cli2);
  // Admin adm1("Ahmed", "qwerty12345", 9000.905);
  // Admin adm2("Assem", "12342412412", 11000.970);
  // fm.addAdmin(adm1);
  // fm.addAdmin(adm2);
  // Load::rewriteAll();
  //------------------------
  /*****Display*****/
  // vector<Employee> emps = fm.getAllEmployees();
  // vector<Client> clis = fm.getAllClients();
  // vector<Admin> adms = fm.getAllAdmins();
  // cout << "Testing Employee Output: " << endl;
  // for (int i = 0; i < emps.size(); i++) {
  //   emps[i].display();
  //   cout << "-----\n";
  // }
  // cout << "-----------------------------------------------------------------\n";
  // cout << "Testing Client Output: " << endl;
  // for (int i = 0; i < clis.size(); i++) {
  //   clis[i].display();
  //   cout << "-----\n";
  // }
  // cout << "-----------------------------------------------------------------\n";
  // cout << "Testing Admin Output: " << endl;
  // for (int i = 0; i < adms.size(); i++) {
  //   adms[i].display();
  //   cout << "-----\n";
  // }
  // cout << "-----------------------------------------------------------------\n";
  /*****Editing file info*****/
  // adm1.editClient(7000, "Johnny", "12314124123", 5000.9745);
  // emp1.editClient(3010, "Ronny", "12314124123", 9000.9745);
  // adm1.editEmployee(2000, "Dennis", "qwerty9876", 8900.4032);

  /***** Clearing Files *****/
  // FilesHelper::clearFile("db/Clients.txt");
  // FilesHelper::clearFile("db/Employees.txt");
  // FilesHelper::clearFile("db/Admins.txt");
  // Admin a = Parser::parseToAdmin("1");

  // try {
    // Admin a = Parser::parseToAdmin("2");
    // Person *p = &a;
    // p->display();

  // Employee emp = Parser::parseToEmployee("2000");
  // emp.searchClient(7010)->display();
  // Admin adm = Parser::parseToAdmin("1");
  // adm.searchEmployee(2010)->display();

  // FilesHelper::showClients();


  // fm.addClient(cli1);

  // fm.addClient(c2);
  // c.display();
  // c2.display();

  // FilesHelper::showClients();
  // try {
  //   Login::login<Client>(7010, "qwerty0987")->display();
  //   cout << "--------\n";
  //   Login::login<Employee>(2000, "121312351")->display();
  //   cout << "--------\n";
  //   Login::login<Admin>(7010, "qwerty0987")->display();
  // }
  // catch (const char *msg) {
  //   cerr << msg;
  // }
  // Load::loadEntity<Employee>();
  // // Login::load<Client>();

  return 0;
}