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

class Transaction{
    double income;
    double expense;
    double total;
    
    public:
    void addIncome(double amount){
        income=amount;
        calcTotal();
    }
    void addExpense(double amount){
        expense=(-1*amount);
        calcTotal();
    }
    void calcTotal(){
            total=income+expense;
            setBalance(total);
    }
}transactions;


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
