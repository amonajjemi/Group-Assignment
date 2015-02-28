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
		Quantity = eQuantity;

}

void InventoryItem::setWholesale(double eWhole)
{
	Wholesale = eWhole;
}

void InventoryItem::setPrice(double ePrice)
{
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
