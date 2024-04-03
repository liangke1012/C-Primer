#include <iostream>
char * builder(char c, int n);
int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "enter a character : ";
    cin >> ch;
    cout << "enter an interger: ";
    cin >> times;
    char *ps = builder(ch, times);
    cout << ps << endl;
    delete [] ps;
    ps = builder('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;
    return 0;
}

char * builder(char c, int n)
{
    char * pstr = new char[n + 1];
    pstr[n] = '\0';
    while (n-- > 0){
        pstr[n] = c;
    }
    return pstr;
}