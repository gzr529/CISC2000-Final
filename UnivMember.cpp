#include "UnivMember.h"

/*
Essentially Taking in MEMBERS OF EACH CLASS
then STORING IT IN THIS "UNIMEMBER" CLASS, 
which is then STORED IN A VECTOR (ALL ENCOMPASSING)
*/

// Initalizer List (before direct intializtion, there would be copies of each member)
UnivMember::UnivMember(const ID& id, const Name& name, const string& role): 
univID(id), 
univName(name), 
univRole(role) 
{}

//Overloading Output
ostream &operator<<(ostream &os, const UnivMember &member)
{
    os << member.univName << " : " << member.univID << " : " << member.univRole << " : ";
    return os;
}
