#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    string accountNumber;
    double balance;


    Account(string accNumber, double initialBalance)
{
  accountNumber=accNumber;
  balance=initialBalance;
}
~Account()
{cout << "Thank You"<< endl;}

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    double getBalance(){
        return balance;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string accNumber, double initialBalance) : Account(accNumber, initialBalance) {}

    void withdraw(double amount)  {
        if (balance >= amount) {  // Additional fee for savings account
            balance -= (amount + 10.0);
        } else {
                cout << "Insufficient funds." << endl;
        }
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(string accNumber, double initialBalance) : Account(accNumber, initialBalance) {}
};

int main() {
    SavingsAccount s1("12345", 1000.0);
    CurrentAccount c1("67890", 1500.0);
    
    s1.deposit(200.0);
    c1.withdraw(100.0);

      cout << "Savings Account Balance: " << s1.getBalance() << endl;
    cout << "Current Account Balance: " << c1.getBalance() << endl;

    return 0;
}