#include "GroceryItem.h"
using namespace std;

GroceryItem::GroceryItem(string name, float price, int quantity) {
  this->name = name;
  this->price = price;
  this->quantity = quantity;
}

string GroceryItem::getName() const { return name; }

float GroceryItem::getPrice() const { return price; }

int GroceryItem::getQuantity() const { return quantity; }

void GroceryItem::setName(string name) { this->name = name; }

void GroceryItem::setPrice(float price) {
  if (price >= 0) {
    this->price = price;
  }
}

void GroceryItem::setQuantity(int quantity) {
  if (quantity >= 0) {
    this->quantity = quantity;
  }
}
