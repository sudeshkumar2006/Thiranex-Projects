#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int age;
    string branch;
};

void addStudent()
{
    Student s;

    ofstream file("students.txt", ios::app);

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Branch: ";
    getline(cin, s.branch);

    file << s.rollNo << "|"
         << s.name << "|"
         << s.age << "|"
         << s.branch << endl;

    file.close();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    ifstream file("students.txt");

    string line;

    cout << "\n----- Student Records -----\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchStudent()
{
    ifstream file("students.txt");

    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    string line;

    while (getline(file, line))
    {
        size_t pos = line.find("|");

        int storedRoll = stoi(line.substr(0, pos));

        if (storedRoll == roll)
        {
            cout << "\nStudent Found:\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found!\n";
    }

    file.close();
}

void updateStudent()
{
    ifstream file("students.txt");

    vector<string> records;

    string line;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    cin.ignore();

    while (getline(file, line))
    {
        size_t pos = line.find("|");

        int storedRoll = stoi(line.substr(0, pos));

        if (storedRoll == roll)
        {
            Student s;

            s.rollNo = roll;

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cin.ignore();

            cout << "Enter New Branch: ";
            getline(cin, s.branch);

            string updatedRecord =
                to_string(s.rollNo) + "|" +
                s.name + "|" +
                to_string(s.age) + "|" +
                s.branch;

            records.push_back(updatedRecord);

            found = true;
        }
        else
        {
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("students.txt");

    for (string record : records)
    {
        outFile << record << endl;
    }

    outFile.close();

    if (found)
        cout << "\nRecord Updated Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}

void deleteStudent()
{
    ifstream file("students.txt");

    vector<string> records;

    string line;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    while (getline(file, line))
    {
        size_t pos = line.find("|");

        int storedRoll = stoi(line.substr(0, pos));

        if (storedRoll == roll)
        {
            found = true;
        }
        else
        {
            records.push_back(line);
        }
    }

    file.close();

    ofstream outFile("students.txt");

    for (string record : records)
    {
        outFile << record << endl;
    }

    outFile.close();

    if (found)
        cout << "\nRecord Deleted Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n STUDENT MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}