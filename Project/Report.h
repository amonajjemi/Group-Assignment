#ifndef REPORT_H
#define REPORT_H

#include "InventoryItem.h"
#include <vector>

using namespace std;

void ReportModule(bool&, bool&, bool&, bool&);
void ReportMenu();

// Generic functions to display the items in the order of the vector passed in 
void DisplayItems(vector<InventoryItem> &);
void DisplayWholesale(vector<InventoryItem> &);
void DisplayRetail(vector<InventoryItem> &);

// Sorts the vector by quantity
void SortQuantity(vector<InventoryItem> &);				
bool compareQuantity(InventoryItem &, InventoryItem &);

// Sorts the vector according to the book's wholesale cost
void SortCost(vector<InventoryItem> &);				
bool compareCost(InventoryItem &, InventoryItem &);

// Sorts the vector according to how long it has been in the inventory
void SortAge(vector<InventoryItem> &);				
bool compareAge(InventoryItem &, InventoryItem &);

// Calculation functions
double getTotalWholesale(vector<InventoryItem> &);
double getTotalRetail(vector<InventoryItem> &);


#endif REPORT_H