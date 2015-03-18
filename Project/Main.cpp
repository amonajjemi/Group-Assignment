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
	strISBNSorted = "ISBN.txt";

// File flags that are used to let the program know that certain files exist and have up to date values
// Each file has its own corresponding flag
bool
	bUnsortedFlag = false,
	bISBNFlag = false;

int main()
{

	string MainMenu[] = {	// String array to hold the main menu
		"================================================================================",
		"\t\t\t\tMAIN MENU\n",
		"================================================================================",
		"\t1) - Cashier module\n",
		"\t2) - Inventory Database Module\n",
		"\t3) - Report Module\n",
		"\t4) - Help\n",
		"\t5) - Exit Program\n"};
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
		"4) - Go back to main menu\n"};
	string CashierHelp[] = { 
		"\nThe Cashier Module allows the cashier to search for a book by its ISBN number.\n"
		"It then displays the book's name and cost and asks if it is the book that the\n"
		"customer wants to purchase.\n"
		"Then the module asks if the customer would like to check out, if not, it allows\n"
		"the cashier to search for another book and repeats the process until the\n"
		"customer decides to cash out and then it displays the final total.\n"
	};
	string DatabaseHelp[] = {
		"\nThe database module manages a database file that stores all the information of\n",
		"the current inventory.\n",
		"Each inventory item has the following attributes:\n",
		"ISBN, title, author, publisher, date added, quantity, wholeale cost\n",
		"	and retail price\n",
		"You can search the database, and add, remove, or modify inventory items\n",
		"To add more of an item, modify the inventory item's quantity\n",
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
			if (FileFlagTest(strISBNSorted))
				bISBNFlag = true;
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
			CashierModule(bUnsortedFlag, bISBNFlag);	// Call the cashier module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '2':
			DatabaseModule(bUnsortedFlag, bISBNFlag);	// Call the database module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '3':
			ReportModule(bUnsortedFlag, bISBNFlag);	// Call the report module, passing all the file flags by reference so they can be modified if necessary
			break;
		case '4':		// Exit condition for the Main Menu loop
			while (true)
			{
				bool exitStatus = false;
				system("cls");
				for (string temp : Help)
					cout << temp;
				switch (Choice('1', '4'))
				{
				case '1':
					for (string temp : CashierHelp)
						cout << temp;
					Pause();
					break;
				case '2':
					for (string temp : DatabaseHelp)
						cout << temp;
					Pause();
					break;
				case '3':
					for (string temp : ReportHelp)
						cout << temp;
					Pause();
					break;
				case '4':
					exitStatus = true;
					break;
				}
				if (exitStatus)
					break;
			}
			break;
		case '5':
			return 0;
			break;
		}
	};
}