#ifndef FILES_H
#define FILES_H

#include "InventoryItem.h"

void BinaryRead(fstream&, InventoryItem*);
void BinaryWrite(fstream&, InventoryItem*, int);
void TextRead(fstream&, Book*);
int Random(int, int);
Date RandomDate();
double RandomWholesale();
double RandomPrice();

#endif