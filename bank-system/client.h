#pragma once
#include <iostream>
#include "person.h"
class Client : public Person
{
private:
    //Attributes
    double balance;

public:
    //Constructors
    /*
    Client() : Person() { //You mustn't allow a default constructors in Client class because it's required for every client to have a minimum of 1500 balance, so you can't initialize balance variable like the following:
      balance = 0;
    }
    */
    Client(int id, std::string name, std::string password, double balance) : Person(id, name, password) {
        Validation::checkBalanceOfClient(balance);
        this->balance = balance;
    }

    Client(double balance) : Person() {
        Validation::checkBalanceOfClient(balance);
        this->balance = balance;
    }

    //Setters 
    void setBalance(double balance) {
        Validation::checkBalanceOfClient(balance);
        this->balance = balance;
    }

    //Getters
    double getBalance() { return balance; }

    //Methods
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    void transferTo(double amount, Client& recipient) {
        if (balance > amount) {
            throw("Amount exceeded balance!");
        }
        recipient.balance += amount;
        balance -= amount;
    }

    void checkBalance() {
        std::cout << "Your balance: " << balance;
    }

    void display() {
        std::cout << "Client Account info.\n";
        std::cout << "Name: " << getName() << std::endl
            << "ID: #" << getID() << std::endl
            // << "Password: " << getPassword() << std::endl
            << "Balance: $" << getBalance() << std::endl;
    }
};