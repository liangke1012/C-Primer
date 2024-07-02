#include <iostream>
using namespace std;

class Useless
{
private:
   int n;
   char * pc;
   static int ct;
   void ShowObject() const;
public:
   Useless();
   explicit Useless(int k);
   Useless(int k, char ch);
   Useless(const Useless & f);
   Useless(Useless && f);
   ~Useless();
   Useless operator+(const Useless & f) const;
   void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called, ct: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "int constructor called, ct: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int , char constructor called, ct: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i] = ch;
    }
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    cout << "copy const constructor called, ct: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
    ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    cout << "move constructor called, ct: " << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "destructor called; ct : " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete[] pc;
}

Useless Useless::operator+(const Useless & f) const
{
    cout << "entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
    {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++)
    {
        temp.pc[i] = f.pc[i - n];
    }
    cout << "temp object:\n";
    cout << "leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "n : " << n;
    cout << " data address: " << (void *) pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0) 
       cout << "object empty";
    else 
       for (int i = 0; i < n; i++)
       {
        cout << pc[i];
       }
    cout << endl;      
}

int main()
{
    Useless one(10, 'x');
    Useless two = one;
    Useless three(20, 'o');
    Useless four(one + three);
    cout << "one: ";
    one.ShowData();
    cout << "two: ";
    two.ShowData();
    cout << "three: ";
    three.ShowData();
    cout << "four: ";
    four.ShowData();
    return 0;
}
