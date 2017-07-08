//
// Created by clay on 7/4/17.
//

#ifndef CART_CARTITEM_H
#define CART_CARTITEM_H

#include <string>
#include "DataResult.h"
#include "DataStore.h"

using namespace std;

class CartItem {
private:
    string name;
    int quantity;
    double price;
public:

    CartItem();
    CartItem(string n, int q, double p);

    const string &getName() const;

    void setName(const string &name);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getPrice() const;

    void setPrice(double price);

    double getItemTotal();

};

DataResult& operator>>(DataResult& in, CartItem& item);
DataStore& operator<<(DataStore& out, CartItem& item);

#endif //CART_CARTITEM_H
