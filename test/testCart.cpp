#include <gtest/gtest.h>

#include "Cart.h"
#include <memory>

using namespace ::testing;
using namespace std;

class CartTest : public testing::Test {
public:
    Cart cart;
    const char *ITEM_NAME = "Yo-Yo";
};

TEST_F(CartTest, itemCount_byDefault_returnsZero) {
    ASSERT_EQ(cart.itemCount(), 0);
}

TEST_F(CartTest, itemCount_afterOneItemAdded_returnsOne) {

    cart.addItem(make_shared<CartItem>(CartItem(ITEM_NAME, 1, 3.14)));

    ASSERT_EQ(cart.itemCount(), 1);
}

TEST_F(CartTest, getItem_afterOneItemAddedAndRequestingItem0_returnsAddedItem) {

    cart.addItem(make_shared<CartItem>(CartItem(ITEM_NAME, 1, 3.14)));
    auto actual = cart.getItem(0);

    ASSERT_EQ(actual->getName(), ITEM_NAME);
    ASSERT_EQ(actual->getPrice(), 3.14);
    ASSERT_EQ(actual->getQuantity(), 1);

}
