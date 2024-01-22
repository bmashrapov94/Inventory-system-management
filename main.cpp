#include <iostream>
#include "Function.h"
#include "Inventory.h"
#include "Product.h"

int main()
{
    Inventory inventory;

    // Calling displayMenu function
    displayMenu(inventory);

    // Deleting objects stored in inventory
    for (Product* product : inventory.getProducts())
    {
        delete product;
    }

    return 0;
}
