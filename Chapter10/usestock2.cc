#include <iostream>
#include "stock20.h"

const int STKS = 4;
int main()
{
    using std::cout;
    Stock stocks[STKS] = {
        Stock("smart", 12,20.0),
        Stock("boffo", 200,2.0),
        Stock("Monolithe", 130, 3.25),
        Stock("Fleep", 60, 6.5)
    };
    cout << "Stock holding :\n";
    int st;
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }
    cout << "\nMost valueable holding:\n";
    top->show();
    return 0;
}