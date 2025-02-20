#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setprecision(2) << fixed;

    ShoppingCart* cart = new ShoppingCart();

    cart->addItem("Apple", 0.99, 5);
    cart->addItem("Banana", 0.75, 7);
    cart->addItem("Cheese", 4.99, 1);

    cart->print();

    cart->updateItemQuantity("Apple", 5);

    cart->print();

    return 0;
}
