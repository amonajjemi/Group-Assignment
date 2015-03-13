#include "InventoryItem.h"
#include "Book.h"
#include "Cashier.h"
#include "Database.h"
#include "Report.h"
#include "Files.h"

#include <iomanip>
#include <cstdlib>

using namespace std;

// Names for various files. The files hold the values in the database, so they can be accessed not only by different parts of the program, but also at different times
// The files should all hold the same information, just sorted in different ways. Having pre sorted files allows for faster data access.
const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

// File flags that are used to let the program know that certain files exist and have up to date values
// Each file has its own corresponding flag
bool
	bUnsortedFlag = false,
	bISBNFlag = false,
	bTitleFlag = false,
	bAuthorFlag = false;

int main()
{

	/*
	// File creator using books.txt file
	unsigned seed = time(0);
	srand(seed);
	Book books[50];
	vector<InventoryItem> vecItemsBook(50);
	TextRead("books.txt", books);
	for (int k = 0; k < 50; k++)	// Assigns values for all objects in the arrItems[] array
		vecItemsBook[k] = { books[k], RandomDate(), Random(1, 100), RandomWholesale(), RandomPrice() };
	TextWrite(strUnsorted, vecItemsBook);	// Write the array of objects into a file
	*/
	string MainMenu[] = {	// String array to hold the main menu
		"================================================================================",
		"\t\t\t\tMAIN MENU\n",
		"================================================================================",
		"\t1) - Cashier module\n",
		"\t2) - Inventory Database Module\n",
		"\t3) - Report Module\n",
		"\t4) - Exit Program\n",
		"\t5) - Help\n"};
	string Help[] = {
		"================================================================================",
		"\t\t\tHelp Menu\n",
		"================================================================================",
		"This program is designed for use in a book store\n",
		"This program manages a database, and can function as a cashier\n",
		"What would you like to know more about?\n",
		"1) - Cashier module\n",
		"2) - Database module\n",
		"3) - Report module\n",
		"4) - Nothing (go back)\n"};
	string CashierHelp[] = { 
		""
	};
	string DatabaseHelp[] = {
		"The database module manages a database file that stores all the information of\n",
		"the current inventory.\n",
		"Each inventory item has the following attributes:\n",
		"ISBN, title, author, publisher, date added, quantity, wholeale cost, retail price",
		"You can search the database, and add, remove, or modify inventory items\n",
		"The database is stored in the file ISBN.txt\n",
		"Do NOT directly modify the database file. Instead, use the database module\n"
		"	to add, remove, or modify items\n"
		"The database file is always sorted by ISBN\n"};
	string ReportHelp[] = {
		""
	};
	while (1)	// Will always loop. The only exit condition is if the user chooses '4' in the main menu
	{
		try
		{
			if (FileFlagTest(strUnsorted))
				bUnsortedFlag = true;
		}
		catch (char *str)
		{
			cout << "ERROR: Database " << str << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		system("cls");
		for (string temp : MainMenu)	// Display the Main Menu
			cout << temp;
		switch (Choice('1', '5'))	// Choice in switch statement corresponds to choice in the menu
		{
		case '1':
			CashierModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);	// Call the cashier module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '2':
			DatabaseModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);	// Call the database module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '3':
			ReportModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);	// Call the report module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '4':		// Exit condition for the Main Menu loop
			return 0;
			break;
		case '5':
			for (string temp : Help)
				cout << temp;
			switch (Choice('1', '4'))
			{
			case '1':
				for (string temp : CashierHelp)
					cout << temp;
				break;
			case '2':
				for (string temp : DatabaseHelp)
					cout << temp;
				break;
			case '3':
				for (string temp : ReportHelp)
					cout << temp;
				break;
			case '4':
				break;
			}
			break;
		}
	};
}