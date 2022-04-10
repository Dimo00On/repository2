//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(Test01, test2) {
    try{
        IsLeap(-1);
        ASSERT_EQ(false, true);
    }
    catch(...) {}
    ASSERT_EQ(IsLeap(100), false);
    ASSERT_EQ(IsLeap(400), true);
    ASSERT_EQ(GetMonthDays(1, 2),28);
    ASSERT_EQ(GetMonthDays(4, 2),29);
    try{
        GetMonthDays(1, 13);
        ASSERT_EQ(false, true);
    }
    catch(...){}
    ASSERT_EQ(GetMonthDays(1, 4), 30);
    ASSERT_EQ(GetMonthDays(1, 5), 31);
}


