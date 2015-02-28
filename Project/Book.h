#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Name.h"

using namespace std;

class Book
{
private:
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
	string getAuthor();
	string getPublisher();
};

#endif
