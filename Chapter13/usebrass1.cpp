#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Hoggy", 382288, 3000.00);

    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing 1000 into the Hoggy account:\n";
    Hoggy.Deposit(1000.00);
    cout << "new balance: $" << Hoggy.Balance() << endl;

    cout << "withdraw $4200 from the Piggy account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Piggy account balance: $" << Piggy.Balance() << endl;
    cout << "withdraw $4200 from the Hoggy account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
    return 0;
}