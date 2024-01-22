#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <ctime>
const int MAX_EXPIRY_DAYS = 10;
using namespace std;

// Base class for all products
class Product
{
protected:
    double price;
    int quantity;
    string name;
    int expiryDate;

public:
    // Constructor with default values
    Product(double price = 0.0, int quantity = 0, const string& name = "", int expiryDate = 0);

    // Setter functions to update product properties
    void setPrice(double price);
    void setQuantity(int quantity);
    void setName(const string& name);
    void setExpiryDate(int expiryDate);

    // Getter functions to retrieve product properties
    double getPrice() const;
    int getQuantity() const;
    string getName() const;
    int getExpiryDate() const;

    // Virtual functions to be overriden in derived classes
    virtual double calculateTotalPrice() = 0;
    virtual void displayProductInfo() = 0;
};

// Derived class representing Fruit product
class Fruit : public Product
{
public:
    // Constructor to intialize Fruit class properties
    Fruit(double price, int quantity, const string& name);

    // Overridden virtual functions
    double calculateTotalPrice() override;
    void displayProductInfo() override;
};

// Derived class representing Vegetable product
class Vegetable : public Product
{
public:
    // Constructor to intialize Vegetable class properties
    Vegetable(double price, int quantity, const string& name);

    // Overridden virtual functions
    double calculateTotalPrice() override;
    void displayProductInfo() override;
};

// Derived class representing BakeryItem product
class BakeryItem : public Product
{
public:
    // Constructor to intialize BakeryItem class properties
    BakeryItem(double price, int quantity, const string& name);

    // Overridden virtual functions
    double calculateTotalPrice() override;
    void displayProductInfo() override;
};

// Derived class representing GlutenFree Bakery
class GlutenFreeBakery : public BakeryItem
{
public:
    GlutenFreeBakery(double price, int quantity, const string& name);
};

// Derived class represeting Regular Bakery
class RegularBakery : public BakeryItem
{
public:
    RegularBakery(double price, int quantity, const string& name);
};

// Drived class representing Homebaked class
class HomeBaked : public RegularBakery
{
public:
    HomeBaked(double price, int quantity, const string& name);
};

// Create a new derived class for perishable products
class PerishableProduct : public Product
{
public:
    PerishableProduct(double price = 0.0, int quantity = 0, const string& name = "", int expiryDate = 0);

    double calculateTotalPrice() override;
    void displayProductInfo() override;
};


#endif // PRODUCT_H
