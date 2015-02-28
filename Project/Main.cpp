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
Date RandomDate();
char Choice(char, char);
char YesNo();
void Database();
void DatabaseMenu(InventoryItem, int);


void BinaryRead(fstream &inFile, InventoryItem *items)
{
	int iSize;
	inFile.read(reinterpret_cast<char *>(&iSize), sizeof(iSize));
	cout << "Number of Inventory Items: " << iSize << endl;

	for (int k = 0; k < iSize; k++)
	{
		inFile.read(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));

	}
	cout << "End of binary read" << endl;
	system("pause");
}
void BinaryWrite(fstream &outFile, InventoryItem *items, int size){
	outFile.write(reinterpret_cast<char *>(&size), sizeof(size));
	for (int k = 0; k < size; k++)
	{
		outFile.write(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));
	}

	cout << "End of binary write" << endl;
	system("pause");
}
void TextRead(fstream &inFile, Book *book)
{
//	if (inFile.good())
//	{
		int count, size;
		int ISBN;
		char temp;
		string strISBN;
		string title, first, last, publisher;
	//	char comma;
		inFile >> size;
	//	book = new Book[size];
		for (count = 0; count < size; count++)
		{
			inFile >> strISBN;
			inFile.get(temp);
			inFile.get(temp);
			getline(inFile, title, '\'');
			getline(inFile, last, ',');
			inFile >> first >> publisher;
			book[count].setISBN(strISBN);
			book[count].setTitle(title);
			book[count].setAuthor({ last, first });
			book[count].setPublisher(publisher);
	/*		cout 
				<< "ISBN: " << strISBN << endl
				<< "Title: " << title << endl
				<< "Name: " << last << ", "<< first << endl 
				<< "Publisher: " << publisher << endl;
				*/
		}
//	}
//	else
//		cout << "File error, cannot open file" << endl;
}
int Random(int min, int max)
{	/*
	Function: Generates a random integer value that is between two values
	Parameters:
	min - Minimum value for the random number
	max - Maximum value for the random number
	Returns: A random integer between min and max
	*/
	return (rand() % (max - min + 1)) + min;
}
Date RandomDate()
{	/*
	Function: Generates a Date object with random values (Between Jan 1, 1990 and Dec 31, 2005). Uses the Date object constructor to ensure valid dates
	Parameters:
	None
	Returns: A Date object with random values
	*/
	Date ranDate = { Random(1990, 2005), Random(1, 12), Random(1, 31) };
	return ranDate;
}
double RandomWholesale()
{	/*
	Function: Generates a randomly selected double value
	The design is to generate a random value for a salary from a pool of pre-set values
	Parameters:
	none
	Returns: A randomly selected double value from the salary[] array
	*/
	double wholesale[] = { 3, 3.25, 3.5, 3.75, 4, 4.25, 4.5, 4.75, 5, 5.25, 5.5, 5.75, 6};
	return wholesale[Random(0, sizeof(wholesale) / sizeof(wholesale[0] - 1))];
}
double RandomPrice()
{	/*
	Function: Generates a randomly selected double value
	The design is to generate a random value for a salary from a pool of pre-set values
	Parameters:
	none
	Returns: A randomly selected double value from the salary[] array
	*/
	double price[] = { 6.25, 6.5, 6.75, 7, 7.25, 7.50, 7.75, 8, 8.25, 9.5, 9.75, 10, 10.25, 10.5, 10.75, 11, 11.25, 11.5, 11.75, 12 };
	return price[Random(0, sizeof(price) / sizeof(price[0] - 1))];
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
				<< " Date added: " << items[k].getDateAdded() << " Quantity: " << items[k].getQuantity() << " Wholesale: " << items[k].getWholesale() << " Price: " << items[k].getPrice() << endl;
		}
		break;
	}

}
int main()
{
	string strBooks = "books.txt", strUnsorted = "unsorted.txt";
	bool unsortedFlag = false, ISBNflag = false, authorFlag = false, titleFlag = false;
	fstream inBook, outBinary, inBinary;
	Book books[50];
	InventoryItem items[50];
	InventoryItem *items2 = nullptr;
	items2 = new InventoryItem[50];


	inBook.open(strBooks, ios::in);
	TextRead(inBook, books);
	inBook.close();
	


	
	cout 
		<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
		<< setw(10) << "Date Added" << setw(8) << "Quantity" << setw(8) << "Wholesale" << setw(6) << "Price" << endl;
		
	for (int k = 0; k < 50; k++)
	{
		items[k] = { books[k], RandomDate(), Random(1, 100), RandomWholesale(), RandomPrice() };
		
		cout << left
			<< setw(14) << items[k].getBook().getISBN() << "\"" << setw(15) << items[k].getBook().getTitle() << "\"" << setw(12) << items[k].getBook().getAuthor() << setw(10) << items[k].getBook().getPublisher() << endl
			<< setw(10) << items[k].getDateAdded() << setw(8) << items[k].getQuantity()
			<< setw(8) << items[k].getWholesale() << setw(6) << items[k].getPrice() << endl << endl;
	
	}
	system("pause");
	outBinary.open(strUnsorted, ios::out | ios::binary);
	BinaryWrite(outBinary, items, 50);
	outBinary.close();
	outBinary.clear();

	inBinary.open(strUnsorted, ios::in | ios::binary);
	BinaryRead(inBinary, items2);
	inBinary.close();
	

	cout << endl << endl << "Binary Read:" << endl << endl;
	system("pause");
	for (int k = 0; k < 50; k++)
	{
		cout << left
			<< setw(14) << items2[k].getBook().getISBN() << "\"" << setw(15) << items2[k].getBook().getTitle() << "\"" << setw(12) << items2[k].getBook().getAuthor() << setw(10) << items2[k].getBook().getPublisher() << endl
			<< setw(10) << items2[k].getDateAdded() << setw(8) << items2[k].getQuantity()
			<< setw(8) << "Whole " << items2[k].getWholesale() << setw(6) << " Price " << items2[k].getPrice() << endl << endl;

	}


	return 0;
}