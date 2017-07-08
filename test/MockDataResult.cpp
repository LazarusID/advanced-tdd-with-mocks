//
// Created by clay on 7/4/17.
//

#include "MockDataResult.h"

#include <queue>
#include <cstdarg>

shared_ptr< vector<string>> MockDataResult::getFields() {
    return fields;
}

shared_ptr< vector<string>> MockDataResult::getNext() {
    auto row = dataset.front();
    dataset.pop();
    return row;
}

bool MockDataResult::eof() {
    return dataset.empty();
}

void MockDataResult::addNext(int fieldCount, ...) {
    vector<string> row;
    va_list args;
    va_start(args, fieldCount);
    for(int i=0; i < fieldCount; ++i) {
        row.push_back(va_arg(args, const char*));
    }
    va_end(args);

    dataset.push(make_shared<vector<string>>(row));
}

void MockDataResult::setFields(int fieldCount, ...)
{
    vector<string> f;
    va_list args;
    va_start(args, fieldCount);
    for(int i=0; i < fieldCount; ++i) {
        f.push_back(va_arg(args, const char*));
    }
    va_end(args);

    fields = make_shared<vector<string>>(f);
}
