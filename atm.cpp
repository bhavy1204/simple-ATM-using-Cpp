#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;
class atm
{
private:
    double balance = 0;

public:
//History 
void history(){
    string filename, line;

    // Ask for the filename
    cout << "Enter the file name to view (e.g., 12345.txt): ";
    cin >> filename;

    // Read and display file contents
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file! Ensure the file name is correct." << endl;
    }
}
    //Create account
    void account(){
    string name, contact, filename;
    int accountNumber;

    // Input user details
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your contact information (phone/email): ";
    getline(cin, contact);

    // Generate a random account number
    srand(time(0)); // Seed for randomness
    accountNumber = rand() % 100000 + 1; // Random account number between 1 and 100000

    // Create filename based on account number
    filename = to_string(accountNumber) + ".txt";

    // Write details to the file
    ofstream file(filename);
    if (file.is_open()) {
        file << "Account Number: " << accountNumber << endl;
        file << "Name: " << name << endl;
        file << "Contact: " << contact << endl;
        file.close();
        cout << "Details saved in file: " << filename << endl;
    } else {
        cout << "Error creating file!" << endl;
    }
}
    // BALANCE------------------------------------------------------
    void balance1()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "CURRENT BALANCE IS  : " << balance << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. Exit" << endl;
    }
    // CREDIT-------------------------------------------------------
    void credit()
    {
        cout << "\n-----------------------------------------------------\n"
             << endl;
        float amount;
        cout << "Enter amount to credit : ";
        cin >> amount;
        if (amount > 1000000)
        {
            cout << " Cash overflow... Credit NOT SUCCESS " << endl;
            cout << "Present balance : " << balance << endl;
        }
        else if (amount <= 0)
        {
            cout << "Insuffiecient amount to be credited.. Credit NOT SUCCESS " << endl;
            cout << "Present balance : " << balance << endl;
        }
        else
        {
            balance += amount;
            cout << "Credited successfully . Your current balance is : " << balance << endl;
        }
        cout << "\n\n----------------------------------------------------\n"
             << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "7. Create account " << endl;
        cout << "6. Exit" << endl;
    }
    // DEBIT-----------------------------------------------
    void debit()
    {
        cout << "--------------------------------------------------------------" << endl;
        float amount;
        cout << "Enter amount to be credit : ";
        cin >> amount;
        if (amount == 0 || amount < 0)
        {
            cout << "Invalid amount debit unsuccessful." << endl;
            cout << "Present balance : " << balance;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance debit unsuccessful.";
            cout << "Present balance : " << balance;
        }
        else
        {
            balance -= amount;
            cout << "Debited successfully . Your current balance is : " << balance << endl;
        }
        cout << "------------------------------------------------------" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. Exit" << endl;
    }
    //MENU-----------------------------------------------------------------------
    void menu()
    {
        int choice;
        cout << "------------------------------------------------------" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout<<"7. Create account"<<endl;
        cout << "6. Exit" << endl;
        do
        {
            cout << "Enter >> ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                balance1();
                break;
            case 2:
                credit();
                break;
            case 3:
                debit();
                break;
            case 4:
                cout << "History" << endl;
                break;
            case 5:
                cout << "Transfer" << endl;
                break;
            case 6:
                cout << "THANK YOU FOR BANKING WITH US !" << endl;
                break;
            case 7:
                cout << "Creating account " << endl;
                break;
            default:
                cout << "INAVLID CHOICE " << endl;
                break;
            }
        } while (choice != 6);
    }
    //VALIDATE--------------------------------------------------------------
    bool validate(int a)
    {
        if (a == 1204)
        {
            return true;
        }
        else
        {
            return false;
        };
    }
};

int main()
{
    char choice;
    int pin;
    system("cls");
    atm user;
    cout << "                     Welcome to BANK ATM             " << endl;
    cout << "--------------------------------------------------------------" << endl;

    while (true)
    {
        cout << "Enter Y to continue or N to exit \nEnter >>  ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "Please Enter your 4 digit pin : ";
            cin >> pin;
            if (user.validate(pin))
            {
                user.menu();
            }

            user.validate(pin);
            break;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Thanks for banking with us ! Have a good day " << endl;
            break;
        }
        else
        {
            cout << "  >>Inavlid choice. Please enter your choice aagain!<< " << endl;
        }
    };

    return 0;
}