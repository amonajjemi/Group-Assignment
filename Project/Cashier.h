#ifndef CASHIER_H
#define CASHIER_H

#include "InventoryItem.h"
#include <vector>

using namespace std;

double SalesTax(double, double&);
double CompleteTransaction(vector <InventoryItem>&);
void CashierModule(bool&, bool&, bool&, bool&);
void CashierMenu();

#endif CASHIER_H