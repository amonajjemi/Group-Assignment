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
		inFile >> size;
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
	char choice1, choice2, choice3;
	string strMainMenu[] = {
		"What would you like to do?\n",
		"1) - Search for an Item\n",
		"2) - Modify an existing item\n",
		"3) - Add a new item\n",
		"4) - Remove an item\n",
		"5) - Exit module\n"};
	string strSubMenu1[] = {	// Menu number corresponds to choice in MainMenu. (1 is for searching for an item)
		"Search for an item\n",
		"1) - Search by ISBN\n",
		"2) - Search by book title\n", 
		"3) - Search by book author\n"};
	string strSubMenu2[] = {	// Menu number corresponds to choice in MainMenu. (2 is for modifying an item)
		"Modify an existing item\n",
		"1) - Modify an item with given ISBN\n",
		"2) - Modify an item with given book title\n",
		"3) - Modify an item with given book author\n"};
	string strFieldMenu[] = {	// Menu used for modifying an item, allowing the user to choose which fields to modify
		"What data field do you wish to modify?\n",
		"1) - ISBN\n",
		"2) - Book Title\n",
		"3) - Book Aathor\n",
		"4) - Book Publisher\n",
		"5) - Date Added \n",
		"6) - Quantity\n",
		"7) - Wholesale Cost\n",
		"8) - Price\n"};
	string strSubMenu4[] = {
		"Remove an item\n",
		"1) - Remove an item with given ISBN\n",
		"2) - Remove an item with given book title\n",
		"3) - Remove an item with given book author\n",	};

	while (1)	// Will always loop. The only exit condition is if the user chooses '5' in the main menu
	{
		for (string temp : strMainMenu)	// Display main menu
			cout << temp;
		switch (Choice('1','5'))
		{
		case '1':	// Search for an item
			do
			{
				for (string temp : strSubMenu1)	// Display sub menu 
					cout << temp;
				int itemIndex = 0;
				switch (Choice('1', '3'))
				{
				case '1':
					// Get user input for ISBN
					// Search array by ISBN, retrieve indexes of found matches
					cout << "Enter ISBN: " << endl;
					break;
				case '2':
					// Get user input for book title
					// Search array by book title, retreive indexes of found matches
					cout << "Enter book title: " << endl;
					break;
				case '3':
					// Get user input for book author
					// Search array by book author, retreive indexes of found matches
					cout << "Enter book author: " << endl;
					break;
				}
				// Display all items found matching search parameters
				cout << "Would you like to search for another item? \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');
			break;
		case '2':	// Modify an existing item
			do
			{
				for (string temp : strSubMenu2)	// Display sub menu
					cout << temp;
				switch (Choice('1', '3'))
				{
				case '1':
					// Get user input for ISBN
					// Search array by ISBN, retrieve indexes of found matches
					cout << "Enter ISBN: " << endl;
					break;
				case '2':
					break;
				case '3':
					break;
				}
				// Display all items found matching search parameters, with numbered options to allow selection
				// Allow user to choose which result to modify
				/*
				for (int count = 0; count < numMatches; index++)
				{
					// 
				}
				*/
				for (string temp : strFieldMenu)
					cout << temp;
				switch (Choice('1', '8'))	// Modify the data members of the choosen inventory item
				{

				}
				cout << "Would you like to modify another item? \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');
			break;
		case '3':	// Add an item
			do
			{

				cout << "Would you like to add another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');
			break;
		case '4':	// Remove an item
			do
			{
				for (string temp : strSubMenu4)	// Display sub menu
					cout << temp;
				switch (Choice('1', '3'))
				{
				case '1':
					// Get user input for ISBN
					// Search array by ISBN, retrieve indexes of found matches
					break;
				case '2':
					// Get user input for book title
					// Search array by book title, retreive indexes of found matches
					break;
				case '3':
					// Get user input for book author
					// Search array by book author, retreive indexes of found matches
					break;
					// Display all items found matching search parameters, with numbered options to allow selection
					// Allow user to choose which result to remove
				}
				cout << "Would you like to remove another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');
			break;
		case '5':	// Exit module
			return;
		}
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
	



	// Assigns values for all objects in the items[] array
	for (int k = 0; k < 50; k++)
		items[k] = { books[k], RandomDate(), Random(1, 100), RandomWholesale(), RandomPrice() };
	// Write the array of objects into a binary file
	outBinary.open(strUnsorted, ios::out | ios::binary);
	BinaryWrite(outBinary, items, 50);
	outBinary.close();
	outBinary.clear();	// End of writing

	// Read the binary file into the dynamic array items2[]
	inBinary.open(strUnsorted, ios::in | ios::binary);
	BinaryRead(inBinary, items2);
	inBinary.close();	// End of reading
	
	// Header formating for output
	cout
		<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
		<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl;


	// Display all values for each object in the array
	cout << endl << endl << "Binary Read:" << endl << endl;
	system("pause");
	for (int k = 0; k < 50; k++)
	{
		cout << left
			<< setw(14) << items2[k].getBook().getISBN() << "\"" << setw(15) << items2[k].getBook().getTitle() << "\"" << setw(12) << items2[k].getBook().getAuthor() << setw(10) << items2[k].getBook().getPublisher() << endl
			<< setw(10) << items2[k].getDateAdded() << setw(8) << items2[k].getQuantity()
			<< setw(8) << items2[k].getWholesale() << setw(6) << items2[k].getPrice() << endl << endl;

	}

	DatabaseMenu(items2, 50);
	return 0;
}