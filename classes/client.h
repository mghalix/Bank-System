#pragma once
#include "person.h"
class Client : public Person {
private:
  // Attributes
  double balance;
  int cliID;
  static int id;
public:
  // Constructors
  Client(std::string name, std::string password, double balance) : Person(name, password), cliID(id += 10) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }

  Client(double balance) : Person(), cliID(id += 10) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }

  // Destructor
  ~Client() { id -= 10; }
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
  static void initID() { id = FilesHelper::getLast("db/Clients.txt"); }

  void deposit(double amount) {
    balance += amount;
  }

  void withdraw(double amount) {
    if (amount > balance)
      throw "Not enough balance in your account\n";
    balance -= amount;
  }

  void transferTo(double amount, Client &recipient) {
    if (amount > balance)
      throw("Amount exceeded balance!");
    recipient.balance += amount;
    balance -= amount;
    std::cout << "Transaction Successful\n";
  }

  void checkBalance() {
    std::cout << "Your balance: " << balance;
  }

  void display() {
    std::cout << "Name: " << getName() << std::endl
      << "ID: #" << getID() << std::endl
      // << "Password: " << getPassword() << std::endl
      << "Balance: $" << CustomMethods::correctView(balance) << std::endl;
  }
};
int Client::id = 6990;