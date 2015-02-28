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
void BinaryWrite(fstream&, InventoryItem*, int);
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
void BinaryWrite(fstream &outFile, InventoryItem *items, int size){

}
void TextRead(fstream &inFile, Book *book)
{
//	if (inFile.good())
//	{
		int count, size;
		int ISBN;
		string strISBN;
		string title, first, last, publisher;
	//	char comma;
		inFile >> size;
	//	book = new Book[size];
		for (count = 0; count < size; count++)
		{
			inFile >> strISBN;

			inFile >> last >> first >> publisher;
		//	book[count].setISBN(ISBN);
		//	book[count].setTitle(title);
		//	book[count].setAuthor({ last, first });
		//	book[count].setPublisher(publisher);
			cout << "\t ISBN: " << strISBN << "\t Title: " << title << "\t Name" << last << first << "\t publisher" << publisher;
		}
//	}
//	else
//		cout << "File error, cannot open file" << endl;
}
char Choice(char low, char high)
{	/*
	Function: Allows user to input char values between two values, based on ASCII values
	Parameters:
	low - Lowest value char to be used
	high - Highest char value to be used
	Returns: Valid character input (characters between 'low' and 'high' based on ASCII values)
	*/
	char cI;
	do			// Loop runs until valid character input is received (characters between 'low' and 'high')
	{
		cout << "Choice: ";
		cin.get(cI);
		//cin.clear();
		cin.ignore(10000, '\n');
		if (cI < low || cI > high)
			cout << "Invalid choice, try again" << endl;
	} while (cI < low || cI > high);
	return cI;
}
char YesNo()
{	/*
	Function: Allows user to input char values that corresponds to a yes/no decision
	Parameters:
	none
	Returns: Valid character input ('y', 'Y', 'n', or 'N')
	*/
	char cYN;
	do			// Loop runs until valid character input is received ('y', 'Y', 'n', or 'N') 
	{			// Uppercase characters are converted to lowercase solely for testing purposes. The function will still return an uppercase 'Y' or 'N'
		cout << "Y/N: ";
		cin.get(cYN);
		cin.ignore(10000, '\n');
		if (!(tolower(cYN) == 'y' || tolower(cYN) == 'n'))
			cout << "Invalid choice. Choice is either \"y\" for yes, or \"n\" for no" << endl;
	} while (!(tolower(cYN) == 'y' || tolower(cYN) == 'n'));
	return cYN;
}
void Database()
{

}
void DatabaseMenu(InventoryItem *items, int size)
{
	string strMainMenu[] = {
		"What would you like to do?\n",
		"1) - Display currently stored inventory items\n" };
	switch (Choice(1, 1))
	{
	case '1':
		for (int k = 0; k < size; k++)
		{
			cout
				<< "ISBN: " << items[k].getBook().getISBN() << " Title: " << items[k].getBook().getTitle() << " Author: " << items[k].getBook().getAuthor() << " Publisher: " << items[k].getBook().getPublisher()
				<< " Date added: " << items[k].getDateAdded() << " Quantity: " << items[k].getQuantity() << " Wholesale: " << items[k].getWholesale() << " Price: " << items[k].getPrice();
		}
		break;
	}

}
int main()
{
	string strBooks = "books.txt", strItems = "items.txt";
	bool unsortedFlag = false, ISBNflag = false, authorFlag = false, titleFlag = false;
	fstream inBook;
	Book books[50];
	//	InventoryItem *itemsPtr = nullptr;

	//	inFile.open("unsorted.txt", ios::in | ios::binary);
	//	BinaryRead(inFile, itemsPtr);

	inBook.open(strBooks, ios::in);
	TextRead(inBook, books);
	for (int k = 0; k < 50; k++)
	{
		cout << "ISBN: " << books[k].getISBN() << " Title: " << books[k].getTitle() << " Author: " << books[k].getAuthor() << " Publisher: " << books[k].getPublisher() << endl;
	}
	return 0;
}