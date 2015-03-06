#ifndef DATABASE_H
#define DATABASE_H

#include "InventoryItem.h"
#include <vector>

using namespace std;

void DatabaseModule(bool&, bool&, bool&, bool&);
void DatabaseMenu(InventoryItem*, int);

// Sorts the vector by ISBN values in ascending order
// And updates the ISBN.txt database file
void SortISBN(vector<InventoryItem> &);
bool compareISBN(InventoryItem &, InventoryItem &);

// Sorts the vector by titles in ascending order
// And updates the title.txt database file
void SortTitle(vector<InventoryItem> &);
bool compareTitle(InventoryItem &, InventoryItem &);

// Sorts the vector by author's last names in ascending order
// And updates the author.txt database file
void SortAuthor(vector<InventoryItem> &);
bool compareAuthor(InventoryItem &, InventoryItem &);

#endif DATABASE_H