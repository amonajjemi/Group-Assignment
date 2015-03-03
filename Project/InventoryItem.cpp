#include "InventoryItem.h"

using namespace std;

InventoryItem::~InventoryItem()
{
}

InventoryItem::InventoryItem(const InventoryItem &obj)
{
	BookItem = obj.BookItem;
	DateAdded = obj.DateAdded;
	Quantity = obj.Quantity;
	Wholesale = obj.Wholesale;
	Price = obj.Price;
}

InventoryItem::InventoryItem()
{
	BookItem.Book::Book();
	DateAdded.Date::Date();
	Quantity = 0;
	Wholesale = 0;
	Price = 0;
}

InventoryItem::InventoryItem(Book item, Date date, int eQuantity, double whole, double ePrice)
{
	BookItem = item;
	DateAdded = date;
	Quantity = eQuantity;
	Wholesale = whole;
	Price = ePrice;
}

void InventoryItem::setBook(Book eBook){ BookItem = eBook; }
void InventoryItem::setDateAdded(Date eDate){ DateAdded = eDate; }
void InventoryItem::setQuantity(int eQuantity){ Quantity = eQuantity; }
void InventoryItem::setWholesale(double eWhole){ Wholesale = eWhole; }
void InventoryItem::setPrice(double ePrice){ Price = ePrice; }
Book InventoryItem::getBook(){ return BookItem; }
Date InventoryItem::getDateAdded(){ return DateAdded; }
int InventoryItem::getQuantity(){ return Quantity; }
double InventoryItem::getWholesale(){ return Wholesale; }
double InventoryItem::getPrice(){ return Price; }

string InventoryItem::GetISBN(){ return BookItem.getISBN(); }
string InventoryItem::GetTitle(){ return BookItem.getTitle(); }
Name InventoryItem::GetAuthor(){ return BookItem.getAuthor(); }
string InventoryItem::GetAuthorName(){ return BookItem.getAuthor().GetName(); }
string InventoryItem::GetPublisher(){ return BookItem.getPublisher(); }

bool InventoryItem::operator==(const InventoryItem &obj){
	if ((BookItem == obj.BookItem) && (DateAdded == obj.DateAdded) && (Quantity == obj.Quantity) && (Wholesale == obj.Wholesale) && (Price = obj.Price))
		return true;
	else
		return false;
}
void InventoryItem::operator=(const InventoryItem &obj){
	BookItem = obj.BookItem;
	DateAdded = obj.DateAdded;
	Quantity = obj.Quantity;
	Wholesale = obj.Wholesale;
	Price = obj.Price;
}
ofstream& operator<<(ofstream &ofs, const InventoryItem &obj){
	ofs << obj.BookItem << " " << obj.DateAdded << " " << obj.Quantity << " " << obj.Wholesale << " " << obj.Price;
	return ofs;
}
ifstream& operator>>(ifstream &ifs, InventoryItem &obj){
	ifs >> obj.BookItem >> obj.DateAdded >> obj.Quantity >> obj.Wholesale >> obj.Price;
	return ifs;
}
fstream& operator<<(fstream &fs, const InventoryItem &obj){
	fs << obj.BookItem << " " << obj.DateAdded << " " << obj.Quantity << " " << obj.Wholesale << " " << obj.Price;
	return fs;
}
fstream& operator>>(fstream &fs, InventoryItem &obj){
	fs >> obj.BookItem >> obj.DateAdded >> obj.Quantity >> obj.Wholesale >> obj.Price;
	return fs;
}