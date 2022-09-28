#include <iostream>
#include "classes/file_manager.h"
using namespace std;
int main()
{

  Employee emp1(441, "Mohamed", "121312351", 56000);
  Employee emp2(442, "Menna", "131512312", 7000.54);
  Client cli1(443, "Hassan", "9786412495", 12314.413);
  Client cli2(444, "Hussein", "923812344", 123123);
  Admin adm1(445, "Ahmed", "11281123412", 9000.905);
  Admin adm2(446, "Assem", "12342412412", 11000.970);
  // FileManager fm;
  // fm.addEmployee(emp1);
  // fm.addEmployee(emp2);
  // fm.addClient(cli1);
  // fm.addClient(cli2);
  // fm.addAdmin(adm1);
  // fm.addAdmin(adm2);

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
  // adm1.editClient(443, "nonnah", "12314124123", 9000.9745);
  // emp1.editClient(443, "nonnah", "12314124123", 9000.9745);
  // adm1.editEmployee(441, "lollah", "qwerty9876", 8900.4032);

  return 0;
}