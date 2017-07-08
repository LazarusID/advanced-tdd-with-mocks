#ifndef _CART_H_
#define _CART_H_

#include "CartItem.h"

#include <memory>
#include <vector>

class Cart {
public:
    int itemCount();
    void addItem(shared_ptr<CartItem> item);
    shared_ptr<CartItem> getItem(int i);

private:
    vector<shared_ptr<CartItem>> items;

};

#endif
