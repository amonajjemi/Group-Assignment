#include "InventoryItem.h"
#include "Book.h"
#include "Cashier.h"
#include "Database.h"
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

bool
	bUnsortedFlag = false,
	bISBNFlag = false,
	bTitleFlag = false,
	bAuthorFlag = false;

int main()
{

	string MainMenu[] = {
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
		for (string temp : MainMenu)
			cout << temp;
		switch (Choice('1', '4'))
		{
		case '1':
			CashierModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);
			break;
		case '2':
			DatabaseModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);
			break;
		case '3':
			ReportModule(bUnsortedFlag, bISBNFlag, bTitleFlag, bAuthorFlag);
			break;
		case '4':
			return 0;
			break;
		}
	};
}