#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Wallet {
    double balance;
public:
    Wallet() : balance(0.0) {}
    
    double getBalance() {
        return balance;
    }

    void updateBalance(double amount) {
        balance += amount;
    }
};

class Transaction {
    string type; // "income" or "expense"
    string tag;
    double amount;
public:
    Transaction(string type, string tag, double amount) 
        : type(type), tag(tag), amount(amount) {}

    string getType() const { return type; }
    string getTag() const { return tag; }
    double getAmount() const { return amount; }

    void display() const {
        cout << type << ": " << amount << " (Tag: " << tag << ")" << endl;
    }
};

class Ledgerous {
    Wallet wallet;
    vector<Transaction> transactions;
public:
    void viewBalance() const {
        cout << "Current Balance: " << wallet.getBalance() << endl;
    }

    void viewTransactionHistory() const {
        if (transactions.empty()) {
            cout << "No transactions available." << endl;
            return;
        }
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transactions) {
            transaction.display();
        }
    }

    void addTransaction() {
        string type, tag;
        double amount;
        cout << "Enter transaction type (income/expense): ";
        cin >> type;
        cout << "Enter transaction tag (e.g., food, travel): ";
        cin >> tag;
        cout << "Enter amount: ";
        cin >> amount;

        if (type == "expense") {
            amount = -amount; // Negative for expenses
        }

        wallet.updateBalance(amount);
        transactions.emplace_back(type, tag, amount);
        cout << "Transaction added successfully!" << endl;
    }

    void menu() {
        int opt;
        do {
            cout << "\nWelcome to Ledgerous!" << endl;
            cout << "1. View Balance" << endl;
            cout << "2. View Transaction History" << endl;
            cout << "3. Add Transaction" << endl;
            cout << "4. Exit" << endl;
            cout << "Choose an Option to Continue: ";
            cin >> opt;

            switch (opt) {
                case 1:
                    viewBalance();
                    break;
                case 2:
                    viewTransactionHistory();
                    break;
                case 3:
                    addTransaction();
                    break;
                case 4:
                    cout << "Exiting Ledgerous. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } while (opt != 4);
    }
};

int main() {
    Ledgerous ledger;
    ledger.menu();
    return 0;
}
