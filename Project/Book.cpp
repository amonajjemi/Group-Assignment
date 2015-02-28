#include "Book.h"
//#include "Name.h"
#include <string>
#include <iostream>

using namespace std;

Book::Book()
{
	//MUST FILL IN
	//
	//
	//
}

Book::Book(int eISBN, string eTitle, Name eAuthor, string ePublisher)
{
	ISBN = eISBN;
	title = eTitle;
	author = eAuthor;
	publisher = ePublisher;
}

void Book::setISBN(int eISBN)
{
	ISBN = eISBN;
}

void Book::setTitle(string eTitle)
{
	title = eTitle;
}

void Book::setAuthor(Name eAuthor)
{
	author = eAuthor;
}

void Book::setPublisher(string ePublisher)
{
	publisher = ePublisher;
}

int Book::getISBN()
{
	return ISBN;
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author.GetName();
}

string Book::getPublisher()
{
	return publisher;
}
