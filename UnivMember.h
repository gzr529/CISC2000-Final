#ifndef UNIVMEMBER_H
#define UNIVMEMBER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Name.h" //To Use Other Classes
#include "ID.h"   //To Use Other Classes
using namespace std;

class UnivMember
{
    private:
        Name univName;   //Using 'Name' Class for Name of UniID
        string univRole; //Fresh New Role to be Implemented
        ID univID;       // Using 'ID' Class for ID Number of UniID

    public:
        UnivMember(const ID& id, const Name& name, const string& role);
        
        // Friend Decleration to OVERLOAD AND OUTPUT
        friend ostream &operator<<(ostream &os, const UnivMember &member);
};

#endif