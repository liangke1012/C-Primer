#include <iostream>
void countdown(int n);

int main()
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Count down ... " << n << "n at " << &n << endl;
    if (n > 0) {
        countdown(n - 1);
    }
    cout << n << " : Kaboom!\n";
}

/*
Count down ... 4n at 0x61fe00
Count down ... 3n at 0x61fdd0
Count down ... 2n at 0x61fda0
Count down ... 1n at 0x61fd70
Count down ... 0n at 0x61fd40
0 : Kaboom!
1 : Kaboom!
2 : Kaboom!
3 : Kaboom!
4 : Kaboom!
*/