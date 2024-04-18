#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "error amt !\n";
    else 
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    format initalStat = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) 
        cout << "error amt! \n";
    else if (amt <= balance)
        balance -= amt;
    else 
        cout << "withdraw amount of $" << amt << " exceeds your balance.\n";
    restore(initalStat, prec); 
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    format initalStat = setFormat();
    precis prec = cout.precision(2);
    cout << "Clinet: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initalStat, prec);
}

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
                    : Brass(s, an, bal)
{
    maxLoan = ml;
    owesbank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
    maxLoan = ml;
    owesbank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    format initalStat = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "MaxLoan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesbank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initalStat, prec);
}

void BrassPlus::Withdraw(double amt)
{
    format initalStat = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();

    if (amt < 0) 
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesbank)
    {
        double advance = amt - bal;
        owesbank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else 
        cout << "Credit limit excedded.\n";
    restore(initalStat, prec); 
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
