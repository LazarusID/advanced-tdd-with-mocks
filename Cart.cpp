#include "Cart.h"

int Cart::itemCount() {
    return items.size();
}

void Cart::addItem(unique_ptr<CartItem> item) {
    items.push_back(move(item));
}