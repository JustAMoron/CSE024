#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

#include <string>

class GroceryItem {
    // private member variables
    std::string name;
    float price;
    int quantity;

public:
    // public constructor
    GroceryItem(std::string name, float price, int quantity);

    // public "getter" methods
    std::string getName() const;
    float getPrice() const;
    int getQuantity() const;

    // public "setter" methods
    void setName(std::string name);
    void setPrice(float price);
    void setQuantity(int quantity);

    // needed for running unit tests
    friend struct AppTest;
};

#endif
