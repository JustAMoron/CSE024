#include "ShoppingCart.h"
#include "GroceryItem.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ShoppingCart::ShoppingCart() {
  subtotal = 0.0;
  tax = 0.0;
  total = 0.0;
}

void ShoppingCart::print() {
  cout << "=========================" << endl;
  cout << "      Shopping Cart      " << endl;
  cout << "=========================" << endl;

  if (items.size() == 0) {
    cout << "Cart is empty." << endl;
  }

  for (unsigned int i = 0; i < items.size(); i++) {
    cout << items[i]->getQuantity() << " x " << items[i]->getName() << ": $"
         << items[i]->getPrice() << endl;
  }

  cout << "=========================" << endl;
  cout << "Subtotal: $" << subtotal << endl;
  cout << "Tax:      $" << tax << endl;
  cout << "Total:    $" << total << endl;
  cout << "=========================" << endl;
}


void ShoppingCart::addItem(std::string name, float price, int quantity) {
  if (price < 0 || quantity < 0) {
    throw logic_error("Shit can't be negative");
    return;
  }

  GroceryItem *newItem = new GroceryItem(name, price, quantity);
  items.push_back(newItem);

  subtotal += price * quantity;
  tax = subtotal * 0.0825;
  total = subtotal + tax;
}

void ShoppingCart::updateItemQuantity(std::string name, int quantity) {
  if (quantity < 0) {
    throw logic_error("shit can't be less than zero");
    return;
  }
  for (size_t i = 0; i < items.size(); i++) {
    if (items[i]->getName() == name) {
        float oldSubtotal = items[i]->getPrice() * items[i]->getQuantity();
      if (quantity == 0) {
        delete items[i];
        items.erase(items.begin() + i);

      } else {
        items[i]->setQuantity(quantity);
      }
        subtotal -= oldSubtotal;
        subtotal += items[i]->getPrice() * quantity;
        tax = subtotal * 0.0825;
        total = subtotal + tax;

      return;
    }
  }

  throw logic_error("Shit ain't in the cart");
}

void ShoppingCart::removeAll() {
  for (auto item : items) {
    delete item;
  }
  items.clear();
  subtotal = 0.0;
  tax = 0.0;
  total = 0.0;
}
