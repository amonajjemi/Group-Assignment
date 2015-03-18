#include "Name.h"
#include <iostream>

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
string Name::GetName(){ return Last + ", " + First; }

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
	// ostream operator for the Name class
	// Gives output in the form of "last name, first name"
	string name = obj.Last + ", " + obj.First;
	os << name;
	return os;
}
istream& operator>>(istream &is, Name &obj){
	// istream operator for the Name class
	// Gets input for Last name and First name
	is >> obj.Last >> obj.First;
	return is;
}
ofstream& operator<<(ofstream &ofs, const Name &obj){
	// ofstream operator for the Name class
	// Gives output in the form of "last name, first name"
	string name = obj.Last + ", " + obj.First;
	ofs << name;
	return ofs;
}
ifstream& operator>>(ifstream &ifs, Name &obj){
	// ifstream operator for the Name class
	// Gets input for Last name and First name
	char temp;
	ifs.get(temp);
	getline(ifs, obj.Last, ',');
	ifs >> obj.First;
	return ifs;
}
fstream& operator<<(fstream &fs, const Name &obj){
	// input fstream operator for the Name class
	// Gives output in the form of "last name, first name"
	string name = obj.Last + ", " + obj.First;
	fs << name;
	return fs;
}
fstream& operator>>(fstream &fs, Name &obj){
	// output fstream operator for the Name class
	// Gets input for Last name and First name
	char temp;
	fs.get(temp);
	getline(fs, obj.Last, ',');
	fs >> obj.First;
	return fs;
}