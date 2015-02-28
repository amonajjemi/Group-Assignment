#include "Database.h"
#include "InventoryItem.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

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
		"1) - Search for an Item\n",
		"2) - Modify an existing item\n",
		"3) - Add a new item\n",
		"4) - Remove an item\n",
		"5) - Exit module\n" };
	string strSubMenu1[] = {	// Menu number corresponds to choice in MainMenu. (1 is for searching for an item)
		"Search for an item\n",
		"1) - Search by ISBN\n",
		"2) - Search by book title\n",
		"3) - Search by book author\n" };
	string strSubMenu2[] = {	// Menu number corresponds to choice in MainMenu. (2 is for modifying an item)
		"Modify an existing item\n",
		"1) - Modify an item with given ISBN\n",
		"2) - Modify an item with given book title\n",
		"3) - Modify an item with given book author\n" };
	string strFieldMenu[] = {	// Menu used for modifying an item, allowing the user to choose which fields to modify
		"What data field do you wish to modify?\n",
		"1) - ISBN\n",
		"2) - Book Title\n",
		"3) - Book Aathor\n",
		"4) - Book Publisher\n",
		"5) - Date Added \n",
		"6) - Quantity\n",
		"7) - Wholesale Cost\n",
		"8) - Price\n" };
	string strSubMenu4[] = {
		"Remove an item\n",
		"1) - Remove an item with given ISBN\n",
		"2) - Remove an item with given book title\n",
		"3) - Remove an item with given book author\n", };

	while (1)	// Will always loop. The only exit condition is if the user chooses '5' in the main menu
	{
		cout << flush;
		system("cls");
		for (string temp : strMainMenu)	// Display main menu
			cout << temp;
		switch (Choice('1', '5'))
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
				// Display all items found matching search parameters, with numbered options to allow selection
				// Allow user to choose which result to remove
				cout << "Would you like to remove another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');
			break;
		case '5':	// Exit module
			return;
		}
	}
}