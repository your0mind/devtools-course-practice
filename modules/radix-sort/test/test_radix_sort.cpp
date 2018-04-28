// Copyright 2018 Batanina Liubov

#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include "include/radix_sort.hpp"

using std::uniform_int_distribution;

class RadixSortTest : public testing::Test {
 protected:
    virtual void SetUp() {
        data.resize(10000);
        int seed = 1;
        std::mt19937 generator(seed);
        uniform_int_distribution<int> distr(std::numeric_limits<int>::min(),
                                            std::numeric_limits<int>::max());
        generate(data.begin(), data.end(), [&distr, &generator](){
            return distr(generator);
        });
    }
    std::vector<int> data;
};


TEST_F(RadixSortTest, Radix_Sort) {
    // Arrange & Act
    radixSort(data.begin(), data.end());

    // Assert
    EXPECT_EQ(std::is_sorted(data.begin(), data.end()), true);
}

TEST_F(RadixSortTest, Radix_Sort_Empty_Vector) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(radixSort(data.begin(), data.begin()));
}

TEST_F(RadixSortTest, Throw_When_Pass_Reverse_Range) {
    // Arrange & Act & Assert
    EXPECT_THROW(radixSort(data.end(), data.begin()), std::logic_error);
}
