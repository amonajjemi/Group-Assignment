#ifndef DATABASE_H
#define DATABASE_H

#include "InventoryItem.h"
#include <vector>

using namespace std;

void ReduceQuantity(vector<InventoryItem> &, int);
void DatabaseModule(bool&, bool&);

// Sorts the vector by ISBN values in ascending order
void SortISBN(vector<InventoryItem> &);
bool compareISBN(InventoryItem &, InventoryItem &);
void UpdateISBNFile(vector<InventoryItem> &, bool &);		//  Updates the ISBN.txt database file


// Sorts the vector by titles in ascending order
void SortTitle(vector<InventoryItem> &);
bool compareTitle(InventoryItem &, InventoryItem &);
void UpdateTitleFile(vector<InventoryItem> &, bool &);		// Updates the title.txt database file


// Sorts the vector by author's last names in ascending order
void SortAuthor(vector<InventoryItem> &);
bool compareAuthor(InventoryItem &, InventoryItem &);
void UpdateAuthorFile(vector<InventoryItem> &, bool &);		// Updates the author.txt database file

// Searching functions
int searchByISBN(vector<InventoryItem> &, string);
vector<int> searchByTitle(vector<InventoryItem> &, string);
vector<int> fuzzySearchByTitle(vector<InventoryItem> &, string);
vector<int> searchByAuthor(vector<InventoryItem> &, Name);


#endif DATABASE_H