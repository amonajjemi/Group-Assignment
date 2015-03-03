#include "Book.h"
//#include "Name.h"
#include <string>
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
	if (ISBN == obj.ISBN && title == obj.title && author == obj.author && publisher == obj.publisher)
		return true;
	else
		return false;
}
void Book::operator=(const Book &obj){
	ISBN = obj.ISBN;
	title = obj.title;
	author = obj.author;
	publisher = obj.publisher;
}