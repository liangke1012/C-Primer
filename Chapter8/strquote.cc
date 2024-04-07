#include <iostream>
#include <string>

using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);
const string & version3(string & s1, const string & s2);

int main()
{
    string input;
    string copy;
    string result;

    cout << "enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "your string is : " << input << endl;
    result = version1(input, "***");
    cout << "your string is : " << result << endl;
    cout << "your original string : " << input << endl;

    result = version2(input, "###");
    cout << "your string is : " << result << endl;
    cout << "your original string : " << input << endl;

    cout << "resetting string.\n";
    input = copy;
    result = version3(input, "@@@@"); // 编译通过，程序崩溃，试图引用已经释放的内存
    cout << "your string is : " << result << endl;
    cout << "your original string : " << input << endl;

    return 0;
}

string version1(const string & s1, const string & s2)
{
    string tmp;
    tmp = s2 + s1 + s2;
    return tmp;
}

const string & version2(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    return s1;
}

const string & version3(string & s1, const string & s2)
{
    string tmp;
    tmp = s2 + s1 + s2;
    return tmp;
}