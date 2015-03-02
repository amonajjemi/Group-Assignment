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
	// Other
	void BoundsChecker();

	//Operator overloads
	bool operator>(const Date&);
	bool operator>=(const Date&);
	bool operator<(const Date&);
	bool operator<=(const Date&);
	bool operator==(const Date&);
	void operator=(const Date&);

	friend ostream& operator<<(ostream &, const Date &);
	friend istream& operator>>(istream &, Date &);
//	friend ofstream& operator<<(ofstream &, const Date &);
//	friend ifstream& operator>>(ifstream &, Date &);

};

#endif DATE_H