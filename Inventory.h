#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

// Class representing inventory of procuts
class Inventory
{
private:
    // Vector to keep Product pointers
    vector<Product*> products;

public:
    // Function to add new product to inventory
    void addProduct(Product* product);

    // Function to update quantity of product
    void updateProductQty(const string& productName, int newQty);

    // Function to display inventory report
    void displayInventoryReport();

    // Function to display total count
    void displayTotalCount();

    // Function to update product information
    void updateProductInfo(const string& productName, double newPrice, int newQuantity, const string& newName);

    // Function to display inventory summary
    void displayInventorySummary();

    // Function to add perishable product to inventory
    void addPerishableProduct(PerishableProduct* product);

    // Function to calculate selling price for perishable products
    double calculateSellingPrice(Product* product);

    // Function to find product 
    Product* findProduct(const string& productName);

    // Public getter for vector products
    const vector<Product*>& getProducts() const;

};

#endif // INVENTORY_H
