#include <iostream>
using namespace std;

void n_cheers(char,int);
int main()
{
    int times;
    char ch;

    cout << "enter a character : ";
    cin >> ch;
    while(ch != 'q')
    {
        cout << "enter an integer: ";
        cin >> times;
        n_cheers(ch, times);
        cout << "\nEnter another character or press the q-key to quit: ";
        cin >> ch;
    }
    cout << "the value of times is " << times << endl;
    return 0;
}

void n_cheers(char c, int n)
{
    while(n-- > 0){
        cout << c;
    }
}