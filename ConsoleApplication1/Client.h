#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Client : public Person
{
private:
  double balance;
public:
  //Constructors
  /*
  Client() : Person() { //You mustn't allow a default constructors in Client class because it's required for every client to have a minimum of 1500 balance, so you can't initialize balance variable like the following:
    balance = 0;
  }
  */
  Client(int id, string name, string password, double balance) : Person(id, name, password) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }
  Client(double balance) : Person() {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }
  //setters 
  void setBalance(double balance) {
    Validation::checkBalanceOfClient(balance);
    this->balance = balance;
  }
  //getters
  double getBalance() { return balance; }

  // methods
  void deposit(double amount) {
    balance += amount;
  }

  void withdraw(double amount) {
    balance -= amount;
  }

  void transferTo(double amount, Client &recipient) {
    if (balance > amount) {
      throw("Amount exceeded balance!");
    }
    recipient.balance += amount;
    balance -= amount;
  }

  void checkBalance() {
    cout << "Your balance: " << balance;
  }

  void display() {
    cout
      << "Client ACCOUNT: \n"
      << "ID: " << id << endl
      << "Name: " << name << endl
      << "Balance" << balance << endl;
  }
};

