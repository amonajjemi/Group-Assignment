#include "Book.h"
#include <iostream>

using namespace std;

Book::~Book()
{}

Book::Book(const Book &obj)
{
	ISBN = obj.ISBN;
	title = obj.title;
	author = obj.author;
	publisher = obj.publisher;
}

Book::Book()
{
	ISBN = "";
	title = "";
	author = { "", "" };
	publisher = "";
}

Book::Book(string eISBN, string eTitle, Name eAuthor, string ePublisher)
{
	ISBN = eISBN;
	title = eTitle;
	author = eAuthor;
	publisher = ePublisher;
}
void Book::setISBN(string eISBN){ ISBN = eISBN; }
void Book::setTitle(string eTitle){ title = eTitle; }
void Book::setAuthor(Name eAuthor){ author = eAuthor; }
void Book::setPublisher(string ePublisher){ publisher = ePublisher; }
string Book::getISBN(){ return ISBN; }
string Book::getTitle(){ return title; }
Name Book::getAuthor(){ return author; }
string Book::getPublisher(){ return publisher; }

bool Book::operator==(const Book &obj){
	// Equal to operator overload for the Book class
	// Returns true if all the members of the objects are the same, otherwise it returns false
	if (ISBN == obj.ISBN && title == obj.title && author == obj.author && publisher == obj.publisher)
		return true;
	else
		return false;
}
void Book::operator=(const Book &obj){
	// Assignment operator overload for the Book class
	// Copies values from one object to another
	ISBN = obj.ISBN;
	title = obj.title;
	author = obj.author;
	publisher = obj.publisher;
}
ofstream& operator<<(ofstream &ofs, const Book &obj){
	// ofstream operator overload for the Book class
	// Uses Name class ofstream operator for the author member
	// Outputs the values with a single space in between them. The title member will be enclosed in single quotes ('title goes here')
	ofs << obj.ISBN << " '" << obj.title << "' " << obj.author << " " << obj.publisher;
	return ofs;
}
ifstream& operator>>(ifstream &ifs, Book &obj){
	// ifstream operator overload for the Book class
	// Uses the Name class ifstream operator for the author member
	// The values must have a space between them. The title member must be enclosed in single quotes ('title goes here')
	// The values should be on the same line, but it may not be neccesary
	string temp;
	ifs >> obj.ISBN;
	getline(ifs, temp, '\'');		// Gets the line leading up to the first single quote, discards the input to the string variable temp
	getline(ifs, obj.title, '\'');	// Gets the line leading up the the second single quote, assigns the input to obj.title
	ifs >> obj.author >> obj.publisher;
	return ifs;
}
fstream& operator<<(fstream &fs, const Book &obj){
	// output fstream operator overload for the Book class
	// Works the same as the ofstream operator overload
	fs << obj.ISBN << " '" << obj.title << "' " << obj.author << " " << obj.publisher;
	return fs;
}
fstream& operator>>(fstream &fs, Book &obj){
	// input fstream operator overload for the Book class
	// Works the same as the ifstream operator overload
	string temp;
	fs >> obj.ISBN;
	getline(fs, temp, '\'');
	getline(fs, obj.title, '\'');
	fs >> obj.author >> obj.publisher;
	return fs;
}