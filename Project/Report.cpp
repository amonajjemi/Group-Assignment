#include "Report.h"
#include "Files.h"
#include "Database.h"

#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

// Fires up the Report Module
void ReportModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &bAuthorFlag){
	// Array to hold all of the inventory items being used
	vector<InventoryItem> vecItems(0);
	TextRead(strUnsorted, vecItems);

	// Holds contents of the main menu
	// To be displayed wherever needed
	string strMainMenu[] = {
		"================================================================================",
		"\t\t\t\tREPORT MODULE\n",
		"================================================================================",
		"\tWhat would you like to view?\n",
		"\t1) - Inventory Listing\n",
		"\t2) - Inventory Wholesale Value\n",
		"\t3) - Inventory Retail Value\n",
		"\t4) - Listing by Quantity\n",
		"\t5) - Listing by Cost\n",
		"\t6) - Listing by Age\n",
		"\t7) - Exit Module\n" };
	while (1)	// Loop repeats forever until the user choose '7' in the module's main menu
	{
		system("cls");
		for (string temp : strMainMenu)	// Display the module's main menu
			cout << temp;
		switch (Choice('1', '7'))
		{
		case '1':
			// Display inventory sorted by ISBN 
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items" << endl
				<< "================================================================================";
			// Sort the items by isbn and display
			SortISBN(vecItems);
			DisplayItems(vecItems);
			break;
		case '2':
			// Display total wholesale value of inventory
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items, with wholesale values" << endl
				<< "================================================================================";
			SortQuantity(vecItems);
			cout << "Total wholesale value of the inventory: $" << getTotalWholesale(vecItems) << endl << endl;
			DisplayWholesale(vecItems);
			break;
		case '3':
			// Display total retail value of inventory
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items, with retail values" << endl
				<< "================================================================================";
			SortQuantity(vecItems);
			cout << "Total retail value of the inventory: $" << getTotalRetail(vecItems) << endl << endl;
			DisplayRetail(vecItems);
			break;
		case '4':
			// Display inventory sorted by quantity
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items, sorted by quantity" << endl
				<< "================================================================================";
			SortQuantity(vecItems);
			DisplayItems(vecItems);
			break;
		case '5':
			// Display inventory sorted by cost
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items, sorted by cost" << endl
				<< "================================================================================";
			SortCost(vecItems);
			DisplayItems(vecItems);
			break;
		case '6':
			// Display inventory sorted by age
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items, sorted by age" << endl
				<< "================================================================================";
			SortAge(vecItems);
			DisplayItems(vecItems);
			break;
		case '7':	// Exit module
			return;
		}
	}
}

// Displays a list of items in the form of a vector passed as a parameter
// Breaks every 10 items for formatting purposes
void DisplayItems(vector<InventoryItem> &vecItems) {
	for (int k = 0; k < vecItems.size(); k++)
	{
		if (k % 10 == 0 || k == 0)	// Allows user to view the results page by page
		{							// It will add a system pause and a new header for every 10th object written to screen
			Pause();
			cout << endl
				<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
				<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
				<< "--------------------------------------------------------------------------------";
		}
		cout << left
			<< setw(14) << vecItems[k].getBook().getISBN() << "\"" << vecItems[k].getBook().getTitle() << "\"; " << vecItems[k].getBook().getAuthor() << "; " << vecItems[k].getBook().getPublisher() << endl
			<< setw(12) << vecItems[k].getDateAdded() << setw(4) << vecItems[k].getQuantity()
			<< setw(6) << fixed << setprecision(2) << vecItems[k].getWholesale() << setw(6) << vecItems[k].getPrice() << endl << endl;
	}
	cout << endl
		<< "================================================================================"
		<< "\t\t\t\tEnd of list" << endl
		<< "================================================================================";

	Pause();
}

// Displays a list of the wholesale value of the vector of books provided
// Breaks every 10 items for formatting purposes
void DisplayWholesale(vector<InventoryItem> &vecItems) {
	for (int k = 0; k < vecItems.size(); k++)
	{
		if (k % 10 == 0 || k == 0)	// Allows user to view the results page by page
		{							// It will add a system pause and a new header for every 10th object written to screen
			Pause();
			cout << endl
				<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Wholesale" << endl
				<< "--------------------------------------------------------------------------------";
		}
		cout << left
			<< setw(14) << vecItems[k].getBook().getISBN() << "\"" << vecItems[k].getBook().getTitle() << "\"; " << vecItems[k].getBook().getAuthor() << "; " << vecItems[k].getWholesale() << endl
			<< endl << endl;
	}
	cout << endl
		<< "================================================================================"
		<< "\t\t\t\tEnd of list" << endl
		<< "================================================================================";

	Pause();
}

// Displays a list of the retail values of the vector of books provided
// Breaks every 10 items for formatting purposes
void DisplayRetail(vector<InventoryItem> &vecItems) {
	for (int k = 0; k < vecItems.size(); k++)
	{
		if (k % 10 == 0 || k == 0)	// Allows user to view the results page by page
		{							// It will add a system pause and a new header for every 10th object written to screen
			Pause();
			cout << endl
				<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Retail Price" << endl
				<< "--------------------------------------------------------------------------------";
		}
		cout << left
			<< setw(14) << vecItems[k].getBook().getISBN() << "\"" << vecItems[k].getBook().getTitle() << "\"; " << vecItems[k].getBook().getAuthor() << "; " << vecItems[k].getPrice() << endl
			<< endl << endl;
	}
	cout << endl
		<< "================================================================================"
		<< "\t\t\t\tEnd of list" << endl
		<< "================================================================================";

	Pause();
}


/* ================= Report/Sorting Functions =================*/
// Quantity Sorting functionality
// Sorts from greatest quantity to least
bool compareQuantity(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getQuantity() > itemTwo.getQuantity();
}
void SortQuantity(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareQuantity);
}

// Sorting by Wholesale Cost functionality
// Greatest cost to least
bool compareCost(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getWholesale() > itemTwo.getWholesale();
}
void SortCost(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareCost);
}

// Sorting by Age functionality
// Oldest to newest books
bool compareAge(InventoryItem &itemOne, InventoryItem &itemTwo) {
	return itemOne.getDateAdded() < itemTwo.getDateAdded();
}
void SortAge(vector<InventoryItem> &items) {
	sort(items.begin(), items.end(), compareAge);
}
/* ============================================================*/

/* ================= Calculation Functions =================*/
// Returns the total wholesale value of the vector of inventory items passed in
double getTotalWholesale(vector<InventoryItem> &items) {
	double total = 0;
	for (int i = 0; i < items.size(); i++) {
		total += items[i].getWholesale() * items[i].getQuantity();
	}
	return total;
}
// Returns the total retail value of the vector of inventory items passed in
double getTotalRetail(vector<InventoryItem> &items) {
	double total = 0;
	for (int i = 0; i < items.size(); i++) {
		total += items[i].getPrice() * items[i].getQuantity();
	}
	return total;
}
/* =========================================================*/