#include <iostream>
#include "BankTools.h"

using namespace std;

void showMessage()
{
    cout << "Banking system ready." << endl;
}

void addRecord(double amounts[], char types[], int &count)
{
    cout << "Enter transaction type (D for Deposit, W for Withdraw): ";
    cin >> types[count];

    cout << "Enter transaction amount: ";
    cin >> amounts[count];

    count++;
}

void displayRecords(double amounts[], char types[], int count)
{
    cout << "\nTransaction Records:" << endl;

    for (int i = 0; i < count; i++)
    {
        if (types[i] == 'D')
        {
            cout << "Transaction " << i + 1
                 << ": Deposit $" << amounts[i] << endl;
        }
        else if (types[i] == 'W')
        {
            cout << "Transaction " << i + 1
                 << ": Withdrawal $" << amounts[i] << endl;
        }
    }
}

double calculateBalance(double amounts[], char types[], int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        if (types[i] == 'D')
        {
            total += amounts[i];
        }
        else if (types[i] == 'W')
        {
            total -= amounts[i];
        }
    }

    return total;
}