#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>


struct Transaction{
    std::string type;
    double amount;
    std::string timestamp;
    double BalanceAfter;
};
class Wallet{
    double balance;
    
    public:

        Wallet(double initialBalance=0.0 ) : balance(initialBalance){
            loadBalance();
        }

        double getBalance() const {
            return balance;
        }

        void updateBalance(double amount){
            balance += amount;
            saveBalance();
        }

        void displayBalance() const {
            std::cout << "\033[32m";
            std::cout<<"Current Balance: "<<std::fixed << std::setprecision(2)<< balance<< std::endl;
            std::cout << "\033[0m";
        }

    private:
        void saveBalance() {
            std::ofstream file("balance.txt");
            if (file.is_open()) {
                file << std::fixed << std::setprecision(2) << balance;
                file.close();
            }
        }

        void loadBalance() {
            std::ifstream file("balance.txt");
            if (file.is_open()) {
                file >> balance;
                file.close();
            }
        }

};

class Transactions: public Wallet{
    public:
        Transactions(double initialBalance = 0.0) : Wallet(initialBalance) {}

        void income(double amount) {
            if(amount < 0.0) {
                std::cout << "Income Cannot be negative"<<std::endl;
                return;
            }
            else {
                updateBalance(amount);
                saveTransaction("INCOME", amount);
            }    
        }

        void expense(double amount){
            if(getBalance() < amount){
                std::cout << "Insufficient Balance!\n";
                return;
            }
            if(amount > 0.0){ 
                updateBalance(-amount);
                saveTransaction("EXPENSE", amount);
            }
            else {
                updateBalance(amount);
                saveTransaction("EXPENSE", amount);
            }
        }

        void displayTransactions () const {
            std::ifstream file("transactions.txt");
            if (!file.is_open()) {
                std::cout << "No transaction history found! \n";
                return;
            }

            std::cout << "\nTransaction History\n";
            std::cout << std::setfill('-') << std::setw(70) << "-" << std::endl;
            std::cout << std::setfill(' ');
            std::cout << std::left << std::setw(20) << "Date/Time"
                      << std::setw(10) << "Type"
                      << std::right << std::setw(15) << "Amount"
                      << std::setw(20) << "Balance After" << std::endl;
            std::cout << std::setfill('-') << std::setw(70) << "-" << std::endl;
            std::cout << std::setfill(' ');

            Transaction t;
            std::string line;
            while (std::getline(file, line)) {
                size_t pos = 0;
                pos = line.find("|");
                t.timestamp = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find("|");
                t.type = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find("|");
                t.amount = std::stod(line.substr(0, pos));
                line.erase(0, pos + 1);

                t.BalanceAfter = std::stod(line);

                if(t.type == "INCOME") {
                    std::cout << "\033[34m";    
                }
                else {
                    std::cout << "\033[31m";
                }

                std::cout << std:: left << std::setw(20) << t.timestamp
                          << std::setw(10) << t.type
                          << std::right << std::setw(15) << std::fixed << std::setprecision(2) << t.amount
                          << std::setw(20) << t.BalanceAfter << std::endl;
                
                std::cout << "\033[0m" ;
            }
            file.close();
        }

    private:

        std::string getTimestamp() {
            time_t now = time(0);
            struct tm t_Struct;
            char buf[80];
            t_Struct = *localtime(&now);
            strftime(buf, sizeof(buf), "%Y-%m-%d %X", &t_Struct);
            return std::string(buf);
        }

        void saveTransaction(const std::string &type, double amount){
            std::ofstream file("transactions.txt", std::ios::app);
            if  (file.is_open()) {
                file << getTimestamp() << "|"
                     << type << "|"
                     << std::fixed << std::setprecision(2) << amount << "|"
                     << getBalance() << "\n";
                file.close();
            }
        }
};

class Ledgerous: public Transactions {
        
    public:
        Transactions userWallet;
        
};

void menu(Ledgerous* user){
    int choice;
    int amount;
    do{
        system("cls");
        std::cout<<"Welcome to Ledgerous!\n";
        std::cout<<"[1] Display Balance\n";
        std::cout<<"[2] Add Income\n";
        std::cout<<"[3] Add Expense\n";
        std::cout<<"[4] View Transaction History\n";
        std::cout<<"[5] Exit\n";
        std::cout<<"\n#####################################################\n";
        std::cout<<"\nEnter your choice: ";
        std::cin>>choice;


        switch(choice){
            case 1:
                user->displayBalance();
                std::cout<<"\n";
                system("pause");
                system("cls");
                break;
            case 2:
                std::cout<<"Enter the amount: Rs. ";
                std::cin>>amount;
                user->income(amount);
                usleep(2);
                break;
            case 3:
                std::cout<<"Enter the amount: Rs. ";
                std::cin>>amount;
                user->expense(amount);
                usleep(2);
                break;
            case 4:
                user->displayTransactions();
                std::cout << "\n";
                system("pause");
                break;
            case 5:
                // usleep(100);
                std::cout<<"\nExiting. . . \n";
                exit(1);
            default:
                std::cout<<"Invalid option!\n";
                // usleep(20);
                break;
        }
    }while(1);
    
}

int main(){
    Ledgerous user;
    menu(&user);
    system("pause");
}