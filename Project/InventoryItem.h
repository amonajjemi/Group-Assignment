#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "Book.h"
#include "Date.h"

class InventoryItem
{
private:
	Book BookItem;
	Date DateAdded;
	int Quantity;
	double Wholesale;
	double Price;
public:
	InventoryItem();
	InventoryItem(Book, Date, int, double, double);
	InventoryItem(const InventoryItem&);
	~InventoryItem();

	void setBook(Book);
	void setDateAdded(Date);
	void setQuantity(int);
	void setWholesale(double);
	void setPrice(double);

	Book getBook();
	string getDateAdded();
	int getQuantity();
	double getWholesale();
	double getPrice();

	int GetISBN();
	string GetTitle();
	string GetAuthor();
	string GetPublisher();
};

#endif
