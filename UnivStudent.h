#include "UnivMember.h"

//Note* Did not Make a Student.cpp file simply due to how small it would be (One Constructer)
class UnivStudent : public UnivMember
{
    private:
        double GPA;

    // Constructor for UnivStudent COMBINES UnivMember with ID, name, and role and sets the GPA.
    public : UnivStudent(const ID &id, const Name &name, const string &role, double gpa): 
    UnivMember(id, name, role), GPA(gpa) {}

    // Friend Decleration to OVERLOAD AND OUTPUT
    friend ostream &operator<<(ostream &os, const UnivStudent &student)
    {
        os << static_cast<const UnivMember &>(student) << student.GPA << " : ";
        return os;
    }
};