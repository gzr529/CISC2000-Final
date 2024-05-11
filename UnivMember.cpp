#include "UnivMember.h"

/*
Essentially Taking in MEMBERS OF EACH CLASS
then STORING IT IN THIS "UNIMEMBER" CLASS, 
which is then STORED IN A VECTOR (ALL ENCOMPASSING)
*/

UnivMember::UnivMember(const ID& id, const Name& name, const string& role): 
//Initalizer List (before direct intializtion, there would be copies of each member)
univID(id), 
univName(name), 
univRole(role) 
{}

void UnivMember::printMember()
{
    cout << univRole << ": ";
    univName.printName();
    cout << "ID: ";
    univID.printID();
    cout << endl;
}

ostream &operator<<(ostream &os, const UnivMember &member)
{
    os << member.univRole << ": " << member.univName << " - ID: " << member.univID;
    return os;
}
