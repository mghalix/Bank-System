#include <iostream>
#include "classes/managers/file_manager.h"
using namespace std;
int main() {
  FileManager fm;
  //TODO: transfer the inits to runApp when phase3 comes.
  //=====================//
  // Admin::initID();
  // Employee::initID();
  // Client::initID();
  try {
    cout << FilesHelper::getLast("db/Clients.txt") << endl;
  }
  catch (const char *msg) {
    cerr << msg;
  }
  //====================//
  /*****init test*****/
// //----Admins
//   Admin a("nonnah", "1234567890", 90302.50);
//   a.display();
//   Admin a2("lollah", "123123123", 75000.304);
//   a2.display();
//   fm.addAdmin(a);
//   fm.addAdmin(a2);
  //----Employees
    // Employee emp1("Mohamed", "121312351", 56000);
    // Employee emp2("Menna", "131512312", 7000.54);
    // emp1.display();
    // emp2.display();
    // // fm.addEmployee(emp1);
    // // fm.addEmployee(emp2);
  //----Clients
    // Client cli1("Hassan", "9786412495", 12314.413);
    // Client cli2("Hussein", "923812344", 123123);
    // cli1.display();
    // cli2.display();
    // // fm.addClient(cli1);
    // // fm.addClient(cli2);
    //------------------------
    /*****Writing into files*****/
// Employee emp1("Mohamed", "121312351", 56000);
// Employee emp2("Menna", "131512312", 7000.54);
// fm.addEmployee(emp1);
// fm.addEmployee(emp2);
  // Client cli1("Hassan", "9786412495", 12314.413);
  // Client cli2("Hussein", "923812344", 123123);
  // fm.addClient(cli1);
  // fm.addClient(cli2);
  // Admin adm1("Ahmed", "11281123412", 9000.905);
  // Admin adm2("Assem", "12342412412", 11000.970);
  // fm.addAdmin(adm1);
  // fm.addAdmin(adm2);
  //------------------------
  /*****Display*****/
    //   vector<Employee> emps = fm.getAllEmployees();
    //   vector<Client> clis = fm.getAllClients();
    //   vector<Admin> adms = fm.getAllAdmins();
    //   cout << "Testing Employee Output: " << endl;
    //   for (int i = 0; i < emps.size(); i++) {
    //     emps[i].display();
    //     cout << "-----\n";
    //   }
    // cout << "-----------------------------------------------------------------\n";
    //   cout << "Testing Client Output: " << endl;
    //   for (int i = 0; i < clis.size(); i++) {
    //     clis[i].display();
    //     cout << "-----\n";
    //   }
    //   cout << "-----------------------------------------------------------------\n";
    //   cout << "Testing Admin Output: " << endl;
    //   for (int i = 0; i < adms.size(); i++) {
    //     adms[i].display();
    //     cout << "-----\n";
    //   }
  // cout << "-----------------------------------------------------------------\n";
  /*****Editing file info*****/
  // adm1.editClient(7000, "Johnny", "12314124123", 5000.9745);
  // emp1.editClient(3010, "Ronny", "12314124123", 9000.9745);
  // adm1.editEmployee(2000, "Dennis", "qwerty9876", 8900.4032);

  /***** Clearing Files *****/
  // FilesHelper::clearFile("db/Clients.txt");
  // FilesHelper::clearFile("db/Employee.txt");
  // FilesHelper::clearFile("db/Admin.txt");
  // Admin a = Parser::parseToAdmin("1");

  // try {
    // Admin a = Parser::parseToAdmin("2");
    // Person *p = &a;
    // p->display();

    // Employee emp = Parser::parseToEmployee("2000");
    // emp.searchClient(7010)->display();
    // Admin adm = Parser::parseToAdmin("1");
    // adm.searchEmployee(2010)->display();

    // Client c("Karma", "qwerty12345", 7000.304);
    // c.display();
    // fm.addClient(c);
    // Client c2("Kenda", "qwerty0987", 9000.50);
    // c2.display();
    // fm.addClient(c2);

    // FilesHelper::showClients();
  // }
  // catch (const char *msg) {
  //   cerr << msg << endl;
  // }

}