#include "Book.h"
#include "Date.h"
#include "Name.h"
#include "Database.h"
#include "Files.h"
#include "InventoryItem.h"


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


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