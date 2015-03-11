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
void InventoryItem::setISBN(string isbn){ BookItem.setISBN(isbn); }
void InventoryItem::setTitle(string title){ BookItem.setTitle(title); }
void InventoryItem::setAuthor(Name name){ BookItem.setAuthor(name); }
void InventoryItem::setPublisher(string pub){ BookItem.setPublisher(pub); }
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
	// Equal to operator overload for InventoryItem class
	// Returns true if all members of the objects are the same, otherwise returns false
	if ((BookItem == obj.BookItem) && (DateAdded == obj.DateAdded) && (Quantity == obj.Quantity) && (abs(Wholesale - obj.Wholesale) <= .0001) && (abs(Price - obj.Price) <= .0001))
		return true;
	else
		return false;
}
void InventoryItem::operator=(const InventoryItem &obj){
	// Assignment operator overload for InventoryItem class
	// Copies values from one object to another
	BookItem = obj.BookItem;
	DateAdded = obj.DateAdded;
	Quantity = obj.Quantity;
	Wholesale = obj.Wholesale;
	Price = obj.Price;
}
ofstream& operator<<(ofstream &ofs, const InventoryItem &obj){
	// ofstream operator overload for InventoryItem class
	// Uses Book and Date class ofstream operators for the BookItem and DateAdded members
	// Outputs the values with a single space in between them. The title member of the Book class will be enclosed in single quotes ('title goes here')
	ofs << obj.BookItem << " " << obj.DateAdded << " " << obj.Quantity << " " << obj.Wholesale << " " << obj.Price;
	return ofs;
}
ifstream& operator>>(ifstream &ifs, InventoryItem &obj){
	// ifstream operator overload for InventoryItem class
	// Uses Book and Date class ifstream operators for the BookItem and DateAdded members
	// The values must have a space between them. The title member of the Book class must be enclosed in single quotes ('title goes here')
	// The values should be on the same line, but it may not be neccesary
	ifs >> obj.BookItem >> obj.DateAdded >> obj.Quantity >> obj.Wholesale >> obj.Price;
	return ifs;
}
fstream& operator<<(fstream &fs, const InventoryItem &obj){
	// output fstream operator overload for InventoryItem class
	// Works the same as the ofstream operator overload
	fs << obj.BookItem << " " << obj.DateAdded << " " << obj.Quantity << " " << obj.Wholesale << " " << obj.Price;
	return fs;
}
fstream& operator>>(fstream &fs, InventoryItem &obj){
	// input fstream operator overload for InventoryItem class
	// Works the same as the ifstream operator overload
	fs >> obj.BookItem >> obj.DateAdded >> obj.Quantity >> obj.Wholesale >> obj.Price;
	return fs;
}