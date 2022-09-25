#include <iostream>
#include "validation.h"
#include "file_manager.h"
#include "employee.h"
using namespace std;
int main() {
  Employee emp1(1234, "Mohanad", "121312351", 56000);
  Employee emp2(123, "Ahmed", "131512312", 7000.54);
  Client cli1(4451, "client1", "9786412495", 12314);
  Client cli2(7402, "client 2", "923812344", 123123);
  Admin adm1(101, "admin1", "11281123412", 9000.90);
  Admin adm2(1011, "admin2", "12342412412", 11000.970);
  FileManager fm;
  fm.addEmployee(emp1);
  fm.addEmployee(emp2);
  fm.addClient(cli1);
  fm.addClient(cli2);
  fm.addAdmin(adm1);
  fm.addAdmin(adm2);

  vector<Employee> emps = fm.getAllEmployees();
  vector<Client> clis = fm.getAllClients();
  vector<Admin> adms = fm.getAllAdmins();
  cout << "Testing Employee Output: " << endl;
  emps[1].display();
  cout << "-----\n";
  cout << "Testing Client Output: " << endl;
  clis[0].display();
  cout << "-----\n";
  cout << "Testing Admin Output: " << endl;
  adms[1].display();


  cin.get();
  return 0;
}