#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Client:private Person
{
private:
	double balance;
public:
	Client() {
		Person p;
		p.setName(Person::name);
		p.setId(Person::id);
		p.setPassword(Person::password);
	};
	Client(int id, string name, string password, double balance):Person(id,name,password) {
		/*Person::Person();*/
		Validation::checkBalanceOfClient(balance);
		this->balance = balance;
	}
	Client(double balance) { 
		Validation::checkBalanceOfClient(balance);
		this->balance = balance;
	}
	//setters 
	void setBalance(double balance) {
		Validation::checkBalanceOfClient(balance);
		this->balance = balance;
	}
	//getters
	double balance() { return balance; }

	// methods

	void deposite(double amount) {
		balance += amount;
	}

	void withdraw(double amount) {
		balance -= amount;
	}

	void transfereTo(double amount , Client& recipien) {
		balance -= amount;
		recipien.balance += amount;
	}

	void checkBalance() {
		cout << "Your balance: " << balance;
	}

	void display() {
		cout 
			<< "Client ACCOUNT: \n" 
			<<"ID: " << id << endl
			<< "Name: " << name << endl
			<< "Balance" << balance << endl;
	}
};

