//
// Created by clay on 7/4/17.
//

#include "CartItem.h"

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
    CartItem::price = price;
}
