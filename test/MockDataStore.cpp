//
// Created by clay on 7/8/17.
//

#include "MockDataStore.h"
#include "MockDataResult.h"

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

unique_ptr<DataResult> MockDataStore::execute() {
    execute_called = true;
    return make_unique<MockDataResult>();
}

string MockDataStore::getSql() {
    return sql;
}

string MockDataStore::getStringParam(string param) {
    return string_params.at(param);
}

int MockDataStore::getIntParam(string param) {
    return int_params.at(param);
}

double MockDataStore::getDoubleParam(string param) {
    return double_params.at(param);
}

bool MockDataStore::executeWasCalled() {
    return execute_called;
}
