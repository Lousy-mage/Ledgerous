#include <iostream>
using namespace std;

class Wallet{
    int Balance;
    public:
    int getBalance(){
        return Balance;
    }
    void setBalance(int amount){
        Balance=amount;
    }
}userBalance;

class Transaction: public Wallet{
    int income;
    int expense;
    public:
    void addIncome(int amount){
        income=amount;
    }
    void addExpense(int amount){
        expense=amount;
    }
}

int main(){
    return 0;
}