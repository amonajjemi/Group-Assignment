#ifndef FILES_H
#define FILES_H

#include "InventoryItem.h"
#include <vector>


bool FileFlagTest(string);
bool isEmpty(string);
void DisplayItem(InventoryItem&);
void TextRead(string, InventoryItem*&);
void TextRead(string, vector<InventoryItem>&);
void TextWrite(string, InventoryItem*, int);
void TextWrite(string, vector<InventoryItem>&);
void TextRead(string, Book*);

char Choice(char, char);
int Choice(int, int);
char YesNo();
void Pause();
template <class Type>
void UserInput(Type &value)
{
	cin >> value;
	cin.ignore(10000, '\n');
	cin.clear();
}

// UNUSED FUNCTIONS //
void BinaryRead(string, InventoryItem*&);
void BinaryWrite(string, InventoryItem*, int);
int Random(int, int);
Date RandomDate();
double RandomWholesale();
double RandomPrice();


#endif