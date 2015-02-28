#include "Name.h"
#include <string>

using namespace std;

Name::Name(){
	First = "";
	Last = "";
}
Name::Name(string first, string last){
	First = first;
	Last = last;
}
Name::Name(const Name &obj){
	First = obj.First;
	Last = obj.Last;
}
Name::~Name(){
}
bool Name::operator>(const Name &obj){
	if ((Last + First) > (obj.Last + obj.First))
		return true;
	else
		return false;
}
bool Name::operator>=(const Name &obj){
	if ((Last + First) > (obj.Last + obj.First))
		return true;
	else if ((Last + First) == (obj.Last + obj.First))
		return true;
	else
		return false;
}
bool Name::operator<(const Name &obj){
	if ((Last + First) < (obj.Last + obj.First))
		return true;
	else
		return false;
}
bool Name::operator<=(const Name &obj){
	if ((Last + First) < (obj.Last + obj.First))
		return true;
	else if ((Last + First) == (obj.Last + obj.First))
		return true;
	else
		return false;
}
bool Name::operator==(const Name &obj){
	if ((Last + First) == (obj.Last + obj.First))
		return true;
	else
		return false;
}
void Name::operator=(const Name &obj){
	First = obj.First;
	Last = obj.Last;
}
void Name::SetFirstName(string first){ First = first; }
void Name::SetLastName(string last){ Last = last; }
string Name::GetFirstName(){ return First; }
string Name::GetLastName(){ return Last; }
string Name::GetName(){ return Last + ", " + First; }
