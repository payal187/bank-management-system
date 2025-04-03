#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNo, string holder, double initialBalance) {
        accountNumber = accNo;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully! New Balance: " << balance << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Amount Withdrawn Successfully! New Balance: " << balance << endl;
        return true;
    }

    void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(int accNo, string holder, double initialBalance) {
        accounts.push_back(Account(accNo, holder, initialBalance));
        cout << "Account Created Successfully!" << endl;
    }

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                return &acc;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;
    int choice;
    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 5) break;
        
        int accNo;
        string name;
        double amount;
        
        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> amount;
                bank.createAccount(accNo, name, amount);
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                Account* acc;
                acc = bank.findAccount(accNo);
                if (acc) {
                    cout << "Enter Amount to Deposit: ";
                    cin >> amount;
                    acc->deposit(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                acc = bank.findAccount(accNo);
                if (acc) {
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amount;
                    acc->withdraw(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                acc = bank.findAccount(accNo);
                if (acc) {
                    acc->displayDetails();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
