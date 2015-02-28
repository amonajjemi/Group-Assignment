#include "InventoryItem.h"
#include <iostream>

using namespace std;

InventoryItem::InventoryItem()
{
	//MUST FILL IN
	//
	//
	//
}

InventoryItem::InventoryItem(Book item, Date date, int eQuantity, double whole, double ePrice)
{
	BookItem = item;
	DateAdded = date;
	Quantity = eQuantity;
	Wholesale = whole;
	Price = ePrice;
}

void InventoryItem::setBook(Book eBook)
{
	BookItem = eBook;
}

void InventoryItem::setDateAdded(Date eDate)
{
	DateAdded = eDate;
}

void InventoryItem::setQuantity(int eQuantity)
{
	while (eQuantity < 0)
	{
		cout << "Please enter a non-negative number." << endl;
		cin >> eQuantity;
	}
		Quantity = eQuantity;

}

void InventoryItem::setWholesale(double eWhole)
{
	while (eWhole < 0)
	{
		cout << "Please enter a non-negative number." << endl;
		cin >> eWhole;
	}
	Wholesale = eWhole;
}

void InventoryItem::setPrice(double ePrice)
{
	while (ePrice < 0)
	{
		cout << "Please enter a non-negative number." << endl;
		cin >> ePrice;
	}
	Price = ePrice;
}

Book InventoryItem::getBook()
{
	return BookItem;
}

string InventoryItem::getDateAdded()
{
	return DateAdded.GetDate();
}

int InventoryItem::getQuantity()
{
	return Quantity;
}

double InventoryItem::getWholesale()
{
	return Wholesale;
}

double InventoryItem::getPrice()
{
	return Price;
}
