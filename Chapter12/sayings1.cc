#include <iostream>
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "what's your name?\n>> ";
    cin >> name;

    cout << name << " please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    String sayings[MaxLen];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n') 
        {
            continue;
        }
        if (!cin || temp[0] == '\0')
        {
            break;
        } else {
            sayings[i] = temp;
        }
    }

    int total = i;
    if (total > 0)
    {
        cout << "here are your saying:\n";
        for (i = 0; i < total; i++)
        {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for (i = 0; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
            {
                shortest = i;
            }
            if (sayings[i] < sayings[first])
            {
                first = i;
            }
        }
        cout << "shortest saying:\n" << sayings[shortest] << endl;
        cout << "first saying:\n" << sayings[first] << endl;
        cout << "this program used " << String::HowMany() << " String object; \n";
    } else {
        cout << "no input! \n";
    }
    return 0;
}