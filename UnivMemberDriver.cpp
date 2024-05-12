#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm> //Googled How to Do To Lower (Use Transform Function)
#include "UnivMember.h"
using namespace std;

int main()
{
    //Initalize Variables

    string currentLine;                 // Current Line we are reading
    vector<UnivMember> uniMemberList;   // A Vector of Members of Class, UnivMemeber
    vector<string> usernameFileVector;  // A Vector to store Usernames to be Compared before Stored in File
    string tempUsername;                // Initalize Temp Username for Comparison Use
    int ProfessorCounter = 0;           // Number of Professors That Must be Skipped Since Professors are Processed Before Students
    int usernameCounter = 0;            // Number of Same Usernamer ; Initalized Now And Used Later

    // START OF PROFESSOR SECTION OF CODE ////////////////////////////////

    ifstream profFile("CSProfNames.txt");

    // Check if file is really open to avoid errors
    if (!profFile.is_open())
    {
        cout << "file is not opened\n";
        exit(0);
    }

    // Will Keep Taking Lines until hits \n or no more Lines
    while (getline(profFile, currentLine))
    {
        Name profName(currentLine); //Calling Default Name Constructor
        ID profID;                  // Calling Default ID Constructor
        UnivMember newProf(profID, profName, "Prof");
        uniMemberList.push_back(newProf);
        ProfessorCounter++;
    }

    profFile.close();

    // ENDS OF PROFESSOR SECTION OF CODE ////////////////////////////////

    // STARTS OF STUDENT SECTION OF CODE ////////////////////////////////

    ifstream studFile("StudentsLastFirst.txt");

    // Check if file is really open to avoid errors
    if (!studFile.is_open())
    {
        cout << "file is not opened\n";
        exit(0);
    }

    while (getline(studFile, currentLine))
    {
        Name studName(currentLine); // Calling Default Name Constructor
        ID studID;                  // Calling Default ID Constructor
        UnivMember newStud(studID, studName, "Student");
        uniMemberList.push_back(newStud);
    }

    // BEGINNING OF MAKING STUDENT USERNAMES //////////////////////////

    // Reset studFile to be Parsed Through Again
    studFile.clear();
    studFile.seekg(0, ios::beg);

    //Open Output File (Use fstream to handle Read AND Write)
    ofstream usernameFileOut("StudentUsernames.txt");

    // Check if file is really open to avoid errors
    if (!usernameFileOut.is_open())
    {
        cout << "file is not opened\n";
        exit(0);
    }


    while (getline(studFile, currentLine))
    {

        // Where Usernames are Made
        int commaPosition = currentLine.find(",");  // Find Comma Position
        int lastPosition = currentLine.length();    // Find Last Letter Position
        string fIntial = currentLine.substr((commaPosition + 1), 1);
        string Lname = currentLine.substr(0, commaPosition);
        string currentUsername = fIntial + Lname;

        // Make Usernames Lowercase (Use Transform Function)
        transform(currentUsername.begin(), currentUsername.end(), currentUsername.begin(), ::tolower);
        
        //Set Temp Username for Comparison
        tempUsername = currentUsername;

        // Reset Counter from Last Run of Dectecting Same Names
        usernameCounter = 0;

        // Check Username Vector To See Match
        // Will Count Amount of Username Matches In Vector
        // Will Add Number to End of Name Accordingly

        for (int i = 0; i < usernameFileVector.size(); i++)
        {
            //Use Temp Username Here to not Effect Real Username
            if (tempUsername == usernameFileVector[i])
            {
                // Add to Num of Same Usernames
                usernameCounter++;

                // To Match Value In Stored Output
                tempUsername = currentUsername;
                tempUsername += to_string(usernameCounter);
            }
        }

        if (usernameCounter != 0)
        {
            currentUsername += to_string(usernameCounter);
        }

        usernameFileVector.push_back(currentUsername);
    }

    //Overload Output To File
    for (int i = 0; i < (usernameFileVector.size()); i++)
    {
        usernameFileOut << usernameFileVector[i] << uniMemberList[i + ProfessorCounter];
    }


    // Programs Old Output

    /*
    for (UnivMember Member : uniMemberList)
    {
        //Member.UnivMember::printMember();
    }
    */

    cout << "Program Output is to File 'StudentUsernames.txt'";

    studFile.close();
    usernameFileOut.close();

    // END OF STUDENT SECTION OF CODE

    return 0;
}