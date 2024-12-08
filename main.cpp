/*
This is ledgerous.

Here you have a complete account of what you do with your money. The transactions are recorded as either 
income or expense. The transactions can be viewed filtered according to time period like week, month, day,
year, etc. Also the transactions can be classified with tags like "food", "travel", "grocery", etc.

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Wallet {
    double balance;
public:
    Wallet(){
        balance = 0.0;
    }
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
    Transaction(string type, string tag, double amount){
         
        this->type=type;
        this->tag=tag;
        this->amount=amount;
    }

    string getType() const { return type; }
    string getTag() const { return tag; }
    double getAmount() const { return amount; }

    void display() const {
        cout << type << ": " << amount << " (Tag: " << tag << ")" << endl;
    }
};


int main(){

    int opt;
    do{
        cout<<"Welcome to Ledgerous!"<<endl;
        cout<<"1. View Balance"<<endl;
        cout<<"2. View Transaction Hitory"<<endl;
        cout<<"3. Add Transaction"<<endl;
        cout<<"Choose an Option to Continue: "<<endl;
        cin>>opt;

        switch(opt){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }while(opt);
    return 0;
}
