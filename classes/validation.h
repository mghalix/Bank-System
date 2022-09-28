#pragma once
class Validation {
public:
  static void checkName(std::string name) {
    std::string illegal = "1234567890!@#$%^&*()_+-=;:'\"><?/";
    if (std::string::npos != name.find_first_of(illegal))
      throw("Error you can only use alphabetic characters.\n");
    if (name.length() < 5)
      throw("Name is too short!");
    if (name.length() > 20)
      throw("Name is too long!");
  }

  static void checkPassword(std::string password) {
    if (password.length() < 8)
      throw("Password is too short!");
    if (password.length() > 20)
      throw("Password is too long!");
  }

  static void checkBalanceOfClient(double balance) {
    if (balance < 1500)
      throw "Your balance must be greater than 1500 ";
  }

  static void checkSalary(double salary) {
    if (salary < 5000)
      throw("Low salary");
  }
};