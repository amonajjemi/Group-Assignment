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

	string MainMenu[] = {	// String array to hold the main menu
		"================================================================================",
		"\t\t\t\tMAIN MENU\n",
		"================================================================================",
		"\t1) - Cashier module\n",
		"\t2) - Inventory Database Module\n",
		"\t3) - Report Module\n",
		"\t4) - Exit Program\n" };
	while (1)	// Will always loop. The only exit condition is if the user chooses '4' in the main menu
	{
		system("cls");
		for (string temp : MainMenu)	// Display the Main Menu
			cout << temp;
		switch (Choice('1', '4'))	// Choice in switch statement corresponds to choice in the menu
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
		}
	};
}