#include "Cashier.h"
#include "Files.h"
#include "Database.h"

#include <iostream>
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

	taxCost = itemPrice * taxRate; //calculates the tax for a single item
	itemPrice += taxCost; //calculates the cost with tax for a single item

	return taxCost;
}

double CompleteTransaction(vector<InventoryItem> &transaction, vector<int> &indexes)
{
	double totalCost = 0;
	for (int i = 0; i < indexes.size(); i++)
	{
		totalCost += transaction[indexes[i]].getPrice(); //Addup total transaction price
		ReduceQuantity(transaction, indexes[i]);
	}
	totalCost *= (1 + SALES_TAX); //calculate total transaction cost with tax
	return totalCost;
}

void CashierModule(bool &bUnsortedFlag, bool &bISBNFlag, bool &bTitleFlag, bool &AuthorFlag)
{
	vector<InventoryItem> vecItems(0); //Holds the all the books in teh inventory
	TextRead(strUnsorted, vecItems); //Reads in all books from the file
	SortISBN(vecItems);// Sort the items by isbn

	vector<int> index(0);
	int itemIndex; //Receives teh serached book's index from teh search function
	string searchISBN; //holds the users input for the ISBN to search for
	double totalPrice,//Holds the the price plus tax for each book is entered (replaced by each new book)
		taxCost,// holds the tax cost for each individual book entered (replaced by each new book)
		finalPurchase; // Holds the total cost of all books being purchased
	char confirmPurchase; //Used to check with the user if that is the book the user wants
	bool finish = false; //Determines when transaction is complete and exits when true

	string strMainMenu[] = {
		"================================================================================",
		"\t\t\t\tCASHIER MODULE\n",
		"================================================================================",
		"\t1) - Search by ISBN number\n", //MENU
		"\t2) - Exit Module\n" //MENU
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
			while (searchISBN.length() != 13) //Check to make sure input is valid
			{
				cout << "Please make sure that the ISBN number is the correct length." << endl;
				cin >> searchISBN;
				cin.ignore();
			}
			itemIndex = searchByISBN(vecItems, searchISBN); //Search vector for item and return the index
			if (itemIndex == -1)//If book isn't found -1 is returned
			{
				cout << "The item is not in the inventory." << endl;
				Pause(); //pauses program for user
				break;
			}
			else
			{
				totalPrice = vecItems[itemIndex].getPrice(); //Total price containst the cost of the item without tax
				taxCost = SalesTax(SALES_TAX, totalPrice); //Now Total price contains the cost of the item with tax

				cout << fixed << setprecision(2);
				cout << left << setw(40) << vecItems[itemIndex].GetTitle() << endl; //Display book's name
				cout << left << setw(40) << "The price of the item is:" << "$" << vecItems[itemIndex].getPrice() << endl; //Display book's price
				cout << left << setw(40) << "The cost of tax is:" << "$" << taxCost << endl; //Display book's tax
				cout << left << setw(40) << "The total cost of the item is:" << "$" << totalPrice << endl << endl; //Display book's total cost

				cout << "Is this the book that you would like to purchase?" << endl;
				cout << "Enter 'Y' or 'y' for yes." << endl;
				cin >> confirmPurchase;
				cin.ignore();
				cout << endl;
				if (confirmPurchase == 'y' || confirmPurchase == 'Y') //Confirmation to purchase the book
				{
					index.push_back(itemIndex);
				}
				else
				{
					cout << "Returning to Cashier Menu." << endl;
					Pause();
					break;
				}

				cout << "Would you like to check out?" << endl;
				cout << "Enter 'Y' or 'y' for yes." << endl;
				cin >> confirmPurchase;
				cin.ignore();
				cout << endl;
				if (confirmPurchase == 'y' || confirmPurchase == 'Y') //Determine whether to checkout and pay for the books
				{
					finish = true;
					system("cls");
					cout << "Books purchased:" << endl;
					for (int i = 0; i < index.size(); i++)
					{
						cout << vecItems[index[i]].GetTitle() << endl;
					}
					cout << endl;
					cout << "Your final total is:" << endl;
					finalPurchase = CompleteTransaction(vecItems, index);
					cout << "$" << finalPurchase << endl; //Display final price for user
					Pause();//pauses program for user
				}
				else
				{
					cout << "Your item is saved." << endl;
					cout << "Returning to Cashier Menu." << endl;
					Pause();
				}
			}
			break;

		case '2'://Exit the module
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