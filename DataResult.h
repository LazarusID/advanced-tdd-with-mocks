//
// Created by clay on 7/4/17.
//

#ifndef CART_DATARESULT_H
#define CART_DATARESULT_H

#include <vector>
#include <string>
#include <memory>

using namespace std;

class DataResult {

public:

    virtual unique_ptr< vector<string>> getFields();
    virtual unique_ptr< vector<string>> getNext();
    virtual bool eof() = 0;

};


#endif //CART_DATARESULT_H
