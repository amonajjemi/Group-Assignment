#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "Book.h"
#include "Date.h"
#include <iostream>
#include <fstream>

class InventoryItem
{
protected:
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
	Date getDateAdded();
	int getQuantity();
	double getWholesale();
	double getPrice();

	string GetISBN();
	string GetTitle();
	Name GetAuthor();
	string GetAuthorName();
	string GetPublisher();
	
	bool operator==(const InventoryItem&);
	void operator=(const InventoryItem&);

	friend ofstream& operator<<(ofstream &, const InventoryItem&);
	friend ifstream& operator>>(ifstream &, InventoryItem&);
	friend fstream& operator<<(fstream &, const InventoryItem&);
	friend fstream& operator>>(fstream &, InventoryItem&);
};

#endif
