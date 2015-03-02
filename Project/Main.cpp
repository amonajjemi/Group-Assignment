#include "Book.h"
#include "Date.h"
#include "Name.h"
#include "Database.h"
#include "Files.h"
#include "InventoryItem.h"


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
	string MainMenu[] = {
		"================================================================================",
		"\t\t\t\tMAIN MENU\n",
		"================================================================================",
		"\t\t1) - Cashier module\n",
		"\t\t2) - Inventory Database Module\n",
		"\t\t3) - Report Module\n",
		"\t\t4) - Exit Program\n" };
	while (1)	// Will always loop. The only exit condition is if the user chooses '4' in the main menu
	{
		system("cls");
		cout << endl << endl;
		for (string temp : MainMenu)
			cout << temp;
		switch (Choice('1', '4'))
		{
		case '1':

			break;
		case '2':
			Database();
			break;
		case '3':
			break;
		case '4':
			return 0;
			break;
		}
	};
}