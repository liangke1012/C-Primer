#include <iostream>
#include "stock00.h"

int main()
{
    using std::cout;
    Stock stock1("nanosmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("boffo", 2, 2.0);
    stock2.show();

    stock2 = stock1;
    cout << "listing stock1 ans stock2: \n";
    stock1.show();
    stock2.show();

    stock1 = Stock("Nifty", 10, 50.0);
    stock1.show();
    cout << "Done!\n";
    return 0;
}