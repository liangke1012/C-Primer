#include "Worker0.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set()
{
    cout << "enter worker's name: ";
    getline(cin, fullname);
    cout << "enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}

void Worker::Show() const
{
    cout << "name: " << fullname << "\n";
    cout << "Employee id: " << id << "\n";
}

void Waiter::Set()
{
    Worker::Set();
    cout << "enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') 
        continue;
}

void Waiter::Show() const
{
    cout << "catrgory: waiter\n";
    Worker::Show();
    cout << "Panache rating: " << panache << "\n";
}

char *Singer::pv[] = {"other", "alto", "contralto", "saprano", "bass",
                      "baritone", "tenor"};
void Singer::Set()
{
    Worker::Set();
    cout << "enter number for singer's voice range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "please enter a value >=0 and " << Vtypes << endl;

    while (cin.get() != '\n')
    {
        continue;
    }
}

void Singer::Show() const
{
    cout << "category: singer\n";
    Worker::Show();
    cout << "Voice range: " << pv[voice] << endl; 
}