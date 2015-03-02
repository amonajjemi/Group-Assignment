#include "Name.h"

using namespace std;

Name::Name(){ 
	Last = "";
	First = "";
}
Name::Name(string last, string first){
	Last = last;
	First = first;
}
Name::Name(const Name &obj){
	Last = obj.Last;
	First = obj.First;
}
Name::~Name(){
}

void Name::SetFirstName(string first){ First = first; }
void Name::SetLastName(string last){ Last = last; }
string Name::GetFirstName(){ return First; }
string Name::GetLastName(){ return Last; }
string Name::GetstrName(){ return Last + ", " + First; }

bool Name::operator>(const Name &obj){
	// Greater than operator for the Name class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if ((Last + First) > (obj.Last + obj.First))	// Compares alphabetically starting with last name
		return true;
	else
		return false;
}
bool Name::operator>=(const Name &obj){
	// Greater than or equal to operator for the Name class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if ((Last + First) > (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else if ((Last + First) == (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else
		return false;
}
bool Name::operator<(const Name &obj){
	// Less than operator for the Name class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if ((Last + First) < (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else
		return false;
}
bool Name::operator<=(const Name &obj){
	// Less than or equal to operator for the Name class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if ((Last + First) < (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else if ((Last + First) == (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else
		return false;
}
bool Name::operator==(const Name &obj){
	// Equal to operator for the Name class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if ((Last + First) == (obj.Last + obj.First)) // Compares alphabetically starting with last name
		return true;
	else
		return false;
}
void Name::operator=(const Name &obj){
	// Assignment operator for the Name class
	// Assigns the value of the right hand side to the left hand side (obj is right hand side)
	First = obj.First;
	Last = obj.Last;
}
ostream& operator<<(ostream &os, const Name &obj){
	os << obj.Last << ", " << obj.First;
	return os;
}
istream& operator>>(istream &is, Name &obj){
	is >> obj.Last >> obj.First;
	return is;
}
ofstream& operator<<(ofstream &ofs, const Name &obj){
	ofs << obj.Last << " " << obj.First;
	return ofs;
}
ifstream& operator>>(ifstream &ifs, Name &obj){
	ifs >> obj.Last >> obj.First;
	return ifs;
}
