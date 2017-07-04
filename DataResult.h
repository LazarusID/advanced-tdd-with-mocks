//
// Created by clay on 7/4/17.
//

#ifndef CART_DATARESULT_H
#define CART_DATARESULT_H

#include <vector>
#include <string>

using namespace std;

class DataResult {

public:

    virtual vector<string> getFields() = 0;
    virtual vector<string> getNext() = 0;
    virtual bool eof() = 0;

};


#endif //CART_DATARESULT_H
