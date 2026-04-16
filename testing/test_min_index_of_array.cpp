#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {

    int testArr[4] = {0,1,2,3};

    EXPECT_EQ(min_index_of_array(testArr, 4), 0);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {

    int testArr[4] = {3,2,1,0};

    EXPECT_EQ(min_index_of_array(testArr, 4), 3);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {

    int testArr[4] = {3,2,0,1};

    EXPECT_EQ(min_index_of_array(testArr, 4), 2);

}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {

    int testArr[4] = {3,0,0,1};

    EXPECT_EQ(min_index_of_array(testArr, 4), 1);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {

    int testArr[4] = {0,1,2,3};
    min_index_of_array(testArr, 4);

    for (int i = 0; i<4 ; i++) {
        EXPECT_EQ(testArr[i], i);
    }

}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    auto values = *rc::gen::nonEmpty(rc::gen::arbitrary<std::vector<int>>());

    int* copiedArr = new int[values.size()];
    copy_vector_to_array(values, copiedArr);

    int minValIndex = min_index_of_array(copiedArr, (int)values.size());

    for (int i = 0; i < (int)values.size(); i++) {
        RC_ASSERT(copiedArr[minValIndex] <= copiedArr[i]);
    }

    delete[] copiedArr;
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    auto values = *rc::gen::nonEmpty(rc::gen::arbitrary<std::vector<int>>());

    int* copiedArr = new int[values.size()];
    copy_vector_to_array(values, copiedArr);

    min_index_of_array(copiedArr, (int)values.size());

    for (int i = 0; i < (int)values.size(); i++) {
        RC_ASSERT(values[i] == copiedArr[i]);
    }

    delete[] copiedArr;
}
