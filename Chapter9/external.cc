#include <iostream>
using namespace std;

double warming = 0.3;
void update(double ft);
void local();

int main()
{
    cout << "global warming is " << warming << " drgree.\n";
    update(0.1);
    cout << "global warming is " << warming << " drgree.\n";
    local();
    cout << "global warming is " << warming << " drgree.\n";
    return 0;
}