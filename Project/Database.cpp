#include "Database.h"
#include "Files.h"

#include <iomanip>
#include <cstdlib>

using namespace std;

const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

void DatabaseModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &AuthorFlag)
{
//	int iSize;
	InventoryItem *items = nullptr;
	TextRead(strUnsorted, items);
		// File creator using books.txt file
	/*
	Book books[50];
	InventoryItem arrItems[50];
	TextRead("books.txt", books);
	for (int k = 0; k < 50; k++)	// Assigns values for all objects in the arrItems[] array
		arrItems[k] = { books[k], RandomDate(), Random(1, 100), RandomWholesale(), RandomPrice() };
	TextWrite(strUnsorted, arrItems, 50);	// Write the array of objects into a file
	*/



//	DatabaseMenu(items, 50);

	string strMainMenu[] = {
		"================================================================================",
		"\t\t\t\tDATABASE MODULE\n",
		"================================================================================",
		"\tWhat would you like to do?\n",
		"\t1) - Search for an Item\n",
		"\t2) - Modify an existing item\n",
		"\t3) - Add a new item\n",
		"\t4) - Remove an item\n",
		"\t5) - Exit module\n"};
	string strSubMenu1[] = {	// Menu number corresponds to choice in the module's MainMenu. (1 is for searching for an item)
		"================================================================================",
		"\tSearch for an item\n",
		"================================================================================",
		"\t1) - Search by ISBN\n",
		"\t2) - Search by book title\n",
		"\t3) - Search by book author\n",
		"\t4) - Go back\n"};
	string strSubMenu2[] = {	// Menu number corresponds to choice in the module's MainMenu. (2 is for modifying an item)
		"================================================================================",
		"\tModify an existing item\n",
		"================================================================================",
		"\t1) - Modify an item with given ISBN\n",
		"\t2) - Modify an item with given book title\n",
		"\t3) - Modify an item with given book author\n",
		"\t4) - Go back\n" };
	string strSubMenu3[] = {	// Menu number corresponds to choice in the module's MainMenu. (2 is for adding an item)
		"================================================================================",
		"\tAdd an item\n",
		"================================================================================",
		"\t1) - Add an item\n",
		"\t2) - Go back\n"};
	string strFieldMenu[] = {	// Menu used for modifying an item, allowing the user to choose which fields to modify
		"================================================================================",
		"\tWhat data field do you wish to modify?\n",
		"================================================================================",
		"\t1) - ISBN\n",
		"\t2) - Book Title\n",
		"\t3) - Book Aathor\n",
		"\t4) - Book Publisher\n",
		"\t5) - Date Added \n",
		"\t6) - Quantity\n",
		"\t7) - Wholesale Cost\n",
		"\t8) - Price\n" };
	string strSubMenu4[] = {	// Menu number corresponds to choice in the module's MainMenu. (4 is for removing an item)
		"================================================================================",
		"\tRemove an item\n",
		"================================================================================",
		"\t1) - Remove an item with given ISBN\n",
		"\t2) - Remove an item with given book title\n",
		"\t3) - Remove an item with given book author\n",
		"\t4) - Go back\n" };
	bool exitFlag;
	while (1)	// Will always loop. The only exit condition is if the user chooses '5' in the main menu
	{
		cout << flush;
		//		system("pause");
		system("cls");
		for (string temp : strMainMenu)	// Display main menu
			cout << temp;
		switch (Choice('1', '5'))
		{
		case '1':	// Search for an item
			do
			{
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu1)	// Display sub menu 
					cout << temp;
				int itemIndex = 0;
				switch (Choice('1', '4'))
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
				case '4':
					exitFlag = true;
					break;
				}
				// Display all items found matching search parameters
				cout << "Would you like to search for another item? \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');
			break;
		case '2':	// Modify an existing item
			do
			{
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu2)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))
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
				case '4':
					exitFlag = true;
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
				if (exitFlag == false)
				{
					for (string temp : strFieldMenu)
						cout << temp;
					switch (Choice('1', '8'))	// Modify the data members of the choosen inventory item
					{
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case '4':
						break;
					case '5':
						break;
					case '6':
						break;
					case '7':
						break;
					case '8':
						break;
					}
				}
				cout << "Would you like to modify another item? \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');
			break;
		case '3':	// Add an item
			system("cls");
			do
			{
				exitFlag = false;
				for (string temp : strSubMenu3)
					cout << temp;
				switch (Choice('1', '2'))
				{
				case '1':
					break;
				case '2':
					exitFlag = true;
					break;
				}
				cout << "Would you like to add another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');
			break;
		case '4':	// Remove an item
			system("cls");
			do
			{
				exitFlag = false;
				for (string temp : strSubMenu4)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))
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
				case '4':
					exitFlag = true;
				}
				// Display all items found matching search parameters, with numbered options to allow selection
				// Allow user to choose which result to remove
				cout << "Would you like to remove another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');
			break;
		case '5':	// Exit module
			// Should write current arrays to files, update file flags
			return;
		}
	}

}
