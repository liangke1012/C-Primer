#include <iostream>
#include "stock00.h"

Stock::Stock()
{
    std::cout << "default constructor\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "constructor using " << co << " calling\n";
    company = co;
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0) {
        std::cout << "shares can't be negative; "
        << company << " shares aet to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "shares can't be negative"
        << "transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "shares can't be negative"
        << "transaction is aborted.\n";
    } else if (num > shares) {
        cout << "you can't sell more than you have! "
        << "transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "company: " << company
              << " shares: " << shares << '\n'
              << " share price: $" << share_val
              << " total worth: $" << total_val << '\n';
}