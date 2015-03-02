#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>
#include <fstream>


using namespace std;


class Name
{
protected:
	string First;
	string Last;
public:
	//Constructors, destructors
	Name();
	Name(string, string);
	Name(const Name &);
	~Name();

	//Setters
	void SetFirstName(string);
	void SetLastName(string);
	//Getters
	string GetFirstName();
	string GetLastName();
	string GetstrName();

	//Operator overloads
	bool operator>(const Name &);
	bool operator>=(const Name &);
	bool operator<(const Name &);
	bool operator<=(const Name &);
	bool operator==(const Name &);
	void operator=(const Name &);

	friend ostream& operator<<(ostream &, const Name &);
	friend istream& operator>>(istream &, Name &);
//	friend ofstream& operator<<(ofstream &, const Name &);
//	friend ifstream& operator>>(ifstream &, Name &);
};

#endif
