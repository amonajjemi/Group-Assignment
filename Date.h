#ifndef DATE_H
#define DATE_H

#include <string>

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
};

#endif DATE_H
