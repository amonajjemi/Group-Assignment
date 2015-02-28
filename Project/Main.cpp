#include "Book.h"
#include "Date.h"
#include "Name.h"
#include "InventoryItem.h"


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void BinaryRead(fstream&, InventoryItem*);
void TextRead(fstream&, Book*, int);

void BinaryRead(fstream &inFile, InventoryItem *items)
{
	int iSize;
	inFile.read(reinterpret_cast<char *>(&iSize), sizeof(iSize));
	cout << "Number of Inventory Items: " << iSize;

	items = new InventoryItem[iSize];
	InventoryItem temp;
	for (int k = 0; k < iSize; k++)
	{
		inFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
		items[k] = temp;
	}
}
void TextRead(fstream &inFile, Book *book, int size)
{
	int count;
	int ISBN;
	string title, first, last, publisher;
	Name name;
	for (count = 0; !inFile.eof(); count++)
	{
		inFile >> ISBN >> title >> last >> first >> publisher;
		book->setISBN(ISBN);
		book->setTitle(title);
		book->setAuthor({first, last});
		book->setPublisher(publisher);
	}
}
void DatabaseMenu()
{

}
int main()
{
	Book books[50];
	InventoryItem *itemsPtr;
	fstream inFile;
	inFile.open("unsorted.txt", ios::in | ios::binary);
	BinaryRead(inFile, itemsPtr);
}