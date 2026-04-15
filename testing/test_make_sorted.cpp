#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {

    int sorted_array[4] = {0,1,2,3};
    make_sorted(sorted_array, 4);

    for (int i = 0 ; i < 4; i++) {
       EXPECT_EQ(sorted_array[i], i);
    }
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {

    int reverseSortedArray[4] = {3,2,1,0};
    make_sorted(reverseSortedArray, 4);

    for (int i = 0 ; i < 4; i++) {
        EXPECT_EQ(reverseSortedArray[i], i);
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {

    int randomArray[4] = {1,3,0,2};
    make_sorted(randomArray, 4);

    for (int i = 0 ; i < 4; i++) {
        EXPECT_EQ(randomArray[i], i);
    }

}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {

    int dublicatesArray[4] = {3,1,1,2};
    make_sorted(dublicatesArray, 4);

    EXPECT_EQ(dublicatesArray[0], 1);
    EXPECT_EQ(dublicatesArray[1], 1);
    EXPECT_EQ(dublicatesArray[2], 2);
    EXPECT_EQ(dublicatesArray[3], 3);

}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    int* randomArr = new int[values.size()];
    copy_vector_to_array(values, randomArr);

    make_sorted(randomArr, (int)values.size());

    for (int i = 0 ; i < ((int)values.size()) - 1; i++) {
        RC_ASSERT(randomArr[i] <= randomArr[i + 1]);
    }

    delete[] randomArr;
}
