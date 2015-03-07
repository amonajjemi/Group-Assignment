#include "Database.h"
#include "Files.h"

#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>    // std::sort


using namespace std;

const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

void DatabaseModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &bAuthorFlag)
{
	vector<InventoryItem> vecItems(0);
	TextRead(strUnsorted, vecItems);

	//InventoryItem *items = nullptr;		// Pointer that will be used to store the database. When a file is read, it allocates enough memory for an array using this pointer
	//if (FileFlagTest(strUnsorted) == true)	// Tests the strUnsorted file (unsorted.txt), sets the bUnsortedFlag to true if the FileFlagTest returns true, then opens the file and reads the file into the items array
	//{
	//	bUnsortedFlag = true;
	//	TextRead(strUnsorted, items);	// TextRead will open the strUnsorted file, and allocate enough memory to read the whole file into an array assigned to the items pointer
	//}
	//else
	//	bUnsortedFlag = false;

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
	string strFieldMenu[] = {	// Menu used for modifying an item, allowing the user to choose which fields to modify.
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
	string strSubMenu3[] = {	// Menu number corresponds to choice in the module's MainMenu. (2 is for adding an item)
		"================================================================================",
		"\tAdd an item\n",
		"================================================================================",
		"\t1) - Add an item\n",
		"\t2) - Go back\n"};
	string strSubMenu4[] = {	// Menu number corresponds to choice in the module's MainMenu. (4 is for removing an item)
		"================================================================================",
		"\tRemove an item\n",
		"================================================================================",
		"\t1) - Remove an item with given ISBN\n",
		"\t2) - Remove an item with given book title\n",
		"\t3) - Remove an item with given book author\n",
		"\t4) - Go back\n" };
	bool exitFlag;	// This exit flag allows for the user to prematurely exit a loop, letting the user go back to the previous menu
	while (1)	// Will always loop. The only exit condition is if the user chooses '5' in the main menu
	{
		cout << flush;
		//		system("pause");
		system("cls");
		for (string temp : strMainMenu)	// Display main menu
			cout << temp;
		switch (Choice('1', '5'))	// Get user choice corresponding to options in the modules' Main Menu
		{
		case '1':	// Search for an item
			do	// Loop iterates the sub menmu until the user chooses not to
			{	// The user can choose to exit the sub menu by either choosing '4' from the menu, or by choosing 'no' after they are prompted on whether to continue the loop
				exitFlag = false;
				string str;
				system("cls");
				for (string temp : strSubMenu1)	// Display sub menu 
					cout << temp;
				vector<int> indexes(0);
				switch (Choice('1', '4'))	// Get user input corresponding to options in the sub menu
				{
				case '1':
					// Get user input for ISBN
					// Search array by ISBN, retrieve indexes of found matches
					str = InputISBN();
					SortISBN(vecItems);
					indexes.push_back(searchByISBN(vecItems, str));
					break;
				case '2':
					// Get user input for book title
					// Search array by book title, retreive indexes of found matches
					cout << "Enter book title: " << endl;
					str = InputTitle();
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
				cout << endl
					<< "================================================================================"
					<< "\t\t\t\tFoundItems" << endl
					<< "================================================================================";
				for (int k = 0; k < indexes.size(); k++)
				{
					if (k % 10 == 0 || k == 0)	// Allows user to view the results page by page
					{							// It will add a system pause and a new header for every 10th object written to screen
						system("pause");
						cout << endl
							<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
							<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
							<< "--------------------------------------------------------------------------------";
					}
					DisplayItem(vecItems[indexes[k]]);
				}
				cout << endl
					<< "================================================================================"
					<< "\t\t\t\tEnd of list" << endl
					<< "================================================================================";
				// Display all items found matching search parameters
				cout << "Would you like to search for another item? \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');	// The loop will exit if the user chooses '4' in the sub menu, or if they choose 'n' when asked if they would like to loop again
			break;
		case '2':	// Modify an existing item
			do	// Loop iterates the sub menmu until the user chooses not to
			{	// The user can choose to exit the sub menu by either choosing '4' from the menu, or by choosing 'no' after they are prompted on whether to continue the loop
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu2)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))	// Get user input corresponding to options in the sub menu
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
				if (exitFlag == false)	// This statement allows to program to skip this loop if the user chooses '4' in the sub menu
				{						// Choosing '4' in the sub menu exits the sub menu
					do	
					{
						for (string temp : strFieldMenu)	// Display field menu
							cout << temp;
						switch (Choice('1', '8'))	// Get user input corresponding to options in the field menu menu
						{							// The field menu allows the user to choose which data members of a chosen Inventory Item to modify
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
						cout << "Would you like to modify another field? \"n\" for no, \"y\" for yes" << endl;
					} while (tolower(YesNo()) == 'y');
				}
				cout << "Would you like to modify another item? \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');	// The loop will exit if the user chooses '4' in the sub menu, or if they choose 'n' when asked if they would like to loop again
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
			} while (exitFlag == false && tolower(YesNo()) == 'y');	// The loop will exit if the user chooses '2' in the sub menu, or if they choose 'n' when asked if they would like to loop again
			break;
		case '4':	// Remove an item	
			do
			{
				vector<int> indexes(0);
				string str;
				system("cls");
				exitFlag = false;
				for (string temp : strSubMenu4)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))
				{
				case '1':
					// Get user input for ISBN
					// Search array by ISBN, retrieve indexes of found matches
					str = InputISBN();
					SortISBN(vecItems);
					indexes.push_back(searchByISBN(vecItems, str));
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
				for (int k = 0; k < indexes.size(); k++)
					vecItems.erase(vecItems.begin() + indexes[k]);

				// Display all items found matching search parameters, with numbered options to allow selection
				// Allow user to choose which result to remove
				cout << "Would you like to remove another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (exitFlag == false && tolower(YesNo()) == 'y');	// The loop will exit if the user chooses '4' in the sub menu, or if they choose 'n' when asked if they would like to loop again
			break;
		case '5':	// Exit module
			// Should write current arrays to files, update file flags
//			delete[] items;
			TextWrite(strUnsorted, vecItems);
			return;
		}
	}

}


/* ================= Sorting Functions =================*/
// ISBN Sorting functionality
bool compareISBN(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getBook().getISBN() < itemTwo.getBook().getISBN();
}
void SortISBN(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareISBN);
}
void UpdateISBNFile(vector<InventoryItem> &items, bool &bISBNFlag) {
	TextWrite(strISBNSorted, items);
	bISBNFlag = true;
}

// Author Sorting functionality
bool compareAuthor(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getBook().getAuthor() < itemTwo.getBook().getAuthor();
}
void SortAuthor(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareAuthor);
}
void UpdateAuthorFile(vector<InventoryItem> &items, bool &bAuthorFlag) {
	TextWrite(strAuthorSorted, items);
	bAuthorFlag = true;
}

// Title Sorting functionality
bool compareTitle(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getBook().getTitle() < itemTwo.getBook().getTitle();
}
void SortTitle(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareTitle);
}
void UpdateTitleFile(vector<InventoryItem> &items, bool &bTitleFlag) {
	TextWrite(strTitleSorted, items);
	bTitleFlag = true;
}

/* =====================================================*/


/* ================= Searching Functions =================*/
// Searches for a book according to ISBN, returns the index where it is found
// Returns -1 if not found
int searchByISBN(vector<InventoryItem> &items, string ISBN) {
	int mid, left = 0;
	int right = items.size();

	while (left < right) {
		mid = left + (right - left) / 2;
		if (ISBN > items[mid].GetISBN()){
			left = mid + 1;
		}
		else if (ISBN < items[mid].GetISBN()){
			right = mid;
		}
		else {
			return mid;
		}
	}

	// In case the book was not found
	return -1;
}
/* =======================================================*/
