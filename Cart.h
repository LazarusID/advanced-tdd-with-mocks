#ifndef _CART_H_
#define _CART_H_

#include "CartItem.h"

#include <memory>
#include <vector>

class Cart {
public:
    int itemCount();
    void addItem(unique_ptr<CartItem> item);

private:
    vector<unique_ptr<CartItem>> items;

};

#endif