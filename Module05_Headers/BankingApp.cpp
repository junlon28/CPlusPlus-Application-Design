#include <iostream>
#include "BankTools.h"

using namespace std;

int main()
{
    showMessage();

    double amounts[10]; //creates transcations amounts
    char types[10]; //difference between withdraw and deposit
    int count = 0;  //tracks how many transcations

    int choice = 0;

    while (choice != 4)
    {
        cout << "\n=== BANKING APPLICATION ===" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. View Transactions" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        addRecord(amounts, types, count);
        break;

        case 2:
        displayRecords(amounts, types, count);
        break;

        case 3:
        cout << "Current Balance: $"
             << calculateBalance(amounts, types, count) << endl;
        break;

        case 4:
        cout << "Goodbye!" << endl;
        break;

        default:
        cout << "Invalid option." << endl;
        }
    }

    addRecord(amounts, types, count);

    displayRecords(amounts, types, count);

    double balance = calculateBalance(amounts, types, count);

    cout << "Current Balance: $" << balance << endl;

    return 0;
}