#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {

    int a = 1;
    int b = 2;

    swap(&a, &b);

    EXPECT_EQ(a , 6);
    EXPECT_EQ(b , 5);
}

TEST(SwapTests, SimpleSwapValuesInArray) {

    int num_arr[3] = {0,1,2};

    swap(&num_arr[0], &num_arr[1]);

    EXPECT_EQ(num_arr[0] , 1);
    EXPECT_EQ(num_arr[1] , 0);
    EXPECT_EQ(num_arr[2] , 2);

}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    int num1 = a_start;
    int num2 = b_start;

    swap(&num1, &num2);

    RC_ASSERT(num1 == b_start);
    RC_ASSERT(num2 == a_start);

}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    RC_PRE(!values.empty());

    int* copiedArr = new int[values.size()];

    copy_vector_to_array(values, copiedArr);

    int indexNum1 = *rc::gen::inRange(0, (int)values.size());
    int indexNum2 = *rc::gen::inRange(0, (int)values.size());

    int originalNum1 = copiedArr[indexNum1];
    int originalNum2 = copiedArr[indexNum2];

    swap(&copiedArr[indexNum1], &copiedArr[indexNum2]);

    RC_ASSERT(copiedArr[indexNum2] == originalNum1);
    RC_ASSERT(copiedArr[indexNum1] == originalNum2);

    delete[] copiedArr;
}
