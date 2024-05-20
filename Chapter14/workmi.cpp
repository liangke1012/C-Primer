#include <iostream>
#include "workermi.h"
#include <cstring>
const int SIZE = 5;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;

    Worker * lolas[SIZE];

    int i;
    for (i = 0; i < SIZE; i++)
    {
        char choice;
        cout << "enter the employee catagory:\n"
             << "w: waiter  s: singer"
             << "   t:singing waiter   q:quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "please enter a,w,s,t or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w': lolas[i] = new Waiter;
                  break;
        case 's': lolas[i] = new Singer;
                  break;
        case 't': lolas[i] = new SingingWaiter;
                  break;
        }
        cin.get();
        lolas[i]->Set();
    }
    cout << "\nHere is your staff: \n";
    int j;
    for (int j = 0; j < i; j++)
    {
        cout << endl;
        lolas[j]->Show();
    }
    for (int j = 0; j < i; j++)
    {
        delete lolas[i];
    }
    cout << "Bye. \n";
    return 0;
}