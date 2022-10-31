#pragma once

#include "../abstract/person.h"

class Client : public Person {
private:
  // Attributes
  double balance;
  int cliID;
  static int id;
public:
  // Constructors
  Client() :Person() {
    balance = 0;
  }
  Client(std::string name, std::string password, double balance) : Person(name, password), cliID(id += 10) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }

  Client(double balance) : Person(), cliID(id += 10) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }

  // Destructor
  // ~Client() { id -= 10; }
  // Setters
  void setBalance(double balance) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }

  void setID(int id) override { cliID = id; }
  // Getters
  double getBalance() { return balance; }

  int getID() const override { return cliID; }

  // Methods
  void deposit(double amount) {
    balance += amount;
  }

  void withdraw(double amount) {
    if (amount > balance)
      throw "Not enough balance in your account!";
    balance -= amount;
  }

  void transferTo(double amount, Client& recipient) {
    if (amount > balance)
      throw("Amount exceeded balance!");
    recipient.balance += amount;
    balance -= amount;
    std::cout << "Transaction Successful\n";
  }

  void checkBalance() {
    std::cout << "Your balance: $" << balance;
  }

  void display() override {
    std::cout << "Name: " << getName() << std::endl
      << "ID: #" << getID() << std::endl
      // << "Password: " << getPassword() << std::endl
      << "Balance: $" << Helpers::correctView(balance) << std::endl;
  }

  /**
   * @brief when we rerun the program we don't want the static id to be reset,
   * so we correct its value based on the last id on the file.
   * @param id
   */
  static void initID() { id = FilesHelper::getLastID(FilesHelper::clientFile); }
  static int lastID() { return FilesHelper::getLastID(FilesHelper::clientFile); }
};
int Client::id = 6990;