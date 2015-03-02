#include "Files.h"
#include <iostream>
#include <fstream>
using namespace std;


void BinaryRead(string strInFile, InventoryItem *items)
{
	fstream inBinary;
	inBinary.open(strInFile, ios::in | ios::binary);
	if (inBinary.good())
	{
		int iSize;
		inBinary.read(reinterpret_cast<char *>(&iSize), sizeof(iSize));
		cout << "Number of Inventory Items: " << iSize << endl;
		InventoryItem temp;
		items = new InventoryItem[iSize];
		for (int k = 0; k < iSize; k++)
		{
			inBinary.read(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));
		}
		cout << "End of binary read" << endl;

		//	delete reinterpret_cast<char *>(temp);
	}
	else
		cout << "Error opening file" << endl;
	system("pause");
	inBinary.close();
	inBinary.clear();
}
void  BinaryWrite(string strOutFile, InventoryItem *items, int size){
	fstream outFile;
	outFile.open(strOutFile, ios::out | ios::binary);
	if (outFile.good())
	{
		outFile.write(reinterpret_cast<char *>(&size), sizeof(size));
		InventoryItem temp;
		for (int k = 0; k < size; k++)
		{
			outFile.write(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));
		}
		cout << "End of binary write" << endl;
		system("pause");
		//	delete reinterpret_cast<char *>(temp);
	}
	else
		cout << "Error opening file" << endl;
	outFile.close();
	outFile.clear();
}
void TextRead(string strFile, InventoryItem *items){
	fstream inFile;
	inFile.open(strFile, ios::in);
	if (inFile.good())
	{
		int size;
		string temp;
		string ISBN, title, first, last, publisher;
		int year, month, day, quantity;
		double wholesale, price;
		inFile >> size;
		for (int k = 0; k < size && !inFile.eof(); k++)
		{
			inFile >> ISBN;
			getline(inFile, temp, '\'');
			getline(inFile, title, '\'');
			inFile >> last >> first >> publisher >> year >> month >> day >> quantity >> wholesale >> price;
			items[k] = { { ISBN, title, { last, first }, publisher }, { year, month, day }, quantity, wholesale, price };
		}
		//	cout << "End of text read for Inventory Items" << endl;
		//	system("pause");
	}
	else
		cout << "Error opening file" << endl;
	inFile.close();
	inFile.clear();
}
void TextWrite(string strFile, InventoryItem *items, int size){
	fstream outFile;
	outFile.open(strFile, ios::out);
	if (outFile.good())
	{
		outFile << size << endl;
		for (int k = 0; k < size; k++)
		{
			outFile
				<< items[k].getBook().getISBN() << " " << "\'" << items[k].getBook().getTitle() << "\'" << items[k].getBook().getAuthor().GetLastName() << " " << items[k].getBook().getAuthor().GetFirstName() << " " << items[k].getBook().getPublisher() << " "
				<< items[k].getDateAdded().GetYear() << " " << items[k].getDateAdded().GetMonth() << " " << items[k].getDateAdded().GetDay() << " " << items[k].getQuantity() << " " << items[k].getWholesale() << " " << items[k].getPrice() << endl;
			//	cout << k + 1 << ") Book title written: " << items[k].getBook().getTitle() << endl;
		}
		//	cout << "End of text write for Inventory Items" << endl;
		//	system("pause");
	}
	else
		cout << "Error opening file" << endl;
	outFile.close();
	outFile.clear();
}

void TextRead(string strFile, Book *book)
{
	fstream inFile;
	inFile.open(strFile, ios::in);
	if (inFile.good())
	{
		int size;
		char temp;
		string ISBN;
		string title, first, last, publisher;
		inFile >> size;
		for (int index = 0; index < size; index++)
		{
			inFile >> ISBN;
			inFile.get(temp);
			inFile.get(temp);
			getline(inFile, title, '\'');
			getline(inFile, last, ',');
			inFile >> first >> publisher;
			book[index] = { ISBN, title, { last, first }, publisher };
		}
	}
	else
		cout << "Error opening file" << endl;
	inFile.close();
	inFile.clear();
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
	double wholesale[] = { 3, 3.25, 3.5, 3.75, 4, 4.25, 4.5, 4.75, 5, 5.25, 5.5, 5.75, 6 };
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