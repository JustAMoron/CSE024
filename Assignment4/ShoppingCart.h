#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "GroceryItem.h"
#include <vector>
#include <string>

class ShoppingCart {
    // private member variables
    std::vector<GroceryItem*> items;
    float subtotal;
    float tax;
    float total;

    void recalculateTotal();

public:
    // public constructor
    ShoppingCart();

    // public member methods
    void addItem(std::string name, float price, int quantity);

    void updateItemQuantity(std::string name, int quantity);

    void removeAll();
    
    void print();

    // needed for running unit tests
    friend struct AppTest;
};

#endif
