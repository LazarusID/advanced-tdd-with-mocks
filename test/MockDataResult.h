
#ifndef CART_MOCKDATARESULT_H
#define CART_MOCKDATARESULT_H

#include <vector>
#include <memory>
#include <string>
#include <queue>
#include "DataResult.h"

using namespace std;

class MockDataResult : public DataResult {

public:

    virtual shared_ptr< vector<string>> getFields() override;
    virtual shared_ptr< vector<string>> getNext() override;
    virtual bool eof() override;

    void addNext(int fieldCount, ...);
    void setFields(int fieldCount, ...);

private:
    queue<shared_ptr< vector<string>>> dataset;
    shared_ptr< vector<string>> fields;
};

#endif //CART_MOCKDATARESULT_H
