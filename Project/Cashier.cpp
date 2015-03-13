#include "Cashier.h"
#include "Files.h"
#include "Database.h"

#include <iomanip>
#include <cstdlib>

using namespace std;

const double SALES_TAX = .0841;
const string
strUnsorted = "unsorted.txt",
strISBNSorted = "ISBN.txt",
strTitleSorted = "title.txt",
strAuthorSorted = "author.txt";

double SalesTax(double taxRate, double &itemPrice) //Calculate the tax cost and return it. Also return the total price by reference.
{
	double taxCost;

	taxCost = itemPrice * taxRate;
	itemPrice += taxCost;

	return taxCost;
}

double CompleteTransaction(vector<InventoryItem> &transaction, vector<int> &indexes)
{
	double totalCost = 0;
	for (int i = 0; i < indexes.size(); i++)
	{
		totalCost += transaction[indexes[i]].getPrice(); //Addup total transaction price
		transaction.erase(transaction.begin() + indexes[i]); //Remove item from database
	}
	totalCost *= (1 + SALES_TAX);
	return totalCost;
}

void CashierModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &AuthorFlag)
{
	vector<InventoryItem> vecItems(0);
	TextRead(strUnsorted, vecItems);
	SortISBN(vecItems);// Sort the items by isbn

	vector<int> index(0);
	int itemIndex;
	string searchISBN;
	/*searchTitle,
	searchAuthorLast,
	searchAuthorFirst,
	searchPublisher;*/
	double totalPrice,
		taxCost,
		finalPurchase;
	char confirmPurchase;
	bool finish = false;

	string strMainMenu[] = {
		"================================================================================",
		"\t\t\t\tCASHIER MODULE\n",
		"================================================================================",
		"\t1) - Search by ISBN number\n",
		//"\t2) - Search by book title\n",
		//"\t3) - Search by author's name\n",
		//"\t4) - Search by publisher's name\n",
		//"\t5) - Complete Transaction\n",
		"\t2) - Exit Module\n"
	};

	while (!finish)	// Loop repeats forever until the user choose '2' in the module's main menu or completes a transaction.
	{
		system("cls");
		for (string temp : strMainMenu)	// Display the module's main menu
			cout << temp;
		switch (Choice('1', '2'))
		{
		case '1':
			SortISBN(vecItems);
			cout
				<< "================================================================================"
				<< "\t\t\tEnter ISBN number" << endl
				<< "================================================================================";
			cin >> searchISBN;
			cin.ignore();
			while (searchISBN.length() != 13)
			{
				cout << "Please make sure that the ISBN number is the correct length." << endl;
				cin >> searchISBN;
				cin.ignore();
			}
			itemIndex = searchByISBN(vecItems, searchISBN);
			if (itemIndex == -1)
			{
				cout << "The item is not in the inventory." << endl;
				system("pause");
				break;
			}
			else
			{
				totalPrice = vecItems[itemIndex].getPrice();
				taxCost = SalesTax(SALES_TAX, totalPrice);

				cout << fixed << setprecision(2);
				cout << left << setw(40) << vecItems[itemIndex].GetTitle() << endl;
				cout << left << setw(40) << "The price of the item is:" << "$" << vecItems[itemIndex].getPrice() << endl;
				cout << left << setw(40) << "The cost of tax is:" << "$" << taxCost << endl;
				cout << left << setw(40) << "The total cost of the item is:" << "$" << totalPrice << endl << endl;

				cout << "Is this the book that you would like to purchase?" << endl;
				cout << "Enter 'Y' or 'y' for yes." << endl;
				cin >> confirmPurchase;
				cin.ignore();
				if (confirmPurchase == 'y' || confirmPurchase == 'Y') //Confirmation to purchase the book
				{
					index.push_back(itemIndex);
				}
				else
					break;

				cout << "Would you like to check out?" << endl;
				cout << "Enter 'Y' or 'y' for yes." << endl;
				cin >> confirmPurchase;
				cin.ignore();
				if (confirmPurchase == 'y' || confirmPurchase == 'Y') //Determine whether to checkout and pay for the books
				{
					finish = true;
					system("cls");
					cout << "Your final total is:" << endl;
					finalPurchase = CompleteTransaction(vecItems, index);
					cout << "$" << finalPurchase << endl;
					system("pause");
				}
			}
			break;
			/*case '2':
			cout
			<< "================================================================================"
			<< "\t\t\tEnter the book title" << endl
			<< "================================================================================";
			cin.ignore();
			getline(cin, searchTitle);

			//Insert function for searching for the inventoryItem object

			totalPrice = vecItems[itemIndex].getPrice();
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << vecItems[itemIndex].getPrice() << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
			purchases.push_back(vecItems[itemIndex]);
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

			totalPrice = vecItems[itemIndex].getPrice();
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << vecItems[itemIndex].getPrice() << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
			purchases.push_back(vecItems[itemIndex]);
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

			totalPrice = vecItems[itemIndex].getPrice();
			taxCost = SalesTax(SALES_TAX, totalPrice);

			cout << setprecision(2);
			cout << "The price of the item is:" << setw(8) << "$" << vecItems[itemIndex].getPrice() << endl;
			cout << "The cost of tax is:" << setw(8) << "$" << taxCost << endl;
			cout << "The total cost of the item is:" << setw(8) << "$" << totalPrice << endl;
			break;

			cout << "Is this the book that you would like to purchase?" << endl;
			cout << "Enter 'Y' or 'y' for yes." << endl;
			cin >> confirmPurchase;
			if (confirmPurchase == 'y' || confirmPurchase == 'Y')
			{
			purchases.push_back(vecItems[itemIndex]);
			}
			else
			break;
			case '5':
			finalPurchase = CompleteTransaction(purchases);
			cout << setprecision(2);
			cout << "The total cost for the purchases is:" << setw(8) << "$" << finalPurchase << endl;

			break;*/
		case '2':
			cout << "================================================================================"
				<< "\t\t\tExit Module" << endl
				<< "================================================================================";
			return;
			break;
		}
	}
	TextWrite(strUnsorted, vecItems);	// Write the sorted vector to the database file
	bISBNFlag = true;		// Set the flag for the database file to true
	return;
}