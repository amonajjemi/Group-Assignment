#ifndef NAME_H
#define NAME_H

#include <string>

using namespace std;

class Name
{
private:
	string First;
	string Last;
public:
	Name();
	Name(string, string);
	Name(const Name&);
	~Name();
	bool operator>(const Name&);
	bool operator>=(const Name&);
	bool operator<(const Name&);
	bool operator<=(const Name&);
	bool operator==(const Name&);
	void operator=(const Name&);
	void SetFirstName(string);
	void SetLastName(string);
	string GetFirstName();
	string GetLastName();
	string GetName();
};

#endif
