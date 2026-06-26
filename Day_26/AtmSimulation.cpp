#include <iostream>
using namespace std;
int main()
{
    int pin;
    int correctPin = 1234;
    cout << "Enter your 4-digit PIN: ";
    cin >> pin;
    int attempts = 3;
    int balance = 5000;
    long long validAccount = 1234567890;

    while (attempts > 0)
    {
        if (pin == correctPin)
        {
            cout << "PIN accepted. Access granted." << endl;
            break;
        }
        attempts--;
        if (attempts > 0)
        {
            cout << "Incorrect PIN. Try again." << endl;
            cout << "Remaining attempts: " << attempts << endl;
            cin >> pin;
        }
        if (attempts == 0)
        {
            cout << "Card Blocked." << endl;
            return 0;
        }
    }
    cout << "Welcome to Main Menu" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. Deposit Cash" << endl;
    cout << "4. Set New PIN" << endl;
    cout << "5. Mini Statement" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Current Balance:" << balance << endl;
        break;
    }
    case 2:
    {
        int withdraw;
        cout << "Enter amount to withdraw: ";
        cin >> withdraw;
        if (withdraw <= 0)
        {
            cout << "Invalid amount. Please enter a positive amount." << endl;
        }
        else if (withdraw > balance)
        {
            cout << "Insufficient Balance." << endl;
        }
        else
        {
            balance -= withdraw;
            cout << "Transaction successful." << endl;
            cout << "Remaining Balance:" << balance << endl;
        }
        break;
    }
    case 3:
    {   
        int deposit;
        cout << "Enter amount to deposit: ";
        cin >> deposit;
        if (deposit <= 0)
        {
            cout << "Invalid amount. Please enter a positive amount." << endl;
        }
        else
        {
            balance += deposit;
            cout << "Transaction successful." << endl;
            cout << "Current Balance:" << balance << endl;
        }
        break;
    case 4:
        int newPin;
        cout << "Enter Account Number: ";
        long long accountNumber;
        cin >> accountNumber;
        if (accountNumber == validAccount)
        {
            cout << "Enter 10 digit mobile number: ";
            long long mobileNumber;
            cin >> mobileNumber;
            if (accountNumber == validAccount && mobileNumber >= 1000000000 && mobileNumber <= 9999999999)
            {
                cout << "Enter otp sent to your mobile number: ";
                int otp;
                cin >> otp;
                int correctOtp = 3456;
                if (otp == correctOtp)
                {
                    cout << "Enter new 4-digit PIN: ";
                    cin >> newPin;
                    correctPin = newPin;
                    cout << "PIN changed successfully." << endl;
                }
                else
                {
                    cout << "Invalid OTP." << endl;
                    cout << "Transaction failed." << endl;
                }
            }

            else
            {
                cout << "Invalid mobile number." << endl;
                cout << "Transaction failed." << endl;
            }
        }
        else
        {
            cout << "Invalid account number." << endl;
            cout << "Transaction failed." << endl;
        }
        break;
    }

case 5:
{

cout << "Mini Statement:" << endl;
cout << "Account Number: " << validAccount << endl;
cout << "Current Balance: " << balance << endl;
break;
}

default:
{
cout << "Exit." << endl;
break;


}
}
}