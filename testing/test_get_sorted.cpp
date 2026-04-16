#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {

    int randomArr[4] = {0,1,2,3};
    int* sortedCopiedArray = get_sorted(randomArr, 4);

    for (int i = 0 ; i < 4; i++) {
        EXPECT_EQ(sortedCopiedArray[i], i);
    }
    delete[] sortedCopiedArray;
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {

    int randomArr[4] = {3,2,1,0};
    int* sortedCopiedArray = get_sorted(randomArr, 4);

    for (int i = 0 ; i < 4; i++) {
        EXPECT_EQ(sortedCopiedArray[i], i);
    }
    delete[] sortedCopiedArray;
}

TEST(GetSortedTests, SimpleSortAverageArray) {

    int randomArr[4] = {2,1,3,0};
    int* sortedCopiedArray = get_sorted(randomArr, 4);

    for (int i = 0 ; i < 4; i++) {
        EXPECT_EQ(sortedCopiedArray[i], i);
    }
    delete[] sortedCopiedArray;

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {

    int dublicatesArray[4] = {3,1,1,2};
    int* sortedCopiedArray = get_sorted(dublicatesArray, 4);

    EXPECT_EQ(sortedCopiedArray[0], 1);
    EXPECT_EQ(sortedCopiedArray[1], 1);
    EXPECT_EQ(sortedCopiedArray[2], 2);
    EXPECT_EQ(sortedCopiedArray[3], 3);

    delete[] sortedCopiedArray;
}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {

    int randomArr[4] = {2,1,3,0};
    int* sortedCopiedArray = get_sorted(randomArr, 4);

    EXPECT_EQ(randomArr[0], 2);
    EXPECT_EQ(randomArr[1], 1);
    EXPECT_EQ(randomArr[2], 3);
    EXPECT_EQ(randomArr[3], 0);

    delete[] sortedCopiedArray;

}

TEST(GetSortedTests, SimpleCopyWasMade) {

    int randomArr[4] = {2,1,3,0};
    int* sortedCopiedArray = get_sorted(randomArr, 4);

    EXPECT_NE(sortedCopiedArray, randomArr);

    delete[] sortedCopiedArray;
}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    int* randomArr = new int[values.size()];
    copy_vector_to_array(values, randomArr);

    int* sortedCopiedArray = get_sorted(randomArr, (int)values.size());

    for (int i = 0 ; i < (int)values.size() - 1; i++) {
        RC_ASSERT(sortedCopiedArray[i] <= sortedCopiedArray[i + 1]);
    }

    delete[] randomArr;
    delete[] sortedCopiedArray;

}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    int* randomArr = new int[values.size()];
    copy_vector_to_array(values, randomArr);

    int* sortedCopiedArray = get_sorted(randomArr, (int)values.size());

    for (int i = 0 ; i < (int)values.size(); i++) {
        RC_ASSERT(randomArr[i] == values[i]);
    }

    delete[] randomArr;
    delete[] sortedCopiedArray;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {

    int* randomArr = new int[values.size()];
    copy_vector_to_array(values, randomArr);

    int* sortedCopiedArray = get_sorted(randomArr, (int)values.size());

    RC_ASSERT(randomArr != sortedCopiedArray);

    delete[] randomArr;
    delete[] sortedCopiedArray;

}











