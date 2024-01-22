#include <iostream>
#include "Function.h"
#include "Inventory.h"
#include "Product.h"

void displayMenu(Inventory& inventory)
{
    int choice;
    do
    {
        cout << "===== Main Menu =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Update Product Quantity" << endl;
        cout << "3. Update Product Information" << endl;
        cout << "4. Display Inventory Report" << endl;
        cout << "5. Display Inventory Summary" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear any remaining characters in the input buffer (including the newline character)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addProductToInventory(inventory);
            break;
        case 2:
            updateProductQuantity(inventory);
            break;
        case 3:
            updateProductInformation(inventory);
            break;
        case 4:
            inventory.displayInventoryReport();
            break;
        case 5:
            inventory.displayInventorySummary();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}


void addProductToInventory(Inventory& inventory)
{
    // Get product details from the user
    double price;
    int quantity;
    string name;
    int expiryDate = 0; // Initialize to 0; will be used only for perishable products

    int productType;
    cout << "Select product type:" << endl;
    cout << "1. Fruit" << endl;
    cout << "2. Vegetable" << endl;
    cout << "3. Perishable Product" << endl;
    cout << "Enter product type (1/2/3): ";
    cin >> productType;

    cin.ignore(); // Clear the newline character from the previous input

    cout << "Enter the price: ";
    cin >> price;

    cout << "Enter the quantity: ";
    cin >> quantity;

    cin.ignore(); // Clear the newline character from the previous input

    cout << "Enter the name: ";
    getline(cin, name);

    if (productType == 3) // If it's a perishable product, ask for expiry date
    {
        cout << "Enter the expiry date (in days): ";
        cin >> expiryDate;
        inventory.addPerishableProduct(new PerishableProduct(price, quantity, name, expiryDate));
    }
    else if (productType == 2)
    {
        inventory.addProduct(new Vegetable(price, quantity, name));
    }
    else
    {
        inventory.addProduct(new Fruit(price, quantity, name));
    }

    cout << "Product added to inventory successfully!" << endl;
}



void updateProductQuantity(Inventory& inventory)
{
    string productName;
    int newQuantity;

    cout << "Enter the product name: ";
    cin.ignore();
    getline(cin, productName);

    Product* productToUpdate = inventory.findProduct(productName);
    if (productToUpdate)
    {
        cout << "Enter the new quantity: ";
        cin >> newQuantity;

        // Updating the product quantity using the setter function
        productToUpdate->setQuantity(newQuantity);

        cout << "Product quantity updated successfully!" << endl;
    }
    else
    {
        cout << "Product not found in the inventory!" << endl;
    }
}

void updateProductInformation(Inventory& inventory)
{
    string productName;
    double newPrice;
    int newQuantity;
    string newName;

    cout << "Enter the product name: ";
    cin.ignore();
    getline(cin, productName);

    Product* productToUpdate = inventory.findProduct(productName);
    if (productToUpdate)
    {
        cout << "Enter the new price: ";
        cin >> newPrice;

        cout << "Enter the new quantity: ";
        cin >> newQuantity;

        cout << "Enter the new name: ";
        cin.ignore();
        getline(cin, newName);

        // Updating the product information using the setter functions
        productToUpdate->setPrice(newPrice);
        productToUpdate->setQuantity(newQuantity);
        productToUpdate->setName(newName);

        cout << "Product information updated successfully!" << endl;
    }
    else
    {
        cout << "Product not found in the inventory!" << endl;
    }
}
