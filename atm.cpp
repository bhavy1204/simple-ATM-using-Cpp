#include <iostream>
#include <stdlib.h>
using namespace std;
class atm
{
private:
    double balance = 0;

public:
    //BALANCE------------------------------------------------------
    void balance1()
    {
        cout<<"-----------------------------------------------------------"<<endl;
        cout << "CURRENT BALANCE IS  : " << balance << endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. Exit" << endl;
    }

    //CREDIT-------------------------------------------------------
    void credit()
    {
        cout << "\n-----------------------------------------------------\n"<< endl;
        float amount;
        cout << "Enter amount to credit : ";
        cin >> amount;
        if (amount > 1000000)
        {
            cout << " Cash overflow... Credit NOT SUCCESS " << endl;
            cout << "Present balance : " << balance<<endl;
        }
        else if (amount<= 0)
        {
            cout << "Insuffiecient amount to be credited.. Credit NOT SUCCESS " << endl;
            cout << "Present balance : " << balance<<endl;
        }
        else
        {
            balance += amount;
            cout<<"Credited successfully . Your current balance is : "<<balance<<endl;
        }
        cout << "\n\n----------------------------------------------------\n"<< endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. Exit" << endl;
    }
    //DEBIT-----------------------------------------------
    void debit()
    {
        cout<<"--------------------------------------------------------------"<<endl;
        float amount;
        cout << "Enter amount to be credit : ";
        cin >> amount;
        if (amount == 0 || amount < 0)
        {
            cout << "Invalid amount debit unsuccessful."<<endl;
            cout << "Present balance : " << balance;
        }else if(amount>balance){
            cout<<"Insufficient balance debit unsuccessful.";
            cout << "Present balance : " << balance;
        }
        else
        {
            balance -= amount;
            cout<<"Debited successfully . Your current balance is : "<<balance<<endl;
        }
        cout << "------------------------------------------------------" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. Exit" << endl;
    }
    void menu()
    {
        int choice;
        cout << "------------------------------------------------------" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. History" << endl;
        cout << "5. Transfer" << endl;
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
            default:
                cout << "INAVLID CHOICE " << endl;
                break;
            }
        } while (choice != 6);
    }
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