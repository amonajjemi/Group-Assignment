#include "Date.h"
#include <string>

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

}
Date::Date(int month, int day, int year){
	if (month > 12)
		month = 12;
	switch (month)
	{
	case 1:
		if (day > 31)
			day = 31;
		break;
	case 2:
		if (day > 28)
			day = 28;
		break;
	case 3:
		if (day > 31)
			day = 31;
		break;
	case 4:
		if (day > 30)
			day = 30;
		break;
	case 5:
		if (day > 31)
			day = 31;
		break;
	case 6:
		if (day > 30)
			day = 30;
		break;
	case 7:
		if (day > 31)
			day = 31;
		break;
	case 8:
		if (day > 31)
			day = 31;
		break;
	case 9:
		if (day > 30)
			day = 30;
		break;
	case 10:
		if (day > 31)
			day = 31;
		break;
	case 11:
		if (day > 30)
			day = 30;
		break;
	case 12:
		if (day > 31)
			day = 31;
		break;
	}
	Day = day;
	Month = month;
	Year = year;

}
Date::~Date(){


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
}
//Setters
void Date::SetDay(int day){ Day = day; }
void Date::SetMonth(int month){ Month = month; }
void Date::SetYear(int year){ Year = year; }
//Getters
int Date::GetDay(){ return Day; }
int Date::GetMonth(){ return Month; }
int Date::GetYear(){ return Year; }
string Date::GetDate(){// Returns the date object as a string, in the format of "year/month/day"
	string str;
	str = to_string(Year) + "/";
	if (to_string(Month).length() == 1)
		str += "0" + to_string(Month) + "/";
	else
		str += to_string(Month) + "/";
	if (to_string(Day).length() == 1)
		str += "0" + to_string(Day);
	else
		str += to_string(Day);
	return str;

}