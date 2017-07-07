//
// Created by clay on 7/4/17.
//

#include "CartItem.h"

CartItem::CartItem() : name(""), quantity(0), price(0.0)
{}

CartItem::CartItem(string n, int q, double p) :
    name(n), quantity(q), price(p)
{}

const string &CartItem::getName() const {
    return name;
}

void CartItem::setName(const string &name) {
    CartItem::name = name;
}

int CartItem::getQuantity() const {
    return quantity;
}

void CartItem::setQuantity(int quantity) {
    CartItem::quantity = quantity;
}

double CartItem::getPrice() const {
    return price;
}

void CartItem::setPrice(double price) {
    this->price = price;
}

double CartItem::getItemTotal() {
    return quantity * price;
}

DataResult& operator>>(DataResult& in, CartItem& item) {
    return in;
}
