#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
void display(const string da[], int n);
int main()
{
    string list[SIZE];
    cout << "enter your " << SIZE << "sights:\n";
    for (int i = 0;i < SIZE; i++){
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }
    cout << "your list: \n";
    display(list, SIZE);
    return 0;
}

void display(const string da[], int n)
{
    for (int i = 0;i < SIZE;i++)
    {
        cout << i + 1 << ": " << da[i] << endl;
    }
}