#pragma once
#include <iostream>
#include "person.h"
#include "validation.h"
class Employee : public Person {
private:
    //Attributes
    float salary;
    double balance;

public:
    //Constructors 
    Employee() : Person() {
        salary = 0.0;
        balance = 0.0;
    }

    Employee(int id, std::string name, std::string password, double balance, float salary) : Person(id, name, password) {
        this->balance = balance;
        Validation::checkSalary(salary);
        this->salary = salary;
    }

    //Setters
    void setSalary(float salary) {
        Validation::checkSalary(salary);
        this->salary = salary;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    //Getters
    float getSalary() const { return salary; }

    double getBalance() const { return balance; }

    //Methods
    void display() override {
        std::cout << "name: " << Person::getName() << std::endl
            << "password: " << Person::getPassword() << std::endl
            << "ID: " << Person::getID() << std::endl
            << "salary: " << salary << std::endl;
    }
};