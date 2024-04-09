#include <iostream>
#include "stock00.h"

int main()
{
    Stock cat;
    cat.acquire("smart", 20, 12.5);
    cat.show();
    cat.buy(15, 18.125);
    cat.show();
    cat.sell(400, 20.00);
    cat.show();
    cat.buy(30000, 30.125);
    cat.show();
    cat.sell(30000, 0.125);
    cat.show();
    return 0;
}