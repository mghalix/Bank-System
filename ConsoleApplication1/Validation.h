#pragma once
using namespace std;
class Validation {
public:
	static void checkName(string name) {
		if (name.length() < 5)
			throw("Name is too short!");
		if (name.length() > 20)
			throw("Name is too long!");
	}

	static void checkPassword(string password) {
		if (password.length() < 8)
			throw("Password is too short!");
		if (password.length() > 20)
			throw("Password is too long!");
	}

	static void checkBalanceOfClient(double balance) {
		if (balance < 1500)
			throw "Your balance must be greater than 1500 ";
	}
};