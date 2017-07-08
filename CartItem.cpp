//
// Created by clay on 7/4/17.
//

#include <sstream>
#include "CartItem.h"

const int FIELD_UNSET = -1;

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

    int name_idx = FIELD_UNSET;
    int price_idx = FIELD_UNSET;
    int quantity_idx = FIELD_UNSET;

    auto fields = in.getFields();

    for(int i=0; i < fields->size(); ++i) {
        if ("name" == fields->at(i)) name_idx = i;
        if ("price" == fields->at(i)) price_idx = i;
        if ("quantity" == fields->at(i)) quantity_idx = i;
    }

    auto row_ptr = in.getNext();
    auto row = *row_ptr;
    item.setName(row[name_idx]);

    istringstream inprice(row[price_idx]);
    istringstream inquantity(row[quantity_idx]);

    double price;
    int quantity;

    inprice >> price;
    inquantity >> quantity;

    item.setPrice(price);
    item.setQuantity(quantity);

    return in;
}
