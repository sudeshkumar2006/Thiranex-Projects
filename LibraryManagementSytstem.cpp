#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
public:
    int bookId;
    string title;
    string author;
};

void addBook()
{
    Book b;

    ofstream file("library.txt", ios::app);

    cout << "\nEnter Book ID: ";
    cin >> b.bookId;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    file << b.bookId << "|" << b.title << "|" << b.author << endl;

    file.close();

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    ifstream file("library.txt");

    string line;

    cout << "\n===== BOOK RECORDS =====\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchBook()
{
    ifstream file("library.txt");

    string title;
    string line;
    int found = 0;

    cin.ignore();

    cout << "\nEnter Book Title to Search: ";
    getline(cin, title);

    while (getline(file, line))
    {
        if (line.find(title) != string::npos)
        {
            cout << "\nBook Found:\n";
            cout << line << endl;
            found = 1;
        }
    }

    if (found == 0)
    {
        cout << "\nBook Not Found!\n";
    }

    file.close();
}

void issueBook()
{
    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    cout << "\nBook Issued Successfully!\n";
}

void returnBook()
{
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    cout << "\nBook Returned Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}