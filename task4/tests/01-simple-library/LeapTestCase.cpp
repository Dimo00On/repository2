//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(Test01, test2a) {
    try{
        IsLeap(-1);
        ASSERT_EQ(false, true);
    }
    catch(...) {}
}

TEST(Test01, test2b) {
    ASSERT_EQ(IsLeap(100), false);
}

TEST(Test01, test2c) {
    ASSERT_EQ(IsLeap(400), true);
}

TEST(Test01, test3a) {
    ASSERT_EQ(GetMonthDays(1, 2),28);
}

TEST(Test01, test3b) {
    ASSERT_EQ(GetMonthDays(4, 2),29);
}

TEST(Test01, test3c) {
    try{
        GetMonthDays(1, 13);
        ASSERT_EQ(false, true);
    }
    catch(...){}
}

TEST(Test01, test3d) {
    ASSERT_EQ(GetMonthDays(1, 4), 30);
}

TEST(Test01, test3e) {
    ASSERT_EQ(GetMonthDays(1, 5), 31);
}

