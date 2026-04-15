#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {

    int numArr[4] = {0,1,2,3};
    int* copiedArr = copy_array(numArr, 4);

    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(numArr[i], copiedArr[i]);
    }
    delete[] copiedArr;
}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {

    int numArr[4] = {0,1,2,3};
    int* copiedArr = copy_array(numArr, 4);

    copiedArr[0] = 11;

    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(numArr[i], 0 + i);
    }
    delete[] copiedArr;
}

TEST(CopyArrayTests, SimpleCopyWasMade) {

    int numArr[4] = {0,1,2,3};
    int* copiedArr = copy_array(numArr, 4);

    EXPECT_NE(numArr, copiedArr);

    delete[] copiedArr;
}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    RC_PRE(!values.empty());

    int* testArr = new int[values.size()];
    copy_vector_to_array(values, testArr);

    int* copiedArr = copy_array(testArr, values.size());

    for (int i = 0; i < (int)values.size(); i++) {
        RC_ASSERT(testArr[i] == copiedArr[i]);
    }
    delete[] testArr;
    delete[] copiedArr;
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {

    RC_PRE(!values.empty());

    int* testArr = new int[values.size()];
    copy_vector_to_array(values, testArr);

    int* copiedArr = copy_array(testArr, values.size());

    copiedArr[0] = copiedArr[0] + 1; // always garuntees to modify the array value

    for (int i = 0; i < (int)values.size(); i++) {
        RC_ASSERT(testArr[i] == values[i]);
    }

    delete[] testArr;
    delete[] copiedArr;
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {

    RC_PRE(!values.empty());

    int* testArr = new int[values.size()];
    copy_vector_to_array(values, testArr);

    int* copiedArr = copy_array(testArr, values.size());

    RC_ASSERT(testArr != copiedArr);

    delete[] testArr;
    delete[] copiedArr;
}



