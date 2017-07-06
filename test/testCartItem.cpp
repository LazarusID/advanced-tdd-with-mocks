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
    CartItem item;

    const char *ITEM_NAME = "Widget";
};

TEST_F(CartItemTest, getLineTotal_withQuantityOne_returnsItemPrice)
{
    item.setName(ITEM_NAME);
    item.setPrice(3.14);
    item.setQuantity(1);

    ASSERT_EQ(item.getItemTotal(), 3.14);
}