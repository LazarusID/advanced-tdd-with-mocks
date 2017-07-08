//
// Created by clay on 7/4/17.
//

#include <gtest/gtest.h>

#include "CartItem.h"
#include "MockDataResult.h"

using namespace ::testing;

class CartItemTest : public testing::Test {
public:
    const char *ITEM_NAME = "Widget";

    CartItem item;
    MockDataResult result;

};

TEST_F(CartItemTest, cartItem_byDefault_setsEmptyCartItem)
{
    ASSERT_EQ(item.getName(), "");
    ASSERT_EQ(item.getQuantity(), 0);
    ASSERT_EQ(item.getPrice(), 0.0);
}

TEST_F(CartItemTest, getLineTotal_withQuantityOne_returnsItemPrice)
{
    item.setName(ITEM_NAME);
    item.setPrice(3.14);
    item.setQuantity(1);

    ASSERT_EQ(item.getItemTotal(), 3.14);
}

TEST_F(CartItemTest, getLineTotal_withQuantityOneAndDifferentPrice_returnsItemPrice)
{
    item.setName(ITEM_NAME);
    item.setPrice(2.71);
    item.setQuantity(1);

    ASSERT_EQ(item.getItemTotal(), 2.71);
}

TEST_F(CartItemTest, getLineTotal_withQuantityTwo_returnsTwiceItemPrice)
{
    item.setName(ITEM_NAME);
    item.setPrice(2.71);
    item.setQuantity(2);

    ASSERT_EQ(item.getItemTotal(), 5.42);
}

TEST_F(CartItemTest, inputStream_givenAllFields_populatesCartItem)
{
    result.setFields(3, "name", "price", "quantity");
    result.addNext(3, ITEM_NAME, "3.14", "1");

    result >> item;

    ASSERT_EQ(item.getName(), ITEM_NAME);
    ASSERT_EQ(item.getPrice(), 3.14);
    ASSERT_EQ(item.getQuantity(), 1);
}

TEST_F(CartItemTest, inputStream_missingQuantity_defaultsToOne)
{
    result.setFields(2, "name", "price");
    result.addNext(2, ITEM_NAME, "2.71");

    result >> item;

    ASSERT_EQ(item.getName(), ITEM_NAME);
    ASSERT_EQ(item.getPrice(), 2.71);
    ASSERT_EQ(item.getQuantity(), 1);
}

