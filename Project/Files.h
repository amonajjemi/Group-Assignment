#ifndef FILES_H
#define FILES_H

#include "InventoryItem.h"

void TextRead(string, InventoryItem*);
void TextWrite(string, InventoryItem*, int);
void BinaryRead(string, InventoryItem*);
void BinaryWrite(string, InventoryItem*, int);
void TextRead(fstream&, Book*);
int Random(int, int);
Date RandomDate();
double RandomWholesale();
double RandomPrice();

#endif