#include "Cashier.h"
#include "Files.h"

#include <iomanip>
#include <cstdlib>

using namespace std;

const double SALES_TAX = .0841;
const string
	strUnsorted = "unsorted.txt",
	strISBNSorted = "ISBN.txt",
	strTitleSorted = "title.txt",
	strAuthorSorted = "author.txt";

void CashierModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &AuthorFlag){
	string strMainMenu[] = {
		"================================================================================",
		"\t\t\t\tCASHIER MODULE\n",
		"================================================================================",
		"\t1) - Search by ISBN number\n",
		"\t2) - Search by book title\n",
		"\t3) - Search by author's name\n",
		"\t4) - Search by publisher's name\n",
		"\t5) - Complete Transaction\n",
		"\t6) - Exit Module\n"
	};

	while (1)	// Loop repeats forever until the user choose '7' in the module's main menu
	{
			system("cls");
		for (string temp : strMainMenu)	// Display the module's main menu
			cout << temp;
		switch (Choice('1', '6'))
		{
		case '1':
			cout
				<< "================================================================================"
				<< "\t\t\tEnter ISBN number" << endl
				<< "================================================================================";
			cin >> searchISBN;
			while (searchISBN.length != 13 || searchISBN.length != 11)
			{
				cout << "Please make sure that the ISBN number is the correct length." << endl;
				cin >> searchISBN;
			}

			//Insert function for searching for the inventoryItem object and copy the object to temp

			totalPrice = tempItem.getPrice;
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << tempItem.getPrice << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl << endl;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
				purchases.push_back(tempItem);
			}
			else
				break;
			break;
		case '2':
			cout
				<< "================================================================================"
				<< "\t\t\tEnter the book title" << endl
				<< "================================================================================";
			cin.ignore();
			getline(cin, searchTitle);

			//Insert function for searching for the inventoryItem object

			totalPrice = tempItem.getPrice;
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << tempItem.getPrice << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
				purchases.push_back(tempItem);
			}
			else
				break;
			break;
		case '3':
			cout
				<< "================================================================================"
				<< "\t\t\tEnter the author's last name" << endl
				<< "================================================================================";
			cin >> searchAuthorLast;
			cout
				<< "================================================================================"
				<< "\t\t\tEnter the author's first name" << endl
				<< "================================================================================";
			cin >> searchAuthorFirst;

			//Insert function for searching for the inventoryItem object

			totalPrice = tempItem.getPrice;
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << tempItem.getPrice << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
				purchases.push_back(tempItem);
			}
			else
				break;
			break;
		case '4':
			cout
				<< "================================================================================"
				<< "\t\t\tEnter the publisher's name" << endl
				<< "================================================================================";
			cin >> searchPublisher;

			//Insert function for searching for the inventoryItem object

			totalPrice = tempItem.getPrice;
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << tempItem.getPrice << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;
			break;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
				purchases.push_back(tempItem);
			}
			else
				break;
		case '5':
			finalPurchase = CompleteTransaction(purchases);
			cout << setprecision(2);
			cout << "The total cost for the purchases is:" << setw(8) << "$" << finalPurchase << endl;
			break;
		case '6':
			cout
				<< "================================================================================"
				<< "\t\t\tExit Module" << endl
				<< "================================================================================";
			return;
			break;
		}
	}
}
