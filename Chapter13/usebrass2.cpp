#include <iostream>
#include "brass.h"
#include <string>
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    Brass * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "enter clinet's name: ";
        getline(cin,temp);
        cout << "enter clinet's account number: ";
        cin >> tempnum;
        cout << "enter opening balance: $";
        cin >> tempbal;
        cout << "enter 1 for Brass or 2 for BrassPlus: ";
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else 
        {
            double tmax, trate;
            cout << "enter the overdraft limit: $";
            cin >> tmax;
            cout << "enter the interest rate: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done!\n";
    return 0;
}