#include <iostream>
#include "Inventory.h"
using namespace std;

// Inventory class implemetations
// Declaring addProduct function which adds product
void Inventory::addProduct(Product* product)
{
    // Using built-in function push_back to add product
    products.push_back(product);
}

// Declaring updateProductQty function which updates quantity of product
void Inventory::updateProductQty(const string& productName, int newQty)
{
    // Updating product quantity by calling corresponding setter and getter functions
    for (Product* product : products)
    {
        if (product->getName() == productName)
        {
            product->setQuantity(newQty);
            return;
        }
    }
    // If product is not found, display a runtime error
    throw runtime_error("Product is not found!");
}

// Declaring displayInventoryReport function which display inventory report
void Inventory::displayInventoryReport()
{
    cout << "Inventory Report" << endl;

    // Calling displayProductInfo function to display the report
    for (Product* product : products)
    {
        product->displayProductInfo();
    }
}

// Declaring displayTotalCpount function 
void Inventory::displayTotalCount()
{
    cout << "Total count" << endl;

    // Calling calculate total price function to display total count
    for (Product* product : products)
    {
        cout<<"Product name: "<< product->getName() << endl;
        cout<<"Total price : "<< product->calculateTotalPrice() << endl;
    }
}

//Declaring productInfo function
void Inventory::updateProductInfo(const string& productName, double newPrice, int newQuantity, const string& newName)
{
    Product* product = findProduct(productName);
    if (product)
    {
        product->setPrice(newPrice);
        product->setQuantity(newQuantity);
        product->setName(newName);
    }
    else
    {
        // If product is not found, throw an error or handle accordingly
        throw runtime_error("Product is not found!");
    }
}

//Declaring inventory summary
void Inventory::displayInventorySummary()
{
    double totalPurchasePrice = 0.0;
    double totalSellingPrice = 0.0;

    cout << "Inventory Summary" << endl;
    for (Product* product : products)
    {
        double total = product->calculateTotalPrice();
        double sellingPrice = calculateSellingPrice(product);

        totalPurchasePrice += total;
        totalSellingPrice += sellingPrice;

        cout << "Product: " << product->getName() << endl;
        cout << "Total Quantity: " << product->getQuantity() << endl;
        cout << "Total Price: $" << total << endl;
        cout << "Selling Price: $" << sellingPrice << endl;
        cout << "*****************************" << endl;
    }

    cout << "Total Inventory Purchase Price: $" << totalPurchasePrice << endl;
    cout << "Total Inventory Selling Price: $" << totalSellingPrice << endl;
}


// Declaring findProduct function which searches product in inventory 
Product* Inventory::findProduct(const string& productName)
{
    // Finding product by using corresponding getter function
    for (Product* product : products)
    {
        if (product->getName() == productName)
        {
            return product;
        }
    }
    // Returning nullptr if product is not found
    return nullptr;
}

// Declaring public getter function to access product vector
const vector<Product*>& Inventory::getProducts() const
{
    return products; 
}

//
void Inventory::addPerishableProduct(PerishableProduct* product)
{
    products.push_back(product);
}

double Inventory::calculateSellingPrice(Product* product)
{
    PerishableProduct* perishableProduct = dynamic_cast<PerishableProduct*>(product);
    if (perishableProduct)
    {
        return perishableProduct->calculateTotalPrice();
    }
    else
    {
        // For regular products, just return the normal total price
        return product->calculateTotalPrice();
    }
}