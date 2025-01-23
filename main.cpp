#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

class Wallet{
    double balance;
    
    public:

        Wallet(double initialBalance=0.0 ) : balance(initialBalance){}

        double getBalance() const {
            return balance;
        }

        void updateBalance(double amount){
            balance += amount;
        }

        void displayBalance() const {
            std::cout<<"Current Balance: "<<std::fixed << std::setprecision(2)<< balance<< std::endl;
        }

};

class Transactions: public Wallet{
    public:
        Transactions(double initialBalance = 0.0) : Wallet(initialBalance) {}

        void income(double amount){
            if(amount < 0.0){
                std::cout<<"Income Cannot be negative"<<std::endl;
                return;
            }
            else updateBalance(amount);
        }

        void expense(double amount){
            if(getBalance() < amount){
                std::cout<<"Insufficient Balance!\n";
                return;
            }
            if(amount > 0.0) updateBalance(-amount);
            else updateBalance(amount);
        }

};

class Ledgerous: public Transactions {
        
    public:
        Transactions userWallet;
        

};

int main(){
    Ledgerous user;
    user.displayBalance();
    user.expense(100);
    user.income(200);
    user.expense(300);
    user.displayBalance();
}