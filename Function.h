// Function.h

#ifndef FUNCTION_H
#define FUNCTION_H

#include "Inventory.h" // Make sure to include the necessary header files

// Function declarations (prototypes)
void addProductToInventory(Inventory& inventory);
void updateProductQuantity(Inventory& inventory);
void updateProductInformation(Inventory& inventory);
void displayMenu(Inventory& inventory);

#endif // FUNCTION_H
