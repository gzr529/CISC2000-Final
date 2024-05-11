#include "Name.h"

// Default Constructor
Name::Name()
{
    fname = "First";
    lname = "Last";
};

Name::Name(string &currentLine)
{
    int commaPosition = currentLine.find(',');                   // Find Comma Position
    int lastPosition = currentLine.length();                     // Find Last Letter Position
    lname = currentLine.substr(0, commaPosition);                // From first Letter to Comma
    fname = currentLine.substr(commaPosition + 1, lastPosition); // From Comma to Last Letter
}

void Name::printName()
{
    cout << fname << " " << lname << endl;
}

ostream &operator<<(ostream &os, const Name &name)
{
    os << name.fname << " " << name.lname; // Output the full name
    return os;
}