#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Record
{
    int id;
    string name;
};

int binarySearch(const vector<Record>& data, int target)
{
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (data[mid].id == target) return mid;
        if (data[mid].id < target) left = mid + 1;
        else right = mid -1;
    }
    return -1;
}

int readNumber(string message)
{
    int number;
    while(true)
    {
        cout << message;
        if (cin >> number)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
        cout << "Invalid input. Enter a number. \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

class User 
{
    protected:
        string username;

    public:
        User(string name) : username(name) {}
            virtual ~User() {}

     void viewRecords(const vector<Record>& records) 
     {
        if (records.empty()) 
        {
            cout << "No records available.\n";
            return;
        }
        cout << "\n--- Records (sorted by ID) ---\n";
        for (int i = 0; i < static_cast<int>(records.size()); i++) 
        {
            cout << "ID: " << records[i].id << " | Name: " << records[i].name << endl;
        }
    }

    void searchRecord(const vector<Record>& records) 
    {
        int id = readNumber("Enter ID to search: ");
        int index = binarySearch(records, id);
        if (index == -1) cout << "Record not found.\n";
        else cout << "Found: ID " << records[index].id << " | Name: " << records[index].name << endl;
    }        
};

class Admin : public User 
{
public:
    Admin(string name) : User(name) {}

    void addRecord(vector<Record>& records) 
    {
        int id = readNumber("Enter new record ID: ");
        if (binarySearch(records, id) != -1) 
        {
            cout << "That ID already exists.\n";
            return;
        }
        string name;
        cout << "Enter record name: ";
        getline(cin, name);
        if (name.empty()) 
        {
            cout << "Name cannot be empty.\n";
            return;
        }
        Record newRecord = {id, name};
        int position = 0;
        while (position < static_cast<int>(records.size()) && records[position].id < id) 
        {
            position++;
        }
        records.insert(records.begin() + position, newRecord);
        cout << "Record added successfully.\n";
    }

    void deleteRecord(vector<Record>& records) 
    {
        int id = readNumber("Enter record ID to delete: ");
        int index = binarySearch(records, id);
        if (index == -1) 
        {
            cout << "Record not found.\n";
            return;
        }
        records.erase(records.begin() + index);
        cout << "Record deleted successfully.\n";
    }
};

int main() 
{
    vector<Record> records;
    int role;
    do 
    {
        cout << "\n=== SELECT ROLE ===\n";
        cout << "1. Admin\n2. Regular User\n3. Exit\n";
        role = readNumber("Choose an option: ");
        if (role == 1) 
        {
            Admin admin("Admin");
            int choice;
            do 
            {
                cout << "\n=== ADMIN MENU ===\n";
                cout << "1. Add Record\n2. Delete Record\n3. View Records\n4. Search Record\n5. Log Out\n";
                choice = readNumber("Choose an option: ");
                switch (choice) 
                {
                    case 1: admin.addRecord(records); break;
                    case 2: admin.deleteRecord(records); break;
                    case 3: admin.viewRecords(records); break;
                    case 4: admin.searchRecord(records); break;
                    case 5: cout << "Logging out...\n"; break;
                    default: cout << "Invalid option.\n";
                }
            } while (choice != 5);
        } 
        
        else if (role == 2) 
        {
            User regularUser("Regular User");
            int choice;
            do 
            {
                cout << "\n=== REGULAR USER MENU ===\n";
                cout << "1. View Records\n2. Search Record\n3. Log Out\n";
                choice = readNumber("Choose an option: ");
                switch (choice) 
                {
                    case 1: regularUser.viewRecords(records); break;
                    case 2: regularUser.searchRecord(records); break;
                    case 3: cout << "Logging out...\n"; break;
                    default: cout << "Invalid option.\n";
                }
            } 
            while (choice != 3);
        } 
        else if (role != 3) 
        {
            cout << "Invalid role.\n";
        }
    } 
    while (role != 3);
    
    cout << "Goodbye!\n";
    return 0;
}