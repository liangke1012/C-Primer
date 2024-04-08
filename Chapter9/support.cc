#include <iostream>
extern double warming;

void updae(double ft);
void local();

using std::cout;
void update(double ft)
{
    extern double warming;
    warming += ft;
    cout << "update warming to " << warming << " degree.\n";
}

void local()
{
    double warming = 0.8;
    cout << "local warming is " << warming << " drgree.\n";
    cout << "but global warming is " << ::warming << " drgree.\n";
}