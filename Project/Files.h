#ifndef FILES_H
#define FILES_H

#include "InventoryItem.h"
#include <vector>

bool FileFlagTest(string);
void TextRead(string, InventoryItem*&);
void TextRead(string, vector<InventoryItem>&);
void TextWrite(string, InventoryItem*, int);
void TextWrite(string, vector<InventoryItem>&);
void BinaryRead(string, InventoryItem*&);
void BinaryWrite(string, InventoryItem*, int);
void TextRead(string, Book*);

char Choice(char, char);
char YesNo();

int Random(int, int);
Date RandomDate();
double RandomWholesale();
double RandomPrice();

#endif