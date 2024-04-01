#include <iostream>

int main()
{
    using namespace std;
    int num = 5;
    int* p = &num;

    cout << "value of num " << num;
    cout << "; address of num " << &num << endl;

    cout << "value of *p "  << *p;
    cout << "; value of p " << p << endl;
    return 0;
}