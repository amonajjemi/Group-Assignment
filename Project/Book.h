#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Name.h"

using namespace std;

class Book
{
private:
	int ISBN;
	string title;
	Name author;
	string publisher;
public:
	Book();
	Book(int eISBN, string eTitle, Name eAuthor, string ePublisher);
	Book(const Book&);
	~Book();

	void setISBN(int);
	void setTitle(string);
	void setAuthor(Name);
	void setPublisher(string);

	int getISBN();
	string getTitle();
	string getAuthor();
	string getPublisher();
};

#endif
