#include "ID.h"

ID::ID()
{
    static int currentNumber = 10000000; // Starting ID
    number_ID = currentNumber++; //Current Number Incremented ; Value is held due to Static
    full_ID = "A" + to_string(number_ID);
}
void ID::printID()
{
    cout << full_ID << endl;
}

ostream &operator<<(ostream &os, const ID &id)
{
    os << id.full_ID; // Output the full ID string
    return os;
}