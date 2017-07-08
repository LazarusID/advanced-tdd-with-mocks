//
// Created by clay on 7/8/17.
//

#ifndef CART_MOCKDATASTORE_H
#define CART_MOCKDATASTORE_H


#include <DataStore.h>
#include <map>

class MockDataStore : public DataStore {
public:

    MockDataStore();

    void setQuery(string sql) override;

    void setParam(string param, string value) override;

    void setParam(string param, int value) override;

    void setParam(string param, double value) override;

    DataResult execute() override;

    string getSql();
    string getStringParam(string param);
    int getIntParam(string param);
    double getDoubleParam(string param);

    bool executeWasCalled();

private:
    map<string, string> string_params;
    map<string, int> int_params;
    map<string, double> double_params;

    string sql;
    bool execute_called;
};


#endif //CART_MOCKDATASTORE_H
