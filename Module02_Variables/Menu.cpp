#include <iostream>

using namespace std;

    void Deposit(double& balance)
{
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    balance += amount;
}

void Withdraw(double& balance)
{
    double amount;
    cout << "Enter amount withdrawn: ";
    cin >> amount;
    balance -= amount;
}

void Balance(double balance)
{
    cout << "Balance: " << balance << endl;
}


int main()
{
    double balance = 0;
    int choice = 0;
    bool quit = false;
   
do
{
  cout << "1. Deposit" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Check Balance" << endl;
  cout << "4. Check Balance and Quit" << endl;
  cout << "5. Quit" << endl;

  cout << "Enter a choice: ";

  cin >> choice;


  switch (choice)
  {
    case 1:
    Deposit(balance);
    break;

    case 2:
    Withdraw(balance);
    break;

    case 3:
    Balance(balance);
    break;

    case 4:
    Balance(balance);
    quit = true;
    
    case 5:
    cout << "Goodbye, have a good day." << endl;
    quit = true;
    break;

    default:
        cout << "Invalid choice, select again." <<endl;

  }

} 
    while(!quit);

    return 0;
}