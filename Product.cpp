#include <iostream>
#include <ctime>
#include "Product.h"
using namespace std;

// Product class implementations
// Declaring Product class constructor to intialize properties
Product::Product(double price, int quantity, const string& name, int expiryDate)
    : price(price), quantity(quantity), name(name), expiryDate(expiryDate) {}

// Declaring setter functions of base class Product to update its properties
void Product::setPrice(double price)
{
    this->price = price;
}

void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Product::setName(const string& name)
{
    this->name = name;
}

void Product::setExpiryDate(int expiryDate)
{
    this->expiryDate = expiryDate;
}

// Declaring getter functions of base class Product to retrieve its properties
double Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

string Product::getName() const
{
    return name;
}

int Product::getExpiryDate() const
{
    return expiryDate;
}

// Derived Fruit class implementations
// Declaring Fruits class constructor to initialize its properties
Fruit::Fruit(double price, int quantity, const string& name)
    : Product(price, quantity, name) {}

// Adapting the virtual function calculateTotalPrice to get total price
double Fruit::calculateTotalPrice()
{
    double total = price * quantity;
    return total;
}

// Adapting the virtual function displayProductInfo to display infromation about product
void Fruit::displayProductInfo()
{
    cout << "Fruit     : " << name << endl;
    cout << "Price     : " << price << endl;
    cout << "Quantity  : " << quantity << endl;
    cout << "*****************************" << endl;
}

// Derived Vegetable class implementations
// Declaring Vegetable class constructor to initialize its properties
Vegetable::Vegetable(double price, int quantity, const string& name)
    : Product(price, quantity, name) {}

// Adapting the virtual function calculateTotalPrice to get total price
double Vegetable::calculateTotalPrice()
{
    double total = price * quantity;
    return total;
}

// Adapting the virtual function displayProductInfo to display infromation about product
void Vegetable::displayProductInfo()
{
    cout << "Vegetable : " << name << endl;
    cout << "Price     : " << price << endl;
    cout << "Quantity  : " << quantity << endl;
    cout << "*****************************" << endl;
}

// Derived BakeryItem class implementations
// Declaring BakeryItem class constructor to initialize its properties
BakeryItem::BakeryItem(double price, int quantity, const string& name)
    : Product(price, quantity, name) {}

// Adapting the virtual function calculateTotalPrice to get total price
double BakeryItem::calculateTotalPrice()
{
    double total = price * quantity;
    return total;
}

// Adapting the virtual function displayProductInfo to display infromation about product
void BakeryItem::displayProductInfo()
{
    cout << "Bakery items: " << name << endl;
    cout << "Price       : " << price << endl;
    cout << "Quantity    : " << quantity << endl;
    cout << "*****************************" << endl;
}

// Derived GlutenFree bakery class implemetations
// Declaring GlutenFree class constructor to initialize its properties
GlutenFreeBakery::GlutenFreeBakery(double price, int quantity, const string& name)
    : BakeryItem(price, quantity, name) {}



// Derived RegularBakery bakery class implemetations
// Declaring RegularBakery class constructor to initialize its properties
RegularBakery::RegularBakery(double price, int quantity, const string& name)
    : BakeryItem(price, quantity, name) {}


// Derived HomeBaked bakery class implemetations
// Declaring HomeBaked class constructor to initialize its properties
HomeBaked::HomeBaked(double price, int quantity, const string& name)
    : RegularBakery(price, quantity, name) {}

// PerishableProduct class implementation

PerishableProduct::PerishableProduct(double price, int quantity, const string& name, int expiryDate)
    : Product(price, quantity, name)
{
    setExpiryDate(expiryDate);
}

double PerishableProduct::calculateTotalPrice()
{
    // Get the current date
    time_t now;
    struct tm localTime;
    if (time(&now) == -1 || localtime_s(&localTime, &now) != 0) {
        cerr << "Failed to get the current time." << endl;
        return 0.0;
    }
    int currentDay = localTime.tm_mday;

    // Calculate the number of days remaining until expiry
    int daysRemaining = getExpiryDate() - currentDay;

    // Calculate the percentage of days remaining out of the maximum expiry days
    double percentageRemaining = static_cast<double>(daysRemaining) / static_cast<double>(MAX_EXPIRY_DAYS);

    // Calculate the selling price by decreasing linearly with days remaining until expiry
    double sellingPrice = getPrice() * percentageRemaining * getQuantity();
    return sellingPrice;
}

void PerishableProduct::displayProductInfo()
{
    cout << "Perishable Product: " << getName() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << "Quantity: " << getQuantity() << endl;
    cout << "Expiry Date (days): " << getExpiryDate() << endl;
    cout << "*****************************" << endl;
}
