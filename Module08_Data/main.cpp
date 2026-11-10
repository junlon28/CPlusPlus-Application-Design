#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 100;

class Student 
{
public:
    int id;
    string name;
    double grade;

    Student() : id(0), name(""), grade(0) {}
    Student(int studentId, string studentName, double studentGrade)
        : id(studentId), name(studentName), grade(studentGrade) {}

    void display() const 
    {
        cout << "ID: " << id << " | Name: " << name
             << " | Grade: " << grade << endl;
    }
};

class User 
{
protected:
    string username;
public:
    User(string name) : username(name) {}
    void welcome() const { cout << "Welcome, " << username << "!\n"; }
};

class Admin : public User 
{
public:
    Admin(string name) : User(name) {}
    void showPermissions() const 
    {
        cout << "Admin can add, delete, view, and search records.\n";
    }
};

// Student objects are stored in a fixed-size array.
Student students[MAX_STUDENTS];
int studentCount = 0;

// Read a whole number and reject extra characters.
int readNumber(const string& prompt) 
{
    string line;
    while (true) 
    {
        cout << prompt;
        if (!getline(cin, line)) return 0;
        try 
        {
            size_t used = 0;
            int value = stoi(line, &used);
            if (used == line.size()) return value;
        } catch (...) {}
        cout << "Invalid input. Please enter a whole number.\n";
    }
}

int readPositiveID(const string& prompt) 
{
    while (true) 
    {
        int id = readNumber(prompt);
        if (id > 0) return id;
        cout << "ID must be a positive whole number. Try again.\n";
    }
}

double readGrade() 
{
    string line;
    while (true) 
    {
        cout << "Enter grade (0-100): ";
        getline(cin, line);
        try 
        {
            size_t used = 0;
            double grade = stod(line, &used);
            if (used == line.size() && grade >= 0 && grade <= 100)
                return grade;
        } catch (...) {}
        cout << "Invalid grade. Enter a number from 0 to 100.\n";
    }
}

string readName() 
{
    string name;
    while (true) 
    {
        cout << "Enter student name: ";
        getline(cin, name);

        if (name.find_first_not_of(" \t") != string::npos) return name;
        cout << "Name cannot be empty. Try again.\n";
    }
}

// Binary search works because the student array is sorted by ID.
int binarySearch(int target) 
{
    int left = 0;
    int right = studentCount - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (students[mid].id == target) return mid;
        if (students[mid].id < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void saveRecords() {
    ofstream file("students.txt");
    if (!file) 
    {
        cout << "Error: could not save records.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) 
    {
        file << students[i].id << '\n'
             << students[i].name << '\n'
             << students[i].grade << '\n';
    }
}

void loadRecords() 
{
    ifstream file("students.txt");
    if (!file) return; // No saved file on the first run.
    int id;
    string name;
    double grade;

    while (studentCount < MAX_STUDENTS && file >> id) 
    {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(file, name) || !(file >> grade)) break;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (id <= 0 || grade < 0 || grade > 100 || name.empty()) continue;
        if (binarySearch(id) != -1) continue;
        int pos = studentCount;

        while (pos > 0 && students[pos - 1].id > id) 
        {
            students[pos] = students[pos - 1];
            pos--;
        }
        students[pos] = Student(id, name, grade);
        studentCount++;
    }
}

void addRecord() 
{
    if (studentCount == MAX_STUDENTS) 
    {
        cout << "The student list is full.\n";
        return;
    }
    int id;
    while (true) 
    {
        id = readPositiveID("Enter student ID: ");
        if (binarySearch(id) == -1) break;
        cout << "That ID already exists. Try another ID.\n";
    }
    string name = readName();
    double grade = readGrade();

    // Shift larger IDs right to keep the array sorted.
    int pos = studentCount;

    while (pos > 0 && students[pos - 1].id > id) 
    {
        students[pos] = students[pos - 1];
        pos--;
    }
    students[pos] = Student(id, name, grade);
    studentCount++;
    saveRecords();
    cout << "Student added successfully.\n";
}

void deleteRecord() 
{
    int id = readPositiveID("Enter ID to delete: ");
    int index = binarySearch(id);
    if (index == -1) 
    {
        cout << "Student not found.\n";
        return;
    }
    for (int i = index; i < studentCount - 1; i++) 
    {
        students[i] = students[i + 1];
    }
    studentCount--;
    saveRecords();
    cout << "Student deleted successfully.\n";
}

void viewRecords() {
    if (studentCount == 0) 
    {
        cout << "No student records available.\n";
        return;
    }
    cout << "\n--- Student Records (Sorted by ID) ---\n";
    for (int i = 0; i < studentCount; i++) 
    {
        // Pointer demonstration: point to the current Student object.
        Student* studentPtr = &students[i];
        studentPtr->display();
    }
}

void searchRecord() 
{
    int id = readPositiveID("Enter ID to search: ");
    int index = binarySearch(id);
    if (index == -1) cout << "Student not found.\n";

    else 
    {
        cout << "Student found: ";
        students[index].display();
    }
}

void showDataSizes() 
{
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of Student: " << sizeof(Student) << " bytes\n";
}

void adminMenu() 
{
    Admin admin("Administrator");
    admin.welcome();
    admin.showPermissions();
    int choice;

    do 
    {
        cout << "\n=== ADMIN MENU ===\n"
             << "1. Add Student\n2. Delete Student\n3. View Students\n"
             << "4. Search Student\n5. Show Data Sizes\n6. Log Out\n";
        while (true) 
        {
            choice = readNumber("Choose an option: ");
            if (choice >= 1 && choice <= 6) break;
            cout << "Invalid option. Please try again.\n";
        }
        switch (choice) 
        {
            case 1: addRecord(); break;
            case 2: deleteRecord(); break;
            case 3: viewRecords(); break;
            case 4: searchRecord(); break;
            case 5: showDataSizes(); break;
            case 6: cout << "Logging out...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 6);
}

void regularMenu() 
{
    User regular("Regular User");
    regular.welcome();
    int choice;
    do 
    {
        cout << "\n=== REGULAR USER MENU ===\n"
             << "1. View Students\n2. Search Student\n3. Show Data Sizes\n4. Log Out\n";
        while (true) 
        {
            choice = readNumber("Choose an option: ");
            if (choice >= 1 && choice <= 4) break;
            cout << "Invalid option. Please try again.\n";
        }

        switch (choice) 
        {
            case 1: viewRecords(); break;
            case 2: searchRecord(); break;
            case 3: showDataSizes(); break;
            case 4: cout << "Logging out...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 4);
}

int main() 
{
    loadRecords();
    int choice;
    do {
        cout << "\n=== STUDENT RECORD MANAGEMENT ===\n"
             << "1. Admin\n2. Regular User\n3. Exit\n";
        while (true) 
        {
            choice = readNumber("Choose an option: ");
            if (choice >= 1 && choice <= 3) break;
            cout << "Invalid option. Please try again.\n";
        }
        switch (choice) 
        {
            case 1: adminMenu(); break;
            case 2: regularMenu(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 3);
    return 0;
}
