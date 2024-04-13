

#include <iostream>
#include <fstream>
#include <sstream>
#include "listtoolshb.h"
#include "MyList.h"


using namespace std;


struct Profile
{
    string fullname;
    string state;
    bool operator==(Profile rhs)
    {
        if (fullname == rhs.fullname) return true; return false;
    }
    bool operator!=(Profile rhs)
    {
        if (fullname != rhs.fullname) return true; return false;
    }
};
ostream& operator<< (ostream& out, Profile& user)
{
    out << user.fullname << "--" << user.state;
    return out;
}

bool searchDeque(MyList<Profile>& pq, Profile& president) {
    for (const auto& profile : pq) {
        if (profile.fullname == president.fullname) {
            president = profile; // Update the president object with the found Profile
            return true;
        }
    }
    return false; // Profile not found
}

int main()
{
    MyList<Profile> pMyList; // create an object of MyList<Profile>

    string line;
    Profile temp;

    //read from the "presidentsWstates.txt" file
    ifstream file("presidentsWstates.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead(temp); //insert the profile object into pMyList
        }
    }

    //testing mylist implemenation
    cout << "Inserting profiles: " << endl;
    Profile newProfile = { "Andrew Eisengruber", "MI" };
    pMyList.insertHead(newProfile);
    pMyList.display(); // display all elements

    cout << "Depleting head: " << pMyList.deleteHead() << endl; //

    Profile searchProfile = { "Abraham Lincoln", "IL" };
    if (pMyList.search(searchProfile)) {
        cout << "Found: " << searchProfile << endl;
    }
    else {
        cout << "Not Found: " << searchProfile << endl;
    }

  
    temp.fullname = "Gerald R. Ford";
    if (searchDeque(pMyList, temp)) {
        cout << "Found: " << temp << endl;
    }
    else {
        cout << "Not found: " << temp << endl;
    }

}
