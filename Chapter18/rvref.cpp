#include <iostream>

inline double f(double tf) { return 5.0 * (tf - 32.0)/9.0; };
int main()
{
    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07;
    double && rd2 = 1.8 * tc + 32.0;
    double && rd3 = f(rd2);
    cout << "tc values and address: " << tc << ", " << &tc << endl;
    cout << "rd1 values and address: " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 values and address: " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 values and address: " << rd3 << ", " << &rd3 << endl;
    return 0;
}