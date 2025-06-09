#include <iostream>
using namespace std;

class ATM {
private:
    string userPIN = "1234"; // default PIN
    float balance = 1000.0;  // default balance

public:
    bool authenticate() {
        string pin;
        cout << "Enter your 4-digit PIN: ";
        cin >> pin;
        if (pin == userPIN) {
            cout << "Authentication successful.\n";
            return true;
        } else {
            cout << "Incorrect PIN.\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "Your current balance is: ?" << balance << endl;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ?";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ?";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }
};

int main() {
    ATM atm;
    int choice;

    cout << "===== Welcome to ATM Machine =====\n";

    if (!atm.authenticate()) {
        return 0;
    }

    do {
        cout << "\n----- ATM Menu -----\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: atm.checkBalance(); break;
            case 2: atm.deposit(); break;
            case 3: atm.withdraw(); break;
            case 4: cout << "Thank you for using the ATM. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
