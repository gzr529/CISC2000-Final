#ifndef ID_H
#define ID_H

#include <iostream>
#include <string>
using namespace std;

class ID
{
    private:
        int number_ID;
        string full_ID;

    public:
        ID();
        void printID();

    // Friend Decleration to OVERLOAD AND OUTPUT
    friend ostream &operator<<(ostream &os, const ID &id);
};

#endif