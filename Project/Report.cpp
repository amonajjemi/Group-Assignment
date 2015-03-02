#include "Report.h"
#include "Files.h"

#include <cstdlib>

using namespace std;

void ReportModule(){
	ReportMenu();
}
void ReportMenu(){
	string strMainMenu[] = {
		"================================================================================",
		"\t\t\tREPORT MODULE\n",
		"================================================================================",
		"What would you like to view?\n",
		"1) - Inventory Listing\n",
		"2) - Inventory Wholesale Value\n",
		"3) - Inventory Retail Value\n",
		"4) - Listing by Quantity\n",
		"5) - Listing by Cost\n",
		"6) - Listing by Age\n",
		"7) - Exit Module\n"};
	do
	{
		system("cls");
		for (string temp : strMainMenu)
		{
			if (temp[0] != '=')
				cout << "\t";
			cout << temp;
		}
		switch (Choice('1', '7'))
		{
		case '1':
			// Display inventory sorted by ISBN or title
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
			return;

		}
		cout << "Would you like to view another report?  \"n\" for no, \"y\" for yes" << endl;
	} while (tolower(YesNo()) == 'y');
}