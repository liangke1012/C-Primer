#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planing;
    Time coding(2,40);
    Time fixing(5,55);
    Time Total;

    cout << "planning time: ";
    planing.show();
    cout << endl;

    cout << "coding time: ";
    coding.show();
    cout << endl;

    cout << "fixing time: ";
    fixing.show();
    cout << endl;

    Total = coding + fixing;
    cout << "total time: ";
    Total.show();
    cout << endl;

    Time morefixing(3, 27);
    cout << "more fixing time: ";
    morefixing.show();
    cout << endl;
    Total = morefixing.operator+(Total);
    cout << "morefixing.operator+(Total) = ";
    Total.show();
    cout << endl;
    return 0;
}