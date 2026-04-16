#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    return rc::gen::map(
        rc::gen::container<std::string>(rc::gen::inRange('a', 'z')),
        [](std::string s) { return s; }
    );
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    std::vector<std::string> strings;
    for (int num : numbers) {
        strings.push_back(std::to_string(num));
    }
    return strings;
}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {

    const char* fakeArgv[] = {"./SortInts", "1", "2", "3"};
    int fakeArgc = 4;

    int* ar_out = nullptr;
    int len_out = 0;

    parse_args(fakeArgc, (char**)fakeArgv, &ar_out, &len_out);

    EXPECT_EQ(len_out, 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(ar_out[i], i + 1);
    }
    free(ar_out);
}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    const char* fakeArgv[] = {"./SortInts"};
    int fakeArgc = 1;

    int* ar_out = nullptr;
    int len_out = 0;

    parse_args(fakeArgc, (char**)fakeArgv, &ar_out, &len_out);

    EXPECT_EQ(ar_out, nullptr);
    EXPECT_EQ(len_out, 0);

    free(ar_out);
}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {

    // Generates a random vector of ints {1, 2, 3}
    std::vector<int> randomVector = *rc::gen::nonEmpty(rc::gen::arbitrary<std::vector<int>>());

    // Converts the int vector into string vector as cmd line uses strings
    std::vector<std::string> stringVector = vector_of_ints_to_vector_of_strings(randomVector);

    // creates a vector of char* simulating real argv & adds a fake program name at the start
    std::vector<char*> fakeArgv;
    fakeArgv.push_back((char*)"./SortInts");

    // Loop sequence to append new str in the argv
    for (int i = 0; i < (int)stringVector.size(); i++) {
        std::string& s = stringVector[i];
        fakeArgv.push_back(s.data());
    }

    // Set up for Tests
    int fakeArgc = fakeArgv.size();
    int* ar_out = nullptr;
    int len_out = 0;

    parse_args(fakeArgc, fakeArgv.data(), &ar_out, &len_out);

    RC_ASSERT(len_out == (int)randomVector.size());

    for (int i = 0; i < (int)randomVector.size(); i++) {
        RC_ASSERT(ar_out[i] == randomVector[i]);
    }

    free(ar_out);

}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {

    // Creates a vector of char* simulating real argv & adds a fake program name at the start
    std::vector<char*> fakeArgv;
    fakeArgv.push_back((char*)"./SortInts");

    // Set up for Tests
    int fakeArgc = fakeArgv.size();
    int* ar_out = nullptr;
    int len_out = 0;

    parse_args(fakeArgc, fakeArgv.data(), &ar_out, &len_out);

    RC_ASSERT(len_out == 0);
    RC_ASSERT(ar_out == nullptr);

    free(ar_out);

}
