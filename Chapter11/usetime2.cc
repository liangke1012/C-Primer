#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time asjusted;

    cout << "total working time: ";
    total = weeding + waxing;
    total.show();
    cout << endl;

    diff = weeding - waxing;
    cout << "diff time: ";
    diff.show();
    cout << endl;

    asjusted = total * 1.5;
    cout << "adjusted work time: ";
    asjusted.show();
    cout << endl;
    return 0;
}