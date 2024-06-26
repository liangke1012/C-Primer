#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting setFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void WithDraw(double amt) = 0;
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0;
    virtual ~AcctABC() {}
};

class Brass : public AcctABC
{
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {}
    virtual void WithDraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesbank;
public: 
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void WithDraw(double amt);
    virtual void ViewAcct() const;
    void ResetMax(double m) { maxLoan = m;};
    void ResetRate(double r) { rate = r;};
    void ResetOwes() { owesbank = 0; };
};
#endif