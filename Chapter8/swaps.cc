#include <iostream>

void swapr(int & a, int & b);
void swapp(int * p, int * q);
void swapv(int a, int b);

int main()
{
    using namespace std;
    int a = 300;
    int b = 500;
    cout << "a = " << a;
    cout << " b = " << b << endl;

    cout << "using references to swap:\n";
    swapr(a, b);
    cout << "a = " << a;
    cout << " b = " << b << endl;

    cout << "using pointers to swap:\n";
    swapp(&a, &b);
    cout << "a = " << a;
    cout << " b = " << b << endl;

    cout << "try to use passing by value:\n";
    swapv(a, b);
    cout << "a = " << a;
    cout << " b = " << b << endl;
    return 0;
}

void swapr(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int * p, int * q)
{
    int temp;
    
    temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}