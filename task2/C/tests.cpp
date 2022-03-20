#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(indexTest, Test1) {
    EXPECT_LE(amount,5);
    EXPECT_GE(amount, 0);
}

TEST(libTest, Test1) {
    EXPECT_TRUE("Hell World!" == hi());
}
