#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
protected:
	int Day, Month, Year;
public:
	//Constructors, Destructors
	Date();
	Date(const Date&);
	Date(int, int, int);
	~Date();

	//Setters
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	//Getters
	int GetDay();
	int GetMonth();
	int GetYear();
	string GetDate();

	//Operator overloads
	bool operator>(const Date&);
	bool operator>=(const Date&);
	bool operator<(const Date&);
	bool operator<=(const Date&);
	bool operator==(const Date&);
	void operator=(const Date&);

	friend ostream& operator<<(ostream &, const Date &);
	friend istream& operator>>(istream &, Date &);
	friend ofstream& operator<<(ofstream &, const Date &);
	friend ifstream& operator>>(ifstream &, Date &);
	friend fstream& operator<<(fstream &, const Date &);
	friend fstream& operator>>(fstream &, Date &);
	
	// Other
	void BoundsChecker();
	friend Date CurrentDate();
};

#endif DATE_H