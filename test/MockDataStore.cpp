//
// Created by clay on 7/8/17.
//

#include "MockDataStore.h"

MockDataStore::MockDataStore() {
    execute_called = false;
}

void MockDataStore::setQuery(string sql) {

}

void MockDataStore::setParam(string param, string value) {

}

void MockDataStore::setParam(string param, int value) {

}

void MockDataStore::setParam(string param, double value) {

}

DataResult MockDataStore::execute() {
    return nullptr;
}
