#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string holderName;
    string accountType;
    double currentBalance;
    double minimumBalance;

public:
    BankAccount(): minimumBalance(500)
    {};

    BankAccount(int num, string holder, string account): accountNumber(num), holderName(holder), accountType(account), currentBalance(500), minimumBalance(500)
    {};

    ~BankAccount()
    {
        cout<<"Account of Mr. "<<holderName<<" with account no "<<accountNumber<<" is destroyed with a balance BDT "<<currentBalance<<endl;
    };
    void createAccount(int num, string holder, string account)
    {
        accountNumber = num;
        holderName = holder;
        accountType = account;
        currentBalance = minimumBalance;
    }

    void showbalance()
    {
        cout<<currentBalance<<endl;
    }

    void deposit(double green)
    {   
        currentBalance += green;
    }

    void withdrawal(double monee)
    {   
        if(currentBalance - monee < minimumBalance)
        {
            cout<<"Boi read the bank policy!"<<endl;
            return;
        }
        currentBalance -= monee;
    }

    void giveInterest(int r = .03)
    {
        double interest = r * currentBalance;
        interest -= (.1 * interest);

        currentBalance += interest;
    }

    void show()
    {
        cout << "Account Number: " << accountNumber << endl
            << "Account Holder Name: " << holderName << endl 
            << "Account Type: " << accountType << endl
            << "Account Balance: " << currentBalance << endl;
    }

};



int main()
{
    BankAccount sigh(5596, "Sammy", "current");

    sigh.showbalance();
    sigh.deposit(1500);
    sigh.withdrawal(1000);
    sigh.withdrawal(7000);
    sigh.giveInterest();
    sigh.show();

    return 0;
}