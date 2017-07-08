//
// Created by clay on 7/8/17.
//

#include "MockDataStore.h"

MockDataStore::MockDataStore() {
    execute_called = false;
}

void MockDataStore::setQuery(string sql) {
    this->sql = sql;
    string_params.clear();
    int_params.clear();
    double_params.clear();
}

void MockDataStore::setParam(string param, string value) {
    string_params[param] = value;
}

void MockDataStore::setParam(string param, int value) {
    int_params[param] = value;
}

void MockDataStore::setParam(string param, double value) {
    double_params[param] = value;
}

DataResult MockDataStore::execute() {
    execute_called = true;
    return nullptr;
}
