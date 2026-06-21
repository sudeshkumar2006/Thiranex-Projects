#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accNo;
    string name;
    float balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;

        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        balance = balance + amount;

        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw()
    {
        float amount;

        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance = balance - amount;
            cout << "Amount Withdrawn Successfully.\n";
        }
    }

    void showBalance()
    {
        cout << "\nAccount Number : " << accNo;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance << endl;
    }

    void saveToFile()
    {
        ofstream file("bank.txt");

        file << accNo << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    void loadFromFile()
    {
        ifstream file("bank.txt");

        if (!file)
        {
            cout << "No Account Found!\n";
            return;
        }

        file >> accNo;
        file.ignore();

        getline(file, name);

        file >> balance;

        file.close();
    }
};

int main()
{
    BankAccount account;

    int choice;

    do
    {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            account.saveToFile();
            break;

        case 2:
            account.loadFromFile();
            account.deposit();
            account.saveToFile();
            break;

        case 3:
            account.loadFromFile();
            account.withdraw();
            account.saveToFile();
            break;

        case 4:
            account.loadFromFile();
            account.showBalance();
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}