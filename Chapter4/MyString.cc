#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owbay";

    cout << "Howdy! i'm" << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ",your name has ";
    cout << strlen(name1) << " letters and store\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "your initial is " << name1[0] << " .\n";
    name2[3] = '\0';
    cout << name2 << endl;
    return 0;
}