//
// Created by clay on 7/4/17.
//

#include <gtest/gtest.h>

#include "DataResult.h"
#include "CartItem.h"
#include "MockDataResult.h"

using namespace ::testing;

class CartItemTest : public testing::Test {
public:
    MockDataResult result;
    CartItem item;
};

TEST_F(CartItemTest, instream_byDefault_copiesFieldsFromDataResult)
{
    result.setFields(3, "name", "quantity", "price");
    result.addNext(3, "Widget", "2", "3.12");

    result >> item;

    ASSERT_EQ(item.getName(), "Widget");
    ASSERT_EQ(item.getPrice(), 3.12);
    ASSERT_EQ(item.getQuantity(), 2);
}