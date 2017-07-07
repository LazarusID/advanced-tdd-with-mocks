#include <gtest/gtest.h>

#include "cart.h"

using namespace ::testing;

class CartTest : public testing::Test {
public:
    Cart cart;

};

TEST_F(CartTest, itemCount_byDefault_returnsZero) {
    ASSERT_EQ(cart.itemCount(), 0);
}