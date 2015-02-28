#include "Files.h"
#include <iostream>
#include <fstream>
using namespace std;

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