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
	if (bUnsortedFlag)		// Tests if the database file is ready for use (if the flag is set to true)
		TextRead(strUnsorted, vecItems);
	else
	{
		cout << "Could not open the database file!" << endl;
		//	system("pause");
		Pause();
		exit(EXIT_FAILURE);
	}

	string strMainMenu[] = {	// Menu for the Main Menu for this module
		"================================================================================",
		"\t\t\t\tDATABASE MODULE\n",
		"================================================================================",
		"\tWhat would you like to do?\n",
		"\t1) - Search for an item\n",
		"\t2) - Modify an existing item\n",
		"\t3) - Add a new item\n",
		"\t4) - Remove an item\n",
		"\t5) - Exit module\n" };
	string strSubMenu1[] = {	// Menu number corresponds to choice in the module's MainMenu. (1 is for searching for an item)
		"================================================================================",
		"\tSearch for an item\n",
		"================================================================================",
		"\t1) - Search by ISBN\n",
		"\t2) - Search by book title\n",
		"\t3) - Search by book author\n",
		"\t4) - Go back\n" };
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
		"\t2) - Go back\n" };
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
		case '1':	// Search for an item. Display all found matches
			do	// Loop iterates the sub menmu until the user chooses not to
			{	// The user can choose to exit the sub menu by either choosing '4' from the menu, or by choosing 'no' after they are prompted on whether to continue the loop
				exitFlag = false;
				vector<int> indexes(0);	// Vector of integers used to store the indexes of all found matches from searching the database vector
				int index;
				string strChoice;
				Name naChoice;
				system("cls");
				for (string temp : strSubMenu1)	// Display sub menu 
					cout << temp;
				switch (Choice('1', '4'))	// Get user input corresponding to options in the sub menu
				{
				case '1':	// Get user input for ISBN, retrieve indexes retreivefound matches
					do
					{	// Input validation for the ISBN. If the ISBN is not the proper length, the user is prompted for input again
						cout << "Enter ISBN: ";
						UserInput(strChoice);	// Use the UserInput() function to get user input for ISBN
						if (strChoice.length() != 13)
							cout << "The ISBN must be 13 digits" << endl;
					} while (strChoice.length() != 13);
					SortISBN(vecItems);		// Sort database vector by ISBN
					index = searchByISBN(vecItems, strChoice);
					if (index >= 0)
						indexes.push_back(index);	// search vector by ISBN, retrieve index of found match (There should be a maximum of one match, as the ISBN is a unique identifier)
					break;
				case '2':	// Get user input for book title, retrieve indexes of found matches
					cout << "Enter title: ";
					getline(cin, strChoice);	// Get user input for title
					cin.clear();
					SortTitle(vecItems);	// Sort database vector by title
					indexes = fuzzySearchByTitle(vecItems, strChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '3':	// Get user input for book author, retrieve indexes of found matches
					cout << "Enter author (Last Name First Name): ";
					UserInput(naChoice);		// Use the UserInput() function to get user input for author's name
					SortAuthor(vecItems);		// Sort datbase vector by author
					indexes = searchByAuthor(vecItems, naChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '4':	// Exit condition for the sub menu
					exitFlag = true;
					break;
				}
				if (exitFlag)	// If exit condition was triggered, exit the loop (exits the current sub menu, returns to the module's main menu)
					break;
				if (indexes.size() < 1)	// If the size of the indexes vector is less than 1, there were no found matches
					cout << "No matches found" << endl;
				else
				{	// If the indexes vector is not empty, display all found matches
					system("cls");
					cout
						<< "================================================================================"
						<< "\t\t\t\tFound Items" << endl
						<< "================================================================================";
					for (int k = 0; k < indexes.size(); k++)	// Iterates through the vector of indexes
					{
						if (k % 10 == 0)	// Allows user to view the results page by page
						{					// It will add a system pause and a new header for every 10th object written to screen
						//	system("pause");
							Pause();
							cout << endl
								<< left << setw(14) << "ISBN" << setw(15) << "Title" << right << setw(12) << "Author" << setw(10) << "Publisher" << endl << left
								<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
								<< "--------------------------------------------------------------------------------";
						}
						DisplayItem(vecItems[indexes[k]]);	// Display the element of vecItems that has the index of indexes[k] 
					}										// (The index of all found matches are stored in indexes, so all found matches will be displayed)
					cout << endl
						<< "================================================================================"
						<< "\t\t\t\tEnd of list" << endl
						<< "================================================================================";
				}
				cout << "Would you like to search for another item? \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');	// Use the YesNo() function get user choice of "yes" or "no". If "no" is choosen, the loop terminates
			break;
		case '2':	// Modify an existing item
			// The user chooses to find items with a given ISBN, book title, or book author
			// All found matches are displayed to the user, and allows the user to choose which found item to modify
			// The user can then choose which data members of the object to modify
			do	// Loop iterates the sub menmu until the user chooses not to
			{	// The user can choose to exit the sub menu by either choosing '4' from the menu, or by choosing 'no' after they are prompted on whether to continue the loop
				vector<int> indexes(0); // Vector of integers used to store the indexes of all found matches from searching the database vector
				// Variables used to set the data type of the UserInput() template
				string strChoice;
				Name naChoice;

				int index;
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu2)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))	// Get user input corresponding to options in the sub menu
				{
				case '1':	// Get user input for ISBN, retrieve indexes of found matches
					do
					{	// Input validation for the ISBN. If the ISBN is not the proper length, the user is prompted for input again
						cout << "Enter ISBN: ";
						UserInput(strChoice);
						if (strChoice.length() != 13)
							cout << "The ISBN must be 13 digits" << endl;
					} while (strChoice.length() != 13);
					SortISBN(vecItems);		// Sort database vector by ISBN
					index = searchByISBN(vecItems, strChoice);
					if (index >= 0)
						indexes.push_back(index);	// search vector by ISBN, retrieve index of found match (There should be a maximum of one match, as the ISBN is a unique identifier)
					break;
				case '2':	// Get user input for book title, retrieve indexes of found matches
					cout << "Enter title: ";
					getline(cin, strChoice);	// Get user input for title
					cin.clear();
					SortTitle(vecItems);	// Sort database vector by title
					indexes = fuzzySearchByTitle(vecItems, strChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '3':	// Get user input for book author, retrieve indexes of found matches
					cout << "Enter author (Last Name First Name): ";
					UserInput(naChoice);		// Get user input for author's name
					SortAuthor(vecItems);		// Sort datbase vector by author
					indexes = searchByAuthor(vecItems, naChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '4':	// Exit condition for the sub menu
					exitFlag = true;
					break;
				}
				if (exitFlag)	// If exit condition was triggered, exit the loop (exits the current sub menu, returns to the module's main menu)
					break;
				if (indexes.size() < 1)	// If the size of the indexes vector is less than 1, there were no found matches
					cout << "No matches found" << endl;
				else
				{	// If the indexes vector is not empty, display all found matches
					int k;
					system("cls");
					cout
						<< "================================================================================"
						<< "\t\t\t\tFound Items" << endl
						<< "================================================================================";
					for (k = 0; k < indexes.size(); k++)	// Iterates through the vector of indexes
					{
						if (k % 10 == 0)		// Allows user to view the results page by page
						{						// It will add a system pause and a new header for every 10th object written to screen
							//	system("pause");
							Pause();
							cout << endl
								<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
								<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
								<< "--------------------------------------------------------------------------------";
						}
						cout << k + 1 << ") ";		// This will ouput all the results of the search, with an incrementing number in front of them
						DisplayItem(vecItems[indexes[k]]);	// The user can use that number to choose which result they wish to delete
					}
					cout << "Choose the number of the item to modify:" << endl;
					// The user chooses a single item to modify. Assign the index of that item to the 'index' variable
					index = indexes[Choice(1, k + 1) - 1];
					do	// Loop iterates until the user chooses to exit (entering value for "no" when prompte dto continue or not)
					{	// The loop allows the user to choose which value of the InventoryItem to modify
						// Variables used to set the data type of the UserInput() template
						string strChoice;
						Name naChoice;
						Date daChoice;
						int iChoice;
						double dChoice;

						system("cls");
						for (string temp : strFieldMenu)	// Display field menu
							cout << temp;					// The field menu allows the user to choose which data members of a chosen Inventory Item to modify
						switch (Choice('1', '8'))	// Get user input corresponding to options in the field menu menu
						{
						case '1':	// Modify ISBN
							do
							{	// Input validation for the ISBN. If the ISBN is not the proper length, the user is prompted for input again
								cout << "Enter ISBN: ";
								UserInput(strChoice); // Use the UserInput() function to get user input for ISBN
								if (strChoice.length() != 13)
									cout << "The ISBN must be 13 digits" << endl;
							} while (strChoice.length() != 13);
							vecItems[index].setISBN(strChoice);
							break;
						case '2':	// Modify Book Title
							cout << "Enter title: ";
							getline(cin, strChoice);	// Get user input for book title
							vecItems[index].setTitle(strChoice);
							break;
						case '3':	// Modify Book author
							cout << "Enter author (Last Name First Name): ";
							UserInput(naChoice);		// Use the UserInput() function to get user input for book author
							vecItems[index].setAuthor(naChoice);
							break;
						case '4':	// Modify Book publisher 
							cout << "Enter publisher: ";
							UserInput(strChoice);		// Use the UserInput() function to get user input for book publisher
							vecItems[index].setPublisher(strChoice);
							break;
						case '5':	// Modify Date added
							cout << "Date added: ";
							UserInput(daChoice);		// Use the UserInput() function to get user input for the date added (the date the inventory item was added to the database)
							vecItems[index].setDateAdded(daChoice);
							break;
						case '6':	// Modify Quantity
							cout << "Enter quantity: ";
							UserInput(iChoice);			// Use the UserInput() function to get user input for the quantity of the inventory item
							vecItems[index].setQuantity(iChoice);
							break;
						case '7':	// Modify Wholesale cost
							cout << "Enter wholesale cost: ";
							UserInput(dChoice);			// Use the UserInput() function to get user input for the wholesale cost of the inventory item
							vecItems[index].setWholesale(dChoice);
							break;
						case '8':	// Modify Price
							cout << "Enter price: ";
							UserInput(dChoice);			// Use the UserInput() function to get user input for the retail price of the inventory item
							vecItems[index].setPrice(dChoice);
							break;
						}
						cout << "Would you like to modify another field? \"n\" for no, \"y\" for yes" << endl;
					} while (tolower(YesNo()) == 'y');	// Use the YesNo() function get user choice of "yes" or "no". If "no" is choosen, the loop terminates
					bUnsortedFlag = false;	// The database vector has been changed, so the database file is no longer up to date
				}
				cout << "Would you like to modify another item? \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');	// Use the YesNo() function get user choice of "yes" or "no". If "no" is choosen, the loop terminates
			break;
		case '3':	// Add an inventory item
			do
			{
				// Variables used to set the data type of the UserInput() template
				string strChoice;
				Name naChoice;
				Date daChoice;
				int iChoice;
				double dChoice;

				InventoryItem newItem;
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu3)
					cout << temp;
				switch (Choice('1', '2'))
				{
				case '1':
					// Input for ISBN
					do
					{
						cout << "Enter ISBN: ";
						UserInput(strChoice);
						if (strChoice.length() != 13)
							cout << "The ISBN must be 13 digits" << endl;
					} while (strChoice.length() != 13);
					newItem.setISBN(strChoice);
					// Input for Book Title
					cout << "Enter title: ";
					getline(cin, strChoice);
					newItem.setTitle(strChoice);
					// Input for Book author
					cout << "Enter author (Last Name First Name): ";
					UserInput(naChoice);
					newItem.setAuthor(naChoice);
					// Input for Book publisher 
					cout << "Enter publisher: ";
					UserInput(strChoice);
					newItem.setPublisher(strChoice);
					// Get current date
					newItem.setDateAdded(CurrentDate());
					// Input for Quantity
					cout << "Enter quantity: ";
					UserInput(iChoice);
					newItem.setQuantity(iChoice);
					// Input for Wholesale cost
					cout << "Enter wholesale cost: ";
					UserInput(dChoice);
					newItem.setWholesale(dChoice);
					// Input for Price
					cout << "Enter price: ";
					UserInput(dChoice);
					newItem.setPrice(dChoice);
					// Add new Inventory Item to the database
					vecItems.push_back(newItem);
					bUnsortedFlag = false;	// The database vector has been changed, so the database file is no longer up to date
					break;
				case '2':	// Exit condition for the sub menu
					exitFlag = true;
					break;
				}
				if (exitFlag)	// If exit condition was triggered, exit the loop (exits the current sub menu, returns to the module's main menu)
					break;
				cout << "Would you like to add another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');	// The loop will exit if the user chooses '2' in the sub menu, or if they choose 'n' when asked if they would like to loop again
			break;
		case '4':	// Remove an item	
			do
			{
				vector<int> indexes(0);
				string strChoice;
				Name naChoice;
				int index, k; // iIndex
				exitFlag = false;
				system("cls");
				for (string temp : strSubMenu4)	// Display sub menu
					cout << temp;
				switch (Choice('1', '4'))
				{
				case '1':	// Get user input for ISBN, retrieve indexes retreivefound matches
					do
					{	// Input validation for the ISBN. If the ISBN is not the proper length, the user is prompted for input again
						cout << "Enter ISBN: ";
						UserInput(strChoice);	// Use the UserInput() function to get user input for ISBN
						if (strChoice.length() != 13)
							cout << "The ISBN must be 13 digits" << endl;
					} while (strChoice.length() != 13);
					SortISBN(vecItems);		// Sort database vector by ISBN
					index = searchByISBN(vecItems, strChoice);
					if (index >= 0)
						indexes.push_back(index);	// search vector by ISBN, retrieve index of found match (There should be a maximum of one match, as the ISBN is a unique identifier)
					break;
				case '2':	// Get user input for book title, retrieve indexes of found matches
					cout << "Enter title: ";
					getline(cin, strChoice);	// Get user input for title
					cin.clear();
					SortTitle(vecItems);	// Sort database vector by title
					indexes = fuzzySearchByTitle(vecItems, strChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '3':	// Get user input for book author, retrieve indexes of found matches
					cout << "Enter author (Last Name First Name): ";
					UserInput(naChoice);		// Use the UserInput() function to get user input for author's name
					SortAuthor(vecItems);		// Sort datbase vector by author
					indexes = searchByAuthor(vecItems, naChoice);		// Search vector by book title, retreive indexes of found matches. Indexes are stored in the indexes vector
					break;
				case '4':	// Exit condition for the sub menu
					exitFlag = true;
					break;
				}
				if (exitFlag)	// If exit condition was triggered, exit the loop (exits the current sub menu, returns to the module's main menu)
					break;
				// Code for deleting a choosen item
				if (indexes.size() < 1)	// If the size of the indexes vector is less than 1, there were no found matches
					cout << "No matches found" << endl;
				else
				{	// If the indexes vector is not empty, display all found matches
					for (k = 0; k < indexes.size(); k++)	// Iterates through the vector of indexes
					{
						if (k % 10 == 0)	// Allows user to view the results page by page
						{					// It will add a system pause and a new header for every 10th object written to screen
							//	system("pause");
							Pause();
							cout << endl
								<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
								<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
								<< "--------------------------------------------------------------------------------";
						}
						cout << k + 1 << ") ";		// This will ouput all the results of the search, with an incrementing number in front of them
						DisplayItem(vecItems[indexes[k]]);	// The user can use that number to choose which result they wish to delete
					}
					if (k > 0)
					{
						cout << "Choose the number of the item to remove:" << endl;
						// The user chooses a single item to modify. Assign the index of that item to the 'index' variable
						index = indexes[Choice(1, k + 1) - 1];
					}
					else
						cout << "No matches found" << endl;
					// Delete items, only if the indexes vector has values in it
					vecItems.erase(vecItems.begin() + index);
					bUnsortedFlag = false;	// The database vector has been changed, so the database file is no longer up to date
				}
				cout << "Would you like to remove another item?  \"n\" for no, \"y\" for yes" << endl;
			} while (tolower(YesNo()) == 'y');	// Use the YesNo() function get user choice of "yes" or "no". If "no" is choosen, the loop terminates.
			break;
		case '5':	// Exit module
			if (bUnsortedFlag == false)
			{
				SortISBN(vecItems);		// Sort the database vector by ISBN
				TextWrite(strUnsorted, vecItems);	// Write the sorted vector to the database file
				bUnsortedFlag = true;		// Set the flag for the database file to true
			}
			return;
		}
	}

}
void ReduceQuantity(vector<InventoryItem> &vecItems, int index)
{
	if (vecItems[index].getQuantity() == 1)
		vecItems.erase(vecItems.begin() + index);
	else
		vecItems[index].setQuantity(vecItems[index].getQuantity() - 1);
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
// Searches for a book according to the title
// Returns a vector with the indexes of all of the exact matches
// Vector will be of size 0 if no matches found
vector<int> searchByTitle(vector<InventoryItem> &items, string title) {
	vector<int> matches;
	int mid, left = 0;
	int right = items.size();
	int oMid;

	while (left < right) {
		mid = left + (right - left) / 2;
		if (title > items[mid].GetTitle()) {
			left = mid + 1;
		}
		else if (title < items[mid].GetTitle()) {
			right = mid;
		}
		else {
			// Atleast one match found
			oMid = mid;
			// Look at following values
			while (title == items[mid].GetTitle())
			{
				matches.push_back(mid);
				mid = mid + 1;
				if (mid >= items.size())
					break;
			}
			// Look at preceding values
			mid = oMid - 1;
			if (mid >= 0) {
				while (title == items[mid].GetTitle())
				{
					matches.push_back(mid);
					mid = mid - 1;
					if (mid < 0)
						break;
				}
			}
			break;
		}
	}
	return matches;
}
// Title search, made fuzzy
// Returns all books whose titles' contain the search term
vector<int> fuzzySearchByTitle(vector<InventoryItem> &items, string title) {
	vector<int> matches;
	for (int i = 0; i < items.size(); i++) {
		if (items[i].GetTitle().find(title) != string::npos) {
			// Some part of the title matched
			matches.push_back(i);
		}
	}
	return matches;
}
// Searches for a book according to the author name
// Returns a vector with the indexes of all of the exact matches
// Vector will be of size 0 if no matches found
vector<int> searchByAuthor(vector<InventoryItem> &items, Name authorName) {
	vector<int> matches;
	int mid, left = 0;
	int right = items.size();
	int oMid;

	while (left < right) {
		mid = left + (right - left) / 2;
		if (authorName > items[mid].GetAuthor()) {
			left = mid + 1;
		}
		else if (authorName < items[mid].GetAuthor()) {
			right = mid;
		}
		else {
			// Atleast one match found
			oMid = mid;
			// Look at following values
			while (authorName == items[mid].GetAuthor())
			{
				matches.push_back(mid);
				mid = mid + 1;
				if (mid >= items.size())
					break;
			}
			// Look at preceding values
			mid = oMid - 1;
			if (mid >= 0) {
				while (authorName == items[mid].GetAuthor())
				{
					matches.push_back(mid);
					mid = mid - 1;
					if (mid < 0)
						break;
				}
			}

			break;
		}
	}
	return matches;
}
/* =======================================================*/