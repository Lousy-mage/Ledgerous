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
};

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
