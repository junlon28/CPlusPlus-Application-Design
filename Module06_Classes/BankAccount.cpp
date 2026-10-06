#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
    private:
    string accountName;
    int accountNumber;
    double balance;

    public:
    BankAccount(string name, int number, double startingBalance)
    {
        accountName = name;
        accountNumber = number;
        balance = startingBalance;

    }

    void displayAccount()
    {
        cout << "Account Name: " << accountName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

     void deposit(double amount)
     {
        balance = balance + amount;
     }
     
     void withdraw(double amount)
     {
        balance = balance - amount;
     }

     double getBalance()
     {
        return balance;
     }

};

int main()
{
    BankAccount account1("Kevin", 1001, 600.00);
    BankAccount account2("Jonathan", 1002, 1000.00);

    account1.deposit(200.00);
    account2.withdraw(400.00);

    account1.displayAccount();

    cout << endl;

    account2.displayAccount();

    cout << endl;
    cout << "Kevin's balance using getter: $" << account1.getBalance() << endl;

    return 0;
}