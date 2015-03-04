#include "Date.h"
#include <iostream>

using namespace std;

//Constructors, Destructors
Date::Date(){
	Day = 1;
	Month = 1;
	Year = 1900;

}
Date::Date(const Date &obj){
	Day = obj.Day;
	Month = obj.Month;
	Year = obj.Year;
	BoundsChecker();
}
Date::Date(int year, int month, int day){
	// Constructor for Date class
	// Prevents invalid values, so there can't be any months beyond 12, or any days beyond what is allowed for the given date
	Day = day;
	Month = month;
	Year = year;
	BoundsChecker();
}
Date::~Date(){

}
//Setters
void Date::SetDay(int day){ Day = day; }
void Date::SetMonth(int month){ Month = month; }
void Date::SetYear(int year){ Year = year; }
//Getters
int Date::GetDay(){ return Day; }
int Date::GetMonth(){ return Month; }
int Date::GetYear(){ return Year; }
string Date::GetDate(){// Returns the date object as a string, in the format of "year-month-day"
	string str;
	str = to_string(Year) + "-";
	if (to_string(Month).length() == 1)
		str += "0" + to_string(Month) + "-";
	else
		str += to_string(Month) + "-";
	if (to_string(Day).length() == 1)
		str += "0" + to_string(Day);
	else
		str += to_string(Day);
	return str;

}
void Date::BoundsChecker(){
	/*
	Function: Bounds checker for the Date class. Prevents invalid values from being stored. Is called for each constructor, and for the assignment operator
	Parameters: 
		None
	Returns: Nothing
	*/
	if (Month > 12)
		Month = 12;
	switch (Month)	// Prevents months from having too many days
	{
	case 1:
		if (Day > 31)
			Day = 31;
		break;
	case 2:
		if (Day > 28)
		{
			Day = 28;
			// Cases to check for leap year
			if (Year % 4 == 0)	// If year is divisble by 4, it IS a leap year
			{
				Day = 29;
				if (Year % 100 == 0) // But if the year is also divisible by 100, it is NOT a leap year
				{
					Day = 28;
					if (Year % 400 == 0) // But if the year is also divisble by 400, it IS a leap year
					{
						Day = 29;
					}
				}
			}
		}

		break;
	case 3:
		if (Day > 31)
			Day = 31;
		break;
	case 4:
		if (Day > 30)
			Day = 30;
		break;
	case 5:
		if (Day > 31)
			Day = 31;
		break;
	case 6:
		if (Day > 30)
			Day = 30;
		break;
	case 7:
		if (Day > 31)
			Day = 31;
		break;
	case 8:
		if (Day > 31)
			Day = 31;
		break;
	case 9:
		if (Day > 30)
			Day = 30;
		break;
	case 10:
		if (Day > 31)
			Day = 31;
		break;
	case 11:
		if (Day > 30)
			Day = 30;
		break;
	case 12:
		if (Day > 31)
			Day = 31;
		break;
	}
}
bool Date::operator>(const Date &obj){
	// Greater than operator for Date class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if (Year > obj.Year)		// If the year is greater, the date is greater
		return true;
	else if (Year < obj.Year)	// If the year is lesser, the date is not greater
		return false;
	else			// equivalent to if (Year == obj.Year) If year is equal, more testing is needed
	{
		if (Month > obj.Month)	// If year is equal, and month is greater, the date is greater
			return true;
		else if (Month < obj.Month)	// If year is equal, and month is lesser, the date is not greater
			return false;
		else		// equivalent toif (Month == obj.Month) If year and month is equal, more testing is needed
		{
			if (Day > obj.Day)	// If year and month is equal, and day is greater, the date is greater
				return true;
			else if (Day < obj.Day)	// If year and month is equal, and day is lesser, the date is not greater
				return false;
			else // equivalent to if (Day == obj.Day) If year and month and day is equal, the date is not greater
				return false;
		}
	}
}
bool Date::operator>=(const Date &obj){
	// Greater than or equal to operator for the Date class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if (Year > obj.Year) // If the year is greater, the date is greater or equal
		return true;
	else if (Year < obj.Year) // If the year is lesser, the date is not greater or equal
		return false;
	else		// equivalent to if (Year == obj.Year) If year is equal, more testing is needed
	{
		if (Month > obj.Month) // If year is equal, and month is greater, the date is greater or equal
			return true;
		else if (Month < obj.Month) // If year is equal, and month is lesser, the date is not greater or equal
			return false;
		else	// equivalent to if (Month == obj.Month) If year and month is equal, more testing is needed
		{
			if (Day > obj.Day) // If year and month is equal, and day is greater, the date is greater or equal
				return true;
			else if (Day < obj.Day) // If year and month is equal, and day is lesser, the date is not greater or equal
				return false;
			else	// equivalent to if (Day == obj.Day) If year and month and day is equal, the date is greater or equal
				return true;
		}
	}
}
bool Date::operator<(const Date &obj){
	// Less than operator for the Date class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if (Year > obj.Year) // If the year is greater, the date is not lesser
		return false;
	else if (Year < obj.Year) // If the year is lesser, the date is lesser
		return true;
	else		// equivalent to if (Year == obj.Year) If year is equal, more testing is needed
	{
		if (Month > obj.Month) // If year is equal, and month is greater, the date is not lesser
			return false;
		else if (Month < obj.Month) // If year is equal, and month is lesser, the date is lesser
			return true;
		else	// equivalent to if (Month == obj.Month) If year and month is equal, more testing is needed
		{
			if (Day > obj.Day) // If year and month is equal, and day is greater, the date is not lesser
				return false;
			else if (Day < obj.Day) // If year and month is equal, and day is lesser, the date is lesser
				return true;
			else	// equivalent to if (Day == obj.Day) If year and month and day is equal, the date is not lesser
				return false;
		}
	}
}
bool Date::operator<=(const Date &obj){
	// Less than or equal to operator for the Date class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if (Year > obj.Year) // If the year is greater, the date is not lesser or equal
		return false;
	else if (Year < obj.Year) // If the year is lesser, the date is lesser or equal
		return true;
	else		// equivalent to if (Year == obj.Year) If year is equal, more testing is needed
	{
		if (Month > obj.Month) // If year is equal, and month is greater, the date is not lesser or equal
			return false;
		else if (Month < obj.Month) // If year is equal, and month is lesser, the date is lesser or equal
			return true;
		else	// equivalent to if (Month == obj.Month) If year and month is equal, more testing is needed
		{
			if (Day > obj.Day) // If year and month is equal, and day is greater, the date is not lesser or equal
				return false;
			else if (Day < obj.Day) // If year and month is equal, and day is lesser, the date is lesser or equal
				return true;
			else // equivalent to if (Day == obj.Day) If year and month and day is equal, the date is lesser or equal
				return true;
		}
	}
}
bool Date::operator==(const Date &obj){
	// Equal to operator for the Date class
	// Compares the left hand side to the right hand side (obj is right hand side)
	if (Year == obj.Year && Month == obj.Month && Day == obj.Day)	// If year, month, and day is equal, the date is equal
		return true;
	else
		return false;
}
void Date::operator=(const Date &obj){
	// Assignment operator for the Date class
	// Assigns the value of the right hand side to the left hand side (obj is right hand side)
	Day = obj.Day;
	Month = obj.Month;
	Year = obj.Year;
	BoundsChecker();
}
ostream& operator<<(ostream &os, const Date &obj){
	// ostream operator overload for the Date class
	// Outputs the date in the format of "year-month-day"
	// If a month or day is a single digit, a '0' is placed in front of it
	string temp;
	temp = to_string(obj.Year) + '-';
	if (to_string(obj.Month).length() == 1)
		temp += '0';
	temp += to_string(obj.Month) + '-';
	if (to_string(obj.Day).length() == 1)
		temp += '0';
	temp += to_string(obj.Day);
	os << temp;
	//os << obj.Year << "-";
	//if (to_string(obj.Month).length() == 1)
	//	os << "0";
	//os << obj.Month << "-";
	//if (to_string(obj.Day).length() == 1)
	//	os << "0";
	//os << obj.Day;
	return os;
}
istream& operator>>(istream &is, Date &obj){
	// ifstream operator overload for the Date class
	// It takes input sequentially as year then month then day
	is >> obj.Year >> obj.Month >> obj.Day;
	return is;
}
ofstream& operator<<(ofstream &ofs, const Date &obj){
	// ofstream operator overload for the Date class
	// Outputs the date in the formate of "year-month-day"
	ofs << obj.Year << "-" << obj.Month << "-" << obj.Day << " ";
	return ofs;
}
ifstream& operator>>(ifstream &ifs, Date &obj){
	// ifstream operator overload for the Date class
	// Takes input in the format of "year-month-day". The individual data members must be seperated by a single dash '-', no spaces.
	// The total date object must be seperated by spaces from other data
	string temp;
	getline(ifs, temp, '-');
	obj.Year = stoi(temp);
	getline(ifs, temp, '-');
	obj.Month = stoi(temp);
	ifs >> obj.Day;
	return ifs;
}
fstream& operator<<(fstream &fs, const Date &obj){
	// output fstream operator overload for the Date class
	// Works the same as the ofstream operator overload
	fs << obj.Year << "-" << obj.Month << "-" << obj.Day << " ";
	return fs;
}
fstream& operator>>(fstream &fs, Date &obj){
	// input fstream operator overload for the Date class
	// Works the same as the ifstream operator overload
	string temp;
	getline(fs, temp, '-');
	obj.Year = stoi(temp);
	getline(fs, temp, '-');
	obj.Month = stoi(temp);
	fs >> obj.Day;
	return fs;
}