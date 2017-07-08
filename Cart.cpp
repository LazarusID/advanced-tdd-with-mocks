#include "Cart.h"

int Cart::itemCount() {
    return items.size();
}

void Cart::addItem(shared_ptr<CartItem> item) {
    items.push_back(item);
}

shared_ptr<CartItem> Cart::getItem(int row) {
    return items.at(row);
}
