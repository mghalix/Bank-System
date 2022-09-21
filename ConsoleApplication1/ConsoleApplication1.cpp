#include <iostream>
#include "Client.h"
#include "Validation.h"
using namespace std;
int main() {
    Client c1(1500);
    try {
        c1.setId(123);
        c1.setName("Ahmed");
        c1.setPassword("15678");

    }
    catch (const char *msg) {
        cout << msg << endl;
    }

    //Outputs zero here because the program didn't accept the password setter above in the try block above, thus used the default password value initialized inside the Client's class constructor
    cout << c1.getPassword() << endl;

    //Updating to an acceptable password(length 8-20)
    cout << "-----\n";
    c1.setPassword("12345678");
    cout << "Client Account info.\n";
    cout << "Name: " << c1.getName() << endl
        << "ID: #" << c1.getId() << endl
        << "Password: " << c1.getPassword() << endl
        << "Balance: $" << c1.getBalance() << endl;

    cout << "-----\n";
    //TODO @nour update the display method below to display output exactly as I did above.
    c1.display();

    return 0;
}