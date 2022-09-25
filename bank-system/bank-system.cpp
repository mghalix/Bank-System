#include <iostream>
#include "validation.h"
#include "file_manager.h"
#include "employee.h"
using namespace std;
int main() {
  Client c1(1500);
  try {
    c1.setID(123);
    c1.setName("Ahmed");
    c1.setPassword("15678");
  }
  catch (const char *msg) {
    cout << msg << endl;
  }
  //Outputs no_password here because the program didn't accept the password setter above in the try block above, thus used the default password value initialized inside the Client's class constructor
  cout << c1.getPassword() << endl;
  //Updating to an acceptable password(length 8-20)
  cout << "-----\n";
  c1.setPassword("12345678");
  // c1.display();
  Employee emp(1234, "Mohanad", "13213123", 56000);

  // emp.display();
  FileManager fm;
  fm.addEmployee(emp);
  try {

    fm.addEmployee(Employee(123, "ahmed", "12312312", 7000.54));
  }
  catch (const char *msg) {
    cerr << msg << endl;
  }
  vector<Employee> emps = fm.getAllEmployees();
  cout << emps[1].getSalary() << endl;
  return 0;
}