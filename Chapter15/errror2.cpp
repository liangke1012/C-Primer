#include <iostream>
#include <cmath>
#include "exec_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    std::cout << "enter two numbers: ";
    while (std::cin >> x >> y) 
    {
        try {
            z = hmean(x, y);
            std::cout << "harmonic mean of " << x << " and " << y << " is " << z << std::endl;
            std::cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << std::endl;
            std::cout << "enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean & bg)
        {
           bg.mesg();
           cout << "Try again.\n";
           continue;
        }
        catch (bad_gmean & hg)
        {
            cout << hg.mesg();
            cout << "value used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "sorry, you don't get to play any more.\n";
            break;
        }
        
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}