#include <iostream>
#include "mytime3.h"

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time temp;
    
    temp = weeding + waxing;
    cout << "total " << temp << endl;
    temp = waxing * 1.17;
    cout << "waxing * 1.17 " << temp << endl;
    cout << "10.0 * weeding " << 10.0 * weeding << endl;
    return 0;
}