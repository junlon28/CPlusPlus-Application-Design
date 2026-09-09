#include <iostream>

using namespace std;

int main()
{
    double balance = 0;
    double amount = 0; 
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

  while (choice < 1 || choice > 5)
  {
    cout << "Invalid option. Select again: ";
    cin >> choice;
  }

  switch (choice)
  {
    case 1:
    cout << "Enter amount: ";
    cin >> amount;
    balance += amount;
    break;

    case 2:
    cout << "Enter amount: ";
    cin >> amount;
    balance -= amount;
    break;

    case 3:
    cout << "Balance: " << balance << endl;
    break;

    case 4:
    cout << "Balance: " << balance << endl;
    
    case 5:
    cout << "Goodbye, have a good day." << endl;
    quit = true;
    break;

  }

} while(!quit);

    return 0;
}