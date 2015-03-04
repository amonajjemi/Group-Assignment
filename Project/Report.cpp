#include "Report.h"
#include "Files.h"

#include <iomanip>
#include <cstdlib>

using namespace std;

const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

void ReportModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &AuthorFlag){
//	ReportMenu();
	InventoryItem *items = nullptr;	// Pointer that will be used to store the database. When a file is read, it allocates enough memory for an array using this pointer
	TextRead(strUnsorted, items);	// TextRead will open the strUnsorted file, and allocate enough memory to read the whole file into an array assigned to the items pointer

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
			// Display inventory sorted by ISBN or title
			system("cls");
			cout
				<< "================================================================================"
				<< "\t\t\tList of all inventory items" << endl
				<< "================================================================================";

			// Display all values for each object in the array
			for (int k = 0; k < 50; k++)
			{
				if (k % 10 == 0 || k == 0)	// Allows user to view the results page by page
				{							// It will add a system pause and a new header for every 10th object written to screen
					system("pause");
					cout << endl
						<< left << setw(14) << "ISBN" << setw(15) << "Title" << setw(12) << "Author" << setw(10) << "Publisher" << endl
						<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
						<< "--------------------------------------------------------------------------------";
				}
				cout << left
					<< setw(14) << items[k].getBook().getISBN() << "\"" << items[k].getBook().getTitle() << "\"; " << items[k].getBook().getAuthor() << "; " << items[k].getBook().getPublisher() << endl
					<< setw(12) << items[k].getDateAdded() << setw(4) << items[k].getQuantity()
					<< setw(6) << fixed << setprecision(2) << items[k].getWholesale() << setw(6) << items[k].getPrice() << endl << endl;
			}
			cout << endl
				<< "================================================================================"
				<< "\t\t\t\tEnd of list" << endl
				<< "================================================================================";
			system("pause");
			break;
		case '2':
			// Display total wholesale value of inventory
			break;
		case '3':
			// Display total retal value of inventory
			break;
		case '4':
			// Display inventory sorted by quanitity
			break;
		case '5':
			// Display inventory sorted by cost
			break;
		case '6':
			// Display inventory sorted by age
			break;
		case '7':	// Exit module
			delete[] items;
			return;
		}
	}
}
