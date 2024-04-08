#include <iostream>
void oil(int x);

int main()
{
    using namespace std;
    int taxas = 31;
    int year = 2024;
    cout << "in main(), taxas = " << taxas << ", &taxas = ";
    cout << &taxas << endl;
    cout << "in main(), year = " << year << ", &year = ";
    cout << &year << endl;
    oil(taxas);
    cout << "in main(), taxas = " << taxas << ", &taxas = ";
    cout << &taxas << endl;
    cout << "in main(), year = " << year << ", &year = ";
    cout << &year << endl;
    return 0;
}

void oil(int x)
{
    using namespace std;
    int taxas = 5;
    cout << "in oil(), taxas = " << taxas << ", &taxas = ";
    cout << &taxas << endl;
    cout << "in oil(), x = " << x << ", &x = ";
    cout << &x << endl;
    {
        int taxas = 113;
        cout << "in block, taxas = " << taxas << ", &taxas = ";
        cout << &taxas << endl;
        cout << "in block, x = " << x << ", &x = ";
        cout << &x << endl;
    }
    cout << "post-block taxas = " << taxas << ", &taxas = " << &taxas << endl;
}