#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    Stonewt poping(9, 2.8);
    double p_wt = poping;
    cout << p_wt << " pound \n";
    cout << "conversion to int => ";
    cout << int (poping) << " pound \n";
    return 0;
}