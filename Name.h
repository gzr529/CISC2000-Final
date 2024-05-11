#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef NAME_H
#define NAME_H

class Name
{
    private:
        string fname;
        string lname;

    public:
        Name();                    // Default Constructor ; Values Set in Name.cpp
        Name(string &currentLine); // Constructor Takes String to get First and Last Name
        void printName();

    // Friend Decleration to OVERLOAD AND OUTPUT
    friend ostream &operator<<(ostream &os, const Name &name);
};

#endif