#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Name.h"

using namespace std;

class Book
{
protected:
	string ISBN;
	string title;
	Name author;
	string publisher;
public:
	Book();
	Book(string eISBN, string eTitle, Name eAuthor, string ePublisher);
	Book(const Book&);
	~Book();

	void setISBN(string);
	void setTitle(string);
	void setAuthor(Name);
	void setPublisher(string);

	string getISBN();
	string getTitle();
	Name getAuthor();
	string getPublisher();

	bool operator==(const Book&);
	void operator=(const Book&);

	friend ofstream& operator<<(ofstream &, const Book&);
	friend ifstream& operator>>(ifstream &, Book&);
	friend fstream& operator<<(fstream &, const Book&);
	friend fstream& operator>>(fstream &, Book&);
};

#endif
