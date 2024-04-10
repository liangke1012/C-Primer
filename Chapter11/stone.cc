#include <iostream>
#include "stonewt.h"

using std::cout;
void display(const Stonewt & st, int n);
int main()
{
    Stonewt incog = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "the celebrity weight ";
    incog.show_stn();
    cout << "the detctive weightd ";
    wolfe.show_stn();
    cout << "the pressident weightd ";
    taft.show_lbs();
    incog = 276.8;
    taft = 325;
    cout << "after \n";
    cout << "the celebrity weight ";
    incog.show_stn();
    cout << "the pressident weightd ";
    taft.show_lbs();
    display(taft, 2);
    return 0;
}

void display(const Stonewt & st, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "WOw! ";
        st.show_stn();
    }
}