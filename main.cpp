#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Banking {
public:
    string name;
    int balance;
    int accountnum;

    // Default constructor
    Banking() : name(""), balance(0), accountnum(0) {}

    // Parameterized constructor
    Banking(string name, int accountnum, int balance) {
        this->name = name;
        this->accountnum = accountnum;
        this->balance = balance;
    }

    string getName() const {
        return name;
    }

    int getAccountNum() const {
        return accountnum;
    }

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance.\n";
        }
    }
};

void findAccountWithBalance(map<int, Banking>& accounts, int balance) {
    for (const auto& account : accounts) {
        if (account.second.getBalance() == balance) {
            cout << "Account found: " << account.second.getName() 
                 << " with account number " << account.second.getAccountNum() << "\n";
            return;
        }
    }
    cout << "No account found with the specified balance.\n";
}

int main() {
    map<int, Banking> accounts;  
    int choice;
    string name;
    int accountnum, balance;
    
    do {
        cout << "Banking Management System\n";
        cout << "\t1. New Account\n";
        cout << "\t2. Search Account\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Withdraw Money\n";
        cout << "\t5. Find account with balance\n";
        cout << "\t6. Exit\n";
        cout << "--------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> name; 
                cout << "Account Number: ";
                cin >> accountnum;
                cout << "Balance: ";
                cin >> balance;
                accounts[accountnum] = Banking(name, accountnum, balance);
                cout << "Account created successfully.\n";
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accountnum;
                if (accounts.find(accountnum) != accounts.end()) {
                    cout << "Account found: " << accounts[accountnum].getName() 
                         << " with balance " << accounts[accountnum].getBalance() << "\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accountnum; 
                if (accounts.find(accountnum) != accounts.end()) {
                    int amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount; 
                    accounts[accountnum].deposit(amount); 
                    cout << "Deposit successful.\n";
                } else {
                    cout << "Account not found.\n"; 
                }
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accountnum; 
                if (accounts.find(accountnum) != accounts.end()) {
                    int amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount; 
                    accounts[accountnum].withdraw(amount); 
                    cout << "Withdrawal successful.\n";
                } else {
                    cout << "Account not found.\n"; 
                }
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accountnum; 
                if (accounts.find(accountnum) != accounts.end()) {
                    cout << "Your current balance is " << accounts[accountnum].getBalance() << "\n";
                } else {
                    cout << "Account not found.\n"; 
                }
                break;
            case 6:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
