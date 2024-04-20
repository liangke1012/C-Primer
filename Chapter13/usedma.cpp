#include <iostream>
#include "dma.h"

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portablely", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Metcator", "Buffalo keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "result of hasDMA copy:\n";
    cout << map2 << endl;
    return 0;
}