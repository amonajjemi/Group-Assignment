#include "Report.h"
#include "Files.h"
#include "Database.h"

#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt";

// Fires up the Report Module
void ReportModule(bool &bUnsortedFlag, bool &bISBNFlag){
	// Array to hold all of the inventory items being used
	vector<InventoryItem> vecItems(0);
	TextRead(strISBNSorted, vecItems);

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
				<< "\t\t\tREPORT MODULE > List of All Books" << endl
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
				<< "\t\t\tREPORT MODULE > Total Wholesale Values" << endl
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
				<< "\t\t\tREPORT MODULE > Total Retail Values" << endl
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
				<< "\t\t\tREPORT MODULE > All Books > Sorted by Quantity" << endl
				<< "================================================================================";
			SortQuantity(vecItems);
			DisplayItems(vecItems);
			break;
		case '5':
			// Display inventory sorted by cost
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tREPORT MODULE > All Books > Sorted by Cost" << endl
				<< "================================================================================";
			SortCost(vecItems);
			DisplayItems(vecItems);
			break;
		case '6':
			// Display inventory sorted by age
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tREPORT MODULE > All Books > Sorted by Age" << endl
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
				<< left << setw(15) << "ISBN" << setw(36) << "Title" << setw(2) << "Author" << endl
				<< setw(15) << "Publisher" << setw(15) << "Date Added" << setw(10) << "Quantity" << setw(11) << "Wholesale" << setw(10) << "Price" << endl
				<< "--------------------------------------------------------------------------------";
		}
		string temp;
		cout << setw(15) << vecItems[k].getBook().getISBN();
		if (vecItems[k].getBook().getTitle().length() > 36 - 3) // Limits the length of the title field, so that the combined length (Title, 2 quotation marks, and a space) doesn't exceed 36 characters (the setw() amount for the title)
		{
			temp = "\"";
			for (int l = 0; l < 36 - 3 - 4; l++)	// Adds as many characters as will fit without overflowing (which is the setw() amount, minus space for the 3 dots, and minus space for two quotation marks and two spaces
				temp += vecItems[k].getBook().getTitle()[l];
			temp += "...\"";	// Adds three dots at the end, to signify that not all of the title is being displayed
		}
		else
			temp = "\"" + vecItems[k].getBook().getTitle() + "\"";
		cout
			<< setw(36) << temp<< setw(20) << vecItems[k].getBook().getAuthor() << endl
			<< setw(15) << vecItems[k].getBook().getPublisher() << setw(15) << vecItems[k].getDateAdded() << setw(10) << vecItems[k].getQuantity() << "$" << setw(10) << fixed << setprecision(2) << vecItems[k].getWholesale() << "$" << setw(9) << vecItems[k].getPrice() << endl << endl;
		/*
		cout << left
			<< setw(14) << vecItems[k].getBook().getISBN() << "\"" << vecItems[k].getBook().getTitle() << "\"; " << vecItems[k].getBook().getAuthor() << "; " << vecItems[k].getBook().getPublisher() << endl
			<< setw(12) << vecItems[k].getDateAdded() << setw(4) << vecItems[k].getQuantity()
			<< setw(6) << fixed << setprecision(2) << vecItems[k].getWholesale() << setw(6) << vecItems[k].getPrice() << endl << endl;
			*/
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