//
// Created by clay on 7/4/17.
//

#ifndef CART_DATASTORE_H
#define CART_DATASTORE_H

#include <string>

#include "DataResult.h"

using namespace std;

class DataStore {

public:

    virtual void setQuery(string sql) = 0;
    virtual void setParam(string param, string value);
    virtual void setParam(string param, int value);
    virtual void setParam(string param, double value);

    virtual DataResult execute() = 0;

};

#endif //CART_DATASTORE_H
