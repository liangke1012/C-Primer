#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    balance += amt;
}

void AcctABC::WithDraw(double amt)
{
    balance -= amt;
}

AcctABC::Formatting AcctABC::setFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::ViewAcct() const
{
    Formatting f = setFormat();
    cout << "Clinet: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

void Brass::WithDraw(double amt)
{
    if (amt < 0) 
        cout << "error amt! \n";
    else if (amt <= Balance())
        AcctABC::WithDraw(amt);
    else 
        cout << "withdraw amount of $" << amt << " exceeds your balance.\n";
}

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
                    : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesbank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    owesbank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = setFormat();
    cout << "Clinet: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "MaxLoan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesbank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::WithDraw(double amt)
{
    Formatting f = setFormat();
    double bal = Balance();

    if (amt < 0) 
        AcctABC::WithDraw(amt);
    else if (amt <= bal + maxLoan - owesbank)
    {
        double advance = amt - bal;
        owesbank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::WithDraw(amt);
    }
    else 
        cout << "Credit limit excedded.\n";
    Restore(f);
}
